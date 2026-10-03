	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r5, #0
	cmp r5, r6
	bge _0804E6CE
_0804E6AA:
	adds r0, r7, r5
	ldrb r0, [r0]
	bl FUN_0804e65c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x7f
	bhi _0804E6C0
	strb r1, [r4]
	adds r4, #1
	b _0804E6C8
_0804E6C0:
	strb r1, [r4]
	lsrs r0, r0, #0x18
	strb r0, [r4, #1]
	adds r4, #2
_0804E6C8:
	adds r5, #1
	cmp r5, r6
	blt _0804E6AA
_0804E6CE:
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
