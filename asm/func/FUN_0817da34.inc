	push {r4, lr}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r3, [r0]
	ldr r4, _0817DA54 @ =0x000008B6
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817DA74
	cmp r0, #9
	bhi _0817DA58
	movs r0, #0x10
	b _0817DA5E
	.align 2, 0
_0817DA54: .4byte 0x000008B6
_0817DA58:
	cmp r0, #0x1d
	bhi _0817DA6A
	movs r0, #0x20
_0817DA5E:
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r1, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817DA6A:
	ldr r0, _0817DA7C @ =0x000008B6
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0817DA74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817DA7C: .4byte 0x000008B6
