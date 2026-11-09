	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov sl, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldr r0, _0818E750 @ =0x000004A4
	add r0, sl
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r3, r0, #6
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0xc
_0818E72E:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0818E72E
	movs r2, #0
	mov r8, r2
	movs r6, #1
	rsbs r6, r6, #0
	mov sb, r6
	ldr r1, [sp, #0x18]
	ldr r2, _0818E754 @ =0x00000F44
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _0818E758
	adds r4, r3, #1
	b _0818E772
	.align 2, 0
_0818E750: .4byte 0x000004A4
_0818E754: .4byte 0x00000F44
_0818E758:
	cmp r0, #5
	bne _0818E784
	ldr r2, _0818E778 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818E77C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _0818E780 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r4, r3, r0
_0818E772:
	movs r0, #3
	ands r4, r0
	b _0818E786
	.align 2, 0
_0818E778: .4byte 0x030046B8
_0818E77C: .4byte 0x000003FF
_0818E780: .4byte 0x0203B400
_0818E784:
	adds r4, r3, #0
_0818E786:
	ldr r0, [sp, #0x18]
	ldr r1, _0818E7F4 @ =0x00000F44
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0x10
	bls _0818E7AE
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, sl
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [sp, #0x18]
	ldr r6, _0818E7F8 @ =0x00000F45
	adds r1, r2, r6
	movs r2, #0
	strb r0, [r1]
	strb r2, [r5]
_0818E7AE:
	movs r6, #3
	movs r7, #3
	mov r1, r8
	lsls r0, r1, #2
	add r0, sp
	str r0, [sp, #0x38]
_0818E7BA:
	ldr r2, [sp, #0x18]
	ldr r1, _0818E7F8 @ =0x00000F45
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, r4, r0
	cmp r0, #0
	bge _0818E7CA
	rsbs r0, r0, #0
_0818E7CA:
	cmp r0, #2
	beq _0818E806
	subs r0, r4, r3
	cmp r0, #0
	bge _0818E7D6
	rsbs r0, r0, #0
_0818E7D6:
	cmp r0, #2
	beq _0818E806
	mov r0, sl
	adds r1, r4, #0
	str r3, [sp, #0x3c]
	bl FUN_0818e524
	adds r5, r0, #0
	ldr r3, [sp, #0x3c]
	cmp r5, #0
	blt _0818E806
	cmp r4, r3
	bne _0818E7FC
	mov sb, r5
	b _0818E806
	.align 2, 0
_0818E7F4: .4byte 0x00000F44
_0818E7F8: .4byte 0x00000F45
_0818E7FC:
	ldr r2, [sp, #0x38]
	stm r2!, {r5}
	str r2, [sp, #0x38]
	movs r0, #1
	add r8, r0
_0818E806:
	adds r4, #1
	ands r4, r6
	subs r7, #1
	cmp r7, #0
	bge _0818E7BA
	mov r1, r8
	cmp r1, #0
	bne _0818E818
	b _0818E970
_0818E818:
	movs r7, #0
	ldr r4, [sp, #0x1c]
	adds r4, #0xc
	cmp r7, r8
	bge _0818E8BC
	mov r6, sp
_0818E824:
	ldr r1, [r6]
	mov r0, sl
	bl FUN_081920c4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818E8B4
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _0818E870 @ =0x030046A4
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
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E874
	adds r0, #4
	b _0818E87E
	.align 2, 0
_0818E870: .4byte 0x030046A4
_0818E874:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E87E:
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
	mov r0, sl
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818E8B0 @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818E8B0: .4byte 0x00000F44
_0818E8B4:
	adds r6, #4
	adds r7, #1
	cmp r7, r8
	blt _0818E824
_0818E8BC:
	ldr r2, _0818E91C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818E920 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0818E924 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	adds r7, r0, #0
	lsls r0, r7, #2
	add r0, sp
	mov sb, r4
	ldr r5, [r0]
	ldr r6, _0818E928 @ =0x030046A4
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
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E92C
	adds r0, #4
	b _0818E936
	.align 2, 0
_0818E91C: .4byte 0x030046B8
_0818E920: .4byte 0x000003FF
_0818E924: .4byte 0x0203B400
_0818E928: .4byte 0x030046A4
_0818E92C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E936:
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
	lsls r0, r7, #2
	add r0, sp
	ldr r1, [r0]
	mov r0, sl
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818E96C @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818E96C: .4byte 0x00000F44
_0818E970:
	movs r0, #1
	rsbs r0, r0, #0
	cmp sb, r0
	beq _0818EA04
	mov r0, sl
	mov r1, sb
	bl FUN_081920c4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818EA04
	ldr r7, [sp, #0x1c]
	adds r7, #0xc
	ldr r5, _0818E9C4 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	mov r0, sb
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	mov r0, sb
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	mov r0, sb
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E9C8
	adds r0, #4
	b _0818E9D4
	.align 2, 0
_0818E9C4: .4byte 0x030046A4
_0818E9C8:
	ldr r0, [r5]
	mov r2, sb
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E9D4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	mov r0, sl
	mov r1, sb
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818EA00 @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818EA00: .4byte 0x00000F44
_0818EA04:
	ldr r1, [sp, #0x18]
	ldr r2, _0818EA20 @ =0x00000F45
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _0818EA40
	cmp r6, #1
	bgt _0818EA24
	cmp r6, #0
	beq _0818EA2E
	b _0818EA90
	.align 2, 0
_0818EA20: .4byte 0x00000F45
_0818EA24:
	cmp r6, #2
	beq _0818EA60
	cmp r6, #3
	beq _0818EA70
	b _0818EA90
_0818EA2E:
	ldr r1, _0818EA3C @ =0x00000256
	add r1, sl
	ldrh r0, [r1]
	adds r7, r0, #1
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA3C: .4byte 0x00000256
_0818EA40:
	ldr r1, _0818EA58 @ =0x00000256
	add r1, sl
	ldr r0, _0818EA5C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA58: .4byte 0x00000256
_0818EA5C: .4byte 0x030046A4
_0818EA60:
	ldr r1, _0818EA6C @ =0x00000256
	add r1, sl
	ldrh r0, [r1]
	subs r7, r0, #1
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA6C: .4byte 0x00000256
_0818EA70:
	ldr r1, _0818EA88 @ =0x00000256
	add r1, sl
	ldrh r2, [r1]
	ldr r0, _0818EA8C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA88: .4byte 0x00000256
_0818EA8C: .4byte 0x030046A4
_0818EA90:
	ldr r0, _0818EAA8 @ =0x00000256
	add r0, sl
	ldrh r7, [r0]
	mov sb, r0
_0818EA98:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EAAC
	adds r0, #4
	b _0818EAB8
	.align 2, 0
_0818EAA8: .4byte 0x00000256
_0818EAAC:
	ldr r0, _0818EAD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EAB8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x20]
	mov r0, sb
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EAD8
	adds r0, #4
	b _0818EAE4
	.align 2, 0
_0818EAD4: .4byte 0x030046A4
_0818EAD8:
	ldr r0, _0818EAFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EAE4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x24]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EB00
	adds r0, #4
	b _0818EB0C
	.align 2, 0
_0818EAFC: .4byte 0x030046A4
_0818EB00:
	ldr r0, _0818EB50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EB0C:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x28]
	add r5, sp, #0x10
	ldr r1, _0818EB50 @ =0x030046A4
	mov r8, r1
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x2c]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EB54
	adds r0, #4
	b _0818EB60
	.align 2, 0
_0818EB50: .4byte 0x030046A4
_0818EB54:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EB60:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	ldr r1, [sp, #0x2c]
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x10
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EB84
	adds r0, #4
	b _0818EB90
_0818EB84:
	ldr r2, _0818EBA4 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EB90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818EBA8
	cmp r2, #2
	beq _0818EBAC
	b _0818EBB0
	.align 2, 0
_0818EBA4: .4byte 0x030046A4
_0818EBA8:
	ldrb r0, [r4, #4]
	b _0818EBAE
_0818EBAC:
	ldrb r0, [r4]
_0818EBAE:
	subs r1, r1, r0
_0818EBB0:
	str r1, [sp, #0x30]
	mov r2, sb
	ldrh r5, [r2]
	mov r3, sp
	adds r3, #0x10
	str r3, [sp, #0x34]
	ldr r1, _0818EBF8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0818EBF8 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EBFC
	adds r0, #4
	b _0818EC08
	.align 2, 0
_0818EBF8: .4byte 0x030046A4
_0818EBFC:
	ldr r3, _0818EC34 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EC08:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [sp, #0x34]
	strh r1, [r0, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	ldr r2, [sp, #0x34]
	strh r0, [r2, #4]
	mov r3, sb
	ldrh r4, [r3]
	add r5, sp, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EC38
	adds r0, #4
	b _0818EC44
	.align 2, 0
_0818EC34: .4byte 0x030046A4
_0818EC38:
	ldr r0, _0818EC58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EC44:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818EC5C
	cmp r2, #2
	beq _0818EC60
	b _0818EC64
	.align 2, 0
_0818EC58: .4byte 0x030046A4
_0818EC5C:
	ldrb r0, [r5, #4]
	b _0818EC62
_0818EC60:
	ldrb r0, [r5]
_0818EC62:
	subs r1, r1, r0
_0818EC64:
	ldr r0, [sp, #0x30]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x30]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x28]
	ands r3, r0
	cmp r3, #0
	beq _0818EC84
	b _0818EE00
_0818EC84:
	cmp r2, #0
	beq _0818ED76
	ldr r0, [sp, #0x20]
	cmp r0, #1
	bne _0818ECA8
	cmp r6, #1
	bne _0818EC9E
	ldr r3, [sp, #0x24]
	cmp r3, #1
	bne _0818ECBE
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ECCE
_0818EC9E:
	cmp r6, #3
	beq _0818ECA4
	b _0818EE00
_0818ECA4:
	ldr r0, [sp, #0x24]
	b _0818ECCC
_0818ECA8:
	ldr r3, [sp, #0x20]
	cmp r3, #2
	bne _0818ECD4
	cmp r6, #0
	bne _0818ECC4
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ECBE
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ECCE
_0818ECBE:
	cmp r1, #0
	beq _0818ECD4
	b _0818EE00
_0818ECC4:
	cmp r6, #2
	beq _0818ECCA
	b _0818EE00
_0818ECCA:
	ldr r3, [sp, #0x24]
_0818ECCC:
	ldr r0, _0818ECEC @ =0xFFFFFF00
_0818ECCE:
	cmp r1, r0
	beq _0818ECD4
	b _0818EE00
_0818ECD4:
	ldr r0, [sp, #0x24]
	cmp r0, #1
	bne _0818ED04
	cmp r6, #1
	bne _0818ECF6
	ldr r3, [sp, #0x20]
	cmp r3, #1
	bne _0818ECF0
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
	.align 2, 0
_0818ECEC: .4byte 0xFFFFFF00
_0818ECF0:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ECF6:
	cmp r6, #3
	beq _0818ECFC
	b _0818EE00
_0818ECFC:
	ldr r6, [sp, #0x20]
	cmp r6, #1
	beq _0818ED2A
	b _0818ED38
_0818ED04:
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ED48
	cmp r6, #0
	bne _0818ED20
	ldr r3, [sp, #0x20]
	cmp r3, #2
	bne _0818ED1A
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ED1A:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ED20:
	cmp r6, #2
	bne _0818EE00
	ldr r6, [sp, #0x20]
	cmp r6, #2
	bne _0818ED38
_0818ED2A:
	ldr r0, _0818ED34 @ =0xFFFFFF00
_0818ED2C:
	cmp r1, r0
	beq _0818ED3C
	b _0818EE00
	.align 2, 0
_0818ED34: .4byte 0xFFFFFF00
_0818ED38:
	cmp r1, #0
	bne _0818EE00
_0818ED3C:
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ED48
	ldr r1, [sp, #0x20]
	cmp r1, #2
	beq _0818ED54
_0818ED48:
	ldr r3, [sp, #0x24]
	cmp r3, #1
	bne _0818ED66
	ldr r6, [sp, #0x20]
	cmp r6, #1
	bne _0818ED66
_0818ED54:
	adds r1, r2, #0
	cmp r2, #0
	bge _0818ED5C
	rsbs r1, r2, #0
_0818ED5C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0818ED76
	b _0818EE00
_0818ED66:
	adds r0, r2, #0
	cmp r0, #0
	bge _0818ED6E
	rsbs r0, r0, #0
_0818ED6E:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _0818ED78
_0818ED76:
	adds r5, r7, #0
_0818ED78:
	cmp r5, #0
	blt _0818EE00
	ldr r0, [sp, #0x1c]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _0818EDBC @ =0x030046A4
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
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818EDC0
	adds r0, #4
	b _0818EDCA
	.align 2, 0
_0818EDBC: .4byte 0x030046A4
_0818EDC0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EDCA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081920f4
	ldr r2, [sp, #0x18]
	ldr r3, _0818EDFC @ =0x00000F44
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	movs r6, #0xf4
	lsls r6, r6, #4
	adds r1, r2, r6
_0818EDF6:
	movs r0, #0x28
	strh r0, [r1]
	b _0818EE10
	.align 2, 0
_0818EDFC: .4byte 0x00000F44
_0818EE00:
	ldr r1, [sp, #0x18]
	ldr r2, _0818EE20 @ =0x00000F45
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_0818EE10:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818EE20: .4byte 0x00000F45
