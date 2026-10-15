	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805AA42
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xa
	strh r0, [r6, #0x10]
	adds r2, r6, #0
	adds r2, #0x98
	subs r0, #0xf
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, _0805AA6C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805AA70 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805AA74 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	subs r1, #0x80
	adds r0, r0, r1
	subs r0, #0x20
	strb r0, [r6, #0xa]
_0805AA42:
	adds r0, r6, #0
	bl FUN_0805a8f0
	mov r3, sp
	ldrb r4, [r6, #0xa]
	ldrh r5, [r6, #0x10]
	ldr r2, _0805AA78 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AA7C
	asrs r1, r0, #0xc
	b _0805AA82
	.align 2, 0
_0805AA6C: .4byte 0x030046B8
_0805AA70: .4byte 0x000003FF
_0805AA74: .4byte 0x0203B400
_0805AA78: .4byte 0x085B0A08
_0805AA7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AA82:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805AA9C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AAA0
	asrs r0, r0, #0xc
	b _0805AAA6
	.align 2, 0
_0805AA9C: .4byte 0x085B0A08
_0805AAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AAA6:
	strh r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #0x14
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x98
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	lsls r0, r0, #0x10
	ldr r1, _0805AB04 @ =0x02570000
	cmp r0, r1
	bls _0805AB08
	movs r0, #3
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805AB0C
	.align 2, 0
_0805AB04: .4byte 0x02570000
_0805AB08:
	ldrh r0, [r6, #6]
	adds r0, #1
_0805AB0C:
	strh r0, [r6, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
