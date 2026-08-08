	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080EC76C @ =0x03002C60
	ldr r4, [r0]
	cmp r4, #0
	beq _080EC790
	b _080EC78A
	.align 2, 0
_080EC76C: .4byte 0x03002C60
_080EC770:
	ldr r1, [r4, #4]
	cmp r5, #0
	bne _080EC788
	ldr r2, _080EC798 @ =0x0000057C
	adds r0, r1, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _080EC788
	adds r0, r1, #0
	adds r1, r6, #0
	bl _call_via_r2
_080EC788:
	ldr r4, [r4]
_080EC78A:
	ldr r0, [r4]
	cmp r0, #0
	bne _080EC770
_080EC790:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EC798: .4byte 0x0000057C
