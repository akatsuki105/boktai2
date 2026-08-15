	push {lr}
	adds r3, r1, #0
	cmp r0, #1
	beq _0822BA24
	cmp r0, #1
	bgt _0822BA12
	cmp r0, #0
	beq _0822BA1C
	b _0822BA44
_0822BA12:
	cmp r0, #2
	beq _0822BA2C
	cmp r0, #3
	beq _0822BA34
	b _0822BA44
_0822BA1C:
	ldr r2, _0822BA20 @ =0x04000008
	b _0822BA36
	.align 2, 0
_0822BA20: .4byte 0x04000008
_0822BA24:
	ldr r2, _0822BA28 @ =0x0400000A
	b _0822BA36
	.align 2, 0
_0822BA28: .4byte 0x0400000A
_0822BA2C:
	ldr r2, _0822BA30 @ =0x0400000C
	b _0822BA36
	.align 2, 0
_0822BA30: .4byte 0x0400000C
_0822BA34:
	ldr r2, _0822BA48 @ =0x0400000E
_0822BA36:
	ldrh r1, [r2]
	ldr r0, _0822BA4C @ =0x0000FFFC
	ands r0, r1
	orrs r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r2]
_0822BA44:
	pop {r0}
	bx r0
	.align 2, 0
_0822BA48: .4byte 0x0400000E
_0822BA4C: .4byte 0x0000FFFC
