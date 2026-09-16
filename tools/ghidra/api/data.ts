import { get } from "./http.ts";

// Ghidra 上で定義されているグローバルなデータ1つ分の情報
export type GlobalInfo = {
  address: number;
  name: string; // シンボル名
  type: string; // データ型の表示名 (e.g. "ArmorData[37]", "u16[9]")
  length: number; // バイト数
  xrefCount: number; // 参照している箇所の数
};

// Ghidra 上のグローバルなデータシンボルを名前で探し、アドレスを返す (list_globals)。見つからなければ undefined。
// list_globals は Ghidra が自動で付けた名前 (u16_ARRAY_085aa8f0 など) を返さないことがある。
export const findGlobalByName = async (name: string, timeoutSec: number = 60): Promise<number | undefined> => {
  const text = await get("list_globals", { name_substring: name, limit: "100" }, timeoutSec);
  for (const line of text.split("\n")) {
    const m = line.match(/^(\S+) @ ([0-9A-Fa-f]+)/);
    if (m && m[1] === name) return parseInt(m[2], 16);
  }
  return undefined;
};

// addr から始まるデータの名前と型を返す (GhidraMCP の audit_global)。
// audit_global はデータの先頭アドレスしか受け付けない。データの途中や未定義の場所を指したときは例外を投げる。
// 応答の issues などは GhidraMCP 独自の命名規則 (g_ 接頭辞など) による判定なので捨てる。
export const auditGlobal = async (addr: number, timeoutSec: number = 60): Promise<GlobalInfo> => {
  const hex = `0x${addr.toString(16).toUpperCase().padStart(8, "0")}`;
  const text = await get("audit_global", { address: hex }, timeoutSec);
  let json: Record<string, unknown>;
  try {
    json = JSON.parse(text);
  } catch {
    throw new Error(`audit_global: JSON ではない応答が返りました: ${text.trim()}`);
  }
  if (typeof json.error === "string") {
    throw new Error(`audit_global: ${json.error}`);
  }
  if (!json.type || !json.length) {
    throw new Error(`audit_global: ${hex} から始まるデータが定義されていません`);
  }
  return {
    address: parseInt(String(json.address), 16),
    name: String(json.name ?? ""),
    type: String(json.type),
    length: Number(json.length),
    xrefCount: Number(json.xref_count ?? 0),
  };
};
