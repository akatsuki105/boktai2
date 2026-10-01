	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D904
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0
	str r0, [r1]
	str r0, [r5, #0x7c]
	adds r1, #4
	str r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #0x2a
	strb r0, [r1]
	adds r1, #0x2c
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _0801D934 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807c7c8
_0801D904:
	ldr r0, [r5, #0x6c]
	movs r1, #3
	cmp r0, #0
	beq _0801D90E
	movs r1, #6
_0801D90E:
	lsrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x88
	ldr r0, [r2]
	cmp r0, #0
	beq _0801D93C
	lsls r0, r1, #2
	ldr r1, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r5, #0x7c]
	ldr r0, _0801D938 @ =0x000002FF
	cmp r1, r0
	ble _0801D950
	adds r0, #1
	str r0, [r5, #0x7c]
	movs r0, #0
	b _0801D94E
	.align 2, 0
_0801D934: .4byte 0x03002BE0
_0801D938: .4byte 0x000002FF
_0801D93C:
	lsls r1, r1, #2
	ldr r0, [r5, #0x7c]
	subs r0, r0, r1
	str r0, [r5, #0x7c]
	ldr r1, _0801D968 @ =0xFFFFFD00
	cmp r0, r1
	bgt _0801D950
	str r1, [r5, #0x7c]
	movs r0, #1
_0801D94E:
	str r0, [r2]
_0801D950:
	adds r2, r5, #0
	adds r2, #0x84
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	ldr r0, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bge _0801D96C
	movs r0, #0
	b _0801D974
	.align 2, 0
_0801D968: .4byte 0xFFFFFD00
_0801D96C:
	movs r0, #0xb0
	lsls r0, r0, #5
	cmp r1, r0
	ble _0801D976
_0801D974:
	str r0, [r2]
_0801D976:
	ldr r0, _0801DA34 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801DA38 @ =0x000053E0
	adds r4, r0, r1
	ldr r0, _0801DA3C @ =0x00001314
	adds r0, r0, r5
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	adds r7, r5, #0
	adds r7, #0x8c
	ldr r0, [r7]
	lsls r0, r0, #5
	movs r1, #5
	bl Div
	cmp r6, r0
	bge _0801D9A2
	adds r6, r0, #0
_0801D9A2:
	movs r1, #0x20
	subs r1, r1, r6
	lsls r3, r1, #5
	subs r3, r3, r1
	ldrh r2, [r4, #0x1e]
	movs r4, #0x1f
	movs r0, #0x1f
	ands r0, r2
	muls r0, r6, r0
	adds r3, r3, r0
	asrs r3, r3, #5
	lsls r1, r1, #2
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x15
	ands r0, r4
	muls r0, r6, r0
	adds r1, r1, r0
	asrs r1, r1, #5
	lsrs r2, r2, #0x1a
	ands r2, r4
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	ands r3, r4
	ands r1, r4
	lsls r1, r1, #5
	adds r3, r3, r1
	ands r0, r4
	lsls r0, r0, #0xa
	adds r3, r3, r0
	ldr r1, _0801DA40 @ =0x00001302
	adds r0, r5, r1
	strh r3, [r0]
	adds r2, r5, #0
	adds r2, #0x90
	ldrb r0, [r2]
	cmp r0, #0
	bne _0801DA50
	ldr r0, [r7]
	cmp r0, #4
	bgt _0801DA28
	ldr r0, _0801DA44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801DA1E
	adds r1, r5, #0
	adds r1, #0x91
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xd
	strb r0, [r2]
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
_0801DA1E:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, _0801DA48 @ =0x000001FF
	cmp r1, r0
	bls _0801DA62
_0801DA28:
	ldr r1, _0801DA4C @ =FUN_0801da7c
	adds r0, r5, #0
	bl FUN_0801d7f8
	b _0801DA6C
	.align 2, 0
_0801DA34: .4byte 0x03003584
_0801DA38: .4byte 0x000053E0
_0801DA3C: .4byte 0x00001314
_0801DA40: .4byte 0x00001302
_0801DA44: .4byte 0x030044E0
_0801DA48: .4byte 0x000001FF
_0801DA4C: .4byte FUN_0801da7c
_0801DA50:
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0801DA62
	adds r0, r5, #0
	bl FUN_0801d338
_0801DA62:
	ldr r0, _0801DA78 @ =0x00001314
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801DA6C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DA78: .4byte 0x00001314
