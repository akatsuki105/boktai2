import { Parser } from "@binary-parser";

const toHex = (val: number, maxLength: number): string => Math.abs(val).toString(16).toUpperCase().padStart(maxLength, "0");
const toHex8 = (val: number): string => toHex(val, 2);
const toHex16 = (val: number): string => toHex(val, 4);
const toHex32 = (val: number): string => toHex(val, 8);

export type FileHeader = {
  magic: number; // "HP\0\0"
  layerCount: number;
  tileCount: number;
  metatileCount: number;
  loadOffset: number;
  offsetToLayerDefinitions: number;
  offsetToTileset: number;
  offsetToMetatiles: number;
  layers: { width: number; height: number; id: number; mtmap: number }[]; // length is layerCount
};

export type File = {
  header: FileHeader;
  tiles?: Uint8Array;
  metatiles: Uint16Array;
  mtmap: Uint16Array;
};

export const ParseFileHeader = (data: Uint8Array): FileHeader => {
  const parser = new Parser()
    .uint32le("magic")
    .uint16le("layerCount")
    .uint16le("tileCount")
    .uint16le("metatileCount")
    .uint16le("loadOffset")
    .uint32le("offsetToLayerDefinitions")
    .uint32le("offsetToTileset")
    .uint32le("offsetToMetatiles")
    .array("layers", {
      type: new Parser()
        .uint16le("width")
        .uint16le("height")
        .uint32le("id")
        .uint32le("mtmap"),
      length: "layerCount",
    });
  return parser.parse(data);
};

export const ParseFile = (data: Uint8Array): File => {
  const header = ParseFileHeader(data);
  return {
    header: header,
    tiles: header.offsetToTileset > 0 ? new Uint8Array(data.slice(header.offsetToTileset, header.offsetToTileset + header.tileCount * 32)) : undefined,
    metatiles: new Uint16Array(data.slice(header.offsetToMetatiles, header.offsetToMetatiles + (header.metatileCount * 8)).buffer),
    mtmap: new Uint16Array(data.slice(header.offsetToMetatiles + (header.metatileCount * 8)).buffer),
  };
};

export const Macros = `.macro layer id:req, base:req, width:req, height:req
  .2byte (\\width * 16), (\\height * 16)
  .4byte (\\id)
  .4byte (\\base)-Header
.endm
`;

export const StringifyFileHeaderAsm = (header: FileHeader): string[] => {
  const lines: string[] = [];
  lines.push(`  .4byte 0x${toHex16(header.magic)} @ magic: MP`);
  lines.push(`  .2byte ${header.layerCount} @ layerCount`);
  lines.push(`  .2byte ${header.tileCount} @ tileCount`);
  lines.push(`  .2byte ${header.metatileCount} @ metatileCount`);
  lines.push(`  .2byte 0x${toHex16(header.loadOffset)} @ loadOffset`);
  lines.push(`  .4byte ${header.offsetToLayerDefinitions} @ offsetToLayerDefinitions`);
  lines.push(`  .4byte ${header.offsetToTileset} @ offsetToTileset`);
  lines.push(`  .4byte ${header.offsetToMetatiles} @ offsetToMetatiles`);

  lines.push(`Layers:`);
  const mtmapOffset = header.offsetToMetatiles + (header.metatileCount * 8);
  let mtmapLength = 0;
  for (let i = 0; i < header.layers.length; i++) {
    lines.push(`  ${StringifyLayerAsm(header.layers[i], mtmapOffset)}`);
    mtmapLength += header.layers[i].width * header.layers[i].height;
  }
  return lines;
};

// layer ${id}, ${base}, ${width/16}, ${height/16}
const StringifyLayerAsm = (layer: { width: number; height: number; id: number; mtmap: number }, from: number): string => {
  if (layer.width % 16 !== 0 || layer.height % 16 !== 0) {
    throw new Error(`Layer dimensions must be multiples of 16: width=${layer.width}, height=${layer.height}`);
  }
  if (layer.id > 0xFFFF) {
    throw new Error(`Layer ID ${layer.id} exceeds 16-bit limit`);
  }
  const offset = layer.mtmap - from;
  if (offset % 512 !== 0) {
    throw new Error(`Layer mtmap offset ${offset} is not aligned to 512 bytes`);
  }
  const block = offset / 512;
  return `layer 0x${toHex16(layer.id & 0xFFFF)}, MetatileMap${block}, ${layer.width >> 4}, ${layer.height >> 4}`;
};
