	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC116
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC11C
_080AC116:
	ldr r0, [r2]
	ldr r1, _080AC138 @ =0xFFFFFBFF
	ands r0, r1
_080AC11C:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080AC132
	adds r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC132:
	pop {r0}
	bx r0
	.align 2, 0
_080AC138: .4byte 0xFFFFFBFF
