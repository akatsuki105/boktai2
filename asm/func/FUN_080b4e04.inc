	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl Video_SetBGLayer
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	ldr r0, _080B4E54 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bgt _080B4E58
	movs r0, #9
	bl MessageWindow_ShowLine
	b _080B4E76
	.align 2, 0
_080B4E54: .4byte 0x030046A0
_080B4E58:
	cmp r0, #5
	bgt _080B4E64
	movs r0, #0xa
	bl MessageWindow_ShowLine
	b _080B4E76
_080B4E64:
	cmp r0, #7
	bgt _080B4E70
	movs r0, #0xb
	bl MessageWindow_ShowLine
	b _080B4E76
_080B4E70:
	movs r0, #0xc
	bl MessageWindow_ShowLine
_080B4E76:
	ldr r1, _080B4E88 @ =FUN_080b54a0
	adds r0, r4, #0
	bl DarkLoans_SetUpdate
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4E88: .4byte FUN_080b54a0
