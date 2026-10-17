	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ce00c
	adds r0, r4, #0
	bl FUN_080ce264
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cdeb0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cddf0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cdfd4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cd958
	adds r0, r4, #0
	bl FUN_080cc648
	adds r0, r4, #0
	bl FUN_080cc780
	adds r0, r4, #0
	bl FUN_080ccf2c
	adds r0, r4, #0
	bl FUN_080cd0f0
	ldr r0, _080CE318 @ =0x00000714
	adds r1, r4, r0
	ldr r2, _080CE31C @ =0x000006AC
	adds r0, r4, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, _080CE320 @ =0x00000604
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2c]
	adds r0, r0, r2
	ldr r2, _080CE324 @ =0x000005FC
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080CE328 @ =0x00000606
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	ldr r2, _080CE32C @ =0x000005FE
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x30]
	adds r0, r0, r2
	subs r1, #8
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE318: .4byte 0x00000714
_080CE31C: .4byte 0x000006AC
_080CE320: .4byte 0x00000604
_080CE324: .4byte 0x000005FC
_080CE328: .4byte 0x00000606
_080CE32C: .4byte 0x000005FE
