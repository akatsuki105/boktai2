	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ 通信対戦用のボク
@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081ae594
FUN_081ae594: @ 0x081AE594
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AE5C8
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081AE5C8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _081AE5D0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081AE5C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AE5D0: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081ae5d4
FUN_081ae5d4: @ 0x081AE5D4
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
	bl FUN_080e8a60
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
	bl FUN_0823785c
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
	bl FUN_08236640
	b _081AE97C
_081AE974:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_080e64e4
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

	thumb_func_start FUN_081aec90
FUN_081aec90: @ 0x081AEC90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	mov r1, sb
	ldr r0, [r1, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r1, _081AECC4 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AECC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AECCA
	.align 2, 0
_081AECC4: .4byte 0x0000046D
_081AECC8:
	movs r0, #0
_081AECCA:
	cmp r0, #0
	beq _081AED82
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, sb
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sb
	strb r0, [r2, #5]
	mov r0, sb
	movs r1, #5
	bl FUN_080ef86c
	movs r2, #4
	ldr r1, _081AED00 @ =0x0000065C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081AED04
	movs r0, #1
	b _081AED06
	.align 2, 0
_081AED00: .4byte 0x0000065C
_081AED04:
	movs r0, #0
_081AED06:
	cmp r0, #0
	beq _081AED1A
	movs r1, #0
	movs r0, #2
	strh r0, [r4, #8]
	strh r1, [r4, #0xe]
	subs r0, #7
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081AED1A:
	ldr r0, _081AED2C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AED30
	movs r0, #1
	b _081AED32
	.align 2, 0
_081AED2C: .4byte 0x030047A4
_081AED30:
	movs r0, #0
_081AED32:
	cmp r0, #0
	beq _081AED6C
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	beq _081AED82
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081AED4E
	adds r3, r0, #0
_081AED4E:
	cmp r3, #0
	blt _081AED82
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _081AED68 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	b _081AED7E
	.align 2, 0
_081AED68: .4byte 0x03002BE0
_081AED6C:
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
_081AED7E:
	str r0, [r2]
	str r1, [r2, #4]
_081AED82:
	ldrh r0, [r4, #8]
	cmp r0, #5
	beq _081AED8A
	b _081AF1A4
_081AED8A:
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _081AED92
	b _081AF1A4
_081AED92:
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	adds r1, #0xfd
	add r1, sb
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081AEDB8
	ldr r2, _081AEDB4 @ =0xFFFFFF00
	adds r1, r1, r2
	b _081AEDC6
	.align 2, 0
_081AEDB4: .4byte 0xFFFFFF00
_081AEDB8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081AEDC6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081AEDC6:
	adds r0, r1, #0
	cmp r1, #0
	bge _081AEDCE
	rsbs r0, r1, #0
_081AEDCE:
	cmp r0, #0x1f
	bgt _081AEE44
	ldr r0, _081AEDE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AEDE8
	movs r0, #1
	b _081AEDEA
	.align 2, 0
_081AEDE4: .4byte 0x030047A4
_081AEDE8:
	movs r0, #0
_081AEDEA:
	cmp r0, #0
	beq _081AEE2C
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	bne _081AEDFC
	b _081AF14A
_081AEDFC:
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081AEE08
	adds r3, r0, #0
_081AEE08:
	cmp r3, #0
	bge _081AEE0E
	b _081AF14A
_081AEE0E:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _081AEE28 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	b _081AF14A
	.align 2, 0
_081AEE28: .4byte 0x03002BE0
_081AEE2C:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	b _081AF14A
_081AEE44:
	ldr r4, _081AEE60 @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	mov r5, sb
	adds r5, #8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AEE64
	adds r0, #4
	b _081AEE70
	.align 2, 0
_081AEE60: .4byte 0x00000256
_081AEE64:
	ldr r0, _081AEE84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AEE70:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081AEE88
	cmp r3, #2
	beq _081AEE8C
	b _081AEE90
	.align 2, 0
_081AEE84: .4byte 0x030046A4
_081AEE88:
	ldrb r0, [r5, #4]
	b _081AEE8E
_081AEE8C:
	ldrb r0, [r5]
_081AEE8E:
	subs r2, r2, r0
_081AEE90:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AEEA2
	adds r0, #4
	b _081AEEAE
_081AEEA2:
	ldr r0, _081AEEC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AEEAE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081AEEC4
	asrs r0, r0, #6
	b _081AEECA
	.align 2, 0
_081AEEC0: .4byte 0x030046A4
_081AEEC4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081AEECA:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081AEF08
	cmp r1, #1
	bgt _081AEEDC
	cmp r1, #0
	beq _081AEEE6
	b _081AEFC8
_081AEEDC:
	cmp r1, #2
	beq _081AEF44
	cmp r1, #3
	beq _081AEF66
	b _081AEFC8
_081AEEE6:
	adds r4, r6, #1
	movs r5, #0
_081AEEEA:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEF04
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081AEEEA
_081AEF04:
	subs r5, r4, #1
	b _081AEFCA
_081AEF08:
	ldr r1, _081AEF40 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_081AEF16:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEFA0
	ldr r0, _081AEF40 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081AEF16
	subs r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEF40: .4byte 0x030046A4
_081AEF44:
	subs r4, r6, #1
	movs r5, #0
_081AEF48:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEF62
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081AEF48
_081AEF62:
	adds r5, r4, #1
	b _081AEFCA
_081AEF66:
	ldr r1, _081AEF9C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
_081AEF74:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEFB4
	ldr r0, _081AEF9C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081AEF74
	adds r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEF9C: .4byte 0x030046A4
_081AEFA0:
	ldr r1, _081AEFB0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEFB0: .4byte 0x030046A4
_081AEFB4:
	ldr r1, _081AEFC4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEFC4: .4byte 0x030046A4
_081AEFC8:
	ldrh r5, [r4]
_081AEFCA:
	movs r6, #0xcd
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _081AF00C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _081AF00C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AF010
	adds r0, #4
	b _081AF01C
	.align 2, 0
_081AF00C: .4byte 0x030046A4
_081AF010:
	ldr r1, _081AF03C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AF01C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r2, sb
	ldrb r0, [r2, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081AF040
	asrs r0, r0, #6
	b _081AF046
	.align 2, 0
_081AF03C: .4byte 0x030046A4
_081AF040:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081AF046:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081AF06E
	cmp r1, #1
	bgt _081AF058
	cmp r1, #0
	beq _081AF062
	b _081AF0BA
_081AF058:
	cmp r1, #2
	beq _081AF088
	cmp r1, #3
	beq _081AF0A4
	b _081AF0BA
_081AF062:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _081AF092
_081AF06E:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _081AF084 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _081AF0B8
	.align 2, 0
_081AF084: .4byte 0x0000066C
_081AF088:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_081AF092:
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0, #0xc]
	ldr r0, _081AF0A0 @ =0x0000066C
	add r0, sl
	strh r1, [r0]
	b _081AF0BA
	.align 2, 0
_081AF0A0: .4byte 0x0000066C
_081AF0A4:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _081AF0E8 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_081AF0B8:
	strh r0, [r1]
_081AF0BA:
	movs r5, #0xcd
	lsls r5, r5, #3
	add r5, sl
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AF0E4
	cmp r1, #0
	blt _081AF0E4
	ldr r0, _081AF0EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AF0E4
	ldr r0, _081AF0F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AF0F4
_081AF0E4:
	movs r4, #0
	b _081AF102
	.align 2, 0
_081AF0E8: .4byte 0x0000066C
_081AF0EC: .4byte 0x030046A8
_081AF0F0: .4byte 0x030046AC
_081AF0F4:
	ldr r0, _081AF114 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AF102:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AF118
	adds r0, #4
	b _081AF124
	.align 2, 0
_081AF114: .4byte 0x030046A4
_081AF118:
	ldr r0, _081AF138 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AF124:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AF13C
	cmp r2, #2
	beq _081AF140
	b _081AF144
	.align 2, 0
_081AF138: .4byte 0x030046A4
_081AF13C:
	ldrb r0, [r5, #4]
	b _081AF142
_081AF140:
	ldrb r0, [r5]
_081AF142:
	subs r1, r1, r0
_081AF144:
	ldr r0, _081AF1C8 @ =0x0000066A
	add r0, sl
	strh r1, [r0]
_081AF14A:
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _081AF1CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldr r0, _081AF1D0 @ =0x00000226
	add r0, sb
	ldrh r2, [r0]
	ldr r0, _081AF1D4 @ =0x0000022E
	add r0, sb
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _081AF1D8 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r0, _081AF1DC @ =0x00000674
	add r0, sl
	ldrb r0, [r0]
	str r0, [sp, #8]
	movs r0, #0x1e
	str r0, [sp, #0xc]
	subs r0, #0x32
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	bl FUN_081f3110
	movs r0, #0xd6
	bl PlaySound_082406e0
_081AF1A4:
	ldr r0, _081AF1E0 @ =0x0000046E
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _081AF1B6
	ldr r1, _081AF1E4 @ =0x0000046B
	add r1, sb
	movs r0, #1
	strb r0, [r1]
_081AF1B6:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AF1C8: .4byte 0x0000066A
_081AF1CC: .4byte 0x0000FFFF
_081AF1D0: .4byte 0x00000226
_081AF1D4: .4byte 0x0000022E
_081AF1D8: .4byte 0x00000236
_081AF1DC: .4byte 0x00000674
_081AF1E0: .4byte 0x0000046E
_081AF1E4: .4byte 0x0000046B

	thumb_func_start FUN_081af1e8
FUN_081af1e8: @ 0x081AF1E8
	push {lr}
	ldr r2, _081AF1FC @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF1F8
	movs r0, #0
	strb r0, [r1]
_081AF1F8:
	pop {r0}
	bx r0
	.align 2, 0
_081AF1FC: .4byte 0x0000046D

	thumb_func_start FUN_081af200
FUN_081af200: @ 0x081AF200
	push {lr}
	adds r2, r0, #0
	ldr r0, _081AF220 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF212
	movs r0, #0
	strb r0, [r1]
_081AF212:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081AF220: .4byte 0x0000046D

	thumb_func_start FUN_081af224
FUN_081af224: @ 0x081AF224
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	adds r3, r5, #0
	adds r3, #0x9c
	ldr r0, _081AF248 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF24C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AF24E
	.align 2, 0
_081AF248: .4byte 0x0000046D
_081AF24C:
	movs r0, #0
_081AF24E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081AF25C
	b _081AF68E
_081AF25C:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r4, _081AF2AC @ =0x0000046A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #6
	beq _081AF2B0
	cmp r0, #0x11
	beq _081AF2B0
	movs r1, #0x89
	lsls r1, r1, #7
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081AF2B0
	ldr r0, [r3, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081AF2B8
	.align 2, 0
_081AF2AC: .4byte 0x0000046A
_081AF2B0:
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r1, [r0]
_081AF2B8:
	asrs r0, r1, #1
	cmp r2, r0
	bne _081AF2FE
	ldr r1, _081AF2EC @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	subs r1, #0x6b
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF2F4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081AF2F0 @ =0x00000469
	b _081AF7DC
	.align 2, 0
_081AF2EC: .4byte 0x0000046B
_081AF2F0: .4byte 0x00000469
_081AF2F4:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _081AF860
_081AF2FE:
	cmp r2, #1
	beq _081AF3D4
	cmp r2, #1
	bgt _081AF30C
	cmp r2, #0
	beq _081AF31A
	b _081AF686
_081AF30C:
	cmp r2, #2
	bne _081AF312
	b _081AF478
_081AF312:
	cmp r2, #3
	bne _081AF318
	b _081AF564
_081AF318:
	b _081AF686
_081AF31A:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081AF36C
	movs r2, #9
	ldr r3, _081AF340 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF348
	ldr r4, _081AF344 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081AF586
	.align 2, 0
_081AF340: .4byte 0x0000025D
_081AF344: .4byte 0x000004B7
_081AF348:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xa
	ldr r1, _081AF364 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF368 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xa
	beq _081AF362
	b _081AF5C2
_081AF362:
	b _081AF5B2
	.align 2, 0
_081AF364: .4byte 0x000004B7
_081AF368: .4byte 0x0000046E
_081AF36C:
	movs r1, #9
	ldr r4, _081AF394 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF39C
	ldr r2, _081AF398 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #0
	bl FUN_08236fac
	b _081AF3C2
	.align 2, 0
_081AF394: .4byte 0x0000025D
_081AF398: .4byte 0x000004B7
_081AF39C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r3, _081AF3CC @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #9
_081AF3B2:
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF3C2:
	ldr r4, _081AF3D0 @ =0x0000046E
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	b _081AF678
	.align 2, 0
_081AF3CC: .4byte 0x000004B7
_081AF3D0: .4byte 0x0000046E
_081AF3D4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081AF428
	movs r2, #9
	ldr r1, _081AF3FC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF404
	ldr r4, _081AF400 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081AF586
	.align 2, 0
_081AF3FC: .4byte 0x0000025D
_081AF400: .4byte 0x000004B7
_081AF404:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xb
	ldr r1, _081AF420 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF424 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xb
	beq _081AF41E
	b _081AF5C2
_081AF41E:
	b _081AF5B2
	.align 2, 0
_081AF420: .4byte 0x000004B7
_081AF424: .4byte 0x0000046E
_081AF428:
	movs r1, #9
	ldr r4, _081AF450 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF458
	ldr r2, _081AF454 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	b _081AF3C2
	.align 2, 0
_081AF450: .4byte 0x0000025D
_081AF454: .4byte 0x000004B7
_081AF458:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r3, _081AF474 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	b _081AF3B2
	.align 2, 0
_081AF474: .4byte 0x000004B7
_081AF478:
	subs r0, r1, #1
	cmp r0, #4
	bls _081AF4F4
	movs r1, #9
	ldr r2, _081AF4A8 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF4B0
	ldr r3, _081AF4AC @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	b _081AF4D6
	.align 2, 0
_081AF4A8: .4byte 0x0000025D
_081AF4AC: .4byte 0x000004B7
_081AF4B0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r2, _081AF4EC @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_081AF4D6:
	ldr r3, _081AF4F0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	b _081AF5EC
	.align 2, 0
_081AF4EC: .4byte 0x000004B7
_081AF4F0: .4byte 0x0000046E
_081AF4F4:
	movs r1, #9
	ldr r2, _081AF51C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF524
	ldr r3, _081AF520 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #2
	bl FUN_08236fac
	b _081AF54C
	.align 2, 0
_081AF51C: .4byte 0x0000025D
_081AF520: .4byte 0x000004B7
_081AF524:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xb
	ldr r2, _081AF55C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xb
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF54C:
	ldr r3, _081AF560 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r5, r4
	b _081AF67E
	.align 2, 0
_081AF55C: .4byte 0x000004B7
_081AF560: .4byte 0x0000046E
_081AF564:
	cmp r1, #3
	bhi _081AF5FC
	movs r2, #9
	ldr r1, _081AF590 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF59C
	ldr r4, _081AF594 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081AF586:
	bl FUN_08236fac
	ldr r0, _081AF598 @ =0x0000046E
	adds r6, r5, r0
	b _081AF5DE
	.align 2, 0
_081AF590: .4byte 0x0000025D
_081AF594: .4byte 0x000004B7
_081AF598: .4byte 0x0000046E
_081AF59C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _081AF5F4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF5F8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #9
	bne _081AF5C2
_081AF5B2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081AF5C2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081AF5E2
_081AF5C2:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF5DE:
	movs r0, #0
	strb r0, [r6]
_081AF5E2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_081AF5EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081AF686
	.align 2, 0
_081AF5F4: .4byte 0x000004B7
_081AF5F8: .4byte 0x0000046E
_081AF5FC:
	movs r2, #9
	ldr r4, _081AF628 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF634
	ldr r1, _081AF62C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	ldr r2, _081AF630 @ =0x0000046E
	adds r6, r5, r2
	b _081AF674
	.align 2, 0
_081AF628: .4byte 0x0000025D
_081AF62C: .4byte 0x000004B7
_081AF630: .4byte 0x0000046E
_081AF634:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xa
	ldr r3, _081AF6CC @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r4, _081AF6D0 @ =0x0000046E
	adds r6, r5, r4
	cmp r1, #0xa
	bne _081AF65C
	ldrb r0, [r6]
	cmp r0, #0
	bne _081AF65C
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081AF678
_081AF65C:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081AF674:
	movs r0, #0
	strb r0, [r6]
_081AF678:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
_081AF67E:
	ldr r1, _081AF6D4 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081AF686:
	ldr r2, _081AF6D0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081AF68E:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _081AF6FC
	ldrh r0, [r1, #8]
	cmp r0, #1
	beq _081AF6A4
	cmp r0, #3
	bne _081AF6FC
_081AF6A4:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r4, r8
	ldrb r2, [r4, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _081AF6C2
	rsbs r0, r0, #0
_081AF6C2:
	cmp r0, #0x20
	bgt _081AF6D8
	mov r0, r8
	strb r1, [r0, #5]
	b _081AF6FC
	.align 2, 0
_081AF6CC: .4byte 0x000004B7
_081AF6D0: .4byte 0x0000046E
_081AF6D4: .4byte 0xFFFEFFFF
_081AF6D8:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AF6F4
	adds r0, r2, #0
	adds r0, #0x20
	mov r4, r8
	strb r0, [r4, #5]
	b _081AF6FC
_081AF6F4:
	adds r0, r2, #0
	subs r0, #0x20
	mov r1, r8
	strb r0, [r1, #5]
_081AF6FC:
	ldr r1, _081AF714 @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF71C
	ldr r3, _081AF718 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081AF72C
	.align 2, 0
_081AF714: .4byte 0x0000A02F
_081AF718: .4byte 0x00000482
_081AF71C:
	ldr r4, _081AF750 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081AF72C
	movs r0, #1
	strh r0, [r2]
_081AF72C:
	ldr r1, _081AF754 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF758
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081AF770
	.align 2, 0
_081AF750: .4byte 0x00000482
_081AF754: .4byte 0x0000025D
_081AF758:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081AF770:
	ldr r2, _081AF820 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081AF860
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081AF79A
	rsbs r1, r1, #0
_081AF79A:
	cmp r1, #0
	bgt _081AF830
	ldr r4, _081AF824 @ =0x0000046B
	adds r0, r5, r4
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF860
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
_081AF7DC:
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081AF828 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081AF82C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _081AF824 @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
	b _081AF860
	.align 2, 0
_081AF820: .4byte 0x0000046E
_081AF824: .4byte 0x0000046B
_081AF828: .4byte 0x0000046A
_081AF82C: .4byte 0x000005BC
_081AF830:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081AF870 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081AF874 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081AF860:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AF870: .4byte 0x0000046D
_081AF874: .4byte 0x0000046B

	thumb_func_start FUN_081af878
FUN_081af878: @ 0x081AF878
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081AF890 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF894
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AF896
	.align 2, 0
_081AF890: .4byte 0x0000046D
_081AF894:
	movs r0, #0
_081AF896:
	cmp r0, #0
	beq _081AF8B8
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081AF8B8
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081AF8B8:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081AF8D4
	ldr r2, _081AF920 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081AF8D4:
	ldr r1, _081AF924 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081AF91A
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081AF91A
	ldr r3, _081AF928 @ =FUN_081af934
	movs r2, #6
	ldr r0, _081AF92C @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081AF930 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081AF91A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AF920: .4byte 0x000001DF
_081AF924: .4byte 0x00000466
_081AF928: .4byte FUN_081af934
_081AF92C: .4byte 0x0000046D
_081AF930: .4byte 0x0000046B

	thumb_func_start FUN_081af934
FUN_081af934: @ 0x081AF934
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _081AF94C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF950
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AF952
	.align 2, 0
_081AF94C: .4byte 0x0000046D
_081AF950:
	movs r0, #0
_081AF952:
	cmp r0, #0
	beq _081AF96E
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081AF96E:
	cmp r5, #0x28
	bne _081AF980
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081AF980:
	ldr r1, _081AF99C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081AF996
	cmp r5, #0x78
	ble _081AF996
	ldr r0, _081AF9A0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081AF996:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AF99C: .4byte 0x0000046E
_081AF9A0: .4byte 0x0000046B

	thumb_func_start FUN_081af9a4
FUN_081af9a4: @ 0x081AF9A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081AF9BC @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081AF9C0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081AF9C2
	.align 2, 0
_081AF9BC: .4byte 0x0000046D
_081AF9C0:
	movs r0, #0
_081AF9C2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081AF9FA
	movs r2, #1
	ldr r1, _081AF9E0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF9E4
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081AF9EE
	.align 2, 0
_081AF9E0: .4byte 0x0000025D
_081AF9E4:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081AF9EE:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _081AFA42
_081AF9FA:
	cmp r1, #0x1a
	ble _081AFA3C
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	ldr r3, _081AFA30 @ =FUN_081afa4c
	movs r2, #0xd
	ldr r0, _081AFA34 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081AFA38 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	b _081AFA42
	.align 2, 0
_081AFA30: .4byte FUN_081afa4c
_081AFA34: .4byte 0x0000046D
_081AFA38: .4byte 0x0000046B
_081AFA3C:
	ldr r1, _081AFA48 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_081AFA42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AFA48: .4byte 0x0000046E

	thumb_func_start FUN_081afa4c
FUN_081afa4c: @ 0x081AFA4C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081AFA64 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AFA68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AFA6A
	.align 2, 0
_081AFA64: .4byte 0x0000046D
_081AFA68:
	movs r0, #0
_081AFA6A:
	cmp r0, #0
	beq _081AFAB6
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _081AFA90 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AFA94
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081AFAA2
	.align 2, 0
_081AFA90: .4byte 0x0000025D
_081AFA94:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081AFAA2:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x3c
	strh r0, [r1]
_081AFAB6:
	ldr r0, [r6, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne _081AFACE
	ldrh r0, [r1, #0xe]
	cmp r0, #4
	bne _081AFACE
	movs r0, #0xee
	bl PlaySound_082406e0
_081AFACE:
	ldr r1, _081AFC6C @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AFADA
	b _081AFC66
_081AFADA:
	adds r0, r6, #0
	bl enemy_boku_081b3298
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _081AFC70 @ =0x0000055C
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _081AFC74 @ =0x00000564
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #5]
	adds r2, #5
	adds r0, r6, r2
	ldrb r1, [r0]
	subs r2, #0xfd
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081AFC78 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081AFC7C @ =0x00000567
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r2, #0xfe
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _081AFC80 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081AFC84 @ =0x00000572
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0xdf
	adds r0, r6, r2
	movs r5, #0
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #0x9e
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _081AFC88 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081AFC8C @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081AFC90 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081AFC94 @ =0x00000544
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xde
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #5
	adds r0, r6, r2
	strb r5, [r0]
	adds r2, #0x3f
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081AFC98 @ =0x00000482
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r6, r1
	str r4, [r0]
	subs r2, #0x10
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x1e
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	subs r1, #0x30
	adds r0, r6, r1
	strb r5, [r0]
	subs r2, #0x35
	adds r0, r6, r2
	movs r1, #8
	bl ClearMemory
	ldr r1, _081AFC9C @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _081AFCA0 @ =0x08252254
	adds r0, r6, #0
	ldr r2, _081AFCA4 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081AFCA8 @ =0x00000541
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0xa
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080eeee0
_081AFC66:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AFC6C: .4byte 0x0000046E
_081AFC70: .4byte 0x0000055C
_081AFC74: .4byte 0x00000564
_081AFC78: .4byte 0x00000566
_081AFC7C: .4byte 0x00000567
_081AFC80: .4byte 0x0000056C
_081AFC84: .4byte 0x00000572
_081AFC88: .4byte 0x0000046B
_081AFC8C: .4byte 0x0000046C
_081AFC90: .4byte 0x0000024E
_081AFC94: .4byte 0x00000544
_081AFC98: .4byte 0x00000482
_081AFC9C: .4byte 0x00000464
_081AFCA0: .4byte 0x08252254
_081AFCA4: .4byte 0x00000982
_081AFCA8: .4byte 0x00000541

	thumb_func_start FUN_081afcac
FUN_081afcac: @ 0x081AFCAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081AFCC4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AFCC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AFCCA
	.align 2, 0
_081AFCC4: .4byte 0x0000046D
_081AFCC8:
	movs r0, #0
_081AFCCA:
	cmp r0, #0
	beq _081AFCD6
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ef86c
_081AFCD6:
	ldr r0, [r4, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #8]
	cmp r0, #7
	bne _081AFD00
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081AFD00
	cmp r2, #1
	beq _081AFD00
	movs r1, #0
	movs r0, #2
	strh r0, [r3, #8]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
_081AFD00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081afd08
FUN_081afd08: @ 0x081AFD08
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _081AFD20 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AFD24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AFD26
	.align 2, 0
_081AFD20: .4byte 0x0000046D
_081AFD24:
	movs r0, #0
_081AFD26:
	cmp r0, #0
	beq _081AFD3A
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080ef86c
	ldr r2, _081AFDE4 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_081AFD3A:
	cmp r5, #0x3c
	bgt _081AFD40
	b _081AFE8C
_081AFD40:
	ldr r3, _081AFDE4 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AFD4C
	b _081AFEAE
_081AFD4C:
	ldr r1, _081AFDE8 @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081AFDFC
	adds r3, #0x36
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _081AFDEC @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081AFDF0 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081AFDF4 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r1, _081AFDF8 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081AFEAE
	.align 2, 0
_081AFDE4: .4byte 0x0000046E
_081AFDE8: .4byte 0x0000046B
_081AFDEC: .4byte 0x0000046D
_081AFDF0: .4byte 0x0000046A
_081AFDF4: .4byte 0x00000484
_081AFDF8: .4byte 0x00000222
_081AFDFC:
	ldr r2, _081AFE78 @ =0x000004A4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081AFE7C @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r3, _081AFE80 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r7, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081AFE84 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081AFE88 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081AFEAE
	.align 2, 0
_081AFE78: .4byte 0x000004A4
_081AFE7C: .4byte 0x0000046D
_081AFE80: .4byte 0x0000046B
_081AFE84: .4byte 0x0000046A
_081AFE88: .4byte 0x00000484
_081AFE8C:
	ldr r0, [r4, #0x44]
	adds r2, r0, #0
	adds r2, #0x48
	ldrh r0, [r2, #8]
	cmp r0, #2
	bne _081AFEAE
	ldrh r1, [r2, #0xe]
	ldrb r3, [r2, #7]
	rsbs r0, r3, #0
	orrs r0, r3
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081AFEAE
	cmp r3, #1
	beq _081AFEAE
	movs r0, #0
	strh r0, [r2, #0xe]
_081AFEAE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081afeb4
FUN_081afeb4: @ 0x081AFEB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _081AFED8 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AFEDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AFEDE
	.align 2, 0
_081AFED8: .4byte 0x0000046D
_081AFEDC:
	movs r0, #0
_081AFEDE:
	cmp r0, #0
	beq _081AFEEA
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081AFEEA:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r5, r1, #0
	cmp r4, #0x11
	bgt _081AFF1E
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _081AFF1E
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081AFF1E
	cmp r2, #1
	beq _081AFF1E
	strh r4, [r3, #0xe]
_081AFF1E:
	ldr r3, _081AFFAC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AFF2C
	bl _081B083C
_081AFF2C:
	ldr r4, _081AFFB0 @ =0x0000046B
	adds r0, r7, r4
	movs r4, #0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strb r2, [r0]
	movs r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x78]
	cmp r3, #0
	beq _081AFFC4
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081AFFB4 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _081AFFB8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r7, r3
	mov r1, sl
	strb r1, [r0]
	ldr r2, _081AFFBC @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	adds r3, #1
	adds r0, r7, r3
	mov r3, sl
	strb r3, [r0]
	ldr r3, _081AFFB0 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _081AFFC0 @ =0xFFFFF67C
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081B083C
	.align 2, 0
_081AFFAC: .4byte 0x0000046E
_081AFFB0: .4byte 0x0000046B
_081AFFB4: .4byte 0x00000469
_081AFFB8: .4byte 0x0000046A
_081AFFBC: .4byte 0x00000594
_081AFFC0: .4byte 0xFFFFF67C
_081AFFC4:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081AFFD2
	b _081B05F4
_081AFFD2:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x88]
	bl FUN_080ef86c
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B00D0 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	mov r0, sl
	strb r0, [r5]
	ldr r1, _081B00D4 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r3, [sp, #0x88]
	strb r3, [r1]
	ldr r2, _081B00D8 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0x14]
	str r3, [r2]
	ldr r4, _081B00DC @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	ldr r1, _081B00E0 @ =FUN_080e6794
	movs r0, #0xe
	ldr r5, _081B00E4 @ =0x0000046D
	adds r6, r7, r5
	mov r2, sl
	strb r2, [r6]
	ldr r4, _081B00E8 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r3, [r4]
	adds r5, #0xe6
	adds r5, r5, r7
	mov ip, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r3, [r1]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B00EC @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B00F0 @ =0x00000552
	adds r0, r7, r3
	movs r4, #0xc
	strb r4, [r0]
	subs r5, #0xac
	adds r3, r7, r5
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
	str r6, [sp, #0x54]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	mov r0, ip
	str r0, [sp, #0x74]
	mov r0, sb
	str r0, [sp, #0x7c]
	mov r0, r8
	str r0, [sp, #0x80]
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B00CC
	cmp r1, #0
	blt _081B00CC
	ldr r0, _081B00F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B00CC
	ldr r0, _081B00F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B00FC
_081B00CC:
	movs r4, #0
	b _081B010A
	.align 2, 0
_081B00D0: .4byte 0x00000469
_081B00D4: .4byte 0x0000046A
_081B00D8: .4byte 0x00000484
_081B00DC: .4byte 0x0000046C
_081B00E0: .4byte FUN_080e6794
_081B00E4: .4byte 0x0000046D
_081B00E8: .4byte 0x0000046B
_081B00EC: .4byte 0x00000551
_081B00F0: .4byte 0x00000552
_081B00F4: .4byte 0x030046A8
_081B00F8: .4byte 0x030046AC
_081B00FC:
	ldr r0, _081B011C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B010A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0120
	adds r0, #4
	b _081B012C
	.align 2, 0
_081B011C: .4byte 0x030046A4
_081B0120:
	ldr r0, _081B0140 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B012C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0144
	cmp r2, #2
	beq _081B0148
	b _081B014C
	.align 2, 0
_081B0140: .4byte 0x030046A4
_081B0144:
	ldrb r0, [r5, #4]
	b _081B014A
_081B0148:
	ldrb r0, [r5]
_081B014A:
	subs r1, r1, r0
_081B014C:
	strh r1, [r5, #2]
	ldr r0, _081B0160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B0164
	movs r0, #1
	b _081B0166
	.align 2, 0
_081B0160: .4byte 0x030047A4
_081B0164:
	movs r0, #0
_081B0166:
	cmp r0, #0
	beq _081B01A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B0186
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B0182
	adds r2, r0, #0
_081B0182:
	cmp r2, #0
	bge _081B0190
_081B0186:
	ldr r2, _081B018C @ =0x000005C4
	adds r0, r7, r2
	b _081B05E2
	.align 2, 0
_081B018C: .4byte 0x000005C4
_081B0190:
	ldr r1, _081B01A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B01EC
	.align 2, 0
_081B01A0: .4byte 0x03002BE0
_081B01A4:
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
	blt _081B01D0
	cmp r1, #0
	blt _081B01D0
	ldr r0, _081B01D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B01D0
	ldr r0, _081B01D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B01DC
_081B01D0:
	movs r5, #0
	b _081B01EA
	.align 2, 0
_081B01D4: .4byte 0x030046A8
_081B01D8: .4byte 0x030046AC
_081B01DC:
	ldr r0, _081B027C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B01EA:
	movs r2, #0
_081B01EC:
	ldr r4, _081B0280 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B020C
	ldr r1, _081B0284 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B020C
	b _081B0520
_081B020C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B0220
	b _081B083C
_081B0220:
	ldr r0, _081B0288 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081B028C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r0, [sp, #0x7c]
	str r1, [r0]
	ldr r1, [sp, #0x80]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B03DA
	.align 2, 0
_081B027C: .4byte 0x030046A4
_081B0280: .4byte 0x00000256
_081B0284: .4byte 0x03002BE0
_081B0288: .4byte 0x00000222
_081B028C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	str r1, [r4]
	ldr r1, [sp, #0x80]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B02F0
	cmp r1, #0
	blt _081B02F0
	ldr r0, _081B02F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B02F0
	ldr r0, _081B02F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B02FC
_081B02F0:
	movs r4, #0
	b _081B030A
	.align 2, 0
_081B02F4: .4byte 0x030046A8
_081B02F8: .4byte 0x030046AC
_081B02FC:
	ldr r0, _081B031C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B030A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0320
	adds r0, #4
	b _081B032C
	.align 2, 0
_081B031C: .4byte 0x030046A4
_081B0320:
	ldr r0, _081B0340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B032C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0344
	cmp r2, #2
	beq _081B0348
	b _081B034C
	.align 2, 0
_081B0340: .4byte 0x030046A4
_081B0344:
	ldrb r0, [r5, #4]
	b _081B034A
_081B0348:
	ldrb r0, [r5]
_081B034A:
	subs r1, r1, r0
_081B034C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0374
	cmp r1, #0
	blt _081B0374
	ldr r0, _081B0378 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0374
	ldr r0, _081B037C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0380
_081B0374:
	movs r4, #0
	b _081B038E
	.align 2, 0
_081B0378: .4byte 0x030046A8
_081B037C: .4byte 0x030046AC
_081B0380:
	ldr r0, _081B03A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B038E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B03A4
	adds r0, #4
	b _081B03B0
	.align 2, 0
_081B03A0: .4byte 0x030046A4
_081B03A4:
	ldr r0, _081B03C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B03B0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B03C8
	cmp r3, #2
	beq _081B03CC
	b _081B03D0
	.align 2, 0
_081B03C4: .4byte 0x030046A4
_081B03C8:
	ldrb r0, [r5, #4]
	b _081B03CE
_081B03CC:
	ldrb r0, [r5]
_081B03CE:
	subs r2, r2, r0
_081B03D0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B03DA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B04E4
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0404
	movs r0, #1
	b _081B0406
_081B0404:
	movs r0, #0
_081B0406:
	ldr r3, _081B04F4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B04E4
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B04F8 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B04FC @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _081B0500 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r4, _081B0504 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _081B0508 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x60]
	ldr r0, _081B050C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x84]
	ldr r1, _081B0510 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r6, _081B0514 @ =0x0203B400
	ldr r1, _081B0518 @ =0x030046B8
	ldr r2, _081B051C @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081B0456:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081B0474
	adds r3, #1
	cmp r3, #3
	ble _081B0456
	mov r0, r8
_081B0474:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x68]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x70]
	strb r0, [r5]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x60]
	strb r1, [r0]
	ldr r1, [sp, #0x84]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	str r2, [r5]
	movs r2, #0
	ldr r0, [sp, #0x80]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x64]
	strb r0, [r4]
_081B04E4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x58]
	strh r0, [r5]
	b _081B083C
	.align 2, 0
_081B04F4: .4byte 0x00000482
_081B04F8: .4byte 0x0000054F
_081B04FC: .4byte 0x0000054C
_081B0500: .4byte 0x0000054D
_081B0504: .4byte 0x0000054E
_081B0508: .4byte 0x00000541
_081B050C: .4byte 0x000005BC
_081B0510: .4byte 0x00000542
_081B0514: .4byte 0x0203B400
_081B0518: .4byte 0x030046B8
_081B051C: .4byte 0x000003FF
_081B0520:
	mov sb, sp
	ldr r6, _081B055C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0560
	adds r0, #4
	b _081B056A
	.align 2, 0
_081B055C: .4byte 0x030046A4
_081B0560:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B056A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _081B05A4 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081B05AC
	ldr r0, _081B05A8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B05D6
	.align 2, 0
_081B05A4: .4byte 0x000004A4
_081B05A8: .4byte 0xFFFFFDFF
_081B05AC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081B05CC
	cmp r0, #2
	beq _081B05C8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B05C8:
	movs r0, #1
	b _081B05D8
_081B05CC:
	ldr r0, _081B05EC @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B05D6:
	movs r0, #0
_081B05D8:
	cmp r0, #0
	beq _081B05DE
	b _081B083C
_081B05DE:
	ldr r4, _081B05F0 @ =0x000005C4
	adds r0, r7, r4
_081B05E2:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B083C
	.align 2, 0
_081B05EC: .4byte 0xFFFFFDFF
_081B05F0: .4byte 0x000005C4
_081B05F4:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, _081B070C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x28]
	mov r3, sl
	strb r3, [r2]
	ldr r4, _081B0710 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r0, _081B0714 @ =0x00000484
	adds r0, r7, r0
	str r0, [sp, #0x30]
	str r5, [r0]
	ldr r1, _081B0718 @ =0x0000046C
	adds r1, r7, r1
	str r1, [sp, #0x34]
	strb r3, [r1]
	ldr r1, _081B071C @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _081B0720 @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _081B0724 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x38]
	strb r5, [r3]
	ldr r4, _081B0728 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x3c]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B072C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B0730 @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	subs r5, #0xd2
	adds r0, r7, r5
	mov r1, sl
	strh r1, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r4, [sp, #0x78]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r5, #0x26
	adds r0, r7, r5
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
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x44]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x48]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x50]
	ldr r4, [sp, #0x38]
	str r4, [sp, #0x4c]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x74]
	mov r3, sb
	str r3, [sp, #0x7c]
	mov r4, r8
	str r4, [sp, #0x80]
	cmp r2, #0
	blt _081B0706
	cmp r1, #0
	blt _081B0706
	ldr r0, _081B0734 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0706
	ldr r0, _081B0738 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B073C
_081B0706:
	movs r4, #0
	b _081B074A
	.align 2, 0
_081B070C: .4byte 0x00000469
_081B0710: .4byte 0x0000046A
_081B0714: .4byte 0x00000484
_081B0718: .4byte 0x0000046C
_081B071C: .4byte FUN_080e6794
_081B0720: .4byte 0x0000046D
_081B0724: .4byte 0x0000046B
_081B0728: .4byte 0x00000553
_081B072C: .4byte 0x00000551
_081B0730: .4byte 0x00000552
_081B0734: .4byte 0x030046A8
_081B0738: .4byte 0x030046AC
_081B073C:
	ldr r0, _081B075C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B074A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0760
	adds r0, #4
	b _081B076C
	.align 2, 0
_081B075C: .4byte 0x030046A4
_081B0760:
	ldr r0, _081B0780 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B076C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0784
	cmp r2, #2
	beq _081B0788
	b _081B078C
	.align 2, 0
_081B0780: .4byte 0x030046A4
_081B0784:
	ldrb r0, [r5, #4]
	b _081B078A
_081B0788:
	ldrb r0, [r5]
_081B078A:
	subs r1, r1, r0
_081B078C:
	strh r1, [r5, #2]
	ldr r5, _081B07BC @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B07C4
	ldr r0, _081B07C0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B07EE
	.align 2, 0
_081B07BC: .4byte 0x000004A4
_081B07C0: .4byte 0xFFFFFDFF
_081B07C4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B07E4
	cmp r0, #2
	beq _081B07E0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B07E0:
	movs r0, #1
	b _081B07F0
_081B07E4:
	ldr r0, _081B0828 @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B07EE:
	movs r0, #0
_081B07F0:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B0830
	ldr r0, _081B082C @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r1, [sp, #0x74]
	strb r3, [r1]
	ldr r4, [sp, #0x7c]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x80]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081B083C
	.align 2, 0
_081B0828: .4byte 0xFFFFFDFF
_081B082C: .4byte FUN_080e48d0
_081B0830:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B083C:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b084c
FUN_081b084c: @ 0x081B084C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd0
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081B0874 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B0878
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B087A
	.align 2, 0
_081B0874: .4byte 0x0000046D
_081B0878:
	movs r0, #0
_081B087A:
	cmp r0, #0
	beq _081B08B6
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B08A4
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B08A4:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	ldr r3, _081B0988 @ =0x0000046E
	adds r0, r7, r3
	strb r1, [r0]
_081B08B6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	mov sb, r2
	cmp r6, #0x11
	bgt _081B08F6
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _081B08F6
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B08F6
	cmp r2, #1
	beq _081B08F6
	strh r3, [r5, #0xe]
_081B08F6:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B0968
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B0968
	ldr r2, _081B098C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B0990 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _081B0994 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B0998 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B099C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl FUN_080ddcc8
_081B0968:
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081B09A0
	asrs r0, r0, #2
	b _081B09A6
	.align 2, 0
_081B0988: .4byte 0x0000046E
_081B098C: .4byte 0xFFFF0000
_081B0990: .4byte 0x0000FFFF
_081B0994: .4byte 0x030046B8
_081B0998: .4byte 0x000003FF
_081B099C: .4byte 0x0203B400
_081B09A0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B09A6:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081B09C6
	asrs r0, r0, #2
	b _081B09CC
_081B09C6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B09CC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081B09D6
	movs r3, #0xc8
	b _081B09E0
_081B09D6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081B09E0
	adds r3, r0, #0
_081B09E0:
	cmp r2, #0xc8
	ble _081B09E8
	movs r2, #0xc8
	b _081B09F2
_081B09E8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081B09F2
	adds r2, r0, #0
_081B09F2:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081B0A16
	cmp r2, #0
	bne _081B0A16
	movs r0, #1
	b _081B0A18
_081B0A16:
	movs r0, #0
_081B0A18:
	cmp r0, #0
	bne _081B0A20
	bl _081B1958
_081B0A20:
	ldr r6, _081B0A7C @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B0A2E
	bl _081B1958
_081B0A2E:
	ldr r1, _081B0A80 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _081B0A84 @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	mov r5, sb
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r3, [r5]
	ands r3, r0
	str r3, [r5]
	ldr r1, _081B0A88 @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	str r2, [sp, #0xa8]
	cmp r4, #0
	beq _081B0A8C
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081B1958
	.align 2, 0
_081B0A7C: .4byte 0x0000046E
_081B0A80: .4byte 0x0000046B
_081B0A84: .4byte 0xFFFFFEDF
_081B0A88: .4byte 0x0000049C
_081B0A8C:
	movs r0, #8
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0B18
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _081B0AFC @ =0x00000469
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _081B0B00 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _081B0B04 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	mov r5, r8
	strb r5, [r0]
	ldr r2, _081B0B08 @ =FUN_081afeb4
	movs r1, #0x14
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _081B0B0C @ =0x0000046B
	adds r0, r7, r5
	strb r6, [r0]
	ldr r6, _081B0B10 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _081B0B14 @ =0x00000482
	adds r0, r7, r4
	mov r5, r8
	strh r5, [r0]
	bl _081B1958
	.align 2, 0
_081B0AFC: .4byte 0x00000469
_081B0B00: .4byte 0x0000046A
_081B0B04: .4byte 0x00000484
_081B0B08: .4byte FUN_081afeb4
_081B0B0C: .4byte 0x0000046B
_081B0B10: .4byte 0x00000553
_081B0B14: .4byte 0x00000482
_081B0B18:
	movs r2, #0x80
	ands r1, r2
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081B0B26
	b _081B123C
_081B0B26:
	orrs r3, r2
	str r3, [r5]
	movs r0, #4
	ldr r6, _081B0B88 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081B0B8C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xc0]
	str r4, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _081B0B82
	cmp r1, #0
	blt _081B0B82
	ldr r0, _081B0B90 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081B0B82
	ldr r0, _081B0B94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0B98
_081B0B82:
	movs r4, #0
	b _081B0BA6
	.align 2, 0
_081B0B88: .4byte 0x00000222
_081B0B8C: .4byte 0x03002BE0
_081B0B90: .4byte 0x030046A8
_081B0B94: .4byte 0x030046AC
_081B0B98:
	ldr r0, _081B0BB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081B0BA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0BBC
	adds r0, #4
	b _081B0BC8
	.align 2, 0
_081B0BB8: .4byte 0x030046A4
_081B0BBC:
	ldr r0, _081B0BDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0BC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0BE0
	cmp r2, #2
	beq _081B0BE4
	b _081B0BE8
	.align 2, 0
_081B0BDC: .4byte 0x030046A4
_081B0BE0:
	ldrb r0, [r6, #4]
	b _081B0BE6
_081B0BE4:
	ldrb r0, [r6]
_081B0BE6:
	subs r1, r1, r0
_081B0BE8:
	strh r1, [r6, #2]
	ldr r0, _081B0BFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B0C00
	movs r0, #1
	b _081B0C02
	.align 2, 0
_081B0BFC: .4byte 0x030047A4
_081B0C00:
	movs r0, #0
_081B0C02:
	cmp r0, #0
	beq _081B0C38
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B0C14
	b _081B1148
_081B0C14:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B0C20
	adds r2, r0, #0
_081B0C20:
	cmp r2, #0
	bge _081B0C26
	b _081B1148
_081B0C26:
	ldr r1, _081B0C34 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B0C80
	.align 2, 0
_081B0C34: .4byte 0x03002BE0
_081B0C38:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0C64
	cmp r1, #0
	blt _081B0C64
	ldr r0, _081B0C68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0C64
	ldr r0, _081B0C6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0C70
_081B0C64:
	movs r5, #0
	b _081B0C7E
	.align 2, 0
_081B0C68: .4byte 0x030046A8
_081B0C6C: .4byte 0x030046AC
_081B0C70:
	ldr r0, _081B0CB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B0C7E:
	movs r2, #0
_081B0C80:
	ldr r6, _081B0CBC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B0CA0
	ldr r1, _081B0CC0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B0CA0
	b _081B1088
_081B0CA0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081B0CC4
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B0CB8: .4byte 0x030046A4
_081B0CBC: .4byte 0x00000256
_081B0CC0: .4byte 0x03002BE0
_081B0CC4:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xc0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081B0D7C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B0D64 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x28]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B0D68 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B0D6C @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x34]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	mov r1, sb
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B0D70 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B0D74 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _081B0D78 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x28]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x34]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B0F46
	.align 2, 0
_081B0D64: .4byte 0x0000046D
_081B0D68: .4byte 0x0000046B
_081B0D6C: .4byte 0x00000553
_081B0D70: .4byte 0x00000469
_081B0D74: .4byte 0x00000484
_081B0D78: .4byte 0x0000046C
_081B0D7C:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B0E3C @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B0E40 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x38]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x44]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081B0E44 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _081B0E48 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081B0E4C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x4c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x4c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x40]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x44]
	str r4, [sp, #0xac]
	mov r5, ip
	cmp r5, #0
	blt _081B0E38
	cmp r1, #0
	blt _081B0E38
	ldr r0, _081B0E50 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081B0E38
	ldr r0, _081B0E54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0E58
_081B0E38:
	movs r4, #0
	b _081B0E68
	.align 2, 0
_081B0E3C: .4byte 0x0000046D
_081B0E40: .4byte 0x0000046B
_081B0E44: .4byte 0x00000469
_081B0E48: .4byte 0x0000046A
_081B0E4C: .4byte 0x00000484
_081B0E50: .4byte 0x030046A8
_081B0E54: .4byte 0x030046AC
_081B0E58:
	ldr r0, _081B0E78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_081B0E68:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0E7C
	adds r0, #4
	b _081B0E88
	.align 2, 0
_081B0E78: .4byte 0x030046A4
_081B0E7C:
	ldr r0, _081B0E9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0E88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0EA0
	cmp r2, #2
	beq _081B0EA6
	b _081B0EAC
	.align 2, 0
_081B0E9C: .4byte 0x030046A4
_081B0EA0:
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2, #4]
	b _081B0EAA
_081B0EA6:
	ldr r3, [sp, #0x4c]
	ldrb r0, [r3]
_081B0EAA:
	subs r1, r1, r0
_081B0EAC:
	ldr r4, [sp, #0x4c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0ED8
	cmp r1, #0
	blt _081B0ED8
	ldr r0, _081B0EDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0ED8
	ldr r0, _081B0EE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0EE4
_081B0ED8:
	movs r4, #0
	b _081B0EF2
	.align 2, 0
_081B0EDC: .4byte 0x030046A8
_081B0EE0: .4byte 0x030046AC
_081B0EE4:
	ldr r0, _081B0F08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B0EF2:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B0F0C
	adds r0, #4
	b _081B0F18
	.align 2, 0
_081B0F08: .4byte 0x030046A4
_081B0F0C:
	ldr r0, _081B0F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0F18:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B0F30
	cmp r3, #2
	beq _081B0F34
	b _081B0F38
	.align 2, 0
_081B0F2C: .4byte 0x030046A4
_081B0F30:
	ldrb r0, [r5, #4]
	b _081B0F36
_081B0F34:
	ldrb r0, [r5]
_081B0F36:
	subs r2, r2, r0
_081B0F38:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B0F46:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x50]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B0F70 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B1050
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0F74
	movs r0, #1
	b _081B0F76
	.align 2, 0
_081B0F70: .4byte 0x00000482
_081B0F74:
	movs r0, #0
_081B0F76:
	ldr r3, _081B1060 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B1050
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B1064 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B1068 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B106C @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B1070 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B1074 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B1078 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B107C @ =0x030046B8
	adds r2, r5, #0
_081B0FBE:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B1080 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B1084 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B0FE2
	adds r3, #1
	cmp r3, #3
	ble _081B0FBE
	adds r0, r5, #0
_081B0FE2:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x50
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B1050:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B1060: .4byte 0x00000482
_081B1064: .4byte 0x0000054F
_081B1068: .4byte 0x0000054C
_081B106C: .4byte 0x0000054E
_081B1070: .4byte 0x00000541
_081B1074: .4byte 0x000005BC
_081B1078: .4byte 0x00000542
_081B107C: .4byte 0x030046B8
_081B1080: .4byte 0x000003FF
_081B1084: .4byte 0x0203B400
_081B1088:
	add r6, sp, #0x18
	ldr r0, _081B10C8 @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B10CC
	adds r0, #4
	b _081B10D8
	.align 2, 0
_081B10C8: .4byte 0x030046A4
_081B10CC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B10D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B1110 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B1118
	ldr r0, _081B1114 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B1142
	.align 2, 0
_081B1110: .4byte 0x000004A4
_081B1114: .4byte 0xFFFFFDFF
_081B1118:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B1138
	cmp r0, #2
	beq _081B1134
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B1134:
	movs r0, #1
	b _081B1144
_081B1138:
	ldr r0, _081B1158 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B1142:
	movs r0, #0
_081B1144:
	cmp r0, #0
	bne _081B1160
_081B1148:
	ldr r3, _081B115C @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B1158: .4byte 0xFFFFFDFF
_081B115C: .4byte 0x000005C4
_081B1160:
	movs r0, #1
_081B1162:
	cmp r0, #0
	bne _081B11D2
	ldr r4, _081B1198 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B11A0
	ldr r0, _081B119C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B11CA
	.align 2, 0
_081B1198: .4byte 0x000004A4
_081B119C: .4byte 0xFFFFFDFF
_081B11A0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B11C0
	cmp r0, #2
	beq _081B11BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B11BC:
	movs r0, #1
	b _081B11CC
_081B11C0:
	ldr r0, _081B1228 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B11CA:
	movs r0, #0
_081B11CC:
	cmp r0, #0
	bne _081B11D2
	b _081B18E8
_081B11D2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081B122C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081B1230 @ =0x0000046B
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
	ldr r1, _081B1234 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B1238 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081B1958
	.align 2, 0
_081B1228: .4byte 0xFFFFFDFF
_081B122C: .4byte 0x0000046D
_081B1230: .4byte 0x0000046B
_081B1234: .4byte 0x0000046A
_081B1238: .4byte 0x00000484
_081B123C:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081B1298 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #0x10
	orrs r3, r0
	mov r0, sb
	str r3, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _081B1294
	cmp r1, #0
	blt _081B1294
	ldr r0, _081B129C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081B1294
	ldr r0, _081B12A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B12A4
_081B1294:
	movs r4, #0
	b _081B12B2
	.align 2, 0
_081B1298: .4byte 0x03002BE0
_081B129C: .4byte 0x030046A8
_081B12A0: .4byte 0x030046AC
_081B12A4:
	ldr r0, _081B12C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081B12B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B12C8
	adds r0, #4
	b _081B12D4
	.align 2, 0
_081B12C4: .4byte 0x030046A4
_081B12C8:
	ldr r0, _081B12E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B12D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B12EC
	cmp r2, #2
	beq _081B12F0
	b _081B12F4
	.align 2, 0
_081B12E8: .4byte 0x030046A4
_081B12EC:
	ldrb r0, [r6, #4]
	b _081B12F2
_081B12F0:
	ldrb r0, [r6]
_081B12F2:
	subs r1, r1, r0
_081B12F4:
	strh r1, [r6, #2]
	ldr r0, _081B1308 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B130C
	movs r0, #1
	b _081B130E
	.align 2, 0
_081B1308: .4byte 0x030047A4
_081B130C:
	movs r0, #0
_081B130E:
	cmp r0, #0
	beq _081B1344
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B1320
	b _081B1860
_081B1320:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B132C
	adds r2, r0, #0
_081B132C:
	cmp r2, #0
	bge _081B1332
	b _081B1860
_081B1332:
	ldr r1, _081B1340 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B138C
	.align 2, 0
_081B1340: .4byte 0x03002BE0
_081B1344:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B1370
	cmp r1, #0
	blt _081B1370
	ldr r0, _081B1374 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B1370
	ldr r0, _081B1378 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B137C
_081B1370:
	movs r5, #0
	b _081B138A
	.align 2, 0
_081B1374: .4byte 0x030046A8
_081B1378: .4byte 0x030046AC
_081B137C:
	ldr r0, _081B13C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B138A:
	movs r2, #0
_081B138C:
	ldr r6, _081B13C8 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B13AC
	ldr r1, _081B13CC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B13AC
	b _081B17A0
_081B13AC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081B13D0
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B13C4: .4byte 0x030046A4
_081B13C8: .4byte 0x00000256
_081B13CC: .4byte 0x03002BE0
_081B13D0:
	ldr r3, _081B1474 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xc0]
	cmp r6, #0
	beq _081B1490
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B1478 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B147C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B1480 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x60]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x64]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B1484 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B1488 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081B148C @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x58]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x64]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B165E
	.align 2, 0
_081B1474: .4byte 0x00000222
_081B1478: .4byte 0x0000046D
_081B147C: .4byte 0x0000046B
_081B1480: .4byte 0x00000553
_081B1484: .4byte 0x00000469
_081B1488: .4byte 0x00000484
_081B148C: .4byte 0x0000046C
_081B1490:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B1550 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B1554 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B1558 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081B155C @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B1560 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B1564 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0xac]
	mov r5, sl
	cmp r5, #0
	blt _081B154C
	cmp r1, #0
	blt _081B154C
	ldr r0, _081B1568 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081B154C
	ldr r0, _081B156C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B1570
_081B154C:
	movs r4, #0
	b _081B1580
	.align 2, 0
_081B1550: .4byte 0x0000046D
_081B1554: .4byte 0x0000046B
_081B1558: .4byte 0x00000469
_081B155C: .4byte 0x0000046A
_081B1560: .4byte 0x00000484
_081B1564: .4byte 0x0000046C
_081B1568: .4byte 0x030046A8
_081B156C: .4byte 0x030046AC
_081B1570:
	ldr r0, _081B1590 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081B1580:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B1594
	adds r0, #4
	b _081B15A0
	.align 2, 0
_081B1590: .4byte 0x030046A4
_081B1594:
	ldr r0, _081B15B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B15A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B15B8
	cmp r2, #2
	beq _081B15BE
	b _081B15C4
	.align 2, 0
_081B15B4: .4byte 0x030046A4
_081B15B8:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081B15C2
_081B15BE:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081B15C2:
	subs r1, r1, r0
_081B15C4:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B15F0
	cmp r1, #0
	blt _081B15F0
	ldr r0, _081B15F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B15F0
	ldr r0, _081B15F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B15FC
_081B15F0:
	movs r4, #0
	b _081B160A
	.align 2, 0
_081B15F4: .4byte 0x030046A8
_081B15F8: .4byte 0x030046AC
_081B15FC:
	ldr r0, _081B1620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B160A:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B1624
	adds r0, #4
	b _081B1630
	.align 2, 0
_081B1620: .4byte 0x030046A4
_081B1624:
	ldr r0, _081B1644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B1630:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B1648
	cmp r3, #2
	beq _081B164C
	b _081B1650
	.align 2, 0
_081B1644: .4byte 0x030046A4
_081B1648:
	ldrb r0, [r5, #4]
	b _081B164E
_081B164C:
	ldrb r0, [r5]
_081B164E:
	subs r2, r2, r0
_081B1650:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B165E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B1688 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B1768
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B168C
	movs r0, #1
	b _081B168E
	.align 2, 0
_081B1688: .4byte 0x00000482
_081B168C:
	movs r0, #0
_081B168E:
	ldr r3, _081B1778 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B1768
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B177C @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B1780 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B1784 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B1788 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B178C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B1790 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B1794 @ =0x030046B8
	adds r2, r5, #0
_081B16D6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B1798 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B179C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B16FA
	adds r3, #1
	cmp r3, #3
	ble _081B16D6
	adds r0, r5, #0
_081B16FA:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B1768:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B1778: .4byte 0x00000482
_081B177C: .4byte 0x0000054F
_081B1780: .4byte 0x0000054C
_081B1784: .4byte 0x0000054E
_081B1788: .4byte 0x00000541
_081B178C: .4byte 0x000005BC
_081B1790: .4byte 0x00000542
_081B1794: .4byte 0x030046B8
_081B1798: .4byte 0x000003FF
_081B179C: .4byte 0x0203B400
_081B17A0:
	add r6, sp, #0x20
	ldr r0, _081B17E0 @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B17E4
	adds r0, #4
	b _081B17F0
	.align 2, 0
_081B17E0: .4byte 0x030046A4
_081B17E4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B17F0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B1828 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B1830
	ldr r0, _081B182C @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B185A
	.align 2, 0
_081B1828: .4byte 0x000004A4
_081B182C: .4byte 0xFFFFFDFF
_081B1830:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B1850
	cmp r0, #2
	beq _081B184C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B184C:
	movs r0, #1
	b _081B185C
_081B1850:
	ldr r0, _081B1870 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B185A:
	movs r0, #0
_081B185C:
	cmp r0, #0
	bne _081B1878
_081B1860:
	ldr r3, _081B1874 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B1870: .4byte 0xFFFFFDFF
_081B1874: .4byte 0x000005C4
_081B1878:
	movs r0, #1
_081B187A:
	cmp r0, #0
	bne _081B1900
	ldr r4, _081B18B0 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B18B8
	ldr r0, _081B18B4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B18E2
	.align 2, 0
_081B18B0: .4byte 0x000004A4
_081B18B4: .4byte 0xFFFFFDFF
_081B18B8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B18D8
	cmp r0, #2
	beq _081B18D4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B18D4:
	movs r0, #1
	b _081B18E4
_081B18D8:
	ldr r0, _081B18F8 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B18E2:
	movs r0, #0
_081B18E4:
	cmp r0, #0
	bne _081B1900
_081B18E8:
	ldr r4, _081B18FC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B1958
	.align 2, 0
_081B18F8: .4byte 0xFFFFFDFF
_081B18FC: .4byte 0x000005C4
_081B1900:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B1968 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B196C @ =0x0000046B
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
	ldr r6, _081B1970 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B1974 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B1978 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B1958:
	add sp, #0xd0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B1968: .4byte 0x0000046D
_081B196C: .4byte 0x0000046B
_081B1970: .4byte 0x00000469
_081B1974: .4byte 0x0000046A
_081B1978: .4byte 0x00000484

	thumb_func_start FUN_081b197c
FUN_081b197c: @ 0x081B197C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r5, _081B199C @ =0x0000046D
	adds r2, r4, r5
	ldrb r0, [r2]
	cmp r0, #0
	beq _081B19A0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081B19A2
	.align 2, 0
_081B199C: .4byte 0x0000046D
_081B19A0:
	movs r0, #0
_081B19A2:
	cmp r0, #0
	bne _081B1A2C
	movs r2, #2
	ldr r0, _081B19BC @ =0x0000065C
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081B19C0
	movs r0, #1
	b _081B19C2
	.align 2, 0
_081B19BC: .4byte 0x0000065C
_081B19C0:
	movs r0, #0
_081B19C2:
	cmp r0, #0
	beq _081B1A24
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _081B1A18 @ =0x0000FFFF
	cmp r1, r0
	bls _081B19DC
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_081B19DC:
	adds r0, r4, #0
	bl FUN_081b3568
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r0, [r5]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r5]
	movs r1, #0xf
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _081B1A1C @ =0x0000046A
	adds r0, r4, r2
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	ldr r0, _081B1A20 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _081B1A2C
	.align 2, 0
_081B1A18: .4byte 0x0000FFFF
_081B1A1C: .4byte 0x0000046A
_081B1A20: .4byte 0x0000046C
_081B1A24:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
_081B1A2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081b1a34
FUN_081b1a34: @ 0x081B1A34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	str r0, [sp, #0x48]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081B1A60 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B1A64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B1A66
	.align 2, 0
_081B1A60: .4byte 0x0000046D
_081B1A64:
	movs r0, #0
_081B1A66:
	cmp r0, #0
	beq _081B1AFE
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r4, _081B1B90 @ =0x0000046E
	adds r0, r7, r4
	movs r4, #0
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r1, [sp, #0x48]
	ldr r0, [r1]
	movs r1, #2
	orrs r0, r1
	ldr r2, [sp, #0x48]
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_080e8360
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B1AD0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B1AD0:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _081B1B94 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081B1B98 @ =0x0000021E
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	subs r1, #0x1c
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081B1AFE:
	adds r0, r7, #0
	bl FUN_080e499c
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B1B74
	movs r5, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _081B1B74
	ldr r3, _081B1B9C @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B1BA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x30]
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _081B1BA4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081B1BA8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _081B1BAC @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_080ddcc8
_081B1B74:
	cmp r6, #0x22
	bgt _081B1B7E
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0xe]
_081B1B7E:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #2
	bhi _081B1BB0
	movs r0, #0x46
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	b _081B1BB8
	.align 2, 0
_081B1B90: .4byte 0x0000046E
_081B1B94: .4byte 0xFFFEBE3F
_081B1B98: .4byte 0x0000021E
_081B1B9C: .4byte 0xFFFF0000
_081B1BA0: .4byte 0x0000FFFF
_081B1BA4: .4byte 0x030046B8
_081B1BA8: .4byte 0x000003FF
_081B1BAC: .4byte 0x0203B400
_081B1BB0:
	movs r0, #0x40
	ldr r4, [sp, #0x48]
	strb r0, [r4, #8]
	strb r0, [r4, #9]
_081B1BB8:
	ldr r6, _081B1DF0 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B1BC4
	b _081B1E9E
_081B1BC4:
	ldr r1, _081B1DF4 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	subs r1, #0x6b
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	ldr r6, _081B1DF8 @ =0x000001DF
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	cmp r0, #0
	beq _081B1BE4
	b _081B1D66
_081B1BE4:
	adds r0, r7, #0
	bl FUN_080e6658
	ldr r2, _081B1DFC @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081B1E00 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r5, sp, #0x38
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _081B1E04 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r6, #3
	ands r1, r6
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r2, #0x14
	mov r8, r2
	str r2, [sp, #4]
	movs r0, #2
	mov sl, r0
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r4, #3
	ands r1, r4
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r4, sl
	str r4, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	cmp r0, #4
	beq _081B1D60
	cmp r0, #1
	beq _081B1D60
	cmp r0, #5
	beq _081B1D60
	cmp r0, #7
	beq _081B1D60
	cmp r0, #6
	beq _081B1D60
	cmp r0, #0x18
	bne _081B1D66
_081B1D60:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081B1D66:
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081B1DC8
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r4, #0xc
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x18]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r4, #0xd2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r6, #0x94
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _081B1DFC @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x40
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081B1DC8:
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081B1E14
	ldr r0, _081B1E10 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _081B1E26
	.align 2, 0
_081B1DF0: .4byte 0x0000046E
_081B1DF4: .4byte 0x0000046B
_081B1DF8: .4byte 0x000001DF
_081B1DFC: .4byte 0xFFFF0000
_081B1E00: .4byte 0x0000FFFF
_081B1E04: .4byte 0x030046B8
_081B1E08: .4byte 0x000003FF
_081B1E0C: .4byte 0x0203B400
_081B1E10: .4byte 0x030046A0
_081B1E14:
	ldr r0, _081B1EB0 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_081B1E26:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	movs r0, #0x40
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _081B1EB4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _081B1EB8 @ =0x0000046D
	adds r0, r7, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r4, _081B1EBC @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _081B1EC0 @ =0x00000484
	adds r0, r7, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r7, r6
	bl FUN_080136b4
_081B1E9E:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B1EB0: .4byte 0x030046A0
_081B1EB4: .4byte FUN_080e48d0
_081B1EB8: .4byte 0x0000046D
_081B1EBC: .4byte 0x00000469
_081B1EC0: .4byte 0x00000484

	thumb_func_start FUN_081b1ec4
FUN_081b1ec4: @ 0x081B1EC4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081B1EE4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B1EE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B1EEA
	.align 2, 0
_081B1EE4: .4byte 0x0000046C
_081B1EE8:
	movs r0, #0
_081B1EEA:
	cmp r0, #0
	beq _081B1F68
	ldr r4, _081B1F88 @ =FUN_080f3cdc
	movs r3, #0xa
	ldr r0, _081B1F8C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B1F90 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _081B1F94 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081B1F4C
	movs r0, #4
	ldr r1, _081B1F98 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081B1F4C:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_081B1F68:
	ldr r1, _081B1F90 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081B1FA0
	adds r0, r5, #0
	bl FUN_081b2e3c
	movs r0, #4
	ldr r1, _081B1F9C @ =0x0000065C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B1FAA
	.align 2, 0
_081B1F88: .4byte FUN_080f3cdc
_081B1F8C: .4byte 0x0000046D
_081B1F90: .4byte 0x0000046B
_081B1F94: .4byte 0x000001DF
_081B1F98: .4byte 0x00000222
_081B1F9C: .4byte 0x0000065C
_081B1FA0:
	ldr r2, _081B1FB0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B1FAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B1FB0: .4byte 0x00000484

	thumb_func_start FUN_081b1fb4
FUN_081b1fb4: @ 0x081B1FB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _081B2118 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B1FD0
	movs r0, #0
	strb r0, [r1]
_081B1FD0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B1FE8
	bl _081B280C
_081B1FE8:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081B1FFA
	bl _081B280C
_081B1FFA:
	ldr r2, _081B211C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081B2008
	bl FUN_081b2808
_081B2008:
	ldr r3, _081B2120 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B2124 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081B2128 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081B211C @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081B2118 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _081B212C @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _081B2130 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _081B2134 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _081B2138 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x50]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x5c]
	mov r0, sb
	str r0, [sp, #0x54]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x34]
	str r3, [sp, #0x30]
	mov sl, r2
	cmp r1, #0
	bne _081B20A6
	b _081B2640
_081B20A6:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B213C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B2112
	cmp r1, #0
	blt _081B2112
	ldr r0, _081B2140 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B2112
	ldr r0, _081B2144 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2148
_081B2112:
	movs r4, #0
	b _081B2156
	.align 2, 0
_081B2118: .4byte 0x0000046C
_081B211C: .4byte 0x00000484
_081B2120: .4byte 0x000001DF
_081B2124: .4byte 0x00000469
_081B2128: .4byte 0x0000046A
_081B212C: .4byte FUN_080e6794
_081B2130: .4byte 0x0000046D
_081B2134: .4byte 0x0000046B
_081B2138: .4byte 0x00000553
_081B213C: .4byte 0x00000551
_081B2140: .4byte 0x030046A8
_081B2144: .4byte 0x030046AC
_081B2148:
	ldr r0, _081B2168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B2156:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B216C
	adds r0, #4
	b _081B2178
	.align 2, 0
_081B2168: .4byte 0x030046A4
_081B216C:
	ldr r0, _081B218C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B2178:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2190
	cmp r2, #2
	beq _081B2194
	b _081B2198
	.align 2, 0
_081B218C: .4byte 0x030046A4
_081B2190:
	ldrb r0, [r5, #4]
	b _081B2196
_081B2194:
	ldrb r0, [r5]
_081B2196:
	subs r1, r1, r0
_081B2198:
	strh r1, [r5, #2]
	ldr r0, _081B21AC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B21B0
	movs r0, #1
	b _081B21B2
	.align 2, 0
_081B21AC: .4byte 0x030047A4
_081B21B0:
	movs r0, #0
_081B21B2:
	cmp r0, #0
	beq _081B21F0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B21D2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B21CE
	adds r2, r0, #0
_081B21CE:
	cmp r2, #0
	bge _081B21DC
_081B21D2:
	ldr r2, _081B21D8 @ =0x000005C4
	adds r0, r7, r2
	b _081B262E
	.align 2, 0
_081B21D8: .4byte 0x000005C4
_081B21DC:
	ldr r1, _081B21EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B2238
	.align 2, 0
_081B21EC: .4byte 0x03002BE0
_081B21F0:
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
	blt _081B221C
	cmp r1, #0
	blt _081B221C
	ldr r0, _081B2220 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B221C
	ldr r0, _081B2224 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2228
_081B221C:
	movs r5, #0
	b _081B2236
	.align 2, 0
_081B2220: .4byte 0x030046A8
_081B2224: .4byte 0x030046AC
_081B2228:
	ldr r0, _081B22C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B2236:
	movs r2, #0
_081B2238:
	ldr r4, _081B22CC @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B2258
	ldr r1, _081B22D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B2258
	b _081B256C
_081B2258:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B226C
	b _081B280C
_081B226C:
	ldr r0, _081B22D4 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x38]
	cmp r3, #0
	beq _081B22D8
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r1, [r0]
	ldr r1, [sp, #0x30]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B2426
	.align 2, 0
_081B22C8: .4byte 0x030046A4
_081B22CC: .4byte 0x00000256
_081B22D0: .4byte 0x03002BE0
_081B22D4: .4byte 0x00000222
_081B22D8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B233C
	cmp r1, #0
	blt _081B233C
	ldr r0, _081B2340 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B233C
	ldr r0, _081B2344 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2348
_081B233C:
	movs r4, #0
	b _081B2356
	.align 2, 0
_081B2340: .4byte 0x030046A8
_081B2344: .4byte 0x030046AC
_081B2348:
	ldr r0, _081B2368 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B2356:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B236C
	adds r0, #4
	b _081B2378
	.align 2, 0
_081B2368: .4byte 0x030046A4
_081B236C:
	ldr r0, _081B238C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B2378:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2390
	cmp r2, #2
	beq _081B2394
	b _081B2398
	.align 2, 0
_081B238C: .4byte 0x030046A4
_081B2390:
	ldrb r0, [r5, #4]
	b _081B2396
_081B2394:
	ldrb r0, [r5]
_081B2396:
	subs r1, r1, r0
_081B2398:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B23C0
	cmp r1, #0
	blt _081B23C0
	ldr r0, _081B23C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B23C0
	ldr r0, _081B23C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B23CC
_081B23C0:
	movs r4, #0
	b _081B23DA
	.align 2, 0
_081B23C4: .4byte 0x030046A8
_081B23C8: .4byte 0x030046AC
_081B23CC:
	ldr r0, _081B23EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B23DA:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B23F0
	adds r0, #4
	b _081B23FC
	.align 2, 0
_081B23EC: .4byte 0x030046A4
_081B23F0:
	ldr r0, _081B2410 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B23FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B2414
	cmp r3, #2
	beq _081B2418
	b _081B241C
	.align 2, 0
_081B2410: .4byte 0x030046A4
_081B2414:
	ldrb r0, [r5, #4]
	b _081B241A
_081B2418:
	ldrb r0, [r5]
_081B241A:
	subs r2, r2, r0
_081B241C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B2426:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B2530
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B2450
	movs r0, #1
	b _081B2452
_081B2450:
	movs r0, #0
_081B2452:
	ldr r3, _081B2540 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B2530
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B2544 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B2548 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _081B254C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _081B2550 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _081B2554 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x18]
	ldr r0, _081B2558 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081B255C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x1c]
	ldr r6, _081B2560 @ =0x0203B400
	ldr r1, _081B2564 @ =0x030046B8
	ldr r5, _081B2568 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_081B24A2:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081B24C0
	adds r3, #1
	cmp r3, #3
	ble _081B24A2
	mov r0, sb
_081B24C0:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x18]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r2, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_081B2530:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x58]
	strh r0, [r2]
	b _081B280C
	.align 2, 0
_081B2540: .4byte 0x00000482
_081B2544: .4byte 0x0000054F
_081B2548: .4byte 0x0000054C
_081B254C: .4byte 0x0000054D
_081B2550: .4byte 0x0000054E
_081B2554: .4byte 0x00000541
_081B2558: .4byte 0x000005BC
_081B255C: .4byte 0x00000542
_081B2560: .4byte 0x0203B400
_081B2564: .4byte 0x030046B8
_081B2568: .4byte 0x000003FF
_081B256C:
	mov sb, sp
	ldr r6, _081B25A8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B25AC
	adds r0, #4
	b _081B25B6
	.align 2, 0
_081B25A8: .4byte 0x030046A4
_081B25AC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B25B6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081B25F0 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081B25F8
	ldr r0, _081B25F4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B2622
	.align 2, 0
_081B25F0: .4byte 0x000004A4
_081B25F4: .4byte 0xFFFFFDFF
_081B25F8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081B2618
	cmp r0, #2
	beq _081B2614
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B2614:
	movs r0, #1
	b _081B2624
_081B2618:
	ldr r0, _081B2638 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B2622:
	movs r0, #0
_081B2624:
	cmp r0, #0
	beq _081B262A
	b _081B280C
_081B262A:
	ldr r4, _081B263C @ =0x000005C4
	adds r0, r7, r4
_081B262E:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B280C
	.align 2, 0
_081B2638: .4byte 0xFFFFFDFF
_081B263C: .4byte 0x000005C4
_081B2640:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B2652
	b _081B27CA
_081B2652:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B26BC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
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
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B26B8
	cmp r1, #0
	blt _081B26B8
	ldr r0, _081B26C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B26B8
	ldr r0, _081B26C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B26C8
_081B26B8:
	movs r4, #0
	b _081B26D6
	.align 2, 0
_081B26BC: .4byte 0x00000551
_081B26C0: .4byte 0x030046A8
_081B26C4: .4byte 0x030046AC
_081B26C8:
	ldr r0, _081B26E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B26D6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B26EC
	adds r0, #4
	b _081B26F8
	.align 2, 0
_081B26E8: .4byte 0x030046A4
_081B26EC:
	ldr r0, _081B270C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B26F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2710
	cmp r2, #2
	beq _081B2714
	b _081B2718
	.align 2, 0
_081B270C: .4byte 0x030046A4
_081B2710:
	ldrb r0, [r5, #4]
	b _081B2716
_081B2714:
	ldrb r0, [r5]
_081B2716:
	subs r1, r1, r0
_081B2718:
	strh r1, [r5, #2]
	ldr r2, _081B2748 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B2750
	ldr r0, _081B274C @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081B277A
	.align 2, 0
_081B2748: .4byte 0x000004A4
_081B274C: .4byte 0xFFFFFDFF
_081B2750:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B2770
	cmp r0, #2
	beq _081B276C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B276C:
	movs r0, #1
	b _081B277C
_081B2770:
	ldr r0, _081B27B4 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081B277A:
	movs r0, #0
_081B277C:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B27BC
	ldr r0, _081B27B8 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x54]
	strb r2, [r1]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r3, [r5]
	ldr r1, [sp, #0x34]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B280C
	.align 2, 0
_081B27B4: .4byte 0xFFFFFDFF
_081B27B8: .4byte FUN_080e48d0
_081B27BC:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081B280C
_081B27CA:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B2804 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081B280C
	.align 2, 0
_081B2804: .4byte 0x00000551

	thumb_func_start FUN_081b2808
FUN_081b2808: @ 0x081B2808
	adds r0, #1
	str r0, [r1]
_081B280C:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b281c
FUN_081b281c: @ 0x081B281C
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081B2828 @ =0x085ADEF4
	str r1, [r0]
	bx lr
	.align 2, 0
_081B2828: .4byte 0x085ADEF4

	thumb_func_start FUN_081b282c
FUN_081b282c: @ 0x081B282C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081B2850 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B2854
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B2856
	.align 2, 0
_081B2850: .4byte 0x0000046C
_081B2854:
	movs r0, #0
_081B2856:
	cmp r0, #0
	beq _081B2884
	ldr r4, _081B28AC @ =FUN_081b197c
	movs r3, #0x23
	ldr r0, _081B28B0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B28B4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081B2884:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B28DC
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B28BC
	ldr r1, _081B28B8 @ =0x0000065C
	adds r0, r7, r1
	b _081B28CC
	.align 2, 0
_081B28AC: .4byte FUN_081b197c
_081B28B0: .4byte 0x0000046D
_081B28B4: .4byte 0x0000046B
_081B28B8: .4byte 0x0000065C
_081B28BC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B28DC
	ldr r2, _081B28D8 @ =0x0000065C
	adds r0, r7, r2
_081B28CC:
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _081B2A1E
	.align 2, 0
_081B28D8: .4byte 0x0000065C
_081B28DC:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r0, _081B2910 @ =0x00000482
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r1, _081B2914 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B2918
	ldr r3, _081B2910 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081B2928
	.align 2, 0
_081B2910: .4byte 0x00000482
_081B2914: .4byte 0x0000A02F
_081B2918:
	ldr r1, _081B294C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081B2928
	movs r0, #1
	strh r0, [r2]
_081B2928:
	ldr r3, _081B2950 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B2954
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081B296C
	.align 2, 0
_081B294C: .4byte 0x00000482
_081B2950: .4byte 0x0000025D
_081B2954:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081B296C:
	ldr r0, _081B29C4 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _081B29D8
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B2A14
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081B29C8 @ =0x00000469
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _081B29CC @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	ldr r0, _081B29D0 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	ldr r1, _081B29D4 @ =0x0000065C
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B2A1E
	.align 2, 0
_081B29C4: .4byte 0x000004A4
_081B29C8: .4byte 0x00000469
_081B29CC: .4byte 0x0000046A
_081B29D0: .4byte 0x0000046C
_081B29D4: .4byte 0x0000065C
_081B29D8:
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B2A14
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081B2A2C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081B2A14:
	ldr r0, _081B2A2C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B2A1E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B2A2C: .4byte 0x00000484

	thumb_func_start FUN_081b2a30
FUN_081b2a30: @ 0x081B2A30
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081B2A50 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B2A54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B2A56
	.align 2, 0
_081B2A50: .4byte 0x0000046C
_081B2A54:
	movs r0, #0
_081B2A56:
	cmp r0, #0
	beq _081B2A8A
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081B2AB0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B2AB4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081B2A8A:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B2ADC
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B2ABC
	ldr r1, _081B2AB8 @ =0x0000065C
	adds r0, r6, r1
	b _081B2ACC
	.align 2, 0
_081B2AB0: .4byte 0x0000046D
_081B2AB4: .4byte 0x0000046B
_081B2AB8: .4byte 0x0000065C
_081B2ABC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B2ADC
	ldr r2, _081B2AD8 @ =0x0000065C
	adds r0, r6, r2
_081B2ACC:
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _081B2B22
	.align 2, 0
_081B2AD8: .4byte 0x0000065C
_081B2ADC:
	ldr r3, _081B2B10 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081B2B18
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081B2B14 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081B2B22
	.align 2, 0
_081B2B10: .4byte 0x0000046B
_081B2B14: .4byte 0x00000484
_081B2B18:
	ldr r0, _081B2B28 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B2B22:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B2B28: .4byte 0x00000484

	thumb_func_start FUN_081b2b2c
FUN_081b2b2c: @ 0x081B2B2C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081B2B44 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B2B48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B2B4A
	.align 2, 0
_081B2B44: .4byte 0x0000046C
_081B2B48:
	movs r0, #0
_081B2B4A:
	cmp r0, #0
	beq _081B2B7C
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081B2BF8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B2BFC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081B2B7C:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B2C12
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _081B2C12
	ldr r2, _081B2BFC @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081B2C08
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _081B2C00 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _081B2C04 @ =0x000005A4
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _081B2BF8 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _081B2BFC @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081B2C12
	.align 2, 0
_081B2BF8: .4byte 0x0000046D
_081B2BFC: .4byte 0x0000046B
_081B2C00: .4byte 0x00000484
_081B2C04: .4byte 0x000005A4
_081B2C08:
	ldr r4, _081B2C18 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B2C12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B2C18: .4byte 0x00000484

	thumb_func_start FUN_081b2c1c
FUN_081b2c1c: @ 0x081B2C1C
	ldr r1, _081B2C28 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081B2C2C @ =0x085ADEFC
	str r1, [r0]
	bx lr
	.align 2, 0
_081B2C28: .4byte 0x00000634
_081B2C2C: .4byte 0x085ADEFC

	thumb_func_start FUN_081b2c30
FUN_081b2c30: @ 0x081B2C30
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081B2C58 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B2C5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B2C5E
	.align 2, 0
_081B2C58: .4byte 0x0000046C
_081B2C5C:
	movs r0, #0
_081B2C5E:
	cmp r0, #0
	beq _081B2CAC
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _081B2D8C @ =FUN_081aec90
	movs r2, #0x22
	ldr r0, _081B2D90 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B2D94 @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B2D98 @ =0x00000553
	adds r0, r7, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _081B2D9C @ =0x00000672
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0]
_081B2CAC:
	ldr r3, _081B2D94 @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B2CB8
	b _081B2E0C
_081B2CB8:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	ldr r1, _081B2DA0 @ =0xFFFFFEFF
	ldrh r0, [r5]
	ands r1, r0
	movs r4, #0
	movs r6, #0
	strh r1, [r5]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _081B2DA4 @ =0x0000067E
	add r0, sb
	ldrh r3, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r5, #0xc
	mov ip, r5
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r5, _081B2DA8 @ =0x00000554
	adds r0, r7, r5
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B2DAC @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B2DB0 @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	ldr r2, _081B2DB4 @ =FUN_080e6794
	movs r1, #0xe
	subs r3, #0xe5
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081B2D94 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081B2DB8 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B2DBC @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #0x3a
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xcc
	lsls r4, r4, #3
	add r4, sb
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B2DC4
	ldr r0, _081B2DC0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _081B2DEE
	.align 2, 0
_081B2D8C: .4byte FUN_081aec90
_081B2D90: .4byte 0x0000046D
_081B2D94: .4byte 0x0000046B
_081B2D98: .4byte 0x00000553
_081B2D9C: .4byte 0x00000672
_081B2DA0: .4byte 0xFFFFFEFF
_081B2DA4: .4byte 0x0000067E
_081B2DA8: .4byte 0x00000554
_081B2DAC: .4byte 0x00000551
_081B2DB0: .4byte 0x00000552
_081B2DB4: .4byte FUN_080e6794
_081B2DB8: .4byte 0x00000469
_081B2DBC: .4byte 0x0000046A
_081B2DC0: .4byte 0xFFFFFDFF
_081B2DC4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B2DE4
	cmp r0, #2
	beq _081B2DE0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B2DE0:
	movs r0, #1
	b _081B2DF0
_081B2DE4:
	ldr r0, _081B2E04 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081B2DEE:
	movs r0, #0
_081B2DF0:
	cmp r0, #0
	bne _081B2E16
	ldr r1, _081B2E08 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B2E16
	.align 2, 0
_081B2E04: .4byte 0xFFFFFDFF
_081B2E08: .4byte 0x000005C4
_081B2E0C:
	ldr r2, _081B2E24 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B2E16:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B2E24: .4byte 0x00000484

	thumb_func_start FUN_081b2e28
FUN_081b2e28: @ 0x081B2E28
	ldr r1, _081B2E34 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081B2E38 @ =0x085ADF44
	str r1, [r0]
	bx lr
	.align 2, 0
_081B2E34: .4byte 0x0000063C
_081B2E38: .4byte 0x085ADF44

	thumb_func_start FUN_081b2e3c
FUN_081b2e3c: @ 0x081B2E3C
	push {r4, r5, r6, lr}
	ldr r4, _081B2E94 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r3, _081B2E98 @ =0x0000046D
	adds r1, r0, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r1]
	ldr r6, _081B2E9C @ =0x0000046B
	adds r1, r0, r6
	strb r3, [r1]
	adds r6, #0xe8
	adds r1, r0, r6
	strb r2, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r4, [r1]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r1, r0, r6
	movs r4, #0
	strh r3, [r1]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r1, r0, r6
	strb r4, [r1]
	adds r6, #1
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _081B2EA0 @ =0x0000046A
	adds r1, r0, r2
	strb r4, [r1]
	adds r6, #0x1b
	adds r1, r0, r6
	str r3, [r1]
	ldr r1, _081B2EA4 @ =0x0000046C
	adds r0, r0, r1
	strb r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B2E94: .4byte FUN_080e48d0
_081B2E98: .4byte 0x0000046D
_081B2E9C: .4byte 0x0000046B
_081B2EA0: .4byte 0x0000046A
_081B2EA4: .4byte 0x0000046C

	thumb_func_start FUN_081b2ea8
FUN_081b2ea8: @ 0x081B2EA8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _081B2F10
	ldr r3, _081B2F04 @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081B2ED4
	movs r0, #4
	ldr r6, _081B2F08 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081B2ED4:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r6, _081B2F0C @ =0x0000024E
	adds r0, r4, r6
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081B2F68
	adds r0, r4, #0
	bl FUN_081b2e3c
	b _081B2F58
	.align 2, 0
_081B2F04: .4byte 0x000001DF
_081B2F08: .4byte 0x00000222
_081B2F0C: .4byte 0x0000024E
_081B2F10:
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _081B2F70 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r6, _081B2F74 @ =0x0000046A
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r3, _081B2F78 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081B2F7C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081B2F58:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081B2F68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B2F70: .4byte 0x00000469
_081B2F74: .4byte 0x0000046A
_081B2F78: .4byte FUN_080e48d0
_081B2F7C: .4byte 0x0000046B

	thumb_func_start FUN_081b2f80
FUN_081b2f80: @ 0x081B2F80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B2FA0
	b _081B31F0
_081B2FA0:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _081B3068 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B306C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _081B3070 @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081B3074 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _081B308C
	ldr r4, _081B3078 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov r8, r2
	movs r1, #0x1e
	adds r4, #0xd6
	adds r2, r5, r4
	subs r4, #4
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B307C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B3080 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	movs r0, #4
	ldr r7, _081B3084 @ =0x00000222
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r6]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081B30D0
	ldr r3, _081B3088 @ =0x0000024E
	adds r2, r5, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	adds r7, #0x2a
	adds r1, r5, r7
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081B30D0
	strh r1, [r2]
	b _081B30D0
	.align 2, 0
_081B3068: .4byte 0x00000469
_081B306C: .4byte 0x0000046A
_081B3070: .4byte FUN_080e6794
_081B3074: .4byte 0x0000046B
_081B3078: .4byte 0x00000482
_081B307C: .4byte 0x00000551
_081B3080: .4byte 0x00000552
_081B3084: .4byte 0x00000222
_081B3088: .4byte 0x0000024E
_081B308C:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081B310C @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B3110 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B3114 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081B30D0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B3108
	cmp r1, #0
	blt _081B3108
	ldr r0, _081B3118 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B3108
	ldr r0, _081B311C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B3120
_081B3108:
	movs r4, #0
	b _081B312E
	.align 2, 0
_081B310C: .4byte 0x00000482
_081B3110: .4byte 0x00000551
_081B3114: .4byte 0x00000552
_081B3118: .4byte 0x030046A8
_081B311C: .4byte 0x030046AC
_081B3120:
	ldr r0, _081B3140 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B312E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B3144
	adds r0, #4
	b _081B3150
	.align 2, 0
_081B3140: .4byte 0x030046A4
_081B3144:
	ldr r0, _081B3164 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B3150:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B3168
	cmp r3, #2
	beq _081B316C
	b _081B3170
	.align 2, 0
_081B3164: .4byte 0x030046A4
_081B3168:
	ldrb r0, [r6, #4]
	b _081B316E
_081B316C:
	ldrb r0, [r6]
_081B316E:
	subs r2, r2, r0
_081B3170:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _081B31AC @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B31B0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B31D6
	.align 2, 0
_081B31AC: .4byte 0x000004A4
_081B31B0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B31D0
	cmp r0, #2
	beq _081B31CC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B31CC:
	movs r0, #1
	b _081B31E0
_081B31D0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B31D6:
	ldr r1, _081B31FC @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B31E0:
	cmp r0, #0
	bne _081B31F0
	ldr r4, _081B3200 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081B31F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B31FC: .4byte 0xFFFFFDFF
_081B3200: .4byte 0x000005C4

	thumb_func_start FUN_081b3204
FUN_081b3204: @ 0x081B3204
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _081B3288 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _081B328C @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r5
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081B3290 @ =FUN_081ae5d4
	mov r0, r8
	str r0, [sp]
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081B3294 @ =FUN_081ae594
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	bl FUN_080e3984
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B3288: .4byte 0xFFFF0000
_081B328C: .4byte 0x0000FFFF
_081B3290: .4byte FUN_081ae5d4
_081B3294: .4byte FUN_081ae594

	thumb_func_start enemy_boku_081b3298
enemy_boku_081b3298: @ 0x081B3298
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _081B3334 @ =0x0000065E
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #0x14
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #0xc
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r2, #0xcd
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #8
	bl ClearMemory
	ldr r1, _081B3338 @ =0x08252274
	adds r0, r5, #0
	movs r2, #0x93
	bl FUN_080e6768
	adds r0, r5, #0
	bl FUN_080e6204
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r5, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081B333C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081B3344
	.align 2, 0
_081B3334: .4byte 0x0000065E
_081B3338: .4byte 0x08252274
_081B333C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081B3344:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081B3368
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081B3370
_081B3368:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081B3370:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081B33A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081B33E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081B33AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081B33A0
	ldrb r0, [r4, #5]
_081B33A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081B33BC
	.align 2, 0
_081B33A8: .4byte 0x0000FFFF
_081B33AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081B33BC
	strh r1, [r4, #8]
_081B33BC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B33E0
	movs r0, #1
	strb r0, [r4, #7]
_081B33E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081b33e8
FUN_081b33e8: @ 0x081B33E8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081b33ec
FUN_081b33ec: @ 0x081B33EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #8
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #9
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #4
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b3490
FUN_081b3490: @ 0x081B3490
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	adds r4, r3, #0
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081B34E0
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3, #8]
	cmp r0, #3
	bhi _081B34C4
	ldr r0, _081B34C0 @ =0x085ADF48
	ldrh r1, [r3, #8]
	b _081B34D4
	.align 2, 0
_081B34C0: .4byte 0x085ADF48
_081B34C4:
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _081B34E0
	ldr r0, _081B34DC @ =0x085ADF48
	ldrh r1, [r4, #8]
	subs r1, #0xa
_081B34D4:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b _081B34E2
	.align 2, 0
_081B34DC: .4byte 0x085ADF48
_081B34E0:
	movs r0, #0
_081B34E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081b34e8
FUN_081b34e8: @ 0x081B34E8
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B3502
	subs r0, #1
	strh r0, [r1]
_081B3502:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081b3508
FUN_081b3508: @ 0x081B3508
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _081B355C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B3560 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081B3564 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _081B3542
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_081B3542:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B355C: .4byte 0x030046B8
_081B3560: .4byte 0x000003FF
_081B3564: .4byte 0x0203B400

	thumb_func_start FUN_081b3568
FUN_081b3568: @ 0x081B3568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	mov sl, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _081B365C @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r6, #0
	ldrsh r1, [r1, r6]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _081B3660 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3, #4]
	bl FUN_08234f6c
	adds r4, r0, #0
	movs r6, #0
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _081B3672
	mov ip, r7
	add r3, sp, #8
	mov r2, sp
	str r2, [sp, #0x10]
_081B3600:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x10]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	ldr r0, [sp, #0x10]
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _081B3664
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _081B3666
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _081B36D4
	.align 2, 0
_081B365C: .4byte 0x085B0A08
_081B3660: .4byte 0xFFFF0000
_081B3664:
	adds r4, #8
_081B3666:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _081B3600
_081B3672:
	mov r2, sl
	cmp r2, #0
	bne _081B36D4
	adds r4, r5, #0
	adds r4, #0x9c
	ldr r2, _081B36C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B36CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B36D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r6, [r4, #2]
	cmp r0, r6
	bne _081B36B0
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_081B36B0:
	strb r0, [r4, #2]
	mov r7, sl
	strb r7, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	b _081B36E4
	.align 2, 0
_081B36C8: .4byte 0x030046B8
_081B36CC: .4byte 0x000003FF
_081B36D0: .4byte 0x0203B400
_081B36D4:
	movs r0, #0
	mov r2, sb
	mov r1, r8
	strb r2, [r1, #2]
	strb r0, [r1, #3]
	str r4, [r1, #8]
	adds r4, r5, #0
	adds r4, #0x9c
_081B36E4:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081B3718
	cmp r1, #0
	blt _081B3718
	ldr r0, _081B371C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B3718
	ldr r0, _081B3720 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B3724
_081B3718:
	movs r4, #0
	b _081B3732
	.align 2, 0
_081B371C: .4byte 0x030046A8
_081B3720: .4byte 0x030046AC
_081B3724:
	ldr r0, _081B3744 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B3732:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B3748
	adds r0, #4
	b _081B3754
	.align 2, 0
_081B3744: .4byte 0x030046A4
_081B3748:
	ldr r0, _081B3768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B3754:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B376C
	cmp r2, #2
	beq _081B3770
	b _081B3774
	.align 2, 0
_081B3768: .4byte 0x030046A4
_081B376C:
	ldrb r0, [r6, #4]
	b _081B3772
_081B3770:
	ldrb r0, [r6]
_081B3772:
	subs r1, r1, r0
_081B3774:
	strh r1, [r6, #2]
	ldr r6, _081B37A0 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B37A4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B37CA
	.align 2, 0
_081B37A0: .4byte 0x000004A4
_081B37A4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B37C4
	cmp r0, #2
	beq _081B37C0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B37C0:
	movs r0, #1
	b _081B37D4
_081B37C4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B37CA:
	ldr r1, _081B3828 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B37D4:
	adds r4, r0, #0
	cmp r4, #0
	bne _081B3848
	ldr r1, _081B382C @ =FUN_080e48d0
	ldr r6, _081B3830 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081B3834 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _081B3838 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _081B383C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B3840 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081B3844 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r3, [r0]
	b _081B3854
	.align 2, 0
_081B3828: .4byte 0xFFFFFDFF
_081B382C: .4byte FUN_080e48d0
_081B3830: .4byte 0x0000046D
_081B3834: .4byte 0x0000046B
_081B3838: .4byte 0x00000553
_081B383C: .4byte 0x00000469
_081B3840: .4byte 0x0000046A
_081B3844: .4byte 0x00000484
_081B3848:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B3854:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b3864
FUN_081b3864: @ 0x081B3864
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _081B3910 @ =0x0000067E
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _081B3914 @ =0x0000067C
	adds r0, r5, r3
	movs r2, #0
	mov sb, r2
	strh r1, [r0]
	movs r3, #1
	mov r8, r3
	ldr r0, _081B3918 @ =0x0000065C
	adds r5, r5, r0
	ldrh r1, [r5]
	movs r3, #0
	mov r0, r8
	orrs r0, r1
	movs r6, #3
	rsbs r6, r6, #0
	ands r0, r6
	strh r0, [r5]
	movs r2, #4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r3, [r0]
	ldr r3, _081B391C @ =0x0000046A
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081B3920 @ =0x00000484
	adds r0, r4, r1
	mov r2, sb
	str r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	movs r2, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	adds r3, #0x4a
	adds r0, r4, r3
	ldrb r0, [r0]
	eors r2, r0
	subs r3, #2
	adds r0, r4, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b490
	adds r0, r4, #0
	bl FUN_081b3568
	ldrh r0, [r5]
	ands r6, r0
	strh r6, [r5]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B3910: .4byte 0x0000067E
_081B3914: .4byte 0x0000067C
_081B3918: .4byte 0x0000065C
_081B391C: .4byte 0x0000046A
_081B3920: .4byte 0x00000484

	thumb_func_start FUN_081b3924
FUN_081b3924: @ 0x081B3924
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _081B397C
	bl VM_GetPC
	cmp r0, #0
	beq _081B394A
	bl Script_GetValue
	adds r1, r0, #0
	b _081B394C
_081B394A:
	movs r1, #0
_081B394C:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B3964
	bl Script_GetValue
	adds r2, r0, #0
	b _081B3966
_081B3964:
	movs r2, #0
_081B3966:
	ldr r1, _081B3974 @ =0x0000065A
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081B3978 @ =0x0000065B
	b _081B398E
	.align 2, 0
_081B3974: .4byte 0x0000065A
_081B3978: .4byte 0x0000065B
_081B397C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081B3998 @ =0x0000065A
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_081B398E:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B3998: .4byte 0x0000065A

	thumb_func_start FUN_081b399c
FUN_081b399c: @ 0x081B399C
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r5, r1, r2
	ldrh r0, [r5]
	cmp r0, #0
	beq _081B39DC
	ldr r0, _081B39E4 @ =0x0000065B
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r2, #2
	adds r6, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	blo _081B39DC
	ldrh r0, [r5]
	movs r1, #0
	bl Script_ExecById
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	strb r1, [r6]
	strb r1, [r4]
_081B39DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B39E4: .4byte 0x0000065B

	thumb_func_start FUN_081b39e8
FUN_081b39e8: @ 0x081B39E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_080fa77c
	ldr r1, _081B3A44 @ =0x0000214A
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B3A18
	adds r0, r6, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3A18
	b _081B3BC8
_081B3A18:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	mov sb, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3A30
	b _081B3BC8
_081B3A30:
	movs r2, #1
	ldr r1, _081B3A48 @ =0x0000065C
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081B3A4C
	movs r0, #1
	b _081B3A4E
	.align 2, 0
_081B3A44: .4byte 0x0000214A
_081B3A48: .4byte 0x0000065C
_081B3A4C:
	movs r0, #0
_081B3A4E:
	cmp r0, #0
	bne _081B3A54
	b _081B3BC8
_081B3A54:
	ldr r1, _081B3A7C @ =0x0000A107
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r4, r4, r6
	mov r8, r4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B3A68
	b _081B3BC8
_081B3A68:
	ldr r1, _081B3A80 @ =0x0000067C
	add r1, sb
	ldrh r0, [r1]
	adds r7, r0, #0
	cmp r7, #0
	beq _081B3A84
	subs r0, #1
	strh r0, [r1]
	b _081B3BC8
	.align 2, 0
_081B3A7C: .4byte 0x0000A107
_081B3A80: .4byte 0x0000067C
_081B3A84:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081B3B70 @ =0x000004A4
	adds r5, r6, r1
	ldr r0, [r5]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r6, #0
	bl FUN_080e6304
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r0, #0xc
	mov ip, r0
	movs r1, #0x1e
	subs r4, #0x60
	adds r2, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _081B3B74 @ =0x00000551
	adds r0, r6, r2
	strb r7, [r0]
	ldr r3, _081B3B78 @ =0x00000552
	adds r0, r6, r3
	mov r4, ip
	strb r4, [r0]
	ldr r3, _081B3B7C @ =FUN_080e6794
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081B3B80 @ =0x0000046B
	adds r0, r6, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	strh r7, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _081B3B84 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r7, [r0]
	ldr r3, _081B3B88 @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x9c
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r2, [r0]
	ldr r3, _081B3B8C @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_0823b490
	ldr r5, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r7, #0xcc
	lsls r7, r7, #3
	add r7, sb
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B3B94
	ldr r0, _081B3B90 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B3BBC
	.align 2, 0
_081B3B70: .4byte 0x000004A4
_081B3B74: .4byte 0x00000551
_081B3B78: .4byte 0x00000552
_081B3B7C: .4byte FUN_080e6794
_081B3B80: .4byte 0x0000046B
_081B3B84: .4byte 0x00000469
_081B3B88: .4byte 0x0000046C
_081B3B8C: .4byte 0x00000251
_081B3B90: .4byte 0xFFFFFDFF
_081B3B94:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B3BB2
	cmp r0, #2
	beq _081B3BBC
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _081B3BBC
_081B3BB2:
	ldr r0, _081B3BDC @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B3BBC:
	movs r0, #2
	rsbs r0, r0, #0
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081B3BC8:
	movs r0, #1
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B3BDC: .4byte 0xFFFFFDFF

	thumb_func_start FUN_081b3be0
FUN_081b3be0: @ 0x081B3BE0
	push {lr}
	bl FUN_081b34e8
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_081b3bec
FUN_081b3bec: @ 0x081B3BEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081B3C10 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B3C14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B3C16
	.align 2, 0
_081B3C10: .4byte 0x0000046C
_081B3C14:
	movs r0, #0
_081B3C16:
	cmp r0, #0
	beq _081B3C44
	ldr r4, _081B3C74 @ =FUN_081b197c
	movs r3, #0x23
	ldr r0, _081B3C78 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B3C7C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081B3C44:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B3C84
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3C84
	ldr r1, _081B3C80 @ =0x0000065C
	adds r0, r7, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _081B3DC2
	.align 2, 0
_081B3C74: .4byte FUN_081b197c
_081B3C78: .4byte 0x0000046D
_081B3C7C: .4byte 0x0000046B
_081B3C80: .4byte 0x0000065C
_081B3C84:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r3, _081B3CB8 @ =0x00000482
	adds r1, r5, r3
	movs r0, #6
	strh r0, [r1]
	ldr r1, _081B3CBC @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B3CC0
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081B3CD0
	.align 2, 0
_081B3CB8: .4byte 0x00000482
_081B3CBC: .4byte 0x0000A02F
_081B3CC0:
	ldr r3, _081B3CF4 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081B3CD0
	movs r0, #1
	strh r0, [r2]
_081B3CD0:
	ldr r1, _081B3CF8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B3CFC
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081B3D14
	.align 2, 0
_081B3CF4: .4byte 0x00000482
_081B3CF8: .4byte 0x0000025D
_081B3CFC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081B3D14:
	ldr r2, _081B3D6C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _081B3D7C
	ldr r1, [r4]
	mov r3, r8
	str r3, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3DB8
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081B3D70 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r1, _081B3D74 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	ldr r1, _081B3D78 @ =0x0000065C
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B3DC2
	.align 2, 0
_081B3D6C: .4byte 0x000004A4
_081B3D70: .4byte 0x00000469
_081B3D74: .4byte 0x0000046A
_081B3D78: .4byte 0x0000065C
_081B3D7C:
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3DB8
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081B3DD0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081B3DB8:
	ldr r0, _081B3DD0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B3DC2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B3DD0: .4byte 0x00000484

	thumb_func_start FUN_081b3dd4
FUN_081b3dd4: @ 0x081B3DD4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081B3DF4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B3DF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B3DFA
	.align 2, 0
_081B3DF4: .4byte 0x0000046C
_081B3DF8:
	movs r0, #0
_081B3DFA:
	cmp r0, #0
	beq _081B3E2E
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081B3E60 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B3E64 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081B3E2E:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B3E6C
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3E6C
	ldr r1, _081B3E68 @ =0x0000065C
	adds r0, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _081B3EB2
	.align 2, 0
_081B3E60: .4byte 0x0000046D
_081B3E64: .4byte 0x0000046B
_081B3E68: .4byte 0x0000065C
_081B3E6C:
	ldr r2, _081B3EA0 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081B3EA8
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081B3EA4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081B3EB2
	.align 2, 0
_081B3EA0: .4byte 0x0000046B
_081B3EA4: .4byte 0x00000484
_081B3EA8:
	ldr r0, _081B3EB8 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B3EB2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B3EB8: .4byte 0x00000484

	thumb_func_start FUN_081b3ebc
FUN_081b3ebc: @ 0x081B3EBC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081B3ED4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B3ED8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B3EDA
	.align 2, 0
_081B3ED4: .4byte 0x0000046C
_081B3ED8:
	movs r0, #0
_081B3EDA:
	cmp r0, #0
	beq _081B3F0C
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081B3F7C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B3F80 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081B3F0C:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _081B3F96
	ldr r2, _081B3F80 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081B3F8C
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _081B3F84 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _081B3F88 @ =0x000005A4
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _081B3F7C @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _081B3F80 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081B3F96
	.align 2, 0
_081B3F7C: .4byte 0x0000046D
_081B3F80: .4byte 0x0000046B
_081B3F84: .4byte 0x00000484
_081B3F88: .4byte 0x000005A4
_081B3F8C:
	ldr r4, _081B3F9C @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B3F96:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B3F9C: .4byte 0x00000484

	thumb_func_start FUN_081b3fa0
FUN_081b3fa0: @ 0x081B3FA0
	ldr r1, _081B3FAC @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081B3FB0 @ =0x085ADF50
	str r1, [r0]
	bx lr
	.align 2, 0
_081B3FAC: .4byte 0x00000634
_081B3FB0: .4byte 0x085ADF50

	thumb_func_start FUN_081b3fb4
FUN_081b3fb4: @ 0x081B3FB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x104
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081B3FFE
	ldr r3, _081B3FF0 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B3FF8
	ldr r0, _081B3FF4 @ =0x00000211
	bl PlaySound_082406e0
	b _081B3FFE
	.align 2, 0
_081B3FF0: .4byte 0x0000048A
_081B3FF4: .4byte 0x00000211
_081B3FF8:
	movs r0, #0xd4
	bl PlaySound_082406e0
_081B3FFE:
	adds r0, r7, #0
	bl FUN_081b399c
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf4]
	cmp r0, #0
	bne _081B401C
	b _081B4714
_081B401C:
	ldr r5, _081B40AC @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _081B40B0 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _081B40B4 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B406A
	b _081B4726
_081B406A:
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B40A6
	cmp r1, #0
	blt _081B40A6
	ldr r0, _081B40B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B40A6
	ldr r0, _081B40BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B40C0
_081B40A6:
	movs r4, #0
	b _081B40CE
	.align 2, 0
_081B40AC: .4byte 0x000001DD
_081B40B0: .4byte 0xFFFFDFDF
_081B40B4: .4byte 0x00000544
_081B40B8: .4byte 0x030046A8
_081B40BC: .4byte 0x030046AC
_081B40C0:
	ldr r0, _081B40E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B40CE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B40E4
	adds r0, #4
	b _081B40F0
	.align 2, 0
_081B40E0: .4byte 0x030046A4
_081B40E4:
	ldr r0, _081B4104 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B40F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B4108
	cmp r2, #2
	beq _081B410C
	b _081B4110
	.align 2, 0
_081B4104: .4byte 0x030046A4
_081B4108:
	ldrb r0, [r5, #4]
	b _081B410E
_081B410C:
	ldrb r0, [r5]
_081B410E:
	subs r1, r1, r0
_081B4110:
	strh r1, [r5, #2]
	ldr r0, _081B4124 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B4128
	movs r0, #1
	b _081B412A
	.align 2, 0
_081B4124: .4byte 0x030047A4
_081B4128:
	movs r0, #0
_081B412A:
	cmp r0, #0
	beq _081B4168
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B414A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B4146
	adds r2, r0, #0
_081B4146:
	cmp r2, #0
	bge _081B4154
_081B414A:
	ldr r2, _081B4150 @ =0x000005C4
	adds r0, r7, r2
	b _081B4680
	.align 2, 0
_081B4150: .4byte 0x000005C4
_081B4154:
	ldr r1, _081B4164 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B41B0
	.align 2, 0
_081B4164: .4byte 0x03002BE0
_081B4168:
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
	blt _081B4194
	cmp r1, #0
	blt _081B4194
	ldr r0, _081B4198 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4194
	ldr r0, _081B419C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B41A0
_081B4194:
	movs r5, #0
	b _081B41AE
	.align 2, 0
_081B4198: .4byte 0x030046A8
_081B419C: .4byte 0x030046AC
_081B41A0:
	ldr r0, _081B41E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B41AE:
	movs r2, #0
_081B41B0:
	ldr r4, _081B41EC @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B41D0
	ldr r1, _081B41F0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B41D0
	b _081B45C0
_081B41D0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	cmp r0, #0
	beq _081B41F4
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B41E8: .4byte 0x030046A4
_081B41EC: .4byte 0x00000256
_081B41F0: .4byte 0x03002BE0
_081B41F4:
	ldr r6, _081B4298 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf4]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xfc]
	cmp r6, #0
	beq _081B42AC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081B429C @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081B42A0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x20]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x24]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x28]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081B42A4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081B42A8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x18]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B447E
	.align 2, 0
_081B4298: .4byte 0x00000222
_081B429C: .4byte 0x0000046D
_081B42A0: .4byte 0x0000046B
_081B42A4: .4byte 0x00000469
_081B42A8: .4byte 0x00000484
_081B42AC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B4370 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r3, _081B4374 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x30]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B4378 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x34]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081B437C @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B4380 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B4384 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x44]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x44]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sb
	cmp r0, #0
	blt _081B436A
	cmp r1, #0
	blt _081B436A
	ldr r0, _081B4388 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081B436A
	ldr r0, _081B438C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4390
_081B436A:
	movs r4, #0
	b _081B43A0
	.align 2, 0
_081B4370: .4byte 0x0000046D
_081B4374: .4byte 0x0000046B
_081B4378: .4byte 0x00000553
_081B437C: .4byte 0x00000469
_081B4380: .4byte 0x00000484
_081B4384: .4byte 0x0000046C
_081B4388: .4byte 0x030046A8
_081B438C: .4byte 0x030046AC
_081B4390:
	ldr r0, _081B43B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081B43A0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B43B4
	adds r0, #4
	b _081B43C0
	.align 2, 0
_081B43B0: .4byte 0x030046A4
_081B43B4:
	ldr r0, _081B43D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B43C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B43D8
	cmp r2, #2
	beq _081B43DE
	b _081B43E4
	.align 2, 0
_081B43D4: .4byte 0x030046A4
_081B43D8:
	ldr r2, [sp, #0x44]
	ldrb r0, [r2, #4]
	b _081B43E2
_081B43DE:
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
_081B43E2:
	subs r1, r1, r0
_081B43E4:
	ldr r4, [sp, #0x44]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4410
	cmp r1, #0
	blt _081B4410
	ldr r0, _081B4414 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4410
	ldr r0, _081B4418 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B441C
_081B4410:
	movs r4, #0
	b _081B442A
	.align 2, 0
_081B4414: .4byte 0x030046A8
_081B4418: .4byte 0x030046AC
_081B441C:
	ldr r0, _081B4440 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B442A:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B4444
	adds r0, #4
	b _081B4450
	.align 2, 0
_081B4440: .4byte 0x030046A4
_081B4444:
	ldr r0, _081B4464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4450:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B4468
	cmp r3, #2
	beq _081B446C
	b _081B4470
	.align 2, 0
_081B4464: .4byte 0x030046A4
_081B4468:
	ldrb r0, [r5, #4]
	b _081B446E
_081B446C:
	ldrb r0, [r5]
_081B446E:
	subs r2, r2, r0
_081B4470:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B447E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x48]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081B44A8 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B4588
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B44AC
	movs r0, #1
	b _081B44AE
	.align 2, 0
_081B44A8: .4byte 0x00000482
_081B44AC:
	movs r0, #0
_081B44AE:
	ldr r3, _081B4598 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B4588
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B459C @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B45A0 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B45A4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B45A8 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B45AC @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B45B0 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B45B4 @ =0x030046B8
	str r4, [sp, #0x100]
_081B44F4:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B45B8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B45BC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B451A
	adds r3, #1
	cmp r3, #3
	ble _081B44F4
	adds r0, r4, #0
_081B451A:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0x48
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B4588:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B4598: .4byte 0x00000482
_081B459C: .4byte 0x0000054F
_081B45A0: .4byte 0x0000054D
_081B45A4: .4byte 0x0000054E
_081B45A8: .4byte 0x00000541
_081B45AC: .4byte 0x000005BC
_081B45B0: .4byte 0x00000542
_081B45B4: .4byte 0x030046B8
_081B45B8: .4byte 0x000003FF
_081B45BC: .4byte 0x0203B400
_081B45C0:
	mov sb, sp
	ldr r6, _081B45FC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B4600
	adds r0, #4
	b _081B460A
	.align 2, 0
_081B45FC: .4byte 0x030046A4
_081B4600:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B460A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081B4644 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081B464C
	ldr r0, _081B4648 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4676
	.align 2, 0
_081B4644: .4byte 0x000004A4
_081B4648: .4byte 0xFFFFFDFF
_081B464C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081B466C
	cmp r0, #2
	beq _081B4668
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4668:
	movs r0, #1
	b _081B4678
_081B466C:
	ldr r0, _081B468C @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4676:
	movs r0, #0
_081B4678:
	cmp r0, #0
	bne _081B4694
	ldr r4, _081B4690 @ =0x000005C4
	adds r0, r7, r4
_081B4680:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B468C: .4byte 0xFFFFFDFF
_081B4690: .4byte 0x000005C4
_081B4694:
	movs r0, #1
_081B4696:
	cmp r0, #0
	beq _081B469E
	bl _081B568C
_081B469E:
	ldr r5, _081B46D0 @ =0x000004A4
	adds r0, r7, r5
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B46D8
	ldr r0, _081B46D4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4702
	.align 2, 0
_081B46D0: .4byte 0x000004A4
_081B46D4: .4byte 0xFFFFFDFF
_081B46D8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B46F8
	cmp r0, #2
	beq _081B46F4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B46F4:
	movs r0, #1
	b _081B4704
_081B46F8:
	ldr r0, _081B4710 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4702:
	movs r0, #0
_081B4704:
	cmp r0, #0
	bne _081B470C
	bl _081B5674
_081B470C:
	bl _081B568C
	.align 2, 0
_081B4710: .4byte 0xFFFFFDFF
_081B4714:
	ldr r4, _081B472C @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _081B4730
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf4]
	strh r0, [r1]
_081B4726:
	movs r0, #0
	bl FUN_081b56e6
	.align 2, 0
_081B472C: .4byte 0x00008002
_081B4730:
	ldr r2, _081B47A0 @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081B47C4
	ldr r3, _081B47A4 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _081B47A8 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081B47AC @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081B47B0 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _081B47B4 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081B47B8 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _081B47BC @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _081B47C0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _081B56E4
	.align 2, 0
_081B47A0: .4byte 0x0000049C
_081B47A4: .4byte 0x000005CC
_081B47A8: .4byte 0x0000046D
_081B47AC: .4byte 0x0000046B
_081B47B0: .4byte 0x00000469
_081B47B4: .4byte 0x0000046A
_081B47B8: .4byte 0x00000484
_081B47BC: .4byte 0x0000046C
_081B47C0: .4byte 0xFEFFFFFF
_081B47C4:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r3
	ldr r6, [sp, #0xf4]
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B4726
	ldr r1, _081B4878 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B4726
	ldr r3, _081B487C @ =0x0000065C
	adds r2, r5, r3
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081B47FE
	b _081B4F6C
_081B47FE:
	ldr r5, _081B4880 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _081B482A
	ldr r6, _081B4884 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081B482A
	ldr r1, _081B4878 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081B482A:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B4838
	b _081B4726
_081B4838:
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B4874
	cmp r1, #0
	blt _081B4874
	ldr r0, _081B4888 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B4874
	ldr r0, _081B488C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4890
_081B4874:
	movs r4, #0
	b _081B489E
	.align 2, 0
_081B4878: .4byte 0x000004BE
_081B487C: .4byte 0x0000065C
_081B4880: .4byte 0x0000048D
_081B4884: .4byte 0x0000048C
_081B4888: .4byte 0x030046A8
_081B488C: .4byte 0x030046AC
_081B4890:
	ldr r0, _081B48B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B489E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B48B4
	adds r0, #4
	b _081B48C0
	.align 2, 0
_081B48B0: .4byte 0x030046A4
_081B48B4:
	ldr r0, _081B48D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B48C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B48D8
	cmp r2, #2
	beq _081B48DC
	b _081B48E0
	.align 2, 0
_081B48D4: .4byte 0x030046A4
_081B48D8:
	ldrb r0, [r5, #4]
	b _081B48DE
_081B48DC:
	ldrb r0, [r5]
_081B48DE:
	subs r1, r1, r0
_081B48E0:
	strh r1, [r5, #2]
	ldr r0, _081B48F4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B48F8
	movs r0, #1
	b _081B48FA
	.align 2, 0
_081B48F4: .4byte 0x030047A4
_081B48F8:
	movs r0, #0
_081B48FA:
	cmp r0, #0
	beq _081B4938
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081B491A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B4916
	adds r2, r0, #0
_081B4916:
	cmp r2, #0
	bge _081B4924
_081B491A:
	ldr r4, _081B4920 @ =0x000005C4
	adds r0, r7, r4
	b _081B4E5C
	.align 2, 0
_081B4920: .4byte 0x000005C4
_081B4924:
	ldr r1, _081B4934 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B4980
	.align 2, 0
_081B4934: .4byte 0x03002BE0
_081B4938:
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
	blt _081B4964
	cmp r1, #0
	blt _081B4964
	ldr r0, _081B4968 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4964
	ldr r0, _081B496C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4970
_081B4964:
	movs r5, #0
	b _081B497E
	.align 2, 0
_081B4968: .4byte 0x030046A8
_081B496C: .4byte 0x030046AC
_081B4970:
	ldr r0, _081B49B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B497E:
	movs r2, #0
_081B4980:
	ldr r6, _081B49BC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B49A0
	ldr r1, _081B49C0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B49A0
	b _081B4D98
_081B49A0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xf4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	cmp r0, #0
	beq _081B49C4
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B49B8: .4byte 0x030046A4
_081B49BC: .4byte 0x00000256
_081B49C0: .4byte 0x03002BE0
_081B49C4:
	ldr r3, _081B4A6C @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _081B4A84
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B4A70 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x50]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081B4A74 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081B4A78 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B4A7C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x4c]
	str r6, [r1]
	ldr r6, _081B4A80 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B4C56
	.align 2, 0
_081B4A6C: .4byte 0x00000222
_081B4A70: .4byte 0x0000046D
_081B4A74: .4byte 0x0000046B
_081B4A78: .4byte 0x00000469
_081B4A7C: .4byte 0x00000484
_081B4A80: .4byte 0x0000046C
_081B4A84:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B4B48 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x60]
	strb r0, [r2]
	ldr r3, _081B4B4C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x64]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B4B50 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x68]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x70]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x74]
	strb r4, [r3]
	ldr r4, _081B4B54 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081B4B58 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081B4B5C @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x78]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x78]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x78]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0x6c]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, r8
	cmp r0, #0
	blt _081B4B44
	cmp r1, #0
	blt _081B4B44
	ldr r0, _081B4B60 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081B4B44
	ldr r0, _081B4B64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4B68
_081B4B44:
	movs r4, #0
	b _081B4B78
	.align 2, 0
_081B4B48: .4byte 0x0000046D
_081B4B4C: .4byte 0x0000046B
_081B4B50: .4byte 0x00000553
_081B4B54: .4byte 0x00000469
_081B4B58: .4byte 0x0000046A
_081B4B5C: .4byte 0x00000484
_081B4B60: .4byte 0x030046A8
_081B4B64: .4byte 0x030046AC
_081B4B68:
	ldr r0, _081B4B88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081B4B78:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B4B8C
	adds r0, #4
	b _081B4B98
	.align 2, 0
_081B4B88: .4byte 0x030046A4
_081B4B8C:
	ldr r0, _081B4BAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4B98:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B4BB0
	cmp r2, #2
	beq _081B4BB6
	b _081B4BBC
	.align 2, 0
_081B4BAC: .4byte 0x030046A4
_081B4BB0:
	ldr r2, [sp, #0x78]
	ldrb r0, [r2, #4]
	b _081B4BBA
_081B4BB6:
	ldr r3, [sp, #0x78]
	ldrb r0, [r3]
_081B4BBA:
	subs r1, r1, r0
_081B4BBC:
	ldr r4, [sp, #0x78]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4BE8
	cmp r1, #0
	blt _081B4BE8
	ldr r0, _081B4BEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4BE8
	ldr r0, _081B4BF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4BF4
_081B4BE8:
	movs r4, #0
	b _081B4C02
	.align 2, 0
_081B4BEC: .4byte 0x030046A8
_081B4BF0: .4byte 0x030046AC
_081B4BF4:
	ldr r0, _081B4C18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B4C02:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B4C1C
	adds r0, #4
	b _081B4C28
	.align 2, 0
_081B4C18: .4byte 0x030046A4
_081B4C1C:
	ldr r0, _081B4C3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4C28:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B4C40
	cmp r3, #2
	beq _081B4C44
	b _081B4C48
	.align 2, 0
_081B4C3C: .4byte 0x030046A4
_081B4C40:
	ldrb r0, [r5, #4]
	b _081B4C46
_081B4C44:
	ldrb r0, [r5]
_081B4C46:
	subs r2, r2, r0
_081B4C48:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B4C56:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x7c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081B4C80 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B4D60
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B4C84
	movs r0, #1
	b _081B4C86
	.align 2, 0
_081B4C80: .4byte 0x00000482
_081B4C84:
	movs r0, #0
_081B4C86:
	ldr r3, _081B4D70 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B4D60
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B4D74 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B4D78 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B4D7C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B4D80 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B4D84 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B4D88 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B4D8C @ =0x030046B8
	str r4, [sp, #0x100]
_081B4CCC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B4D90 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B4D94 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B4CF2
	adds r3, #1
	cmp r3, #3
	ble _081B4CCC
	adds r0, r4, #0
_081B4CF2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0x7c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B4D60:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B4D70: .4byte 0x00000482
_081B4D74: .4byte 0x0000054F
_081B4D78: .4byte 0x0000054D
_081B4D7C: .4byte 0x0000054E
_081B4D80: .4byte 0x00000541
_081B4D84: .4byte 0x000005BC
_081B4D88: .4byte 0x00000542
_081B4D8C: .4byte 0x030046B8
_081B4D90: .4byte 0x000003FF
_081B4D94: .4byte 0x0203B400
_081B4D98:
	add r6, sp, #8
	ldr r0, _081B4DD8 @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B4DDC
	adds r0, #4
	b _081B4DE8
	.align 2, 0
_081B4DD8: .4byte 0x030046A4
_081B4DDC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B4DE8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B4E20 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B4E28
	ldr r0, _081B4E24 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B4E52
	.align 2, 0
_081B4E20: .4byte 0x000004A4
_081B4E24: .4byte 0xFFFFFDFF
_081B4E28:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B4E48
	cmp r0, #2
	beq _081B4E44
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4E44:
	movs r0, #1
	b _081B4E54
_081B4E48:
	ldr r0, _081B4E68 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B4E52:
	movs r0, #0
_081B4E54:
	cmp r0, #0
	bne _081B4E70
	ldr r3, _081B4E6C @ =0x000005C4
	adds r0, r7, r3
_081B4E5C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B4E68: .4byte 0xFFFFFDFF
_081B4E6C: .4byte 0x000005C4
_081B4E70:
	movs r0, #1
_081B4E72:
	cmp r0, #0
	bne _081B4EE2
	ldr r4, _081B4EA8 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B4EB0
	ldr r0, _081B4EAC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4EDA
	.align 2, 0
_081B4EA8: .4byte 0x000004A4
_081B4EAC: .4byte 0xFFFFFDFF
_081B4EB0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B4ED0
	cmp r0, #2
	beq _081B4ECC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4ECC:
	movs r0, #1
	b _081B4EDC
_081B4ED0:
	ldr r0, _081B4F50 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4EDA:
	movs r0, #0
_081B4EDC:
	cmp r0, #0
	bne _081B4EE2
	b _081B5674
_081B4EE2:
	movs r2, #0x80
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _081B4F54 @ =0x00000222
	adds r2, r7, r6
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081B4F58 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081B4F5C @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
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
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081B4F60 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081B4F64 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081B4F68 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081B56E4
	.align 2, 0
_081B4F50: .4byte 0xFFFFFDFF
_081B4F54: .4byte 0x00000222
_081B4F58: .4byte 0x0000046D
_081B4F5C: .4byte 0x0000046B
_081B4F60: .4byte 0x00000469
_081B4F64: .4byte 0x0000046A
_081B4F68: .4byte 0x0000046C
_081B4F6C:
	ldr r2, _081B500C @ =0x00000544
	adds r0, r7, r2
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r3, _081B5010 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081B4FA2
	ldr r4, _081B5014 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081B4FA2
	ldr r5, _081B5018 @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081B4FA2:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B4FB2
	bl _081B4726
_081B4FB2:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B5008
	cmp r1, #0
	blt _081B5008
	ldr r0, _081B501C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B5008
	ldr r0, _081B5020 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5024
_081B5008:
	movs r4, #0
	b _081B5032
	.align 2, 0
_081B500C: .4byte 0x00000544
_081B5010: .4byte 0x0000048D
_081B5014: .4byte 0x0000048C
_081B5018: .4byte 0x000004BE
_081B501C: .4byte 0x030046A8
_081B5020: .4byte 0x030046AC
_081B5024:
	ldr r0, _081B5044 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B5032:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5048
	adds r0, #4
	b _081B5054
	.align 2, 0
_081B5044: .4byte 0x030046A4
_081B5048:
	ldr r0, _081B5068 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5054:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B506C
	cmp r2, #2
	beq _081B5070
	b _081B5074
	.align 2, 0
_081B5068: .4byte 0x030046A4
_081B506C:
	ldrb r0, [r5, #4]
	b _081B5072
_081B5070:
	ldrb r0, [r5]
_081B5072:
	subs r1, r1, r0
_081B5074:
	strh r1, [r5, #2]
	ldr r0, _081B5088 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B508C
	movs r0, #1
	b _081B508E
	.align 2, 0
_081B5088: .4byte 0x030047A4
_081B508C:
	movs r0, #0
_081B508E:
	cmp r0, #0
	beq _081B50CC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081B50AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B50AA
	adds r2, r0, #0
_081B50AA:
	cmp r2, #0
	bge _081B50B8
_081B50AE:
	ldr r4, _081B50B4 @ =0x000005C4
	adds r0, r7, r4
	b _081B55F0
	.align 2, 0
_081B50B4: .4byte 0x000005C4
_081B50B8:
	ldr r1, _081B50C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B5114
	.align 2, 0
_081B50C8: .4byte 0x03002BE0
_081B50CC:
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
	blt _081B50F8
	cmp r1, #0
	blt _081B50F8
	ldr r0, _081B50FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B50F8
	ldr r0, _081B5100 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5104
_081B50F8:
	movs r5, #0
	b _081B5112
	.align 2, 0
_081B50FC: .4byte 0x030046A8
_081B5100: .4byte 0x030046AC
_081B5104:
	ldr r0, _081B514C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B5112:
	movs r2, #0
_081B5114:
	ldr r6, _081B5150 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B5134
	ldr r1, _081B5154 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B5134
	b _081B552C
_081B5134:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xf4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x80]
	cmp r0, #0
	beq _081B5158
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B514C: .4byte 0x030046A4
_081B5150: .4byte 0x00000256
_081B5154: .4byte 0x03002BE0
_081B5158:
	ldr r3, _081B5200 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _081B5218
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B5204 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081B5208 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x88]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x90]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x80
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081B520C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B5210 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x80]
	str r6, [r1]
	ldr r6, _081B5214 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x84]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B53EC
	.align 2, 0
_081B5200: .4byte 0x00000222
_081B5204: .4byte 0x0000046D
_081B5208: .4byte 0x0000046B
_081B520C: .4byte 0x00000469
_081B5210: .4byte 0x00000484
_081B5214: .4byte 0x0000046C
_081B5218:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B52E0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x94]
	strb r0, [r2]
	ldr r3, _081B52E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B52E8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	mov r2, sl
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	strb r4, [r3]
	ldr r4, _081B52EC @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081B52F0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081B52F4 @ =0x00000484
	adds r3, r7, r6
	mov r1, sl
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0xac]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xac]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xac]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xb0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x94]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	ldr r0, [sp, #0xb0]
	cmp r0, #0
	blt _081B52DA
	cmp r1, #0
	blt _081B52DA
	ldr r0, _081B52F8 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xb0]
	cmp r2, r0
	bhs _081B52DA
	ldr r0, _081B52FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5300
_081B52DA:
	movs r4, #0
	b _081B5310
	.align 2, 0
_081B52E0: .4byte 0x0000046D
_081B52E4: .4byte 0x0000046B
_081B52E8: .4byte 0x00000553
_081B52EC: .4byte 0x00000469
_081B52F0: .4byte 0x0000046A
_081B52F4: .4byte 0x00000484
_081B52F8: .4byte 0x030046A8
_081B52FC: .4byte 0x030046AC
_081B5300:
	ldr r0, _081B5320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xb0]
	adds r4, r0, r3
_081B5310:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5324
	adds r0, #4
	b _081B5330
	.align 2, 0
_081B5320: .4byte 0x030046A4
_081B5324:
	ldr r0, _081B5344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5348
	cmp r2, #2
	beq _081B534E
	b _081B5354
	.align 2, 0
_081B5344: .4byte 0x030046A4
_081B5348:
	ldr r4, [sp, #0xac]
	ldrb r0, [r4, #4]
	b _081B5352
_081B534E:
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
_081B5352:
	subs r1, r1, r0
_081B5354:
	ldr r6, [sp, #0xac]
	strh r1, [r6, #2]
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5380
	cmp r1, #0
	blt _081B5380
	ldr r0, _081B5384 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5380
	ldr r0, _081B5388 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B538C
_081B5380:
	movs r4, #0
	b _081B539A
	.align 2, 0
_081B5384: .4byte 0x030046A8
_081B5388: .4byte 0x030046AC
_081B538C:
	ldr r0, _081B53B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B539A:
	ldr r2, [sp, #0xd4]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B53B4
	adds r0, #4
	b _081B53C0
	.align 2, 0
_081B53B0: .4byte 0x030046A4
_081B53B4:
	ldr r0, _081B53D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B53C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B53D8
	cmp r3, #2
	beq _081B53DC
	b _081B53E0
	.align 2, 0
_081B53D4: .4byte 0x030046A4
_081B53D8:
	ldrb r0, [r5, #4]
	b _081B53DE
_081B53DC:
	ldrb r0, [r5]
_081B53DE:
	subs r2, r2, r0
_081B53E0:
	ldr r3, [sp, #0xd4]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081B53EC:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xb4]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	ldr r6, _081B5414 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B54F4
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B5418
	movs r0, #1
	b _081B541A
	.align 2, 0
_081B5414: .4byte 0x00000482
_081B5418:
	movs r0, #0
_081B541A:
	ldr r3, _081B5504 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B54F4
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B5508 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B550C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B5510 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B5514 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B5518 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B551C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B5520 @ =0x030046B8
	str r4, [sp, #0x100]
_081B5460:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B5524 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B5528 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B5486
	adds r3, #1
	cmp r3, #3
	ble _081B5460
	adds r0, r4, #0
_081B5486:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0xb4
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B54F4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B5504: .4byte 0x00000482
_081B5508: .4byte 0x0000054F
_081B550C: .4byte 0x0000054D
_081B5510: .4byte 0x0000054E
_081B5514: .4byte 0x00000541
_081B5518: .4byte 0x000005BC
_081B551C: .4byte 0x00000542
_081B5520: .4byte 0x030046B8
_081B5524: .4byte 0x000003FF
_081B5528: .4byte 0x0203B400
_081B552C:
	add r6, sp, #0x10
	ldr r0, _081B556C @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B5570
	adds r0, #4
	b _081B557C
	.align 2, 0
_081B556C: .4byte 0x030046A4
_081B5570:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B557C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B55B4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B55BC
	ldr r0, _081B55B8 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B55E6
	.align 2, 0
_081B55B4: .4byte 0x000004A4
_081B55B8: .4byte 0xFFFFFDFF
_081B55BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B55DC
	cmp r0, #2
	beq _081B55D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B55D8:
	movs r0, #1
	b _081B55E8
_081B55DC:
	ldr r0, _081B55FC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B55E6:
	movs r0, #0
_081B55E8:
	cmp r0, #0
	bne _081B5604
	ldr r3, _081B5600 @ =0x000005C4
	adds r0, r7, r3
_081B55F0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B55FC: .4byte 0xFFFFFDFF
_081B5600: .4byte 0x000005C4
_081B5604:
	movs r0, #1
_081B5606:
	cmp r0, #0
	bne _081B568C
	ldr r4, _081B563C @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B5644
	ldr r0, _081B5640 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B566E
	.align 2, 0
_081B563C: .4byte 0x000004A4
_081B5640: .4byte 0xFFFFFDFF
_081B5644:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B5664
	cmp r0, #2
	beq _081B5660
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B5660:
	movs r0, #1
	b _081B5670
_081B5664:
	ldr r0, _081B5684 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B566E:
	movs r0, #0
_081B5670:
	cmp r0, #0
	bne _081B568C
_081B5674:
	ldr r4, _081B5688 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081B4726
	.align 2, 0
_081B5684: .4byte 0xFFFFFDFF
_081B5688: .4byte 0x000005C4
_081B568C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B56F8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B56FC @ =0x0000046B
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
	ldr r6, _081B5700 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B5704 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B5708 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B56E4:
	movs r0, #1
FUN_081b56e6:
	add sp, #0x104
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B56F8: .4byte 0x0000046D
_081B56FC: .4byte 0x0000046B
_081B5700: .4byte 0x00000469
_081B5704: .4byte 0x0000046A
_081B5708: .4byte 0x00000484

	thumb_func_start FUN_081b570c
FUN_081b570c: @ 0x081B570C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _081B5730 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B5734
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B5736
	.align 2, 0
_081B5730: .4byte 0x0000046D
_081B5734:
	movs r0, #0
_081B5736:
	cmp r0, #0
	beq _081B5742
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081B5742:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r5, r1, #0
	cmp r4, #0x11
	bgt _081B5776
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _081B5776
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B5776
	cmp r2, #1
	beq _081B5776
	strh r4, [r3, #0xe]
_081B5776:
	ldr r3, _081B5800 @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B5784
	bl _081B60AC
_081B5784:
	ldr r4, _081B5804 @ =0x0000046B
	adds r0, r7, r4
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x78]
	cmp r3, #0
	beq _081B581C
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081B5808 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B580C @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r4, [r0]
	adds r1, #3
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	ldr r3, _081B5810 @ =0x00000594
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081B5814 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r3, _081B5804 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _081B5818 @ =0xFFFFF67C
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081B60AC
	.align 2, 0
_081B5800: .4byte 0x0000046E
_081B5804: .4byte 0x0000046B
_081B5808: .4byte 0x00000469
_081B580C: .4byte 0x0000046A
_081B5810: .4byte 0x00000594
_081B5814: .4byte 0x0000046D
_081B5818: .4byte 0xFFFFF67C
_081B581C:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081B582A
	b _081B5E64
_081B582A:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x88]
	bl FUN_080ef86c
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B593C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081B5940 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r3, [sp, #0x88]
	strb r3, [r1]
	ldr r2, _081B5944 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0x14]
	str r3, [r2]
	ldr r4, _081B5948 @ =0x0000046C
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	ldr r1, _081B594C @ =FUN_080e6794
	movs r0, #0xe
	ldr r5, _081B5950 @ =0x0000046D
	adds r6, r7, r5
	movs r2, #1
	strb r2, [r6]
	ldr r4, _081B5954 @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	strb r3, [r4]
	adds r5, #0xe6
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r3, [r1]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #0xc
	mov ip, r5
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081B5958 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B595C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B5960 @ =0x00000552
	adds r0, r7, r3
	mov r4, ip
	strb r4, [r0]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	str r6, [sp, #0x54]
	ldr r5, [sp, #8]
	str r5, [sp, #0x40]
	ldr r1, [sp, #0xc]
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x10]
	str r2, [sp, #0x48]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x5c]
	mov r4, sb
	str r4, [sp, #0x50]
	mov r5, sl
	str r5, [sp, #0x4c]
	ldr r1, [sp, #0x18]
	str r1, [sp, #0x74]
	ldr r2, [sp, #0x1c]
	str r2, [sp, #0x7c]
	mov r3, r8
	str r3, [sp, #0x80]
	cmp r0, #0
	bne _081B58FC
	b _081B60AC
_081B58FC:
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B5938
	cmp r1, #0
	blt _081B5938
	ldr r0, _081B5964 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B5938
	ldr r0, _081B5968 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B596C
_081B5938:
	movs r4, #0
	b _081B597A
	.align 2, 0
_081B593C: .4byte 0x00000469
_081B5940: .4byte 0x0000046A
_081B5944: .4byte 0x00000484
_081B5948: .4byte 0x0000046C
_081B594C: .4byte FUN_080e6794
_081B5950: .4byte 0x0000046D
_081B5954: .4byte 0x0000046B
_081B5958: .4byte 0x00000554
_081B595C: .4byte 0x00000551
_081B5960: .4byte 0x00000552
_081B5964: .4byte 0x030046A8
_081B5968: .4byte 0x030046AC
_081B596C:
	ldr r0, _081B598C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B597A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5990
	adds r0, #4
	b _081B599C
	.align 2, 0
_081B598C: .4byte 0x030046A4
_081B5990:
	ldr r0, _081B59B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B599C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B59B4
	cmp r2, #2
	beq _081B59B8
	b _081B59BC
	.align 2, 0
_081B59B0: .4byte 0x030046A4
_081B59B4:
	ldrb r0, [r5, #4]
	b _081B59BA
_081B59B8:
	ldrb r0, [r5]
_081B59BA:
	subs r1, r1, r0
_081B59BC:
	strh r1, [r5, #2]
	ldr r0, _081B59D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B59D4
	movs r0, #1
	b _081B59D6
	.align 2, 0
_081B59D0: .4byte 0x030047A4
_081B59D4:
	movs r0, #0
_081B59D6:
	cmp r0, #0
	beq _081B5A14
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081B59F6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B59F2
	adds r2, r0, #0
_081B59F2:
	cmp r2, #0
	bge _081B5A00
_081B59F6:
	ldr r1, _081B59FC @ =0x000005C4
	adds r0, r7, r1
	b _081B5E52
	.align 2, 0
_081B59FC: .4byte 0x000005C4
_081B5A00:
	ldr r1, _081B5A10 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B5A5C
	.align 2, 0
_081B5A10: .4byte 0x03002BE0
_081B5A14:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5A40
	cmp r1, #0
	blt _081B5A40
	ldr r0, _081B5A44 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5A40
	ldr r0, _081B5A48 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5A4C
_081B5A40:
	movs r5, #0
	b _081B5A5A
	.align 2, 0
_081B5A44: .4byte 0x030046A8
_081B5A48: .4byte 0x030046AC
_081B5A4C:
	ldr r0, _081B5AEC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B5A5A:
	movs r2, #0
_081B5A5C:
	ldr r3, _081B5AF0 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B5A7C
	ldr r1, _081B5AF4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B5A7C
	b _081B5D90
_081B5A7C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x78]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B5A90
	b _081B60AC
_081B5A90:
	ldr r5, _081B5AF8 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081B5AFC
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r0, [sp, #0x7c]
	str r1, [r0]
	ldr r1, [sp, #0x80]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B5C4A
	.align 2, 0
_081B5AEC: .4byte 0x030046A4
_081B5AF0: .4byte 0x00000256
_081B5AF4: .4byte 0x03002BE0
_081B5AF8: .4byte 0x00000222
_081B5AFC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	str r1, [r4]
	ldr r1, [sp, #0x80]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5B60
	cmp r1, #0
	blt _081B5B60
	ldr r0, _081B5B64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5B60
	ldr r0, _081B5B68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5B6C
_081B5B60:
	movs r4, #0
	b _081B5B7A
	.align 2, 0
_081B5B64: .4byte 0x030046A8
_081B5B68: .4byte 0x030046AC
_081B5B6C:
	ldr r0, _081B5B8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5B7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5B90
	adds r0, #4
	b _081B5B9C
	.align 2, 0
_081B5B8C: .4byte 0x030046A4
_081B5B90:
	ldr r0, _081B5BB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5B9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5BB4
	cmp r2, #2
	beq _081B5BB8
	b _081B5BBC
	.align 2, 0
_081B5BB0: .4byte 0x030046A4
_081B5BB4:
	ldrb r0, [r5, #4]
	b _081B5BBA
_081B5BB8:
	ldrb r0, [r5]
_081B5BBA:
	subs r1, r1, r0
_081B5BBC:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5BE4
	cmp r1, #0
	blt _081B5BE4
	ldr r0, _081B5BE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5BE4
	ldr r0, _081B5BEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5BF0
_081B5BE4:
	movs r4, #0
	b _081B5BFE
	.align 2, 0
_081B5BE8: .4byte 0x030046A8
_081B5BEC: .4byte 0x030046AC
_081B5BF0:
	ldr r0, _081B5C10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5BFE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5C14
	adds r0, #4
	b _081B5C20
	.align 2, 0
_081B5C10: .4byte 0x030046A4
_081B5C14:
	ldr r0, _081B5C34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5C20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B5C38
	cmp r3, #2
	beq _081B5C3C
	b _081B5C40
	.align 2, 0
_081B5C34: .4byte 0x030046A4
_081B5C38:
	ldrb r0, [r5, #4]
	b _081B5C3E
_081B5C3C:
	ldrb r0, [r5]
_081B5C3E:
	subs r2, r2, r0
_081B5C40:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B5C4A:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B5D54
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B5C74
	movs r0, #1
	b _081B5C76
_081B5C74:
	movs r0, #0
_081B5C76:
	ldr r3, _081B5D64 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B5D54
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B5D68 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B5D6C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _081B5D70 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r4, _081B5D74 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _081B5D78 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x60]
	ldr r0, _081B5D7C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x84]
	ldr r1, _081B5D80 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r6, _081B5D84 @ =0x0203B400
	ldr r1, _081B5D88 @ =0x030046B8
	ldr r2, _081B5D8C @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081B5CC6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081B5CE4
	adds r3, #1
	cmp r3, #3
	ble _081B5CC6
	mov r0, r8
_081B5CE4:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x68]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x70]
	strb r0, [r5]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x60]
	strb r1, [r0]
	ldr r1, [sp, #0x84]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	str r2, [r5]
	movs r2, #0
	ldr r0, [sp, #0x80]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x64]
	strb r0, [r4]
_081B5D54:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x58]
	strh r0, [r5]
	b _081B60AC
	.align 2, 0
_081B5D64: .4byte 0x00000482
_081B5D68: .4byte 0x0000054F
_081B5D6C: .4byte 0x0000054C
_081B5D70: .4byte 0x0000054D
_081B5D74: .4byte 0x0000054E
_081B5D78: .4byte 0x00000541
_081B5D7C: .4byte 0x000005BC
_081B5D80: .4byte 0x00000542
_081B5D84: .4byte 0x0203B400
_081B5D88: .4byte 0x030046B8
_081B5D8C: .4byte 0x000003FF
_081B5D90:
	mov sb, sp
	ldr r6, _081B5DCC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5DD0
	adds r0, #4
	b _081B5DDA
	.align 2, 0
_081B5DCC: .4byte 0x030046A4
_081B5DD0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B5DDA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _081B5E14 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081B5E1C
	ldr r0, _081B5E18 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B5E46
	.align 2, 0
_081B5E14: .4byte 0x000004A4
_081B5E18: .4byte 0xFFFFFDFF
_081B5E1C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081B5E3C
	cmp r0, #2
	beq _081B5E38
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B5E38:
	movs r0, #1
	b _081B5E48
_081B5E3C:
	ldr r0, _081B5E5C @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B5E46:
	movs r0, #0
_081B5E48:
	cmp r0, #0
	beq _081B5E4E
	b _081B60AC
_081B5E4E:
	ldr r4, _081B5E60 @ =0x000005C4
	adds r0, r7, r4
_081B5E52:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B60AC
	.align 2, 0
_081B5E5C: .4byte 0xFFFFFDFF
_081B5E60: .4byte 0x000005C4
_081B5E64:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, _081B5F7C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x28]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081B5F80 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r0, _081B5F84 @ =0x00000484
	adds r0, r7, r0
	str r0, [sp, #0x30]
	str r5, [r0]
	ldr r1, _081B5F88 @ =0x0000046C
	adds r1, r7, r1
	str r1, [sp, #0x34]
	strb r3, [r1]
	ldr r1, _081B5F8C @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _081B5F90 @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _081B5F94 @ =0x0000046B
	adds r3, r3, r7
	mov ip, r3
	strb r5, [r3]
	ldr r4, _081B5F98 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B5F9C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B5FA0 @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	subs r5, #0xd2
	adds r0, r7, r5
	movs r1, #1
	strh r1, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r4, [sp, #0x78]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r5, #0x26
	adds r0, r7, r5
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
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x44]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x48]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x50]
	mov r4, ip
	str r4, [sp, #0x4c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x74]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	mov r4, r8
	str r4, [sp, #0x80]
	cmp r2, #0
	blt _081B5F76
	cmp r1, #0
	blt _081B5F76
	ldr r0, _081B5FA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5F76
	ldr r0, _081B5FA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5FAC
_081B5F76:
	movs r4, #0
	b _081B5FBA
	.align 2, 0
_081B5F7C: .4byte 0x00000469
_081B5F80: .4byte 0x0000046A
_081B5F84: .4byte 0x00000484
_081B5F88: .4byte 0x0000046C
_081B5F8C: .4byte FUN_080e6794
_081B5F90: .4byte 0x0000046D
_081B5F94: .4byte 0x0000046B
_081B5F98: .4byte 0x00000553
_081B5F9C: .4byte 0x00000551
_081B5FA0: .4byte 0x00000552
_081B5FA4: .4byte 0x030046A8
_081B5FA8: .4byte 0x030046AC
_081B5FAC:
	ldr r0, _081B5FCC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5FBA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B5FD0
	adds r0, #4
	b _081B5FDC
	.align 2, 0
_081B5FCC: .4byte 0x030046A4
_081B5FD0:
	ldr r0, _081B5FF0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5FDC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5FF4
	cmp r2, #2
	beq _081B5FF8
	b _081B5FFC
	.align 2, 0
_081B5FF0: .4byte 0x030046A4
_081B5FF4:
	ldrb r0, [r5, #4]
	b _081B5FFA
_081B5FF8:
	ldrb r0, [r5]
_081B5FFA:
	subs r1, r1, r0
_081B5FFC:
	strh r1, [r5, #2]
	ldr r5, _081B602C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081B6034
	ldr r0, _081B6030 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B605E
	.align 2, 0
_081B602C: .4byte 0x000004A4
_081B6030: .4byte 0xFFFFFDFF
_081B6034:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B6054
	cmp r0, #2
	beq _081B6050
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B6050:
	movs r0, #1
	b _081B6060
_081B6054:
	ldr r0, _081B6098 @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B605E:
	movs r0, #0
_081B6060:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B60A0
	ldr r0, _081B609C @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r1, [sp, #0x74]
	strb r3, [r1]
	ldr r4, [sp, #0x7c]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x80]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081B60AC
	.align 2, 0
_081B6098: .4byte 0xFFFFFDFF
_081B609C: .4byte FUN_080e48d0
_081B60A0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B60AC:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b60bc
FUN_081b60bc: @ 0x081B60BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd0
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081B60E4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B60E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B60EA
	.align 2, 0
_081B60E4: .4byte 0x0000046D
_081B60E8:
	movs r0, #0
_081B60EA:
	cmp r0, #0
	beq _081B6126
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B6114
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B6114:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	ldr r3, _081B61F8 @ =0x0000046E
	adds r0, r7, r3
	strb r1, [r0]
_081B6126:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	mov sb, r2
	cmp r6, #0x11
	bgt _081B6166
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _081B6166
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B6166
	cmp r2, #1
	beq _081B6166
	strh r3, [r5, #0xe]
_081B6166:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B61D8
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B61D8
	ldr r2, _081B61FC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B6200 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _081B6204 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B6208 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B620C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl FUN_080ddcc8
_081B61D8:
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081B6210
	asrs r0, r0, #2
	b _081B6216
	.align 2, 0
_081B61F8: .4byte 0x0000046E
_081B61FC: .4byte 0xFFFF0000
_081B6200: .4byte 0x0000FFFF
_081B6204: .4byte 0x030046B8
_081B6208: .4byte 0x000003FF
_081B620C: .4byte 0x0203B400
_081B6210:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B6216:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081B6236
	asrs r0, r0, #2
	b _081B623C
_081B6236:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B623C:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081B6246
	movs r3, #0xc8
	b _081B6250
_081B6246:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081B6250
	adds r3, r0, #0
_081B6250:
	cmp r2, #0xc8
	ble _081B6258
	movs r2, #0xc8
	b _081B6262
_081B6258:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081B6262
	adds r2, r0, #0
_081B6262:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081B6286
	cmp r2, #0
	bne _081B6286
	movs r0, #1
	b _081B6288
_081B6286:
	movs r0, #0
_081B6288:
	cmp r0, #0
	bne _081B6290
	bl _081B71C4
_081B6290:
	ldr r6, _081B62EC @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B629E
	bl _081B71C4
_081B629E:
	ldr r1, _081B62F0 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _081B62F4 @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	mov r5, sb
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r3, [r5]
	ands r3, r0
	str r3, [r5]
	ldr r1, _081B62F8 @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	str r2, [sp, #0xa8]
	cmp r4, #0
	beq _081B62FC
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081B71C4
	.align 2, 0
_081B62EC: .4byte 0x0000046E
_081B62F0: .4byte 0x0000046B
_081B62F4: .4byte 0xFFFFFEDF
_081B62F8: .4byte 0x0000049C
_081B62FC:
	movs r0, #8
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B6388
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _081B636C @ =0x00000469
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _081B6370 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _081B6374 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	mov r5, r8
	strb r5, [r0]
	ldr r2, _081B6378 @ =FUN_081b570c
	movs r1, #0x14
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _081B637C @ =0x0000046B
	adds r0, r7, r5
	strb r6, [r0]
	ldr r6, _081B6380 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _081B6384 @ =0x00000482
	adds r0, r7, r4
	mov r5, r8
	strh r5, [r0]
	bl _081B71C4
	.align 2, 0
_081B636C: .4byte 0x00000469
_081B6370: .4byte 0x0000046A
_081B6374: .4byte 0x00000484
_081B6378: .4byte FUN_081b570c
_081B637C: .4byte 0x0000046B
_081B6380: .4byte 0x00000553
_081B6384: .4byte 0x00000482
_081B6388:
	movs r2, #0x80
	ands r1, r2
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081B6396
	b _081B6AA8
_081B6396:
	orrs r3, r2
	str r3, [r5]
	movs r0, #4
	ldr r6, _081B63F8 @ =0x00000222
	adds r4, r7, r6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	str r4, [sp, #0xc0]
	cmp r0, #0
	bne _081B63B8
	bl _081B71C4
_081B63B8:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r4, #0
	blt _081B63F4
	cmp r1, #0
	blt _081B63F4
	ldr r0, _081B63FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B63F4
	ldr r0, _081B6400 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6404
_081B63F4:
	movs r4, #0
	b _081B6412
	.align 2, 0
_081B63F8: .4byte 0x00000222
_081B63FC: .4byte 0x030046A8
_081B6400: .4byte 0x030046AC
_081B6404:
	ldr r0, _081B6424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B6412:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B6428
	adds r0, #4
	b _081B6434
	.align 2, 0
_081B6424: .4byte 0x030046A4
_081B6428:
	ldr r0, _081B6448 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6434:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B644C
	cmp r2, #2
	beq _081B6450
	b _081B6454
	.align 2, 0
_081B6448: .4byte 0x030046A4
_081B644C:
	ldrb r0, [r5, #4]
	b _081B6452
_081B6450:
	ldrb r0, [r5]
_081B6452:
	subs r1, r1, r0
_081B6454:
	strh r1, [r5, #2]
	ldr r0, _081B6468 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B646C
	movs r0, #1
	b _081B646E
	.align 2, 0
_081B6468: .4byte 0x030047A4
_081B646C:
	movs r0, #0
_081B646E:
	cmp r0, #0
	beq _081B64AC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B648E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B648A
	adds r2, r0, #0
_081B648A:
	cmp r2, #0
	bge _081B6498
_081B648E:
	ldr r2, _081B6494 @ =0x000005C4
	adds r0, r7, r2
	b _081B69B8
	.align 2, 0
_081B6494: .4byte 0x000005C4
_081B6498:
	ldr r1, _081B64A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B64F4
	.align 2, 0
_081B64A8: .4byte 0x03002BE0
_081B64AC:
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
	blt _081B64D8
	cmp r1, #0
	blt _081B64D8
	ldr r0, _081B64DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B64D8
	ldr r0, _081B64E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B64E4
_081B64D8:
	movs r5, #0
	b _081B64F2
	.align 2, 0
_081B64DC: .4byte 0x030046A8
_081B64E0: .4byte 0x030046AC
_081B64E4:
	ldr r0, _081B652C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B64F2:
	movs r2, #0
_081B64F4:
	ldr r4, _081B6530 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B6514
	ldr r1, _081B6534 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B6514
	b _081B68F4
_081B6514:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xa8]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081B6538
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B652C: .4byte 0x030046A4
_081B6530: .4byte 0x00000256
_081B6534: .4byte 0x03002BE0
_081B6538:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xc0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081B65E8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081B65D8 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x28]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081B65DC @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	mov r0, sb
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081B65E0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081B65E4 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x28]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x34]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B67B2
	.align 2, 0
_081B65D8: .4byte 0x0000046D
_081B65DC: .4byte 0x0000046B
_081B65E0: .4byte 0x00000469
_081B65E4: .4byte 0x00000484
_081B65E8:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B66A8 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B66AC @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x38]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x44]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081B66B0 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _081B66B4 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081B66B8 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x4c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x4c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x40]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x44]
	str r4, [sp, #0xac]
	mov r5, ip
	cmp r5, #0
	blt _081B66A4
	cmp r1, #0
	blt _081B66A4
	ldr r0, _081B66BC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081B66A4
	ldr r0, _081B66C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B66C4
_081B66A4:
	movs r4, #0
	b _081B66D4
	.align 2, 0
_081B66A8: .4byte 0x0000046D
_081B66AC: .4byte 0x0000046B
_081B66B0: .4byte 0x00000469
_081B66B4: .4byte 0x0000046A
_081B66B8: .4byte 0x00000484
_081B66BC: .4byte 0x030046A8
_081B66C0: .4byte 0x030046AC
_081B66C4:
	ldr r0, _081B66E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_081B66D4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B66E8
	adds r0, #4
	b _081B66F4
	.align 2, 0
_081B66E4: .4byte 0x030046A4
_081B66E8:
	ldr r0, _081B6708 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B66F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B670C
	cmp r2, #2
	beq _081B6712
	b _081B6718
	.align 2, 0
_081B6708: .4byte 0x030046A4
_081B670C:
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2, #4]
	b _081B6716
_081B6712:
	ldr r3, [sp, #0x4c]
	ldrb r0, [r3]
_081B6716:
	subs r1, r1, r0
_081B6718:
	ldr r4, [sp, #0x4c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6744
	cmp r1, #0
	blt _081B6744
	ldr r0, _081B6748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6744
	ldr r0, _081B674C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6750
_081B6744:
	movs r4, #0
	b _081B675E
	.align 2, 0
_081B6748: .4byte 0x030046A8
_081B674C: .4byte 0x030046AC
_081B6750:
	ldr r0, _081B6774 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B675E:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B6778
	adds r0, #4
	b _081B6784
	.align 2, 0
_081B6774: .4byte 0x030046A4
_081B6778:
	ldr r0, _081B6798 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6784:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B679C
	cmp r3, #2
	beq _081B67A0
	b _081B67A4
	.align 2, 0
_081B6798: .4byte 0x030046A4
_081B679C:
	ldrb r0, [r5, #4]
	b _081B67A2
_081B67A0:
	ldrb r0, [r5]
_081B67A2:
	subs r2, r2, r0
_081B67A4:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B67B2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x50]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B67DC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B68BC
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B67E0
	movs r0, #1
	b _081B67E2
	.align 2, 0
_081B67DC: .4byte 0x00000482
_081B67E0:
	movs r0, #0
_081B67E2:
	ldr r3, _081B68CC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B68BC
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B68D0 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B68D4 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B68D8 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B68DC @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B68E0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B68E4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B68E8 @ =0x030046B8
	adds r2, r5, #0
_081B682A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B68EC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B68F0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B684E
	adds r3, #1
	cmp r3, #3
	ble _081B682A
	adds r0, r5, #0
_081B684E:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x50
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B68BC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B68CC: .4byte 0x00000482
_081B68D0: .4byte 0x0000054F
_081B68D4: .4byte 0x0000054C
_081B68D8: .4byte 0x0000054E
_081B68DC: .4byte 0x00000541
_081B68E0: .4byte 0x000005BC
_081B68E4: .4byte 0x00000542
_081B68E8: .4byte 0x030046B8
_081B68EC: .4byte 0x000003FF
_081B68F0: .4byte 0x0203B400
_081B68F4:
	add r6, sp, #0x18
	ldr r0, _081B6934 @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B6938
	adds r0, #4
	b _081B6944
	.align 2, 0
_081B6934: .4byte 0x030046A4
_081B6938:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B6944:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B697C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B6984
	ldr r0, _081B6980 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B69AE
	.align 2, 0
_081B697C: .4byte 0x000004A4
_081B6980: .4byte 0xFFFFFDFF
_081B6984:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B69A4
	cmp r0, #2
	beq _081B69A0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B69A0:
	movs r0, #1
	b _081B69B0
_081B69A4:
	ldr r0, _081B69C4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B69AE:
	movs r0, #0
_081B69B0:
	cmp r0, #0
	bne _081B69CC
	ldr r3, _081B69C8 @ =0x000005C4
	adds r0, r7, r3
_081B69B8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B69C4: .4byte 0xFFFFFDFF
_081B69C8: .4byte 0x000005C4
_081B69CC:
	movs r0, #1
_081B69CE:
	cmp r0, #0
	bne _081B6A3E
	ldr r4, _081B6A04 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B6A0C
	ldr r0, _081B6A08 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B6A36
	.align 2, 0
_081B6A04: .4byte 0x000004A4
_081B6A08: .4byte 0xFFFFFDFF
_081B6A0C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B6A2C
	cmp r0, #2
	beq _081B6A28
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B6A28:
	movs r0, #1
	b _081B6A38
_081B6A2C:
	ldr r0, _081B6A94 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B6A36:
	movs r0, #0
_081B6A38:
	cmp r0, #0
	bne _081B6A3E
	b _081B7154
_081B6A3E:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081B6A98 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081B6A9C @ =0x0000046B
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
	ldr r1, _081B6AA0 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B6AA4 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081B71C4
	.align 2, 0
_081B6A94: .4byte 0xFFFFFDFF
_081B6A98: .4byte 0x0000046D
_081B6A9C: .4byte 0x0000046B
_081B6AA0: .4byte 0x0000046A
_081B6AA4: .4byte 0x00000484
_081B6AA8:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B6AB6
	b _081B71C4
_081B6AB6:
	movs r1, #0x10
	mov r6, sb
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r1
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
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r4, #0
	blt _081B6B02
	cmp r1, #0
	blt _081B6B02
	ldr r0, _081B6B08 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B6B02
	ldr r0, _081B6B0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6B10
_081B6B02:
	movs r4, #0
	b _081B6B1E
	.align 2, 0
_081B6B08: .4byte 0x030046A8
_081B6B0C: .4byte 0x030046AC
_081B6B10:
	ldr r0, _081B6B30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B6B1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B6B34
	adds r0, #4
	b _081B6B40
	.align 2, 0
_081B6B30: .4byte 0x030046A4
_081B6B34:
	ldr r0, _081B6B54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6B40:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B6B58
	cmp r2, #2
	beq _081B6B5C
	b _081B6B60
	.align 2, 0
_081B6B54: .4byte 0x030046A4
_081B6B58:
	ldrb r0, [r5, #4]
	b _081B6B5E
_081B6B5C:
	ldrb r0, [r5]
_081B6B5E:
	subs r1, r1, r0
_081B6B60:
	strh r1, [r5, #2]
	ldr r0, _081B6B74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B6B78
	movs r0, #1
	b _081B6B7A
	.align 2, 0
_081B6B74: .4byte 0x030047A4
_081B6B78:
	movs r0, #0
_081B6B7A:
	cmp r0, #0
	beq _081B6BB0
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B6B8C
	b _081B70CC
_081B6B8C:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B6B98
	adds r2, r0, #0
_081B6B98:
	cmp r2, #0
	bge _081B6B9E
	b _081B70CC
_081B6B9E:
	ldr r1, _081B6BAC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B6BF8
	.align 2, 0
_081B6BAC: .4byte 0x03002BE0
_081B6BB0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6BDC
	cmp r1, #0
	blt _081B6BDC
	ldr r0, _081B6BE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6BDC
	ldr r0, _081B6BE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6BE8
_081B6BDC:
	movs r5, #0
	b _081B6BF6
	.align 2, 0
_081B6BE0: .4byte 0x030046A8
_081B6BE4: .4byte 0x030046AC
_081B6BE8:
	ldr r0, _081B6C30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B6BF6:
	movs r2, #0
_081B6BF8:
	ldr r6, _081B6C34 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B6C18
	ldr r1, _081B6C38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B6C18
	b _081B700C
_081B6C18:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081B6C3C
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B6C30: .4byte 0x030046A4
_081B6C34: .4byte 0x00000256
_081B6C38: .4byte 0x03002BE0
_081B6C3C:
	ldr r3, _081B6CE0 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xc0]
	cmp r6, #0
	beq _081B6CFC
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B6CE4 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B6CE8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B6CEC @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x60]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x64]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B6CF0 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B6CF4 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081B6CF8 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x58]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x64]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B6ECA
	.align 2, 0
_081B6CE0: .4byte 0x00000222
_081B6CE4: .4byte 0x0000046D
_081B6CE8: .4byte 0x0000046B
_081B6CEC: .4byte 0x00000553
_081B6CF0: .4byte 0x00000469
_081B6CF4: .4byte 0x00000484
_081B6CF8: .4byte 0x0000046C
_081B6CFC:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B6DBC @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B6DC0 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B6DC4 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081B6DC8 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B6DCC @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B6DD0 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0xac]
	mov r5, sl
	cmp r5, #0
	blt _081B6DB8
	cmp r1, #0
	blt _081B6DB8
	ldr r0, _081B6DD4 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081B6DB8
	ldr r0, _081B6DD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6DDC
_081B6DB8:
	movs r4, #0
	b _081B6DEC
	.align 2, 0
_081B6DBC: .4byte 0x0000046D
_081B6DC0: .4byte 0x0000046B
_081B6DC4: .4byte 0x00000469
_081B6DC8: .4byte 0x0000046A
_081B6DCC: .4byte 0x00000484
_081B6DD0: .4byte 0x0000046C
_081B6DD4: .4byte 0x030046A8
_081B6DD8: .4byte 0x030046AC
_081B6DDC:
	ldr r0, _081B6DFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081B6DEC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B6E00
	adds r0, #4
	b _081B6E0C
	.align 2, 0
_081B6DFC: .4byte 0x030046A4
_081B6E00:
	ldr r0, _081B6E20 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6E0C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B6E24
	cmp r2, #2
	beq _081B6E2A
	b _081B6E30
	.align 2, 0
_081B6E20: .4byte 0x030046A4
_081B6E24:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081B6E2E
_081B6E2A:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081B6E2E:
	subs r1, r1, r0
_081B6E30:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6E5C
	cmp r1, #0
	blt _081B6E5C
	ldr r0, _081B6E60 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6E5C
	ldr r0, _081B6E64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6E68
_081B6E5C:
	movs r4, #0
	b _081B6E76
	.align 2, 0
_081B6E60: .4byte 0x030046A8
_081B6E64: .4byte 0x030046AC
_081B6E68:
	ldr r0, _081B6E8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B6E76:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B6E90
	adds r0, #4
	b _081B6E9C
	.align 2, 0
_081B6E8C: .4byte 0x030046A4
_081B6E90:
	ldr r0, _081B6EB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6E9C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B6EB4
	cmp r3, #2
	beq _081B6EB8
	b _081B6EBC
	.align 2, 0
_081B6EB0: .4byte 0x030046A4
_081B6EB4:
	ldrb r0, [r5, #4]
	b _081B6EBA
_081B6EB8:
	ldrb r0, [r5]
_081B6EBA:
	subs r2, r2, r0
_081B6EBC:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B6ECA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B6EF4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B6FD4
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B6EF8
	movs r0, #1
	b _081B6EFA
	.align 2, 0
_081B6EF4: .4byte 0x00000482
_081B6EF8:
	movs r0, #0
_081B6EFA:
	ldr r3, _081B6FE4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B6FD4
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B6FE8 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B6FEC @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B6FF0 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B6FF4 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B6FF8 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B6FFC @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B7000 @ =0x030046B8
	adds r2, r5, #0
_081B6F42:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B7004 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B7008 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B6F66
	adds r3, #1
	cmp r3, #3
	ble _081B6F42
	adds r0, r5, #0
_081B6F66:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B6FD4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B6FE4: .4byte 0x00000482
_081B6FE8: .4byte 0x0000054F
_081B6FEC: .4byte 0x0000054C
_081B6FF0: .4byte 0x0000054E
_081B6FF4: .4byte 0x00000541
_081B6FF8: .4byte 0x000005BC
_081B6FFC: .4byte 0x00000542
_081B7000: .4byte 0x030046B8
_081B7004: .4byte 0x000003FF
_081B7008: .4byte 0x0203B400
_081B700C:
	add r6, sp, #0x20
	ldr r0, _081B704C @ =0x030046A4
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
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081B7050
	adds r0, #4
	b _081B705C
	.align 2, 0
_081B704C: .4byte 0x030046A4
_081B7050:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B705C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B7094 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081B709C
	ldr r0, _081B7098 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B70C6
	.align 2, 0
_081B7094: .4byte 0x000004A4
_081B7098: .4byte 0xFFFFFDFF
_081B709C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081B70BC
	cmp r0, #2
	beq _081B70B8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B70B8:
	movs r0, #1
	b _081B70C8
_081B70BC:
	ldr r0, _081B70DC @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B70C6:
	movs r0, #0
_081B70C8:
	cmp r0, #0
	bne _081B70E4
_081B70CC:
	ldr r3, _081B70E0 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B70DC: .4byte 0xFFFFFDFF
_081B70E0: .4byte 0x000005C4
_081B70E4:
	movs r0, #1
_081B70E6:
	cmp r0, #0
	bne _081B716C
	ldr r4, _081B711C @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081B7124
	ldr r0, _081B7120 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B714E
	.align 2, 0
_081B711C: .4byte 0x000004A4
_081B7120: .4byte 0xFFFFFDFF
_081B7124:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B7144
	cmp r0, #2
	beq _081B7140
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B7140:
	movs r0, #1
	b _081B7150
_081B7144:
	ldr r0, _081B7164 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B714E:
	movs r0, #0
_081B7150:
	cmp r0, #0
	bne _081B716C
_081B7154:
	ldr r4, _081B7168 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B71C4
	.align 2, 0
_081B7164: .4byte 0xFFFFFDFF
_081B7168: .4byte 0x000005C4
_081B716C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B71D4 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B71D8 @ =0x0000046B
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
	ldr r6, _081B71DC @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B71E0 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B71E4 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B71C4:
	add sp, #0xd0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B71D4: .4byte 0x0000046D
_081B71D8: .4byte 0x0000046B
_081B71DC: .4byte 0x00000469
_081B71E0: .4byte 0x0000046A
_081B71E4: .4byte 0x00000484

	thumb_func_start FUN_081b71e8
FUN_081b71e8: @ 0x081B71E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081b39e8
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B720C
	ldr r1, _081B723C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B722C
_081B720C:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _081B7240 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_081B722C:
	adds r0, r4, #0
	bl FUN_081b3be0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081B723C: .4byte 0x000004BE
_081B7240: .4byte 0x0000062C

	thumb_func_start FUN_081b7244
FUN_081b7244: @ 0x081B7244
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyBokuLink_Destroy
EnemyBokuLink_Destroy: @ 0x081B7250
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081B7268 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B726C
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081B7274
	.align 2, 0
_081B7268: .4byte 0x0000025D
_081B726C:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081B7274:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081B7290 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081B7294
	movs r0, #1
	b _081B7296
	.align 2, 0
_081B7290: .4byte 0x00000474
_081B7294:
	movs r0, #0
_081B7296:
	cmp r0, #0
	beq _081B72A2
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081B72A2:
	ldr r1, _081B72FC @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081B72BA
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081B72BA:
	ldr r0, _081B7300 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081B72D2
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081B72D2:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B72EA
	adds r0, r4, #0
	bl FUN_08002a58
_081B72EA:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081B7304
	movs r0, #1
	b _081B7306
	.align 2, 0
_081B72FC: .4byte 0x0000044C
_081B7300: .4byte 0x0000044D
_081B7304:
	movs r0, #0
_081B7306:
	cmp r0, #0
	beq _081B7312
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081B7312:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyBokuLink_Init
EnemyBokuLink_Init: @ 0x081B7330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	ldr r1, _081B73B8 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_081b33ec
	adds r0, r7, #0
	bl FUN_081b3924
	ldr r2, _081B73BC @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B73CC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081B73C0 @ =0x00009247
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081B73C4 @ =0x00001DF8
	bl FUN_080e3804
	ldr r3, _081B73C8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0xac]
	cmp r1, #0x11
	beq _081B73A8
	cmp r1, #0x17
	bne _081B73AC
_081B73A8:
	movs r0, #1
	strb r0, [r5, #7]
_081B73AC:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081B7434
	.align 2, 0
_081B73B8: .4byte 0x0000065C
_081B73BC: .4byte 0x0000025D
_081B73C0: .4byte 0x00009247
_081B73C4: .4byte 0x00001DF8
_081B73C8: .4byte 0x000001DF
_081B73CC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081B74B0 @ =0x05000002
	bl CpuSet
	ldr r0, _081B74B4 @ =0x0000CB05
	ldr r1, _081B74B8 @ =0x00009247
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r2!, {r3, r6}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r5, r8
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r6, _081B74BC @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0xac]
_081B7434:
	str r7, [sp, #0x2c]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r4, #0
	str r4, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	str r4, [r2]
	ldr r3, _081B74C0 @ =0x0000046F
	adds r0, r7, r3
	strb r4, [r0]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r6, #0
	mov sl, r6
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _081B74C4 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081B74B0 @ =0x05000002
	bl CpuSet
	ldr r3, _081B74C8 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x6c]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _081B74A0
	b _081B75FC
_081B74A0:
	bl VM_GetPC
	cmp r0, #0
	beq _081B74CC
	bl Script_GetValue
	adds r1, r0, #0
	b _081B74CE
	.align 2, 0
_081B74B0: .4byte 0x05000002
_081B74B4: .4byte 0x0000CB05
_081B74B8: .4byte 0x00009247
_081B74BC: .4byte 0x000004B7
_081B74C0: .4byte 0x0000046F
_081B74C4: .4byte 0x00000474
_081B74C8: .4byte 0x000004B6
_081B74CC:
	movs r1, #0
_081B74CE:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081B74F4 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc8]
	str r4, [sp, #0xcc]
	cmp r0, #0
	beq _081B74F8
	bl Script_GetValue
	adds r1, r0, #0
	b _081B74FA
	.align 2, 0
_081B74F4: .4byte 0x00000251
_081B74F8:
	movs r1, #0
_081B74FA:
	ldr r2, _081B7530 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081B7534 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xc8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _081B7538
	bl Script_GetValue
	b _081B753C
	.align 2, 0
_081B7530: .4byte 0x00000252
_081B7534: .4byte 0x000004B4
_081B7538:
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
_081B753C:
	strb r0, [r6]
	ldr r5, [sp, #0xc8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd0]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B7574
	cmp r1, #0
	blt _081B7574
	ldr r0, _081B7578 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B7574
	ldr r0, _081B757C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B7580
_081B7574:
	movs r1, #0
	b _081B758E
	.align 2, 0
_081B7578: .4byte 0x030046A8
_081B757C: .4byte 0x030046AC
_081B7580:
	ldr r0, _081B75A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081B758E:
	ldr r2, _081B75AC @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B75B0
	adds r0, #4
	b _081B75BC
	.align 2, 0
_081B75A8: .4byte 0x030046A4
_081B75AC: .4byte 0x00000256
_081B75B0:
	ldr r0, _081B75D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B75BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B75D4
	cmp r2, #2
	beq _081B75D8
	b _081B75DC
	.align 2, 0
_081B75D0: .4byte 0x030046A4
_081B75D4:
	ldrb r0, [r4, #4]
	b _081B75DA
_081B75D8:
	ldrb r0, [r4]
_081B75DA:
	subs r1, r1, r0
_081B75DC:
	ldr r3, _081B75F4 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081B75F8 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _081B763C
	.align 2, 0
_081B75F4: .4byte 0x00000472
_081B75F8: .4byte 0x0000FFFF
_081B75FC:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081B7660 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081B7664 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081B7668 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x30]
	str r5, [sp, #0xc8]
	str r4, [sp, #0xcc]
	str r3, [sp, #0xd0]
_081B763C:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B7686
	bl VM_GetPC
	cmp r0, #0
	beq _081B766C
	bl Script_GetValue
	adds r4, r0, #0
	b _081B766E
	.align 2, 0
_081B7660: .4byte 0x00000251
_081B7664: .4byte 0x00000252
_081B7668: .4byte 0x000004B4
_081B766C:
	movs r4, #0x30
_081B766E:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7680
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081B7682
_081B7680:
	movs r5, #0x40
_081B7682:
	mov r8, r4
	b _081B768C
_081B7686:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081B768C:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B76C4
	bl VM_GetPC
	cmp r0, #0
	beq _081B76A6
	bl Script_GetValue
	adds r6, r0, #0
	b _081B76A8
_081B76A6:
	movs r6, #0
_081B76A8:
	bl VM_GetPC
	cmp r0, #0
	beq _081B76B8
	bl Script_GetValue
	adds r1, r0, #0
	b _081B76BA
_081B76B8:
	movs r1, #0
_081B76BA:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081B76CE
_081B76C4:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081B76CE:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _081B7954 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x98]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa4]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa8]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _081B7958 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x190]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r1, _081B795C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081B7960 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r3, _081B7964 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _081B7968 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x50]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _081B796C @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _081B7970 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _081B7974 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x148]
	ldr r3, _081B7978 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x150]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	ldr r5, _081B797C @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _081B7980 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	ldr r2, _081B7984 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x110]
	ldr r3, _081B7988 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x188]
	ldr r5, _081B798C @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xb8]
	ldr r6, _081B7990 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081B7994 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x168]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _081B7998 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x180]
	ldr r6, _081B799C @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _081B79A0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x140]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x164]
	ldr r5, _081B79A4 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x170]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081B79A8 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _081B79AC @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081B79B0 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x120]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x124]
	ldr r2, _081B79B4 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x128]
	ldr r3, _081B79B8 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x138]
	ldr r4, _081B79BC @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, [sp, #0x28]
	adds r5, #8
	str r5, [sp, #0x194]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _081B79C0 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081B79C4 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081B79C8 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081B79CC @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	ldr r4, _081B79D0 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x104]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _081B79D4 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _081B79D8 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xe8]
	ldr r4, _081B79DC @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _081B79E0 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081B79E4 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _081B79E8 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	cmp r0, #0
	bne _081B7924
	b _081B7A44
_081B7924:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_081B7944:
	bl VM_GetPC
	cmp r0, #0
	beq _081B79EC
	bl Script_GetValue
	b _081B79EE
	.align 2, 0
_081B7954: .4byte 0x0000025D
_081B7958: .4byte 0x0000025A
_081B795C: .4byte 0x0000047A
_081B7960: .4byte 0x0000047C
_081B7964: .4byte 0x0000047E
_081B7968: .4byte 0x00000476
_081B796C: .4byte 0x000004A4
_081B7970: .4byte 0x000005A4
_081B7974: .4byte 0x000005C4
_081B7978: .4byte 0x000005CC
_081B797C: .4byte 0x000005D4
_081B7980: .4byte 0x000005DC
_081B7984: .4byte 0x00000584
_081B7988: .4byte 0x00000604
_081B798C: .4byte 0x0000021D
_081B7990: .4byte 0x0000060C
_081B7994: .4byte 0x000005E4
_081B7998: .4byte 0x000005FC
_081B799C: .4byte 0x00000614
_081B79A0: .4byte 0x000005BC
_081B79A4: .4byte 0x000005EC
_081B79A8: .4byte 0x00000624
_081B79AC: .4byte 0x0000058C
_081B79B0: .4byte 0x00000594
_081B79B4: .4byte 0x0000059C
_081B79B8: .4byte 0x000005B4
_081B79BC: .4byte 0x00000543
_081B79C0: .4byte 0x00000496
_081B79C4: .4byte 0x00000469
_081B79C8: .4byte 0x0000046A
_081B79CC: .4byte 0x00000553
_081B79D0: .4byte 0x00000572
_081B79D4: .4byte 0x0000055C
_081B79D8: .4byte 0x00000564
_081B79DC: .4byte 0x00000565
_081B79E0: .4byte 0x00000566
_081B79E4: .4byte 0x00000567
_081B79E8: .4byte 0x0000056C
_081B79EC:
	movs r0, #0x18
_081B79EE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A00
	bl Script_GetValue
	b _081B7A02
_081B7A00:
	movs r0, #0x18
_081B7A02:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A14
	bl Script_GetValue
	b _081B7A16
_081B7A14:
	movs r0, #0
_081B7A16:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A28
	bl Script_GetValue
	b _081B7A2A
_081B7A28:
	movs r0, #0
_081B7A2A:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _081B7A44
	b _081B7944
_081B7A44:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B7A90
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A5E
	bl Script_GetValue
	adds r4, r0, #0
	b _081B7A62
_081B7A5E:
	movs r4, #0x96
	lsls r4, r4, #1
_081B7A62:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A72
	bl Script_GetValue
	adds r6, r0, #0
	b _081B7A76
_081B7A72:
	movs r6, #0x96
	lsls r6, r6, #1
_081B7A76:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A84
	bl Script_GetValue
	b _081B7A8A
_081B7A84:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081B7A8A:
	ldr r2, [sp, #0xc0]
	strh r0, [r2]
	b _081B7A98
_081B7A90:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc0]
	strh r6, [r3]
_081B7A98:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081B7AB0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081B7AB0:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x7c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x78]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B7B80
	bl VM_GetPC
	cmp r0, #0
	beq _081B7AE0
	bl Script_GetValue
	b _081B7AE2
_081B7AE0:
	movs r0, #0
_081B7AE2:
	ldr r3, [sp, #0xd4]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081B7AF0
	asrs r1, r0, #1
	b _081B7AF6
_081B7AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081B7AF6:
	ldr r5, _081B7B0C @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B10
	bl Script_GetValue
	b _081B7B12
	.align 2, 0
_081B7B0C: .4byte 0x00000546
_081B7B10:
	movs r0, #0
_081B7B12:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B28
	bl Script_GetValue
	b _081B7B2A
_081B7B28:
	movs r0, #0
_081B7B2A:
	ldr r3, _081B7B40 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B44
	bl Script_GetValue
	adds r1, r0, #0
	b _081B7B46
	.align 2, 0
_081B7B40: .4byte 0x00000187
_081B7B44:
	movs r1, #0
_081B7B46:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B5C
	bl Script_GetValue
	b _081B7B5E
_081B7B5C:
	movs r0, #0
_081B7B5E:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B76
	bl Script_GetValue
	adds r1, r0, #0
	b _081B7B78
_081B7B76:
	movs r1, #0
_081B7B78:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081B7B80:
	ldr r5, [sp, #0xd4]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x98]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xa4]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa8]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x9c]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B7BE2
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081B7BC8
	bl Script_GetValue
	b _081B7BCA
_081B7BC8:
	movs r0, #0
_081B7BCA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7BDA
	bl Script_GetValue
	b _081B7BDC
_081B7BDA:
	movs r0, #0
_081B7BDC:
	ldr r6, _081B7C44 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081B7BE2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xdc]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081B7C06
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081B7C06:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081B7C1E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x6c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081B7C1E:
	ldr r4, [sp, #0x94]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081B7C48
	movs r0, #1
	b _081B7C4A
	.align 2, 0
_081B7C44: .4byte 0x00000189
_081B7C48:
	movs r0, #0
_081B7C4A:
	cmp r0, #0
	beq _081B7C5A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081B7C84 @ =FUN_080f48ac
	ldr r1, [sp, #0x2c]
	bl FUN_0807f558
_081B7C5A:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081B7C66
	ldr r1, [r7, #0x44]
_081B7C66:
	ldr r0, [sp, #0x2c]
	bl FUN_0823b46c
	ldr r1, [sp, #0xac]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081B7C88
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081B7C94
	.align 2, 0
_081B7C84: .4byte FUN_080f48ac
_081B7C88:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081B7C94:
	ldr r2, [sp, #0xac]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081B7CE2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081B7CE2
	cmp r0, #0x16
	beq _081B7CE2
	cmp r0, #0x14
	beq _081B7CE2
	cmp r0, #9
	beq _081B7CE2
	cmp r0, #0x19
	beq _081B7CE2
	cmp r0, #0x1a
	beq _081B7CE2
	cmp r0, #0xd
	beq _081B7CE2
	cmp r0, #0x1b
	beq _081B7CE2
	cmp r0, #0x1f
	beq _081B7CE2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xcc]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd0]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl FUN_0823b490
_081B7CE2:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081B7CF2
	movs r0, #1
	b _081B7CF4
_081B7CF2:
	movs r0, #0
_081B7CF4:
	cmp r0, #0
	beq _081B7D02
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb0]
	str r0, [r2]
	b _081B7D14
_081B7D02:
	ldr r3, [sp, #0xb4]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb0]
	str r0, [r4]
_081B7D14:
	ldrh r0, [r7]
	ldr r5, [sp, #0x38]
	strh r0, [r5]
	ldr r6, [sp, #0x190]
	ldr r0, [sp, #0x3c]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _081B7D3E
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, [sp, #0x2c]
	strb r0, [r2, #5]
_081B7D3E:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B7DA8
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D58
	bl Script_GetValue
	adds r1, r0, #0
	b _081B7D5A
_081B7D58:
	movs r1, #0x78
_081B7D5A:
	ldr r3, [sp, #0x24]
	ldr r4, _081B7D74 @ =0x00000674
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D78
	bl Script_GetValue
	adds r1, r0, #0
	b _081B7D7A
	.align 2, 0
_081B7D74: .4byte 0x00000674
_081B7D78:
	movs r1, #0x78
_081B7D7A:
	ldr r5, [sp, #0x24]
	ldr r6, _081B7D94 @ =0x0000067E
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D98
	bl Script_GetValue
	adds r1, r0, #0
	b _081B7D9A
	.align 2, 0
_081B7D94: .4byte 0x0000067E
_081B7D98:
	movs r1, #0x78
_081B7D9A:
	ldr r2, [sp, #0x24]
	ldr r3, _081B7DA4 @ =0x00000672
	adds r0, r2, r3
	b _081B7DB6
	.align 2, 0
_081B7DA4: .4byte 0x00000672
_081B7DA8:
	ldr r4, [sp, #0x24]
	ldr r5, _081B7DF4 @ =0x00000674
	adds r0, r4, r5
	movs r1, #0x78
	strb r1, [r0]
	ldr r6, _081B7DF8 @ =0x0000067E
	adds r0, r4, r6
_081B7DB6:
	strh r1, [r0]
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x68]
	strh r0, [r1]
	ldr r2, [sp, #0x58]
	strh r4, [r2]
	ldr r3, [sp, #0x5c]
	strh r4, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x64]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x68]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081B7DFC
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081B7E08
	.align 2, 0
_081B7DF4: .4byte 0x00000674
_081B7DF8: .4byte 0x0000067E
_081B7DFC:
	ldr r2, [r7, #0x44]
	ldr r0, _081B7E40 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081B7E08:
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081B7E58
	ldr r2, [sp, #0xac]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081B7E44
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081B7E4E
	.align 2, 0
_081B7E40: .4byte 0x03003584
_081B7E44:
	ldr r3, [sp, #0xac]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_081B7E4E:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081B7E58:
	movs r4, #0
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	adds r0, #4
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	ldrh r0, [r5]
	ldr r1, [sp, #0x54]
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_081b3204
	ldr r2, [sp, #0x24]
	movs r3, #0xd0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r5, _081B8008 @ =0x000006A4
	adds r2, r2, r5
	mov r8, r2
	ldr r6, _081B800C @ =FUN_081b71e8
	mov sb, r6
	ldr r1, _081B8010 @ =FUN_081b3490
	mov sl, r1
	ldr r2, _081B8014 @ =FUN_081af224
	mov ip, r2
	ldr r5, _081B8018 @ =FUN_081b60bc
	ldr r3, _081B801C @ =FUN_080f62b0
	ldr r6, _081B8020 @ =FUN_080f62ac
	str r6, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x8c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x10c]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x114]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x11c]
	str r2, [r6]
	ldr r1, _081B8024 @ =FUN_081af1e8
	ldr r2, [sp, #0x12c]
	str r1, [r2]
	ldr r6, _081B8028 @ =FUN_081af200
	ldr r1, [sp, #0x130]
	str r6, [r1]
	ldr r2, _081B802C @ =FUN_081af878
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r1, [sp, #0x148]
	str r3, [r1]
	ldr r2, [sp, #0x150]
	str r5, [r2]
	ldr r3, _081B8030 @ =FUN_081b1a34
	ldr r5, [sp, #0x154]
	str r3, [r5]
	ldr r1, _081B8034 @ =FUN_080f44f4
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, _081B8038 @ =FUN_080f410c
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, _081B803C @ =FUN_081afd08
	ldr r5, [sp, #0x14c]
	str r3, [r5]
	ldr r6, _081B8040 @ =FUN_081af9a4
	ldr r1, [sp, #0x110]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x184]
	str r2, [r3]
	ldr r1, _081B8044 @ =FUN_080f0430
	ldr r5, [sp, #0x188]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r1, _081B8048 @ =0x085AD470
	ldr r2, [sp, #0x18c]
	str r1, [r2]
	ldr r1, _081B804C @ =FUN_080e73c8
	ldr r3, [sp, #0x174]
	str r1, [r3]
	ldr r5, [sp, #0x168]
	str r4, [r5]
	ldr r6, [sp, #0x178]
	str r4, [r6]
	ldr r1, [sp, #0x17c]
	str r4, [r1]
	ldr r2, [sp, #0x180]
	str r4, [r2]
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081B8050 @ =FUN_080f0320
	ldr r5, [sp, #0x19c]
	str r1, [r5]
	ldr r1, _081B8054 @ =FUN_080eff14
	ldr r6, [sp, #0x140]
	str r1, [r6]
	ldr r1, _081B8058 @ =FUN_080e72b0
	ldr r2, [sp, #0x16c]
	str r1, [r2]
	ldr r3, _081B805C @ =FUN_081afcac
	ldr r5, [sp, #0x164]
	str r3, [r5]
	ldr r1, _081B8060 @ =FUN_080f47c8
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r1, _081B8064 @ =FUN_080f54e4
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, [sp, #0x134]
	str r4, [r3]
	ldr r1, _081B8068 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a0]
	str r1, [r5]
	ldr r1, _081B806C @ =FUN_080f64f0
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081B8070 @ =FUN_080f84d4
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _081B8074 @ =FUN_080f624c
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r1, _081B8078 @ =FUN_080f56ec
	ldr r5, [sp, #0x120]
	str r1, [r5]
	ldr r1, _081B807C @ =FUN_080f5b34
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r1, _081B8080 @ =FUN_080f5fac
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0xbc]
	strb r1, [r4]
	ldr r1, [sp, #0x194]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081B8084 @ =enemy_boku_081b3298
	str r0, [r1]
	ldr r6, _081B8088 @ =0x000005FC
	adds r1, r7, r6
	ldr r0, _081B808C @ =FUN_081b33e8
	str r0, [r1]
	ldr r0, _081B8090 @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _081B8094 @ =FUN_081b2ea8
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081B8098 @ =FUN_081b2f80
	str r0, [r1]
	ldr r3, _081B809C @ =0x0000058C
	adds r1, r7, r3
	ldr r0, _081B80A0 @ =FUN_081b3fb4
	str r0, [r1]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _081B80A4 @ =FUN_080fa384
	str r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	ldr r6, _081B80A8 @ =0x000001DF
	adds r0, r7, r6
	movs r1, #4
	strb r1, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081B80B6
	movs r3, #0xce
	lsls r3, r3, #1
	adds r5, r7, r3
	movs r4, #4
_081B7FFA:
	bl VM_GetPC
	cmp r0, #0
	beq _081B80AC
	bl Script_GetValue
	b _081B80AE
	.align 2, 0
_081B8008: .4byte 0x000006A4
_081B800C: .4byte FUN_081b71e8
_081B8010: .4byte FUN_081b3490
_081B8014: .4byte FUN_081af224
_081B8018: .4byte FUN_081b60bc
_081B801C: .4byte FUN_080f62b0
_081B8020: .4byte FUN_080f62ac
_081B8024: .4byte FUN_081af1e8
_081B8028: .4byte FUN_081af200
_081B802C: .4byte FUN_081af878
_081B8030: .4byte FUN_081b1a34
_081B8034: .4byte FUN_080f44f4
_081B8038: .4byte FUN_080f410c
_081B803C: .4byte FUN_081afd08
_081B8040: .4byte FUN_081af9a4
_081B8044: .4byte FUN_080f0430
_081B8048: .4byte 0x085AD470
_081B804C: .4byte FUN_080e73c8
_081B8050: .4byte FUN_080f0320
_081B8054: .4byte FUN_080eff14
_081B8058: .4byte FUN_080e72b0
_081B805C: .4byte FUN_081afcac
_081B8060: .4byte FUN_080f47c8
_081B8064: .4byte FUN_080f54e4
_081B8068: .4byte FUN_080f6e64
_081B806C: .4byte FUN_080f64f0
_081B8070: .4byte FUN_080f84d4
_081B8074: .4byte FUN_080f624c
_081B8078: .4byte FUN_080f56ec
_081B807C: .4byte FUN_080f5b34
_081B8080: .4byte FUN_080f5fac
_081B8084: .4byte enemy_boku_081b3298
_081B8088: .4byte 0x000005FC
_081B808C: .4byte FUN_081b33e8
_081B8090: .4byte 0x000005AC
_081B8094: .4byte FUN_081b2ea8
_081B8098: .4byte FUN_081b2f80
_081B809C: .4byte 0x0000058C
_081B80A0: .4byte FUN_081b3fb4
_081B80A4: .4byte FUN_080fa384
_081B80A8: .4byte 0x000001DF
_081B80AC:
	movs r0, #0
_081B80AE:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081B7FFA
_081B80B6:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r4, [sp, #0x84]
	strh r0, [r4]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r5, [sp, #0x74]
	strh r0, [r5]
	cmp r2, #0
	beq _081B80EE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	cmp r2, #2
	bne _081B80EE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r6]
_081B80EE:
	movs r2, #0
	movs r1, #4
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081B8100
	movs r0, #1
	b _081B8102
_081B8100:
	movs r0, #0
_081B8102:
	cmp r0, #0
	beq _081B8114
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #1
_081B8114:
	cmp r2, #1
	beq _081B8154
	movs r1, #0
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, _081B8164 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	ldr r3, _081B8168 @ =0x0000046C
	adds r0, r7, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x130]
	ldr r3, [r4]
	ldr r5, _081B816C @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081B8170 @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xc4]
	strb r1, [r0]
	ldr r2, [sp, #0x108]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081B8154:
	movs r1, #2
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B8174
	movs r0, #1
	b _081B8176
	.align 2, 0
_081B8164: .4byte 0x00000484
_081B8168: .4byte 0x0000046C
_081B816C: .4byte 0x0000046D
_081B8170: .4byte 0x0000046B
_081B8174:
	movs r0, #0
_081B8176:
	cmp r0, #0
	beq _081B8190
	ldr r0, _081B818C @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	b _081B819A
	.align 2, 0
_081B818C: .4byte 0x030046A0
_081B8190:
	ldr r0, [sp, #0x190]
	bl FUN_08241574
	ldr r1, [sp, #0x70]
	strh r0, [r1]
_081B819A:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B81AA
	movs r0, #1
	b _081B81AC
_081B81AA:
	movs r0, #0
_081B81AC:
	cmp r0, #0
	beq _081B81BC
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081B81E0 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081B81BC:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081B81EE
	ldr r0, _081B81E4 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x70]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081B81E8
	movs r0, #1
	b _081B81EA
	.align 2, 0
_081B81E0: .4byte 0xFFFFFEFF
_081B81E4: .4byte 0x030046A0
_081B81E8:
	movs r0, #0
_081B81EA:
	cmp r0, #0
	bne _081B81F6
_081B81EE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081B81F6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xe4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081B82DE
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081B8238
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081B8240
_081B8238:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081B8240:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081B8264
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081B826C
_081B8264:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081B826C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081B82A4 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081B82E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081B82A8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081B829C
	ldrb r0, [r4, #5]
_081B829C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081B82B8
	.align 2, 0
_081B82A4: .4byte 0x0000FFFF
_081B82A8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081B82B8
	strh r1, [r4, #8]
_081B82B8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B82E8
	movs r0, #1
	strb r0, [r4, #7]
	b _081B82E8
_081B82DE:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081B82E8:
	movs r0, #0
	ldr r3, [sp, #0xa0]
	str r0, [r3]
	ldr r0, _081B8300 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B8304
	movs r0, #1
	b _081B8306
	.align 2, 0
_081B8300: .4byte 0x030047A4
_081B8304:
	movs r0, #0
_081B8306:
	cmp r0, #0
	bne _081B8346
	ldr r4, [sp, #0xac]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081B832E
	adds r0, r1, #0
	cmp r0, #7
	beq _081B832E
	cmp r0, #6
	beq _081B832E
	cmp r0, #0x15
	beq _081B832E
	cmp r0, #0x14
	beq _081B832E
	cmp r0, #0x17
	bne _081B8346
_081B832E:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081B8346:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081b3fa0
	adds r0, r7, #0
	bl FUN_081b281c
	adds r0, r7, #0
	bl FUN_081b2e28
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ldr r1, [sp, #0x104]
	strh r0, [r1]
	ldr r2, [sp, #0x90]
	ldrh r0, [r2]
	ldr r3, [sp, #0x100]
	strh r0, [r3]
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	ldr r5, [sp, #0xd8]
	str r0, [r5]
	ldr r6, [sp, #0x6c]
	ldr r0, [r6]
	ldr r1, [sp, #0xe0]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xe8]
	strb r0, [r2]
	ldr r3, [sp, #0x40]
	ldrb r0, [r3]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0xf4]
	strb r0, [r2]
	ldr r3, [sp, #0x108]
	ldr r0, [r3]
	ldr r4, [sp, #0xf8]
	str r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xfc]
	strb r0, [r6]
	ldr r0, _081B83D8 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _081B83DC @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _081B83E0 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081B83E4 @ =FUN_081b7244
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081B83E8 @ =EnemyBokuLink_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B83EC
	movs r0, #0
	b _081B83F0
	.align 2, 0
_081B83D8: .4byte 0x0000057C
_081B83DC: .4byte FUN_080f09e0
_081B83E0: .4byte 0x0000061C
_081B83E4: .4byte FUN_081b7244
_081B83E8: .4byte EnemyBokuLink_Destroy
_081B83EC:
	movs r0, #1
	rsbs r0, r0, #0
_081B83F0:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyBokuLink_Create
EnemyBokuLink_Create: @ 0x081B8400
	push {r4, r5, lr}
	ldr r5, _081B8434 @ =0x000006AC
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081B842C
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyBokuLink_Init
	cmp r0, #0
	bge _081B842C
	adds r0, r4, #0
	bl EnemyBokuLink_Destroy
	adds r0, r4, #0
	bl Free
_081B842C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B8434: .4byte 0x000006AC
