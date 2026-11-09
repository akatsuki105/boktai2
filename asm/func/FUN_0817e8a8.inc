	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _0817E8D8 @ =0x000008AF
	adds r2, r0, r3
	subs r3, #3
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0817E8D2
	movs r0, #0
	strb r0, [r2]
_0817E8D2:
	pop {r0}
	bx r0
	.align 2, 0
_0817E8D8: .4byte 0x000008AF
