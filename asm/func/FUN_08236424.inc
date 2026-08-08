	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08236458 @ =0x03000780
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _08236464
	ldr r1, [r2, #0x18]
	ldr r2, [r1]
	cmp r2, #0
	beq _08236464
_0823643A:
	cmp r2, r3
	bne _0823645C
	ldr r3, [r4]
	ldr r0, [r3, #0x20]
	cmp r2, r0
	bne _08236448
	str r1, [r3, #0x20]
_08236448:
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, [r4]
	adds r1, #0xc8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08236464
	.align 2, 0
_08236458: .4byte 0x03000780
_0823645C:
	adds r1, r2, #0
	ldr r2, [r2]
	cmp r2, #0
	bne _0823643A
_08236464:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
