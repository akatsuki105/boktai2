	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_080af400
	ldr r5, _080AF634 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080AF638 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080AF640 @ =0x00000686
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080AF644 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF648 @ =0x00000674
	adds r2, r4, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r2, _080AF64C @ =0x0000067C
	adds r1, r4, r2
	ldrh r1, [r1]
	lsrs r1, r1, #4
	ldr r3, _080AF650 @ =0xFFFFFF00
	adds r0, r0, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _080AF654
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	adds r2, #4
	b _080AF670
	.align 2, 0
_080AF634: .4byte 0x030046B8
_080AF638: .4byte 0x000003FF
_080AF63C: .4byte 0x0203B400
_080AF640: .4byte 0x00000686
_080AF644: .4byte 0x03002BE0
_080AF648: .4byte 0x00000674
_080AF64C: .4byte 0x0000067C
_080AF650: .4byte 0xFFFFFF00
_080AF654:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080AF6AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	rsbs r0, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #3
_080AF670:
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _080AF6B0 @ =0x0000067E
	adds r1, r4, r3
	movs r3, #0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080AF6B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF6B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF6AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080AF6BC @ =0x00000682
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080AF6C0 @ =0x0000068C
	adds r0, r4, r1
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF6AC: .4byte 0x0203B400
_080AF6B0: .4byte 0x0000067E
_080AF6B4: .4byte 0x030046B8
_080AF6B8: .4byte 0x000003FF
_080AF6BC: .4byte 0x00000682
_080AF6C0: .4byte 0x0000068C
