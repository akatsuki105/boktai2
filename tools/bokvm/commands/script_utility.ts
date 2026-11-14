import { type BokVM, OP } from "../vm.ts";
import * as M from "../memory.ts";
import type { CommandHandler } from "./index.ts";

// VM そのものに近いコマンド。スクリプトの流れや変数・メモリだけで完結するので, ゲーム本体なしでも C と同じに動かせる。

// VM_ReadMemoryRef で写したメモリ参照の記述子 (8バイト)
type MemoryRef = { desc: number[]; a: number; b: number };

// VM_GetMemoryRef (VM_ReadMemoryRef), Indexed なら添字2つを s16 で持つ, そうでなければ (1, 0)
const getMemoryRef = (vm: BokVM): MemoryRef => {
  const pc = vm.getPC();
  if (pc === null) throw new Error("メモリ参照を読む位置に引数がありません");
  const desc = [0, 1, 2, 3].map((i) => vm.mem.u8(pc + i));
  if ((desc[0] & 0xF0) === OP.MEMORY_INDEXED) {
    const a = vm.decodeValue(pc + 4);
    const b = vm.decodeValue(a.next!);
    vm.pc = b.next;
    return { desc, a: (a.val << 16) >> 16, b: (b.val << 16) >> 16 };
  }
  vm.pc = pc + 4;
  return { desc, a: 1, b: 0 };
};

// VM_StoreMemoryRef, Indexed の添字は記述子の +6 を u16 で足す
const storeMemoryRef = (vm: BokVM, ref: MemoryRef, offset: number, val: number): void => {
  const cmd = ((ref.desc[0] << 24) | (ref.desc[1] << 16) | (ref.desc[2] << 8) | ref.desc[3]) >>> 0;
  const base = M.regionBaseOf(ref.desc[1]) + (cmd & 0xFFFF);
  if (((cmd >>> 24) & 0xF0) === OP.MEMORY_INDEXED) offset += ref.b & 0xFFFF;
  vm.storePointerCore(base, cmd, offset, val);
};

// VM_ExecByPointer
const execByPointer = (vm: BokVM, pc: number, argv: number[]): number => {
  if (vm.execBlock(pc, { argc: argv.length, argv }, 0)) return vm.result;
  vm.result = 0;
  return 0;
};

// 0x7935, Cmd_InitArray (src/script_utility.c)
const initArray: CommandHandler = (vm) => {
  const ref = getMemoryRef(vm);
  for (let i = 0; vm.getPC() !== null; i++) storeMemoryRef(vm, ref, i, vm.getValue());
  return 0;
};

// 0x7636, Cmd_ForEach (src/script_utility.c), 'a' 個の引数を読み直しながら 'e' のブロックを 'r' 回呼ぶ
const forEach: CommandHandler = (vm) => {
  vm.seekToNamedArg("a");
  const count = vm.getValue();
  vm.seekToNamedArg("r");
  const repeat = vm.getValue();
  if (!vm.seekToNamedArg("e")) return 0;
  const script = vm.getValue();
  vm.seekToNamedArg("d");
  let pc = vm.getPC();
  for (let i = 0; i < repeat; i++) {
    const argv: number[] = [];
    for (let j = 0; j < count; j++) {
      argv.push(vm.getValueAt(pc));
      pc = vm.getPC();
    }
    execByPointer(vm, script, argv);
  }
  return 0;
};

// 0xEC1F, Cmd_Assert (src/vm.c), 偽でも何もしない
const assert: CommandHandler = (vm) => {
  if (!vm.getValue()) {
    vm.getValueSafe();
    vm.trace.note("assert が偽");
  }
  return 0;
};

// 0x430D, Cmd_Delay (src/delay.c), 't' フレーム後に 'e' のブロックか 'p' のスクリプトを実行する TimerEntity を作る
// フレームを進める仕組みは無いので, 予約された内容をログに出すだけにしている
const delay: CommandHandler = (vm, mesgID = 0) => {
  const frames = vm.seekToNamedArg("t") ? vm.getValue() : 0;
  let target = "なし";
  if (vm.seekToNamedArg("e")) {
    target = `ブロック 0x${vm.decodeValue(vm.getPC()!).val.toString(16).toUpperCase()}`;
  } else if (vm.seekToNamedArg("p")) {
    target = `スクリプト 0x${(vm.getValue() & 0xFFFF).toString(16).toUpperCase().padStart(4, "0")}`;
  }
  const argv: number[] = [];
  if (vm.seekToNamedArg("a")) {
    while (argv.length < 8 && vm.getPC() !== null) argv.push(vm.getValue());
  }
  vm.trace.event(`Delay: ${frames} フレーム後に ${target}(${argv.join(", ")}) を予約 (mesg=${mesgID}, 実行はしない)`);
  return 0;
};

export const scriptCommands: [string, CommandHandler][] = [
  ["Cmd_InitArray", initArray],
  ["Cmd_ForEach", forEach],
  ["Cmd_Assert", assert],
  ["Cmd_Delay", delay],
];
