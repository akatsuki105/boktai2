	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08012DBC @ =0x0000FFFF
	movs r5, #0
	adds r1, r7, #0
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #4
	cmp r5, r0
	bge _08012D90
	adds r4, r1, #0
_08012D7E:
	adds r0, r7, #0
	bl FUN_08012cec
	eors r6, r0
	adds r5, #1
	ldrb r0, [r4]
	adds r0, #4
	cmp r5, r0
	blt _08012D7E
_08012D90:
	adds r4, r7, #0
	adds r4, #0x2e
	movs r5, #0x13
_08012D96:
	ldrb r1, [r4]
	adds r0, r6, #0
	eors r0, r1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4]
	adds r0, r7, #0
	bl FUN_08012cec
	eors r6, r0
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08012D96
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012DBC: .4byte 0x0000FFFF
