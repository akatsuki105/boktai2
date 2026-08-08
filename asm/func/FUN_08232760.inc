	push {r4, r5, r6, r7, lr}
	ldr r5, _08232798 @ =0x030046A4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	movs r2, #4
	ldrsh r6, [r1, r2]
	adds r4, r0, #0
	adds r4, #0x24
	movs r3, #0
	movs r2, #0
	movs r7, #6
	ldrsh r0, [r1, r7]
	cmp r2, r0
	bge _08232792
	adds r1, r4, #0
_0823277E:
	strh r3, [r1]
	adds r3, r3, r6
	adds r1, #2
	adds r2, #1
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r4, #6
	ldrsh r0, [r0, r4]
	cmp r2, r0
	blt _0823277E
_08232792:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08232798: .4byte 0x030046A4
