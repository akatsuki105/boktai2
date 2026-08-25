	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r3, _080A81F8 @ =0x030046A0
	ldr r1, [r3]
	adds r2, r1, #0
	adds r2, #0x40
	ldrh r5, [r2]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r0, #0x62
	bgt _080A81F2
	ldr r1, [r1, #0x50]
	ldr r0, [r4, #0x74]
	cmp r1, r0
	bhs _080A81FC
_080A81F2:
	movs r0, #0
	b _080A821C
	.align 2, 0
_080A81F8: .4byte 0x030046A0
_080A81FC:
	adds r0, r5, #1
	strh r0, [r2]
	ldr r1, [r3]
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r0, [r3]
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl GetNextLvExp
	str r0, [r4, #0x74]
	movs r0, #1
_080A821C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
