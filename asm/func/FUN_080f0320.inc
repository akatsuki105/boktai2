	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _080F040C
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r1, _080F03A0 @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _080F03A4 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F039A
	cmp r1, #0
	blt _080F039A
	ldr r0, _080F03A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F039A
	ldr r0, _080F03AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F03B0
_080F039A:
	movs r1, #0
	b _080F03BE
	.align 2, 0
_080F03A0: .4byte 0x00000222
_080F03A4: .4byte 0xFFFFFEFF
_080F03A8: .4byte 0x030046A8
_080F03AC: .4byte 0x030046AC
_080F03B0:
	ldr r0, _080F0404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080F03BE:
	ldr r3, _080F0408 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	movs r0, #1
	b _080F0424
	.align 2, 0
_080F0404: .4byte 0x030046A4
_080F0408: .4byte 0x0000025E
_080F040C:
	movs r0, #8
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _080F0422
	ldr r0, _080F042C @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_080F0422:
	movs r0, #0
_080F0424:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F042C: .4byte 0xF7FFFFFF
