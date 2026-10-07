	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809B318 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r5, #0
	bl FUN_0808b4c0
	ldr r0, _0809B31C @ =0x00004003
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0809B2E2
	adds r1, r0, #0
	adds r0, r5, #0
	bl EntityCC28_ShowLineInstant
	movs r0, #0xff
	strb r0, [r4]
_0809B2E2:
	ldr r0, _0809B320 @ =0x000010A4
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, #0xf
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0809B32C
	ldr r1, _0809B324 @ =FUN_0809ac30
	movs r4, #1
	ldr r0, _0809B328 @ =0x0000108C
	adds r2, r5, r0
	movs r3, #9
_0809B302:
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B302
	adds r0, r5, #0
	bl FUN_0808a33c
	b _0809B33E
	.align 2, 0
_0809B318: .4byte 0x00001084
_0809B31C: .4byte 0x00004003
_0809B320: .4byte 0x000010A4
_0809B324: .4byte FUN_0809ac30
_0809B328: .4byte 0x0000108C
_0809B32C:
	ldr r0, _0809B344 @ =0x00001104
	adds r1, r5, r0
	movs r3, #8
_0809B332:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B332
_0809B33E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809B344: .4byte 0x00001104
