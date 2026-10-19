	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start NestedState_Reset0
NestedState_Reset0: @ 0x081FA590
	movs r1, #0
	strb r1, [r0, #2]
	strb r1, [r0, #1]
	strb r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr

	thumb_func_start NestedState_Set0
NestedState_Set0: @ 0x081FA5A0
	movs r2, #0
	strb r1, [r0]
	strb r2, [r0, #2]
	strb r2, [r0, #1]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	str r2, [r0, #4]
	bx lr

	thumb_func_start NestedState_Advance0
NestedState_Advance0: @ 0x081FA5B0
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strb r2, [r0, #2]
	strb r2, [r0, #1]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	str r2, [r0, #4]
	bx lr

	thumb_func_start NestedState_Reset1
NestedState_Reset1: @ 0x081FA5C4
	movs r1, #0
	strb r1, [r0, #2]
	strb r1, [r0, #1]
	str r1, [r0, #0xc]
	str r1, [r0, #8]
	bx lr

	thumb_func_start NestedState_Set1
NestedState_Set1: @ 0x081FA5D0
	movs r2, #0
	strb r1, [r0, #1]
	strb r2, [r0, #2]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	bx lr

	thumb_func_start NestedState_Advance1
NestedState_Advance1: @ 0x081FA5DC
	ldrb r1, [r0, #1]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #1]
	strb r2, [r0, #2]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	bx lr

	thumb_func_start NestedState_Reset2
NestedState_Reset2: @ 0x081FA5EC
	movs r1, #0
	strb r1, [r0, #2]
	str r1, [r0, #0xc]
	bx lr

	thumb_func_start NestedState_Set2
NestedState_Set2: @ 0x081FA5F4
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	bx lr

	thumb_func_start NestedState_Advance2
NestedState_Advance2: @ 0x081FA5FC
	ldrb r1, [r0, #2]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	bx lr

