import { type BokVM, CLAUSE_CASE, CLAUSE_DEFAULT, CLAUSE_ELIF, CLAUSE_ELSE, MAPCHANGE_BACKUP, MAPCHANGE_LOAD, MAPCHANGE_RESTART, MAPCHANGE_RESTORE, OP, STAT_MAP_INIT_SCRIPT_ID } from "./vm.ts";
import { callChara, callCommand } from "./commands/index.ts";

// 制御命令 (0x60) のハンドラ。src/vm_ctrl1.c と src/vm_ctrl2.c の移植。
// 戻り値が 1 なら, VM_ExecBlock はそこでブロックを打ち切る (return と同じ扱い)。
// ゲーム本体に作用するもの (LoadMap, trap など) は引数を C と同じ順で読んだうえでログに出すだけにしている。

export type CtrlHandler = (vm: BokVM, pc: number) => number;

const hex4 = (n: number) => "0x" + (n & 0xFFFF).toString(16).toUpperCase().padStart(4, "0");

// VM_Ctrl_If_Internal, 条件が真になった最初の分岐のブロックと, それが何番目の分岐か
const ifInternal = (vm: BokVM, pc: number | null): { block: number; branch: number } | null => {
  let branch = 0;
  let type: number;
  let cond: number;
  do {
    const c = vm.decodeValue(pc!);
    pc = c.next;
    cond = c.val;
    do {
      const b = vm.decodeValue(pc!);
      pc = b.next;
      if (cond !== 0) return { block: b.val, branch };
      const l = vm.decodeValue(pc!);
      pc = l.next;
      if (pc === null) return null;
      type = l.type >> 16;
      pc = l.val;
      branch++;
      if (type === CLAUSE_ELSE) cond = 1;
    } while (type === CLAUSE_ELSE);
  } while (type === CLAUSE_ELIF);
  return null;
};

// 0x0D86, if
const ctrlIf: CtrlHandler = (vm, pc) => {
  const hit = ifInternal(vm, pc);
  if (hit === null) {
    vm.trace.note("どの分岐にも入らない");
    return 0;
  }
  vm.trace.note(hit.branch === 0 ? "if の本体へ" : `${hit.branch} 番目の else / else if へ`);
  return vm.execBlock(hit.block, null, 0) ? 1 : 0;
};

// 0x4A6F, switch, フォールスルーしない
const ctrlSwitch: CtrlHandler = (vm, pc) => {
  const head = vm.decodeValue(pc);
  vm.pc = head.next;
  const switchVal = head.val;
  let block: number;
  while (true) {
    const kw = vm.nextLabel();
    if (kw === 0) {
      vm.trace.note(`${switchVal}: 一致する case も default もない`);
      return 0;
    }
    if (kw === CLAUSE_CASE) {
      const caseVal = vm.getValue();
      if (caseVal === switchVal) {
        block = vm.decodeValue(vm.getPC()!).val;
        vm.trace.note(`${switchVal}: case ${caseVal} へ`);
        break;
      }
    } else if (kw === CLAUSE_DEFAULT) {
      block = vm.decodeValue(vm.getPC()!).val;
      vm.trace.note(`${switchVal}: default へ`);
      break;
    }
  }
  return vm.execBlock(block, null, 0) ? 1 : 0;
};

// 0x64C0, 第1オペランドを result に入れるだけ
const ctrlEval: CtrlHandler = (vm, pc) => {
  vm.result = vm.decodeValue(pc).val;
  return 0;
};

// 0x121F, ScriptCall, 呼び先を式で決めるスクリプト呼び出し
// C は VM_ExecByID の戻り値 (スクリプトの戻り値) をそのまま返すので, 呼んだスクリプトが 1 を返すと呼び出し元のブロックも終わる
const ctrlCallIndirect: CtrlHandler = (vm) => {
  const id = vm.getValue();
  const ret = vm.execByID(id, vm.readArgs(vm.getPC()));
  if (ret === 1) vm.trace.note("呼んだスクリプトが 1 を返したので, このブロックも終わる");
  return ret;
};

// 0xCD3A, return
const ctrlReturn: CtrlHandler = (vm) => {
  vm.result = vm.getPC() !== null ? vm.getValue() : 0;
  return 1;
};

// 0xB96E, DebugPrint, 実機では出力先が残っていない
const ctrlDebugPrint: CtrlHandler = (vm, pc) => {
  let p: number | null = pc;
  const texts: string[] = [];
  while (p !== null) {
    const d = vm.decodeValue(p);
    if (d.type === 0) break;
    if (d.type === OP.STRING) texts.push(new TextDecoder("euc-jp").decode(vm.mem.cstring(d.val)));
    p = d.next;
  }
  vm.trace.event(`DebugPrint: ${texts.join(" ")}`);
  return 0;
};

