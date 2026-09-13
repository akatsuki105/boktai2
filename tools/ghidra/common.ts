import * as gba from "../common/gba/gba.ts";
import { parseSymbolFile } from "../parser/common/symbol.ts";
import { findGlobalByName } from "./api/data.ts";

// 引数がアドレスかシンボル名かを判別する。0x 付き、または16進数字だけならアドレス扱い。
const looksLikeAddress = (s: string): boolean => /^(0x)?[0-9A-Fa-f]+$/.test(s);

const isFunctionSymbol = (type: string): boolean => type === "T" || type === "t";

// シンボル名またはROMアドレスの文字列を、Ghidraに渡すROMアドレスに直す。
export const resolveAddress = (target: string): gba.addr => {
  if (looksLikeAddress(target)) {
    return parseInt(target.replace(/^0x/i, ""), 16);
  }

  const sym = parseSymbolFile().find((s) => s.name === target);
  if (!sym) {
    console.error(`エラー: シンボル '${target}' が boktai2.sym に見つかりません`);
    Deno.exit(1);
  }
  // Thumb関数のシンボルは最下位ビットが立っているので落とす
  return isFunctionSymbol(sym.type) ? sym.offset & ~1 : sym.offset;
};

// アドレス -> シンボル名。Thumb関数は最下位ビットを落としたアドレスでも引けるようにする。
export const symbolsByAddress = (): Map<number, string> => {
  const map = new Map<number, string>();
  for (const s of parseSymbolFile()) {
    if (!s.name) continue;
    map.set(s.offset, s.name);
    if (isFunctionSymbol(s.type)) map.set(s.offset & ~1, s.name);
  }
  return map;
};

// アドレスまたはシンボル名の文字列を ROM アドレスに直す。見つからなければ undefined。
// resolveAddress と違い、boktai2.sym にない Ghidra 側だけの名前も引ける。次の順に試す:
//   1. アドレス (0x 付き、または16進数だけ)
//   2. boktai2.sym のシンボル名 (Thumb 関数は最下位ビットを落とす)
//   3. u16_ARRAY_085aa8f0 のように末尾に8桁のアドレスが付いた Ghidra の自動名
//   4. Ghidra のグローバルなデータ名 (list_globals)
export const resolveTarget = async (target: string): Promise<gba.addr | undefined> => {
  if (looksLikeAddress(target)) return parseInt(target.replace(/^0x/i, ""), 16);

  const sym = parseSymbolFile().find((s) => s.name === target);
  if (sym) return isFunctionSymbol(sym.type) ? sym.offset & ~1 : sym.offset;

  const auto = target.match(/_([0-9A-Fa-f]{8})$/);
  if (auto) return parseInt(auto[1], 16);

  return await findGlobalByName(target);
};
