	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x60]
	subs r1, #3
	ands r0, r1
	str r0, [r2, #0x60]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080A216C
	ldr r0, [r2, #0x60]
	subs r1, #1
	ands r0, r1
	str r0, [r2, #0x60]
	adds r0, r2, #0
	adds r0, #0x68
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A2164 @ =FUN_080a20a0
	str r0, [r1]
	ldr r0, _080A2168 @ =0x0000032F
	bl PlaySound_082406e0
	b _080A218C
	.align 2, 0
_080A2164: .4byte FUN_080a20a0
_080A2168: .4byte 0x0000032F
_080A216C:
	ldr r0, [r2, #0x60]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x60]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	strb r1, [r0]
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x69
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	subs r1, #3
	strb r0, [r1]
_080A218C:
	pop {r0}
	bx r0
