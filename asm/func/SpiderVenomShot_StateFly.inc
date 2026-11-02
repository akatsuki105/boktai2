	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r7, #0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x20
	adds r0, r7, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081E8744
	movs r0, #1
	b _081E8746
_081E8744:
	movs r0, #0
_081E8746:
	cmp r0, #0
	bne _081E874E
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_081E874E:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E877A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081E8782
_081E877A:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8782:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E87A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E87AE
_081E87A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E87AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081E87E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E882E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E87F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E87EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E8808
	.align 2, 0
_081E87E8: .4byte 0x0000FFFF
_081E87EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E8806
_081E87F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E8806
	strh r1, [r4, #8]
	movs r2, #1
	b _081E8808
_081E8806:
	movs r2, #0
_081E8808:
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
	bne _081E8830
	movs r0, #1
	strb r0, [r4, #7]
	b _081E8830
_081E882E:
	movs r2, #0
_081E8830:
	cmp r2, #0
	beq _081E886A
	adds r1, r7, #0
	adds r1, #0x9c
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r4, r7, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x38]
	bics r0, r1
	str r0, [r3, #0x38]
	adds r0, r7, #0
	adds r0, #0x96
	strb r2, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r4]
	b _081E8A2A
_081E886A:
	movs r2, #0x20
	adds r1, r7, #0
	adds r1, #0x94
	movs r3, #0
	ldrsh r0, [r1, r3]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081E8880
	movs r0, #1
	b _081E8882
_081E8880:
	movs r0, #0
_081E8882:
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _081E888E
	b _081E8A16
_081E888E:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r2, sp
	adds r3, r7, #0
	adds r3, #0x3c
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7, #0x3c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	strh r0, [r7, #0x3e]
	mov r5, r8
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E88E4
	cmp r1, #0
	blt _081E88E4
	ldr r0, _081E88E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E88E4
	ldr r0, _081E88EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E88F0
_081E88E4:
	movs r4, #0
	b _081E88FE
	.align 2, 0
_081E88E8: .4byte 0x030046A8
_081E88EC: .4byte 0x030046AC
_081E88F0:
	ldr r0, _081E8910 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E88FE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E8914
	adds r0, #4
	b _081E8920
	.align 2, 0
_081E8910: .4byte 0x030046A4
_081E8914:
	ldr r0, _081E8934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E8920:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E8938
	cmp r2, #2
	beq _081E893C
	b _081E8940
	.align 2, 0
_081E8934: .4byte 0x030046A4
_081E8938:
	ldrb r0, [r5, #4]
	b _081E893E
_081E893C:
	ldrb r0, [r5]
_081E893E:
	subs r1, r1, r0
_081E8940:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E896E
	cmp r1, #0
	blt _081E896E
	ldr r0, _081E8974 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E896E
	ldr r0, _081E8978 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E897C
_081E896E:
	movs r4, #0
	b _081E898A
	.align 2, 0
_081E8974: .4byte 0x030046A8
_081E8978: .4byte 0x030046AC
_081E897C:
	ldr r0, _081E899C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E898A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E89A0
	adds r0, #4
	b _081E89AC
	.align 2, 0
_081E899C: .4byte 0x030046A4
_081E89A0:
	ldr r0, _081E89C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E89AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E89C4
	cmp r2, #2
	beq _081E89C8
	b _081E89CC
	.align 2, 0
_081E89C0: .4byte 0x030046A4
_081E89C4:
	ldrb r0, [r5, #4]
	b _081E89CA
_081E89C8:
	ldrb r0, [r5]
_081E89CA:
	subs r1, r1, r0
_081E89CC:
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r6, r3]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _081E89EE
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _081E8A16
_081E89EE:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3c]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	adds r3, r7, #0
	adds r3, #0x40
	ldrh r0, [r6, #0x20]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x20
	orrs r0, r1
	mov r1, sl
	strh r0, [r1]
	strh r2, [r7, #0x3c]
	strh r2, [r7, #0x3e]
	strh r2, [r3]
_081E8A16:
	adds r4, r7, #0
	adds r4, #0x44
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081E8A2A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
