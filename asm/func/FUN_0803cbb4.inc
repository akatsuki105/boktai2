	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #7
	bl Boss_Get
	adds r7, r0, #0
	cmp r7, #0
	beq _0803CC4A
	cmp r6, #1
	beq _0803CBCC
	cmp r6, #4
	bne _0803CBE6
_0803CBCC:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r7, r0
	ldr r4, [r5]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	adds r2, r0, #0
	adds r2, #1
	adds r0, r4, #0
	movs r1, #1
	b _0803CC06
_0803CBE6:
	cmp r6, #2
	beq _0803CBEE
	cmp r6, #5
	bne _0803CC0E
_0803CBEE:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r5, r7, r1
	ldr r4, [r5]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	adds r2, r0, #0
	adds r2, #1
	adds r0, r4, #0
	movs r1, #3
_0803CC06:
	bl FUN_0807ae6c
	adds r4, r5, #0
	b _0803CC3E
_0803CC0E:
	movs r3, #0x82
	lsls r3, r3, #1
	adds r4, r7, r3
	ldr r5, [r4]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r3, _0803CC50 @ =0x00000311
	adds r1, r7, r3
	ldrb r1, [r1]
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	bl Player_ApplyBadCondition
_0803CC3E:
	ldr r2, [r4]
	adds r2, #0x2c
	movs r0, #2
	movs r1, #0
	bl FUN_08050e2c
_0803CC4A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC50: .4byte 0x00000311
