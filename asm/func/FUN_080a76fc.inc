	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A774C @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7746
	ldr r5, _080A7750 @ =FUN_0822e110
	ldr r6, _080A7754 @ =FUN_0822adac
	ldr r7, _080A7758 @ =FUN_0822f244
	movs r3, #2
	rsbs r3, r3, #0
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A7722:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A7722
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_0822a448
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
_080A7746:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A774C: .4byte 0x00000346
_080A7750: .4byte FUN_0822e110
_080A7754: .4byte FUN_0822adac
_080A7758: .4byte FUN_0822f244
