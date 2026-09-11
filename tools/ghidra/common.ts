import * as gba from "../common/gba/gba.ts";
import { parseSymbolFile } from "../parser/common/symbol.ts";

// GhidraMCP (https://github.com/bethington/ghidra-mcp) が MCP のために立てている HTTP サーバを
// スクリプトからも利用する。pyghidra で GUI の Ghidra を起動している必要がある。
export const BASE_URL = "http://127.0.0.1:8089";

// 引数がアドレスかシンボル名かを判別する。0x 付き、または16進数字だけならアドレス扱い。
const looksLikeAddress = (s: string): boolean => /^(0x)?[0-9A-Fa-f]+$/.test(s);

const isFunctionSymbol = (type: string): boolean => type === "T" || type === "t";

// シンボル名またはROMアドレスの文字列を、Ghidraに渡すROMアドレスに直す。
export const resolveAddress = (target: string): gba.addr => {
  if (looksLikeAddress(target)) {
    const val = parseInt(target.replace(/^0x/i, ""), 16);
    // ファイルオフセットで指定された場合はROMアドレスに直す(tools/bokcc/main.ts と同じ扱い)
    return val < gba.BASE ? val + gba.BASE : val;
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

export const ghidraGet = async (endpoint: string, params: Record<string, string>, timeoutSec: number): Promise<string> => {
  const url = `${BASE_URL}/${endpoint}?${new URLSearchParams(params)}`;
  let res: Response;
  try {
    res = await fetch(url, { signal: AbortSignal.timeout(timeoutSec * 1000) });
  } catch (e) {
    console.error(`エラー: ${BASE_URL} に接続できません(Ghidra を pyghidra で起動していますか?)`);
    console.error(`  ${e instanceof Error ? e.message : String(e)}`);
    Deno.exit(1);
  }
  if (!res.ok) {
    console.error(`エラー: ${res.status} ${res.statusText}`);
    Deno.exit(1);
  }
  return await res.text();
};
