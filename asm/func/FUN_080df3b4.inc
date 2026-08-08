	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x40
_080DF3BE:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DF3CE
	movs r0, #1
	b _080DF3D0
_080DF3CE:
	movs r0, #0
_080DF3D0:
	cmp r0, #0
	beq _080DF3DA
	adds r0, r4, #0
	bl FUN_0822a4e0
_080DF3DA:
	adds r4, #0xfc
	adds r5, #1
	cmp r5, #0x17
	ble _080DF3BE
	movs r1, #0
	ldr r0, _080DF3F0 @ =0x03000178
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080DF3F0: .4byte 0x03000178
