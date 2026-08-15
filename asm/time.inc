	.include "asm/macros.inc"
	.syntax unified
	.text

@ 多分、緯度経度に基づいた計算処理 (f64 を多用する, asm直書きの関数もあるかも)
@ FUN_082401e8 が gClock に書き込みをしているので時間関連であることは確か

	thumb_func_start FUN_0823e850
FUN_0823e850: @ 0x0823E850
  .include "asm/func/FUN_0823e850.inc"

	thumb_func_start FUN_0823e948
FUN_0823e948: @ 0x0823E948
  .include "asm/func/FUN_0823e948.inc"

	thumb_func_start FUN_0823ea00
FUN_0823ea00: @ 0x0823EA00
  .include "asm/func/FUN_0823ea00.inc"

	thumb_func_start FUN_0823f210
FUN_0823f210: @ 0x0823F210
  .include "asm/func/FUN_0823f210.inc"

	thumb_func_start FUN_0823f3d4
FUN_0823f3d4: @ 0x0823F3D4
  .include "asm/func/FUN_0823f3d4.inc"

	thumb_func_start FUN_0823f3e4
FUN_0823f3e4: @ 0x0823F3E4
  .include "asm/func/FUN_0823f3e4.inc"

	thumb_func_start FUN_0823f618
FUN_0823f618: @ 0x0823F618
  .include "asm/func/FUN_0823f618.inc"

	thumb_func_start FUN_0823fb90
FUN_0823fb90: @ 0x0823FB90
  .include "asm/func/FUN_0823fb90.inc"

	thumb_func_start FUN_082401e8
FUN_082401e8: @ 0x082401E8
  .include "asm/func/FUN_082401e8.inc"

