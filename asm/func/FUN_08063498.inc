	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	ldr r1, _080634F8 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063516
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080634E0
	adds r0, r4, #0
	bl FUN_08063478
	ldr r2, _080634FC @ =0x085ABAB4
	ldr r3, _08063500 @ =0x000004C5
	adds r1, r4, r3
	ldrb r1, [r1]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	blt _080634E0
	adds r0, r4, #0
	bl FUN_080630e8
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _08063504 @ =0x00000401
	adds r0, r4, r2
	strb r1, [r0]
_080634E0:
	ldr r3, _080634F8 @ =0x000004C7
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063516
	ldr r1, _08063500 @ =0x000004C5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063508
	movs r5, #3
	b _08063516
	.align 2, 0
_080634F8: .4byte 0x000004C7
_080634FC: .4byte 0x085ABAB4
_08063500: .4byte 0x000004C5
_08063504: .4byte 0x00000401
_08063508:
	cmp r0, #2
	bne _08063510
	movs r5, #4
	b _08063516
_08063510:
	cmp r0, #3
	bne _08063516
	movs r5, #5
_08063516:
	ldr r2, _08063548 @ =0x00000402
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063522
	movs r5, #7
_08063522:
	cmp r5, r6
	bne _08063554
	ldr r0, _0806354C @ =0x00000954
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _08063562
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063542
	ldr r1, _08063550 @ =0x00000952
	adds r0, r4, r1
	ldrh r5, [r0]
_08063542:
	subs r0, r2, #1
	strh r0, [r3]
	b _08063562
	.align 2, 0
_08063548: .4byte 0x00000402
_0806354C: .4byte 0x00000954
_08063550: .4byte 0x00000952
_08063554:
	ldr r2, _0806356C @ =0x00000952
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _08063570 @ =0x00000954
	adds r1, r4, r3
	movs r0, #0x40
	strh r0, [r1]
_08063562:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806356C: .4byte 0x00000952
_08063570: .4byte 0x00000954
