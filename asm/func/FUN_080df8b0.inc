	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_080DF8B8:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _080DF8CA
	movs r0, #1
	b _080DF8CC
_080DF8CA:
	movs r0, #0
_080DF8CC:
	cmp r0, #0
	bne _080DF8F0
	movs r0, #0xda
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	ldr r3, _080DF8EC @ =0x000001AF
	adds r1, r0, r3
	strb r2, [r1]
	b _080DF8F8
	.align 2, 0
_080DF8EC: .4byte 0x000001AF
_080DF8F0:
	adds r2, #1
	cmp r2, #7
	ble _080DF8B8
	movs r0, #0
_080DF8F8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
