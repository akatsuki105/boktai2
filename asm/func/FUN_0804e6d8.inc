	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r5, #0
	b _0804E706
_0804E6E4:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804E6F0
	ldrb r1, [r4]
	adds r4, #1
	b _0804E6FA
_0804E6F0:
	ldrb r1, [r4]
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	adds r4, #2
_0804E6FA:
	adds r0, r1, #0
	bl FUN_0804e674
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
_0804E706:
	cmp r5, r6
	bge _0804E720
	ldrb r0, [r4]
	cmp r0, #0
	bne _0804E6E4
	cmp r5, r6
	bge _0804E720
	movs r1, #0
_0804E716:
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, r6
	blt _0804E716
_0804E720:
	adds r1, r7, r6
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
