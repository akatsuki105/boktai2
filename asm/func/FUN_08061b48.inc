	push {r4, lr}
	ldr r1, _08061B8C @ =0x000006AC
	adds r4, r0, r1
	ldr r1, [r4]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r4]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r3, _08061B90 @ =0x000006CA
	adds r2, r0, r3
	ldrh r1, [r2]
	adds r1, #0xe6
	strh r1, [r2]
	ldr r2, _08061B94 @ =0x00000A8A
	adds r1, r0, r2
	ldrh r2, [r1]
	subs r3, #0x18
	adds r1, r0, r3
	strb r2, [r1]
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061B8C: .4byte 0x000006AC
_08061B90: .4byte 0x000006CA
_08061B94: .4byte 0x00000A8A
