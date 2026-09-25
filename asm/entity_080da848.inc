	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d8644
FUN_080d8644: @ 0x080D8644
	push {r4, lr}
	movs r4, #0
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x32
	adds r2, r0, #0
	adds r2, #0x3e
	adds r0, #0x4c
_080D8654:
	strb r3, [r1]
	strb r3, [r1, #3]
	stm r0!, {r3}
	strh r3, [r2]
	adds r1, #1
	adds r2, #2
	adds r4, #1
	cmp r4, #2
	ble _080D8654
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d866c
FUN_080d866c: @ 0x080D866C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r5, #0x58]
	cmp r3, #0
	bne _080D8678
	b _080D877E
_080D8678:
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, _080D8694 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080D8698
	movs r0, #1
	b _080D869A
	.align 2, 0
_080D8694: .4byte 0x030046A0
_080D8698:
	movs r0, #0
_080D869A:
	cmp r0, #0
	beq _080D877E
	adds r2, r5, #0
	adds r2, #0x2e
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _080D877E
	ldr r1, _080D86D0 @ =0x00000553
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _080D877E
	ldr r2, _080D86D4 @ =0x000001DF
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080D877E
	lsls r0, r0, #2
	ldr r1, _080D86D8 @ =_080D86DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D86D0: .4byte 0x00000553
_080D86D4: .4byte 0x000001DF
_080D86D8: .4byte _080D86DC
_080D86DC: @ jump table
	.4byte _080D8758 @ case 0
	.4byte _080D877E @ case 1
	.4byte _080D8766 @ case 2
	.4byte _080D8754 @ case 3
	.4byte _080D877E @ case 4
	.4byte _080D877E @ case 5
	.4byte _080D877E @ case 6
	.4byte _080D877E @ case 7
	.4byte _080D877E @ case 8
	.4byte _080D8770 @ case 9
	.4byte _080D877E @ case 10
	.4byte _080D877E @ case 11
	.4byte _080D877E @ case 12
	.4byte _080D877E @ case 13
	.4byte _080D877E @ case 14
	.4byte _080D877E @ case 15
	.4byte _080D877E @ case 16
	.4byte _080D877E @ case 17
	.4byte _080D877E @ case 18
	.4byte _080D877E @ case 19
	.4byte _080D877E @ case 20
	.4byte _080D877E @ case 21
	.4byte _080D877E @ case 22
	.4byte _080D877E @ case 23
	.4byte _080D877E @ case 24
	.4byte _080D877E @ case 25
	.4byte _080D877E @ case 26
	.4byte _080D8754 @ case 27
	.4byte _080D877E @ case 28
	.4byte _080D8766 @ case 29
_080D8754:
	movs r0, #0xee
	b _080D8772
_080D8758:
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D877E
	movs r0, #0xff
	b _080D8772
_080D8766:
	adds r0, r3, #0
	movs r1, #3
	bl FUN_080e81dc
	b _080D8776
_080D8770:
	ldr r0, _080D8784 @ =0x000001CF
_080D8772:
	bl PlaySound_082406e0
_080D8776:
	ldrb r1, [r4]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4]
_080D877E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D8784: .4byte 0x000001CF

	thumb_func_start FUN_080d8788
FUN_080d8788: @ 0x080D8788
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _080D8800
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D87B0
	movs r0, #1
	b _080D87B2
_080D87B0:
	movs r0, #0
