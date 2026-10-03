	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809329C @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080932B6
	ldr r1, _080932A0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r0, _080932A4 @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080932A8 @ =0x00003F9D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080932B0
	ldr r0, _080932AC @ =0x0000027F
	bl PlaySound_082406e0
	b _080932B6
	.align 2, 0
_0809329C: .4byte 0x000009EE
_080932A0: .4byte 0x00003AEE
_080932A4: .4byte 0x000020AC
_080932A8: .4byte 0x00003F9D
_080932AC: .4byte 0x0000027F
_080932B0:
	ldr r0, _080932D0 @ =0x0000027E
	bl PlaySound_082406e0
_080932B6:
	ldr r1, _080932D4 @ =0x00003F9D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080932DC
	ldr r1, _080932D8 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #0x10
	movs r1, #0
	bl FUN_0808a458
	b _080932EA
	.align 2, 0
_080932D0: .4byte 0x0000027E
_080932D4: .4byte 0x00003F9D
_080932D8: .4byte 0x000009EE
_080932DC:
	ldr r1, _0809330C @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #0x10
	ldr r1, _08093310 @ =0x00007FFF
	bl FUN_0808a458
_080932EA:
	ldr r0, _0809330C @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bls _08093306
	ldr r1, _08093314 @ =FUN_08093318
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08093306:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809330C: .4byte 0x000009EE
_08093310: .4byte 0x00007FFF
_08093314: .4byte FUN_08093318
