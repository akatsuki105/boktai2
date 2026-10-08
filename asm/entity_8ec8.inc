	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Earthquake_HandleMessages
Earthquake_HandleMessages: @ 0x0821B860
  .include "asm/func/Earthquake_HandleMessages.inc"

	thumb_func_start Earthquake_IsStartHeld
Earthquake_IsStartHeld: @ 0x0821B90C
  .include "asm/func/Earthquake_IsStartHeld.inc"

	thumb_func_start Earthquake_IsSelectHeld
Earthquake_IsSelectHeld: @ 0x0821B948
  .include "asm/func/Earthquake_IsSelectHeld.inc"

	thumb_func_start Earthquake_Update
Earthquake_Update: @ 0x0821B984
  .include "asm/func/Earthquake_Update.inc"

	thumb_func_start Earthquake_Destroy
Earthquake_Destroy: @ 0x0821BC5C
  .include "asm/func/Earthquake_Destroy.inc"

	thumb_func_start Earthquake_Init
Earthquake_Init: @ 0x0821BC70
  .include "asm/func/Earthquake_Init.inc"

	thumb_func_start Earthquake_Create
Earthquake_Create: @ 0x0821BCD4
  .include "asm/func/Earthquake_Create.inc"

	thumb_func_start FUN_0821bd14
FUN_0821bd14: @ 0x0821BD14
  .include "asm/func/FUN_0821bd14.inc"

