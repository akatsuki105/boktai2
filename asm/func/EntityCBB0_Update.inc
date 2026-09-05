	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b2354
	adds r0, r4, #0
	bl FUN_080b2434
	adds r0, r4, #0
	bl FUN_080b2474
	strb r0, [r4, #0x1f]
	ldr r0, _080B25BC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	cmp r1, #4
	bne _080B25C0
	movs r0, #0
	b _080B26C2
	.align 2, 0
_080B25BC: .4byte 0x03002BE0
_080B25C0:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bne _080B2604
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0xe
	beq _080B2604
	cmp r1, #1
	bne _080B2604
	ldr r0, _080B262C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2604
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080ad1ec
	ldr r2, _080B2630 @ =0x00000C6C
	adds r0, r4, r2
	movs r1, #9
	bl FUN_080af374
	adds r0, r4, #0
	bl FUN_080af0c8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080ad204
_080B2604:
	ldr r1, _080B2634 @ =0x085AD07C
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B2638
	adds r0, r4, #0
	bl FUN_080ad96c
	b _080B26BC
	.align 2, 0
_080B2628: .4byte 0x000004FC
_080B262C: .4byte 0x030046A0
_080B2630: .4byte 0x00000C6C
_080B2634: .4byte 0x085AD07C
_080B2638:
	adds r0, r4, #0
	bl FUN_080b09d4
	adds r0, r4, #0
	bl FUN_080b252c
	adds r0, r4, #0
	bl FUN_080ae8a4
	adds r0, r4, #0
	bl FUN_080ade4c
	adds r0, r4, #0
	bl FUN_080b24a4
	ldr r1, _080B2688 @ =0x0000133E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B26BC
	ldr r2, _080B268C @ =0x00000C0F
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B26B4
	ldr r0, _080B2690 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2698
	ldr r2, _080B2694 @ =0x00001344
	adds r0, r4, r2
	ldrh r0, [r0]
	bl PlaySound_082406e0
	b _080B26AE
	.align 2, 0
_080B2688: .4byte 0x0000133E
_080B268C: .4byte 0x00000C0F
_080B2690: .4byte 0x030046A0
_080B2694: .4byte 0x00001344
_080B2698:
	ldr r1, _080B26C8 @ =0x0000133F
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
_080B26AE:
	ldr r0, _080B26CC @ =0x0000029B
	bl PlaySound_082406e0
_080B26B4:
	ldr r0, _080B26D0 @ =0x0000133E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080B26BC:
	adds r0, r4, #0
	bl FUN_080ad23c
_080B26C2:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B26C8: .4byte 0x0000133F
_080B26CC: .4byte 0x0000029B
_080B26D0: .4byte 0x0000133E
