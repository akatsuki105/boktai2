	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r1, _081D233C @ =0x000012AC
	adds r3, r0, r1
	movs r7, #1
	adds r4, r0, #0
	adds r4, #0xcc
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0xc6
	lsls r6, r6, #1
_081D232A:
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D2340
	movs r0, #1
	b _081D2342
	.align 2, 0
_081D233C: .4byte 0x000012AC
_081D2340:
	movs r0, #0
_081D2342:
	cmp r0, #0
	bne _081D2356
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D2362
_081D2356:
	adds r4, r4, r6
	adds r5, r5, r6
	adds r2, #1
	cmp r2, #0xb
	ble _081D232A
	movs r0, #0
_081D2362:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