// 0x22FF, Mesg
const ctrlMesg: CtrlHandler = (vm) => {
  const id = vm.getValue() & 0xFFFF;
  const values: number[] = [];
  while (vm.getPC() !== null) values.push(vm.getValue() & 0xFFFF);
  vm.trace.event(`Mesg: ${hex4(id)} 宛て [${values.join(", ")}]`);
  return 0;
};

// 0xB745, Command
const ctrlCommand: CtrlHandler = (vm) => {
  const id = vm.getValue() & 0xFFFF;
  return callCommand(vm, id);
};

// 0x9906, Chara
const ctrlChara: CtrlHandler = (vm) => {
  const id = vm.getValue() & 0xFFFF;
  return callChara(vm, id);
};

// 0xD4CB, SetZoneCallback (trap), ゾーンへの登録はせず読んだ値だけ出す
const ctrlTrap: CtrlHandler = (vm) => {
  const zoneID = vm.getValue() & 0xFFFF;
  const sourceID = vm.getValue() & 0xFFFF;
  const trigger = vm.seekToNamedArg("m") ? vm.getValue() & 0xFFFF : 0xDD2;
  const t = vm.getNamedArgValue("t", 0);
  const readList = (name: string): number[] => {
    const list: number[] = [];
    if (vm.seekToNamedArg(name)) {
      for (let i = 0; i < 4; i++) {
        const pc = vm.getPC();
        if (pc === null) break;
        list.push(vm.getValueAt(pc));
      }
    }
    return list;
  };
  const w = readList("w");
  const s = readList("s");
  const keys = vm.seekToNamedArg("b") ? vm.getValue() : undefined;
  let script = "なし";
  if (vm.seekToNamedArg("e")) {
    script = `ブロック 0x${vm.decodeValue(vm.getPC()!).val.toString(16).toUpperCase()}`;
  } else if (vm.seekToNamedArg("p")) {
    script = `スクリプト ${hex4(vm.getValue())}`;
  }
  vm.trace.event(`SetZoneCallback: zone=${zoneID} source=${hex4(sourceID)} trigger=${hex4(trigger)} t=${t} w=[${w}] s=[${s}]${keys !== undefined ? ` keys=${keys}` : ""} -> ${script}`);
  return 0;
};

// 0xC8BB, LoadMap
const ctrlLoadMap: CtrlHandler = (vm) => {
  const scriptID = vm.getValue() & 0xFFFF;
  vm.mapChangeFlags = MAPCHANGE_LOAD;
  if (!vm.seekToNamedArg("n") || (vm.getPC() !== null && vm.getValue() === 0)) vm.mapChangeFlags |= MAPCHANGE_BACKUP;
  vm.mapInitScriptID = scriptID;
  const name = vm.program.ctx.scriptNames?.get(scriptID) ?? hex4(scriptID);
  vm.trace.event(`LoadMap: ${name}${vm.mapChangeFlags & MAPCHANGE_BACKUP ? " (退避あり)" : ""}`);
  vm.storeStatS32(STAT_MAP_INIT_SCRIPT_ID, scriptID);
  return 0;
};

// 0xE43C, restart, GameSystem_IsMapChangeBlocked は偽とみなす
const ctrlRestart: CtrlHandler = (vm) => {
  vm.mapChangeFlags = MAPCHANGE_RESTART;
  if (vm.seekToNamedArg("s")) {
    vm.mapChangeFlags |= MAPCHANGE_BACKUP;
  } else if (vm.seekToNamedArg("r")) {
    vm.mapChangeFlags |= MAPCHANGE_RESTORE;
  }
  vm.trace.event(`Restart: flags=0x${vm.mapChangeFlags.toString(16).toUpperCase()}`);
  return 0;
};

// gCtrlHandlers1 (vm_ctrl1.c) と gCtrlHandlers2 (vm_ctrl2.c)
export const CTRL_HANDLERS = new Map<number, CtrlHandler>([
  [0x0D86, ctrlIf], // if
  [0x4A6F, ctrlSwitch], // switch
  [0x64C0, ctrlEval], // eval
  [0x121F, ctrlCallIndirect], // call
  [0xCD3A, ctrlReturn], // return
  [0xB96E, ctrlDebugPrint], // print
  [0x22FF, ctrlMesg], // mesg
  [0xB745, ctrlCommand], // command
  [0x9906, ctrlChara], // chara
  [0xD4CB, ctrlTrap], // trap
  [0xC8BB, ctrlLoadMap], // load
  [0x0BB3, () => 0], // VM_Ctrl_Unused_0BB3
  [0xC091, (_, pc) => pc], // map, VM_Ctrl_Unused_C091 は受け取ったポインタをそのまま返す
  [0xE43C, ctrlRestart], // restart
]);