_080D87B2:
	cmp r0, #0
	beq _080D884A
	adds r0, r5, #0
	bl FUN_080d8644
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x24]
	str r0, [r5, #0x48]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r4, [r0]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r2, _080D87FC @ =0x000009FC
	add r2, r8
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	movs r0, #1
	b _080D884C
	.align 2, 0
_080D87FC: .4byte 0x000009FC
_080D8800:
	cmp r0, #0xa
	ble _080D883E
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D8816
	movs r0, #1
	b _080D8818
_080D8816:
	movs r0, #0
_080D8818:
	cmp r0, #0
	beq _080D883E
	ldr r2, _080D8858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D885C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D8860 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
_080D883E:
	adds r0, r5, #0
	bl FUN_080d866c
	ldrh r0, [r5, #0x3c]
	subs r0, #1
	strh r0, [r5, #0x3c]
_080D884A:
	movs r0, #0
_080D884C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D8858: .4byte 0x030046B8
_080D885C: .4byte 0x000003FF
_080D8860: .4byte 0x0203B400

	thumb_func_start FUN_080d8864
FUN_080d8864: @ 0x080D8864
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080D889A
	movs r2, #1
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080D8888
	movs r0, #1
	b _080D888A
_080D8888:
	movs r0, #0
_080D888A:
	cmp r0, #0
	beq _080D88DA
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	b _080D88DA
_080D889A:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D88AC
	movs r0, #1
	b _080D88AE
_080D88AC:
	movs r0, #0
_080D88AE:
	cmp r0, #0
	beq _080D88D4
	ldr r2, _080D88E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D88E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D88E8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r5, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
_080D88D4:
	ldrh r0, [r4, #0x3c]
	subs r0, #1
	strh r0, [r4, #0x3c]
_080D88DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D88E0: .4byte 0x030046B8
_080D88E4: .4byte 0x000003FF
_080D88E8: .4byte 0x0203B400

	thumb_func_start FUN_080d88ec
FUN_080d88ec: @ 0x080D88EC
	push {lr}
	cmp r0, #1
	beq _080D8918
	cmp r0, #1
	bgt _080D88FC
	cmp r0, #0
	beq _080D8906
	b _080D894E
_080D88FC:
	cmp r0, #2
	beq _080D892A
	cmp r0, #3
	beq _080D8936
	b _080D894E
_080D8906:
	cmp r3, #0
	bne _080D8914
	movs r0, #0xc
	rsbs r0, r0, #0
	str r0, [r1]
	str r3, [r2]
	b _080D894E
_080D8914:
	str r0, [r1]
	b _080D894C
_080D8918:
	cmp r3, #3
	bgt _080D894E
	cmp r3, #0
	blt _080D894E
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D894C
_080D892A:
	cmp r3, #0
	beq _080D8932
	cmp r3, #3
	bne _080D8942
_080D8932:
	movs r0, #0
	b _080D8946
_080D8936:
	cmp r3, #0
	beq _080D893E
	cmp r3, #3
	bne _080D8942
_080D893E:
	movs r0, #0
	b _080D8946
_080D8942:
	movs r0, #8
	rsbs r0, r0, #0
_080D8946:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
_080D894C:
	str r0, [r2]
_080D894E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8954
FUN_080d8954: @ 0x080D8954
	push {lr}
	cmp r0, #1
	beq _080D8978
	cmp r0, #1
	bgt _080D8964
	cmp r0, #0
	beq _080D896E
	b _080D898A
_080D8964:
	cmp r0, #2
	beq _080D8982
	cmp r0, #3
	beq _080D8982
	b _080D898A
_080D896E:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D8988
_080D8978:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8988
_080D8982:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8988:
	str r0, [r2]
_080D898A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8990
FUN_080d8990: @ 0x080D8990
	push {lr}
	cmp r0, #1
	beq _080D89B4
	cmp r0, #1
	bgt _080D89A0
	cmp r0, #0
	beq _080D89AA
	b _080D89C6
_080D89A0:
	cmp r0, #2
	beq _080D89BE
	cmp r0, #3
	beq _080D89BE
	b _080D89C6
_080D89AA:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D89C4
_080D89B4:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D89C4
_080D89BE:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D89C4:
	str r0, [r2]
_080D89C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d89cc
FUN_080d89cc: @ 0x080D89CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	movs r5, #0
	cmp r0, #0
	beq _080D89E8
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	ble _080D89E8
	movs r5, #1
_080D89E8:
	cmp r4, #1
	beq _080D8A78
	cmp r4, #1
	bgt _080D89F6
	cmp r4, #0
	beq _080D8A00
	b _080D8A8A
_080D89F6:
	cmp r4, #2
	beq _080D8A82
	cmp r4, #3
	beq _080D8A82
	b _080D8A8A
_080D8A00:
	cmp r5, #0
	bne _080D8A3E
	cmp r3, #1
	beq _080D8A24
	cmp r3, #1
	bgt _080D8A12
	cmp r3, #0
	beq _080D8A1C
	b _080D8A8A
_080D8A12:
	cmp r3, #2
	beq _080D8A2C
	cmp r3, #3
	beq _080D8A36
	b _080D8A8A
_080D8A1C:
	movs r0, #0x40
	str r0, [r1]
	str r3, [r2]
	b _080D8A8A
_080D8A24:
	movs r0, #0xc
	str r0, [r1]
	movs r0, #0x20
	b _080D8A88
_080D8A2C:
	movs r0, #0x1c
	rsbs r0, r0, #0
	str r0, [r1]
	str r5, [r2]
	b _080D8A8A
_080D8A36:
	movs r0, #0x1c
	str r0, [r1]
	subs r0, #0x3c
	b _080D8A88
_080D8A3E:
	cmp r3, #1
	beq _080D8A5E
	cmp r3, #1
	bgt _080D8A4C
	cmp r3, #0
	beq _080D8A56
	b _080D8A8A
_080D8A4C:
	cmp r3, #2
	beq _080D8A66
	cmp r3, #3
	beq _080D8A70
	b _080D8A8A
_080D8A56:
	movs r0, #0xc0
	str r0, [r1]
	movs r0, #0xa
	b _080D8A88
_080D8A5E:
	movs r0, #0x1e
	str r0, [r1]
	movs r0, #0xc0
	b _080D8A88
_080D8A66:
	movs r0, #0x1a
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x2a
	b _080D8A88
_080D8A70:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x70
	b _080D8A88
_080D8A78:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8A88
_080D8A82:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8A88:
	str r0, [r2]
_080D8A8A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8a90
FUN_080d8a90: @ 0x080D8A90
	push {lr}
	cmp r0, #1
	beq _080D8AE6
	cmp r0, #1
	bgt _080D8AA0
	cmp r0, #0
	beq _080D8AAA
	b _080D8B54
_080D8AA0:
	cmp r0, #2
	beq _080D8B00
	cmp r0, #3
	beq _080D8B18
	b _080D8B54
_080D8AAA:
	cmp r3, #1
	beq _080D8ACA
	cmp r3, #1
	bgt _080D8AB8
	cmp r3, #0
	beq _080D8AC2
	b _080D8B54
_080D8AB8:
	cmp r3, #2
	beq _080D8AD4
	cmp r3, #3
	beq _080D8ADE
	b _080D8B54
_080D8AC2:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x6a
	b _080D8B52
_080D8ACA:
	movs r0, #0x24
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x18
	b _080D8B52
_080D8AD4:
	movs r0, #0x56
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0x4a
	b _080D8B52
_080D8ADE:
	movs r0, #0x20
	str r0, [r1]
	subs r0, #0x80
	b _080D8B52
_080D8AE6:
	cmp r3, #0
	beq _080D8AEE
	cmp r3, #3
	bne _080D8AF6
_080D8AEE:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8B52
_080D8AF6:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8B52
_080D8B00:
	cmp r3, #0
	beq _080D8B08
	cmp r3, #3
	bne _080D8B0C
_080D8B08:
	movs r0, #0
	b _080D8B10
_080D8B0C:
	movs r0, #8
	rsbs r0, r0, #0
_080D8B10:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8B52
_080D8B18:
	cmp r3, #1
	beq _080D8B38
	cmp r3, #1
	bgt _080D8B26
	cmp r3, #0
	beq _080D8B30
	b _080D8B54
_080D8B26:
	cmp r3, #2
	beq _080D8B42
	cmp r3, #3
	beq _080D8B4C
	b _080D8B54
_080D8B30:
	movs r0, #0xa
	str r0, [r1]
	str r3, [r2]
	b _080D8B54
_080D8B38:
	movs r0, #0xe
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #2
	b _080D8B52
_080D8B42:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0xe
	b _080D8B52
_080D8B4C:
	movs r0, #8
	str r0, [r1]
	subs r0, #0xc
_080D8B52:
	str r0, [r2]
_080D8B54:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8b58
FUN_080d8b58: @ 0x080D8B58
	push {lr}
	cmp r0, #1
	beq _080D8BAC
	cmp r0, #1
	bgt _080D8B68
	cmp r0, #0
	beq _080D8B72
	b _080D8C1A
_080D8B68:
	cmp r0, #2
	beq _080D8BC6
	cmp r0, #3
	beq _080D8BDE
	b _080D8C1A
_080D8B72:
	cmp r3, #1
	beq _080D8B92
	cmp r3, #1
	bgt _080D8B80
	cmp r3, #0
	beq _080D8B8A
	b _080D8C1A
_080D8B80:
	cmp r3, #2
	beq _080D8B9A
	cmp r3, #3
	beq _080D8BA4
	b _080D8C1A
_080D8B8A:
	movs r0, #0xdc
	str r0, [r1]
	movs r0, #0x20
	b _080D8C18
_080D8B92:
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0xd2
	b _080D8C18
_080D8B9A:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x4e
	b _080D8C18
_080D8BA4:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x60
	b _080D8C18
_080D8BAC:
	cmp r3, #0
	beq _080D8BB4
	cmp r3, #3
	bne _080D8BBC
_080D8BB4:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8C18
_080D8BBC:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8C18
_080D8BC6:
	cmp r3, #0
	beq _080D8BCE
	cmp r3, #3
	bne _080D8BD2
_080D8BCE:
	movs r0, #0
	b _080D8BD6
_080D8BD2:
	movs r0, #8
	rsbs r0, r0, #0
_080D8BD6:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8C18
_080D8BDE:
	cmp r3, #1
	beq _080D8BFE
	cmp r3, #1
	bgt _080D8BEC
	cmp r3, #0
	beq _080D8BF6
	b _080D8C1A
_080D8BEC:
	cmp r3, #2
	beq _080D8C08
	cmp r3, #3
	beq _080D8C12
	b _080D8C1A
_080D8BF6:
	movs r0, #2
	str r0, [r1]
	movs r0, #0xa
	b _080D8C18
_080D8BFE:
	movs r0, #8
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0xe
	b _080D8C18
_080D8C08:
	movs r0, #0xa
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #8
	b _080D8C18
_080D8C12:
	movs r0, #6
	str r0, [r1]
	movs r0, #5
_080D8C18:
	str r0, [r2]
_080D8C1A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8c20
FUN_080d8c20: @ 0x080D8C20
	push {lr}
	cmp r0, #0
	blt _080D8C6C
	cmp r0, #2
	ble _080D8C6C
	cmp r0, #3
	bne _080D8C6C
	cmp r3, #1
	beq _080D8C50
	cmp r3, #1
	bgt _080D8C3C
	cmp r3, #0
	beq _080D8C46
	b _080D8C6C
_080D8C3C:
	cmp r3, #2
	beq _080D8C5A
	cmp r3, #3
	beq _080D8C62
	b _080D8C6C
_080D8C46:
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #6
	b _080D8C6A
_080D8C50:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #3
	b _080D8C6A
_080D8C5A:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	b _080D8C6A
_080D8C62:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #7
_080D8C6A:
	str r0, [r2]
_080D8C6C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8c70
FUN_080d8c70: @ 0x080D8C70
	push {lr}
	adds r3, r1, #0
	cmp r0, #5
	bhi _080D8CBC
	lsls r0, r0, #2
	ldr r1, _080D8C84 @ =_080D8C88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8C84: .4byte _080D8C88
_080D8C88: @ jump table
	.4byte _080D8CA0 @ case 0
	.4byte _080D8CAA @ case 1
	.4byte _080D8CB4 @ case 2
	.4byte _080D8CB4 @ case 3
	.4byte _080D8CAA @ case 4
	.4byte _080D8CAA @ case 5
_080D8CA0:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
	subs r0, #0xb
	b _080D8CBA
_080D8CAA:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r3]
	adds r0, #8
	b _080D8CBA
_080D8CB4:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
_080D8CBA:
	str r0, [r2]
_080D8CBC:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8cc0
FUN_080d8cc0: @ 0x080D8CC0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r6, [sp, #0x14]
	adds r0, r5, #0
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r5, r0, #6
	subs r0, r1, #1
	cmp r0, #0x1d
	bhi _080D8DC6
	lsls r0, r0, #2
	ldr r1, _080D8CE4 @ =_080D8CE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8CE4: .4byte _080D8CE8
_080D8CE8: @ jump table
	.4byte _080D8D6E @ case 0
	.4byte _080D8DC6 @ case 1
	.4byte _080D8D7C @ case 2
	.4byte _080D8D60 @ case 3
	.4byte _080D8D9C @ case 4
	.4byte _080D8D9C @ case 5
	.4byte _080D8D9C @ case 6
	.4byte _080D8DC6 @ case 7
	.4byte _080D8DC6 @ case 8
	.4byte _080D8D8A @ case 9
	.4byte _080D8DC6 @ case 10
	.4byte _080D8DC6 @ case 11
	.4byte _080D8DC6 @ case 12
	.4byte _080D8DC6 @ case 13
	.4byte _080D8DC6 @ case 14
	.4byte _080D8DC6 @ case 15
	.4byte _080D8DC6 @ case 16
	.4byte _080D8DC6 @ case 17
	.4byte _080D8DC6 @ case 18
	.4byte _080D8DC6 @ case 19
	.4byte _080D8DAA @ case 20
	.4byte _080D8DC6 @ case 21
	.4byte _080D8DC6 @ case 22
	.4byte _080D8DC6 @ case 23
	.4byte _080D8DC6 @ case 24
	.4byte _080D8DC6 @ case 25
	.4byte _080D8DB8 @ case 26
	.4byte _080D8D60 @ case 27
	.4byte _080D8DC6 @ case 28
	.4byte _080D8D7C @ case 29
_080D8D60:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d88ec
	b _080D8DD2
_080D8D6E:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8954
	b _080D8DD2
_080D8D7C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8990
	b _080D8DD2
_080D8D8A:
	ldr r0, [sp, #0x18]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d89cc
	b _080D8DD2
_080D8D9C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8a90
	b _080D8DD2
_080D8DAA:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8b58
	b _080D8DD2
_080D8DB8:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c20
	b _080D8DD2
_080D8DC6:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c70
_080D8DD2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8ddc
FUN_080d8ddc: @ 0x080D8DDC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080d8de0
FUN_080d8de0: @ 0x080D8DE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, _080D8E88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D8E78
	ldr r2, [r7, #0x48]
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _080D8E78
	adds r0, r7, #0
	adds r0, #0x32
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D8E78
	ldr r3, _080D8E8C @ =0x0203B400
	mov ip, r3
	ldr r0, _080D8E90 @ =0x030046B8
	mov sb, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080D8E94 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r5, #3
	adds r2, r7, r2
	movs r3, #0xf
	ands r0, r3
	subs r0, #8
	mov sl, r0
	movs r0, #0
	mov r8, r0
	mov r0, sl
	strh r0, [r2, #4]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r2, #6]
	adds r1, #1
	ands r1, r4
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r3
	subs r0, #8
	strh r0, [r2, #8]
	ldrb r1, [r6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6]
	lsls r1, r5, #2
	adds r0, r7, #0
	adds r0, #0x4c
	adds r0, r0, r1
	mov r1, r8
	str r1, [r0]
_080D8E78:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8E88: .4byte 0x0300015C
_080D8E8C: .4byte 0x0203B400
_080D8E90: .4byte 0x030046B8
_080D8E94: .4byte 0x000003FF

	thumb_func_start FUN_080d8e98
FUN_080d8e98: @ 0x080D8E98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _080D8EF4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D8EB0
	b _080D928C
_080D8EB0:
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x88
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #0x10]
	mov sb, r1
	adds r2, r7, #0
	adds r2, #0x38
	str r2, [sp, #0x14]
	movs r3, #0
	str r3, [sp, #0x1c]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	adds r5, r7, #4
	mov sl, r5
	adds r6, r0, #0
_080D8ED6:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	bne _080D8EF8
	ldr r0, [r6]
	orrs r0, r3
	str r0, [r6]
	ldr r4, [sp, #0x10]
	adds r4, #1
	str r4, [sp, #0x10]
	b _080D9208
	.align 2, 0
_080D8EF4: .4byte 0x0300015C
_080D8EF8:
	adds r0, r7, #0
	adds r0, #0x32
	add r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D8F0A
	b _080D9070
_080D8F0A:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r5, [sp, #0x1c]
	adds r1, r0, r5
	ldr r1, [r1]
	str r0, [sp, #0x18]
	cmp r1, #0xe
	ble _080D8F2A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	b _080D9208
_080D8F2A:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D8F3E
	cmp r0, #3
	beq _080D8F46
	movs r3, #0
	mov ip, r3
	b _080D8F4C
_080D8F3E:
	ldr r4, [sp]
	ldr r4, [r4, #0x58]
	mov ip, r4
	b _080D8F4C
_080D8F46:
	ldr r5, [sp]
	ldr r5, [r5, #0x58]
	mov ip, r5
_080D8F4C:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D8F8E
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D8F96
_080D8F8E:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D8F96:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D8FBA
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D8FC2
_080D8FBA:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D8FC2:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D8FF8 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D9022
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D8FFC
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D8FF2
	ldrb r0, [r3, #5]
_080D8FF2:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D900C
	.align 2, 0
_080D8FF8: .4byte 0x0000FFFF
_080D8FFC:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D900C
	strh r1, [r3, #8]
_080D900C:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D9022:
	ldrh r1, [r7, #0x1c]
	mov r3, sl
	ldrh r3, [r3]
	adds r1, r1, r3
	ldrh r0, [r6, #0x18]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r1, [r7, #0x1e]
	mov r4, sl
	ldrh r4, [r4, #2]
	adds r1, r1, r4
	ldrh r0, [r6, #0x1a]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
	ldrh r1, [r7, #0x20]
	mov r5, sl
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	ldrh r0, [r6, #0x1c]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r2, r0, r1
	ldr r1, [r2]
	asrs r1, r1, #1
	mov r3, sl
	ldrh r0, [r3, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _080D9208
_080D9070:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r4, [sp, #0x1c]
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _080D9084
	subs r0, #1
	str r0, [r1]
	b _080D9208
_080D9084:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D9098
	cmp r0, #3
	beq _080D90A0
	movs r5, #0
	mov ip, r5
	b _080D90A6
_080D9098:
	ldr r0, [sp]
	ldr r0, [r0, #0x58]
	mov ip, r0
	b _080D90A6
_080D90A0:
	ldr r1, [sp]
	ldr r1, [r1, #0x58]
	mov ip, r1
_080D90A6:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r2, ip
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D90E8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D90F0
_080D90E8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D90F0:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D9114
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D911C
_080D9114:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D911C:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D9154 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D917E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9158
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D914C
	ldrb r0, [r3, #5]
_080D914C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D9168
	.align 2, 0
_080D9154: .4byte 0x0000FFFF
_080D9158:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D9168
	strh r1, [r3, #8]
_080D9168:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D917E:
	ldr r5, _080D929C @ =0x085B0A08
	adds r4, r7, #0
	adds r4, #0x35
	add r4, sb
	ldrb r3, [r4]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	lsrs r0, r0, #0x10
	ldr r2, _080D92A0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080D92A4 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r3, #5
	strb r3, [r4]
	ldr r0, [r7]
	mov r2, sp
	ldrh r3, [r2, #8]
	ldrh r0, [r0]
	adds r2, r3, r0
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x18]
	ldr r0, [r7]
	asrs r1, r1, #0x10
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r7, #0x28]
	adds r0, r0, r1
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r6, #0x1a]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	subs r0, r0, r3
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080d8de0
_080D9208:
	ldr r0, [sp, #0x1c]
	adds r0, #4
	str r0, [sp, #0x1c]
	movs r1, #0x10
	add r8, r1
	movs r2, #8
	add sl, r2
	adds r6, #0x28
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #2
	bgt _080D9224
	b _080D8ED6
_080D9224:
	ldr r5, [sp, #0x10]
	cmp r5, #2
	ble _080D928C
	adds r0, r7, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x39
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, [sp]
	ldr r5, _080D92A8 @ =0x000009FC
	adds r3, r1, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	strh r2, [r7, #0x24]
	str r2, [r7, #0x48]
	mov sb, r2
	adds r5, r4, #0
	ldr r4, [sp, #4]
_080D9254:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9270
	adds r0, r7, #0
	bl FUN_080d8644
	adds r0, r4, #0
	bl Particle_Remove
_080D9270:
	adds r4, #0x28
	movs r3, #1
	add sb, r3
	mov r0, sb
	cmp r0, #2
	ble _080D9254
	movs r4, #0
	adds r0, r7, #0
	bl FUN_080d866c
	ldr r1, [sp, #0x14]
	strb r4, [r1]
	movs r0, #0xff
	strb r0, [r5]
_080D928C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D929C: .4byte 0x085B0A08
_080D92A0: .4byte 0xFFFF0000
_080D92A4: .4byte 0x0000FFFF
_080D92A8: .4byte 0x000009FC

	thumb_func_start FUN_080d92ac
FUN_080d92ac: @ 0x080D92AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080D92DC @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D92BE
	b _080D94AA
_080D92BE:
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x88
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D92E0
	cmp r0, #3
	beq _080D92E6
	movs r3, #0
	b _080D92EA
	.align 2, 0
_080D92DC: .4byte 0x0300015C
_080D92E0:
	mov r1, ip
	ldr r3, [r1, #0x58]
	b _080D92EA
_080D92E6:
	mov r2, ip
	ldr r3, [r2, #0x58]
_080D92EA:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D9326
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080D932E
_080D9326:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D932E:
	str r0, [r7]
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
	beq _080D9352
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D935A
_080D9352:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D935A:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9390 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D93BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9394
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D938A
	ldrb r0, [r4, #5]
_080D938A:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D93A4
	.align 2, 0
_080D9390: .4byte 0x0000FFFF
_080D9394:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D93A4
	strh r1, [r4, #8]
_080D93A4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_080D93BA:
	ldr r1, [r6, #0x4c]
	asrs r1, r1, #1
	ldr r2, _080D9434 @ =0x085B0A08
	adds r3, r6, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r6, #4]
	ldrh r0, [r6, #6]
	adds r0, #2
	strh r0, [r6, #6]
	ldr r2, _080D9438 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D943C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9440 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #7
	ands r0, r1
	ldrb r2, [r3]
	adds r0, r0, r2
	strb r0, [r3]
	ldr r1, [r6]
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldr r0, [r6]
	ldrh r1, [r6, #6]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r7, #0x1a]
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0x3c
	bgt _080D9444
	movs r0, #0
	b _080D944E
	.align 2, 0
_080D9434: .4byte 0x085B0A08
_080D9438: .4byte 0x030046B8
_080D943C: .4byte 0x000003FF
_080D9440: .4byte 0x0203B400
_080D9444:
	cmp r0, #0x78
	bgt _080D944C
	movs r0, #1
	b _080D944E
_080D944C:
	movs r0, #2
_080D944E:
	strh r0, [r4, #8]
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #0xd2
	ble _080D94A4
	adds r0, r6, #0
	adds r0, #0x2d
	movs r5, #0
	strb r5, [r0]
	movs r0, #0x39
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _080D94A0 @ =0x000009FC
	add r2, ip
	movs r3, #1
	adds r1, r3, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, [r7]
	orrs r0, r3
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_080d8644
	movs r4, #0
	strh r5, [r6, #0x24]
	adds r0, r7, #0
	bl Particle_Remove
	adds r0, r6, #0
	adds r0, #0x38
	strb r4, [r0]
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	b _080D94AA
	.align 2, 0
_080D94A0: .4byte 0x000009FC
_080D94A4:
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
_080D94AA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d94b4
FUN_080d94b4: @ 0x080D94B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080D9500 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D94C6
	b _080D96AE
_080D94C6:
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080D9504
	ldr r0, [r5, #0x5c]
	movs r1, #4
	orrs r0, r1
	b _080D950C
	.align 2, 0
_080D9500: .4byte 0x0300015C
_080D9504:
	ldr r0, [r5, #0x5c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D950C:
	str r0, [r5, #0x5c]
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
	beq _080D9530
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D9538
_080D9530:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D9538:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9570 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D95B6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D957A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D9574
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D9590
	.align 2, 0
_080D9570: .4byte 0x0000FFFF
_080D9574:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D958E
_080D957A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D958E
	strh r1, [r4, #8]
	movs r2, #1
	b _080D9590
_080D958E:
	movs r2, #0
_080D9590:
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
	bne _080D95B8
	movs r0, #1
	strb r0, [r4, #7]
	b _080D95B8
_080D95B6:
	movs r2, #0
_080D95B8:
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080D95D4
	ldrh r0, [r5, #0x30]
	adds r0, #0x19
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r3, [r2, #2]
	adds r1, r1, r3
	b _080D95E2
_080D95D4:
	ldrh r0, [r5, #0x30]
	adds r0, #0xa
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r6, [r2, #2]
	adds r1, r1, r6
_080D95E2:
	adds r0, r0, r1
	strh r0, [r5, #0x2a]
	ldrh r1, [r5, #0x2a]
	ldrh r3, [r5, #0x26]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	adds r6, r3, #0
	cmp r1, r0
	ble _080D95FC
	ldrh r0, [r2, #2]
	adds r0, r6, r0
	strh r0, [r5, #0x2a]
_080D95FC:
	ldrh r1, [r5, #0x2a]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	cmp r1, r0
	blt _080D9610
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble _080D9616
_080D9610:
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9616:
	ldr r0, [r5, #0x4c]
	cmp r0, #0x1d
	bgt _080D9622
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9622:
	mov r2, ip
	cmp r2, #0
	beq _080D9670
	adds r0, r5, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r3, _080D966C @ =0x000009FC
	add r3, r8
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	ldr r0, [r7]
	orrs r0, r4
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x32
	strb r2, [r0]
	movs r4, #0
	strh r2, [r5, #0x24]
	str r2, [r5, #0x4c]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	b _080D96AE
	.align 2, 0
_080D966C: .4byte 0x000009FC
_080D9670:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, [r5]
	cmp r0, #0
	beq _080D96A0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r6, [r5, #0x2a]
	adds r0, r0, r6
	strh r0, [r7, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
_080D96A0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080d8864
	ldr r0, [r5, #0x4c]
	adds r0, #1
	str r0, [r5, #0x4c]
_080D96AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d96b8
FUN_080d96b8: @ 0x080D96B8
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #4
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D96CC
	movs r0, #1
	b _080D96CE
_080D96CC:
	movs r0, #0
_080D96CE:
	adds r5, r0, #0
	cmp r5, #0
	bne _080D9750
	ldr r0, [r3, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, r0, #0
	cmp r1, #0
	bgt _080D96FA
	movs r0, #0x14
	strh r0, [r3, #0x3c]
	adds r2, r3, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #5
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2c
	movs r0, #4
	strb r0, [r1]
	b _080D9750
_080D96FA:
	movs r2, #4
	movs r6, #0
	ldrsh r1, [r4, r6]
	movs r6, #0x3e
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r6, #0x32
	adds r6, r6, r3
	mov ip, r6
	adds r6, r3, #0
	adds r6, #0x2e
	cmp r1, r0
	blt _080D971C
	adds r0, r3, #0
	adds r0, #0x2c
	strb r5, [r0]
	b _080D973A
_080D971C:
	subs r2, #1
	cmp r2, #0
	ble _080D973A
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r5, #0x3e
	ldrsh r1, [r3, r5]
	muls r1, r2, r1
	cmp r0, r1
	blt _080D971C
	movs r0, #4
	subs r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x2c
	strb r0, [r1]
_080D973A:
	movs r0, #0
	strh r0, [r3, #0x3c]
	subs r0, #6
	mov r2, ip
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6]
_080D9750:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d9758
FUN_080d9758: @ 0x080D9758
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080D97A4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D97F4
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_080d96b8
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D97DC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r2, [r4, #0x2a]
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D97A8
	movs r0, #1
	b _080D97AA
	.align 2, 0
_080D97A4: .4byte 0x0300015C
_080D97A8:
	movs r0, #0
_080D97AA:
	cmp r0, #0
	bne _080D97C2
	ldr r0, _080D97FC @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	asrs r0, r0, #8
	adds r2, r2, r0
_080D97C2:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r2
	ldrh r3, [r5, #0x1e]
	adds r0, r0, r3
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_080D97DC:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080d8788
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D97F4
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_080D97F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D97FC: .4byte 0x085B0A08

	thumb_func_start FUN_080d9800
FUN_080d9800: @ 0x080D9800
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080D984C @ =0x0300015C
	ldr r3, [r0]
	cmp r3, #0
	beq _080D98C8
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D98C8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #3
	bgt _080D9850
	ldrh r0, [r4, #0x30]
	adds r0, #0x14
	strh r0, [r4, #0x30]
	ldr r2, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	strh r0, [r5, #0x1e]
	b _080D98A6
	.align 2, 0
_080D984C: .4byte 0x0300015C
_080D9850:
	cmp r0, #9
	bgt _080D987C
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r4, #0
	bl FUN_080d8864
	b _080D98A6
_080D987C:
	ldr r0, [r4]
	movs r2, #2
	ldrsh r1, [r0, r2]
	ldrh r0, [r4, #0x28]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r1, r1, r0
	ldr r2, _080D98D0 @ =0x085B0A08
	adds r3, r4, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	ldrb r0, [r3]
	adds r0, #4
	strb r0, [r3]
_080D98A6:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #9
	bgt _080D98C8
	adds r0, #1
	str r0, [r4, #0x4c]
_080D98C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D98D0: .4byte 0x085B0A08

	thumb_func_start FUN_080d98d4
FUN_080d98d4: @ 0x080D98D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9952
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D98FA
	ldr r0, [r2, #0x30]
	ldr r1, [r2, #0x34]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _080D9952
_080D98FA:
	adds r4, r6, #0
	adds r4, #0x3b
	ldrb r0, [r4]
	ldrb r1, [r1]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r6, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080D9946
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	adds r4, #0x4d
_080D9926:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D993C
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	adds r0, r4, #0
	bl Particle_SetOffset
_080D993C:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9926
	b _080D9952
_080D9946:
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r6, #0x1c]
	strh r1, [r6, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r6, #0x20]
_080D9952:
	ldr r0, _080D9970 @ =0x085AD2EC
	adds r1, r6, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D9970: .4byte 0x085AD2EC

	thumb_func_start FUN_080d9974
FUN_080d9974: @ 0x080D9974
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080D9990 @ =0x000009FC
	adds r4, r2, r0
	movs r5, #1
_080D9980:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080D9994
	movs r0, #1
	b _080D9996
	.align 2, 0
_080D9990: .4byte 0x000009FC
_080D9994:
	movs r0, #0
_080D9996:
	cmp r0, #0
	bne _080D99B6
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	adds r0, r2, r0
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	adds r1, r0, #0
	adds r1, #0x39
	strb r3, [r1]
	b _080D99BE
_080D99B6:
	adds r3, #1
	cmp r3, #7
	ble _080D9980
	movs r0, #0
_080D99BE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d99c4
FUN_080d99c4: @ 0x080D99C4
	push {lr}
	bl FUN_080d9974
	cmp r0, #0
	bne _080D99D0
	movs r0, #0
_080D99D0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080d99d4
FUN_080d99d4: @ 0x080D99D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r7, #0
	beq _080D9A8A
	ldr r0, _080D9A4C @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9A8A
	adds r0, r7, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9A8A
	ldrh r0, [r7, #0x24]
	cmp r0, r3
	bne _080D9A8A
	movs r0, #0x88
	adds r0, r0, r7
	mov ip, r0
	adds r5, r7, #0
	adds r5, #0x5c
	adds r3, r7, #0
	adds r3, #0x3b
	ldrb r0, [r3]
	cmp r0, r4
	bne _080D9A8E
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9A50 @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #1
	bls _080D9A36
	cmp r0, #4
	beq _080D9A36
	cmp r0, #5
	bne _080D9A54
_080D9A36:
	adds r4, r7, #0
	adds r4, #0x44
	ldrb r0, [r4]
	cmp r0, #0
	beq _080D9A7A
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
	b _080D9A7A
	.align 2, 0
_080D9A4C: .4byte 0x0300015C
_080D9A50: .4byte 0x000009FC
_080D9A54:
	movs r5, #0
	adds r6, r7, #0
	adds r6, #0x38
	mov r4, ip
_080D9A5C:
	ldrb r0, [r6]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9A6E
	adds r0, r4, #0
	bl Particle_Remove
_080D9A6E:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9A5C
	movs r0, #0
	strb r0, [r6]
_080D9A7A:
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9A8A:
	movs r0, #0
	b _080D9A90
_080D9A8E:
	adds r0, r7, #0
_080D9A90:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d9a9c
FUN_080d9a9c: @ 0x080D9A9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r6, #0
	beq _080D9B22
	ldr r0, _080D9B28 @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9B22
	movs r0, #0x88
	adds r0, r0, r6
	mov ip, r0
	adds r0, r6, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9B22
	ldrh r0, [r6, #0x24]
	cmp r0, r3
	bne _080D9B22
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D9B30
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9B2C @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	mov r4, ip
_080D9AF4:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9B06
	adds r0, r4, #0
	bl Particle_Remove
_080D9B06:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9AF4
	movs r0, #0
	strb r0, [r7]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r6, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9B22:
	movs r0, #0
	b _080D9B32
	.align 2, 0
_080D9B28: .4byte 0x0300015C
_080D9B2C: .4byte 0x000009FC
_080D9B30:
	adds r0, r6, #0
_080D9B32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d9b3c
FUN_080d9b3c: @ 0x080D9B3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	ldr r5, [sp, #0x4c]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080D9B6C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9B70
	bl Entity080da848_Create
	mov sb, r0
	cmp r0, #0
	bne _080D9B72
_080D9B66:
	movs r0, #0
	b _080D9CDA
	.align 2, 0
_080D9B6C: .4byte 0x0300015C
_080D9B70:
	mov sb, r0
_080D9B72:
	cmp r5, #0
	beq _080D9B66
	mov r0, sb
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9B66
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	str r5, [r0]
	movs r2, #0x2c
	adds r2, r2, r7
	mov r8, r2
	movs r2, #0
	mov r3, r8
	strb r4, [r3]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x3a
	strb r2, [r3]
	adds r6, r7, #0
	adds r6, #0x2f
	ldr r0, [sp, #0x44]
	strb r0, [r6]
	movs r4, #0
	strh r2, [r7, #0x30]
	mov r5, sl
	strh r5, [r7, #0x24]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r7, #0x26]
	ldr r0, [sp, #0x40]
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0xa
	strh r0, [r7, #0x3c]
	adds r5, r7, #0
	adds r5, #0x3b
	strb r4, [r5]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	ldr r1, [sp, #0x10]
	str r1, [r7]
	ldr r0, [sp, #0x48]
	str r0, [r7, #0x58]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	movs r2, #0x5c
	adds r2, r2, r7
	mov sl, r2
	ldrb r0, [r3]
	mov r1, r8
	str r1, [sp, #0x18]
	mov r8, r3
	str r4, [sp, #0x1c]
	mov r4, sl
	cmp r0, #1
	beq _080D9C10
	cmp r0, #1
	bgt _080D9C00
	cmp r0, #0
	beq _080D9C0A
	b _080D9C16
_080D9C00:
	cmp r0, #5
	bgt _080D9C16
	cmp r0, #4
	blt _080D9C16
	b _080D9C10
_080D9C0A:
	mov r1, sb
	adds r1, #0x18
	b _080D9C18
_080D9C10:
	mov r1, sb
	adds r1, #0x34
	b _080D9C18
_080D9C16:
	movs r1, #0
_080D9C18:
	mov r0, sl
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _080D9C38
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9C60
_080D9C38:
	ldrb r0, [r5]
	ldrb r1, [r6]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080D9C60:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0xff
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080D9CB0
	lsls r0, r0, #2
	ldr r1, _080D9C88 @ =_080D9C8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9C88: .4byte _080D9C8C
_080D9C8C: @ jump table
	.4byte _080D9CA4 @ case 0
	.4byte _080D9CB0 @ case 1
	.4byte _080D9CAA @ case 2
	.4byte _080D9CAA @ case 3
	.4byte _080D9CB0 @ case 4
	.4byte _080D9CB0 @ case 5
_080D9CA4:
	mov r2, sb
	ldr r3, [r2, #0x50]
	b _080D9CB2
_080D9CAA:
	mov r5, sb
	ldr r3, [r5, #0x54]
	b _080D9CB2
_080D9CB0:
	movs r3, #0
_080D9CB2:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [sp, #0x18]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	ldr r3, [sp, #0x1c]
	strb r0, [r3]
	adds r0, r7, #0
_080D9CDA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d9cec
FUN_080d9cec: @ 0x080D9CEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	str r1, [sp, #0x28]
	str r2, [sp, #0x2c]
	adds r5, r3, #0
	ldr r1, [sp, #0x74]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r0, _080D9D20 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9D24
	bl Entity080da848_Create
	mov r8, r0
	cmp r0, #0
	bne _080D9D26
_080D9D1C:
	movs r0, #0
	b _080D9F3C
	.align 2, 0
_080D9D20: .4byte 0x0300015C
_080D9D24:
	mov r8, r0
_080D9D26:
	ldr r0, [sp, #0x80]
	cmp r0, #0
	beq _080D9D1C
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9D1C
	movs r1, #0x2c
	adds r1, r1, r7
	mov sl, r1
	strb r4, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x6c]
	strb r0, [r5]
	add r2, sp, #0x68
	ldrh r2, [r2]
	strh r2, [r7, #0x28]
	add r3, sp, #0x68
	ldrh r3, [r3]
	strh r3, [r7, #0x2a]
	mov r6, sb
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #5
	bl Div
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x44
	strb r4, [r1]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x80]
	str r3, [r0]
	ldr r6, [sp, #0x70]
	str r6, [r7, #0x48]
	movs r4, #0
	movs r3, #4
	movs r0, #0
	ldrsh r2, [r6, r0]
	movs r6, #0x3e
	ldrsh r0, [r7, r6]
	lsls r0, r0, #2
	mov r6, sl
	str r5, [sp, #0x38]
	str r1, [sp, #0x40]
	movs r1, #0x3b
	adds r1, r1, r7
	mov sl, r1
	movs r1, #0x3a
	adds r1, r1, r7
	mov sb, r1
	adds r1, r7, #0
	adds r1, #0x5c
	str r1, [sp, #0x44]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r2, r0
	blt _080D9DC6
	movs r0, #0
	b _080D9DEA
_080D9DC6:
	subs r3, #1
	cmp r3, #0
	ble _080D9DE4
	ldr r0, [r7, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x3e
	ldrsh r0, [r7, r2]
	muls r0, r3, r0
	cmp r1, r0
	blt _080D9DC6
	movs r0, #4
	subs r0, r0, r3
	strb r0, [r6]
	movs r4, #1
_080D9DE4:
	cmp r4, #0
	bne _080D9DEC
	movs r0, #3
_080D9DEA:
	strb r0, [r6]
_080D9DEC:
	movs r1, #0
	mov r3, sp
	ldrh r3, [r3, #0x2c]
	strh r3, [r7, #0x24]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	mov r3, sb
	strb r0, [r3]
	ldr r0, [sp, #0x28]
	str r0, [r7]
	ldr r0, [sp, #0x7c]
	str r0, [r7, #0x58]
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
	ldr r5, [sp, #0x44]
	ldrb r0, [r3]
	adds r1, r0, #0
	cmp r0, #1
	beq _080D9E2E
	cmp r0, #1
	bgt _080D9E1E
	cmp r0, #0
	beq _080D9E28
	b _080D9E34
_080D9E1E:
	cmp r1, #5
	bgt _080D9E34
	cmp r1, #4
	blt _080D9E34
	b _080D9E2E
_080D9E28:
	mov r1, r8
	adds r1, #0x18
	b _080D9E36
_080D9E2E:
	mov r1, r8
	adds r1, #0x34
	b _080D9E36
_080D9E34:
	movs r1, #0
_080D9E36:
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D9E54
	ldr r2, [sp, #0x3c]
	ldr r0, [r2]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9E7C
_080D9E54:
	mov r3, sl
	ldrb r0, [r3]
	ldr r2, [sp, #0x38]
	ldrb r1, [r2]
	ldr r3, [sp, #0x3c]
	ldr r2, [r3]
	ldrb r2, [r2, #5]
	add r3, sp, #0x20
	add r4, sp, #0x24
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r0, [sp, #0x20]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0x20]
_080D9E7C:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0xff
	ldr r1, [sp, #0x34]
	strh r0, [r1]
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #5
	bhi _080D9EC8
	lsls r0, r0, #2
	ldr r1, _080D9EA0 @ =_080D9EA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9EA0: .4byte _080D9EA4
_080D9EA4: @ jump table
	.4byte _080D9EBC @ case 0
	.4byte _080D9EC8 @ case 1
	.4byte _080D9EC2 @ case 2
	.4byte _080D9EC2 @ case 3
	.4byte _080D9EC8 @ case 4
	.4byte _080D9EC8 @ case 5
_080D9EBC:
	mov r3, r8
	ldr r1, [r3, #0x50]
	b _080D9ECA
_080D9EC2:
	mov r0, r8
	ldr r1, [r0, #0x54]
	b _080D9ECA
_080D9EC8:
	movs r1, #0
_080D9ECA:
	ldrb r2, [r6]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x30]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x44]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	ldr r0, _080D9F4C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D9F3A
	ldr r0, [sp, #0x78]
	cmp r0, #1
	bne _080D9F3A
	ldr r2, _080D9F50 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D9F54 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9F58 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	add r1, sp, #8
	movs r3, #2
_080D9F1C:
	ldr r0, [r7]
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r7]
	ldrh r0, [r0, #2]
	ldr r2, [sp, #0x68]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	adds r1, #8
	subs r3, #1
	cmp r3, #0
	bge _080D9F1C
_080D9F3A:
	adds r0, r7, #0
_080D9F3C:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D9F4C: .4byte 0x030047A4
_080D9F50: .4byte 0x030046B8
_080D9F54: .4byte 0x000003FF
_080D9F58: .4byte 0x0203B400

	thumb_func_start FUN_080d9f5c
FUN_080d9f5c: @ 0x080D9F5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080D9F88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9F8C
	bl Entity080da848_Create
	mov sl, r0
	cmp r0, #0
	bne _080D9F8E
_080D9F84:
	movs r0, #0
	b _080DA100
	.align 2, 0
_080D9F88: .4byte 0x0300015C
_080D9F8C:
	mov sl, r0
_080D9F8E:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _080D9F84
	mov r0, sl
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x20]
	cmp r7, #0
	beq _080D9F84
	movs r2, #0x2c
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov r8, r3
	ldr r0, [sp, #0x48]
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	adds r5, r7, #0
	adds r5, #0x3a
	movs r6, #2
	strb r6, [r5]
	strh r4, [r7, #0x30]
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r1, sp
	ldrh r1, [r1, #0x1c]
	strh r1, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r1, r7, #0
	adds r1, #0x3b
	strb r6, [r1]
	str r4, [r7, #0x58]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x4c]
	str r3, [r0]
	str r4, [sp, #0x10]
	str r4, [sp, #0xc]
	ldr r6, [sp, #0x20]
	ldrb r0, [r5]
	mov r2, sb
	str r2, [sp, #0x24]
	mov sb, r5
	adds r4, r1, #0
	cmp r0, #2
	beq _080DA016
	cmp r0, #3
	beq _080DA01C
	movs r1, #0
	b _080DA020
_080DA016:
	mov r3, sl
	ldr r1, [r3, #0x58]
	b _080DA020
_080DA01C:
	mov r0, sl
	ldr r1, [r0, #0x58]
_080DA020:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldrb r0, [r4]
	mov r2, r8
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r5, r7, r3
	ldr r2, [r5]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r6, #0
	bl Particle_SetOffset
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA064
	ldr r0, [r5]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA074
_080DA064:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA0A0 @ =0x05000002
	bl CpuSet
_080DA074:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	movs r0, #0x7f
	strb r0, [r6, #0x10]
	strb r1, [r6, #0xf]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xff
	strh r0, [r1]
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #5
	bhi _080DA0CC
	lsls r0, r0, #2
	ldr r1, _080DA0A4 @ =_080DA0A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA0A0: .4byte 0x05000002
_080DA0A4: .4byte _080DA0A8
_080DA0A8: @ jump table
	.4byte _080DA0C0 @ case 0
	.4byte _080DA0CC @ case 1
	.4byte _080DA0C6 @ case 2
	.4byte _080DA0C6 @ case 3
	.4byte _080DA0CC @ case 4
	.4byte _080DA0CC @ case 5
_080DA0C0:
	mov r0, sl
	ldr r1, [r0, #0x50]
	b _080DA0CE
_080DA0C6:
	mov r2, sl
	ldr r1, [r2, #0x54]
	b _080DA0CE
_080DA0CC:
	movs r1, #0
_080DA0CE:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r3, [sp, #0x24]
	ldrb r2, [r3]
	movs r4, #0
	str r4, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x14]
	str r0, [r7]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	adds r1, r7, #0
	adds r1, #0x38
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, r7, #0
_080DA100:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da110
FUN_080da110: @ 0x080DA110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DA13C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA140
	bl Entity080da848_Create
	str r0, [sp, #0x20]
	cmp r0, #0
	bne _080DA142
_080DA138:
	movs r0, #0
	b _080DA346
	.align 2, 0
_080DA13C: .4byte 0x0300015C
_080DA140:
	str r0, [sp, #0x20]
_080DA142:
	ldr r0, [sp, #0x74]
	cmp r0, #0
	beq _080DA138
	ldr r0, [sp, #0x6c]
	movs r1, #3
	bl Div
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x20]
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x24]
	cmp r7, #0
	beq _080DA138
	adds r2, r7, #0
	adds r2, #0x2c
	str r2, [sp, #0x2c]
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov sb, r3
	ldr r0, [sp, #0x64]
	strb r0, [r3]
	ldr r0, [sp, #0x68]
	str r0, [r7, #0x48]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	movs r5, #0x3a
	adds r5, r5, r7
	mov r8, r5
	movs r5, #3
	mov r0, r8
	strb r5, [r0]
	movs r6, #0
	strh r4, [r7, #0x30]
	mov r1, sp
	ldrh r1, [r1, #0x18]
	strh r1, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r2, r7, #0
	adds r2, #0x3b
	strb r5, [r2]
	ldr r3, [sp, #0x14]
	str r3, [r7]
	adds r1, r7, #0
	adds r1, #0x38
	strb r6, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r6, [r0]
	ldr r0, [sp, #0x78]
	str r0, [r7, #0x58]
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r3, [sp, #0x74]
	str r3, [r0]
	movs r5, #0
	mov sl, r5
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x3c]
	mov r3, sb
	str r3, [sp, #0x40]
	mov r5, r8
	str r5, [sp, #0x34]
	str r2, [sp, #0x38]
	str r1, [sp, #0x30]
	ldr r0, [sp, #0x70]
	cmp sl, r0
	blt _080DA1F0
	b _080DA344
_080DA1F0:
	mov r1, sl
	lsls r3, r1, #2
	adds r1, r7, #0
	adds r1, #0x4c
	adds r1, r1, r3
	mov r2, sl
	lsls r4, r2, #4
	adds r0, r4, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x35
	add r0, sl
	movs r2, #0
	strb r2, [r0]
	mov r5, sl
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	ldr r5, [sp, #0x28]
	mov r1, sl
	muls r1, r5, r1
	strh r1, [r0]
	str r2, [sp, #0x10]
	str r2, [sp, #0xc]
	mov r1, sl
	adds r0, r3, r1
	lsls r0, r0, #3
	adds r0, #0x88
	adds r5, r7, r0
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	mov sb, r3
	mov r8, r4
	cmp r0, #2
	beq _080DA240
	cmp r0, #3
	beq _080DA246
	movs r1, #0
	b _080DA24A
_080DA240:
	ldr r3, [sp, #0x20]
	ldr r1, [r3, #0x58]
	b _080DA24A
_080DA246:
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x58]
_080DA24A:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r6, r7, r3
	ldr r2, [r6]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r5, #0
	bl Particle_SetOffset
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA290
	ldr r0, [r6]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA2A0
_080DA290:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA2D0 @ =0x05000002
	bl CpuSet
_080DA2A0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0x7f
	strb r0, [r5, #0x10]
	strb r1, [r5, #0xf]
	mov r2, r8
	adds r0, r7, r2
	movs r3, #0x85
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0xff
	strh r0, [r1]
	ldr r5, [sp, #0x34]
	ldrb r0, [r5]
	cmp r0, #5
	bhi _080DA2FC
	lsls r0, r0, #2
	ldr r1, _080DA2D4 @ =_080DA2D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA2D0: .4byte 0x05000002
_080DA2D4: .4byte _080DA2D8
_080DA2D8: @ jump table
	.4byte _080DA2F0 @ case 0
	.4byte _080DA2FC @ case 1
	.4byte _080DA2F6 @ case 2
	.4byte _080DA2F6 @ case 3
	.4byte _080DA2FC @ case 4
	.4byte _080DA2FC @ case 5
_080DA2F0:
	ldr r0, [sp, #0x20]
	ldr r3, [r0, #0x50]
	b _080DA2FE
_080DA2F6:
	ldr r1, [sp, #0x20]
	ldr r3, [r1, #0x54]
	b _080DA2FE
_080DA2FC:
	movs r3, #0
_080DA2FE:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	adds r0, r7, r0
	ldr r5, [sp, #0x3c]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	mov r2, sb
	add r2, sl
	lsls r2, r2, #3
	ldr r0, [sp, #0x24]
	adds r2, r2, r0
	ldr r3, [sp, #0x14]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r0, #1
	mov r5, sl
	lsls r0, r5
	ldr r2, [sp, #0x30]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r3, #1
	add sl, r3
	ldr r5, [sp, #0x70]
	cmp sl, r5
	bge _080DA344
	b _080DA1F0
_080DA344:
	adds r0, r7, #0
_080DA346:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da358
FUN_080da358: @ 0x080DA358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov sb, r1
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, _080DA384 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA388
	bl Entity080da848_Create
	mov r8, r0
	cmp r0, #0
	bne _080DA38A
_080DA37E:
	movs r0, #0
	b _080DA4E8
	.align 2, 0
_080DA384: .4byte 0x0300015C
_080DA388:
	mov r8, r0
_080DA38A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080DA37E
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080DA37E
	movs r1, #0x2c
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x3c]
	strb r0, [r5]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	strh r2, [r7, #0x30]
	mov r3, sb
	strh r3, [r7, #0x24]
	adds r3, r7, #0
	adds r3, #0x3b
	movs r0, #4
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
	ldr r6, [sp, #0x10]
	str r6, [r7]
	ldr r0, [sp, #0x40]
	str r0, [r7, #0x58]
	movs r6, #0x98
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r6, [sp, #0x44]
	str r6, [r0]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r0, [r1]
	mov sl, ip
	str r4, [sp, #0x14]
	adds r4, r3, #0
	mov sb, r1
	str r6, [sp, #0x18]
	cmp r0, #1
	beq _080DA41C
	cmp r0, #1
	bgt _080DA40C
	cmp r0, #0
	beq _080DA416
	b _080DA422
_080DA40C:
	cmp r0, #5
	bgt _080DA422
	cmp r0, #4
	blt _080DA422
	b _080DA41C
_080DA416:
	mov r1, r8
	adds r1, #0x18
	b _080DA424
_080DA41C:
	mov r1, r8
	adds r1, #0x34
	b _080DA424
_080DA422:
	movs r1, #0
_080DA424:
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080DA444
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA46C
_080DA444:
	ldrb r0, [r4]
	ldrb r1, [r5]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080DA46C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	strb r1, [r6, #7]
	movs r6, #0x85
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0xff
	strh r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080DA4BC
	lsls r0, r0, #2
	ldr r1, _080DA494 @ =_080DA498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA494: .4byte _080DA498
_080DA498: @ jump table
	.4byte _080DA4B0 @ case 0
	.4byte _080DA4BC @ case 1
	.4byte _080DA4B6 @ case 2
	.4byte _080DA4B6 @ case 3
	.4byte _080DA4BC @ case 4
	.4byte _080DA4BC @ case 5
_080DA4B0:
	mov r2, r8
	ldr r3, [r2, #0x50]
	b _080DA4BE
_080DA4B6:
	mov r6, r8
	ldr r3, [r6, #0x54]
	b _080DA4BE
_080DA4BC:
	movs r3, #0
_080DA4BE:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r6, sl
	ldrb r2, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x14]
	strb r0, [r6]
	adds r0, r7, #0
_080DA4E8:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da4f8
FUN_080da4f8: @ 0x080DA4F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov sb, r1
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, _080DA524 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA528
	bl Entity080da848_Create
	mov r8, r0
	cmp r0, #0
	bne _080DA52A
_080DA51E:
	movs r0, #0
	b _080DA688
	.align 2, 0
_080DA524: .4byte 0x0300015C
_080DA528:
	mov r8, r0
_080DA52A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080DA51E
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080DA51E
	movs r1, #0x2c
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x3c]
	strb r0, [r5]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	strh r2, [r7, #0x30]
	mov r3, sb
	strh r3, [r7, #0x24]
	adds r3, r7, #0
	adds r3, #0x3b
	movs r0, #5
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
	ldr r6, [sp, #0x10]
	str r6, [r7]
	ldr r0, [sp, #0x40]
	str r0, [r7, #0x58]
	movs r6, #0x98
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r6, [sp, #0x44]
	str r6, [r0]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r0, [r1]
	mov sl, ip
	str r4, [sp, #0x14]
	adds r4, r3, #0
	mov sb, r1
	str r6, [sp, #0x18]
	cmp r0, #1
	beq _080DA5BC
	cmp r0, #1
	bgt _080DA5AC
	cmp r0, #0
	beq _080DA5B6
	b _080DA5C2
_080DA5AC:
	cmp r0, #5
	bgt _080DA5C2
	cmp r0, #4
	blt _080DA5C2
	b _080DA5BC
_080DA5B6:
	mov r1, r8
	adds r1, #0x18
	b _080DA5C4
_080DA5BC:
	mov r1, r8
	adds r1, #0x34
	b _080DA5C4
_080DA5C2:
	movs r1, #0
_080DA5C4:
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080DA5E4
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA60C
_080DA5E4:
	ldrb r0, [r4]
	ldrb r1, [r5]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080DA60C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	strb r1, [r6, #7]
	movs r6, #0x85
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0xff
	strh r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080DA65C
	lsls r0, r0, #2
	ldr r1, _080DA634 @ =_080DA638
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA634: .4byte _080DA638
_080DA638: @ jump table
	.4byte _080DA650 @ case 0
	.4byte _080DA65C @ case 1
	.4byte _080DA656 @ case 2
	.4byte _080DA656 @ case 3
	.4byte _080DA65C @ case 4
	.4byte _080DA65C @ case 5
_080DA650:
	mov r2, r8
	ldr r3, [r2, #0x50]
	b _080DA65E
_080DA656:
	mov r6, r8
	ldr r3, [r6, #0x54]
	b _080DA65E
_080DA65C:
	movs r3, #0
_080DA65E:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r6, sl
	ldrb r2, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x14]
	strb r0, [r6]
	adds r0, r7, #0
_080DA688:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da698
FUN_080da698: @ 0x080DA698
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x3c]
	str r7, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #3
	str r4, [sp, #0xc]
	bl FUN_080da110
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da6c4
FUN_080da6c4: @ 0x080DA6C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	str r7, [sp, #0xc]
	ldr r7, [sp, #0x3c]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x40]
	str r7, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_080da110
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080da848_Update
Entity080da848_Update: @ 0x080DA6F0
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x5c
	ldr r3, _080DA730 @ =0x000009FC
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA728
	ldr r7, _080DA734 @ =0x085AD304
	adds r5, r1, #0
	adds r5, #0x89
	adds r4, r2, #0
	ldr r0, _080DA738 @ =0x000008C8
	adds r6, r1, r0
_080DA70E:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r4, r6
	ble _080DA70E
_080DA728:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA730: .4byte 0x000009FC
_080DA734: .4byte 0x085AD304
_080DA738: .4byte 0x000008C8

	thumb_func_start Entity080da848_Destroy
Entity080da848_Destroy: @ 0x080DA73C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r2, #0
	ldr r0, _080DA760 @ =0x000009FC
	add r0, r8
	mov sb, r0
_080DA74E:
	movs r1, #1
	lsls r1, r2
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080DA764
	movs r0, #1
	b _080DA766
	.align 2, 0
_080DA760: .4byte 0x000009FC
_080DA764:
	movs r0, #0
_080DA766:
	adds r7, r2, #1
	cmp r0, #0
	beq _080DA7AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x5c
	mov r1, r8
	adds r5, r1, r0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x88
_080DA77E:
	adds r0, r5, #0
	adds r0, #0x38
	ldrb r0, [r0]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA794
	adds r0, r4, #0
	bl Particle_Remove
_080DA794:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA77E
	adds r0, r5, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA7AE
	adds r0, r5, #0
	adds r0, #0x5c
	bl AuxSprite_Remove
_080DA7AE:
	adds r2, r7, #0
	cmp r2, #7
	ble _080DA74E
	movs r1, #0
	ldr r0, _080DA7C8 @ =0x0300015C
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA7C8: .4byte 0x0300015C

	thumb_func_start FUN_080da7cc
FUN_080da7cc: @ 0x080DA7CC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x18
	ldr r1, _080DA808 @ =0x0000363C
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080DA80C @ =0x0000363D
	bl Video_GetAuxSprite
	ldr r0, _080DA810 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x58]
	ldr r4, _080DA814 @ =0x0000922E
	ldr r1, _080DA818 @ =0x00006830
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x50]
	ldr r1, _080DA81C @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x54]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DA808: .4byte 0x0000363C
_080DA80C: .4byte 0x0000363D
_080DA810: .4byte 0x00001C1C
_080DA814: .4byte 0x0000922E
_080DA818: .4byte 0x00006830
_080DA81C: .4byte 0x0000D41F

	thumb_func_start Entity080da848_Init
Entity080da848_Init: @ 0x080DA820
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DA840 @ =0x000009FC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080da7cc
	ldr r0, _080DA844 @ =0x0300015C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DA840: .4byte 0x000009FC
_080DA844: .4byte 0x0300015C

	thumb_func_start Entity080da848_Create
Entity080da848_Create: @ 0x080DA848
	push {r4, lr}
	ldr r0, _080DA880 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA88E
	movs r1, #0xa0
	lsls r1, r1, #4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DA88C
	ldr r1, _080DA884 @ =Entity080da848_Update
	ldr r2, _080DA888 @ =Entity080da848_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080da848_Init
	cmp r0, #0
	bge _080DA88C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DA88E
	.align 2, 0
_080DA880: .4byte 0x0300015C
_080DA884: .4byte Entity080da848_Update
_080DA888: .4byte Entity080da848_Destroy
_080DA88C:
	adds r0, r4, #0
_080DA88E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da894
FUN_080da894: @ 0x080DA894
	ldr r1, _080DA89C @ =0x0300015C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DA89C: .4byte 0x0300015C

	thumb_func_start FUN_080da8a0
FUN_080da8a0: @ 0x080DA8A0
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DA8C0 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	cmp r1, #0
	beq _080DA8C4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	movs r0, #0
	b _080DA8C6
	.align 2, 0
_080DA8C0: .4byte 0x0300015C
_080DA8C4:
	movs r0, #1
_080DA8C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da8cc
FUN_080da8cc: @ 0x080DA8CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DA908 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	str r0, [sp]
	ldr r1, _080DA90C @ =0x000009FC
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	movs r3, #0
	ldr r2, [sp]
	adds r2, r2, r1
	mov sl, r2
_080DA8F4:
	movs r1, #1
	lsls r1, r3
	mov r7, sl
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DA910
	movs r0, #1
	b _080DA912
	.align 2, 0
_080DA908: .4byte 0x0300015C
_080DA90C: .4byte 0x000009FC
_080DA910:
	movs r0, #0
_080DA912:
	adds r1, r3, #1
	mov sb, r1
	cmp r0, #0
	beq _080DA9AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	ldr r2, [sp]
	adds r5, r2, r0
	adds r4, r5, #0
	adds r4, #0x88
	adds r6, r5, #0
	adds r6, #0x5c
	adds r2, r5, #0
	adds r2, #0x39
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080DA9AE
	movs r1, #1
	lsls r1, r0
	mov r7, sl
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #1
	bls _080DA958
	cmp r0, #4
	beq _080DA958
	cmp r0, #5
	bne _080DA978
_080DA958:
	adds r4, r5, #0
	adds r4, #0x44
	ldrb r0, [r4]
	movs r1, #0x39
	adds r1, r1, r5
	mov r8, r1
	adds r3, #1
	mov sb, r3
	cmp r0, #0
	beq _080DA99E
	adds r0, r6, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
	b _080DA99E
_080DA978:
	movs r6, #0
	mov r8, r2
	adds r7, r5, #0
	adds r7, #0x38
_080DA980:
	ldrb r0, [r7]
	asrs r0, r6
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080DA992
	adds r0, r4, #0
	bl Particle_Remove
_080DA992:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA980
	movs r0, #0
	strb r0, [r7]
_080DA99E:
	adds r0, r5, #0
	movs r1, #0x9a
	lsls r1, r1, #1
	bl ClearMemory
	movs r0, #0xff
	mov r7, r8
	strb r0, [r7]
_080DA9AE:
	mov r3, sb
	cmp r3, #7
	ble _080DA8F4
_080DA9B4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
