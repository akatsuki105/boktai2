# The GBA decomp corpus — grep before you invent

Seventeen mature GBA decompilation repos, most built with the same compiler family (agbcc / GCC 2.9 Thumb). When retail emits an instruction shape you cannot reproduce, grep the corpus for the same shape before contorting your source: someone has usually matched it, and their C is the lever.

| Repo | Game |
|---|---|
| https://github.com/jellees/bkgr | Banjo-Kazooie: Grunty's Revenge |
| https://github.com/Normmatt/bof | Breath of Fire |
| https://github.com/FireEmblemUniverse/fireemblem6j | Fire Emblem: The Binding Blade |
| https://github.com/FireEmblemUniverse/fireemblem8u | Fire Emblem: The Sacred Stones |
| https://github.com/laqieer/fireemblem8j | Fire Emblem: The Sacred Stones (J) |
| https://github.com/gsret/goldensun | Golden Sun |
| https://github.com/StanHash/fomt | Harvest Moon: Friends of Mineral Town |
| https://github.com/jiangzhengwenjz/katam | Kirby & The Amazing Mirror |
| https://github.com/metroidret/mzm | Metroid: Zero Mission |
| https://github.com/pret/pokeemerald | Pokémon Emerald |
| https://github.com/pret/pokefirered | Pokémon FireRed/LeafGreen |
| https://github.com/pret/pmd-red | Pokémon Mystery Dungeon: Red Rescue Team |
| https://github.com/pret/pokepinballrs | Pokémon Pinball: Ruby & Sapphire |
| https://github.com/pret/pokeruby | Pokémon Ruby/Sapphire |
| https://github.com/SAT-R/sa2 | Sonic Advance 2 |
| https://github.com/jiangzhengwenjz/csm3 | Summon Night: Swordcraft Story 3 |
| https://github.com/atasro2/sma2 | Super Mario Advance 2 |
| https://github.com/zeldaret/tmc | The Legend of Zelda: The Minish Cap |

## How to search it

`scripts/corpus-grep.sh 'PATTERN'` greps every corpus repo's `src/` and `asm/`. Typical uses:

- An odd instruction pair in retail (`ands; lsls #24; lsrs #24`) — search corpus asm for it, find which repo matched that function, read their C.
- A macro idiom — search for the macro name family (`SET_`, `RMW`, bitfield inserts) to see how sister projects structured it.
- Compiler-flag archaeology — corpus makefiles show which agbcc variants and flags each game used.

Related deep-dives in this directory: `fe8j-playbook.md` (what the fireemblem8j project's techniques transfer). 
