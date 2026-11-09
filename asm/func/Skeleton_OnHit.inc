	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r4, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108998
	movs r2, #0x10
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0810893A
	movs r0, #1
	b _0810893C
_0810893A:
	movs r0, #0
_0810893C:
	cmp r0, #0
	beq _0810896A
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08108950
	movs r0, #1
	b _08108952
_08108950:
	movs r0, #0
_08108952:
	cmp r0, #0
	beq _08108998
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08108998
_0810896A:
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108998
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08108998
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _081089A0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08108998:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081089A0: .4byte 0xFEFFFFFF
