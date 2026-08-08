	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_080ef840
	adds r6, r0, #0
	cmp r6, #0
	beq _080EC750
	ldr r1, _080EC728 @ =0x03002C60
	ldr r5, [r1]
	cmp r5, #0
	beq _080EC750
	ldr r0, [r5, #4]
	cmp r0, r4
	bne _080EC74A
	ldr r0, [r5]
	str r0, [r1]
	str r0, [r6, #0x20]
	adds r0, r5, #0
	bl Free
	b _080EC738
	.align 2, 0
_080EC728: .4byte 0x03002C60
_080EC72C:
	ldr r4, [r1]
	adds r0, r1, #0
	bl Free
	str r4, [r5]
	str r4, [r6, #0x20]
_080EC738:
	ldrh r0, [r6, #0x32]
	subs r0, #1
	strh r0, [r6, #0x32]
	b _080EC750
_080EC740:
	ldr r1, [r5]
	ldr r0, [r1, #4]
	cmp r0, r4
	beq _080EC72C
	adds r5, r1, #0
_080EC74A:
	ldr r0, [r5]
	cmp r0, #0
	bne _080EC740
_080EC750:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
