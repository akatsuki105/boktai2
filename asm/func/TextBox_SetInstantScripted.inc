	push {lr}
	bl Script_GetValue
	bl TextBox_SetInstant
	pop {r1}
	bx r1
	.align 2, 0
