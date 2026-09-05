	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081623c0
FUN_081623c0: @ 0x081623C0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816241C
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	bne _0816241C
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08162408
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08162408
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08162424 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08162408:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0816241C
	adds r0, r4, #0
	bl FUN_08164780
	str r0, [r6, #0x38]
_0816241C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08162424: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08162428
FUN_08162428: @ 0x08162428
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
	bl FUN_080e8a60
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
	bl FUN_08234224
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
	bl FUN_0823785c
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
	bl FUN_08234224
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
	bl FUN_08165178
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
	bl FUN_080e8a60
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
	bl FUN_08236640
	b _081629E4
_081629DC:
	mov r0, sl
	adds r1, r7, #0
	bl FUN_08236524
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
	bl FUN_0823785c
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

	thumb_func_start FUN_08162cf4
FUN_08162cf4: @ 0x08162CF4
	push {lr}
	adds r2, r0, #0
	ldr r0, _08162D14 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162D06
	movs r0, #0
	strb r0, [r1]
_08162D06:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080efe38
	pop {r0}
	bx r0
	.align 2, 0
_08162D14: .4byte 0x0000046D

	thumb_func_start FUN_08162d18
FUN_08162d18: @ 0x08162D18
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08162D30 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162D34
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162D36
	.align 2, 0
_08162D30: .4byte 0x0000046D
_08162D34:
	movs r0, #0
_08162D36:
	cmp r0, #0
	beq _08162D54
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080efe38
	ldr r0, _08162D9C @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
_08162D54:
	ldr r1, _08162DA0 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162DE0
	ldr r2, _08162DA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x6f
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08162DA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x17
	bgt _08162DB8
	ldr r3, _08162DAC @ =FUN_08162df4
	movs r2, #0
	ldr r0, _08162DB0 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162DB4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r3, [r0]
	b _08162DD8
	.align 2, 0
_08162D9C: .4byte 0x00000482
_08162DA0: .4byte 0x0000046E
_08162DA4: .4byte 0x030046B8
_08162DA8: .4byte 0x0203B400
_08162DAC: .4byte FUN_08162df4
_08162DB0: .4byte 0x0000046D
_08162DB4: .4byte 0x0000046B
_08162DB8:
	ldr r4, _08162DE8 @ =FUN_08162d18
	movs r3, #0x28
	ldr r0, _08162DEC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162DF0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
_08162DD8:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08162DE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08162DE8: .4byte FUN_08162d18
_08162DEC: .4byte 0x0000046D
_08162DF0: .4byte 0x0000046B

	thumb_func_start FUN_08162df4
FUN_08162df4: @ 0x08162DF4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08162E0C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162E10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162E12
	.align 2, 0
_08162E0C: .4byte 0x0000046D
_08162E10:
	movs r0, #0
_08162E12:
	cmp r0, #0
	beq _08162E30
	ldr r0, _08162E4C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efe38
_08162E30:
	ldr r0, _08162E50 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08162E54 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08162E58 @ =0x0203B400
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #7
	bgt _08162E5C
	movs r0, #0x10
	b _08162E62
	.align 2, 0
_08162E4C: .4byte 0x00000482
_08162E50: .4byte 0x030046B8
_08162E54: .4byte 0x000003FF
_08162E58: .4byte 0x0203B400
_08162E5C:
	cmp r0, #0xd
	bgt _08162E6E
	movs r0, #0x20
_08162E62:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08162E6E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08162e74
FUN_08162e74: @ 0x08162E74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08162E8C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162E90
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162E92
	.align 2, 0
_08162E8C: .4byte 0x0000046D
_08162E90:
	movs r0, #0
_08162E92:
	cmp r0, #0
	beq _08162EB0
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080efe38
	ldr r0, _08162EE8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
_08162EB0:
	ldr r1, _08162EEC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162EE2
	ldr r4, _08162EF0 @ =FUN_08162fa8
	movs r3, #0x21
	ldr r0, _08162EF4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162EF8 @ =0x0000046B
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
_08162EE2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08162EE8: .4byte 0x00000482
_08162EEC: .4byte 0x0000046E
_08162EF0: .4byte FUN_08162fa8
_08162EF4: .4byte 0x0000046D
_08162EF8: .4byte 0x0000046B

	thumb_func_start FUN_08162efc
FUN_08162efc: @ 0x08162EFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08162F14 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162F18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162F1A
	.align 2, 0
_08162F14: .4byte 0x0000046D
_08162F18:
	movs r0, #0
_08162F1A:
	cmp r0, #0
	beq _08162F38
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_080efe38
	ldr r2, _08162F94 @ =0x00000482
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
_08162F38:
	ldr r6, _08162F98 @ =0x0000046E
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162F8C
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08162F9C @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	subs r6, #4
	adds r0, r5, r6
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	ldr r4, _08162FA0 @ =FUN_080e48d0
	movs r3, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08162FA4 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
_08162F8C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08162F94: .4byte 0x00000482
_08162F98: .4byte 0x0000046E
_08162F9C: .4byte 0x00000469
_08162FA0: .4byte FUN_080e48d0
_08162FA4: .4byte 0x0000046B

	thumb_func_start FUN_08162fa8
FUN_08162fa8: @ 0x08162FA8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08162FC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162FC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162FC6
	.align 2, 0
_08162FC0: .4byte 0x0000046D
_08162FC4:
	movs r0, #0
_08162FC6:
	cmp r0, #0
	beq _0816307E
	ldr r1, _08162FF8 @ =0x000004FC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _08162FFC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08163008
	ldr r1, _08163000 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, _08163004 @ =0x0000046E
	adds r6, r5, r2
	b _0816304A
	.align 2, 0
_08162FF8: .4byte 0x000004FC
_08162FFC: .4byte 0x0000025D
_08163000: .4byte 0x000004B7
_08163004: .4byte 0x0000046E
_08163008:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _081630B8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081630BC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0816302E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0816302E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816304E
_0816302E:
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
_0816304A:
	movs r0, #0
	strb r0, [r6]
_0816304E:
	ldr r2, _081630C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081630C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081630C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldr r2, _081630CC @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	cmp r0, #0
	bne _08163074
	movs r0, #1
	strh r0, [r1]
_08163074:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r1]
	bl FUN_08237098
_0816307E:
	ldr r1, _081630BC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081630B0
	ldr r4, _081630D0 @ =FUN_081630dc
	movs r3, #0x22
	ldr r2, _081630D4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081630D8 @ =0x0000046B
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
_081630B0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081630B8: .4byte 0x000004B7
_081630BC: .4byte 0x0000046E
_081630C0: .4byte 0x030046B8
_081630C4: .4byte 0x000003FF
_081630C8: .4byte 0x0203B400
_081630CC: .4byte 0x00000482
_081630D0: .4byte FUN_081630dc
_081630D4: .4byte 0x0000046D
_081630D8: .4byte 0x0000046B

	thumb_func_start FUN_081630dc
FUN_081630dc: @ 0x081630DC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081630F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081630F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081630FA
	.align 2, 0
_081630F4: .4byte 0x0000046D
_081630F8:
	movs r0, #0
_081630FA:
	cmp r0, #0
	beq _08163188
	ldr r1, _0816312C @ =0x000004FC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _08163130 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0816313C
	ldr r1, _08163134 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _08163138 @ =0x0000046E
	adds r4, r5, r0
	b _08163184
	.align 2, 0
_0816312C: .4byte 0x000004FC
_08163130: .4byte 0x0000025D
_08163134: .4byte 0x000004B7
_08163138: .4byte 0x0000046E
_0816313C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, #1
	ldr r1, _081631C4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081631C8 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, r2
	bne _08163164
	ldrb r0, [r4]
	cmp r0, #0
	bne _08163164
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08163188
_08163164:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
_08163184:
	movs r0, #0
	strb r0, [r4]
_08163188:
	ldr r1, _081631C8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081631BA
	ldr r4, _081631CC @ =FUN_081631d8
	movs r3, #0x23
	ldr r0, _081631D0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081631D4 @ =0x0000046B
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
_081631BA:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081631C4: .4byte 0x000004B7
_081631C8: .4byte 0x0000046E
_081631CC: .4byte FUN_081631d8
_081631D0: .4byte 0x0000046D
_081631D4: .4byte 0x0000046B

	thumb_func_start FUN_081631d8
FUN_081631d8: @ 0x081631D8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _081631F8 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081631FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081631FE
	.align 2, 0
_081631F8: .4byte 0x0000046D
_081631FC:
	movs r0, #0
_081631FE:
	cmp r0, #0
	beq _08163222
	ldr r2, _08163234 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08163238 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816323C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	ldr r2, _08163240 @ =0x0000068C
	adds r1, r3, r2
	strh r0, [r1]
_08163222:
	ldr r0, _08163240 @ =0x0000068C
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	beq _08163244
	subs r0, #1
	strh r0, [r1]
	b _08163276
	.align 2, 0
_08163234: .4byte 0x030046B8
_08163238: .4byte 0x000003FF
_0816323C: .4byte 0x0203B400
_08163240: .4byte 0x0000068C
_08163244:
	ldr r1, _0816327C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163276
	ldr r3, _08163280 @ =FUN_08162fa8
	movs r2, #0x21
	ldr r0, _08163284 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163288 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_08163276:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816327C: .4byte 0x0000046E
_08163280: .4byte FUN_08162fa8
_08163284: .4byte 0x0000046D
_08163288: .4byte 0x0000046B

	thumb_func_start FUN_0816328c
FUN_0816328c: @ 0x0816328C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081632A4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081632A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081632AA
	.align 2, 0
_081632A4: .4byte 0x0000046D
_081632A8:
	movs r0, #0
_081632AA:
	cmp r0, #0
	beq _081632C0
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080efe38
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
_081632C0:
	ldr r1, _08163308 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163348
	ldr r2, _0816330C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x6f
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08163310 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x17
	bgt _08163320
	ldr r3, _08163314 @ =FUN_08162df4
	movs r2, #0
	ldr r0, _08163318 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816331C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r3, [r0]
	b _08163340
	.align 2, 0
_08163308: .4byte 0x0000046E
_0816330C: .4byte 0x030046B8
_08163310: .4byte 0x0203B400
_08163314: .4byte FUN_08162df4
_08163318: .4byte 0x0000046D
_0816331C: .4byte 0x0000046B
_08163320:
	ldr r4, _08163350 @ =FUN_08162d18
	movs r3, #0x28
	ldr r0, _08163354 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163358 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
_08163340:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08163348:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08163350: .4byte FUN_08162d18
_08163354: .4byte 0x0000046D
_08163358: .4byte 0x0000046B

	thumb_func_start FUN_0816335c
FUN_0816335c: @ 0x0816335C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08163360
FUN_08163360: @ 0x08163360
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sb, r0
	ldr r2, _0816338C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163390
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163392
	.align 2, 0
_0816338C: .4byte 0x0000046D
_08163390:
	movs r0, #0
_08163392:
	cmp r0, #0
	beq _081633F6
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	blt _081633A8
	asrs r1, r0, #2
	b _081633AE
