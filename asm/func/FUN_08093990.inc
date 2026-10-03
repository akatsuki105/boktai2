	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080939CC @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #7
	bls _080939A4
	adds r0, r4, #0
	bl FUN_0808c1cc
_080939A4:
	ldr r2, _080939D0 @ =0x00003F9D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080939D8
	ldrh r0, [r5]
	cmp r0, #9
	bls _080939EC
	ldr r2, _080939D4 @ =0x00002524
	adds r0, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl MainSprite_AdvanceAnim
	b _080939EC
	.align 2, 0
_080939CC: .4byte 0x000009EE
_080939D0: .4byte 0x00003F9D
_080939D4: .4byte 0x00002524
_080939D8:
	ldr r2, _08093A0C @ =0x00002524
	adds r0, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl MainSprite_AdvanceAnim
_080939EC:
	ldr r1, _08093A10 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08093A18
	ldr r2, _08093A14 @ =0x0000252C
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08093A24
	.align 2, 0
_08093A0C: .4byte 0x00002524
_08093A10: .4byte 0x000009EE
_08093A14: .4byte 0x0000252C
_08093A18:
	ldr r1, _08093A48 @ =0x0000252C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08093A24:
	str r1, [r0]
	ldr r2, _08093A4C @ =0x000009EE
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _08093A42
	ldr r1, _08093A50 @ =FUN_08093a54
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08093A42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093A48: .4byte 0x0000252C
_08093A4C: .4byte 0x000009EE
_08093A50: .4byte FUN_08093a54
