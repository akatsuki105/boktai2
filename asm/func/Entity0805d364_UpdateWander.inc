	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805C382
	movs r0, #0
	strb r0, [r4]
	ldr r3, _0805C390 @ =0x0203B400
	ldr r1, _0805C394 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C398 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
	adds r2, r4, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C382:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C39C
	movs r0, #5
	movs r1, #0
	b _0805C3A4
	.align 2, 0
_0805C390: .4byte 0x0203B400
_0805C394: .4byte 0x030046B8
_0805C398: .4byte 0x000003FF
_0805C39C:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C3AE
	movs r0, #9
_0805C3A4:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805C4B8
_0805C3AE:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805C3EC
	ldr r3, _0805C3E0 @ =0x0203B400
	ldr r1, _0805C3E4 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C3E8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805C3EE
	.align 2, 0
_0805C3E0: .4byte 0x0203B400
_0805C3E4: .4byte 0x030046B8
_0805C3E8: .4byte 0x000003FF
_0805C3EC:
	subs r0, #1
_0805C3EE:
	strb r0, [r4, #7]
	mov r3, sp
	ldrb r5, [r4, #6]
	ldrh r6, [r4, #0x10]
	ldr r2, _0805C414 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C418
	asrs r1, r0, #0xc
	b _0805C41E
	.align 2, 0
_0805C414: .4byte gSineTable
_0805C418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C41E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C436
	asrs r0, r0, #0xc
	b _0805C43C
_0805C436:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C43C:
	movs r5, #0
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r4, #4]
	cmp r0, #0x1f
	bls _0805C486
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805C4B6
_0805C486:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805C4B2
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C4B2
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C4A6
	mov r3, r8
	cmp r3, #7
	bgt _0805C4AA
	movs r0, #1
	b _0805C4B0
_0805C4A6:
	cmp r0, #0
	bne _0805C4AE
_0805C4AA:
	strb r5, [r4, #8]
	b _0805C4B2
_0805C4AE:
	movs r0, #0xff
_0805C4B0:
	strb r0, [r4, #8]
_0805C4B2:
	ldrh r0, [r4, #4]
	adds r0, #1
_0805C4B6:
	strh r0, [r4, #4]
_0805C4B8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
