	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5F54
	ldr r0, _080A5F90 @ =0x000002C3
	bl PlaySound_082406e0
_080A5F54:
	ldrh r0, [r4]
	cmp r0, #7
	bhi _080A5FA0
	ldr r6, _080A5F94 @ =0x0203B400
	ldr r5, _080A5F98 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080A5F9C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	subs r0, #2
	adds r2, r7, #0
	adds r2, #0x58
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #2
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	b _080A5FB0
	.align 2, 0
_080A5F90: .4byte 0x000002C3
_080A5F94: .4byte 0x0203B400
_080A5F98: .4byte 0x030046B8
_080A5F9C: .4byte 0x000003FF
_080A5FA0:
	cmp r0, #8
	bne _080A5FB0
	adds r0, r7, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A5FB0:
	adds r1, r7, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A5FC8
	adds r0, r7, #0
	bl KillEntity
_080A5FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
