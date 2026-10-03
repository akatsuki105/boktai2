	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080B02B4 @ =0x0000068A
	adds r1, r4, r0
	movs r7, #0
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _080B02B8 @ =0x0000067A
	adds r6, r4, r1
	ldrh r0, [r6]
	cmp r0, #0x3f
	bhi _080B02D0
	cmp r0, #0
	bne _080B021C
	adds r0, r4, #0
	bl FUN_080af2f4
	ldr r0, _080B02BC @ =0x03002C58
	ldr r0, [r0]
	ldr r1, _080B02C0 @ =0x0000133E
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
_080B021C:
	ldrh r1, [r6]
	cmp r1, #0x1f
	bls _080B022A
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B02A6
_080B022A:
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	ldr r3, _080B02C4 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _080B02C8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	str r7, [sp]
	str r7, [sp, #4]
	movs r5, #2
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	cmp r0, #0x1f
	bhi _080B02A6
	ldr r1, _080B02CC @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldrh r0, [r6]
	movs r1, #5
	bl Mod
	movs r1, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r0, r0, r1
	str r7, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
_080B02A6:
	ldr r0, _080B02B8 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080B02D8
	.align 2, 0
_080B02B4: .4byte 0x0000068A
_080B02B8: .4byte 0x0000067A
_080B02BC: .4byte 0x03002C58
_080B02C0: .4byte 0x0000133E
_080B02C4: .4byte 0xFFFF0000
_080B02C8: .4byte 0x0000FFFF
_080B02CC: .4byte 0x000006AC
_080B02D0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080af374
_080B02D8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
