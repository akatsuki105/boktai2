	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800CFBE
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
_0800CFBE:
	ldrh r0, [r4, #0x2a]
	movs r1, #1
	orrs r1, r0
	strh r1, [r4, #0x2a]
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D062
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CFE4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800CFE4:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CFFC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800CFFC:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D014
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D014:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D02C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D02C:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D036
	movs r0, #0x78
	b _0800D05C
_0800D036:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D044
	movs r0, #0x7b
	b _0800D05C
_0800D044:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D050
	movs r0, #0x7c
	b _0800D05C
_0800D050:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D05C
	movs r0, #0x79
_0800D05C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D06C
_0800D062:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D06C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
