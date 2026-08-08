	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FC504 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FC508
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FC50A
	.align 2, 0
_080FC504: .4byte 0x0000046D
_080FC508:
	movs r0, #0
_080FC50A:
	cmp r0, #0
	beq _080FC516
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ef86c
_080FC516:
	ldr r0, [r4, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #8]
	cmp r0, #7
	bne _080FC540
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080FC540
	cmp r2, #1
	beq _080FC540
	movs r1, #0
	movs r0, #2
	strh r0, [r3, #8]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
_080FC540:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
