import * as M from "./memory.ts";
import type { Program } from "./loader.ts";
import type { Tracer } from "./trace.ts";
import { runExpression } from "./expr.ts";
import { CTRL_HANDLERS } from "./control.ts";

// src/vm.c の移植。バイトコードを ROM のアドレスのまま読み, C と同じ順番で値を評価する。
// 関数名は C 側に合わせてあるので, 挙動を確かめるときは src/vm.c の同名の関数と見比べること。
//
// 値はすべて JS の number で持ち, 32bit 符号付き (| 0) に正規化する。ポインタも GBA のアドレスの数値のまま扱う。

export const OP = {
  END: 0x00,
  S16: 0x01,
  U8: 0x02,
  U8_0x03: 0x03,
  BOOL8: 0x04,
  U16: 0x06,
  STRING: 0x07,
  U24: 0x08,
  S32: 0x09,
  S32_0x0A: 0x0A,
  S32_0x0D: 0x0D,
  STRING_REF: 0x0E,
  MEMORY: 0x10,
  MEMORY_INDEXED: 0x20,
  EXPRESSION: 0x30,
  PARAMETER: 0x40,
  LABEL: 0x50,
  CONTROL: 0x60,
  CALL: 0x70,
  BLOCK: 0x80,
  VARIABLE: 0x90,
  END_EXPRESSION: 0xA0,
} as const;

export const CLAUSE_CASE = 0x63;
export const CLAUSE_DEFAULT = 0x64;
export const CLAUSE_ELSE = 0x65;
export const CLAUSE_ELIF = 0x69;

const SCRIPT_STACK_SIZE = 32;
const SUBROUTINE_STACK_SIZE = 24;
const MAX_ARGS = 16;

export type ScriptArgs = { argc: number; argv: number[] };
export type Decoded = { type: number; val: number; next: number | null };

export const s16 = (n: number): number => (n << 16) >> 16;

// gMapChangeFlags (include/global.h)
export const MAPCHANGE_LOAD = 1 << 0;
export const MAPCHANGE_BACKUP = 1 << 4;
export const MAPCHANGE_RESTART = 1 << 6;
export const MAPCHANGE_RESTORE = 1 << 8;

// gStat->mapInitScriptID (include/game.h)
export const STAT_MAP_INIT_SCRIPT_ID = 0x24C;

export class BokVM {
  readonly program: Program;
  readonly mem: M.Memory;
  readonly trace: Tracer;

  pc: number | null = null;
  result = 0;
  private readonly subroutineStack: number[] = [];
  private readonly scriptStack: (number | ScriptArgs)[] = new Array(SCRIPT_STACK_SIZE).fill(0);
  private scriptStackTop = 0;
  // いま積まれているフレームの引数記述子の位置, 前のフレームが残した記述子 (ただの古い値) と区別するため
  private readonly liveArgs = new Set<number>();
  // subroutineStack の各段が2バイト形式のラベル距離から積まれたか
  private readonly subroutineStackWide: boolean[] = [];

  // VM の外にあるゲーム側の変数のうち, 制御命令が書くもの
  mapChangeFlags = 0;
  mapInitScriptID = 0;

  // --ret で与えたコマンドの戻り値 (名前 -> 値)
  readonly commandResults = new Map<string, number>();

  steps = 0;
  maxSteps = 1_000_000;

  constructor(program: Program, trace: Tracer) {
    this.program = program;
    this.mem = program.memory;
    this.trace = trace;
    this.mem.warn = (msg) => trace.warn(msg);
  }

  private u8(addr: number): number {
    return this.mem.u8(addr);
  }

  private u16(addr: number): number {
    return this.u8(addr) | (this.u8(addr + 1) << 8);
  }

  // ---- コンテナ ----

  // VM_ReadContainerLength
  readContainerLength(pc: number): [number, number] {
    const nibble = this.u8(pc) & 0xF;
    switch (nibble) {
      case 0xD:
        return [pc + 2, this.u8(pc + 1)];
      case 0xE:
        return [pc + 3, this.u8(pc + 1) | (this.u8(pc + 2) << 8)];
      case 0xF:
        return [pc + 4, this.u8(pc + 1) | (this.u8(pc + 2) << 8) | (this.u8(pc + 3) << 16)];
      default:
        return [pc + 1, nibble];
    }
  }

