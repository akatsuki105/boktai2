	push {r4, lr}
	adds r4, r0, #0
	movs r2, #9
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
_08078508:
	ldrh r0, [r1]
	strh r0, [r1, #2]
	subs r1, #2
	subs r2, #1
	cmp r2, #0
	bgt _08078508
	adds r0, r4, #0
	bl FUN_0807849c
	adds r1, r0, #0
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _0807853E
	ldr r3, _08078544 @ =0x00000456
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	adds r0, #7
	movs r1, #7
	ands r0, r1
	strh r0, [r2]
_0807853E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078544: .4byte 0x00000456
