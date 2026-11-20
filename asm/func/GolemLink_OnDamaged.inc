	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x34]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _081C24E4 @ =0x0000065C
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r6, r7, r4
	ldr r0, [r6]
	ldr r5, _081C24E8 @ =0xFEFFFFFF
	ands r0, r5
	str r0, [r6]
	ldr r0, _081C24EC @ =0x0000049C
	adds r0, r0, r7
	mov sl, r0
	ldr r4, [r0]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	bne _081C243A
	b _081C2750
_081C243A:
	movs r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081C24F0 @ =0xFFFF5FD8
	ands r0, r1
	strh r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _081C24F4 @ =0xFFFFF634
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _081C24F8 @ =0xFFFFBFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r5, _081C24FC @ =0x00000316
	adds r4, r7, r5
	ldrb r0, [r4]
	cmp r0, #3
	bhi _081C24B8
	movs r0, #0x14
	str r0, [sp]
	subs r0, #0x15
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0xa
	bl Enemy_ScatterParticles
	movs r6, #0x8c
	lsls r6, r6, #3
	adds r2, r7, r6
	ldrh r0, [r2]
	lsls r0, r0, #1
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r1, r1, r0
	movs r0, #0x91
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r5, _081C2500 @ =0x00000462
	adds r3, r7, r5
	movs r0, #1
	ldrh r6, [r2]
	lsls r0, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_081C24B8:
	movs r1, #1
	ldrb r4, [r4]
	lsls r1, r4
	ldr r2, _081C2504 @ =0x0000048A
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldr r0, _081C2508 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C250C
	movs r0, #1
	b _081C250E
	.align 2, 0
_081C24E4: .4byte 0x0000065C
_081C24E8: .4byte 0xFEFFFFFF
_081C24EC: .4byte 0x0000049C
_081C24F0: .4byte 0xFFFF5FD8
_081C24F4: .4byte 0xFFFFF634
_081C24F8: .4byte 0xFFFFBFFF
_081C24FC: .4byte 0x00000316
_081C2500: .4byte 0x00000462
_081C2504: .4byte 0x0000048A
_081C2508: .4byte 0x030047A4
_081C250C:
	movs r0, #0
_081C250E:
	cmp r0, #0
	beq _081C257C
	movs r4, #0x94
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081C257C
	cmp r2, #0
	beq _081C257C
	ldr r0, _081C2534 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081C2538
	movs r0, #1
	rsbs r0, r0, #0
	b _081C253C
	.align 2, 0
_081C2534: .4byte 0x03002C68
_081C2538:
	movs r5, #0x18
	ldrsh r0, [r0, r5]
_081C253C:
	cmp r0, #1
	beq _081C255E
	cmp r0, #1
	bgt _081C254A
	cmp r0, #0
	beq _081C2554
	b _081C257C
_081C254A:
	cmp r0, #2
	beq _081C2568
	cmp r0, #3
	beq _081C2572
	b _081C257C
_081C2554:
	ldr r0, [r1]
	cmp r0, #1
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C255E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C2568:
	ldr r0, [r1]
	cmp r0, #4
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C2572:
	ldr r0, [r1]
	cmp r0, #8
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C257C:
	movs r0, #1