  // VM_ReadCtrlLabelOffset, 2バイト形式はリトルエンディアンで読む (C のまま)
  // 2バイト形式は bokcc が書く綴りとバイト順が逆なので, ラベルの位置がずれる (名前付き引数を探すときに警告する)
  readCtrlLabelOffset(pc: number): [number, number, boolean] {
    const b0 = this.u8(pc);
    if (b0 & 0x80) return [pc + 2, (b0 | (this.u8(pc + 1) << 8)) & 0x7FFF, true];
    return [pc + 1, b0, false];
  }

  // ---- 値のデコード ----

  // VM_DecodeValue, C で未初期化のまま返る値は 0 にしている
  decodeValue(pc: number): Decoded {
    const cmd = this.u8(pc);
    const nibble = cmd & 0xF0;

    if ((nibble & 0xC0) === 0xC0) {
      return { type: OP.S32, val: (cmd & 0x3F) - 1, next: pc + 1 };
    }

    if (nibble === 0) {
      const p = pc + 1;
      switch (cmd) {
        case OP.END:
          return { type: cmd, val: 0, next: null };
        case OP.S16:
        case OP.U24:
          return { type: cmd, val: s16(this.u16(p)), next: p + 2 };
        case OP.S32:
        case OP.S32_0x0A:
        case OP.S32_0x0D:
          return { type: cmd, val: (this.u16(p) | (this.u16(p + 2) << 16)) | 0, next: p + 4 };
        case OP.U16:
          return { type: cmd, val: this.u16(p), next: p + 2 };
        case OP.U8:
        case OP.U8_0x03:
        case OP.BOOL8:
          return { type: cmd, val: this.u8(p), next: p + 1 };
        case OP.STRING:
          return { type: cmd, val: p + 1, next: p + this.u8(p) + 1 };
        case OP.STRING_REF:
          return { type: OP.STRING, val: this.program.stringAddr(this.u16(p)), next: p + 2 };
        default:
          return { type: cmd, val: 0, next: p };
      }
    }

    switch (nibble) {
      case OP.MEMORY:
      case OP.MEMORY_INDEXED:
        return this.readMemory(pc);
      case OP.PARAMETER: {
        const idx = cmd & 0xF;
        if (idx === 0xF) return { type: OP.S32, val: this.parseParameter(this.u8(pc + 1) + 0xF), next: pc + 2 };
        return { type: OP.S32, val: this.parseParameter(idx), next: pc + 1 };
      }
      case OP.VARIABLE:
        return { type: OP.S32, val: this.getVariable(cmd & 0xF), next: pc + 1 };
      case OP.BLOCK: {
        const [body, len] = this.readContainerLength(pc);
        return { type: nibble, val: body, next: body + len };
      }
      case OP.EXPRESSION: {
        const [body, len] = this.readContainerLength(pc);
        return { type: nibble, val: runExpression(this, body), next: body + len };
      }
      case OP.LABEL: {
        const [body, len] = this.readContainerLength(pc);
        return { type: nibble | (this.u8(body) << 16), val: body + 1, next: body + len };
      }
      default:
        // C では pc が進まず, 呼び出し側のループが止まらなくなる
        throw new Error(`0x${pc.toString(16).toUpperCase()}: 値として読めない命令 0x${cmd.toString(16).toUpperCase()} です`);
    }
  }

  // ---- スクリプトのフレーム ----

  // VM_PushScriptFrame
  private pushScriptFrame(args: ScriptArgs | null, localVarCount: number): number | null {
    if (args === null) return null;
    const base = this.scriptStackTop;
    const sp = base + localVarCount;
    if (sp >= SCRIPT_STACK_SIZE) this.trace.warn(`scriptStack (${SCRIPT_STACK_SIZE}語) があふれました, 実機では gVM の後ろを壊します`);
    this.scriptStack[sp] = args;
    this.liveArgs.add(sp);
    this.scriptStackTop = sp + 1;
    return base;
  }

  // VM_PopScriptFrame
  private popScriptFrame(base: number | null): void {
    if (base === null) return;
    for (const at of this.liveArgs) if (at >= base) this.liveArgs.delete(at);
    this.scriptStackTop = base;
  }

