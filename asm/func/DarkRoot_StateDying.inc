	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [r7, #0x44]
	str r2, [sp, #0x74]
	ldr r3, _081A3FF8 @ =0x0000046D
	adds r1, r7, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3FFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3FFE
	.align 2, 0
_081A3FF8: .4byte 0x0000046D
_081A3FFC:
	movs r0, #0
_081A3FFE:
	cmp r0, #0
	bne _081A4004
	b _081A41A8
_081A4004:
	movs r0, #0x40
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #1
	bl Enemy_PlayAnimWithVariant
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #4
	bl Enemy_FadeParticles
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	ldr r1, _081A40BC @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A40C0 @ =0x00000474
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl PlayEnemyDeathCry
	add r4, sp, #0x50
	str r5, [sp, #0x2c]
	add r0, sp, #0x2c
	adds r1, r4, #0
	ldr r2, _081A40C4 @ =0x05000002
	bl CpuSet
	ldr r2, _081A40C8 @ =0x000001DD
	adds r0, r7, r2
	ldrb r3, [r0]
	ldr r2, _081A40CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A40D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _081A40D4 @ =0x0203B400
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r0, #0x1f
	adds r6, r4, #0
	ands r5, r0
	ldr r2, _081A40D8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov r8, r6
	cmp r0, #0
	blt _081A40DC
	asrs r1, r0, #0xc
	b _081A40E2
	.align 2, 0
_081A40BC: .4byte 0x0000FFF7
_081A40C0: .4byte 0x00000474
_081A40C4: .4byte 0x05000002
_081A40C8: .4byte 0x000001DD
_081A40CC: .4byte 0x030046B8
_081A40D0: .4byte 0x000003FF
_081A40D4: .4byte 0x0203B400
_081A40D8: .4byte gSineTable
_081A40DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A40E2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A40FC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A4100
	asrs r0, r0, #0xc
	b _081A4106
	.align 2, 0
_081A40FC: .4byte gSineTable
_081A4100:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A4106:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r2, _081A4168 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A416C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A4170 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x30
	mov r6, r8
	strh r0, [r6, #2]
	adds r0, r7, #0
	adds r0, #8
	ldr r2, _081A4174 @ =0x0000D638
	ldr r3, _081A4178 @ =0x000099DD
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0x1e
	str r1, [sp, #4]
	movs r5, #2
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xdc
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	mov r1, r8
	bl Entity081efa9c_Spawn
	ldr r1, _081A417C @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	ands r4, r5
	cmp r4, #0
	beq _081A4180
	movs r0, #0xe5
	bl PlaySound_082406e0
	b _081A41A8
	.align 2, 0
_081A4168: .4byte 0x030046B8
_081A416C: .4byte 0x000003FF
_081A4170: .4byte 0x0203B400
_081A4174: .4byte 0x0000D638
_081A4178: .4byte 0x000099DD
_081A417C: .4byte 0x0000049C
_081A4180:
	ldr r5, _081A4248 @ =0x0000066C
	add r5, sb
	ldrh r0, [r5]
	cmp r0, #0
	beq _081A41A8
	ldrh r0, [r7]
	str r0, [sp, #0x58]
	ldr r1, _081A424C @ =0xFFFF0000
	ldr r0, [sp, #0x5c]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x5c]
	add r0, sp, #0x58
	add r1, sp, #0x5c
	str r0, [r1, #4]
	ldrh r0, [r5]
	bl VM_ExecByID
	strh r4, [r5]
_081A41A8:
	mov r2, sl
	cmp r2, #0x14
	bgt _081A41B0
	b _081A460A
_081A41B0:
	ldr r3, _081A4250 @ =0x0000049C
	adds r0, r7, r3
	ldr r5, [r0]
	movs r0, #2
	ands r5, r0
	cmp r5, #0
	bne _081A4268
	movs r6, #0x95
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	strh r1, [r0]
	subs r6, #0xd4
	adds r2, r7, r6
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	ldr r6, _081A4254 @ =0x00000469
	adds r0, r7, r6
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r7, r6
	str r5, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _081A4258 @ =DarkRoot_StateEmerge
	movs r2, #0x29
	subs r6, #0x17
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081A425C @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	movs r1, #8
	orrs r0, r1
	orrs r0, r3
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2, #6]
	ldr r3, _081A4260 @ =0x00000474
	adds r2, r7, r3
	ldr r0, _081A4264 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081A460A
	.align 2, 0
_081A4248: .4byte 0x0000066C
_081A424C: .4byte 0xFFFF0000
_081A4250: .4byte 0x0000049C
_081A4254: .4byte 0x00000469
_081A4258: .4byte DarkRoot_StateEmerge
_081A425C: .4byte 0x0000046B
_081A4260: .4byte 0x00000474
_081A4264: .4byte 0xFFFFF7FF
_081A4268:
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _081A4280 @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _081A4284 @ =0x00000934
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A4288
	movs r0, #1
	b _081A428A
	.align 2, 0
_081A4280: .4byte 0x030046A0
_081A4284: .4byte 0x00000934
_081A4288:
	movs r0, #0
_081A428A:
	cmp r0, #0
	beq _081A42B8
	movs r0, #0xe5
	bl PlaySound_082406e0
	adds r0, r7, #0
	adds r0, #8
	bl FUN_0803712c
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _081A42B4 @ =0x000001DF
	adds r5, r7, r2
	b _081A442E
	.align 2, 0
_081A42B4: .4byte 0x000001DF
_081A42B8:
	ldr r2, _081A44C0 @ =0xFFFF0000
	ldr r0, [sp, #0x64]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081A44C4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x64]
	add r5, sp, #0x64
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _081A44C8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _081A44CC @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r6, _081A44D0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #8
	adds r2, r2, r7
	mov sl, r2
	movs r3, #4
	str r3, [sp]
	movs r6, #0x14
	mov sb, r6
	str r6, [sp, #4]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #8]
	movs r6, #1
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x20
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xf0
	bl EmitSmoke
	ldr r6, _081A44D4 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #4
	beq _081A4428
	cmp r1, #1
	beq _081A4428
	cmp r1, #5
	beq _081A4428
	cmp r1, #7
	beq _081A4428
	cmp r1, #6
	beq _081A4428
	cmp r1, #0x18
	bne _081A442E
_081A4428:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081A442E:
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081A44A0
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x30]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x34]
	movs r3, #0xc
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x38]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	movs r6, #0x94
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldrh r0, [r7]
	str r0, [sp, #0x4c]
	ldr r1, _081A44C0 @ =0xFFFF0000
	ldr r0, [sp, #0x6c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x6c]
	add r0, sp, #0x30
	add r1, sp, #0x6c
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081A44A0:
	ldrb r0, [r5]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	cmp r0, #0x1f
	bgt _081A44DC
	ldr r3, _081A44D8 @ =0x030046A0
	ldr r2, [r3]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	b _081A44E8
	.align 2, 0
_081A44C0: .4byte 0xFFFF0000
_081A44C4: .4byte 0x0000FFFF
_081A44C8: .4byte 0x030046B8
_081A44CC: .4byte 0x000003FF
_081A44D0: .4byte 0x0203B400
_081A44D4: .4byte 0x000001DF
_081A44D8: .4byte 0x030046A0
_081A44DC:
	ldr r3, _081A4558 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	subs r0, #0x20
_081A44E8:
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r5, r3, #0
	ldr r4, _081A455C @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r2, _081A4560 @ =0x0000046D
	adds r0, r7, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _081A4564 @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r3, [r0]
	ldr r3, _081A4568 @ =0x0000046A
	adds r0, r7, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r7, r6
	str r1, [r0]
	ldr r1, _081A456C @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r3, _081A4570 @ =0x00000948
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r0, _081A4574 @ =0x0000270E
	cmp r1, r0
	bgt _081A4578
	adds r0, r3, #1
	b _081A457C
	.align 2, 0
_081A4558: .4byte 0x030046A0
_081A455C: .4byte Enemy_ClearStateBegun
_081A4560: .4byte 0x0000046D
_081A4564: .4byte 0x0000046B
_081A4568: .4byte 0x0000046A
_081A456C: .4byte 0x0000046C
_081A4570: .4byte 0x00000948
_081A4574: .4byte 0x0000270E
_081A4578:
	ldr r1, _081A4598 @ =0x0000270F
	adds r0, r1, #0
_081A457C:
	strh r0, [r2]
	ldr r0, [r5]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldr r0, _081A459C @ =0x0000270E
	cmp r1, r0
	bgt _081A45A0
	adds r0, r2, #1
	b _081A45A4
	.align 2, 0
_081A4598: .4byte 0x0000270F
_081A459C: .4byte 0x0000270E
_081A45A0:
	ldr r1, _081A45DC @ =0x0000270F
	adds r0, r1, #0
_081A45A4:
	strh r0, [r3]
	adds r0, r7, #0
	bl Enemy_AddKillCount
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	bl AddPlayerExp
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r6, _081A45E0 @ =0x00000189
	adds r1, r7, r6
	ldrb r1, [r1]
	bl Player_AddWeaponExp
	ldr r0, _081A45E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A45E8
	movs r0, #1
	b _081A45EA
	.align 2, 0
_081A45DC: .4byte 0x0000270F
_081A45E0: .4byte 0x00000189
_081A45E4: .4byte 0x030047A4
_081A45E8:
	movs r0, #0
_081A45EA:
	cmp r0, #0
	bne _081A460A
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081A460A
	ldr r0, _081A461C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl DefeatedEnemyLog_Add
_081A460A:
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A461C: .4byte 0x03002B28
