	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A09B0
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0998
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldr r5, _080A0994 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r4, #4
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0994: .4byte 0x03003540
_080A0998:
	movs r0, #8
	strh r0, [r7, #0x34]
	ldr r1, _080A09AC @ =0x03003540
	ldrh r0, [r1]
	strh r0, [r7, #0x28]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r1, #4]
	b _080A0CFE
	.align 2, 0
_080A09AC: .4byte 0x03003540
_080A09B0:
	ldr r1, _080A09EC @ =0x03002BE0
	ldrb r2, [r7, #0x1e]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _080A09F0 @ =0x000003CE
	adds r0, r3, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	bne _080A09CC
	b _080A0AC8
_080A09CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A09FC
	ldr r0, _080A09F4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080A09F8 @ =0x00000932
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	b _080A0A06
	.align 2, 0
_080A09EC: .4byte 0x03002BE0
_080A09F0: .4byte 0x000003CE
_080A09F4: .4byte 0x030046A0
_080A09F8: .4byte 0x00000932
_080A09FC:
	ldr r0, _080A0A80 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080A0A84 @ =0x00000932
	adds r0, r0, r3
	ldrh r0, [r0]
_080A0A06:
	strh r0, [r7, #0x30]
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0A8C
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r5, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	mov r2, ip
	lsls r1, r2, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	ldr r2, _080A0A88 @ =0x000003C2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0A80: .4byte 0x030046A0
_080A0A84: .4byte 0x00000932
_080A0A88: .4byte 0x000003C2
_080A0A8C:
	movs r0, #8
	strh r0, [r7, #0x34]
	mov r4, ip
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r2, _080A0AC4 @ =0x000003C2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x2a]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r3, #0xf1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	b _080A0CFE
	.align 2, 0
_080A0AC4: .4byte 0x000003C2
_080A0AC8:
	ldr r2, _080A0B00 @ =0x030046A0
	ldr r0, [r2]
	ldr r4, _080A0B04 @ =0x00000932
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r4, [r7, #0x30]
	ldr r3, _080A0B08 @ =0xFFFFFF00
	adds r0, r4, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x80
	subs r0, r0, r1
	adds r3, r0, #0
	cmp r0, #0
	bge _080A0AEC
	rsbs r3, r0, #0
_080A0AEC:
	cmp r3, #0x10
	bgt _080A0B4C
	cmp r1, #0x80
	beq _080A0B1C
	cmp r1, #0x7f
	bgt _080A0B0C
	asrs r0, r0, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B16
	.align 2, 0
_080A0B00: .4byte 0x030046A0
_080A0B04: .4byte 0x00000932
_080A0B08: .4byte 0xFFFFFF00
_080A0B0C:
	adds r0, r1, #0
	subs r0, #0x80
	asrs r0, r0, #2
	subs r0, r4, r0
	adds r0, #0xff
_080A0B16:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B1C:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A0B44 @ =0xFFFFFED4
	adds r1, r1, r0
	asrs r1, r1, #2
	strh r1, [r7, #0x32]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080A0B88
	rsbs r0, r1, #0
	strh r0, [r7, #0x32]
	ldr r0, [r2]
	ldr r1, _080A0B48 @ =0x00000932
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x30]
	b _080A0B88
	.align 2, 0
_080A0B44: .4byte 0xFFFFFED4
_080A0B48: .4byte 0x00000932
_080A0B4C:
	cmp r1, #0
	beq _080A0B70
	cmp r1, #0x7f
	bgt _080A0B5C
	asrs r0, r1, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B6A
_080A0B5C:
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, r0, r1
	asrs r1, r1, #2
	adds r1, #1
	adds r0, r4, r0
	subs r0, r0, r1
_080A0B6A:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B70:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	ldr r0, _080A0BB4 @ =0x0000012B
	cmp r1, r0
	bgt _080A0B88
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r0, r4
	asrs r0, r0, #2
	strh r0, [r7, #0x32]
_080A0B88:
	ldrh r0, [r7, #0x34]
	adds r3, r0, #0
	cmp r3, #1
	bls _080A0C6C
	ldr r2, _080A0BB8 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0BBC
	asrs r1, r0, #0xc
	b _080A0BC2
	.align 2, 0
_080A0BB4: .4byte 0x0000012B
_080A0BB8: .4byte 0x085B0A08
_080A0BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0BC2:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r1, _080A0C0C @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x22]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0C10
	asrs r1, r0, #0xc
	b _080A0C16
	.align 2, 0
_080A0C0C: .4byte 0x0000097A
_080A0C10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C16:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r7, #0x24]
	subs r0, r3, #1
	strh r0, [r7, #0x34]
	ldrh r1, [r7, #0x34]
	adds r4, r1, #1
	movs r3, #0x28
	ldrsh r0, [r7, r3]
	muls r0, r1, r0
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x22
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	b _080A0CFE
_080A0C6C:
	movs r0, #0
	strh r0, [r7, #0x34]
	ldr r2, _080A0C94 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0C98
	asrs r1, r0, #0xc
	b _080A0C9E
	.align 2, 0
_080A0C94: .4byte 0x085B0A08
_080A0C98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C9E:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r3, _080A0CE8 @ =0x0000097A
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x2a]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r2, #0x32
	ldrsh r0, [r7, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0CEC
	asrs r1, r0, #0xc
	b _080A0CF2
	.align 2, 0
_080A0CE8: .4byte 0x0000097A
_080A0CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0CF2:
	mov r3, ip
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
_080A0CFE:
	strh r0, [r7, #0x2c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
