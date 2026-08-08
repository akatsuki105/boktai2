	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08063260 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063264
	subs r1, #1
	adds r0, r5, r1
	bl FUN_08246790
	b _0806327C
	.align 2, 0
_08063260: .4byte 0x000004C5
_08063264:
	ldr r1, _08063284 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806327C
	adds r4, r0, #0
_08063270:
	adds r0, r5, #0
	bl FUN_080630e8
	subs r4, #1
	cmp r4, #0
	bne _08063270
_0806327C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063284: .4byte 0x000004C7
