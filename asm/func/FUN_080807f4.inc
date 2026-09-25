	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	cmp r6, #3
	bne _08080868
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r5, _08080850 @ =0x0000037D
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080858
	adds r0, r4, #0
	bl FUN_08080620
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r0, #1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080854 @ =FUN_080808cc
	adds r0, r4, #0
	bl Entity08080be8_SetState
	b _080808C0
	.align 2, 0
_08080850: .4byte 0x0000037D
_08080854: .4byte FUN_080808cc
_08080858:
	cmp r0, #8
	bne _08080870
	adds r0, r4, #0
	bl FUN_08080620
	adds r0, r4, #0
	bl FUN_0808065c
_08080868:
	adds r0, r4, #0
	bl KillEntity
	b _080808C0
_08080870:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	adds r0, r0, r5
	ldrb r1, [r0]
	cmp r1, #2
	bne _08080896
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r6, r0
	adds r5, r1, #0
	cmp r6, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
	b _080808AC
_08080896:
	adds r5, r4, #0
	adds r5, #0xca
	cmp r1, #3
	bne _080808AC
	ldrh r0, [r5]
	ands r1, r0
	cmp r1, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
_080808AC:
	ldr r0, [r4, #0x18]
	ldr r1, _080808C8 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xc9
	strb r1, [r0]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080808C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080808C8: .4byte 0x00000A8F
