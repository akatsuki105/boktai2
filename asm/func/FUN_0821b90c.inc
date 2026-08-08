	push {lr}
	ldr r0, _0821B938 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r2, #0
	ldr r0, _0821B93C @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0821B940
	cmp r2, #0
	beq _0821B940
	ldr r1, [r2, #0x1c]
	cmp r1, #1
	bne _0821B940
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0821B940
	movs r0, #1
	b _0821B942
	.align 2, 0
_0821B938: .4byte 0x03002BE0
_0821B93C: .4byte 0x030044E0
_0821B940:
	movs r0, #0
_0821B942:
	pop {r1}
	bx r1
	.align 2, 0
