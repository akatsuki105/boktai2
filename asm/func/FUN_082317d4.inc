	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082317F4 @ =0x03000768
	ldr r3, [r0]
	cmp r3, #0
	beq _08231806
_082317E0:
	ldr r2, [r3, #8]
	ldr r1, [r3, #4]
	cmp r1, #0
	ble _08231800
_082317E8:
	ldr r0, [r2]
	cmp r0, r4
	bne _082317F8
	adds r0, r2, #0
	b _08231808
	.align 2, 0
_082317F4: .4byte 0x03000768
_082317F8:
	adds r2, #8
	subs r1, #1
	cmp r1, #0
	bgt _082317E8
_08231800:
	ldr r3, [r3]
	cmp r3, #0
	bne _082317E0
_08231806:
	movs r0, #0
_08231808:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
