	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081AE5F6
	b _081AEC7C
_081AE5F6:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081AE620
	ldr r3, _081AE61C @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AE60E
	b _081AEC7C
_081AE60E:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081AEC7C
	.align 2, 0
_081AE61C: .4byte 0x0000048C
_081AE620:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081AE630
	b _081AEC7C
_081AE630:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081AE640
	b _081AE94C
_081AE640:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081AE652
	b _081AEC7C
_081AE652:
	ldr r2, _081AE6E4 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081AE666
	b _081AEC7C
_081AE666:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081AE674
	b _081AEC7C
_081AE674:
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
	bne _081AE68C
	b _081AE7D4
_081AE68C:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081AE6F4
	ands r3, r1
	cmp r3, #0
	beq _081AE6F4
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081AE6B2
	rsbs r1, r1, #0
_081AE6B2:
	cmp r1, #0x20
	bgt _081AE6F4
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081AE6E8 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081AE6EC @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081AE6F0 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081AEC7C
	.align 2, 0
_081AE6E4: .4byte 0x0000A007
_081AE6E8: .4byte 0x000004BE
_081AE6EC: .4byte 0x0000048C
_081AE6F0: .4byte 0x0000044E
_081AE6F4:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081AE71C @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081AE724
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081AE720 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081AE792
	.align 2, 0
_081AE71C: .4byte 0x0000048A
_081AE720: .4byte 0x03002BE0
_081AE724:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081AE740
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081AE73C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081AE792
	.align 2, 0
_081AE73C: .4byte 0x03002BE0
_081AE740:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081AE75C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081AE758 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081AE792
	.align 2, 0
_081AE758: .4byte 0x03002BE0
_081AE75C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081AE778
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081AE774 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081AE792
	.align 2, 0
_081AE774: .4byte 0x03002BE0
_081AE778:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081AE78A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081AE792
_081AE78A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081AE794
_081AE792:
	movs r3, #1
_081AE794:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081AE7C8 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081AE7B6
	b _081AE90C
_081AE7B6:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AE7CC
	movs r0, #1
	b _081AE7CE
	.align 2, 0
_081AE7C8: .4byte 0x0000049C
_081AE7CC:
	movs r0, #0
_081AE7CE:
	cmp r0, #0
	bne _081AE8B2
	b _081AE8C8
_081AE7D4:
	strh r2, [r7, #0x3e]
	ldr r1, _081AE7FC @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081AE804
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081AE800 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081AE872
	.align 2, 0
_081AE7FC: .4byte 0x0000048A
_081AE800: .4byte 0x03002BE0
_081AE804:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081AE820
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081AE81C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081AE872
	.align 2, 0
_081AE81C: .4byte 0x03002BE0
_081AE820:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081AE83C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081AE838 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081AE872
	.align 2, 0
_081AE838: .4byte 0x03002BE0
_081AE83C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081AE858
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081AE854 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081AE872
	.align 2, 0
_081AE854: .4byte 0x03002BE0
_081AE858:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081AE86A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081AE872
_081AE86A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081AE874
_081AE872:
	movs r3, #1
_081AE874:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081AE8A8 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081AE90C
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AE8AC
	movs r0, #1
	b _081AE8AE
	.align 2, 0
_081AE8A8: .4byte 0x0000049C
_081AE8AC:
	movs r0, #0
_081AE8AE:
	cmp r0, #0
	beq _081AE8C8
_081AE8B2:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081AE8C4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081AE8D4
	.align 2, 0
_081AE8C4: .4byte 0x03002BE0
_081AE8C8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081AE90C
_081AE8D4:
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
_081AE90C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081AE938
	ldr r5, _081AE944 @ =0x0000024E
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
	bls _081AE938
	strh r1, [r2]
_081AE938:
	ldr r5, _081AE948 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081AEC7C
	.align 2, 0
_081AE944: .4byte 0x0000024E
_081AE948: .4byte 0x0000048C
_081AE94C:
	ldr r0, _081AE960 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AE964
	movs r0, #1
	b _081AE966
	.align 2, 0
_081AE960: .4byte 0x030047A4
_081AE964:
	movs r0, #0
_081AE966:
	cmp r0, #0
	beq _081AE974
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081AE97C
_081AE974:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081AE97C:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081AE9B4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081AE9B8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081AE9AA
	cmp r2, #0x17
	bne _081AE9BC
_081AE9AA:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081AE9DE
	.align 2, 0
_081AE9B4: .4byte 0x0000048C
_081AE9B8: .4byte 0x000001DF
_081AE9BC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081AE9AA
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081AEA0C @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081AE9DE
	movs r1, #0
_081AE9DE:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081AEA1A
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081AEA10
	asrs r0, r0, #1
	b _081AEA16
	.align 2, 0
_081AEA0C: .4byte 0x00000187
_081AEA10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081AEA16:
	mov r2, sb
	strh r0, [r2]
_081AEA1A:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081AEA38
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081AEA34 @ =0x000001DD
	adds r1, r6, r4
	b _081AEAAC
	.align 2, 0
_081AEA34: .4byte 0x000001DD
_081AEA38:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081AEA98
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081AEA98
	ldr r2, _081AEA88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081AEA8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081AEA90 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081AEA94 @ =0x000001DD
	adds r1, r6, r4
	b _081AEAAC
	.align 2, 0
_081AEA88: .4byte 0x030046B8
_081AEA8C: .4byte 0x000003FF
_081AEA90: .4byte 0x0203B400
_081AEA94: .4byte 0x000001DD
_081AEA98:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081AEACC @ =0x000001DD
	adds r1, r6, r3
_081AEAAC:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081AEAD4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081AEAD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081AEB42
	.align 2, 0
_081AEACC: .4byte 0x000001DD
_081AEAD0: .4byte 0x03002BE0
_081AEAD4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081AEAF0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081AEAEC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081AEB42
	.align 2, 0
_081AEAEC: .4byte 0x03002BE0
_081AEAF0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081AEB0C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081AEB08 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081AEB42
	.align 2, 0
_081AEB08: .4byte 0x03002BE0
_081AEB0C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081AEB28
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081AEB24 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081AEB42
	.align 2, 0
_081AEB24: .4byte 0x03002BE0
_081AEB28:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081AEB3A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081AEB42
_081AEB3A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081AEB44
_081AEB42:
	movs r3, #1
_081AEB44:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _081AEB78 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081AEBE0
	movs r1, #2
	ldr r2, _081AEB7C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AEB80
	movs r0, #1
	b _081AEB82
	.align 2, 0
_081AEB78: .4byte 0x0000049C
_081AEB7C: .4byte 0x00000474
_081AEB80:
	movs r0, #0
_081AEB82:
	cmp r0, #0
	beq _081AEB9C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081AEB98 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081AEBA8
	.align 2, 0
_081AEB98: .4byte 0x03002BE0
_081AEB9C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081AEBE0
_081AEBA8:
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
_081AEBE0:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081AEC14
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081AEC14
	ldr r0, _081AEC2C @ =0x0000024E
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
	bls _081AEC14
	strh r1, [r2]
_081AEC14:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081AEC30 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081AEC34 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AEC38
	movs r0, #1
	b _081AEC3A
	.align 2, 0
_081AEC2C: .4byte 0x0000024E
_081AEC30: .4byte 0x030046A0
_081AEC34: .4byte 0x00000934
_081AEC38:
	movs r0, #0
_081AEC3A:
	ldr r1, _081AEC8C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081AEC52
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081AEC52:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
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
_081AEC7C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AEC8C: .4byte 0x0000048A
