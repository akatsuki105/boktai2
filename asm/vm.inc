	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0823193c
FUN_0823193c: @ 0x0823193C
  .include "asm/func/FUN_0823193c.inc"

	thumb_func_start Textbox_LookupString
Textbox_LookupString: @ 0x08231978
  .include "asm/func/Textbox_LookupString.inc"

@ 引数: gScriptDirectory (0x08cbf248)
	thumb_func_start Script_LoadIndex
Script_LoadIndex: @ 0x082319A8
  .include "asm/func/Script_LoadIndex.inc"

	thumb_func_start FUN_08231a74
FUN_08231a74: @ 0x08231A74
  .include "asm/func/FUN_08231a74.inc"

	thumb_func_start FUN_08231a80
FUN_08231a80: @ 0x08231A80
  .include "asm/func/FUN_08231a80.inc"

	thumb_func_start FUN_08231aa8
FUN_08231aa8: @ 0x08231AA8
  .include "asm/func/FUN_08231aa8.inc"

	thumb_func_start Script_ExecBlock
Script_ExecBlock: @ 0x08231AD0
  .include "asm/func/Script_ExecBlock.inc"

	thumb_func_start Script_ExecByPointer
Script_ExecByPointer: @ 0x08231B58
  .include "asm/func/Script_ExecByPointer.inc"

	thumb_func_start Script_Exec
Script_Exec: @ 0x08231B7C
  .include "asm/func/Script_Exec.inc"

	thumb_func_start FUN_08231ba8
FUN_08231ba8: @ 0x08231BA8
  .include "asm/func/FUN_08231ba8.inc"

	thumb_func_start FUN_08231bcc
FUN_08231bcc: @ 0x08231BCC
  .include "asm/func/FUN_08231bcc.inc"

	thumb_func_start FUN_08231be0
FUN_08231be0: @ 0x08231BE0
  .include "asm/func/FUN_08231be0.inc"

	thumb_func_start FUN_08231bec
FUN_08231bec: @ 0x08231BEC
  .include "asm/func/FUN_08231bec.inc"

	thumb_func_start FUN_08231c1c
FUN_08231c1c: @ 0x08231C1C
  .include "asm/func/FUN_08231c1c.inc"

	thumb_func_start RandomizeGameStateAddr
RandomizeGameStateAddr: @ 0x08231C28
  .include "asm/func/RandomizeGameStateAddr.inc"

	thumb_func_start FUN_08231c80
FUN_08231c80: @ 0x08231C80
  .include "asm/func/FUN_08231c80.inc"

	thumb_func_start FUN_08231ca8
FUN_08231ca8: @ 0x08231CA8
  .include "asm/func/FUN_08231ca8.inc"

	thumb_func_start Save_BackupStatAndWorld
Save_BackupStatAndWorld: @ 0x08231CEC
  .include "asm/func/Save_BackupStatAndWorld.inc"

	thumb_func_start RestoreGameState
RestoreGameState: @ 0x08231D24
  .include "asm/func/RestoreGameState.inc"

	thumb_func_start FUN_08231d5c
FUN_08231d5c: @ 0x08231D5C
  .include "asm/func/FUN_08231d5c.inc"

	thumb_func_start FUN_08231d80
FUN_08231d80: @ 0x08231D80
  .include "asm/func/FUN_08231d80.inc"

	thumb_func_start FUN_08231d98
FUN_08231d98: @ 0x08231D98
  .include "asm/func/FUN_08231d98.inc"

	thumb_func_start Script_LoadPointer
Script_LoadPointer: @ 0x08231DB0
  .include "asm/func/Script_LoadPointer.inc"

	thumb_func_start ReadMemory
ReadMemory: @ 0x08231E54
  .include "asm/func/ReadMemory.inc"

	thumb_func_start Script_StorePointerCore
Script_StorePointerCore: @ 0x08231EF0
  .include "asm/func/Script_StorePointerCore.inc"

	thumb_func_start Script_StorePointer
Script_StorePointer: @ 0x08231F88
  .include "asm/func/Script_StorePointer.inc"

	thumb_func_start FUN_0823201c
FUN_0823201c: @ 0x0823201C
  .include "asm/func/FUN_0823201c.inc"

	thumb_func_start FUN_0823206c
FUN_0823206c: @ 0x0823206C
  .include "asm/func/FUN_0823206c.inc"

	thumb_func_start FUN_082320e4
FUN_082320e4: @ 0x082320E4
  .include "asm/func/FUN_082320e4.inc"
