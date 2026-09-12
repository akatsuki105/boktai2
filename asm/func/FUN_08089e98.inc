	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08089EF0 @ =0x0203B400
	ldr r5, _08089EF4 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089EF8 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	adds r2, r7, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	adds r1, r7, #0
	adds r1, #0x62
	strh r0, [r1]
	ldr r3, [r7, #0x64]
	cmp r3, #3
	bhi _08089EFC
	movs r0, #0x28
	bl FUN_0823b9cc
	adds r0, r7, #0
	adds r0, #0x50
	ldrh r1, [r0]
	ldr r3, [r7, #0x64]
	lsls r3, r3, #4
	adds r0, r7, #0
	movs r2, #8
	bl FUN_08089b48
	b _08089F0E
	.align 2, 0
_08089EF0: .4byte 0x0203B400
_08089EF4: .4byte 0x030046B8
_08089EF8: .4byte 0x000003FF
_08089EFC:
	adds r0, r7, #0
	adds r0, #0x50
	ldrh r2, [r0]
	subs r3, #4
	lsls r3, r3, #4
	adds r0, r7, #0
	movs r1, #8
	bl FUN_08089b48
_08089F0E:
	ldr r0, [r7, #0x64]
	cmp r0, #7
	bls _08089F2C
	adds r0, r7, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0x4e
	strh r0, [r2]
	str r1, [r7, #0x64]
	b _08089F30
_08089F2C:
	adds r0, #1
	str r0, [r7, #0x64]
_08089F30:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
