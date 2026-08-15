	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08230f94
FUN_08230f94: @ 0x08230F94
  .include "asm/func/FUN_08230f94.inc"

	thumb_func_start FindFile
FindFile: @ 0x08231000
  .include "asm/func/FindFile.inc"

	thumb_func_start GetAssetFile
GetAssetFile: @ 0x0823103C
  .include "asm/func/GetAssetFile.inc"

	thumb_func_start GetDirectory
GetDirectory: @ 0x08231094
  .include "asm/func/GetDirectory.inc"

	thumb_func_start GetFile
GetFile: @ 0x082310CC
  .include "asm/func/GetFile.inc"

