	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xaa
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r1, _08084CE4 @ =0x0000FFFF
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08084CC2
	movs r0, #0x20
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084CC2:
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	ands r0, r6
	cmp r0, #0
	bne _08084CDE
	movs r0, #1
	strh r0, [r1]
_08084CDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084CE4: .4byte 0x0000FFFF
