import { Parser } from "npm:binary-parser@2.2.1";

export const Coord = new Parser().endianness("little").int32("x").int32("y");
