	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E9FE
	movs r0, #0
	strb r0, [r1]
_0809E9FE:
	ldr r0, _0809EA2C @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	beq _0809EA7E
	ldr r0, _0809EA30 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0809EA3C
	adds r0, r4, #0
	bl FUN_0809e9d0
	cmp r0, #0
	beq _0809EA34
	adds r0, r4, #0
	bl FUN_0809e89c
	b _0809EA5E
	.align 2, 0
_0809EA2C: .4byte 0x03002BE0
_0809EA30: .4byte 0x030046A0
_0809EA34:
	adds r0, r4, #0
	bl FUN_0809e840
	b _0809EA5E
_0809EA3C:
	ldr r2, _0809EA54 @ =0x00000934
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EA58
	adds r0, r4, #0
	bl FUN_0809e734
	b _0809EA5E
	.align 2, 0
_0809EA54: .4byte 0x00000934
_0809EA58:
	adds r0, r4, #0
	bl FUN_0809e7c4
_0809EA5E:
	ldr r0, _0809EA88 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _0809EA6A
	movs r1, #1
_0809EA6A:
	cmp r1, #0
	beq _0809EA7E
	ldr r0, _0809EA8C @ =0x03002BF0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809EA7E
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_0809EA7E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EA88: .4byte 0x03002B80
_0809EA8C: .4byte 0x03002BF0
