	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08170604
FUN_08170604: @ 0x08170604
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08170638
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08170638
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08170640 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08170638:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08170640: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08170644
FUN_08170644: @ 0x08170644
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817066A
	b _08170D34
_0817066A:
	ldr r0, [r4]
	movs r1, #0x20
	ldr r2, _08170680 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170684
	movs r0, #1
	b _08170686
	.align 2, 0
_08170680: .4byte 0x00001008
_08170684:
	movs r0, #0
_08170686:
	cmp r0, #0
	beq _0817068C
	b _08170D34
_0817068C:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0817069C
	b _08170D20
_0817069C:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081706C4
	ldr r4, _081706C0 @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081706B4
	b _08170D20
_081706B4:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08170D20
	.align 2, 0
_081706C0: .4byte 0x0000048C
_081706C4:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081706D4
	b _08170D20
_081706D4:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081706E4
	b _081709F0
_081706E4:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081706F6
	b _08170D20
_081706F6:
	ldr r2, _08170788 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0817070A
	b _08170D20
_0817070A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08170718
	b _08170D20
_08170718:
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
	bne _08170730
	b _08170878
_08170730:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08170798
	ands r3, r1
	cmp r3, #0
	beq _08170798
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08170756
	rsbs r1, r1, #0
_08170756:
	cmp r1, #0x20
	bgt _08170798
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0817078C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08170790 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08170794 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08170D20
	.align 2, 0
_08170788: .4byte 0x0000A007
_0817078C: .4byte 0x000004BE
_08170790: .4byte 0x0000048C
_08170794: .4byte 0x0000044E
_08170798:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081707C0 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081707C8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081707C4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707C0: .4byte 0x0000048A
_081707C4: .4byte 0x03002BE0
_081707C8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081707E4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081707E0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707E0: .4byte 0x03002BE0
_081707E4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08170800
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081707FC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707FC: .4byte 0x03002BE0
_08170800:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817081C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08170818 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_08170818: .4byte 0x03002BE0
_0817081C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817082E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08170836
_0817082E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170838
_08170836:
	movs r3, #1
_08170838:
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
	ldr r5, _0817086C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0817085A
	b _081709B0
_0817085A:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170870
	movs r0, #1
	b _08170872
	.align 2, 0
_0817086C: .4byte 0x0000049C
_08170870:
	movs r0, #0
_08170872:
	cmp r0, #0
	bne _08170956
	b _0817096C
