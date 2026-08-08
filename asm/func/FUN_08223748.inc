	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	ldr r1, _0822379C @ =0x00000F45
	add r1, r8
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0
	mov sl, r0
_08223762:
	movs r0, #0xd8
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x1c
	mov r2, r8
	adds r5, r2, r0
	adds r1, r5, #0
	adds r1, #0xd4
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xad
	ldrb r1, [r0]
	movs r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08223788
	b _082238C8
_08223788:
	adds r0, r5, #0
	adds r0, #0xae
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _082237A0
	movs r3, #0
	movs r4, #0x80
	b _082237A4
	.align 2, 0
_0822379C: .4byte 0x00000F45
_082237A0:
	movs r3, #0x80
	movs r4, #0
_082237A4:
	mov r6, r8
	ldr r2, [r6, #0x18]
	movs r0, #0x2c
	ldrsh r1, [r2, r0]
	adds r0, r5, #0
	adds r0, #0x48
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	subs r6, r1, r3
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	subs r4, r1, r4
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r1, r0
	ldr r0, _082237F4 @ =0x00000F1A
	add r0, r8
	ldrh r0, [r0]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r1, r0
	bge _082238C8
	ldrb r0, [r7]
	cmp r0, #0
	bne _082237F8
	movs r0, #0
	mov sb, r0
	movs r7, #6
	movs r3, #7
	b _08223800
	.align 2, 0
_082237F4: .4byte 0x00000F1A
_082237F8:
	movs r1, #0
	mov sb, r1
	movs r7, #1
	movs r3, #2
_08223800:
	adds r0, r6, #0
	adds r1, r4, #0
	str r3, [sp]
	bl FUN_0823785c
	subs r0, #0x10
	lsls r0, r0, #0x18
	mov r2, sb
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	lsrs r2, r0, #0x1d
	ldr r3, [sp]
	cmp r1, r2
	beq _08223834
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _08223834
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _08223834
	movs r3, #0xff
	movs r7, #0xff
	movs r0, #0xff
	mov sb, r0
_08223834:
	mov r1, sb
	lsls r0, r1, #0x18
	ldr r1, _082238A4 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _082238A8 @ =0x00000932
	adds r1, r1, r2
	asrs r0, r0, #0x18
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	beq _0822385A
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	beq _0822385A
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _082238C8
_0822385A:
	adds r0, r5, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0x2e
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08223872
	rsbs r0, r0, #0
_08223872:
	cmp r0, #0x77
	bgt _082238C8
	adds r1, r5, #0
	adds r1, #0xd4
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0xd0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r3, r1, r0
	str r3, [r2]
	ldr r2, _082238AC @ =0x00000F45
	add r2, r8
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _082238B0
	mov r6, sl
	strb r6, [r2]
	b _082238C8
	.align 2, 0
_082238A4: .4byte 0x030046A0
_082238A8: .4byte 0x00000932
_082238AC: .4byte 0x00000F45
_082238B0:
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #0xd8
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0xec
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r3, r0
	bge _082238C8
	mov r0, sl
	strb r0, [r2]
_082238C8:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #0xf
	bgt _082238D4
	b _08223762
_082238D4:
	movs r6, #0
	mov sl, r6
_082238D8:
	movs r0, #0xd8
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x1c
	mov r2, r8
	adds r5, r2, r0
	ldr r0, _0822391C @ =0x00000F45
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp sl, r0
	bne _08223932
	adds r4, r5, #0
	adds r4, #0xb0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _08223920
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r5, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	bl FUN_0822b20c
	movs r0, #0xa
	strb r0, [r4]
	b _0822396A
	.align 2, 0
_0822391C: .4byte 0x00000F45
_08223920:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r5, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _0822396A
_08223932:
	adds r2, r5, #0
	adds r2, #0xb0
	ldrb r1, [r2]
	adds r0, r1, #0
	adds r0, #0xff
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _0822395A
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r5, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _0822396A
_0822395A:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r5, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
_0822396A:
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #0xf
	ble _082238D8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