_081633A8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081633AE:
	movs r7, #0xe0
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081633C8
	asrs r1, r0, #2
	b _081633CE
_081633C8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081633CE:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r4, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080efe38
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r7, _08163438 @ =0x0000046E
	adds r0, r5, r7
	strb r4, [r0]
_081633F6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r6, r3, #0
	adds r3, r1, #0
	cmp r0, #0
	blt _0816343C
	asrs r0, r0, #2
	b _08163442
	.align 2, 0
_08163438: .4byte 0x0000046E
_0816343C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08163442:
	adds r4, r0, #0
	movs r7, #0x84
	lsls r7, r7, #2
	adds r0, r5, r7
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r7, #8
	adds r1, r5, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, r2, r0
	cmp r0, #0
	blt _08163460
	asrs r0, r0, #2
	b _08163466
_08163460:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08163466:
	adds r2, r0, #0
	cmp r4, #0xc8
	ble _08163470
	movs r4, #0xc8
	b _0816347A
_08163470:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0816347A
	adds r4, r0, #0
_0816347A:
	cmp r2, #0xc8
	ble _08163482
	movs r2, #0xc8
	b _0816348C
_08163482:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0816348C
	adds r2, r0, #0
_0816348C:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r4
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r3]
	adds r0, r0, r4
	strh r0, [r3]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r4, #0
	bne _081634B0
	cmp r2, #0
	bne _081634B0
	movs r0, #1
	b _081634B2
_081634B0:
	movs r0, #0
