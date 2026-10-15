	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x38
	movs r6, #0
	ldr r0, _0801ACC8 @ =0x030046B8
	mov sl, r0
	ldr r1, _0801ACCC @ =0x085B0A08
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
_0801AC22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801ACB0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0801ACD0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801ACD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	ldrb r1, [r4, #3]
	adds r1, r1, r2
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r4, #4]
	movs r3, #4
	ldrsb r3, [r4, r3]
	cmp r3, #0
	bge _0801AC5A
	rsbs r3, r3, #0
_0801AC5A:
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r2, r1, #0
	muls r2, r0, r2
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r4, #1]
	muls r1, r0, r1
	asrs r1, r1, #0xc
	asrs r2, r2, #0xc
	ldrh r0, [r5, #0x1c]
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0801ACB0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl Entity78C9Elem_Respawn
_0801ACB0:
	adds r6, #1
	adds r4, #0x34
	cmp r6, #0x1f
	ble _0801AC22
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801ACC8: .4byte 0x030046B8
_0801ACCC: .4byte 0x085B0A08
_0801ACD0: .4byte 0x000003FF
_0801ACD4: .4byte 0x0203B400
