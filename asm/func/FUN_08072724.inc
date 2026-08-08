	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807273C @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	beq _0807278A
	cmp r5, #1
	bgt _08072740
	cmp r5, #0
	beq _08072746
	b _080727CC
	.align 2, 0
_0807273C: .4byte 0x0000037D
_08072740:
	cmp r5, #2
	beq _08072778
	b _080727CC
_08072746:
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
	ldr r0, _08072774 @ =0x000004AF
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080727CC
	strb r5, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
	b _080727CC
	.align 2, 0
_08072774: .4byte 0x000004AF
_08072778:
	ldr r0, _080727A4 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080727A8
_0807278A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080727CC
	.align 2, 0
_080727A4: .4byte 0x0000037E
_080727A8:
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
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080727CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
