	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl GetDate
	asrs r6, r0, #0x10
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r3, r5, r0
	lsrs r0, r6, #0xc
	lsls r2, r0, #5
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r0
	lsls r2, r2, #3
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r6
	lsrs r0, r0, #8
	movs r1, #0x64
	muls r0, r1, r0
	adds r2, r2, r0
	movs r1, #0xf0
	ands r1, r6
	lsrs r1, r1, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xf
	ands r6, r0
	adds r2, r2, r6
	str r2, [r3]
	bl GetDate
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	asrs r6, r1, #8
	lsrs r1, r6, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r4, #0xf
	ands r6, r4
	adds r0, r0, r6
	ldr r2, _08214324 @ =0x000006BC
	adds r1, r5, r2
	strb r0, [r1]
	bl GetDate
	adds r6, r0, #0
	movs r0, #0xff
	ands r6, r0
	lsrs r1, r6, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ands r6, r4
	adds r0, r0, r6
	ldr r2, _08214328 @ =0x000006BD
	adds r1, r5, r2
	strb r0, [r1]
	bl GetHour
	ldr r2, _0821432C @ =0x000006BE
	adds r1, r5, r2
	strb r0, [r1]
	bl GetMinute
	ldr r2, _08214330 @ =0x000006BF
	adds r1, r5, r2
	strb r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r5, r5, r0
	movs r1, #0xb
_08214310:
	ldr r0, [r5]
	ands r0, r2
	str r0, [r5]
	adds r5, #0x60
	subs r1, #1
	cmp r1, #0
	bge _08214310
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08214324: .4byte 0x000006BC
_08214328: .4byte 0x000006BD
_0821432C: .4byte 0x000006BE
_08214330: .4byte 0x000006BF
