	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08132314
FUN_08132314: @ 0x08132314
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08132348
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08132348
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08132350 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08132348:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132350: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08132354
FUN_08132354: @ 0x08132354
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
	cmp r0, #0
	beq _08132374
	b _08132A0E
_08132374:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08132384
	b _08132A08
_08132384:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081323AC
	ldr r3, _081323A8 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813239C
	b _08132A08
_0813239C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08132A08
	.align 2, 0
_081323A8: .4byte 0x0000048C
_081323AC:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081323BC
	b _08132A08
_081323BC:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081323CC
	b _081326D8
_081323CC:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081323DE
	b _08132A08
_081323DE:
	ldr r2, _08132470 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081323F2
	b _08132A08
_081323F2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08132400
	b _08132A08
_08132400:
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
	bne _08132418
	b _08132560
_08132418:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08132480
	ands r3, r1
	cmp r3, #0
	beq _08132480
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813243E
	rsbs r1, r1, #0
_0813243E:
	cmp r1, #0x20
	bgt _08132480
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08132474 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08132478 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813247C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08132A08
	.align 2, 0
_08132470: .4byte 0x0000A007
_08132474: .4byte 0x000004BE
_08132478: .4byte 0x0000048C
_0813247C: .4byte 0x0000044E
_08132480:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081324A8 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081324B0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081324AC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324A8: .4byte 0x0000048A
_081324AC: .4byte 0x03002BE0
_081324B0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081324CC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081324C8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324C8: .4byte 0x03002BE0
_081324CC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081324E8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081324E4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324E4: .4byte 0x03002BE0
_081324E8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08132504
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08132500 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_08132500: .4byte 0x03002BE0
_08132504:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08132516
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813251E
_08132516:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08132520
_0813251E:
	movs r3, #1
_08132520:
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
	ldr r5, _08132554 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08132542
	b _08132698
_08132542:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08132558
	movs r0, #1
	b _0813255A
	.align 2, 0
_08132554: .4byte 0x0000049C
_08132558:
	movs r0, #0
_0813255A:
	cmp r0, #0
	bne _0813263E
	b _08132654
