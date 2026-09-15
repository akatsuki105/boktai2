import { Parser } from "@binary-parser";

export type FileHeader = {
  magic: number; // "HP\0\0"
  layerCount: number;
  tileCount: number;
  metatileCount: number;
  loadOffset: number;
  offsetToLayerDefinitions: number;
  offsetToTileset: number;
  offsetToMetatiles: number;
};

const parser = new Parser().endianness("little")
  .uint32("magic")
  .uint16("layerCount")
  .uint16("tileCount")
  .uint16("metatileCount")
  .uint16("loadOffset")
  .uint32("offsetToLayerDefinitions")
  .uint32("offsetToTileset")
  .uint32("offsetToMetatiles");

export const ParseFileHeader = (data: Uint8Array): FileHeader => parser.parse(data);
