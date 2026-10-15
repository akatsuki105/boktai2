export * from "./file.ts";

export const MAGIC = 0x0000504D; // "MP\0\0" in little-endian

export const CheckMagic = (data: Uint8Array, offset = 0): boolean => data[offset] === 0x4D && data[offset + 1] === 0x50; // "MP"
