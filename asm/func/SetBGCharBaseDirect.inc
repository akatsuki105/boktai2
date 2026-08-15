	push {lr}
	adds r3, r1, #0
	cmp r0, #1
	beq _0822BA74
	cmp r0, #1
	bgt _0822BA62
	cmp r0, #0
	beq _0822BA6C
	b _0822BA96
_0822BA62:
	cmp r0, #2
	beq _0822BA7C
	cmp r0, #3
	beq _0822BA84
	b _0822BA96
_0822BA6C:
	ldr r2, _0822BA70 @ =0x04000008
	b _0822BA86
	.align 2, 0
_0822BA70: .4byte 0x04000008
_0822BA74:
	ldr r2, _0822BA78 @ =0x0400000A
	b _0822BA86
	.align 2, 0
_0822BA78: .4byte 0x0400000A
_0822BA7C:
	ldr r2, _0822BA80 @ =0x0400000C
	b _0822BA86
	.align 2, 0
_0822BA80: .4byte 0x0400000C
_0822BA84:
	ldr r2, _0822BA9C @ =0x0400000E
_0822BA86:
	ldrh r1, [r2]
	ldr r0, _0822BAA0 @ =0x0000FFF3
	ands r0, r1
	lsls r1, r3, #2
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r2]
_0822BA96:
	pop {r0}
	bx r0
	.align 2, 0
_0822BA9C: .4byte 0x0400000E
_0822BAA0: .4byte 0x0000FFF3
