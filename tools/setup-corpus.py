#!/usr/bin/env -S uv run python3
"""One-shot: the GBA decomp corpus (shallow clones).

Requires DECOMP_CORPUS env var to be set.
"""

import os
import subprocess
import sys
from pathlib import Path

REPOS = [
    "jellees/bkgr",
    "Normmatt/bof",
    "FireEmblemUniverse/fireemblem6j",
    "FireEmblemUniverse/fireemblem8u",
    "laqieer/fireemblem8j",
    "gsret/goldensun",
    "StanHash/fomt",
    "jiangzhengwenjz/katam",
    "metroidret/mzm",
    "pret/pokeemerald",
    "pret/pokefirered",
    "pret/pmd-red",
    "pret/pokepinballrs",
    "pret/pokeruby",
    "SAT-R/sa2",
    "jiangzhengwenjz/csm3",
    "atasro2/sma2",
    "zeldaret/tmc",
]

corpus_dir = os.environ.get("DECOMP_CORPUS")
if not corpus_dir:
    print("DECOMP_CORPUS is not set — export it before running", file=sys.stderr)
    sys.exit(1)

corpus = Path(corpus_dir)
corpus.mkdir(parents=True, exist_ok=True)
print(f"== decomp corpus (shallow clones into {corpus})")

for repo in REPOS:
    name = repo.split("/")[-1]
    dest = corpus / name
    if dest.exists():
        print(f"skipping {name} (already exists)")
    else:
        print(f"cloning {repo}")
        subprocess.run(["gh", "repo", "clone", repo, "--", "--depth=1"], cwd=corpus, check=True)
