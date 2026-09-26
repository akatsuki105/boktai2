	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r1, [r6, #0x30]
	adds r0, r6, #0
	movs r2, #3
	bl FUN_0822dafc
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldr r5, _080AC454 @ =0x0203B400
	ldr r0, _080AC458 @ =0x030046B8
	mov ip, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r7, _080AC45C @ =0x000003FF
	ands r2, r7
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x18]
	subs r0, #0x1f
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #0x18]
	adds r2, #1
	ands r2, r7
	mov r1, ip
	str r2, [r1]
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	strh r4, [r6, #0x38]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _080AC460
	adds r0, r2, #1
	ands r0, r7
	mov r1, ip
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3e]
	bl Mod
	ldrh r1, [r6, #0x3c]
	adds r1, r1, r0
	strh r1, [r6, #0x3a]
	b _080AC464
	.align 2, 0
_080AC454: .4byte 0x0203B400
_080AC458: .4byte 0x030046B8
_080AC45C: .4byte 0x000003FF
_080AC460:
	ldrh r0, [r6, #0x3c]
	strh r0, [r6, #0x3a]
_080AC464:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
