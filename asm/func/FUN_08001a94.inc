	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08001AB0 @ =0x00000642
	adds r5, r6, r0
	ldrb r4, [r5]
	adds r0, r6, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001AB4
	ldrb r0, [r5]
	adds r0, #4
	strb r0, [r5]
	b _08001AC4
	.align 2, 0
_08001AB0: .4byte 0x00000642
_08001AB4:
	adds r0, r6, #0
	bl FUN_08001a64
	strb r0, [r5]
	ldr r0, _08001ACC @ =0x00000644
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
_08001AC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001ACC: .4byte 0x00000644
