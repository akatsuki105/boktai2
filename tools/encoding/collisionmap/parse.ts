import { Parser } from "@binary-parser";

export type FileHeader = {
  magic: number; // "HP\0\0"
  offsetToTileData: number;
  offsetToZones: number;
  offsetToPaths: number;
  offsetToNavmesh: number;
};

export type TileData = {
  unk_0: number;
  width: number;
  height: number;
  tilemapOffsetX: number;
  tilemapOffsetY: number;
  tiles: number[]; // u32[width * height]
};

export type ZoneData = {
  count: number;
  unk_1: number;
  unk_2: number;
  zones: {
    x1: number;
    y1: number;
    x2: number;
    y2: number;
    z1: number;
    z2: number;
    id: number;
  }[];
};

export type PathData = {
  count: number; // u32
  paths: {
    nodeCount: number; // u16
    nodeOffset: number; // u16
  }[];
  nodes: {
    x: number; // u16
    y: number; // u16
    delay: number; // u8
    param: number; // u8
    command: number; // u16
  }[];
};

export type Navmesh = {
  count: number; // u32
  offsets: number[]; // u32[count]
  islands: {
    countRects: number; // u16
    countPortals: number; // u16
    countDistanceMap: number; // u32 (u16 + pad)
    offsetToRects: number; // u32
    offsetToPortals: number; // u32
    offsetToDistanceMap: number; // u32
    rects: {
      range: number[]; // u8[4], minX, minY, maxX, maxY
      partals: number[]; // u8[12]
    }[]; // rects[countRects]
    portals: {
      x: number; // u16
      y: number; // u16
      unk_4: number; // u16
      rects: number[]; // u8[6]
    }[]; // portals[countPortals]
    distanceMap: number[]; // u16[countDistanceMap]
  }[];
};

export type File = {
  header: FileHeader;
  tileData: TileData;
  zones: ZoneData;
  paths: PathData;
  navmesh: Navmesh;
};

export const ParseFileHeader = (data: Uint8Array): FileHeader => {
  const parser = new Parser()
    .uint32le("magic")
    .uint32le("offsetToTileData")
    .uint32le("offsetToZones")
    .uint32le("offsetToPaths")
    .uint32le("offsetToNavmesh");
  return parser.parse(data);
};

// CollisionMapTileData
export const ParseTileData = (data: Uint8Array): TileData => {
  const parser = new Parser()
    .uint32le("unk_0")
    .int16le("width")
    .int16le("height")
    .int16le("tilemapOffsetX")
    .int16le("tilemapOffsetY")
    .array("tiles", {
      type: "uint32le",
      length: function () {
        // @ts-ignore: shut up
        return this.width * this.height;
      },
    });
  return parser.parse(data);
};

export const ParseZoneData = (data: Uint8Array): ZoneData => {
  const parser = new Parser()
    .uint8("count")
    .uint8("unk_1")
    .uint16le("unk_2")
    .array("zones", {
      type: new Parser()
        .int16le("x1")
        .int16le("y1")
        .int16le("x2")
        .int16le("y2")
        .uint8("z1")
        .uint8("z2")
        .uint16le("id"),
      length: "count",
    });
  return parser.parse(data);
};

export const ParsePathData = (data: Uint8Array): PathData => {
  const parser = new Parser()
    .uint32le("count")
    .array("paths", {
      type: new Parser()
        .uint16le("nodeCount")
        .uint16le("nodeOffset"),
      length: "count",
    })
    .array("nodes", {
      type: new Parser()
        .uint16le("x")
        .uint16le("y")
        .uint8("delay")
        .uint8("param")
        .uint16le("command"),
      length: function () {
        // @ts-ignore: shut up
        return this.paths.reduce((sum: number, path: any) => sum + path.nodeCount, 0);
      },
    });
  return parser.parse(data);
};

export const ParseNavmesh = (data: Uint8Array): Navmesh => {
  const island = new Parser()
    .uint16le("countRects")
    .uint16le("countPortals")
    .uint32le("countDistanceMap")
    .uint32le("offsetToRects")
    .uint32le("offsetToPortals")
    .uint32le("offsetToDistanceMap")
    .array("rects", {
      type: new Parser()
        .array("range", {
          type: "uint8",
          length: 4,
        })
        .array("portals", {
          type: "uint8",
          length: 12,
        }),
      length: "countRects",
    })
    .array("portals", {
      type: new Parser()
        .uint16le("x")
        .uint16le("y")
        .uint16le("unk_4")
        .array("rects", {
          type: "uint8",
          length: 6,
        }),
      length: "countPortals",
    })
    .array("distanceMap", {
      type: "uint16le",
      length: "countDistanceMap",
    });

  const parser = new Parser()
    .uint32le("count")
    .array("offsets", {
      type: "uint32le",
      length: "count",
    })
    .array("islands", {
      type: island,
      length: "count",
    });

  return parser.parse(data);
};

export const ParseFile = (data: Uint8Array): File => {
  const header = ParseFileHeader(data);
  return {
    header,
    tileData: ParseTileData(data.subarray(header.offsetToTileData)),
    zones: ParseZoneData(data.subarray(header.offsetToZones)),
    paths: ParsePathData(data.subarray(header.offsetToPaths)),
    navmesh: ParseNavmesh(data.subarray(header.offsetToNavmesh)),
  };
};
