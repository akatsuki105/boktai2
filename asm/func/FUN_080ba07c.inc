	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl TextBox_Start
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	movs r0, #1
	bl TextBox_SetInstant
	adds r0, r5, #0
	bl TextBox_ShowLine
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