_081C257E:
	cmp r0, #0
	beq _081C25E4
	ldrh r0, [r7]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r2, [r2]
	ldr r4, _081C2684 @ =0x0000025A
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r5, #1
	str r5, [sp]
	bl HUD_ShowEnemyGauge
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081C2688 @ =0x05000002
	bl CpuSet
	ldr r6, _081C268C @ =0x0000048A
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	bne _081C25D0
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081C25E4
_081C25D0:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r4, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
_081C25E4:
	movs r0, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	movs r1, #0
	strb r0, [r2]
	ldr r3, _081C2690 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r1, [r3]
	ldr r4, _081C2694 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x40]
	strb r1, [r4]
	ldr r5, _081C2698 @ =0x00000484
	adds r5, r7, r5
	str r5, [sp, #0x44]
	str r1, [r5]
	ldr r6, _081C269C @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r0, #1
	strb r0, [r6]
	ldr r3, _081C26A0 @ =GolemLink_StateIgnite
	movs r2, #0x2d
	ldr r4, _081C26A4 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	strb r0, [r4]
	ldr r5, _081C26A8 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, _081C26AC @ =0x00000553
	adds r5, r7, r6
	strb r2, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r3, [r4]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	subs r6, #0xef
	adds r1, r7, r6
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _081C26B0 @ =0x0000047E
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r3, #0x95
	adds r0, r7, r3
	ldrb r0, [r0]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0x164]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x168]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x16c]
	ldr r3, [sp, #0x44]
	str r3, [sp, #0x180]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x174]
	ldr r3, [sp, #0x4c]
	str r3, [sp, #0x178]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0x170]
	str r5, [sp, #0x144]
	str r4, [sp, #0x148]
	str r2, [sp, #0x15c]
	cmp r0, #0
	bne _081C26B4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081C26C0
	.align 2, 0
_081C2684: .4byte 0x0000025A
_081C2688: .4byte 0x05000002
_081C268C: .4byte 0x0000048A
_081C2690: .4byte 0x00000469
_081C2694: .4byte 0x0000046A
_081C2698: .4byte 0x00000484
_081C269C: .4byte 0x0000046C
_081C26A0: .4byte GolemLink_StateIgnite
_081C26A4: .4byte 0x0000046D
_081C26A8: .4byte 0x0000046B
_081C26AC: .4byte 0x00000553
_081C26B0: .4byte 0x0000047E
_081C26B4:
	ldr r2, [r7, #0x44]
	ldr r0, _081C273C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C26C0:
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081C2740 @ =0x00000494
	adds r1, r7, r2
	movs r5, #0
	movs r4, #0
	ldr r0, _081C2744 @ =0x00001770
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	ldr r3, _081C2748 @ =0x000004BE
	adds r0, r7, r3
	strh r4, [r0]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081C26FC
	bl _081C491C
_081C26FC:
	movs r0, #3
	ldr r2, [sp, #0x164]
	strb r0, [r2]
	ldr r3, [sp, #0x168]
	strb r5, [r3]
	ldr r6, [sp, #0x16c]
	strb r5, [r6]
	ldr r0, [sp, #0x180]
	str r4, [r0]
	movs r1, #1
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r0, #0x11
	ldr r6, [sp, #0x178]
	strb r1, [r6]
	ldr r1, [sp, #0x170]
	strb r5, [r1]
	ldr r3, [sp, #0x144]
	strb r0, [r3]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	ldr r6, [sp, #0x15c]
	strh r4, [r6]
	ldr r1, _081C274C @ =0x00000464
	adds r0, r7, r1
	strh r4, [r0]
	bl _081C491C
	.align 2, 0
_081C273C: .4byte 0x03003584
_081C2740: .4byte 0x00000494
_081C2744: .4byte 0x00001770
_081C2748: .4byte 0x000004BE
_081C274C: .4byte 0x00000464
_081C2750:
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	movs r2, #0x10
	mov sb, r2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r5, [r1]
	mov r8, r5
	mov r2, r8
	adds r0, r2, #0
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	str r1, [sp, #0x158]
	cmp r5, #0
	beq _081C2800
	movs r1, #8
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _081C27E8 @ =0x00000469
	adds r0, r7, r6
	strb r4, [r0]
	ldr r2, _081C27EC @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081C27F0 @ =0x00000484
	adds r0, r7, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r7, r5
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C27F4 @ =GolemLink_StateBurning
	movs r2, #0x13
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C27F8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r7, r5
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	ldr r0, _081C27FC @ =0xFFFFDFDF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl Enemy_RouteToNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C27DC
	bl _081C491C
_081C27DC:
	adds r0, r7, #0
	bl Enemy_PickPathNodeAwayFromPlayer
	bl _081C491C
	.align 2, 0
_081C27E8: .4byte 0x00000469
_081C27EC: .4byte 0x0000046A
_081C27F0: .4byte 0x00000484
_081C27F4: .4byte GolemLink_StateBurning
_081C27F8: .4byte 0x0000046B
_081C27FC: .4byte 0xFFFFDFDF
_081C2800:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	bne _081C280C
	b _081C2F0C
_081C280C:
	ldr r3, _081C2898 @ =0x000001DD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _081C289C @ =0xFFFFDFDF
	ldr r4, [sp, #0x158]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r6, _081C28A0 @ =0x00000544
	adds r1, r7, r6
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, #0x4c
	adds r1, r7, r0
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	strh r5, [r0, #6]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C2858
	bl _081C314C
_081C2858:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C2894
	cmp r1, #0
	blt _081C2894
	ldr r0, _081C28A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C2894
	ldr r0, _081C28A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C28AC
_081C2894:
	movs r4, #0
	b _081C28BA
	.align 2, 0
_081C2898: .4byte 0x000001DD
_081C289C: .4byte 0xFFFFDFDF
_081C28A0: .4byte 0x00000544
_081C28A4: .4byte 0x030046A8
_081C28A8: .4byte 0x030046AC
_081C28AC:
	ldr r0, _081C28CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C28BA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C28D0
	adds r0, #4
	b _081C28DC
	.align 2, 0
_081C28CC: .4byte 0x030046A4
_081C28D0:
	ldr r0, _081C28F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C28DC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C28F4
	cmp r2, #2
	beq _081C28F8
	b _081C28FC
	.align 2, 0
_081C28F0: .4byte 0x030046A4
_081C28F4:
	ldrb r0, [r5, #4]
	b _081C28FA
_081C28F8:
	ldrb r0, [r5]
_081C28FA:
	subs r1, r1, r0
_081C28FC:
	strh r1, [r5, #2]
	ldr r0, _081C2910 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C2914
	movs r0, #1
	b _081C2916
	.align 2, 0
_081C2910: .4byte 0x030047A4
_081C2914:
	movs r0, #0
_081C2916:
	cmp r0, #0
	beq _081C2954
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081C2936
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C2932
	adds r2, r0, #0
_081C2932:
	cmp r2, #0
	bge _081C2940
_081C2936:
	ldr r6, _081C293C @ =0x000005C4
	adds r0, r7, r6
	b _081C2E78
	.align 2, 0
_081C293C: .4byte 0x000005C4
_081C2940:
	ldr r1, _081C2950 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C299C
	.align 2, 0
_081C2950: .4byte 0x03002BE0
_081C2954:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C2980
	cmp r1, #0
	blt _081C2980
	ldr r0, _081C2984 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C2980
	ldr r0, _081C2988 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C298C
_081C2980:
	movs r5, #0
	b _081C299A
	.align 2, 0
_081C2984: .4byte 0x030046A8
_081C2988: .4byte 0x030046AC
_081C298C:
	ldr r0, _081C29D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C299A:
	movs r2, #0
_081C299C:
	ldr r3, _081C29D8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C29BC
	ldr r1, _081C29DC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C29BC
	b _081C2DB4
_081C29BC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081C29E0
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C29D4: .4byte 0x030046A4
_081C29D8: .4byte 0x00000256
_081C29DC: .4byte 0x03002BE0
_081C29E0:
	ldr r5, _081C2A84 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x158]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x160]
	cmp r6, #0
	beq _081C2AA4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081C2A88 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	movs r5, #1
	strb r5, [r2]
	ldr r3, _081C2A8C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _081C2A90 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x60]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x64]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	add r2, sp, #0x54
	ldrh r2, [r2]
	strh r2, [r1]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081C2A94 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081C2A98 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C2A9C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081C2AA0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x5c]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x60]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x64]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0x68]
	str r4, [sp, #0x15c]
	b _081C2C72
	.align 2, 0
_081C2A84: .4byte 0x00000222
_081C2A88: .4byte 0x0000046D
_081C2A8C: .4byte 0x0000046B
_081C2A90: .4byte 0x00000553
_081C2A94: .4byte 0x00000469
_081C2A98: .4byte 0x0000046A
_081C2A9C: .4byte 0x00000484
_081C2AA0: .4byte 0x0000046C
_081C2AA4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C2B68 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, _081C2B6C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081C2B70 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081C2B74 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081C2B78 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0x84]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x84]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x84]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x80]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0x78]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0x7c]
	str r6, [sp, #0x15c]
	mov r0, sb
	cmp r0, #0
	blt _081C2B62
	cmp r1, #0
	blt _081C2B62
	ldr r0, _081C2B7C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081C2B62
	ldr r0, _081C2B80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C2B84
_081C2B62:
	movs r4, #0
	b _081C2B94
	.align 2, 0
_081C2B68: .4byte 0x0000046D
_081C2B6C: .4byte 0x0000046B
_081C2B70: .4byte 0x00000469
_081C2B74: .4byte 0x00000484
_081C2B78: .4byte 0x0000046C
_081C2B7C: .4byte 0x030046A8
_081C2B80: .4byte 0x030046AC
_081C2B84:
	ldr r0, _081C2BA4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081C2B94:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C2BA8
	adds r0, #4
	b _081C2BB4
	.align 2, 0
_081C2BA4: .4byte 0x030046A4
_081C2BA8:
	ldr r0, _081C2BC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C2BB4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C2BCC
	cmp r2, #2
	beq _081C2BD2
	b _081C2BD8
	.align 2, 0
_081C2BC8: .4byte 0x030046A4
_081C2BCC:
	ldr r2, [sp, #0x84]
	ldrb r0, [r2, #4]
	b _081C2BD6
_081C2BD2:
	ldr r3, [sp, #0x84]
	ldrb r0, [r3]
_081C2BD6:
	subs r1, r1, r0
_081C2BD8:
	ldr r4, [sp, #0x84]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x184]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C2C04
	cmp r1, #0
	blt _081C2C04
	ldr r0, _081C2C08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C2C04
	ldr r0, _081C2C0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C2C10
_081C2C04:
	movs r4, #0
	b _081C2C1E
	.align 2, 0
_081C2C08: .4byte 0x030046A8
_081C2C0C: .4byte 0x030046AC
_081C2C10:
	ldr r0, _081C2C34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C2C1E:
	ldr r6, [sp, #0x184]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C2C38
	adds r0, #4
	b _081C2C44
	.align 2, 0
_081C2C34: .4byte 0x030046A4
_081C2C38:
	ldr r0, _081C2C58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C2C44:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C2C5C
	cmp r3, #2
	beq _081C2C60
	b _081C2C64
	.align 2, 0
_081C2C58: .4byte 0x030046A4
_081C2C5C:
	ldrb r0, [r5, #4]
	b _081C2C62
_081C2C60:
	ldrb r0, [r5]
_081C2C62:
	subs r2, r2, r0
_081C2C64:
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C2C72:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x88]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081C2C9C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C2D7A
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C2CA0
	movs r0, #1
	b _081C2CA2
	.align 2, 0
_081C2C9C: .4byte 0x00000482
_081C2CA0:
	movs r0, #0
_081C2CA2:
	ldr r3, _081C2D8C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C2D7A
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C2D90 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C2D94 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C2D98 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C2D9C @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C2DA0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C2DA4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C2DA8 @ =0x030046B8
	str r5, [sp, #0x188]
_081C2CE8:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C2DAC @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C2DB0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C2D0E
	adds r3, #1
	cmp r3, #3
	ble _081C2CE8
	adds r0, r5, #0
_081C2D0E:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0x88
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C2D7A:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C2D8C: .4byte 0x00000482
_081C2D90: .4byte 0x0000054F
_081C2D94: .4byte 0x0000054C
_081C2D98: .4byte 0x0000054E
_081C2D9C: .4byte 0x00000541
_081C2DA0: .4byte 0x000005BC
_081C2DA4: .4byte 0x00000542
_081C2DA8: .4byte 0x030046B8
_081C2DAC: .4byte 0x000003FF
_081C2DB0: .4byte 0x0203B400
_081C2DB4:
	add r6, sp, #0x14
	ldr r0, _081C2DF4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081C2DF8
	adds r0, #4
	b _081C2E04
	.align 2, 0
_081C2DF4: .4byte 0x030046A4
_081C2DF8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C2E04:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C2E3C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C2E44
	ldr r0, _081C2E40 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C2E6E
	.align 2, 0
_081C2E3C: .4byte 0x000004A4
_081C2E40: .4byte 0xFFFFFDFF
_081C2E44:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C2E64
	cmp r0, #2
	beq _081C2E60
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C2E60:
	movs r0, #1
	b _081C2E70
_081C2E64:
	ldr r0, _081C2E84 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C2E6E:
	movs r0, #0
_081C2E70:
	cmp r0, #0
	bne _081C2E8C
	ldr r3, _081C2E88 @ =0x000005C4
	adds r0, r7, r3
_081C2E78:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C2E84: .4byte 0xFFFFFDFF
_081C2E88: .4byte 0x000005C4
_081C2E8C:
	movs r0, #1
_081C2E8E:
	cmp r0, #0
	beq _081C2E96
	bl _081C48C4
_081C2E96:
	ldr r4, _081C2EC8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C2ED0
	ldr r0, _081C2ECC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C2EFA
	.align 2, 0
_081C2EC8: .4byte 0x000004A4
_081C2ECC: .4byte 0xFFFFFDFF
_081C2ED0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C2EF0
	cmp r0, #2
	beq _081C2EEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C2EEC:
	movs r0, #1
	b _081C2EFC
_081C2EF0:
	ldr r0, _081C2F08 @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C2EFA:
	movs r0, #0
_081C2EFC:
	cmp r0, #0
	bne _081C2F04
	bl _081C48AC
_081C2F04:
	bl _081C48C4
	.align 2, 0
_081C2F08: .4byte 0xFFFFFDFF
_081C2F0C:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C2F26
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r1, r8
	ands r0, r1
	ldr r2, [sp, #0x158]
	b _081C314A
_081C2F26:
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081C2FBC
	movs r5, #0x83
	lsls r5, r5, #2
	adds r3, r7, r5
	movs r6, #0x85
	lsls r6, r6, #2
	adds r2, r7, r6
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081C2FA0 @ =0x00000594
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081C2FA4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081C2FA8 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _081C2FAC @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _081C2FB0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081C2FB4 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _081C2FB8 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	bl _081C491C
	.align 2, 0
_081C2FA0: .4byte 0x00000594
_081C2FA4: .4byte 0x0000046D
_081C2FA8: .4byte 0x0000046B
_081C2FAC: .4byte 0x00000553
_081C2FB0: .4byte 0x0000046A
_081C2FB4: .4byte 0x00000484
_081C2FB8: .4byte 0x0000046C
_081C2FBC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081C2FCC
	b _081C3158
_081C2FCC:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r5, [r0]
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _081C3088
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081C3070 @ =0x000005CC
	adds r0, r7, r3
	ldr r4, [r0]
	movs r1, #0x12
	ldr r5, _081C3074 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	mov r5, sb
	strh r5, [r0]
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _081C3078 @ =0x00000469
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081C307C @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081C3080 @ =0x00000484
	adds r0, r7, r2
	mov r4, sb
	str r4, [r0]
	adds r5, #3
	adds r0, r7, r5
	strb r3, [r0]
	mov r1, sl
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081C3084 @ =0xFEFFFFFC
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	adds r5, #0x16
	adds r0, r7, r5
	strh r3, [r0]
	bl _081C491C
	.align 2, 0
_081C3070: .4byte 0x000005CC
_081C3074: .4byte 0x0000046D
_081C3078: .4byte 0x00000469
_081C307C: .4byte 0x0000046A
_081C3080: .4byte 0x00000484
_081C3084: .4byte 0xFEFFFFFC
_081C3088:
	mov r1, sl
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081C311C
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	ldr r4, _081C3108 @ =0x000005CC
	adds r0, r7, r4
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r3, _081C310C @ =0x0000046D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081C3110 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081C3114 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _081C3118 @ =0xFEFFFFFF
	ands r0, r3
	str r0, [r6]
	bl _081C491C
	.align 2, 0
_081C3108: .4byte 0x000005CC
_081C310C: .4byte 0x0000046D
_081C3110: .4byte 0x00000469
_081C3114: .4byte 0x0000046C
_081C3118: .4byte 0xFEFFFFFF
_081C311C:
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _081C3140
	adds r0, r7, #0
	bl GolemLink_TargetPlayerTile
	ldr r5, [sp, #0x34]
	ldr r6, _081C3154 @ =0x000006B4
	adds r1, r5, r6
	movs r0, #0x78
	strh r0, [r1]
_081C3140:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
_081C314A:
	strh r0, [r2]
_081C314C:
	movs r0, #0
	bl _081C491E
	.align 2, 0
_081C3154: .4byte 0x000006B4
_081C3158:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081C31F0
	movs r4, #0xc8
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081C31D8 @ =0x000005CC
	adds r0, r7, r3
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r4, _081C31DC @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r3, _081C31E0 @ =0x0000046B
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081C31E4 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081C31E8 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _081C31EC @ =0xFEFFFFFF
	ands r0, r3
	str r0, [r6]
	bl _081C491C
	.align 2, 0
_081C31D8: .4byte 0x000005CC
_081C31DC: .4byte 0x0000046D
_081C31E0: .4byte 0x0000046B
_081C31E4: .4byte 0x00000469
_081C31E8: .4byte 0x0000046C
_081C31EC: .4byte 0xFEFFFFFF
_081C31F0:
	movs r3, #0x21
	rsbs r3, r3, #0
	mov r4, r8
	ands r3, r4
	ldr r5, [sp, #0x158]
	strh r3, [r5]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x154]
	cmp r0, #0
	bne _081C314C
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	bne _081C321A
	b _081C3970
_081C321A:
	ldr r0, _081C32AC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C3246
	ldr r1, _081C32B0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C3246
	ldr r3, _081C32B4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081C3246:
	movs r1, #0x80
	ldr r4, [sp, #0x154]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #4
	ldr r5, _081C32B8 @ =0x00000222
	adds r4, r7, r5
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	str r4, [sp, #0x160]
	cmp r0, #0
	bne _081C326C
	b _081C314C
_081C326C:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C32A8
	cmp r1, #0
	blt _081C32A8
	ldr r0, _081C32BC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C32A8
	ldr r0, _081C32C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C32C4
_081C32A8:
	movs r4, #0
	b _081C32D2
	.align 2, 0
_081C32AC: .4byte 0x0000048D
_081C32B0: .4byte 0x0000048C
_081C32B4: .4byte 0x000004BE
_081C32B8: .4byte 0x00000222
_081C32BC: .4byte 0x030046A8
_081C32C0: .4byte 0x030046AC
_081C32C4:
	ldr r0, _081C32E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C32D2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C32E8
	adds r0, #4
	b _081C32F4
	.align 2, 0
_081C32E4: .4byte 0x030046A4
_081C32E8:
	ldr r0, _081C3308 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C32F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C330C
	cmp r2, #2
	beq _081C3310
	b _081C3314
	.align 2, 0
_081C3308: .4byte 0x030046A4
_081C330C:
	ldrb r0, [r5, #4]
	b _081C3312
_081C3310:
	ldrb r0, [r5]
_081C3312:
	subs r1, r1, r0
_081C3314:
	strh r1, [r5, #2]
	ldr r0, _081C3328 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C332C
	movs r0, #1
	b _081C332E
	.align 2, 0
_081C3328: .4byte 0x030047A4
_081C332C:
	movs r0, #0
_081C332E:
	cmp r0, #0
	beq _081C336C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C334E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C334A
	adds r2, r0, #0
_081C334A:
	cmp r2, #0
	bge _081C3358
_081C334E:
	ldr r2, _081C3354 @ =0x000005C4
	adds r0, r7, r2
	b _081C387C
	.align 2, 0
_081C3354: .4byte 0x000005C4
_081C3358:
	ldr r1, _081C3368 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C33B4
	.align 2, 0
_081C3368: .4byte 0x03002BE0
_081C336C:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3398
	cmp r1, #0
	blt _081C3398
	ldr r0, _081C339C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3398
	ldr r0, _081C33A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C33A4
_081C3398:
	movs r5, #0
	b _081C33B2
	.align 2, 0
_081C339C: .4byte 0x030046A8
_081C33A0: .4byte 0x030046AC
_081C33A4:
	ldr r0, _081C33EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C33B2:
	movs r2, #0
_081C33B4:
	ldr r4, _081C33F0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C33D4
	ldr r1, _081C33F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C33D4
	b _081C37B8
_081C33D4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x8c]
	cmp r0, #0
	beq _081C33F8
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C33EC: .4byte 0x030046A4
_081C33F0: .4byte 0x00000256
_081C33F4: .4byte 0x03002BE0
_081C33F8:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0x160]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081C34A8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081C3498 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x90]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081C349C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x98]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	add r0, sp, #0x8c
	ldrh r0, [r0]
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081C34A0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081C34A4 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x8c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x90]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x94]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x98]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x9c]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0xa0]
	str r4, [sp, #0x15c]
	b _081C3676
	.align 2, 0
_081C3498: .4byte 0x0000046D
_081C349C: .4byte 0x0000046B
_081C34A0: .4byte 0x00000469
_081C34A4: .4byte 0x00000484
_081C34A8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C3568 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r3, _081C356C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0xac]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	strb r4, [r3]
	ldr r4, _081C3570 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r3, _081C3574 @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081C3578 @ =0x00000484
	adds r3, r7, r6
	str r2, [r3]
	ldr r1, _081C357C @ =0x0000046C
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, [sp, #0x184]
	ldr r6, [r6]
	str r6, [sp, #0xbc]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xbc]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xb8]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0xa4]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0xa8]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0xac]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0xb0]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0xb4]
	str r6, [sp, #0x15c]
	mov r0, r8
	cmp r0, #0
	blt _081C3562
	cmp r1, #0
	blt _081C3562
	ldr r0, _081C3580 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081C3562
	ldr r0, _081C3584 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3588
_081C3562:
	movs r4, #0
	b _081C3598
	.align 2, 0
_081C3568: .4byte 0x0000046D
_081C356C: .4byte 0x0000046B
_081C3570: .4byte 0x00000469
_081C3574: .4byte 0x0000046A
_081C3578: .4byte 0x00000484
_081C357C: .4byte 0x0000046C
_081C3580: .4byte 0x030046A8
_081C3584: .4byte 0x030046AC
_081C3588:
	ldr r0, _081C35A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081C3598:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C35AC
	adds r0, #4
	b _081C35B8
	.align 2, 0
_081C35A8: .4byte 0x030046A4
_081C35AC:
	ldr r0, _081C35CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C35B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C35D0
	cmp r2, #2
	beq _081C35D6
	b _081C35DC
	.align 2, 0
_081C35CC: .4byte 0x030046A4
_081C35D0:
	ldr r2, [sp, #0xbc]
	ldrb r0, [r2, #4]
	b _081C35DA
_081C35D6:
	ldr r3, [sp, #0xbc]
	ldrb r0, [r3]
_081C35DA:
	subs r1, r1, r0
_081C35DC:
	ldr r4, [sp, #0xbc]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x184]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3608
	cmp r1, #0
	blt _081C3608
	ldr r0, _081C360C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3608
	ldr r0, _081C3610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3614
_081C3608:
	movs r4, #0
	b _081C3622
	.align 2, 0
_081C360C: .4byte 0x030046A8
_081C3610: .4byte 0x030046AC
_081C3614:
	ldr r0, _081C3638 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C3622:
	ldr r6, [sp, #0x184]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C363C
	adds r0, #4
	b _081C3648
	.align 2, 0
_081C3638: .4byte 0x030046A4
_081C363C:
	ldr r0, _081C365C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3648:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C3660
	cmp r3, #2
	beq _081C3664
	b _081C3668
	.align 2, 0
_081C365C: .4byte 0x030046A4
_081C3660:
	ldrb r0, [r5, #4]
	b _081C3666
_081C3664:
	ldrb r0, [r5]
_081C3666:
	subs r2, r2, r0
_081C3668:
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C3676:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xc0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081C36A0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C377E
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C36A4
	movs r0, #1
	b _081C36A6
	.align 2, 0
_081C36A0: .4byte 0x00000482
_081C36A4:
	movs r0, #0
_081C36A6:
	ldr r3, _081C3790 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C377E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C3794 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C3798 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C379C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C37A0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C37A4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C37A8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C37AC @ =0x030046B8
	str r5, [sp, #0x188]
_081C36EC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C37B0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C37B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C3712
	adds r3, #1
	cmp r3, #3
	ble _081C36EC
	adds r0, r5, #0
_081C3712:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0xc0
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C377E:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C3790: .4byte 0x00000482
_081C3794: .4byte 0x0000054F
_081C3798: .4byte 0x0000054C
_081C379C: .4byte 0x0000054E
_081C37A0: .4byte 0x00000541
_081C37A4: .4byte 0x000005BC
_081C37A8: .4byte 0x00000542
_081C37AC: .4byte 0x030046B8
_081C37B0: .4byte 0x000003FF
_081C37B4: .4byte 0x0203B400
_081C37B8:
	add r6, sp, #0x1c
	ldr r0, _081C37F8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081C37FC
	adds r0, #4
	b _081C3808
	.align 2, 0
_081C37F8: .4byte 0x030046A4
_081C37FC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C3808:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C3840 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C3848
	ldr r0, _081C3844 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C3872
	.align 2, 0
_081C3840: .4byte 0x000004A4
_081C3844: .4byte 0xFFFFFDFF
_081C3848:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C3868
	cmp r0, #2
	beq _081C3864
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C3864:
	movs r0, #1
	b _081C3874
_081C3868:
	ldr r0, _081C3888 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C3872:
	movs r0, #0
_081C3874:
	cmp r0, #0
	bne _081C3890
	ldr r3, _081C388C @ =0x000005C4
	adds r0, r7, r3
_081C387C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C3888: .4byte 0xFFFFFDFF
_081C388C: .4byte 0x000005C4
_081C3890:
	movs r0, #1
_081C3892:
	cmp r0, #0
	bne _081C3904
	ldr r4, _081C38C8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C38D0
	ldr r0, _081C38CC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C38FA
	.align 2, 0
_081C38C8: .4byte 0x000004A4
_081C38CC: .4byte 0xFFFFFDFF
_081C38D0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C38F0
	cmp r0, #2
	beq _081C38EC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C38EC:
	movs r0, #1
	b _081C38FC
_081C38F0:
	ldr r0, _081C395C @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C38FA:
	movs r0, #0
_081C38FC:
	cmp r0, #0
	bne _081C3904
	bl _081C48AC
_081C3904:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081C3960 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081C3964 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C3968 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081C396C @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _081C491C
	.align 2, 0
_081C395C: .4byte 0xFFFFFDFF
_081C3960: .4byte 0x0000046D
_081C3964: .4byte 0x0000046B
_081C3968: .4byte 0x0000046A
_081C396C: .4byte 0x00000484
_081C3970:
	ldr r6, [sp, #0x34]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C3982
	bl _081C41A4
_081C3982:
	ldr r3, _081C39F8 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C39AE
	ldr r4, _081C39FC @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C39AE
	ldr r5, _081C3A00 @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081C39AE:
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r3, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x150]
	cmp r3, #0
	blt _081C39F2
	cmp r1, #0
	blt _081C39F2
	ldr r0, _081C3A04 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081C39F2
	ldr r0, _081C3A08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3A0C
_081C39F2:
	movs r4, #0
	b _081C3A1A
	.align 2, 0
_081C39F8: .4byte 0x0000048D
_081C39FC: .4byte 0x0000048C
_081C3A00: .4byte 0x000004BE
_081C3A04: .4byte 0x030046A8
_081C3A08: .4byte 0x030046AC
_081C3A0C:
	ldr r0, _081C3A2C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081C3A1A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C3A30
	adds r0, #4
	b _081C3A3C
	.align 2, 0
_081C3A2C: .4byte 0x030046A4
_081C3A30:
	ldr r0, _081C3A50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3A3C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3A54
	cmp r2, #2
	beq _081C3A58
	b _081C3A5C
	.align 2, 0
_081C3A50: .4byte 0x030046A4
_081C3A54:
	ldrb r0, [r5, #4]
	b _081C3A5A
_081C3A58:
	ldrb r0, [r5]
_081C3A5A:
	subs r1, r1, r0
_081C3A5C:
	strh r1, [r5, #2]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C3A6E
	bl _081C314C
_081C3A6E:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	adds r2, r7, r2
	ldr r5, [r2]
	ldr r3, [sp, #0x150]
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x184]
	cmp r4, #0
	blt _081C3AAE
	cmp r1, #0
	blt _081C3AAE
	ldr r0, _081C3AB4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C3AAE
	ldr r0, _081C3AB8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3ABC
_081C3AAE:
	movs r4, #0
	b _081C3ACA
	.align 2, 0
_081C3AB4: .4byte 0x030046A8
_081C3AB8: .4byte 0x030046AC
_081C3ABC:
	ldr r0, _081C3ADC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C3ACA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C3AE0
	adds r0, #4
	b _081C3AEC
	.align 2, 0
_081C3ADC: .4byte 0x030046A4
_081C3AE0:
	ldr r0, _081C3B00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3AEC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3B04
	cmp r2, #2
	beq _081C3B08
	b _081C3B0C
	.align 2, 0
_081C3B00: .4byte 0x030046A4
_081C3B04:
	ldrb r0, [r5, #4]
	b _081C3B0A
_081C3B08:
	ldrb r0, [r5]
_081C3B0A:
	subs r1, r1, r0
_081C3B0C:
	strh r1, [r5, #2]
	ldr r0, _081C3B20 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C3B24
	movs r0, #1
	b _081C3B26
	.align 2, 0
_081C3B20: .4byte 0x030047A4
_081C3B24:
	movs r0, #0
_081C3B26:
	cmp r0, #0
	beq _081C3B64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C3B46
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C3B42
	adds r2, r0, #0
_081C3B42:
	cmp r2, #0
	bge _081C3B50
_081C3B46:
	ldr r5, _081C3B4C @ =0x000005C4
	adds r0, r7, r5
	b _081C408C
	.align 2, 0
_081C3B4C: .4byte 0x000005C4
_081C3B50:
	ldr r1, _081C3B60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C3BAC
	.align 2, 0
_081C3B60: .4byte 0x03002BE0
_081C3B64:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3B90
	cmp r1, #0
	blt _081C3B90
	ldr r0, _081C3B94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3B90
	ldr r0, _081C3B98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3B9C
_081C3B90:
	movs r5, #0
	b _081C3BAA
	.align 2, 0
_081C3B94: .4byte 0x030046A8
_081C3B98: .4byte 0x030046AC
_081C3B9C:
	ldr r0, _081C3BE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C3BAA:
	movs r2, #0
_081C3BAC:
	ldr r1, _081C3BE8 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C3BCC
	ldr r1, _081C3BEC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C3BCC
	b _081C3FC8
_081C3BCC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc4]
	cmp r0, #0
	beq _081C3BF0
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C3BE4: .4byte 0x030046A4
_081C3BE8: .4byte 0x00000256
_081C3BEC: .4byte 0x03002BE0
_081C3BF0:
	ldr r3, _081C3C98 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x160]
	cmp r0, #0
	beq _081C3CB4
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C3C9C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xc8]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081C3CA0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C3CA4 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	add r1, sp, #0xc4
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081C3CA8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C3CAC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0xc4]
	str r6, [r1]
	ldr r6, _081C3CB0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0xc8]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0xcc]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0xd0]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0xd4]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0xd8]
	str r4, [sp, #0x15c]
	b _081C3E84
	.align 2, 0
_081C3C98: .4byte 0x00000222
_081C3C9C: .4byte 0x0000046D
_081C3CA0: .4byte 0x0000046B
_081C3CA4: .4byte 0x00000553
_081C3CA8: .4byte 0x00000469
_081C3CAC: .4byte 0x00000484
_081C3CB0: .4byte 0x0000046C
_081C3CB4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C3D78 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	strb r0, [r6]
	ldr r2, _081C3D7C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C3D80 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xe4]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0xe8]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xec]
	mov r1, ip
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	strb r3, [r2]
	ldr r3, _081C3D84 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _081C3D88 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081C3D8C @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0xf4]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xf4]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xf4]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xf8]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xf0]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0xdc]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0xe0]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0xe4]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0xe8]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0xec]
	str r6, [sp, #0x15c]
	ldr r0, [sp, #0xf8]
	cmp r0, #0
	blt _081C3D74
	cmp r1, #0
	blt _081C3D74
	ldr r0, _081C3D90 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xf8]
	cmp r2, r0
	bhs _081C3D74
	ldr r0, _081C3D94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3D98
_081C3D74:
	movs r4, #0
	b _081C3DA8
	.align 2, 0
_081C3D78: .4byte 0x0000046D
_081C3D7C: .4byte 0x0000046B
_081C3D80: .4byte 0x00000553
_081C3D84: .4byte 0x00000469
_081C3D88: .4byte 0x0000046A
_081C3D8C: .4byte 0x00000484
_081C3D90: .4byte 0x030046A8
_081C3D94: .4byte 0x030046AC
_081C3D98:
	ldr r0, _081C3DB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xf8]
	adds r4, r0, r3
_081C3DA8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C3DBC
	adds r0, #4
	b _081C3DC8
	.align 2, 0
_081C3DB8: .4byte 0x030046A4
_081C3DBC:
	ldr r0, _081C3DDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3DC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3DE0
	cmp r2, #2
	beq _081C3DE6
	b _081C3DEC
	.align 2, 0
_081C3DDC: .4byte 0x030046A4
_081C3DE0:
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4, #4]
	b _081C3DEA
_081C3DE6:
	ldr r5, [sp, #0xf4]
	ldrb r0, [r5]
_081C3DEA:
	subs r1, r1, r0
_081C3DEC:
	ldr r6, [sp, #0xf4]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3E18
	cmp r1, #0
	blt _081C3E18
	ldr r0, _081C3E1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3E18
	ldr r0, _081C3E20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3E24
_081C3E18:
	movs r4, #0
	b _081C3E32
	.align 2, 0
_081C3E1C: .4byte 0x030046A8
_081C3E20: .4byte 0x030046AC
_081C3E24:
	ldr r0, _081C3E48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C3E32:
	ldr r2, [sp, #0x184]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C3E4C
	adds r0, #4
	b _081C3E58
	.align 2, 0
_081C3E48: .4byte 0x030046A4
_081C3E4C:
	ldr r0, _081C3E6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3E58:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C3E70
	cmp r3, #2
	beq _081C3E74
	b _081C3E78
	.align 2, 0
_081C3E6C: .4byte 0x030046A4
_081C3E70:
	ldrb r0, [r5, #4]
	b _081C3E76
_081C3E74:
	ldrb r0, [r5]
_081C3E76:
	subs r2, r2, r0
_081C3E78:
	ldr r3, [sp, #0x184]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081C3E84:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xfc]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081C3EB0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C3F8E
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C3EB4
	movs r0, #1
	b _081C3EB6
	.align 2, 0
_081C3EB0: .4byte 0x00000482
_081C3EB4:
	movs r0, #0
_081C3EB6:
	ldr r3, _081C3FA0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C3F8E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C3FA4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C3FA8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C3FAC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C3FB0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C3FB4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C3FB8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C3FBC @ =0x030046B8
	str r5, [sp, #0x188]
_081C3EFC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C3FC0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C3FC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C3F22
	adds r3, #1
	cmp r3, #3
	ble _081C3EFC
	adds r0, r5, #0
_081C3F22:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0xfc
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C3F8E:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C3FA0: .4byte 0x00000482
_081C3FA4: .4byte 0x0000054F
_081C3FA8: .4byte 0x0000054C
_081C3FAC: .4byte 0x0000054E
_081C3FB0: .4byte 0x00000541
_081C3FB4: .4byte 0x000005BC
_081C3FB8: .4byte 0x00000542
_081C3FBC: .4byte 0x030046B8
_081C3FC0: .4byte 0x000003FF
_081C3FC4: .4byte 0x0203B400
_081C3FC8:
	add r6, sp, #0x24
	ldr r0, _081C4008 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081C400C
	adds r0, #4
	b _081C4018
	.align 2, 0
_081C4008: .4byte 0x030046A4
_081C400C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C4018:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C4050 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C4058
	ldr r0, _081C4054 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C4082
	.align 2, 0
_081C4050: .4byte 0x000004A4
_081C4054: .4byte 0xFFFFFDFF
_081C4058:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C4078
	cmp r0, #2
	beq _081C4074
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4074:
	movs r0, #1
	b _081C4084
_081C4078:
	ldr r0, _081C4098 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C4082:
	movs r0, #0
_081C4084:
	cmp r0, #0
	bne _081C40A0
	ldr r3, _081C409C @ =0x000005C4
	adds r0, r7, r3
_081C408C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C4098: .4byte 0xFFFFFDFF
_081C409C: .4byte 0x000005C4
_081C40A0:
	movs r0, #1
_081C40A2:
	cmp r0, #0
	bne _081C4112
	ldr r4, _081C40D8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C40E0
	ldr r0, _081C40DC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C410A
	.align 2, 0
_081C40D8: .4byte 0x000004A4
_081C40DC: .4byte 0xFFFFFDFF
_081C40E0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C4100
	cmp r0, #2
	beq _081C40FC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C40FC:
	movs r0, #1
	b _081C410C
_081C4100:
	ldr r0, _081C4184 @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C410A:
	movs r0, #0
_081C410C:
	cmp r0, #0
	bne _081C4112
	b _081C48AC
_081C4112:
	ldr r5, _081C4188 @ =0x00000482
	adds r1, r7, r5
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x34]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081C4132
	adds r0, #1
	strb r0, [r1]
_081C4132:
	ldr r2, _081C418C @ =FUN_080f3cdc
	movs r1, #0xa
	ldr r6, _081C4190 @ =0x0000046D
	adds r0, r7, r6
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	subs r6, #0xeb
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _081C4194 @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _081C4198 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _081C419C @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	ldr r5, _081C41A0 @ =0x0000046C
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0x10
	ldr r6, [sp, #0x154]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	b _081C491C
	.align 2, 0
_081C4184: .4byte 0xFFFFFDFF
_081C4188: .4byte 0x00000482
_081C418C: .4byte FUN_080f3cdc
_081C4190: .4byte 0x0000046D
_081C4194: .4byte 0x00000469
_081C4198: .4byte 0x0000046A
_081C419C: .4byte 0x00000484
_081C41A0: .4byte 0x0000046C

_081C41A4:
	ldr r1, _081C4240 @ =0x00000544
	adds r0, r7, r1
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r3, _081C4244 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C41DA
	ldr r4, _081C4248 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C41DA
	ldr r5, _081C424C @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081C41DA:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C41EA
	bl _081C314C
_081C41EA:
	movs r1, #0x90
	ldr r6, [sp, #0x154]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C423C
	cmp r1, #0
	blt _081C423C
	ldr r0, _081C4250 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C423C
	ldr r0, _081C4254 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4258
_081C423C:
	movs r4, #0
	b _081C4266
	.align 2, 0
_081C4240: .4byte 0x00000544
_081C4244: .4byte 0x0000048D
_081C4248: .4byte 0x0000048C
_081C424C: .4byte 0x000004BE
_081C4250: .4byte 0x030046A8
_081C4254: .4byte 0x030046AC
_081C4258:
	ldr r0, _081C4278 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C4266:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C427C
	adds r0, #4
	b _081C4288
	.align 2, 0
_081C4278: .4byte 0x030046A4
_081C427C:
	ldr r0, _081C429C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4288:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C42A0
	cmp r2, #2
	beq _081C42A4
	b _081C42A8
	.align 2, 0
_081C429C: .4byte 0x030046A4
_081C42A0:
	ldrb r0, [r5, #4]
	b _081C42A6
_081C42A4:
	ldrb r0, [r5]
_081C42A6:
	subs r1, r1, r0
_081C42A8:
	strh r1, [r5, #2]
	ldr r0, _081C42BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C42C0
	movs r0, #1
	b _081C42C2
	.align 2, 0
_081C42BC: .4byte 0x030047A4
_081C42C0:
	movs r0, #0
_081C42C2:
	cmp r0, #0
	beq _081C4300
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081C42E2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C42DE
	adds r2, r0, #0
_081C42DE:
	cmp r2, #0
	bge _081C42EC
_081C42E2:
	ldr r4, _081C42E8 @ =0x000005C4
	adds r0, r7, r4
	b _081C4828
	.align 2, 0
_081C42E8: .4byte 0x000005C4
_081C42EC:
	ldr r1, _081C42FC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C4348
	.align 2, 0
_081C42FC: .4byte 0x03002BE0
_081C4300:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C432C
	cmp r1, #0
	blt _081C432C
	ldr r0, _081C4330 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C432C
	ldr r0, _081C4334 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4338
_081C432C:
	movs r5, #0
	b _081C4346
	.align 2, 0
_081C4330: .4byte 0x030046A8
_081C4334: .4byte 0x030046AC
_081C4338:
	ldr r0, _081C4380 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C4346:
	movs r2, #0
_081C4348:
	ldr r6, _081C4384 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C4368
	ldr r1, _081C4388 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C4368
	b _081C4764
_081C4368:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x100]
	cmp r0, #0
	beq _081C438C
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C4380: .4byte 0x030046A4
_081C4384: .4byte 0x00000256
_081C4388: .4byte 0x03002BE0
_081C438C:
	ldr r3, _081C4434 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0x160]
	cmp r0, #0
	beq _081C4450
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C4438 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x104]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081C443C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C4440 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x110]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x114]
	add r1, sp, #0x100
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081C4444 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C4448 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x100]
	str r6, [r1]
	ldr r6, _081C444C @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x104]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x108]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x10c]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x110]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0x114]
	str r4, [sp, #0x15c]
	b _081C4620
	.align 2, 0
_081C4434: .4byte 0x00000222
_081C4438: .4byte 0x0000046D
_081C443C: .4byte 0x0000046B
_081C4440: .4byte 0x00000553
_081C4444: .4byte 0x00000469
_081C4448: .4byte 0x00000484
_081C444C: .4byte 0x0000046C
_081C4450:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C4514 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x118]
	strb r0, [r6]
	ldr r2, _081C4518 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C451C @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x120]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0x124]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x128]
	mov r1, sl
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x12c]
	strb r3, [r2]
	ldr r3, _081C4520 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _081C4524 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081C4528 @ =0x00000484
	adds r3, r7, r1
	mov r2, sl
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0x130]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x130]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x130]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0x134]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x12c]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0x118]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0x11c]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0x120]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0x124]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0x128]
	str r6, [sp, #0x15c]
	ldr r0, [sp, #0x134]
	cmp r0, #0
	blt _081C4510
	cmp r1, #0
	blt _081C4510
	ldr r0, _081C452C @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0x134]
	cmp r2, r0
	bhs _081C4510
	ldr r0, _081C4530 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4534
_081C4510:
	movs r4, #0
	b _081C4544
	.align 2, 0
_081C4514: .4byte 0x0000046D
_081C4518: .4byte 0x0000046B
_081C451C: .4byte 0x00000553
_081C4520: .4byte 0x00000469
_081C4524: .4byte 0x0000046A
_081C4528: .4byte 0x00000484
_081C452C: .4byte 0x030046A8
_081C4530: .4byte 0x030046AC
_081C4534:
	ldr r0, _081C4554 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0x134]
	adds r4, r0, r3
