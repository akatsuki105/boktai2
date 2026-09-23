	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	cmp r1, #0
	beq _0804991C
	bl FUN_080498d4
_0804991C:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #9
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x1e
	strb r0, [r2]
	ldr r2, _08049968 @ =0x0000017D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0x13
	adds r0, r4, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	strb r1, [r5, #7]
	adds r0, r5, #0
	bl FUN_08049640
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049968: .4byte 0x0000017D
