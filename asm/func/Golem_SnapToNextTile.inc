	push {lr}
	adds r2, r0, #0
	cmp r1, #1
	beq _08115572
	cmp r1, #1
	bgt _08115562
	cmp r1, #0
	beq _0811556C
	b _08115598
_08115562:
	cmp r1, #2
	beq _08115578
	cmp r1, #3
	beq _0811558C
	b _08115598
_0811556C:
	ldrh r0, [r2]
	adds r0, #0xff
	b _0811557C
_08115572:
	ldrh r0, [r2, #4]
	adds r0, #0xff
	b _08115590
_08115578:
	ldrh r0, [r2]
	subs r0, #0xff
_0811557C:
	ldr r1, _08115588 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2]
	b _08115598
	.align 2, 0
_08115588: .4byte 0xFFFFFF00
_0811558C:
	ldrh r0, [r2, #4]
	subs r0, #0xff
_08115590:
	ldr r1, _0811559C @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #4]
_08115598:
	pop {r0}
	bx r0
	.align 2, 0
_0811559C: .4byte 0xFFFFFF00