_081634B2:
	cmp r0, #0
	bne _081634BC
	mov r1, sb
	strh r0, [r1, #0xe]
	b _081635DE
_081634BC:
	ldr r2, _08163510 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081634C8
	b _081635DE
_081634C8:
	ldr r4, _08163514 @ =0x0000046B
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r5, r7
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #0xdb
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _08163524
	movs r1, #8
	ldr r0, _08163518 @ =0x0000068E
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816351C
	movs r0, #1
	b _0816351E
	.align 2, 0
_08163510: .4byte 0x0000046E
_08163514: .4byte 0x0000046B
_08163518: .4byte 0x0000068E
_0816351C:
	movs r0, #0
_0816351E:
	adds r3, r0, #0
	cmp r3, #0
	beq _08163598
_08163524:
	ldr r3, _08163580 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _08163584 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08163588 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0816358C @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08163590 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r4, [r0]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _08163594 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081635DE
	.align 2, 0
_08163580: .4byte FUN_080e48d0
_08163584: .4byte 0x0000046D
_08163588: .4byte 0x0000046B
_0816358C: .4byte 0x00000469
_08163590: .4byte 0x0000046A
_08163594: .4byte 0xFFFFF67F
_08163598:
	ldr r1, _081635EC @ =FUN_08162df4
	ldr r2, _081635F0 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081635F4 @ =0x0000046B
	adds r0, r5, r4
	strb r3, [r0]
	ldr r6, _081635F8 @ =0x00000553
	adds r0, r5, r6
	strb r3, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r3, [r0]
	subs r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _081635FC @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08163600 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r4, #4
	adds r0, r5, r4
	strb r2, [r0]
_081635DE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081635EC: .4byte FUN_08162df4
_081635F0: .4byte 0x0000046D
_081635F4: .4byte 0x0000046B
_081635F8: .4byte 0x00000553
_081635FC: .4byte 0x0000046A
_08163600: .4byte 0x00000484

	thumb_func_start FUN_08163604
FUN_08163604: @ 0x08163604
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _0816362C @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08163630
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _08163632
	.align 2, 0
_0816362C: .4byte 0x0000046D
_08163630:
	movs r0, #0
_08163632:
	cmp r0, #0
	beq _0816366A
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081636C0 @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080efe38
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816366A:
	movs r7, #0
	strh r7, [r5, #8]
	movs r0, #5
	strh r0, [r5, #0xe]
	adds r0, r6, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816368C
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816368C:
	cmp r6, #0x1e
	ble _081636B8
	ldr r3, _081636C4 @ =FUN_081636d4
	movs r2, #0x2a
	ldr r0, _081636C8 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081636CC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _081636D0 @ =0x00000553
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
_081636B8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081636C0: .4byte 0x00000482
_081636C4: .4byte FUN_081636d4
_081636C8: .4byte 0x0000046D
_081636CC: .4byte 0x0000046B
_081636D0: .4byte 0x00000553

	thumb_func_start FUN_081636d4
FUN_081636d4: @ 0x081636D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r6, [r5, #0x44]
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081636F8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081636FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081636FE
	.align 2, 0
_081636F8: .4byte 0x0000046D
_081636FC:
	movs r0, #0
_081636FE:
	cmp r0, #0
	beq _0816379C
	ldr r0, _08163740 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl FUN_08237098
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrb r4, [r0]
	movs r7, #0x12
	ldr r2, _08163744 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08163748
	asrs r1, r0, #0xc
	b _0816374E
	.align 2, 0
_08163740: .4byte 0x00000482
_08163744: .4byte 0x085B0A08
_08163748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816374E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08163768 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0816376C
	asrs r0, r0, #0xc
	b _08163772
	.align 2, 0
_08163768: .4byte 0x085B0A08
_0816376C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08163772:
	movs r4, #0
	strh r0, [r3, #4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #2
	orrs r0, r1
	str r0, [r6]
	movs r0, #0x40
	strb r0, [r6, #8]
	strb r0, [r6, #9]
	ldr r0, _081637C4 @ =0x000003C1
	bl PlaySound_082406e0
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_0816379C:
	mov r2, r8
	ldrh r0, [r2, #8]
	cmp r0, #3
	bne _081637A8
	movs r0, #0
	strh r0, [r2, #0xe]
_081637A8:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081637C8
	ldrb r1, [r6, #9]
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x7e
	bgt _081637E2
	adds r0, r1, #1
	b _081637E0
	.align 2, 0
_081637C4: .4byte 0x000003C1
_081637C8:
	ldrb r1, [r6, #9]
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x40
	ble _081637D6
	subs r0, r1, #2
	strb r0, [r6, #9]
_081637D6:
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x3f
	bgt _081637E2
	movs r0, #0x40
_081637E0:
	strb r0, [r6, #9]
_081637E2:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816382C
	ldr r4, _08163838 @ =FUN_08163848
	movs r3, #0x2b
	ldr r0, _0816383C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163840 @ =0x0000046B
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
	adds r0, r5, #0
	bl FUN_08164da8
	adds r0, r5, #0
	bl FUN_08164da8
	ldr r0, _08163844 @ =0x000003C2
	bl PlaySound_082406e0
_0816382C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08163838: .4byte FUN_08163848
_0816383C: .4byte 0x0000046D
_08163840: .4byte 0x0000046B
_08163844: .4byte 0x000003C2

	thumb_func_start FUN_08163848
FUN_08163848: @ 0x08163848
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, [r6, #0x44]
	ldr r0, _08163860 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163864
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163866
	.align 2, 0
_08163860: .4byte 0x0000046D
_08163864:
	movs r0, #0
_08163866:
	cmp r0, #0
	beq _08163888
	movs r0, #0x40
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, _081638EC @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08163888:
	ldr r2, _081638F0 @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081638E6
	ldr r3, _081638F4 @ =0x00000482
	adds r1, r6, r3
	movs r2, #0
	movs r4, #0
	movs r5, #1
	movs r0, #1
	strh r0, [r1]
	ldr r3, _081638F8 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _081638FC @ =0x0000046D
	adds r0, r6, r7
	strb r5, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r2, [r0]
	ldr r3, _08163900 @ =0x00000469
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08163904 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	ldr r2, _08163908 @ =0x0000046C
	adds r0, r6, r2
	strb r5, [r0]
_081638E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081638EC: .4byte 0xFFFFFEFF
_081638F0: .4byte 0x0000046E
_081638F4: .4byte 0x00000482
_081638F8: .4byte FUN_080e48d0
_081638FC: .4byte 0x0000046D
_08163900: .4byte 0x00000469
_08163904: .4byte 0x00000484
_08163908: .4byte 0x0000046C

	thumb_func_start FUN_0816390c
FUN_0816390c: @ 0x0816390C
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08163928 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816392C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816392E
	.align 2, 0
_08163928: .4byte 0x0000046D
_0816392C:
	movs r0, #0
_0816392E:
	cmp r0, #0
	beq _08163956
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080efe38
	adds r0, r5, #0
	bl FUN_080e8360
	adds r0, r5, #0
	bl FUN_081647c8
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x39
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08163956:
	movs r2, #0x80
	lsls r2, r2, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0816396C
	b _08163AFA
_0816396C:
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08163980
	b _08163AB4
_08163980:
	ldr r1, _08163A10 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081639E8
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _08163A14 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081639E8:
	ldr r1, _08163A18 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08163A20
	ldr r0, _08163A1C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _08163A32
	.align 2, 0
_08163A10: .4byte 0x0000046B
_08163A14: .4byte 0xFFFF0000
_08163A18: .4byte 0x000001DF
_08163A1C: .4byte 0x030046A0
_08163A20:
	ldr r0, _08163A9C @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_08163A32:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _08163A4A
	adds r0, r5, #0
	bl FUN_080e6658
_08163A4A:
	ldr r4, _08163AA0 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r2, _08163AA4 @ =0x0000046D
	adds r0, r5, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _08163AA8 @ =0x0000046B
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _08163AAC @ =0x0000046A
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _08163AB0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _08163AFA
	.align 2, 0
_08163A9C: .4byte 0x030046A0
_08163AA0: .4byte FUN_080e48d0
_08163AA4: .4byte 0x0000046D
_08163AA8: .4byte 0x0000046B
_08163AAC: .4byte 0x0000046A
_08163AB0: .4byte 0x0000046C
_08163AB4:
	movs r1, #1
	ldr r2, _08163ACC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08163AD0
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08163ADA
	b _08163ADE
	.align 2, 0
_08163ACC: .4byte 0x0000025D
_08163AD0:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _08163ADE
_08163ADA:
	movs r0, #1
	b _08163AE0
_08163ADE:
	movs r0, #0
_08163AE0:
	cmp r0, #0
	beq _08163AF0
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r5, r3
	bl FUN_080136b4
	b _08163AFA
_08163AF0:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_08013698
_08163AFA:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08163b04
FUN_08163b04: @ 0x08163B04
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08163B24 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163B28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163B2A
	.align 2, 0
_08163B24: .4byte 0x0000046C
_08163B28:
	movs r0, #0
_08163B2A:
	cmp r0, #0
	beq _08163B70
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r4, #5]
	adds r0, r4, #0
	bl FUN_080e6750
	ldr r2, _08163B88 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08163B54
	movs r0, #4
	ldr r1, _08163B8C @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08163B54:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_08163B70:
	ldr r1, _08163B90 @ =0x0000046B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163B98
	movs r0, #4
	ldr r1, _08163B94 @ =0x0000068E
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08163BA2
	.align 2, 0
_08163B88: .4byte 0x000001DF
_08163B8C: .4byte 0x00000222
_08163B90: .4byte 0x0000046B
_08163B94: .4byte 0x0000068E
_08163B98:
	ldr r2, _08163BA8 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08163BA2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08163BA8: .4byte 0x00000484

	thumb_func_start FUN_08163bac
FUN_08163bac: @ 0x08163BAC
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _08163BB8 @ =0x085AD9C4
	str r1, [r0]
	bx lr
	.align 2, 0
_08163BB8: .4byte 0x085AD9C4

	thumb_func_start FUN_08163bbc
FUN_08163bbc: @ 0x08163BBC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08163BD4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163BD8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163BDA
	.align 2, 0
_08163BD4: .4byte 0x0000046C
_08163BD8:
	movs r0, #0
_08163BDA:
	cmp r0, #0
	beq _08163C24
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	ldr r3, _08163C1C @ =0x0000046D
	adds r0, r5, r3
	movs r1, #0
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r1, [r5, #5]
	adds r0, r5, #0
	bl FUN_08164120
	ldr r3, _08163C20 @ =0x00000482
	adds r0, r5, r3
	strh r4, [r0]
	b _08163D88
	.align 2, 0
_08163C1C: .4byte 0x0000046D
_08163C20: .4byte 0x00000482
_08163C24:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08163C60 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08163C68
	ldr r0, _08163C64 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08163C78
	.align 2, 0
_08163C60: .4byte 0x0000A02F
_08163C64: .4byte 0x00000482
_08163C68:
	ldr r1, _08163C9C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08163C78
	movs r0, #1
	strh r0, [r2]
_08163C78:
	ldr r3, _08163CA0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08163CA4
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
	b _08163CBC
	.align 2, 0
_08163C9C: .4byte 0x00000482
_08163CA0: .4byte 0x0000025D
_08163CA4:
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
_08163CBC:
	ldr r1, _08163CF4 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08163CDE
	rsbs r2, r2, #0
_08163CDE:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08163CF8
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08163CEC
	rsbs r2, r2, #0
_08163CEC:
	cmp r2, #0x20
	bgt _08163CF8
	movs r0, #1
	b _08163D62
	.align 2, 0
_08163CF4: .4byte 0x000004A4
_08163CF8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08163D04
	cmp r1, #0
	beq _08163D60
_08163D04:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08163D28 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08163D2C
	asrs r1, r0, #0xc
	b _08163D32
	.align 2, 0
_08163D28: .4byte 0x085B0A08
_08163D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08163D32:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08163D50 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08163D54
	asrs r1, r0, #0xc
	b _08163D5A
	.align 2, 0
_08163D50: .4byte 0x085B0A08
_08163D54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08163D5A:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08163D60:
	movs r0, #0
_08163D62:
	cmp r0, #0
	beq _08163D6E
	ldrb r1, [r5, #5]
	adds r0, r5, #0
	bl FUN_08164120
_08163D6E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08163D90 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08163D88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08163D90: .4byte 0x00000484

	thumb_func_start FUN_08163d94
FUN_08163d94: @ 0x08163D94
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08163DAC @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163DB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163DB2
	.align 2, 0
_08163DAC: .4byte 0x0000046C
_08163DB0:
	movs r0, #0
_08163DB2:
	cmp r0, #0
	beq _08163DE0
	ldr r1, _08163E00 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08163E04 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163E08 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
_08163DE0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, _08163E0C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08163E00: .4byte 0x000005A4
_08163E04: .4byte 0x0000046D
_08163E08: .4byte 0x0000046B
_08163E0C: .4byte 0x00000484

	thumb_func_start FUN_08163e10
FUN_08163e10: @ 0x08163E10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08163E94 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163E22
	movs r0, #0
	strb r0, [r1]
_08163E22:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08163E84
	ldr r3, _08163E98 @ =FUN_08162efc
	movs r1, #0x26
	ldr r2, _08163E9C @ =0x0000046D
	adds r0, r4, r2
	movs r2, #1
	strb r2, [r0]
	ldr r6, _08163EA0 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08163EA4 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r2, [r0]
_08163E84:
	ldr r0, _08163EA8 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08163E94: .4byte 0x0000046C
_08163E98: .4byte FUN_08162efc
_08163E9C: .4byte 0x0000046D
_08163EA0: .4byte 0x0000046B
_08163EA4: .4byte 0x00000469
_08163EA8: .4byte 0x00000484

	thumb_func_start FUN_08163eac
FUN_08163eac: @ 0x08163EAC
	ldr r1, _08163EB8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08163EBC @ =0x085AD9C8
	str r1, [r0]
	bx lr
	.align 2, 0
_08163EB8: .4byte 0x00000634
_08163EBC: .4byte 0x085AD9C8

	thumb_func_start FUN_08163ec0
FUN_08163ec0: @ 0x08163EC0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _08163F44 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _08163F48 @ =0x0000FFFF
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
	ldr r3, _08163F4C @ =FUN_08162428
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
	ldr r3, _08163F50 @ =FUN_081623c0
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
_08163F44: .4byte 0xFFFF0000
_08163F48: .4byte 0x0000FFFF
_08163F4C: .4byte FUN_08162428
_08163F50: .4byte FUN_081623c0

	thumb_func_start slime_08163f54
slime_08163f54: @ 0x08163F54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _08163FB8 @ =0x0000068E
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r0, r1
	strh r2, [r0]
	ldr r1, _08163FBC @ =0x08252120
	adds r0, r4, #0
	movs r2, #0x45
	bl FUN_080e6768
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r4, #0x44]
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
	beq _08163FC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08163FC8
	.align 2, 0
_08163FB8: .4byte 0x0000068E
_08163FBC: .4byte 0x08252120
_08163FC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08163FC8:
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
	beq _08163FEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08163FF4
_08163FEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08163FF4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0816402C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08164064
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08164030
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08164024
	ldrb r0, [r4, #5]
_08164024:
	subs r0, #1
	strh r0, [r4, #8]
	b _08164040
	.align 2, 0
_0816402C: .4byte 0x0000FFFF
_08164030:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08164040
	strh r1, [r4, #8]
_08164040:
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
	bne _08164064
	movs r0, #1
	strb r0, [r4, #7]
_08164064:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816406c
FUN_0816406c: @ 0x0816406C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08164070
FUN_08164070: @ 0x08164070
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #9
	movs r3, #4
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081640e4
FUN_081640e4: @ 0x081640E4
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	beq _081640F8
	movs r0, #0
	b _08164118
_081640F8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3, #8]
	movs r1, #6
	bl Mod
	ldr r1, _0816411C @ =0x085ADA08
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_08164118:
	pop {r1}
	bx r1
	.align 2, 0
_0816411C: .4byte 0x085ADA08

	thumb_func_start FUN_08164120
FUN_08164120: @ 0x08164120
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _08164170 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08164174 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08164178 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #8]
	strb r0, [r2, #5]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _0816417C @ =0x00000256
	adds r1, r2, r1
	str r1, [sp, #0x14]
	adds r2, #8
	str r2, [sp, #0x18]
	ldr r2, _08164180 @ =0x030046A4
	mov sb, r2
_0816415A:
	ldr r0, [sp, #0x14]
	ldrh r6, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08164184
	adds r0, #4
	b _08164190
	.align 2, 0
_08164170: .4byte 0x030046B8
_08164174: .4byte 0x000003FF
_08164178: .4byte 0x0203B400
_0816417C: .4byte 0x00000256
_08164180: .4byte 0x030046A4
_08164184:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08164190:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081641A4
	cmp r3, #2
	beq _081641AA
	b _081641B0
_081641A4:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _081641AE
_081641AA:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_081641AE:
	subs r2, r2, r0
_081641B0:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081641C2
	adds r0, #4
	b _081641CE
_081641C2:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081641CE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, [sp, #8]
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081641E0
	asrs r0, r0, #6
	b _081641E6
_081641E0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081641E6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08164224
	cmp r1, #1
	bgt _081641F8
	cmp r1, #0
	beq _08164202
	b _081642E0
_081641F8:
	cmp r1, #2
	beq _08164264
	cmp r1, #3
	beq _08164286
	b _081642E0
_08164202:
	adds r4, r6, #1
	movs r5, #0
_08164206:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08164220
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08164206
_08164220:
	subs r5, r4, #1
	b _081642E4
_08164224:
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	ldr r2, _08164260 @ =0x030046A4
	mov sl, r2
_08164236:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081642C4
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08164236
	mov r1, sl
	b _081642C6
	.align 2, 0
_08164260: .4byte 0x030046A4
_08164264:
	subs r4, r6, #1
	movs r5, #0
_08164268:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08164282
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08164268
_08164282:
	adds r5, r4, #1
	b _081642E4
_08164286:
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
	ldr r0, _081642C0 @ =0x030046A4
	mov sl, r0
_08164298:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081642D2
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08164298
	mov r1, sl
	b _081642D4
	.align 2, 0
_081642C0: .4byte 0x030046A4
_081642C4:
	mov r1, sb
_081642C6:
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _081642E4
_081642D2:
	mov r1, sb
_081642D4:
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _081642E4
_081642E0:
	ldr r0, [sp, #0x14]
	ldrh r5, [r0]
_081642E4:
	ldr r1, [sp, #0x14]
	ldrh r1, [r1]
	cmp r5, r1
	bne _08164300
	ldr r2, [sp, #8]
	ldrb r0, [r2, #5]
	adds r0, #0x40
	strb r0, [r2, #5]
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _08164300
	b _0816415A
_08164300:
	mov r1, sp
	ldrb r2, [r1, #0xc]
	ldr r1, [sp, #8]
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _08164344 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08164348
	adds r0, #4
	b _08164352
	.align 2, 0
_08164344: .4byte 0x030046A4
_08164348:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08164352:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r2, [sp, #8]
	ldr r1, _08164384 @ =0x000004A4
	adds r0, r2, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164384: .4byte 0x000004A4

	thumb_func_start FUN_08164388
FUN_08164388: @ 0x08164388
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r2, _081643E0 @ =0x00000482
	adds r1, r3, r2
	movs r0, #1
	strh r0, [r1]
	movs r5, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _081643DC
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _081643E4 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _081643C0
	rsbs r1, r1, #0
_081643C0:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _081643DC
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _081643E8
_081643DC:
	movs r0, #0
	b _08164466
	.align 2, 0
_081643E0: .4byte 0x00000482
_081643E4: .4byte 0x03002BE0
_081643E8:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0816440C @ =0x00000546
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _0816441A
	ldr r1, _08164410 @ =0x0000068E
	adds r0, r4, r1
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _08164414
	movs r0, #1
	b _08164416
	.align 2, 0
_0816440C: .4byte 0x00000546
_08164410: .4byte 0x0000068E
_08164414:
	movs r0, #0
_08164416:
	cmp r0, #0
	beq _08164454
_0816441A:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08164450 @ =0x00000482
	adds r1, r3, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08164464
	.align 2, 0
_08164450: .4byte 0x00000482
_08164454:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08164464:
	movs r0, #1
_08164466:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0816446c
FUN_0816446c: @ 0x0816446C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r1, _08164500 @ =0x000004A4
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r0, _08164504 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r3, #0xc]
	str r1, [r3, #0x10]
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r0, r2, r6
	ldr r1, _08164508 @ =0x0000065A
	adds r2, r2, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	cmp r0, r2
	blo _081644FA
	ldr r3, _0816450C @ =FUN_08163604
	movs r1, #0x29
	ldr r2, _08164510 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08164514 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08164518 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0816451C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
_081644FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08164500: .4byte 0x000004A4
_08164504: .4byte 0x03002BE0
_08164508: .4byte 0x0000065A
_0816450C: .4byte FUN_08163604
_08164510: .4byte 0x0000046D
_08164514: .4byte 0x0000046B
_08164518: .4byte 0x00000469
_0816451C: .4byte 0x0000046C

	thumb_func_start FUN_08164520
FUN_08164520: @ 0x08164520
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _08164590 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x25
	beq _08164588
	cmp r0, #0x21
	beq _08164588
	cmp r0, #0x22
	beq _08164588
	cmp r0, #0x23
	beq _08164588
	ldr r3, _08164594 @ =FUN_08162e74
	movs r1, #0x25
	ldr r2, _08164598 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0816459C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xf
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081645A0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_08164588:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08164590: .4byte 0x00000553
_08164594: .4byte FUN_08162e74
_08164598: .4byte 0x0000046D
_0816459C: .4byte 0x0000046B
_081645A0: .4byte 0x0000046A

	thumb_func_start FUN_081645a4
FUN_081645a4: @ 0x081645A4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _081645E8
	bl VM_GetPC
	cmp r0, #0
	beq _081645C4
	bl Script_GetValue
	adds r1, r0, #0
	b _081645C6
_081645C4:
	movs r1, #0
_081645C6:
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081645DE
	bl Script_GetValue
	adds r1, r0, #0
	b _081645E0
_081645DE:
	movs r1, #0
_081645E0:
	ldr r2, _081645E4 @ =0x0000068A
	b _081645F2
	.align 2, 0
_081645E4: .4byte 0x0000068A
_081645E8:
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
_081645F2:
	adds r0, r4, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081645fc
FUN_081645fc: @ 0x081645FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816461C
	b _08164758
_0816461C:
	movs r3, #8
	ldrsh r0, [r7, r3]
	str r0, [sp]
	movs r4, #0xa
	ldrsh r0, [r7, r4]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #0xc]
	ldr r4, _08164664 @ =0x000001DD
	adds r0, r7, r4
	add r3, sp, #0x28
	ldrb r4, [r0]
	movs r5, #0xc
	ldr r2, _08164668 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r3
	cmp r0, #0
	blt _0816466C
	asrs r1, r0, #0xc
	b _08164672
	.align 2, 0
_08164664: .4byte 0x000001DD
_08164668: .4byte 0x085B0A08
_0816466C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164672:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0816468A
	asrs r0, r0, #0xc
	b _08164690
_0816468A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164690:
	movs r5, #0
	movs r4, #0
	mov r8, r4
	strh r0, [r3, #4]
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x10]
	movs r0, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x28
	movs r3, #4
	ldrsh r0, [r0, r3]
	str r0, [sp, #0x18]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08164764 @ =0x0000068A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _08164768 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	mov r3, sp
	str r3, [r1, #4]
	movs r0, #0xd1
	lsls r0, r0, #3
	adds r4, r6, r0
	ldrh r0, [r4]
	bl Script_ExecById
	adds r0, r7, #0
	bl FUN_081647c8
	mov r1, r8
	strh r1, [r4]
	movs r0, #8
	ldr r3, _0816476C @ =0x0000068E
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08164770 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _08164774 @ =0x0000046D
	adds r0, r7, r4
	movs r3, #1
	strb r3, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r4, r8
	strh r4, [r0]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	ldr r4, _08164778 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _0816477C @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08164758:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164764: .4byte 0x0000068A
_08164768: .4byte 0xFFFF0000
_0816476C: .4byte 0x0000068E
_08164770: .4byte FUN_080e48d0
_08164774: .4byte 0x0000046D
_08164778: .4byte 0x00000469
_0816477C: .4byte 0xFFFFF67F

	thumb_func_start FUN_08164780
FUN_08164780: @ 0x08164780
	push {lr}
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _08164792
	movs r0, #0
	b _081647B0
_08164792:
	ldr r2, _081647B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081647B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081647BC @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _081647C0 @ =0x00200004
	cmp r0, #0xb3
	bgt _081647AE
	ldr r1, _081647C4 @ =0x00400008
_081647AE:
	adds r0, r1, #0
_081647B0:
	pop {r1}
	bx r1
	.align 2, 0
_081647B4: .4byte 0x030046B8
_081647B8: .4byte 0x000003FF
_081647BC: .4byte 0x0203B400
_081647C0: .4byte 0x00200004
_081647C4: .4byte 0x00400008

	thumb_func_start FUN_081647c8
FUN_081647c8: @ 0x081647C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r4, _08164814 @ =0x0203B400
	ldr r3, _08164818 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0816481C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r2, sp, #0x2c
	adds r3, r0, #6
	ldr r1, _08164820 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164824
	asrs r1, r0, #0xc
	b _0816482A
	.align 2, 0
_08164814: .4byte 0x0203B400
_08164818: .4byte 0x030046B8
_0816481C: .4byte 0x000003FF
_08164820: .4byte 0x085B0A08
_08164824:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816482A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _08164844 @ =0x085B0A08
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164848
	asrs r0, r0, #0xc
	b _0816484E
	.align 2, 0
_08164844: .4byte 0x085B0A08
_08164848:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816484E:
	movs r4, #0
	strh r0, [r2, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	mov r6, r8
	adds r6, #8
	ldr r2, _081648D8 @ =0x0000B96C
	ldr r3, _081648DC @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081648E0 @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r4, _081648E4 @ =0x0203B400
	ldr r3, _081648E8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081648EC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r3, sp, #0x2c
	adds r2, r0, #6
	ldr r1, _081648F0 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081648F4
	asrs r1, r0, #0xc
	b _081648FA
	.align 2, 0
_081648D8: .4byte 0x0000B96C
_081648DC: .4byte 0x0000A929
_081648E0: .4byte 0x0000047A
_081648E4: .4byte 0x0203B400
_081648E8: .4byte 0x030046B8
_081648EC: .4byte 0x000003FF
_081648F0: .4byte 0x085B0A08
_081648F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081648FA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08164914 @ =0x085B0A08
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08164918
	asrs r0, r0, #0xc
	b _0816491E
	.align 2, 0
_08164914: .4byte 0x085B0A08
_08164918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816491E:
	movs r4, #0
	strh r0, [r3, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _081649A4 @ =0x0000B96C
	ldr r3, _081649A8 @ =0x0000A929
	movs r0, #7
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081649AC @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r4, _081649B0 @ =0x0203B400
	ldr r3, _081649B4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081649B8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r3, sp, #0x2c
	adds r2, r0, #6
	ldr r1, _081649BC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081649C0
	asrs r1, r0, #0xc
	b _081649C6
	.align 2, 0
_081649A4: .4byte 0x0000B96C
_081649A8: .4byte 0x0000A929
_081649AC: .4byte 0x0000047A
_081649B0: .4byte 0x0203B400
_081649B4: .4byte 0x030046B8
_081649B8: .4byte 0x000003FF
_081649BC: .4byte 0x085B0A08
_081649C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081649C6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081649E0 @ =0x085B0A08
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081649E4
	asrs r0, r0, #0xc
	b _081649EA
	.align 2, 0
_081649E0: .4byte 0x085B0A08
_081649E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081649EA:
	movs r4, #0
	strh r0, [r3, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08164A3C @ =0x0000B96C
	ldr r3, _08164A40 @ =0x0000A929
	movs r0, #7
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08164A44 @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164A3C: .4byte 0x0000B96C
_08164A40: .4byte 0x0000A929
_08164A44: .4byte 0x0000047A

	thumb_func_start FUN_08164a48
FUN_08164a48: @ 0x08164A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	bl FUN_08164780
	str r0, [sp, #0x34]
	ldr r0, _08164AEC @ =0x0203B400
	mov r8, r0
	ldr r4, _08164AF0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08164AF4 @ =0x000003FF
	mov sb, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r6, [r0]
	movs r0, #0xf
	ands r6, r0
	add r2, sp, #0x2c
	adds r5, r7, #0
	adds r5, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	mov sl, r0
	ldr r0, [r4]
	adds r0, #1
	mov r5, sb
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	mov r0, sl
	adds r3, r0, r6
	adds r4, r1, #6
	ldr r2, _08164AF8 @ =0x085B0A08
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
	blt _08164AFC
	asrs r1, r0, #0xc
	b _08164B02
	.align 2, 0
_08164AEC: .4byte 0x0203B400
_08164AF0: .4byte 0x030046B8
_08164AF4: .4byte 0x000003FF
_08164AF8: .4byte 0x085B0A08
_08164AFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164B02:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164B20 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164B24
	asrs r0, r0, #0xc
	b _08164B2A
	.align 2, 0
_08164B20: .4byte 0x085B0A08
_08164B24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164B2A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	movs r5, #8
	adds r5, r5, r7
	mov r8, r5
	ldr r2, _08164BD8 @ =0x0000B96C
	ldr r3, _08164BDC @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, _08164BE0 @ =0x0000047A
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164BE4 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164BE8 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, r8
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r5, _08164BEC @ =0x0203B400
	ldr r4, _08164BF0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08164BF4 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	movs r1, #0xf
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	mov r0, sl
	adds r3, r0, r2
	adds r4, r1, #6
	ldr r2, _08164BF8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov sb, r8
	cmp r0, #0
	blt _08164BFC
	asrs r1, r0, #0xc
	b _08164C02
	.align 2, 0
_08164BD8: .4byte 0x0000B96C
_08164BDC: .4byte 0x0000A929
_08164BE0: .4byte 0x0000047A
_08164BE4: .4byte 0x00000226
_08164BE8: .4byte 0x0000022E
_08164BEC: .4byte 0x0203B400
_08164BF0: .4byte 0x030046B8
_08164BF4: .4byte 0x000003FF
_08164BF8: .4byte 0x085B0A08
_08164BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164C02:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164C20 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164C24
	asrs r0, r0, #0xc
	b _08164C2A
	.align 2, 0
_08164C20: .4byte 0x085B0A08
_08164C24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164C2A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _08164CD4 @ =0x0000B96C
	ldr r3, _08164CD8 @ =0x0000A929
	movs r5, #7
	mov r8, r5
	str r5, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, _08164CDC @ =0x0000047A
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164CE0 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164CE4 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r5, _08164CE8 @ =0x0203B400
	ldr r4, _08164CEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08164CF0 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	movs r1, #0xf
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	mov r3, r8
	ands r0, r3
	add r5, sp, #0x2c
	mov r1, sl
	adds r3, r1, r2
	adds r4, r0, #6
	ldr r2, _08164CF4 @ =0x085B0A08
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
	blt _08164CF8
	asrs r1, r0, #0xc
	b _08164CFE
	.align 2, 0
_08164CD4: .4byte 0x0000B96C
_08164CD8: .4byte 0x0000A929
_08164CDC: .4byte 0x0000047A
_08164CE0: .4byte 0x00000226
_08164CE4: .4byte 0x0000022E
_08164CE8: .4byte 0x0203B400
_08164CEC: .4byte 0x030046B8
_08164CF0: .4byte 0x000003FF
_08164CF4: .4byte 0x085B0A08
_08164CF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164CFE:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164D1C @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164D20
	asrs r0, r0, #0xc
	b _08164D26
	.align 2, 0
_08164D1C: .4byte 0x085B0A08
_08164D20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164D26:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08164D94 @ =0x0000B96C
	ldr r3, _08164D98 @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r5, _08164D9C @ =0x0000047A
	adds r0, r7, r5
	ldrh r0, [r0]
	adds r5, #6
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164DA0 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164DA4 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164D94: .4byte 0x0000B96C
_08164D98: .4byte 0x0000A929
_08164D9C: .4byte 0x0000047A
_08164DA0: .4byte 0x00000226
_08164DA4: .4byte 0x0000022E

	thumb_func_start FUN_08164da8
FUN_08164da8: @ 0x08164DA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	bl FUN_08164780
	str r0, [sp, #0x34]
	ldr r0, _08164E4C @ =0x0203B400
	mov ip, r0
	ldr r6, _08164E50 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _08164E54 @ =0x000003FF
	ands r1, r4
	str r1, [r6]
	lsls r0, r1, #1
	add r0, ip
	ldrh r5, [r0]
	movs r0, #0xf
	ands r5, r0
	add r2, sp, #0x2c
	mov sl, r2
	movs r3, #8
	add r3, sb
	mov r8, r3
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	mov r7, sb
	ldrh r2, [r7, #8]
	subs r0, r0, r2
	add r2, sp, #0x2c
	strh r0, [r2]
	ldrh r0, [r3, #2]
	mov r7, r8
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	mov r2, sl
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r7, #4]
	subs r0, r0, r2
	mov r3, sl
	strh r0, [r3, #4]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	movs r2, #0xff
	ldrb r7, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	movs r0, #7
	ands r1, r0
	add r6, sp, #0x2c
	adds r3, r7, r5
	adds r4, r1, #0
	adds r4, #0xc
	ldr r1, _08164E58 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164E5C
	asrs r1, r0, #0xc
	b _08164E62
	.align 2, 0
_08164E4C: .4byte 0x0203B400
_08164E50: .4byte 0x030046B8
_08164E54: .4byte 0x000003FF
_08164E58: .4byte 0x085B0A08
_08164E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164E62:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _08164E80 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164E84
	asrs r0, r0, #0xc
	b _08164E8A
	.align 2, 0
_08164E80: .4byte 0x085B0A08
_08164E84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164E8A:
	movs r4, #0
	strh r0, [r6, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	movs r2, #8
	add r2, sb
	mov r8, r2
	ldr r2, _08164F44 @ =0x0000B96C
	ldr r3, _08164F48 @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08164F4C @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _08164F50 @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08164F54 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r7, [sp, #0x34]
	orrs r0, r7
	str r0, [sp, #0x24]
	ldr r0, _08164F58 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, r8
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r4, _08164F5C @ =0x0203B400
	ldr r5, _08164F60 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08164F64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r0, #1
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	adds r2, r7, r3
	adds r3, r1, #0
	adds r3, #0xc
	ldr r1, _08164F68 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov sl, r8
	cmp r0, #0
	blt _08164F6C
	asrs r1, r0, #0xc
	b _08164F72
	.align 2, 0
_08164F44: .4byte 0x0000B96C
_08164F48: .4byte 0x0000A929
_08164F4C: .4byte 0x0000047A
_08164F50: .4byte 0x00000226
_08164F54: .4byte 0x0000022E
_08164F58: .4byte 0x00000236
_08164F5C: .4byte 0x0203B400
_08164F60: .4byte 0x030046B8
_08164F64: .4byte 0x000003FF
_08164F68: .4byte 0x085B0A08
_08164F6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164F72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164F90 @ =0x085B0A08
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164F94
	asrs r0, r0, #0xc
	b _08164F9A
	.align 2, 0
_08164F90: .4byte 0x085B0A08
_08164F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164F9A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _08165050 @ =0x0000B96C
	ldr r3, _08165054 @ =0x0000A929
	movs r7, #7
	mov r8, r7
	mov r0, r8
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08165058 @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _0816505C @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08165060 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r1, [sp, #0x34]
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, _08165064 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sl
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r4, _08165068 @ =0x0203B400
	ldr r5, _0816506C @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08165070 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r0, #1
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	add r5, sp, #0x2c
	adds r2, r7, r3
	adds r3, r0, #6
	ldr r1, _08165074 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r3, r0
	cmp r0, #0
	blt _08165078
	asrs r1, r0, #0xc
	b _0816507E
	.align 2, 0
_08165050: .4byte 0x0000B96C
_08165054: .4byte 0x0000A929
_08165058: .4byte 0x0000047A
_0816505C: .4byte 0x00000226
_08165060: .4byte 0x0000022E
_08165064: .4byte 0x00000236
_08165068: .4byte 0x0203B400
_0816506C: .4byte 0x030046B8
_08165070: .4byte 0x000003FF
_08165074: .4byte 0x085B0A08
_08165078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816507E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _0816509C @ =0x085B0A08
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081650A0
	asrs r0, r0, #0xc
	b _081650A6
	.align 2, 0
_0816509C: .4byte 0x085B0A08
_081650A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081650A6:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08165118 @ =0x0000B96C
	ldr r3, _0816511C @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08165120 @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _08165124 @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08165128 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r7, [sp, #0x34]
	orrs r0, r7
	str r0, [sp, #0x24]
	ldr r0, _0816512C @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sl
	add r1, sp, #0x2c
	bl FUN_081ef708
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08165118: .4byte 0x0000B96C
_0816511C: .4byte 0x0000A929
_08165120: .4byte 0x0000047A
_08165124: .4byte 0x00000226
_08165128: .4byte 0x0000022E
_0816512C: .4byte 0x00000236

	thumb_func_start FUN_08165130
FUN_08165130: @ 0x08165130
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #0x10
	ldr r2, _0816514C @ =0x0000068E
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08165150
	movs r0, #1
	b _08165152
	.align 2, 0
_0816514C: .4byte 0x0000068E
_08165150:
	movs r0, #0
_08165152:
	cmp r0, #0
	beq _0816516A
	ldr r0, _08165170 @ =0x000003C2
	bl PlaySound_082406e0
	ldr r0, _08165174 @ =0x0000068E
	adds r2, r4, r0
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0816516A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08165170: .4byte 0x000003C2
_08165174: .4byte 0x0000068E

	thumb_func_start FUN_08165178
FUN_08165178: @ 0x08165178
	push {r4, r5, lr}
	ldr r2, _081651D4 @ =0x000001DD
	adds r1, r0, r2
	movs r3, #0
	strb r3, [r1]
	movs r5, #0x94
	lsls r5, r5, #3
	adds r1, r0, r5
	movs r4, #1
	str r4, [r1]
	subs r2, #0x59
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r5, #0x8b
	lsls r5, r5, #1
	adds r1, r0, r5
	strh r2, [r1]
	ldr r5, _081651D8 @ =0x0000048A
	adds r1, r0, r5
	strh r2, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0x28
	strh r1, [r2]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r0, r2
	str r3, [r1]
	adds r5, #0x12
	adds r1, r0, r5
	str r3, [r1]
	subs r2, #0xc
	adds r1, r0, r2
	strb r4, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081651D4: .4byte 0x000001DD
_081651D8: .4byte 0x0000048A

	thumb_func_start FUN_081651dc
FUN_081651dc: @ 0x081651DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r0, _08165248 @ =0x000003BF
	bl PlaySound_082406e0
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _08165200
	adds r0, r6, #0
	bl FUN_08164a48
_08165200:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xcb
	lsls r5, r5, #3
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #0x50
	strh r0, [r1]
	movs r7, #0xd1
	lsls r7, r7, #3
	adds r0, r4, r7
	ldrh r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0816526E
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0816524C @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _08165250
	adds r0, r6, #0
	bl FUN_081645fc
	b _0816526E
	.align 2, 0
_08165248: .4byte 0x000003BF
_0816524C: .4byte 0x00000546
_08165250:
	ldr r2, _081652E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081652E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _081652E8 @ =0x0203B400
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0x18
	bgt _0816526E
	adds r0, r6, #0
	bl FUN_081645fc
_0816526E:
	ldr r1, _081652EC @ =0x0000049C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _08165308
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r3, r6, r2
	ldr r1, _081652F0 @ =0xFFFFF67F
	ldrh r0, [r3]
	ands r1, r0
	movs r2, #0
	movs r5, #0
	strh r1, [r3]
	ldr r3, _081652F4 @ =0x000005CC
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #0x12
	ldr r4, _081652F8 @ =0x0000046D
	adds r0, r6, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081652FC @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08165300 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _08165304 @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r5, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	b _08165436
	.align 2, 0
_081652E0: .4byte 0x030046B8
_081652E4: .4byte 0x000003FF
_081652E8: .4byte 0x0203B400
_081652EC: .4byte 0x0000049C
_081652F0: .4byte 0xFFFFF67F
_081652F4: .4byte 0x000005CC
_081652F8: .4byte 0x0000046D
_081652FC: .4byte 0x0000046B
_08165300: .4byte 0x00000469
_08165304: .4byte 0x0000046A
_08165308:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0816531C
	movs r0, #0
	b _08165438
_0816531C:
	ldr r3, _08165358 @ =0x00000544
	adds r1, r6, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r2, [r0, #6]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #2
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _08165368
	movs r1, #8
	ldr r5, _0816535C @ =0x0000068E
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08165360
	movs r0, #1
	b _08165362
	.align 2, 0
_08165358: .4byte 0x00000544
_0816535C: .4byte 0x0000068E
_08165360:
	movs r0, #0
_08165362:
	adds r3, r0, #0
	cmp r3, #0
	beq _081653DC
_08165368:
	ldr r3, _081653C4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _081653C8 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081653CC @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081653D0 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _081653D4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _081653D8 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08165436
	.align 2, 0
_081653C4: .4byte FUN_080e48d0
_081653C8: .4byte 0x0000046D
_081653CC: .4byte 0x0000046B
_081653D0: .4byte 0x0000046A
_081653D4: .4byte 0x00000484
_081653D8: .4byte 0xFFFFF67F
_081653DC:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, _08165440 @ =0x00FFFFFF
	ands r0, r1
	cmp r0, #0
	beq _08165436
	ldr r2, _08165444 @ =0x000005A4
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r4, _08165448 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0816544C @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _08165450 @ =0x00000553
	adds r0, r6, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r3, [r0]
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08165454 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	ldr r5, _08165458 @ =0x0000046A
	adds r0, r6, r5
	strb r1, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r3, [r0]
	ldr r1, _0816545C @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
_08165436:
	movs r0, #1
_08165438:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08165440: .4byte 0x00FFFFFF
_08165444: .4byte 0x000005A4
_08165448: .4byte 0x0000046D
_0816544C: .4byte 0x0000046B
_08165450: .4byte 0x00000553
_08165454: .4byte 0x00000469
_08165458: .4byte 0x0000046A
_0816545C: .4byte 0x0000046C

	thumb_func_start FUN_08165460
FUN_08165460: @ 0x08165460
	movs r0, #1
	bx lr

	thumb_func_start FUN_08165464
FUN_08165464: @ 0x08165464
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	ldr r1, _081654A8 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081654AC @ =0x0000065C
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r0, _081654B0 @ =0x000001FF
	cmp r1, r0
	ble _081654E6
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081654A2
	cmp r1, #0
	blt _081654A2
	ldr r0, _081654B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081654A2
	ldr r0, _081654B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081654BC
_081654A2:
	movs r0, #0
	b _081654CA
	.align 2, 0
_081654A8: .4byte 0x00000472
_081654AC: .4byte 0x0000065C
_081654B0: .4byte 0x000001FF
_081654B4: .4byte 0x030046A8
_081654B8: .4byte 0x030046AC
_081654BC:
	ldr r0, _081654FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081654CA:
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081654E6
	adds r0, r5, #0
	bl FUN_08165178
	ldr r1, _08165500 @ =0x0000065C
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08165504 @ =0x00000472
	adds r0, r5, r2
	strh r1, [r0]
_081654E6:
	ldr r1, _08165504 @ =0x00000472
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _08165500 @ =0x0000065C
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081654FC: .4byte 0x030046A4
_08165500: .4byte 0x0000065C
_08165504: .4byte 0x00000472

	thumb_func_start FUN_08165508
FUN_08165508: @ 0x08165508
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	bl FUN_08165460
	ldr r1, _0816554C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816553C
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08165550 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_0816553C:
	adds r0, r5, #0
	bl FUN_08165464
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0816554C: .4byte 0x000004BE
_08165550: .4byte 0x0000062C

	thumb_func_start FUN_08165554
FUN_08165554: @ 0x08165554
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _08165570 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08165570: .4byte 0x03002BE0

	thumb_func_start FUN_08165574
FUN_08165574: @ 0x08165574
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0816558C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08165590
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08165598
	.align 2, 0
_0816558C: .4byte 0x0000025D
_08165590:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08165598:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081655B4 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081655B8
	movs r0, #1
	b _081655BA
	.align 2, 0
_081655B4: .4byte 0x00000474
_081655B8:
	movs r0, #0
_081655BA:
	cmp r0, #0
	beq _081655C6
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081655C6:
	ldr r1, _08165620 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081655DE
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081655DE:
	ldr r0, _08165624 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081655F6
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081655F6:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816560E
	adds r0, r4, #0
	bl FUN_08002a58
_0816560E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08165628
	movs r0, #1
	b _0816562A
	.align 2, 0
_08165620: .4byte 0x0000044C
_08165624: .4byte 0x0000044D
_08165628:
	movs r0, #0
_0816562A:
	cmp r0, #0
	beq _08165636
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08165636:
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

	thumb_func_start EnemySlime_Init
EnemySlime_Init: @ 0x08165654
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081656D4 @ =0x0000068E
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_08164070
	ldr r2, _081656D8 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081656E8
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081656DC @ =0x0000B96C
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081656E0 @ =0x0000A929
	bl FUN_080e3804
	ldr r3, _081656E4 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x48]
	cmp r1, #0x11
	beq _081656C4
	cmp r1, #0x17
	bne _081656C8
_081656C4:
	movs r0, #1
	strb r0, [r5, #7]
_081656C8:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08165750
	.align 2, 0
_081656D4: .4byte 0x0000068E
_081656D8: .4byte 0x0000025D
_081656DC: .4byte 0x0000B96C
_081656E0: .4byte 0x0000A929
_081656E4: .4byte 0x000001DF
_081656E8:
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
	ldr r2, _081657D4 @ =0x05000002
	bl CpuSet
	ldr r0, _081657D8 @ =0x0000CB05
	ldr r1, _081657DC @ =0x0000B96C
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
	ldr r6, _081657E0 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x48]
_08165750:
	ldr r2, _081657E4 @ =0x000001DF
	adds r1, r7, r2
	movs r4, #0
	movs r0, #0x16
	strb r0, [r1]
	str r7, [sp, #0x28]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	str r4, [r3]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	str r4, [r5]
	ldr r6, _081657E8 @ =0x0000046F
	adds r0, r7, r6
	strb r4, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	mov sl, r2
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, _081657EC @ =0x00000474
	adds r6, r7, r3
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081657D4 @ =0x05000002
	bl CpuSet
	ldr r4, _081657F0 @ =0x000004B6
	adds r2, r7, r4
	mov r0, sl
	strb r0, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x184]
	mov r3, r8
	str r3, [sp, #0x188]
	str r6, [sp, #0x160]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _081657C4
	b _08165924
_081657C4:
	bl VM_GetPC
	cmp r0, #0
	beq _081657F4
	bl Script_GetValue
	adds r1, r0, #0
	b _081657F6
	.align 2, 0
_081657D4: .4byte 0x05000002
_081657D8: .4byte 0x0000CB05
_081657DC: .4byte 0x0000B96C
_081657E0: .4byte 0x000004B7
_081657E4: .4byte 0x000001DF
_081657E8: .4byte 0x0000046F
_081657EC: .4byte 0x00000474
_081657F0: .4byte 0x000004B6
_081657F4:
	movs r1, #0
_081657F6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0816581C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xd8]
	str r4, [sp, #0xdc]
	cmp r0, #0
	beq _08165820
	bl Script_GetValue
	adds r1, r0, #0
	b _08165822
	.align 2, 0
_0816581C: .4byte 0x00000251
_08165820:
	movs r1, #0
_08165822:
	ldr r2, _08165858 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0816585C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xd8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xe0]
	cmp r0, #0
	beq _08165860
	bl Script_GetValue
	b _08165864
	.align 2, 0
_08165858: .4byte 0x00000252
_0816585C: .4byte 0x000004B4
_08165860:
	ldr r4, [sp, #0xd8]
	ldrb r0, [r4]
_08165864:
	strb r0, [r6]
	ldr r5, [sp, #0xd8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xe0]
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
	blt _0816589C
	cmp r1, #0
	blt _0816589C
	ldr r0, _081658A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816589C
	ldr r0, _081658A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081658A8
_0816589C:
	movs r1, #0
	b _081658B6
	.align 2, 0
_081658A0: .4byte 0x030046A8
_081658A4: .4byte 0x030046AC
_081658A8:
	ldr r0, _081658D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081658B6:
	ldr r2, _081658D4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081658D8
	adds r0, #4
	b _081658E4
	.align 2, 0
_081658D0: .4byte 0x030046A4
_081658D4: .4byte 0x00000256
_081658D8:
	ldr r0, _081658F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081658E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081658FC
	cmp r2, #2
	beq _08165900
	b _08165904
	.align 2, 0
_081658F8: .4byte 0x030046A4
_081658FC:
	ldrb r0, [r4, #4]
	b _08165902
_08165900:
	ldrb r0, [r4]
_08165902:
	subs r1, r1, r0
_08165904:
	ldr r3, _0816591C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08165920 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08165964
	.align 2, 0
_0816591C: .4byte 0x00000472
_08165920: .4byte 0x0000FFFF
_08165924:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08165988 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0816598C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08165990 @ =0x000004B4
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
	str r0, [sp, #0x2c]
	str r5, [sp, #0xd8]
	str r4, [sp, #0xdc]
	str r3, [sp, #0xe0]
_08165964:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081659AE
	bl VM_GetPC
	cmp r0, #0
	beq _08165994
	bl Script_GetValue
	adds r4, r0, #0
	b _08165996
	.align 2, 0
_08165988: .4byte 0x00000251
_0816598C: .4byte 0x00000252
_08165990: .4byte 0x000004B4
_08165994:
	movs r4, #0x30
_08165996:
	bl VM_GetPC
	cmp r0, #0
	beq _081659A8
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081659AA
_081659A8:
	movs r5, #0x40
_081659AA:
	mov r8, r4
	b _081659B4
_081659AE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081659B4:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081659EC
	bl VM_GetPC
	cmp r0, #0
	beq _081659CE
	bl Script_GetValue
	adds r6, r0, #0
	b _081659D0
_081659CE:
	movs r6, #0
_081659D0:
	bl VM_GetPC
	cmp r0, #0
	beq _081659E0
	bl Script_GetValue
	adds r1, r0, #0
	b _081659E2
_081659E0:
	movs r1, #0
_081659E2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081659F6
_081659EC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081659F6:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08165C70 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x190]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	lsls r4, r4, #0x10
	str r4, [sp, #0x40]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x50]
	lsls r6, r6, #0x10
	str r6, [sp, #0x54]
	lsls r5, r5, #0x10
	str r5, [sp, #0x4c]
	ldr r4, _08165C74 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x3c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x148]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x60]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x68]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x14c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x150]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x144]
	ldr r1, _08165C78 @ =0x0000068E
	ldr r6, [sp, #0x24]
	adds r1, r6, r1
	str r1, [sp, #0x140]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _08165C7C @ =0x0000047A
	adds r3, r7, r3
	str r3, [sp, #0x164]
	ldr r4, _08165C80 @ =0x0000047C
	adds r4, r7, r4
	str r4, [sp, #0x168]
	ldr r5, _08165C84 @ =0x0000047E
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08165C88 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _08165C8C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _08165C90 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _08165C94 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _08165C98 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0xf4]
	ldr r6, _08165C9C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd4]
	ldr r2, _08165CA0 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x90]
	ldr r3, _08165CA4 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x124]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x128]
	ldr r5, _08165CA8 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	ldr r6, _08165CAC @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x12c]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x114]
	ldr r2, _08165CB0 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x118]
	ldr r4, _08165CB4 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _08165CB8 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _08165CBC @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x104]
	ldr r5, _08165CC0 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x110]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _08165CC4 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x138]
	ldr r3, _08165CC8 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x13c]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08165CCC @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	ldr r2, _08165CD0 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xac]
	ldr r3, _08165CD4 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	ldr r4, _08165CD8 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x194]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _08165CDC @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x178]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x154]
	ldr r3, _08165CE0 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x158]
	ldr r4, _08165CE4 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08165CE8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x44]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _08165CEC @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x30]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	ldr r6, _08165CF0 @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _08165CF4 @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r3, _08165CF8 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _08165CFC @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08165D00 @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _08165D04 @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	cmp r0, #0
	bne _08165C40
	b _08165D60
_08165C40:
	movs r2, #0
	mov sl, r2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_08165C60:
	bl VM_GetPC
	cmp r0, #0
	beq _08165D08
	bl Script_GetValue
	b _08165D0A
	.align 2, 0
_08165C70: .4byte 0x0000025D
_08165C74: .4byte 0x0000025A
_08165C78: .4byte 0x0000068E
_08165C7C: .4byte 0x0000047A
_08165C80: .4byte 0x0000047C
_08165C84: .4byte 0x0000047E
_08165C88: .4byte 0x000004A4
_08165C8C: .4byte 0x000005A4
_08165C90: .4byte 0x000005C4
_08165C94: .4byte 0x000005CC
_08165C98: .4byte 0x000005D4
_08165C9C: .4byte 0x000005DC
_08165CA0: .4byte 0x00000584
_08165CA4: .4byte 0x00000604
_08165CA8: .4byte 0x0000021D
_08165CAC: .4byte 0x0000060C
_08165CB0: .4byte 0x000005E4
_08165CB4: .4byte 0x000005FC
_08165CB8: .4byte 0x00000614
_08165CBC: .4byte 0x000005BC
_08165CC0: .4byte 0x000005EC
_08165CC4: .4byte 0x00000624
_08165CC8: .4byte 0x0000058C
_08165CCC: .4byte 0x00000594
_08165CD0: .4byte 0x0000059C
_08165CD4: .4byte 0x000005B4
_08165CD8: .4byte 0x00000543
_08165CDC: .4byte 0x00000496
_08165CE0: .4byte 0x00000469
_08165CE4: .4byte 0x0000046A
_08165CE8: .4byte 0x00000553
_08165CEC: .4byte 0x00000572
_08165CF0: .4byte 0x0000055C
_08165CF4: .4byte 0x00000564
_08165CF8: .4byte 0x00000565
_08165CFC: .4byte 0x00000566
_08165D00: .4byte 0x00000567
_08165D04: .4byte 0x0000056C
_08165D08:
	movs r0, #0x18
_08165D0A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08165D1C
	bl Script_GetValue
	b _08165D1E
_08165D1C:
	movs r0, #0x18
_08165D1E:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08165D30
	bl Script_GetValue
	b _08165D32
_08165D30:
	movs r0, #0
_08165D32:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08165D44
	bl Script_GetValue
	b _08165D46
_08165D44:
	movs r0, #0
_08165D46:
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
	bgt _08165D60
	b _08165C60
_08165D60:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08165DAC
	bl VM_GetPC
	cmp r0, #0
	beq _08165D7A
	bl Script_GetValue
	adds r4, r0, #0
	b _08165D7E
_08165D7A:
	movs r4, #0x96
	lsls r4, r4, #1
_08165D7E:
	bl VM_GetPC
	cmp r0, #0
	beq _08165D8E
	bl Script_GetValue
	adds r6, r0, #0
	b _08165D92
_08165D8E:
	movs r6, #0x96
	lsls r6, r6, #1
_08165D92:
	bl VM_GetPC
	cmp r0, #0
	beq _08165DA0
	bl Script_GetValue
	b _08165DA6
_08165DA0:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08165DA6:
	ldr r2, [sp, #0xd0]
	strh r0, [r2]
	b _08165DB4
_08165DAC:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xd0]
	strh r6, [r3]
_08165DB4:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08165DCC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x188]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08165DCC:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x190]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x18c]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08165E9C
	bl VM_GetPC
	cmp r0, #0
	beq _08165DFC
	bl Script_GetValue
	b _08165DFE
_08165DFC:
	movs r0, #0
_08165DFE:
	ldr r3, [sp, #0xe8]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08165E0C
	asrs r1, r0, #1
	b _08165E12
_08165E0C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08165E12:
	ldr r5, _08165E28 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E2C
	bl Script_GetValue
	b _08165E2E
	.align 2, 0
_08165E28: .4byte 0x00000546
_08165E2C:
	movs r0, #0
_08165E2E:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E44
	bl Script_GetValue
	b _08165E46
_08165E44:
	movs r0, #0
_08165E46:
	ldr r3, _08165E5C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E60
	bl Script_GetValue
	adds r1, r0, #0
	b _08165E62
	.align 2, 0
_08165E5C: .4byte 0x00000187
_08165E60:
	movs r1, #0
_08165E62:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E78
	bl Script_GetValue
	b _08165E7A
_08165E78:
	movs r0, #0
_08165E7A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E92
	bl Script_GetValue
	adds r1, r0, #0
	b _08165E94
_08165E92:
	movs r1, #0
_08165E94:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08165E9C:
	ldr r5, [sp, #0xe8]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x40]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x50]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x54]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x4c]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08165EFE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08165EE4
	bl Script_GetValue
	b _08165EE6
_08165EE4:
	movs r0, #0
_08165EE6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08165EF6
	bl Script_GetValue
	b _08165EF8
_08165EF6:
	movs r0, #0
_08165EF8:
	ldr r6, _08165F60 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08165EFE:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xf0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08165F22
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x188]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08165F22:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08165F3A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08165F3A:
	ldr r4, [sp, #0x3c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x160]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08165F64
	movs r0, #1
	b _08165F66
	.align 2, 0
_08165F60: .4byte 0x00000189
_08165F64:
	movs r0, #0
_08165F66:
	cmp r0, #0
	beq _08165F76
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08165FA0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08165F76:
	ldr r6, [sp, #0xf8]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08165F82
	ldr r1, [r7, #0x44]
_08165F82:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08165FA4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08165FB0
	.align 2, 0
_08165FA0: .4byte FUN_080f48ac
_08165FA4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08165FB0:
	ldr r2, [sp, #0x48]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08165FFE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08165FFE
	cmp r0, #0x16
	beq _08165FFE
	cmp r0, #0x14
	beq _08165FFE
	cmp r0, #9
	beq _08165FFE
	cmp r0, #0x19
	beq _08165FFE
	cmp r0, #0x1a
	beq _08165FFE
	cmp r0, #0xd
	beq _08165FFE
	cmp r0, #0x1b
	beq _08165FFE
	cmp r0, #0x1f
	beq _08165FFE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xd8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xdc]
	ldrb r3, [r4]
	ldr r5, [sp, #0xe0]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_08165FFE:
	movs r1, #8
	ldr r6, [sp, #0x160]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816600E
	movs r0, #1
	b _08166010
_0816600E:
	movs r0, #0
_08166010:
	cmp r0, #0
	beq _0816601E
	ldr r1, [sp, #0x68]
	ldr r0, [r1]
	ldr r2, [sp, #0x60]
	str r0, [r2]
	b _08166030
_0816601E:
	ldr r3, [sp, #0x68]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x60]
	str r0, [r4]
_08166030:
	ldrh r0, [r7]
	ldr r5, [sp, #0x14c]
	strh r0, [r5]
	ldr r6, [sp, #0x144]
	ldr r0, [sp, #0x150]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0816605A
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
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_0816605A:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08166066
	b _08166162
_08166066:
	bl VM_GetPC
	cmp r0, #0
	beq _08166074
	bl Script_GetValue
	b _08166076
_08166074:
	movs r0, #0
_08166076:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08166086
	bl Script_GetValue
	b _08166088
_08166086:
	movs r0, #0
_08166088:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08166098
	bl Script_GetValue
	b _0816609A
_08166098:
	movs r0, #0
_0816609A:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x144]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081660C2
	cmp r1, #0
	blt _081660C2
	ldr r0, _081660C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081660C2
	ldr r0, _081660CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081660D0
_081660C2:
	movs r1, #0
	b _081660DE
	.align 2, 0
_081660C8: .4byte 0x030046A8
_081660CC: .4byte 0x030046AC
_081660D0:
	ldr r0, _081660F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081660DE:
	ldr r4, _081660FC @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x144]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08166100
	adds r0, #4
	b _0816610C
	.align 2, 0
_081660F8: .4byte 0x030046A4
_081660FC: .4byte 0x00000256
_08166100:
	ldr r0, _08166120 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816610C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08166124
	cmp r2, #2
	beq _08166128
	b _0816612C
	.align 2, 0
_08166120: .4byte 0x030046A4
_08166124:
	ldrb r0, [r5, #4]
	b _0816612A
_08166128:
	ldrb r0, [r5]
_0816612A:
	subs r1, r1, r0
_0816612C:
	ldr r5, _08166150 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	ldr r2, _08166154 @ =0x0000065C
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, [sp, #0xf8]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08166158
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08166162
	.align 2, 0
_08166150: .4byte 0x00000472
_08166154: .4byte 0x0000065C
_08166158:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08166162:
	movs r0, #0x6a
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08166200
	bl VM_GetPC
	cmp r0, #0
	beq _0816617E
	bl Script_GetValue
	adds r1, r0, #0
	b _08166180
_0816617E:
	movs r1, #0
_08166180:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08166196
	bl Script_GetValue
	b _08166198
_08166196:
	movs r0, #0
_08166198:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081661B0
	bl Script_GetValue
	adds r1, r0, #0
	b _081661B2
_081661B0:
	movs r1, #0
_081661B2:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0x18
	ldr r2, [sp, #0x140]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _081661F0
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r1, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	blt _081661E4
	asrs r1, r0, #1
	b _081661EA
_081661E4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081661EA:
	ldr r4, _081661FC @ =0x00000546
	adds r0, r7, r4
	strh r1, [r0]
_081661F0:
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #1
	strh r0, [r1]
	b _08166208
	.align 2, 0
_081661FC: .4byte 0x00000546
_08166200:
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
_08166208:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, [sp, #0x24]
	ldr r4, _08166288 @ =0x0000065A
	adds r1, r3, r4
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08166244
	movs r0, #0x10
	ldr r6, [sp, #0x140]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
_08166244:
	adds r0, r7, #0
	bl FUN_081645a4
	movs r4, #0x93
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x170]
	strh r0, [r1]
	ldr r2, [sp, #0x164]
	strh r4, [r2]
	ldr r3, [sp, #0x168]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, #0x93
	ldr r4, [sp, #0x16c]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x170]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xf8]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0816628C
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08166298
	.align 2, 0
_08166288: .4byte 0x0000065A
_0816628C:
	ldr r2, [r7, #0x44]
	ldr r0, _081662D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08166298:
	ldr r1, [sp, #0xf8]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081662E8
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081662D4
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
	b _081662DE
	.align 2, 0
_081662D0: .4byte 0x03003584
_081662D4:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_081662DE:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081662E8:
	adds r0, r7, #0
	bl FUN_08163ec0
	ldr r4, [sp, #0x24]
	ldr r5, _08166470 @ =0x00000664
	adds r3, r4, r5
	movs r2, #0
	ldr r4, _08166474 @ =FUN_08165508
	ldr r5, _08166478 @ =FUN_081640e4
	ldr r6, _0816647C @ =FUN_08162df4
	mov r8, r6
	ldr r0, _08166480 @ =FUN_08163360
	mov sb, r0
	ldr r1, _08166484 @ =FUN_0816390c
	mov sl, r1
	ldr r6, _08166488 @ =FUN_080f62ac
	mov ip, r6
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x184]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x17c]
	str r3, [r0]
	ldr r1, [sp, #0x180]
	str r2, [r1]
	ldr r3, [sp, #0x8c]
	str r4, [r3]
	ldr r4, [sp, #0x94]
	str r5, [r4]
	ldr r5, [sp, #0x9c]
	str r2, [r5]
	ldr r6, _0816648C @ =FUN_08162cf4
	ldr r0, [sp, #0xb0]
	str r6, [r0]
	mov r1, r8
	ldr r3, [sp, #0xb4]
	str r1, [r3]
	ldr r4, [sp, #0xc8]
	str r2, [r4]
	ldr r5, [sp, #0xcc]
	str r2, [r5]
	mov r6, sb
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sl
	ldr r3, [sp, #0xec]
	str r1, [r3]
	ldr r0, _08166490 @ =FUN_080f44f4
	ldr r4, [sp, #0xf4]
	str r0, [r4]
	ldr r0, _08166494 @ =FUN_080f410c
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r6, [sp, #0xd4]
	str r2, [r6]
	ldr r0, _08166498 @ =FUN_0816335c
	ldr r1, [sp, #0x90]
	str r0, [r1]
	mov r3, ip
	ldr r4, [sp, #0x124]
	str r3, [r4]
	ldr r0, _0816649C @ =FUN_080f0430
	ldr r5, [sp, #0x128]
	str r0, [r5]
	movs r0, #1
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, _081664A0 @ =0x085AD470
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _081664A4 @ =FUN_080e73c8
	ldr r3, [sp, #0x114]
	str r0, [r3]
	ldr r4, [sp, #0x108]
	str r2, [r4]
	ldr r5, [sp, #0x118]
	str r2, [r5]
	ldr r6, [sp, #0x11c]
	str r2, [r6]
	ldr r0, [sp, #0x120]
	str r2, [r0]
	ldr r1, [sp, #0x130]
	str r2, [r1]
	ldr r0, _081664A8 @ =FUN_080f0320
	ldr r3, [sp, #0x134]
	str r0, [r3]
	ldr r0, _081664AC @ =FUN_080eff14
	ldr r4, [sp, #0xc4]
	str r0, [r4]
	ldr r0, _081664B0 @ =FUN_080e72b0
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r6, [sp, #0x104]
	str r2, [r6]
	ldr r0, _081664B4 @ =FUN_080f47c8
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r0, _081664B8 @ =FUN_080f54e4
	ldr r3, [sp, #0xfc]
	str r0, [r3]
	ldr r4, [sp, #0xb8]
	str r2, [r4]
	ldr r0, _081664BC @ =FUN_080f6e64
	ldr r5, [sp, #0x138]
	str r0, [r5]
	ldr r0, _081664C0 @ =FUN_080f64f0
	ldr r6, [sp, #0x98]
	str r0, [r6]
	ldr r0, _081664C4 @ =FUN_080f84d4
	ldr r1, [sp, #0x13c]
	str r0, [r1]
	ldr r0, _081664C8 @ =FUN_080f624c
	ldr r3, [sp, #0xc0]
	str r0, [r3]
	ldr r0, _081664CC @ =FUN_080f56ec
	ldr r4, [sp, #0xa0]
	str r0, [r4]
	ldr r0, _081664D0 @ =FUN_080f5b34
	ldr r5, [sp, #0xa8]
	str r0, [r5]
	ldr r0, _081664D4 @ =FUN_080f5fac
	ldr r6, [sp, #0xac]
	str r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081664D8 @ =slime_08163f54
	str r0, [r1]
	ldr r3, _081664DC @ =0x000005FC
	adds r1, r7, r3
	ldr r0, _081664E0 @ =FUN_0816406c
	str r0, [r1]
	ldr r4, _081664E4 @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _081664E8 @ =FUN_0816446c
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081664EC @ =FUN_08164520
	str r0, [r1]
	ldr r6, _081664F0 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081664F4 @ =FUN_081651dc
	str r0, [r1]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081664F8 @ =FUN_08164388
	str r0, [r1]
	subs r2, #0x44
	adds r1, r7, r2
	ldr r0, _081664FC @ =FUN_08165130
	str r0, [r1]
	movs r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x160]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x194]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0816650A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08166462:
	bl VM_GetPC
	cmp r0, #0
	beq _08166500
	bl Script_GetValue
	b _08166502
	.align 2, 0
_08166470: .4byte 0x00000664
_08166474: .4byte FUN_08165508
_08166478: .4byte FUN_081640e4
_0816647C: .4byte FUN_08162df4
_08166480: .4byte FUN_08163360
_08166484: .4byte FUN_0816390c
_08166488: .4byte FUN_080f62ac
_0816648C: .4byte FUN_08162cf4
_08166490: .4byte FUN_080f44f4
_08166494: .4byte FUN_080f410c
_08166498: .4byte FUN_0816335c
_0816649C: .4byte FUN_080f0430
_081664A0: .4byte 0x085AD470
_081664A4: .4byte FUN_080e73c8
_081664A8: .4byte FUN_080f0320
_081664AC: .4byte FUN_080eff14
_081664B0: .4byte FUN_080e72b0
_081664B4: .4byte FUN_080f47c8
_081664B8: .4byte FUN_080f54e4
_081664BC: .4byte FUN_080f6e64
_081664C0: .4byte FUN_080f64f0
_081664C4: .4byte FUN_080f84d4
_081664C8: .4byte FUN_080f624c
_081664CC: .4byte FUN_080f56ec
_081664D0: .4byte FUN_080f5b34
_081664D4: .4byte FUN_080f5fac
_081664D8: .4byte slime_08163f54
_081664DC: .4byte 0x000005FC
_081664E0: .4byte FUN_0816406c
_081664E4: .4byte 0x000005AC
_081664E8: .4byte FUN_0816446c
_081664EC: .4byte FUN_08164520
_081664F0: .4byte 0x0000058C
_081664F4: .4byte FUN_081651dc
_081664F8: .4byte FUN_08164388
_081664FC: .4byte FUN_08165130
_08166500:
	movs r0, #0
_08166502:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08166462
_0816650A:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x198]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x178]
	strh r0, [r3]
	cmp r2, #0
	beq _08166542
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x184]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08166542
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08166542:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x160]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08166554
	movs r0, #1
	b _08166556
_08166554:
	movs r0, #0
_08166556:
	cmp r0, #0
	beq _08166568
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x188]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08166568:
	cmp r2, #1
	beq _081665A8
	movs r1, #0
	ldr r0, [sp, #0x154]
	strb r1, [r0]
	ldr r2, [sp, #0x158]
	strb r1, [r2]
	ldr r3, [sp, #0x15c]
	strb r1, [r3]
	ldr r4, _081665B8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081665BC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xb4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x88]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081665A8:
	movs r1, #2
	ldr r3, [sp, #0x160]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081665C0
	movs r0, #1
	b _081665C2
	.align 2, 0
_081665B8: .4byte 0x00000484
_081665BC: .4byte 0x0000046C
_081665C0:
	movs r0, #0
_081665C2:
	cmp r0, #0
	beq _081665DC
	ldr r0, _081665D8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x174]
	strh r0, [r5]
	b _081665E6
	.align 2, 0
_081665D8: .4byte 0x030046A0
_081665DC:
	ldr r0, [sp, #0x144]
	bl FUN_08241574
	ldr r6, [sp, #0x174]
	strh r0, [r6]
_081665E6:
	movs r1, #0x40
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081665F6
	movs r0, #1
	b _081665F8
_081665F6:
	movs r0, #0
_081665F8:
	cmp r0, #0
	beq _08166608
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0816662C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08166608:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _0816663A
	ldr r0, _08166630 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x174]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08166634
	movs r0, #1
	b _08166636
	.align 2, 0
_0816662C: .4byte 0xFFFFFEFF
_08166630: .4byte 0x030046A0
_08166634:
	movs r0, #0
_08166636:
	cmp r0, #0
	bne _08166642
_0816663A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08166642:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xf8]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816672A
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
	beq _08166684
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816668C
_08166684:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816668C:
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
	beq _081666B0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081666B8
_081666B0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081666B8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081666F0 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08166734
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081666F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081666E8
	ldrb r0, [r4, #5]
_081666E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08166704
	.align 2, 0
_081666F0: .4byte 0x0000FFFF
_081666F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08166704
	strh r1, [r4, #8]
_08166704:
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
	bne _08166734
	movs r0, #1
	strb r0, [r4, #7]
	b _08166734
_0816672A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08166734:
	movs r0, #0
	ldr r3, [sp, #0x38]
	str r0, [r3]
	ldr r0, _0816674C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08166750
	movs r0, #1
	b _08166752
	.align 2, 0
_0816674C: .4byte 0x030047A4
_08166750:
	movs r0, #0
_08166752:
	cmp r0, #0
	bne _08166792
	ldr r4, [sp, #0x48]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816677A
	adds r0, r1, #0
	cmp r0, #7
	beq _0816677A
	cmp r0, #6
	beq _0816677A
	cmp r0, #0x15
	beq _0816677A
	cmp r0, #0x14
	beq _0816677A
	cmp r0, #0x17
	bne _08166792
_0816677A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x160]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08166792:
	movs r1, #8
	ldr r6, [sp, #0x140]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081667A2
	movs r0, #1
	b _081667A4
_081667A2:
	movs r0, #0
_081667A4:
	cmp r0, #0
	beq _081667F4
	ldr r3, _08166880 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08166884 @ =0x0000046D
	adds r0, r7, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08166888 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x88]
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r0, #2
	ldr r3, [sp, #0x154]
	strb r1, [r3]
	ldr r5, [sp, #0x158]
	strb r1, [r5]
	ldr r6, [sp, #0x15c]
	strb r0, [r6]
	ldr r1, _0816688C @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08166890 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081667F4:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08163eac
	adds r0, r7, #0
	bl FUN_08163bac
	ldr r4, [sp, #0x160]
	ldrh r0, [r4]
	ldr r5, [sp, #0x84]
	strh r0, [r5]
	ldr r6, [sp, #0x30]
	ldrh r0, [r6]
	ldr r1, [sp, #0x80]
	strh r0, [r1]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	ldr r3, [sp, #0x58]
	str r0, [r3]
	ldr r4, [sp, #0x188]
	ldr r0, [r4]
	ldr r5, [sp, #0x5c]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	ldr r1, [sp, #0x154]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, [sp, #0x158]
	ldrb r0, [r3]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r5, [sp, #0x15c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r1, [sp, #0x88]
	ldr r0, [r1]
	ldr r2, [sp, #0x78]
	str r0, [r2]
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r5, _08166894 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _08166898 @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _0816689C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081668A0 @ =FUN_08165554
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081668A4 @ =FUN_08165574
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081668A8
	movs r0, #0
	b _081668AC
	.align 2, 0
_08166880: .4byte FUN_080e48d0
_08166884: .4byte 0x0000046D
_08166888: .4byte 0x0000046B
_0816688C: .4byte 0x00000484
_08166890: .4byte 0x0000046C
_08166894: .4byte 0x0000057C
_08166898: .4byte FUN_080f09e0
_0816689C: .4byte 0x0000061C
_081668A0: .4byte FUN_08165554
_081668A4: .4byte FUN_08165574
_081668A8:
	movs r0, #1
	rsbs r0, r0, #0
_081668AC:
	add sp, #0x1a0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemySlime_Create
EnemySlime_Create: @ 0x081668BC
	push {r4, r5, lr}
	movs r5, #0xd2
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081668EA
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySlime_Init
	cmp r0, #0
	bge _081668EA
	adds r0, r4, #0
	bl FUN_08165574
	adds r0, r4, #0
	bl Free
_081668EA:
	pop {r4, r5}
	pop {r0}
	bx r0
