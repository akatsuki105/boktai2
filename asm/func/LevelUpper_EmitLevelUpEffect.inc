	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x18]
	movs r2, #0
	strh r2, [r4, #0x28]
	ldr r0, _080A83D8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	ldrh r0, [r4, #0x36]
	adds r0, #0xfa
	strh r0, [r4, #0x36]
	adds r0, r4, #0
	adds r0, #0x64
	strh r2, [r0]
	subs r0, #2
	movs r1, #1
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x80
	movs r6, #7
_080A83BE:
	ldr r1, [r4, #0x7c]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r5, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A83BE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A83D8: .4byte 0x03002BE0
