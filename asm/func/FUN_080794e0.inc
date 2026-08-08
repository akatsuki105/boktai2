	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0807951E
	ldr r2, _08079554 @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0807951E
	adds r1, #0x58
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08079558 @ =0x000003F6
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0807951E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079542
	adds r0, r4, #0
	bl FUN_08064db0
	adds r2, r0, #0
_08079542:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807955C
	movs r2, #0x18
	b _080795B2
	.align 2, 0
_08079554: .4byte 0x000003FF
_08079558: .4byte 0x000003F6
_0807955C:
	cmp r2, #0x18
	beq _080795B2
	cmp r2, #0x14
	beq _080795B2
	cmp r2, #0x13
	beq _080795B2
	cmp r2, #0xc
	beq _080795B2
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079586
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080795AC
_08079586:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080795AC
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080795B0
_080795AC:
	movs r2, #0
	b _080795B2
_080795B0:
	movs r2, #1
_080795B2:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
