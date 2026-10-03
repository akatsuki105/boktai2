	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BE094 @ =0x0000168E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BE074
	ldr r0, _080BE098 @ =0x00000276
	bl PlaySound_082406e0
_080BE074:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BE0B8
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE0A0
	ldr r2, _080BE09C @ =0x00000C3A
	adds r1, r5, r2
	b _080BE0C0
	.align 2, 0
_080BE094: .4byte 0x0000168E
_080BE098: .4byte 0x00000276
_080BE09C: .4byte 0x00000C3A
_080BE0A0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BE0B4 @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BE0D2
	.align 2, 0
_080BE0B4: .4byte 0x00000C3A
_080BE0B8:
	cmp r1, #0xf
	bhi _080BE0CC
	ldr r0, _080BE0C8 @ =0x00000C3A
	adds r1, r5, r0
_080BE0C0:
	movs r0, #0x20
	strh r0, [r1]
	b _080BE0D2
	.align 2, 0
_080BE0C8: .4byte 0x00000C3A
_080BE0CC:
	adds r0, r5, #0
	bl FUN_080bd964
_080BE0D2:
	pop {r4, r5}
	pop {r0}
	bx r0
