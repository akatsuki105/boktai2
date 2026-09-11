	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _0800EF74
	b _0800F0A8
_0800EF74:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_0800EF7C:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r7, [r0]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0800EF90
	adds r0, r4, #0
	bl FUN_0800e54c
	b _0800F0A0
_0800EF90:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800F082
	adds r6, r4, #0
	adds r6, #0x44
	adds r3, r4, #0
	adds r3, #0x70
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0800EFCA
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	b _0800EFD2
_0800EFCA:
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800EFD2:
	str r0, [r4, #0x44]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0800EFF6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800EFFE
_0800EFF6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800EFFE:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _0800F038 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _0800F07E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800F042
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0800F03C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _0800F058
	.align 2, 0
_0800F038: .4byte 0x0000FFFF
_0800F03C:
	subs r0, #1
	strh r0, [r3, #8]
	b _0800F056
_0800F042:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0800F056
	strh r1, [r3, #8]
	movs r2, #1
	b _0800F058
_0800F056:
	movs r2, #0
_0800F058:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _0800F080
	mov r5, r8
	strb r5, [r3, #7]
	b _0800F080
_0800F07E:
	movs r2, #0
_0800F080:
	strb r2, [r4, #0xa]
_0800F082:
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	str r0, [r4, #0x60]
	str r1, [r4, #0x64]
	ldr r2, _0800F0B8 @ =0x085AA7A0
	ldrb r1, [r4, #4]
	lsls r1, r1, #2
	ldrb r0, [r4, #2]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0800F0A0:
	adds r4, r7, #0
	cmp r4, #0
	beq _0800F0A8
	b _0800EF7C
_0800F0A8:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0B8: .4byte 0x085AA7A0
