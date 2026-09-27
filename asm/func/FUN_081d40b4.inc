	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081D41B0 @ =0x03002BE0
	mov r8, r0
	ldr r3, [r0]
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r3, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081D41B4 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r0, r7, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D41B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	ldrh r3, [r3, #0x30]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r5, sp
	ldr r0, [sp, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r5, #2]
	ldrh r0, [r3, #2]
	subs r6, r2, r0
	strh r6, [r4, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r3, #4]
	subs r5, r2, r0
	strh r5, [r4, #4]
	ldr r0, _081D41BC @ =0x03000194
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _081D41C0 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r3, r0, #0
	cmp r1, r2
	bgt _081D41CC
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	ldr r4, _081D41C4 @ =0x000012B0
	add r4, ip
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	adds r0, r7, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081d4034
	movs r0, #8
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D41C8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	b _081D42AC
	.align 2, 0
_081D41B0: .4byte 0x03002BE0
_081D41B4: .4byte 0xFFFF0000
_081D41B8: .4byte 0x0000FFFF
_081D41BC: .4byte 0x03000194
_081D41C0: .4byte 0x085AE0D0
_081D41C4: .4byte 0x000012B0
_081D41C8: .4byte 0x0000060E
_081D41CC:
	ldr r0, _081D422C @ =0x000012B0
	add r0, ip
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D42AE
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D4234
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4234
	ldr r2, _081D4230 @ =0x085AE0D8
	movs r3, #0
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	b _081D4266
	.align 2, 0
_081D422C: .4byte 0x000012B0
_081D4230: .4byte 0x085AE0D8
_081D4234:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
_081D4266:
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	adds r0, r7, #0
	bl FUN_081d4034
	b _081D42AE
_081D4276:
	ldr r1, _081D42BC @ =0x000012B0
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #5
	bl FUN_0807a99c
	adds r2, r7, #0
	adds r2, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D42C0 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
_081D42AC:
	strb r0, [r1]
_081D42AE:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D42BC: .4byte 0x000012B0
_081D42C0: .4byte 0x0000060E
