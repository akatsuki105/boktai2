	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081756D6
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _081756B8 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081756BC
	movs r0, #1
	b _081756BE
	.align 2, 0
_081756B8: .4byte 0x00001008
_081756BC:
	movs r0, #0
_081756BE:
	cmp r0, #0
	bne _081756D6
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081756DC @ =0x00000FAA
	adds r1, r1, r2
	ldrh r0, [r5]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_081756D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081756DC: .4byte 0x00000FAA
