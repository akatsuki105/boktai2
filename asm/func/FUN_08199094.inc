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
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x14
	ble _08199112
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08199118 @ =FUN_0819911c
	str r0, [r1]
_08199112:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08199118: .4byte FUN_0819911c
