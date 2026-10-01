	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl EntityDA0B_TakeFnChanged
	ldr r3, _0801CA28 @ =0x030044E0
	ldrh r6, [r3]
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0801CA2C
	ldrh r1, [r3, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801CA08
	b _0801CBAE
_0801CA08:
	adds r1, r5, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CA1E
	movs r0, #0
	strb r0, [r1]
_0801CA1E:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CBAE
	.align 2, 0
_0801CA28: .4byte 0x030044E0
_0801CA2C:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r4, #0
	ldrh r3, [r3, #2]
	movs r0, #0x40
	mov ip, r0
	ands r0, r3
	mov r8, r1
	cmp r0, #0
	beq _0801CA46
	movs r4, #1
	b _0801CABE
_0801CA46:
	movs r7, #0x80
	adds r0, r7, #0
	ands r0, r3
	cmp r0, #0
	beq _0801CA54
	movs r4, #2
	b _0801CABE
_0801CA54:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0801CA60
	movs r4, #4
	b _0801CABE
_0801CA60:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0801CA6A
	movs r4, #8
_0801CA6A:
	cmp r4, #0
	bne _0801CABE
	adds r3, r5, #0
	adds r3, #0x3f
	ldrb r1, [r3]
	cmp r1, #7
	bls _0801CAB2
	mov r0, ip
	ands r0, r6
	cmp r0, #0
	beq _0801CA84
	movs r4, #1
	b _0801CA8E
_0801CA84:
	adds r0, r7, #0
	ands r0, r6
	cmp r0, #0
	beq _0801CA8E
	movs r4, #2
_0801CA8E:
	ldr r0, _0801CAA0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801CAA4
	movs r0, #4
	orrs r4, r0
	b _0801CABE
	.align 2, 0
_0801CAA0: .4byte 0x030044E0
_0801CAA4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801CABE
	movs r0, #8
	orrs r4, r0
	b _0801CABE
_0801CAB2:
	movs r0, #0xf0
	ands r0, r6
	cmp r0, #0
	beq _0801CABE
	adds r0, r1, #1
	strb r0, [r3]
_0801CABE:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0801CADA
	asrs r0, r2, #2
	cmp r0, #0
	bne _0801CAD6
	movs r0, #3
	ands r0, r2
	adds r2, r0, #0
	adds r2, #0xc
	b _0801CB24
_0801CAD6:
	subs r2, #4
	b _0801CB24
_0801CADA:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0801CAF0
	asrs r0, r2, #2
	cmp r0, #3
	bne _0801CAEC
	ands r2, r0
	b _0801CB24
_0801CAEC:
	adds r2, #4
	b _0801CB24
_0801CAF0:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0801CB0C
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801CB08
	movs r0, #0xfc
	ands r0, r2
	adds r2, r0, #3
	b _0801CB24
_0801CB08:
	subs r2, #1
	b _0801CB24
_0801CB0C:
	movs r0, #8
	ands r4, r0
	cmp r4, #0
	beq _0801CB2C
	movs r0, #3
	ands r0, r2
	cmp r0, #3
	bne _0801CB22
	movs r0, #0xfc
	ands r2, r0
	b _0801CB24
_0801CB22:
	adds r2, #1
_0801CB24:
	adds r1, r5, #0
	adds r1, #0x3f
	movs r0, #0
	strb r0, [r1]
_0801CB2C:
	mov r3, r8
	ldrb r1, [r3]
	cmp r2, r1
	beq _0801CB66
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r4, _0801CB8C @ =0x00000B24
	adds r1, r5, r4
	strh r0, [r1]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r4, #2
	adds r1, r5, r4
	strh r0, [r1]
	strb r2, [r3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
_0801CB66:
	ldr r0, _0801CB90 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CB9E
	adds r0, r2, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	ldr r1, [r5, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801CB94
	adds r0, r5, #0
	bl FUN_0801c5f0
	b _0801CBBA
	.align 2, 0
_0801CB8C: .4byte 0x00000B24
_0801CB90: .4byte 0x030044E0
_0801CB94:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801CBBA
_0801CB9E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CBAE
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801CBBA
_0801CBAE:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CBBA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
