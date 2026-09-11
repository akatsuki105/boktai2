	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r2]
	ldr r5, [r2, #4]
	str r4, [r6, #0x64]
	str r5, [r6, #0x68]
	str r1, [r6, #0x18]
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r6, r0
	strh r3, [r4]
	adds r0, r6, #0
	bl FUN_080a8d78
	adds r0, r6, #0
	bl FUN_080a8dd8
	ldr r1, [r6, #0x18]
	ldr r2, _080A8F90 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	beq _080A8F94
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x78
	b _080A8FB8
	.align 2, 0
_080A8F90: .4byte 0x000003FB
_080A8F94:
	ldr r0, _080A8FAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8FB0
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x5a
	b _080A8FB8
	.align 2, 0
_080A8FAC: .4byte 0x030047A4
_080A8FB0:
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xb4
_080A8FB8:
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Div
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x15
	bl PlaySound_082406e0
	ldr r1, _080A8FF4 @ =FUN_080a881c
	adds r0, r6, #0
	bl FUN_080a8804
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8FF4: .4byte FUN_080a881c
