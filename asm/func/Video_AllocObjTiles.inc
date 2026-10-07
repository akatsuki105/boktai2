	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0822B288 @ =0x03003590
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0x7f
	bls _0822B290
	ldr r0, _0822B28C @ =0x03003594
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _0822B2F8
	.align 2, 0
_0822B288: .4byte 0x03003590
_0822B28C: .4byte 0x03003594
_0822B290:
	ldr r0, _0822B2A8 @ =0x03003588
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, r1, r4
	ldr r2, _0822B2AC @ =0x000003FF
	mov ip, r0
	cmp r1, r2
	ble _0822B2B8
	ldr r0, _0822B2B0 @ =0x03003594
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _0822B2F8
	.align 2, 0
_0822B2A8: .4byte 0x03003588
_0822B2AC: .4byte 0x000003FF
_0822B2B0: .4byte 0x03003594
_0822B2B4:
	ldrh r0, [r2, #2]
	b _0822B2F8
_0822B2B8:
	ldr r2, _0822B300 @ =0x03000288
	movs r1, #0
	ldrh r0, [r6]
	adds r7, r2, #0
	cmp r1, r0
	bge _0822B2D4
	adds r3, r0, #0
_0822B2C6:
	ldr r0, [r2, #4]
	cmp r0, r5
	beq _0822B2B4
	adds r1, #1
	adds r2, #8
	cmp r1, r3
	blt _0822B2C6
_0822B2D4:
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r7
	strh r4, [r1]
	mov r2, ip
	ldrh r0, [r2]
	strh r0, [r1, #2]
	str r5, [r1, #4]
	adds r0, r0, r4
	strh r0, [r2]
	ldr r2, _0822B304 @ =0x03003578
	ldrh r0, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldrh r0, [r1, #2]
_0822B2F8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0822B300: .4byte 0x03000288
_0822B304: .4byte 0x03003578
