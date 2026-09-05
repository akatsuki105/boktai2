// 'A' = 41        の場合 { char: 'A',       code: [0x41] }
// MEOW5 = 85 00   の場合 { char: '{MEOW5}', code: [0x85, 0x00] }
type CharmapEntry = {
  char: string;
  code: number[];
};

// charmap.txt のパーサ
export const ParseFile = (filename: string): CharmapEntry[] => {
  const charmapFileContent = Deno.readTextFileSync(filename);
  const lines = charmapFileContent.split("\n");
  const charmapEntries: CharmapEntry[] = [];

  // line をパースして charmapEntries に追加する
  for (const line of lines) {
    const entry = ParseLine(line);
    if (entry) charmapEntries.push(entry);
  }

  return charmapEntries;
};

export const ParseLine = (line: string): CharmapEntry | null => {
  const trimmedLine = line.split(" @")[0].trim(); // 先頭以外でもコメントアウト可能 (@ でコメントアウト開始)
  if (!trimmedLine || trimmedLine.startsWith("@") || !trimmedLine.includes("=")) return null;

  if (!trimmedLine.startsWith("'")) {
    // シングルクオートで囲まれていない裸の識別子(定数)。
    const eqIdx = trimmedLine.indexOf("=");
    const name = trimmedLine.slice(0, eqIdx).trim();
    const rhs = trimmedLine.slice(eqIdx + 1).trim();
    const code = rhs.split(/\s+/).filter(Boolean).map((b) => parseInt(b, 16));
    return { char: `{${name}}`, code };
  }

  // LHS が 'X' や '\X' の場合、X 自体が '=' のこともあるため、 単純に最初の '=' で区切らずクォートの終端を見て区切る。
  const closingIdx = trimmedLine[1] === "\\" ? 3 : 2;
  if (closingIdx >= trimmedLine.length || trimmedLine[closingIdx] !== "'") return null;

  const lhs = trimmedLine.slice(0, closingIdx + 1);
  const rhs = trimmedLine.slice(closingIdx + 1).split("=")[1].trim();
  const char = lhs.slice(1, -1);
  const code = rhs.split(/\s+/).filter(Boolean).map((b) => parseInt(b, 16));

  return { char, code };
};
