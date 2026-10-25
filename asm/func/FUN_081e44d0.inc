	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E4510 @ =0x00001604
	adds r0, r4, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E4514 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E4518 @ =0x0000160C
	adds r0, r4, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #1
	ldr r2, _081E451C @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4520
	movs r0, #1
	b _081E4522
	.align 2, 0
_081E4510: .4byte 0x00001604
_081E4514: .4byte 0x00001608
_081E4518: .4byte 0x0000160C
_081E451C: .4byte 0x00001610
_081E4520:
	movs r0, #0
_081E4522:
	cmp r0, #0
	beq _081E4538
	bl Marquee_CloseGlobal
	ldr r0, _081E4540 @ =0x00001610
	adds r2, r4, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E4538:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4540: .4byte 0x00001610
