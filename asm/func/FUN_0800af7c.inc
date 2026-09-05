	push {r4, lr}
	ldr r0, _0800AF8C @ =0x03000044
	ldr r0, [r0]
	cmp r0, #0
	bne _0800AF90
	movs r0, #0
	b _0800AFB0
	.align 2, 0
_0800AF8C: .4byte 0x03000044
_0800AF90:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x28
	movs r4, #0xa4
	lsls r4, r4, #1
	movs r2, #5
_0800AF9C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800AFA6
	ldrb r0, [r1, #1]
	adds r3, r3, r0
_0800AFA6:
	adds r1, r1, r4
	subs r2, #1
	cmp r2, #0
	bge _0800AF9C
	adds r0, r3, #0
_0800AFB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
