export * from "./parse.ts";

export const MAGIC = 0x00005048; // "HP\0\0" in little-endian

export const CheckMagic = (data: Uint8Array, offset = 0): boolean => data[offset] === 0x48 && data[offset + 1] === 0x50; // "HP" in little-endian
