	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A741A:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A741A
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	bl FUN_0822a3f0
	ldr r0, _080A7444 @ =0x00000342
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A7444: .4byte 0x00000342
