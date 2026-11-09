	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r0, [r7, #0x24]
	strh r0, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x5c
	mov sb, r0
	movs r0, #1
	mov sl, r0
	movs r1, #0xd4
	adds r1, r1, r7
	mov r8, r1
_08058CCC:
	mov r0, sl
	mov r2, sb
	lsls r0, r2
	ldr r1, [r7, #0x1c]
	ands r1, r0
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp]
	cmp r1, #0
	bne _08058CE2
	b _08058E82
_08058CE2:
	adds r6, r5, #0
	adds r6, #0x4c
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x78]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _08058D14
	ldr r0, [r5, #0x4c]
	movs r1, #4
	orrs r0, r1
	b _08058D1C
_08058D14:
	ldr r0, [r5, #0x4c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08058D1C:
	str r0, [r5, #0x4c]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _08058D40
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08058D48
_08058D40:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08058D48:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _08058D80 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _08058DC6
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08058D8A
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _08058D84
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _08058DA0
	.align 2, 0
_08058D80: .4byte 0x0000FFFF
_08058D84:
	subs r0, #1
	strh r0, [r3, #8]
	b _08058D9E
_08058D8A:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08058D9E
	strh r1, [r3, #8]
	movs r2, #1
	b _08058DA0
_08058D9E:
	movs r2, #0
_08058DA0:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058DC8
	mov r4, sl
	strb r4, [r3, #7]
	b _08058DC8
_08058DC6:
	movs r2, #0
_08058DC8:
	movs r0, #0
	strb r2, [r5, #7]
	strb r0, [r5, #0xa]
	ldr r1, [r7, #0x20]
	movs r2, #3
	ands r1, r2
	mov r0, sb
	ands r0, r2
	cmp r1, r0
	bne _08058E04
	ldr r1, _08058E30 @ =0x00000EBC
	adds r0, r7, r1
	ldr r1, [r0]
	movs r3, #0x2c
	ldrsh r2, [r1, r3]
	movs r4, #0x1c
	ldrsh r0, [r6, r4]
	subs r2, r2, r0
	movs r0, #0x30
	ldrsh r1, [r1, r0]
	movs r3, #0x20
	ldrsh r0, [r6, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r4, #0
	adds r0, r0, r1
	str r0, [r5, #0x18]
_08058E04:
	ldr r1, _08058E34 @ =0x085AB9B4
	ldrb r0, [r5, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	bl _call_via_r3
	ldrb r1, [r5, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08058E38
	mov r0, r8
	ldrh r1, [r0, #0x16]
	movs r0, #4
	orrs r0, r1
	mov r1, r8
	strh r0, [r1, #0x16]
	b _08058E50
	.align 2, 0
_08058E30: .4byte 0x00000EBC
_08058E34: .4byte 0x085AB9B4
_08058E38:
	mov r2, r8
	ldrh r0, [r2, #0x16]
	ldr r3, _08058EB0 @ =0x0000FFFB
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [sp]
	movs r2, #0
	bl Hitbox_SetPos
_08058E50:
	ldrb r1, [r5, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08058E62
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08057214
_08058E62:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08058E7C
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058E7C
	adds r0, r5, #0
	adds r0, #0x30
	ldr r1, _08058EB4 @ =0x0000022A
	bl Video_SetAuxSpritePltt
_08058E7C:
	ldrh r0, [r7, #0x26]
	adds r0, #1
	strh r0, [r7, #0x26]
_08058E82:
	movs r4, #1
	add sb, r4
	movs r0, #0x8c
	lsls r0, r0, #1
	add r8, r0
	adds r5, r5, r0
	mov r1, sb
	cmp r1, #0xb
	bgt _08058E96
	b _08058CCC
_08058E96:
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058EB0: .4byte 0x0000FFFB
_08058EB4: .4byte 0x0000022A
