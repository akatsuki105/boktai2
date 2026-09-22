	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08018624 @ =0x085AA948
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080185FC
	adds r0, r4, #0
	bl _call_via_r1
_080185FC:
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bls _08018608
	adds r0, r4, #0
	bl WeatherManager_ScrollClouds
_08018608:
	ldrb r0, [r4, #0x19]
	cmp r0, #3
	bne _08018638
	ldr r0, _08018628 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0801862C @ =0x00000946
	adds r0, r0, r1
	ldr r2, _08018630 @ =0x00007FFF
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, _08018634 @ =0x0300007C
	movs r0, #1
	b _08018652
	.align 2, 0
_08018624: .4byte 0x085AA948
_08018628: .4byte 0x030046A0
_0801862C: .4byte 0x00000946
_08018630: .4byte 0x00007FFF
_08018634: .4byte 0x0300007C
_08018638:
	ldr r0, _08018674 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08018678 @ =0x00000946
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0801864E
	subs r0, r2, #1
	strh r0, [r1]
_0801864E:
	ldr r1, _0801867C @ =0x0300007C
	movs r0, #0
_08018652:
	str r0, [r1]
	ldr r1, _08018680 @ =0x03002B48
	ldr r0, [r1]
	cmp r0, #0
	ble _08018660
	subs r0, #1
	str r0, [r1]
_08018660:
	adds r0, r4, #0
	bl WeatherManager_UpdateParticles
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018674: .4byte 0x030046A0
_08018678: .4byte 0x00000946
_0801867C: .4byte 0x0300007C
_08018680: .4byte 0x03002B48
