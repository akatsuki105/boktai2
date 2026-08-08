	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r1, #0
	strb r1, [r2, #2]
	strb r1, [r2, #3]
	strb r1, [r2, #1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r3, r2, r1
	ldr r1, _082467CC @ =FUN_0824666c
	str r1, [r3]
	movs r4, #0
	movs r6, #0xa
	movs r5, #1
	adds r2, #0xc
	movs r3, #3
_082467B0:
	strb r4, [r2]
	strh r4, [r2, #2]
	strb r6, [r2, #1]
	ldr r1, [r2, #0x10]
	orrs r1, r5
	str r1, [r2, #0x10]
	adds r2, #0x48
	subs r3, #1
	cmp r3, #0
	bge _082467B0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082467CC: .4byte FUN_0824666c
