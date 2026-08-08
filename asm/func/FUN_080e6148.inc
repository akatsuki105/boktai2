	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, [r5, #0x24]
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	movs r3, #8
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	ldrh r1, [r2, #2]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl FUN_080e5d80
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r2, #8
	ldrsh r0, [r5, r2]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl FUN_080e5d80
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bgt _080E61B2
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r6]
	strh r1, [r6, #2]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
_080E61B2:
	adds r4, r5, #0
	adds r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080E61CC
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _080E61F0
_080E61CC:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080E61EA
	cmp r0, #2
	beq _080E61F8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080E61F8
_080E61EA:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_080E61F0:
	ldr r1, _080E6200 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080E61F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E6200: .4byte 0xFFFFFDFF
