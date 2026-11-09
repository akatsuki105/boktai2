	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816E850 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E854
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E856
	.align 2, 0
_0816E850: .4byte 0x0000046C
_0816E854:
	movs r0, #0
_0816E856:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _0816E860
	b _0816E9F4
_0816E860:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _0816E8D8 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	ldr r0, _0816E8DC @ =0x00000834
	add r0, r8
	strb r1, [r0]
	ldr r0, _0816E8E0 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E8E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E8E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0816E8EC @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _0816E8F0 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _0816E8F4
	asrs r1, r0, #0xc
	b _0816E8FA
	.align 2, 0
_0816E8D8: .4byte 0x0000046D
_0816E8DC: .4byte 0x00000834
_0816E8E0: .4byte 0x03002BE0
_0816E8E4: .4byte 0x030046B8
_0816E8E8: .4byte 0x000003FF
_0816E8EC: .4byte 0x0203B400
_0816E8F0: .4byte gSineTable
_0816E8F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E8FA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E916
	asrs r0, r0, #0xc
	b _0816E91C
_0816E916:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E91C:
	strh r0, [r4, #4]
	mov r0, sp
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0816E9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r2, sp
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0816E9B0 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0816E9B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r6, _0816E9B8 @ =0x00000888
	add r6, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _0816E9BC
	asrs r1, r0, #0xc
	b _0816E9C2
	.align 2, 0
_0816E9AC: .4byte 0xFFFF0000
_0816E9B0: .4byte 0x000003FF
_0816E9B4: .4byte 0x0203B400
_0816E9B8: .4byte 0x00000888
_0816E9BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E9C2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E9DC
	asrs r0, r0, #0xc
	b _0816E9E2
_0816E9DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E9E2:
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r1, r3, #0
	bl Ghost_BuildCurvePoints
	ldr r1, _0816EA90 @ =0x000007EA
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_0816E9F4:
	ldr r6, _0816EA94 @ =0x00000834
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _0816EA98 @ =0x000007EC
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl Ghost_SpawnAfterimage
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816EAF4
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _0816EA98 @ =0x000007EC
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r0, _0816EA90 @ =0x000007EA
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816EA9C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816EAA0
	asrs r1, r0, #0xc
	b _0816EAA6
	.align 2, 0
_0816EA90: .4byte 0x000007EA
_0816EA94: .4byte 0x00000834
_0816EA98: .4byte 0x000007EC
_0816EA9C: .4byte gSineTable
_0816EAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816EAA6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816EAC0 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816EAC4
	asrs r0, r0, #0xc
	b _0816EACA
	.align 2, 0
_0816EAC0: .4byte gSineTable
_0816EAC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816EACA:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _0816EAF0 @ =0x00000888
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816EC10
	.align 2, 0
_0816EAF0: .4byte 0x00000888
_0816EAF4:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816EB04
	b _0816EC10
_0816EB04:
	ldr r3, _0816EB90 @ =0x00000888
	add r3, r8
	ldr r2, _0816EB94 @ =0x0000082C
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _0816EB98 @ =0x0000088A
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	movs r0, #0x83
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _0816EB9C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816EBA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816EBA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816EBA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _0816EBAC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r2
	cmp r0, #0
	blt _0816EBB0
	asrs r1, r0, #0xc
	b _0816EBB6
	.align 2, 0
_0816EB90: .4byte 0x00000888
_0816EB94: .4byte 0x0000082C
_0816EB98: .4byte 0x0000088A
_0816EB9C: .4byte 0x03002BE0
_0816EBA0: .4byte 0x030046B8
_0816EBA4: .4byte 0x000003FF
_0816EBA8: .4byte 0x0203B400
_0816EBAC: .4byte gSineTable
_0816EBB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816EBB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0816EBD2
	asrs r0, r0, #0xc
	b _0816EBD8
_0816EBD2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816EBD8:
	strh r0, [r3, #4]
	add r1, sp, #8
	mov r0, sp
	ldrh r2, [r0]
	ldrh r3, [r1]
	adds r2, r2, r3
	strh r2, [r1]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r7, #4]
	subs r0, r0, r2
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl Ghost_BuildCurvePoints
	b _0816EC38
_0816EC10:
	ldr r1, _0816EC44 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _0816EC2E
	ldr r1, _0816EC48 @ =0x000007EA
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0x11
	bhi _0816EC2E
	adds r0, #1
	strh r0, [r1]
_0816EC2E:
	ldr r2, _0816EC44 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816EC38:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816EC44: .4byte 0x00000484
_0816EC48: .4byte 0x000007EA
