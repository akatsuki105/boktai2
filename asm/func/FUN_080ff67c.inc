	push {r4, r5, r6, lr}
	ldr r4, _080FF6D4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r3, _080FF6D8 @ =0x0000046D
	adds r1, r0, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r1]
	ldr r6, _080FF6DC @ =0x0000046B
	adds r1, r0, r6
	strb r3, [r1]
	adds r6, #0xe8
	adds r1, r0, r6
	strb r2, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r4, [r1]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r1, r0, r6
	movs r4, #0
	strh r3, [r1]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r1, r0, r6
	strb r4, [r1]
	adds r6, #1
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _080FF6E0 @ =0x0000046A
	adds r1, r0, r2
	strb r4, [r1]
	adds r6, #0x1b
	adds r1, r0, r6
	str r3, [r1]
	ldr r1, _080FF6E4 @ =0x0000046C
	adds r0, r0, r1
	strb r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080FF6D4: .4byte FUN_080e48d0
_080FF6D8: .4byte 0x0000046D
_080FF6DC: .4byte 0x0000046B
_080FF6E0: .4byte 0x0000046A
_080FF6E4: .4byte 0x0000046C
