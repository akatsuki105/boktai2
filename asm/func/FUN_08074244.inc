	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r2, [r1]
	movs r6, #0x40
	cmp r2, #1
	bne _08074258
	movs r6, #0x30
_08074258:
	ldr r3, _0807426C @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807429E
	cmp r0, #1
	bgt _08074270
	cmp r0, #0
	beq _08074276
	b _08074340
	.align 2, 0
_0807426C: .4byte 0x0000037D
_08074270:
	cmp r0, #2
	beq _080742B2
	b _08074340
_08074276:
	ldrb r0, [r1]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08074340
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _08074340
_0807429E:
	ldrb r0, [r1]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	b _08074340
_080742B2:
	cmp r2, #0
	bne _080742D0
	ldr r1, _080742CC @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x11
	bne _080742E0
	movs r0, #0xe4
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080742E0
	.align 2, 0
_080742CC: .4byte 0x0000037E
_080742D0:
	ldr r3, _08074348 @ =0x0000037E
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0xb
	bne _080742E0
	ldr r0, _0807434C @ =0x0000038E
	bl PlaySound_082406e0
_080742E0:
	ldr r0, _08074348 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	adds r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _08074330
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _08074330
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08074330
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_08061a98
_08074330:
	cmp r6, #0
	beq _08074340
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_08074340:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08074348: .4byte 0x0000037E
_0807434C: .4byte 0x0000038E
