	push {lr}
	ldr r3, _0823E48C @ =gClock
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #1
	adds r2, r2, r1
	strh r2, [r3, #0x14]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x22
	bhi _0823E490
	movs r0, #0
	b _0823E4C2
	.align 2, 0
_0823E48C: .4byte gClock
_0823E490:
	cmp r2, #0x45
	bhi _0823E498
	movs r0, #1
	b _0823E4C2
_0823E498:
	cmp r2, #0x68
	bhi _0823E4A0
	movs r0, #2
	b _0823E4C2
_0823E4A0:
	cmp r2, #0x95
	bhi _0823E4A8
	movs r0, #3
	b _0823E4C2
_0823E4A8:
	cmp r2, #0x9f
	bhi _0823E4B0
	movs r0, #4
	b _0823E4C2
_0823E4B0:
	cmp r2, #0xd1
	bhi _0823E4B8
	movs r0, #5
	b _0823E4C2
_0823E4B8:
	cmp r2, #0xf4
	bhi _0823E4C0
	movs r0, #6
	b _0823E4C2
_0823E4C0:
	movs r0, #7
_0823E4C2:
	strb r0, [r3, #0x16]
	pop {r0}
	bx r0
