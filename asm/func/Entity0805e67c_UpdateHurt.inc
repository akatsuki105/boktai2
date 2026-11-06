	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r7, r4, #0
	adds r7, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E344
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r4, #0
	adds r0, #0xf0
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	bl Entity0805e67c_SetElemAnim
	bl FUN_0821bd3c
	movs r0, #0xe8
	bl PlaySound_082406e0
_0805E344:
	ldr r1, [r4, #4]
	movs r0, #0x14
	subs r0, r0, r1
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	lsls r6, r0, #1
	ldr r2, _0805E370 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov ip, r3
	cmp r0, #0
	blt _0805E374
	asrs r1, r0, #0xc
	b _0805E37A
	.align 2, 0
_0805E370: .4byte gSineTable
_0805E374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E37A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E392
	asrs r0, r0, #0xc
	b _0805E398
_0805E392:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E398:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r4, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	mov r2, ip
	ldrh r0, [r2, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bls _0805E3CC
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl Entity0805e67c_ReleaseElem
	b _0805E408
_0805E3CC:
	cmp r0, #6
	bne _0805E3DA
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E3F4 @ =0x00000263
	bl Video_SetAuxSpritePltt
_0805E3DA:
	ldr r0, [r4, #4]
	lsrs r0, r0, #2
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0805E3F8
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	subs r2, #3
	ands r1, r2
	str r1, [r0]
	b _0805E402
	.align 2, 0
_0805E3F4: .4byte 0x00000263
_0805E3F8:
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0805E402:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805E408:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
