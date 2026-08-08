	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0x80
	lsls r3, r3, #0x12
	adds r2, #0xf
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r2, r0
	adds r2, #0x10
	movs r4, #0x80
	lsls r4, r4, #0x18
_082308D2:
	ldr r1, [r3, #8]
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	beq _0823091C
	ldr r0, _08230904 @ =0x000FFFFF
	ands r0, r1
	cmp r0, r2
	blt _0823091C
	subs r0, r0, r2
	cmp r0, #0x10
	bls _08230908
	adds r1, r3, r2
	orrs r0, r4
	str r0, [r1, #8]
	str r3, [r1]
	ldr r0, [r3, #4]
	str r0, [r1, #4]
	cmp r0, #0
	beq _082308FC
	str r1, [r0]
_082308FC:
	str r2, [r3, #8]
	str r1, [r3, #4]
	b _0823090E
	.align 2, 0
_08230904: .4byte 0x000FFFFF
_08230908:
	ldr r0, _08230918 @ =0x7FFFFFFF
	ands r1, r0
	str r1, [r3, #8]
_0823090E:
	movs r0, #0
	str r0, [r3, #0xc]
	adds r0, r3, #0
	adds r0, #0x10
	b _08230924
	.align 2, 0
_08230918: .4byte 0x7FFFFFFF
_0823091C:
	ldr r3, [r3, #4]
	cmp r3, #0
	bne _082308D2
	movs r0, #0
_08230924:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
