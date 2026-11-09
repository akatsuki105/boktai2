	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0818F1BC @ =0x00000F36
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _0818F1DE
	movs r5, #1
	adds r6, r1, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r7, _0818F1C0 @ =0x0000077A
	adds r1, r0, r7
	adds r1, r1, r2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r2, r0, r2
	movs r4, #0x92
	lsls r4, r4, #1
_0818F1AE:
	ldrh r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _0818F1C4
	movs r0, #1
	b _0818F1C6
	.align 2, 0
_0818F1BC: .4byte 0x00000F36
_0818F1C0: .4byte 0x0000077A
_0818F1C4:
	movs r0, #0
_0818F1C6:
	cmp r0, #0
	bne _0818F1D0
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
_0818F1D0:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0818F1AE
_0818F1DE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
