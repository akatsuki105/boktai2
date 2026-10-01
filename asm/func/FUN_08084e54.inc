	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	subs r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bhi _08084E78
	strh r1, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084E78:
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084EC0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084EC4 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084EC0: .4byte 0x030046B8
_08084EC4: .4byte 0x000003FF
_08084EC8: .4byte 0x0203B400
