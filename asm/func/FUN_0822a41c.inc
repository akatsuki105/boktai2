	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x58]
	ldr r2, [r0, #0x5c]
	movs r1, #0
	strb r1, [r0, #4]
	cmp r3, #0
	beq _0822A430
	str r2, [r3, #0x5c]
	b _0822A438
_0822A430:
	ldr r1, _0822A444 @ =0x03003568
	lsls r0, r4, #2
	adds r0, r0, r1
	str r2, [r0]
_0822A438:
	cmp r2, #0
	beq _0822A43E
	str r3, [r2, #0x58]
_0822A43E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A444: .4byte 0x03003568
