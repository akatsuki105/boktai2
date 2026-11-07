	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0813F620 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F624
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F626
	.align 2, 0
_0813F620: .4byte 0x0000046D
_0813F624:
	movs r0, #0
_0813F626:
	cmp r0, #0
	beq _0813F64E
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r6, #0x94
	lsls r6, r6, #1
	adds r2, r4, r6
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0813F64E:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _0813F67E
	asrs r0, r0, #2
	b _0813F684
_0813F67E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F684:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r4, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813F6A2
	asrs r0, r0, #2
	b _0813F6A8
_0813F6A2:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F6A8:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813F6B2
	movs r3, #0xc8
	b _0813F6BC
_0813F6B2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813F6BC
	adds r3, r0, #0
_0813F6BC:
	cmp r2, #0xc8
	ble _0813F6C4
	movs r2, #0xc8
	b _0813F6CE
_0813F6C4:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813F6CE
	adds r2, r0, #0
_0813F6CE:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldrh r0, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813F6F2
	cmp r2, #0
	bne _0813F6F2
	movs r0, #1
	b _0813F6F4
_0813F6F2:
	movs r0, #0
_0813F6F4:
	cmp r0, #0
	beq _0813F7C2
	ldr r1, _0813F778 @ =0x0000046B
	adds r0, r4, r1
	movs r7, #1
	strb r7, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r4, r2
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	movs r6, #0
	strh r0, [r5]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0813F77C @ =0x00000666
	add r0, r8
	strb r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, [r2]
	adds r3, r0, #0
	ands r3, r1
	cmp r3, #0
	beq _0813F78C
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _0813F780 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_08140970
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r3, _0813F784 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0813F788 @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r1, r4, r2
	movs r0, #0
	str r0, [r1]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	adds r0, r4, #0
	bl FUN_08140904
	b _0813F7C2
	.align 2, 0
_0813F778: .4byte 0x0000046B
_0813F77C: .4byte 0x00000666
_0813F780: .4byte 0x03002BE0
_0813F784: .4byte 0x00000469
_0813F788: .4byte 0x0000046A
_0813F78C:
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r6, [r0]
	ldr r6, _0813F7CC @ =0x0000046A
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0813F7D0 @ =0x00000484
	adds r0, r4, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r4, #0
	bl FUN_08140904
_0813F7C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F7CC: .4byte 0x0000046A
_0813F7D0: .4byte 0x00000484
