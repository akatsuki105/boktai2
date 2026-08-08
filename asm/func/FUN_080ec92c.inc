	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x2a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080EC95E
	ldr r3, [r4, #0x20]
	cmp r3, #0
	beq _080EC958
	ldr r1, [r3, #4]
	cmp r1, #0
	beq _080EC958
	movs r2, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r3]
	b _080EC95C
_080EC958:
	ldr r0, _080EC964 @ =0x03002C60
	ldr r0, [r0]
_080EC95C:
	str r0, [r4, #0x20]
_080EC95E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080EC964: .4byte 0x03002C60
