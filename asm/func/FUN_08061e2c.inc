	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _08061E94 @ =0x0000085C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08061E44
	b _08061F56
_08061E44:
	movs r2, #0
	mov sb, r2
	movs r7, #0
	ldr r0, _08061E98 @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
_08061E52:
	movs r0, #0x34
	muls r0, r7, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r4, r6, r0
	adds r2, r4, #0
	adds r2, #0x28
	ldrb r0, [r2]
	cmp r0, #0
	beq _08061F44
	adds r5, r4, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08061E74
	rsbs r0, r0, #0
_08061E74:
	cmp r0, #0xf
	bgt _08061E9C
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08061E82
	rsbs r0, r0, #0
_08061E82:
	cmp r0, #0xf
	bgt _08061E9C
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
	b _08061F44
	.align 2, 0
_08061E94: .4byte 0x0000085C
_08061E98: .4byte 0x085B0A08
_08061E9C:
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r3, r0, #0
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	mov ip, r0
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08061ED0
	asrs r2, r0, #0xc
	b _08061ED6
_08061ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061ED6:
	ldrh r0, [r4, #0x2c]
	subs r0, r0, r2
	strh r0, [r4, #0x2c]
	ldrb r1, [r1]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08061EF4
	asrs r1, r0, #0xc
	b _08061EFA
_08061EF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061EFA:
	ldrh r0, [r4, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldr r2, _08061F64 @ =0x00000934
	adds r1, r6, r2
	ldrh r0, [r4, #0x30]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r1, r8
	ands r0, r1
	cmp r0, #4
	bne _08061F40
	subs r2, #0xdc
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_08061F40:
	movs r0, #1
	add sb, r0
_08061F44:
	adds r7, #1
	cmp r7, #3
	ble _08061E52
	mov r1, sb
	cmp r1, #0
	bne _08061F56
	ldr r2, _08061F68 @ =0x0000085C
	adds r0, r6, r2
	strb r1, [r0]
_08061F56:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061F64: .4byte 0x00000934
_08061F68: .4byte 0x0000085C
