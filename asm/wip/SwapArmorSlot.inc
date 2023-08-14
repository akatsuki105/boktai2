	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _082432B8 @ =0x030046A0
	ldr r3, [r0]
	lsls r2, r6, #1
	adds r2, r2, r3
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r2, r1
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r0, r5, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, r6
	bne _082432BC
	strh r5, [r3]
	b _082432C2
	.align 2, 0
_082432B8: .4byte 0x030046A0
_082432BC:
	cmp r0, r5
	bne _082432C2
	strh r6, [r3]
_082432C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