  // VM_ParseParameter, 0 は result, n は p(n-1)
  parseParameter(idx: number): number {
    if (idx === 0) return this.result;
    const args = this.scriptStack[this.scriptStackTop - 1];
    if (typeof args !== "object") {
      this.trace.warn(`p${idx - 1} を読もうとしましたがスクリプトのフレームがありません`);
      return 0;
    }
    if (idx - 1 >= args.argc) this.trace.warn(`p${idx - 1} を読みましたが引数は ${args.argc} 個です`);
    return args.argv[idx - 1] ?? 0;
  }

  // VM_GetVariable
  // 前のフレームが残した記述子の位置なら, C ではそのポインタの値が読める (ここでは 0 にする)
  getVariable(idx: number): number {
    const at = this.scriptStackTop - 1 - idx;
    const v = this.scriptStack[at];
    if (typeof v === "object") {
      if (this.liveArgs.has(at)) this.trace.warn(`v${idx} は実行中のフレームの引数記述子を指しています`);
      return 0;
    }
    return v ?? 0;
  }

  // VM_StoreVariable
  storeVariable(idx: number, val: number): void {
    const at = this.scriptStackTop - 1 - idx;
    const old = this.scriptStack[at];
    if (this.liveArgs.has(at)) {
      this.trace.warn(`v${idx} に書いて実行中のフレームの引数記述子を壊しました`);
      this.liveArgs.delete(at);
    }
    this.scriptStack[at] = val | 0;
    this.trace.note(`v${idx}: ${typeof old === "number" ? old : "?"} -> ${val | 0}`);
  }

  // ---- 名前付き引数 ----

  private pushSubroutineStack(pc: number, wide: boolean): void {
    if (this.subroutineStack.length >= SUBROUTINE_STACK_SIZE) this.trace.warn(`subroutineStack (${SUBROUTINE_STACK_SIZE}語) があふれました`);
    this.subroutineStack.push(pc);
    this.subroutineStackWide.push(wide);
  }

  private popSubroutineStack(): void {
    this.subroutineStack.pop();
    this.subroutineStackWide.pop();
  }

  // VM_SeekToNamedArg, 見つかれば pc をラベルの中身に合わせて 0 以外を返す
  seekToNamedArg(name: string | number): number {
    const code = typeof name === "string" ? name.charCodeAt(0) : name;
    if (this.subroutineStackWide[this.subroutineStackWide.length - 1]) this.trace.warn(`'${String.fromCharCode(code)}' を探しましたが, この命令はラベルまでの距離が2バイト形式なので, 探し始める位置が bokcc の意図とずれています`);
    let pc: number | null = this.subroutineStack[this.subroutineStack.length - 1];
    while (true) {
      const d: Decoded = this.decodeValue(pc!);
      if (d.type === 0) return 0;
      if ((d.type & 0xF0) === OP.LABEL && (d.type >> 16) === code) {
        this.pc = d.val;
        return d.val;
      }
      pc = d.next;
    }
  }

  // VM_Ctrl_Switch_Internal, 今の pc から次のラベルまで進めてその文字を返す
  nextLabel(): number {
    let pc = this.pc;
    if (pc === null || this.u8(pc) === 0) return 0;
    while (true) {
      const d: Decoded = this.decodeValue(pc!);
      if (d.type === 0) return 0;
      if ((d.type & 0xF0) === OP.LABEL) {
        this.pc = d.val;
        return d.type >> 16;
      }
      pc = d.next;
    }
  }

  // ---- 位置引数 ----

  // VM_GetPC, 終端かラベルを指していれば null
  getPC(): number | null {
    const pc = this.pc;
    if (pc === null) return null;
    const b = this.u8(pc);
    if (b === OP.END || (b & 0xF0) === OP.LABEL) return null;
    return pc;
  }

  // VM_GetValueAt, C は NULL を渡されるとアドレス 0 を読むが, ここでは警告して 0 を返す
  getValueAt(addr: number | null): number {
    if (addr === null) {
      this.trace.warn("引数が残っていない位置で値を読みました (C ではアドレス 0 を読みます)");
      this.pc = null;
      return 0;
    }
    const d = this.decodeValue(addr);
    this.pc = d.next;
    return d.val;
  }

  // VM_GetValue
  getValue(): number {
    return this.getValueAt(this.getPC());
  }

