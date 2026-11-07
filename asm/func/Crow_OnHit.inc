	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _081428BE
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081428BE
	ldrh r1, [r4, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081428BE
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r4, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081428C4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081428BE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081428C4: .4byte 0xFEFFFFFF