_08170878:
	strh r2, [r7, #0x3e]
	ldr r1, _081708A0 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081708A8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081708A4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708A0: .4byte 0x0000048A
_081708A4: .4byte 0x03002BE0
_081708A8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081708C4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081708C0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708C0: .4byte 0x03002BE0
_081708C4:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081708E0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081708DC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708DC: .4byte 0x03002BE0
_081708E0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081708FC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081708F8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708F8: .4byte 0x03002BE0
_081708FC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817090E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08170916
_0817090E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170918
_08170916:
	movs r3, #1
_08170918:
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
	ldr r5, _0817094C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081709B0
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170950
	movs r0, #1
	b _08170952
	.align 2, 0
_0817094C: .4byte 0x0000049C
_08170950:
	movs r0, #0
_08170952:
	cmp r0, #0
	beq _0817096C
_08170956:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170968 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08170978
	.align 2, 0
_08170968: .4byte 0x03002BE0
_0817096C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081709B0
_08170978:
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
_081709B0:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081709DC
	ldr r5, _081709E8 @ =0x0000024E
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
	bls _081709DC
	strh r1, [r2]
_081709DC:
	ldr r5, _081709EC @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08170D20
	.align 2, 0
_081709E8: .4byte 0x0000024E
_081709EC: .4byte 0x0000048C
_081709F0:
	ldr r0, _08170A04 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08170A08
	movs r0, #1
	b _08170A0A
	.align 2, 0
_08170A04: .4byte 0x030047A4
_08170A08:
	movs r0, #0
_08170A0A:
	cmp r0, #0
	beq _08170A18
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08170A20
_08170A18:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08170A20:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08170A58 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08170A5C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08170A4E
	cmp r2, #0x17
	bne _08170A60
_08170A4E:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08170A82
	.align 2, 0
_08170A58: .4byte 0x0000048C
_08170A5C: .4byte 0x000001DF
_08170A60:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08170A4E
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08170AB0 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08170A82
	movs r1, #0
_08170A82:
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
	beq _08170ABE
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08170AB4
	asrs r0, r0, #1
	b _08170ABA
	.align 2, 0
_08170AB0: .4byte 0x00000187
_08170AB4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08170ABA:
	mov r2, sb
	strh r0, [r2]
_08170ABE:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08170ADC
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08170AD8 @ =0x000001DD
	adds r1, r6, r4
	b _08170B50
	.align 2, 0
_08170AD8: .4byte 0x000001DD
_08170ADC:
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
	bne _08170B3C
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08170B3C
	ldr r2, _08170B2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08170B30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08170B34 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08170B38 @ =0x000001DD
	adds r1, r6, r4
	b _08170B50
	.align 2, 0
_08170B2C: .4byte 0x030046B8
_08170B30: .4byte 0x000003FF
_08170B34: .4byte 0x0203B400
_08170B38: .4byte 0x000001DD
_08170B3C:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08170B70 @ =0x000001DD
	adds r1, r6, r3
_08170B50:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08170B78
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08170B74 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170B70: .4byte 0x000001DD
_08170B74: .4byte 0x03002BE0
_08170B78:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08170B94
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08170B90 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170B90: .4byte 0x03002BE0
_08170B94:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08170BB0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170BAC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170BAC: .4byte 0x03002BE0
_08170BB0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08170BCC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08170BC8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170BC8: .4byte 0x03002BE0
_08170BCC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08170BDE
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08170BE6
_08170BDE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170BE8
_08170BE6:
	movs r3, #1
_08170BE8:
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
	ldr r5, _08170C1C @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08170C84
	movs r1, #2
	ldr r2, _08170C20 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170C24
	movs r0, #1
	b _08170C26
	.align 2, 0
_08170C1C: .4byte 0x0000049C
_08170C20: .4byte 0x00000474
_08170C24:
	movs r0, #0
_08170C26:
	cmp r0, #0
	beq _08170C40
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08170C4C
	.align 2, 0
_08170C3C: .4byte 0x03002BE0
_08170C40:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08170C84
_08170C4C:
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
_08170C84:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08170CB8
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08170CB8
	ldr r0, _08170CD0 @ =0x0000024E
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
	bls _08170CB8
	strh r1, [r2]
_08170CB8:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08170CD4 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08170CD8 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170CDC
	movs r0, #1
	b _08170CDE
	.align 2, 0
_08170CD0: .4byte 0x0000024E
_08170CD4: .4byte 0x030046A0
_08170CD8: .4byte 0x00000934
_08170CDC:
	movs r0, #0
_08170CDE:
	ldr r1, _08170D44 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08170CF6
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08170CF6:
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
_08170D20:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r2, _08170D48 @ =0x00001008
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_08170D34:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08170D44: .4byte 0x0000048A
_08170D48: .4byte 0x00001008

	thumb_func_start FUN_08170d4c
FUN_08170d4c: @ 0x08170D4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08170D68 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08170D6C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08170D6E
	.align 2, 0
_08170D68: .4byte 0x0000046D
_08170D6C:
	movs r0, #0
_08170D6E:
	cmp r0, #0
	beq _08170E56
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170DB4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08170DC0
	ldr r1, _08170DB8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08170DBC @ =0x0000046E
	adds r7, r5, r0
	b _08170E42
	.align 2, 0
_08170DB4: .4byte 0x0000025D
_08170DB8: .4byte 0x000004B7
_08170DBC: .4byte 0x0000046E
_08170DC0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08170E30 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08170E34 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08170DFA
	ldrb r0, [r7]
	cmp r0, #0
	bne _08170DFA
	cmp r4, #1
	bne _08170DEC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170E46
_08170DEC:
	cmp r4, #0
	bne _08170DFA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170E46
_08170DFA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08170E0C
	movs r3, #6
_08170E0C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08170E38
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08170E40
	.align 2, 0
_08170E30: .4byte 0x000004B7
_08170E34: .4byte 0x0000046E
_08170E38:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170E40:
	str r0, [r6, #8]
_08170E42:
	movs r0, #0
	strb r0, [r7]
_08170E46:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	b _08170F6E
_08170E56:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170E98 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08170EA4
	ldr r1, _08170E9C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08170EA0 @ =0x0000046E
	adds r7, r5, r0
	b _08170F26
	.align 2, 0
_08170E98: .4byte 0x0000025D
_08170E9C: .4byte 0x000004B7
_08170EA0: .4byte 0x0000046E
_08170EA4:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08170F14 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08170F18 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08170EDE
	ldrb r0, [r7]
	cmp r0, #0
	bne _08170EDE
	cmp r4, #1
	bne _08170ED0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170F2A
_08170ED0:
	cmp r4, #0
	bne _08170EDE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170F2A
_08170EDE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08170EF0
	movs r3, #6
_08170EF0:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08170F1C
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08170F24
	.align 2, 0
_08170F14: .4byte 0x000004B7
_08170F18: .4byte 0x0000046E
_08170F1C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170F24:
	str r0, [r6, #8]
_08170F26:
	movs r0, #0
	strb r0, [r7]
_08170F2A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _08170F6E
	ldr r4, _08170F7C @ =FUN_08170f88
	movs r3, #0x28
	ldr r0, _08170F80 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08170F84 @ =0x0000046B
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
_08170F6E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08170F7C: .4byte FUN_08170f88
_08170F80: .4byte 0x0000046D
_08170F84: .4byte 0x0000046B

	thumb_func_start FUN_08170f88
FUN_08170f88: @ 0x08170F88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08170FA4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08170FA8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08170FAA
	.align 2, 0
_08170FA4: .4byte 0x0000046D
_08170FA8:
	movs r0, #0
_08170FAA:
	cmp r0, #0
	beq _08171096
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	ldr r1, _08170FF0 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170FF4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08171000
	ldr r1, _08170FF8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08170FFC @ =0x0000046E
	adds r7, r5, r0
	b _08171082
	.align 2, 0
_08170FF0: .4byte 0x00000504
_08170FF4: .4byte 0x0000025D
_08170FF8: .4byte 0x000004B7
_08170FFC: .4byte 0x0000046E
_08171000:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08171070 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08171074 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817103A
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817103A
	cmp r4, #1
	bne _0817102C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08171086
_0817102C:
	cmp r4, #0
	bne _0817103A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08171086
_0817103A:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817104C
	movs r3, #6
_0817104C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08171078
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08171080
	.align 2, 0
_08171070: .4byte 0x000004B7
_08171074: .4byte 0x0000046E
_08171078:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171080:
	str r0, [r6, #8]
_08171082:
	movs r0, #0
	strb r0, [r7]
_08171086:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	b _0817117C
_08171096:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	ldr r1, _081710D8 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081710DC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081710E8
	ldr r1, _081710E0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081710E4 @ =0x0000046E
	adds r7, r5, r0
	b _0817116A
	.align 2, 0
_081710D8: .4byte 0x00000504
_081710DC: .4byte 0x0000025D
_081710E0: .4byte 0x000004B7
_081710E4: .4byte 0x0000046E
_081710E8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08171158 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817115C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08171122
	ldrb r0, [r7]
	cmp r0, #0
	bne _08171122
	cmp r4, #1
	bne _08171114
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817116E
_08171114:
	cmp r4, #0
	bne _08171122
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817116E
_08171122:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08171134
	movs r3, #6
_08171134:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08171160
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08171168
	.align 2, 0
_08171158: .4byte 0x000004B7
_0817115C: .4byte 0x0000046E
_08171160:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171168:
	str r0, [r6, #8]
_0817116A:
	movs r0, #0
	strb r0, [r7]
_0817116E:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
_0817117C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08171188
FUN_08171188: @ 0x08171188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081711E4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081711A0
	movs r0, #0
	strb r0, [r1]
_081711A0:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081711E8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081711F4
	ldr r1, _081711EC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081711F0 @ =0x0000046E
	adds r7, r5, r0
	b _08171276
	.align 2, 0
_081711E4: .4byte 0x0000046D
_081711E8: .4byte 0x0000025D
_081711EC: .4byte 0x000004B7
_081711F0: .4byte 0x0000046E
_081711F4:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08171264 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08171268 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817122E
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817122E
	cmp r4, #1
	bne _08171220
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817127A
_08171220:
	cmp r4, #0
	bne _0817122E
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817127A
_0817122E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08171240
	movs r3, #6
_08171240:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0817126C
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08171274
	.align 2, 0
_08171264: .4byte 0x000004B7
_08171268: .4byte 0x0000046E
_0817126C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171274:
	str r0, [r6, #8]
_08171276:
	movs r0, #0
	strb r0, [r7]
_0817127A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_081770d0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08171294
FUN_08171294: @ 0x08171294
	bx lr
	.align 2, 0

	thumb_func_start FUN_08171298
FUN_08171298: @ 0x08171298
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081712B0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081712B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081712B6
	.align 2, 0
_081712B0: .4byte 0x0000046D
_081712B4:
	movs r0, #0
_081712B6:
	cmp r0, #0
	beq _081712D8
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
	bne _081712D8
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081712D8:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081712F4
	ldr r2, _08171340 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081712F4:
	ldr r1, _08171344 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0817133A
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0817133A
	ldr r3, _08171348 @ =FUN_08171354
	movs r2, #6
	ldr r0, _0817134C @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171350 @ =0x0000046B
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
_0817133A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08171340: .4byte 0x000001DF
_08171344: .4byte 0x00000466
_08171348: .4byte FUN_08171354
_0817134C: .4byte 0x0000046D
_08171350: .4byte 0x0000046B

	thumb_func_start FUN_08171354
FUN_08171354: @ 0x08171354
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0817136C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171370
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171372
	.align 2, 0
_0817136C: .4byte 0x0000046D
_08171370:
	movs r0, #0
_08171372:
	cmp r0, #0
	beq _0817138E
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
_0817138E:
	cmp r5, #0x28
	bne _081713A0
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081713A0:
	ldr r1, _081713BC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081713B6
	cmp r5, #0x78
	ble _081713B6
	ldr r0, _081713C0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081713B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081713BC: .4byte 0x0000046E
_081713C0: .4byte 0x0000046B

	thumb_func_start FUN_081713c4
FUN_081713c4: @ 0x081713C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081713DC @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081713E0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081713E2
	.align 2, 0
_081713DC: .4byte 0x0000046D
_081713E0:
	movs r0, #0
_081713E2:
	adds r5, r0, #0
	cmp r5, #0
	beq _0817141A
	movs r2, #1
	ldr r1, _08171400 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08171404
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0817140E
	.align 2, 0
_08171400: .4byte 0x0000025D
_08171404:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_0817140E:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _08171462
_0817141A:
	cmp r1, #0x1a
	ble _0817145C
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	ldr r3, _08171450 @ =FUN_0817146c
	movs r2, #0xd
	ldr r0, _08171454 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171458 @ =0x0000046B
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
	b _08171462
	.align 2, 0
_08171450: .4byte FUN_0817146c
_08171454: .4byte 0x0000046D
_08171458: .4byte 0x0000046B
_0817145C:
	ldr r1, _08171468 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08171462:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08171468: .4byte 0x0000046E

	thumb_func_start FUN_0817146c
FUN_0817146c: @ 0x0817146C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08171484 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171488
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817148A
	.align 2, 0
_08171484: .4byte 0x0000046D
_08171488:
	movs r0, #0
_0817148A:
	cmp r0, #0
	beq _081714D6
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _081714B0 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081714B4
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081714C2
	.align 2, 0
_081714B0: .4byte 0x0000025D
_081714B4:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081714C2:
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
_081714D6:
	ldr r0, [r6, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne _081714EE
	ldrh r0, [r1, #0xe]
	cmp r0, #4
	bne _081714EE
	movs r0, #0xee
	bl PlaySound_082406e0
_081714EE:
	ldr r1, _0817168C @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081714FA
	b _08171686
_081714FA:
	adds r0, r6, #0
	bl FUN_08178078
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _08171690 @ =0x0000055C
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
	ldr r1, _08171694 @ =0x00000564
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
	ldr r1, _08171698 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0817169C @ =0x00000567
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
	ldr r1, _081716A0 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081716A4 @ =0x00000572
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
	ldr r2, _081716A8 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081716AC @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081716B0 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081716B4 @ =0x00000544
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
	ldr r2, _081716B8 @ =0x00000482
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
	ldr r1, _081716BC @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _081716C0 @ =0x08252168
	adds r0, r6, #0
	ldr r2, _081716C4 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081716C8 @ =0x00000541
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
_08171686:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817168C: .4byte 0x0000046E
_08171690: .4byte 0x0000055C
_08171694: .4byte 0x00000564
_08171698: .4byte 0x00000566
_0817169C: .4byte 0x00000567
_081716A0: .4byte 0x0000056C
_081716A4: .4byte 0x00000572
_081716A8: .4byte 0x0000046B
_081716AC: .4byte 0x0000046C
_081716B0: .4byte 0x0000024E
_081716B4: .4byte 0x00000544
_081716B8: .4byte 0x00000482
_081716BC: .4byte 0x00000464
_081716C0: .4byte 0x08252168
_081716C4: .4byte 0x00000982
_081716C8: .4byte 0x00000541

	thumb_func_start FUN_081716cc
FUN_081716cc: @ 0x081716CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081716E4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081716E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081716EA
	.align 2, 0
_081716E4: .4byte 0x0000046D
_081716E8:
	movs r0, #0
_081716EA:
	cmp r0, #0
	beq _081716F6
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
_081716F6:
	ldr r1, _08171710 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08171708
	ldr r0, _08171714 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08171708:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08171710: .4byte 0x0000046E
_08171714: .4byte 0x0000046B

	thumb_func_start FUN_08171718
FUN_08171718: @ 0x08171718
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08171740 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171744
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171746
	.align 2, 0
_08171740: .4byte 0x0000046D
_08171744:
	movs r0, #0
_08171746:
	cmp r0, #0
	beq _0817177C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_08175868
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_0817734c
	movs r0, #2
	ldr r7, _081717D4 @ =0x00001008
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817177C:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	str r6, [sp]
	mov r0, sp
	ldr r2, _081717D8 @ =0x05000002
	bl CpuSet
	ldr r1, _081717DC @ =0x00001022
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0817179C
	adds r2, #0x64
_0817179C:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r2
	blt _081717F0
	ldr r3, _081717E0 @ =FUN_081719b4
	movs r2, #0x26
	ldr r0, _081717E4 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081717E8 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	ldr r7, _081717EC @ =0x00000553
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
	b _081719A0
	.align 2, 0
_081717D4: .4byte 0x00001008
_081717D8: .4byte 0x05000002
_081717DC: .4byte 0x00001022
_081717E0: .4byte FUN_081719b4
_081717E4: .4byte 0x0000046D
_081717E8: .4byte 0x0000046B
_081717EC: .4byte 0x00000553
_081717F0:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _08171804
	movs r6, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _0817180A
_08171804:
	movs r6, #2
	ldrh r0, [r1]
	adds r0, #0x28
_0817180A:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08171830 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	cmp r0, #0
	blt _08171834
	asrs r1, r0, #0xc
	b _0817183A
	.align 2, 0
_08171830: .4byte 0x085B0A08
_08171834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817183A:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08171852
	asrs r2, r0, #0xc
	b _08171858
_08171852:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171858:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldr r3, _081718A4 @ =0x00002EE0
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0xc
	bl FUN_08177d34
	movs r2, #0
	mov sb, r2
	mov ip, r2
	ldr r3, _081718A8 @ =0x00001012
	adds r0, r5, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp ip, r0
	blt _0817187E
	b _081719A0
_0817187E:
	ldr r3, _081718AC @ =0x085B0A08
	movs r6, #0
	ldr r0, _081718B0 @ =0x00000674
	adds r2, r5, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov r8, r1
_0817188C:
	adds r0, r6, r5
	movs r7, #2
	mov sl, r7
	ldr r1, _081718B4 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _081718B8
	movs r0, #1
	b _081718BA
	.align 2, 0
_081718A4: .4byte 0x00002EE0
_081718A8: .4byte 0x00001012
_081718AC: .4byte 0x085B0A08
_081718B0: .4byte 0x00000674
_081718B4: .4byte 0x00000755
_081718B8:
	movs r0, #0
_081718BA:
	cmp r0, #0
	beq _0817198A
	adds r0, r6, r5
	movs r1, #5
	ldr r7, _081718D4 @ =0x00000755
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081718D8
	movs r0, #1
	b _081718DA
	.align 2, 0
_081718D4: .4byte 0x00000755
_081718D8:
	movs r0, #0
_081718DA:
	cmp r0, #0
	bne _0817198A
	mov r0, sb
	cmp r0, #0
	beq _081718F0
	cmp r0, #1
	beq _08171938
	ldrh r0, [r4, #8]
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	b _08171984
_081718F0:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov sl, r1
	movs r0, #0x36
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08171912
	asrs r1, r0, #0xc
	b _08171918
_08171912:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171918:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r7, [r0, r1]
	mov sl, r7
	movs r0, #0x36
	mov r7, sl
	muls r7, r0, r7
	adds r0, r7, #0
	cmp r0, #0
	bge _08171976
	b _0817197A
_08171938:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08171956
	asrs r1, r0, #0xc
	b _0817195C
_08171956:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817195C:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0817197A
_08171976:
	asrs r1, r0, #0xc
	b _08171980
_0817197A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171980:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
_08171984:
	strh r0, [r2, #4]
	movs r0, #1
	add sb, r0
_0817198A:
	add r6, r8
	add r2, r8
	movs r1, #1
	add ip, r1
	ldr r7, _081719B0 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _081719A0
	b _0817188C
_081719A0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081719B0: .4byte 0x00001012

	thumb_func_start FUN_081719b4
FUN_081719b4: @ 0x081719B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081719b8
FUN_081719b8: @ 0x081719B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r3, [r0]
	ldr r1, _08171A20 @ =0x0000046D
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081719DC
	movs r0, #0
	strb r0, [r1]
_081719DC:
	movs r6, #0
	ldr r1, _08171A24 @ =0x00001012
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r4, sp, #8
	mov sl, r4
	ldr r1, _08171A28 @ =0x0000025D
	add r1, r8
	str r1, [sp, #0x10]
	ldr r2, _08171A2C @ =0x000004B7
	add r2, r8
	mov sb, r2
	ldr r4, _08171A30 @ =0x0000046E
	add r4, r8
	str r4, [sp, #0xc]
	cmp r6, r0
	bge _08171AB6
_08171A00:
	lsls r2, r6, #3
	adds r0, r2, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #2
	ldr r4, _08171A34 @ =0x00000755
	adds r0, r0, r4
	ldrb r0, [r0]
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _08171A38
	movs r0, #1
	b _08171A3A
	.align 2, 0
_08171A20: .4byte 0x0000046D
_08171A24: .4byte 0x00001012
_08171A28: .4byte 0x0000025D
_08171A2C: .4byte 0x000004B7
_08171A30: .4byte 0x0000046E
_08171A34: .4byte 0x00000755
_08171A38:
	movs r0, #0
_08171A3A:
	adds r5, r6, #1
	cmp r0, #0
	beq _08171AA8
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #5
	ldr r2, _08171A5C @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08171A60
	movs r0, #1
	b _08171A62
	.align 2, 0
_08171A5C: .4byte 0x00000755
_08171A60:
	movs r0, #0
_08171A62:
	adds r7, r0, #0
	adds r5, r6, #1
	cmp r7, #0
	bne _08171AA8
	mov r1, r8
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	adds r4, r4, r6
	lsls r4, r4, #3
	adds r4, r4, r6
	lsls r4, r4, #2
	ldr r3, [sp, #0x14]
	adds r4, r3, r4
	ldr r2, _08171B04 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _08171B08 @ =0x0000076E
	adds r0, r4, r1
	strh r7, [r0]
	mov r2, r8
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r4, r4, r2
	strh r0, [r4]
	ldr r3, [sp, #0x14]
_08171AA8:
	adds r6, r5, #0
	ldr r4, _08171B0C @ =0x00001012
	adds r0, r3, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _08171A00
_08171AB6:
	movs r3, #0x80
	lsls r3, r3, #0xb
	mov r0, r8
	movs r1, #0x18
	movs r2, #0xc
	bl FUN_08177d34
	mov r2, r8
	ldrb r0, [r2, #5]
	add r1, sp, #4
	mov r2, sl
	bl FUN_08175868
	movs r0, #0x9f
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08171B10
	mov r0, sb
	strb r2, [r0]
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _08171B84
	.align 2, 0
_08171B04: .4byte 0x0000076C
_08171B08: .4byte 0x0000076E
_08171B0C: .4byte 0x00001012
_08171B10:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, r2
	bne _08171B46
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08171B46
	cmp r4, #1
	bne _08171B38
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08171B8A
_08171B38:
	cmp r4, #0
	bne _08171B46
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08171B8A
_08171B46:
	mov r0, sb
	strb r2, [r0]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _08171B58
	movs r3, #6
_08171B58:
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08171B7A
	ldr r0, [r5, #8]
	orrs r0, r6
	b _08171B82
_08171B7A:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171B82:
	str r0, [r5, #8]
_08171B84:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
_08171B8A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08171ba8
FUN_08171ba8: @ 0x08171BA8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08171BC0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171BC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171BC6
	.align 2, 0
_08171BC0: .4byte 0x0000046D
_08171BC4:
	movs r0, #0
_08171BC6:
	cmp r0, #0
	beq _08171BDA
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08171BDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _08171C24 @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _08171C34
	ldr r3, _08171C28 @ =FUN_08171cc8
	movs r2, #0x22
	ldr r0, _08171C2C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171C30 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _08171CC0
	.align 2, 0
_08171C24: .4byte 0x05000002
_08171C28: .4byte FUN_08171cc8
_08171C2C: .4byte 0x0000046D
_08171C30: .4byte 0x0000046B
_08171C34:
	ldr r3, _08171C48 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _08171C4C
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _08171C52
	.align 2, 0
_08171C48: .4byte 0x00000484
_08171C4C:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_08171C52:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08171C78 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08171C7C
	asrs r1, r0, #0xc
	b _08171C82
	.align 2, 0
_08171C78: .4byte 0x085B0A08
_08171C7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171C82:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08171C9A
	asrs r2, r0, #0xc
	b _08171CA0
_08171C9A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171CA0:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_08177a4c
_08171CC0:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08171cc8
FUN_08171cc8: @ 0x08171CC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08171CF4 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171CF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171CFA
	.align 2, 0
_08171CF4: .4byte 0x0000046D
_08171CF8:
	movs r0, #0
_08171CFA:
	cmp r0, #0
	beq _08171D06
	ldr r1, _08171D1C @ =0x00000FAD
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_08171D06:
	ldr r0, _08171D1C @ =0x00000FAD
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08171D20
	ldrb r3, [r6, #5]
	b _08171D2A
	.align 2, 0
_08171D1C: .4byte 0x00000FAD
_08171D20:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_08171D2A:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _08171D4C @ =0x085B0A08
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
	blt _08171D50
	asrs r1, r0, #0xc
	b _08171D56
	.align 2, 0
_08171D4C: .4byte 0x085B0A08
_08171D50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171D56:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08171D6E
	asrs r2, r0, #0xc
	b _08171D74
_08171D6E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171D74:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _08171D8C @ =0x00000FAD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08171F2A
	.align 2, 0
_08171D8C: .4byte 0x00000FAD
_08171D90:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	ldr r3, _08171DB0 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08171DB4
	movs r0, #1
	b _08171DB6
	.align 2, 0
_08171DB0: .4byte 0x00000755
_08171DB4:
	movs r0, #0
_08171DB6:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08171DC0
	b _08171F28
_08171DC0:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #5
	ldr r3, _08171DE0 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08171DE4
	movs r0, #1
	b _08171DE6
	.align 2, 0
_08171DE0: .4byte 0x00000755
_08171DE4:
	movs r0, #0
_08171DE6:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _08171DF2
	b _08171F28
_08171DF2:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #3
	adds r1, r1, r7
	lsls r1, r1, #2
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _08171E44 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _08171E48 @ =0x0000076E
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _08171E4C
	cmp r3, #1
	beq _08171EA4
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08171F20
	.align 2, 0
_08171E44: .4byte 0x0000076C
_08171E48: .4byte 0x0000076E
_08171E4C:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08171E6C @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _08171E6C @ =0x085B0A08
	cmp r0, #0
	blt _08171E70
	asrs r3, r0, #0xc
	b _08171E76
	.align 2, 0
_08171E6C: .4byte 0x085B0A08
_08171E70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08171E76:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08171EA0 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _08171EFC
	b _08171F04
	.align 2, 0
_08171EA0: .4byte 0x00000674
_08171EA4:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08171EC8 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08171ECC
	asrs r3, r0, #0xc
	b _08171ED2
	.align 2, 0
_08171EC8: .4byte 0x085B0A08
_08171ECC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08171ED2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08171F00 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08171F04
_08171EFC:
	asrs r2, r0, #0xc
	b _08171F0A
	.align 2, 0
_08171F00: .4byte 0x00000674
_08171F04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171F0A:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_08171F20:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08171F28:
	mov r7, sl
_08171F2A:
	ldr r0, _08171F84 @ =0x00001012
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _08171F38
	b _08171D90
_08171F38:
	ldr r3, _08171F88 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl FUN_08177d34
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _08171F74
	ldr r4, _08171F8C @ =FUN_08171f98
	movs r3, #0x23
	ldr r0, _08171F90 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171F94 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_08171F74:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08171F84: .4byte 0x00001012
_08171F88: .4byte 0x0000FFFF
_08171F8C: .4byte FUN_08171f98
_08171F90: .4byte 0x0000046D
_08171F94: .4byte 0x0000046B

	thumb_func_start FUN_08171f98
FUN_08171f98: @ 0x08171F98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _08171FC0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171FC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171FC6
	.align 2, 0
_08171FC0: .4byte 0x0000046D
_08171FC4:
	movs r0, #0
_08171FC6:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _08172018
	adds r0, r6, #0
	bl FUN_0817b848
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0817205C @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08172060 @ =0x00001008
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08172018:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08172064 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172070
	ldr r1, _08172068 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0817206C @ =0x0000046E
	adds r7, r6, r2
	b _081720F2
	.align 2, 0
_0817205C: .4byte 0xFFEFFFFF
_08172060: .4byte 0x00001008
_08172064: .4byte 0x0000025D
_08172068: .4byte 0x000004B7
_0817206C: .4byte 0x0000046E
_08172070:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _081720E0 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081720E4 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _081720AA
	ldrb r0, [r7]
	cmp r0, #0
	bne _081720AA
	cmp r4, #1
	bne _0817209C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081720F6
_0817209C:
	cmp r4, #0
	bne _081720AA
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081720F6
_081720AA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081720BC
	movs r3, #6
_081720BC:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081720E8
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _081720F0
	.align 2, 0
_081720E0: .4byte 0x000004B7
_081720E4: .4byte 0x0000046E
_081720E8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081720F0:
	str r0, [r5, #8]
_081720F2:
	movs r0, #0
	strb r0, [r7]
_081720F6:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_08177a4c
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08172168
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08172158 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _0817215C @ =FUN_08172188
	movs r2, #0x24
	ldr r0, _08172160 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08172164 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _08172178
	.align 2, 0
_08172158: .4byte 0xFFFFFEFF
_0817215C: .4byte FUN_08172188
_08172160: .4byte 0x0000046D
_08172164: .4byte 0x0000046B
_08172168:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08172178:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08172188
FUN_08172188: @ 0x08172188
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _081721F0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081721A6
	movs r0, #0
	strb r0, [r1]
_081721A6:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _081721F4 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08172200
	ldr r0, _081721F8 @ =0x000004B7
	adds r5, r6, r0
	strb r2, [r5]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r7, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	mov r8, r5
	ldr r1, _081721FC @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _08172282
	.align 2, 0
_081721F0: .4byte 0x0000046D
_081721F4: .4byte 0x0000025D
_081721F8: .4byte 0x000004B7
_081721FC: .4byte 0x0000046E
_08172200:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _08172270 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _08172274 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _0817223C
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817223C
	cmp r7, #1
	bne _0817222E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08172288
_0817222E:
	cmp r7, #0
	bne _0817223C
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08172288
_0817223C:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _0817224E
	movs r3, #6
_0817224E:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _08172278
	ldr r0, [r4, #8]
	orrs r0, r5
	b _08172280
	.align 2, 0
_08172270: .4byte 0x000004B7
_08172274: .4byte 0x0000046E
_08172278:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08172280:
	str r0, [r4, #8]
_08172282:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08172288:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_081770d0
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _08172370
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_08175868
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _081722E4
	mov r0, r8
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _08172354
_081722E4:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _08172318
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _08172318
	cmp r4, #1
	bne _0817230A
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817235A
_0817230A:
	cmp r4, #0
	bne _08172318
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817235A
_08172318:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _0817232A
	movs r3, #6
_0817232A:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0817234A
	ldr r0, [r5, #8]
	orrs r0, r7
	b _08172352
_0817234A:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08172352:
	str r0, [r5, #8]
_08172354:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_0817235A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	ldr r0, _08172380 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_08172370:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172380: .4byte 0x0000046B

	thumb_func_start FUN_08172384
FUN_08172384: @ 0x08172384
	push {lr}
	ldr r2, _08172398 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08172394
	movs r0, #0
	strb r0, [r1]
_08172394:
	pop {r0}
	bx r0
	.align 2, 0
_08172398: .4byte 0x0000046D

	thumb_func_start FUN_0817239c
FUN_0817239c: @ 0x0817239C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081723C4 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081723C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081723CA
	.align 2, 0
_081723C4: .4byte 0x0000046D
_081723C8:
	movs r0, #0
_081723CA:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r6
	mov sl, r4
	movs r7, #0x83
	lsls r7, r7, #2
	adds r7, r6, r7
	str r7, [sp]
	movs r1, #0x85
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	beq _08172448
	movs r0, #0x20
	subs r1, #0x94
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r4, _08172474 @ =0x00001023
	adds r1, r5, r4
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	ldr r1, _08172478 @ =0x00001022
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _08172448
	adds r5, r5, r1
_0817243A:
	adds r0, r6, #0
	bl FUN_08178470
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0817243A
_08172448:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, sl
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [sp]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, r1, r0
	cmp r0, #0
	blt _0817247C
	asrs r0, r0, #2
	b _08172482
	.align 2, 0
_08172474: .4byte 0x00001023
_08172478: .4byte 0x00001022
_0817247C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08172482:
	adds r2, r0, #0
	ldr r4, [sp, #4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r1, r0
	cmp r0, #0
	blt _0817249A
	asrs r0, r0, #2
	b _081724A0
_0817249A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081724A0:
	adds r1, r0, #0
	cmp r2, #0xc8
	ble _081724AA
	movs r2, #0xc8
	b _081724B4
_081724AA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081724B4
	adds r2, r0, #0
_081724B4:
	cmp r1, #0xc8
	ble _081724BC
	movs r1, #0xc8
	b _081724C6
_081724BC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081724C6
	adds r1, r0, #0
_081724C6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r2
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	ldrh r0, [r7]
	adds r0, r0, r2
	strh r0, [r7]
	mov r7, r8
	ldrh r0, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	cmp r2, #0
	bne _081724EC
	cmp r1, #0
	bne _081724EC
	movs r0, #1
	b _081724EE
_081724EC:
	movs r0, #0
_081724EE:
	cmp r0, #0
	beq _08172564
	ldr r1, _08172574 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r4, _08172578 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _0817257C @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r1, [r0]
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
	strh r5, [r0]
	movs r2, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08172580 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08172584 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08172588 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r3, [r0]
_08172564:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172574: .4byte 0x0000046B
_08172578: .4byte FUN_080e48d0
_0817257C: .4byte 0x0000046D
_08172580: .4byte 0x00000469
_08172584: .4byte 0x00000484
_08172588: .4byte 0x0000046C

	thumb_func_start FUN_0817258c
FUN_0817258c: @ 0x0817258C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081725A8 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081725AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081725AE
	.align 2, 0
_081725A8: .4byte 0x0000046D
_081725AC:
	movs r0, #0
_081725AE:
	cmp r0, #0
	beq _08172614
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081726E8 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081726EC @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _081726F0 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081726F4 @ =0x000001A3
	bl PlaySound_082406e0
_08172614:
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0817262A
	adds r0, r6, #0
	adds r0, #8
	movs r1, #0xa
	bl FUN_08176530
_0817262A:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817263E
	b _08172828
_0817263E:
	adds r0, r6, #0
	adds r0, #8
	movs r1, #0x10
	bl FUN_08176530
	adds r0, r6, #0
	bl FUN_08178504
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08172666
	adds r0, r6, #0
	bl FUN_080e6658
_08172666:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081726C6
	movs r4, #8
	ldrsh r0, [r6, r4]
	str r0, [sp]
	movs r7, #0xa
	ldrsh r0, [r6, r7]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	str r0, [sp, #8]
	adds r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _081726F8 @ =0xFFFF0000
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
_081726C6:
	ldr r4, _081726FC @ =0x000001DF
	adds r0, r6, r4
	ldrb r0, [r0]
	movs r7, #0x90
	lsls r7, r7, #3
	adds r1, r6, r7
	ldrh r1, [r1]
	bl FUN_0820ccd0
	cmp r0, #0x1f
	bgt _08172704
	ldr r3, _08172700 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r2, r2, r1
	b _08172710
	.align 2, 0
_081726E8: .4byte 0xFFFEBE3F
_081726EC: .4byte 0x0000021E
_081726F0: .4byte 0x00000202
_081726F4: .4byte 0x000001A3
_081726F8: .4byte 0xFFFF0000
_081726FC: .4byte 0x000001DF
_08172700: .4byte 0x030046A0
_08172704:
	ldr r3, _08172730 @ =0x030046A0
	ldr r2, [r3]
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r2, r4
	subs r0, #0x20
_08172710:
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ldr r7, _08172734 @ =0x00000948
	adds r2, r0, r7
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08172738 @ =0x0000270E
	cmp r1, r0
	bgt _0817273C
	adds r0, r4, #1
	b _08172740
	.align 2, 0
_08172730: .4byte 0x030046A0
_08172734: .4byte 0x00000948
_08172738: .4byte 0x0000270E
_0817273C:
	ldr r1, _0817275C @ =0x0000270F
	adds r0, r1, #0
_08172740:
	strh r0, [r2]
	ldr r0, [r3]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, _08172760 @ =0x0000270E
	cmp r1, r0
	bgt _08172764
	adds r0, r2, #1
	b _08172768
	.align 2, 0
_0817275C: .4byte 0x0000270F
_08172760: .4byte 0x0000270E
_08172764:
	ldr r7, _081727A0 @ =0x0000270F
	adds r0, r7, #0
_08172768:
	strh r0, [r3]
	adds r0, r6, #0
	bl FUN_080e9178
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0807a798
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r3, _081727A4 @ =0x00000189
	adds r1, r6, r3
	ldrb r1, [r1]
	bl FUN_0807a840
	ldr r0, _081727A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081727AC
	movs r0, #1
	b _081727AE
	.align 2, 0
_081727A0: .4byte 0x0000270F
_081727A4: .4byte 0x00000189
_081727A8: .4byte 0x030047A4
_081727AC:
	movs r0, #0
_081727AE:
	cmp r0, #0
	bne _081727CE
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081727CE
	ldr r0, _08172830 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl FUN_080ec5b4
_081727CE:
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08172834 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r1, _08172838 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0817283C @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08172840 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08172844 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r1, [r0]
_08172828:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172830: .4byte 0x03002B28
_08172834: .4byte FUN_080e48d0
_08172838: .4byte 0x0000046D
_0817283C: .4byte 0x0000046B
_08172840: .4byte 0x00000469
_08172844: .4byte 0x00000484

	thumb_func_start FUN_08172848
FUN_08172848: @ 0x08172848
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08172868 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817286C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817286E
	.align 2, 0
_08172868: .4byte 0x0000046C
_0817286C:
	movs r0, #0
_0817286E:
	cmp r0, #0
	beq _081728B4
	ldr r3, _081728E0 @ =0x0000100C
	adds r0, r6, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r7, _081728E4 @ =0x00001010
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r7, _081728E8 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081728EC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
_081728B4:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081728F0 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081728F8
	ldr r0, _081728F4 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08172908
	.align 2, 0
_081728E0: .4byte 0x0000100C
_081728E4: .4byte 0x00001010
_081728E8: .4byte 0x0000046D
_081728EC: .4byte 0x00000553
_081728F0: .4byte 0x0000A02F
_081728F4: .4byte 0x00000482
_081728F8:
	ldr r1, _0817292C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08172908
	movs r0, #1
	strh r0, [r2]
_08172908:
	ldr r3, _08172930 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172934
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
	b _0817294C
	.align 2, 0
_0817292C: .4byte 0x00000482
_08172930: .4byte 0x0000025D
_08172934:
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
_0817294C:
	ldr r1, _08172984 @ =0x000004A4
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
	bge _0817296E
	rsbs r2, r2, #0
_0817296E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08172988
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0817297C
	rsbs r2, r2, #0
_0817297C:
	cmp r2, #0x20
	bgt _08172988
	movs r0, #1
	b _081729F2
	.align 2, 0
_08172984: .4byte 0x000004A4
_08172988:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08172994
	cmp r1, #0
	beq _081729F0
_08172994:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _081729B8 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081729BC
	asrs r1, r0, #0xc
	b _081729C2
	.align 2, 0
_081729B8: .4byte 0x085B0A08
_081729BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081729C2:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081729E0 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _081729E4
	asrs r1, r0, #0xc
	b _081729EA
	.align 2, 0
_081729E0: .4byte 0x085B0A08
_081729E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081729EA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_081729F0:
	movs r0, #0
_081729F2:
	cmp r0, #0
	beq _08172A9C
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08172A4C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08172A54
	ldr r3, _08172A50 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08172A62
	.align 2, 0
_08172A4C: .4byte 0x000004A4
_08172A50: .4byte 0xFFFFFF00
_08172A54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08172A62
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08172A62:
	cmp r1, #0
	bge _08172A68
	rsbs r1, r1, #0
_08172A68:
	cmp r1, #0x20
	ble _08172A9C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08172A94 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _08172A98 @ =0x0000046A
	adds r0, r5, r7
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	b _08172B3E
	.align 2, 0
_08172A94: .4byte 0x00000469
_08172A98: .4byte 0x0000046A
_08172A9C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08178640
	ldr r0, _08172AC4 @ =0x0000101C
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08172AC8
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0xc
	bl FUN_08177d34
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08172AD6
	.align 2, 0
_08172AC4: .4byte 0x0000101C
_08172AC8:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
_08172AD6:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	movs r2, #0xfb
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0x3c
	bls _08172B30
	movs r2, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08172B20 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r1, [r0]
	ldr r0, _08172B24 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08172B28 @ =0x00000FA6
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08172B2C @ =0x00000F96
	adds r0, r6, r2
	strb r1, [r0]
	b _08172B3E
	.align 2, 0
_08172B20: .4byte 0x00000469
_08172B24: .4byte 0x0000046C
_08172B28: .4byte 0x00000FA6
_08172B2C: .4byte 0x00000F96
_08172B30:
	adds r0, #1
	strh r0, [r1]
	ldr r3, _08172B48 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08172B3E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172B48: .4byte 0x00000484

	thumb_func_start FUN_08172b4c
FUN_08172b4c: @ 0x08172B4C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08172B6C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08172B70
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08172B72
	.align 2, 0
_08172B6C: .4byte 0x0000046C
_08172B70:
	movs r0, #0
_08172B72:
	cmp r0, #0
	beq _08172BD0
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08172C0C @ =0x0000046D
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
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08172C10 @ =0x00001021
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_08175898
_08172BD0:
	ldr r4, _08172C14 @ =0x00000544
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _08172BDE
	movs r0, #1
	strh r0, [r1]
_08172BDE:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08172C18 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08172C20
	ldr r3, _08172C1C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08172C30
	.align 2, 0
_08172C0C: .4byte 0x0000046D
_08172C10: .4byte 0x00001021
_08172C14: .4byte 0x00000544
_08172C18: .4byte 0x0000A02F
_08172C1C: .4byte 0x00000482
_08172C20:
	ldr r4, _08172C54 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08172C30
	movs r0, #1
	strh r0, [r2]
_08172C30:
	ldr r1, _08172C58 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172C5C
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
	b _08172C74
	.align 2, 0
_08172C54: .4byte 0x00000482
_08172C58: .4byte 0x0000025D
_08172C5C:
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
_08172C74:
	ldr r2, _08172CAC @ =0x000004A4
	adds r0, r5, r2
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
	bge _08172C96
	rsbs r2, r2, #0
_08172C96:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08172CB0
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08172CA4
	rsbs r2, r2, #0
_08172CA4:
	cmp r2, #0x20
	bgt _08172CB0
	movs r0, #1
	b _08172D1A
	.align 2, 0
_08172CAC: .4byte 0x000004A4
_08172CB0:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08172CBC
	cmp r1, #0
	beq _08172D18
_08172CBC:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08172CE0 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172CE4
	asrs r1, r0, #0xc
	b _08172CEA
	.align 2, 0
_08172CE0: .4byte 0x085B0A08
_08172CE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172CEA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08172D08 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172D0C
	asrs r1, r0, #0xc
	b _08172D12
	.align 2, 0
_08172D08: .4byte 0x085B0A08
_08172D0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172D12:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08172D18:
	movs r0, #0
_08172D1A:
	cmp r0, #0
	beq _08172D64
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08172D8C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_08172D64:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08178640
	ldr r3, _08172D90 @ =0x0000101C
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _08172D94
	subs r3, #0x1c
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0xc
	bl FUN_08177d34
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08172DA2
	.align 2, 0
_08172D8C: .4byte 0x000004A4
_08172D90: .4byte 0x0000101C
_08172D94:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
_08172DA2:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	ldr r4, _08172DE0 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	cmp r0, #0x50
	ble _08172DE8
	movs r2, #8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08172DE4 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x1a
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08172DE0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08172DEC
	.align 2, 0
_08172DE0: .4byte 0x00000484
_08172DE4: .4byte 0x00000469
_08172DE8:
	adds r0, #1
	str r0, [r1]
_08172DEC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08172df4
FUN_08172df4: @ 0x08172DF4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08172E14 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08172E18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08172E1A
	.align 2, 0
_08172E14: .4byte 0x0000046C
_08172E18:
	movs r0, #0
_08172E1A:
	cmp r0, #0
	beq _08172E78
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08172EB4 @ =0x0000046D
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
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08172EB8 @ =0x00001021
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_08175898
_08172E78:
	ldr r4, _08172EBC @ =0x00000544
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _08172E86
	movs r0, #1
	strh r0, [r1]
_08172E86:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08172EC0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08172EC8
	ldr r3, _08172EC4 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08172ED8
	.align 2, 0
_08172EB4: .4byte 0x0000046D
_08172EB8: .4byte 0x00001021
_08172EBC: .4byte 0x00000544
_08172EC0: .4byte 0x0000A02F
_08172EC4: .4byte 0x00000482
_08172EC8:
	ldr r4, _08172EFC @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08172ED8
	movs r0, #1
	strh r0, [r2]
_08172ED8:
	ldr r1, _08172F00 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172F04
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
	b _08172F1C
	.align 2, 0
_08172EFC: .4byte 0x00000482
_08172F00: .4byte 0x0000025D
_08172F04:
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
_08172F1C:
	ldr r2, _08172F54 @ =0x000004A4
	adds r0, r5, r2
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
	bge _08172F3E
	rsbs r2, r2, #0
_08172F3E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08172F58
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08172F4C
	rsbs r2, r2, #0
_08172F4C:
	cmp r2, #0x20
	bgt _08172F58
	movs r0, #1
	b _08172FC2
	.align 2, 0
_08172F54: .4byte 0x000004A4
_08172F58:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08172F64
	cmp r1, #0
	beq _08172FC0
_08172F64:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08172F88 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172F8C
	asrs r1, r0, #0xc
	b _08172F92
	.align 2, 0
_08172F88: .4byte 0x085B0A08
_08172F8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172F92:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08172FB0 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172FB4
	asrs r1, r0, #0xc
	b _08172FBA
	.align 2, 0
_08172FB0: .4byte 0x085B0A08
_08172FB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172FBA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08172FC0:
	movs r0, #0
_08172FC2:
	cmp r0, #0
	beq _0817300C
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08173034 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_0817300C:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08178640
	ldr r3, _08173038 @ =0x0000101C
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _0817303C
	subs r3, #0x1c
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0xc
	bl FUN_08177d34
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _0817304A
	.align 2, 0
_08173034: .4byte 0x000004A4
_08173038: .4byte 0x0000101C
_0817303C:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
_0817304A:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	ldr r4, _08173090 @ =0x00000484
	adds r2, r5, r4
	ldr r1, [r2]
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r1, r0
	ble _08173098
	adds r0, r5, #0
	bl FUN_08175898
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08173094 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x1a
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08173090 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0817309C
	.align 2, 0
_08173090: .4byte 0x00000484
_08173094: .4byte 0x00000469
_08173098:
	adds r0, r1, #1
	str r0, [r2]
_0817309C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081730a4
FUN_081730a4: @ 0x081730A4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081730BC @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081730C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081730C2
	.align 2, 0
_081730BC: .4byte 0x0000046C
_081730C0:
	movs r0, #0
_081730C2:
	cmp r0, #0
	beq _08173104
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08173138 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0817313C @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08173104:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _08173140 @ =0x05000002
	bl CpuSet
	ldr r1, _08173144 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0xef
	ble _081731A0
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817314C
	ldr r3, _08173148 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0817315A
	.align 2, 0
_08173138: .4byte 0x0000046D
_0817313C: .4byte 0x0000046B
_08173140: .4byte 0x05000002
_08173144: .4byte 0x00000484
_08173148: .4byte 0xFFFFFF00
_0817314C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817315A
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0817315A:
	movs r0, #0
	cmp r1, #0x1f
	bgt _08173162
	movs r0, #1
_08173162:
	cmp r0, #0
	beq _081731A0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _08173198 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r1, [r0]
	ldr r0, _0817319C @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08173240
	.align 2, 0
_08173198: .4byte 0x00000469
_0817319C: .4byte 0x0000046C
_081731A0:
	ldr r1, _081731B8 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x77
	bgt _081731BC
	movs r5, #0x50
	movs r2, #8
	mov ip, r2
	movs r6, #2
	movs r7, #0xc3
	lsls r7, r7, #5
	b _081731D6
	.align 2, 0
_081731B8: .4byte 0x00000484
_081731BC:
	cmp r0, #0xc7
	bgt _081731CA
	movs r5, #0x28
	movs r3, #8
	mov ip, r3
	movs r6, #4
	b _081731D2
_081731CA:
	movs r5, #0x28
	movs r0, #8
	mov ip, r0
	movs r6, #6
_081731D2:
	movs r7, #0x9b
	lsls r7, r7, #3
_081731D6:
	ldr r3, _081731F4 @ =0x085B0A08
	ldrb r2, [r4, #5]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081731F8
	asrs r0, r0, #0xc
	b _081731FE
	.align 2, 0
_081731F4: .4byte 0x085B0A08
_081731F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081731FE:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173212
	asrs r2, r0, #0xc
	b _08173218
_08173212:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173218:
	ldrb r0, [r4, #5]
	adds r0, r0, r6
	strb r0, [r4, #5]
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	mov r1, ip
	movs r2, #0xc
	adds r3, r7, #0
	bl FUN_08177d34
	ldr r3, _08173248 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173240:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08173248: .4byte 0x00000484

	thumb_func_start FUN_0817324c
FUN_0817324c: @ 0x0817324C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08173264 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173268
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817326A
	.align 2, 0
_08173264: .4byte 0x0000046C
_08173268:
	movs r0, #0
_0817326A:
	cmp r0, #0
	beq _081732A8
	ldr r4, _081732F0 @ =FUN_08171718
	movs r3, #0x25
	ldr r2, _081732F4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081732F8 @ =0x0000046B
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
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081732A8:
	ldr r1, _081732F8 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08173304
	adds r0, r5, #0
	bl FUN_08175898
	movs r2, #2
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
	ldr r2, _081732FC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _08173300 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817330E
	.align 2, 0
_081732F0: .4byte FUN_08171718
_081732F4: .4byte 0x0000046D
_081732F8: .4byte 0x0000046B
_081732FC: .4byte 0x00000484
_08173300: .4byte 0xFFEFFFFF
_08173304:
	ldr r2, _08173314 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817330E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08173314: .4byte 0x00000484

	thumb_func_start FUN_08173318
FUN_08173318: @ 0x08173318
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08173344 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173348
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817334A
	.align 2, 0
_08173344: .4byte 0x0000046C
_08173348:
	movs r0, #0
_0817334A:
	cmp r0, #0
	beq _081733CA
	ldr r3, _0817339C @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _081733A0 @ =0x00000FB6
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _081733A4 @ =0x00001058
	add r7, sl
	ldr r0, _081733A8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081733AC
	adds r0, #4
	b _081733B8
	.align 2, 0
_0817339C: .4byte 0x00000256
_081733A0: .4byte 0x00000FB6
_081733A4: .4byte 0x00001058
_081733A8: .4byte 0x030046A4
_081733AC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081733B8:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_081733CA:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081733F8 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08173400
	ldr r0, _081733FC @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08173410
	.align 2, 0
_081733F8: .4byte 0x0000A02F
_081733FC: .4byte 0x00000482
_08173400:
	ldr r1, _08173434 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08173410
	movs r0, #1
	strh r0, [r2]
_08173410:
	ldr r3, _08173438 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817343C
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
	b _08173454
	.align 2, 0
_08173434: .4byte 0x00000482
_08173438: .4byte 0x0000025D
_0817343C:
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
_08173454:
	movs r2, #0x10
	ldr r1, _08173468 @ =0x00001008
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _0817346C
	movs r0, #1
	b _0817346E
	.align 2, 0
_08173468: .4byte 0x00001008
_0817346C:
	movs r0, #0
_0817346E:
	cmp r0, #0
	beq _08173480
	ldr r0, _08173498 @ =0x00000472
	adds r1, r5, r0
	ldr r2, _0817349C @ =0xFFFFFC00
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
_08173480:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _081734A4
	ldr r0, _081734A0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081734B2
	.align 2, 0
_08173498: .4byte 0x00000472
_0817349C: .4byte 0xFFFFFC00
_081734A0: .4byte 0xFFFFFF00
_081734A4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081734B2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081734B2:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _081734BC
	rsbs r0, r6, #0
_081734BC:
	cmp r0, #8
	ble _0817350C
	ldr r2, _081734DC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081734E0
	asrs r0, r0, #0xc
	b _081734E6
	.align 2, 0
_081734DC: .4byte 0x085B0A08
_081734E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081734E6:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081734FA
	asrs r2, r0, #0xc
	b _08173500
_081734FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173500:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_0817350C:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08173554
	cmp r1, #0
	blt _08173554
	ldr r0, _08173558 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08173554
	ldr r0, _0817355C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08173560
_08173554:
	movs r7, #0
	b _0817356E
	.align 2, 0
_08173558: .4byte 0x030046A8
_0817355C: .4byte 0x030046AC
_08173560:
	ldr r0, _081735F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0817356E:
	ldr r2, _081735F8 @ =0x00000FB6
	add r2, sl
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, r7
	beq _081735BE
	mov r4, sp
	ldr r2, _081735FC @ =0x00001058
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_081735BE:
	adds r0, r5, #0
	bl FUN_081765f8
	ldr r3, _08173600 @ =0x0000A410
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r6, #0
	cmp r6, #0
	bge _081735D8
	rsbs r0, r6, #0
_081735D8:
	cmp r0, #7
	bgt _08173668
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r7
	bne _0817368E
	movs r1, #0x10
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08173604
	movs r0, #1
	b _08173606
	.align 2, 0
_081735F4: .4byte 0x030046A4
_081735F8: .4byte 0x00000FB6
_081735FC: .4byte 0x00001058
_08173600: .4byte 0x0000A410
_08173604:
	movs r0, #0
_08173606:
	adds r2, r0, #0
	cmp r2, #0
	beq _08173638
	movs r2, #0xe
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08173630 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08173634 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	b _08173658
	.align 2, 0
_08173630: .4byte 0x00000469
_08173634: .4byte 0x00000484
_08173638:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08173660 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08173664 @ =0x0000046C
	adds r1, r5, r2
_08173658:
	movs r0, #1
	strb r0, [r1]
	b _0817368E
	.align 2, 0
_08173660: .4byte 0x00000484
_08173664: .4byte 0x0000046C
_08173668:
	cmp r6, #0
	ble _08173680
	ldr r3, _0817367C @ =0x00000482
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r5, #5]
	adds r0, r0, r1
	b _0817368C
	.align 2, 0
_0817367C: .4byte 0x00000482
_08173680:
	ldr r2, _081736A8 @ =0x00000482
	adds r0, r5, r2
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_0817368C:
	strb r0, [r5, #5]
_0817368E:
	ldr r3, _081736AC @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081736A8: .4byte 0x00000482
_081736AC: .4byte 0x00000484

	thumb_func_start FUN_081736b0
FUN_081736b0: @ 0x081736B0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081736D0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081736D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081736D6
	.align 2, 0
_081736D0: .4byte 0x0000046C
_081736D4:
	movs r0, #0
_081736D6:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r5, r3
	cmp r0, #0
	beq _081737AC
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r7, _08173738 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0817373C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r4, _08173740 @ =0x000001DD
	adds r0, r5, r4
	movs r7, #0xe0
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrb r4, [r0]
	ldr r2, _08173744 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08173748
	asrs r1, r0, #0xc
	b _0817374E
	.align 2, 0
_08173738: .4byte 0x0000046D
_0817373C: .4byte 0x0000046B
_08173740: .4byte 0x000001DD
_08173744: .4byte 0x085B0A08
_08173748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817374E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08173768
	asrs r0, r0, #0xc
	b _0817376E
_08173768:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817376E:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x20
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	movs r7, #0xde
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x80
	ldr r1, _081737DC @ =0x00001008
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r4, r3, #0
_081737AC:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081737C6
	b _081738CC
_081737C6:
	movs r2, #0x20
	ldr r3, _081737DC @ =0x00001008
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081737E0
	movs r0, #1
	b _081737E2
	.align 2, 0
_081737DC: .4byte 0x00001008
_081737E0:
	movs r0, #0
_081737E2:
	adds r4, r0, #0
	cmp r4, #0
	beq _0817384C
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r7, _0817383C @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08173840 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r2, [r0]
	movs r4, #0xd
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08173844 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08173848 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	b _081738A8
	.align 2, 0
_0817383C: .4byte 0x0000046D
_08173840: .4byte 0x0000046B
_08173844: .4byte 0x0000046A
_08173848: .4byte 0x00000484
_0817384C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _081738B4 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r7, _081738B8 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #0x14
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081738BC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081738C0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	ldr r4, _081738C4 @ =0x0000046C
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_08175898
	ldr r0, _081738C8 @ =0x000003D9
	bl PlaySound_082406e0
_081738A8:
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081738D6
	.align 2, 0
_081738B4: .4byte 0x0000046D
_081738B8: .4byte 0x0000046B
_081738BC: .4byte 0x0000046A
_081738C0: .4byte 0x00000484
_081738C4: .4byte 0x0000046C
_081738C8: .4byte 0x000003D9
_081738CC:
	ldr r7, _081738DC @ =0x00000484
	adds r1, r5, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081738D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081738DC: .4byte 0x00000484

	thumb_func_start FUN_081738e0
FUN_081738e0: @ 0x081738E0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08173900 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173904
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173906
	.align 2, 0
_08173900: .4byte 0x0000046C
_08173904:
	movs r0, #0
_08173906:
	cmp r0, #0
	beq _08173938
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08173968 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r7, _0817396C @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08173938:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	ldr r2, _08173970 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x63
	bgt _08173974
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0817398A
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0x18
	movs r3, #0
	bl FUN_08177a4c
	b _0817398A
	.align 2, 0
_08173968: .4byte 0x0000046D
_0817396C: .4byte 0x0000046B
_08173970: .4byte 0x00000484
_08173974:
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	bne _0817398A
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0x2c
	movs r3, #1
	bl FUN_08177a4c
_0817398A:
	ldr r3, _08173A04 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	cmp r0, #0xc8
	ble _08173A1C
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r2, #1
	ldr r7, _08173A08 @ =0x0000046D
	adds r0, r5, r7
	movs r1, #0
	strb r2, [r0]
	ldr r4, _08173A0C @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r3, #0
	strh r1, [r0]
	movs r4, #0x11
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r4, [r0]
	ldr r4, _08173A04 @ =0x00000484
	adds r0, r5, r4
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, _08173A10 @ =0x00001008
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08173A14 @ =0x00000F97
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08173A18 @ =0x00000F96
	adds r1, r6, r3
	movs r0, #3
	strb r0, [r1]
	b _08173A20
	.align 2, 0
_08173A04: .4byte 0x00000484
_08173A08: .4byte 0x0000046D
_08173A0C: .4byte 0x0000046B
_08173A10: .4byte 0x00001008
_08173A14: .4byte 0x00000F97
_08173A18: .4byte 0x00000F96
_08173A1C:
	adds r0, #1
	str r0, [r1]
_08173A20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08173a28
FUN_08173a28: @ 0x08173A28
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08173A40 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173A44
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173A46
	.align 2, 0
_08173A40: .4byte 0x0000046C
_08173A44:
	movs r0, #0
_08173A46:
	cmp r0, #0
	beq _08173AEC
	ldr r1, _08173A9C @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08173AA0 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08173AA4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08173AA8 @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _08173AAC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08173AB0
	asrs r1, r0, #0xc
	b _08173AB6
	.align 2, 0
_08173A9C: .4byte 0x000005A4
_08173AA0: .4byte 0x0000046D
_08173AA4: .4byte 0x0000046B
_08173AA8: .4byte 0x00000553
_08173AAC: .4byte 0x085B0A08
_08173AB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08173AB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _08173AD0
	asrs r2, r0, #0xc
	b _08173AD6
_08173AD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173AD6:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_08173AEC:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08173B74
	adds r0, r5, #0
	bl FUN_08175898
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08173B64 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08173B68 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08173B6C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08173B70 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08173B7E
	.align 2, 0
_08173B64: .4byte 0x0000046D
_08173B68: .4byte 0x0000046B
_08173B6C: .4byte 0x0000046A
_08173B70: .4byte 0x00000484
_08173B74:
	ldr r0, _08173B84 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173B7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08173B84: .4byte 0x00000484

	thumb_func_start FUN_08173b88
FUN_08173b88: @ 0x08173B88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08173BB0 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173BB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173BB6
	.align 2, 0
_08173BB0: .4byte 0x0000046C
_08173BB4:
	movs r0, #0
_08173BB6:
	cmp r0, #0
	bne _08173BBC
	b _08173D24
_08173BBC:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08173C30 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r2, _08173C34 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08173C38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08173C3C @ =0x0203B400
	adds r0, r0, r4
	movs r2, #0xff
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08173C74
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r7, r4
	ldrb r4, [r0]
	movs r5, #0x14
	ldr r1, _08173C40 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173C44
	asrs r2, r0, #0xc
	b _08173C4A
	.align 2, 0
_08173C30: .4byte 0x0000046D
_08173C34: .4byte 0x030046B8
_08173C38: .4byte 0x000003FF
_08173C3C: .4byte 0x0203B400
_08173C40: .4byte 0x085B0A08
_08173C44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173C4A:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173C62
	asrs r0, r0, #0xc
	b _08173C68
_08173C62:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08173C68:
	strh r0, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	b _08173CD8
_08173C74:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x20
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r7, r0
	ands r3, r2
	movs r5, #0x14
	ldr r1, _08173CA4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173CA8
	asrs r2, r0, #0xc
	b _08173CAE
	.align 2, 0
_08173CA4: .4byte 0x085B0A08
_08173CA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173CAE:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173CC6
	asrs r0, r0, #0xc
	b _08173CCC
_08173CC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08173CCC:
	strh r0, [r4, #4]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
_08173CD8:
	strb r0, [r7, #5]
	ldr r0, _08173D5C @ =0x00000472
	adds r4, r7, r0
	ldr r1, _08173D60 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	movs r5, #0
	strh r0, [r7, #0xa]
	adds r1, r7, #0
	adds r1, #8
	mov r0, r8
	bl FUN_08177f7c
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x2a
	strh r0, [r1]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r5, [r0]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #4
	ldr r2, _08173D64 @ =0x00001008
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08173D68 @ =0x000003E6
	bl PlaySound_082406e0
_08173D24:
	ldr r2, _08173D6C @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _08173D74
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173D70 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r6, r7, r3
_08173D4A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #3
	ble _08173D4A
	b _08173E2C
	.align 2, 0
_08173D5C: .4byte 0x00000472
_08173D60: .4byte 0xFFFFFF00
_08173D64: .4byte 0x00001008
_08173D68: .4byte 0x000003E6
_08173D6C: .4byte 0x00000484
_08173D70: .4byte 0x05000002
_08173D74:
	cmp r0, #0x13
	bgt _08173DAC
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173DA8 @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r6, r7, r0
_08173D94:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08173D94
	b _08173E2C
	.align 2, 0
_08173DA8: .4byte 0x05000002
_08173DAC:
	cmp r0, #0x3b
	bgt _08173DE4
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r6, r7, r1
_08173DCC:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08173DCC
	b _08173E2C
	.align 2, 0
_08173DE0: .4byte 0x05000002
_08173DE4:
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r6, r7, r2
	cmp r0, #0x4f
	bgt _08173E2C
	add r4, sp, #0x1c
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173E14 @ =0x05000002
	bl CpuSet
	movs r5, #0
_08173E00:
	cmp r5, #3
	bgt _08173E18
	movs r0, #0x54
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	b _08173E26
	.align 2, 0
_08173E14: .4byte 0x05000002
_08173E18:
	movs r0, #0x94
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
_08173E26:
	adds r5, #1
	cmp r5, #7
	ble _08173E00
_08173E2C:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	mov r0, r8
	bl FUN_08176c60
	ldr r0, [r7, #0x44]
	ldr r0, [r0]
	movs r3, #1
	mov r8, r3
	ands r0, r3
	cmp r0, #0
	bne _08173E58
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r7, r4
	bl FUN_08013984
_08173E58:
	movs r0, #0x10
	ldr r1, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08173F10
	ldr r0, _08173EF8 @ =0xFFEFFFFF
	ands r1, r0
	str r1, [r6]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x24
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08173EFC @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	mov r3, r8
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r5, [r0]
	ldr r2, _08173F00 @ =0x00000469
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _08173F04 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r6, [r0]
	ldr r1, _08173F08 @ =0x0000046C
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, _08173F0C @ =0x00000145
	bl PlaySound_082406e0
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_080139a0
	b _08173F1A
	.align 2, 0
_08173EF8: .4byte 0xFFEFFFFF
_08173EFC: .4byte 0x000004A4
_08173F00: .4byte 0x00000469
_08173F04: .4byte 0x0000046A
_08173F08: .4byte 0x0000046C
_08173F0C: .4byte 0x00000145
_08173F10:
	ldr r4, _08173F28 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173F1A:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08173F28: .4byte 0x00000484

	thumb_func_start FUN_08173f2c
FUN_08173f2c: @ 0x08173F2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08173F58 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173F5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173F5E
	.align 2, 0
_08173F58: .4byte 0x0000046C
_08173F5C:
	movs r0, #0
_08173F5E:
	ldr r3, _08173FD4 @ =0x00001008
	add r3, sb
	mov r8, r3
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r5, r6
	str r6, [sp, #0x10]
	cmp r0, #0
	beq _08173FBC
	movs r3, #0x20
	ldr r0, _08173FD8 @ =0x00000474
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r4, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	mov r6, r8
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	ldr r1, _08173FDC @ =0xFFEFFFFF
	ldr r6, [sp, #0x10]
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #9
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08173FBC:
	ldr r3, _08173FE0 @ =0x00000484
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0x50
	ble _08173FE4
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #4
	movs r3, #0
	bl FUN_08177d34
	b _08173FF0
	.align 2, 0
_08173FD4: .4byte 0x00001008
_08173FD8: .4byte 0x00000474
_08173FDC: .4byte 0xFFEFFFFF
_08173FE0: .4byte 0x00000484
_08173FE4:
	ldr r3, _081740C0 @ =0x0000FFFF
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #4
	bl FUN_08177d34
_08173FF0:
	movs r6, #0
	ldr r1, _081740C4 @ =0x00001012
	add r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _0817406C
	mov r3, sp
	adds r7, r5, #0
	adds r7, #8
	ldr r0, _081740C8 @ =0x00000472
	adds r0, r5, r0
	str r0, [sp, #0xc]
	str r1, [sp, #8]
	mov r4, sb
	mov ip, r6
	movs r1, #0x92
	lsls r1, r1, #1
	mov sl, r1
_08174016:
	mov r2, ip
	add r2, sb
	ldr r0, _081740CC @ =0x00000674
	adds r2, r2, r0
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
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0817405C
	ldr r0, [sp, #0xc]
	ldrh r1, [r0]
	ldr r2, _081740D0 @ =0x00000676
	adds r0, r4, r2
	strh r1, [r0]
_0817405C:
	add r4, sl
	add ip, sl
	adds r6, #1
	ldr r1, [sp, #8]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _08174016
_0817406C:
	mov r0, sb
	bl FUN_08176c60
	movs r1, #0x10
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081740B0
	adds r0, r5, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #8
	mov r6, r8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0x20
	ldr r1, _081740D4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081740B0:
	movs r1, #8
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081740D8
	movs r0, #1
	b _081740DA
	.align 2, 0
_081740C0: .4byte 0x0000FFFF
_081740C4: .4byte 0x00001012
_081740C8: .4byte 0x00000472
_081740CC: .4byte 0x00000674
_081740D0: .4byte 0x00000676
_081740D4: .4byte 0x00000474
_081740D8:
	movs r0, #0
_081740DA:
	cmp r0, #0
	beq _081741D0
	ldrh r0, [r5, #0xa]
	subs r0, #0x10
	movs r6, #0
	movs r7, #0
	strh r0, [r5, #0xa]
	mov r0, sb
	bl FUN_08176c60
	cmp r0, #0
	bge _081741D0
	ldr r2, _0817412C @ =0x00000F96
	add r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _08174138
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r6, [r0]
	ldr r6, _08174130 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174134 @ =0x00000484
	adds r0, r5, r1
	str r7, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _081741DA
	.align 2, 0
_0817412C: .4byte 0x00000F96
_08174130: .4byte 0x0000046A
_08174134: .4byte 0x00000484
_08174138:
	ldr r4, _0817416C @ =0x00000F97
	add r4, sb
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	ble _0817417C
	movs r1, #0xe
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08174170 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r6, _08174174 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174178 @ =0x00000484
	adds r0, r5, r1
	str r7, [r0]
	adds r2, #4
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081741DA
	.align 2, 0
_0817416C: .4byte 0x00000F97
_08174170: .4byte 0x00000469
_08174174: .4byte 0x0000046A
_08174178: .4byte 0x00000484
_0817417C:
	movs r1, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	ldr r2, _081741C0 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081741C4 @ =0x00000484
	adds r0, r5, r6
	str r7, [r0]
	ldr r0, _081741C8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081741CC @ =0x00000474
	adds r2, r5, r1
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _081741DA
	.align 2, 0
_081741C0: .4byte 0x00000469
_081741C4: .4byte 0x00000484
_081741C8: .4byte 0x0000046C
_081741CC: .4byte 0x00000474
_081741D0:
	ldr r2, _081741EC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081741DA:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081741EC: .4byte 0x00000484

	thumb_func_start FUN_081741f0
FUN_081741f0: @ 0x081741F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0817421C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174220
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174222
	.align 2, 0
_0817421C: .4byte 0x0000046C
_08174220:
	movs r0, #0
_08174222:
	cmp r0, #0
	beq _08174266
	movs r3, #0x20
	ldr r5, _0817424C @ =0x00000474
	adds r2, r4, r5
	ldrh r1, [r2]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08174250 @ =0x00001008
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ands r0, r3
	cmp r0, #0
	beq _08174254
	movs r0, #1
	b _08174256
	.align 2, 0
_0817424C: .4byte 0x00000474
_08174250: .4byte 0x00001008
_08174254:
	movs r0, #0
_08174256:
	cmp r0, #0
	beq _08174266
	bl FUN_081f746c
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08174266:
	movs r7, #0xa
	ldrsh r1, [r4, r7]
	ldr r0, _08174294 @ =0xFFFFF800
	ldrh r6, [r4, #0xa]
	cmp r1, r0
	ble _08174324
	mov r3, sp
	ldrb r5, [r4, #5]
	ldr r2, _08174298 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _0817429C
	asrs r1, r0, #0xc
	b _081742A2
	.align 2, 0
_08174294: .4byte 0xFFFFF800
_08174298: .4byte 0x085B0A08
_0817429C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081742A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _081742BC
	asrs r0, r0, #0xc
	b _081742C2
_081742BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081742C2:
	strh r0, [r3, #4]
	adds r0, r6, #0
	subs r0, #0x64
	strh r0, [r4, #0xa]
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	cmp r0, #0
	bne _0817432A
	movs r3, #0xa
	ldrsh r1, [r4, r3]
	ldr r5, _08174308 @ =0x00000472
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817432A
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x20
	ldr r0, _0817430C @ =0x00001008
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08174310
	movs r0, #1
	b _08174312
	.align 2, 0
_08174308: .4byte 0x00000472
_0817430C: .4byte 0x00001008
_08174310:
	movs r0, #0
_08174312:
	cmp r0, #0
	bne _0817432A
	ldr r0, _08174320 @ =0x000001A5
	bl PlaySound_082406e0
	b _0817432A
	.align 2, 0
_08174320: .4byte 0x000001A5
_08174324:
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
_0817432A:
	ldr r7, _08174344 @ =0x00000484
	adds r0, r4, r7
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _08174348
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #4
	movs r3, #0
	bl FUN_08177d34
	b _08174354
	.align 2, 0
_08174344: .4byte 0x00000484
_08174348:
	ldr r3, _081743FC @ =0x0000A410
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #6
	bl FUN_08177d34
_08174354:
	movs r6, #0
	ldr r1, _08174400 @ =0x00001012
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _081743DC
	add r3, sp, #8
	adds r5, r4, #0
	adds r5, #8
	str r5, [sp, #0x14]
	ldr r7, _08174404 @ =0x00000472
	adds r7, r4, r7
	str r7, [sp, #0x10]
	mov sl, r1
	mov r5, r8
	mov ip, r6
	movs r0, #0x92
	lsls r0, r0, #1
	mov sb, r0
_0817437C:
	mov r2, ip
	add r2, r8
	ldr r1, _08174408 @ =0x00000674
	adds r2, r2, r1
	ldrh r0, [r2]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldr r7, [sp, #0x14]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _081743CC
	ldr r0, _0817440C @ =0x00000676
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	cmp r0, r1
	bge _081743CC
	strh r1, [r2]
_081743CC:
	add r5, sb
	add ip, sb
	adds r6, #1
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _0817437C
_081743DC:
	mov r0, r8
	bl FUN_08176c60
	cmp r0, #0
	blt _081743E8
	b _0817454C
_081743E8:
	movs r1, #0x20
	ldr r0, _08174410 @ =0x00001008
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08174414
	movs r0, #1
	b _08174416
	.align 2, 0
_081743FC: .4byte 0x0000A410
_08174400: .4byte 0x00001012
_08174404: .4byte 0x00000472
_08174408: .4byte 0x00000674
_0817440C: .4byte 0x00000676
_08174410: .4byte 0x00001008
_08174414:
	movs r0, #0
_08174416:
	adds r2, r0, #0
	cmp r2, #0
	beq _08174458
	ldr r3, _08174450 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0xa0
	bgt _08174428
	b _0817454C
_08174428:
	movs r2, #0x13
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08174454 @ =0x00000469
	adds r0, r4, r7
	strb r1, [r0]
	subs r3, #0x1a
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r4, r5
	str r1, [r0]
	adds r7, #3
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	b _0817454C
	.align 2, 0
_08174450: .4byte 0x00000484
_08174454: .4byte 0x00000469
_08174458:
	ldr r1, _081744A0 @ =0x00000484
	adds r0, r4, r1
	ldr r1, _081744A4 @ =0x00000F98
	add r1, r8
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	ble _0817454C
	ldr r3, _081744A8 @ =0x00000F96
	add r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _081744B4
	movs r1, #0xe
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r2, [r0]
	ldr r7, _081744AC @ =0x00000469
	adds r0, r4, r7
	strb r2, [r0]
	adds r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r2, [r0]
	ldr r0, _081744B0 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	b _08174556
	.align 2, 0
_081744A0: .4byte 0x00000484
_081744A4: .4byte 0x00000F98
_081744A8: .4byte 0x00000F96
_081744AC: .4byte 0x00000469
_081744B0: .4byte 0x0000046C
_081744B4:
	ldr r5, _081744E8 @ =0x00000F97
	add r5, r8
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	ble _081744FC
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r5, _081744EC @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	ldr r7, _081744F0 @ =0x0000046A
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _081744F4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _081744F8 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _08174556
	.align 2, 0
_081744E8: .4byte 0x00000F97
_081744EC: .4byte 0x00000469
_081744F0: .4byte 0x0000046A
_081744F4: .4byte 0x00000484
_081744F8: .4byte 0x0000046C
_081744FC:
	movs r1, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r7, _08174540 @ =0x00000469
	adds r0, r4, r7
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r2, [r0]
	ldr r0, _08174544 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08174548 @ =0x00000474
	adds r2, r4, r1
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08174556
	.align 2, 0
_08174540: .4byte 0x00000469
_08174544: .4byte 0x0000046C
_08174548: .4byte 0x00000474
_0817454C:
	ldr r2, _08174568 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08174556:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174568: .4byte 0x00000484

	thumb_func_start FUN_0817456c
FUN_0817456c: @ 0x0817456C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0817458C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174590
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174592
	.align 2, 0
_0817458C: .4byte 0x0000046C
_08174590:
	movs r0, #0
_08174592:
	cmp r0, #0
	beq _08174658
	movs r2, #0x10
	ldr r3, _081745AC @ =0x00001008
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081745B0
	movs r0, #1
	b _081745B2
	.align 2, 0
_081745AC: .4byte 0x00001008
_081745B0:
	movs r0, #0
_081745B2:
	adds r2, r0, #0
	cmp r2, #0
	bne _08174658
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r4, #1
	ldr r3, _0817468C @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
	adds r0, r7, #0
	bl FUN_08176e14
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _08174690 @ =0x00000472
	adds r1, r5, r2
	ldr r3, _08174694 @ =0xFFFFFF00
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08177f7c
	ldr r0, _08174698 @ =0x00000474
	adds r2, r5, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r1, _0817469C @ =0x00000F8C
	adds r2, r7, r1
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _081746A0 @ =0x00000FA4
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r3, _081746A4 @ =0x00000F94
	adds r0, r7, r3
	strh r1, [r0]
	movs r0, #0x10
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0xf9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08174658:
	adds r0, r5, #0
	bl FUN_081765f8
	movs r6, #0xb1
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _081746A8 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081746B0
	ldr r3, _081746AC @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081746C0
	.align 2, 0
_0817468C: .4byte 0x0000046D
_08174690: .4byte 0x00000472
_08174694: .4byte 0xFFFFFF00
_08174698: .4byte 0x00000474
_0817469C: .4byte 0x00000F8C
_081746A0: .4byte 0x00000FA4
_081746A4: .4byte 0x00000F94
_081746A8: .4byte 0x0000A02F
_081746AC: .4byte 0x00000482
_081746B0:
	ldr r1, _081746E4 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081746C0
	movs r0, #1
	strh r0, [r2]
_081746C0:
	ldr r3, _081746E8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081746EC
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
	b _08174704
	.align 2, 0
_081746E4: .4byte 0x00000482
_081746E8: .4byte 0x0000025D
_081746EC:
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
_08174704:
	ldr r0, _0817474C @ =0x00000472
	adds r1, r5, r0
	ldr r2, _08174750 @ =0xFFFFFC00
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	ldr r3, _08174754 @ =0x000004A4
	adds r0, r5, r3
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
	bge _08174734
	rsbs r2, r2, #0
_08174734:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08174758
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08174742
	rsbs r2, r2, #0
_08174742:
	cmp r2, #0x20
	bgt _08174758
	movs r0, #1
	b _081747C2
	.align 2, 0
_0817474C: .4byte 0x00000472
_08174750: .4byte 0xFFFFFC00
_08174754: .4byte 0x000004A4
_08174758:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08174764
	cmp r1, #0
	beq _081747C0
_08174764:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08174788 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0817478C
	asrs r1, r0, #0xc
	b _08174792
	.align 2, 0
_08174788: .4byte 0x085B0A08
_0817478C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08174792:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081747B0 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081747B4
	asrs r1, r0, #0xc
	b _081747BA
	.align 2, 0
_081747B0: .4byte 0x085B0A08
_081747B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081747BA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_081747C0:
	movs r0, #0
_081747C2:
	cmp r0, #0
	beq _081748B8
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _08174834 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
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
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r3, r5, r1
	strb r0, [r3]
	ldr r2, _08174838 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817483C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08174840 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _081748B8
	ldrb r1, [r3]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08174848
	ldr r3, _08174844 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08174856
	.align 2, 0
_08174834: .4byte 0x000004A4
_08174838: .4byte 0x030046B8
_0817483C: .4byte 0x000003FF
_08174840: .4byte 0x0203B400
_08174844: .4byte 0xFFFFFF00
_08174848:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174856
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08174856:
	cmp r1, #0
	bge _0817485C
	rsbs r1, r1, #0
_0817485C:
	cmp r1, #0x20
	ble _081748B8
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, _081748A8 @ =0x00000472
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r2, _081748AC @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	adds r0, r5, #0
	bl FUN_0817697c
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _081748B0 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _081748B4 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0817496E
	.align 2, 0
_081748A8: .4byte 0x00000472
_081748AC: .4byte 0x0000FFFF
_081748B0: .4byte 0x00000469
_081748B4: .4byte 0x0000046C
_081748B8:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08178640
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	ldr r2, _08174948 @ =0x00000F94
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _08174960
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _0817494C @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _08174950 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08174954 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174958 @ =0x0000046B
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
	ldr r3, _0817495C @ =0x00001008
	adds r2, r7, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	b _0817496E
	.align 2, 0
_08174948: .4byte 0x00000F94
_0817494C: .4byte 0x00000469
_08174950: .4byte 0x0000046A
_08174954: .4byte FUN_080e48d0
_08174958: .4byte 0x0000046B
_0817495C: .4byte 0x00001008
_08174960:
	subs r0, #1
	strh r0, [r1]
	ldr r6, _08174978 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817496E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174978: .4byte 0x00000484

	thumb_func_start FUN_0817497c
FUN_0817497c: @ 0x0817497C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0817499C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081749A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081749A2
	.align 2, 0
_0817499C: .4byte 0x0000046C
_081749A0:
	movs r0, #0
_081749A2:
	cmp r0, #0
	beq _08174A54
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _08174A9C @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	subs r4, #0xe1
	adds r5, r6, r4
	ldrh r0, [r5]
	strh r0, [r6, #0xa]
	ldr r0, _08174AA0 @ =0x00000474
	adds r2, r6, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08174AA4 @ =0x00001008
	adds r2, r7, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x2a
	strh r0, [r1]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	adds r4, r6, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08176698
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08174AA8 @ =0xFFFFF818
	adds r1, r0, #0
	ldrh r5, [r5]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r2, _08174AAC @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	bl FUN_08177f7c
	ldr r0, _08174AB0 @ =0x000003E3
	bl PlaySound_082406e0
_08174A54:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08174ABC
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174AB4 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _08174AB8 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08174AD8
	.align 2, 0
_08174A9C: .4byte 0x0000046D
_08174AA0: .4byte 0x00000474
_08174AA4: .4byte 0x00001008
_08174AA8: .4byte 0xFFFFF818
_08174AAC: .4byte 0x0000FFFF
_08174AB0: .4byte 0x000003E3
_08174AB4: .4byte 0x00000469
_08174AB8: .4byte 0x00000484
_08174ABC:
	ldr r3, _08174AE0 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #4
	movs r2, #4
	bl FUN_08177d34
	adds r0, r7, #0
	bl FUN_08176c60
	ldr r4, _08174AE4 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08174AD8:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174AE0: .4byte 0x0000FFFF
_08174AE4: .4byte 0x00000484

	thumb_func_start FUN_08174ae8
FUN_08174ae8: @ 0x08174AE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08174B14 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174B18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174B1A
	.align 2, 0
_08174B14: .4byte 0x0000046C
_08174B18:
	movs r0, #0
_08174B1A:
	ldr r3, _08174BE0 @ =0x00001008
	add r3, sl
	str r3, [sp, #0x34]
	cmp r0, #0
	beq _08174BCC
	ldr r4, _08174BE4 @ =0x00000F78
	add r4, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	movs r2, #0xf8
	lsls r2, r2, #4
	add r2, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r5, _08174BE8 @ =0x0203B400
	mov r8, r5
	ldr r3, _08174BEC @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _08174BF0 @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0x40
	movs r5, #0x7f
	ands r2, r5
	adds r0, r0, r2
	movs r2, #0
	mov sb, r2
	movs r2, #0
	mov ip, r2
	strh r0, [r4]
	adds r1, #1
	ldr r4, _08174BF0 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ldr r2, _08174BF4 @ =0x00000F7C
	add r2, sl
	ldrh r0, [r2]
	subs r0, #0x40
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #5]
	ldr r0, _08174BF8 @ =0x00000F8A
	add r0, sl
	strb r1, [r0]
	ldr r1, _08174BFC @ =0x00000F88
	add r1, sl
	movs r0, #0x3c
	strh r0, [r1]
	ldr r3, _08174C00 @ =FUN_081719b8
	movs r2, #0x27
	ldr r5, _08174C04 @ =0x0000046D
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08174C08 @ =0x0000046B
	adds r0, r7, r1
	mov r4, sb
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r3, ip
	strh r3, [r0]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r4, [sp, #0x34]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08174BCC:
	bl FUN_081f7444
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08174C0C
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r2, [r0]
	b _08174C52
	.align 2, 0
_08174BE0: .4byte 0x00001008
_08174BE4: .4byte 0x00000F78
_08174BE8: .4byte 0x0203B400
_08174BEC: .4byte 0x030046B8
_08174BF0: .4byte 0x000003FF
_08174BF4: .4byte 0x00000F7C
_08174BF8: .4byte 0x00000F8A
_08174BFC: .4byte 0x00000F88
_08174C00: .4byte FUN_081719b8
_08174C04: .4byte 0x0000046D
_08174C08: .4byte 0x0000046B
_08174C0C:
	ldr r0, _08174C60 @ =0x00000F78
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldr r4, _08174C64 @ =0x00000F88
	add r4, sl
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x10]
	adds r1, r1, r0
	strh r1, [r7, #0x10]
	ldr r0, _08174C68 @ =0x00000F7C
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc
	ldrsh r1, [r7, r5]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #0x14]
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	bl FUN_0823785c
	adds r2, r0, #0
_08174C52:
	ldrb r0, [r7, #5]
	subs r1, r2, r0
	cmp r1, #0x80
	ble _08174C70
	ldr r3, _08174C6C @ =0xFFFFFF00
	adds r1, r1, r3
	b _08174C7E
	.align 2, 0
_08174C60: .4byte 0x00000F78
_08174C64: .4byte 0x00000F88
_08174C68: .4byte 0x00000F7C
_08174C6C: .4byte 0xFFFFFF00
_08174C70:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174C7E
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_08174C7E:
	adds r0, r1, #0
	cmp r1, #0
	bge _08174C86
	rsbs r0, r1, #0
_08174C86:
	cmp r0, #0x1f
	bgt _08174C8E
	strb r2, [r7, #5]
	b _08174C9E
_08174C8E:
	cmp r1, #0
	bge _08174C98
	ldrb r0, [r7, #5]
	subs r0, #4
	b _08174C9C
_08174C98:
	ldrb r0, [r7, #5]
	adds r0, #4
_08174C9C:
	strb r0, [r7, #5]
_08174C9E:
	ldr r6, _08174D28 @ =0x00000F88
	add r6, sl
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08174D18
	ldr r3, _08174D2C @ =0x00000F78
	add r3, sl
	movs r0, #0xf8
	lsls r0, r0, #4
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r5, _08174D30 @ =0x0203B400
	mov sb, r5
	ldr r4, _08174D34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r0, _08174D38 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0x40
	movs r5, #0x7f
	mov r8, r5
	mov r5, r8
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r0, _08174D38 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldr r3, _08174D3C @ =0x00000F7C
	add r3, sl
	ldrh r0, [r3]
	subs r0, #0x40
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r2, _08174D38 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x1e
	strh r0, [r6]
_08174D18:
	movs r1, #0x40
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08174D40
	movs r0, #1
	b _08174D42
	.align 2, 0
_08174D28: .4byte 0x00000F88
_08174D2C: .4byte 0x00000F78
_08174D30: .4byte 0x0203B400
_08174D34: .4byte 0x030046B8
_08174D38: .4byte 0x000003FF
_08174D3C: .4byte 0x00000F7C
_08174D40:
	movs r0, #0
_08174D42:
	cmp r0, #0
	beq _08174DCE
	ldr r0, _08174E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	movs r4, #0x8a
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r1, [r1]
	movs r5, #0x8c
	lsls r5, r5, #2
	adds r2, r7, r5
	ldrh r2, [r2]
	adds r4, #0x1c
	adds r3, r7, r4
	ldr r3, [r3]
	adds r5, #8
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp]
	ldr r4, _08174E8C @ =0x00000F9C
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	movs r4, #0xfa
	lsls r4, r4, #4
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	ldr r4, _08174E90 @ =0x00000FB2
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	subs r5, #0xae
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	adds r5, #2
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl FUN_081f7248
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r2, [sp, #0x34]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08174E94 @ =0x00000F96
	add r1, sl
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	ldr r1, _08174E98 @ =0x00000F97
	add r1, sl
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	ldr r3, _08174E9C @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #0x14
	str r0, [r1]
_08174DCE:
	ldr r5, _08174E9C @ =0x00000484
	adds r4, r7, r5
	ldr r1, _08174EA0 @ =0x00000F9A
	add r1, sl
	ldr r0, [r4]
	ldrh r1, [r1]
	cmp r0, r1
	bgt _08174DE0
	b _081750D0
_08174DE0:
	bl FUN_081f7444
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08174DEC
	b _081750DC
_08174DEC:
	ldr r1, _08174EA4 @ =0x00000546
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _08174E02
	b _08174F6C
_08174E02:
	ldr r2, _08174EA8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08174EAC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08174EB0 @ =0x0203B400
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x2f
	ble _08174E1C
	b _08174F38
_08174E1C:
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08174EB4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x24
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08174EB8 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r6, #0
	adds r0, r2, #0
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl FUN_0823785c
	adds r5, #0x60
	adds r1, r7, r5
	strb r0, [r1]
	ldr r0, _08174E98 @ =0x00000F97
	add r0, sl
	strb r6, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08174EC0
	ldr r0, _08174EBC @ =0xFFFFFF00
	adds r1, r1, r0
	b _08174ECE
	.align 2, 0
_08174E88: .4byte 0x03002BE0
_08174E8C: .4byte 0x00000F9C
_08174E90: .4byte 0x00000FB2
_08174E94: .4byte 0x00000F96
_08174E98: .4byte 0x00000F97
_08174E9C: .4byte 0x00000484
_08174EA0: .4byte 0x00000F9A
_08174EA4: .4byte 0x00000546
_08174EA8: .4byte 0x030046B8
_08174EAC: .4byte 0x000003FF
_08174EB0: .4byte 0x0203B400
_08174EB4: .4byte 0xFFEFFFFF
_08174EB8: .4byte 0x000004A4
_08174EBC: .4byte 0xFFFFFF00
_08174EC0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174ECE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08174ECE:
	cmp r1, #0
	bge _08174ED4
	rsbs r1, r1, #0
_08174ED4:
	cmp r1, #0x20
	ble _08174F08
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08174F00 @ =0x00000469
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08174F04 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r1, [r0]
	adds r4, #3
	adds r0, r7, r4
	strb r2, [r0]
	b _081750DC
	.align 2, 0
_08174F00: .4byte 0x00000469
_08174F04: .4byte 0x0000046A
_08174F08:
	movs r2, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174F2C @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08174F30 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	ldr r0, _08174F34 @ =0x0000046C
	adds r1, r7, r0
	b _081750C2
	.align 2, 0
_08174F2C: .4byte 0x00000469
_08174F30: .4byte 0x0000046A
_08174F34: .4byte 0x0000046C
_08174F38:
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174F5C @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08174F60 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _08174F64 @ =0x00000484
	adds r0, r7, r5
	str r1, [r0]
	ldr r0, _08174F68 @ =0x0000046C
	adds r1, r7, r0
	b _081750C2
	.align 2, 0
_08174F5C: .4byte 0x00000469
_08174F60: .4byte 0x0000046A
_08174F64: .4byte 0x00000484
_08174F68: .4byte 0x0000046C
_08174F6C:
	ldr r2, _08175008 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817500C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08175010 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc1
	ble _08174F86
	b _081750A0
_08174F86:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _08175014 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x2c
	adds r4, r7, #0
	adds r4, #8
	ldr r5, _08175018 @ =0x000004A4
	adds r0, r7, r5
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	mov sb, r5
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r5, #0xee
	lsls r5, r5, #1
	adds r4, r7, r5
	strb r0, [r4]
	ldr r0, _0817501C @ =0x00000F97
	add r0, sl
	mov r1, r8
	strb r1, [r0]
	movs r0, #0xfb
	lsls r0, r0, #4
	add r0, sl
	mov r2, sb
	strh r2, [r0]
	movs r0, #0xd3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrb r1, [r4]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08175024
	ldr r3, _08175020 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08175032
	.align 2, 0
_08175008: .4byte 0x030046B8
_0817500C: .4byte 0x000003FF
_08175010: .4byte 0x0203B400
_08175014: .4byte 0xFFEFFFFF
_08175018: .4byte 0x000004A4
_0817501C: .4byte 0x00000F97
_08175020: .4byte 0xFFFFFF00
_08175024:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08175032
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_08175032:
	cmp r1, #0
	bge _08175038
	rsbs r1, r1, #0
_08175038:
	cmp r1, #0x20
	ble _08175070
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08175064 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08175068 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0817506C @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	b _081750DC
	.align 2, 0
_08175064: .4byte 0x00000469
_08175068: .4byte 0x0000046A
_0817506C: .4byte 0x0000046C
_08175070:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08175094 @ =0x00000469
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08175098 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0817509C @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #4
	adds r1, r7, r3
	b _081750C2
	.align 2, 0
_08175094: .4byte 0x00000469
_08175098: .4byte 0x0000046A
_0817509C: .4byte 0x00000484
_081750A0:
	movs r2, #0x11
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _081750C8 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	ldr r3, _081750CC @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r1, [r0]
	adds r5, #3
	adds r1, r7, r5
_081750C2:
	movs r0, #1
	strb r0, [r1]
	b _081750DC
	.align 2, 0
_081750C8: .4byte 0x00000469
_081750CC: .4byte 0x0000046A
_081750D0:
	adds r0, r7, #0
	bl FUN_08179a94
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_081750DC:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081750ec
FUN_081750ec: @ 0x081750EC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0817510C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175110
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08175112
	.align 2, 0
_0817510C: .4byte 0x0000046C
_08175110:
	movs r0, #0
_08175112:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r5, r4, r3
	cmp r0, #0
	beq _08175172
	movs r7, #0xb4
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r2, [r0]
	movs r1, #1
	ldr r3, _081751B8 @ =0x0000046D
	adds r0, r4, r3
	movs r3, #0
	strb r1, [r0]
	ldr r7, _081751BC @ =0x0000046B
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
	ldr r7, _081751C0 @ =0x00001008
	adds r2, r6, r7
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _081751C4 @ =0x0000FFC0
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	ldr r1, _081751C8 @ =0xFFEFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
_08175172:
	ldr r3, _081751CC @ =0x0000FFFF
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r6, #0
	bl FUN_08176c60
	movs r1, #0x10
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08175218
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _081751C0 @ =0x00001008
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081751D0
	movs r0, #1
	b _081751D2
	.align 2, 0
_081751B8: .4byte 0x0000046D
_081751BC: .4byte 0x0000046B
_081751C0: .4byte 0x00001008
_081751C4: .4byte 0x0000FFC0
_081751C8: .4byte 0xFFEFFFFF
_081751CC: .4byte 0x0000FFFF
_081751D0:
	movs r0, #0
_081751D2:
	cmp r0, #0
	beq _081751EC
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r0, _081751E8 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _081751F2
	.align 2, 0
_081751E8: .4byte 0xFFFFFEFF
_081751EC:
	ldr r0, _08175228 @ =0x00000145
	bl PlaySound_082406e0
_081751F2:
	movs r2, #0xd
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817522C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _08175230 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_08175218:
	ldr r7, _08175230 @ =0x00000484
	adds r1, r4, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175228: .4byte 0x00000145
_0817522C: .4byte 0x00000469
_08175230: .4byte 0x00000484

	thumb_func_start FUN_08175234
FUN_08175234: @ 0x08175234
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08175254 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175258
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817525A
	.align 2, 0
_08175254: .4byte 0x0000046C
_08175258:
	movs r0, #0
_0817525A:
	adds r1, r0, #0
	cmp r1, #0
	bne _08175262
	b _081753B8
_08175262:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08175328 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r2, [r0]
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
	strh r2, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	strh r0, [r6, #8]
	movs r0, #0xfc
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r6, #0xc]
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r4, r6, #0
	adds r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08177f7c
	movs r0, #0x20
	ldr r1, _0817532C @ =0x00000474
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	ldr r3, _08175330 @ =0x00001008
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08175334 @ =0x03002BE0
	add r2, sp, #4
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r6, r4
	ldrb r4, [r6, #5]
	movs r7, #0x18
	ldr r2, _08175338 @ =0x085B0A08
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
	blt _0817533C
	asrs r1, r0, #0xc
	b _08175342
	.align 2, 0
_08175328: .4byte 0x0000046D
_0817532C: .4byte 0x00000474
_08175330: .4byte 0x00001008
_08175334: .4byte 0x03002BE0
_08175338: .4byte 0x085B0A08
_0817533C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08175342:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0817535C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08175360
	asrs r0, r0, #0xc
	b _08175366
	.align 2, 0
_0817535C: .4byte 0x085B0A08
_08175360:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08175366:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x30
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	subs r3, #0x46
	adds r2, r6, r3
	ldr r1, _081753B0 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_08179ef0
	ldr r0, _081753B4 @ =0x000001A5
	bl PlaySound_082406e0
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	b _0817551E
	.align 2, 0
_081753B0: .4byte 0xFFEFFFFF
_081753B4: .4byte 0x000001A5
_081753B8:
	ldr r4, _081753E8 @ =0x00000484
	adds r0, r6, r4
	ldr r0, [r0]
	cmp r0, #9
	bgt _081753F0
	add r4, sp, #0xc
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081753EC @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_081753D6:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #3
	ble _081753D6
	b _08175490
	.align 2, 0
_081753E8: .4byte 0x00000484
_081753EC: .4byte 0x05000002
_081753F0:
	cmp r0, #0x13
	bgt _08175420
	add r4, sp, #0x14
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0817541C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_08175408:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08175408
	b _08175490
	.align 2, 0
_0817541C: .4byte 0x05000002
_08175420:
	cmp r0, #0x3b
	bgt _08175450
	add r4, sp, #0x1c
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0817544C @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_08175438:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08175438
	b _08175490
	.align 2, 0
_0817544C: .4byte 0x05000002
_08175450:
	cmp r0, #0x4f
	bgt _08175490
	add r4, sp, #0x24
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08175478 @ =0x05000002
	bl CpuSet
	movs r5, #0
_08175464:
	cmp r5, #3
	bgt _0817547C
	movs r0, #0x54
	strh r0, [r4, #2]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	b _0817548A
	.align 2, 0
_08175478: .4byte 0x05000002
_0817547C:
	movs r0, #0x94
	strh r0, [r4, #2]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
_0817548A:
	adds r5, #1
	cmp r5, #7
	ble _08175464
_08175490:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r6, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	ldr r2, _08175504 @ =0x00000472
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081754B8
	ldr r0, [r6, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081754B8:
	adds r0, r7, #0
	bl FUN_08176c60
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc
	bgt _08175514
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x15
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08175508 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0817550C @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _08175510 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0817551E
	.align 2, 0
_08175504: .4byte 0x00000472
_08175508: .4byte 0x00000469
_0817550C: .4byte 0x0000046A
_08175510: .4byte 0x00000484
_08175514:
	ldr r4, _08175528 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817551E:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175528: .4byte 0x00000484

	thumb_func_start FUN_0817552c
FUN_0817552c: @ 0x0817552C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r6, _0817554C @ =0x0000046C
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175550
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08175552
	.align 2, 0
_0817554C: .4byte 0x0000046C
_08175550:
	movs r0, #0
_08175552:
	cmp r0, #0
	beq _08175590
	ldr r0, _08175584 @ =0x00001008
	adds r2, r2, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08175588 @ =0x00000474
	adds r2, r5, r1
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0817558C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08175670
	.align 2, 0
_08175584: .4byte 0x00001008
_08175588: .4byte 0x00000474
_0817558C: .4byte 0xFFEFFFFF
_08175590:
	ldr r1, _081755AC @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x46
	beq _081755D4
	cmp r0, #0x46
	bgt _081755B6
	cmp r0, #0x1e
	beq _081755D4
	cmp r0, #0x1e
	bgt _081755B0
	cmp r0, #0xa
	beq _081755CE
	b _081755DA
	.align 2, 0
_081755AC: .4byte 0x00000484
_081755B0:
	cmp r0, #0x32
	beq _081755D4
	b _081755DA
_081755B6:
	cmp r0, #0x5a
	beq _081755D4
	cmp r0, #0x5a
	bgt _081755C4
	cmp r0, #0x50
	beq _081755D4
	b _081755DA
_081755C4:
	cmp r0, #0x5f
	beq _081755D4
	cmp r0, #0x64
	beq _081755D4
	b _081755DA
_081755CE:
	ldr r0, _0817564C @ =0x000001C5
	bl PlaySound_082406e0
_081755D4:
	adds r0, r5, #0
	bl FUN_08178470
_081755DA:
	ldr r2, _08175650 @ =0x00000484
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0x1f
	bne _081755EA
	ldr r0, _08175654 @ =0x000003D9
	bl PlaySound_082406e0
_081755EA:
	ldr r3, _08175658 @ =0x00002EE0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	ldr r0, [r4]
	cmp r0, #0x78
	ble _0817566C
	ldr r3, _0817565C @ =FUN_0817258c
	movs r1, #0x11
	ldr r6, _08175660 @ =0x0000046D
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
	ldr r1, _08175664 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08175668 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _08175670
	.align 2, 0
_0817564C: .4byte 0x000001C5
_08175650: .4byte 0x00000484
_08175654: .4byte 0x000003D9
_08175658: .4byte 0x00002EE0
_0817565C: .4byte FUN_0817258c
_08175660: .4byte 0x0000046D
_08175664: .4byte 0x00000469
_08175668: .4byte 0x0000046C
_0817566C:
	adds r0, #1
	str r0, [r4]
_08175670:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08175678
FUN_08175678: @ 0x08175678
	ldr r1, _08175684 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08175688 @ =0x085ADAE4
	str r1, [r0]
	bx lr
	.align 2, 0
_08175684: .4byte 0x00000634
_08175688: .4byte 0x085ADAE4

	thumb_func_start FUN_0817568c
FUN_0817568c: @ 0x0817568C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081756D6
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _081756B8 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081756BC
	movs r0, #1
	b _081756BE
	.align 2, 0
_081756B8: .4byte 0x00001008
_081756BC:
	movs r0, #0
_081756BE:
	cmp r0, #0
	bne _081756D6
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081756DC @ =0x00000FAA
	adds r1, r1, r2
	ldrh r0, [r5]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_081756D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081756DC: .4byte 0x00000FAA

	thumb_func_start FUN_081756e0
FUN_081756e0: @ 0x081756E0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081756F2
	b _08175858
_081756F2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r1, #0x20
	ldr r2, _0817570C @ =0x00001008
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08175710
	movs r0, #1
	b _08175712
	.align 2, 0
_0817570C: .4byte 0x00001008
_08175710:
	movs r0, #0
_08175712:
	adds r5, r0, #0
	cmp r5, #0
	beq _0817571A
	b _08175858
_0817571A:
	ldr r3, _08175794 @ =0x00000FAA
	adds r0, r7, r3
	ldrh r2, [r0]
	cmp r2, #0
	bne _08175730
	ldr r6, _08175798 @ =0x0000048A
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08175730
	b _08175848
_08175730:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r3, #0
	strh r0, [r1]
	movs r2, #0
	ldrsh r6, [r1, r2]
	ldr r0, _08175798 @ =0x0000048A
	adds r2, r4, r0
	ldrh r0, [r2]
	subs r0, r6, r0
	cmp r0, #0
	bgt _08175830
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
	adds r6, #5
	adds r0, r4, r6
	strb r3, [r0]
	ldr r6, _0817579C @ =0x0000048C
	adds r0, r4, r6
	strb r3, [r0]
	strh r5, [r2]
	ldr r2, _081757A0 @ =0x000004BE
	adds r0, r4, r2
	strh r5, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0x20
	ldr r6, _081757A4 @ =0x00001008
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0x84
	adds r0, r7, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081757A8
	movs r0, #1
	b _081757AA
	.align 2, 0
_08175794: .4byte 0x00000FAA
_08175798: .4byte 0x0000048A
_0817579C: .4byte 0x0000048C
_081757A0: .4byte 0x000004BE
_081757A4: .4byte 0x00001008
_081757A8:
	movs r0, #0
_081757AA:
	adds r5, r0, #0
	cmp r5, #0
	bne _08175800
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _0817581C @ =0x0000046D
	adds r0, r4, r3
	strb r2, [r0]
	ldr r6, _08175820 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r3, #0xe6
	adds r0, r4, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r3, #0xd
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08175824 @ =0x0000046A
	adds r0, r4, r1
	strb r3, [r0]
	ldr r3, _08175828 @ =0x00000484
	adds r0, r4, r3
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r2, [r0]
_08175800:
	ldrh r0, [r4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldr r3, _0817582C @ =0x0000025A
	adds r1, r4, r3
	ldrh r3, [r1]
	movs r1, #0
	str r1, [sp]
	bl FUN_0809c344
	b _08175848
	.align 2, 0
_0817581C: .4byte 0x0000046D
_08175820: .4byte 0x0000046B
_08175824: .4byte 0x0000046A
_08175828: .4byte 0x00000484
_0817582C: .4byte 0x0000025A
_08175830:
	ldrh r0, [r4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldr r3, _08175860 @ =0x0000025A
	adds r1, r4, r3
	ldrh r3, [r1]
	str r5, [sp]
	adds r1, r6, #0
	bl FUN_0809c344
_08175848:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08175864 @ =0x00000FAA
	adds r0, r7, r2
	strh r1, [r0]
_08175858:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175860: .4byte 0x0000025A
_08175864: .4byte 0x00000FAA

	thumb_func_start FUN_08175868
FUN_08175868: @ 0x08175868
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0817588C
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _08175890
_0817588C:
	str r1, [r3]
	movs r0, #0
_08175890:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08175898
FUN_08175898: @ 0x08175898
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r2, [sp, #0x20]
	ldr r3, _081758F8 @ =0x000004A4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	str r0, [sp, #0x2c]
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0xc
_081758CC:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _081758CC
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x24]
	movs r2, #0x81
	lsls r2, r2, #5
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #2
	bne _081758FC
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0817592A
	.align 2, 0
_081758F8: .4byte 0x000004A4
_081758FC:
	cmp r3, #3
	bne _08175928
	ldr r2, _0817591C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08175920 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08175924 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0x2c]
	adds r6, r1, r0
	ands r6, r3
	b _0817592A
	.align 2, 0
_0817591C: .4byte 0x030046B8
_08175920: .4byte 0x000003FF
_08175924: .4byte 0x0203B400
_08175928:
	ldr r6, [sp, #0x2c]
_0817592A:
	ldr r2, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r3, r2, r4
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _08175956
	ldr r1, [sp, #0x20]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r4, [sp, #0x24]
	ldr r2, _08175990 @ =0x00001021
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_08175956:
	movs r3, #3
	str r3, [sp, #0x30]
_0817595A:
	ldr r4, [sp, #0x24]
	ldr r1, _08175990 @ =0x00001021
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _0817596A
	rsbs r0, r0, #0
_0817596A:
	cmp r0, #2
	bne _08175970
	b _08175D0E
_08175970:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _0817597A
	rsbs r0, r0, #0
_0817597A:
	cmp r0, #2
	bne _08175980
	b _08175D0E
_08175980:
	cmp r6, #1
	beq _081759B0
	cmp r6, #1
	bgt _08175994
	cmp r6, #0
	beq _0817599E
	b _08175A04
	.align 2, 0
_08175990: .4byte 0x00001021
_08175994:
	cmp r6, #2
	beq _081759D0
	cmp r6, #3
	beq _081759E4
	b _08175A04
_0817599E:
	ldr r3, [sp, #0x20]
	ldr r4, _081759AC @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759AC: .4byte 0x00000256
_081759B0:
	ldr r0, [sp, #0x20]
	ldr r2, _081759C8 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _081759CC @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759C8: .4byte 0x00000256
_081759CC: .4byte 0x030046A4
_081759D0:
	ldr r3, [sp, #0x20]
	ldr r4, _081759E0 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759E0: .4byte 0x00000256
_081759E4:
	ldr r0, [sp, #0x20]
	ldr r2, _081759FC @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _08175A00 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759FC: .4byte 0x00000256
_08175A00: .4byte 0x030046A4
_08175A04:
	ldr r1, [sp, #0x20]
	ldr r2, _08175A20 @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08175A0E:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175A24
	adds r0, #4
	b _08175A30
	.align 2, 0
_08175A20: .4byte 0x00000256
_08175A24:
	ldr r3, _08175A4C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A30:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175A50
	adds r0, #4
	b _08175A5C
	.align 2, 0
_08175A4C: .4byte 0x030046A4
_08175A50:
	ldr r1, _08175A74 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A5C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175A78
	adds r0, #4
	b _08175A84
	.align 2, 0
_08175A74: .4byte 0x030046A4
_08175A78:
	ldr r2, _08175AC8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A84:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _08175AC8 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175ACC
	adds r0, #4
	b _08175AD8
	.align 2, 0
_08175AC8: .4byte 0x030046A4
_08175ACC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175AD8:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x10
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175AFC
	adds r0, #4
	b _08175B08
_08175AFC:
	ldr r1, _08175B1C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175B08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08175B20
	cmp r2, #2
	beq _08175B24
	b _08175B28
	.align 2, 0
_08175B1C: .4byte 0x030046A4
_08175B20:
	ldrb r0, [r4, #4]
	b _08175B26
_08175B24:
	ldrb r0, [r4]
_08175B26:
	subs r1, r1, r0
_08175B28:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _08175B70 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08175B70 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175B74
	adds r0, #4
	b _08175B80
	.align 2, 0
_08175B70: .4byte 0x030046A4
_08175B74:
	ldr r3, _08175BAC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175B80:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r4, sb
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175BB0
	adds r0, #4
	b _08175BBC
	.align 2, 0
_08175BAC: .4byte 0x030046A4
_08175BB0:
	ldr r3, _08175BD0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175BBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08175BD4
	cmp r2, #2
	beq _08175BD8
	b _08175BDC
	.align 2, 0
_08175BD0: .4byte 0x030046A4
_08175BD4:
	ldrb r0, [r5, #4]
	b _08175BDA
_08175BD8:
	ldrb r0, [r5]
_08175BDA:
	subs r1, r1, r0
_08175BDC:
	ldr r4, [sp, #0x44]
	subs r2, r4, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x40]
	ands r3, r0
	cmp r3, #0
	beq _08175BFC
	b _08175D0E
_08175BFC:
	cmp r2, #0
	beq _08175CF2
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _08175C22
	cmp r6, #1
	bne _08175C1A
	mov r0, sl
	cmp r0, #1
	bne _08175C3C
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08175C4E
	b _08175D0E
_08175C1A:
	cmp r6, #3
	bne _08175D0E
	mov r4, sl
	b _08175C48
_08175C22:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _08175C4E
	cmp r6, #0
	bne _08175C42
	mov r3, sl
	cmp r3, #2
	bne _08175C3C
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08175C4E
	b _08175D0E
_08175C3C:
	cmp r1, #0
	beq _08175C4E
	b _08175D0E
_08175C42:
	cmp r6, #2
	bne _08175D0E
	mov r0, sl
_08175C48:
	ldr r0, _08175C64 @ =0xFFFFFF00
	cmp r1, r0
	bne _08175D0E
_08175C4E:
	mov r3, sl
	cmp r3, #1
	bne _08175C7E
	cmp r6, #1
	bne _08175C72
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _08175C68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08175CAA
	.align 2, 0
_08175C64: .4byte 0xFFFFFF00
_08175C68:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08175CB8
	b _08175D0E
_08175C72:
	cmp r6, #3
	bne _08175D0E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _08175CA8
	b _08175CB4
_08175C7E:
	mov r0, sl
	cmp r0, #2
	bne _08175CC4
	cmp r6, #0
	bne _08175C9E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08175C98
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08175CB8
	b _08175D0E
_08175C98:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08175CAA
_08175C9E:
	cmp r6, #2
	bne _08175D0E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08175CB4
_08175CA8:
	ldr r0, _08175CB0 @ =0xFFFFFF00
_08175CAA:
	cmp r1, r0
	beq _08175CB8
	b _08175D0E
	.align 2, 0
_08175CB0: .4byte 0xFFFFFF00
_08175CB4:
	cmp r1, #0
	bne _08175D0E
_08175CB8:
	mov r4, sl
	cmp r4, #2
	bne _08175CC4
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _08175CD0
_08175CC4:
	mov r1, sl
	cmp r1, #1
	bne _08175CE2
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _08175CE2
_08175CD0:
	adds r0, r2, #0
	cmp r2, #0
	bge _08175CD8
	rsbs r0, r2, #0
_08175CD8:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _08175CF2
	b _08175D0E
_08175CE2:
	adds r0, r2, #0
	cmp r0, #0
	bge _08175CEA
	rsbs r0, r0, #0
_08175CEA:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08175CF4
_08175CF2:
	adds r5, r7, #0
_08175CF4:
	cmp r5, #0
	blt _08175D0E
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _08175D02
	str r5, [sp, #0x38]
	b _08175D0E
_08175D02:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_08175D0E:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _08175D20
	b _0817595A
_08175D20:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _08175D28
	b _08175E7C
_08175D28:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _08175DD6
	mov r6, sp
_08175D38:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_081794e0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08175DC8
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _08175D84 @ =0x030046A4
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
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175D88
	adds r0, #4
	b _08175D92
	.align 2, 0
_08175D84: .4byte 0x030046A4
_08175D88:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175D92:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_08179510
	ldr r3, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08175DC4 @ =0x0000101C
	adds r1, r3, r0
	b _08176306
	.align 2, 0
_08175DC4: .4byte 0x0000101C
_08175DC8:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _08175D38
_08175DD6:
	ldr r2, _08175E34 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08175E38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08175E3C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _08175E40 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
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
	ldr r3, [sp, #0x28]
	strh r4, [r3, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175E44
	adds r0, #4
	b _08175E4E
	.align 2, 0
_08175E34: .4byte 0x030046B8
_08175E38: .4byte 0x000003FF
_08175E3C: .4byte 0x0203B400
_08175E40: .4byte 0x030046A4
_08175E44:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175E4E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, r8
	strh r0, [r4, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #2
	add r0, sp
	ldr r1, [r0]
	ldr r0, [sp, #0x20]
	bl FUN_08179510
	ldr r2, [sp, #0x24]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08176300
_08175E7C:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _08175F10
	ldr r0, [sp, #0x20]
	bl FUN_081794e0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08175F10
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _08175ED0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r0, [sp, #0x38]
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x38]
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	ldr r0, [sp, #0x38]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175ED4
	adds r0, #4
	b _08175EE0
	.align 2, 0
_08175ED0: .4byte 0x030046A4
_08175ED4:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175EE0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x38]
	bl FUN_08179510
	ldr r3, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _08175F0C @ =0x0000101C
	adds r1, r3, r0
	b _08176306
	.align 2, 0
_08175F0C: .4byte 0x0000101C
_08175F10:
	ldr r1, [sp, #0x24]
	ldr r2, _08175F2C @ =0x00001021
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _08175F4C
	cmp r6, #1
	bgt _08175F30
	cmp r6, #0
	beq _08175F3A
	b _08175FA0
	.align 2, 0
_08175F2C: .4byte 0x00001021
_08175F30:
	cmp r6, #2
	beq _08175F6C
	cmp r6, #3
	beq _08175F80
	b _08175FA0
_08175F3A:
	ldr r3, [sp, #0x20]
	ldr r4, _08175F48 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F48: .4byte 0x00000256
_08175F4C:
	ldr r0, [sp, #0x20]
	ldr r2, _08175F64 @ =0x00000256
	adds r1, r0, r2
	ldr r0, _08175F68 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F64: .4byte 0x00000256
_08175F68: .4byte 0x030046A4
_08175F6C:
	ldr r0, [sp, #0x20]
	ldr r2, _08175F7C @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F7C: .4byte 0x00000256
_08175F80:
	ldr r3, [sp, #0x20]
	ldr r4, _08175F98 @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _08175F9C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F98: .4byte 0x00000256
_08175F9C: .4byte 0x030046A4
_08175FA0:
	ldr r4, [sp, #0x20]
	ldr r1, _08175FBC @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08175FAA:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175FC0
	adds r0, #4
	b _08175FCC
	.align 2, 0
_08175FBC: .4byte 0x00000256
_08175FC0:
	ldr r0, _08175FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08175FCC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08175FEC
	adds r0, #4
	b _08175FF8
	.align 2, 0
_08175FE8: .4byte 0x030046A4
_08175FEC:
	ldr r0, _08176010 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08175FF8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08176014
	adds r0, #4
	b _08176020
	.align 2, 0
_08176010: .4byte 0x030046A4
_08176014:
	ldr r0, _08176064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176020:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _08176064 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x4c]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08176068
	adds r0, #4
	b _08176074
	.align 2, 0
_08176064: .4byte 0x030046A4
_08176068:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08176074:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	ldr r4, [sp, #0x4c]
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x18
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08176098
	adds r0, #4
	b _081760A4
_08176098:
	ldr r2, _081760B8 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081760A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081760BC
	cmp r2, #2
	beq _081760C0
	b _081760C4
	.align 2, 0
_081760B8: .4byte 0x030046A4
_081760BC:
	ldrb r0, [r4, #4]
	b _081760C2
_081760C0:
	ldrb r0, [r4]
_081760C2:
	subs r1, r1, r0
_081760C4:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _0817610C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0817610C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08176110
	adds r0, #4
	b _0817611C
	.align 2, 0
_0817610C: .4byte 0x030046A4
_08176110:
	ldr r3, _08176148 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817611C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r4, [sp, #0x54]
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817614C
	adds r0, #4
	b _08176158
	.align 2, 0
_08176148: .4byte 0x030046A4
_0817614C:
	ldr r0, _0817616C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176158:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08176170
	cmp r2, #2
	beq _08176174
	b _08176178
	.align 2, 0
_0817616C: .4byte 0x030046A4
_08176170:
	ldrb r0, [r5, #4]
	b _08176176
_08176174:
	ldrb r0, [r5]
_08176176:
	subs r1, r1, r0
_08176178:
	ldr r3, [sp, #0x50]
	subs r2, r3, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r4, [sp, #0x48]
	ands r4, r0
	cmp r4, #0
	beq _08176198
	b _08176310
_08176198:
	cmp r2, #0
	beq _08176286
	mov r0, sl
	cmp r0, #1
	bne _081761BA
	cmp r6, #1
	bne _081761B2
	mov r3, sb
	cmp r3, #1
	bne _081761D0
	movs r0, #0x80
	lsls r0, r0, #1
	b _081761E0
_081761B2:
	cmp r6, #3
	beq _081761B8
	b _08176310
_081761B8:
	b _081761DC
_081761BA:
	mov r0, sl
	cmp r0, #2
	bne _081761E6
	cmp r6, #0
	bne _081761D6
	mov r3, sb
	cmp r3, #2
	bne _081761D0
	movs r0, #0x80
	lsls r0, r0, #1
	b _081761E0
_081761D0:
	cmp r1, #0
	beq _081761E6
	b _08176310
_081761D6:
	cmp r6, #2
	beq _081761DC
	b _08176310
_081761DC:
	mov r4, sb
	ldr r0, _081761FC @ =0xFFFFFF00
_081761E0:
	cmp r1, r0
	beq _081761E6
	b _08176310
_081761E6:
	mov r0, sb
	cmp r0, #1
	bne _08176214
	cmp r6, #1
	bne _08176206
	mov r3, sl
	cmp r3, #1
	bne _08176200
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
	.align 2, 0
_081761FC: .4byte 0xFFFFFF00
_08176200:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_08176206:
	cmp r6, #3
	beq _0817620C
	b _08176310
_0817620C:
	mov r4, sl
	cmp r4, #1
	beq _0817623A
	b _08176248
_08176214:
	mov r0, sb
	cmp r0, #2
	bne _08176258
	cmp r6, #0
	bne _08176230
	mov r3, sl
	cmp r3, #2
	bne _0817622A
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_0817622A:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_08176230:
	cmp r6, #2
	bne _08176310
	mov r4, sl
	cmp r4, #2
	bne _08176248
_0817623A:
	ldr r0, _08176244 @ =0xFFFFFF00
_0817623C:
	cmp r1, r0
	beq _0817624C
	b _08176310
	.align 2, 0
_08176244: .4byte 0xFFFFFF00
_08176248:
	cmp r1, #0
	bne _08176310
_0817624C:
	mov r0, sb
	cmp r0, #2
	bne _08176258
	mov r1, sl
	cmp r1, #2
	beq _08176264
_08176258:
	mov r3, sb
	cmp r3, #1
	bne _08176276
	mov r4, sl
	cmp r4, #1
	bne _08176276
_08176264:
	adds r1, r2, #0
	cmp r2, #0
	bge _0817626C
	rsbs r1, r2, #0
_0817626C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _08176286
	b _08176310
_08176276:
	adds r0, r2, #0
	cmp r0, #0
	bge _0817627E
	rsbs r0, r0, #0
_0817627E:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08176288
_08176286:
	adds r5, r7, #0
_08176288:
	cmp r5, #0
	blt _08176310
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _081762CC @ =0x030046A4
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
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081762D0
	adds r0, #4
	b _081762DA
	.align 2, 0
_081762CC: .4byte 0x030046A4
_081762D0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081762DA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, [sp, #0x20]
	adds r1, r5, #0
	bl FUN_08179510
	ldr r2, [sp, #0x24]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_08176300:
	strb r0, [r1]
	ldr r4, _0817630C @ =0x0000101C
	adds r1, r2, r4
_08176306:
	movs r0, #0x28
	strh r0, [r1]
	b _08176320
	.align 2, 0
_0817630C: .4byte 0x0000101C
_08176310:
	ldr r1, [sp, #0x24]
	ldr r2, _08176330 @ =0x00001021
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_08176320:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08176330: .4byte 0x00001021

	thumb_func_start FUN_08176334
FUN_08176334: @ 0x08176334
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _08176350 @ =0x0000100B
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08176354
	subs r0, #1
	strb r0, [r1]
	b _08176398
	.align 2, 0
_08176350: .4byte 0x0000100B
_08176354:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _081763A0 @ =0x00001012
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r5
	ldr r0, _081763A4 @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_081775d8
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _081763A4 @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_081775d8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_081775d8
_08176398:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081763A0: .4byte 0x00001012
_081763A4: .4byte 0x00000674

	thumb_func_start FUN_081763a8
FUN_081763a8: @ 0x081763A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0817647C @ =0x00001012
	adds r4, r6, r2
	movs r0, #8
	strh r0, [r4]
	movs r1, #8
	adds r2, #0x10
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _08176480 @ =0x00001024
	adds r1, r6, r0
	ldr r0, _08176484 @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _08176488 @ =0x00001023
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	mov r8, r0
	movs r7, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r7, r0
	blt _08176408
	b _0817651C
_08176408:
	movs r2, #0
	mov sl, r2
	movs r0, #0
	str r0, [sp, #0x1c]
	movs r1, #0xe8
	lsls r1, r1, #3
	adds r4, r6, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _0817648C @ =0x00000684
	adds r5, r6, r0
_08176422:
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	bl Video_GetActorSprite
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0xd1
	lsls r1, r1, #1
	bl FUN_0822b20c
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _08176490 @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x10]
	ldr r2, _0817647C @ =0x00001012
	adds r0, r6, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp r7, r0
	bne _08176494
	mov r0, sl
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	movs r3, #0
	bl FUN_08236fac
	movs r0, #4
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _081764DC
	.align 2, 0
_0817647C: .4byte 0x00001012
_08176480: .4byte 0x00001024
_08176484: .4byte 0x7FFFFFFF
_08176488: .4byte 0x00001023
_0817648C: .4byte 0x00000684
_08176490: .4byte 0x0000922E
_08176494:
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_08175868
	cmp r7, #2
	bgt _081764A8
	movs r3, #0
	movs r0, #0x20
	b _081764B6
_081764A8:
	cmp r7, #4
	bgt _081764B2
	movs r3, #1
	movs r0, #0x10
	b _081764B6
_081764B2:
	movs r3, #2
	movs r0, #8
_081764B6:
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	ldr r1, [r4, #0x10]
	mov r2, sl
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08236fac
	mov r0, r8
	strh r0, [r4, #8]
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #3
	ble _081764DC
	movs r0, #0
	mov r8, r0
_081764DC:
	str r6, [r4, #0x34]
	mov r1, sl
	strh r1, [r4, #0x38]
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bne _081764F8
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1a]
	movs r0, #2
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _081764FE
_081764F8:
	ldr r1, [sp, #0x18]
	adds r1, #1
	str r1, [sp, #0x18]
_081764FE:
	ldr r2, [sp, #0x1c]
	adds r2, #0x18
	str r2, [sp, #0x1c]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	add sb, r0
	adds r5, r5, r0
	adds r7, #1
	ldr r1, _0817652C @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	blt _08176422
_0817651C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817652C: .4byte 0x00001012

	thumb_func_start FUN_08176530
FUN_08176530: @ 0x08176530
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #0
	cmp r4, r6
	bge _081765E2
	movs r0, #1
	mov r8, r0
	movs r7, #0
_08176548:
	adds r1, r4, #0
	mov r0, r8
	ands r1, r0
	cmp r1, #0
	beq _0817659C
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x38
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r7, [sp, #0x20]
	ldr r0, _08176594 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _08176598 @ =0x0000121B
	str r0, [sp, #0x28]
	str r7, [sp, #0x2c]
	str r7, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #8
	movs r3, #4
	bl FUN_081ee53c
	b _081765DC
	.align 2, 0
_08176594: .4byte 0x0000F422
_08176598: .4byte 0x0000121B
_0817659C:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x38
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r0, _081765F0 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081765F4 @ =0x0000121B
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #8
	movs r3, #4
	bl FUN_081ee53c
_081765DC:
	adds r4, #1
	cmp r4, r6
	blt _08176548
_081765E2:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081765F0: .4byte 0x0000F422
_081765F4: .4byte 0x0000121B

	thumb_func_start FUN_081765f8
FUN_081765f8: @ 0x081765F8
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	movs r1, #0x10
	ldr r2, _08176618 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817661C
	movs r0, #1
	b _0817661E
	.align 2, 0
_08176618: .4byte 0x00001008
_0817661C:
	movs r0, #0
_0817661E:
	cmp r0, #0
	beq _08176682
	mov r3, sp
	adds r2, r5, #0
	adds r2, #8
	ldr r0, _0817668C @ =0x00000F8C
	adds r4, r4, r0
	ldrh r0, [r4]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08176690 @ =0x00002EE0
	cmp r1, r0
	ble _08176682
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, _08176694 @ =0x00000472
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r3, #2]
	mov r0, sp
	movs r1, #0xc
	bl FUN_081f7740
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
_08176682:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817668C: .4byte 0x00000F8C
_08176690: .4byte 0x00002EE0
_08176694: .4byte 0x00000472

	thumb_func_start FUN_08176698
FUN_08176698: @ 0x08176698
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	mov sb, r1
	ldr r2, _081766DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081766E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081766E4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0x28
	ldr r1, _081766E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081766EC
	asrs r1, r0, #0xc
	b _081766F2
	.align 2, 0
_081766DC: .4byte 0x030046B8
_081766E0: .4byte 0x000003FF
_081766E4: .4byte 0x0203B400
_081766E8: .4byte 0x085B0A08
_081766EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081766F2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0817670C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08176710
	asrs r0, r0, #0xc
	b _08176716
	.align 2, 0
_0817670C: .4byte 0x085B0A08
_08176710:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08176716:
	movs r7, #0
	strh r0, [r4, #4]
	ldr r5, _08176788 @ =0x0203B400
	ldr r4, _0817678C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08176790 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x3f
	ands r0, r2
	adds r0, #0x14
	add r2, sp, #0x2c
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrb r0, [r1]
	cmp r0, #0x7f
	bgt _081767A4
	ldr r2, _08176794 @ =0x00009D41
	ldr r3, _08176798 @ =0x0000E677
	movs r1, #1
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _0817679C @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _081767A0 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
	b _081767E4
	.align 2, 0
_08176788: .4byte 0x0203B400
_0817678C: .4byte 0x030046B8
_08176790: .4byte 0x000003FF
_08176794: .4byte 0x00009D41
_08176798: .4byte 0x0000E677
_0817679C: .4byte 0x0000023D
_081767A0: .4byte 0x0000022A
_081767A4:
	ldr r2, _08176828 @ =0x00009D41
	ldr r3, _0817682C @ =0x0000E677
	movs r0, #1
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176830 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r1, _08176834 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
_081767E4:
	movs r7, #0
	ldr r5, _08176838 @ =0x030046B8
	movs r2, #0xff
	mov r8, r2
	add r4, sp, #0x2c
	movs r0, #0xa
	mov sl, r0
_081767F2:
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0817683C @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176840 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	mov r2, r8
	ands r3, r2
	ldr r1, _08176844 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08176848
	asrs r1, r0, #0xc
	b _0817684E
	.align 2, 0
_08176828: .4byte 0x00009D41
_0817682C: .4byte 0x0000E677
_08176830: .4byte 0x0000023D
_08176834: .4byte 0x0000022A
_08176838: .4byte 0x030046B8
_0817683C: .4byte 0x000003FF
_08176840: .4byte 0x0203B400
_08176844: .4byte 0x085B0A08
_08176848:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817684E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _08176870 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08176874
	asrs r0, r0, #0xc
	b _0817687A
	.align 2, 0
_08176870: .4byte 0x085B0A08
_08176874:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817687A:
	movs r2, #0
	strh r0, [r4, #4]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081768E8 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _081768EC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	adds r1, #0x20
	add r0, sp, #0x2c
	strh r1, [r0, #2]
	movs r3, #1
	adds r1, r7, #0
	ands r1, r3
	cmp r1, #0
	beq _08176904
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, _081768F0 @ =0x0000023D
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r2, _081768F4 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _081768F8 @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _081768FC @ =0x00009D41
	ldr r3, _08176900 @ =0x0000E677
	bl FUN_081ef708
	b _08176944
	.align 2, 0
_081768E8: .4byte 0x000003FF
_081768EC: .4byte 0x0203B400
_081768F0: .4byte 0x0000023D
_081768F4: .4byte 0x0000022A
_081768F8: .4byte 0x00000232
_081768FC: .4byte 0x00009D41
_08176900: .4byte 0x0000E677
_08176904:
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _08176964 @ =0x0000023D
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08176968 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _0817696C @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _08176970 @ =0x00009D41
	ldr r3, _08176974 @ =0x0000E677
	bl FUN_081ef708
_08176944:
	adds r7, #1
	cmp r7, #1
	bgt _0817694C
	b _081767F2
_0817694C:
	ldr r0, _08176978 @ =0x000003E2
	bl PlaySound_082406e0
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08176964: .4byte 0x0000023D
_08176968: .4byte 0x0000022A
_0817696C: .4byte 0x00000232
_08176970: .4byte 0x00009D41
_08176974: .4byte 0x0000E677
_08176978: .4byte 0x000003E2

	thumb_func_start FUN_0817697c
FUN_0817697c: @ 0x0817697C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	mov sb, r1
	ldr r2, _081769C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081769C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081769C8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081769CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081769D0
	asrs r1, r0, #0xc
	b _081769D6
	.align 2, 0
_081769C0: .4byte 0x030046B8
_081769C4: .4byte 0x000003FF
_081769C8: .4byte 0x0203B400
_081769CC: .4byte 0x085B0A08
_081769D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081769D6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081769F0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081769F4
	asrs r0, r0, #0xc
	b _081769FA
	.align 2, 0
_081769F0: .4byte 0x085B0A08
_081769F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081769FA:
	movs r7, #0
	strh r0, [r4, #4]
	ldr r5, _08176A6C @ =0x0203B400
	ldr r4, _08176A70 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08176A74 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x3f
	ands r0, r2
	adds r0, #0x2a
	add r2, sp, #0x2c
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrb r0, [r1]
	cmp r0, #0x7f
	bgt _08176A88
	ldr r2, _08176A78 @ =0x00009D41
	ldr r3, _08176A7C @ =0x0000E677
	movs r1, #1
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176A80 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _08176A84 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
	b _08176AC8
	.align 2, 0
_08176A6C: .4byte 0x0203B400
_08176A70: .4byte 0x030046B8
_08176A74: .4byte 0x000003FF
_08176A78: .4byte 0x00009D41
_08176A7C: .4byte 0x0000E677
_08176A80: .4byte 0x0000023D
_08176A84: .4byte 0x0000022A
_08176A88:
	ldr r2, _08176B0C @ =0x00009D41
	ldr r3, _08176B10 @ =0x0000E677
	movs r0, #1
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176B14 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r1, _08176B18 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl FUN_081ef708
_08176AC8:
	movs r7, #0
	ldr r5, _08176B1C @ =0x030046B8
	movs r2, #0xff
	mov r8, r2
	add r4, sp, #0x2c
	movs r0, #0xa
	mov sl, r0
_08176AD6:
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08176B20 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176B24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	mov r2, r8
	ands r3, r2
	ldr r1, _08176B28 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08176B2C
	asrs r1, r0, #0xc
	b _08176B32
	.align 2, 0
_08176B0C: .4byte 0x00009D41
_08176B10: .4byte 0x0000E677
_08176B14: .4byte 0x0000023D
_08176B18: .4byte 0x0000022A
_08176B1C: .4byte 0x030046B8
_08176B20: .4byte 0x000003FF
_08176B24: .4byte 0x0203B400
_08176B28: .4byte 0x085B0A08
_08176B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08176B32:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _08176B54 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08176B58
	asrs r0, r0, #0xc
	b _08176B5E
	.align 2, 0
_08176B54: .4byte 0x085B0A08
_08176B58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08176B5E:
	movs r2, #0
	strh r0, [r4, #4]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08176BCC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176BD0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	adds r1, #0x20
	add r0, sp, #0x2c
	strh r1, [r0, #2]
	movs r3, #1
	adds r1, r7, #0
	ands r1, r3
	cmp r1, #0
	beq _08176BE8
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, _08176BD4 @ =0x0000023D
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r2, _08176BD8 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08176BDC @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _08176BE0 @ =0x00009D41
	ldr r3, _08176BE4 @ =0x0000E677
	bl FUN_081ef708
	b _08176C28
	.align 2, 0
_08176BCC: .4byte 0x000003FF
_08176BD0: .4byte 0x0203B400
_08176BD4: .4byte 0x0000023D
_08176BD8: .4byte 0x0000022A
_08176BDC: .4byte 0x00000232
_08176BE0: .4byte 0x00009D41
_08176BE4: .4byte 0x0000E677
_08176BE8:
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _08176C48 @ =0x0000023D
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r2, _08176C4C @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08176C50 @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _08176C54 @ =0x00009D41
	ldr r3, _08176C58 @ =0x0000E677
	bl FUN_081ef708
_08176C28:
	adds r7, #1
	cmp r7, #2
	bgt _08176C30
	b _08176AD6
_08176C30:
	ldr r0, _08176C5C @ =0x000003E2
	bl PlaySound_082406e0
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08176C48: .4byte 0x0000023D
_08176C4C: .4byte 0x0000022A
_08176C50: .4byte 0x00000232
_08176C54: .4byte 0x00009D41
_08176C58: .4byte 0x0000E677
_08176C5C: .4byte 0x000003E2

	thumb_func_start FUN_08176c60
FUN_08176c60: @ 0x08176C60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp, #8]
	ldr r2, _08176CA4 @ =0x00001012
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _08176C84
	b _08176DDC
_08176C84:
	mov sl, r7
	movs r2, #0
	str r2, [sp, #0xc]
	ldr r0, _08176CA8 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _08176CAC @ =0x00000755
	adds r1, r1, r7
	mov sb, r1
_08176C94:
	movs r1, #1
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08176CB0
	movs r0, #1
	b _08176CB2
	.align 2, 0
_08176CA4: .4byte 0x00001012
_08176CA8: .4byte 0x00000674
_08176CAC: .4byte 0x00000755
_08176CB0:
	movs r0, #0
_08176CB2:
	cmp r0, #0
	beq _08176CB8
	b _08176DB6
_08176CB8:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08176CDC
	cmp r1, #0
	blt _08176CDC
	ldr r0, _08176CE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08176CDC
	ldr r0, _08176CE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08176CE8
_08176CDC:
	movs r4, #0
	b _08176CF6
	.align 2, 0
_08176CE0: .4byte 0x030046A8
_08176CE4: .4byte 0x030046AC
_08176CE8:
	ldr r0, _08176D08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08176CF6:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08176D0C
	adds r0, #4
	b _08176D18
	.align 2, 0
_08176D08: .4byte 0x030046A4
_08176D0C:
	ldr r0, _08176D2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176D18:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08176D30
	cmp r3, #2
	beq _08176D34
	b _08176D38
	.align 2, 0
_08176D2C: .4byte 0x030046A4
_08176D30:
	ldrb r0, [r5, #4]
	b _08176D36
_08176D34:
	ldrb r0, [r5]
_08176D36:
	subs r2, r2, r0
_08176D38:
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _08176D80
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [sp, #0xc]
	adds r3, r0, r1
	ldr r1, [r3]
	movs r4, #1
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	bne _08176D76
	orrs r1, r4
	str r1, [r3]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp]
	str r1, [sp, #4]
	lsls r2, r2, #0x10
	ldr r1, _08176D7C @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	movs r1, #2
	bl FUN_08176530
_08176D76:
	movs r2, #1
	rsbs r2, r2, #0
	b _08176DB4
	.align 2, 0
_08176D7C: .4byte 0x0000FFFF
_08176D80:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [sp, #0xc]
	adds r3, r0, r1
	ldr r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08176DB2
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	ldr r0, _08176DEC @ =0x00000674
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	strh r2, [r0, #2]
	movs r1, #2
	bl FUN_08176530
_08176DB2:
	movs r2, #1
_08176DB4:
	add r8, r2
_08176DB6:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	adds r6, r6, r0
	add sb, r0
	ldr r2, [sp, #8]
	adds r2, #1
	str r2, [sp, #8]
	ldr r1, _08176DF0 @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #8]
	cmp r1, r0
	bge _08176DDC
	b _08176C94
_08176DDC:
	ldr r2, _08176DF0 @ =0x00001012
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _08176DF4
	movs r0, #1
	b _08176E02
	.align 2, 0
_08176DEC: .4byte 0x00000674
_08176DF0: .4byte 0x00001012
_08176DF4:
	mov r2, r8
	cmn r2, r0
	ble _08176DFE
	movs r0, #0
	b _08176E02
_08176DFE:
	movs r0, #1
	rsbs r0, r0, #0
_08176E02:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08176e14
FUN_08176e14: @ 0x08176E14
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08176E44 @ =0x00001012
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _08176E66
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _08176E48 @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_08176E38:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _08176E4C
	movs r0, #1
	b _08176E4E
	.align 2, 0
_08176E44: .4byte 0x00001012
_08176E48: .4byte 0x00000755
_08176E4C:
	movs r0, #0
_08176E4E:
	cmp r0, #0
	bne _08176E58
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08176E58:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _08176E38
_08176E66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08176e6c
FUN_08176e6c: @ 0x08176E6C
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _08176EAC @ =0x00001012
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _08176ECE
	movs r5, #1
	adds r6, r1, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r7, _08176EB0 @ =0x00000755
	adds r1, r0, r7
	adds r1, r1, r2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r2, r0, r2
	movs r4, #0x92
	lsls r4, r4, #1
_08176E9E:
	ldrb r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _08176EB4
	movs r0, #1
	b _08176EB6
	.align 2, 0
_08176EAC: .4byte 0x00001012
_08176EB0: .4byte 0x00000755
_08176EB4:
	movs r0, #0
_08176EB6:
	cmp r0, #0
	bne _08176EC0
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
_08176EC0:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _08176E9E
_08176ECE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08176ed4
FUN_08176ed4: @ 0x08176ED4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08176F18 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #8]
	cmp r2, r0
	blt _08176EF8
	b _081770BA
_08176EF8:
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r3, #0xcb
	lsls r3, r3, #3
	add r3, sb
	mov r8, r3
	movs r0, #0
	mov sl, r0
_08176F0A:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08176F1C
	movs r0, #1
	b _08176F1E
	.align 2, 0
_08176F18: .4byte 0x00001012
_08176F1C:
	movs r0, #0
_08176F1E:
	cmp r0, #0
	beq _08176F24
	b _0817709C
_08176F24:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _08176F32
	movs r0, #1
	b _08176F34
_08176F32:
	movs r0, #0
_08176F34:
	cmp r0, #0
	beq _08176F52
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #7
	movs r3, #0
	bl FUN_08236fac
	b _08176FBC
_08176F52:
	movs r1, #0x20
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _08176F60
	movs r0, #1
	b _08176F62
_08176F60:
	movs r0, #0
_08176F62:
	cmp r0, #0
	beq _08176F6A
	movs r3, #0
	b _08176F82
_08176F6A:
	movs r1, #0x10
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _08176F78
	movs r0, #1
	b _08176F7A
_08176F78:
	movs r0, #0
_08176F7A:
	movs r3, #2
	cmp r0, #0
	beq _08176F82
	movs r3, #1
_08176F82:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08236fac
	ldr r0, _08176FF0 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl FUN_08237098
_08176FBC:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08176FF4
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _08177002
	.align 2, 0
_08176FF0: .4byte 0x00000482
_08176FF4:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_08177002:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08177024
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0817702C
_08177024:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0817702C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08177064 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0817709C
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08177068
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0817705C
	ldrb r0, [r4, #5]
_0817705C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08177078
	.align 2, 0
_08177064: .4byte 0x0000FFFF
_08177068:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08177078
	strh r1, [r4, #8]
_08177078:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _0817709C
	movs r3, #1
	strb r3, [r4, #7]
_0817709C:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	add r8, r0
	add sl, r0
	ldr r1, [sp, #8]
	adds r1, #1
	str r1, [sp, #8]
	ldr r0, _081770CC @ =0x00001012
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081770BA
	b _08176F0A
_081770BA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081770CC: .4byte 0x00001012

	thumb_func_start FUN_081770d0
FUN_081770d0: @ 0x081770D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08177114 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #8]
	cmp r2, r0
	blt _081770F4
	b _081772B6
_081770F4:
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r3, #0xcb
	lsls r3, r3, #3
	add r3, sb
	mov r8, r3
	movs r0, #0
	mov sl, r0
_08177106:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08177118
	movs r0, #1
	b _0817711A
	.align 2, 0
_08177114: .4byte 0x00001012
_08177118:
	movs r0, #0
_0817711A:
	cmp r0, #0
	beq _08177120
	b _08177298
_08177120:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0817712E
	movs r0, #1
	b _08177130
_0817712E:
	movs r0, #0
_08177130:
	cmp r0, #0
	beq _0817714E
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #7
	movs r3, #0
	bl FUN_08236fac
	b _081771B8
_0817714E:
	movs r1, #0x20
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0817715C
	movs r0, #1
	b _0817715E
_0817715C:
	movs r0, #0
_0817715E:
	cmp r0, #0
	beq _08177166
	movs r3, #0
	b _0817717E
_08177166:
	movs r1, #0x10
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _08177174
	movs r0, #1
	b _08177176
_08177174:
	movs r0, #0
_08177176:
	movs r3, #2
	cmp r0, #0
	beq _0817717E
	movs r3, #1
_0817717E:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08236fac
	ldr r0, _081771EC @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl FUN_08237098
_081771B8:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _081771F0
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _081771FE
	.align 2, 0
_081771EC: .4byte 0x00000482
_081771F0:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_081771FE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08177220
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08177228
_08177220:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08177228:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08177260 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08177298
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08177264
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08177258
	ldrb r0, [r4, #5]
_08177258:
	subs r0, #1
	strh r0, [r4, #8]
	b _08177274
	.align 2, 0
_08177260: .4byte 0x0000FFFF
_08177264:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08177274
	strh r1, [r4, #8]
_08177274:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08177298
	movs r3, #1
	strb r3, [r4, #7]
_08177298:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	add r8, r0
	add sl, r0
	ldr r1, [sp, #8]
	adds r1, #1
	str r1, [sp, #8]
	ldr r0, _081772C8 @ =0x00001012
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081772B6
	b _08177106
_081772B6:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081772C8: .4byte 0x00001012

	thumb_func_start FUN_081772cc
FUN_081772cc: @ 0x081772CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r6, #0
	ldr r2, _0817730C @ =0x00001012
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0817733C
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _08177310 @ =0x00000755
	adds r4, r7, r1
_081772FC:
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08177314
	movs r0, #1
	b _08177316
	.align 2, 0
_0817730C: .4byte 0x00001012
_08177310: .4byte 0x00000755
_08177314:
	movs r0, #0
_08177316:
	cmp r0, #0
	bne _08177326
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
_08177326:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	ldr r1, _08177348 @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081772FC
_0817733C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177348: .4byte 0x00001012

	thumb_func_start FUN_0817734c
FUN_0817734c: @ 0x0817734C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08177390 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #8]
	cmp r2, r0
	blt _08177370
	b _08177532
_08177370:
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r3, #0xcb
	lsls r3, r3, #3
	add r3, sb
	mov r8, r3
	movs r0, #0
	mov sl, r0
_08177382:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08177394
	movs r0, #1
	b _08177396
	.align 2, 0
_08177390: .4byte 0x00001012
_08177394:
	movs r0, #0
_08177396:
	cmp r0, #0
	beq _0817739C
	b _08177514
_0817739C:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773AA
	movs r0, #1
	b _081773AC
_081773AA:
	movs r0, #0
_081773AC:
	cmp r0, #0
	beq _081773CA
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #7
	movs r3, #0
	bl FUN_08237040
	b _08177434
_081773CA:
	movs r1, #0x20
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773D8
	movs r0, #1
	b _081773DA
_081773D8:
	movs r0, #0
_081773DA:
	cmp r0, #0
	beq _081773E2
	movs r3, #0
	b _081773FA
_081773E2:
	movs r1, #0x10
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773F0
	movs r0, #1
	b _081773F2
_081773F0:
	movs r0, #0
_081773F2:
	movs r3, #2
	cmp r0, #0
	beq _081773FA
	movs r3, #1
_081773FA:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08237040
	ldr r0, _08177468 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl FUN_08237098
_08177434:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0817746C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _0817747A
	.align 2, 0
_08177468: .4byte 0x00000482
_0817746C:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_0817747A:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0817749C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081774A4
_0817749C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081774A4:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081774DC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08177514
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081774E0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081774D4
	ldrb r0, [r4, #5]
_081774D4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081774F0
	.align 2, 0
_081774DC: .4byte 0x0000FFFF
_081774E0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081774F0
	strh r1, [r4, #8]
_081774F0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08177514
	movs r3, #1
	strb r3, [r4, #7]
_08177514:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	add r8, r0
	add sl, r0
	ldr r1, [sp, #8]
	adds r1, #1
	str r1, [sp, #8]
	ldr r0, _08177544 @ =0x00001012
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08177532
	b _08177382
_08177532:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177544: .4byte 0x00001012

	thumb_func_start FUN_08177548
FUN_08177548: @ 0x08177548
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08177578 @ =0x00001012
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _08177596
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _0817757C @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_0817756C:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _08177580
	movs r0, #1
	b _08177582
	.align 2, 0
_08177578: .4byte 0x00001012
_0817757C: .4byte 0x00000755
_08177580:
	movs r0, #0
_08177582:
	cmp r0, #0
	beq _08177588
	str r5, [r1]
_08177588:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0817756C
_08177596:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0817759c
FUN_0817759c: @ 0x0817759C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, _081775D4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _081775CE
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r6, r0
_081775B4:
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, #1
	ldr r1, _081775D4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _081775B4
_081775CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081775D4: .4byte 0x00001012

	thumb_func_start FUN_081775d8
FUN_081775d8: @ 0x081775D8
	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, _081775F4 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_081775F4: .4byte 0x00000674

	thumb_func_start FUN_081775f8
FUN_081775f8: @ 0x081775F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r2, #0
	ldr r7, _0817763C @ =0x00001012
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _0817769C
	mov r5, sp
	add r7, sp, #8
	mov r8, r7
	ldr r0, _08177640 @ =0x00000674
	adds r4, r3, r0
	ldr r1, _08177644 @ =0x00000754
	adds r6, r3, r1
_0817762C:
	movs r1, #1
	ldrb r0, [r6, #1]
	ands r0, r1
	cmp r0, #0
	beq _08177648
	movs r0, #1
	b _0817764A
	.align 2, 0
_0817763C: .4byte 0x00001012
_08177640: .4byte 0x00000674
_08177644: .4byte 0x00000754
_08177648:
	movs r0, #0
_0817764A:
	cmp r0, #0
	bne _08177686
	mov r7, r8
	ldrh r0, [r7]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r7, #4
	ldrsh r1, [r5, r7]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl FUN_0823785c
	strb r0, [r6]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, [sp, #0x14]
	ldr r2, [sp, #0x10]
_08177686:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _081776A8 @ =0x00001012
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _0817762C
_0817769C:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081776A8: .4byte 0x00001012

	thumb_func_start FUN_081776ac
FUN_081776ac: @ 0x081776AC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _081776C8 @ =0x00001010
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r0, _081776CC @ =0x0000100C
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_081776C8: .4byte 0x00001010
_081776CC: .4byte 0x0000100C

	thumb_func_start FUN_081776d0
FUN_081776d0: @ 0x081776D0
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #1
	ldr r2, _081776EC @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081776F0
	movs r0, #1
	b _081776F2
	.align 2, 0
_081776EC: .4byte 0x00001008
_081776F0:
	movs r0, #0
_081776F2:
	cmp r0, #0
	beq _08177714
	ldr r0, _0817771C @ =0x00001008
	adds r2, r4, r0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08177720 @ =0x00000FC4
	adds r4, r4, r1
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_08177714:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817771C: .4byte 0x00001008
_08177720: .4byte 0x00000FC4

	thumb_func_start FUN_08177724
FUN_08177724: @ 0x08177724
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r5, #0xff
	movs r1, #0
	ldr r2, _0817775C @ =0x00001012
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08177772
	movs r7, #4
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0xcb
	lsls r6, r6, #3
_08177748:
	adds r0, r2, r4
	adds r0, r0, r6
	adds r0, #0xfd
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08177760
	movs r0, #1
	b _08177762
	.align 2, 0
_0817775C: .4byte 0x00001012
_08177760:
	movs r0, #0
_08177762:
	cmp r0, #0
	bne _0817778C
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, #1
	cmp r1, r3
	blt _08177748
_08177772:
	cmp r5, #0xff
	beq _081777C0
	movs r1, #1
	ldr r2, _08177788 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08177790
	movs r0, #1
	b _08177792
	.align 2, 0
_08177788: .4byte 0x00001008
_0817778C:
	adds r5, r1, #0
	b _08177772
_08177790:
	movs r0, #0
_08177792:
	cmp r0, #0
	beq _081777C0
	ldr r0, _081777C8 @ =0x00000FCC
	adds r3, r4, r0
	lsls r2, r5, #3
	adds r2, r2, r5
	lsls r2, r2, #3
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, _081777CC @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081777D0 @ =0x00000FEC
	adds r0, r4, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r4, r2
	str r2, [r0]
_081777C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081777C8: .4byte 0x00000FCC
_081777CC: .4byte 0x00000674
_081777D0: .4byte 0x00000FEC

	thumb_func_start FUN_081777d4
FUN_081777d4: @ 0x081777D4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0xff
	movs r2, #0
	ldr r3, _08177810 @ =0x00001012
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _0817782E
	movs r3, #4
	mov ip, r3
	adds r4, r0, #0
	movs r3, #0
_081777FA:
	adds r0, r3, r6
	ldr r5, _08177814 @ =0x00000755
	adds r0, r0, r5
	ldrb r0, [r0]
	mov r5, ip
	ands r0, r5
	cmp r0, #0
	beq _08177818
	movs r0, #1
	b _0817781A
	.align 2, 0
_08177810: .4byte 0x00001012
_08177814: .4byte 0x00000755
_08177818:
	movs r0, #0
_0817781A:
	cmp r0, #0
	beq _08177822
	adds r7, r2, #0
	b _0817782E
_08177822:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r2, #1
	cmp r2, r4
	blt _081777FA
_0817782E:
	cmp r7, #0xff
	beq _0817787A
	ldr r2, _08177884 @ =0x00000FC4
	adds r5, r6, r2
	ldrh r1, [r1]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r7, #3
	adds r4, r4, r7
	lsls r4, r4, #3
	adds r4, r4, r7
	lsls r4, r4, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r4, r4, r3
	adds r4, r6, r4
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823b400
	ldr r1, _08177888 @ =0x00000FEC
	adds r0, r6, r1
	str r4, [r0]
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #1
	ldr r3, _0817788C @ =0x00001008
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817787A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177884: .4byte 0x00000FC4
_08177888: .4byte 0x00000FEC
_0817788C: .4byte 0x00001008

	thumb_func_start FUN_08177890
FUN_08177890: @ 0x08177890
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _081778B4 @ =0x00001010
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _081778BC
	strh r1, [r0]
	ldr r0, _081778B8 @ =0x0000100C
	adds r1, r2, r0
	movs r0, #0xff
	b _081778CA
	.align 2, 0
_081778B4: .4byte 0x00001010
_081778B8: .4byte 0x0000100C
_081778BC:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _081778CC
	strh r1, [r0]
	ldr r3, _081778E8 @ =0x0000100C
	adds r1, r2, r3
	movs r0, #1
_081778CA:
	strb r0, [r1]
_081778CC:
	ldr r5, _081778EC @ =0x00001010
	adds r1, r2, r5
	ldr r3, _081778E8 @ =0x0000100C
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081778E8: .4byte 0x0000100C
_081778EC: .4byte 0x00001010

	thumb_func_start FUN_081778f0
FUN_081778f0: @ 0x081778F0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08177904 @ =0x00000FAC
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08177904: .4byte 0x00000FAC

	thumb_func_start FUN_08177908
FUN_08177908: @ 0x08177908
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _08177968 @ =0x00000FAC
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081779B8
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _0817796C @ =0x00001012
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _081779B8
	movs r0, #2
	mov sl, r0
	movs r2, #1
	mov sb, r2
	mov r8, r1
	adds r3, r7, #0
	ldr r7, _08177970 @ =0x00000755
	adds r4, r3, r7
_08177958:
	ldrb r0, [r4]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08177974
	movs r0, #1
	b _08177976
	.align 2, 0
_08177968: .4byte 0x00000FAC
_0817796C: .4byte 0x00001012
_08177970: .4byte 0x00000755
_08177974:
	movs r0, #0
_08177976:
	cmp r0, #0
	beq _081779A2
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08177988
	movs r0, #1
	b _0817798A
_08177988:
	movs r0, #0
_0817798A:
	cmp r0, #0
	bne _081779A2
	ldr r7, _081779C8 @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xf0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_081779A2:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r4, r4, r0
	movs r1, #1
	add ip, r1
	mov r2, r8
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp ip, r0
	blt _08177958
_081779B8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081779C8: .4byte 0x00000674

	thumb_func_start FUN_081779cc
FUN_081779cc: @ 0x081779CC
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	ldr r2, _081779F8 @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081779FC
	movs r0, #1
	b _081779FE
	.align 2, 0
_081779F8: .4byte 0x00000755
_081779FC:
	movs r0, #0
_081779FE:
	cmp r0, #0
	beq _08177A40
	lsls r2, r3, #3
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	ldr r6, _08177A20 @ =0x00000755
	adds r0, r0, r6
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08177A24
	movs r0, #1
	b _08177A26
	.align 2, 0
_08177A20: .4byte 0x00000755
_08177A24:
	movs r0, #0
_08177A26:
	cmp r0, #0
	bne _08177A40
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _08177A48 @ =0x0000076C
	adds r0, r0, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
_08177A40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08177A48: .4byte 0x0000076C

	thumb_func_start FUN_08177a4c
FUN_08177a4c: @ 0x08177A4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r1, #0
	str r2, [sp]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0
	mov ip, r0
	ldr r1, _08177AA0 @ =0x00001012
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08177A78
	b _08177B74
_08177A78:
	ldr r0, _08177AA4 @ =0x085B0A08
	mov sb, r0
	adds r4, r5, #0
	movs r6, #0
	ldr r1, _08177AA8 @ =0x0000075A
	adds r3, r5, r1
	movs r0, #0x92
	lsls r0, r0, #1
	mov r8, r0
_08177A8A:
	adds r0, r6, r5
	ldr r1, _08177AAC @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08177AB0
	movs r0, #1
	b _08177AB2
	.align 2, 0
_08177AA0: .4byte 0x00001012
_08177AA4: .4byte 0x085B0A08
_08177AA8: .4byte 0x0000075A
_08177AAC: .4byte 0x00000755
_08177AB0:
	movs r0, #0
_08177AB2:
	cmp r0, #0
	beq _08177B5E
	adds r0, r6, r5
	ldr r1, _08177ACC @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08177AD0
	movs r0, #1
	b _08177AD2
	.align 2, 0
_08177ACC: .4byte 0x00000755
_08177AD0:
	movs r0, #0
_08177AD2:
	cmp r0, #0
	bne _08177B5E
	mov r0, sl
	cmp r0, #0
	bne _08177B00
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08177AF0
	asrs r2, r0, #0xc
	b _08177AF6
_08177AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177AF6:
	ldr r0, _08177AFC @ =0x0000076E
	b _08177B4E
	.align 2, 0
_08177AFC: .4byte 0x0000076E
_08177B00:
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08177B1A
	asrs r2, r0, #0xc
	b _08177B20
_08177B1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177B20:
	ldr r0, _08177B40 @ =0x0000076C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08177B44
	asrs r2, r0, #0xc
	b _08177B4A
	.align 2, 0
_08177B40: .4byte 0x0000076C
_08177B44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177B4A:
	movs r0, #0xee
	lsls r0, r0, #3
_08177B4E:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_08177B5E:
	add r4, r8
	add r6, r8
	add r3, r8
	movs r0, #1
	add ip, r0
	ldr r1, _08177B84 @ =0x00001012
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08177A8A
_08177B74:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177B84: .4byte 0x00001012

	thumb_func_start FUN_08177b88
FUN_08177b88: @ 0x08177B88
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	ldr r7, [sp, #0x68]
	subs r1, r7, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	cmp sl, r7
	blt _08177BCA
	b _08177D24
_08177BCA:
	mov r1, sp
	adds r1, #4
	str r1, [sp, #0x34]
	add r2, sp, #0xc
	mov sb, r2
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x38]
	add r4, sp, #0x1c
	mov r8, r4
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x40]
_08177BE4:
	adds r4, r0, #1
	ldr r0, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _08177C28 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _08177C2C
	asrs r0, r0, #0xa
	b _08177C32
	.align 2, 0
_08177C28: .4byte 0x05000002
_08177C2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08177C32:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _08177C40
	asrs r1, r0, #0xa
	b _08177C46
_08177C40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08177C46:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _08177C84
	asrs r1, r0, #0xa
	b _08177C8A
_08177C84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08177C8A:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _08177CC4
	asrs r1, r0, #0xa
	b _08177CCA
_08177CC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08177CCA:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _08177CFC
	asrs r1, r0, #0xa
	b _08177D02
_08177CFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08177D02:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl FUN_081775d8
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _08177D24
	b _08177BE4
_08177D24:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08177d34
FUN_08177d34: @ 0x08177D34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #0x18]
	mov r8, r1
	str r2, [sp, #0x1c]
	str r3, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r2, [sp, #0x18]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r3, #0
	mov sl, r3
	ldr r4, _08177D88 @ =0x00001012
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08177E66
	ldr r2, _08177D8C @ =0x00000764
	adds r7, r6, r2
	str r3, [sp, #0x24]
	ldr r4, _08177D90 @ =0x00000755
	adds r4, r4, r6
	mov sb, r4
_08177D78:
	movs r1, #2
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08177D94
	movs r0, #1
	b _08177D96
	.align 2, 0
_08177D88: .4byte 0x00001012
_08177D8C: .4byte 0x00000764
_08177D90: .4byte 0x00000755
_08177D94:
	movs r0, #0
_08177D96:
	cmp r0, #0
	beq _08177E48
	movs r1, #1
	mov r3, sb
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08177DAA
	movs r0, #1
	b _08177DAC
_08177DAA:
	movs r0, #0
_08177DAC:
	cmp r0, #0
	bne _08177E48
	mov r5, sp
	ldr r4, [sp, #0x24]
	adds r2, r4, r6
	ldr r3, _08177EA4 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r7]
	ldrh r0, [r2]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x20]
	cmp r1, r0
	ble _08177E48
	mov r1, r8
	cmp r1, #1
	bge _08177E06
	movs r4, #1
	mov r8, r4
_08177E06:
	adds r0, r2, #0
	mov r1, r8
	str r3, [sp, #0x28]
	bl Div
	ldr r1, [sp, #0x24]
	adds r4, r6, r1
	ldr r3, [sp, #0x28]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	mov r1, r8
	bl Div
	ldr r3, _08177EA8 @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	mov r1, r8
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_08177E48:
	movs r3, #0x92
	lsls r3, r3, #1
	adds r7, r7, r3
	ldr r4, [sp, #0x24]
	adds r4, r4, r3
	str r4, [sp, #0x24]
	add sb, r3
	movs r0, #1
	add sl, r0
	ldr r1, _08177EAC @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sl, r0
	blt _08177D78
_08177E66:
	ldr r3, [sp, #0x18]
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r4, #0
	mov sl, r4
	ldr r1, _08177EAC @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sl, r0
	bge _08177F5A
	add r7, sp, #0x10
	mov sb, r4
	ldr r3, _08177EB0 @ =0x00000755
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r5, r6, r4
_08177E92:
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08177EB4
	movs r0, #1
	b _08177EB6
	.align 2, 0
_08177EA4: .4byte 0x00000674
_08177EA8: .4byte 0x00000676
_08177EAC: .4byte 0x00001012
_08177EB0: .4byte 0x00000755
_08177EB4:
	movs r0, #0
_08177EB6:
	cmp r0, #0
	bne _08177F40
	add r4, sp, #8
	mov r3, sb
	adds r2, r3, r6
	ldr r0, _08177F70 @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r7]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r2, [r4, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08177F74 @ =0x000031B4
	cmp r1, r0
	ble _08177F30
	adds r0, r2, #0
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
_08177F30:
	mov r3, sb
	adds r0, r6, r3
	ldr r4, _08177F70 @ =0x00000674
	adds r0, r0, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
_08177F40:
	movs r0, #0x92
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r5, r5, r0
	movs r1, #1
	add sl, r1
	ldr r2, _08177F78 @ =0x00001012
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sl, r0
	blt _08177E92
_08177F5A:
	ldr r0, [sp, #0x18]
	bl FUN_081775f8
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177F70: .4byte 0x00000674
_08177F74: .4byte 0x000031B4
_08177F78: .4byte 0x00001012

	thumb_func_start FUN_08177f7c
FUN_08177f7c: @ 0x08177F7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _08177FC8 @ =0x00001012
	adds r7, r3, r0
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r5, r0
	bge _08177FBE
	ldr r2, [r1, #4]
	ldr r1, [r1]
	ldr r6, _08177FCC @ =0x00000764
	adds r4, r3, r6
	ldr r0, _08177FD0 @ =0x00000674
	adds r3, r3, r0
	movs r6, #0x92
	lsls r6, r6, #1
	mov r8, r6
	mov ip, r7
_08177FA6:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	add r4, r8
	add r3, r8
	adds r5, #1
	mov r7, ip
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r5, r0
	blt _08177FA6
_08177FBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177FC8: .4byte 0x00001012
_08177FCC: .4byte 0x00000764
_08177FD0: .4byte 0x00000674

	thumb_func_start FUN_08177fd4
FUN_08177fd4: @ 0x08177FD4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r5, _08178068 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r2, _0817806C @ =0x0000FFFF
	mov r8, r2
	ands r0, r2
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _08178070 @ =FUN_08170644
	str r4, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r2, #0x52
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _08178074 @ =FUN_08170604
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r4, #0
	bl FUN_080e3984
	movs r2, #0x94
	lsls r2, r2, #1
	adds r4, r4, r2
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08178068: .4byte 0xFFFF0000
_0817806C: .4byte 0x0000FFFF
_08178070: .4byte FUN_08170644
_08178074: .4byte FUN_08170604

	thumb_func_start FUN_08178078
FUN_08178078: @ 0x08178078
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _081780E0 @ =0x00001008
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _081780E4 @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r2, _081780E8 @ =0x00000FB5
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _081780EC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081780F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081780F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081780F8 @ =0x00001021
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _081780FC @ =0x00000FAD
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x3f
	adds r1, r5, r2
	ldr r3, _08178100 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08178104
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0817810E
	.align 2, 0
_081780E0: .4byte 0x00001008
_081780E4: .4byte 0x0000FFFD
_081780E8: .4byte 0x00000FB5
_081780EC: .4byte 0x030046B8
_081780F0: .4byte 0x000003FF
_081780F4: .4byte 0x0203B400
_081780F8: .4byte 0x00001021
_081780FC: .4byte 0x00000FAD
_08178100: .4byte 0x0000025D
_08178104:
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0817810E:
	movs r1, #0x83
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	adds r0, r4, #0
	bl FUN_081794a8
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_08177f7c
	adds r0, r4, #0
	bl FUN_08175898
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r5, _08178198 @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r1, _0817819C @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	subs r5, #0x17
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08178198: .4byte 0x00000469
_0817819C: .4byte 0x0000046C

	thumb_func_start FUN_081781a0
FUN_081781a0: @ 0x081781A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r3, [r6, #0x44]
	ldr r2, _081781DC @ =0x085B0A08
	ldr r4, _081781E0 @ =0x0000100A
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081781E4
	asrs r1, r0, #0xc
	b _081781EA
	.align 2, 0
_081781DC: .4byte 0x085B0A08
_081781E0: .4byte 0x0000100A
_081781E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081781EA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldr r1, [r6, #0x44]
	ldr r3, [sp, #0x24]
	ldr r4, _0817820C @ =0x0000100A
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #4
	cmp r0, #0
	blt _08178210
	asrs r2, r0, #0xc
	b _08178216
	.align 2, 0
_0817820C: .4byte 0x0000100A
_08178210:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08178216:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r0, [sp, #0x24]
	ldr r2, _08178268 @ =0x0000100A
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov sl, r5
	ldr r3, [sp, #0x24]
	ldr r4, _0817826C @ =0x00001012
	adds r1, r3, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	bge _081782A6
	ldr r0, _08178270 @ =0x085B0A08
	mov r8, r0
	mov sb, r1
	movs r1, #0x92
	lsls r1, r1, #1
	adds r3, r3, r1
	ldr r4, [sp, #0x24]
	ldr r7, _08178274 @ =0x0000087D
	adds r2, r4, r7
	movs r4, #0x92
	lsls r4, r4, #2
_08178252:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08178278
	asrs r0, r0, #0xc
	b _0817827E
	.align 2, 0
_08178268: .4byte 0x0000100A
_0817826C: .4byte 0x00001012
_08178270: .4byte 0x085B0A08
_08178274: .4byte 0x0000087D
_08178278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817827E:
	ldr r7, _08178330 @ =0x00000674
	adds r1, r3, r7
	muls r0, r5, r0
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #8
	strb r0, [r2]
	rsbs r5, r5, #0
	adds r3, r3, r4
	adds r2, r2, r4
	movs r0, #2
	add sl, r0
	mov r1, sb
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	blt _08178252
_081782A6:
	ldr r0, [r6, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #0x24]
	ldr r2, _08178334 @ =0x00001012
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sl, r0
	blt _081782C6
	b _081783F0
_081782C6:
	add r4, sp, #4
	mov sb, r4
	add r7, sp, #0xc
	add r6, sp, #0x14
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
_081782DA:
	ldrh r0, [r5]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _08178338 @ =0x05000002
	bl CpuSet
	mov r3, r8
	movs r4, #0xc0
	lsls r4, r4, #2
	subs r1, r3, r4
	adds r1, #1
	add r2, sp, #0x1c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	mov r3, r8
	subs r1, r0, r3
	movs r3, #0
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _0817833C
	asrs r1, r0, #0xa
	b _08178342
	.align 2, 0
_08178330: .4byte 0x00000674
_08178334: .4byte 0x00001012
_08178338: .4byte 0x05000002
_0817833C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08178342:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4]
	mov r0, r8
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	rsbs r2, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [sp, #0x28]
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [sp, #0x28]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _08178380
	asrs r1, r0, #0xa
	b _08178386
_08178380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08178386:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _081783B4
	asrs r1, r0, #0xa
	b _081783BA
_081783B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081783BA:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4, #4]
	ldr r0, [sp, #0x24]
	mov r1, sl
	mov r2, sb
	bl FUN_081775d8
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x92
	lsls r0, r0, #2
	adds r5, r5, r0
	movs r1, #2
	add sl, r1
	ldr r2, [sp, #0x24]
	ldr r3, _08178400 @ =0x00001012
	adds r0, r2, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp sl, r0
	bge _081783F0
	b _081782DA
_081783F0:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178400: .4byte 0x00001012

	thumb_func_start FUN_08178404
FUN_08178404: @ 0x08178404
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _0817843C @ =0x00001012
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _08178468
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08178440 @ =0x00000755
	adds r2, r1, r0
	movs r6, #0x92
	lsls r6, r6, #1
_08178430:
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _08178444
	movs r0, #1
	b _08178446
	.align 2, 0
_0817843C: .4byte 0x00001012
_08178440: .4byte 0x00000755
_08178444:
	movs r0, #0
_08178446:
	cmp r0, #0
	bne _0817845C
	cmp r4, #1
	bne _08178452
	movs r4, #0
	b _0817845C
_08178452:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
	adds r4, #1
_0817845C:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _08178430
_08178468:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08178470
FUN_08178470: @ 0x08178470
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r6, r0
	ldr r1, _081784B4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, #1
	cmp r2, #0
	blt _081784F6
	movs r7, #1
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1c
	adds r5, r1, r3
	adds r1, #0x7c
	adds r1, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
_081784A8:
	ldrb r0, [r4]
	ands r0, r7
	cmp r0, #0
	beq _081784B8
	movs r0, #1
	b _081784BA
	.align 2, 0
_081784B4: .4byte 0x00001012
_081784B8:
	movs r0, #0
_081784BA:
	cmp r0, #0
	bne _081784E8
	adds r0, r1, #0
	bl FUN_08236424
	ldrb r1, [r4]
	adds r0, r7, #0
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _081784E4 @ =0x00001022
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_08176530
	movs r0, #1
	b _081784F8
	.align 2, 0
_081784E4: .4byte 0x00001022
_081784E8:
	ldr r0, _08178500 @ =0xFFFFFEDC
	adds r5, r5, r0
	adds r1, r1, r0
	adds r4, r4, r0
	subs r2, #1
	cmp r2, #0
	bge _081784A8
_081784F6:
	movs r0, #0
_081784F8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08178500: .4byte 0xFFFFFEDC

	thumb_func_start FUN_08178504
FUN_08178504: @ 0x08178504
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0xcb
	lsls r2, r2, #3
	add r2, r8
	ldr r0, _08178560 @ =0x00001022
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817859C
	ldr r0, _08178564 @ =0x00001012
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0817859C
	movs r0, #1
	mov sb, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1c
	adds r7, r1, r2
	adds r1, #0x7c
	adds r6, r1, r2
	adds r0, #0xfd
	adds r4, r0, r2
_08178550:
	ldrb r0, [r4]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _08178568
	movs r0, #1
	b _0817856A
	.align 2, 0
_08178560: .4byte 0x00001022
_08178564: .4byte 0x00001012
_08178568:
	movs r0, #0
_0817856A:
	cmp r0, #0
	bne _0817858E
	adds r0, r6, #0
	bl FUN_08236424
	ldrb r1, [r4]
	mov r0, sb
	orrs r0, r1
	strb r0, [r4]
	ldr r1, _081785A8 @ =0x00001022
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_08176530
_0817858E:
	ldr r0, _081785AC @ =0xFFFFFEDC
	adds r7, r7, r0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08178550
_0817859C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081785A8: .4byte 0x00001022
_081785AC: .4byte 0xFFFFFEDC

	thumb_func_start FUN_081785b0
FUN_081785b0: @ 0x081785B0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r1, _081785FC @ =0x00001022
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817862E
	subs r1, #0x10
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0817862E
	movs r2, #1
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x98
	adds r6, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
_081785F0:
	ldrb r0, [r4]
	ands r0, r2
	cmp r0, #0
	beq _08178600
	movs r0, #1
	b _08178602
	.align 2, 0
_081785FC: .4byte 0x00001022
_08178600:
	movs r0, #0
_08178602:
	cmp r0, #0
	bne _08178622
	adds r0, r6, #0
	str r2, [sp]
	bl FUN_08236424
	ldrb r1, [r4]
	ldr r2, [sp]
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _08178638 @ =0x00001022
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08178622:
	ldr r1, _0817863C @ =0xFFFFFEDC
	adds r6, r6, r1
	adds r4, r4, r1
	subs r5, #1
	cmp r5, #0
	bge _081785F0
_0817862E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178638: .4byte 0x00001022
_0817863C: .4byte 0xFFFFFEDC

	thumb_func_start FUN_08178640
FUN_08178640: @ 0x08178640
	push {lr}
	cmp r1, #0
	beq _08178658
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0817865C @ =0x0000100A
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_08178658:
	pop {r0}
	bx r0
	.align 2, 0
_0817865C: .4byte 0x0000100A

	thumb_func_start FUN_08178660
FUN_08178660: @ 0x08178660
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r5, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r6, r0
	ble _081786A6
	movs r6, #0xff
	b _081786B0
_081786A6:
	cmp r6, #0x80
	ble _081786AE
	movs r6, #0x7f
	b _081786B0
_081786AE:
	movs r6, #0x3f
_081786B0:
	movs r2, #0
	mov ip, r2
	ldr r3, _081786E4 @ =0x00001012
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08178794
	ldr r2, _081786E8 @ =0x085B0A08
	mov sl, r2
	movs r7, #0
	movs r3, #0xcb
	lsls r3, r3, #3
	mov sb, r3
	ldr r0, _081786EC @ =0x030046B8
	mov r8, r0
_081786D0:
	adds r0, r7, r5
	add r0, sb
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _081786F0
	movs r0, #1
	b _081786F2
	.align 2, 0
_081786E4: .4byte 0x00001012
_081786E8: .4byte 0x085B0A08
_081786EC: .4byte 0x030046B8
_081786F0:
	movs r0, #0
_081786F2:
	cmp r0, #0
	beq _0817877E
	adds r0, r7, r5
	add r0, sb
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0817870A
	movs r0, #1
	b _0817870C
_0817870A:
	movs r0, #0
_0817870C:
	cmp r0, #0
	bne _0817877E
	mov r3, r8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08178748 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0817874C @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r2, r7, r5
	ldr r0, _08178750 @ =0x0000076C
	adds r2, r2, r0
	ands r3, r6
	movs r4, #0xc
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08178754
	asrs r1, r0, #0xc
	b _0817875A
	.align 2, 0
_08178748: .4byte 0x000003FF
_0817874C: .4byte 0x0203B400
_08178750: .4byte 0x0000076C
_08178754:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817875A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08178776
	asrs r0, r0, #0xc
	b _0817877C
_08178776:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817877C:
	strh r0, [r2, #4]
_0817877E:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r1, #1
	add ip, r1
	ldr r2, _081787A4 @ =0x00001012
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp ip, r0
	blt _081786D0
_08178794:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081787A4: .4byte 0x00001012

	thumb_func_start FUN_081787a8
FUN_081787a8: @ 0x081787A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, [sp]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081787D6
	b _081788FE
_081787D6:
	movs r0, #0
	mov sl, r0
	ldr r0, _08178808 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081787E8
	b _081788FE
_081787E8:
	ldr r7, _0817880C @ =0x00000676
	add r7, sb
	ldr r6, _08178810 @ =0x00000674
	add r6, sb
	ldr r2, _08178814 @ =0x00000755
	add r2, sb
	mov r8, r2
_081787F6:
	movs r1, #2
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08178818
	movs r0, #1
	b _0817881A
	.align 2, 0
_08178808: .4byte 0x00001012
_0817880C: .4byte 0x00000676
_08178810: .4byte 0x00000674
_08178814: .4byte 0x00000755
_08178818:
	movs r0, #0
_0817881A:
	cmp r0, #0
	beq _081788E2
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817882E
	movs r0, #1
	b _08178830
_0817882E:
	movs r0, #0
_08178830:
	cmp r0, #0
	bne _081788E2
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08178858
	cmp r1, #0
	blt _08178858
	ldr r0, _0817885C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08178858
	ldr r0, _08178860 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08178864
_08178858:
	movs r4, #0
	b _08178872
	.align 2, 0
_0817885C: .4byte 0x030046A8
_08178860: .4byte 0x030046AC
_08178864:
	ldr r0, _08178884 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08178872:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08178888
	adds r0, #4
	b _08178894
	.align 2, 0
_08178884: .4byte 0x030046A4
_08178888:
	ldr r0, _081788A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08178894:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081788AC
	cmp r2, #2
	beq _081788B0
	b _081788B4
	.align 2, 0
_081788A8: .4byte 0x030046A4
_081788AC:
	ldrb r0, [r5, #4]
	b _081788B2
_081788B0:
	ldrb r0, [r5]
_081788B2:
	subs r1, r1, r0
_081788B4:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r0, r1
	beq _081788E2
	cmp r0, r1
	bge _081788D4
	subs r0, r1, r0
	cmp r0, #0
	bge _081788C8
	rsbs r0, r0, #0
_081788C8:
	cmp r0, #0xff
	ble _081788E0
	ldr r1, [sp]
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _081788E2
_081788D4:
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
_081788E0:
	strh r1, [r7]
_081788E2:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r7, r7, r2
	adds r6, r6, r2
	add r8, r2
	movs r3, #1
	add sl, r3
	ldr r0, _08178910 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _081788FE
	b _081787F6
_081788FE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178910: .4byte 0x00001012

	thumb_func_start FUN_08178914
FUN_08178914: @ 0x08178914
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r2, #0
	mov sl, r2
	ldr r7, _08178960 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08178A22
	movs r6, #0
	ldr r2, _08178964 @ =0x0000076E
	adds r3, r5, r2
	adds r4, r5, #0
	movs r7, #2
	mov sb, r7
	movs r0, #1
	mov r8, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov ip, r1
_0817894C:
	adds r0, r6, r5
	ldr r2, _08178968 @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _0817896C
	movs r0, #1
	b _0817896E
	.align 2, 0
_08178960: .4byte 0x00001012
_08178964: .4byte 0x0000076E
_08178968: .4byte 0x00000755
_0817896C:
	movs r0, #0
_0817896E:
	cmp r0, #0
	beq _08178A0C
	adds r0, r6, r5
	ldr r1, _08178988 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0817898C
	movs r0, #1
	b _0817898E
	.align 2, 0
_08178988: .4byte 0x00000755
_0817898C:
	movs r0, #0
_0817898E:
	cmp r0, #0
	bne _08178A0C
	ldr r7, _081789C8 @ =0x00000674
	adds r1, r4, r7
	ldr r0, _081789CC @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _081789D0 @ =0x00000676
	adds r1, r4, r0
	ldrh r0, [r3]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081789D4
	asrs r1, r0, #1
	b _081789DA
	.align 2, 0
_081789C8: .4byte 0x00000674
_081789CC: .4byte 0x0000076C
_081789D0: .4byte 0x00000676
_081789D4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081789DA:
	ldr r2, _081789EC @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _081789F0
	asrs r0, r0, #1
	b _081789F6
	.align 2, 0
_081789EC: .4byte 0x0000076C
_081789F0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081789F6:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08178A04
	asrs r0, r0, #1
	b _08178A0A
_08178A04:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08178A0A:
	strh r0, [r3, #2]
_08178A0C:
	add r6, ip
	add r3, ip
	add r4, ip
	movs r2, #1
	add sl, r2
	ldr r7, _08178A30 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _0817894C
_08178A22:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178A30: .4byte 0x00001012

	thumb_func_start FUN_08178a34
FUN_08178a34: @ 0x08178A34
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	movs r1, #2
	ldr r2, _08178A54 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08178A58
	movs r0, #1
	b _08178A5A
	.align 2, 0
_08178A54: .4byte 0x00001008
_08178A58:
	movs r0, #0
_08178A5A:
	cmp r0, #0
	beq _08178AA4
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r2, [r0]
	ldr r2, _08178AB8 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08178ABC @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08178AC0 @ =0x00000544
	adds r1, r3, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r0, #2
	strh r0, [r1]
_08178AA4:
	ldr r1, _08178AC4 @ =0x00001008
	adds r0, r4, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08178AB8: .4byte 0x00000484
_08178ABC: .4byte 0xFFEFFFFF
_08178AC0: .4byte 0x00000544
_08178AC4: .4byte 0x00001008

	thumb_func_start FUN_08178ac8
FUN_08178ac8: @ 0x08178AC8
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08178B3A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _08178AF8 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08178AFC
	movs r0, #1
	b _08178AFE
	.align 2, 0
_08178AF8: .4byte 0x00001008
_08178AFC:
	movs r0, #0
_08178AFE:
	adds r2, r0, #0
	cmp r2, #0
	bne _08178B3A
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _08178B44 @ =0x00000FAA
	adds r1, r1, r0
	ldrh r0, [r5, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	add r4, sp, #0xc
	str r2, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _08178B48 @ =0x05000002
	bl CpuSet
	ldrh r1, [r5, #0x3e]
	adds r3, r6, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0805fe7c
_08178B3A:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08178B44: .4byte 0x00000FAA
_08178B48: .4byte 0x05000002

	thumb_func_start FUN_08178b4c
FUN_08178b4c: @ 0x08178B4C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08178b50
FUN_08178b50: @ 0x08178B50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08178B78
	b _08178D1A
_08178B78:
	movs r2, #0x20
	ldr r0, _08178B8C @ =0x00001008
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08178B90
	movs r0, #1
	b _08178B92
	.align 2, 0
_08178B8C: .4byte 0x00001008
_08178B90:
	movs r0, #0
_08178B92:
	cmp r0, #0
	beq _08178B98
	b _08178D1A
_08178B98:
	adds r0, r7, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #0
	beq _08178BA4
	b _08178D1A
_08178BA4:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08178ac8
	adds r0, r7, #0
	bl FUN_08179c00
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0x40
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08178BF8
	b _08178D1A
_08178BF8:
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08178C0C
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08178C78
_08178C0C:
	add r4, sp, #0x10
	adds r3, r6, #0
	adds r3, #0xc
	adds r2, r5, #0
	adds r2, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	adds r0, r4, #0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08178C64
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08178C64
	ldr r0, _08178C58 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08178C5C @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08178C60 @ =0x0203B400
	adds r1, r1, r0
	ldrb r3, [r1]
	b _08178C78
	.align 2, 0
_08178C58: .4byte 0x030046B8
_08178C5C: .4byte 0x000003FF
_08178C60: .4byte 0x0203B400
_08178C64:
	add r0, sp, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #0x10
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08178C78:
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _08178D2C @ =0x0203B400
	mov r8, r0
	ldr r1, _08178D30 @ =0x030046B8
	mov sl, r1
	ldr r4, [r1]
	adds r4, #1
	ldr r6, _08178D34 @ =0x000003FF
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08178D38 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _08178D3C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r1, #0x3c
	orrs r0, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r5
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r5, [r0]
	movs r0, #7
	ands r5, r0
	adds r5, #4
	adds r4, #1
	ands r4, r6
	mov r1, sl
	str r4, [r1]
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r4]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x20
	str r5, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	bl FUN_080ddcc8
_08178D1A:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178D2C: .4byte 0x0203B400
_08178D30: .4byte 0x030046B8
_08178D34: .4byte 0x000003FF
_08178D38: .4byte 0x0000FFFF
_08178D3C: .4byte 0xFFFF0000

	thumb_func_start FUN_08178d40
FUN_08178d40: @ 0x08178D40
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _08178D88 @ =0x00001024
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r4, _08178D8C @ =0x7FFFFFFF
	cmp r0, r4
	beq _08178DBE
	ldr r2, _08178D90 @ =0x00001028
	adds r0, r1, r2
	ldr r2, [r0]
	str r4, [r3]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r1, r2, #0
	adds r1, #0xd8
	adds r4, #0x14
	adds r3, r2, r4
	ldrb r4, [r0]
	ldrh r5, [r1]
	ldr r2, _08178D94 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08178D98
	asrs r1, r0, #0xc
	b _08178D9E
	.align 2, 0
_08178D88: .4byte 0x00001024
_08178D8C: .4byte 0x7FFFFFFF
_08178D90: .4byte 0x00001028
_08178D94: .4byte 0x085B0A08
_08178D98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08178D9E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08178DB6
	asrs r0, r0, #0xc
	b _08178DBC
_08178DB6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08178DBC:
	strh r0, [r3, #4]
_08178DBE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08178dc4
FUN_08178dc4: @ 0x08178DC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08178E6C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08178E70 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0
	mov sb, r2
	ldr r3, _08178E74 @ =0x00001012
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov sl, r1
	cmp sb, r0
	bge _08178ED0
	ldr r3, _08178E78 @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_08178E26:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08178E7C @ =0x00005009
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08178E74 @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _08178E84
	ldr r3, _08178E80 @ =0x00000FB2
	adds r0, r6, r3
	ldrh r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl FUN_08236514
	b _08178EA2
	.align 2, 0
_08178E6C: .4byte 0xFFFF0000
_08178E70: .4byte 0x0000FFFF
_08178E74: .4byte 0x00001012
_08178E78: .4byte 0x00000674
_08178E7C: .4byte 0x00005009
_08178E80: .4byte 0x00000FB2
_08178E84:
	ldr r1, _08178F8C @ =0x00000FB2
	adds r0, r6, r1
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl FUN_08236514
_08178EA2:
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08178F90 @ =FUN_08178b50
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _08178F94 @ =0x00001012
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _08178E26
_08178ED0:
	movs r3, #0
	movs r2, #0x30
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	mov r0, sl
	strh r3, [r0]
	add r1, sp, #0x14
	movs r0, #0x80
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	mov sb, r3
	ldr r1, _08178F94 @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	bge _08178F7C
	ldr r3, _08178F98 @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_08178F0C:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08178F9C @ =0x00002401
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08178FA0 @ =FUN_08178b4c
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _08178F94 @ =0x00001012
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _08178F0C
_08178F7C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178F8C: .4byte 0x00000FB2
_08178F90: .4byte FUN_08178b50
_08178F94: .4byte 0x00001012
_08178F98: .4byte 0x00000674
_08178F9C: .4byte 0x00002401
_08178FA0: .4byte FUN_08178b4c

	thumb_func_start FUN_08178fa4
FUN_08178fa4: @ 0x08178FA4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08178fdc
FUN_08178fdc: @ 0x08178FDC
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r1, _0817901C @ =0x00000546
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _08179040
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08179094
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08179020 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08179024
	movs r0, #1
	b _08179026
	.align 2, 0
_0817901C: .4byte 0x00000546
_08179020: .4byte 0x00001008
_08179024:
	movs r0, #0
_08179026:
	cmp r0, #0
	beq _0817906A
	ldr r2, _0817903C @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #2
	b _08179096
	.align 2, 0
_0817903C: .4byte 0x085ADB3C
_08179040:
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08179094
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08179060 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08179064
	movs r0, #1
	b _08179066
	.align 2, 0
_08179060: .4byte 0x00001008
_08179064:
	movs r0, #0
_08179066:
	cmp r0, #0
	beq _08179080
_0817906A:
	ldr r2, _0817907C @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #1
	b _08179096
	.align 2, 0
_0817907C: .4byte 0x085ADB3C
_08179080:
	ldr r2, _08179090 @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _08179096
	.align 2, 0
_08179090: .4byte 0x085ADB3C
_08179094:
	movs r0, #0
_08179096:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817909c
FUN_0817909c: @ 0x0817909C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa0
	ldr r4, _081790D4 @ =0x00001008
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081790D8
	movs r0, #1
	b _081790DA
	.align 2, 0
_081790D4: .4byte 0x00001008
_081790D8:
	movs r0, #0
_081790DA:
	cmp r0, #0
	beq _081790E8
	ldr r0, _081790E4 @ =0x00000FB5
	adds r1, r7, r0
	b _08179202
	.align 2, 0
_081790E4: .4byte 0x00000FB5
_081790E8:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r3
	cmp r2, #0
	blt _08179134
	cmp r1, #0
	blt _08179134
	ldr r0, _08179138 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08179134
	ldr r0, _0817913C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08179140
_08179134:
	movs r4, #0
	b _0817914E
	.align 2, 0
_08179138: .4byte 0x030046A8
_0817913C: .4byte 0x030046AC
_08179140:
	ldr r0, _08179160 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0817914E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08179164
	adds r0, #4
	b _08179170
	.align 2, 0
_08179160: .4byte 0x030046A4
_08179164:
	ldr r0, _08179184 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179170:
	ldrh r6, [r0, #2]
	mov r8, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08179188
	adds r0, #4
	b _08179194
	.align 2, 0
_08179184: .4byte 0x030046A4
_08179188:
	ldr r0, _081791A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179194:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081791AC
	cmp r2, #2
	beq _081791B2
	b _081791B8
	.align 2, 0
_081791A8: .4byte 0x030046A4
_081791AC:
	mov r2, r8
	ldrb r0, [r2, #4]
	b _081791B6
_081791B2:
	mov r3, r8
	ldrb r0, [r3]
_081791B6:
	subs r1, r1, r0
_081791B8:
	ldr r4, _081791F0 @ =0x00000472
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, r1
	blt _081791CA
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _081791DC
_081791CA:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081791DC:
	movs r1, #0xa4
	ldr r3, _081791F4 @ =0x00001008
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081791F8
	movs r0, #1
	b _081791FA
	.align 2, 0
_081791F0: .4byte 0x00000472
_081791F4: .4byte 0x00001008
_081791F8:
	movs r0, #0
_081791FA:
	cmp r0, #0
	beq _0817920C
	ldr r4, _08179208 @ =0x00000FB5
	adds r1, r7, r4
_08179202:
	movs r0, #0
	strb r0, [r1]
	b _081792EA
	.align 2, 0
_08179208: .4byte 0x00000FB5
_0817920C:
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081792E4
	ldr r0, _0817928C @ =0x00000FB5
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081792EA
	ldr r1, _08179290 @ =0x00001021
	adds r2, r7, r1
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	ldr r3, _08179294 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	mov r4, sb
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817929C
	ldr r0, _08179298 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081792AA
	.align 2, 0
_0817928C: .4byte 0x00000FB5
_08179290: .4byte 0x00001021
_08179294: .4byte 0x000004A4
_08179298: .4byte 0xFFFFFF00
_0817929C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081792AA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081792AA:
	cmp r1, #0
	bge _081792B0
	rsbs r1, r1, #0
_081792B0:
	cmp r1, #0x20
	ble _081792EA
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _081792DC @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _081792E0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081792EA
	.align 2, 0
_081792DC: .4byte 0x00000469
_081792E0: .4byte 0x0000046C
_081792E4:
	ldr r2, _081792F8 @ =0x00000FB5
	adds r0, r7, r2
	strb r1, [r0]
_081792EA:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081792F8: .4byte 0x00000FB5

	thumb_func_start FUN_081792fc
FUN_081792fc: @ 0x081792FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r2, _08179454 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _08179458 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r4, _0817945C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08179460 @ =0x000003FF
	mov sl, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r0, #0x14
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #2
	str r6, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08179464 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xf0
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179454: .4byte 0xFFFF0000
_08179458: .4byte 0x0000FFFF
_0817945C: .4byte 0x030046B8
_08179460: .4byte 0x000003FF
_08179464: .4byte 0x0203B400

	thumb_func_start FUN_08179468
FUN_08179468: @ 0x08179468
	push {lr}
	adds r1, r0, #0
	ldr r2, _08179484 @ =0x00000544
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08179498
	cmp r0, #0x3b
	bhi _0817948C
	ldr r0, _08179488 @ =0x00000482
	adds r1, r1, r0
	movs r0, #2
	b _0817949E
	.align 2, 0
_08179484: .4byte 0x00000544
_08179488: .4byte 0x00000482
_0817948C:
	ldr r2, _08179494 @ =0x00000482
	adds r1, r1, r2
	movs r0, #3
	b _0817949E
	.align 2, 0
_08179494: .4byte 0x00000482
_08179498:
	ldr r0, _081794A4 @ =0x00000482
	adds r1, r1, r0
	movs r0, #1
_0817949E:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081794A4: .4byte 0x00000482

	thumb_func_start FUN_081794a8
FUN_081794a8: @ 0x081794A8
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	ldr r0, _081794D8 @ =0x00000FB8
	adds r2, r4, r0
	movs r3, #5
_081794BC:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081794BC
	ldr r2, _081794DC @ =0x00000FB4
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081794D8: .4byte 0x00000FB8
_081794DC: .4byte 0x00000FB4

	thumb_func_start FUN_081794e0
FUN_081794e0: @ 0x081794E0
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	ldr r4, _081794FC @ =0x00000FB8
	adds r2, r0, r4
_081794F0:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08179500
	movs r0, #1
	b _0817950A
	.align 2, 0
_081794FC: .4byte 0x00000FB8
_08179500:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _081794F0
	movs r0, #0
_0817950A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08179510
FUN_08179510: @ 0x08179510
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r4, _0817953C @ =0x00000FB4
	adds r3, r2, r4
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r4, #4
	adds r2, r2, r4
	adds r2, r2, r0
	strh r1, [r2]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817953C: .4byte 0x00000FB4

	thumb_func_start FUN_08179540
FUN_08179540: @ 0x08179540
	push {r4, r5, r6, lr}
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r0, r3
	movs r3, #0
	strb r3, [r1]
	ldr r4, _08179594 @ =0x00000469
	adds r1, r0, r4
	strb r2, [r1]
	ldr r6, _08179598 @ =0x0000046A
	adds r1, r0, r6
	strb r3, [r1]
	ldr r2, _0817959C @ =0x00000484
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #3
	adds r1, r0, r4
	movs r2, #1
	strb r2, [r1]
	ldr r5, _081795A0 @ =FUN_080e48d0
	movs r4, #0x10
	adds r6, #3
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _081795A4 @ =0x0000046B
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #0xe6
	adds r1, r0, r6
	strb r4, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r5, [r1]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08179594: .4byte 0x00000469
_08179598: .4byte 0x0000046A
_0817959C: .4byte 0x00000484
_081795A0: .4byte FUN_080e48d0
_081795A4: .4byte 0x0000046B

	thumb_func_start FUN_081795a8
FUN_081795a8: @ 0x081795A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081795ac
FUN_081795ac: @ 0x081795AC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08179688
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _081795E0 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _081795E4
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _081795EC
	.align 2, 0
_081795E0: .4byte 0x00000553
_081795E4:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_081795EC:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _08179688
	mov r5, sp
	adds r3, r4, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r5, r3]
	bl FUN_0823785c
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	ldrb r1, [r4, #5]
	adds r1, #0x10
	ands r1, r3
	asrs r1, r1, #6
	cmp r0, r1
	bne _08179688
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08179650
	rsbs r1, r1, #0
_08179650:
	ldr r0, _08179680 @ =0x000001FF
	cmp r1, r0
	bgt _08179688
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r1, #0x30
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ands r0, r3
	asrs r0, r0, #6
	ldr r3, _08179684 @ =0x00001021
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _0817968A
	.align 2, 0
_08179680: .4byte 0x000001FF
_08179684: .4byte 0x00001021
_08179688:
	movs r0, #0
_0817968A:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08179694
FUN_08179694: @ 0x08179694
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817976E
	movs r2, #0x20
	ldr r3, _081796C4 @ =0x00001008
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081796C8
	movs r0, #1
	b _081796CA
	.align 2, 0
_081796C4: .4byte 0x00001008
_081796C8:
	movs r0, #0
_081796CA:
	cmp r0, #0
	bne _0817976E
	ldr r1, _081796EC @ =0x0000A027
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0817976E
	movs r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081796F0
	movs r0, #1
	b _081796F2
	.align 2, 0
_081796EC: .4byte 0x0000A027
_081796F0:
	movs r0, #0
_081796F2:
	cmp r0, #0
	beq _08179738
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _0817972C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	ldr r2, _08179730 @ =0x00000226
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _08179734 @ =0x0000022E
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #0xa
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _0817976E
	.align 2, 0
_0817972C: .4byte 0xFFFFFEFF
_08179730: .4byte 0x00000226
_08179734: .4byte 0x0000022E
_08179738:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x28
	ldrh r2, [r0, #6]
	orrs r1, r2
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #8
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_0817976E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08179778
FUN_08179778: @ 0x08179778
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r6, #0
	movs r1, #1
	mov ip, r1
	movs r1, #0x80
	mov r8, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r3, r0, r1
	adds r1, #0xfd
	adds r4, r0, r1
	movs r7, #0x92
	lsls r7, r7, #1
	movs r5, #7
_081797A0:
	ldrb r0, [r4]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081797AE
	movs r0, #1
	b _081797B0
_081797AE:
	movs r0, #0
_081797B0:
	cmp r0, #0
	bne _081797DC
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081797C6
	subs r0, #1
	strh r0, [r1]
	b _081797DC
_081797C6:
	cmp r6, #1
	bgt _081797DC
	movs r0, #3
	strh r0, [r1]
	adds r2, r3, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	mov r0, r8
	orrs r0, r1
	strb r0, [r2]
	adds r6, #1
_081797DC:
	adds r3, r3, r7
	adds r4, r4, r7
	subs r5, #1
	cmp r5, #0
	bge _081797A0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081797f0
FUN_081797f0: @ 0x081797F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817983E
	movs r1, #0x30
	ldr r0, _08179828 @ =0x00001008
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817982C
	movs r0, #1
	b _0817982E
	.align 2, 0
_08179828: .4byte 0x00001008
_0817982C:
	movs r0, #0
_0817982E:
	cmp r0, #0
	bne _0817983E
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08179868
_0817983E:
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r3, _08179864 @ =0x00000474
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	b _0817988E
	.align 2, 0
_08179864: .4byte 0x00000474
_08179868:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r1, _081798D8 @ =0x00000474
	adds r2, r5, r1
	ldr r0, _081798DC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
_0817988E:
	strh r0, [r2]
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, _081798E0 @ =0x00001012
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	blt _081798A2
	b _08179A80
_081798A2:
	add r0, sp, #8
	mov r8, r0
	movs r4, #0xd4
	lsls r4, r4, #3
	add r4, sb
	movs r1, #0
	str r1, [sp, #0x18]
	movs r7, #0xcb
	lsls r7, r7, #3
	add r7, sb
	ldr r2, _081798E4 @ =0x00000674
	add r2, sb
	str r2, [sp, #0x1c]
	movs r6, #0xde
	lsls r6, r6, #3
	add r6, sb
	ldr r3, _081798E8 @ =0x00000755
	add r3, sb
	mov sl, r3
_081798C8:
	movs r1, #1
	mov r2, sl
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081798EC
	movs r0, #1
	b _081798EE
	.align 2, 0
_081798D8: .4byte 0x00000474
_081798DC: .4byte 0xFFFFF7FF
_081798E0: .4byte 0x00001012
_081798E4: .4byte 0x00000674
_081798E8: .4byte 0x00000755
_081798EC:
	movs r0, #0
_081798EE:
	cmp r0, #0
	beq _081798F4
	b _08179A54
_081798F4:
	movs r1, #0x80
	mov r3, sl
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08179904
	movs r0, #1
	b _08179906
_08179904:
	movs r0, #0
_08179906:
	cmp r0, #0
	beq _0817993E
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [sp, #0x18]
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0817993E
	movs r2, #0x20
	ldr r1, _08179934 @ =0x00001008
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _08179938
	movs r0, #1
	b _0817993A
	.align 2, 0
_08179934: .4byte 0x00001008
_08179938:
	movs r0, #0
_0817993A:
	cmp r0, #0
	beq _0817994E
_0817993E:
	ldrh r0, [r4, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r4, #6]
	ldrh r0, [r6, #6]
	orrs r0, r2
	strh r0, [r6, #6]
	b _08179A54
_0817994E:
	adds r0, r6, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	movs r0, #4
	mvns r3, r0
	ldrh r1, [r6, #6]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r0, _081799D8 @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	mov ip, r2
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, ip
	adds r1, r2, r0
	ldr r0, _081799DC @ =0x0000FFFF
	cmp r1, r0
	bgt _08179A54
	ldrh r0, [r4, #6]
	adds r1, r3, #0
	ands r1, r0
	strh r1, [r4, #6]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081799E0
	movs r0, #1
	b _081799E2
	.align 2, 0
_081799D8: .4byte 0x03002BE0
_081799DC: .4byte 0x0000FFFF
_081799E0:
	movs r0, #0
_081799E2:
	cmp r0, #0
	beq _08179A20
	ldrh r1, [r4, #6]
	ldr r0, _08179A14 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r4, #6]
	ldr r2, _08179A18 @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08179A1C @ =0x0000022E
	adds r0, r5, r3
	ldrh r2, [r0]
	adds r3, #0x12
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	b _08179A54
	.align 2, 0
_08179A14: .4byte 0xFFFFFEFF
_08179A18: .4byte 0x00000226
_08179A1C: .4byte 0x0000022E
_08179A20:
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r1
	strh r0, [r4, #6]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
_08179A54:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, [sp, #0x18]
	adds r1, r1, r0
	str r1, [sp, #0x18]
	adds r7, r7, r0
	ldr r2, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x1c]
	adds r6, r6, r0
	add sl, r0
	ldr r3, [sp, #0x10]
	adds r3, #1
	str r3, [sp, #0x10]
	ldr r0, _08179A90 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r3, r0
	bge _08179A80
	b _081798C8
_08179A80:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179A90: .4byte 0x00001012

	thumb_func_start FUN_08179a94
FUN_08179a94: @ 0x08179A94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08179AAE
	b _08179BF0
_08179AAE:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	bl FUN_081f7444
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08179AC2
	b _08179BF0
_08179AC2:
	movs r2, #8
	ldrsh r0, [r5, r2]
	movs r3, #0xc
	ldrsh r1, [r5, r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r7, _08179B70 @ =0x0000021D
	adds r3, r5, r7
	ldrb r4, [r3]
	movs r3, #2
	orrs r3, r4
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge _08179AEE
	b _08179BF0
_08179AEE:
	adds r0, r5, #0
	bl FUN_080e8f20
	ldr r2, _08179B74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08179B78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08179B7C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08179B84
	movs r2, #0x81
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r7, #0x27
	adds r3, r5, r7
	ldr r3, [r3]
	subs r7, #0xc
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp]
	ldr r7, _08179B80 @ =0x00000F9C
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	adds r7, #4
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	mov r4, r8
	str r4, [sp, #0x14]
	adds r7, #0x12
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl FUN_081f7248
	b _08179BE8
	.align 2, 0
_08179B70: .4byte 0x0000021D
_08179B74: .4byte 0x030046B8
_08179B78: .4byte 0x000003FF
_08179B7C: .4byte 0x0203B400
_08179B80: .4byte 0x00000F9C
_08179B84:
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r4, #0x91
	lsls r4, r4, #2
	adds r3, r5, r4
	ldr r3, [r3]
	movs r7, #0x8e
	lsls r7, r7, #2
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp]
	ldr r7, _08179BEC @ =0x00000F9E
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	adds r7, #4
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	adds r7, #0x10
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl FUN_081f7248
_08179BE8:
	movs r0, #1
	b _08179BF2
	.align 2, 0
_08179BEC: .4byte 0x00000F9E
_08179BF0:
	movs r0, #0
_08179BF2:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08179c00
FUN_08179c00: @ 0x08179C00
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x40
	adds r2, r4, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _08179C2C @ =0x00000103
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08179C2C: .4byte 0x00000103

	thumb_func_start FUN_08179c30
FUN_08179c30: @ 0x08179C30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08179C80 @ =0x00001012
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	cmp r1, r0
	bge _08179D34
	mov sl, r7
	movs r3, #0
	ldr r0, _08179C84 @ =0x00000734
	adds r6, r7, r0
	ldr r1, _08179C88 @ =0x0000075B
	adds r1, r1, r7
	mov sb, r1
	adds r0, #0x21
	adds r5, r7, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
_08179C70:
	ldrb r0, [r5]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08179C8C
	movs r0, #1
	b _08179C8E
	.align 2, 0
_08179C80: .4byte 0x00001012
_08179C84: .4byte 0x00000734
_08179C88: .4byte 0x0000075B
_08179C8C:
	movs r0, #0
_08179C8E:
	cmp r0, #0
	beq _08179CC4
	ldrb r0, [r5, #6]
	adds r4, r0, #0
	cmp r4, #0
	beq _08179CA0
	subs r0, #1
	strb r0, [r5, #6]
	b _08179CC4
_08179CA0:
	adds r0, r3, r7
	ldr r1, _08179CE4 @ =0x00000684
	adds r0, r0, r1
	movs r1, #0xd1
	lsls r1, r1, #1
	str r3, [sp, #4]
	bl FUN_0822b20c
	mov r0, sb
	strb r4, [r0]
	ldr r2, _08179CE8 @ =0x00000755
	add r2, sl
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r3, [sp, #4]
_08179CC4:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08179D12
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08179CEC
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08179CF6
	.align 2, 0
_08179CE4: .4byte 0x00000684
_08179CE8: .4byte 0x00000755
_08179CEC:
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08179CF6:
	str r1, [r0]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08179D12
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_08179D12:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r3, r3, r0
	adds r6, r6, r0
	add sb, r0
	adds r5, r5, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r1, _08179D44 @ =0x00001012
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	cmp r1, r0
	blt _08179C70
_08179D34:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179D44: .4byte 0x00001012

	thumb_func_start FUN_08179d48
FUN_08179d48: @ 0x08179D48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r7, [r0]
	ldr r2, _08179D88 @ =0x00000553
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08179D6A
	b _08179ED6
_08179D6A:
	movs r0, #0xa
	ldrsh r1, [r3, r0]
	subs r2, #0xe1
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _08179D7C
	cmp r0, #0
	bne _08179D8C
_08179D7C:
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08179DA2
	.align 2, 0
_08179D88: .4byte 0x00000553
_08179D8C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179DA4
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08179DA2:
	str r1, [r0]
_08179DA4:
	movs r2, #0
	str r2, [sp]
	ldr r1, _08179DD8 @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp]
	cmp r1, r0
	blt _08179DB8
	b _08179ED6
_08179DB8:
	mov sb, r7
	movs r2, #0
	mov sl, r2
	ldr r0, _08179DDC @ =0x00000674
	adds r6, r7, r0
	ldr r1, _08179DE0 @ =0x00000755
	adds r1, r1, r7
	mov r8, r1
_08179DC8:
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08179DE4
	movs r0, #1
	b _08179DE6
	.align 2, 0
_08179DD8: .4byte 0x00001012
_08179DDC: .4byte 0x00000674
_08179DE0: .4byte 0x00000755
_08179DE4:
	movs r0, #0
_08179DE6:
	cmp r0, #0
	bne _08179EB4
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08179E0E
	cmp r1, #0
	blt _08179E0E
	ldr r0, _08179E14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08179E0E
	ldr r0, _08179E18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08179E1C
_08179E0E:
	movs r4, #0
	b _08179E2A
	.align 2, 0
_08179E14: .4byte 0x030046A8
_08179E18: .4byte 0x030046AC
_08179E1C:
	ldr r0, _08179E40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08179E2A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #4]
	bl FUN_08234224
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _08179E44
	adds r0, #4
	b _08179E50
	.align 2, 0
_08179E40: .4byte 0x030046A4
_08179E44:
	ldr r0, _08179E64 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179E50:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08179E68
	cmp r2, #2
	beq _08179E6C
	b _08179E70
	.align 2, 0
_08179E64: .4byte 0x030046A4
_08179E68:
	ldrb r0, [r5, #4]
	b _08179E6E
_08179E6C:
	ldrb r0, [r5]
_08179E6E:
	subs r1, r1, r0
_08179E70:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _08179E82
	ldr r1, _08179E94 @ =0x00000472
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179E98
_08179E82:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08179EB2
	.align 2, 0
_08179E94: .4byte 0x00000472
_08179E98:
	ldr r0, _08179EE8 @ =0x00000734
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179EB4
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sl
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08179EB2:
	str r1, [r0]
_08179EB4:
	movs r2, #0x92
	lsls r2, r2, #1
	add sb, r2
	add sl, r2
	adds r6, r6, r2
	add r8, r2
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r1, _08179EEC @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp]
	cmp r1, r0
	bge _08179ED6
	b _08179DC8
_08179ED6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179EE8: .4byte 0x00000734
_08179EEC: .4byte 0x00001012

	thumb_func_start FUN_08179ef0
FUN_08179ef0: @ 0x08179EF0
	push {r4, lr}
	sub sp, #0xc
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, _08179F30 @ =0x00000FA8
	adds r4, r0, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _08179F28
	ldrh r0, [r1]
	str r0, [sp]
	ldr r1, _08179F34 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r4]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r4]
_08179F28:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08179F30: .4byte 0x00000FA8
_08179F34: .4byte 0xFFFF0000

	thumb_func_start FUN_08179f38
FUN_08179f38: @ 0x08179F38
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _08179FB0 @ =0x00000546
	adds r1, r0, r2
	ldrh r1, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _08179FD8
	ldr r0, _08179FB4 @ =0x00000F98
	adds r1, r3, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r2, _08179FB8 @ =0x00000F9A
	adds r1, r3, r2
	movs r0, #0xdc
	strh r0, [r1]
	ldr r0, _08179FBC @ =0x00000F9C
	adds r1, r3, r0
	movs r0, #0x1e
	strh r0, [r1]
	adds r2, #6
	adds r1, r3, r2
	movs r0, #8
	strh r0, [r1]
	ldr r0, _08179FC0 @ =0x00000F9E
	adds r1, r3, r0
	movs r0, #0x40
	strh r0, [r1]
	adds r2, #2
	adds r1, r3, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, _08179FC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08179FC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08179FCC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x64
	ldr r2, _08179FD0 @ =0x00000FA4
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08179FD4 @ =0x00000FA6
	adds r1, r3, r0
	movs r0, #1
	b _0817A030
	.align 2, 0
_08179FB0: .4byte 0x00000546
_08179FB4: .4byte 0x00000F98
_08179FB8: .4byte 0x00000F9A
_08179FBC: .4byte 0x00000F9C
_08179FC0: .4byte 0x00000F9E
_08179FC4: .4byte 0x030046B8
_08179FC8: .4byte 0x000003FF
_08179FCC: .4byte 0x0203B400
_08179FD0: .4byte 0x00000FA4
_08179FD4: .4byte 0x00000FA6
_08179FD8:
	ldr r1, _0817A038 @ =0x00000F98
	adds r0, r3, r1
	movs r2, #0x50
	strh r2, [r0]
	ldr r0, _0817A03C @ =0x00000F9A
	adds r1, r3, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _0817A040 @ =0x00000F9C
	adds r0, r3, r1
	strh r2, [r0]
	movs r2, #0xfa
	lsls r2, r2, #4
	adds r1, r3, r2
	movs r0, #0x28
	strh r0, [r1]
	ldr r0, _0817A044 @ =0x00000F9E
	adds r1, r3, r0
	movs r0, #0x64
	strh r0, [r1]
	adds r2, #2
	adds r1, r3, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _0817A048 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817A04C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0817A050 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xc8
	ldr r2, _0817A054 @ =0x00000FA4
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _0817A058 @ =0x00000FA6
	adds r1, r3, r0
	movs r0, #3
_0817A030:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0817A038: .4byte 0x00000F98
_0817A03C: .4byte 0x00000F9A
_0817A040: .4byte 0x00000F9C
_0817A044: .4byte 0x00000F9E
_0817A048: .4byte 0x030046B8
_0817A04C: .4byte 0x000003FF
_0817A050: .4byte 0x0203B400
_0817A054: .4byte 0x00000FA4
_0817A058: .4byte 0x00000FA6

	thumb_func_start FUN_0817a05c
FUN_0817a05c: @ 0x0817A05C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0817A074 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817A078
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817A07A
	.align 2, 0
_0817A074: .4byte 0x0000046C
_0817A078:
	movs r0, #0
_0817A07A:
	cmp r0, #0
	beq _0817A0B2
	ldr r4, _0817A154 @ =FUN_08171cc8
	movs r3, #0x22
	ldr r2, _0817A158 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0817A15C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0817A160 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
_0817A0B2:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _0817A0C4
	rsbs r3, r1, #0
_0817A0C4:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _0817A0D6
	rsbs r2, r0, #0
_0817A0D6:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_08177d34
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl FUN_08177890
	ldr r6, _0817A15C @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817A16C
	adds r0, r5, #0
	bl FUN_08175898
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _0817A158 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _0817A160 @ =0x00000553
	adds r0, r5, r4
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0817A164 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _0817A168 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _0817A176
	.align 2, 0
_0817A154: .4byte FUN_08171cc8
_0817A158: .4byte 0x0000046D
_0817A15C: .4byte 0x0000046B
_0817A160: .4byte 0x00000553
_0817A164: .4byte 0x0000046A
_0817A168: .4byte 0x00000484
_0817A16C:
	ldr r0, _0817A17C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817A176:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817A17C: .4byte 0x00000484

	thumb_func_start FUN_0817a180
FUN_0817a180: @ 0x0817A180
	ldr r1, _0817A18C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0817A190 @ =0x085ADB4C
	str r1, [r0]
	bx lr
	.align 2, 0
_0817A18C: .4byte 0x0000063C
_0817A190: .4byte 0x085ADB4C

	thumb_func_start FUN_0817a194
FUN_0817a194: @ 0x0817A194
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08178d40
	adds r0, r4, #0
	bl FUN_08179c30
	adds r0, r4, #0
	bl FUN_08179f38
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817a1b0
FUN_0817a1b0: @ 0x0817A1B0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08179778
	adds r0, r4, #0
	bl FUN_081797f0
	adds r0, r4, #0
	bl FUN_08179694
	adds r0, r4, #0
	bl FUN_08179468
	adds r0, r4, #0
	bl FUN_08177548
	adds r0, r4, #0
	bl FUN_08177908
	adds r0, r4, #0
	bl FUN_08178914
	adds r0, r4, #0
	bl FUN_081787a8
	adds r0, r4, #0
	bl FUN_0817909c
	adds r0, r4, #0
	bl FUN_08179d48
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817a1f8
FUN_0817a1f8: @ 0x0817A1F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _0817A30C @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0817A310 @ =0x000003DB
	bl PlaySound_082406e0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0817A300
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0817A300
	ldr r2, _0817A314 @ =0x0000046A
	adds r0, r7, r2
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817A258
	adds r0, r1, #0
	cmp r0, #0xc
	beq _0817A258
	cmp r0, #0xf
	bne _0817A300
_0817A258:
	ldr r6, _0817A318 @ =0x00000544
	adds r1, r7, r6
	movs r4, #0
	movs r5, #0
	movs r0, #0xf0
	strh r0, [r1]
	adds r0, #0x8c
	adds r2, r7, r0
	ldr r1, _0817A31C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	mov ip, r1
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r3, #1
	mvns r0, r3
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0817A320 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _0817A324 @ =0x0000046D
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
	movs r1, #5
	subs r6, #0xeb
	adds r0, r7, r6
	strb r4, [r0]
	ldr r2, _0817A328 @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817A32C @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	subs r1, #2
	adds r0, r7, r1
	mov r2, ip
	strh r2, [r0]
	movs r0, #0xfb
	lsls r0, r0, #4
	add r0, r8
	strh r5, [r0]
	ldr r2, _0817A330 @ =0x00001008
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r6, #0xac
	adds r0, r7, r6
	bl FUN_080139a0
_0817A300:
	movs r0, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0817A30C: .4byte 0xFFFFFEDF
_0817A310: .4byte 0x000003DB
_0817A314: .4byte 0x0000046A
_0817A318: .4byte 0x00000544
_0817A31C: .4byte 0xFFEFFFFF
_0817A320: .4byte FUN_080e48d0
_0817A324: .4byte 0x0000046D
_0817A328: .4byte 0x00000469
_0817A32C: .4byte 0x00000484
_0817A330: .4byte 0x00001008

	thumb_func_start FUN_0817a334
FUN_0817a334: @ 0x0817A334
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0817a194
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0817A36C @ =0x0000062C
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
	bl FUN_0817a1b0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0817A36C: .4byte 0x0000062C

	thumb_func_start FUN_0817a370
FUN_0817a370: @ 0x0817A370
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _0817A3D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0817A3D4 @ =0x030047A4
	ldr r1, _0817A3D8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0817A398
	b _0817A4A4
_0817A398:
	movs r1, #4
	ldr r0, _0817A3DC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817A3A6
	b _0817A4A4
_0817A3A6:
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0817A468
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0817A3E0 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0817A3E4
	movs r0, #1
	b _0817A3E6
	.align 2, 0
_0817A3D0: .4byte 0x03002BE0
_0817A3D4: .4byte 0x030047A4
_0817A3D8: .4byte 0x030047A0
_0817A3DC: .4byte 0x03002BC0
_0817A3E0: .4byte 0x030046A0
_0817A3E4:
	movs r0, #0
_0817A3E6:
	cmp r0, #0
	bne _0817A3F4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f07d0
	b _0817A4A4
_0817A3F4:
	adds r0, r4, #0
	bl FUN_081756e0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817A426
	ldr r1, _0817A464 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817A426
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0817A426:
	adds r0, r4, #0
	bl FUN_080eafdc
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e35b4
	adds r0, r4, #0
	bl FUN_080e191c
	adds r0, r4, #0
	bl FUN_080eb168
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _0817A4A6
	.align 2, 0
_0817A464: .4byte 0x00000624
_0817A468:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0817A49E
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0817A48C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0817A490
	movs r0, #1
	b _0817A492
	.align 2, 0
_0817A48C: .4byte 0x030046A0
_0817A490:
	movs r0, #0
_0817A492:
	cmp r0, #0
	beq _0817A49E
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f0914
_0817A49E:
	adds r0, r4, #0
	bl FUN_080f06ac
_0817A4A4:
	movs r0, #0
_0817A4A6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EnemySandWorm_Destroy
EnemySandWorm_Destroy: @ 0x0817A4AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_0817759c
	ldr r0, _0817A4E8 @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A4D6
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r5]
_0817A4D6:
	ldr r2, _0817A4EC @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817A4F0
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0817A4F8
	.align 2, 0
_0817A4E8: .4byte 0x0000044C
_0817A4EC: .4byte 0x0000025D
_0817A4F0:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0817A4F8:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0817A514 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0817A518
	movs r0, #1
	b _0817A51A
	.align 2, 0
_0817A514: .4byte 0x00000474
_0817A518:
	movs r0, #0
_0817A51A:
	cmp r0, #0
	beq _0817A526
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0817A526:
	ldr r1, _0817A580 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A53E
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0817A53E:
	ldr r0, _0817A584 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A556
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0817A556:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0817A56E
	adds r0, r4, #0
	bl FUN_08002a58
_0817A56E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817A588
	movs r0, #1
	b _0817A58A
	.align 2, 0
_0817A580: .4byte 0x0000044C
_0817A584: .4byte 0x0000044D
_0817A588:
	movs r0, #0
_0817A58A:
	cmp r0, #0
	beq _0817A596
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0817A596:
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

	thumb_func_start EnemySandWorm_Init
EnemySandWorm_Init: @ 0x0817A5B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x30]
	ldr r1, _0817A63C @ =0x00001008
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _0817A640 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08178fa4
	ldr r3, _0817A644 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817A650
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0817A648 @ =0x0000D636
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0817A64C @ =0x0000C102
	bl FUN_080e3804
	ldr r4, _0817A640 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xb4]
	cmp r1, #0x11
	beq _0817A62C
	cmp r1, #0x17
	bne _0817A630
_0817A62C:
	movs r0, #1
	strb r0, [r5, #7]
_0817A630:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _0817A6B8
	.align 2, 0
_0817A63C: .4byte 0x00001008
_0817A640: .4byte 0x000001DF
_0817A644: .4byte 0x0000025D
_0817A648: .4byte 0x0000D636
_0817A64C: .4byte 0x0000C102
_0817A650:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x20
	mov r8, r0
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, r8
	ldr r2, _0817A734 @ =0x05000002
	bl CpuSet
	ldr r0, _0817A738 @ =0x0000CB05
	ldr r1, _0817A73C @ =0x0000D636
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _0817A740 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _0817A744 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xb4]
_0817A6B8:
	str r7, [sp, #0x34]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _0817A748 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _0817A74C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _0817A734 @ =0x05000002
	bl CpuSet
	ldr r3, _0817A750 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x88]
	mov r3, r8
	str r3, [sp, #0x8c]
	str r6, [sp, #0x60]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _0817A724
	b _0817A884
_0817A724:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A754
	bl Script_GetValue
	adds r1, r0, #0
	b _0817A756
	.align 2, 0
_0817A734: .4byte 0x05000002
_0817A738: .4byte 0x0000CB05
_0817A73C: .4byte 0x0000D636
_0817A740: .4byte 0x000004B7
_0817A744: .4byte 0x000001DF
_0817A748: .4byte 0x0000046F
_0817A74C: .4byte 0x00000474
_0817A750: .4byte 0x000004B6
_0817A754:
	movs r1, #0
_0817A756:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0817A77C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x134]
	str r4, [sp, #0x138]
	cmp r0, #0
	beq _0817A780
	bl Script_GetValue
	adds r1, r0, #0
	b _0817A782
	.align 2, 0
_0817A77C: .4byte 0x00000251
_0817A780:
	movs r1, #0
_0817A782:
	ldr r2, _0817A7B8 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0817A7BC @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x134]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x140]
	cmp r0, #0
	beq _0817A7C0
	bl Script_GetValue
	b _0817A7C4
	.align 2, 0
_0817A7B8: .4byte 0x00000252
_0817A7BC: .4byte 0x000004B4
_0817A7C0:
	ldr r4, [sp, #0x134]
	ldrb r0, [r4]
_0817A7C4:
	strb r0, [r6]
	ldr r5, [sp, #0x134]
	ldrb r1, [r5]
	ldr r6, [sp, #0x140]
	ldrb r2, [r6]
	add r0, sp, #0x28
	bl FUN_08234f90
	add r0, sp, #0x28
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817A7FC
	cmp r1, #0
	blt _0817A7FC
	ldr r0, _0817A800 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817A7FC
	ldr r0, _0817A804 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817A808
_0817A7FC:
	movs r1, #0
	b _0817A816
	.align 2, 0
_0817A800: .4byte 0x030046A8
_0817A804: .4byte 0x030046AC
_0817A808:
	ldr r0, _0817A830 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817A816:
	ldr r2, _0817A834 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817A838
	adds r0, #4
	b _0817A844
	.align 2, 0
_0817A830: .4byte 0x030046A4
_0817A834: .4byte 0x00000256
_0817A838:
	ldr r0, _0817A858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817A844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817A85C
	cmp r2, #2
	beq _0817A860
	b _0817A864
	.align 2, 0
_0817A858: .4byte 0x030046A4
_0817A85C:
	ldrb r0, [r4, #4]
	b _0817A862
_0817A860:
	ldrb r0, [r4]
_0817A862:
	subs r1, r1, r0
_0817A864:
	ldr r3, _0817A87C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0817A880 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _0817A8C4
	.align 2, 0
_0817A87C: .4byte 0x00000472
_0817A880: .4byte 0x0000FFFF
_0817A884:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0817A8E8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0817A8EC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0817A8F0 @ =0x000004B4
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
	str r0, [sp, #0x38]
	str r5, [sp, #0x134]
	str r4, [sp, #0x138]
	str r3, [sp, #0x140]
_0817A8C4:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817A90E
	bl VM_GetPC
	cmp r0, #0
	beq _0817A8F4
	bl Script_GetValue
	adds r4, r0, #0
	b _0817A8F6
	.align 2, 0
_0817A8E8: .4byte 0x00000251
_0817A8EC: .4byte 0x00000252
_0817A8F0: .4byte 0x000004B4
_0817A8F4:
	movs r4, #0x30
_0817A8F6:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A908
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0817A90A
_0817A908:
	movs r5, #0x40
_0817A90A:
	mov r8, r4
	b _0817A914
_0817A90E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0817A914:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817A94C
	bl VM_GetPC
	cmp r0, #0
	beq _0817A92E
	bl Script_GetValue
	adds r6, r0, #0
	b _0817A930
_0817A92E:
	movs r6, #0
_0817A930:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A940
	bl Script_GetValue
	adds r1, r0, #0
	b _0817A942
_0817A940:
	movs r1, #0
_0817A942:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0817A956
_0817A94C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0817A956:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _0817ABE8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x90]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x144]
	lsls r4, r4, #0x10
	str r4, [sp, #0xb0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xbc]
	lsls r6, r6, #0x10
	str r6, [sp, #0xc4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xb8]
	ldr r4, _0817ABEC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x150]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xac]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x3c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x40]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x44]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x1b4]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r1, _0817ABF0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _0817ABF4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r3, _0817ABF8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _0817ABFC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _0817AC00 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x128]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _0817AC04 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	ldr r1, _0817AC08 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x168]
	ldr r3, _0817AC0C @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	ldr r4, _0817AC10 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _0817AC14 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x108]
	ldr r1, _0817AC18 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x198]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x19c]
	ldr r3, _0817AC1C @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x104]
	ldr r4, _0817AC20 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x1a0]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _0817AC24 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _0817AC28 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x194]
	ldr r4, _0817AC2C @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a8]
	ldr r6, _0817AC30 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x14c]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _0817AC34 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0817AC38 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x1ac]
	ldr r1, _0817AC3C @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1b0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _0817AC40 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _0817AC44 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x120]
	ldr r1, _0817AC48 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _0817AC4C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xc0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	ldr r5, _0817AC50 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	ldr r1, _0817AC54 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	ldr r2, _0817AC58 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x50]
	ldr r3, _0817AC5C @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _0817AC60 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x58]
	ldr r5, _0817AC64 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _0817AC68 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _0817AC6C @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x78]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	ldr r6, _0817AC70 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf4]
	ldr r3, _0817AC74 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd8]
	ldr r5, _0817AC78 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xdc]
	ldr r6, _0817AC7C @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	ldr r1, _0817AC80 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	ldr r2, _0817AC84 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xec]
	ldr r4, _0817AC88 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	cmp r0, #0
	bne _0817ABB8
	b _0817ACE4
_0817ABB8:
	movs r5, #0
	mov sl, r5
	movs r6, #0x8d
	lsls r6, r6, #2
	adds r6, r6, r7
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r7, r2
_0817ABD8:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AC8C
	bl Script_GetValue
	b _0817AC8E
	.align 2, 0
_0817ABE8: .4byte 0x0000025D
_0817ABEC: .4byte 0x0000025A
_0817ABF0: .4byte 0x0000047A
_0817ABF4: .4byte 0x0000047C
_0817ABF8: .4byte 0x0000047E
_0817ABFC: .4byte 0x000004A4
_0817AC00: .4byte 0x000005A4
_0817AC04: .4byte 0x000005C4
_0817AC08: .4byte 0x000005CC
_0817AC0C: .4byte 0x000005D4
_0817AC10: .4byte 0x000005DC
_0817AC14: .4byte 0x00000584
_0817AC18: .4byte 0x00000604
_0817AC1C: .4byte 0x0000021D
_0817AC20: .4byte 0x0000060C
_0817AC24: .4byte 0x000005E4
_0817AC28: .4byte 0x000005FC
_0817AC2C: .4byte 0x00000614
_0817AC30: .4byte 0x000005BC
_0817AC34: .4byte 0x000005EC
_0817AC38: .4byte 0x00000624
_0817AC3C: .4byte 0x0000058C
_0817AC40: .4byte 0x00000594
_0817AC44: .4byte 0x0000059C
_0817AC48: .4byte 0x000005B4
_0817AC4C: .4byte 0x00000543
_0817AC50: .4byte 0x00000496
_0817AC54: .4byte 0x00000469
_0817AC58: .4byte 0x0000046A
_0817AC5C: .4byte 0x00000484
_0817AC60: .4byte 0x0000046C
_0817AC64: .4byte 0x0000046D
_0817AC68: .4byte 0x0000046B
_0817AC6C: .4byte 0x00000553
_0817AC70: .4byte 0x00000572
_0817AC74: .4byte 0x0000055C
_0817AC78: .4byte 0x00000564
_0817AC7C: .4byte 0x00000565
_0817AC80: .4byte 0x00000566
_0817AC84: .4byte 0x00000567
_0817AC88: .4byte 0x0000056C
_0817AC8C:
	movs r0, #0x18
_0817AC8E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACA0
	bl Script_GetValue
	b _0817ACA2
_0817ACA0:
	movs r0, #0x18
_0817ACA2:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACB4
	bl Script_GetValue
	b _0817ACB6
_0817ACB4:
	movs r0, #0
_0817ACB6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACC8
	bl Script_GetValue
	b _0817ACCA
_0817ACC8:
	movs r0, #0
_0817ACCA:
	strh r0, [r6]
	movs r3, #2
	add sb, r3
	movs r6, #4
	add r8, r6
	adds r5, #2
	adds r4, #2
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _0817ACE4
	b _0817ABD8
_0817ACE4:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817AD30
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACFE
	bl Script_GetValue
	adds r4, r0, #0
	b _0817AD02
_0817ACFE:
	movs r4, #0x96
	lsls r4, r4, #1
_0817AD02:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD12
	bl Script_GetValue
	adds r6, r0, #0
	b _0817AD16
_0817AD12:
	movs r6, #0x96
	lsls r6, r6, #1
_0817AD16:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD24
	bl Script_GetValue
	b _0817AD2A
_0817AD24:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0817AD2A:
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	b _0817AD38
_0817AD30:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x130]
	strh r6, [r5]
_0817AD38:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0817AD50
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0817AD50:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x94]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817AE20
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD80
	bl Script_GetValue
	b _0817AD82
_0817AD80:
	movs r0, #0
_0817AD82:
	ldr r1, [sp, #0x144]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0817AD90
	asrs r1, r0, #1
	b _0817AD96
_0817AD90:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0817AD96:
	ldr r2, _0817ADAC @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADB0
	bl Script_GetValue
	b _0817ADB2
	.align 2, 0
_0817ADAC: .4byte 0x00000546
_0817ADB0:
	movs r0, #0
_0817ADB2:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADC8
	bl Script_GetValue
	b _0817ADCA
_0817ADC8:
	movs r0, #0
_0817ADCA:
	ldr r5, _0817ADE0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADE4
	bl Script_GetValue
	adds r1, r0, #0
	b _0817ADE6
	.align 2, 0
_0817ADE0: .4byte 0x00000187
_0817ADE4:
	movs r1, #0
_0817ADE6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADFC
	bl Script_GetValue
	b _0817ADFE
_0817ADFC:
	movs r0, #0
_0817ADFE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE16
	bl Script_GetValue
	adds r1, r0, #0
	b _0817AE18
_0817AE16:
	movs r1, #0
_0817AE18:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0817AE20:
	ldr r0, [sp, #0x144]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0xb0]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xbc]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xc4]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xb8]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817AE82
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE68
	bl Script_GetValue
	b _0817AE6A
_0817AE68:
	movs r0, #0
_0817AE6A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE7A
	bl Script_GetValue
	b _0817AE7C
_0817AE7A:
	movs r0, #0
_0817AE7C:
	ldr r2, _0817AEE4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0817AE82:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x150]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0817AEA6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x8c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0817AEA6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0817AEBE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0817AEBE:
	ldr r6, [sp, #0xac]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x34]
	add r2, sp, #0x28
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817AEE8
	movs r0, #1
	b _0817AEEA
	.align 2, 0
_0817AEE4: .4byte 0x00000189
_0817AEE8:
	movs r0, #0
_0817AEEA:
	cmp r0, #0
	beq _0817AEFA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0817AF24 @ =FUN_080f48ac
	ldr r1, [sp, #0x34]
	bl FUN_0807f558
_0817AEFA:
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0817AF06
	ldr r1, [r7, #0x44]
_0817AF06:
	ldr r0, [sp, #0x34]
	bl FUN_0823b46c
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0817AF28
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x3c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _0817AF34
	.align 2, 0
_0817AF24: .4byte FUN_080f48ac
_0817AF28:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x3c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_0817AF34:
	ldr r5, [sp, #0xb4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817AF82
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0817AF82
	cmp r0, #0x16
	beq _0817AF82
	cmp r0, #0x14
	beq _0817AF82
	cmp r0, #9
	beq _0817AF82
	cmp r0, #0x19
	beq _0817AF82
	cmp r0, #0x1a
	beq _0817AF82
	cmp r0, #0xd
	beq _0817AF82
	cmp r0, #0x1b
	beq _0817AF82
	cmp r0, #0x1f
	beq _0817AF82
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x134]
	ldrb r2, [r6]
	ldr r0, [sp, #0x138]
	ldrb r3, [r0]
	ldr r4, [sp, #0x140]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl FUN_0823b490
_0817AF82:
	movs r1, #8
	ldr r5, [sp, #0x60]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817AF92
	movs r0, #1
	b _0817AF94
_0817AF92:
	movs r0, #0
_0817AF94:
	cmp r0, #0
	beq _0817AFA2
	ldr r6, [sp, #0xcc]
	ldr r0, [r6]
	ldr r1, [sp, #0xc8]
	str r0, [r1]
	b _0817AFB4
_0817AFA2:
	ldr r2, [sp, #0xcc]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xc8]
	str r0, [r3]
_0817AFB4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x40]
	strh r0, [r4]
	ldr r5, [sp, #0x1b4]
	ldr r6, [sp, #0x44]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0817AFDE
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
	ldr r1, [sp, #0x34]
	strb r0, [r1, #5]
_0817AFDE:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817B0D2
	bl VM_GetPC
	cmp r0, #0
	beq _0817AFF6
	bl Script_GetValue
	b _0817AFF8
_0817AFF6:
	movs r0, #0
_0817AFF8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0817B008
	bl Script_GetValue
	b _0817B00A
_0817B008:
	movs r0, #0
_0817B00A:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0817B01A
	bl Script_GetValue
	b _0817B01C
_0817B01A:
	movs r0, #0
_0817B01C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x1b4]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817B044
	cmp r1, #0
	blt _0817B044
	ldr r0, _0817B048 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817B044
	ldr r0, _0817B04C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817B050
_0817B044:
	movs r1, #0
	b _0817B05E
	.align 2, 0
_0817B048: .4byte 0x030046A8
_0817B04C: .4byte 0x030046AC
_0817B050:
	ldr r0, _0817B078 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817B05E:
	ldr r4, _0817B07C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x1b4]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817B080
	adds r0, #4
	b _0817B08C
	.align 2, 0
_0817B078: .4byte 0x030046A4
_0817B07C: .4byte 0x00000256
_0817B080:
	ldr r0, _0817B0A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817B08C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817B0A4
	cmp r3, #2
	beq _0817B0A8
	b _0817B0AC
	.align 2, 0
_0817B0A0: .4byte 0x030046A4
_0817B0A4:
	ldrb r0, [r5, #4]
	b _0817B0AA
_0817B0A8:
	ldrb r0, [r5]
_0817B0AA:
	subs r2, r2, r0
_0817B0AC:
	ldr r5, _0817B0EC @ =0x00000472
	adds r1, r7, r5
	strh r2, [r1]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r2
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	movs r1, #0x83
	lsls r1, r1, #5
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_0817B0D2:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817B0FE
	bl VM_GetPC
	cmp r0, #0
	beq _0817B0F0
	bl Script_GetValue
	adds r1, r0, #0
	b _0817B0F6
	.align 2, 0
_0817B0EC: .4byte 0x00000472
_0817B0F0:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r2, #0
_0817B0F6:
	ldr r3, [sp, #0x30]
	ldr r4, _0817B15C @ =0x00000FB2
	adds r0, r3, r4
	strh r1, [r0]
_0817B0FE:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x30]
	ldr r6, _0817B160 @ =0x00000FA8
	adds r1, r5, r6
	movs r2, #0
	strh r0, [r1]
	movs r1, #0xfb
	lsls r1, r1, #4
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r7, #0
	bl FUN_081794a8
	movs r4, #0xd1
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	ldr r3, [sp, #0x64]
	strh r4, [r3]
	ldr r4, [sp, #0x68]
	strh r5, [r4]
	ldrh r0, [r2]
	adds r5, #0x70
	adds r0, r0, r5
	ldr r6, [sp, #0x6c]
	strh r0, [r6]
	ldrh r1, [r3]
	ldrh r0, [r2]
	adds r1, r1, r0
	ldr r2, [sp, #0x154]
	ldrb r0, [r2]
	cmp r0, #0
	bne _0817B164
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0817B170
	.align 2, 0
_0817B15C: .4byte 0x00000FB2
_0817B160: .4byte 0x00000FA8
_0817B164:
	ldr r2, [r7, #0x44]
	ldr r0, _0817B1A8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0817B170:
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0817B1C0
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0817B1AC
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
	b _0817B1B6
	.align 2, 0
_0817B1A8: .4byte 0x03003584
_0817B1AC:
	ldr r5, [sp, #0xb4]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_0817B1B6:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0817B1C0:
	adds r0, r7, #0
	bl FUN_08177fd4
	adds r0, r7, #0
	bl FUN_081778f0
	ldr r0, _0817B3C0 @ =0x0000102C
	ldr r6, [sp, #0x30]
	adds r0, r6, r0
	str r0, [sp, #0x1c0]
	ldr r1, _0817B3C4 @ =0x00001050
	adds r6, r6, r1
	mov r8, r6
	ldr r2, _0817B3C8 @ =FUN_0817a334
	mov sb, r2
	ldr r3, _0817B3CC @ =FUN_08178fdc
	mov sl, r3
	ldr r4, _0817B3D0 @ =FUN_08171294
	mov ip, r4
	movs r5, #0
	ldr r3, _0817B3D4 @ =FUN_0817239c
	ldr r4, _0817B3D8 @ =FUN_0817258c
	ldr r2, _0817B3DC @ =FUN_080f62b0
	ldr r6, _0817B3E0 @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x88]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1c0]
	ldr r1, [sp, #0x80]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0x84]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0x100]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0x10c]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0x114]
	str r6, [r0]
	ldr r1, _0817B3E4 @ =FUN_08170d4c
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r0, _0817B3E8 @ =FUN_08171188
	ldr r1, [sp, #0x128]
	str r0, [r1]
	ldr r6, _0817B3EC @ =FUN_08171298
	ldr r0, [sp, #0x158]
	str r6, [r0]
	ldr r1, [sp, #0x15c]
	str r2, [r1]
	ldr r2, [sp, #0x164]
	str r3, [r2]
	ldr r3, [sp, #0x168]
	str r4, [r3]
	ldr r0, _0817B3F0 @ =FUN_080f44f4
	ldr r4, [sp, #0x16c]
	str r0, [r4]
	ldr r0, _0817B3F4 @ =FUN_080f410c
	ldr r6, [sp, #0x174]
	str r0, [r6]
	ldr r0, [sp, #0x160]
	str r5, [r0]
	ldr r1, _0817B3F8 @ =FUN_081713c4
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r3, [sp, #0x1b8]
	ldr r4, [sp, #0x198]
	str r3, [r4]
	ldr r0, _0817B3FC @ =FUN_080f0430
	ldr r6, [sp, #0x19c]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0x104]
	strb r1, [r0]
	ldr r0, _0817B400 @ =0x085AD470
	ldr r2, [sp, #0x1a0]
	str r0, [r2]
	ldr r0, _0817B404 @ =FUN_080e73c8
	ldr r3, [sp, #0x188]
	str r0, [r3]
	ldr r4, [sp, #0x17c]
	str r5, [r4]
	ldr r6, [sp, #0x18c]
	str r5, [r6]
	ldr r0, [sp, #0x190]
	str r5, [r0]
	ldr r1, [sp, #0x194]
	str r5, [r1]
	ldr r2, [sp, #0x1a4]
	str r5, [r2]
	ldr r0, _0817B408 @ =FUN_080f0320
	ldr r3, [sp, #0x1a8]
	str r0, [r3]
	ldr r0, _0817B40C @ =FUN_080eff14
	ldr r4, [sp, #0x14c]
	str r0, [r4]
	ldr r0, _0817B410 @ =FUN_080e72b0
	ldr r6, [sp, #0x180]
	str r0, [r6]
	ldr r0, _0817B414 @ =FUN_08172384
	ldr r1, [sp, #0x178]
	str r0, [r1]
	ldr r0, _0817B418 @ =FUN_080f47c8
	ldr r2, [sp, #0x184]
	str r0, [r2]
	ldr r0, _0817B41C @ =FUN_080f54e4
	ldr r3, [sp, #0x170]
	str r0, [r3]
	ldr r4, [sp, #0x12c]
	str r5, [r4]
	ldr r0, _0817B420 @ =FUN_080f6e64
	ldr r6, [sp, #0x1ac]
	str r0, [r6]
	ldr r0, _0817B424 @ =FUN_080f64f0
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r0, _0817B428 @ =FUN_080f84d4
	ldr r2, [sp, #0x1b0]
	str r0, [r2]
	ldr r0, _0817B42C @ =FUN_080f624c
	ldr r3, [sp, #0x148]
	str r0, [r3]
	ldr r0, _0817B430 @ =FUN_080f56ec
	ldr r4, [sp, #0x118]
	str r0, [r4]
	ldr r0, _0817B434 @ =FUN_080f5b34
	ldr r6, [sp, #0x11c]
	str r0, [r6]
	ldr r0, _0817B438 @ =FUN_080f5fac
	ldr r1, [sp, #0x120]
	str r0, [r1]
	ldr r2, [sp, #0x13c]
	str r5, [r2]
	movs r0, #0x28
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, _0817B43C @ =0x0000060C
	adds r1, r7, r4
	ldr r0, _0817B440 @ =0x085ADB50
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _0817B444 @ =FUN_08178078
	str r0, [r1]
	ldr r1, _0817B448 @ =0x000005FC
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _0817B44C @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _0817B450 @ =FUN_08179540
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0817B454 @ =FUN_081795a8
	str r0, [r1]
	subs r4, #4
	adds r1, r7, r4
	ldr r0, _0817B458 @ =FUN_081795ac
	str r0, [r1]
	subs r6, #0x6c
	adds r1, r7, r6
	ldr r0, _0817B45C @ =FUN_0817a1f8
	str r0, [r1]
	ldr r0, _0817B460 @ =0x000005B4
	adds r1, r7, r0
	ldr r0, _0817B464 @ =FUN_08178660
	str r0, [r1]
	ldr r1, _0817B468 @ =0x00100200
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0817B46C @ =0x02000008
	ldr r3, [sp, #0x8c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0xc0
	ldr r4, [sp, #0x60]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r6, #0xaa
	lsls r6, r6, #2
	adds r4, r7, r6
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x1b4]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r2, _0817B470 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _0817B474 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08013cb8
	adds r0, r4, #0
	bl FUN_080139a0
	ldr r3, _0817B478 @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x98]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0817B486
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0817B3B0:
	bl VM_GetPC
	cmp r0, #0
	beq _0817B47C
	bl Script_GetValue
	b _0817B47E
	.align 2, 0
_0817B3C0: .4byte 0x0000102C
_0817B3C4: .4byte 0x00001050
_0817B3C8: .4byte FUN_0817a334
_0817B3CC: .4byte FUN_08178fdc
_0817B3D0: .4byte FUN_08171294
_0817B3D4: .4byte FUN_0817239c
_0817B3D8: .4byte FUN_0817258c
_0817B3DC: .4byte FUN_080f62b0
_0817B3E0: .4byte FUN_080f62ac
_0817B3E4: .4byte FUN_08170d4c
_0817B3E8: .4byte FUN_08171188
_0817B3EC: .4byte FUN_08171298
_0817B3F0: .4byte FUN_080f44f4
_0817B3F4: .4byte FUN_080f410c
_0817B3F8: .4byte FUN_081713c4
_0817B3FC: .4byte FUN_080f0430
_0817B400: .4byte 0x085AD470
_0817B404: .4byte FUN_080e73c8
_0817B408: .4byte FUN_080f0320
_0817B40C: .4byte FUN_080eff14
_0817B410: .4byte FUN_080e72b0
_0817B414: .4byte FUN_08172384
_0817B418: .4byte FUN_080f47c8
_0817B41C: .4byte FUN_080f54e4
_0817B420: .4byte FUN_080f6e64
_0817B424: .4byte FUN_080f64f0
_0817B428: .4byte FUN_080f84d4
_0817B42C: .4byte FUN_080f624c
_0817B430: .4byte FUN_080f56ec
_0817B434: .4byte FUN_080f5b34
_0817B438: .4byte FUN_080f5fac
_0817B43C: .4byte 0x0000060C
_0817B440: .4byte 0x085ADB50
_0817B444: .4byte FUN_08178078
_0817B448: .4byte 0x000005FC
_0817B44C: .4byte 0x000005AC
_0817B450: .4byte FUN_08179540
_0817B454: .4byte FUN_081795a8
_0817B458: .4byte FUN_081795ac
_0817B45C: .4byte FUN_0817a1f8
_0817B460: .4byte 0x000005B4
_0817B464: .4byte FUN_08178660
_0817B468: .4byte 0x00100200
_0817B46C: .4byte 0x02000008
_0817B470: .4byte 0x0000044C
_0817B474: .4byte 0x00001C1B
_0817B478: .4byte 0x0000044D
_0817B47C:
	movs r0, #0
_0817B47E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0817B3B0
_0817B486:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x9c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	cmp r2, #0
	beq _0817B4BE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x88]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0817B4BE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0817B4BE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x60]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817B4D0
	movs r0, #1
	b _0817B4D2
_0817B4D0:
	movs r0, #0
_0817B4D2:
	cmp r0, #0
	beq _0817B4E4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x8c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_0817B4E4:
	cmp r2, #1
	beq _0817B518
	movs r0, #0
	ldr r1, [sp, #0x48]
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r4, [sp, #0x74]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x58]
	strb r1, [r5]
	ldr r6, [sp, #0x128]
	ldr r2, [r6]
	ldr r3, [sp, #0x5c]
	strb r1, [r3]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r5, [sp, #0xd0]
	strb r0, [r5]
	ldr r6, [sp, #0xfc]
	str r2, [r6]
	ldr r1, [sp, #0xa4]
	strh r0, [r1]
_0817B518:
	movs r1, #2
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817B528
	movs r0, #1
	b _0817B52A
_0817B528:
	movs r0, #0
_0817B52A:
	cmp r0, #0
	beq _0817B544
	ldr r0, _0817B540 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	b _0817B54E
	.align 2, 0
_0817B540: .4byte 0x030046A0
_0817B544:
	ldr r0, [sp, #0x1b4]
	bl FUN_08241574
	ldr r5, [sp, #0x78]
	strh r0, [r5]
_0817B54E:
	movs r1, #0x40
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817B55E
	movs r0, #1
	b _0817B560
_0817B55E:
	movs r0, #0
_0817B560:
	cmp r0, #0
	beq _0817B570
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0817B594 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0817B570:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _0817B5A2
	ldr r0, _0817B598 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x78]
	ldrh r2, [r2]
	cmp r0, r2
	bne _0817B59C
	movs r0, #1
	b _0817B59E
	.align 2, 0
_0817B594: .4byte 0xFFFFFEFF
_0817B598: .4byte 0x030046A0
_0817B59C:
	movs r0, #0
_0817B59E:
	cmp r0, #0
	bne _0817B5AA
_0817B5A2:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0817B5AA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	cmp r0, #0
	bne _0817B692
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
	beq _0817B5EC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0817B5F4
_0817B5EC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817B5F4:
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
	beq _0817B618
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0817B620
_0817B618:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0817B620:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _0817B658 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0817B69C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0817B65C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0817B650
	ldrb r0, [r4, #5]
_0817B650:
	subs r0, #1
	strh r0, [r4, #8]
	b _0817B66C
	.align 2, 0
_0817B658: .4byte 0x0000FFFF
_0817B65C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0817B66C
	strh r1, [r4, #8]
_0817B66C:
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
	bne _0817B69C
	movs r0, #1
	strb r0, [r4, #7]
	b _0817B69C
_0817B692:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0817B69C:
	movs r0, #0
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _0817B6B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817B6B8
	movs r0, #1
	b _0817B6BA
	.align 2, 0
_0817B6B4: .4byte 0x030047A4
_0817B6B8:
	movs r0, #0
_0817B6BA:
	cmp r0, #0
	bne _0817B6FA
	ldr r4, [sp, #0xb4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817B6E2
	adds r0, r1, #0
	cmp r0, #7
	beq _0817B6E2
	cmp r0, #6
	beq _0817B6E2
	cmp r0, #0x15
	beq _0817B6E2
	cmp r0, #0x14
	beq _0817B6E2
	cmp r0, #0x17
	bne _0817B6FA
_0817B6E2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x60]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0817B6FA:
	adds r0, r7, #0
	bl FUN_08175898
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x48]
	strb r2, [r6]
	ldr r1, [sp, #0x4c]
	strb r2, [r1]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r4, [sp, #0x74]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x58]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x5c]
	strb r1, [r3]
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0xd0]
	strb r1, [r5]
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r0, [sp, #0xa4]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08175678
	adds r0, r7, #0
	bl FUN_0817a180
	ldr r1, _0817B7E0 @ =0x0000D636
	ldr r2, _0817B7E4 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_081763a8
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x1b4]
	bl FUN_08177f7c
	adds r0, r7, #0
	bl FUN_08178dc4
	adds r0, r7, #0
	bl FUN_08175898
	ldr r1, [sp, #0x60]
	ldrh r0, [r1]
	ldr r2, [sp, #0xf8]
	strh r0, [r2]
	ldr r3, [sp, #0xa0]
	ldrh r0, [r3]
	ldr r4, [sp, #0xf4]
	strh r0, [r4]
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	ldr r6, [sp, #0xd4]
	str r0, [r6]
	ldr r1, [sp, #0x8c]
	ldr r0, [r1]
	ldr r2, [sp, #0xd8]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xdc]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0xe0]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xe4]
	strb r0, [r1]
	ldr r2, [sp, #0x50]
	ldrb r0, [r2]
	ldr r3, [sp, #0xe8]
	strb r0, [r3]
	ldr r4, [sp, #0xfc]
	ldr r0, [r4]
	ldr r5, [sp, #0xec]
	str r0, [r5]
	ldr r6, [sp, #0xd0]
	ldrb r0, [r6]
	ldr r1, [sp, #0xf0]
	strb r0, [r1]
	ldr r2, _0817B7E8 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0817B7EC @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0817B7F0 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0817B7F4 @ =FUN_0817a370
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0817B7F8 @ =EnemySandWorm_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817B7FC
	movs r0, #0
	b _0817B800
	.align 2, 0
_0817B7E0: .4byte 0x0000D636
_0817B7E4: .4byte 0x0000C102
_0817B7E8: .4byte 0x0000057C
_0817B7EC: .4byte FUN_080f09e0
_0817B7F0: .4byte 0x0000061C
_0817B7F4: .4byte FUN_0817a370
_0817B7F8: .4byte EnemySandWorm_Destroy
_0817B7FC:
	movs r0, #1
	rsbs r0, r0, #0
_0817B800:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemySandWorm_Create
EnemySandWorm_Create: @ 0x0817B810
	push {r4, r5, lr}
	ldr r5, _0817B844 @ =0x00001068
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0817B83C
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySandWorm_Init
	cmp r0, #0
	bge _0817B83C
	adds r0, r4, #0
	bl EnemySandWorm_Destroy
	adds r0, r4, #0
	bl Free
_0817B83C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817B844: .4byte 0x00001068

	thumb_func_start FUN_0817b848
FUN_0817b848: @ 0x0817B848
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x44]
	ldr r0, _0817B8A4 @ =0x03002BE0
	mov r2, sp
	adds r4, r1, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r1, #0x1c]
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
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _0817B8A8 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0817B8AC
	asrs r1, r0, #0xc
	b _0817B8B2
	.align 2, 0
_0817B8A4: .4byte 0x03002BE0
_0817B8A8: .4byte 0x085B0A08
_0817B8AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817B8B2:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _0817B8D4 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0817B8D8
	asrs r1, r0, #0xc
	b _0817B8DE
	.align 2, 0
_0817B8D4: .4byte 0x085B0A08
_0817B8D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817B8DE:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r3, r5, r4
	strh r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _0817B904
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	b _0817B91A
_0817B904:
	cmp r1, #0
	beq _0817B918
	mov r0, sp
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Div
	b _0817B91A
_0817B918:
	movs r0, #0
_0817B91A:
	cmp r0, #0
	blt _0817B922
	asrs r0, r0, #1
	b _0817B928
_0817B922:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0817B928:
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
