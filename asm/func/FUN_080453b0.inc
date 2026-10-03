	push {r4, r5, lr}
	adds r2, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0, #8]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080453CE
	rsbs r1, r1, #0
_080453CE:
	ldr r4, [r2, #0x38]
	cmp r1, r4
	bhi _080453F4
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x6c
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _080453E6
	rsbs r0, r0, #0
_080453E6:
	cmp r0, r4
	bhi _080453F4
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08045330
	b _08045400
_080453F4:
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_08045400:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
