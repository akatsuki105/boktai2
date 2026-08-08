	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x20]
	ldr r2, [r0, #0x24]
	movs r1, #0
	strb r1, [r0, #4]
	cmp r3, #0
	beq _0822A3D8
	str r2, [r3, #0x24]
	b _0822A3E0
_0822A3D8:
	ldr r1, _0822A3EC @ =0x03003570
	lsls r0, r4, #2
	adds r0, r0, r1
	str r2, [r0]
_0822A3E0:
	cmp r2, #0
	beq _0822A3E6
	str r3, [r2, #0x20]
_0822A3E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A3EC: .4byte 0x03003570
