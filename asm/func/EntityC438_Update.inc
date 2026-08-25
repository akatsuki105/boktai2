	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AADA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080AADAC
	adds r0, r4, #0
	bl FUN_080aad30
	cmp r0, #0
	beq _080AADAC
	ldr r0, [r4, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080AADB2
	.align 2, 0
_080AADA8: .4byte 0x030047A4
_080AADAC:
	ldr r0, [r4, #0x24]
	movs r1, #1
	orrs r0, r1
_080AADB2:
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
