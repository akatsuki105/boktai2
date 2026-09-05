	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080A7A50 @ =0x00000342
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A7A44
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A7A2C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A7A2C
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_0822f1c0
_080A7A44:
	ldr r1, _080A7A54 @ =0x03000150
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A7A50: .4byte 0x00000342
_080A7A54: .4byte 0x03000150
