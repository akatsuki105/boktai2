	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AB85E
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AB864
_080AB85E:
	ldr r0, [r2]
	ldr r1, _080AB884 @ =0xFFFFFBFF
	ands r0, r1
_080AB864:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	bne _080AB888
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r2, #0
	adds r0, #0x6c
	strb r3, [r0]
	b _080AB892
	.align 2, 0
_080AB884: .4byte 0xFFFFFBFF
_080AB888:
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ab780
_080AB892:
	pop {r0}
	bx r0
	.align 2, 0
