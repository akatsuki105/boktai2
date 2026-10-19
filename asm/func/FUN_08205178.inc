	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0xc]
	adds r5, r1, #0
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0x5c
	adds r2, r2, r5
	mov r8, r2
	adds r6, r5, #0
	adds r6, #0x64
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _082051B6
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_082051B6:
	ldr r0, _08205298 @ =0x00000402
	ldrh r1, [r5, #0xe]
	movs r2, #0
	mov r3, sp
	strh r2, [r3, #0x14]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _082051DC
	b _08205422
_082051DC:
	cmp r7, #0
	bne _082051E2
	b _08205412
_082051E2:
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	str r0, [sp, #0x10]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	mov sb, r0
	mov r2, r8
	movs r1, #8
	ldrsh r0, [r2, r1]
	mov r2, sb
	subs r2, r2, r0
	mov ip, r2
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov sl, r0
	movs r0, #4
	ldrsh r2, [r6, r0]
	mov r1, sl
	subs r0, r1, r2
	mov r2, ip
	mov r1, ip
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #0xc
	mov sl, r6
	mov sb, r4
	cmp r1, r0
	ble _082052F4
	adds r0, r5, #0
	adds r0, #0x61
	strb r3, [r0]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	add r4, sp, #4
	mov r0, r8
	ldrb r6, [r0, #5]
	ldr r1, _0820529C @ =0xFFFFFD00
	mov ip, r1
	ldr r1, _082052A0 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _082052A4
	asrs r2, r0, #0xc
	b _082052AA
	.align 2, 0
_08205298: .4byte 0x00000402
_0820529C: .4byte 0xFFFFFD00
_082052A0: .4byte gSineTable
_082052A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_082052AA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _082052C6
	asrs r0, r0, #0xc
	b _082052CC
_082052C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082052CC:
	strh r0, [r4, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r7, [r7, #0x2c]
	adds r0, r0, r7
	mov r3, r8
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	mov r3, sl
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	mov r1, sb
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	b _08205412
_082052F4:
	ldr r0, _08205348 @ =0x0000FFFF
	cmp r1, r0
	ble _08205378
	adds r0, r5, #0
	adds r0, #0x61
	strb r3, [r0]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	adds r4, r5, #0
	adds r4, #0x6c
	mov r2, r8
	ldrb r6, [r2, #5]
	movs r7, #0x18
	ldr r1, _0820534C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _08205350
	asrs r2, r0, #0xc
	b _08205356
	.align 2, 0
_08205348: .4byte 0x0000FFFF
_0820534C: .4byte gSineTable
_08205350:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08205356:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0820536E
	asrs r0, r0, #0xc
	b _08205374
_0820536E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08205374:
	strh r0, [r4, #4]
	b _08205412
_08205378:
	adds r4, r5, #0
	adds r4, #0x61
	strb r3, [r4]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	mov r2, r8
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	ldr r2, [sp, #0xc]
	ldr r3, _08205434 @ =0x00000434
	adds r0, r2, r3
	ldr r2, [r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _082053BC
	rsbs r0, r0, #0
_082053BC:
	cmp r0, #0xff
	bgt _08205412
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [sp, #0x10]
	subs r0, r1, r0
	ldrb r1, [r4]
	adds r1, #0x80
	ldr r2, [sp, #0x10]
	subs r1, r2, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _082053F6
	rsbs r0, r0, #0
_082053F6:
	cmp r0, #0x3f
	bgt _08205412
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08205404
	rsbs r0, r0, #0
_08205404:
	cmp r0, #0x1f
	bgt _08205412
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
_08205412:
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08205422:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205434: .4byte 0x00000434
