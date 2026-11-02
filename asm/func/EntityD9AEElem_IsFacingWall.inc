	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003204
	cmp r2, #1
	bgt _080031E8
	cmp r2, #0
	beq _080031F2
	b _0800321C
_080031E8:
	cmp r2, #2
	beq _08003208
	cmp r2, #3
	beq _08003218
	b _0800321C
_080031F2:
	ldr r0, _08003200 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _0800321C
	.align 2, 0
_08003200: .4byte 0x030046A4
_08003204:
	movs r0, #1
	b _0800321C
_08003208:
	ldr r0, _08003214 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _0800321C
	.align 2, 0
_08003214: .4byte 0x030046A4
_08003218:
	movs r0, #1
	rsbs r0, r0, #0
_0800321C:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800322E
	adds r0, #4
	b _0800323A
_0800322E:
	ldr r0, _08003254 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800323A:
	cmp r0, #0
	beq _08003262
	ldrb r2, [r0]
	movs r0, #0xf
	ldrb r3, [r6]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	blo _08003258
	movs r0, #1
	b _08003264
	.align 2, 0
_08003254: .4byte 0x030046A4
_08003258:
	ldrb r0, [r5]
	cmp r0, #5
	bne _08003262
	bl EntityD9AE_PlayHitWallSound
_08003262:
	movs r0, #0
_08003264:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
