	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0xc
	adds r5, r3, #0
	adds r5, #0x24
	ldr r4, [r3, #8]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080136FE
	cmp r1, #0
	blt _080136FE
	ldr r0, _08013704 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080136FE
	ldr r0, _08013708 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801370C
_080136FE:
	movs r7, #0
	b _0801371A
	.align 2, 0
_08013704: .4byte 0x030046A8
_08013708: .4byte 0x030046AC
_0801370C:
	ldr r0, _0801372C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0801371A:
	ldrb r1, [r3, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013730
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	b _0801376E
	.align 2, 0
_0801372C: .4byte 0x030046A4
_08013730:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013740
	adds r0, #4
	b _0801374C
_08013740:
	ldr r0, _08013760 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0801374C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08013764
	cmp r2, #2
	beq _08013768
	b _0801376C
	.align 2, 0
_08013760: .4byte 0x030046A4
_08013764:
	ldrb r0, [r4, #4]
	b _0801376A
_08013768:
	ldrb r0, [r4]
_0801376A:
	subs r1, r1, r0
_0801376C:
	strh r1, [r5, #2]
_0801376E:
	movs r1, #2
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	blt _080137A4
	cmp r1, #0
	beq _080137A4
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0801378E
	adds r0, #4
	b _0801379A
_0801378E:
	ldr r0, _080137B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0801379A:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080137B4
_080137A4:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _080137C6
	.align 2, 0
_080137B0: .4byte 0x030046A4
_080137B4:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldrh r0, [r4]
	strh r0, [r5]
	ldrh r0, [r4, #4]
	strh r0, [r5, #4]
_080137C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
