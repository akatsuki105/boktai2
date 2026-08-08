	push {r4, r5, lr}
	sub sp, #0x20
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _0806E420
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
_0806E420:
	ldr r1, _0806E43C @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806E482
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bhi _0806E440
	movs r0, #0xd5
	bl PlaySound_082406e0
	b _0806E482
	.align 2, 0
_0806E43C: .4byte 0x0000037E
_0806E440:
	ldr r0, _0806E4A8 @ =0x0000038A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806E454
	ldr r0, _0806E4AC @ =0x0000026B
	bl PlaySound_082406e0
	movs r0, #0x28
	strh r0, [r5]
_0806E454:
	movs r0, #0xcd
	bl PlaySound_082406e0
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0xb4
	movs r3, #0
	bl FUN_08080be8
_0806E482:
	ldr r0, _0806E4B0 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806E49E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E49E:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E4A8: .4byte 0x0000038A
_0806E4AC: .4byte 0x0000026B
_0806E4B0: .4byte 0x0000037E
