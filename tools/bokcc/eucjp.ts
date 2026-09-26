// EUC-JP のエンコード/デコード。
//
// デコードは TextDecoder("euc-jp") がそのまま使えるが、TextEncoder は仕様上 UTF-8 しか出せないので
// エンコード側だけ自前で用意する。表を手で持つ代わりに、デコーダに全バイト列を一度食わせて逆引き表を作る
// (デコーダと必ず整合するうえ、表のメンテが要らない)。
//
// EUC-JP のバイト構成:
//   0x00-0x7F               ASCII
//   0xA1-0xFE + 0xA1-0xFE   JIS X 0208 (漢字・かな)
//   0x8E     + 0xA1-0xDF    JIS X 0201 (半角カナ)
//   0x8F     + 0xA1-0xFE ×2 JIS X 0212 (補助漢字)

const decoder = new TextDecoder("euc-jp");

const REPLACEMENT = "�";

// 逆引き表は実際に非ASCIIを触るまで作らない(純ASCIIしか出てこないスクリプトでは無駄になるため)
let encodeTable: Map<string, Uint8Array> | null = null;

// 表に載せる候補バイト列を、上の3つの範囲ぶん並べる
const candidates = (): Uint8Array[] => {
  const seqs: Uint8Array[] = [];
  for (let lead = 0xA1; lead <= 0xFE; lead++) {
    for (let trail = 0xA1; trail <= 0xFE; trail++) seqs.push(new Uint8Array([lead, trail]));
  }
  for (let b = 0xA1; b <= 0xDF; b++) seqs.push(new Uint8Array([0x8E, b]));
  for (let lead = 0xA1; lead <= 0xFE; lead++) {
    for (let trail = 0xA1; trail <= 0xFE; trail++) seqs.push(new Uint8Array([0x8F, lead, trail]));
  }
  return seqs;
};

// 候補を1本に連結して1回でデコードする。各列は自己区切りなので i 番目の文字が i 番目の列に対応する。
// 対応が崩れた場合(未知のデコーダ挙動)は1列ずつのデコードに落とす。
const decodeAll = (seqs: Uint8Array[]): string[] => {
  const total = seqs.reduce((n, s) => n + s.length, 0);
  const buf = new Uint8Array(total);
  let at = 0;
  for (const s of seqs) {
    buf.set(s, at);
    at += s.length;
  }
  const joined = [...decoder.decode(buf)];
  if (joined.length === seqs.length) return joined;
  return seqs.map((s) => decoder.decode(s));
};

const table = (): Map<string, Uint8Array> => {
  if (encodeTable) return encodeTable;
  const seqs = candidates();
  const chars = decodeAll(seqs);
  const m = new Map<string, Uint8Array>();
  for (let i = 0; i < seqs.length; i++) {
    const ch = chars[i];
    // 未割り当ての符号位置は U+FFFD になる。先に入ったバイト列を優先して重複を避ける
    if (ch.length === 0 || ch === REPLACEMENT || m.has(ch)) continue;
    m.set(ch, seqs[i]);
  }
  encodeTable = m;
  return m;
};

// 1文字を EUC-JP のバイト列にする。表に無ければ null
export const encodeChar = (ch: string): Uint8Array | null => {
  const cp = ch.codePointAt(0);
  if (cp === undefined) return null;
  if (cp < 0x80) return new Uint8Array([cp]);
  return table().get(ch) ?? null;
};

// bytes[i] から始まる1文字を読む。読めて、かつ同じバイト列に戻せるときだけ返す
// (戻せない文字を可読化するとコンパイル結果がROMと変わってしまうため)
export const readChar = (bytes: Uint8Array, i: number): { ch: string; len: number } | null => {
  const b = bytes[i];
  let len: number;
  if (b === 0x8F) len = 3;
  else if (b === 0x8E || (b >= 0xA1 && b <= 0xFE)) len = 2;
  else return null;
  if (i + len > bytes.length) return null;

  const seq = bytes.subarray(i, i + len);
  const decoded = [...decoder.decode(seq)];
  if (decoded.length !== 1 || decoded[0] === REPLACEMENT) return null;

  const ch = decoded[0];
  const back = encodeChar(ch);
  if (!back || back.length !== len) return null;
  for (let k = 0; k < len; k++) {
    if (back[k] !== seq[k]) return null;
  }
  return { ch, len };
};
