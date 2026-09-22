	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d34c
	adds r1, r0, #0
	adds r0, r4, #0
	bl TextBox_SetExtendValue
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
