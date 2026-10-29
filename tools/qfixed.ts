#!/usr/bin/env -S deno run

import { Command } from "@cliffy/command";

// C の (s32)((x) * (1 << frac)) と同じく 0 方向に切り捨てる
const toRaw = (x: number, frac: number): number => Math.trunc(x * 2 ** frac);

// (s32)(x * 2^frac) == raw になる x のうち, 10進数で一番短いものを返す
const shortestDecimal = (raw: number, frac: number): string => {
  const exact = raw / 2 ** frac;
  // 2^frac の逆数は小数点以下 frac 桁で必ず表せるので, frac 桁までで見つかる
  for (let digits = 0; digits <= frac; digits++) {
    const candidates = [exact.toFixed(digits)];
    // 切り捨てなので, 四捨五入した値がわずかに足りないときは 1 桁上げた値も試す
    const unit = 10 ** -digits;
    candidates.push((Number(candidates[0]) + Math.sign(raw) * unit).toFixed(digits));
    for (const s of candidates) {
      if (toRaw(Number(s), frac) === raw) return String(Number(s));
    }
  }
  return String(exact);
};

const parseInteger = (s: string): number => {
  const neg = s.startsWith("-");
  const body = neg ? s.slice(1) : s;
  const v = /^0x[0-9a-f]+$/i.test(body) ? parseInt(body, 16) : /^\d+$/.test(body) ? parseInt(body, 10) : NaN;
  if (Number.isNaN(v)) throw new Error(`整数として読めません: ${s}`);
  return neg ? -v : v;
};

const main = () => {
  new Command()
    .name("qfixed.ts")
    .description("固定小数の生の値を Q<frac>(x) の形に直します。x は (s32)(x * 2^frac) が元の値に戻る一番短い10進数です。")
    .example("小数部 8 ビット", "tools/qfixed.ts 8 128 256 0x82  # -> Q8(0.5), Q8(1), Q8(0.51)")
    .argument("<frac:integer>", "小数部のビット数")
    .argument("<values...:string>", "生の値 (10進数か 0x で始まる16進数, 負数も可)")
    .action((_, fracBits, ...values) => {
      const out = values.map((s) => `Q${fracBits}(${shortestDecimal(parseInteger(s), fracBits)})`);
      console.log(out.join(", "));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
