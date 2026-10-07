	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D192
	movs r0, #0
	strb r0, [r4, #1]
	ldr r0, _0800D1C8 @ =0x0000021A
	bl PlaySound_082406e0
_0800D192:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r3, #0x20
	ldrsh r0, [r5, r3]
	adds r1, r1, r0
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	cmp r0, r1
	blt _0800D1C0
	strh r1, [r4, #0x34]
	strb r2, [r4, #3]
	movs r0, #0
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800D1C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D1C8: .4byte 0x0000021A
