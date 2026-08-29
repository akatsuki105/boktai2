export type addr = number;
export const BASE: addr = 0x08000000;

export const [SCR_W, SCR_H] = [240, 160];

export const getU8 = (rom: DataView, address: addr) => rom.getUint8(address - BASE);
export const getS8 = (rom: DataView, address: addr) => rom.getInt8(address - BASE);
export const getU16 = (rom: DataView, address: addr) => rom.getUint16(address - BASE, true);
export const getU16BE = (rom: DataView, address: addr) => rom.getUint16(address - BASE, false);
export const getS16 = (rom: DataView, address: addr) => rom.getInt16(address - BASE, true);
export const getU32 = (rom: DataView, address: addr) => rom.getUint32(address - BASE, true);
export const getS32 = (rom: DataView, address: addr) => rom.getInt32(address - BASE, true);
export const getSlice = (rom: DataView, address: addr, bytesize: number): ArrayBufferLike => rom.buffer.slice(address - BASE, address - BASE + bytesize);

export const toHex = (val: number, maxLength: number): string => {
  const abs = Math.abs(val);
  return abs.toString(16).toUpperCase().padStart(maxLength, "0");
};

export const toHex8 = (val: number): string => toHex(val, 2);
export const toHex16 = (val: number): string => toHex(val, 4);
export const toHex32 = (val: number): string => toHex(val, 8);

// "U32J" や "BZ3J" みたいな、4バイトの文字列
export const getGameCode = (rom: DataView): string => {
  const idBytes = new Uint8Array(rom.buffer.slice(0xAC, 0xB0));
  return String.fromCharCode(...idBytes);
};

export const getGameRevision = (rom: DataView): number => {
  return rom.getUint8(0xBC);
};

export const getGameID = (rom: DataView): string => {
  const gamecode = getGameCode(rom); // e.g. "BZ3J"
  const revision = getGameRevision(rom); // e.g. 0, 1
  if (revision !== 0) {
    return `${gamecode}_rev${revision}`; // e.g. "BZ3J_rev1"
  } else {
    return gamecode; // e.g. "BZ3J"
  }
};
