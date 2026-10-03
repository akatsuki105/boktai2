	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _080441CE
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_080441CE:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
