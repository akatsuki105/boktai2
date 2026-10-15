	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A3018
	subs r0, #2
	b _080A301A
_080A3018:
	movs r0, #0
_080A301A:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	ldr r0, _080A30AC @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	adds r0, r1, #0
	movs r1, #4
	movs r2, #0
	bl FUN_0807c200
	ldr r0, _080A30B0 @ =0x000001C3
	adds r5, r4, r0
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_080a2778
	cmp r0, #0
	beq _080A3070
	bl FUN_08086ab8
	cmp r0, #0
	beq _080A3070
	movs r0, #1
	strb r0, [r5]
_080A3070:
	ldr r0, [r4, #0x50]
	ldr r1, _080A30B4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A30B8 @ =FUN_080a30bc
	adds r0, r4, #0
	bl FUN_080a2a14
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A30A6
	movs r1, #0
	bl VM_ExecByID
_080A30A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A30AC: .4byte 0x03002BE0
_080A30B0: .4byte 0x000001C3
_080A30B4: .4byte 0xFFFFFDFF
_080A30B8: .4byte FUN_080a30bc
