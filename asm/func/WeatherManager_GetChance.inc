	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08017C00 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08017C04 @ =0x000002B2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08017C08
	movs r0, #0x32
	ldrsh r4, [r1, r0]
	b _08017C14
	.align 2, 0
_08017C00: .4byte 0x030046A0
_08017C04: .4byte 0x000002B2
_08017C08:
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	movs r2, #0x32
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	asrs r4, r0, #6
_08017C14:
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08017C24
	cmp r1, #0
	bne _08017C26
_08017C24:
	asrs r4, r4, #1
_08017C26:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
