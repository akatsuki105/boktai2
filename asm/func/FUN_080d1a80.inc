	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080D1A98 @ =0x00000A75
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #3
	beq _080D1AD0
	cmp r1, #3
	ble _080D1A9C
	cmp r1, #4
	beq _080D1AE0
	b _080D1AF8
	.align 2, 0
_080D1A98: .4byte 0x00000A75
_080D1A9C:
	cmp r1, #0
	blt _080D1AF8
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, #0x63
	asrs r2, r0, #1
	ldr r0, _080D1AC8 @ =0x00000A78
	adds r1, r4, r0
	ldr r3, _080D1ACC @ =0x00000A96
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, #0
	bge _080D1AC2
	movs r0, #0
_080D1AC2:
	adds r0, r2, r0
	b _080D1AF8
	.align 2, 0
_080D1AC8: .4byte 0x00000A78
_080D1ACC: .4byte 0x00000A96
_080D1AD0:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #0x63
	asrs r0, r0, #1
	b _080D1AF8
_080D1AE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	ldr r3, _080D1B00 @ =0x00000A78
	adds r2, r4, r3
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrh r2, [r2]
	adds r0, r1, r2
	lsls r0, r0, #1
_080D1AF8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B00: .4byte 0x00000A78
