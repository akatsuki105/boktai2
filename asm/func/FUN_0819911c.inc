	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bne _081991A0
	ldr r0, _081991A8 @ =0x00000183
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #0x38
	adds r1, r5, r2
	ldr r0, _081991AC @ =FUN_081991b0
	str r0, [r1]
_081991A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081991A8: .4byte 0x00000183
_081991AC: .4byte FUN_081991b0