_08132560:
	strh r2, [r7, #0x3e]
	ldr r1, _08132588 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08132590
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813258C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_08132588: .4byte 0x0000048A
_0813258C: .4byte 0x03002BE0
_08132590:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081325AC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081325A8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325A8: .4byte 0x03002BE0
_081325AC:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081325C8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081325C4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325C4: .4byte 0x03002BE0
_081325C8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081325E4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081325E0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325E0: .4byte 0x03002BE0
_081325E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081325F6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081325FE
_081325F6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08132600
_081325FE:
	movs r3, #1
_08132600:
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
	ldr r5, _08132634 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08132698
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08132638
	movs r0, #1
	b _0813263A
	.align 2, 0
_08132634: .4byte 0x0000049C
_08132638:
	movs r0, #0
_0813263A:
	cmp r0, #0
	beq _08132654
_0813263E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132650 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08132660
	.align 2, 0
_08132650: .4byte 0x03002BE0
_08132654:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08132698
_08132660:
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
_08132698:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081326C4
	ldr r5, _081326D0 @ =0x0000024E
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
	bls _081326C4
	strh r1, [r2]
_081326C4:
	ldr r5, _081326D4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08132A08
	.align 2, 0
_081326D0: .4byte 0x0000024E
_081326D4: .4byte 0x0000048C
_081326D8:
	ldr r0, _081326EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081326F0
	movs r0, #1
	b _081326F2
	.align 2, 0
_081326EC: .4byte 0x030047A4
_081326F0:
	movs r0, #0
_081326F2:
	cmp r0, #0
	beq _08132700
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08132708
_08132700:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08132708:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08132740 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08132744 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08132736
	cmp r2, #0x17
	bne _08132748
_08132736:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813276A
	.align 2, 0
_08132740: .4byte 0x0000048C
_08132744: .4byte 0x000001DF
_08132748:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08132736
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08132798 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813276A
	movs r1, #0
_0813276A:
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
	beq _081327A6
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813279C
	asrs r0, r0, #1
	b _081327A2
	.align 2, 0
_08132798: .4byte 0x00000187
_0813279C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081327A2:
	mov r2, sb
	strh r0, [r2]
_081327A6:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081327C4
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081327C0 @ =0x000001DD
	adds r1, r6, r4
	b _08132838
	.align 2, 0
_081327C0: .4byte 0x000001DD
_081327C4:
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
	bne _08132824
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08132824
	ldr r2, _08132814 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08132818 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813281C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08132820 @ =0x000001DD
	adds r1, r6, r4
	b _08132838
	.align 2, 0
_08132814: .4byte 0x030046B8
_08132818: .4byte 0x000003FF
_0813281C: .4byte 0x0203B400
_08132820: .4byte 0x000001DD
_08132824:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08132858 @ =0x000001DD
	adds r1, r6, r3
_08132838:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08132860
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813285C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132858: .4byte 0x000001DD
_0813285C: .4byte 0x03002BE0
_08132860:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813287C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08132878 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132878: .4byte 0x03002BE0
_0813287C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08132898
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132894 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132894: .4byte 0x03002BE0
_08132898:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081328B4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081328B0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_081328B0: .4byte 0x03002BE0
_081328B4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081328C6
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081328CE
_081328C6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081328D0
_081328CE:
	movs r3, #1
_081328D0:
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
	ldr r5, _08132904 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0813296C
	movs r1, #2
	ldr r2, _08132908 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813290C
	movs r0, #1
	b _0813290E
	.align 2, 0
_08132904: .4byte 0x0000049C
_08132908: .4byte 0x00000474
_0813290C:
	movs r0, #0
_0813290E:
	cmp r0, #0
	beq _08132928
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132924 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08132934
	.align 2, 0
_08132924: .4byte 0x03002BE0
_08132928:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813296C
_08132934:
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
_0813296C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081329A0
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081329A0
	ldr r0, _081329B8 @ =0x0000024E
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
	bls _081329A0
	strh r1, [r2]
_081329A0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081329BC @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081329C0 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081329C4
	movs r0, #1
	b _081329C6
	.align 2, 0
_081329B8: .4byte 0x0000024E
_081329BC: .4byte 0x030046A0
_081329C0: .4byte 0x00000934
_081329C4:
	movs r0, #0
_081329C6:
	ldr r1, _08132A20 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081329DE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081329DE:
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
_08132A08:
	adds r0, r6, #0
	bl FUN_08137e98
_08132A0E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08132A20: .4byte 0x0000048A

	thumb_func_start FUN_08132a24
FUN_08132a24: @ 0x08132A24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08132A40 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132A44
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132A46
	.align 2, 0
_08132A40: .4byte 0x0000046D
_08132A44:
	movs r0, #0
_08132A46:
	cmp r0, #0
	beq _08132B34
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081355c0
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08132A8C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132A98
	ldr r1, _08132A90 @ =0x000004B7
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
	ldr r0, _08132A94 @ =0x0000046E
	adds r7, r5, r0
	b _08132B1A
	.align 2, 0
_08132A8C: .4byte 0x0000025D
_08132A90: .4byte 0x000004B7
_08132A94: .4byte 0x0000046E
_08132A98:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08132B08 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08132B0C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08132AD2
	ldrb r0, [r7]
	cmp r0, #0
	bne _08132AD2
	cmp r4, #1
	bne _08132AC4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08132B1E
_08132AC4:
	cmp r4, #0
	bne _08132AD2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08132B1E
_08132AD2:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08132AE4
	movs r3, #6
_08132AE4:
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
	beq _08132B10
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08132B18
	.align 2, 0
_08132B08: .4byte 0x000004B7
_08132B0C: .4byte 0x0000046E
_08132B10:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08132B18:
	str r0, [r6, #8]
_08132B1A:
	movs r0, #0
	strb r0, [r7]
_08132B1E:
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0xf
	bl FUN_0813632c
	ldr r0, [r4]
	bl FUN_081362b0
	b _08132C18
_08132B34:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081355c0
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08132B78 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132B84
	ldr r1, _08132B7C @ =0x000004B7
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
	ldr r0, _08132B80 @ =0x0000046E
	adds r7, r5, r0
	b _08132C06
	.align 2, 0
_08132B78: .4byte 0x0000025D
_08132B7C: .4byte 0x000004B7
_08132B80: .4byte 0x0000046E
_08132B84:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08132BF4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08132BF8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08132BBE
	ldrb r0, [r7]
	cmp r0, #0
	bne _08132BBE
	cmp r4, #1
	bne _08132BB0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08132C0A
_08132BB0:
	cmp r4, #0
	bne _08132BBE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08132C0A
_08132BBE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08132BD0
	movs r3, #6
_08132BD0:
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
	beq _08132BFC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08132C04
	.align 2, 0
_08132BF4: .4byte 0x000004B7
_08132BF8: .4byte 0x0000046E
_08132BFC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08132C04:
	str r0, [r6, #8]
_08132C06:
	movs r0, #0
	strb r0, [r7]
_08132C0A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0813632c
_08132C18:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08132c24
FUN_08132c24: @ 0x08132C24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08132C7C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132C3C
	movs r0, #0
	strb r0, [r1]
_08132C3C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081355c0
	ldr r1, _08132C80 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08132C84 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132C90
	ldr r1, _08132C88 @ =0x000004B7
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
	ldr r0, _08132C8C @ =0x0000046E
	adds r7, r5, r0
	b _08132D12
	.align 2, 0
_08132C7C: .4byte 0x0000046D
_08132C80: .4byte 0x00000504
_08132C84: .4byte 0x0000025D
_08132C88: .4byte 0x000004B7
_08132C8C: .4byte 0x0000046E
_08132C90:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08132D00 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08132D04 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08132CCA
	ldrb r0, [r7]
	cmp r0, #0
	bne _08132CCA
	cmp r4, #1
	bne _08132CBC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08132D16
_08132CBC:
	cmp r4, #0
	bne _08132CCA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08132D16
_08132CCA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08132CDC
	movs r3, #6
_08132CDC:
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
	beq _08132D08
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08132D10
	.align 2, 0
_08132D00: .4byte 0x000004B7
_08132D04: .4byte 0x0000046E
_08132D08:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08132D10:
	str r0, [r6, #8]
_08132D12:
	movs r0, #0
	strb r0, [r7]
_08132D16:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x12
	bl FUN_0813652c
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08132d30
FUN_08132d30: @ 0x08132D30
	bx lr
	.align 2, 0

	thumb_func_start FUN_08132d34
FUN_08132d34: @ 0x08132D34
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08132D4C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132D50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132D52
	.align 2, 0
_08132D4C: .4byte 0x0000046D
_08132D50:
	movs r0, #0
_08132D52:
	cmp r0, #0
	beq _08132D74
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
	bne _08132D74
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_08132D74:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _08132D90
	ldr r2, _08132DDC @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_08132D90:
	ldr r1, _08132DE0 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08132DD6
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _08132DD6
	ldr r3, _08132DE4 @ =FUN_08132df0
	movs r2, #6
	ldr r0, _08132DE8 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08132DEC @ =0x0000046B
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
_08132DD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132DDC: .4byte 0x000001DF
_08132DE0: .4byte 0x00000466
_08132DE4: .4byte FUN_08132df0
_08132DE8: .4byte 0x0000046D
_08132DEC: .4byte 0x0000046B

	thumb_func_start FUN_08132df0
FUN_08132df0: @ 0x08132DF0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08132E08 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132E0E
	.align 2, 0
_08132E08: .4byte 0x0000046D
_08132E0C:
	movs r0, #0
_08132E0E:
	cmp r0, #0
	beq _08132E2A
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
_08132E2A:
	cmp r5, #0x28
	bne _08132E3C
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08132E3C:
	ldr r1, _08132E58 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08132E52
	cmp r5, #0x78
	ble _08132E52
	ldr r0, _08132E5C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08132E52:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132E58: .4byte 0x0000046E
_08132E5C: .4byte 0x0000046B

	thumb_func_start FUN_08132e60
FUN_08132e60: @ 0x08132E60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08132E78 @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08132E7C
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _08132E7E
	.align 2, 0
_08132E78: .4byte 0x0000046D
_08132E7C:
	movs r0, #0
_08132E7E:
	adds r5, r0, #0
	cmp r5, #0
	beq _08132EB6
	movs r2, #1
	ldr r1, _08132E9C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132EA0
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08132EAA
	.align 2, 0
_08132E9C: .4byte 0x0000025D
_08132EA0:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08132EAA:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _08132EFE
_08132EB6:
	cmp r1, #0x1a
	ble _08132EF8
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	ldr r3, _08132EEC @ =FUN_08132f08
	movs r2, #0xd
	ldr r0, _08132EF0 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08132EF4 @ =0x0000046B
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
	b _08132EFE
	.align 2, 0
_08132EEC: .4byte FUN_08132f08
_08132EF0: .4byte 0x0000046D
_08132EF4: .4byte 0x0000046B
_08132EF8:
	ldr r1, _08132F04 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08132EFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132F04: .4byte 0x0000046E

	thumb_func_start FUN_08132f08
FUN_08132f08: @ 0x08132F08
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08132F20 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132F24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132F26
	.align 2, 0
_08132F20: .4byte 0x0000046D
_08132F24:
	movs r0, #0
_08132F26:
	cmp r0, #0
	beq _08132F72
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _08132F4C @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132F50
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08132F5E
	.align 2, 0
_08132F4C: .4byte 0x0000025D
_08132F50:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08132F5E:
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
_08132F72:
	ldr r0, [r6, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne _08132F8A
	ldrh r0, [r1, #0xe]
	cmp r0, #4
	bne _08132F8A
	movs r0, #0xee
	bl PlaySound_082406e0
_08132F8A:
	ldr r1, _08133128 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132F96
	b _08133122
_08132F96:
	adds r0, r6, #0
	bl FUN_0813744c
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _0813312C @ =0x0000055C
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
	ldr r1, _08133130 @ =0x00000564
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
	ldr r1, _08133134 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08133138 @ =0x00000567
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
	ldr r1, _0813313C @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08133140 @ =0x00000572
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
	ldr r2, _08133144 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08133148 @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _0813314C @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _08133150 @ =0x00000544
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
	ldr r2, _08133154 @ =0x00000482
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
	ldr r1, _08133158 @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _0813315C @ =0x08252048
	adds r0, r6, #0
	ldr r2, _08133160 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08133164 @ =0x00000541
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
_08133122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08133128: .4byte 0x0000046E
_0813312C: .4byte 0x0000055C
_08133130: .4byte 0x00000564
_08133134: .4byte 0x00000566
_08133138: .4byte 0x00000567
_0813313C: .4byte 0x0000056C
_08133140: .4byte 0x00000572
_08133144: .4byte 0x0000046B
_08133148: .4byte 0x0000046C
_0813314C: .4byte 0x0000024E
_08133150: .4byte 0x00000544
_08133154: .4byte 0x00000482
_08133158: .4byte 0x00000464
_0813315C: .4byte 0x08252048
_08133160: .4byte 0x00000982
_08133164: .4byte 0x00000541

	thumb_func_start FUN_08133168
FUN_08133168: @ 0x08133168
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08133180 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133184
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133186
	.align 2, 0
_08133180: .4byte 0x0000046D
_08133184:
	movs r0, #0
_08133186:
	cmp r0, #0
	beq _08133192
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
_08133192:
	ldr r1, _081331AC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081331A4
	ldr r0, _081331B0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081331A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081331AC: .4byte 0x0000046E
_081331B0: .4byte 0x0000046B

	thumb_func_start FUN_081331b4
FUN_081331b4: @ 0x081331B4
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
	ldr r2, _081331DC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081331E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081331E2
	.align 2, 0
_081331DC: .4byte 0x0000046D
_081331E0:
	movs r0, #0
_081331E2:
	cmp r0, #0
	beq _0813321A
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
	bl FUN_081355c0
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081367a0
	movs r0, #2
	movs r7, #0xb3
	lsls r7, r7, #4
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813321A:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	str r6, [sp]
	mov r0, sp
	ldr r2, _08133274 @ =0x05000002
	bl CpuSet
	ldr r1, _08133278 @ =0x00000B4A
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0813323A
	adds r2, #0x64
_0813323A:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r2
	blt _0813328C
	ldr r3, _0813327C @ =FUN_0813344c
	movs r2, #0x26
	ldr r0, _08133280 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133284 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	ldr r7, _08133288 @ =0x00000553
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
	b _08133438
	.align 2, 0
_08133274: .4byte 0x05000002
_08133278: .4byte 0x00000B4A
_0813327C: .4byte FUN_0813344c
_08133280: .4byte 0x0000046D
_08133284: .4byte 0x0000046B
_08133288: .4byte 0x00000553
_0813328C:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _081332A0
	movs r6, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _081332A6
_081332A0:
	movs r6, #2
	ldrh r0, [r1]
	adds r0, #0x28
_081332A6:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081332CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	cmp r0, #0
	blt _081332D0
	asrs r1, r0, #0xc
	b _081332D6
	.align 2, 0
_081332CC: .4byte 0x085B0A08
_081332D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081332D6:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081332EE
	asrs r2, r0, #0xc
	b _081332F4
_081332EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081332F4:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldr r2, _0813333C @ =0x00002EE0
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_081370f4
	movs r2, #0
	mov sb, r2
	mov ip, r2
	ldr r3, _08133340 @ =0x00000B3A
	adds r0, r5, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp ip, r0
	blt _08133318
	b _08133438
_08133318:
	ldr r3, _08133344 @ =0x085B0A08
	movs r6, #0
	ldr r0, _08133348 @ =0x00000674
	adds r2, r5, r0
	movs r1, #0x90
	lsls r1, r1, #1
	mov r8, r1
_08133326:
	adds r0, r6, r5
	movs r7, #2
	mov sl, r7
	ldr r1, _0813334C @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08133350
	movs r0, #1
	b _08133352
	.align 2, 0
_0813333C: .4byte 0x00002EE0
_08133340: .4byte 0x00000B3A
_08133344: .4byte 0x085B0A08
_08133348: .4byte 0x00000674
_0813334C: .4byte 0x00000755
_08133350:
	movs r0, #0
_08133352:
	cmp r0, #0
	beq _08133422
	adds r0, r6, r5
	movs r1, #5
	ldr r7, _0813336C @ =0x00000755
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133370
	movs r0, #1
	b _08133372
	.align 2, 0
_0813336C: .4byte 0x00000755
_08133370:
	movs r0, #0
_08133372:
	cmp r0, #0
	bne _08133422
	mov r0, sb
	cmp r0, #0
	beq _08133388
	cmp r0, #1
	beq _081333D0
	ldrh r0, [r4, #8]
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	b _0813341C
_08133388:
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
	blt _081333AA
	asrs r1, r0, #0xc
	b _081333B0
_081333AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081333B0:
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
	bge _0813340E
	b _08133412
_081333D0:
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
	blt _081333EE
	asrs r1, r0, #0xc
	b _081333F4
_081333EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081333F4:
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
	blt _08133412
_0813340E:
	asrs r1, r0, #0xc
	b _08133418
_08133412:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08133418:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
_0813341C:
	strh r0, [r2, #4]
	movs r0, #1
	add sb, r0
_08133422:
	add r6, r8
	add r2, r8
	movs r1, #1
	add ip, r1
	ldr r7, _08133448 @ =0x00000B3A
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08133438
	b _08133326
_08133438:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133448: .4byte 0x00000B3A

	thumb_func_start FUN_0813344c
FUN_0813344c: @ 0x0813344C
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
	ldr r2, _08133478 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813347C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813347E
	.align 2, 0
_08133478: .4byte 0x0000046D
_0813347C:
	movs r0, #0
_0813347E:
	cmp r0, #0
	beq _0813348A
	ldr r1, _081334A0 @ =0x00000AD9
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0813348A:
	ldr r0, _081334A0 @ =0x00000AD9
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081334A4
	ldrb r3, [r6, #5]
	b _081334AE
	.align 2, 0
_081334A0: .4byte 0x00000AD9
_081334A4:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_081334AE:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081334D0 @ =0x085B0A08
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
	blt _081334D4
	asrs r1, r0, #0xc
	b _081334DA
	.align 2, 0
_081334D0: .4byte 0x085B0A08
_081334D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081334DA:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081334F2
	asrs r2, r0, #0xc
	b _081334F8
_081334F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081334F8:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _08133510 @ =0x00000AD9
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08133696
	.align 2, 0
_08133510: .4byte 0x00000AD9
_08133514:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #2
	ldr r3, _08133530 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08133534
	movs r0, #1
	b _08133536
	.align 2, 0
_08133530: .4byte 0x00000755
_08133534:
	movs r0, #0
_08133536:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08133540
	b _08133694
_08133540:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #5
	ldr r3, _0813355C @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133560
	movs r0, #1
	b _08133562
	.align 2, 0
_0813355C: .4byte 0x00000755
_08133560:
	movs r0, #0
_08133562:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _0813356E
	b _08133694
_0813356E:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #5
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _081335BC @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _081335C0 @ =0x0000076E
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
	beq _081335C4
	cmp r3, #1
	beq _08133618
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _0813368C
	.align 2, 0
_081335BC: .4byte 0x0000076C
_081335C0: .4byte 0x0000076E
_081335C4:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081335E4 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081335E4 @ =0x085B0A08
	cmp r0, #0
	blt _081335E8
	asrs r3, r0, #0xc
	b _081335EE
	.align 2, 0
_081335E4: .4byte 0x085B0A08
_081335E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081335EE:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133614 @ =0x00000674
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
	bge _0813366C
	b _08133674
	.align 2, 0
_08133614: .4byte 0x00000674
_08133618:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0813363C @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08133640
	asrs r3, r0, #0xc
	b _08133646
	.align 2, 0
_0813363C: .4byte 0x085B0A08
_08133640:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08133646:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133670 @ =0x00000674
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
	blt _08133674
_0813366C:
	asrs r2, r0, #0xc
	b _0813367A
	.align 2, 0
_08133670: .4byte 0x00000674
_08133674:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0813367A:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_0813368C:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08133694:
	mov r7, sl
_08133696:
	ldr r0, _081336D4 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _081336A4
	b _08133514
_081336A4:
	ldr r0, _081336D8 @ =0x00000B46
	add r0, r8
	ldr r2, [sp]
	ldrh r0, [r0]
	cmp r2, r0
	ble _081336E0
	ldr r3, _081336DC @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	movs r2, #0xb3
	lsls r2, r2, #4
	add r2, r8
	subs r0, #5
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081336EA
	.align 2, 0
_081336D4: .4byte 0x00000B3A
_081336D8: .4byte 0x00000B46
_081336DC: .4byte 0x0000046B
_081336E0:
	ldr r2, _081336FC @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_081370f4
_081336EA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081336FC: .4byte 0x0000FFFF

	thumb_func_start FUN_08133700
FUN_08133700: @ 0x08133700
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08133718 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813371C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813371E
	.align 2, 0
_08133718: .4byte 0x0000046D
_0813371C:
	movs r0, #0
_0813371E:
	cmp r0, #0
	beq _08133732
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08133732:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0813377C @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _0813378C
	ldr r3, _08133780 @ =FUN_08133820
	movs r2, #0x22
	ldr r0, _08133784 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133788 @ =0x0000046B
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
	b _08133816
	.align 2, 0
_0813377C: .4byte 0x05000002
_08133780: .4byte FUN_08133820
_08133784: .4byte 0x0000046D
_08133788: .4byte 0x0000046B
_0813378C:
	ldr r3, _081337A0 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _081337A4
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _081337AA
	.align 2, 0
_081337A0: .4byte 0x00000484
_081337A4:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_081337AA:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081337D0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081337D4
	asrs r1, r0, #0xc
	b _081337DA
	.align 2, 0
_081337D0: .4byte 0x085B0A08
_081337D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081337DA:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _081337F2
	asrs r2, r0, #0xc
	b _081337F8
_081337F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081337F8:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081370f4
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_08136de4
_08133816:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08133820
FUN_08133820: @ 0x08133820
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
	ldr r2, _0813384C @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133850
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133852
	.align 2, 0
_0813384C: .4byte 0x0000046D
_08133850:
	movs r0, #0
_08133852:
	cmp r0, #0
	beq _0813385E
	ldr r1, _08133874 @ =0x00000AD9
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0813385E:
	ldr r0, _08133874 @ =0x00000AD9
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08133878
	ldrb r3, [r6, #5]
	b _08133882
	.align 2, 0
_08133874: .4byte 0x00000AD9
_08133878:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_08133882:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081338A4 @ =0x085B0A08
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
	blt _081338A8
	asrs r1, r0, #0xc
	b _081338AE
	.align 2, 0
_081338A4: .4byte 0x085B0A08
_081338A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081338AE:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081338C6
	asrs r2, r0, #0xc
	b _081338CC
_081338C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081338CC:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _081338E4 @ =0x00000AD9
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08133A6A
	.align 2, 0
_081338E4: .4byte 0x00000AD9
_081338E8:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #2
	ldr r3, _08133904 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08133908
	movs r0, #1
	b _0813390A
	.align 2, 0
_08133904: .4byte 0x00000755
_08133908:
	movs r0, #0
_0813390A:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08133914
	b _08133A68
_08133914:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #5
	ldr r3, _08133930 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133934
	movs r0, #1
	b _08133936
	.align 2, 0
_08133930: .4byte 0x00000755
_08133934:
	movs r0, #0
_08133936:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _08133942
	b _08133A68
_08133942:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #5
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _08133990 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _08133994 @ =0x0000076E
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
	beq _08133998
	cmp r3, #1
	beq _081339EC
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08133A60
	.align 2, 0
_08133990: .4byte 0x0000076C
_08133994: .4byte 0x0000076E
_08133998:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081339B8 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081339B8 @ =0x085B0A08
	cmp r0, #0
	blt _081339BC
	asrs r3, r0, #0xc
	b _081339C2
	.align 2, 0
_081339B8: .4byte 0x085B0A08
_081339BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081339C2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _081339E8 @ =0x00000674
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
	bge _08133A40
	b _08133A48
	.align 2, 0
_081339E8: .4byte 0x00000674
_081339EC:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08133A10 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08133A14
	asrs r3, r0, #0xc
	b _08133A1A
	.align 2, 0
_08133A10: .4byte 0x085B0A08
_08133A14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08133A1A:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133A44 @ =0x00000674
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
	blt _08133A48
_08133A40:
	asrs r2, r0, #0xc
	b _08133A4E
	.align 2, 0
_08133A44: .4byte 0x00000674
_08133A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08133A4E:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_08133A60:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08133A68:
	mov r7, sl
_08133A6A:
	ldr r0, _08133AC4 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _08133A78
	b _081338E8
_08133A78:
	ldr r2, _08133AC8 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_081370f4
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _08133AB2
	ldr r4, _08133ACC @ =FUN_08133ad8
	movs r3, #0x23
	ldr r0, _08133AD0 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133AD4 @ =0x0000046B
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
_08133AB2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133AC4: .4byte 0x00000B3A
_08133AC8: .4byte 0x0000FFFF
_08133ACC: .4byte FUN_08133ad8
_08133AD0: .4byte 0x0000046D
_08133AD4: .4byte 0x0000046B

	thumb_func_start FUN_08133ad8
FUN_08133ad8: @ 0x08133AD8
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
	ldr r2, _08133B00 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133B04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133B06
	.align 2, 0
_08133B00: .4byte 0x0000046D
_08133B04:
	movs r0, #0
_08133B06:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _08133B64
	adds r0, r6, #0
	bl FUN_0813a160
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
	ldr r1, _08133BA8 @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08133BAC @ =0x000003D6
	bl PlaySound_082406e0
_08133B64:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081355c0
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08133BB0 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08133BBC
	ldr r1, _08133BB4 @ =0x000004B7
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
	ldr r2, _08133BB8 @ =0x0000046E
	adds r7, r6, r2
	b _08133C3E
	.align 2, 0
_08133BA8: .4byte 0xFFEFFFFF
_08133BAC: .4byte 0x000003D6
_08133BB0: .4byte 0x0000025D
_08133BB4: .4byte 0x000004B7
_08133BB8: .4byte 0x0000046E
_08133BBC:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08133C2C @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08133C30 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _08133BF6
	ldrb r0, [r7]
	cmp r0, #0
	bne _08133BF6
	cmp r4, #1
	bne _08133BE8
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133C42
_08133BE8:
	cmp r4, #0
	bne _08133BF6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133C42
_08133BF6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08133C08
	movs r3, #6
_08133C08:
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
	beq _08133C34
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08133C3C
	.align 2, 0
_08133C2C: .4byte 0x000004B7
_08133C30: .4byte 0x0000046E
_08133C34:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133C3C:
	str r0, [r5, #8]
_08133C3E:
	movs r0, #0
	strb r0, [r7]
_08133C42:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_08136de4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0813632c
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08133CB4
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08133CA4 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _08133CA8 @ =FUN_08133cd4
	movs r2, #0x24
	ldr r0, _08133CAC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133CB0 @ =0x0000046B
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
	b _08133CC4
	.align 2, 0
_08133CA4: .4byte 0xFFFFFEFF
_08133CA8: .4byte FUN_08133cd4
_08133CAC: .4byte 0x0000046D
_08133CB0: .4byte 0x0000046B
_08133CB4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08133CC4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08133cd4
FUN_08133cd4: @ 0x08133CD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _08133D3C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133CF2
	movs r0, #0
	strb r0, [r1]
_08133CF2:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081355c0
	ldr r1, _08133D40 @ =0x00000504
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _08133D44 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08133D50
	ldr r0, _08133D48 @ =0x000004B7
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
	ldr r1, _08133D4C @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _08133DD2
	.align 2, 0
_08133D3C: .4byte 0x0000046D
_08133D40: .4byte 0x00000504
_08133D44: .4byte 0x0000025D
_08133D48: .4byte 0x000004B7
_08133D4C: .4byte 0x0000046E
_08133D50:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _08133DC0 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _08133DC4 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _08133D8C
	ldrb r0, [r0]
	cmp r0, #0
	bne _08133D8C
	cmp r7, #1
	bne _08133D7E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133DD8
_08133D7E:
	cmp r7, #0
	bne _08133D8C
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133DD8
_08133D8C:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _08133D9E
	movs r3, #6
_08133D9E:
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
	beq _08133DC8
	ldr r0, [r4, #8]
	orrs r0, r5
	b _08133DD0
	.align 2, 0
_08133DC0: .4byte 0x000004B7
_08133DC4: .4byte 0x0000046E
_08133DC8:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133DD0:
	str r0, [r4, #8]
_08133DD2:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08133DD8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x12
	bl FUN_0813652c
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r6, #0
	movs r1, #0x14
	bl FUN_081370f4
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _08133EBE
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08133E32
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
	b _08133EA2
_08133E32:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _08133E66
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _08133E66
	cmp r4, #1
	bne _08133E58
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133EA8
_08133E58:
	cmp r4, #0
	bne _08133E66
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133EA8
_08133E66:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _08133E78
	movs r3, #6
_08133E78:
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
	beq _08133E98
	ldr r0, [r5, #8]
	orrs r0, r7
	b _08133EA0
_08133E98:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133EA0:
	str r0, [r5, #8]
_08133EA2:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08133EA8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0813632c
	ldr r0, _08133ED0 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_08133EBE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133ED0: .4byte 0x0000046B

	thumb_func_start FUN_08133ed4
FUN_08133ed4: @ 0x08133ED4
	push {lr}
	ldr r2, _08133EE8 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133EE4
	movs r0, #0
	strb r0, [r1]
_08133EE4:
	pop {r0}
	bx r0
	.align 2, 0
_08133EE8: .4byte 0x0000046D

	thumb_func_start FUN_08133eec
FUN_08133eec: @ 0x08133EEC
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
	ldr r2, _08133F14 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133F18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133F1A
	.align 2, 0
_08133F14: .4byte 0x0000046D
_08133F18:
	movs r0, #0
_08133F1A:
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
	beq _08133F90
	movs r0, #0x20
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08133FBC @ =0x00000B4B
	adds r1, r5, r3
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	ldr r1, _08133FC0 @ =0x00000B4A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _08133F90
	adds r5, r5, r1
_08133F82:
	adds r0, r6, #0
	bl FUN_08137858
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _08133F82
_08133F90:
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
	blt _08133FC4
	asrs r0, r0, #2
	b _08133FCA
	.align 2, 0
_08133FBC: .4byte 0x00000B4B
_08133FC0: .4byte 0x00000B4A
_08133FC4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08133FCA:
	adds r2, r0, #0
	ldr r4, [sp, #4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r1, r0
	cmp r0, #0
	blt _08133FE2
	asrs r0, r0, #2
	b _08133FE8
_08133FE2:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08133FE8:
	adds r1, r0, #0
	cmp r2, #0xc8
	ble _08133FF2
	movs r2, #0xc8
	b _08133FFC
_08133FF2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08133FFC
	adds r2, r0, #0
_08133FFC:
	cmp r1, #0xc8
	ble _08134004
	movs r1, #0xc8
	b _0813400E
_08134004:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0813400E
	adds r1, r0, #0
_0813400E:
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
	bne _08134034
	cmp r1, #0
	bne _08134034
	movs r0, #1
	b _08134036
_08134034:
	movs r0, #0
_08134036:
	cmp r0, #0
	beq _081340AC
	ldr r1, _081340BC @ =0x0000046B
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
	ldr r4, _081340C0 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _081340C4 @ =0x0000046D
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
	ldr r4, _081340C8 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081340CC @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _081340D0 @ =0x0000046C
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
_081340AC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081340BC: .4byte 0x0000046B
_081340C0: .4byte FUN_080e48d0
_081340C4: .4byte 0x0000046D
_081340C8: .4byte 0x00000469
_081340CC: .4byte 0x00000484
_081340D0: .4byte 0x0000046C

	thumb_func_start FUN_081340d4
FUN_081340d4: @ 0x081340D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x48
	adds r6, r0, #0
	mov sb, r1
	ldr r0, _081340F4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081340F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081340FA
	.align 2, 0
_081340F4: .4byte 0x0000046D
_081340F8:
	movs r0, #0
_081340FA:
	cmp r0, #0
	bne _08134100
	b _08134248
_08134100:
	ldrb r0, [r6, #5]
	add r1, sp, #0x30
	add r2, sp, #0x34
	bl FUN_081355c0
	ldr r1, _08134140 @ =0x00000504
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #0x30]
	ldr r4, [sp, #0x34]
	ldr r7, _08134144 @ =0x0000025D
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813414C
	subs r1, #0x4d
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
	ldr r2, _08134148 @ =0x0000046E
	adds r7, r6, r2
	b _081341CE
	.align 2, 0
_08134140: .4byte 0x00000504
_08134144: .4byte 0x0000025D
_08134148: .4byte 0x0000046E
_0813414C:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r3, _081341BC @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081341C0 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _08134186
	ldrb r0, [r7]
	cmp r0, #0
	bne _08134186
	cmp r4, #1
	bne _08134178
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081341D2
_08134178:
	cmp r4, #0
	bne _08134186
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081341D2
_08134186:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08134198
	movs r3, #6
_08134198:
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
	beq _081341C4
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _081341CC
	.align 2, 0
_081341BC: .4byte 0x000004B7
_081341C0: .4byte 0x0000046E
_081341C4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081341CC:
	str r0, [r5, #8]
_081341CE:
	movs r0, #0
	strb r0, [r7]
_081341D2:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #0x12
	bl FUN_0813652c
	ldr r4, _08134380 @ =0x0000046E
	adds r0, r6, r4
	movs r4, #0
	strb r4, [r0]
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
	adds r0, r6, #0
	bl FUN_080e8360
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _08134384 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08134388 @ =0x0000021E
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r4, [r0]
	ldr r3, _0813438C @ =0x00000202
	adds r0, r6, r3
	strh r4, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08134248:
	mov r0, sb
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081342AA
	ldr r3, _08134390 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08134394 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r2, sp, #0x38
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _08134398 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0813439C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _081343A0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r6, #0
	adds r0, #8
	ldrb r3, [r6, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	movs r4, #8
	str r4, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_080ddcc8
_081342AA:
	adds r0, r6, #0
	mov r1, sb
	bl FUN_08136720
	ldr r0, [r6, #0x44]
	mov r1, sb
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081342C6
	b _08134426
_081342C6:
	ldr r7, _081343A4 @ =0x0000046B
	adds r0, r6, r7
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_081378fc
	adds r0, r6, #0
	adds r0, #8
	bl FUN_08138504
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081342F4
	adds r0, r6, #0
	bl FUN_080e6658
_081342F4:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08134356
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x14]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #0x18]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r6]
	str r0, [sp, #0x2c]
	ldr r1, _08134390 @ =0xFFFF0000
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
_08134356:
	ldr r1, _081343A8 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081343B0
	ldr r0, _081343AC @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _081343C2
	.align 2, 0
_08134380: .4byte 0x0000046E
_08134384: .4byte 0xFFFEBE3F
_08134388: .4byte 0x0000021E
_0813438C: .4byte 0x00000202
_08134390: .4byte 0xFFFF0000
_08134394: .4byte 0x0000FFFF
_08134398: .4byte 0x030046B8
_0813439C: .4byte 0x000003FF
_081343A0: .4byte 0x0203B400
_081343A4: .4byte 0x0000046B
_081343A8: .4byte 0x000001DF
_081343AC: .4byte 0x030046A0
_081343B0:
	ldr r0, _08134434 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081343C2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08134438 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _0813443C @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
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
	ldr r4, _08134440 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08134444 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl FUN_080136b4
_08134426:
	add sp, #0x48
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134434: .4byte 0x030046A0
_08134438: .4byte FUN_080e48d0
_0813443C: .4byte 0x0000046D
_08134440: .4byte 0x00000469
_08134444: .4byte 0x00000484

	thumb_func_start FUN_08134448
FUN_08134448: @ 0x08134448
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08134468 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813446C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813446E
	.align 2, 0
_08134468: .4byte 0x0000046C
_0813446C:
	movs r0, #0
_0813446E:
	cmp r0, #0
	beq _081344B4
	ldr r3, _081344F0 @ =0x00000B34
	adds r0, r7, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r6, _081344F4 @ =0x00000B38
	adds r0, r7, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r6, _081344F8 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081344FC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08136ac8
_081344B4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134508
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08134500 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _08134504 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0813472C
	.align 2, 0
_081344F0: .4byte 0x00000B34
_081344F4: .4byte 0x00000B38
_081344F8: .4byte 0x0000046D
_081344FC: .4byte 0x00000553
_08134500: .4byte 0x00000469
_08134504: .4byte 0x0000046C
_08134508:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134534 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813453C
	ldr r3, _08134538 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813454C
	.align 2, 0
_08134534: .4byte 0x0000A02F
_08134538: .4byte 0x00000482
_0813453C:
	ldr r1, _08134570 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813454C
	movs r0, #1
	strh r0, [r2]
_0813454C:
	ldr r3, _08134574 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134578
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
	b _08134590
	.align 2, 0
_08134570: .4byte 0x00000482
_08134574: .4byte 0x0000025D
_08134578:
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
_08134590:
	ldr r1, _081345C8 @ =0x000004A4
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
	bge _081345B2
	rsbs r2, r2, #0
_081345B2:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _081345CC
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _081345C0
	rsbs r2, r2, #0
_081345C0:
	cmp r2, #0x20
	bgt _081345CC
	movs r0, #1
	b _08134636
	.align 2, 0
_081345C8: .4byte 0x000004A4
_081345CC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081345D8
	cmp r1, #0
	beq _08134634
_081345D8:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _081345FC @ =0x085B0A08
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
	blt _08134600
	asrs r1, r0, #0xc
	b _08134606
	.align 2, 0
_081345FC: .4byte 0x085B0A08
_08134600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134606:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08134624 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134628
	asrs r1, r0, #0xc
	b _0813462E
	.align 2, 0
_08134624: .4byte 0x085B0A08
_08134628:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813462E:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134634:
	movs r0, #0
_08134636:
	cmp r0, #0
	beq _081346E0
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08134690 @ =0x000004A4
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
	ble _08134698
	ldr r3, _08134694 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081346A6
	.align 2, 0
_08134690: .4byte 0x000004A4
_08134694: .4byte 0xFFFFFF00
_08134698:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081346A6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081346A6:
	cmp r1, #0
	bge _081346AC
	rsbs r1, r1, #0
_081346AC:
	cmp r1, #0x20
	ble _081346E0
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081346D8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081346DC @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _0813472C
	.align 2, 0
_081346D8: .4byte 0x00000469
_081346DC: .4byte 0x0000046A
_081346E0:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r0, _08134708 @ =0x00000B44
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0813470C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08134718
	.align 2, 0
_08134708: .4byte 0x00000B44
_0813470C:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_08134718:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r2, _08134734 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813472C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134734: .4byte 0x00000484

	thumb_func_start FUN_08134738
FUN_08134738: @ 0x08134738
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08134758 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813475C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813475E
	.align 2, 0
_08134758: .4byte 0x0000046C
_0813475C:
	movs r0, #0
_0813475E:
	cmp r0, #0
	beq _081347BA
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081347F4 @ =0x0000046D
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
	bl FUN_08136ac8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _081347F8 @ =0x00000B49
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _081347FC @ =0x00000B48
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081355f0
_081347BA:
	ldr r4, _08134800 @ =0x00000544
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _081347C8
	movs r0, #1
	strh r0, [r1]
_081347C8:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134804 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813480C
	ldr r3, _08134808 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813481C
	.align 2, 0
_081347F4: .4byte 0x0000046D
_081347F8: .4byte 0x00000B49
_081347FC: .4byte 0x00000B48
_08134800: .4byte 0x00000544
_08134804: .4byte 0x0000A02F
_08134808: .4byte 0x00000482
_0813480C:
	ldr r4, _08134840 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813481C
	movs r0, #1
	strh r0, [r2]
_0813481C:
	ldr r1, _08134844 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134848
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
	b _08134860
	.align 2, 0
_08134840: .4byte 0x00000482
_08134844: .4byte 0x0000025D
_08134848:
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
_08134860:
	ldr r2, _08134898 @ =0x000004A4
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
	bge _08134882
	rsbs r2, r2, #0
_08134882:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813489C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08134890
	rsbs r2, r2, #0
_08134890:
	cmp r2, #0x20
	bgt _0813489C
	movs r0, #1
	b _08134906
	.align 2, 0
_08134898: .4byte 0x000004A4
_0813489C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081348A8
	cmp r1, #0
	beq _08134904
_081348A8:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _081348CC @ =0x085B0A08
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
	blt _081348D0
	asrs r1, r0, #0xc
	b _081348D6
	.align 2, 0
_081348CC: .4byte 0x085B0A08
_081348D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081348D6:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081348F4 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _081348F8
	asrs r1, r0, #0xc
	b _081348FE
	.align 2, 0
_081348F4: .4byte 0x085B0A08
_081348F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081348FE:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134904:
	movs r0, #0
_08134906:
	cmp r0, #0
	beq _08134950
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08134978 @ =0x000004A4
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
_08134950:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r3, _0813497C @ =0x00000B44
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _08134980
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _0813498C
	.align 2, 0
_08134978: .4byte 0x000004A4
_0813497C: .4byte 0x00000B44
_08134980:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_0813498C:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r4, _081349C8 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	cmp r0, #0x50
	ble _081349D0
	movs r2, #8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081349CC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x1a
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _081349C8 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081349D4
	.align 2, 0
_081349C8: .4byte 0x00000484
_081349CC: .4byte 0x00000469
_081349D0:
	adds r0, #1
	str r0, [r1]
_081349D4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081349dc
FUN_081349dc: @ 0x081349DC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081349FC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134A00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134A02
	.align 2, 0
_081349FC: .4byte 0x0000046C
_08134A00:
	movs r0, #0
_08134A02:
	cmp r0, #0
	beq _08134A5E
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08134A8C @ =0x0000046D
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
	bl FUN_08136ac8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08134A90 @ =0x00000B49
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _08134A94 @ =0x00000B48
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081355f0
_08134A5E:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134AA4
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08134A98 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08134A9C @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08134AA0 @ =0x00000484
	b _08134CA4
	.align 2, 0
_08134A8C: .4byte 0x0000046D
_08134A90: .4byte 0x00000B49
_08134A94: .4byte 0x00000B48
_08134A98: .4byte 0x00000469
_08134A9C: .4byte 0x0000046A
_08134AA0: .4byte 0x00000484
_08134AA4:
	ldr r2, _08134AE0 @ =0x00000544
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08134AB2
	movs r0, #1
	strh r0, [r1]
_08134AB2:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134AE4 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08134AEC
	ldr r0, _08134AE8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08134AFC
	.align 2, 0
_08134AE0: .4byte 0x00000544
_08134AE4: .4byte 0x0000A02F
_08134AE8: .4byte 0x00000482
_08134AEC:
	ldr r1, _08134B20 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08134AFC
	movs r0, #1
	strh r0, [r2]
_08134AFC:
	ldr r3, _08134B24 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134B28
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
	b _08134B40
	.align 2, 0
_08134B20: .4byte 0x00000482
_08134B24: .4byte 0x0000025D
_08134B28:
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
_08134B40:
	ldr r4, _08134B78 @ =0x000004A4
	adds r0, r5, r4
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
	bge _08134B62
	rsbs r2, r2, #0
_08134B62:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08134B7C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08134B70
	rsbs r2, r2, #0
_08134B70:
	cmp r2, #0x20
	bgt _08134B7C
	movs r0, #1
	b _08134BE6
	.align 2, 0
_08134B78: .4byte 0x000004A4
_08134B7C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08134B88
	cmp r1, #0
	beq _08134BE4
_08134B88:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08134BAC @ =0x085B0A08
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
	blt _08134BB0
	asrs r1, r0, #0xc
	b _08134BB6
	.align 2, 0
_08134BAC: .4byte 0x085B0A08
_08134BB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134BB6:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08134BD4 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134BD8
	asrs r1, r0, #0xc
	b _08134BDE
	.align 2, 0
_08134BD4: .4byte 0x085B0A08
_08134BD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134BDE:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134BE4:
	movs r0, #0
_08134BE6:
	cmp r0, #0
	beq _08134C30
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _08134C58 @ =0x000004A4
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
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
_08134C30:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r0, _08134C5C @ =0x00000B44
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08134C60
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08134C6C
	.align 2, 0
_08134C58: .4byte 0x000004A4
_08134C5C: .4byte 0x00000B44
_08134C60:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_08134C6C:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r1, _08134CB4 @ =0x00000484
	adds r2, r5, r1
	ldr r1, [r2]
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r1, r0
	ble _08134CC0
	adds r0, r5, #0
	bl FUN_081355f0
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08134CB8 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
_08134CA4:
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08134CBC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08134CC4
	.align 2, 0
_08134CB4: .4byte 0x00000484
_08134CB8: .4byte 0x00000469
_08134CBC: .4byte 0x0000046C
_08134CC0:
	adds r0, r1, #1
	str r0, [r2]
_08134CC4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08134ccc
FUN_08134ccc: @ 0x08134CCC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08134CE4 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134CE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134CEA
	.align 2, 0
_08134CE4: .4byte 0x0000046C
_08134CE8:
	movs r0, #0
_08134CEA:
	cmp r0, #0
	beq _08134D2C
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08134D70 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08134D74 @ =0x0000046B
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
_08134D2C:
	ldr r0, _08134D78 @ =0x00000484
	adds r5, r4, r0
	ldr r0, [r5]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _08134D42
	ldr r0, _08134D7C @ =0x000003D7
	bl PlaySound_082406e0
_08134D42:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _08134D80 @ =0x05000002
	bl CpuSet
	ldr r0, [r5]
	cmp r0, #0x73
	ble _08134DDC
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08134D88
	ldr r5, _08134D84 @ =0xFFFFFF00
	adds r1, r1, r5
	b _08134D96
	.align 2, 0
_08134D70: .4byte 0x0000046D
_08134D74: .4byte 0x0000046B
_08134D78: .4byte 0x00000484
_08134D7C: .4byte 0x000003D7
_08134D80: .4byte 0x05000002
_08134D84: .4byte 0xFFFFFF00
_08134D88:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08134D96
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08134D96:
	movs r0, #0
	cmp r1, #0x1f
	bgt _08134D9E
	movs r0, #1
_08134D9E:
	cmp r0, #0
	beq _08134DDC
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _08134DD4 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r1, [r0]
	ldr r0, _08134DD8 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08134E7A
	.align 2, 0
_08134DD4: .4byte 0x00000469
_08134DD8: .4byte 0x0000046C
_08134DDC:
	ldr r1, _08134DF4 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x3f
	bgt _08134DF8
	movs r5, #0x14
	movs r2, #8
	mov ip, r2
	movs r6, #4
	movs r7, #0xc3
	lsls r7, r7, #5
	b _08134E12
	.align 2, 0
_08134DF4: .4byte 0x00000484
_08134DF8:
	cmp r0, #0x73
	bgt _08134E06
	movs r5, #0xe
	movs r3, #8
	mov ip, r3
	movs r6, #8
	b _08134E0E
_08134E06:
	movs r5, #3
	movs r0, #8
	mov ip, r0
	movs r6, #6
_08134E0E:
	movs r7, #0x9b
	lsls r7, r7, #3
_08134E12:
	ldr r3, _08134E30 @ =0x085B0A08
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
	blt _08134E34
	asrs r0, r0, #0xc
	b _08134E3A
	.align 2, 0
_08134E30: .4byte 0x085B0A08
_08134E34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08134E3A:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08134E4E
	asrs r2, r0, #0xc
	b _08134E54
_08134E4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08134E54:
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
	adds r2, r7, #0
	bl FUN_081370f4
	ldr r3, _08134E84 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08134E7A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134E84: .4byte 0x00000484

	thumb_func_start FUN_08134e88
FUN_08134e88: @ 0x08134E88
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08134EA0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134EA4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134EA6
	.align 2, 0
_08134EA0: .4byte 0x0000046C
_08134EA4:
	movs r0, #0
_08134EA6:
	cmp r0, #0
	beq _08134EEA
	ldr r4, _08134F30 @ =FUN_081331b4
	movs r3, #0x25
	ldr r2, _08134F34 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08134F38 @ =0x0000046B
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
	ldr r0, _08134F3C @ =0x0000019B
	bl PlaySound_082406e0
_08134EEA:
	ldr r1, _08134F40 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _08134F4C
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134F4C
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08134F44 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _08134F48 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08134FAA
	.align 2, 0
_08134F30: .4byte FUN_081331b4
_08134F34: .4byte 0x0000046D
_08134F38: .4byte 0x0000046B
_08134F3C: .4byte 0x0000019B
_08134F40: .4byte 0x00000553
_08134F44: .4byte 0x0000046A
_08134F48: .4byte 0x0000046C
_08134F4C:
	ldr r1, _08134F94 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08134FA0
	adds r0, r5, #0
	bl FUN_081355f0
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
	ldr r2, _08134F98 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _08134F9C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08134FAA
	.align 2, 0
_08134F94: .4byte 0x0000046B
_08134F98: .4byte 0x00000484
_08134F9C: .4byte 0xFFEFFFFF
_08134FA0:
	ldr r2, _08134FB0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08134FAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08134FB0: .4byte 0x00000484

	thumb_func_start FUN_08134fb4
FUN_08134fb4: @ 0x08134FB4
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
	ldr r2, _08134FE0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134FE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134FE6
	.align 2, 0
_08134FE0: .4byte 0x0000046C
_08134FE4:
	movs r0, #0
_08134FE6:
	cmp r0, #0
	beq _08135066
	ldr r3, _08135038 @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _0813503C @ =0x00000ADE
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _08135040 @ =0x00000B84
	add r7, sl
	ldr r0, _08135044 @ =0x030046A4
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
	beq _08135048
	adds r0, #4
	b _08135054
	.align 2, 0
_08135038: .4byte 0x00000256
_0813503C: .4byte 0x00000ADE
_08135040: .4byte 0x00000B84
_08135044: .4byte 0x030046A4
_08135048:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135054:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_08135066:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081350A0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081350A8
	ldr r3, _081350A4 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081350B8
	.align 2, 0
_081350A0: .4byte 0x0000A02F
_081350A4: .4byte 0x00000482
_081350A8:
	ldr r1, _081350DC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081350B8
	movs r0, #1
	strh r0, [r2]
_081350B8:
	ldr r3, _081350E0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081350E4
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
	b _081350FC
	.align 2, 0
_081350DC: .4byte 0x00000482
_081350E0: .4byte 0x0000025D
_081350E4:
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
_081350FC:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _08135118
	ldr r2, _08135114 @ =0xFFFFFF00
	adds r1, r1, r2
	b _08135126
	.align 2, 0
_08135114: .4byte 0xFFFFFF00
_08135118:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08135126
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08135126:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _08135130
	rsbs r0, r6, #0
_08135130:
	cmp r0, #8
	ble _08135180
	ldr r2, _08135150 @ =0x085B0A08
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
	blt _08135154
	asrs r0, r0, #0xc
	b _0813515A
	.align 2, 0
_08135150: .4byte 0x085B0A08
_08135154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813515A:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0813516E
	asrs r2, r0, #0xc
	b _08135174
_0813516E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08135174:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_08135180:
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
	blt _081351C8
	cmp r1, #0
	blt _081351C8
	ldr r0, _081351CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081351C8
	ldr r0, _081351D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081351D4
_081351C8:
	movs r7, #0
	b _081351E2
	.align 2, 0
_081351CC: .4byte 0x030046A8
_081351D0: .4byte 0x030046AC
_081351D4:
	ldr r0, _08135278 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081351E2:
	ldr r2, _0813527C @ =0x00000ADE
	add r2, sl
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, r7
	beq _08135232
	mov r4, sp
	ldr r2, _08135280 @ =0x00000B84
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
_08135232:
	ldr r2, _08135284 @ =0x0000A410
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_081370f4
	adds r0, r6, #0
	cmp r6, #0
	bge _08135244
	rsbs r0, r6, #0
_08135244:
	cmp r0, #7
	bgt _0813528C
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r7
	bne _081352B2
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
	ldr r2, _08135288 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081352B2
	.align 2, 0
_08135278: .4byte 0x030046A4
_0813527C: .4byte 0x00000ADE
_08135280: .4byte 0x00000B84
_08135284: .4byte 0x0000A410
_08135288: .4byte 0x00000484
_0813528C:
	cmp r6, #0
	ble _081352A4
	ldr r1, _081352A0 @ =0x00000482
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldrb r2, [r5, #5]
	adds r0, r0, r2
	b _081352B0
	.align 2, 0
_081352A0: .4byte 0x00000482
_081352A4:
	ldr r3, _081352CC @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_081352B0:
	strb r0, [r5, #5]
_081352B2:
	ldr r0, _081352D0 @ =0x00000484
	adds r1, r5, r0
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
_081352CC: .4byte 0x00000482
_081352D0: .4byte 0x00000484

	thumb_func_start FUN_081352d4
FUN_081352d4: @ 0x081352D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081352EC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081352F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081352F2
	.align 2, 0
_081352EC: .4byte 0x0000046C
_081352F0:
	movs r0, #0
_081352F2:
	cmp r0, #0
	beq _081353A6
	ldr r1, _08135354 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08135358 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0813535C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08135360 @ =0x00000553
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
	ldr r0, _08135364 @ =0x000001DD
	adds r1, r5, r0
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r5, r4
	ldrb r4, [r1]
	lsrs r6, r0, #3
	ldr r2, _08135368 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813536C
	asrs r1, r0, #0xc
	b _08135372
	.align 2, 0
_08135354: .4byte 0x000005A4
_08135358: .4byte 0x0000046D
_0813535C: .4byte 0x0000046B
_08135360: .4byte 0x00000553
_08135364: .4byte 0x000001DD
_08135368: .4byte 0x085B0A08
_0813536C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08135372:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813538A
	asrs r0, r0, #0xc
	b _08135390
_0813538A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08135390:
	strh r0, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_081353A6:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081370f4
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08135438
	adds r0, r5, #0
	bl FUN_081355f0
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08135424 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08135428 @ =0x0000046B
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
	ldr r1, _0813542C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08135430 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	ldr r0, _08135434 @ =0x000003D7
	bl PlaySound_082406e0
	b _08135442
	.align 2, 0
_08135424: .4byte 0x0000046D
_08135428: .4byte 0x0000046B
_0813542C: .4byte 0x0000046A
_08135430: .4byte 0x00000484
_08135434: .4byte 0x000003D7
_08135438:
	ldr r0, _08135448 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08135442:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08135448: .4byte 0x00000484

	thumb_func_start FUN_0813544c
FUN_0813544c: @ 0x0813544C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08135464 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08135468
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813546A
	.align 2, 0
_08135464: .4byte 0x0000046C
_08135468:
	movs r0, #0
_0813546A:
	cmp r0, #0
	beq _08135510
	ldr r1, _081354C0 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _081354C4 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081354C8 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081354CC @ =0x00000553
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
	ldr r2, _081354D0 @ =0x085B0A08
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
	blt _081354D4
	asrs r1, r0, #0xc
	b _081354DA
	.align 2, 0
_081354C0: .4byte 0x000005A4
_081354C4: .4byte 0x0000046D
_081354C8: .4byte 0x0000046B
_081354CC: .4byte 0x00000553
_081354D0: .4byte 0x085B0A08
_081354D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081354DA:
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
	blt _081354F4
	asrs r2, r0, #0xc
	b _081354FA
_081354F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081354FA:
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
_08135510:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081370f4
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08135598
	adds r0, r5, #0
	bl FUN_081355f0
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08135588 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0813558C @ =0x0000046B
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
	ldr r1, _08135590 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08135594 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081355A2
	.align 2, 0
_08135588: .4byte 0x0000046D
_0813558C: .4byte 0x0000046B
_08135590: .4byte 0x0000046A
_08135594: .4byte 0x00000484
_08135598:
	ldr r0, _081355A8 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081355A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081355A8: .4byte 0x00000484

	thumb_func_start FUN_081355ac
FUN_081355ac: @ 0x081355AC
	ldr r1, _081355B8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081355BC @ =0x085AD72C
	str r1, [r0]
	bx lr
	.align 2, 0
_081355B8: .4byte 0x00000634
_081355BC: .4byte 0x085AD72C

	thumb_func_start FUN_081355c0
FUN_081355c0: @ 0x081355C0
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
	ble _081355E4
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _081355E8
_081355E4:
	str r1, [r3]
	movs r0, #0
_081355E8:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081355f0
FUN_081355f0: @ 0x081355F0
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
	ldr r3, _08135650 @ =0x000004A4
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
_08135624:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _08135624
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x20]
	ldr r2, _08135654 @ =0x00000256
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08135658
	adds r0, #4
	b _08135664
	.align 2, 0
_08135650: .4byte 0x000004A4
_08135654: .4byte 0x00000256
_08135658:
	ldr r0, _08135684 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135664:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	subs r0, #1
	cmp r0, #1
	bls _081356B8
	ldr r3, [sp, #0x24]
	ldr r4, _08135688 @ =0x00000B48
	adds r0, r3, r4
	ldrb r3, [r0]
	cmp r3, #2
	bne _0813568C
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _081356BA
	.align 2, 0
_08135684: .4byte 0x030046A4
_08135688: .4byte 0x00000B48
_0813568C:
	cmp r3, #3
	bne _081356B8
	ldr r2, _081356AC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081356B0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081356B4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x2c]
	adds r6, r2, r0
	ands r6, r3
	b _081356BA
	.align 2, 0
_081356AC: .4byte 0x030046B8
_081356B0: .4byte 0x000003FF
_081356B4: .4byte 0x0203B400
_081356B8:
	ldr r6, [sp, #0x2c]
_081356BA:
	ldr r4, [sp, #0x24]
	ldr r0, _0813571C @ =0x00000B48
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _081356E2
	ldr r1, [sp, #0x20]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08135720 @ =0x00000B49
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_081356E2:
	movs r3, #3
	str r3, [sp, #0x30]
_081356E6:
	ldr r4, [sp, #0x24]
	ldr r1, _08135720 @ =0x00000B49
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _081356F6
	rsbs r0, r0, #0
_081356F6:
	cmp r0, #2
	bne _081356FC
	b _08135A9E
_081356FC:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _08135706
	rsbs r0, r0, #0
_08135706:
	cmp r0, #2
	bne _0813570C
	b _08135A9E
_0813570C:
	cmp r6, #1
	beq _08135740
	cmp r6, #1
	bgt _08135724
	cmp r6, #0
	beq _0813572E
	b _08135794
	.align 2, 0
_0813571C: .4byte 0x00000B48
_08135720: .4byte 0x00000B49
_08135724:
	cmp r6, #2
	beq _08135760
	cmp r6, #3
	beq _08135774
	b _08135794
_0813572E:
	ldr r3, [sp, #0x20]
	ldr r4, _0813573C @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_0813573C: .4byte 0x00000256
_08135740:
	ldr r0, [sp, #0x20]
	ldr r2, _08135758 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _0813575C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_08135758: .4byte 0x00000256
_0813575C: .4byte 0x030046A4
_08135760:
	ldr r3, [sp, #0x20]
	ldr r4, _08135770 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_08135770: .4byte 0x00000256
_08135774:
	ldr r0, [sp, #0x20]
	ldr r2, _0813578C @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _08135790 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_0813578C: .4byte 0x00000256
_08135790: .4byte 0x030046A4
_08135794:
	ldr r1, [sp, #0x20]
	ldr r2, _081357B0 @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_0813579E:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081357B4
	adds r0, #4
	b _081357C0
	.align 2, 0
_081357B0: .4byte 0x00000256
_081357B4:
	ldr r3, _081357DC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081357C0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081357E0
	adds r0, #4
	b _081357EC
	.align 2, 0
_081357DC: .4byte 0x030046A4
_081357E0:
	ldr r1, _08135804 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081357EC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08135808
	adds r0, #4
	b _08135814
	.align 2, 0
_08135804: .4byte 0x030046A4
_08135808:
	ldr r2, _08135858 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135814:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _08135858 @ =0x030046A4
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
	beq _0813585C
	adds r0, #4
	b _08135868
	.align 2, 0
_08135858: .4byte 0x030046A4
_0813585C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135868:
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
	beq _0813588C
	adds r0, #4
	b _08135898
_0813588C:
	ldr r1, _081358AC @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135898:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081358B0
	cmp r2, #2
	beq _081358B4
	b _081358B8
	.align 2, 0
_081358AC: .4byte 0x030046A4
_081358B0:
	ldrb r0, [r4, #4]
	b _081358B6
_081358B4:
	ldrb r0, [r4]
_081358B6:
	subs r1, r1, r0
_081358B8:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _08135900 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08135900 @ =0x030046A4
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
	beq _08135904
	adds r0, #4
	b _08135910
	.align 2, 0
_08135900: .4byte 0x030046A4
_08135904:
	ldr r3, _0813593C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135910:
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
	beq _08135940
	adds r0, #4
	b _0813594C
	.align 2, 0
_0813593C: .4byte 0x030046A4
_08135940:
	ldr r3, _08135960 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0813594C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135964
	cmp r2, #2
	beq _08135968
	b _0813596C
	.align 2, 0
_08135960: .4byte 0x030046A4
_08135964:
	ldrb r0, [r5, #4]
	b _0813596A
_08135968:
	ldrb r0, [r5]
_0813596A:
	subs r1, r1, r0
_0813596C:
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
	beq _0813598C
	b _08135A9E
_0813598C:
	cmp r2, #0
	beq _08135A82
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081359B2
	cmp r6, #1
	bne _081359AA
	mov r0, sl
	cmp r0, #1
	bne _081359CC
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081359DE
	b _08135A9E
_081359AA:
	cmp r6, #3
	bne _08135A9E
	mov r4, sl
	b _081359D8
_081359B2:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _081359DE
	cmp r6, #0
	bne _081359D2
	mov r3, sl
	cmp r3, #2
	bne _081359CC
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081359DE
	b _08135A9E
_081359CC:
	cmp r1, #0
	beq _081359DE
	b _08135A9E
_081359D2:
	cmp r6, #2
	bne _08135A9E
	mov r0, sl
_081359D8:
	ldr r0, _081359F4 @ =0xFFFFFF00
	cmp r1, r0
	bne _08135A9E
_081359DE:
	mov r3, sl
	cmp r3, #1
	bne _08135A0E
	cmp r6, #1
	bne _08135A02
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081359F8
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135A3A
	.align 2, 0
_081359F4: .4byte 0xFFFFFF00
_081359F8:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08135A48
	b _08135A9E
_08135A02:
	cmp r6, #3
	bne _08135A9E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _08135A38
	b _08135A44
_08135A0E:
	mov r0, sl
	cmp r0, #2
	bne _08135A54
	cmp r6, #0
	bne _08135A2E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08135A28
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08135A48
	b _08135A9E
_08135A28:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135A3A
_08135A2E:
	cmp r6, #2
	bne _08135A9E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08135A44
_08135A38:
	ldr r0, _08135A40 @ =0xFFFFFF00
_08135A3A:
	cmp r1, r0
	beq _08135A48
	b _08135A9E
	.align 2, 0
_08135A40: .4byte 0xFFFFFF00
_08135A44:
	cmp r1, #0
	bne _08135A9E
_08135A48:
	mov r4, sl
	cmp r4, #2
	bne _08135A54
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _08135A60
_08135A54:
	mov r1, sl
	cmp r1, #1
	bne _08135A72
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _08135A72
_08135A60:
	adds r0, r2, #0
	cmp r2, #0
	bge _08135A68
	rsbs r0, r2, #0
_08135A68:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _08135A82
	b _08135A9E
_08135A72:
	adds r0, r2, #0
	cmp r0, #0
	bge _08135A7A
	rsbs r0, r0, #0
_08135A7A:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08135A84
_08135A82:
	adds r5, r7, #0
_08135A84:
	cmp r5, #0
	blt _08135A9E
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _08135A92
	str r5, [sp, #0x38]
	b _08135A9E
_08135A92:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_08135A9E:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _08135AB0
	b _081356E6
_08135AB0:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _08135AB8
	b _08135C10
_08135AB8:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _08135B66
	mov r6, sp
_08135AC8:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_08138744
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08135B58
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _08135B14 @ =0x030046A4
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
	beq _08135B18
	adds r0, #4
	b _08135B22
	.align 2, 0
_08135B14: .4byte 0x030046A4
_08135B18:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135B22:
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
	bl FUN_08138770
	ldr r3, [sp, #0x24]
	ldr r4, _08135B50 @ =0x00000B48
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08135B54 @ =0x00000B44
	adds r1, r3, r0
	b _0813609C
	.align 2, 0
_08135B50: .4byte 0x00000B48
_08135B54: .4byte 0x00000B44
_08135B58:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _08135AC8
_08135B66:
	ldr r2, _08135BC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08135BC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08135BCC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _08135BD0 @ =0x030046A4
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
	beq _08135BD4
	adds r0, #4
	b _08135BDE
	.align 2, 0
_08135BC4: .4byte 0x030046B8
_08135BC8: .4byte 0x000003FF
_08135BCC: .4byte 0x0203B400
_08135BD0: .4byte 0x030046A4
_08135BD4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135BDE:
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
	bl FUN_08138770
	ldr r2, [sp, #0x24]
	ldr r3, _08135C0C @ =0x00000B48
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08136096
	.align 2, 0
_08135C0C: .4byte 0x00000B48
_08135C10:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _08135CA8
	ldr r0, [sp, #0x20]
	bl FUN_08138744
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08135CA8
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _08135C64 @ =0x030046A4
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
	beq _08135C68
	adds r0, #4
	b _08135C74
	.align 2, 0
_08135C64: .4byte 0x030046A4
_08135C68:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135C74:
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
	bl FUN_08138770
	ldr r3, [sp, #0x24]
	ldr r4, _08135CA0 @ =0x00000B48
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _08135CA4 @ =0x00000B44
	adds r1, r3, r0
	b _0813609C
	.align 2, 0
_08135CA0: .4byte 0x00000B48
_08135CA4: .4byte 0x00000B44
_08135CA8:
	ldr r1, [sp, #0x24]
	ldr r2, _08135CC4 @ =0x00000B49
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _08135CE4
	cmp r6, #1
	bgt _08135CC8
	cmp r6, #0
	beq _08135CD2
	b _08135D38
	.align 2, 0
_08135CC4: .4byte 0x00000B49
_08135CC8:
	cmp r6, #2
	beq _08135D04
	cmp r6, #3
	beq _08135D18
	b _08135D38
_08135CD2:
	ldr r3, [sp, #0x20]
	ldr r4, _08135CE0 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135CE0: .4byte 0x00000256
_08135CE4:
	ldr r0, [sp, #0x20]
	ldr r2, _08135CFC @ =0x00000256
	adds r1, r0, r2
	ldr r0, _08135D00 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135CFC: .4byte 0x00000256
_08135D00: .4byte 0x030046A4
_08135D04:
	ldr r0, [sp, #0x20]
	ldr r2, _08135D14 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135D14: .4byte 0x00000256
_08135D18:
	ldr r3, [sp, #0x20]
	ldr r4, _08135D30 @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _08135D34 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135D30: .4byte 0x00000256
_08135D34: .4byte 0x030046A4
_08135D38:
	ldr r4, [sp, #0x20]
	ldr r1, _08135D54 @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08135D42:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08135D58
	adds r0, #4
	b _08135D64
	.align 2, 0
_08135D54: .4byte 0x00000256
_08135D58:
	ldr r0, _08135D80 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135D64:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08135D84
	adds r0, #4
	b _08135D90
	.align 2, 0
_08135D80: .4byte 0x030046A4
_08135D84:
	ldr r0, _08135DA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135D90:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08135DAC
	adds r0, #4
	b _08135DB8
	.align 2, 0
_08135DA8: .4byte 0x030046A4
_08135DAC:
	ldr r0, _08135DFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135DB8:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _08135DFC @ =0x030046A4
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
	beq _08135E00
	adds r0, #4
	b _08135E0C
	.align 2, 0
_08135DFC: .4byte 0x030046A4
_08135E00:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135E0C:
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
	beq _08135E30
	adds r0, #4
	b _08135E3C
_08135E30:
	ldr r2, _08135E50 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135E3C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135E54
	cmp r2, #2
	beq _08135E58
	b _08135E5C
	.align 2, 0
_08135E50: .4byte 0x030046A4
_08135E54:
	ldrb r0, [r4, #4]
	b _08135E5A
_08135E58:
	ldrb r0, [r4]
_08135E5A:
	subs r1, r1, r0
_08135E5C:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _08135EA4 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08135EA4 @ =0x030046A4
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
	beq _08135EA8
	adds r0, #4
	b _08135EB4
	.align 2, 0
_08135EA4: .4byte 0x030046A4
_08135EA8:
	ldr r3, _08135EE0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135EB4:
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
	beq _08135EE4
	adds r0, #4
	b _08135EF0
	.align 2, 0
_08135EE0: .4byte 0x030046A4
_08135EE4:
	ldr r0, _08135F04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135EF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135F08
	cmp r2, #2
	beq _08135F0C
	b _08135F10
	.align 2, 0
_08135F04: .4byte 0x030046A4
_08135F08:
	ldrb r0, [r5, #4]
	b _08135F0E
_08135F0C:
	ldrb r0, [r5]
_08135F0E:
	subs r1, r1, r0
_08135F10:
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
	beq _08135F30
	b _081360AC
_08135F30:
	cmp r2, #0
	beq _0813601E
	mov r0, sl
	cmp r0, #1
	bne _08135F52
	cmp r6, #1
	bne _08135F4A
	mov r3, sb
	cmp r3, #1
	bne _08135F68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135F78
_08135F4A:
	cmp r6, #3
	beq _08135F50
	b _081360AC
_08135F50:
	b _08135F74
_08135F52:
	mov r0, sl
	cmp r0, #2
	bne _08135F7E
	cmp r6, #0
	bne _08135F6E
	mov r3, sb
	cmp r3, #2
	bne _08135F68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135F78
_08135F68:
	cmp r1, #0
	beq _08135F7E
	b _081360AC
_08135F6E:
	cmp r6, #2
	beq _08135F74
	b _081360AC
_08135F74:
	mov r4, sb
	ldr r0, _08135F94 @ =0xFFFFFF00
_08135F78:
	cmp r1, r0
	beq _08135F7E
	b _081360AC
_08135F7E:
	mov r0, sb
	cmp r0, #1
	bne _08135FAC
	cmp r6, #1
	bne _08135F9E
	mov r3, sl
	cmp r3, #1
	bne _08135F98
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
	.align 2, 0
_08135F94: .4byte 0xFFFFFF00
_08135F98:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135F9E:
	cmp r6, #3
	beq _08135FA4
	b _081360AC
_08135FA4:
	mov r4, sl
	cmp r4, #1
	beq _08135FD2
	b _08135FE0
_08135FAC:
	mov r0, sb
	cmp r0, #2
	bne _08135FF0
	cmp r6, #0
	bne _08135FC8
	mov r3, sl
	cmp r3, #2
	bne _08135FC2
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135FC2:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135FC8:
	cmp r6, #2
	bne _081360AC
	mov r4, sl
	cmp r4, #2
	bne _08135FE0
_08135FD2:
	ldr r0, _08135FDC @ =0xFFFFFF00
_08135FD4:
	cmp r1, r0
	beq _08135FE4
	b _081360AC
	.align 2, 0
_08135FDC: .4byte 0xFFFFFF00
_08135FE0:
	cmp r1, #0
	bne _081360AC
_08135FE4:
	mov r0, sb
	cmp r0, #2
	bne _08135FF0
	mov r1, sl
	cmp r1, #2
	beq _08135FFC
_08135FF0:
	mov r3, sb
	cmp r3, #1
	bne _0813600E
	mov r4, sl
	cmp r4, #1
	bne _0813600E
_08135FFC:
	adds r1, r2, #0
	cmp r2, #0
	bge _08136004
	rsbs r1, r2, #0
_08136004:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0813601E
	b _081360AC
_0813600E:
	adds r0, r2, #0
	cmp r0, #0
	bge _08136016
	rsbs r0, r0, #0
_08136016:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08136020
_0813601E:
	adds r5, r7, #0
_08136020:
	cmp r5, #0
	blt _081360AC
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _08136064 @ =0x030046A4
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
	beq _08136068
	adds r0, #4
	b _08136072
	.align 2, 0
_08136064: .4byte 0x030046A4
_08136068:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08136072:
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
	bl FUN_08138770
	ldr r2, [sp, #0x24]
	ldr r3, _081360A4 @ =0x00000B48
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_08136096:
	strb r0, [r1]
	ldr r4, _081360A8 @ =0x00000B44
	adds r1, r2, r4
_0813609C:
	movs r0, #0x28
	strh r0, [r1]
	b _081360BC
	.align 2, 0
_081360A4: .4byte 0x00000B48
_081360A8: .4byte 0x00000B44
_081360AC:
	ldr r1, [sp, #0x24]
	ldr r2, _081360CC @ =0x00000B49
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_081360BC:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081360CC: .4byte 0x00000B49

	thumb_func_start FUN_081360d0
FUN_081360d0: @ 0x081360D0
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _081360EC @ =0x00000B33
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081360F0
	subs r0, #1
	strb r0, [r1]
	b _08136130
	.align 2, 0
_081360EC: .4byte 0x00000B33
_081360F0:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08136138 @ =0x00000B3A
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #5
	adds r2, r2, r5
	ldr r0, _0813613C @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_0813a250
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _0813613C @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_0813a250
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0813a250
_08136130:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08136138: .4byte 0x00000B3A
_0813613C: .4byte 0x00000674

	thumb_func_start FUN_08136140
FUN_08136140: @ 0x08136140
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0813621C @ =0x00000B3A
	adds r4, r5, r2
	movs r0, #4
	strh r0, [r4]
	movs r1, #4
	adds r2, #0x10
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _08136220 @ =0x00000B4C
	adds r1, r5, r0
	ldr r0, _08136224 @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _08136228 @ =0x00000B4B
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r7, #0
	movs r1, #0
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp sb, r0
	bge _0813629A
	mov sl, r1
	movs r0, #0xe8
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r1, _0813622C @ =0x00000684
	adds r6, r5, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r5
	mov r8, r2
_081361B4:
	adds r0, r6, #0
	ldr r1, [sp, #0xc]
	bl Video_GetActorSprite
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _08136230 @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r4, #0x10]
	ldr r1, _0813621C @ =0x00000B3A
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _08136234
	ldrb r0, [r4, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	movs r0, #4
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _08136260
	.align 2, 0
_0813621C: .4byte 0x00000B3A
_08136220: .4byte 0x00000B4C
_08136224: .4byte 0x7FFFFFFF
_08136228: .4byte 0x00000B4B
_0813622C: .4byte 0x00000684
_08136230: .4byte 0x0000922E
_08136234:
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	strh r7, [r4, #8]
	adds r7, #1
	cmp r7, #3
	ble _08136260
	movs r7, #0
_08136260:
	str r5, [r4, #0x34]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _08136276
	mov r1, sl
	strb r1, [r4, #0x1a]
	movs r0, #2
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _0813627C
_08136276:
	ldr r2, [sp, #0x18]
	adds r2, #1
	str r2, [sp, #0x18]
_0813627C:
	movs r0, #0x18
	add sl, r0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r6, r6, r1
	add r8, r1
	movs r2, #1
	add sb, r2
	ldr r1, _081362AC @ =0x00000B3A
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _081361B4
_0813629A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081362AC: .4byte 0x00000B3A

	thumb_func_start FUN_081362b0
FUN_081362b0: @ 0x081362B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r2, #0
	movs r3, #0
	ldr r0, _081362F0 @ =0x00000B3A
	adds r1, r4, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r3, r0
	bge _0813631E
	movs r6, #5
	mov ip, r6
	mov r8, r1
	adds r1, r4, #0
	movs r5, #0
	movs r7, #0x90
	lsls r7, r7, #1
	mov sb, r7
_081362DA:
	adds r0, r5, r4
	ldr r6, _081362F4 @ =0x00000755
	adds r0, r0, r6
	ldrb r0, [r0]
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _081362F8
	movs r0, #1
	b _081362FA
	.align 2, 0
_081362F0: .4byte 0x00000B3A
_081362F4: .4byte 0x00000755
_081362F8:
	movs r0, #0
_081362FA:
	cmp r0, #0
	bne _0813630E
	movs r6, #0xe9
	lsls r6, r6, #3
	adds r0, r1, r6
	strh r2, [r0]
	adds r2, #1
	cmp r2, #3
	ble _0813630E
	movs r2, #0
_0813630E:
	add r1, sb
	add r5, sb
	adds r3, #1
	mov r7, r8
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r3, r0
	blt _081362DA
_0813631E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813632c
FUN_0813632c: @ 0x0813632C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _08136370 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _08136350
	b _08136516
_08136350:
	movs r3, #0
	mov sl, r3
	movs r6, #0xe8
	lsls r6, r6, #3
	add r6, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_08136362:
	ldrb r0, [r6, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136374
	movs r0, #1
	b _08136376
	.align 2, 0
_08136370: .4byte 0x00000B3A
_08136374:
	movs r0, #0
_08136376:
	cmp r0, #0
	beq _0813637C
	b _081364F8
_0813637C:
	movs r1, #4
	ldrb r0, [r6, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0813638A
	movs r0, #1
	b _0813638C
_0813638A:
	movs r0, #0
_0813638C:
	cmp r0, #0
	beq _081363C2
	ldrb r0, [r6, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_08236fac
	b _08136418
_081363C2:
	ldrb r0, [r6, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	ldrh r4, [r6, #8]
	ldrh r5, [r6, #0xe]
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_08236fac
	ldr r0, _08136450 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl FUN_08237098
	strh r4, [r6, #8]
	strh r5, [r6, #0xe]
_08136418:
	mov r7, r8
	adds r4, r6, #0
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r6, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08136454
	mov r1, r8
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _08136460
	.align 2, 0
_08136450: .4byte 0x00000482
_08136454:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08136460:
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
	beq _08136482
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _0813648A
_08136482:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813648A:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081364C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081364F8
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081364C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081364BA
	ldrb r0, [r4, #5]
_081364BA:
	subs r0, #1
	strh r0, [r4, #8]
	b _081364D4
	.align 2, 0
_081364C0: .4byte 0x0000FFFF
_081364C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081364D4
	strh r1, [r4, #8]
_081364D4:
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
	bne _081364F8
	movs r3, #1
	strb r3, [r4, #7]
_081364F8:
	movs r0, #0x90
	lsls r0, r0, #1
	add sl, r0
	adds r6, r6, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _08136528 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08136516
	b _08136362
_08136516:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136528: .4byte 0x00000B3A

	thumb_func_start FUN_0813652c
FUN_0813652c: @ 0x0813652C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _08136570 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _08136550
	b _0813670A
_08136550:
	movs r3, #0
	mov sl, r3
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_08136562:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136574
	movs r0, #1
	b _08136576
	.align 2, 0
_08136570: .4byte 0x00000B3A
_08136574:
	movs r0, #0
_08136576:
	cmp r0, #0
	beq _0813657C
	b _081366EC
_0813657C:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0813658A
	movs r0, #1
	b _0813658C
_0813658A:
	movs r0, #0
_0813658C:
	cmp r0, #0
	beq _081365C2
	ldrb r0, [r7, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #1
	bl FUN_08236fac
	b _08136610
_081365C2:
	ldrb r0, [r7, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081355c0
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08236fac
	ldr r0, _08136644 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl FUN_08237098
_08136610:
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
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _08136648
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _08136654
	.align 2, 0
_08136644: .4byte 0x00000482
_08136648:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08136654:
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
	beq _08136676
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0813667E
_08136676:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813667E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081366B4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081366EC
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081366B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081366AE
	ldrb r0, [r4, #5]
_081366AE:
	subs r0, #1
	strh r0, [r4, #8]
	b _081366C8
	.align 2, 0
_081366B4: .4byte 0x0000FFFF
_081366B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081366C8
	strh r1, [r4, #8]
_081366C8:
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
	bne _081366EC
	movs r3, #1
	strb r3, [r4, #7]
_081366EC:
	movs r0, #0x90
	lsls r0, r0, #1
	add sl, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _0813671C @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0813670A
	b _08136562
_0813670A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813671C: .4byte 0x00000B3A

	thumb_func_start FUN_08136720
FUN_08136720: @ 0x08136720
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
	ldr r2, _08136760 @ =0x00000B3A
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08136790
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _08136764 @ =0x00000755
	adds r4, r7, r1
_08136750:
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08136768
	movs r0, #1
	b _0813676A
	.align 2, 0
_08136760: .4byte 0x00000B3A
_08136764: .4byte 0x00000755
_08136768:
	movs r0, #0
_0813676A:
	cmp r0, #0
	bne _0813677A
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
_0813677A:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	ldr r1, _0813679C @ =0x00000B3A
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _08136750
_08136790:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813679C: .4byte 0x00000B3A

	thumb_func_start FUN_081367a0
FUN_081367a0: @ 0x081367A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, _081367EC @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r3, [sp, #0xc]
	cmp r3, r0
	blt _081367C6
	b _08136968
_081367C6:
	movs r4, #0
	mov sl, r4
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	lsls r2, r2, #0x18
	str r2, [sp, #0x10]
_081367DC:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081367F0
	movs r0, #1
	b _081367F2
	.align 2, 0
_081367EC: .4byte 0x00000B3A
_081367F0:
	movs r0, #0
_081367F2:
	cmp r0, #0
	beq _081367F8
	b _08136948
_081367F8:
	ldrb r0, [r7, #0x15]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _08136806
	movs r0, #1
	b _08136808
_08136806:
	movs r0, #0
_08136808:
	cmp r0, #0
	beq _0813682C
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #8]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #1
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl FUN_08237040
	b _0813686E
_0813682C:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r4, [sp, #8]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl FUN_08237040
	ldr r0, _081368A0 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl FUN_08237098
_0813686E:
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
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _081368A4
	ldr r0, [r6]
	movs r2, #4
	orrs r0, r2
	str r0, [r6]
	b _081368B0
	.align 2, 0
_081368A0: .4byte 0x00000482
_081368A4:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081368B0:
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
	beq _081368D2
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081368DA
_081368D2:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081368DA:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08136910 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08136948
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08136914
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0813690A
	ldrb r0, [r4, #5]
_0813690A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08136924
	.align 2, 0
_08136910: .4byte 0x0000FFFF
_08136914:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08136924
	strh r1, [r4, #8]
_08136924:
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
	bne _08136948
	movs r3, #1
	strb r3, [r4, #7]
_08136948:
	movs r4, #0x90
	lsls r4, r4, #1
	add sl, r4
	adds r7, r7, r4
	add r8, r4
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	ldr r0, _08136978 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0xc]
	cmp r2, r0
	bge _08136968
	b _081367DC
_08136968:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136978: .4byte 0x00000B3A

	thumb_func_start FUN_0813697c
FUN_0813697c: @ 0x0813697C
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _081369AC @ =0x00000B3A
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _081369CA
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _081369B0 @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x90
	lsls r4, r4, #1
_081369A0:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _081369B4
	movs r0, #1
	b _081369B6
	.align 2, 0
_081369AC: .4byte 0x00000B3A
_081369B0: .4byte 0x00000755
_081369B4:
	movs r0, #0
_081369B6:
	cmp r0, #0
	beq _081369BC
	str r5, [r1]
_081369BC:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _081369A0
_081369CA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081369d0
FUN_081369d0: @ 0x081369D0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, _08136A08 @ =0x00000B3A
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _08136A02
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r6, r0
_081369E8:
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, #1
	ldr r1, _08136A08 @ =0x00000B3A
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _081369E8
_08136A02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08136A08: .4byte 0x00000B3A

	thumb_func_start FUN_08136a0c
FUN_08136a0c: @ 0x08136A0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
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
	ldr r7, _08136A54 @ =0x00000B3A
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _08136AB4
	movs r7, #1
	mov r8, r7
	mov r5, sp
	add r0, sp, #8
	mov sb, r0
	ldr r1, _08136A58 @ =0x00000674
	adds r4, r3, r1
	ldr r7, _08136A5C @ =0x00000754
	adds r6, r3, r7
_08136A46:
	ldrb r0, [r6, #1]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08136A60
	movs r0, #1
	b _08136A62
	.align 2, 0
_08136A54: .4byte 0x00000B3A
_08136A58: .4byte 0x00000674
_08136A5C: .4byte 0x00000754
_08136A60:
	movs r0, #0
_08136A62:
	cmp r0, #0
	bne _08136A9E
	mov r7, sb
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
_08136A9E:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _08136AC4 @ =0x00000B3A
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _08136A46
_08136AB4:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136AC4: .4byte 0x00000B3A

	thumb_func_start FUN_08136ac8
FUN_08136ac8: @ 0x08136AC8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08136AE4 @ =0x00000B38
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r0, _08136AE8 @ =0x00000B34
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08136AE4: .4byte 0x00000B38
_08136AE8: .4byte 0x00000B34

	thumb_func_start FUN_08136aec
FUN_08136aec: @ 0x08136AEC
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #1
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08136B0A
	movs r0, #1
	b _08136B0C
_08136B0A:
	movs r0, #0
_08136B0C:
	cmp r0, #0
	beq _08136B30
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08136B38 @ =0x00000AEC
	adds r4, r4, r1
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_08136B30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08136B38: .4byte 0x00000AEC

	thumb_func_start FUN_08136b3c
FUN_08136b3c: @ 0x08136B3C
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r5, #0xff
	movs r1, #0
	ldr r2, _08136B74 @ =0x00000B3A
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08136B8A
	movs r7, #4
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0xcb
	lsls r6, r6, #3
_08136B60:
	adds r0, r2, r4
	adds r0, r0, r6
	adds r0, #0xfd
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08136B78
	movs r0, #1
	b _08136B7A
	.align 2, 0
_08136B74: .4byte 0x00000B3A
_08136B78:
	movs r0, #0
_08136B7A:
	cmp r0, #0
	bne _08136BA2
	movs r0, #0x90
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, #1
	cmp r1, r3
	blt _08136B60
_08136B8A:
	cmp r5, #0xff
	beq _08136BD2
	movs r1, #1
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08136BA6
	movs r0, #1
	b _08136BA8
_08136BA2:
	adds r5, r1, #0
	b _08136B8A
_08136BA6:
	movs r0, #0
_08136BA8:
	cmp r0, #0
	beq _08136BD2
	ldr r0, _08136BD8 @ =0x00000AF4
	adds r3, r4, r0
	lsls r2, r5, #3
	adds r2, r2, r5
	lsls r2, r2, #5
	adds r0, r4, r2
	ldr r1, _08136BDC @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _08136BE0 @ =0x00000B14
	adds r0, r4, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r4, r2
	str r2, [r0]
_08136BD2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136BD8: .4byte 0x00000AF4
_08136BDC: .4byte 0x00000674
_08136BE0: .4byte 0x00000B14

	thumb_func_start FUN_08136be4
FUN_08136be4: @ 0x08136BE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0xff
	movs r2, #0
	ldr r3, _08136C28 @ =0x00000B3A
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _08136C42
	movs r3, #4
	mov ip, r3
	adds r4, r0, #0
	movs r3, #0
	movs r5, #0xcb
	lsls r5, r5, #3
	mov r8, r5
_08136C14:
	adds r0, r3, r6
	add r0, r8
	adds r0, #0xfd
	ldrb r0, [r0]
	mov r5, ip
	ands r0, r5
	cmp r0, #0
	beq _08136C2C
	movs r0, #1
	b _08136C2E
	.align 2, 0
_08136C28: .4byte 0x00000B3A
_08136C2C:
	movs r0, #0
_08136C2E:
	cmp r0, #0
	beq _08136C36
	adds r7, r2, #0
	b _08136C42
_08136C36:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r2, #1
	cmp r2, r4
	blt _08136C14
_08136C42:
	cmp r7, #0xff
	beq _08136C8C
	ldr r2, _08136C98 @ =0x00000AEC
	adds r5, r6, r2
	ldrh r1, [r1]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r7, #3
	adds r4, r4, r7
	lsls r4, r4, #5
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
	ldr r1, _08136C9C @ =0x00000B14
	adds r0, r6, r1
	str r4, [r0]
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #1
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08136C8C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136C98: .4byte 0x00000AEC
_08136C9C: .4byte 0x00000B14

	thumb_func_start FUN_08136ca0
FUN_08136ca0: @ 0x08136CA0
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _08136CC4 @ =0x00000B38
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _08136CCC
	strh r1, [r0]
	ldr r0, _08136CC8 @ =0x00000B34
	adds r1, r2, r0
	movs r0, #0xff
	b _08136CDA
	.align 2, 0
_08136CC4: .4byte 0x00000B38
_08136CC8: .4byte 0x00000B34
_08136CCC:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _08136CDC
	strh r1, [r0]
	ldr r3, _08136CF8 @ =0x00000B34
	adds r1, r2, r3
	movs r0, #1
_08136CDA:
	strb r0, [r1]
_08136CDC:
	ldr r5, _08136CFC @ =0x00000B38
	adds r1, r2, r5
	ldr r3, _08136CF8 @ =0x00000B34
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
_08136CF8: .4byte 0x00000B34
_08136CFC: .4byte 0x00000B38

	thumb_func_start FUN_08136d00
FUN_08136d00: @ 0x08136D00
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08136D14 @ =0x00000AD8
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08136D14: .4byte 0x00000AD8

	thumb_func_start FUN_08136d18
FUN_08136d18: @ 0x08136D18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08136DD0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _08136D80 @ =0x00000AD8
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _08136DD0
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _08136D84 @ =0x00000B3A
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _08136DD0
	movs r0, #2
	mov sl, r0
	movs r2, #1
	mov sb, r2
	mov r8, r1
	adds r3, r7, #0
	ldr r7, _08136D88 @ =0x00000755
	adds r4, r3, r7
_08136D72:
	ldrb r0, [r4]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08136D8C
	movs r0, #1
	b _08136D8E
	.align 2, 0
_08136D80: .4byte 0x00000AD8
_08136D84: .4byte 0x00000B3A
_08136D88: .4byte 0x00000755
_08136D8C:
	movs r0, #0
_08136D8E:
	cmp r0, #0
	beq _08136DBA
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08136DA0
	movs r0, #1
	b _08136DA2
_08136DA0:
	movs r0, #0
_08136DA2:
	cmp r0, #0
	bne _08136DBA
	ldr r7, _08136DE0 @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xf0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_08136DBA:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r4, r4, r0
	movs r1, #1
	add ip, r1
	mov r2, r8
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp ip, r0
	blt _08136D72
_08136DD0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136DE0: .4byte 0x00000674

	thumb_func_start FUN_08136de4
FUN_08136de4: @ 0x08136DE4
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
	ldr r1, _08136E38 @ =0x00000B3A
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08136E10
	b _08136F0C
_08136E10:
	ldr r0, _08136E3C @ =0x085B0A08
	mov sb, r0
	movs r6, #0
	ldr r1, _08136E40 @ =0x0000075A
	adds r3, r5, r1
	adds r4, r5, #0
	movs r0, #0x90
	lsls r0, r0, #1
	mov r8, r0
_08136E22:
	adds r0, r6, r5
	ldr r1, _08136E44 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08136E48
	movs r0, #1
	b _08136E4A
	.align 2, 0
_08136E38: .4byte 0x00000B3A
_08136E3C: .4byte 0x085B0A08
_08136E40: .4byte 0x0000075A
_08136E44: .4byte 0x00000755
_08136E48:
	movs r0, #0
_08136E4A:
	cmp r0, #0
	beq _08136EF6
	adds r0, r6, r5
	ldr r1, _08136E64 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136E68
	movs r0, #1
	b _08136E6A
	.align 2, 0
_08136E64: .4byte 0x00000755
_08136E68:
	movs r0, #0
_08136E6A:
	cmp r0, #0
	bne _08136EF6
	mov r0, sl
	cmp r0, #0
	bne _08136E98
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08136E88
	asrs r2, r0, #0xc
	b _08136E8E
_08136E88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136E8E:
	ldr r0, _08136E94 @ =0x0000076E
	b _08136EE6
	.align 2, 0
_08136E94: .4byte 0x0000076E
_08136E98:
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
	blt _08136EB2
	asrs r2, r0, #0xc
	b _08136EB8
_08136EB2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136EB8:
	ldr r0, _08136ED8 @ =0x0000076C
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
	blt _08136EDC
	asrs r2, r0, #0xc
	b _08136EE2
	.align 2, 0
_08136ED8: .4byte 0x0000076C
_08136EDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136EE2:
	movs r0, #0xee
	lsls r0, r0, #3
_08136EE6:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_08136EF6:
	add r6, r8
	add r3, r8
	add r4, r8
	movs r0, #1
	add ip, r0
	ldr r1, _08136F1C @ =0x00000B3A
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08136E22
_08136F0C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136F1C: .4byte 0x00000B3A

	thumb_func_start FUN_08136f20
FUN_08136f20: @ 0x08136F20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	ldr r5, [sp, #0x68]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r6, [r0]
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
	subs r1, r5, r1
	bl Div
	str r0, [sp, #0x2c]
	movs r1, #0
	mov sl, r4
	cmp sl, r5
	blt _08136F60
	b _081370E4
_08136F60:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x30]
	add r7, sp, #0xc
	mov sb, r7
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x34]
	add r2, sp, #0x1c
	mov r8, r2
	mov r3, sl
	lsls r0, r3, #3
	add r0, sl
	lsls r0, r0, #5
	ldr r4, _08136FD4 @ =0x00000674
	adds r0, r0, r4
	adds r0, r0, r6
	str r0, [sp, #0x3c]
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x38]
	subs r3, r5, r3
	mov sl, r3
_08136F8E:
	adds r4, r1, #1
	ldr r0, [sp, #0x2c]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x34]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x34]
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
	ldr r2, _08136FD8 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _08136FDC
	asrs r0, r0, #0xa
	b _08136FE2
	.align 2, 0
_08136FD4: .4byte 0x00000674
_08136FD8: .4byte 0x05000002
_08136FDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08136FE2:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _08136FF0
	asrs r1, r0, #0xa
	b _08136FF6
_08136FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08136FF6:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	str r1, [sp, #0x40]
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x38]
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
	ldr r1, [sp, #0x40]
	adds r0, r0, r1
	cmp r0, #0
	blt _08137036
	asrs r1, r0, #0xa
	b _0813703C
_08137036:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813703C:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x30]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x38]
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
	ldr r4, [sp, #0x40]
	adds r0, r0, r4
	cmp r0, #0
	blt _08137078
	asrs r1, r0, #0xa
	b _0813707E
_08137078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813707E:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	strh r0, [r1, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x38]
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
	ldr r4, [sp, #0x40]
	adds r0, r0, r4
	cmp r0, #0
	blt _081370B2
	asrs r1, r0, #0xa
	b _081370B8
_081370B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081370B8:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	strh r0, [r1, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r1, ip
	movs r3, #0x90
	lsls r3, r3, #1
	adds r2, r2, r3
	str r2, [sp, #0x3c]
	movs r4, #1
	rsbs r4, r4, #0
	add sl, r4
	mov r7, sl
	cmp r7, #0
	beq _081370E4
	b _08136F8E
_081370E4:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081370f4
FUN_081370f4: @ 0x081370F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #0x1c]
	adds r7, r1, #0
	str r2, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0
	mov sl, r3
	ldr r0, _0813714C @ =0x00000B3A
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp sl, r0
	bge _08137226
	ldr r6, _08137150 @ =0x00000764
	add r6, sb
	movs r0, #0
	str r0, [sp, #0x24]
	ldr r1, _08137154 @ =0x00000755
	add r1, sb
	mov r8, r1
_0813713A:
	movs r1, #2
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08137158
	movs r0, #1
	b _0813715A
	.align 2, 0
_0813714C: .4byte 0x00000B3A
_08137150: .4byte 0x00000764
_08137154: .4byte 0x00000755
_08137158:
	movs r0, #0
_0813715A:
	cmp r0, #0
	beq _08137208
	movs r1, #1
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0813716E
	movs r0, #1
	b _08137170
_0813716E:
	movs r0, #0
_08137170:
	cmp r0, #0
	bne _08137208
	add r5, sp, #4
	ldr r2, [sp, #0x24]
	add r2, sb
	ldr r3, _08137264 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r6]
	ldrh r0, [r2]
	subs r1, r1, r0
	adds r0, r5, #0
	strh r1, [r0]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	adds r0, r5, #0
	movs r4, #0
	ldrsh r2, [r0, r4]
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
	ble _08137208
	cmp r7, #1
	bge _081371C6
	movs r7, #1
_081371C6:
	adds r0, r2, #0
	adds r1, r7, #0
	str r3, [sp, #0x28]
	bl Div
	ldr r4, [sp, #0x24]
	add r4, sb
	ldr r3, [sp, #0x28]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldr r3, _08137268 @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_08137208:
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r6, r3
	ldr r4, [sp, #0x24]
	adds r4, r4, r3
	str r4, [sp, #0x24]
	add r8, r3
	movs r0, #1
	add sl, r0
	ldr r0, _0813726C @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _0813713A
_08137226:
	ldr r0, [sp, #0x1c]
	bl FUN_08136b3c
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0xff
	movs r2, #0
	mov sl, r2
	ldr r0, _0813726C @ =0x00000B3A
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp sl, r0
	blt _0813724C
	b _08137344
_0813724C:
	add r7, sp, #0xc
	ldr r5, _08137264 @ =0x00000674
	add r5, sb
	ldr r6, _08137270 @ =0x00000755
	add r6, sb
_08137256:
	movs r1, #1
	ldrb r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08137274
	movs r0, #1
	b _08137276
	.align 2, 0
_08137264: .4byte 0x00000674
_08137268: .4byte 0x00000676
_0813726C: .4byte 0x00000B3A
_08137270: .4byte 0x00000755
_08137274:
	movs r0, #0
_08137276:
	cmp r0, #0
	bne _0813732C
	movs r1, #2
	ldrb r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08137288
	movs r0, #1
	b _0813728A
_08137288:
	movs r0, #0
_0813728A:
	cmp r0, #0
	beq _08137324
	cmp r3, #0xff
	beq _081372A2
	adds r0, r3, r2
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0xc
	adds r2, r5, #0
	bl FUN_08136f20
	b _08137310
_081372A2:
	add r4, sp, #0x14
	ldrh r0, [r7]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r2, [r4, r0]
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
	ldr r0, _08137320 @ =0x00001A44
	cmp r1, r0
	ble _08137310
	adds r0, r2, #0
	movs r1, #4
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	movs r1, #2
	ldrsh r0, [r4, r1]
	movs r1, #4
	bl Div
	ldrh r1, [r5, #2]
	adds r1, r1, r0
	strh r1, [r5, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #4
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
_08137310:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0xff
	movs r2, #0
	b _0813732C
	.align 2, 0
_08137320: .4byte 0x00001A44
_08137324:
	cmp r3, #0xff
	bne _0813732A
	mov r3, sl
_0813732A:
	adds r2, #1
_0813732C:
	movs r4, #0x90
	lsls r4, r4, #1
	adds r5, r5, r4
	adds r6, r6, r4
	movs r0, #1
	add sl, r0
	ldr r0, _0813735C @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _08137256
_08137344:
	ldr r0, [sp, #0x1c]
	bl FUN_08136a0c
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813735C: .4byte 0x00000B3A

	thumb_func_start FUN_08137360
FUN_08137360: @ 0x08137360
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r6, #0
	ldr r0, _081373AC @ =0x00000B3A
	adds r4, r3, r0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r6, r0
	bge _081373A2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	mov ip, r4
	ldr r5, _081373B0 @ =0x00000764
	adds r4, r3, r5
	ldr r7, _081373B4 @ =0x00000674
	adds r3, r3, r7
	movs r0, #0x90
	lsls r0, r0, #1
	mov r8, r0
_0813738A:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	add r4, r8
	add r3, r8
	adds r6, #1
	mov r5, ip
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r6, r0
	blt _0813738A
_081373A2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081373AC: .4byte 0x00000B3A
_081373B0: .4byte 0x00000764
_081373B4: .4byte 0x00000674

	thumb_func_start FUN_081373b8
FUN_081373b8: @ 0x081373B8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _0813743C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _08137440 @ =0x0000FFFF
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
	ldr r3, _08137444 @ =FUN_08132354
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
	ldr r3, _08137448 @ =FUN_08132314
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
_0813743C: .4byte 0xFFFF0000
_08137440: .4byte 0x0000FFFF
_08137444: .4byte FUN_08132354
_08137448: .4byte FUN_08132314

	thumb_func_start FUN_0813744c
FUN_0813744c: @ 0x0813744C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	ldr r0, _081374BC @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r4, #0
	strh r0, [r2]
	ldr r1, _081374C0 @ =0x00000ADD
	adds r0, r6, r1
	strb r3, [r0]
	ldr r2, _081374C4 @ =0x00000ADE
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081374C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081374CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081374D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081374D4 @ =0x00000B49
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _081374D8 @ =0x00000AD9
	adds r0, r6, r1
	strb r3, [r0]
	adds r2, #0xb
	adds r0, r6, r2
	strh r4, [r0]
	ldr r3, _081374DC @ =0x00000B8C
	adds r1, r6, r3
	ldr r4, _081374E0 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081374E4
	ldr r2, [r5, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081374EE
	.align 2, 0
_081374BC: .4byte 0x0000FFFD
_081374C0: .4byte 0x00000ADD
_081374C4: .4byte 0x00000ADE
_081374C8: .4byte 0x030046B8
_081374CC: .4byte 0x000003FF
_081374D0: .4byte 0x0203B400
_081374D4: .4byte 0x00000B49
_081374D8: .4byte 0x00000AD9
_081374DC: .4byte 0x00000B8C
_081374E0: .4byte 0x0000025D
_081374E4:
	ldr r2, [r5, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081374EE:
	ldr r1, _08137574 @ =0x00000B8C
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	adds r0, r5, #0
	bl FUN_08138710
	adds r1, r5, #0
	adds r1, #8
	adds r0, r6, #0
	bl FUN_08137360
	adds r0, r5, #0
	bl FUN_081355f0
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _08137578 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r2, [r0]
	ldr r1, _0813757C @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
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
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08137574: .4byte 0x00000B8C
_08137578: .4byte 0x00000469
_0813757C: .4byte 0x0000046C

	thumb_func_start FUN_08137580
FUN_08137580: @ 0x08137580
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r3, [r6, #0x44]
	ldr r2, _081375BC @ =0x085B0A08
	ldr r4, _081375C0 @ =0x00000B32
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
	blt _081375C4
	asrs r1, r0, #0xc
	b _081375CA
	.align 2, 0
_081375BC: .4byte 0x085B0A08
_081375C0: .4byte 0x00000B32
_081375C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081375CA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldr r1, [r6, #0x44]
	ldr r3, [sp, #0x24]
	ldr r4, _081375EC @ =0x00000B32
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081375F0
	asrs r2, r0, #0xc
	b _081375F6
	.align 2, 0
_081375EC: .4byte 0x00000B32
_081375F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081375F6:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r0, [sp, #0x24]
	ldr r2, _08137648 @ =0x00000B32
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov sb, r5
	ldr r3, [sp, #0x24]
	ldr r4, _0813764C @ =0x00000B3A
	adds r1, r3, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sb, r0
	bge _08137686
	ldr r0, _08137650 @ =0x085B0A08
	mov r8, r0
	mov sl, r1
	movs r1, #0x90
	lsls r1, r1, #1
	adds r3, r3, r1
	ldr r4, [sp, #0x24]
	ldr r7, _08137654 @ =0x00000879
	adds r2, r4, r7
	movs r4, #0x90
	lsls r4, r4, #2
_08137632:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08137658
	asrs r0, r0, #0xc
	b _0813765E
	.align 2, 0
_08137648: .4byte 0x00000B32
_0813764C: .4byte 0x00000B3A
_08137650: .4byte 0x085B0A08
_08137654: .4byte 0x00000879
_08137658:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813765E:
	ldr r7, _08137714 @ =0x00000674
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
	add sb, r0
	mov r1, sl
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sb, r0
	blt _08137632
_08137686:
	ldr r0, [r6, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov sb, r0
	ldr r1, [sp, #0x24]
	ldr r2, _08137718 @ =0x00000B3A
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sb, r0
	blt _081376A6
	b _081377D6
_081376A6:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x28]
	add r7, sp, #0xc
	add r6, sp, #0x14
	ldr r0, _0813771C @ =0x00000794
	adds r5, r1, r0
	ldr r2, _08137714 @ =0x00000674
	adds r2, r1, r2
	str r2, [sp, #0x2c]
	movs r3, #0x80
	lsls r3, r3, #1
	mov r8, r3
	movs r4, #0xc0
	lsls r4, r4, #2
	mov sl, r4
_081376C6:
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
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _08137720 @ =0x05000002
	bl CpuSet
	mov r2, r8
	mov r3, sl
	subs r1, r2, r3
	adds r1, #1
	add r2, sp, #0x1c
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	subs r1, r3, r0
	movs r3, #0
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _08137724
	asrs r1, r0, #0xa
	b _0813772A
	.align 2, 0
_08137714: .4byte 0x00000674
_08137718: .4byte 0x00000B3A
_0813771C: .4byte 0x00000794
_08137720: .4byte 0x05000002
_08137724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813772A:
	ldrh r0, [r7]
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	mov r0, r8
	mov r1, sl
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	rsbs r2, r0, #0
	mov r1, sl
	adds r1, r2, r1
	str r1, [sp, #0x30]
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [sp, #0x30]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _08137764
	asrs r1, r0, #0xa
	b _0813776A
_08137764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813776A:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, sl
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _08137796
	asrs r1, r0, #0xa
	b _0813779C
_08137796:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813779C:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	strh r0, [r4, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0x90
	lsls r3, r3, #2
	adds r5, r5, r3
	adds r2, r2, r3
	str r2, [sp, #0x2c]
	movs r4, #2
	add sb, r4
	ldr r1, [sp, #0x24]
	ldr r2, _081377E8 @ =0x00000B3A
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sb, r0
	bge _081377D6
	b _081376C6
_081377D6:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081377E8: .4byte 0x00000B3A

	thumb_func_start FUN_081377ec
FUN_081377ec: @ 0x081377EC
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _08137824 @ =0x00000B3A
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _08137850
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08137828 @ =0x00000755
	adds r2, r1, r0
	movs r6, #0x90
	lsls r6, r6, #1
_08137818:
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _0813782C
	movs r0, #1
	b _0813782E
	.align 2, 0
_08137824: .4byte 0x00000B3A
_08137828: .4byte 0x00000755
_0813782C:
	movs r0, #0
_0813782E:
	cmp r0, #0
	bne _08137844
	cmp r4, #1
	bne _0813783A
	movs r4, #0
	b _08137844
_0813783A:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
	adds r4, #1
_08137844:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _08137818
_08137850:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08137858
FUN_08137858: @ 0x08137858
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r7, r5, r4
	ldr r1, _08137874 @ =0x00000B4A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _081378AC
	b _081378F4
	.align 2, 0
_08137874: .4byte 0x00000B4A
_08137878:
	adds r0, r4, r1
	lsls r0, r0, #5
	adds r4, r7, r0
	adds r0, r4, #0
	adds r0, #0x98
	bl FUN_08236424
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _081378A8 @ =0x00000B4A
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_08138504
	movs r0, #1
	b _081378F6
	.align 2, 0
_081378A8: .4byte 0x00000B4A
_081378AC:
	ldr r1, _081378DC @ =0x00000B3A
	adds r0, r5, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r0, #1
	cmp r1, #0
	blt _081378F4
	movs r0, #5
	mov ip, r0
	lsls r2, r1, #3
	adds r0, r2, r1
	lsls r0, r0, #5
	adds r0, #0xfd
	adds r3, r0, r7
	ldr r6, _081378E0 @ =0xFFFFFEE0
_081378CA:
	ldrb r0, [r3]
	mov r4, ip
	ands r0, r4
	adds r4, r2, #0
	cmp r0, #0
	beq _081378E4
	movs r0, #1
	b _081378E6
	.align 2, 0
_081378DC: .4byte 0x00000B3A
_081378E0: .4byte 0xFFFFFEE0
_081378E4:
	movs r0, #0
_081378E6:
	cmp r0, #0
	beq _08137878
	subs r2, #8
	adds r3, r3, r6
	subs r1, #1
	cmp r1, #0
	bge _081378CA
_081378F4:
	movs r0, #0
_081378F6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081378fc
FUN_081378fc: @ 0x081378FC
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
	ldr r0, _08137954 @ =0x00000B4A
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813798E
	ldr r0, _08137958 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0813798E
	movs r0, #1
	mov sb, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r1, #0x1c
	adds r7, r1, r2
	adds r1, #0x7c
	adds r6, r1, r2
	adds r0, #0xfd
	adds r4, r0, r2
_08137944:
	ldrb r0, [r4]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0813795C
	movs r0, #1
	b _0813795E
	.align 2, 0
_08137954: .4byte 0x00000B4A
_08137958: .4byte 0x00000B3A
_0813795C:
	movs r0, #0
_0813795E:
	cmp r0, #0
	bne _08137980
	adds r0, r6, #0
	bl FUN_08236424
	ldrb r1, [r4]
	mov r0, sb
	orrs r0, r1
	strb r0, [r4]
	ldr r1, _0813799C @ =0x00000B4A
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08138504
_08137980:
	ldr r0, _081379A0 @ =0xFFFFFEE0
	adds r7, r7, r0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08137944
_0813798E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813799C: .4byte 0x00000B4A
_081379A0: .4byte 0xFFFFFEE0

	thumb_func_start FUN_081379a4
FUN_081379a4: @ 0x081379A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r2, r0
	ldr r1, _081379F8 @ =0x00000B4A
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08137A22
	subs r1, #0x10
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _08137A22
	movs r0, #1
	mov r8, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r1, #0x98
	adds r6, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
	ldr r1, _081379F8 @ =0x00000B4A
	adds r7, r2, r1
_081379E8:
	ldrb r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _081379FC
	movs r0, #1
	b _081379FE
	.align 2, 0
_081379F8: .4byte 0x00000B4A
_081379FC:
	movs r0, #0
_081379FE:
	cmp r0, #0
	bne _08137A16
	adds r0, r6, #0
	bl FUN_08236424
	ldrb r0, [r4]
	mov r1, r8
	orrs r1, r0
	strb r1, [r4]
	ldrb r0, [r7]
	subs r0, #1
	strb r0, [r7]
_08137A16:
	ldr r0, _08137A2C @ =0xFFFFFEE0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _081379E8
_08137A22:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137A2C: .4byte 0xFFFFFEE0

	thumb_func_start FUN_08137a30
FUN_08137a30: @ 0x08137A30
	push {lr}
	cmp r1, #0
	beq _08137A48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08137A4C @ =0x00000B32
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_08137A48:
	pop {r0}
	bx r0
	.align 2, 0
_08137A4C: .4byte 0x00000B32

	thumb_func_start FUN_08137a50
FUN_08137a50: @ 0x08137A50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
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
	ble _08137A96
	movs r6, #0xff
	b _08137AA0
_08137A96:
	cmp r6, #0x80
	ble _08137A9E
	movs r6, #0x7f
	b _08137AA0
_08137A9E:
	movs r6, #0x3f
_08137AA0:
	movs r2, #0
	mov ip, r2
	ldr r3, _08137AD8 @ =0x00000B3A
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r2, r2, r4
	mov r8, r2
	cmp ip, r0
	bge _08137B92
	movs r7, #0
	movs r3, #0xcb
	lsls r3, r3, #3
	mov sl, r3
	ldr r0, _08137ADC @ =0x030046B8
	mov sb, r0
_08137AC4:
	adds r0, r7, r4
	add r0, sl
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08137AE0
	movs r0, #1
	b _08137AE2
	.align 2, 0
_08137AD8: .4byte 0x00000B3A
_08137ADC: .4byte 0x030046B8
_08137AE0:
	movs r0, #0
_08137AE2:
	cmp r0, #0
	beq _08137B7C
	adds r0, r7, r4
	add r0, sl
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _08137AFA
	movs r0, #1
	b _08137AFC
_08137AFA:
	movs r0, #0
_08137AFC:
	cmp r0, #0
	bne _08137B7C
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08137B3C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08137B40 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r2, r7, r4
	ldr r0, _08137B44 @ =0x0000076C
	adds r2, r2, r0
	ands r3, r6
	movs r5, #0xc
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08137B48 @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08137B4C
	asrs r1, r0, #0xc
	b _08137B52
	.align 2, 0
_08137B3C: .4byte 0x000003FF
_08137B40: .4byte 0x0203B400
_08137B44: .4byte 0x0000076C
_08137B48: .4byte 0x085B0A08
_08137B4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08137B52:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	ldr r3, _08137B70 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08137B74
	asrs r0, r0, #0xc
	b _08137B7A
	.align 2, 0
_08137B70: .4byte 0x085B0A08
_08137B74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08137B7A:
	strh r0, [r2, #4]
_08137B7C:
	movs r2, #0x90
	lsls r2, r2, #1
	adds r7, r7, r2
	movs r3, #1
	add ip, r3
	ldr r1, _08137BA4 @ =0x00000B3A
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp ip, r0
	blt _08137AC4
_08137B92:
	movs r1, #4
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08137BA8
	movs r0, #1
	b _08137BAA
	.align 2, 0
_08137BA4: .4byte 0x00000B3A
_08137BA8:
	movs r0, #0
_08137BAA:
	cmp r0, #0
	beq _08137BC2
	movs r0, #0xf5
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #5
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08137BC2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08137bd0
FUN_08137bd0: @ 0x08137BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08137BEA
	b _08137D6C
_08137BEA:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08137C08
	b _08137D6C
_08137C08:
	movs r0, #0
	str r0, [sp]
	ldr r0, _08137C3C @ =0x00000B3A
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	blt _08137C1C
	b _08137D6C
_08137C1C:
	ldr r5, _08137C40 @ =0x00000676
	add r5, sl
	ldr r7, _08137C44 @ =0x00000674
	add r7, sl
	ldr r3, _08137C48 @ =0x00000755
	add r3, sl
	mov r8, r3
_08137C2A:
	movs r1, #2
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08137C4C
	movs r0, #1
	b _08137C4E
	.align 2, 0
_08137C3C: .4byte 0x00000B3A
_08137C40: .4byte 0x00000676
_08137C44: .4byte 0x00000674
_08137C48: .4byte 0x00000755
_08137C4C:
	movs r0, #0
_08137C4E:
	cmp r0, #0
	bne _08137C54
	b _08137D4E
_08137C54:
	movs r1, #1
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08137C64
	movs r0, #1
	b _08137C66
_08137C64:
	movs r0, #0
_08137C66:
	cmp r0, #0
	bne _08137D4E
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08137C8E
	cmp r1, #0
	blt _08137C8E
	ldr r0, _08137C94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08137C8E
	ldr r0, _08137C98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08137C9C
_08137C8E:
	movs r4, #0
	b _08137CAA
	.align 2, 0
_08137C94: .4byte 0x030046A8
_08137C98: .4byte 0x030046AC
_08137C9C:
	ldr r0, _08137CBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08137CAA:
	adds r6, r7, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08137CC0
	adds r0, #4
	b _08137CCC
	.align 2, 0
_08137CBC: .4byte 0x030046A4
_08137CC0:
	ldr r0, _08137CE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08137CCC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08137CE4
	cmp r2, #2
	beq _08137CE8
	b _08137CEC
	.align 2, 0
_08137CE0: .4byte 0x030046A4
_08137CE4:
	ldrb r0, [r6, #4]
	b _08137CEA
_08137CE8:
	ldrb r0, [r6]
_08137CEA:
	subs r1, r1, r0
_08137CEC:
	adds r2, r1, #0
	movs r3, #2
	ldrsh r0, [r7, r3]
	cmp r0, r2
	beq _08137D4E
	cmp r0, r2
	bge _08137D26
	subs r0, r2, r0
	adds r1, r0, #0
	cmp r0, #0
	bge _08137D04
	rsbs r1, r0, #0
_08137D04:
	cmp r1, #0xff
	ble _08137D10
	mov r1, sb
	ldrh r0, [r1, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D10:
	cmp r0, #0
	bge _08137D16
	rsbs r0, r0, #0
_08137D16:
	cmp r0, #0xff
	bgt _08137D1E
	strh r2, [r5]
	b _08137D4E
_08137D1E:
	mov r2, sb
	ldrh r0, [r2, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D26:
	subs r1, r1, r0
	adds r2, r1, #0
	cmp r1, #0
	bge _08137D30
	rsbs r2, r1, #0
_08137D30:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	ble _08137D40
	mov r3, sb
	ldrh r0, [r3, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D40:
	adds r0, r1, #0
	movs r1, #0xa
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
_08137D4E:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r0, _08137D7C @ =0x00000B3A
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08137D6C
	b _08137C2A
_08137D6C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137D7C: .4byte 0x00000B3A

	thumb_func_start FUN_08137d80
FUN_08137d80: @ 0x08137D80
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08137E86
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r2, #0
	mov sb, r2
	ldr r7, _08137DD0 @ =0x00000B3A
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	bge _08137E86
	adds r4, r6, #0
	ldr r2, _08137DD4 @ =0x0000076E
	adds r3, r6, r2
	movs r7, #2
	mov r8, r7
	movs r0, #0x90
	lsls r0, r0, #1
	mov ip, r0
	ldr r1, _08137DD8 @ =0x00000755
	adds r5, r6, r1
_08137DC0:
	ldrb r0, [r5]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08137DDC
	movs r0, #1
	b _08137DDE
	.align 2, 0
_08137DD0: .4byte 0x00000B3A
_08137DD4: .4byte 0x0000076E
_08137DD8: .4byte 0x00000755
_08137DDC:
	movs r0, #0
_08137DDE:
	cmp r0, #0
	beq _08137E70
	movs r1, #1
	ldrb r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08137DF0
	movs r0, #1
	b _08137DF2
_08137DF0:
	movs r0, #0
_08137DF2:
	cmp r0, #0
	bne _08137E70
	ldr r7, _08137E2C @ =0x00000674
	adds r1, r4, r7
	ldr r0, _08137E30 @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _08137E34 @ =0x00000676
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
	blt _08137E38
	asrs r1, r0, #1
	b _08137E3E
	.align 2, 0
_08137E2C: .4byte 0x00000674
_08137E30: .4byte 0x0000076C
_08137E34: .4byte 0x00000676
_08137E38:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08137E3E:
	ldr r2, _08137E50 @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _08137E54
	asrs r0, r0, #1
	b _08137E5A
	.align 2, 0
_08137E50: .4byte 0x0000076C
_08137E54:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08137E5A:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08137E68
	asrs r0, r0, #1
	b _08137E6E
_08137E68:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08137E6E:
	strh r0, [r3, #2]
_08137E70:
	add r4, ip
	add r5, ip
	add r3, ip
	movs r2, #1
	add sb, r2
	ldr r7, _08137E94 @ =0x00000B3A
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	blt _08137DC0
_08137E86:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137E94: .4byte 0x00000B3A

	thumb_func_start FUN_08137e98
FUN_08137e98: @ 0x08137E98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08137EB8
	movs r0, #1
	b _08137EBA
_08137EB8:
	movs r0, #0
_08137EBA:
	movs r1, #0xb3
	lsls r1, r1, #4
	adds r5, r2, r1
	cmp r0, #0
	beq _08137F10
	movs r3, #4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _08137F20 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08137F24 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08137F28 @ =0x00000544
	adds r1, r4, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r5]
	orrs r3, r0
	strh r3, [r5]
_08137F10:
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08137F20: .4byte 0x0000046C
_08137F24: .4byte 0xFFEFFFFF
_08137F28: .4byte 0x00000544

	thumb_func_start FUN_08137f2c
FUN_08137f2c: @ 0x08137F2C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08137f30
FUN_08137f30: @ 0x08137F30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r8
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08138042
	mov r6, sp
	adds r3, r5, #0
	adds r3, #0x24
	adds r2, r4, #0
	adds r2, #0x24
	ldrh r0, [r4, #0x24]
	ldrh r1, [r5, #0x24]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov sb, r1
	ldr r1, _08137FD4 @ =0x00000B4C
	adds r0, r7, r1
	ldr r0, [r0]
	cmp sb, r0
	bhs _0813803C
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08236524
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrh r1, [r4, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08137FD8
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r1, [r0]
	b _08137FFE
	.align 2, 0
_08137FD4: .4byte 0x00000B4C
_08137FD8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08138014
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _08138014
	ldr r2, _08138008 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813800C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08138010 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
_08137FFE:
	mov r2, r8
	adds r0, r2, r3
	strb r1, [r0]
	b _0813802C
	.align 2, 0
_08138008: .4byte 0x030046B8
_0813800C: .4byte 0x000003FF
_08138010: .4byte 0x0203B400
_08138014:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, sl
	strb r0, [r1]
_0813802C:
	ldr r1, _08138054 @ =0x00000B4C
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
_0813803C:
	adds r0, r7, #0
	bl FUN_08137e98
_08138042:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138054: .4byte 0x00000B4C

	thumb_func_start FUN_08138058
FUN_08138058: @ 0x08138058
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _081380A0 @ =0x00000B4C
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r4, _081380A4 @ =0x7FFFFFFF
	cmp r0, r4
	beq _081380D2
	movs r2, #0xb5
	lsls r2, r2, #4
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
	ldr r2, _081380A8 @ =0x085B0A08
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
	blt _081380AC
	asrs r1, r0, #0xc
	b _081380B2
	.align 2, 0
_081380A0: .4byte 0x00000B4C
_081380A4: .4byte 0x7FFFFFFF
_081380A8: .4byte 0x085B0A08
_081380AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081380B2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081380CA
	asrs r0, r0, #0xc
	b _081380D0
_081380CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081380D0:
	strh r0, [r3, #4]
_081380D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081380d8
FUN_081380d8: @ 0x081380D8
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
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0813824C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08138250 @ =0x0000FFFF
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
	mov r8, r2
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov sl, r1
	cmp r8, r0
	bge _08138192
	ldr r7, _08138258 @ =0x00000674
	add r7, sb
	movs r4, #0xde
	lsls r4, r4, #3
	add r4, sb
	movs r6, #0xcb
	lsls r6, r6, #3
	add r6, sb
_0813813A:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r4, #0
	ldr r2, _0813825C @ =0x00004109
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08138260 @ =FUN_08137f30
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0x90
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r1, #1
	add r8, r1
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _0813813A
_08138192:
	movs r3, #0
	movs r2, #0x40
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
	mov r8, r3
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	bge _0813823C
	ldr r7, _08138258 @ =0x00000674
	add r7, sb
	movs r4, #0xd4
	lsls r4, r4, #3
	add r4, sb
	movs r6, #0xcb
	lsls r6, r6, #3
	add r6, sb
_081381CC:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08138264 @ =0x00002401
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
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08138268 @ =FUN_08137f2c
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0x90
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r1, #1
	add r8, r1
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081381CC
_0813823C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813824C: .4byte 0xFFFF0000
_08138250: .4byte 0x0000FFFF
_08138254: .4byte 0x00000B3A
_08138258: .4byte 0x00000674
_0813825C: .4byte 0x00004109
_08138260: .4byte FUN_08137f30
_08138264: .4byte 0x00002401
_08138268: .4byte FUN_08137f2c

	thumb_func_start FUN_0813826c
FUN_0813826c: @ 0x0813826C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081382b0
FUN_081382b0: @ 0x081382B0
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	beq _081382C4
	movs r0, #0
	b _081382E2
_081382C4:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081382E8 @ =0x085AD75C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
_081382E2:
	pop {r1}
	bx r1
	.align 2, 0
_081382E8: .4byte 0x085AD75C

	thumb_func_start FUN_081382ec
FUN_081382ec: @ 0x081382EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08138304
	b _081384F2
_08138304:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
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
	blt _0813835A
	cmp r1, #0
	blt _0813835A
	ldr r0, _08138360 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813835A
	ldr r0, _08138364 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08138368
_0813835A:
	movs r4, #0
	b _08138376
	.align 2, 0
_08138360: .4byte 0x030046A8
_08138364: .4byte 0x030046AC
_08138368:
	ldr r0, _08138388 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08138376:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813838C
	adds r0, #4
	b _08138398
	.align 2, 0
_08138388: .4byte 0x030046A4
_0813838C:
	ldr r0, _081383AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08138398:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081383B0
	adds r0, #4
	b _081383BC
	.align 2, 0
_081383AC: .4byte 0x030046A4
_081383B0:
	ldr r0, _081383D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081383BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081383D4
	cmp r2, #2
	beq _081383D8
	b _081383DC
	.align 2, 0
_081383D0: .4byte 0x030046A4
_081383D4:
	ldrb r0, [r7, #4]
	b _081383DA
_081383D8:
	ldrb r0, [r7]
_081383DA:
	subs r1, r1, r0
_081383DC:
	ldr r2, _08138490 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _081383EE
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _08138400
_081383EE:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
_08138400:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081384EC
	ldr r1, _08138494 @ =0x00000ADD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081384F2
	ldr r2, _08138498 @ =0x00000B49
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	ldr r1, _0813849C @ =0x000004A4
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
	ble _081384A4
	ldr r0, _081384A0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081384B2
	.align 2, 0
_08138490: .4byte 0x00000472
_08138494: .4byte 0x00000ADD
_08138498: .4byte 0x00000B49
_0813849C: .4byte 0x000004A4
_081384A0: .4byte 0xFFFFFF00
_081384A4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081384B2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081384B2:
	cmp r1, #0
	bge _081384B8
	rsbs r1, r1, #0
_081384B8:
	cmp r1, #0x20
	ble _081384F2
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _081384E4 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _081384E8 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081384F2
	.align 2, 0
_081384E4: .4byte 0x00000469
_081384E8: .4byte 0x0000046C
_081384EC:
	ldr r0, _08138500 @ =0x00000ADD
	add r0, r8
	strb r1, [r0]
_081384F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138500: .4byte 0x00000ADD

	thumb_func_start FUN_08138504
FUN_08138504: @ 0x08138504
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r2, _08138664 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _08138668 @ =0x0000FFFF
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
	ldr r4, _0813866C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08138670 @ =0x000003FF
	mov sl, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08138674 @ =0x0203B400
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
	ldr r1, _08138674 @ =0x0203B400
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
	ldr r1, _08138674 @ =0x0203B400
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
	ldr r1, _08138674 @ =0x0203B400
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
	ldr r1, _08138674 @ =0x0203B400
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
	ldr r1, _08138674 @ =0x0203B400
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
	movs r0, #0xe5
	bl PlaySound_082406e0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138664: .4byte 0xFFFF0000
_08138668: .4byte 0x0000FFFF
_0813866C: .4byte 0x030046B8
_08138670: .4byte 0x000003FF
_08138674: .4byte 0x0203B400

	thumb_func_start FUN_08138678
FUN_08138678: @ 0x08138678
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08138704
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r3, _081386A4 @ =0x00000544
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081386FC
	cmp r0, #0x3b
	bhi _081386AC
	ldr r0, _081386A8 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	b _08138702
	.align 2, 0
_081386A4: .4byte 0x00000544
_081386A8: .4byte 0x00000482
_081386AC:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081386F0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081386F0
	ldr r0, _081386D8 @ =0x00000B54
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081386DC
	subs r0, #1
	strh r0, [r1]
	b _081386F0
	.align 2, 0
_081386D8: .4byte 0x00000B54
_081386DC:
	ldrh r0, [r2]
	movs r1, #0x18
	bl Mod
	cmp r0, #0
	bne _081386F0
	movs r0, #0xf6
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081386F0:
	ldr r3, _081386F8 @ =0x00000482
	adds r1, r4, r3
	movs r0, #3
	b _08138702
	.align 2, 0
_081386F8: .4byte 0x00000482
_081386FC:
	ldr r0, _0813870C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_08138702:
	strh r0, [r1]
_08138704:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813870C: .4byte 0x00000482

	thumb_func_start FUN_08138710
FUN_08138710: @ 0x08138710
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r3, #5
_08138726:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08138726
	ldr r2, _08138740 @ =0x00000ADC
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08138740: .4byte 0x00000ADC

	thumb_func_start FUN_08138744
FUN_08138744: @ 0x08138744
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	movs r4, #0xae
	lsls r4, r4, #4
	adds r2, r0, r4
_08138756:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08138760
	movs r0, #1
	b _0813876A
_08138760:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _08138756
	movs r0, #0
_0813876A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08138770
FUN_08138770: @ 0x08138770
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r4, _0813879C @ =0x00000ADC
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
_0813879C: .4byte 0x00000ADC

	thumb_func_start FUN_081387a0
FUN_081387a0: @ 0x081387A0
	push {r4, r5, r6, lr}
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r0, r3
	movs r3, #0
	strb r3, [r1]
	ldr r4, _081387F4 @ =0x00000469
	adds r1, r0, r4
	strb r2, [r1]
	ldr r6, _081387F8 @ =0x0000046A
	adds r1, r0, r6
	strb r3, [r1]
	ldr r2, _081387FC @ =0x00000484
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #3
	adds r1, r0, r4
	movs r2, #1
	strb r2, [r1]
	ldr r5, _08138800 @ =FUN_080e48d0
	movs r4, #0x10
	adds r6, #3
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _08138804 @ =0x0000046B
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
_081387F4: .4byte 0x00000469
_081387F8: .4byte 0x0000046A
_081387FC: .4byte 0x00000484
_08138800: .4byte FUN_080e48d0
_08138804: .4byte 0x0000046B

	thumb_func_start FUN_08138808
FUN_08138808: @ 0x08138808
	bx lr
	.align 2, 0

	thumb_func_start FUN_0813880c
FUN_0813880c: @ 0x0813880C
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
	beq _081388E8
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _08138840 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _08138844
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _0813884C
	.align 2, 0
_08138840: .4byte 0x00000553
_08138844:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_0813884C:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _081388E8
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
	bne _081388E8
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _081388B0
	rsbs r1, r1, #0
_081388B0:
	ldr r0, _081388DC @ =0x000001FF
	cmp r1, r0
	bgt _081388E8
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
	ldr r3, _081388E0 @ =0x00000B49
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, _081388E4 @ =0x00000B48
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _081388EA
	.align 2, 0
_081388DC: .4byte 0x000001FF
_081388E0: .4byte 0x00000B49
_081388E4: .4byte 0x00000B48
_081388E8:
	movs r0, #0
_081388EA:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081388f4
FUN_081388f4: @ 0x081388F4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813898E
	ldr r0, _08138950 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0813898E
	movs r3, #0x80
	lsls r3, r3, #1
	ands r1, r3
	cmp r1, #0
	beq _08138958
	movs r5, #0x94
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r1, [r0, #6]
	bics r1, r3
	strh r1, [r0, #6]
	adds r2, #0xa6
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _08138954 @ =0x0000022E
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
	b _0813898E
	.align 2, 0
_08138950: .4byte 0x0000A027
_08138954: .4byte 0x0000022E
_08138958:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r2, [r0, #6]
	adds r1, r3, #0
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
_0813898E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08138998
FUN_08138998: @ 0x08138998
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
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
	beq _081389BE
	b _08138B1E
_081389BE:
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, _08138A00 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	blt _081389D0
	b _08138B1E
_081389D0:
	add r7, sp, #8
	movs r6, #0xd4
	lsls r6, r6, #3
	add r6, sb
	ldr r4, _08138A04 @ =0x00000674
	add r4, sb
	movs r0, #0xde
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	movs r1, #0
	str r1, [sp, #0x14]
	ldr r2, _08138A08 @ =0x00000755
	add r2, sb
	mov sl, r2
_081389EE:
	movs r1, #1
	mov r3, sl
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08138A0C
	movs r0, #1
	b _08138A0E
	.align 2, 0
_08138A00: .4byte 0x00000B3A
_08138A04: .4byte 0x00000674
_08138A08: .4byte 0x00000755
_08138A0C:
	movs r0, #0
_08138A0E:
	cmp r0, #0
	bne _08138AF8
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, r8
	bl FUN_08236400
	ldr r0, _08138AAC @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r7]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r7, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r7, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08138AB0 @ =0x0000FFFF
	cmp r1, r0
	bgt _08138AF8
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	movs r3, #0x80
	lsls r3, r3, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r0, r3
	cmp r0, #0
	beq _08138ABC
	ldrh r0, [r4, #0x32]
	bics r0, r3
	strh r0, [r4, #0x32]
	ldr r2, _08138AB4 @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08138AB8 @ =0x0000022E
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
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
	b _08138AF8
	.align 2, 0
_08138AAC: .4byte 0x03002BE0
_08138AB0: .4byte 0x0000FFFF
_08138AB4: .4byte 0x00000226
_08138AB8: .4byte 0x0000022E
_08138ABC:
	ldr r1, [sp, #0x14]
	add r1, sb
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r2, [r1, #6]
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1, #6]
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
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
_08138AF8:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	add r8, r0
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	add sl, r0
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	ldr r0, _08138B30 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bge _08138B1E
	b _081389EE
_08138B1E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138B30: .4byte 0x00000B3A

	thumb_func_start FUN_08138b34
FUN_08138b34: @ 0x08138B34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08138B4C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08138B50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08138B52
	.align 2, 0
_08138B4C: .4byte 0x0000046C
_08138B50:
	movs r0, #0
_08138B52:
	cmp r0, #0
	beq _08138B8A
	ldr r4, _08138C28 @ =FUN_08133820
	movs r3, #0x22
	ldr r2, _08138C2C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08138C30 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08138C34 @ =0x00000553
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
_08138B8A:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _08138B9C
	rsbs r3, r1, #0
_08138B9C:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _08138BAE
	rsbs r2, r0, #0
_08138BAE:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #4
	bl FUN_081370f4
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl FUN_08136ca0
	ldr r6, _08138C30 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08138C40
	adds r0, r5, #0
	bl FUN_081355f0
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _08138C2C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _08138C34 @ =0x00000553
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
	ldr r1, _08138C38 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08138C3C @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08138C4A
	.align 2, 0
_08138C28: .4byte FUN_08133820
_08138C2C: .4byte 0x0000046D
_08138C30: .4byte 0x0000046B
_08138C34: .4byte 0x00000553
_08138C38: .4byte 0x0000046A
_08138C3C: .4byte 0x00000484
_08138C40:
	ldr r0, _08138C50 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08138C4A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08138C50: .4byte 0x00000484

	thumb_func_start FUN_08138c54
FUN_08138c54: @ 0x08138C54
	ldr r1, _08138C60 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08138C64 @ =0x085AD76C
	str r1, [r0]
	bx lr
	.align 2, 0
_08138C60: .4byte 0x0000063C
_08138C64: .4byte 0x085AD76C

	thumb_func_start FUN_08138c68
FUN_08138c68: @ 0x08138C68
	push {lr}
	bl FUN_08138058
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08138c74
FUN_08138c74: @ 0x08138C74
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08138998
	adds r0, r4, #0
	bl FUN_081388f4
	adds r0, r4, #0
	bl FUN_08138678
	adds r0, r4, #0
	bl FUN_0813697c
	adds r0, r4, #0
	bl FUN_08136d18
	adds r0, r4, #0
	bl FUN_08137d80
	adds r0, r4, #0
	bl FUN_08137bd0
	adds r0, r4, #0
	bl FUN_081382ec
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08138cb0
FUN_08138cb0: @ 0x08138CB0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r4, [r5]
	subs r0, #0x30
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r6, r1
	ldr r0, _08138DBC @ =0xFFFFFEFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #4
	movs r7, #0xb3
	lsls r7, r7, #4
	adds r2, r4, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08138DC0 @ =0x00000544
	adds r1, r6, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #0x1e
	strh r0, [r1]
	adds r7, #0x24
	adds r4, r4, r7
	movs r0, #0x10
	strh r0, [r4]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08138DC4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r5, [r5]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08138DC8 @ =0x00000B4B
	adds r1, r5, r3
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	subs r7, #0xa
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r4, r0
	bge _08138D46
	adds r0, r7, #0
	adds r5, r5, r0
_08138D38:
	adds r0, r6, #0
	bl FUN_08137858
	adds r4, #1
	ldrb r1, [r5]
	cmp r4, r1
	blt _08138D38
_08138D46:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #0x21
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _08138DCC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _08138DD0 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r5, [r0]
	movs r1, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _08138DD4 @ =0x00000469
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08138DD8 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r3, _08138DDC @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r2, [r0]
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08138DBC: .4byte 0xFFFFFEFF
_08138DC0: .4byte 0x00000544
_08138DC4: .4byte 0xFFEFFFFF
_08138DC8: .4byte 0x00000B4B
_08138DCC: .4byte FUN_080e48d0
_08138DD0: .4byte 0x0000046D
_08138DD4: .4byte 0x00000469
_08138DD8: .4byte 0x00000484
_08138DDC: .4byte 0x0000046C

	thumb_func_start FUN_08138de0
FUN_08138de0: @ 0x08138DE0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08138c68
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08138E18 @ =0x0000062C
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
	bl FUN_08138c74
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08138E18: .4byte 0x0000062C

	thumb_func_start FUN_08138e1c
FUN_08138e1c: @ 0x08138E1C
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _08138E38 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08138E38: .4byte 0x03002BE0

	thumb_func_start EnemyCentipede_Destroy
EnemyCentipede_Destroy: @ 0x08138E3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_081369d0
	adds r0, r4, #0
	bl FUN_08136aec
	ldr r1, _08138E5C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08138E60
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08138E68
	.align 2, 0
_08138E5C: .4byte 0x0000025D
_08138E60:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08138E68:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08138E84 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08138E88
	movs r0, #1
	b _08138E8A
	.align 2, 0
_08138E84: .4byte 0x00000474
_08138E88:
	movs r0, #0
_08138E8A:
	cmp r0, #0
	beq _08138E96
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08138E96:
	ldr r1, _08138EF0 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08138EAE
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08138EAE:
	ldr r0, _08138EF4 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08138EC6
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08138EC6:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08138EDE
	adds r0, r4, #0
	bl FUN_08002a58
_08138EDE:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08138EF8
	movs r0, #1
	b _08138EFA
	.align 2, 0
_08138EF0: .4byte 0x0000044C
_08138EF4: .4byte 0x0000044D
_08138EF8:
	movs r0, #0
_08138EFA:
	cmp r0, #0
	beq _08138F06
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08138F06:
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

	thumb_func_start EnemyCentipede_Init
EnemyCentipede_Init: @ 0x08138F24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b8
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xb3
	lsls r1, r1, #4
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _08138FB0 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #9
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0813826c
	ldr r3, _08138FB4 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08138FC0
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08138FB8 @ =0x0000D636
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08138FBC @ =0x0000C102
	bl FUN_080e3804
	ldr r4, _08138FB0 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xd4]
	cmp r1, #0x11
	beq _08138F9E
	cmp r1, #0x17
	bne _08138FA2
_08138F9E:
	movs r0, #1
	strb r0, [r5, #7]
_08138FA2:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08139028
	.align 2, 0
_08138FB0: .4byte 0x000001DF
_08138FB4: .4byte 0x0000025D
_08138FB8: .4byte 0x0000D636
_08138FBC: .4byte 0x0000C102
_08138FC0:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081390A4 @ =0x05000002
	bl CpuSet
	ldr r0, _081390A8 @ =0x0000CB05
	ldr r1, _081390AC @ =0x0000D636
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
	ldr r0, _081390B0 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081390B4 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xd4]
_08139028:
	str r7, [sp, #0x28]
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
	ldr r5, _081390B8 @ =0x0000046F
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
	bl Script_GetKeywordValue
	ldr r1, _081390BC @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081390A4 @ =0x05000002
	bl CpuSet
	ldr r3, _081390C0 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0xa8]
	mov r3, r8
	str r3, [sp, #0xac]
	str r6, [sp, #0x80]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08139094
	b _081391F4
_08139094:
	bl VM_GetPC
	cmp r0, #0
	beq _081390C4
	bl Script_GetValue
	adds r1, r0, #0
	b _081390C6
	.align 2, 0
_081390A4: .4byte 0x05000002
_081390A8: .4byte 0x0000CB05
_081390AC: .4byte 0x0000D636
_081390B0: .4byte 0x000004B7
_081390B4: .4byte 0x000001DF
_081390B8: .4byte 0x0000046F
_081390BC: .4byte 0x00000474
_081390C0: .4byte 0x000004B6
_081390C4:
	movs r1, #0
_081390C6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081390EC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x14c]
	str r4, [sp, #0x150]
	cmp r0, #0
	beq _081390F0
	bl Script_GetValue
	adds r1, r0, #0
	b _081390F2
	.align 2, 0
_081390EC: .4byte 0x00000251
_081390F0:
	movs r1, #0
_081390F2:
	ldr r2, _08139128 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813912C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x14c]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x158]
	cmp r0, #0
	beq _08139130
	bl Script_GetValue
	b _08139134
	.align 2, 0
_08139128: .4byte 0x00000252
_0813912C: .4byte 0x000004B4
_08139130:
	ldr r4, [sp, #0x14c]
	ldrb r0, [r4]
_08139134:
	strb r0, [r6]
	ldr r5, [sp, #0x14c]
	ldrb r1, [r5]
	ldr r6, [sp, #0x158]
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
	blt _0813916C
	cmp r1, #0
	blt _0813916C
	ldr r0, _08139170 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813916C
	ldr r0, _08139174 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08139178
_0813916C:
	movs r1, #0
	b _08139186
	.align 2, 0
_08139170: .4byte 0x030046A8
_08139174: .4byte 0x030046AC
_08139178:
	ldr r0, _081391A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08139186:
	ldr r2, _081391A4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081391A8
	adds r0, #4
	b _081391B4
	.align 2, 0
_081391A0: .4byte 0x030046A4
_081391A4: .4byte 0x00000256
_081391A8:
	ldr r0, _081391C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081391B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081391CC
	cmp r2, #2
	beq _081391D0
	b _081391D4
	.align 2, 0
_081391C8: .4byte 0x030046A4
_081391CC:
	ldrb r0, [r4, #4]
	b _081391D2
_081391D0:
	ldrb r0, [r4]
_081391D2:
	subs r1, r1, r0
_081391D4:
	ldr r3, _081391EC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081391F0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08139234
	.align 2, 0
_081391EC: .4byte 0x00000472
_081391F0: .4byte 0x0000FFFF
_081391F4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08139258 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813925C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08139260 @ =0x000004B4
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
	str r5, [sp, #0x14c]
	str r4, [sp, #0x150]
	str r3, [sp, #0x158]
_08139234:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0813927E
	bl VM_GetPC
	cmp r0, #0
	beq _08139264
	bl Script_GetValue
	adds r4, r0, #0
	b _08139266
	.align 2, 0
_08139258: .4byte 0x00000251
_0813925C: .4byte 0x00000252
_08139260: .4byte 0x000004B4
_08139264:
	movs r4, #0x30
_08139266:
	bl VM_GetPC
	cmp r0, #0
	beq _08139278
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0813927A
_08139278:
	movs r5, #0x40
_0813927A:
	mov r8, r4
	b _08139284
_0813927E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08139284:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081392BC
	bl VM_GetPC
	cmp r0, #0
	beq _0813929E
	bl Script_GetValue
	adds r6, r0, #0
	b _081392A0
_0813929E:
	movs r6, #0
_081392A0:
	bl VM_GetPC
	cmp r0, #0
	beq _081392B0
	bl Script_GetValue
	adds r1, r0, #0
	b _081392B2
_081392B0:
	movs r1, #0
_081392B2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081392C6
_081392BC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081392C6:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08139558 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x144]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	lsls r4, r4, #0x10
	str r4, [sp, #0xd0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xdc]
	lsls r6, r6, #0x10
	str r6, [sp, #0xe0]
	lsls r5, r5, #0x10
	str r5, [sp, #0xd8]
	ldr r4, _0813955C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x164]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xcc]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x5c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x60]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x64]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x58]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x90]
	ldr r1, _08139560 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _08139564 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x88]
	ldr r3, _08139568 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x8c]
	ldr r4, _0813956C @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _08139570 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x178]
	ldr r6, _08139574 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _08139578 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x184]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x188]
	ldr r3, _0813957C @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x18c]
	ldr r4, _08139580 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x194]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x180]
	ldr r6, _08139584 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x128]
	ldr r1, _08139588 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _0813958C @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _08139590 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a8]
	ldr r6, _08139594 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x19c]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x30]
	ldr r2, _08139598 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x34]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x38]
	ldr r4, _0813959C @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	ldr r6, _081395A0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x174]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x1a0]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _081395A4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x1a4]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x190]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _081395A8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r1, _081395AC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x130]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _081395B0 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x138]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081395B4 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _081395B8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	ldr r2, _081395BC @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xec]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, _081395C0 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r1, _081395C4 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _081395C8 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _081395CC @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x94]
	ldr r4, _081395D0 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r5, _081395D4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	ldr r6, _081395D8 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081395DC @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x120]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xc4]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x98]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	ldr r6, _081395E0 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0x11c]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x118]
	ldr r3, _081395E4 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _081395E8 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	ldr r6, _081395EC @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _081395F0 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _081395F4 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	ldr r4, _081395F8 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0x110]
	cmp r0, #0
	bne _08139528
	b _08139654
_08139528:
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
_08139548:
	bl VM_GetPC
	cmp r0, #0
	beq _081395FC
	bl Script_GetValue
	b _081395FE
	.align 2, 0
_08139558: .4byte 0x0000025D
_0813955C: .4byte 0x0000025A
_08139560: .4byte 0x0000047A
_08139564: .4byte 0x0000047C
_08139568: .4byte 0x0000047E
_0813956C: .4byte 0x000004A4
_08139570: .4byte 0x000005A4
_08139574: .4byte 0x000005C4
_08139578: .4byte 0x000005CC
_0813957C: .4byte 0x000005D4
_08139580: .4byte 0x000005DC
_08139584: .4byte 0x00000584
_08139588: .4byte 0x00000604
_0813958C: .4byte 0x0000021D
_08139590: .4byte 0x0000060C
_08139594: .4byte 0x000005E4
_08139598: .4byte 0x000005FC
_0813959C: .4byte 0x00000614
_081395A0: .4byte 0x000005BC
_081395A4: .4byte 0x000005EC
_081395A8: .4byte 0x00000624
_081395AC: .4byte 0x0000058C
_081395B0: .4byte 0x00000594
_081395B4: .4byte 0x0000059C
_081395B8: .4byte 0x000005B4
_081395BC: .4byte 0x00000543
_081395C0: .4byte 0x00000496
_081395C4: .4byte 0x00000469
_081395C8: .4byte 0x0000046A
_081395CC: .4byte 0x00000484
_081395D0: .4byte 0x0000046C
_081395D4: .4byte 0x0000046D
_081395D8: .4byte 0x0000046B
_081395DC: .4byte 0x00000553
_081395E0: .4byte 0x00000572
_081395E4: .4byte 0x0000055C
_081395E8: .4byte 0x00000564
_081395EC: .4byte 0x00000565
_081395F0: .4byte 0x00000566
_081395F4: .4byte 0x00000567
_081395F8: .4byte 0x0000056C
_081395FC:
	movs r0, #0x18
_081395FE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08139610
	bl Script_GetValue
	b _08139612
_08139610:
	movs r0, #0x18
_08139612:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08139624
	bl Script_GetValue
	b _08139626
_08139624:
	movs r0, #0
_08139626:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08139638
	bl Script_GetValue
	b _0813963A
_08139638:
	movs r0, #0
_0813963A:
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
	bgt _08139654
	b _08139548
_08139654:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081396A0
	bl VM_GetPC
	cmp r0, #0
	beq _0813966E
	bl Script_GetValue
	adds r4, r0, #0
	b _08139672
_0813966E:
	movs r4, #0x96
	lsls r4, r4, #1
_08139672:
	bl VM_GetPC
	cmp r0, #0
	beq _08139682
	bl Script_GetValue
	adds r6, r0, #0
	b _08139686
_08139682:
	movs r6, #0x96
	lsls r6, r6, #1
_08139686:
	bl VM_GetPC
	cmp r0, #0
	beq _08139694
	bl Script_GetValue
	b _0813969A
_08139694:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0813969A:
	ldr r3, [sp, #0x144]
	strh r0, [r3]
	b _081396A8
_081396A0:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x144]
	strh r6, [r5]
_081396A8:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081396C0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0xac]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081396C0:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0xb4]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0xb0]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08139790
	bl VM_GetPC
	cmp r0, #0
	beq _081396F0
	bl Script_GetValue
	b _081396F2
_081396F0:
	movs r0, #0
_081396F2:
	ldr r1, [sp, #0x15c]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08139700
	asrs r1, r0, #1
	b _08139706
_08139700:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08139706:
	ldr r2, _0813971C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08139720
	bl Script_GetValue
	b _08139722
	.align 2, 0
_0813971C: .4byte 0x00000546
_08139720:
	movs r0, #0
_08139722:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139738
	bl Script_GetValue
	b _0813973A
_08139738:
	movs r0, #0
_0813973A:
	ldr r5, _08139750 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139754
	bl Script_GetValue
	adds r1, r0, #0
	b _08139756
	.align 2, 0
_08139750: .4byte 0x00000187
_08139754:
	movs r1, #0
_08139756:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813976C
	bl Script_GetValue
	b _0813976E
_0813976C:
	movs r0, #0
_0813976E:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139786
	bl Script_GetValue
	adds r1, r0, #0
	b _08139788
_08139786:
	movs r1, #0
_08139788:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08139790:
	ldr r0, [sp, #0x15c]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0xd0]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xdc]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xe0]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xd8]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081397F2
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081397D8
	bl Script_GetValue
	b _081397DA
_081397D8:
	movs r0, #0
_081397DA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081397EA
	bl Script_GetValue
	b _081397EC
_081397EA:
	movs r0, #0
_081397EC:
	ldr r2, _08139854 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_081397F2:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x164]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08139816
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0xac]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08139816:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0813982E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0xac]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0813982E:
	ldr r6, [sp, #0xcc]
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
	ldr r2, [sp, #0x80]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08139858
	movs r0, #1
	b _0813985A
	.align 2, 0
_08139854: .4byte 0x00000189
_08139858:
	movs r0, #0
_0813985A:
	cmp r0, #0
	beq _0813986A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08139894 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_0813986A:
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08139876
	ldr r1, [r7, #0x44]
_08139876:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08139898
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081398A4
	.align 2, 0
_08139894: .4byte FUN_080f48ac
_08139898:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081398A4:
	ldr r5, [sp, #0xd4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081398F2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081398F2
	cmp r0, #0x16
	beq _081398F2
	cmp r0, #0x14
	beq _081398F2
	cmp r0, #9
	beq _081398F2
	cmp r0, #0x19
	beq _081398F2
	cmp r0, #0x1a
	beq _081398F2
	cmp r0, #0xd
	beq _081398F2
	cmp r0, #0x1b
	beq _081398F2
	cmp r0, #0x1f
	beq _081398F2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x14c]
	ldrb r2, [r6]
	ldr r0, [sp, #0x150]
	ldrb r3, [r0]
	ldr r4, [sp, #0x158]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081398F2:
	movs r1, #8
	ldr r5, [sp, #0x80]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08139902
	movs r0, #1
	b _08139904
_08139902:
	movs r0, #0
_08139904:
	cmp r0, #0
	beq _08139912
	ldr r6, [sp, #0xe8]
	ldr r0, [r6]
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	b _08139924
_08139912:
	ldr r2, [sp, #0xe8]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xe4]
	str r0, [r3]
_08139924:
	ldrh r0, [r7]
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	ldr r5, [sp, #0x58]
	ldr r6, [sp, #0x64]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0813994E
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
_0813994E:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	bne _0813995A
	b _08139A68
_0813995A:
	bl VM_GetPC
	cmp r0, #0
	beq _08139968
	bl Script_GetValue
	b _0813996A
_08139968:
	movs r0, #0
_0813996A:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0813997A
	bl Script_GetValue
	b _0813997C
_0813997A:
	movs r0, #0
_0813997C:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0813998C
	bl Script_GetValue
	b _0813998E
_0813998C:
	movs r0, #0
_0813998E:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x58]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081399B6
	cmp r1, #0
	blt _081399B6
	ldr r0, _081399BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081399B6
	ldr r0, _081399C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081399C4
_081399B6:
	movs r1, #0
	b _081399D2
	.align 2, 0
_081399BC: .4byte 0x030046A8
_081399C0: .4byte 0x030046AC
_081399C4:
	ldr r0, _081399EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081399D2:
	ldr r4, _081399F0 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x58]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081399F4
	adds r0, #4
	b _08139A00
	.align 2, 0
_081399EC: .4byte 0x030046A4
_081399F0: .4byte 0x00000256
_081399F4:
	ldr r0, _08139A14 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08139A00:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08139A18
	cmp r3, #2
	beq _08139A1C
	b _08139A20
	.align 2, 0
_08139A14: .4byte 0x030046A4
_08139A18:
	ldrb r0, [r5, #4]
	b _08139A1E
_08139A1C:
	ldrb r0, [r5]
_08139A1E:
	subs r2, r2, r0
_08139A20:
	ldr r5, _08139A4C @ =0x00000472
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
	ldr r1, [sp, #0x168]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08139A50
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08139A5A
	.align 2, 0
_08139A4C: .4byte 0x00000472
_08139A50:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08139A5A:
	ldr r3, [sp, #0x24]
	ldr r4, _08139A84 @ =0x00000B8C
	adds r2, r3, r4
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08139A68:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _08139A96
	bl VM_GetPC
	cmp r0, #0
	beq _08139A88
	bl Script_GetValue
	adds r1, r0, #0
	b _08139A8E
	.align 2, 0
_08139A84: .4byte 0x00000B8C
_08139A88:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r1, r5, #0
_08139A8E:
	ldr r6, [sp, #0x24]
	ldr r2, _08139AD8 @ =0x00000B46
	adds r0, r6, r2
	strh r1, [r0]
_08139A96:
	adds r0, r7, #0
	bl FUN_08138710
	ldr r4, _08139ADC @ =0x000001A1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x90]
	strh r0, [r3]
	ldr r6, [sp, #0x84]
	strh r4, [r6]
	ldr r0, [sp, #0x88]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x168]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08139AE0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08139AEC
	.align 2, 0
_08139AD8: .4byte 0x00000B46
_08139ADC: .4byte 0x000001A1
_08139AE0:
	ldr r2, [r7, #0x44]
	ldr r0, _08139B24 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08139AEC:
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08139B3C
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08139B28
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
	b _08139B32
	.align 2, 0
_08139B24: .4byte 0x03003584
_08139B28:
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_08139B32:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08139B3C:
	adds r0, r7, #0
	bl FUN_081373b8
	adds r0, r7, #0
	bl FUN_08136d00
	ldr r0, _08139CE8 @ =0x00000B58
	ldr r6, [sp, #0x24]
	adds r0, r6, r0
	str r0, [sp, #0x1b4]
	ldr r1, _08139CEC @ =0x00000B7C
	adds r6, r6, r1
	mov r8, r6
	ldr r2, _08139CF0 @ =FUN_08138de0
	mov sb, r2
	ldr r3, _08139CF4 @ =FUN_081382b0
	mov sl, r3
	ldr r4, _08139CF8 @ =FUN_08132d30
	mov ip, r4
	movs r2, #0
	ldr r4, _08139CFC @ =FUN_08133eec
	ldr r5, _08139D00 @ =FUN_081340d4
	ldr r3, _08139D04 @ =FUN_080f62b0
	ldr r6, _08139D08 @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0xa8]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1b4]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0xa4]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0x124]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0x134]
	str r6, [r0]
	ldr r1, _08139D0C @ =FUN_08132a24
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r0, _08139D10 @ =FUN_08132c24
	ldr r1, [sp, #0x154]
	str r0, [r1]
	ldr r6, _08139D14 @ =FUN_08132d34
	ldr r0, [sp, #0x178]
	str r6, [r0]
	ldr r1, [sp, #0x17c]
	str r3, [r1]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r4, [sp, #0x188]
	str r5, [r4]
	ldr r0, _08139D18 @ =FUN_080f44f4
	ldr r5, [sp, #0x18c]
	str r0, [r5]
	ldr r0, _08139D1C @ =FUN_080f410c
	ldr r6, [sp, #0x194]
	str r0, [r6]
	ldr r0, [sp, #0x180]
	str r2, [r0]
	ldr r1, _08139D20 @ =FUN_08132e60
	ldr r3, [sp, #0x128]
	str r1, [r3]
	ldr r4, [sp, #0x1ac]
	ldr r5, [sp, #0x3c]
	str r4, [r5]
	ldr r0, _08139D24 @ =FUN_080f0430
	ldr r6, [sp, #0x40]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0x114]
	strb r1, [r0]
	ldr r0, _08139D28 @ =0x085AD470
	ldr r3, [sp, #0x44]
	str r0, [r3]
	ldr r0, _08139D2C @ =FUN_080e73c8
	ldr r4, [sp, #0x1a8]
	str r0, [r4]
	ldr r5, [sp, #0x19c]
	str r2, [r5]
	ldr r6, [sp, #0x30]
	str r2, [r6]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	ldr r1, [sp, #0x38]
	str r2, [r1]
	ldr r3, [sp, #0x48]
	str r2, [r3]
	ldr r0, _08139D30 @ =FUN_080f0320
	ldr r4, [sp, #0x4c]
	str r0, [r4]
	ldr r0, _08139D34 @ =FUN_080eff14
	ldr r5, [sp, #0x174]
	str r0, [r5]
	ldr r0, _08139D38 @ =FUN_080e72b0
	ldr r6, [sp, #0x1a0]
	str r0, [r6]
	ldr r0, _08139D3C @ =FUN_08133ed4
	ldr r1, [sp, #0x198]
	str r0, [r1]
	ldr r0, _08139D40 @ =FUN_080f47c8
	ldr r3, [sp, #0x1a4]
	str r0, [r3]
	ldr r0, _08139D44 @ =FUN_080f54e4
	ldr r4, [sp, #0x190]
	str r0, [r4]
	ldr r5, [sp, #0x160]
	str r2, [r5]
	ldr r0, _08139D48 @ =FUN_080f6e64
	ldr r6, [sp, #0x50]
	str r0, [r6]
	ldr r0, _08139D4C @ =FUN_080f64f0
	ldr r1, [sp, #0x130]
	str r0, [r1]
	ldr r0, _08139D50 @ =FUN_080f84d4
	ldr r3, [sp, #0x54]
	str r0, [r3]
	ldr r0, _08139D54 @ =FUN_080f624c
	ldr r4, [sp, #0x170]
	str r0, [r4]
	ldr r0, _08139D58 @ =FUN_080f56ec
	ldr r5, [sp, #0x138]
	str r0, [r5]
	ldr r0, _08139D5C @ =FUN_080f5b34
	ldr r6, [sp, #0x13c]
	str r0, [r6]
	ldr r0, _08139D60 @ =FUN_080f5fac
	ldr r1, [sp, #0x140]
	str r0, [r1]
	ldr r3, [sp, #0x16c]
	str r2, [r3]
	movs r0, #0x28
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08139D64 @ =FUN_0813744c
	str r0, [r1]
	ldr r6, _08139D68 @ =0x000005FC
	adds r0, r7, r6
	str r2, [r0]
	ldr r0, _08139D6C @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _08139D70 @ =FUN_081387a0
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08139D74 @ =FUN_08138808
	str r0, [r1]
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08139D78 @ =FUN_0813880c
	str r0, [r1]
	ldr r4, _08139D7C @ =0x0000058C
	adds r1, r7, r4
	ldr r0, _08139D80 @ =FUN_08138cb0
	str r0, [r1]
	subs r5, #0x44
	adds r1, r7, r5
	ldr r0, _08139D84 @ =FUN_08137a50
	str r0, [r1]
	ldr r1, _08139D88 @ =0x00100200
	ldr r6, [sp, #0xa8]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #8
	ldr r2, [sp, #0xac]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x40
	ldr r3, [sp, #0x80]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r4, [sp, #0xb8]
	strh r0, [r4]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08139D96
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08139CD8:
	bl VM_GetPC
	cmp r0, #0
	beq _08139D8C
	bl Script_GetValue
	b _08139D8E
	.align 2, 0
_08139CE8: .4byte 0x00000B58
_08139CEC: .4byte 0x00000B7C
_08139CF0: .4byte FUN_08138de0
_08139CF4: .4byte FUN_081382b0
_08139CF8: .4byte FUN_08132d30
_08139CFC: .4byte FUN_08133eec
_08139D00: .4byte FUN_081340d4
_08139D04: .4byte FUN_080f62b0
_08139D08: .4byte FUN_080f62ac
_08139D0C: .4byte FUN_08132a24
_08139D10: .4byte FUN_08132c24
_08139D14: .4byte FUN_08132d34
_08139D18: .4byte FUN_080f44f4
_08139D1C: .4byte FUN_080f410c
_08139D20: .4byte FUN_08132e60
_08139D24: .4byte FUN_080f0430
_08139D28: .4byte 0x085AD470
_08139D2C: .4byte FUN_080e73c8
_08139D30: .4byte FUN_080f0320
_08139D34: .4byte FUN_080eff14
_08139D38: .4byte FUN_080e72b0
_08139D3C: .4byte FUN_08133ed4
_08139D40: .4byte FUN_080f47c8
_08139D44: .4byte FUN_080f54e4
_08139D48: .4byte FUN_080f6e64
_08139D4C: .4byte FUN_080f64f0
_08139D50: .4byte FUN_080f84d4
_08139D54: .4byte FUN_080f624c
_08139D58: .4byte FUN_080f56ec
_08139D5C: .4byte FUN_080f5b34
_08139D60: .4byte FUN_080f5fac
_08139D64: .4byte FUN_0813744c
_08139D68: .4byte 0x000005FC
_08139D6C: .4byte 0x000005AC
_08139D70: .4byte FUN_081387a0
_08139D74: .4byte FUN_08138808
_08139D78: .4byte FUN_0813880c
_08139D7C: .4byte 0x0000058C
_08139D80: .4byte FUN_08138cb0
_08139D84: .4byte FUN_08137a50
_08139D88: .4byte 0x00100200
_08139D8C:
	movs r0, #0
_08139D8E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08139CD8
_08139D96:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xbc]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x9c]
	strh r0, [r3]
	cmp r2, #0
	beq _08139DCE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0xa8]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08139DCE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08139DCE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x80]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08139DE0
	movs r0, #1
	b _08139DE2
_08139DE0:
	movs r0, #0
_08139DE2:
	cmp r0, #0
	beq _08139DF4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0xac]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08139DF4:
	cmp r2, #1
	beq _08139E28
	movs r0, #0
	ldr r1, [sp, #0x68]
	strb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, [sp, #0x70]
	strb r0, [r3]
	ldr r4, [sp, #0x94]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x78]
	strb r1, [r5]
	ldr r6, [sp, #0x154]
	ldr r2, [r6]
	ldr r3, [sp, #0x7c]
	strb r1, [r3]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0xf0]
	strb r0, [r5]
	ldr r6, [sp, #0x120]
	str r2, [r6]
	ldr r1, [sp, #0xc4]
	strh r0, [r1]
_08139E28:
	movs r1, #2
	ldr r2, [sp, #0x80]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08139E38
	movs r0, #1
	b _08139E3A
_08139E38:
	movs r0, #0
_08139E3A:
	cmp r0, #0
	beq _08139E54
	ldr r0, _08139E50 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x98]
	strh r0, [r4]
	b _08139E5E
	.align 2, 0
_08139E50: .4byte 0x030046A0
_08139E54:
	ldr r0, [sp, #0x58]
	bl FUN_08241574
	ldr r5, [sp, #0x98]
	strh r0, [r5]
_08139E5E:
	movs r1, #0x40
	ldr r6, [sp, #0x80]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08139E6E
	movs r0, #1
	b _08139E70
_08139E6E:
	movs r0, #0
_08139E70:
	cmp r0, #0
	beq _08139E80
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08139EA4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08139E80:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _08139EB2
	ldr r0, _08139EA8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x98]
	ldrh r2, [r2]
	cmp r0, r2
	bne _08139EAC
	movs r0, #1
	b _08139EAE
	.align 2, 0
_08139EA4: .4byte 0xFFFFFEFF
_08139EA8: .4byte 0x030046A0
_08139EAC:
	movs r0, #0
_08139EAE:
	cmp r0, #0
	bne _08139EBA
_08139EB2:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08139EBA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08139FA2
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
	beq _08139EFC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08139F04
_08139EFC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08139F04:
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
	beq _08139F28
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08139F30
_08139F28:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08139F30:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08139F68 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _08139FAC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08139F6C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08139F60
	ldrb r0, [r4, #5]
_08139F60:
	subs r0, #1
	strh r0, [r4, #8]
	b _08139F7C
	.align 2, 0
_08139F68: .4byte 0x0000FFFF
_08139F6C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08139F7C
	strh r1, [r4, #8]
_08139F7C:
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
	bne _08139FAC
	movs r0, #1
	strb r0, [r4, #7]
	b _08139FAC
_08139FA2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08139FAC:
	movs r0, #0
	ldr r3, [sp, #0xc8]
	str r0, [r3]
	ldr r0, _08139FC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08139FC8
	movs r0, #1
	b _08139FCA
	.align 2, 0
_08139FC4: .4byte 0x030047A4
_08139FC8:
	movs r0, #0
_08139FCA:
	cmp r0, #0
	bne _0813A00A
	ldr r4, [sp, #0xd4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08139FF2
	adds r0, r1, #0
	cmp r0, #7
	beq _08139FF2
	cmp r0, #6
	beq _08139FF2
	cmp r0, #0x15
	beq _08139FF2
	cmp r0, #0x14
	beq _08139FF2
	cmp r0, #0x17
	bne _0813A00A
_08139FF2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x80]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0813A00A:
	adds r0, r7, #0
	bl FUN_081355f0
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x68]
	strb r2, [r6]
	ldr r1, [sp, #0x6c]
	strb r2, [r1]
	ldr r3, [sp, #0x70]
	strb r0, [r3]
	ldr r4, [sp, #0x94]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x78]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x7c]
	strb r1, [r3]
	ldr r4, [sp, #0x74]
	strb r2, [r4]
	ldr r5, [sp, #0xf0]
	strb r1, [r5]
	ldr r6, [sp, #0x120]
	str r0, [r6]
	ldr r0, [sp, #0xc4]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081355ac
	adds r0, r7, #0
	bl FUN_08138c54
	ldr r1, _0813A0F8 @ =0x0000D636
	ldr r2, _0813A0FC @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_08136140
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x58]
	bl FUN_08137360
	adds r0, r7, #0
	bl FUN_081380d8
	adds r0, r7, #0
	bl FUN_081355f0
	adds r0, r7, #0
	bl FUN_08136be4
	ldr r1, [sp, #0x80]
	ldrh r0, [r1]
	ldr r2, [sp, #0x11c]
	strh r0, [r2]
	ldr r3, [sp, #0xc0]
	ldrh r0, [r3]
	ldr r4, [sp, #0x118]
	strh r0, [r4]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xf8]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
	ldr r4, [sp, #0x68]
	ldrb r0, [r4]
	ldr r5, [sp, #0x100]
	strb r0, [r5]
	ldr r6, [sp, #0x6c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x104]
	strb r0, [r1]
	ldr r2, [sp, #0x70]
	ldrb r0, [r2]
	ldr r3, [sp, #0x108]
	strb r0, [r3]
	ldr r4, [sp, #0x120]
	ldr r0, [r4]
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r6, [sp, #0xf0]
	ldrb r0, [r6]
	ldr r1, [sp, #0x110]
	strb r0, [r1]
	ldr r2, _0813A100 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0813A104 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0813A108 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0813A10C @ =FUN_08138e1c
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0813A110 @ =EnemyCentipede_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813A114
	movs r0, #0
	b _0813A118
	.align 2, 0
_0813A0F8: .4byte 0x0000D636
_0813A0FC: .4byte 0x0000C102
_0813A100: .4byte 0x0000057C
_0813A104: .4byte FUN_080f09e0
_0813A108: .4byte 0x0000061C
_0813A10C: .4byte FUN_08138e1c
_0813A110: .4byte EnemyCentipede_Destroy
_0813A114:
	movs r0, #1
	rsbs r0, r0, #0
_0813A118:
	add sp, #0x1b8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyCentipede_Create
EnemyCentipede_Create: @ 0x0813A128
	push {r4, r5, lr}
	ldr r5, _0813A15C @ =0x00000B94
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0813A154
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyCentipede_Init
	cmp r0, #0
	bge _0813A154
	adds r0, r4, #0
	bl EnemyCentipede_Destroy
	adds r0, r4, #0
	bl Free
_0813A154:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813A15C: .4byte 0x00000B94

	thumb_func_start FUN_0813a160
FUN_0813a160: @ 0x0813A160
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x44]
	ldr r0, _0813A1BC @ =0x03002BE0
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
	ldr r2, _0813A1C0 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0813A1C4
	asrs r1, r0, #0xc
	b _0813A1CA
	.align 2, 0
_0813A1BC: .4byte 0x03002BE0
_0813A1C0: .4byte 0x085B0A08
_0813A1C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813A1CA:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _0813A1EC @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0813A1F0
	asrs r1, r0, #0xc
	b _0813A1F6
	.align 2, 0
_0813A1EC: .4byte 0x085B0A08
_0813A1F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813A1F6:
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
	beq _0813A21C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	b _0813A232
_0813A21C:
	cmp r1, #0
	beq _0813A230
	mov r0, sp
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Div
	b _0813A232
_0813A230:
	movs r0, #0
_0813A232:
	cmp r0, #0
	blt _0813A23A
	asrs r0, r0, #1
	b _0813A240
_0813A23A:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0813A240:
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813a250
FUN_0813a250: @ 0x0813A250
	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, _0813A268 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_0813A268: .4byte 0x00000674

