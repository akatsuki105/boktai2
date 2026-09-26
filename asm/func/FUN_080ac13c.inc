	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC152
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC158
_080AC152:
	ldr r0, [r2]
	ldr r1, _080AC178 @ =0xFFFFFBFF
	ands r0, r1
_080AC158:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	bne _080AC17C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r2, #0
	adds r0, #0x6c
	strb r3, [r0]
	b _080AC186
	.align 2, 0
_080AC178: .4byte 0xFFFFFBFF
_080AC17C:
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC186:
	pop {r0}
	bx r0
	.align 2, 0
