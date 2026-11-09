	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _0818F7E4 @ =0x00000F36
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _0818F802
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _0818F7E8 @ =0x0000077A
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_0818F7D8:
	ldrh r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _0818F7EC
	movs r0, #1
	b _0818F7EE
	.align 2, 0
_0818F7E4: .4byte 0x00000F36
_0818F7E8: .4byte 0x0000077A
_0818F7EC:
	movs r0, #0
_0818F7EE:
	cmp r0, #0
	beq _0818F7F4
	str r5, [r1]
_0818F7F4:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0818F7D8
_0818F802:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
