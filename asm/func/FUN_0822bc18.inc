	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, [r0, #0xc]
	movs r3, #0
	ldrh r0, [r0]
	cmp r3, r0
	bge _0822BC3C
	adds r1, r0, #0
_0822BC2A:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0822BC34
	adds r0, r2, #0
	b _0822BC3E
_0822BC34:
	adds r2, #8
	adds r3, #1
	cmp r3, r1
	blt _0822BC2A
_0822BC3C:
	movs r0, #0
_0822BC3E:
	pop {r4}
	pop {r1}
	bx r1
