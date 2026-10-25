	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r6, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	ldr r0, _0802F1B0 @ =0x00000899
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r4, #0
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
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F204
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F1B8
	ldr r1, _0802F1B4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	subs r1, #4
	adds r5, r4, r1
	cmp r0, #0
	bne _0802F1CA
	movs r3, #0x1a
	b _0802F1CA
	.align 2, 0
_0802F1B0: .4byte 0x00000899
_0802F1B4: .4byte 0x00000824
_0802F1B8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r3, #0x1a
	adds r5, r0, #0
	cmp r1, #0
	beq _0802F1CA
	movs r3, #0x1f
_0802F1CA:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
	ldr r0, [r5]
	cmp r0, #0
	bne _0802F24E
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802F24E
	ldr r0, _0802F200 @ =0x0000035D
	bl PlaySound_0824078c
	b _0802F24E
	.align 2, 0
_0802F200: .4byte 0x0000035D
_0802F204:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F224
	ldr r1, _0802F220 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _0802F234
	movs r3, #0x1a
	b _0802F234
	.align 2, 0
_0802F220: .4byte 0x00000824
_0802F224:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _0802F234
	movs r3, #0x1f
_0802F234:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
_0802F24E:
	movs r2, #8
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F35C
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F35C
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0802F2F2
	mov r0, r8
	cmp r0, #0x1f
	bgt _0802F354
	movs r0, #0x20
	mov r1, r8
	subs r0, r0, r1
	asrs r0, r0, #2
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r5, [r7, #5]
	rsbs r6, r0, #0
	ldr r2, _0802F2C0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F2C4
	asrs r1, r0, #0xc
	b _0802F2CA
	.align 2, 0
_0802F2C0: .4byte gSineTable
_0802F2C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F2CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F2E2
	asrs r0, r0, #0xc
	b _0802F2E8
_0802F2E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F2E8:
	strh r0, [r3, #4]
	mov r0, r8
	cmp r0, #0x1f
	ble _0802F35C
	b _0802F354
_0802F2F2:
	mov r1, r8
	cmp r1, #0x3f
	bgt _0802F354
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r5, [r7, #5]
	rsbs r6, r0, #0
	ldr r2, _0802F324 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F328
	asrs r1, r0, #0xc
	b _0802F32E
	.align 2, 0
_0802F324: .4byte gSineTable
_0802F328:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F32E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F346
	asrs r0, r0, #0xc
	b _0802F34C
_0802F346:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F34C:
	strh r0, [r3, #4]
	mov r0, r8
	cmp r0, #0x3f
	ble _0802F35C
_0802F354:
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F35C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
