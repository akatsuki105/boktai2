	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08094c6c
	cmp r4, #0
	beq _08094D06
	ldrb r1, [r5]
	adds r0, r7, #0
	bl TextPanel_SetMessage
	adds r0, r7, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0804a40c
	b _08094D14
_08094D06:
	ldrb r0, [r5]
	bl TextBox_ShowLine
	movs r0, #0
	adds r1, r6, #0
	bl TextBox_SetExtendValue
_08094D14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
