	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sb, r1
	adds r7, r6, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E9C6
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0802E974 @ =0x00000899
	adds r5, r6, r1
	ldrb r0, [r5]
	adds r4, r6, #0
	adds r4, #0xc8
	adds r0, r4, r0
	ldrb r3, [r0]
	ldr r2, _0802E978 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802E97C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0802E980 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x40
	adds r3, r3, r0
	ldr r1, _0802E984 @ =0x00000175
	adds r0, r6, r1
	strb r3, [r0]
	ldrb r0, [r5]
	adds r4, r4, r0
	ldrb r0, [r4]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E98C
	ldr r3, _0802E988 @ =0x00000824
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E99C
	movs r3, #0
	b _0802E99C
	.align 2, 0
_0802E974: .4byte 0x00000899
_0802E978: .4byte 0x030046B8
_0802E97C: .4byte 0x000003FF
_0802E980: .4byte 0x0203B400
_0802E984: .4byte 0x00000175
_0802E988: .4byte 0x00000824
_0802E98C:
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E99C
	movs r3, #5
_0802E99C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl Boss_PlayAnimDir8
	ldr r0, _0802EA2C @ =0x00000854
	adds r2, r7, r0
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_0802E9C6:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0802EA30 @ =0x00000167
	adds r0, r7, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r4, #0x80
	adds r0, r6, r4
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802EAAA
	mov r0, sb
	cmp r0, #6
	bgt _0802EA9C
	ldr r1, _0802EA34 @ =0x00000175
	adds r0, r7, r1
	add r3, sp, #0xc
	ldrb r4, [r0]
	mov r0, sb
	lsls r5, r0, #5
	ldr r2, _0802EA38 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802EA3C
	asrs r1, r0, #0xc
	b _0802EA42
	.align 2, 0
_0802EA2C: .4byte 0x00000854
_0802EA30: .4byte 0x00000167
_0802EA34: .4byte 0x00000175
_0802EA38: .4byte gSineTable
_0802EA3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EA42:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802EA5A
	asrs r0, r0, #0xc
	b _0802EA60
_0802EA5A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802EA60:
	strh r0, [r3, #4]
	mov r3, r8
	adds r3, #8
	ldr r0, _0802EAB8 @ =0x00000854
	adds r1, r7, r0
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	mov r4, r8
	strh r0, [r4, #8]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _0802EABC @ =0x000008E4
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802EA9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_0802EA9C:
	mov r3, sb
	cmp r3, #0xf
	ble _0802EAAA
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802EAAA:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EAB8: .4byte 0x00000854
_0802EABC: .4byte 0x000008E4
