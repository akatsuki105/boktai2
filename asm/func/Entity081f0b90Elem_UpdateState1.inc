	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r1
	movs r4, #0xad
	lsls r4, r4, #1
	add r4, r8
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F069C
	ldr r0, _081F06F4 @ =0x000003B1
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r4]
_081F069C:
	movs r0, #0
	mov ip, r0
	mov r1, r8
	adds r1, #0xf0
	str r1, [sp]
	movs r2, #1
	mov sl, r2
	mov r4, r8
	adds r4, #0xb0
	ldr r3, _081F06F8 @ =0x030047C8
	mov sb, r3
_081F06B2:
	movs r0, #0x2c
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	mov r1, r8
	adds r7, r1, r0
	ldr r3, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r3, r0
	str r3, [r7]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r6, sl
	ands r0, r6
	cmp r2, r0
	beq _081F06FC
	movs r0, #4
	orrs r3, r0
	b _081F0702
	.align 2, 0
_081F06F4: .4byte 0x000003B1
_081F06F8: .4byte 0x030047C8
_081F06FC:
	movs r0, #5
	rsbs r0, r0, #0
	ands r3, r0
_081F0702:
	str r3, [r7]
	ldrb r0, [r4, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _081F0726
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F072E
_081F0726:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F072E:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081F0764 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081F079C
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F0768
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F075E
	ldrb r0, [r4, #5]
_081F075E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F0778
	.align 2, 0
_081F0764: .4byte 0x0000FFFF
_081F0768:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F0778
	strh r1, [r4, #8]
_081F0778:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F079C
	mov r3, sl
	strb r3, [r4, #7]
_081F079C:
	adds r5, r7, #0
	adds r5, #0x1c
	ldr r6, [sp]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F07BE
	asrs r0, r0, #8
	b _081F07C4
_081F07BE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07C4:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F07D6
	asrs r0, r0, #8
	b _081F07DC
_081F07D6:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07DC:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081F07F0
	asrs r0, r0, #8
	b _081F07F6
_081F07F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07F6:
	subs r2, r3, r0
	strh r2, [r5, #2]
	adds r3, r3, r0
	strh r3, [r5, #4]
	ldrh r0, [r5]
	mov r6, sb
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r5, #4]
	mov r1, ip
	lsls r0, r1, #5
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	adds r4, #0x10
	movs r3, #1
	add ip, r3
	mov r6, ip
	cmp r6, #2
	bgt _081F0830
	b _081F06B2
_081F0830:
	movs r5, #0xac
	lsls r5, r5, #1
	add r5, r8
	ldrh r0, [r5]
	cmp r0, #4
	bls _081F0852
	movs r1, #0xa9
	lsls r1, r1, #1
	add r1, r8
	movs r0, #2
	strb r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081F0870
_081F0852:
	movs r4, #0x80
	lsls r4, r4, #1
	add r4, r8
	mov r1, r8
	adds r1, #0xf8
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_081F0870:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