  // VM_GetValueAtSafe / VM_GetValueSafe1 / VM_GetValueSafe2
  getValueSafe(): number {
    const addr = this.getPC();
    if (addr === null) return 0;
    const d = this.decodeValue(addr);
    this.pc = d.next;
    return d.next === null ? 0 : d.val;
  }

  // VM_GetNamedArgValue
  getNamedArgValue(name: string, fallback: number): number {
    if (this.seekToNamedArg(name) !== 0) return this.getValueAt(this.getPC());
    return fallback;
  }

  // ---- メモリ参照 ----

  // 記述子の4バイト (ビッグエンディアン) とアドレスの計算, Indexed なら添字2つも読む (1つ目は読み捨てる)
  private memoryOperand(pc: number): { cmd: number; base: number; offset: number; next: number } {
    const cmd = ((this.u8(pc) << 24) | (this.u8(pc + 1) << 16) | (this.u8(pc + 2) << 8) | this.u8(pc + 3)) >>> 0;
    const base = M.regionBaseOf(this.u8(pc + 1)) + (cmd & 0xFFFF);
    if (((cmd >>> 24) & 0xF0) === OP.MEMORY_INDEXED) {
      const scale = this.decodeValue(pc + 4);
      const offset = this.decodeValue(scale.next!);
      return { cmd, base, offset: offset.val, next: offset.next! };
    }
    return { cmd, base, offset: 0, next: pc + 4 };
  }

  // VM_ReadMemory, type は記述子の型タグ (下位ニブル)
  private readMemory(pc: number): Decoded {
    const m = this.memoryOperand(pc);
    return { type: (m.cmd >>> 24) & 0xF, val: this.loadPointer(m.base, m.cmd, m.offset), next: m.next };
  }

  // VM_LoadPointer
  loadPointer(src: number, cmd: number, offset: number): number {
    switch ((cmd >>> 24) & 0xF) {
      case OP.S32:
        return this.mem.stateU32(src + offset * 4) | 0;
      case OP.U24:
        return this.mem.stateU16(src + offset * 4); // C も下位2バイトしか読まない
      case OP.S16:
      case OP.U16:
        return s16(this.mem.stateU16(src + offset * 2));
      case OP.U8:
      case OP.U8_0x03:
        return this.mem.stateU8(src + offset);
      case OP.BOOL8: {
        const bit = offset + ((cmd >>> 16) & 0xF);
        return (this.mem.stateU8(src + (bit >> 3)) & (1 << (bit & 7))) !== 0 ? 1 : 0;
      }
      default:
        return 0;
    }
  }

  // VM_StorePointerCore, 書いた結果をログに出す
  storePointerCore(dst: number, cmd: number, offset: number, val: number): void {
    const before = this.loadPointer(dst, cmd, offset);
    let at = dst;
    switch ((cmd >>> 24) & 0xF) {
      case OP.S32:
        at = dst + offset * 4;
        this.mem.setStateU32(at, val);
        break;
      case OP.U24:
        at = dst + offset * 4;
        this.mem.setStateU8(at + 2, val >> 16);
        this.mem.setStateU8(at + 1, val >> 8);
        this.mem.setStateU8(at, val);
        break;
      case OP.S16:
      case OP.U16:
        at = dst + offset * 2;
        this.mem.setStateU8(at, val);
        this.mem.setStateU8(at + 1, val >> 8);
        break;
      case OP.U8:
      case OP.U8_0x03:
        at = dst + offset;
        this.mem.setStateU8(at, val);
        break;
      case OP.BOOL8: {
        const bit = offset + ((cmd >>> 16) & 0xF);
        at = dst + (bit >> 3);
        const mask = 1 << (bit & 7);
        this.mem.setStateU8(at, val !== 0 ? this.mem.stateU8(at) | mask : this.mem.stateU8(at) & ~mask);
        this.trace.note(`${M.describeState(at)} bit${bit & 7}: ${before} -> ${this.loadPointer(dst, cmd, offset)}`);
        return;
      }
      default:
        return;
    }
    this.trace.note(`${M.describeState(at)}: ${before} -> ${this.loadPointer(dst, cmd, offset)}`);
  }

  // VM_StorePointer, 式の代入から呼ばれる (添字はここでもう一度評価される)
  storePointer(pc: number, val: number): void {
    const m = this.memoryOperand(pc);
    this.storePointerCore(m.base, m.cmd, m.offset, val);
  }

