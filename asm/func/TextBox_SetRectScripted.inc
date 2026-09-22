	push {r4, r5, r6, lr}
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl TextBox_SetRect
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
