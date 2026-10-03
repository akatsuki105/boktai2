	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0, #8]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804352E
	rsbs r1, r1, #0
_0804352E:
	cmp r1, #0x28
	bgt _08043552
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x68
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r0, r0, r1
	cmp r0, #0
	bge _08043544
	rsbs r0, r0, #0
_08043544:
	cmp r0, #0x28
	bgt _08043552
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_080434ac
	b _08043554
_08043552:
	movs r0, #9
_08043554:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
