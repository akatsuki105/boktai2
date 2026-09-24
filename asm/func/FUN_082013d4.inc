	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	str r0, [sp, #0x5c]
	cmp r1, #0
	bne _08201402
	bl FUN_082010d0
	ldr r2, _08201460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08201464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08201468 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r2, [sp, #0x5c]
	str r0, [r2, #0x1c]
_08201402:
	ldr r5, [sp, #0x5c]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r5, r0
	mov sl, r5
	ldr r1, [sp, #0x5c]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r7, r1, r2
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	movs r5, #0
	mov sb, r5
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x64]
	ldr r6, _0820146C @ =0x085B0A08
	movs r5, #0xff
	adds r2, r1, #0
	adds r2, #0x44
	movs r4, #0
_0820142E:
	ldrh r0, [r2, #2]
	adds r0, #9
	strh r0, [r2, #2]
	movs r1, #8
	mov r0, sb
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, r0, #0
	adds r3, #0xa
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08201470
	asrs r1, r0, #0xf
	b _08201476
	.align 2, 0
_08201460: .4byte 0x030046B8
_08201464: .4byte 0x000003FF
_08201468: .4byte 0x0203B400
_0820146C: .4byte 0x085B0A08
_08201470:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_08201476:
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0820149A
	asrs r1, r0, #0xf
	b _082014A0
_0820149A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082014A0:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r4, #0x10
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #6
	ble _0820142E
	movs r2, #0
	mov sb, r2
	ldr r5, [sp, #0x64]
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x60]
	adds r7, #0x1c
_082014C2:
	ldrh r1, [r7]
	movs r2, #0x1c
	add r2, sl
	mov r8, r2
	mov r2, sl
	ldrh r0, [r2, #0x1c]
	subs r1, r1, r0
	ldr r0, [sp, #0x60]
	strh r1, [r0]
	ldrh r0, [r7, #2]
	mov r2, r8
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	ldr r1, [sp, #0x60]
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _082015FC @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _0820157C
	ldr r0, _08201600 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0820155C
	ldr r1, [sp, #0x64]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r1, [sp, #0x60]
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_0820155C:
	ldr r2, [sp, #0x64]
	ldrh r0, [r2]
	mov r1, sl
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r5, #2]
	mov r2, r8
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r5, #4]
	mov r1, r8
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r7, #4]
_0820157C:
	movs r2, #0x2c
	rsbs r2, r2, #0
	add sl, r2
	subs r7, #0x2c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #6
	ble _082014C2
	ldr r2, [sp, #0x5c]
	ldr r0, [r2, #0x1c]
	movs r1, #0x20
	bl Mod
	cmp r0, #0
	beq _0820159E
	b _0820179C
_0820159E:
	ldr r4, _08201604 @ =0x030046B8
	ldr r0, [r4]
	adds r2, r0, #1
	ldr r3, _08201608 @ =0x000003FF
	ands r2, r3
	str r2, [r4]
	lsls r0, r2, #1
	ldr r5, _0820160C @ =0x0203B400
	adds r0, r0, r5
	movs r6, #0xff
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _08201666
	ldr r1, [sp, #0x5c]
	ldr r5, _08201610 @ =0x00000694
	adds r0, r1, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	adds r1, r2, #1
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _0820160C @ =0x0203B400
	adds r0, r0, r2
	ldrh r5, [r0]
	ands r5, r6
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r4, [r1]
	movs r0, #0x7f
	ands r4, r0
	ldr r1, _08201614 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _08201618
	asrs r0, r0, #0xc
	b _0820161E
	.align 2, 0
_082015FC: .4byte 0x085AE7C8
_08201600: .4byte 0x085AE7B8
_08201604: .4byte 0x030046B8
_08201608: .4byte 0x000003FF
_0820160C: .4byte 0x0203B400
_08201610: .4byte 0x00000694
_08201614: .4byte 0x085B0A08
_08201618:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0820161E:
	add r3, sp, #0x44
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0820164C @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _08201650
	asrs r1, r0, #0xc
	b _08201656
	.align 2, 0
_0820164C: .4byte 0xFFFF0000
_08201650:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08201656:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	bl FUN_08204d04
	b _0820179C
_08201666:
	ldr r1, [sp, #0x5c]
	ldr r5, _0820169C @ =0x00000694
	adds r0, r1, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	str r1, [sp, #0x50]
	adds r0, r2, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _082016A0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ands r4, r6
	movs r5, #0x78
	ldr r1, _082016A4 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _082016A8
	asrs r0, r0, #0xc
	b _082016AE
	.align 2, 0
_0820169C: .4byte 0x00000694
_082016A0: .4byte 0x0203B400
_082016A4: .4byte 0x085B0A08
_082016A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082016AE:
	add r3, sp, #0x4c
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _082016E0 @ =0xFFFF0000
	ldr r0, [sp, #0x4c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x4c]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _082016E4
	asrs r1, r0, #0xc
	b _082016EA
	.align 2, 0
_082016E0: .4byte 0xFFFF0000
_082016E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082016EA:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #4]
	add r5, sp, #0x54
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r5, #0
	ldr r2, _08201748 @ =0x05000002
	bl CpuSet
	ldr r2, [sp, #0x5c]
	ldr r1, _0820174C @ =0x000006DD
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820175C
	ldr r2, _08201750 @ =0x00002E78
	ldr r3, _08201754 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08201758 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_081f22c0
	b _08201790
	.align 2, 0
_08201748: .4byte 0x05000002
_0820174C: .4byte 0x000006DD
_08201750: .4byte 0x00002E78
_08201754: .4byte 0x000038E2
_08201758: .4byte 0x00000232
_0820175C:
	ldr r2, _082017B8 @ =0x00002E78
	ldr r3, _082017BC @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _082017C0 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_081f22c0
_08201790:
	ldr r2, [sp, #0x5c]
	ldr r5, _082017C4 @ =0x000006DD
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0820179C:
	ldr r0, [sp, #0x5c]
	ldr r2, _082017C8 @ =0x000006D9
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082017B8: .4byte 0x00002E78
_082017BC: .4byte 0x000038E2
_082017C0: .4byte 0x00000232
_082017C4: .4byte 0x000006DD
_082017C8: .4byte 0x000006D9
