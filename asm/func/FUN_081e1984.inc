	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E19CC @ =0x030001B0
	ldr r0, [r0]
	cmp r0, #0
	beq _081E19D4
	bl Entity150F_FindSlot
	adds r3, r0, #0
	cmp r3, #0
	beq _081E19D4
	movs r0, #0xff
	strb r0, [r3]
	movs r2, #0
	strb r2, [r3, #1]
	strb r2, [r3, #2]
	strb r2, [r3, #3]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x40]
	str r1, [r3, #0x44]
	adds r1, r3, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	ldr r0, _081E19D0 @ =FUN_081e1438
	str r0, [r3, #0x20]
	strh r2, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
	movs r0, #0
	b _081E19D8
	.align 2, 0
_081E19CC: .4byte 0x030001B0
_081E19D0: .4byte FUN_081e1438
_081E19D4:
	movs r0, #1
	rsbs r0, r0, #0
_081E19D8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
