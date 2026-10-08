	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r6, _080982CC @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080982D4
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #8
	bl FUN_0808c658
	ldr r1, _080982D0 @ =FUN_080983a4
	b _0809833C
	.align 2, 0
_080982CC: .4byte 0x030044E0
_080982D0: .4byte FUN_080983a4
_080982D4:
	ldr r2, _08098348 @ =0x000009F8
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0809834C @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r2, _08098350 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08098368
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _08098354 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fbbc
	ldr r0, _08098358 @ =0x000014AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0809835C @ =0x000014C4
	adds r0, r5, r1
	ldr r2, _08098360 @ =0x00003AEE
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097ab8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097fb4
	ldr r1, _08098364 @ =FUN_080984a0
_0809833C:
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _08098390
	.align 2, 0
_08098348: .4byte 0x000009F8
_0809834C: .4byte 0x00001444
_08098350: .4byte 0x00001E64
_08098354: .4byte 0x00003AE8
_08098358: .4byte 0x000014AC
_0809835C: .4byte 0x000014C4
_08098360: .4byte 0x00003AEE
_08098364: .4byte FUN_080984a0
_08098368:
	ldr r1, _08098398 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08098390
	ldr r2, _0809839C @ =0x00001464
	adds r0, r5, r2
	ldr r2, _080983A0 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	bl FUN_08097c04
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097fb4
_08098390:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098398: .4byte 0x00003AE8
_0809839C: .4byte 0x00001464
_080983A0: .4byte 0x00003AEB
