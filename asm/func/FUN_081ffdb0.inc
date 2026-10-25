	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r7, sb
	movs r3, #0x97
	lsls r3, r3, #2
	add r3, sb
	mov r2, sb
	ldr r0, [r2, #0x50]
	ldr r1, [r2, #0x54]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081FFE80 @ =0x00000804
	add r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _081FFE32
	subs r0, #1
	strh r0, [r1]
	ldr r6, _081FFE84 @ =0x0203B400
	ldr r5, _081FFE88 @ =0x030046B8
	mov r8, r5
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _081FFE8C @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldr r3, _081FFE90 @ =0x0000025E
	add r3, sb
	ldrh r0, [r3]
	subs r0, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #0x98
	lsls r2, r2, #2
	add r2, sb
	ldrh r0, [r2]
	subs r0, #0xf
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_081FFE32:
	movs r1, #0x48
	add r1, sb
	mov r8, r1
	ldr r2, _081FFE94 @ =0x00000802
	add r2, sb
	ldrh r0, [r2]
	mov r6, sb
	adds r6, #0x98
	cmp r0, #0
	beq _081FFE64
	movs r0, #4
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081FFE64
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
_081FFE64:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r7, r2
	movs r1, #4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFE98
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _081FFF46
	.align 2, 0
_081FFE80: .4byte 0x00000804
_081FFE84: .4byte 0x0203B400
_081FFE88: .4byte 0x030046B8
_081FFE8C: .4byte 0x000003FF
_081FFE90: .4byte 0x0000025E
_081FFE94: .4byte 0x00000802
_081FFE98:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	mov r3, r8
	ldrb r0, [r3, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	add r5, sp, #4
	adds r3, r0, #0
	adds r3, #0x40
	movs r0, #0xa0
	rsbs r0, r0, #0
	mov ip, r0
	ldr r2, _081FFEDC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FFEE0
	asrs r1, r0, #0xc
	b _081FFEE6
	.align 2, 0
_081FFEDC: .4byte gSineTable
_081FFEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FFEE6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081FFF06
	asrs r0, r0, #0xc
	b _081FFF0C
_081FFF06:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FFF0C:
	strh r0, [r5, #4]
	add r2, sp, #4
	mov r3, r8
	adds r3, #8
	adds r0, r2, #0
	ldrh r0, [r0]
	mov r5, r8
	ldrh r5, [r5, #8]
	adds r0, r0, r5
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r2, r8
	ldrb r1, [r2, #5]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081FFF46:
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r4, r7, r3
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFF98
	ldr r0, _081FFF94 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #2
	beq _081FFF98
	movs r0, #0x80
	lsls r0, r0, #4
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x20]
	mov r1, r8
	adds r1, #8
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r1, r8
	ldrb r0, [r1, #5]
	movs r3, #0xf7
	lsls r3, r3, #1
	adds r2, r7, r3
	strb r0, [r2]
	adds r0, r4, #0
	bl Hitbox_Register
	b _081FFFA2
	.align 2, 0
_081FFF94: .4byte 0x03002BE0
_081FFF98:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x20]
_081FFFA2:
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFFBA
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	b _081FFFC8
_081FFFBA:
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_081FFFC8:
	str r1, [r0, #8]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08200000
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081FFFE6
	b _08200152
_081FFFE6:
	ldr r0, _081FFFF8 @ =0x03003584
	ldr r0, [r0]
	ldr r5, _081FFFFC @ =0x00004620
	adds r0, r0, r5
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _08200152
	.align 2, 0
_081FFFF8: .4byte 0x03003584
_081FFFFC: .4byte 0x00004620
_08200000:
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r8, r3
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #2
	beq _08200098
	cmp r0, #2
	bgt _0820001A
	cmp r0, #1
	beq _08200020
	b _08200152
_0820001A:
	cmp r0, #3
	beq _08200110
	b _08200152
_08200020:
	ldr r5, _08200084 @ =0x000007CA
	adds r4, r7, r5
	ldr r0, _08200088 @ =0x00000233
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081fa620
	adds r1, r0, #0
	ldr r0, _0820008C @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldrh r0, [r4]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r3, _08200090 @ =0x000007C9
	adds r5, r7, r3
	ldrb r3, [r5]
	movs r0, #7
	str r0, [sp]
	adds r0, r4, #0
	bl BlendPltt
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _08200094 @ =0x000007CC
	adds r0, r7, r2
	ldr r0, [r0]
	adds r1, r4, #0
	bl FUN_08203c64
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r5]
	movs r0, #0
	mov r3, r8
	strb r0, [r3]
	b _08200152
	.align 2, 0
_08200084: .4byte 0x000007CA
_08200088: .4byte 0x00000233
_0820008C: .4byte 0x03003584
_08200090: .4byte 0x000007C9
_08200094: .4byte 0x000007CC
_08200098:
	ldr r5, _082000FC @ =0x000007CA
	adds r1, r7, r5
	ldr r0, _08200100 @ =0x00000231
	strh r0, [r1]
	ldr r5, _08200104 @ =0x03003584
	lsls r0, r0, #5
	ldr r4, [r5]
	adds r4, r4, r0
	adds r0, r7, #0
	bl FUN_081fa620
	lsls r0, r0, #5
	ldr r2, [r5]
	adds r2, r2, r0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, _08200108 @ =0x000007C9
	adds r6, r7, r1
	ldrb r3, [r6]
	movs r0, #7
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl BlendPltt
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [r0]
	ldr r3, _0820010C @ =0x000007CC
	adds r0, r7, r3
	ldr r0, [r0]
	adds r1, r5, #0
	bl FUN_08203c64
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r6]
	movs r0, #0
	mov r5, r8
	strb r0, [r5]
	b _08200152
	.align 2, 0
_082000FC: .4byte 0x000007CA
_08200100: .4byte 0x00000231
_08200104: .4byte 0x03003584
_08200108: .4byte 0x000007C9
_0820010C: .4byte 0x000007CC
_08200110:
	ldr r0, _08200190 @ =0x03003584
	ldr r1, [r0]
	ldr r0, _08200194 @ =0x00004720
	adds r1, r1, r0
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, _08200198 @ =0x000007C9
	adds r4, r7, r3
	ldrb r2, [r4]
	movs r3, #0x80
	subs r3, r3, r2
	movs r2, #7
	str r2, [sp]
	movs r2, #0
	bl BlendPlttToColor
	movs r5, #0xb9
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r2, #0xb9
	lsls r2, r2, #3
	adds r0, r7, r2
	str r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r4]
_08200152:
	mov r0, sb
	bl FUN_081ff948
	ldr r3, _0820019C @ =0x000007D2
	adds r0, r7, r3
	movs r1, #0
	movs r2, #0
	strh r2, [r0]
	ldr r5, _082001A0 @ =0x000007DC
	adds r0, r7, r5
	strh r2, [r0]
	adds r3, #0xc
	adds r0, r7, r3
	strb r1, [r0]
	mov r1, sb
	adds r1, #0xe0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	mov r0, sb
	adds r0, #0xb4
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200190: .4byte 0x03003584
_08200194: .4byte 0x00004720
_08200198: .4byte 0x000007C9
_0820019C: .4byte 0x000007D2
_082001A0: .4byte 0x000007DC
