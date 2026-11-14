import type { BokVM } from "../vm.ts";
import { scriptCommands } from "./script_utility.ts";

// gCommandList のコマンド。Command (0xB745) と Chara (0x9906) から呼ばれる。
//
// 中身を移植したものだけ HANDLERS に入れ, それ以外は何もしないスタブにする。
// スタブの戻り値は 0 で, --ret Cmd_HasItem=1 のように名前ごとに変えられる。
// 移植は src/ の同名の関数を写す。引数は C と同じく vm.getValue() / vm.seekToNamedArg() で, 読む順番も C に合わせること。

// Command から呼ぶときは param なし, Chara から呼ぶときは u16 の値が1つ入る
export type CommandHandler = (vm: BokVM, param?: number) => number;

const HANDLERS = new Map<string, CommandHandler>([
  ...scriptCommands,
]);

const commandName = (vm: BokVM, id: number): string | undefined => vm.program.ctx.commandNames?.get(id);

const stubResult = (vm: BokVM, name: string): number => vm.commandResults.get(name) ?? 0;

// VM_Ctrl_CallSubroutine, 戻り値は result に入る, 表に無い ID は -1 を返すだけで result は変えない
export const callCommand = (vm: BokVM, id: number): number => {
  const name = commandName(vm, id);
  if (name === undefined) {
    vm.trace.warn(`コマンド 0x${id.toString(16).toUpperCase()} は gCommandList にありません`);
    return -1;
  }
  const handler = HANDLERS.get(name);
  if (handler !== undefined) {
    vm.result = handler(vm) | 0;
    vm.trace.note(`${name} -> ${vm.result}`);
  } else {
    vm.result = stubResult(vm, name) | 0;
    vm.trace.note(`${name} -> ${vm.result} (未実装)`);
  }
  return 0;
};

// VM_Ctrl_CreateEntity, 2つ目の値を u16 にして渡す, 戻り値は捨てる
export const callChara = (vm: BokVM, id: number): number => {
  const name = commandName(vm, id);
  if (name === undefined) {
    vm.trace.warn(`コマンド 0x${id.toString(16).toUpperCase()} は gCommandList にありません`);
    return -1;
  }
  const param = vm.getValue() & 0xFFFF;
  const handler = HANDLERS.get(name);
  if (handler !== undefined) {
    handler(vm, param);
  } else {
    vm.trace.note(`${name}(${param}) (未実装)`);
  }
  return 0;
};
