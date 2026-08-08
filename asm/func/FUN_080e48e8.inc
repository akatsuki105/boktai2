	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r7, #0
	movs r5, #0
	strh r5, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, _080E4954 @ =FUN_080e48d0
	str r0, [r2]
	ldr r0, _080E4958 @ =0x0000046D
	adds r2, r4, r0
	movs r0, #1
	strb r0, [r2]
	ldr r2, _080E495C @ =0x0000046B
	adds r0, r4, r2
	strb r7, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	cmp r3, #0
	bgt _080E4928
	adds r3, r6, #0
_080E4928:
	movs r2, #0xc7
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #0x8e
	adds r0, r4, r2
	strb r7, [r0]
	ldr r1, _080E4960 @ =0x00000454
	adds r0, r4, r1
	str r5, [r0]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E4954: .4byte FUN_080e48d0
_080E4958: .4byte 0x0000046D
_080E495C: .4byte 0x0000046B
_080E4960: .4byte 0x00000454
