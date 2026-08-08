	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08231284
	ldrb r0, [r2]
	str r0, [r3]
	adds r0, r2, #1
	b _08231294
_08231284:
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	ldr r1, _08231298 @ =0x00007FFF
	ands r0, r1
	str r0, [r3]
	adds r0, r2, #2
_08231294:
	pop {r1}
	bx r1
	.align 2, 0
_08231298: .4byte 0x00007FFF
