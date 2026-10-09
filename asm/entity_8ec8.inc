	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Entity8EC8_HandleMessages
Entity8EC8_HandleMessages: @ 0x0821B860
  .include "asm/func/Entity8EC8_HandleMessages.inc"

	thumb_func_start Entity8EC8_IsStartHeld
Entity8EC8_IsStartHeld: @ 0x0821B90C
  .include "asm/func/Entity8EC8_IsStartHeld.inc"

	thumb_func_start Entity8EC8_IsSelectHeld
Entity8EC8_IsSelectHeld: @ 0x0821B948
  .include "asm/func/Entity8EC8_IsSelectHeld.inc"

	thumb_func_start Entity8EC8_Update
Entity8EC8_Update: @ 0x0821B984
  .include "asm/func/Entity8EC8_Update.inc"

	thumb_func_start Entity8EC8_Destroy
Entity8EC8_Destroy: @ 0x0821BC5C
  .include "asm/func/Entity8EC8_Destroy.inc"

	thumb_func_start Entity8EC8_Init
Entity8EC8_Init: @ 0x0821BC70
  .include "asm/func/Entity8EC8_Init.inc"

	thumb_func_start Entity8EC8_Create
Entity8EC8_Create: @ 0x0821BCD4
  .include "asm/func/Entity8EC8_Create.inc"

	thumb_func_start FUN_0821bd14
FUN_0821bd14: @ 0x0821BD14
  .include "asm/func/FUN_0821bd14.inc"

