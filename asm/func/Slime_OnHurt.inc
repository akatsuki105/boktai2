	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sl, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816244A
	bl _08162CE0
_0816244A:
	movs r1, #0x80
	lsls r1, r1, #4
	mov r2, sl
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	bne _0816245A
	b _0816264E
_0816245A:
	mov r8, r6
	mov r2, sp
	mov r3, r8
	adds r3, #8
	mov r4, r8
	adds r4, #0x10
	mov r5, r8
	ldrh r0, [r5, #8]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r5, [r4, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r4, [r4, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	add r5, sp, #8
	mov r6, sl
	adds r6, #0x24
	mov r1, sl
	ldrh r0, [r1, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	ldr r0, _081624EC @ =0x00000256
	add r0, r8
	ldrh r7, [r0]
	add r2, sp, #0x10
	mov sb, r2
	ldr r3, _081624F0 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _081624F0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x30]
	lsls r4, r4, #8
	adds r4, #0x80
	mov r3, sb
	strh r4, [r3]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov r3, sb
	cmp r0, #0
	beq _081624F4
	adds r0, #4
	b _08162500
	.align 2, 0
_081624EC: .4byte 0x00000256
_081624F0: .4byte 0x030046A4
_081624F4:
	ldr r4, _08162548 @ =0x030046A4
	ldr r0, [r4]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08162500:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	ldr r2, [sp, #0x30]
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	add r2, sp, #0x18
	add r0, sp, #0x10
	ldrh r0, [r0]
	mov r4, sl
	ldrh r1, [r4, #0x24]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r0, #0x20
	cmp r0, #0
	blt _0816254C
	asrs r2, r0, #6
	b _08162552
	.align 2, 0
_08162548: .4byte 0x030046A4
_0816254C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r2, r0, #0
_08162552:
	cmp r2, #1
	beq _08162570
	cmp r2, #1
	bgt _08162560
	cmp r2, #0
	beq _0816256A
	b _08162596
_08162560:
	cmp r2, #2
	beq _0816257C
	cmp r2, #3
	beq _0816258A
	b _08162596
_0816256A:
	ldrh r0, [r5]
	adds r0, #0xc0
	b _08162582
_08162570:
	movs r0, #0
	strh r0, [r5]
	add r1, sp, #8
	ldrh r0, [r1, #4]
	adds r0, #0xc0
	b _08162594
_0816257C:
	ldrh r0, [r5]
	subs r0, #0xc0
	movs r2, #0
_08162582:
	add r1, sp, #8
	strh r0, [r1]
	strh r2, [r1, #4]
	b _08162596
_0816258A:
	movs r0, #0
	strh r0, [r5]
	add r1, sp, #8
	ldrh r0, [r1, #4]
	subs r0, #0xc0
_08162594:
	strh r0, [r1, #4]
_08162596:
	add r2, sp, #0x20
	add r0, sp, #8
	mov r4, r8
	ldrh r1, [r4, #8]
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r0, [r5, #2]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r4, #0xc]
	ldrh r4, [r5, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081625D4
	cmp r1, #0
	blt _081625D4
	ldr r0, _081625D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081625D4
	ldr r0, _081625DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081625E0
_081625D4:
	movs r4, #0
	b _081625EE
	.align 2, 0
_081625D8: .4byte 0x030046A8
_081625DC: .4byte 0x030046AC
_081625E0:
	ldr r0, _08162604 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081625EE:
	ldr r0, _08162608 @ =0x00000472
	add r0, r8
	ldrh r6, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816260C
	adds r0, #4
	b _08162618
	.align 2, 0
_08162604: .4byte 0x030046A4
_08162608: .4byte 0x00000472
_0816260C:
	ldr r0, _0816262C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08162618:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _08162630
	mov r0, r8
	bl Slime_TakeFatalDamage
	b _08162CE0
	.align 2, 0
_0816262C: .4byte 0x030046A4
_08162630:
	ldrh r0, [r5]
	mov r5, r8
	ldrh r5, [r5, #8]
	adds r0, r0, r5
	movs r1, #0
	mov r2, r8
	strh r0, [r2, #8]
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r3, [r2, #0xc]
	adds r0, r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0x10]
	strh r1, [r2, #0x14]
	b _08162CE0
_0816264E:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0816265E
	b _08162CE0
_0816265E:
	movs r4, #0x8e
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _08162688
	ldr r5, _08162684 @ =0x0000048C
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08162676
	b _08162CE0
_08162676:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08162CE0
	.align 2, 0
_08162684: .4byte 0x0000048C
_08162688:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08162698
	b _08162CE0
_08162698:
	movs r4, #1
	mov r0, sl
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081626A8
	b _081629B4
_081626A8:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, sl
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov r8, r1
	cmp r0, #0
	bne _081626BA
	b _08162CE0
_081626BA:
	ldr r2, _0816274C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081626CE
	b _08162CE0
_081626CE:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081626DC
	b _08162CE0
_081626DC:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081626F4
	b _0816283C
_081626F4:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816275C
	ands r3, r1
	cmp r3, #0
	beq _0816275C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, sl
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816271A
	rsbs r1, r1, #0
_0816271A:
	cmp r1, #0x20
	bgt _0816275C
	mov r3, sl
	ldrh r0, [r3, #0x3c]
	ldr r5, _08162750 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08162754 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08162758 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08162CE0
	.align 2, 0
_0816274C: .4byte 0x0000A007
_08162750: .4byte 0x000004BE
_08162754: .4byte 0x0000048C
_08162758: .4byte 0x0000044E
_0816275C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08162784 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, sl
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0816278C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08162788 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081627FA
	.align 2, 0
_08162784: .4byte 0x0000048A
_08162788: .4byte 0x03002BE0
_0816278C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081627A8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081627A4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081627FA
	.align 2, 0
_081627A4: .4byte 0x03002BE0
_081627A8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081627C4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081627C0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081627FA
	.align 2, 0
_081627C0: .4byte 0x03002BE0
_081627C4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081627E0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081627DC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081627FA
	.align 2, 0
_081627DC: .4byte 0x03002BE0
_081627E0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081627F2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081627FA
_081627F2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081627FC
_081627FA:
	movs r3, #1
_081627FC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, sl
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, r8
	str r4, [r0]
	ldr r5, _08162830 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0816281E
	b _08162974
_0816281E:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162834
	movs r0, #1
	b _08162836
	.align 2, 0
_08162830: .4byte 0x0000049C
_08162834:
	movs r0, #0
_08162836:
	cmp r0, #0
	bne _0816291A
	b _08162930
_0816283C:
	strh r2, [r7, #0x3e]
	ldr r1, _08162864 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, sl
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0816286C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08162868 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081628DA
	.align 2, 0
_08162864: .4byte 0x0000048A
_08162868: .4byte 0x03002BE0
_0816286C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08162888
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08162884 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081628DA
	.align 2, 0
_08162884: .4byte 0x03002BE0
_08162888:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081628A4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081628A0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081628DA
	.align 2, 0
_081628A0: .4byte 0x03002BE0
_081628A4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081628C0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081628BC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081628DA
	.align 2, 0
_081628BC: .4byte 0x03002BE0
_081628C0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081628D2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081628DA
_081628D2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081628DC
_081628DA:
	movs r3, #1
_081628DC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, sl
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, r8
	str r4, [r0]
	ldr r5, _08162910 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08162974
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162914
	movs r0, #1
	b _08162916
	.align 2, 0
_08162910: .4byte 0x0000049C
_08162914:
	movs r0, #0
_08162916:
	cmp r0, #0
	beq _08162930
_0816291A:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816292C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0816293C
	.align 2, 0
_0816292C: .4byte 0x03002BE0
_08162930:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08162974
_0816293C:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08162974:
	movs r1, #0x80
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081629A0
	ldr r5, _081629AC @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081629A0
	strh r1, [r2]
_081629A0:
	ldr r5, _081629B0 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08162CE0
	.align 2, 0
_081629AC: .4byte 0x0000024E
_081629B0: .4byte 0x0000048C
_081629B4:
	ldr r0, _081629C8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081629CC
	movs r0, #1
	b _081629CE
	.align 2, 0
_081629C8: .4byte 0x030047A4
_081629CC:
	movs r0, #0
_081629CE:
	cmp r0, #0
	beq _081629DC
	mov r0, sl
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081629E4
_081629DC:
	mov r0, sl
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081629E4:
	mov r0, sl
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08162A1C @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08162A20 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x34]
	cmp r0, #2
	bls _08162A12
	cmp r2, #0x17
	bne _08162A24
_08162A12:
	mov r0, sl
	adds r0, #0x40
	ldrh r1, [r0]
	b _08162A46
	.align 2, 0
_08162A1C: .4byte 0x0000048C
_08162A20: .4byte 0x000001DF
_08162A24:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, sl
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08162A12
	mov r0, sl
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08162A74 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08162A46
	movs r1, #0
_08162A46:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov r8, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _08162A82
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0
	blt _08162A78
	asrs r0, r0, #1
	b _08162A7E
	.align 2, 0
_08162A74: .4byte 0x00000187
_08162A78:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08162A7E:
	mov r2, r8
	strh r0, [r2]
_08162A82:
	mov r3, sl
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08162AA0
	mov r0, sl
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08162A9C @ =0x000001DD
	adds r1, r6, r4
	b _08162B0E
	.align 2, 0
_08162A9C: .4byte 0x000001DD
_08162AA0:
	add r3, sp, #0x28
	mov r5, sl
	adds r5, #0xc
	adds r4, r7, #0
	adds r4, #0xc
	ldrh r2, [r7, #0xc]
	mov r1, sl
	ldrh r0, [r1, #0xc]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r0, r1, r0
	strh r0, [r3, #4]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne _08162AFC
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08162AFC
	ldr r2, _08162AEC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08162AF0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08162AF4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _08162AF8 @ =0x000001DD
	adds r1, r6, r3
	b _08162B0E
	.align 2, 0
_08162AEC: .4byte 0x030046B8
_08162AF0: .4byte 0x000003FF
_08162AF4: .4byte 0x0203B400
_08162AF8: .4byte 0x000001DD
_08162AFC:
	movs r4, #0
	ldrsh r0, [r3, r4]
	add r1, sp, #0x28
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl ArcTan2_8
	ldr r2, _08162B30 @ =0x000001DD
	adds r1, r6, r2
_08162B0E:
	strb r0, [r1]
	movs r3, #0
	mov r4, sl
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08162B38
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08162B34 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08162BA6
	.align 2, 0
_08162B30: .4byte 0x000001DD
_08162B34: .4byte 0x03002BE0
_08162B38:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08162B54
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08162B50 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08162BA6
	.align 2, 0
_08162B50: .4byte 0x03002BE0
_08162B54:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08162B70
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08162B6C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08162BA6
	.align 2, 0
_08162B6C: .4byte 0x03002BE0
_08162B70:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08162B8C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08162B88 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08162BA6
	.align 2, 0
_08162B88: .4byte 0x03002BE0
_08162B8C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08162B9E
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08162BA6
_08162B9E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08162BA8
_08162BA6:
	movs r3, #1
_08162BA8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sl
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _08162BDC @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08162C44
	movs r1, #2
	ldr r2, _08162BE0 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162BE4
	movs r0, #1
	b _08162BE6
	.align 2, 0
_08162BDC: .4byte 0x0000049C
_08162BE0: .4byte 0x00000474
_08162BE4:
	movs r0, #0
_08162BE6:
	cmp r0, #0
	beq _08162C00
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08162BFC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08162C0C
	.align 2, 0
_08162BFC: .4byte 0x03002BE0
_08162C00:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08162C44
_08162C0C:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08162C44:
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08162C78
	movs r1, #0x80
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08162C78
	ldr r0, _08162C90 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08162C78
	strh r1, [r2]
_08162C78:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08162C94 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08162C98 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162C9C
	movs r0, #1
	b _08162C9E
	.align 2, 0
_08162C90: .4byte 0x0000024E
_08162C94: .4byte 0x030046A0
_08162C98: .4byte 0x00000934
_08162C9C:
	movs r0, #0
_08162C9E:
	ldr r1, _08162CF0 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08162CB6
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, r8
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #0x34]
	strb r0, [r3]
_08162CB6:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, sl
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08162CE0:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08162CF0: .4byte 0x0000048A
