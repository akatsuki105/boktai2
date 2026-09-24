	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D14DA
	adds r0, r4, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D1494
	adds r0, r4, #0
	movs r1, #1
	b _081D1498
_081D1494:
	adds r0, r4, #0
	movs r1, #2
_081D1498:
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r2, r4, #0
	adds r2, #0x66
	ldrh r0, [r2]
	movs r1, #4
	orrs r1, r0
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r0, r4, #0
	adds r0, #0xc2
	adds r1, r4, #0
	adds r1, #0xc4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D14DA
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
_081D14DA:
	pop {r4}
	pop {r0}
	bx r0
