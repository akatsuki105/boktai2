	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080528D2
	movs r0, #0
	strb r0, [r4, #0x1d]
_080528D2:
	ldr r2, [r4, #0x18]
	cmp r2, #0x1d
	bls _08052910
	ldr r0, _08052908 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _0805290C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _08052910
	movs r0, #4
	bl Sound_FadeOutBGMTemporarily
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r1, #0x8b
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08052900
	bl _call_via_r0
_08052900:
	adds r0, r4, #0
	bl KillEntity
	b _08052914
	.align 2, 0
_08052908: .4byte 0x030044E0
_0805290C: .4byte 0x0000030F
_08052910:
	adds r0, r2, #1
	str r0, [r4, #0x18]
_08052914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
