	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xe8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x8c]
	ldr r2, _0810E2CC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810E2D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810E2D2
	.align 2, 0
_0810E2CC: .4byte 0x0000046D
_0810E2D0:
	movs r0, #0
_0810E2D2:
	cmp r0, #0
	bne _0810E2D8
	b _0810E4C0
_0810E2D8:
	adds r0, r7, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r3, _0810E37C @ =0x0000046E
	adds r0, r7, r3
	movs r4, #0
	strb r4, [r0]
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
	adds r0, r7, #0
	bl PlayEnemyDeathCry
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _0810E380 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _0810E384 @ =0x0000021E
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _0810E388 @ =0x00000202
	adds r0, r7, r2
	strh r4, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _0810E38C @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #6
	bne _0810E410
	ldrb r0, [r7, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	add r5, sp, #0x4c
	movs r4, #0xa
	ldr r2, _0810E390 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810E394
	asrs r1, r0, #0xc
	b _0810E39A
	.align 2, 0
_0810E37C: .4byte 0x0000046E
_0810E380: .4byte 0xFFFEBE3F
_0810E384: .4byte 0x0000021E
_0810E388: .4byte 0x00000202
_0810E38C: .4byte 0x000001DF
_0810E390: .4byte gSineTable
_0810E394:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810E39A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810E3B2
	asrs r0, r0, #0xc
	b _0810E3B8
_0810E3B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810E3B8:
	movs r4, #0
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x54]
	str r1, [sp, #0x58]
	ldr r2, [sp, #0x54]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0810E404 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x54]
	movs r0, #0x36
	strh r0, [r6, #2]
	add r0, sp, #0x54
	ldr r2, _0810E408 @ =0x0000D45E
	ldr r3, _0810E40C @ =0x00001DC3
	str r4, [sp]
	movs r1, #0x1a
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xf7
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r1, r6, #0
	bl Entity081efa9c_Spawn
	b _0810E4B2
	.align 2, 0
_0810E404: .4byte 0x0000FFFF
_0810E408: .4byte 0x0000D45E
_0810E40C: .4byte 0x00001DC3
_0810E410:
	cmp r0, #7
	bne _0810E4B2
	ldrb r0, [r7, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	add r5, sp, #0x5c
	movs r4, #0xa
	ldr r2, _0810E440 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810E444
	asrs r1, r0, #0xc
	b _0810E44A
	.align 2, 0
_0810E440: .4byte gSineTable
_0810E444:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810E44A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810E462
	asrs r0, r0, #0xc
	b _0810E468
_0810E462:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810E468:
	movs r4, #0
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	ldr r2, [sp, #0x64]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0810E58C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x64]
	movs r0, #0x36
	strh r0, [r6, #2]
	add r0, sp, #0x64
	ldr r2, _0810E590 @ =0x0000D45E
	ldr r3, _0810E594 @ =0x00001DC3
	movs r1, #4
	str r1, [sp]
	movs r1, #0x1a
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xf7
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r1, r6, #0
	bl Entity081efa9c_Spawn
_0810E4B2:
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r3, _0810E598 @ =0x00000474
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810E4C0:
	adds r0, r7, #0
	bl Enemy_ClearDamage
	ldr r4, _0810E59C @ =0x0000046E
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810E4D4
	bl _0810ECCC
_0810E4D4:
	ldr r5, _0810E5A0 @ =0x0000046B
	adds r0, r7, r5
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r6, #0xc9
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #7
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0xe0]
	cmp r0, #0
	bne _0810E504
	b _0810E648
_0810E504:
	movs r5, #0xcd
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E564
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x2c]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x30]
	movs r3, #0xc
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x34]
	adds r5, #2
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x38]
	movs r6, #0xd0
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E5A4 @ =0xFFFF0000
	ldr r0, [sp, #0x6c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x6c]
	add r1, sp, #0x6c
	add r5, sp, #0x2c
	str r5, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0810E564:
	ldr r6, _0810E5A8 @ =0x000001DF
	adds r0, r7, r6
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0810E5B0
	ldr r0, _0810E5AC @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r2, r2, r5
	adds r1, r4, #0
	lsls r1, r3
	b _0810E5C2
	.align 2, 0
_0810E58C: .4byte 0x0000FFFF
_0810E590: .4byte 0x0000D45E
_0810E594: .4byte 0x00001DC3
_0810E598: .4byte 0x00000474
_0810E59C: .4byte 0x0000046E
_0810E5A0: .4byte 0x0000046B
_0810E5A4: .4byte 0xFFFF0000
_0810E5A8: .4byte 0x000001DF
_0810E5AC: .4byte 0x030046A0
_0810E5B0:
	ldr r0, _0810E630 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0810E5C2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, _0810E634 @ =Skeleton_StateDormant
	movs r3, #0x38
	ldr r1, _0810E638 @ =0x0000046D
	adds r0, r7, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0810E63C @ =0x0000046B
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0810E640 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r2, [r0]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r6, [sp, #0xe0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r0, #0x12
	ldr r1, [sp, #0x8c]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r1, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810E644 @ =0x000003AD
	bl PlaySound_082406e0
	adds r4, #0xa0
	adds r0, r7, r4
	bl ParticleShadow_Hide
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #1
	bl MsgQueue_EndWait
	b _0810ECCC
	.align 2, 0
_0810E630: .4byte 0x030046A0
_0810E634: .4byte Skeleton_StateDormant
_0810E638: .4byte 0x0000046D
_0810E63C: .4byte 0x0000046B
_0810E640: .4byte 0x00000553
_0810E644: .4byte 0x000003AD
_0810E648:
	ldr r5, _0810E68C @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _0810E672
	movs r6, #0x93
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0x17
	ands r0, r1
	movs r2, #0xe6
	lsls r2, r2, #3
	ldr r1, [sp, #0x8c]
	adds r2, r1, r2
	str r2, [sp, #0xd8]
	cmp r0, #0
	beq _0810E672
	b _0810E888
_0810E672:
	movs r2, #0xc0
	lsls r2, r2, #5
	ldr r3, [sp, #0x8c]
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0xd8]
	cmp r0, #0
	beq _0810E690
	movs r0, #1
	b _0810E692
	.align 2, 0
_0810E68C: .4byte 0x0000049C
_0810E690:
	movs r0, #0
_0810E692:
	adds r3, r0, #0
	cmp r3, #0
	beq _0810E69A
	b _0810E888
_0810E69A:
	ldr r1, _0810E73C @ =Skeleton_StateDormant
	movs r0, #0x38
	ldr r5, _0810E740 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r2, #1
	strb r2, [r5]
	ldr r6, _0810E744 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x94]
	strb r3, [r6]
	ldr r4, _0810E748 @ =0x00000553
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sb, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x98]
	movs r1, #0
	strh r3, [r6]
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	strb r0, [r4]
	ldr r5, _0810E74C @ =0x00000469
	adds r5, r5, r7
	mov ip, r5
	strb r1, [r5]
	ldr r6, _0810E750 @ =0x0000046A
	adds r5, r7, r6
	strb r1, [r5]
	ldr r0, _0810E754 @ =0x00000484
	adds r4, r7, r0
	str r3, [r4]
	ldr r1, _0810E758 @ =0x0000046C
	adds r3, r7, r1
	strb r2, [r3]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r2, [r0]
	movs r2, #0x40
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r6, [sp, #0xe0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r1, [sp, #0xd8]
	ldrh r0, [r1]
	ands r0, r2
	ldr r2, [sp, #0x90]
	str r2, [sp, #0xd0]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0xc8]
	mov r1, r8
	str r1, [sp, #0xdc]
	mov r2, sb
	str r2, [sp, #0xe4]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xb4]
	ldr r1, [sp, #0x9c]
	str r1, [sp, #0xbc]
	mov r2, ip
	str r2, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xd4]
	str r3, [sp, #0xcc]
	cmp r0, #0
	beq _0810E75C
	movs r0, #1
	b _0810E75E
	.align 2, 0
_0810E73C: .4byte Skeleton_StateDormant
_0810E740: .4byte 0x0000046D
_0810E744: .4byte 0x0000046B
_0810E748: .4byte 0x00000553
_0810E74C: .4byte 0x00000469
_0810E750: .4byte 0x0000046A
_0810E754: .4byte 0x00000484
_0810E758: .4byte 0x0000046C
_0810E75C:
	movs r0, #0
_0810E75E:
	cmp r0, #0
	beq _0810E776
	ldr r3, _0810E80C @ =0x000001DF
	adds r1, r7, r3
	movs r0, #7
	strb r0, [r1]
	adds r0, r7, #0
	bl Skeleton_InitAnims
	adds r0, r7, #0
	bl Skeleton_InitAttackRanges
_0810E776:
	ldr r4, [sp, #0x8c]
	ldr r5, _0810E810 @ =0x00000726
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r0, _0810E814 @ =0x00004E1F
	cmp r1, r0
	bls _0810E864
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E7E4
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x2c]
	movs r3, #0xa
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x30]
	movs r4, #0xc
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x34]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x38]
	adds r6, #6
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E818 @ =0xFFFF0000
	ldr r0, [sp, #0x74]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x74]
	add r1, sp, #0x74
	add r4, sp, #0x2c
	str r4, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0810E7E4:
	ldr r5, _0810E80C @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0810E820
	ldr r0, _0810E81C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0810E832
	.align 2, 0
_0810E80C: .4byte 0x000001DF
_0810E810: .4byte 0x00000726
_0810E814: .4byte 0x00004E1F
_0810E818: .4byte 0xFFFF0000
_0810E81C: .4byte 0x030046A0
_0810E820:
	ldr r0, _0810E858 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0810E832:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r2, [sp, #0x8c]
	ldr r3, _0810E85C @ =0x0000072A
	adds r0, r2, r3
	ldrh r0, [r0]
	bl AddPlayerExp
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	ldr r5, _0810E860 @ =0x00000189
	adds r1, r7, r5
	ldrb r1, [r1]
	bl Player_AddWeaponExp
	b _0810E872
	.align 2, 0
_0810E858: .4byte 0x030046A0
_0810E85C: .4byte 0x0000072A
_0810E860: .4byte 0x00000189
_0810E864:
	ldr r6, [sp, #0x8c]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	bl AddPlayerExp
_0810E872:
	movs r0, #0x10
	ldr r2, [sp, #0xd8]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810E884 @ =0x000003AD
	bl PlaySound_082406e0
	b _0810EC3E
	.align 2, 0
_0810E884: .4byte 0x000003AD
_0810E888:
	ldr r3, _0810E914 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r4, _0810E918 @ =0x0000046D
	adds r4, r4, r7
	mov sl, r4
	movs r0, #0
	movs r1, #1
	strb r1, [r4]
	ldr r5, _0810E91C @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	strb r0, [r5]
	ldr r6, _0810E920 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	strb r2, [r6]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	movs r2, #0
	strh r0, [r3]
	movs r3, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xb0]
	strb r1, [r4]
	ldr r6, _0810E924 @ =0x00000469
	adds r5, r7, r6
	strb r2, [r5]
	ldr r2, _0810E928 @ =0x0000046A
	adds r4, r7, r2
	strb r3, [r4]
	adds r6, #0x1b
	adds r3, r7, r6
	str r0, [r3]
	ldr r0, _0810E92C @ =0x0000046C
	adds r2, r7, r0
	strb r1, [r2]
	movs r0, #0x40
	ldr r6, [sp, #0xd8]
	ldrh r1, [r6]
	ands r1, r0
	mov r0, sl
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xdc]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xe4]
	ldr r0, [sp, #0xac]
	str r0, [sp, #0xb4]
	ldr r6, [sp, #0xb0]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0xd4]
	str r2, [sp, #0xcc]
	cmp r1, #0
	beq _0810E930
	movs r0, #1
	b _0810E932
	.align 2, 0
_0810E914: .4byte Enemy_ClearStateBegun
_0810E918: .4byte 0x0000046D
_0810E91C: .4byte 0x0000046B
_0810E920: .4byte 0x00000553
_0810E924: .4byte 0x00000469
_0810E928: .4byte 0x0000046A
_0810E92C: .4byte 0x0000046C
_0810E930:
	movs r0, #0
_0810E932:
	cmp r0, #0
	beq _0810E93E
	ldr r0, _0810E9D0 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #7
	strb r0, [r1]
_0810E93E:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E9A4
	movs r3, #8
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x2c]
	movs r4, #0xa
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x30]
	movs r5, #0xc
	ldrsh r0, [r7, r5]
	str r0, [sp, #0x34]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x38]
	adds r1, #6
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E9D4 @ =0xFFFF0000
	ldr r0, [sp, #0x7c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x7c]
	add r1, sp, #0x7c
	add r5, sp, #0x2c
	str r5, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0810E9A4:
	ldr r6, _0810E9D0 @ =0x000001DF
	adds r4, r7, r6
	ldrb r0, [r4]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	str r4, [sp, #0xb8]
	cmp r3, #0x1f
	bgt _0810E9DC
	ldr r0, _0810E9D8 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _0810E9EE
	.align 2, 0
_0810E9D0: .4byte 0x000001DF
_0810E9D4: .4byte 0xFFFF0000
_0810E9D8: .4byte 0x030046A0
_0810E9DC:
	ldr r0, _0810EA2C @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe3
	lsls r5, r5, #2
	adds r2, r2, r5
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0810E9EE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r6, [sp, #0x8c]
	ldr r1, _0810EA30 @ =0x0000072A
	adds r0, r6, r1
	ldrh r0, [r0]
	bl AddPlayerExp
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r3, _0810EA34 @ =0x00000189
	adds r1, r7, r3
	ldrb r1, [r1]
	bl Player_AddWeaponExp
	ldr r0, _0810EA2C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0810EA38 @ =0x00000948
	adds r2, r0, r4
	ldrh r3, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldr r0, _0810EA3C @ =0x0000270E
	cmp r1, r0
	bgt _0810EA40
	adds r0, r3, #1
	b _0810EA44
	.align 2, 0
_0810EA2C: .4byte 0x030046A0
_0810EA30: .4byte 0x0000072A
_0810EA34: .4byte 0x00000189
_0810EA38: .4byte 0x00000948
_0810EA3C: .4byte 0x0000270E
_0810EA40:
	ldr r6, _0810EA60 @ =0x0000270F
	adds r0, r6, #0
_0810EA44:
	strh r0, [r2]
	ldr r0, _0810EA64 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0810EA68 @ =0x0000270E
	cmp r1, r0
	bgt _0810EA6C
	adds r0, r3, #1
	b _0810EA70
	.align 2, 0
_0810EA60: .4byte 0x0000270F
_0810EA64: .4byte 0x030046A0
_0810EA68: .4byte 0x0000270E
_0810EA6C:
	ldr r5, _0810EC00 @ =0x0000270F
	adds r0, r5, #0
_0810EA70:
	strh r0, [r2]
	adds r0, r7, #0
	bl Enemy_AddKillCount
	ldr r2, _0810EC04 @ =0xFFFF0000
	ldr r0, [sp, #0x84]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0810EC08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x84]
	add r5, sp, #0x84
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _0810EC0C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r6, _0810EC10 @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0810EC14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r3, #4
	str r3, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r4, #4
	str r4, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl EmitSmoke
	ldr r5, [sp, #0xb8]
	ldrb r4, [r5]
	cmp r4, #4
	beq _0810EBE8
	cmp r4, #1
	beq _0810EBE8
	cmp r4, #5
	beq _0810EBE8
	cmp r4, #7
	beq _0810EBE8
	cmp r4, #6
	beq _0810EBE8
	cmp r4, #0x18
	bne _0810EBEE
_0810EBE8:
	movs r0, #0xe5
	bl PlaySound_082406e0
_0810EBEE:
	ldr r0, _0810EC18 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810EC1C
	movs r0, #1
	b _0810EC1E
	.align 2, 0
_0810EC00: .4byte 0x0000270F
_0810EC04: .4byte 0xFFFF0000
_0810EC08: .4byte 0x0000FFFF
_0810EC0C: .4byte 0x030046B8
_0810EC10: .4byte 0x000003FF
_0810EC14: .4byte 0x0203B400
_0810EC18: .4byte 0x030047A4
_0810EC1C:
	movs r0, #0
_0810EC1E:
	cmp r0, #0
	bne _0810EC3E
	movs r1, #0x80
	lsls r1, r1, #4
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0810EC3E
	ldr r0, _0810EC5C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl DefeatedEnemyLog_Add
_0810EC3E:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl ParticleShadow_Hide
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0xd8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810EC60
	movs r0, #1
	b _0810EC62
	.align 2, 0
_0810EC5C: .4byte 0x03002B28
_0810EC60:
	movs r0, #0
_0810EC62:
	cmp r0, #0
	beq _0810ECCC
	add r1, sp, #0x2c
	movs r4, #0
	movs r5, #0
	movs r0, #6
	strh r0, [r1]
	ldr r3, [sp, #0x8c]
	ldr r6, _0810ECDC @ =0x00000756
	adds r0, r3, r6
	ldrb r0, [r0]
	strh r0, [r1, #2]
	ldrh r0, [r7, #8]
	strh r0, [r1, #4]
	ldrh r0, [r7, #0xa]
	strh r0, [r1, #6]
	ldrh r0, [r7, #0xc]
	strh r0, [r1, #8]
	movs r0, #8
	bl Enemy_SendMsgByKind
	ldr r1, _0810ECE0 @ =Enemy_ClearStateBegun
	movs r0, #0x10
	movs r2, #1
	ldr r3, [sp, #0xd0]
	strb r2, [r3]
	ldr r6, [sp, #0xc8]
	strb r4, [r6]
	ldr r3, [sp, #0xdc]
	strb r0, [r3]
	ldr r6, [sp, #0xe4]
	str r1, [r6]
	ldr r0, [sp, #0xb4]
	strh r5, [r0]
	movs r0, #3
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r3, [sp, #0xc0]
	strb r4, [r3]
	ldr r6, [sp, #0xc4]
	strb r4, [r6]
	ldr r0, [sp, #0xd4]
	str r5, [r0]
	ldr r1, [sp, #0xcc]
	strb r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810ECCC:
	add sp, #0xe8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810ECDC: .4byte 0x00000756
_0810ECE0: .4byte Enemy_ClearStateBegun
