	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0x28
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	adds r2, #0x19
	movs r3, #0
	bl FUN_0822f3cc
	ldrb r0, [r4]
	bl FUN_0820ff78
	cmp r0, #0
	beq _08210756
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #1
_08210746:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08210746
	b _0821076E
_08210756:
	movs r3, #1
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #1
_08210760:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08210760
_0821076E:
	pop {r4, r5}
	pop {r0}
	bx r0
