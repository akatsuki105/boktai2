	push {r4, lr}
	bl FUN_0822d114
	bl FUN_0822b238
	ldr r0, _0822A274 @ =0x03003534
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0822A278 @ =0x03003558
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0822A27C @ =0x03003554
	ldr r0, [r0]
	bl _call_via_r0
	bl FUN_0822b470
	ldr r4, _0822A280 @ =0x0300446C
	ldr r0, [r4]
	cmp r0, #0
	beq _0822A284
	bl FUN_0822d8e8
	bl FUN_0822d828
	ldr r0, [r4]
	cmp r0, #0
	ble _0822A268
	subs r0, #1
	str r0, [r4]
_0822A268:
	ldr r0, [r4]
	cmp r0, #0
	bne _0822A28C
	bl FUN_0822d98c
	b _0822A28C
	.align 2, 0
_0822A274: .4byte 0x03003534
_0822A278: .4byte 0x03003558
_0822A27C: .4byte 0x03003554
_0822A280: .4byte 0x0300446C
_0822A284:
	bl FUN_0822d630
	bl FUN_0822d248
_0822A28C:
	movs r0, #0
	bl FUN_0822b41c
	ldr r1, _0822A2A4 @ =0x03002CF0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0822A2A4: .4byte 0x03002CF0
