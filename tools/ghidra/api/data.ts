import { get, post } from "./http.ts";

const toHexAddr = (addr: number): string => `0x${addr.toString(16).toUpperCase().padStart(8, "0")}`;

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

// GhidraMCP の書き込み系エンドポイントの応答。status/success のどちらかで成否を返してくる。
// warnings は Strict Naming Enforcement が無効なときの「本来なら拒否した」という注意書き。
type WriteResponse = { ok: boolean; message: string; warnings: string[] };

const parseWriteResponse = (endpoint: string, text: string): WriteResponse => {
  let json: Record<string, unknown>;
  try {
    json = JSON.parse(text);
  } catch {
    // JSON を返さず素のメッセージだけ返すエンドポイントもある (rename_variable など)
    return { ok: true, message: text.trim(), warnings: [] };
  }
  if (typeof json.error === "string") {
    throw new Error(`${endpoint}: ${json.error}`);
  }
  const ok = json.status === "success" || json.success === true;
  const warnings = Array.isArray(json.warnings) ? json.warnings.map(String) : [];
  return { ok, message: String(json.message ?? text.trim()), warnings };
};

// addr にあるデータをリネームする (rename_data)。
// dry_run は受け付けない (GhidraMCP-6.0.0 のハンドラが読んでいない) ので、
// 呼び出し側で auditGlobal による前後比較をすること。
export const renameData = async (addr: number, newName: string, timeoutSec: number = 60): Promise<WriteResponse> => {
  const text = await post("rename_data", { address: toHexAddr(addr), new_name: newName }, timeoutSec);
  return parseWriteResponse("rename_data", text);
};

// addr にあるデータに型を適用する (apply_data_type)。
// 注意: ポインタ型や配列型を当てると Ghidra が名前を自動で付け替えることがある。
// 名前を保ちたい場合は呼び出し側で控えておき、変わっていたら renameData で戻すこと。
export const applyDataType = async (addr: number, typeName: string, timeoutSec: number = 60): Promise<WriteResponse> => {
  const text = await post("apply_data_type", { address: toHexAddr(addr), type_name: typeName }, timeoutSec);
  return parseWriteResponse("apply_data_type", text);
};
