	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
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
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4F00 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xd
	bl MessageWindow_ShowLine
	ldr r1, _080B4F04 @ =FUN_080b5528
	adds r0, r4, #0
	bl DarkLoans_SetUpdate
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F00: .4byte 0x0000FFFF
_080B4F04: .4byte FUN_080b5528
