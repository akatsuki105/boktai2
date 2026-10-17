	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _080D1EB0 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _080D1EB4 @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D1EC0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D1EB8
	ldr r0, [r7, #0x18]
	movs r1, #0xe3
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
	b _080D1EC0
	.align 2, 0
_080D1EB0: .4byte 0x000009C8
_080D1EB4: .4byte 0x00000A8A
_080D1EB8:
	ldr r0, [r7, #0x18]
	ldr r1, _080D1F04 @ =0x0000038B
	bl Sound_PlayForPlayer
_080D1EC0:
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xbc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r0
	ldrh r2, [r2]
	cmp r1, r2
	bls _080D1EDC
	b _080D1FF8
_080D1EDC:
	ldr r4, _080D1F08 @ =0x000002E7
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D1F0C
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r1, [r0]
	mov r0, r8
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r2, r0
	subs r1, r1, r0
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r1, r3
	b _080D1F2A
	.align 2, 0
_080D1F04: .4byte 0x0000038B
_080D1F08: .4byte 0x000002E7
_080D1F0C:
	adds r2, r5, #0
	adds r2, #0xc4
	mov r4, r8
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r6, r0, #0
	subs r6, #0x20
_080D1F2A:
	movs r0, #0xff
	ands r6, r0
	ldr r2, _080D1F50 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r4, r2, #0
	cmp r0, #0
	blt _080D1F54
	asrs r1, r0, #0xc
	b _080D1F5A
	.align 2, 0
_080D1F50: .4byte gSineTable
_080D1F54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D1F5A:
	adds r3, r5, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r2, r5, #0
	adds r2, #0x98
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x9a
	strh r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sb, r3
	adds r3, r2, #0
	cmp r0, #0
	blt _080D1F8E
	asrs r2, r0, #0xc
	b _080D1F94
_080D1F8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D1F94:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r2, r5, #0
	adds r2, #0xc5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080D1FEE
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1FEE
	ldr r1, _080D1FF4 @ =0x000002E7
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl FUN_080d1d44
_080D1FEE:
	movs r0, #0
	b _080D1FFA
	.align 2, 0
_080D1FF4: .4byte 0x000002E7
_080D1FF8:
	movs r0, #1
_080D1FFA:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
