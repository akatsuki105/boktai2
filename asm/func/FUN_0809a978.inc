	push {r4, r5, lr}
	subs r2, r1, #1
	cmp r1, #0
	bne _0809A982
	movs r2, #9
_0809A982:
	movs r3, #0
	ldr r5, _0809A994 @ =0x00000F58
	adds r4, r0, r5
_0809A988:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A998
	adds r0, r2, #0
	b _0809A9AA
	.align 2, 0
_0809A994: .4byte 0x00000F58
_0809A998:
	cmp r2, #0
	bne _0809A9A0
	movs r2, #9
	b _0809A9A2
_0809A9A0:
	subs r2, #1
_0809A9A2:
	adds r3, #1
	cmp r3, #9
	ble _0809A988
	adds r0, r1, #0
_0809A9AA:
	pop {r4, r5}
	pop {r1}
	bx r1
