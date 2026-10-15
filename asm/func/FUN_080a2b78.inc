	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A2B8C
	subs r0, #2
	b _080A2B8E
_080A2B8C:
	movs r0, #0
_080A2B8E:
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r3, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2BCE
	ldr r0, [r3, #0x50]
	ldr r1, _080A2BD4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2BD8 @ =FUN_080a2bdc
	adds r0, r3, #0
	bl FUN_080a2a14
_080A2BCE:
	pop {r0}
	bx r0
	.align 2, 0
_080A2BD4: .4byte 0xFFFFFDFF
_080A2BD8: .4byte FUN_080a2bdc
