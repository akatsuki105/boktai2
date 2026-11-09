	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r1, r6, r1
	str r1, [sp, #4]
	adds r2, r6, #0
	adds r2, #0x20
	str r2, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0x28
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0x14]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r7, r6, r3
	movs r0, #0xda
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x18]
_081DBEE2:
	ldr r0, _081DBF24 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DBF04
	mov r1, sb
	cmp r1, #0
	blt _081DBF04
	mov r3, sb
	lsls r0, r3, #3
	add r0, sb
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r3, r2, r0
	cmp r3, #0
	bne _081DBF28
_081DBF04:
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, r8
	b _081DC01C
	.align 2, 0
_081DBF24: .4byte 0x03002C68
_081DBF28:
	mov r1, sb
	lsls r0, r1, #2
	adds r0, r6, r0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _081DC000
	ldrb r0, [r2, #0x1c]
	cmp r0, #5
	bgt _081DBF5C
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	ldr r0, [r7]
	subs r1, #3
	ands r0, r1
	str r0, [r7]
	b _081DC01E
_081DBF5C:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
	mov r1, sb
	cmp r1, #1
	bgt _081DBFC0
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFA6
	cmp r0, #1
	bgt _081DBF94
	cmp r0, #0
	beq _081DBF9A
	b _081DC050
_081DBF94:
	cmp r0, #2
	beq _081DBFB2
	b _081DC050
_081DBF9A:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	b _081DC050
_081DBFA6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcf
	strh r0, [r1]
	b _081DC050
_081DBFB2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd3
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DBFC0:
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFE6
	cmp r0, #1
	bgt _081DBFD4
	cmp r0, #0
	beq _081DBFDA
	b _081DC050
_081DBFD4:
	cmp r0, #2
	beq _081DBFF2
	b _081DC050
_081DBFDA:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #6
	strh r0, [r1]
	b _081DC050
_081DBFE6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcd
	strh r0, [r1]
	b _081DC050
_081DBFF2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DC000:
	cmp r1, #1
	bne _081DC02A
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
_081DC01C:
	str r0, [r2]
_081DC01E:
	mov r2, sb
	adds r2, #4
	movs r3, #0x28
	adds r3, r3, r6
	mov sl, r3
	b _081DC050
_081DC02A:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
_081DC050:
	lsls r0, r2, #1
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r5, r6, r3
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _081DC076
	ldr r0, [sp, #0xc]
	subs r3, #0x50
	adds r1, r6, r3
	bl MainSprite_LoadPose
_081DC076:
	ldr r0, [sp, #0x14]
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r5, r5, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _081DC0AE
	ldr r2, [sp, #0x10]
	add r2, sl
	ldr r0, _081DC0FC @ =0x085AE204
	add r0, sb
	ldrb r1, [r0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r2, [r4]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r3, #1
	bl MainSprite_SetAnim
	ldrh r0, [r4]
	strh r0, [r5]
_081DC0AE:
	ldr r0, [sp, #8]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
	ldr r3, [sp, #8]
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, #0x60
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x60
	add r8, r2
	ldr r3, [sp, #0x14]
	adds r3, #2
	str r3, [sp, #0x14]
	adds r7, #0x60
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	bgt _081DC0EA
	b _081DBEE2
_081DC0EA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC0FC: .4byte 0x085AE204