  // gStat の s32 フィールドへの書き込み (制御命令が直接書くもの)
  storeStatS32(offset: number, val: number): void {
    const at = M.STAT + offset;
    const before = this.mem.stateU32(at) | 0;
    this.mem.setStateU32(at, val);
    this.trace.note(`${M.describeState(at)}: ${before} -> ${val | 0}`);
  }

  // ---- 実行 ----

  // VM_ExecBlock, return で抜けたら true
  execBlock(pc: number | null, args: ScriptArgs | null, localVarCount: number): boolean {
    const frame = this.pushScriptFrame(args, localVarCount);
    this.trace.depth++;
    try {
      while (pc !== null) {
        if (++this.steps > this.maxSteps) throw new Error(`${this.maxSteps} 文を超えたので止めました (--max-steps で変えられます)`);
        const op = this.u8(pc) & 0xF0;
        switch (op) {
          case OP.CONTROL: {
            this.trace.statement(pc);
            const [body, len] = this.readContainerLength(pc);
            if (this.runControl(body) === 1) return true;
            pc = body + len;
            break;
          }
          case OP.CALL: {
            this.trace.statement(pc);
            const [body, len] = this.readContainerLength(pc);
            this.result = this.callScript(body);
            pc = body + len;
            break;
          }
          case OP.END: {
            pc = null;
            break;
          }
          case OP.EXPRESSION: {
            this.trace.statement(pc);
            const [body, len] = this.readContainerLength(pc);
            this.result = runExpression(this, body);
            pc = body + len;
            break;
          }
          default:
            // C ではここで pc が進まなくなり止まる
            throw new Error(`0x${pc.toString(16).toUpperCase()}: 文として実行できない命令 0x${this.u8(pc).toString(16).toUpperCase()} です`);
        }
      }
      return false;
    } finally {
      this.trace.depth--;
      this.popScriptFrame(frame);
    }
  }

  // VM_RunControl
  private runControl(pc: number): number {
    const id = this.u16(pc);
    const handler = CTRL_HANDLERS.get(id);
    if (handler === undefined) throw new Error(`制御命令 0x${id.toString(16).toUpperCase().padStart(4, "0")} のハンドラがありません (C では NULL を呼びます)`);
    const [body, labelOffset, wide] = this.readCtrlLabelOffset(pc + 2);
    this.pushSubroutineStack(body + labelOffset, wide);
    this.pc = body;
    try {
      return handler(this, body);
    } finally {
      this.popSubroutineStack();
    }
  }

  // pc から終端まで値を読み, スクリプトの引数にする (VM_CallScript と VM_Ctrl_CallScriptIndirect の共通部分)
  readArgs(pc: number | null): ScriptArgs {
    const argv: number[] = [];
    while (pc !== null) {
      const d = this.decodeValue(pc);
      if (d.type === 0) break;
      argv.push(d.val);
      pc = d.next;
    }
    if (argv.length > MAX_ARGS) this.trace.warn(`引数が ${argv.length} 個あります, C の argv は ${MAX_ARGS} 個分しかありません`);
    return { argc: argv.length & 0xFFFF, argv };
  }

  // VM_CallScript, 呼び先は即値の s16
  private callScript(pc: number): number {
    const id = s16(this.u16(pc));
    return this.execByID(id, this.readArgs(pc + 2));
  }

  // VM_ExecByID
  execByID(id: number, args: ScriptArgs | null): number {
    const entry = this.program.lookup(id);
    const [body] = this.readContainerLength(entry.addr);
    const masked = (id & 0x7FFFFFFF) >>> 0;
    const name = this.program.ctx.scriptNames?.get(masked) ?? `Scr_0x${masked.toString(16).toUpperCase().padStart(4, "0")}`;
    const argText = args === null ? "" : args.argv.join(", ");
    this.trace.event(`>> ${name}(${argText})${this.program.overlaid.has(masked) ? " [overlay]" : ""}`);
    const ret = this.exec(body, args, entry.varcount);
    this.trace.event(`<< ${name} = ${ret}`);
    return ret;
  }

  // VM_Exec, 引数なしは sEmptyArgs
  exec(pc: number, args: ScriptArgs | null, localVarCount: number): number {
    if (this.execBlock(pc, args ?? { argc: 0, argv: [] }, localVarCount)) return this.result;
    this.result = 0;
    return 0;
  }
}
