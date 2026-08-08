	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #4
	strb r1, [r6]
	movs r1, #0x28
	strb r1, [r6, #1]
	strb r4, [r6, #4]
	strh r2, [r6, #6]
	str r5, [r6, #8]
	movs r1, #1
	strb r1, [r6, #0x11]
	movs r1, #0xf0
	strh r1, [r6, #0x12]
	adds r1, #0xf0
	strh r1, [r6, #0x14]
	cmp r7, #0
	beq _0823A760
	strh r3, [r6, #2]
	b _0823A762
_0823A760:
	strh r7, [r6, #2]
_0823A762:
	ldr r1, [sp, #0x1c]
	str r1, [r6, #0xc]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
