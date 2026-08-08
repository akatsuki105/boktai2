	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _0806FD88 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _0806FD8C @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806FD96
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806FD90
	movs r0, #0xe3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806FD96
	.align 2, 0
_0806FD88: .4byte 0x000009C8
_0806FD8C: .4byte 0x00000A8A
_0806FD90:
	ldr r0, _0806FDD8 @ =0x0000038B
	bl PlaySound_082406e0
_0806FD96:
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
	bls _0806FDB2
	b _0806FECC
_0806FDB2:
	ldr r4, _0806FDDC @ =0x000002E7
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806FDE0
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
	b _0806FDFE
	.align 2, 0
_0806FDD8: .4byte 0x0000038B
_0806FDDC: .4byte 0x000002E7
_0806FDE0:
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
_0806FDFE:
	movs r0, #0xff
	ands r6, r0
	ldr r2, _0806FE24 @ =0x085B0A08
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
	blt _0806FE28
	asrs r1, r0, #0xc
	b _0806FE2E
	.align 2, 0
_0806FE24: .4byte 0x085B0A08
_0806FE28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806FE2E:
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
	blt _0806FE62
	asrs r2, r0, #0xc
	b _0806FE68
_0806FE62:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806FE68:
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
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r2, r5, #0
	adds r2, #0xc5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _0806FEC2
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
	beq _0806FEC2
	ldr r1, _0806FEC8 @ =0x000002E7
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl FUN_0806fc20
_0806FEC2:
	movs r0, #0
	b _0806FECE
	.align 2, 0
_0806FEC8: .4byte 0x000002E7
_0806FECC:
	movs r0, #1
_0806FECE:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
