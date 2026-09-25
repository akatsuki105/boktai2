	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #4
	bls _0820EFE6
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #4
	bls _0820EFE2
	movs r0, #8
	subs r0, r0, r3
	strb r0, [r1]
	b _0820F008
_0820EFE2:
	strb r3, [r1]
	b _0820F00E
_0820EFE6:
	cmp r0, #0
	beq _0820F014
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0xff
	lsls r4, r4, #0x18
	adds r0, r0, r4
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0820F000
	movs r0, #1
	b _0820F002
_0820F000:
	movs r0, #0
_0820F002:
	strb r0, [r1]
	cmp r3, #1
	bls _0820F00E
_0820F008:
	movs r0, #1
	strb r0, [r2]
	b _0820F018
_0820F00E:
	movs r0, #0
	strb r0, [r2]
	b _0820F018
_0820F014:
	strb r3, [r1]
	strb r3, [r2]
_0820F018:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
