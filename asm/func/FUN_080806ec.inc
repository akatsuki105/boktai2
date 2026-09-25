	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _08080706
	adds r0, r4, #0
	bl KillEntity
	b _080807EE
_08080706:
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r1, _0808074C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080754
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
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080750 @ =FUN_080808cc
	adds r0, r4, #0
	bl Entity08080be8_SetState
	b _080807EE
	.align 2, 0
_0808074C: .4byte 0x0000037D
_08080750: .4byte FUN_080808cc
_08080754:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	ldr r1, _0808077C @ =0x0000037D
	adds r0, r0, r1
	ldrb r2, [r0]
	cmp r2, #2
	bne _08080780
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r5, #3
	bne _080807C2
	b _080807A0
	.align 2, 0
_0808077C: .4byte 0x0000037D
_08080780:
	cmp r2, #3
	bne _080807A8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r2, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r2, #3
	bne _080807C2
_080807A0:
	adds r0, r4, #0
	bl FUN_080804a0
	b _080807C2
_080807A8:
	adds r1, r4, #0
	adds r1, #0xc9
	ldrb r0, [r1]
	adds r6, r1, #0
	adds r7, r4, #0
	adds r7, #0xca
	cmp r0, #0
	beq _080807C2
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
_080807C2:
	ldr r0, [r4, #0x18]
	ldr r1, _080807E0 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldrh r0, [r7]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080807E4
	ldrb r0, [r6]
	adds r0, #1
	b _080807E6
	.align 2, 0
_080807E0: .4byte 0x00000A8F
_080807E4:
	ldrb r0, [r6]
_080807E6:
	strh r0, [r4, #0x2c]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_080807EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
