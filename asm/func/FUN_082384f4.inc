	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08238508 @ =0x03000820
	ldr r4, [r0]
	cmp r4, #0
	bne _0823850C
	movs r0, #1
	rsbs r0, r0, #0
	b _08238530
	.align 2, 0
_08238508: .4byte 0x03000820
_0823850C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082381c8
	cmp r0, #0
	beq _0823851C
	movs r0, #1
	b _08238530
_0823851C:
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	bl FUN_082381c8
	cmp r0, #0
	bne _0823852E
	movs r0, #0
	b _08238530
_0823852E:
	movs r0, #2
_08238530:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
