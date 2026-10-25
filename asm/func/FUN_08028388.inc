	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	ldr r0, _080283B8 @ =0x00000884
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	ble _080283BC
	subs r0, #1
	b _080283C2
	.align 2, 0
_080283B8: .4byte 0x00000884
_080283BC:
	cmp r0, r2
	bge _080283C4
	adds r0, #1
_080283C2:
	strh r0, [r1]
_080283C4:
	ldr r1, _080283E0 @ =0x00000884
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r3, r0, r1
	ldr r2, _080283E4 @ =0x00000886
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r3, r0
	cmp r0, #0
	blt _080283E8
	asrs r0, r0, #7
	b _080283EE
	.align 2, 0
_080283E0: .4byte 0x00000884
_080283E4: .4byte 0x00000886
_080283E8:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_080283EE:
	adds r3, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _08028404
	asrs r1, r0, #8
	b _0802840A
_08028404:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0802840A:
	ldrh r0, [r5]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08028440 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrh r1, [r5, #2]
	adds r1, #0x78
	lsls r1, r1, #0x10
	ldr r0, _08028444 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _08028448
	asrs r1, r0, #8
	b _0802844E
	.align 2, 0
_08028440: .4byte 0xFFFF0000
_08028444: .4byte 0x0000FFFF
_08028448:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0802844E:
	ldrh r0, [r5, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08028470 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	bl Camera_MoveTo
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028470: .4byte 0xFFFF0000
