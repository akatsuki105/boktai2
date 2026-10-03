	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BA9B0 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA9DC
	ldr r2, _080BA9B4 @ =0x0000140E
	adds r5, r4, r2
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA9C4
	ldr r3, _080BA9B8 @ =0x0000140B
	adds r1, r4, r3
	ldrb r0, [r1]
	ldrb r5, [r5]
	cmp r0, r5
	bne _080BA9BC
	movs r0, #0x22
	strb r0, [r1]
	movs r0, #5
	b _080BAA3A
	.align 2, 0
_080BA9B0: .4byte 0x0000140C
_080BA9B4: .4byte 0x0000140E
_080BA9B8: .4byte 0x0000140B
_080BA9BC:
	cmp r0, #0x22
	bne _080BA9D2
	movs r0, #5
	b _080BAA3A
_080BA9C4:
	ldr r1, _080BA9D8 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BAA38
_080BA9D2:
	movs r0, #1
	b _080BAA3A
	.align 2, 0
_080BA9D8: .4byte 0x0000140B
_080BA9DC:
	ldr r3, _080BAA0C @ =0x0000140B
	adds r2, r4, r3
	ldr r0, _080BAA10 @ =0x0000140E
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BAA1C
	ldr r1, _080BAA14 @ =0x000012F2
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #2
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BAA18 @ =0x0000140A
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA0C: .4byte 0x0000140B
_080BAA10: .4byte 0x0000140E
_080BAA14: .4byte 0x000012F2
_080BAA18: .4byte 0x0000140A
_080BAA1C:
	ldr r3, _080BAA34 @ =0x00001409
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BAA38
	ldrb r0, [r2]
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA38
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA34: .4byte 0x00001409
_080BAA38:
	movs r0, #0
_080BAA3A:
	pop {r4, r5}
	pop {r1}
	bx r1
