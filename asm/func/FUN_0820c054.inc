	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820C07C
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	adds r0, r4, #0
	bl FUN_0820c014
_0820C07C:
	ldr r0, _0820C0AC @ =0x03002CF0
	ldr r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _0820C092
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_0820C092:
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _0820C0B4
	subs r0, #1
	strb r0, [r1]
	ldr r2, _0820C0B0 @ =0x00000131
	adds r1, r4, r2
	strb r0, [r1]
	b _0820C0C8
	.align 2, 0
_0820C0AC: .4byte 0x03002CF0
_0820C0B0: .4byte 0x00000131
_0820C0B4:
	ldr r0, _0820C0F0 @ =FUN_08042178
	movs r2, #0
	strb r3, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r1, r4, r5
	str r0, [r1]
	str r2, [r4, #0x10]
	strb r3, [r4, #9]
	strb r2, [r4, #0x18]
_0820C0C8:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0820C0F4
	adds r0, r4, #0
	bl FUN_0820c034
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	b _0820C19C
	.align 2, 0
_0820C0F0: .4byte FUN_08042178
_0820C0F4:
	add r6, sp, #4
	adds r2, r4, #0
	adds r2, #0x54
	adds r3, r4, #0
	adds r3, #0x64
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r1, r6, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r6, #0
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r5, #2
	ldrsh r0, [r6, r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r5, #4
	ldrsh r0, [r6, r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r5, #0x82
	lsls r5, r5, #2
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r1, r0
	bhi _0820C150
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	b _0820C19C
_0820C150:
	movs r2, #0x81
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r7, [r0]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0820C194
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	add r1, sp, #4
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r6, r2]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r6, #2]
	movs r1, #4
	ldrsh r0, [r6, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r6, #4]
_0820C194:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x6c]
	str r1, [r4, #0x70]
_0820C19C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
