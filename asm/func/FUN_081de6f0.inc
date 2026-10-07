	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE724
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DE724:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE73A
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE7E2
_081DE73A:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE750
	movs r0, #1
	b _081DE752
_081DE750:
	movs r0, #0
_081DE752:
	cmp r0, #0
	beq _081DE770
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DE76C @ =FUN_081de7e8
	adds r0, r5, #0
	movs r1, #6
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DE7E2
	.align 2, 0
_081DE76C: .4byte FUN_081de7e8
_081DE770:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DE7B8
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DE78E:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DE7AE
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DE7AE:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DE78E
_081DE7B8:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DE7CE
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	bne _081DE7CE
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x42
	strh r1, [r2]
_081DE7CE:
	ldr r2, [r5, #0x34]
	movs r1, #0xe1
	lsls r1, r1, #4
	cmp r2, r1
	bls _081DE7E2
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DE7E2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
