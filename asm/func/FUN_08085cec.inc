	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08085D14 @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085D04
	ldr r2, _08085D18 @ =0x00000406
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D1C
_08085D04:
	movs r0, #0xcd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085D2C
	adds r0, #1
	b _08085D2A
	.align 2, 0
_08085D14: .4byte 0x0000040A
_08085D18: .4byte 0x00000406
_08085D1C:
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08085D2C
	subs r0, #1
_08085D2A:
	strh r0, [r1]
_08085D2C:
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _08085D5C
	ldr r2, _08085D58 @ =0x0000032E
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #9
	beq _08085D4E
	movs r0, #9
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_08085cb0
_08085D4E:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	b _08085D9E
	.align 2, 0
_08085D58: .4byte 0x0000032E
_08085D5C:
	movs r1, #0xcd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D7C
	ldr r2, _08085D78 @ =0x0000032E
	adds r1, r4, r2
	movs r0, #8
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08085bd0
	b _08085D9E
	.align 2, 0
_08085D78: .4byte 0x0000032E
_08085D7C:
	ldr r0, _08085DA4 @ =0x0000032E
	adds r1, r4, r0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	beq _08085D98
	strh r2, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	bl FUN_08085cb0
_08085D98:
	adds r0, r4, #0
	bl FUN_08085b34
_08085D9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085DA4: .4byte 0x0000032E
