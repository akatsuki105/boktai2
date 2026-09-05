	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081845e0
FUN_081845e0: @ 0x081845E0
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
	beq _08184602
	b _08184C88
_08184602:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0818462C
	ldr r3, _08184628 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818461A
	b _08184C88
_0818461A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08184C88
	.align 2, 0
_08184628: .4byte 0x0000048C
_0818462C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0818463C
	b _08184C88
_0818463C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0818464C
	b _08184958
_0818464C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0818465E
	b _08184C88
_0818465E:
	ldr r2, _081846F0 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08184672
	b _08184C88
_08184672:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08184680
	b _08184C88
_08184680:
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
	bne _08184698
	b _081847E0
_08184698:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08184700
	ands r3, r1
	cmp r3, #0
	beq _08184700
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081846BE
	rsbs r1, r1, #0
_081846BE:
	cmp r1, #0x20
	bgt _08184700
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081846F4 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081846F8 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081846FC @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08184C88
	.align 2, 0
_081846F0: .4byte 0x0000A007
_081846F4: .4byte 0x000004BE
_081846F8: .4byte 0x0000048C
_081846FC: .4byte 0x0000044E
_08184700:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08184728 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08184730
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0818472C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184728: .4byte 0x0000048A
_0818472C: .4byte 0x03002BE0
_08184730:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0818474C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184748 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184748: .4byte 0x03002BE0
_0818474C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08184768
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184764 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184764: .4byte 0x03002BE0
_08184768:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184784
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184780 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184780: .4byte 0x03002BE0
_08184784:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184796
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0818479E
_08184796:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081847A0
_0818479E:
	movs r3, #1
_081847A0:
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
	ldr r5, _081847D4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081847C2
	b _08184918
_081847C2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081847D8
	movs r0, #1
	b _081847DA
	.align 2, 0
_081847D4: .4byte 0x0000049C
_081847D8:
	movs r0, #0
_081847DA:
	cmp r0, #0
	bne _081848BE
	b _081848D4
