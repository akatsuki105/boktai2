	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r4, r1, r0
	adds r5, r4, #0
	adds r5, #0x10
	movs r0, #0x28
	adds r0, r0, r4
	mov r8, r0
	adds r6, r4, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800BF3E
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	mov r3, r8
	movs r5, #0x1c
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r2, [r4, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _0800BED4
	adds r0, r1, #0
	cmp r1, #0
	bge _0800BE94
	rsbs r0, r1, #0
_0800BE94:
	cmp r0, #4
	bgt _0800BE9C
	adds r0, r2, r1
	b _0800BE9E
_0800BE9C:
	adds r0, r2, #4
_0800BE9E:
	strb r0, [r6]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BF12
	ldr r2, _0800BEC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800BECC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800BED0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800BF10
	.align 2, 0
_0800BEC8: .4byte 0x030046B8
_0800BECC: .4byte 0x000003FF
_0800BED0: .4byte 0x0203B400
_0800BED4:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800BEDC
	rsbs r0, r1, #0
_0800BEDC:
	cmp r0, #4
	bgt _0800BEE4
	subs r0, r2, r1
	b _0800BEE6
_0800BEE4:
	subs r0, r2, #4
_0800BEE6:
	strb r0, [r6]
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BF12
	ldr r2, _0800BF9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800BFA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800BFA4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800BF10:
	strb r0, [r4, #3]
_0800BF12:
	ldr r2, _0800BFA8 @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r4, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r4, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r4, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r4, #0xc]
_0800BF3E:
	ldrh r0, [r4, #8]
	mov r1, r8
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #0x18]
	ldrh r0, [r4, #0xc]
	ldrh r3, [r2, #0x1c]
	adds r0, r0, r3
	strh r0, [r2, #0x1c]
	adds r6, r4, #0
	adds r6, #0x28
	mov r5, sl
	ldr r3, [r5, #0x20]
	adds r5, r4, #0
	adds r5, #0x18
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BFAC
	ldr r0, [r4, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BFB4
	.align 2, 0
_0800BF9C: .4byte 0x030046B8
_0800BFA0: .4byte 0x000003FF
_0800BFA4: .4byte 0x0203B400
_0800BFA8: .4byte 0x085B0A08
_0800BFAC:
	ldr r0, [r4, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BFB4:
	str r0, [r4, #0x28]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BFD8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BFE0
_0800BFD8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BFE0:
	str r0, [r6]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _0800C018 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _0800C042
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800C01C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _0800C010
	ldrb r0, [r5, #5]
_0800C010:
	subs r0, #1
	strh r0, [r5, #8]
	b _0800C02C
	.align 2, 0
_0800C018: .4byte 0x0000FFFF
_0800C01C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _0800C02C
	strh r1, [r5, #8]
_0800C02C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_0800C042:
	ldrb r0, [r4, #1]
	cmp r0, #5
	bls _0800C04C
	subs r0, #1
	strb r0, [r4, #1]
_0800C04C:
	ldrh r2, [r4, #6]
	ldrh r0, [r4, #4]
	cmp r0, r2
	blo _0800C066
	ldr r0, [r4, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x28]
	subs r0, r2, #1
	movs r1, #0
	strh r0, [r4, #6]
	strh r1, [r4, #4]
	b _0800C070
_0800C066:
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
_0800C070:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0800C0A0
	movs r0, #0
	strb r0, [r4]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r5, sb
	ldrb r0, [r5, #1]
	subs r0, #1
	strb r0, [r5, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800C0A0
	mov r0, sl
	mov r1, sb
	bl Entity0800a89c_ReleaseSwarm
_0800C0A0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
