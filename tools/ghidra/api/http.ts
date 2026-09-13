// GhidraMCP (https://github.com/bethington/ghidra-mcp) が立てている HTTP サーバの呼び出し。
// GUI の Ghidra が起動している必要がある。
// ここの関数は失敗しても終了せず例外を投げる。エラーの扱いは呼び出し側で決める。

export const BASE_URL = Deno.env.get("GHIDRA_MCP_URL") ?? "http://127.0.0.1:8089";

// GET で呼び出し、応答の本文をそのまま返す。
export const get = async (endpoint: string, params: Record<string, string>, timeoutSec: number): Promise<string> => {
  const url = `${BASE_URL}/${endpoint}?${new URLSearchParams(params)}`;
  let res: Response;
  try {
    res = await fetch(url, { signal: AbortSignal.timeout(timeoutSec * 1000) });
  } catch (e) {
    throw new Error(`${BASE_URL} に接続できません(Ghidra は起動していますか?): ${e instanceof Error ? e.message : String(e)}`);
  }
  const text = await res.text();
  if (!res.ok) {
    throw new Error(`${endpoint}: ${res.status} ${res.statusText}: ${text.trim()}`);
  }
  return text;
};

// JSON を body にして POST で呼び出し、応答の本文をそのまま返す。
export const post = async (endpoint: string, body: Record<string, unknown>, timeoutSec: number): Promise<string> => {
  let res: Response;
  try {
    res = await fetch(`${BASE_URL}/${endpoint}`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(body),
      signal: AbortSignal.timeout(timeoutSec * 1000),
    });
  } catch (e) {
    throw new Error(`${BASE_URL} に接続できません(Ghidra は起動していますか?): ${e instanceof Error ? e.message : String(e)}`);
  }
  const text = await res.text();
  if (!res.ok) {
    throw new Error(`${endpoint}: ${res.status} ${res.statusText}: ${text.trim()}`);
  }
  return text;
};
