import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";

export const Align4 = `.balign 4, 0`;

export const dumpGlobalSymbol = (label: string): string => {
  return `.global ${label}\n${label}:`;
};

export const dumpU8array = (arr: number[] | Uint8Array, indent: string = "", columns: number = 16): string => {
  if (arr instanceof Uint8Array) arr = Array.from(arr);
  return dumpDataArray(arr, 8, indent, columns);
};

export const dumpU16array = (arr: number[], indent: string = "", columns: number = 16): string => {
  return dumpDataArray(arr, 16, indent, columns);
};

export const dumpU32array = (arr: number[], indent: string = "", columns: number = 8): string => {
  return dumpDataArray(arr, 32, indent, columns);
};

const dumpDataArray = (arr: number[], datasize: 8 | 16 | 32, indent: string, columns: number): string => {
  const directive = datasize === 8 ? ".byte" : datasize === 16 ? ".2byte" : ".4byte";
  const formatFunc = datasize === 8 ? gba.toHex8 : datasize === 16 ? gba.toHex16 : gba.toHex32;

  let output = "";
  for (let i = 0; i < arr.length; i++) {
    if (i % columns === 0) {
      output += indent + directive + " ";
    }
    output += `0x${formatFunc(arr[i])}`;
    if (i % columns === columns - 1 || i === arr.length - 1) {
      output += "\n";
    } else {
      output += ", ";
    }
  }
  return output;
};