_081847E0:
	strh r2, [r7, #0x3e]
	ldr r1, _08184808 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08184810
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0818480C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184808: .4byte 0x0000048A
_0818480C: .4byte 0x03002BE0
_08184810:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0818482C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184828 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184828: .4byte 0x03002BE0
_0818482C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08184848
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184844 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184844: .4byte 0x03002BE0
_08184848:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184864
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184860 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184860: .4byte 0x03002BE0
_08184864:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184876
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0818487E
_08184876:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08184880
_0818487E:
	movs r3, #1
_08184880:
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
	ldr r5, _081848B4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08184918
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081848B8
	movs r0, #1
	b _081848BA
	.align 2, 0
_081848B4: .4byte 0x0000049C
_081848B8:
	movs r0, #0
_081848BA:
	cmp r0, #0
	beq _081848D4
_081848BE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081848D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081848E0
	.align 2, 0
_081848D0: .4byte 0x03002BE0
_081848D4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08184918
_081848E0:
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
_08184918:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08184944
	ldr r5, _08184950 @ =0x0000024E
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
	bls _08184944
	strh r1, [r2]
_08184944:
	ldr r5, _08184954 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08184C88
	.align 2, 0
_08184950: .4byte 0x0000024E
_08184954: .4byte 0x0000048C
_08184958:
	ldr r0, _0818496C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08184970
	movs r0, #1
	b _08184972
	.align 2, 0
_0818496C: .4byte 0x030047A4
_08184970:
	movs r0, #0
_08184972:
	cmp r0, #0
	beq _08184980
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08184988
_08184980:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08184988:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081849C0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081849C4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081849B6
	cmp r2, #0x17
	bne _081849C8
_081849B6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081849EA
	.align 2, 0
_081849C0: .4byte 0x0000048C
_081849C4: .4byte 0x000001DF
_081849C8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081849B6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08184A18 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081849EA
	movs r1, #0
_081849EA:
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
	beq _08184A26
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08184A1C
	asrs r0, r0, #1
	b _08184A22
	.align 2, 0
_08184A18: .4byte 0x00000187
_08184A1C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08184A22:
	mov r2, sb
	strh r0, [r2]
_08184A26:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08184A44
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08184A40 @ =0x000001DD
	adds r1, r6, r4
	b _08184AB8
	.align 2, 0
_08184A40: .4byte 0x000001DD
_08184A44:
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
	bne _08184AA4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08184AA4
	ldr r2, _08184A94 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08184A98 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08184A9C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08184AA0 @ =0x000001DD
	adds r1, r6, r4
	b _08184AB8
	.align 2, 0
_08184A94: .4byte 0x030046B8
_08184A98: .4byte 0x000003FF
_08184A9C: .4byte 0x0203B400
_08184AA0: .4byte 0x000001DD
_08184AA4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08184AD8 @ =0x000001DD
	adds r1, r6, r3
_08184AB8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08184AE0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184ADC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184AD8: .4byte 0x000001DD
_08184ADC: .4byte 0x03002BE0
_08184AE0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08184AFC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184AF8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184AF8: .4byte 0x03002BE0
_08184AFC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08184B18
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08184B14 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184B14: .4byte 0x03002BE0
_08184B18:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184B34
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184B30 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184B30: .4byte 0x03002BE0
_08184B34:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184B46
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08184B4E
_08184B46:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08184B50
_08184B4E:
	movs r3, #1
_08184B50:
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
	ldr r5, _08184B84 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08184BEC
	movs r1, #2
	ldr r2, _08184B88 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08184B8C
	movs r0, #1
	b _08184B8E
	.align 2, 0
_08184B84: .4byte 0x0000049C
_08184B88: .4byte 0x00000474
_08184B8C:
	movs r0, #0
_08184B8E:
	cmp r0, #0
	beq _08184BA8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08184BA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08184BB4
	.align 2, 0
_08184BA4: .4byte 0x03002BE0
_08184BA8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08184BEC
_08184BB4:
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
_08184BEC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08184C20
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08184C20
	ldr r0, _08184C38 @ =0x0000024E
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
	bls _08184C20
	strh r1, [r2]
_08184C20:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08184C3C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08184C40 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08184C44
	movs r0, #1
	b _08184C46
	.align 2, 0
_08184C38: .4byte 0x0000024E
_08184C3C: .4byte 0x030046A0
_08184C40: .4byte 0x00000934
_08184C44:
	movs r0, #0
_08184C46:
	ldr r1, _08184C98 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08184C5E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08184C5E:
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
_08184C88:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08184C98: .4byte 0x0000048A

	thumb_func_start FUN_08184c9c
FUN_08184c9c: @ 0x08184C9C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08184ca0
FUN_08184ca0: @ 0x08184CA0
	push {lr}
	adds r3, r0, #0
	ldr r0, _08184CB8 @ =0x0000046D
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08184CBC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08184CBE
	.align 2, 0
_08184CB8: .4byte 0x0000046D
_08184CBC:
	movs r0, #0
_08184CBE:
	cmp r0, #0
	beq _08184CDE
	adds r2, r3, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _08184CEC @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08184CF0 @ =0x00000474
	adds r2, r3, r0
	ldr r0, _08184CF4 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08184CDE:
	adds r0, r3, #0
	movs r1, #0xe
	bl FUN_080efd44
	pop {r0}
	bx r0
	.align 2, 0
_08184CEC: .4byte 0x0000FFFB
_08184CF0: .4byte 0x00000474
_08184CF4: .4byte 0xFFFFF7FF

	thumb_func_start FUN_08184cf8
FUN_08184cf8: @ 0x08184CF8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08184D10 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08184D14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08184D16
	.align 2, 0
_08184D10: .4byte 0x0000046D
_08184D14:
	movs r0, #0
_08184D16:
	cmp r0, #0
	beq _08184D82
	ldr r1, [r5, #0x44]
	movs r2, #0
	movs r0, #2
	strb r0, [r1, #7]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r1, _08184D44 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08184D48
	ldr r2, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08184D56
	.align 2, 0
_08184D44: .4byte 0x0000025D
_08184D48:
	ldr r0, [r5, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08184D56:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _08184DBC @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08184DC0 @ =0x00000474
	adds r2, r5, r0
	ldr r0, _08184DC4 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080efd44
	movs r0, #0xa8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08184D82:
	ldr r1, _08184DC8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08184DB4
	ldr r4, _08184DCC @ =FUN_08184ca0
	movs r3, #0x21
	ldr r0, _08184DD0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08184DD4 @ =0x0000046B
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
_08184DB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08184DBC: .4byte 0x0000FFFB
_08184DC0: .4byte 0x00000474
_08184DC4: .4byte 0xFFFFF7FF
_08184DC8: .4byte 0x0000046E
_08184DCC: .4byte FUN_08184ca0
_08184DD0: .4byte 0x0000046D
_08184DD4: .4byte 0x0000046B

	thumb_func_start FUN_08184dd8
FUN_08184dd8: @ 0x08184DD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08184ddc
FUN_08184ddc: @ 0x08184DDC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _08184DF8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08184DFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08184DFE
	.align 2, 0
_08184DF8: .4byte 0x0000046D
_08184DFC:
	movs r0, #0
_08184DFE:
	cmp r0, #0
	beq _08184EDC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #4
	bne _08184E74
	ldr r4, _08184E5C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08184E60 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08184E64 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r1, #0
	strh r2, [r0]
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r4, _08184E68 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	ldr r1, _08184E6C @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08184E70 @ =0x0000046C
	adds r0, r5, r2
	strb r3, [r0]
	b _08184F2E
	.align 2, 0
_08184E5C: .4byte FUN_080e48d0
_08184E60: .4byte 0x0000046D
_08184E64: .4byte 0x0000046B
_08184E68: .4byte 0x00000469
_08184E6C: .4byte 0x00000484
_08184E70: .4byte 0x0000046C
_08184E74:
	cmp r1, #3
	bhi _08184EBE
	ldr r4, [r0, #0x38]
	adds r0, r5, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl FUN_081e9f78
	adds r4, #0x24
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r1, #8
	adds r0, r5, r1
	ldrh r3, [r0]
	adds r1, #0x10
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp]
	subs r1, #8
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081ea540
	movs r0, #0xf0
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08184EBE:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08184F38 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r4, _08184F3C @ =0x00000474
	adds r2, r5, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08184EDC:
	cmp r6, #0x3c
	ble _08184F2E
	ldr r3, _08184F40 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _08184F44 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
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
	movs r3, #4
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08184F48 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_08184F2E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08184F38: .4byte 0x0000FFF7
_08184F3C: .4byte 0x00000474
_08184F40: .4byte FUN_080e48d0
_08184F44: .4byte 0x0000046D
_08184F48: .4byte 0x0000046A

	thumb_func_start FUN_08184f4c
FUN_08184f4c: @ 0x08184F4C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08184F64 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08184F68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08184F6A
	.align 2, 0
_08184F64: .4byte 0x0000046D
_08184F68:
	movs r0, #0
_08184F6A:
	cmp r0, #0
	beq _08184F94
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08184FC4 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _08184FC8 @ =0x00000474
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efd44
_08184F94:
	ldr r1, _08184FCC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08184FE2
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08184FD0 @ =0x0000046B
	adds r0, r4, r1
	movs r2, #1
	strb r2, [r0]
	ldr r1, _08184FD4 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08184FD8
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08184FE2
	.align 2, 0
_08184FC4: .4byte 0x0000FFF7
_08184FC8: .4byte 0x00000474
_08184FCC: .4byte 0x0000046E
_08184FD0: .4byte 0x0000046B
_08184FD4: .4byte 0x0000025D
_08184FD8:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08184FE2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08184fe8
FUN_08184fe8: @ 0x08184FE8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, [r6, #0x44]
	adds r7, r0, #0
	adds r7, #0x48
	ldr r0, _0818500C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185010
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185012
	.align 2, 0
_0818500C: .4byte 0x0000046D
_08185010:
	movs r0, #0
_08185012:
	cmp r0, #0
	beq _08185032
	adds r0, r6, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08185032
	adds r0, r7, #0
	movs r1, #0x30
	bl FUN_08237098
_08185032:
	ldrh r0, [r7, #8]
	cmp r0, #3
	bne _08185044
	ldrh r0, [r7, #0xe]
	cmp r0, #0
	bne _08185044
	ldr r0, _081851A4 @ =0x000001DD
	bl PlaySound_082406e0
_08185044:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	movs r2, #6
	cmp r0, #1
	bne _08185054
	movs r2, #3
_08185054:
	ldrh r0, [r7, #8]
	adds r1, r0, #0
	cmp r1, #3
	beq _0818505E
	b _08185216
_0818505E:
	ldrh r0, [r7, #0xe]
	cmp r0, r2
	bgt _08185066
	b _08185216
_08185066:
	adds r5, r6, #0
	adds r5, #0xde
	ldrh r1, [r5]
	movs r0, #4
	movs r3, #0
	mov r8, r3
	movs r4, #0
	mov sb, r4
	orrs r0, r1
	ldr r1, _081851A8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081851AC @ =0x00000474
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08187364
	adds r3, r5, #0
	adds r2, r4, #0
	cmp r0, #0
	bne _0818509E
	b _08185266
_0818509E:
	ldr r3, _081851B0 @ =FUN_081853c8
	movs r1, #0x24
	ldr r2, _081851B4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081851B8 @ =0x0000046B
	adds r0, r6, r4
	mov r4, r8
	strb r4, [r0]
	ldr r4, _081851BC @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	mov r4, sb
	strh r4, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _081851C0 @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r1, _081851C4 @ =0x00000484
	adds r0, r6, r1
	mov r3, sb
	str r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r0, r6, #0
	movs r1, #0x12
	bl FUN_080efd44
	movs r0, #0x15
	add r0, sp
	mov r8, r0
	adds r0, r6, #0
	add r1, sp, #0x14
	mov r2, r8
	bl FUN_080e5d44
	ldr r3, _081851C8 @ =0x085ADBFC
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r4, [r7, #8]
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081851CC @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x18]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081851D0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r7, [r7, #8]
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r5, sp, #0x18
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #3
	bhi _081851D8
	ldr r1, _081851D4 @ =0x03002BE0
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	str r1, [sp]
	mov r7, sb
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
	b _081852D2
	.align 2, 0
_081851A4: .4byte 0x000001DD
_081851A8: .4byte 0x0000FFF7
_081851AC: .4byte 0x00000474
_081851B0: .4byte FUN_081853c8
_081851B4: .4byte 0x0000046D
_081851B8: .4byte 0x0000046B
_081851BC: .4byte 0x00000553
_081851C0: .4byte 0x0000046A
_081851C4: .4byte 0x00000484
_081851C8: .4byte 0x085ADBFC
_081851CC: .4byte 0xFFFF0000
_081851D0: .4byte 0x0000FFFF
_081851D4: .4byte 0x03002BE0
_081851D8:
	cmp r1, #4
	bne _081852D2
	ldr r4, [r0, #0x38]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	strh r2, [r0]
	adds r0, r4, #0
	bl FUN_080e499c
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r7, r8
	ldrb r0, [r7]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080e6978
	b _081852D2
_08185216:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08185248
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	ldr r0, _0818523C @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08185240 @ =0x00000474
	adds r2, r6, r1
	ldr r0, _08185244 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	b _08185264
	.align 2, 0
_0818523C: .4byte 0x0000FFFB
_08185240: .4byte 0x00000474
_08185244: .4byte 0xFFFFF7FF
_08185248:
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081852E0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r4, _081852E4 @ =0x00000474
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
_08185264:
	strh r0, [r2]
_08185266:
	ldr r7, _081852E8 @ =0x0000046E
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081852D2
	ldrh r1, [r3]
	ldr r0, _081852EC @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r5, #0
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _081852F0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _081852F4 @ =FUN_08185308
	movs r1, #0x26
	ldr r3, _081852F8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	subs r7, #3
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r4, _081852FC @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08185300 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08185304 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
_081852D2:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081852E0: .4byte 0x0000FFF7
_081852E4: .4byte 0x00000474
_081852E8: .4byte 0x0000046E
_081852EC: .4byte 0x0000FFFB
_081852F0: .4byte 0xFFFFF7FF
_081852F4: .4byte FUN_08185308
_081852F8: .4byte 0x0000046D
_081852FC: .4byte 0x00000469
_08185300: .4byte 0x00000484
_08185304: .4byte 0x0000046C

	thumb_func_start FUN_08185308
FUN_08185308: @ 0x08185308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08185320 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185324
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185326
	.align 2, 0
_08185320: .4byte 0x0000046D
_08185324:
	movs r0, #0
_08185326:
	cmp r0, #0
	beq _0818534E
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _081853AC @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _081853B0 @ =0x00000474
	adds r2, r5, r1
	ldr r0, _081853B4 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
_0818534E:
	ldr r2, _081853B8 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081853A6
	ldr r3, _081853BC @ =FUN_08184ca0
	movs r1, #0x21
	ldr r6, _081853C0 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
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
	movs r3, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081853C4 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_081853A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081853AC: .4byte 0x0000FFFB
_081853B0: .4byte 0x00000474
_081853B4: .4byte 0xFFFFF7FF
_081853B8: .4byte 0x0000046E
_081853BC: .4byte FUN_08184ca0
_081853C0: .4byte 0x0000046D
_081853C4: .4byte 0x0000046A

	thumb_func_start FUN_081853c8
FUN_081853c8: @ 0x081853C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	str r1, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081853FC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185400
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185402
	.align 2, 0
_081853FC: .4byte 0x0000046D
_08185400:
	movs r0, #0
_08185402:
	cmp r0, #0
	beq _08185436
	ldr r0, _08185470 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _08185474 @ =0x0000066C
	add r0, sl
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08185478 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r7, _0818547C @ =0x00000474
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08185436:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	mov r4, sp
	adds r4, #0x15
	adds r0, r6, #0
	add r1, sp, #0x14
	adds r2, r4, #0
	bl FUN_080e5d44
	mov r2, sb
	ldrb r0, [r2, #4]
	cmp r0, #3
	bhi _08185486
	mov r3, r8
	ldrh r0, [r3, #0xe]
	adds r0, #1
	ldrb r7, [r3, #7]
	cmp r0, r7
	blt _08185480
	ldrh r0, [r3, #8]
	adds r0, #1
	ldrb r1, [r3, #5]
	cmp r0, r1
	blt _0818548A
	movs r0, #0
	b _0818548A
	.align 2, 0
_08185470: .4byte 0x03002BE0
_08185474: .4byte 0x0000066C
_08185478: .4byte 0x0000FFF7
_0818547C: .4byte 0x00000474
_08185480:
	mov r2, r8
	ldrh r0, [r2, #8]
	b _0818548A
_08185486:
	mov r3, r8
	ldrh r0, [r3, #8]
_0818548A:
	ldr r4, _08185514 @ =0x085ADBFC
	lsls r3, r0, #3
	mov r7, sp
	adds r7, #0x15
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08185518 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r5
	orrs r2, r0
	str r2, [sp, #0x18]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0818551C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r2, [r6, #0xc]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r3, sb
	ldrb r0, [r3, #4]
	cmp r0, #4
	bne _08185520
	ldr r1, [r6, #0x44]
	movs r2, #0
	movs r0, #2
	strb r0, [r1, #7]
	ldr r0, [r3, #0x38]
	ldrb r1, [r7]
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_080e6978
	b _081856FC
	.align 2, 0
_08185514: .4byte 0x085ADBFC
_08185518: .4byte 0xFFFF0000
_0818551C: .4byte 0x0000FFFF
_08185520:
	cmp r0, #3
	bls _08185526
	b _081856FC
_08185526:
	ldr r1, [r6, #0x44]
	movs r5, #0
	movs r0, #1
	strb r0, [r1, #7]
	mov r7, sb
	ldr r7, [r7, #0x38]
	mov sb, r7
	ldr r0, _08185558 @ =0x0000066E
	add r0, sl
	ldrb r1, [r0]
	ldr r0, [sp, #0x20]
	bl Mod
	cmp r0, #0
	beq _08185546
	b _081856DC
_08185546:
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _0818555C
	movs r0, #1
	b _0818555E
	.align 2, 0
_08185558: .4byte 0x0000066E
_0818555C:
	movs r0, #0
_0818555E:
	cmp r0, #0
	bne _0818559A
	ldr r0, _08185580 @ =0x0000066C
	add r0, sl
	ldrb r2, [r0]
	ldr r0, _08185584 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, r2
	bge _0818558C
	ldr r3, _08185588 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r1, r1, r0
	b _0818558E
	.align 2, 0
_08185580: .4byte 0x0000066C
_08185584: .4byte 0x03002BE0
_08185588: .4byte 0xFFFFFF00
_0818558C:
	subs r1, r1, r2
_0818558E:
	ldr r0, _081855B0 @ =0x0000066D
	add r0, sl
	ldrb r0, [r0]
	cmp r1, r0
	bgt _0818559A
	b _081856A4
_0818559A:
	add r2, sp, #0x14
	ldrb r0, [r6, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081855B4
	asrs r0, r1, #6
	b _081855BA
	.align 2, 0
_081855B0: .4byte 0x0000066D
_081855B4:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081855BA:
	lsls r0, r0, #6
	strb r0, [r2]
	ldr r7, _08185604 @ =0x00000256
	adds r0, r6, r7
	ldrh r5, [r0]
	add r0, sp, #0x18
	mov sl, r0
	ldr r7, _08185608 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x18
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818560C
	adds r0, #4
	b _08185616
	.align 2, 0
_08185604: .4byte 0x00000256
_08185608: .4byte 0x030046A4
_0818560C:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08185616:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	movs r4, #0
	mov r7, sl
	strh r0, [r7, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r0, sp, #0x14
	ldrb r3, [r0]
	movs r0, #0x3c
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x18
	movs r2, #0x40
	bl FUN_0807ac74
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08185690 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r7, _08185694 @ =0x0000046A
	adds r0, r6, r7
	strb r5, [r0]
	ldr r1, _08185698 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818569C @ =FUN_080e48d0
	movs r2, #0x10
	adds r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081856A0 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	b _0818572C
	.align 2, 0
_08185690: .4byte 0x00000469
_08185694: .4byte 0x0000046A
_08185698: .4byte 0x00000484
_0818569C: .4byte FUN_080e48d0
_081856A0: .4byte 0x0000046B
_081856A4:
	adds r0, r6, #0
	bl FUN_0818758c
	adds r3, r0, #0
	mov r7, sp
	ldrb r0, [r7, #0x15]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, _081856D8 @ =0x00000226
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, sb
	add r1, sp, #0x18
	movs r2, #0
	bl FUN_0807ab64
	b _081856FC
	.align 2, 0
_081856D8: .4byte 0x00000226
_081856DC:
	adds r0, r6, #0
	bl FUN_0818758c
	adds r3, r0, #0
	mov r7, sp
	ldrb r0, [r7, #0x15]
	str r0, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0807ab64
_081856FC:
	adds r0, r6, #0
	movs r1, #0x12
	bl FUN_080efd44
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #0
	bne _0818571A
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _0818571A
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818571A:
	ldr r2, [sp, #0x20]
	cmp r2, #0xb4
	ble _0818572C
	ldr r3, _0818573C @ =0x0000046B
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6, #0x44]
	strb r1, [r0, #7]
_0818572C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818573C: .4byte 0x0000046B

	thumb_func_start FUN_08185740
FUN_08185740: @ 0x08185740
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _08185764 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185768
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818576A
	.align 2, 0
_08185764: .4byte 0x0000046D
_08185768:
	movs r0, #0
_0818576A:
	cmp r0, #0
	beq _08185794
	adds r0, r7, #0
	movs r1, #0x13
	bl FUN_080efd44
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081857BC @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081857C0 @ =0x00000474
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08185794:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _081857C4
	ldrh r0, [r4, #0xe]
	adds r0, #1
	ldrb r1, [r4, #7]
	cmp r0, r1
	blt _081857C4
	ldrh r0, [r4, #8]
	adds r6, r0, #1
	ldrb r4, [r4, #5]
	cmp r6, r4
	blt _081857C6
	movs r6, #0
	b _081857C6
	.align 2, 0
_081857BC: .4byte 0x0000FFF7
_081857C0: .4byte 0x00000474
_081857C4:
	ldrh r6, [r4, #8]
_081857C6:
	mov r5, sp
	adds r5, #0x15
	adds r0, r7, #0
	add r1, sp, #0x14
	adds r2, r5, #0
	bl FUN_080e5d44
	ldr r4, _08185854 @ =0x085ADC4C
	lsls r3, r6, #3
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r6, _08185858 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0x18]
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r7, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0818585C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r0, [r7, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, r8
	ldrb r3, [r1, #4]
	movs r0, #4
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r4, r2, #0
	cmp r1, #0
	beq _08185860
	mov r0, r8
	ldr r1, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r1, #0
	movs r1, #1
	movs r3, #0
	bl FUN_080e6978
	b _08185884
	.align 2, 0
_08185854: .4byte 0x085ADC4C
_08185858: .4byte 0xFFFF0000
_0818585C: .4byte 0x0000FFFF
_08185860:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185884
	mov r0, r8
	ldr r2, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl FUN_0807ab64
_08185884:
	ldr r1, _081858B0 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08185946
	subs r1, #3
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	movs r0, #2
	strb r0, [r1, #7]
	ldr r1, _081858B4 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081858B8
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081858C2
	.align 2, 0
_081858B0: .4byte 0x0000046E
_081858B4: .4byte 0x0000025D
_081858B8:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081858C2:
	movs r0, #0xf0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	mov r0, r8
	ldrb r2, [r0, #4]
	movs r0, #4
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818590C
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_080edda0
	adds r1, r0, #0
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r1, #0
	movs r1, #2
	adds r2, r4, #0
	movs r3, #0
	bl FUN_080e6978
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl FUN_081e9f78
	b _08185946
_0818590C:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185946
	mov r0, r8
	ldr r2, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl FUN_0807ab64
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_081e9f78
_08185946:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08185954
FUN_08185954: @ 0x08185954
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	ldr r0, [r5, #0x44]
	str r0, [sp, #0x1c]
	ldr r2, _0818597C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185980
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185982
	.align 2, 0
_0818597C: .4byte 0x0000046D
_08185980:
	movs r0, #0
_08185982:
	cmp r0, #0
	beq _08185A54
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080efe38
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081859E8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r6, _081859EC @ =0x00000474
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r6, r5, #0
	adds r6, #8
	adds r1, r5, #0
	adds r1, #0x9c
	ldr r0, [r1, #8]
	ldrh r0, [r0]
	strh r0, [r5, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r0, #2]
	strh r1, [r6, #4]
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081859E2
	cmp r1, #0
	blt _081859E2
	ldr r0, _081859F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081859E2
	ldr r0, _081859F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081859F8
_081859E2:
	movs r4, #0
	b _08185A06
	.align 2, 0
_081859E8: .4byte 0x0000FFF7
_081859EC: .4byte 0x00000474
_081859F0: .4byte 0x030046A8
_081859F4: .4byte 0x030046AC
_081859F8:
	ldr r0, _08185A18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08185A06:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08185A1C
	adds r0, #4
	b _08185A28
	.align 2, 0
_08185A18: .4byte 0x030046A4
_08185A1C:
	ldr r0, _08185A3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08185A28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08185A40
	cmp r2, #2
	beq _08185A44
	b _08185A48
	.align 2, 0
_08185A3C: .4byte 0x030046A4
_08185A40:
	ldrb r0, [r6, #4]
	b _08185A46
_08185A44:
	ldrb r0, [r6]
_08185A46:
	subs r1, r1, r0
_08185A48:
	strh r1, [r6, #2]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #0x1c]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_08185A54:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r6, [r0]
	mov r0, sb
	cmp r0, #0x3c
	beq _08185A66
	cmp r0, #0x5a
	bne _08185B3A
_08185A66:
	ldr r1, _08185A84 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185A88
	ldr r0, [r5, #0x44]
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	adds r3, r0, #0
	b _08185A98
	.align 2, 0
_08185A84: .4byte 0x0000025D
_08185A88:
	ldr r3, [r5, #0x44]
	adds r2, r3, #0
	adds r2, #0x20
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_08185A98:
	ldr r2, _08185AB0 @ =0x0000047C
	adds r0, r5, r2
	ldrh r1, [r0]
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185AB4
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08185ABE
	.align 2, 0
_08185AB0: .4byte 0x0000047C
_08185AB4:
	ldr r0, _08185B10 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3, #0x68]
_08185ABE:
	ldr r0, _08185B14 @ =0x00000492
	adds r1, r5, r0
	movs r3, #0
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r6, #4]
	cmp r1, #3
	bhi _08185B18
	ldr r1, [r6, #0x38]
	mov r8, r1
	adds r1, r5, #0
	adds r1, #8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r2, #0x1c
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, r8
	movs r2, #0
	bl FUN_0807ab64
	movs r0, #0xe6
	bl PlaySound_082406e0
	b _08185B62
	.align 2, 0
_08185B10: .4byte 0x03003584
_08185B14: .4byte 0x00000492
_08185B18:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08185B62
	ldr r4, [r6, #0x38]
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r1, #2
	add r2, sp, #0x14
	movs r3, #0
	bl FUN_080e6978
	adds r0, r4, #0
	bl FUN_080e7f30
	b _08185B62
_08185B3A:
	movs r2, #1
	ldr r1, _08185B54 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185B58
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185B62
	.align 2, 0
_08185B54: .4byte 0x0000025D
_08185B58:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185B62:
	mov r0, sb
	subs r0, #0x33
	cmp r0, #8
	bhi _08185B70
	movs r0, #0x14
	bl FUN_0823b9cc
_08185B70:
	mov r0, sb
	subs r0, #0x51
	cmp r0, #8
	bhi _08185B7E
	movs r0, #0x28
	bl FUN_0823b9cc
_08185B7E:
	mov r2, sb
	cmp r2, #0x78
	bgt _08185B86
	b _08185D1A
_08185B86:
	movs r2, #1
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185B98
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185BA2
_08185B98:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185BA2:
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08185BC4
	ldr r4, [r6, #0x38]
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #2
	add r2, sp, #0x14
	movs r3, #0
	bl FUN_080e6978
	b _08185C88
_08185BC4:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185C88
	ldr r6, [r6, #0x38]
	mov r8, r6
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _08185BE2
	asrs r0, r1, #6
	b _08185BE8
_08185BE2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08185BE8:
	lsls r0, r0, #6
	str r0, [sp, #0x20]
	ldr r6, _08185C30 @ =0x00000256
	adds r0, r5, r6
	ldrh r6, [r0]
	add r0, sp, #0x14
	mov sl, r0
	ldr r7, _08185C34 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x14
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08185C38
	adds r0, #4
	b _08185C42
	.align 2, 0
_08185C30: .4byte 0x00000256
_08185C34: .4byte 0x030046A4
_08185C38:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08185C42:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	mov r6, sl
	strh r0, [r6, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	movs r0, #0x3c
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	add r1, sp, #0x14
	movs r2, #0x80
	ldr r3, [sp, #0x20]
	bl FUN_0807ac74
	adds r0, r5, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl FUN_081e9f78
	ldr r0, _08185D2C @ =0x000001DF
	bl PlaySound_082406e0
_08185C88:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080efd44
	ldr r3, _08185D30 @ =FUN_080e48d0
	movs r4, #1
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
	movs r2, #0
	strb r2, [r0]
	subs r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldr r3, _08185D34 @ =FUN_080e68d8
	movs r1, #0xe
	subs r6, #0xe4
	adds r0, r5, r6
	strb r4, [r0]
	subs r6, #2
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
	ldr r1, _08185D38 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08185D3C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	ldrh r0, [r5, #8]
	adds r0, #0x20
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, #0x20
	strh r0, [r5, #0xc]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r6, [sp, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_08185D1A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08185D2C: .4byte 0x000001DF
_08185D30: .4byte FUN_080e48d0
_08185D34: .4byte FUN_080e68d8
_08185D38: .4byte 0x00000469
_08185D3C: .4byte 0x0000046C

	thumb_func_start FUN_08185d40
FUN_08185d40: @ 0x08185D40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08185D5C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185D60
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185D62
	.align 2, 0
_08185D5C: .4byte 0x0000046D
_08185D60:
	movs r0, #0
_08185D62:
	cmp r0, #0
	bne _08185D68
	b _08185F5E
_08185D68:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08185DB0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _08185DB4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080efe38
	ldr r2, _08185DB8 @ =0x0000047A
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, r0, #3
	ldr r6, _08185DBC @ =0x0000025D
	adds r0, r5, r6
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185DC0
	ldr r0, [r5, #0x44]
	adds r0, #0x2c
	adds r1, r3, #0
	bl FUN_0822b20c
	b _08185DCC
	.align 2, 0
_08185DB0: .4byte 0x0000FFF7
_08185DB4: .4byte 0x00000474
_08185DB8: .4byte 0x0000047A
_08185DBC: .4byte 0x0000025D
_08185DC0:
	ldr r2, [r5, #0x44]
	ldr r0, _08185DE0 @ =0x03003584
	lsls r1, r3, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08185DCC:
	movs r2, #1
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185DE4
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185DEE
	.align 2, 0
_08185DE0: .4byte 0x03003584
_08185DE4:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185DEE:
	ldr r1, [r5, #0x44]
	movs r0, #3
	strb r0, [r1, #7]
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0x8a
	lsls r0, r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #2
	movs r3, #1
	bl FUN_081e9f78
	ldr r0, _08185E38 @ =0x000001D9
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080e49c4
	ldr r1, _08185E3C @ =0x0000047A
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r7]
	mov r8, r4
	cmp r0, #0
	bne _08185E40
	ldr r0, [r5, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08185E4C
	.align 2, 0
_08185E38: .4byte 0x000001D9
_08185E3C: .4byte 0x0000047A
_08185E40:
	ldr r2, [r5, #0x44]
	ldr r0, _08185ED4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08185E4C:
	ldr r3, _08185ED8 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _08185EDC @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
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
	ldr r1, _08185EE0 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08185EE4 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	mov r6, r8
	adds r1, r5, #0
	adds r1, #0x9c
	ldr r0, [r1, #8]
	ldrh r0, [r0]
	strh r0, [r5, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r0, #2]
	strh r1, [r6, #4]
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08185ECE
	cmp r1, #0
	blt _08185ECE
	ldr r0, _08185EE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08185ECE
	ldr r0, _08185EEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08185EF0
_08185ECE:
	movs r4, #0
	b _08185EFE
	.align 2, 0
_08185ED4: .4byte 0x03003584
_08185ED8: .4byte FUN_080e48d0
_08185EDC: .4byte 0x0000046D
_08185EE0: .4byte 0x00000469
_08185EE4: .4byte 0x0000046C
_08185EE8: .4byte 0x030046A8
_08185EEC: .4byte 0x030046AC
_08185EF0:
	ldr r0, _08185F10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08185EFE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08185F14
	adds r0, #4
	b _08185F20
	.align 2, 0
_08185F10: .4byte 0x030046A4
_08185F14:
	ldr r0, _08185F34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08185F20:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08185F38
	cmp r2, #2
	beq _08185F3C
	b _08185F40
	.align 2, 0
_08185F34: .4byte 0x030046A4
_08185F38:
	ldrb r0, [r6, #4]
	b _08185F3E
_08185F3C:
	ldrb r0, [r6]
_08185F3E:
	subs r1, r1, r0
_08185F40:
	strh r1, [r6, #2]
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185F54
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08185F5E
_08185F54:
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08185F5E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08185f6c
FUN_08185f6c: @ 0x08185F6C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _08185F8C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185F90
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185F92
	.align 2, 0
_08185F8C: .4byte 0x0000046D
_08185F90:
	movs r0, #0
_08185F92:
	cmp r0, #0
	beq _08185FDA
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080efd44
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _08186094 @ =0x0000046E
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08186098 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r7, _0818609C @ =0x00000474
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08185FDA:
	movs r0, #0x10
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x11
	bgt _08186006
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _08186006
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08186006
	cmp r2, #1
	beq _08186006
	strh r3, [r4, #0xe]
_08186006:
	ldr r1, _08186094 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0818608C
	ldr r2, _081860A0 @ =0x0000046B
	adds r0, r6, r2
	movs r3, #0
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r2, r6, r7
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r4, _081860A4 @ =FUN_08184f4c
	movs r2, #0x22
	ldr r1, _081860A8 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _081860A0 @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	movs r2, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _081860AC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _081860B0 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xfe
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrb r0, [r0]
	strb r0, [r6, #5]
_0818608C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08186094: .4byte 0x0000046E
_08186098: .4byte 0x0000FFF7
_0818609C: .4byte 0x00000474
_081860A0: .4byte 0x0000046B
_081860A4: .4byte FUN_08184f4c
_081860A8: .4byte 0x0000046D
_081860AC: .4byte 0x00000469
_081860B0: .4byte 0x00000484

	thumb_func_start FUN_081860b4
FUN_081860b4: @ 0x081860B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r6, [r7, #0x44]
	ldr r2, _081860E4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081860E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081860EA
	.align 2, 0
_081860E4: .4byte 0x0000046D
_081860E8:
	movs r0, #0
_081860EA:
	cmp r0, #0
	bne _081860F0
	b _0818620C
_081860F0:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080efd44
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
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	movs r3, #0
	mov sb, r3
	orrs r0, r1
	ldr r1, _081861E0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r5, _081861E4 @ =0x00000474
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, sb
	strh r5, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	movs r1, #8
	bl ClearMemory
	ldr r5, _081861E8 @ =0x0203B400
	ldr r4, _081861EC @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _081861F0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #0x48
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r2, r2, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0x20
	rsbs r1, r1, #0
	orrs r0, r1
	ldr r1, _081861F4 @ =0x0000065E
	add r1, r8
	strh r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, sb
	strh r5, [r0]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _081861C2
	rsbs r0, r0, #0
_081861C2:
	cmp r0, #9
	bgt _081861CA
	movs r0, #0xa
	strh r0, [r1]
_081861CA:
	movs r2, #2
	ldr r3, _081861F8 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081861FC
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08186206
	.align 2, 0
_081861E0: .4byte 0x0000FFF7
_081861E4: .4byte 0x00000474
_081861E8: .4byte 0x0203B400
_081861EC: .4byte 0x030046B8
_081861F0: .4byte 0x000003FF
_081861F4: .4byte 0x0000065E
_081861F8: .4byte 0x0000025D
_081861FC:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08186206:
	adds r0, r7, #0
	bl FUN_080e8360
_0818620C:
	ldr r0, _081862B8 @ =0x0000065E
	add r0, r8
	ldrb r0, [r0]
	ldrb r5, [r6, #6]
	adds r0, r0, r5
	strb r0, [r6, #6]
	ldrb r0, [r6, #6]
	movs r2, #0xd0
	lsls r2, r2, #1
	subs r2, r2, r0
	movs r3, #0xff
	ands r2, r3
	ldr r4, _081862BC @ =0x085B0A08
	adds r0, r2, #0
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #5
	adds r1, r1, r0
	asrs r1, r1, #0xb
	ldrh r0, [r6, #0x20]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	adds r2, #0x40
	ands r2, r3
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r1, r0, #5
	adds r1, r1, r0
	asrs r1, r1, #0xb
	ldrh r0, [r6, #0x1c]
	subs r0, r0, r1
	strh r0, [r6, #0x1c]
	movs r1, #0x10
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08186268
	b _08186434
_08186268:
	movs r0, #0x40
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl FUN_081e9f78
	movs r0, #0xec
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
	ldr r3, _081862C0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _081862C4
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r2, r1, #0
	b _081862D0
	.align 2, 0
_081862B8: .4byte 0x0000065E
_081862BC: .4byte 0x085B0A08
_081862C0: .4byte 0x0000025D
_081862C4:
	ldr r2, [r7, #0x44]
	adds r1, r2, #0
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_081862D0:
	ldrb r0, [r3]
	cmp r0, #0
	bne _081862E2
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081862EE
_081862E2:
	adds r2, #0x20
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_081862EE:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r5, #0xcd
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _08186356
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #4]
	movs r3, #0xa
	ldrsh r0, [r7, r3]
	str r0, [sp, #8]
	movs r5, #0xc
	ldrsh r0, [r7, r5]
	str r0, [sp, #0xc]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r5, #0xd2
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldrh r0, [r7]
	str r0, [sp, #0x20]
	ldr r1, _08186380 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r3, sp, #4
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_08186356:
	ldr r5, _08186384 @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0818638C
	ldr r0, _08186388 @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r3
	b _0818639E
	.align 2, 0
_08186380: .4byte 0xFFFF0000
_08186384: .4byte 0x000001DF
_08186388: .4byte 0x030046A0
_0818638C:
	ldr r0, _0818641C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0818639E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, _08186420 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r1, _08186424 @ =0x0000046D
	adds r0, r7, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r5, _08186428 @ =0x0000046B
	adds r0, r7, r5
	strb r3, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r3, [r0]
	movs r4, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0818642C @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	add r2, sp, #4
	movs r0, #8
	strh r0, [r2]
	adds r0, r2, #0
	strh r3, [r0, #2]
	ldr r0, _08186430 @ =0x00000664
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0818644C
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xf
	add r1, sp, #4
	bl FUN_080ec848
	b _0818644C
	.align 2, 0
_0818641C: .4byte 0x030046A0
_08186420: .4byte FUN_080e48d0
_08186424: .4byte 0x0000046D
_08186428: .4byte 0x0000046B
_0818642C: .4byte 0x0000046A
_08186430: .4byte 0x00000664
_08186434:
	mov r0, sl
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0818644C
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
_0818644C:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818645c
FUN_0818645c: @ 0x0818645C
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r2, [r0, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r0, #6]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08186470
FUN_08186470: @ 0x08186470
	push {lr}
	adds r1, r0, #0
	adds r0, #0xd8
	adds r1, #8
	movs r2, #0
	bl FUN_082364c4
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08186484
FUN_08186484: @ 0x08186484
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0818649C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081864A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081864A2
	.align 2, 0
_0818649C: .4byte 0x0000046C
_081864A0:
	movs r0, #0
_081864A2:
	cmp r0, #0
	beq _081864F2
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081864DC @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081864E0 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #1
	ldr r3, _081864E4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081864E8
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081864F2
	.align 2, 0
_081864DC: .4byte 0x0000FFF7
_081864E0: .4byte 0x00000474
_081864E4: .4byte 0x0000025D
_081864E8:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081864F2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08187364
	adds r3, r0, #0
	cmp r3, #0
	bne _08186542
	ldr r4, _08186534 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	cmp r0, #0x3c
	ble _0818653C
	movs r1, #2
	movs r2, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	subs r4, #0x1b
	adds r0, r5, r4
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186534 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	ldr r2, _08186538 @ =0x0000046C
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _0818658E
	.align 2, 0
_08186534: .4byte 0x00000484
_08186538: .4byte 0x0000046C
_0818653C:
	adds r0, #1
	str r0, [r1]
	b _0818658E
_08186542:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _08186594 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _08186598 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818659C @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #4
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _081865A0 @ =FUN_08184cf8
	movs r3, #0x28
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081865A4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_0818658E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186594: .4byte 0x00000469
_08186598: .4byte 0x0000046A
_0818659C: .4byte 0x00000484
_081865A0: .4byte FUN_08184cf8
_081865A4: .4byte 0x0000046B

	thumb_func_start FUN_081865a8
FUN_081865a8: @ 0x081865A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081865C0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081865C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081865C6
	.align 2, 0
_081865C0: .4byte 0x0000046C
_081865C4:
	movs r0, #0
_081865C6:
	cmp r0, #0
	beq _081865FC
	ldr r4, _08186638 @ =FUN_08184cf8
	movs r3, #0x28
	ldr r2, _0818663C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08186640 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186644 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _08186648 @ =0x0000046E
	adds r0, r5, r2
	strb r1, [r0]
_081865FC:
	ldr r6, _08186648 @ =0x0000046E
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08186612
	ldr r1, _08186644 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	beq _08186612
	b _08186720
_08186612:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08187364
	cmp r0, #0
	beq _081866A8
	ldr r2, _0818664C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08186650
	ldr r2, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0818665E
	.align 2, 0
_08186638: .4byte FUN_08184cf8
_0818663C: .4byte 0x0000046D
_08186640: .4byte 0x0000046B
_08186644: .4byte 0x00000553
_08186648: .4byte 0x0000046E
_0818664C: .4byte 0x0000025D
_08186650:
	ldr r0, [r5, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_0818665E:
	movs r4, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r2, #0
	strb r4, [r0]
	ldr r1, _08186708 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818670C @ =FUN_08184fe8
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08186710 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r4, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081866A8:
	ldr r1, _08186714 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _08186720
	ldr r2, _08186718 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0xb4
	ble _08186720
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1b
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	ldr r4, _0818671C @ =FUN_080e48d0
	movs r3, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08186710 @ =0x0000046B
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
	b _0818672A
	.align 2, 0
_08186708: .4byte 0x00000469
_0818670C: .4byte FUN_08184fe8
_08186710: .4byte 0x0000046B
_08186714: .4byte 0x00000553
_08186718: .4byte 0x00000484
_0818671C: .4byte FUN_080e48d0
_08186720:
	ldr r0, _08186730 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818672A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186730: .4byte 0x00000484

	thumb_func_start FUN_08186734
FUN_08186734: @ 0x08186734
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081867AC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186746
	movs r0, #0
	strb r0, [r1]
_08186746:
	adds r0, r5, #0
	bl FUN_08187294
	adds r4, r0, #0
	cmp r4, #0
	beq _081867C0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	str r4, [r0]
	ldr r3, _081867B0 @ =FUN_08184ddc
	movs r1, #0x2c
	ldr r2, _081867B4 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081867B8 @ =0x0000046B
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
	ldr r1, _081867BC @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _081867AC @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _0818682C
	.align 2, 0
_081867AC: .4byte 0x0000046C
_081867B0: .4byte FUN_08184ddc
_081867B4: .4byte 0x0000046D
_081867B8: .4byte 0x0000046B
_081867BC: .4byte 0x00000469
_081867C0:
	ldr r6, _08186834 @ =0x00000484
	adds r0, r5, r6
	ldr r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bgt _081867DA
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08187364
	cmp r0, #0
	beq _08186822
_081867DA:
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r6, _08186838 @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0818683C @ =FUN_080e48d0
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08186840 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_08186822:
	ldr r6, _08186834 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818682C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186834: .4byte 0x00000484
_08186838: .4byte 0x00000469
_0818683C: .4byte FUN_080e48d0
_08186840: .4byte 0x0000046B

	thumb_func_start FUN_08186844
FUN_08186844: @ 0x08186844
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r7, [r0]
	ldr r3, _0818686C @ =0x0000046C
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186870
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08186872
	.align 2, 0
_0818686C: .4byte 0x0000046C
_08186870:
	movs r0, #0
_08186872:
	cmp r0, #0
	beq _08186880
	movs r5, #0xcd
	lsls r5, r5, #3
	adds r1, r6, r5
	movs r0, #0
	strh r0, [r1]
_08186880:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08187364
	adds r3, r0, #0
	cmp r3, #0
	bne _081868E0
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r1, _081868CC @ =0x0000066A
	adds r0, r6, r1
	ldrh r5, [r2]
	mov ip, r5
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	ble _081868D8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	strb r3, [r0]
	ldr r2, _081868D0 @ =0x00000469
	adds r0, r4, r2
	strb r3, [r0]
	ldr r5, _081868D4 @ =0x0000046A
	adds r0, r4, r5
	strb r3, [r0]
	adds r1, #0x1c
	adds r0, r4, r1
	str r3, [r0]
	adds r2, #3
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _081868EA
	.align 2, 0
_081868CC: .4byte 0x0000066A
_081868D0: .4byte 0x00000469
_081868D4: .4byte 0x0000046A
_081868D8:
	mov r0, ip
	adds r0, #1
	strh r0, [r2]
	b _081868EA
_081868E0:
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
_081868EA:
	ldr r5, _08186974 @ =0x00000484
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _08186964
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _08186964
	movs r3, #8
	ldrsh r0, [r7, r3]
	movs r6, #8
	ldrsh r1, [r4, r6]
	subs r0, r0, r1
	movs r2, #0xc
	ldrsh r1, [r7, r2]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #5]
	movs r3, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	ldr r1, _08186978 @ =0x00000469
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0818697C @ =0x0000046A
	adds r0, r4, r2
	strb r5, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r5, [r0]
	adds r1, #3
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _08186980 @ =FUN_08184fe8
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08186984 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_08186964:
	ldr r3, _08186974 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08186974: .4byte 0x00000484
_08186978: .4byte 0x00000469
_0818697C: .4byte 0x0000046A
_08186980: .4byte FUN_08184fe8
_08186984: .4byte 0x0000046B

	thumb_func_start FUN_08186988
FUN_08186988: @ 0x08186988
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081869A0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081869A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081869A6
	.align 2, 0
_081869A0: .4byte 0x0000046C
_081869A4:
	movs r0, #0
_081869A6:
	cmp r0, #0
	beq _081869DA
	ldr r4, _08186A5C @ =FUN_08184f4c
	movs r3, #0x22
	ldr r2, _08186A60 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08186A64 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186A68 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r1, #0
	strh r2, [r0]
	adds r0, r5, r6
	strb r1, [r0]
_081869DA:
	ldr r6, _08186A64 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186A54
	ldr r3, _08186A6C @ =FUN_080e48d0
	movs r4, #1
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	adds r6, #0xe9
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08186A70 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	movs r1, #3
	subs r3, #0xe9
	adds r0, r5, r3
	strb r1, [r0]
	subs r6, #0xe9
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186A74 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _08186A78 @ =FUN_080e68d8
	movs r1, #0xe
	adds r6, #1
	adds r0, r5, r6
	strb r4, [r0]
	ldr r4, _08186A64 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08186A54:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186A5C: .4byte FUN_08184f4c
_08186A60: .4byte 0x0000046D
_08186A64: .4byte 0x0000046B
_08186A68: .4byte 0x00000553
_08186A6C: .4byte FUN_080e48d0
_08186A70: .4byte 0x00000551
_08186A74: .4byte 0x0000046A
_08186A78: .4byte FUN_080e68d8

	thumb_func_start FUN_08186a7c
FUN_08186a7c: @ 0x08186A7C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08186AE8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186A8E
	movs r0, #0
	strb r0, [r1]
_08186A8E:
	ldr r1, _08186AEC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186AFC
	ldr r2, _08186AF0 @ =FUN_081853c8
	movs r1, #0x24
	ldr r3, _08186AF4 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08186AEC @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08186AF8 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _08186AE8 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	b _08186B06
	.align 2, 0
_08186AE8: .4byte 0x0000046C
_08186AEC: .4byte 0x0000046B
_08186AF0: .4byte FUN_081853c8
_08186AF4: .4byte 0x0000046D
_08186AF8: .4byte 0x00000469
_08186AFC:
	ldr r6, _08186B0C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08186B06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186B0C: .4byte 0x00000484

	thumb_func_start FUN_08186b10
FUN_08186b10: @ 0x08186B10
	push {lr}
	ldr r2, _08186B24 @ =0x0000046C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186B20
	movs r0, #0
	strb r0, [r1]
_08186B20:
	pop {r0}
	bx r0
	.align 2, 0
_08186B24: .4byte 0x0000046C

	thumb_func_start FUN_08186b28
FUN_08186b28: @ 0x08186B28
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _08186B74 @ =0x0000046C
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186B3A
	movs r0, #0
	strb r0, [r1]
_08186B3A:
	ldr r1, _08186B78 @ =0x00000484
	adds r3, r2, r1
	ldr r0, [r3]
	cmp r0, #0x3c
	ble _08186B68
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r2, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r2, r4
	str r1, [r0]
	ldr r0, _08186B74 @ =0x0000046C
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
_08186B68:
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08186B74: .4byte 0x0000046C
_08186B78: .4byte 0x00000484

	thumb_func_start FUN_08186b7c
FUN_08186b7c: @ 0x08186B7C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08186BEC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186B8E
	movs r0, #0
	strb r0, [r1]
_08186B8E:
	ldr r1, _08186BF0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186BE6
	ldr r2, _08186BF4 @ =FUN_08185740
	movs r1, #0x25
	ldr r3, _08186BF8 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08186BF0 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08186BFC @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _08186BEC @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
_08186BE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186BEC: .4byte 0x0000046C
_08186BF0: .4byte 0x0000046B
_08186BF4: .4byte FUN_08185740
_08186BF8: .4byte 0x0000046D
_08186BFC: .4byte 0x00000469

	thumb_func_start FUN_08186c00
FUN_08186c00: @ 0x08186C00
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _08186C70 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186C12
	movs r0, #0
	strb r0, [r1]
_08186C12:
	ldr r1, _08186C74 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186C6A
	ldr r2, _08186C78 @ =FUN_08185954
	movs r1, #0x27
	ldr r3, _08186C7C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08186C74 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _08186C80 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08186C84 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r3, [r0]
	ldr r3, _08186C70 @ =0x0000046C
	adds r0, r6, r3
	strb r5, [r0]
_08186C6A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08186C70: .4byte 0x0000046C
_08186C74: .4byte 0x0000046B
_08186C78: .4byte FUN_08185954
_08186C7C: .4byte 0x0000046D
_08186C80: .4byte 0x00000553
_08186C84: .4byte 0x00000469

	thumb_func_start FUN_08186c88
FUN_08186c88: @ 0x08186C88
	push {lr}
	ldr r2, _08186C9C @ =0x0000046C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186C98
	movs r0, #0
	strb r0, [r1]
_08186C98:
	pop {r0}
	bx r0
	.align 2, 0
_08186C9C: .4byte 0x0000046C

	thumb_func_start FUN_08186ca0
FUN_08186ca0: @ 0x08186CA0
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08186CEC @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186CB2
	movs r0, #0
	strb r0, [r1]
_08186CB2:
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	ldr r4, _08186CF0 @ =0x00000484
	adds r2, r3, r4
	ldr r1, [r2]
	cmp r0, r1
	bgt _08186CF4
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	subs r4, #0x1b
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #0x1a
	adds r0, r3, r4
	str r1, [r0]
	ldr r1, _08186CEC @ =0x0000046C
	adds r0, r3, r1
	strb r2, [r0]
	b _08186CF8
	.align 2, 0
_08186CEC: .4byte 0x0000046C
_08186CF0: .4byte 0x00000484
_08186CF4:
	adds r0, r1, #1
	str r0, [r2]
_08186CF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08186d00
FUN_08186d00: @ 0x08186D00
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08186D6C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186D12
	movs r0, #0
	strb r0, [r1]
_08186D12:
	ldr r1, _08186D70 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186D66
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r2, [r0]
	ldr r6, _08186D74 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _08186D78 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08186D70 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_08186D66:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186D6C: .4byte 0x0000046C
_08186D70: .4byte 0x0000046B
_08186D74: .4byte 0x00000469
_08186D78: .4byte FUN_080e48d0

	thumb_func_start FUN_08186d7c
FUN_08186d7c: @ 0x08186D7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08186D94 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08186D98
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08186D9A
	.align 2, 0
_08186D94: .4byte 0x0000046C
_08186D98:
	movs r0, #0
_08186D9A:
	cmp r0, #0
	beq _08186DEE
	movs r2, #1
	ldr r1, _08186DB4 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08186DB8
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08186DC2
	.align 2, 0
_08186DB4: .4byte 0x0000025D
_08186DB8:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08186DC2:
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08186E00 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _08186E04 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080e49c4
_08186DEE:
	ldr r2, _08186E08 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08186E00: .4byte 0x00000469
_08186E04: .4byte 0x0000046C
_08186E08: .4byte 0x00000484

	thumb_func_start FUN_08186e0c
FUN_08186e0c: @ 0x08186E0C
	ldr r1, _08186E28 @ =0x00000634
	adds r2, r0, r1
	ldr r1, _08186E2C @ =0x085ADC84
	str r1, [r2]
	ldr r1, _08186E30 @ =0x0000063C
	adds r2, r0, r1
	ldr r1, _08186E34 @ =0x085ADC6C
	str r1, [r2]
	ldr r1, _08186E38 @ =0x00000644
	adds r0, r0, r1
	ldr r1, _08186E3C @ =0x085ADC98
	str r1, [r0]
	bx lr
	.align 2, 0
_08186E28: .4byte 0x00000634
_08186E2C: .4byte 0x085ADC84
_08186E30: .4byte 0x0000063C
_08186E34: .4byte 0x085ADC6C
_08186E38: .4byte 0x00000644
_08186E3C: .4byte 0x085ADC98

	thumb_func_start FUN_08186e40
FUN_08186e40: @ 0x08186E40
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _08186EB8
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r6, _08186EA8 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	ldr r1, _08186EAC @ =0x0000046A
	adds r0, r4, r1
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08186EB0 @ =FUN_08185f6c
	movs r2, #0x29
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08186EB4 @ =0x0000046B
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
	movs r0, #1
	b _08186EC2
	.align 2, 0
_08186EA8: .4byte 0x00000469
_08186EAC: .4byte 0x0000046A
_08186EB0: .4byte FUN_08185f6c
_08186EB4: .4byte 0x0000046B
_08186EB8:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
_08186EC2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08186ec8
FUN_08186ec8: @ 0x08186EC8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08186f3c
FUN_08186f3c: @ 0x08186F3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r0, r1
	strh r2, [r0]
	ldrh r0, [r4, #8]
	adds r0, #0x20
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	adds r0, #0x20
	strh r0, [r4, #0xc]
	ldr r2, _08186F7C @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08186F80
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08186F8A
	.align 2, 0
_08186F7C: .4byte 0x0000025D
_08186F80:
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08186F8A:
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
	beq _08186FC6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08186FCE
_08186FC6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08186FCE:
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
	beq _08186FF2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08186FFA
_08186FF2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08186FFA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08187030 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08187068
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08187034
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818702A
	ldrb r0, [r4, #5]
_0818702A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08187044
	.align 2, 0
_08187030: .4byte 0x0000FFFF
_08187034:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08187044
	strh r1, [r4, #8]
_08187044:
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
	bne _08187068
	movs r0, #1
	strb r0, [r4, #7]
_08187068:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08187070
FUN_08187070: @ 0x08187070
	push {r4, r5, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r4, _081870E0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _081870E4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081870E8 @ =FUN_081845e0
	str r5, [sp]
	ldr r0, _081870EC @ =0x00005005
	str r0, [sp, #4]
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080e38a8
	movs r2, #0
	str r2, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	str r0, [r1, #4]
	str r2, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081870F0 @ =FUN_08184c9c
	movs r0, #1
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl FUN_080e3984
	add sp, #0x28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081870E0: .4byte 0xFFFF0000
_081870E4: .4byte 0x0000FFFF
_081870E8: .4byte FUN_081845e0
_081870EC: .4byte 0x00005005
_081870F0: .4byte FUN_08184c9c

	thumb_func_start FUN_081870f4
FUN_081870f4: @ 0x081870F4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r5, [r0]
	ldr r2, _08187188 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _0818718C @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r6, r2
	str r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	movs r7, #1
	strb r7, [r0]
	ldr r0, _08187190 @ =FUN_08185d40
	mov ip, r0
	movs r2, #0x3c
	adds r4, #0xec
	adds r3, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r2, [r0]
	mov r0, ip
	str r0, [r3]
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	subs r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08187194 @ =FUN_080e68d8
	movs r2, #0xe
	subs r4, #0xe4
	adds r0, r6, r4
	strb r7, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_080e4a68
	ldr r1, _08187198 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818719C
	ldr r1, [r6, #0x44]
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	b _081871A6
	.align 2, 0
_08187188: .4byte 0x00000469
_0818718C: .4byte 0x0000046A
_08187190: .4byte FUN_08185d40
_08187194: .4byte FUN_080e68d8
_08187198: .4byte 0x0000025D
_0818719C:
	ldr r1, [r6, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r7
	str r0, [r1, #8]
_081871A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081871ac
FUN_081871ac: @ 0x081871AC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _081871F6
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r5, [r0]
	movs r0, #0x42
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	bl FUN_08188978
	mov r1, sp
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r6]
	strh r0, [r1, #2]
	ldr r2, _08187200 @ =0x000001DF
	adds r0, r6, r2
	ldrb r0, [r0]
	strh r0, [r1, #4]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xf
	bl FUN_080ec848
	ldr r0, _08187204 @ =0x00000664
	adds r5, r5, r0
	str r4, [r5]
_081871F6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08187200: .4byte 0x000001DF
_08187204: .4byte 0x00000664

	thumb_func_start FUN_08187208
FUN_08187208: @ 0x08187208
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x10
	bl FUN_080efd44
	movs r2, #1
	ldr r1, _08187228 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818722C
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08187236
	.align 2, 0
_08187228: .4byte 0x0000025D
_0818722C:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08187236:
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08187288 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _0818728C @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08187290 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08187288: .4byte 0x00000469
_0818728C: .4byte FUN_080e48d0
_08187290: .4byte 0x0000046B

	thumb_func_start FUN_08187294
FUN_08187294: @ 0x08187294
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	lsls r6, r0, #1
	ldr r0, _081872DC @ =0x03002BE0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081872C2
	movs r6, #0x90
	lsls r6, r6, #0xa
_081872C2:
	ldr r2, _081872E0 @ =0x00000553
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _081872E4
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _081872E4
	movs r0, #0
	b _08187352
	.align 2, 0
_081872DC: .4byte 0x03002BE0
_081872E0: .4byte 0x00000553
_081872E4:
	movs r0, #0x80
	lsls r0, r0, #5
	mov sb, r0
	mov r3, sp
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _08187360 @ =0x03002BE0
	movs r1, #0
	mov ip, r1
_081872F6:
	ldr r1, [r4]
	cmp r1, #0
	beq _08187342
	ldr r0, [r1, #0x20]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	bne _08187342
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r6, r1
	ble _08187342
	adds r6, r1, #0
	ldr r0, [r4]
	adds r0, #0x24
	mov r8, r0
_08187342:
	adds r4, #4
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	mov r1, ip
	cmp r1, #0
	bge _081872F6
	mov r0, r8
_08187352:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08187360: .4byte 0x03002BE0

	thumb_func_start FUN_08187364
FUN_08187364: @ 0x08187364
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_08187294
	adds r6, r0, #0
	cmp r6, #0
	beq _081873D8
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bne _081873D8
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r6, #0
	adds r3, #8
	ldrh r0, [r6, #8]
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
	mov r0, sp
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	cmp r8, r1
	ble _081873D6
	mov r8, r1
	b _081873D8
_081873D6:
	movs r6, #0
_081873D8:
	adds r7, r5, #0
	adds r7, #8
	adds r0, r7, #0
	bl FUN_080edc40
	adds r4, r0, #0
	cmp r4, #0
	beq _08187430
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08187430
	mov r2, sp
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r4, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r8, r1
	ble _08187430
	adds r6, r4, #0
_08187430:
	cmp r6, #0
	bne _08187436
	b _0818757C
_08187436:
	ldrh r0, [r6, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0818745A
	cmp r1, #0
	blt _0818745A
	ldr r0, _08187460 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0818745A
	ldr r0, _08187464 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08187468
_0818745A:
	movs r3, #0
	b _08187476
	.align 2, 0
_08187460: .4byte 0x030046A8
_08187464: .4byte 0x030046AC
_08187468:
	ldr r0, _08187494 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_08187476:
	mov r4, sb
	cmp r4, #1
	bne _081874DA
	ldr r1, _08187498 @ =0x00000256
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r1, #1
	cmp r0, r3
	bne _0818749C
	movs r0, #0
	strb r0, [r5, #5]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0818756C
	.align 2, 0
_08187494: .4byte 0x030046A4
_08187498: .4byte 0x00000256
_0818749C:
	subs r0, r1, #1
	cmp r0, r3
	bne _081874A8
	movs r0, #0x80
	strb r0, [r5, #5]
	b _08187566
_081874A8:
	ldr r0, _081874C4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r2, [r0, r4]
	adds r0, r1, r2
	cmp r0, r3
	bne _081874C8
	movs r0, #0x40
	strb r0, [r5, #5]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _0818756C
	.align 2, 0
_081874C4: .4byte 0x030046A4
_081874C8:
	subs r0, r1, r2
	cmp r0, r3
	bne _0818757C
	movs r0, #0xc0
	strb r0, [r5, #5]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0818756C
_081874DA:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _08187514
	cmp r1, #1
	bgt _081874F2
	cmp r1, #0
	beq _081874FC
	b _0818757C
_081874F2:
	cmp r1, #2
	beq _0818753C
	cmp r1, #3
	beq _08187550
	b _0818757C
_081874FC:
	ldr r4, _08187510 @ =0x00000256
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, #1
	cmp r0, r3
	bne _0818757C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _0818756C
	.align 2, 0
_08187510: .4byte 0x00000256
_08187514:
	ldr r2, _08187534 @ =0x00000256
	adds r1, r5, r2
	ldr r0, _08187538 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, r3
	bne _0818757C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _0818756C
	.align 2, 0
_08187534: .4byte 0x00000256
_08187538: .4byte 0x030046A4
_0818753C:
	ldr r2, _0818754C @ =0x00000256
	adds r0, r5, r2
	ldrh r0, [r0]
	subs r0, #1
	cmp r0, r3
	bne _0818757C
	b _08187566
	.align 2, 0
_0818754C: .4byte 0x00000256
_08187550:
	ldr r4, _08187574 @ =0x00000256
	adds r0, r5, r4
	ldrh r1, [r0]
	ldr r0, _08187578 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, r3
	bne _0818757C
_08187566:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
_0818756C:
	str r6, [r0]
	adds r0, r6, #0
	b _0818757E
	.align 2, 0
_08187574: .4byte 0x00000256
_08187578: .4byte 0x030046A4
_0818757C:
	movs r0, #0
_0818757E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0818758c
FUN_0818758c: @ 0x0818758C
	push {lr}
	ldr r0, [r0, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	cmp r1, #3
	bne _0818759C
	movs r0, #1
	b _081875A6
_0818759C:
	cmp r1, #4
	beq _081875A4
	ldrh r0, [r0, #8]
	b _081875A6
_081875A4:
	movs r0, #0
_081875A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081875ac
FUN_081875ac: @ 0x081875AC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0818645c
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081875E4 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_08186470
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081875E4: .4byte 0x0000062C

	thumb_func_start FUN_081875e8
FUN_081875e8: @ 0x081875E8
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081875f4
FUN_081875f4: @ 0x081875F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0818760C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08187610
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08187618
	.align 2, 0
_0818760C: .4byte 0x0000025D
_08187610:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08187618:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08187634 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08187638
	movs r0, #1
	b _0818763A
	.align 2, 0
_08187634: .4byte 0x00000474
_08187638:
	movs r0, #0
_0818763A:
	cmp r0, #0
	beq _08187646
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08187646:
	ldr r1, _081876A0 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0818765E
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0818765E:
	ldr r0, _081876A4 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08187676
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08187676:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0818768E
	adds r0, r4, #0
	bl FUN_08002a58
_0818768E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081876A8
	movs r0, #1
	b _081876AA
	.align 2, 0
_081876A0: .4byte 0x0000044C
_081876A4: .4byte 0x0000044D
_081876A8:
	movs r0, #0
_081876AA:
	cmp r0, #0
	beq _081876B6
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081876B6:
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

	thumb_func_start EnemyOctopus_Init
EnemyOctopus_Init: @ 0x081876D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x19c
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_08186ec8
	ldr r2, _08187758 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08187768
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0818775C @ =0x0000D291
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08187760 @ =0x0000DCEB
	bl FUN_080e3804
	ldr r3, _08187764 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _08187746
	cmp r1, #0x17
	bne _0818774A
_08187746:
	movs r0, #1
	strb r0, [r5, #7]
_0818774A:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081877D0
	.align 2, 0
_08187758: .4byte 0x0000025D
_0818775C: .4byte 0x0000D291
_08187760: .4byte 0x0000DCEB
_08187764: .4byte 0x000001DF
_08187768:
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
	ldr r2, _0818784C @ =0x05000002
	bl CpuSet
	ldr r0, _08187850 @ =0x0000CB05
	ldr r1, _08187854 @ =0x0000D291
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
	ldr r6, _08187858 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x9c]
_081877D0:
	str r7, [sp, #0x28]
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
	ldr r3, _0818785C @ =0x0000046F
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
	ldr r1, _08187860 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0818784C @ =0x05000002
	bl CpuSet
	ldr r3, _08187864 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x198]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x54]
	mov r3, r8
	str r3, [sp, #0x5c]
	str r6, [sp, #0x44]
	ldr r2, [sp, #0x198]
	adds r6, r2, #0
	cmp r0, #0
	bne _0818783C
	b _08187998
_0818783C:
	bl VM_GetPC
	cmp r0, #0
	beq _08187868
	bl Script_GetValue
	adds r1, r0, #0
	b _0818786A
	.align 2, 0
_0818784C: .4byte 0x05000002
_08187850: .4byte 0x0000CB05
_08187854: .4byte 0x0000D291
_08187858: .4byte 0x000004B7
_0818785C: .4byte 0x0000046F
_08187860: .4byte 0x00000474
_08187864: .4byte 0x000004B6
_08187868:
	movs r1, #0
_0818786A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08187890 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	cmp r0, #0
	beq _08187894
	bl Script_GetValue
	adds r1, r0, #0
	b _08187896
	.align 2, 0
_08187890: .4byte 0x00000251
_08187894:
	movs r1, #0
_08187896:
	ldr r2, _081878CC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081878D0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xb8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc0]
	cmp r0, #0
	beq _081878D4
	bl Script_GetValue
	b _081878D8
	.align 2, 0
_081878CC: .4byte 0x00000252
_081878D0: .4byte 0x000004B4
_081878D4:
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
_081878D8:
	strb r0, [r6]
	ldr r5, [sp, #0xb8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc0]
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
	blt _08187910
	cmp r1, #0
	blt _08187910
	ldr r0, _08187914 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08187910
	ldr r0, _08187918 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818791C
_08187910:
	movs r1, #0
	b _0818792A
	.align 2, 0
_08187914: .4byte 0x030046A8
_08187918: .4byte 0x030046AC
_0818791C:
	ldr r0, _08187944 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0818792A:
	ldr r2, _08187948 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818794C
	adds r0, #4
	b _08187958
	.align 2, 0
_08187944: .4byte 0x030046A4
_08187948: .4byte 0x00000256
_0818794C:
	ldr r0, _0818796C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08187958:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08187970
	cmp r2, #2
	beq _08187974
	b _08187978
	.align 2, 0
_0818796C: .4byte 0x030046A4
_08187970:
	ldrb r0, [r4, #4]
	b _08187976
_08187974:
	ldrb r0, [r4]
_08187976:
	subs r1, r1, r0
_08187978:
	ldr r3, _08187990 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08187994 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081879D8
	.align 2, 0
_08187990: .4byte 0x00000472
_08187994: .4byte 0x0000FFFF
_08187998:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081879FC @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08187A00 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08187A04 @ =0x000004B4
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
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
_081879D8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08187A22
	bl VM_GetPC
	cmp r0, #0
	beq _08187A08
	bl Script_GetValue
	adds r4, r0, #0
	b _08187A0A
	.align 2, 0
_081879FC: .4byte 0x00000251
_08187A00: .4byte 0x00000252
_08187A04: .4byte 0x000004B4
_08187A08:
	movs r4, #0x30
_08187A0A:
	bl VM_GetPC
	cmp r0, #0
	beq _08187A1C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08187A1E
_08187A1C:
	movs r5, #0x40
_08187A1E:
	mov r8, r4
	b _08187A28
_08187A22:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08187A28:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08187A60
	bl VM_GetPC
	cmp r0, #0
	beq _08187A42
	bl Script_GetValue
	adds r6, r0, #0
	b _08187A44
_08187A42:
	movs r6, #0
_08187A44:
	bl VM_GetPC
	cmp r0, #0
	beq _08187A54
	bl Script_GetValue
	adds r1, r0, #0
	b _08187A56
_08187A54:
	movs r1, #0
_08187A56:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08187A6A
_08187A60:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08187A6A:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08187CDC @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xd4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x88]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x90]
	lsls r6, r6, #0x10
	str r6, [sp, #0x94]
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	ldr r4, _08187CE0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x84]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x194]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x30]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x34]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x184]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r1, _08187CE4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _08187CE8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r3, _08187CEC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x50]
	ldr r4, _08187CF0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x78]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	ldr r4, _08187CF4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _08187CF8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x138]
	ldr r1, _08187CFC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x140]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x144]
	ldr r3, _08187D00 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _08187D04 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x150]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08187D08 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _08187D0C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x174]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _08187D10 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	ldr r4, _08187D14 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _08187D18 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	ldr r2, _08187D1C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _08187D20 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x180]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _08187D24 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x15c]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x154]
	ldr r3, _08187D28 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x160]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _08187D2C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	ldr r1, _08187D30 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _08187D34 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x110]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x114]
	ldr r6, _08187D38 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x118]
	ldr r1, _08187D3C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08187D40 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xac]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _08187D44 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r1, _08187D48 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r2, _08187D4C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _08187D50 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x98]
	ldr r1, _08187D54 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x80]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf0]
	ldr r4, _08187D58 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xc8]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xcc]
	ldr r6, _08187D5C @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08187D60 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	ldr r2, _08187D64 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _08187D68 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	ldr r5, _08187D6C @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xec]
	cmp r0, #0
	bne _08187CAC
	b _08187DC6
_08187CAC:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_08187CCC:
	bl VM_GetPC
	cmp r0, #0
	beq _08187D70
	bl Script_GetValue
	b _08187D72
	.align 2, 0
_08187CDC: .4byte 0x0000025D
_08187CE0: .4byte 0x0000025A
_08187CE4: .4byte 0x0000047A
_08187CE8: .4byte 0x0000047C
_08187CEC: .4byte 0x0000047E
_08187CF0: .4byte 0x000004A4
_08187CF4: .4byte 0x000005A4
_08187CF8: .4byte 0x000005C4
_08187CFC: .4byte 0x000005CC
_08187D00: .4byte 0x000005D4
_08187D04: .4byte 0x000005DC
_08187D08: .4byte 0x00000584
_08187D0C: .4byte 0x00000604
_08187D10: .4byte 0x0000021D
_08187D14: .4byte 0x0000060C
_08187D18: .4byte 0x000005E4
_08187D1C: .4byte 0x000005FC
_08187D20: .4byte 0x00000614
_08187D24: .4byte 0x000005BC
_08187D28: .4byte 0x000005EC
_08187D2C: .4byte 0x00000624
_08187D30: .4byte 0x0000058C
_08187D34: .4byte 0x00000594
_08187D38: .4byte 0x0000059C
_08187D3C: .4byte 0x000005B4
_08187D40: .4byte 0x00000543
_08187D44: .4byte 0x00000496
_08187D48: .4byte 0x00000469
_08187D4C: .4byte 0x0000046A
_08187D50: .4byte 0x00000553
_08187D54: .4byte 0x00000572
_08187D58: .4byte 0x0000055C
_08187D5C: .4byte 0x00000564
_08187D60: .4byte 0x00000565
_08187D64: .4byte 0x00000566
_08187D68: .4byte 0x00000567
_08187D6C: .4byte 0x0000056C
_08187D70:
	movs r0, #0x18
_08187D72:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08187D84
	bl Script_GetValue
	b _08187D86
_08187D84:
	movs r0, #0x18
_08187D86:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08187D98
	bl Script_GetValue
	b _08187D9A
_08187D98:
	movs r0, #0
_08187D9A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08187DAC
	bl Script_GetValue
	b _08187DAE
_08187DAC:
	movs r0, #0
_08187DAE:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _08187CCC
_08187DC6:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08187E12
	bl VM_GetPC
	cmp r0, #0
	beq _08187DE0
	bl Script_GetValue
	adds r4, r0, #0
	b _08187DE4
_08187DE0:
	movs r4, #0x96
	lsls r4, r4, #1
_08187DE4:
	bl VM_GetPC
	cmp r0, #0
	beq _08187DF4
	bl Script_GetValue
	adds r6, r0, #0
	b _08187DF8
_08187DF4:
	movs r6, #0x96
	lsls r6, r6, #1
_08187DF8:
	bl VM_GetPC
	cmp r0, #0
	beq _08187E06
	bl Script_GetValue
	b _08187E0C
_08187E06:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_08187E0C:
	ldr r5, [sp, #0xb0]
	strh r0, [r5]
	b _08187E1A
_08187E12:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0xb0]
	strh r6, [r0]
_08187E1A:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08187E32
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08187E32:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x68]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08187F00
	bl VM_GetPC
	cmp r0, #0
	beq _08187E62
	bl Script_GetValue
	b _08187E64
_08187E62:
	movs r0, #0
_08187E64:
	ldr r1, [sp, #0xc4]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08187E72
	asrs r1, r0, #1
	b _08187E78
_08187E72:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08187E78:
	ldr r2, _08187E8C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08187E90
	bl Script_GetValue
	b _08187E92
	.align 2, 0
_08187E8C: .4byte 0x00000546
_08187E90:
	movs r0, #0
_08187E92:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EA8
	bl Script_GetValue
	b _08187EAA
_08187EA8:
	movs r0, #0
_08187EAA:
	ldr r5, _08187EC0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EC4
	bl Script_GetValue
	adds r1, r0, #0
	b _08187EC6
	.align 2, 0
_08187EC0: .4byte 0x00000187
_08187EC4:
	movs r1, #0
_08187EC6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EDC
	bl Script_GetValue
	b _08187EDE
_08187EDC:
	movs r0, #0
_08187EDE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EF6
	bl Script_GetValue
	adds r1, r0, #0
	b _08187EF8
_08187EF6:
	movs r1, #0
_08187EF8:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08187F00:
	ldr r0, [sp, #0xc4]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x88]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x90]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x94]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x8c]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08187F62
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08187F48
	bl Script_GetValue
	b _08187F4A
_08187F48:
	movs r0, #0
_08187F4A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08187F5A
	bl Script_GetValue
	b _08187F5C
_08187F5A:
	movs r0, #0
_08187F5C:
	ldr r2, _08187FC4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08187F62:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, [sp, #0xd0]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08187F86
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x5c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08187F86:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08187F9E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08187F9E:
	ldr r6, [sp, #0x84]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08187FC8
	movs r0, #1
	b _08187FCA
	.align 2, 0
_08187FC4: .4byte 0x00000189
_08187FC8:
	movs r0, #0
_08187FCA:
	cmp r0, #0
	beq _08187FDA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08188004 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08187FDA:
	ldr r3, [sp, #0xd4]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08187FE6
	ldr r1, [r7, #0x44]
_08187FE6:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0x9c]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08188008
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x194]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08188014
	.align 2, 0
_08188004: .4byte FUN_080f48ac
_08188008:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x194]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08188014:
	ldr r5, [sp, #0x9c]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08188062
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08188062
	cmp r0, #0x16
	beq _08188062
	cmp r0, #0x14
	beq _08188062
	cmp r0, #9
	beq _08188062
	cmp r0, #0x19
	beq _08188062
	cmp r0, #0x1a
	beq _08188062
	cmp r0, #0xd
	beq _08188062
	cmp r0, #0x1b
	beq _08188062
	cmp r0, #0x1f
	beq _08188062
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xb8]
	ldrb r2, [r6]
	ldr r0, [sp, #0xbc]
	ldrb r3, [r0]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_08188062:
	movs r1, #8
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08188072
	movs r0, #1
	b _08188074
_08188072:
	movs r0, #0
_08188074:
	cmp r0, #0
	beq _08188082
	ldr r6, [sp, #0xa4]
	ldr r0, [r6]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	b _08188094
_08188082:
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa0]
	str r0, [r3]
_08188094:
	ldrh r0, [r7]
	ldr r4, [sp, #0x30]
	strh r0, [r4]
	ldr r5, [sp, #0x184]
	ldr r6, [sp, #0x34]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081880BE
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
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_081880BE:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08188122
	bl VM_GetPC
	cmp r0, #0
	beq _081880D8
	bl Script_GetValue
	adds r1, r0, #0
	b _081880DA
_081880D8:
	movs r1, #0
_081880DA:
	ldr r2, [sp, #0x24]
	ldr r3, _081880F4 @ =0x0000066A
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081880F8
	bl Script_GetValue
	adds r1, r0, #0
	b _081880FA
	.align 2, 0
_081880F4: .4byte 0x0000066A
_081880F8:
	movs r1, #0
_081880FA:
	ldr r4, [sp, #0x24]
	ldr r5, _08188114 @ =0x0000066E
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08188118
	bl Script_GetValue
	adds r1, r0, #0
	b _0818811A
	.align 2, 0
_08188114: .4byte 0x0000066E
_08188118:
	movs r1, #0
_0818811A:
	ldr r6, [sp, #0x24]
	ldr r2, _08188144 @ =0x0000066D
	adds r0, r6, r2
	strb r1, [r0]
_08188122:
	ldrh r0, [r7, #8]
	adds r0, #0x20
	strh r0, [r7, #8]
	ldrh r0, [r7, #0xc]
	adds r0, #0x20
	strh r0, [r7, #0xc]
	ldr r3, [sp, #0xd4]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08188148
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08188152
	.align 2, 0
_08188144: .4byte 0x0000066D
_08188148:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08188152:
	ldr r4, _08188190 @ =0x000001BF
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	ldr r0, [sp, #0x48]
	strh r4, [r0]
	ldr r1, [sp, #0x4c]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x50]
	strh r0, [r2]
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	cmp r0, #0
	bne _08188194
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081881A0
	.align 2, 0
_08188190: .4byte 0x000001BF
_08188194:
	ldr r2, [r7, #0x44]
	ldr r0, _081881D8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081881A0:
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	cmp r0, #1
	bne _081881F0
	ldr r6, [sp, #0x9c]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081881DC
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
	b _081881E6
	.align 2, 0
_081881D8: .4byte 0x03003584
_081881DC:
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	bl FUN_080ecf60
	adds r4, r0, #1
_081881E6:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081881F0:
	adds r0, r7, #0
	bl FUN_08187070
	ldr r2, [sp, #0x24]
	movs r4, #0xce
	lsls r4, r4, #3
	adds r3, r2, r4
	ldr r5, _0818838C @ =0x00000694
	adds r4, r2, r5
	ldr r5, _08188390 @ =FUN_081875ac
	movs r1, #0
	ldr r6, _08188394 @ =FUN_08184dd8
	mov sb, r6
	ldr r0, _08188398 @ =FUN_081860b4
	mov ip, r0
	ldr r2, _0818839C @ =FUN_080f62ac
	mov r8, r2
	movs r6, #1
	mov sl, r6
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x54]
	ldr r0, [r6]
	orrs r0, r2
	str r0, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x7c]
	str r4, [r2]
	ldr r3, [sp, #0xfc]
	str r5, [r3]
	ldr r4, [sp, #0x104]
	str r1, [r4]
	ldr r5, [sp, #0x10c]
	str r1, [r5]
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r0, [sp, #0x120]
	str r1, [r0]
	ldr r2, [sp, #0x134]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r1, [r3]
	ldr r4, [sp, #0x140]
	str r1, [r4]
	mov r5, ip
	ldr r6, [sp, #0x144]
	str r5, [r6]
	ldr r0, _081883A0 @ =FUN_080f44f4
	ldr r2, [sp, #0x148]
	str r0, [r2]
	ldr r0, _081883A4 @ =FUN_080f410c
	ldr r3, [sp, #0x150]
	str r0, [r3]
	ldr r4, [sp, #0x13c]
	str r1, [r4]
	mov r5, sb
	ldr r6, [sp, #0x100]
	str r5, [r6]
	mov r0, r8
	ldr r2, [sp, #0x174]
	str r0, [r2]
	ldr r0, _081883A8 @ =FUN_080f0430
	ldr r3, [sp, #0x178]
	str r0, [r3]
	mov r5, sl
	ldr r4, [sp, #0xa8]
	strb r5, [r4]
	ldr r0, _081883AC @ =0x085AD470
	ldr r6, [sp, #0x17c]
	str r0, [r6]
	ldr r0, _081883B0 @ =FUN_080e73c8
	ldr r2, [sp, #0x164]
	str r0, [r2]
	ldr r3, [sp, #0x158]
	str r1, [r3]
	ldr r4, [sp, #0x168]
	str r1, [r4]
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r0, [sp, #0x180]
	str r1, [r0]
	ldr r0, _081883B4 @ =FUN_080f0320
	ldr r2, [sp, #0x188]
	str r0, [r2]
	ldr r0, _081883B8 @ =FUN_080eff14
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _081883BC @ =FUN_080e72b0
	ldr r4, [sp, #0x15c]
	str r0, [r4]
	ldr r5, [sp, #0x154]
	str r1, [r5]
	ldr r0, _081883C0 @ =FUN_080f47c8
	ldr r6, [sp, #0x160]
	str r0, [r6]
	ldr r0, _081883C4 @ =FUN_080f54e4
	ldr r2, [sp, #0x14c]
	str r0, [r2]
	ldr r3, [sp, #0x124]
	str r1, [r3]
	ldr r0, _081883C8 @ =FUN_080f6e64
	ldr r4, [sp, #0x18c]
	str r0, [r4]
	ldr r0, _081883CC @ =FUN_080f64f0
	ldr r5, [sp, #0x108]
	str r0, [r5]
	ldr r0, _081883D0 @ =FUN_080f84d4
	ldr r6, [sp, #0x190]
	str r0, [r6]
	ldr r0, _081883D4 @ =FUN_080f624c
	ldr r2, [sp, #0x12c]
	str r0, [r2]
	ldr r0, _081883D8 @ =FUN_080f56ec
	ldr r3, [sp, #0x110]
	str r0, [r3]
	ldr r0, _081883DC @ =FUN_080f5b34
	ldr r4, [sp, #0x114]
	str r0, [r4]
	ldr r0, _081883E0 @ =FUN_080f5fac
	ldr r5, [sp, #0x118]
	str r0, [r5]
	ldr r6, [sp, #0x128]
	str r1, [r6]
	movs r0, #0x28
	ldr r2, [sp, #0xac]
	strb r0, [r2]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _081883E4 @ =FUN_08186f3c
	str r0, [r2]
	ldr r4, _081883E8 @ =0x000005AC
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	ldr r6, _081883EC @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081883F0 @ =FUN_08186e40
	str r0, [r1]
	ldr r0, _081883F4 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x54]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x81
	lsls r1, r1, #3
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x44]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081871ac
	movs r0, #0x45
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08188360
	movs r1, #0x80
	lsls r1, r1, #0x12
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08188360:
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08188402
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0818837E:
	bl VM_GetPC
	cmp r0, #0
	beq _081883F8
	bl Script_GetValue
	b _081883FA
	.align 2, 0
_0818838C: .4byte 0x00000694
_08188390: .4byte FUN_081875ac
_08188394: .4byte FUN_08184dd8
_08188398: .4byte FUN_081860b4
_0818839C: .4byte FUN_080f62ac
_081883A0: .4byte FUN_080f44f4
_081883A4: .4byte FUN_080f410c
_081883A8: .4byte FUN_080f0430
_081883AC: .4byte 0x085AD470
_081883B0: .4byte FUN_080e73c8
_081883B4: .4byte FUN_080f0320
_081883B8: .4byte FUN_080eff14
_081883BC: .4byte FUN_080e72b0
_081883C0: .4byte FUN_080f47c8
_081883C4: .4byte FUN_080f54e4
_081883C8: .4byte FUN_080f6e64
_081883CC: .4byte FUN_080f64f0
_081883D0: .4byte FUN_080f84d4
_081883D4: .4byte FUN_080f624c
_081883D8: .4byte FUN_080f56ec
_081883DC: .4byte FUN_080f5b34
_081883E0: .4byte FUN_080f5fac
_081883E4: .4byte FUN_08186f3c
_081883E8: .4byte 0x000005AC
_081883EC: .4byte 0x0000058C
_081883F0: .4byte FUN_08186e40
_081883F4: .4byte 0x000001DF
_081883F8:
	movs r0, #0
_081883FA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0818837E
_08188402:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _0818843A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x54]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0818843A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0818843A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818844C
	movs r0, #1
	b _0818844E
_0818844C:
	movs r0, #0
_0818844E:
	cmp r0, #0
	beq _08188460
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08188460:
	cmp r2, #1
	beq _081884A0
	movs r1, #0
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	ldr r3, [sp, #0x40]
	strb r1, [r3]
	ldr r4, _081884B0 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081884B4 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x120]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xf8]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081884A0:
	movs r1, #2
	ldr r3, [sp, #0x44]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081884B8
	movs r0, #1
	b _081884BA
	.align 2, 0
_081884B0: .4byte 0x00000484
_081884B4: .4byte 0x0000046C
_081884B8:
	movs r0, #0
_081884BA:
	cmp r0, #0
	beq _081884D4
	ldr r0, _081884D0 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081884DE
	.align 2, 0
_081884D0: .4byte 0x030046A0
_081884D4:
	ldr r0, [sp, #0x184]
	bl FUN_08241574
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081884DE:
	movs r1, #0x40
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081884EE
	movs r0, #1
	b _081884F0
_081884EE:
	movs r0, #0
_081884F0:
	cmp r0, #0
	beq _08188500
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08188524 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08188500:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08188532
	ldr r0, _08188528 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0818852C
	movs r0, #1
	b _0818852E
	.align 2, 0
_08188524: .4byte 0xFFFFFEFF
_08188528: .4byte 0x030046A0
_0818852C:
	movs r0, #0
_0818852E:
	cmp r0, #0
	bne _0818853A
_08188532:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0818853A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08188622
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
	beq _0818857C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08188584
_0818857C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08188584:
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
	beq _081885A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081885B0
_081885A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081885B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081885E8 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0818862C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081885EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081885E0
	ldrb r0, [r4, #5]
_081885E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081885FC
	.align 2, 0
_081885E8: .4byte 0x0000FFFF
_081885EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081885FC
	strh r1, [r4, #8]
_081885FC:
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
	bne _0818862C
	movs r0, #1
	strb r0, [r4, #7]
	b _0818862C
_08188622:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0818862C:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08188644 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08188648
	movs r0, #1
	b _0818864A
	.align 2, 0
_08188644: .4byte 0x030047A4
_08188648:
	movs r0, #0
_0818864A:
	cmp r0, #0
	bne _0818868A
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08188672
	adds r0, r1, #0
	cmp r0, #7
	beq _08188672
	cmp r0, #6
	beq _08188672
	cmp r0, #0x15
	beq _08188672
	cmp r0, #0x14
	beq _08188672
	cmp r0, #0x17
	bne _0818868A
_08188672:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x44]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0818868A:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08186e0c
	ldr r6, _0818871C @ =0x0000060C
	adds r1, r7, r6
	ldr r0, _08188720 @ =0x085ADCA8
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_08187208
	ldr r1, [sp, #0x44]
	ldrh r0, [r1]
	ldr r2, [sp, #0xf4]
	strh r0, [r2]
	ldr r3, [sp, #0x80]
	ldrh r0, [r3]
	ldr r4, [sp, #0xf0]
	strh r0, [r4]
	ldr r5, [sp, #0x54]
	ldr r0, [r5]
	ldr r6, [sp, #0xc8]
	str r0, [r6]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xd8]
	strb r0, [r3]
	ldr r4, [sp, #0x38]
	ldrb r0, [r4]
	ldr r5, [sp, #0xdc]
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xe0]
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	ldr r3, [sp, #0xe4]
	strb r0, [r3]
	ldr r4, [sp, #0xf8]
	ldr r0, [r4]
	ldr r5, [sp, #0xe8]
	str r0, [r5]
	ldr r6, [sp, #0xb4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xec]
	strb r0, [r1]
	ldr r2, _08188724 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08188728 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0818872C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08188730 @ =FUN_081875e8
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08188734 @ =FUN_081875f4
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08188738
	movs r0, #0
	b _0818873C
	.align 2, 0
_0818871C: .4byte 0x0000060C
_08188720: .4byte 0x085ADCA8
_08188724: .4byte 0x0000057C
_08188728: .4byte FUN_080f09e0
_0818872C: .4byte 0x0000061C
_08188730: .4byte FUN_081875e8
_08188734: .4byte FUN_081875f4
_08188738:
	movs r0, #1
	rsbs r0, r0, #0
_0818873C:
	add sp, #0x19c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyOctopus_Create
EnemyOctopus_Create: @ 0x0818874C
	push {r4, r5, lr}
	ldr r5, _08188780 @ =0x0000069C
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08188778
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyOctopus_Init
	cmp r0, #0
	bge _08188778
	adds r0, r4, #0
	bl FUN_081875f4
	adds r0, r4, #0
	bl Free
_08188778:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08188780: .4byte 0x0000069C
