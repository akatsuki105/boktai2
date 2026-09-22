	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl TextBox_SetVarValue
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
