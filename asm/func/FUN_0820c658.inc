	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _0820C68C
	ldr r1, _0820C688 @ =0x085AEFB4
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820C68E
	.align 2, 0
_0820C688: .4byte 0x085AEFB4
_0820C68C:
	movs r0, #0
_0820C68E:
	pop {r4}
	pop {r1}
	bx r1
