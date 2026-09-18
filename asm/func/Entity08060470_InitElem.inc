	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r4, #8
	movs r2, #0
	strb r2, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	strh r2, [r1, #2]
	strh r2, [r1, #4]
	ldr r1, [r5, #0x20]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r1, [r5, #0x20]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_0822dafc
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
