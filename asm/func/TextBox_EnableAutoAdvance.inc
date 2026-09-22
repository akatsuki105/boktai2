	push {r4, r5, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	rsbs r1, r4, #0
	orrs r1, r4
	lsrs r1, r1, #0x1f
	movs r0, #0x6d
	bl VM_GetKeywordValue
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl TextBox_SetAutoAdvance
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
