	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _080696CE
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _080696CE
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080696B8
	lsrs r2, r1, #1
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080696A2
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x8b
	lsls r0, r0, #1
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080696B8
_080696A2:
	adds r1, r4, #0
	adds r1, #0x2c
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, _08069708 @ =0x00000117
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
_080696B8:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080609dc
_080696CE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806970C @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _080696FE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080696FE:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069708: .4byte 0x00000117
_0806970C: .4byte 0x000003FF
