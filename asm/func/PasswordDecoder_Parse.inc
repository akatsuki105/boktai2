	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov r8, r0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #3
	bl FUN_080111d8
	adds r1, r7, #0
	adds r1, #0x80
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x10
	bl FUN_080111d8
	adds r4, r7, #0
	adds r4, #0x84
	str r0, [r4]
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #2
	bl FUN_080111d8
	adds r1, r7, #0
	adds r1, #0x88
	str r0, [r1]
	movs r6, #0x15
	ldr r2, _0801131C @ =0x0000FFFF
	movs r5, #4
	mov sb, r4
	movs r4, #0x80
	lsls r4, r4, #8
	ldr r1, _08011320 @ =0x00001021
_08011302:
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r3, #0
	adds r5, #1
_0801130E:
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08011324
	lsls r2, r2, #1
	eors r2, r1
	b _08011326
	.align 2, 0
_0801131C: .4byte 0x0000FFFF
_08011320: .4byte 0x00001021
_08011324:
	lsls r2, r2, #1
_08011326:
	adds r3, #1
	cmp r3, #7
	bls _0801130E
	cmp r5, #0x17
	ble _08011302
	ldr r0, _08011344 @ =0x0000FFFF
	bics r0, r2
	mov r2, sb
	ldr r1, [r2]
	cmp r0, r1
	beq _08011348
	movs r0, #2
	rsbs r0, r0, #0
	b _0801148E
	.align 2, 0
_08011344: .4byte 0x0000FFFF
_08011348:
	adds r0, r7, #0
	bl FUN_08011124
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #9
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1]
	adds r6, #9
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #2]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #4]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #6]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #3
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #8]
	adds r6, #3
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0xa]
	adds r6, #5
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #3
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0xc]
	adds r6, #3
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #4
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0xe]
	adds r6, #4
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x10]
	adds r6, #5
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #7
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x12]
	adds r6, #7
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #4
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x14]
	adds r6, #4
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x16]
	adds r6, #5
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	mov r4, r8
	adds r4, #0x18
	movs r5, #4
_0801141A:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #8
	bl FUN_080111d8
	strh r0, [r4]
	adds r6, #8
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0801141A
	mov r1, sb
	ldr r0, [r1]
	cmp r0, #1
	bne _08011466
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x24]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x26]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #8
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x28]
_08011466:
	mov r1, r8
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08011486
	adds r0, r7, #0
	bl PasswordDecoder_IsIllegalName
	cmp r0, #0
	bne _08011486
	mov r2, r8
	ldrh r0, [r2, #0xc]
	cmp r0, #0
	beq _08011486
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _0801148C
_08011486:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801148E
_0801148C:
	movs r0, #0
_0801148E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
