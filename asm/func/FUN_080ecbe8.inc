	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r3, r1, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r0, _080ECC20 @ =0xFFFFBFFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	cmp r3, #0
	beq _080ECC24
	cmp r3, #1
	bne _080ECC1C
	b _080ECE10
_080ECC1C:
	b _080ECEF2
	.align 2, 0
_080ECC20: .4byte 0xFFFFBFFF
_080ECC24:
	movs r1, #0x10
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r3, r5, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r3, #0
	cmp r2, #0
	blt _080ECC68
	cmp r1, #0
	blt _080ECC68
	ldr r0, _080ECC6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080ECC68
	ldr r0, _080ECC70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080ECC74
_080ECC68:
	movs r4, #0
	b _080ECC82
	.align 2, 0
_080ECC6C: .4byte 0x030046A8
_080ECC70: .4byte 0x030046AC
_080ECC74:
	ldr r0, _080ECC94 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080ECC82:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080ECC98
	adds r0, #4
	b _080ECCA4
	.align 2, 0
_080ECC94: .4byte 0x030046A4
_080ECC98:
	ldr r0, _080ECCB8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080ECCA4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080ECCBC
	cmp r2, #2
	beq _080ECCC0
	b _080ECCC4
	.align 2, 0
_080ECCB8: .4byte 0x030046A4
_080ECCBC:
	ldrb r0, [r6, #4]
	b _080ECCC2
_080ECCC0:
	ldrb r0, [r6]
_080ECCC2:
	subs r1, r1, r0
_080ECCC4:
	strh r1, [r6, #2]
	ldrh r1, [r5, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r3, _080ECCEC @ =0x000004A4
	adds r0, r5, r3
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080ECCF0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
	b _080ECD14
	.align 2, 0
_080ECCEC: .4byte 0x000004A4
_080ECCF0:
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080ECD0E
	cmp r0, #2
	beq _080ECD1C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080ECD1C
_080ECD0E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_080ECD14:
	ldr r1, _080ECD8C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080ECD1C:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	mov r8, r3
	movs r6, #1
	movs r0, #1
	strh r0, [r1, #6]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ECD98
	movs r1, #0xc1
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r1, #7
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _080ECD90 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _080ECD94 @ =0x0000046B
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #0xe6
	adds r0, r5, r2
	strb r6, [r0]
	b _080ECDDC
	.align 2, 0
_080ECD8C: .4byte 0xFFFFFDFF
_080ECD90: .4byte 0x00000469
_080ECD94: .4byte 0x0000046B
_080ECD98:
	movs r1, #0xd1
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _080ECDF8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _080ECDFC @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	mov r3, r8
	str r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080ECE00 @ =0x000005A4
	adds r0, r5, r2
	ldr r1, [r0]
	ldr r3, _080ECE04 @ =0x0000046D
	adds r0, r5, r3
	strb r6, [r0]
	ldr r6, _080ECE08 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	subs r2, #0x51
	adds r0, r5, r2
	strb r4, [r0]
_080ECDDC:
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	mov r1, r8
	strh r1, [r0]
	ldr r2, _080ECE0C @ =0x00000482
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	b _080ECEF2
	.align 2, 0
_080ECDF8: .4byte 0x00000469
_080ECDFC: .4byte 0x0000046A
_080ECE00: .4byte 0x000005A4
_080ECE04: .4byte 0x0000046D
_080ECE08: .4byte 0x0000046B
_080ECE0C: .4byte 0x00000482
_080ECE10:
	ldr r3, _080ECE84 @ =0x000001DF
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _080ECE26
	movs r0, #4
	ldr r6, _080ECE88 @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080ECE26:
	movs r0, #0x80
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _080ECE8C @ =0x0000024E
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _080ECE90 @ =0x03002BE0
	ldr r3, _080ECE94 @ =0x000004A4
	adds r0, r5, r3
	ldr r7, [r0]
	movs r6, #8
	adds r6, r6, r5
	mov r8, r6
	ldr r0, [r1]
	adds r6, r0, #0
	adds r6, #0x2c
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _080ECE98
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080ECE98
	cmp r0, #2
	beq _080ECEA0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080ECEA0
	.align 2, 0
_080ECE84: .4byte 0x000001DF
_080ECE88: .4byte 0x00000222
_080ECE8C: .4byte 0x0000024E
_080ECE90: .4byte 0x03002BE0
_080ECE94: .4byte 0x000004A4
_080ECE98:
	ldr r0, _080ECF00 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_080ECEA0:
	movs r2, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080ECF04 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _080ECF08 @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _080ECF0C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0x1a
	ldr r6, _080ECF10 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _080ECF14 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_080ECEF2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ECF00: .4byte 0xFFFFFDFF
_080ECF04: .4byte 0x00000469
_080ECF08: .4byte 0x0000046A
_080ECF0C: .4byte 0x00000484
_080ECF10: .4byte 0x0000046D
_080ECF14: .4byte 0x0000046B

