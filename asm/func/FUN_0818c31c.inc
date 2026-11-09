	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0818C33C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C340
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C342
	.align 2, 0
_0818C33C: .4byte 0x0000046C
_0818C340:
	movs r0, #0
_0818C342:
	cmp r0, #0
	beq _0818C35E
	ldr r3, _0818C3A4 @ =0x00000472
	adds r0, r4, r3
	ldr r2, _0818C3A8 @ =0xFFFFFF00
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_0819014c
_0818C35E:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r3, _0818C3AC @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	cmp r0, #0x28
	ble _0818C3B0
	movs r2, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #0x1b
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0818C3AC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0818C3B4
	.align 2, 0
_0818C3A4: .4byte 0x00000472
_0818C3A8: .4byte 0xFFFFFF00
_0818C3AC: .4byte 0x00000484
_0818C3B0:
	adds r0, #1
	str r0, [r1]
_0818C3B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
