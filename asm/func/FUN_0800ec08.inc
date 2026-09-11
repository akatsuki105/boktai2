	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EC80
	movs r0, #0
	strb r0, [r5, #3]
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r0, _0800EC94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0800EC7C
	ldr r2, _0800EC98 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0800EC9C @ =0x0000FFF1
	orrs r0, r3
	ldr r4, _0800ECA0 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #0x18
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
_0800EC7C:
	movs r0, #0x1e
	strh r0, [r5, #8]
_0800EC80:
	ldrh r0, [r5, #6]
	cmp r0, #0xb
	bhi _0800ECA4
	ldrh r0, [r5, #0x1a]
	adds r0, #8
	strh r0, [r5, #0x1a]
	movs r0, #0x28
	bl FUN_0823b9cc
	b _0800ECB6
	.align 2, 0
_0800EC94: .4byte 0x030047A4
_0800EC98: .4byte 0xFFFF0000
_0800EC9C: .4byte 0x0000FFF1
_0800ECA0: .4byte 0x0000FFFF
_0800ECA4:
	ldrh r0, [r5, #0x1a]
	subs r0, #4
	strh r0, [r5, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, #0x14]
	cmp r0, r1
	bge _0800ECB6
	strh r1, [r5, #0x1a]
_0800ECB6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800ECC6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800ECC6:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800ECDC
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800ECDC:
	ldrh r1, [r5, #6]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bhi _0800ECF0
	ldr r0, [r5, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0800ECF8
_0800ECF0:
	ldr r0, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0800ECF8:
	str r0, [r5, #0x44]
	adds r0, r2, #1
	strh r0, [r5, #6]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #8]
	cmp r0, r1
	bls _0800ED0C
	movs r0, #1
	strb r0, [r5, #0xd]
_0800ED0C:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
