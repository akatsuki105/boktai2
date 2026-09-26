	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AB806
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AB80C
_080AB806:
	ldr r0, [r4]
	ldr r1, _080AB844 @ =0xFFFFFBFF
	ands r0, r1
_080AB80C:
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080AB822
	adds r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080ab780
_080AB822:
	adds r1, r4, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080AB83C
	ldr r0, [r4, #0x74]
	subs r1, #0x56
	bl FUN_080ab134
_080AB83C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB844: .4byte 0xFFFFFBFF
