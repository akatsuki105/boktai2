import { assertEquals, assertStringIncludes } from "@std/assert";
import { loadProgram } from "./loader.ts";
import { WORLD } from "./memory.ts";
import { Tracer } from "./trace.ts";
import { BokVM } from "./vm.ts";

// bokvm の挙動の確認。期待値は src/vm.c, src/vm_expr.c, src/vm_ctrl1.c を読んで決めたもの。
// 手書きのスクリプトを overlay として ROM の ID 1.. に差し込んで実行し, ゲーム状態と result を見る。

const program = loadProgram(new URL("../../baserom.gba", import.meta.url).pathname);

// src を overlay に入れて先頭の定義を実行する, 定義の見出しは Scr_0x0001 から順に付ける
const run = (src: string, args: number[] = []) => {
  program.memory.state.fill(0);
  program.addOverlay(src);
  const lines: string[] = [];
  const trace = new Tracer(program);
  trace.out = (l) => lines.push(l);
  const vm = new BokVM(program, trace);
  const head = /^\s*Scr_0x([0-9A-F]{4})\s*\(\s*\)/m.exec(src)!;
  const ret = vm.execByID(parseInt(head[1], 16), { argc: args.length, argv: args });
  return { vm, ret, lines, trace };
};

const worldS32 = (off: number) => new DataView(program.memory.state.buffer).getInt32(WORLD + off, true);
const worldS16 = (off: number) => new DataView(program.memory.state.buffer).getInt16(WORLD + off, true);
const worldU8 = (off: number) => program.memory.state[WORLD + off];

Deno.test("演算子: 優先順位, 0 方向への切り捨て, 比較と論理演算", () => {
  run(`Scr_0x0001() {
	*((s32 *)(world + 0x0)) = 1 + 2 * 3;
	*((s32 *)(world + 0x4)) = -7 / 2;
	*((s32 *)(world + 0x8)) = -7 % 2;
	*((s32 *)(world + 0xC)) = 3 < 5 && 5 >= 5;
	*((s32 *)(world + 0x10)) = !(0) + ~(0);
	*((s32 *)(world + 0x14)) = -1 >> 28;
}`);
  assertEquals(worldS32(0x0), 7);
  assertEquals(worldS32(0x4), -3);
  assertEquals(worldS32(0x8), -1);
  assertEquals(worldS32(0xC), 1);
  assertEquals(worldS32(0x10), 0);
  assertEquals(worldS32(0x14), 15); // >> は u32 の論理シフト
});

Deno.test("シフト量が 32 以上なら 0 (ARM のレジスタ指定シフト)", () => {
  run(`Scr_0x0001() {
	*((s32 *)(world + 0x0)) = 1 << 32;
	*((s32 *)(world + 0x4)) = 1 << 31;
}`);
  assertEquals(worldS32(0x0), 0);
  assertEquals(worldS32(0x4), -2147483648);
});

Deno.test("メモリ: s16 は符号拡張, u24 は書くと3バイト読むと下位2バイト, BIT はビット単位", () => {
  run(`Scr_0x0001() {
	*((s16 *)(world + 0x0)) = 65535;
	*((s32 *)(world + 0x4)) = *((s16 *)(world + 0x0));
	*((u24 *)(world + 0x8)) = 1193046;
	*((s32 *)(world + 0xC)) = *((u24 *)(world + 0x8));
	BIT(world + 0x10, 3) = 1;
	*((s32 *)(world + 0x14)) = BIT(world + 0x10, 3);
}`);
  assertEquals(worldS32(0x4), -1);
  assertEquals([worldU8(0x8), worldU8(0x9), worldU8(0xA)], [0x56, 0x34, 0x12]);
  assertEquals(worldS32(0xC), 0x3456);
  assertEquals(worldU8(0x10), 0x08);
  assertEquals(worldS32(0x14), 1);
});

Deno.test("メモリ: 添字つき参照は1つ目の添字を無視し, 2つ目を型の大きさで掛ける", () => {
  run(`Scr_0x0001() {
	((s16 *)(world + 0x20))[4, 0] = 11;
	((s16 *)(world + 0x20))[4, 2] = 22;
}`);
  assertEquals(worldS16(0x20), 11);
  assertEquals(worldS16(0x24), 22);
});

Deno.test("引数とローカル変数", () => {
  const { ret } = run(`Scr_0x0001() {
	v1 = p0 + p1;
	v2 = v1 * 2;
	return v2;
}`, [3, 4]);
  assertEquals(ret, 14);
});

Deno.test("switch はフォールスルーせず, 一致しなければ default", () => {
  const src = `Scr_0x0001() {
	switch (p0) {
		case 1: {
			*((s32 *)(world + 0x0)) = 10;
		}
		case 2: {
			*((s32 *)(world + 0x0)) = 20;
		}
		default: {
			*((s32 *)(world + 0x0)) = 99;
		}
	}
}`;
  run(src, [1]);
  assertEquals(worldS32(0x0), 10);
  run(src, [5]);
  assertEquals(worldS32(0x0), 99);
});

Deno.test("if / else if / else", () => {
  const src = `Scr_0x0001() {
	if (p0 == 1) {
		return 10;
	} else if (p0 == 2) {
		return 20;
	} else {
		return 30;
	}
}`;
  assertEquals(run(src, [1]).ret, 10);
  assertEquals(run(src, [2]).ret, 20);
  assertEquals(run(src, [3]).ret, 30);
});

Deno.test("入れ子の内側の return はスクリプトの外まで抜ける", () => {
  const { ret } = run(`Scr_0x0001() {
	if (1) {
		switch (2) {
			case 2: {
				return 5;
			}
		}
	}
	return 6;
}`);
  assertEquals(ret, 5);
});

Deno.test("スクリプト呼び出しの戻り値は result に入る", () => {
  const { ret } = run(`Scr_0x0001() {
	Scr_0x0002(20);
	return result + 1;
}
Scr_0x0002() {
	return p0 * 2;
}`);
  assertEquals(ret, 41);
});

Deno.test("ScriptCall で呼んだスクリプトが 1 を返すと, 呼び出し元のブロックも終わる (C のまま)", () => {
  const { lines } = run(`Scr_0x0001() {
	ScriptCall(2, 0);
	*((s32 *)(world + 0x0)) = 1;
}
Scr_0x0002() {
	return 1;
}`);
  assertEquals(worldS32(0x0), 0);
  assertStringIncludes(lines.join("\n"), "このブロックも終わる");
});

Deno.test("式の中のブロックは, 実行後の result を値にする", () => {
  const { ret } = run(`Scr_0x0001() {
	return { Scr_0x0002(); } + 1;
}
Scr_0x0002() {
	return 9;
}`);
  assertEquals(ret, 10);
});

Deno.test("未実装のコマンドは 0 を返し, --ret の値で変えられる", () => {
  const src = `Scr_0x0001() {
	if ({ Command(0x814C, .i = 1); } == 1) {
		return 1;
	}
	return 2;
}`;
  assertEquals(run(src).ret, 2);

  program.memory.state.fill(0);
  program.addOverlay(src);
  const trace = new Tracer(program);
  trace.out = () => {};
  const vm = new BokVM(program, trace);
  vm.commandResults.set("Cmd_HasItem", 1);
  assertEquals(vm.execByID(1, null), 1);
});

Deno.test("Cmd_InitArray は記述子の位置から順に書く", () => {
  run(`Scr_0x0001() {
	Command(0x7935, BIT(world + 0x30, 0, 8, 0), 1, 0, 1, 1);
}`);
  assertEquals(worldU8(0x30), 0b1101);
});
