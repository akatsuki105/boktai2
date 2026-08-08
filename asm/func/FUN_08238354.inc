	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0xc0
	adds r6, r7, #0
	b _082383A6
_08238360:
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_08237f74
	adds r1, r0, #0
	strb r1, [r4, #9]
	ldrb r0, [r4, #0xe]
	strb r0, [r4, #8]
	cmp r1, #0
	beq _082383D4
	cmp r1, #0
	bge _08238382
	adds r0, r5, #0
	movs r1, #4
	bl FUN_082382ec
	b _082383D4
_08238382:
	adds r0, r4, #0
	bl FUN_082381fc
	cmp r0, #0
	bge _0823839E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08238178
	adds r0, r5, #0
	movs r1, #5
	bl FUN_082382ec
	b _082383D4
_0823839E:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_082382f8
_082383A6:
	adds r0, r6, #0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	bne _08238360
	b _082383D4
_082383B4:
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _082383C0
	cmp r0, #2
	beq _082383CC
	b _082383D4
_082383C0:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r4, #0
	bl FUN_08238178
	b _082383D4
_082383CC:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08238178
_082383D4:
	adds r0, r5, #0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082383FA
	adds r0, #0xc
	ldrb r1, [r4, #9]
	bl FUN_08238014
	adds r1, r0, #0
	cmp r1, #0
	beq _082383FA
	cmp r1, #0
	bge _082383B4
	adds r0, r5, #0
	movs r1, #6
	bl FUN_082382ec
_082383FA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