_081C4544:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C4558
	adds r0, #4
	b _081C4564
	.align 2, 0
_081C4554: .4byte 0x030046A4
_081C4558:
	ldr r0, _081C4578 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4564:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C457C
	cmp r2, #2
	beq _081C4582
	b _081C4588
	.align 2, 0
_081C4578: .4byte 0x030046A4
_081C457C:
	ldr r4, [sp, #0x130]
	ldrb r0, [r4, #4]
	b _081C4586
_081C4582:
	ldr r5, [sp, #0x130]
	ldrb r0, [r5]
_081C4586:
	subs r1, r1, r0
_081C4588:
	ldr r6, [sp, #0x130]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C45B4
	cmp r1, #0
	blt _081C45B4
	ldr r0, _081C45B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C45B4
	ldr r0, _081C45BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C45C0
_081C45B4:
	movs r4, #0
	b _081C45CE
	.align 2, 0
_081C45B8: .4byte 0x030046A8
_081C45BC: .4byte 0x030046AC
_081C45C0:
	ldr r0, _081C45E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C45CE:
	ldr r2, [sp, #0x184]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C45E8
	adds r0, #4
	b _081C45F4
	.align 2, 0
_081C45E4: .4byte 0x030046A4
_081C45E8:
	ldr r0, _081C4608 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C45F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C460C
	cmp r3, #2
	beq _081C4610
	b _081C4614
	.align 2, 0
_081C4608: .4byte 0x030046A4
_081C460C:
	ldrb r0, [r5, #4]
	b _081C4612
_081C4610:
	ldrb r0, [r5]
_081C4612:
	subs r2, r2, r0
_081C4614:
	ldr r3, [sp, #0x184]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081C4620:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x138]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081C464C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C472A
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C4650
	movs r0, #1
	b _081C4652
	.align 2, 0
_081C464C: .4byte 0x00000482
_081C4650:
	movs r0, #0
_081C4652:
	ldr r3, _081C473C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C472A
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C4740 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C4744 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C4748 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C474C @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C4750 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C4754 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C4758 @ =0x030046B8
	str r5, [sp, #0x188]
_081C4698:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C475C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C4760 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C46BE
	adds r3, #1
	cmp r3, #3
	ble _081C4698
	adds r0, r5, #0
_081C46BE:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0x138
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C472A:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C473C: .4byte 0x00000482
_081C4740: .4byte 0x0000054F
_081C4744: .4byte 0x0000054C
_081C4748: .4byte 0x0000054E
_081C474C: .4byte 0x00000541
_081C4750: .4byte 0x000005BC
_081C4754: .4byte 0x00000542
_081C4758: .4byte 0x030046B8
_081C475C: .4byte 0x000003FF
_081C4760: .4byte 0x0203B400
_081C4764:
	add r6, sp, #0x2c
	ldr r0, _081C47A4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081C47A8
	adds r0, #4
	b _081C47B4
	.align 2, 0
_081C47A4: .4byte 0x030046A4
_081C47A8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C47B4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C47EC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C47F4
	ldr r0, _081C47F0 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C481E
	.align 2, 0
_081C47EC: .4byte 0x000004A4
_081C47F0: .4byte 0xFFFFFDFF
_081C47F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C4814
	cmp r0, #2
	beq _081C4810
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4810:
	movs r0, #1
	b _081C4820
_081C4814:
	ldr r0, _081C4834 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C481E:
	movs r0, #0
_081C4820:
	cmp r0, #0
	bne _081C483C
	ldr r3, _081C4838 @ =0x000005C4
	adds r0, r7, r3
_081C4828:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C4834: .4byte 0xFFFFFDFF
_081C4838: .4byte 0x000005C4
_081C483C:
	movs r0, #1
_081C483E:
	cmp r0, #0
	bne _081C48C4
	ldr r4, _081C4874 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C487C
	ldr r0, _081C4878 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C48A6
	.align 2, 0
_081C4874: .4byte 0x000004A4
_081C4878: .4byte 0xFFFFFDFF
_081C487C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C489C
	cmp r0, #2
	beq _081C4898
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4898:
	movs r0, #1
	b _081C48A8
_081C489C:
	ldr r0, _081C48BC @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C48A6:
	movs r0, #0
_081C48A8:
	cmp r0, #0
	bne _081C48C4
_081C48AC:
	ldr r4, _081C48C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081C314C
	.align 2, 0
_081C48BC: .4byte 0xFFFFFDFF
_081C48C0: .4byte 0x000005C4
_081C48C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081C4930 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081C4934 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081C4938 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C493C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081C4940 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081C491C:
	movs r0, #1
_081C491E:
	add sp, #0x18c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C4930: .4byte 0x0000046D
_081C4934: .4byte 0x0000046B
_081C4938: .4byte 0x00000469
_081C493C: .4byte 0x0000046A
_081C4940: .4byte 0x00000484
