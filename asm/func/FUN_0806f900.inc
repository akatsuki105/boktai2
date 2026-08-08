	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_0806f7bc
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _0806F95C @ =0x00000A9C
	adds r4, r5, r0
_0806F910:
	ldr r1, [r4]
	cmp r1, #0
	beq _0806F91E
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r6, r0
_0806F91E:
	adds r4, #4
	adds r7, #1
	cmp r7, #2
	ble _0806F910
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F952
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r2, #0x12
	adds r1, r5, r2
	ldrh r1, [r1]
	bl Div
	adds r6, r6, r0
_0806F952:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806F95C: .4byte 0x00000A9C
