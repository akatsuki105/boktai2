	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r2, [r4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	cmp r1, #0
	blt _08064E1A
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _08064DD6
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	b _08064FCE
_08064DD6:
	ldrb r6, [r4, #5]
	cmp r6, #0
	bne _08064E1A
	cmp r1, #5
	bgt _08064E2C
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _08064DF4
	strb r6, [r4, #3]
	ldr r2, _08064DF0 @ =0x00000951
	adds r0, r5, r2
	strb r6, [r0]
	b _08064E1A
	.align 2, 0
_08064DF0: .4byte 0x00000951
_08064DF4:
	movs r6, #1
	strb r6, [r4, #3]
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _08064E1A
	ldr r1, _08064E24 @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08064E28 @ =0x00000964
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x13
	adds r1, r5, r2
	strb r0, [r1]
_08064E1A:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	b _08064FCE
	.align 2, 0
_08064E24: .4byte 0x00000979
_08064E28: .4byte 0x00000964
_08064E2C:
	adds r0, r2, #0
	subs r0, #0xe
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08064E3A
	b _08064F50
_08064E3A:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #1
	bls _08064E48
	b _08064FCE
_08064E48:
	cmp r1, #0xf
	bne _08064EA8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08064EA0
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064F12
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #4
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	ldr r0, _08064EA4 @ =0x00000382
	adds r1, r5, r0
	movs r0, #0xbe
	strb r0, [r1]
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064EA0:
	movs r0, #0xc
	b _08064FCE
	.align 2, 0
_08064EA4: .4byte 0x00000382
_08064EA8:
	cmp r1, #0x10
	bne _08064EFC
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08064EF8
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064F12
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #0x20
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064EF8:
	movs r0, #0xd
	b _08064FCE
_08064EFC:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08064F4C
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	bne _08064F16
_08064F12:
	ldrb r0, [r4]
	b _08064FCE
_08064F16:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #0x3c
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064F4C:
	movs r0, #0xe
	b _08064FCE
_08064F50:
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bhi _08064FCE
	cmp r1, #0x11
	bne _08064F6E
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064FC8
	movs r0, #0xb
	b _08064FCE
_08064F6E:
	cmp r1, #6
	bne _08064F76
	movs r0, #0xa
	b _08064FCE
_08064F76:
	cmp r1, #7
	beq _08064F7E
	cmp r1, #9
	bne _08064F82
_08064F7E:
	movs r0, #9
	b _08064FCE
_08064F82:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #8
	bne _08064F9E
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064FC8
	adds r0, r5, #0
	bl FUN_08064be4
	movs r0, #2
	b _08064FCE
_08064F9E:
	cmp r0, #0xb
	bne _08064FA6
	movs r0, #2
	b _08064FCE
_08064FA6:
	cmp r0, #0xd
	bne _08064FBC
	ldr r1, _08064FB8 @ =0x000003FB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08064FC8
	movs r0, #0x11
	b _08064FCE
	.align 2, 0
_08064FB8: .4byte 0x000003FB
_08064FBC:
	cmp r0, #0xa
	bne _08064FC4
	movs r0, #0xf
	b _08064FCE
_08064FC4:
	cmp r0, #0xc
	beq _08064FCC
_08064FC8:
	ldrb r0, [r6]
	b _08064FCE
_08064FCC:
	movs r0, #0x10
_08064FCE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
