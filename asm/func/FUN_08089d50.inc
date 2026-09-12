	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x64]
	cmp r0, #3
	bhi _08089D8E
	ldr r6, _08089DA0 @ =0x0203B400
	ldr r5, _08089DA4 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089DA8 @ =0x000003FF
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
_08089D8E:
	ldr r1, [r7, #0x64]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08089DAC
	adds r0, r7, #0
	bl FUN_08089c60
	b _08089DB6
	.align 2, 0
_08089DA0: .4byte 0x0203B400
_08089DA4: .4byte 0x030046B8
_08089DA8: .4byte 0x000003FF
_08089DAC:
	cmp r1, #2
	bne _08089DB6
	adds r0, r7, #0
	bl FUN_08089c44
_08089DB6:
	ldr r0, [r7, #0x64]
	cmp r0, #0xf
	bls _08089DD2
	ldr r0, [r7, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x74]
	movs r1, #3
	adds r2, r7, #0
	adds r2, #0x4e
	movs r0, #0
	strh r1, [r2]
	b _08089DD4
_08089DD2:
	adds r0, #1
_08089DD4:
	str r0, [r7, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
