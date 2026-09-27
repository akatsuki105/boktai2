	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xf4
	adds r1, r5, #0
	adds r1, #0xe8
	adds r2, r5, #0
	adds r2, #0x58
	adds r4, r5, #0
	adds r4, #0xba
	movs r6, #0
	ldrsh r3, [r4, r6]
	str r3, [sp]
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl FUN_081d2698
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2A54
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081d5588
	b _081D2A5A
_081D2A54:
	adds r0, r5, #0
	bl FUN_081d2368
_081D2A5A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
