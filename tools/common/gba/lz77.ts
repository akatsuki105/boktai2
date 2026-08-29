/**
 * Decompresse LZ77 compressed data.
 * @param srcbuf Compressed data
 * @returns `Uint8Array` of decompressed data
 */
export const decompressLZ77 = (srcbuf: ArrayBufferLike): ArrayBufferLike => {
  let ofs = 0;
  const src = new Uint8Array(srcbuf);
  const id = src[ofs++];
  if (id !== 0x10) {
    return new ArrayBuffer(0);
  }
  const decompressedSize = src[ofs] | (src[ofs + 1] << 8) | (src[ofs + 2] << 16);
  ofs += 3;
  const result = new Uint8Array(decompressedSize);
  let resultOfs = 0;

  const BUFFER_LENGTH = 0x1000;
  const buffer = new Uint8Array(BUFFER_LENGTH);
  let bufferOffset = 0;
  let currentOutsize = 0;
  let flags = 0;
  let mask = 1;

  while (currentOutsize < decompressedSize) {
    if (mask == 1) {
      flags = src[ofs++] & 0xff;
      mask = 0x80;
    } else {
      mask = mask >> 1;
    }

    if ((flags & mask) > 0) {
      const byte1 = src[ofs++];
      const byte2 = src[ofs++];
      const len = (byte1 >> 4) + 3;
      const disp = (((byte1 & 0xf) << 8) | byte2) + 1;
      if (disp > currentOutsize) {
        throw new Error(`Size Error: ${disp} > ${currentOutsize}`);
      }

      let bufIdx = bufferOffset + BUFFER_LENGTH - disp;
      for (let i = 0; i < len; i++) {
        const next = buffer[bufIdx % BUFFER_LENGTH];
        bufIdx++;
        result[resultOfs++] = next;
        buffer[bufferOffset] = next;
        bufferOffset = (bufferOffset + 1) % BUFFER_LENGTH;
      }
      currentOutsize += len;
    } else {
      const next = src[ofs++];
      currentOutsize++;
      result[resultOfs++] = next;
      buffer[bufferOffset] = next;
      bufferOffset = (bufferOffset + 1) % BUFFER_LENGTH;
    }
  }

  return result.buffer;
};
