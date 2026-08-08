	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, #0xc0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082382E0
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	strb r1, [r4, #0xf]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	strb r0, [r4, #8]
	movs r0, #0xf0
	lsls r0, r0, #1
	strh r0, [r4, #0xa]
	movs r0, #4
	strb r0, [r4, #9]
	adds r0, r4, #0
	bl FUN_08238228
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08238178
	movs r0, #0
	b _082382E4
_082382E0:
	movs r0, #1
	rsbs r0, r0, #0
_082382E4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
