	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x14]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_080a802c
	adds r0, r4, #0
	bl FUN_080a8080
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a7f88
	ldr r0, _080A815C @ =0x00000202
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	movs r0, #0xe6
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r1, _080A8160 @ =FUN_080a7d78
	adds r0, r4, #0
	bl FUN_080a7b68
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A815C: .4byte 0x00000202
_080A8160: .4byte FUN_080a7d78
