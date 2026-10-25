	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	movs r0, #0x34
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080595BE
	movs r0, #0
	strb r0, [r4]
_080595BE:
	ldrb r0, [r4, #1]
	adds r0, #4
	strb r0, [r4, #1]
	adds r5, r4, #0
	adds r5, #0x50
	ldrb r6, [r4, #1]
	ldr r2, _080595E8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	adds r3, r5, #0
	cmp r0, #0
	blt _080595EC
	asrs r1, r0, #0xc
	b _080595F2
	.align 2, 0
_080595E8: .4byte gSineTable
_080595EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080595F2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805960E
	asrs r0, r0, #0xc
	b _08059614
_0805960E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059614:
	strh r0, [r5, #4]
	adds r1, r7, #0
	adds r1, #0x34
	ldrh r0, [r7, #0x34]
	mov r5, ip
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	mov r2, ip
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r4, #6]
	cmp r0, #0x3f
	bls _08059654
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4]
_08059654:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
