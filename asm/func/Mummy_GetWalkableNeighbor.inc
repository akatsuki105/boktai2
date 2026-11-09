	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r0, _081299BC @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	mov sb, r0
	cmp r1, #1
	bne _081299B0
	b _08129B7C
_081299B0:
	cmp r1, #1
	bgt _081299C0
	cmp r1, #0
	beq _081299CE
	b _0812A080
	.align 2, 0
_081299BC: .4byte 0x00000256
_081299C0:
	cmp r1, #2
	bne _081299C6
	b _08129D2C
_081299C6:
	cmp r1, #3
	bne _081299CC
	b _08129EDC
_081299CC:
	b _0812A080
_081299CE:
	mov r4, sb
	adds r4, #1
	ldr r0, _081299F8 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r2, r8
	ldrh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x18
	cmp sb, r1
	bne _08129A58
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081299FC
	adds r0, #4
	b _08129A08
	.align 2, 0
_081299F8: .4byte 0x00000256
_081299FC:
	ldr r0, _08129A24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129A08:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129A28
	adds r0, #4
	b _08129A34
	.align 2, 0
_08129A24: .4byte 0x030046A4
_08129A28:
	ldr r0, _08129A44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129A34:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129A48
_08129A3E:
	movs r0, #0
	b _08129A4A
	.align 2, 0
_08129A44: .4byte 0x030046A4
_08129A48:
	movs r0, #1
_08129A4A:
	cmp r0, #0
	bne _08129A50
	b _08129B62
_08129A50:
	cmp r5, r4
	bne _08129A56
	b _08129B5E
_08129A56:
	b _08129B62
_08129A58:
	ldr r6, _08129A7C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r4, r0
	bne _08129AC0
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129A80
	adds r0, #4
	b _08129A8A
	.align 2, 0
_08129A7C: .4byte 0x030046A4
_08129A80:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129A8A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129AA4
_08129AA0:
	adds r0, #4
	b _08129AB0
_08129AA4:
	ldr r0, _08129ABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129AB0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129A3E
	b _08129A48
	.align 2, 0
_08129ABC: .4byte 0x030046A4
_08129AC0:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129AFA
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129AD8
	adds r0, #4
	b _08129AE2
_08129AD8:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129AE2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _08129AA0
	b _08129AA4
_08129AFA:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129B62
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129B12
	adds r0, #4
	b _08129B1C
_08129B12:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129B1C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129B4C
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129B36
	adds r0, #4
	b _08129B42
_08129B36:
	ldr r0, _08129B50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129B42:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129B54
_08129B4C:
	movs r0, #0
	b _08129B56
	.align 2, 0
_08129B50: .4byte 0x030046A4
_08129B54:
	movs r0, #1
_08129B56:
	cmp r0, #0
	beq _08129B62
	cmp r5, r4
	bne _08129B62
_08129B5E:
	movs r0, #1
	b _08129B64
_08129B62:
	movs r0, #0
_08129B64:
	cmp r0, #0
	bne _08129B6A
	b _0812A080
_08129B6A:
	ldr r0, _08129B78 @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	adds r0, #1
	mov sb, r0
	b _0812A080
	.align 2, 0
_08129B78: .4byte 0x00000256
_08129B7C:
	ldr r7, _08129BB0 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	mov r3, sb
	adds r4, r3, r2
	ldr r0, _08129BB4 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	subs r0, r4, #1
	cmp r0, r1
	bne _08129C0C
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129BB8
	adds r0, #4
	b _08129BC2
	.align 2, 0
_08129BB0: .4byte 0x030046A4
_08129BB4: .4byte 0x00000256
_08129BB8:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129BC2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129BDC
	adds r0, #4
	b _08129BE8
_08129BDC:
	ldr r0, _08129BF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129BE8:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129BFC
_08129BF2:
	movs r0, #0
	b _08129BFE
	.align 2, 0
_08129BF8: .4byte 0x030046A4
_08129BFC:
	movs r0, #1
_08129BFE:
	cmp r0, #0
	bne _08129C04
	b _08129D06
_08129C04:
	cmp r5, r4
	bne _08129C0A
	b _08129D02
_08129C0A:
	b _08129D06
_08129C0C:
	adds r0, r1, r2
	cmp r4, r0
	bne _08129C64
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129C24
	adds r0, #4
	b _08129C2E
_08129C24:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129C2E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129C48
_08129C44:
	adds r0, #4
	b _08129C54
_08129C48:
	ldr r0, _08129C60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129C54:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129BF2
	b _08129BFC
	.align 2, 0
_08129C60: .4byte 0x030046A4
_08129C64:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129C9E
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129C7C
	adds r0, #4
	b _08129C86
_08129C7C:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129C86:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _08129C44
	b _08129C48
_08129C9E:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129D06
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129CB6
	adds r0, #4
	b _08129CC0
_08129CB6:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129CC0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129CF0
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129CDA
	adds r0, #4
	b _08129CE6
_08129CDA:
	ldr r0, _08129CF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129CE6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129CF8
_08129CF0:
	movs r0, #0
	b _08129CFA
	.align 2, 0
_08129CF4: .4byte 0x030046A4
_08129CF8:
	movs r0, #1
_08129CFA:
	cmp r0, #0
	beq _08129D06
	cmp r5, r4
	bne _08129D06
_08129D02:
	movs r0, #1
	b _08129D08
_08129D06:
	movs r0, #0
_08129D08:
	cmp r0, #0
	bne _08129D0E
	b _0812A080
_08129D0E:
	ldr r1, _08129D24 @ =0x00000256
	add r1, r8
	ldr r0, _08129D28 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r1, r1, r0
	b _0812A07E
	.align 2, 0
_08129D24: .4byte 0x00000256
_08129D28: .4byte 0x030046A4
_08129D2C:
	mov r4, sb
	subs r4, #1
	ldr r0, _08129D58 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x18
	mov r0, sb
	subs r0, #2
	cmp r0, r1
	bne _08129DB8
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129D5C
	adds r0, #4
	b _08129D68
	.align 2, 0
_08129D58: .4byte 0x00000256
_08129D5C:
	ldr r0, _08129D84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129D68:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129D88
	adds r0, #4
	b _08129D94
	.align 2, 0
_08129D84: .4byte 0x030046A4
_08129D88:
	ldr r0, _08129DA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129D94:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129DA8
_08129D9E:
	movs r0, #0
	b _08129DAA
	.align 2, 0
_08129DA4: .4byte 0x030046A4
_08129DA8:
	movs r0, #1
_08129DAA:
	cmp r0, #0
	bne _08129DB0
	b _08129EC2
_08129DB0:
	cmp r5, r4
	bne _08129DB6
	b _08129EBE
_08129DB6:
	b _08129EC2
_08129DB8:
	ldr r6, _08129DDC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r4, r0
	bne _08129E20
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129DE0
	adds r0, #4
	b _08129DEA
	.align 2, 0
_08129DDC: .4byte 0x030046A4
_08129DE0:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129DEA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129E04
_08129E00:
	adds r0, #4
	b _08129E10
_08129E04:
	ldr r0, _08129E1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129E10:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129D9E
	b _08129DA8
	.align 2, 0
_08129E1C: .4byte 0x030046A4
_08129E20:
	cmp sb, r1
	bne _08129E58
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129E36
	adds r0, #4
	b _08129E40
_08129E36:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129E40:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _08129E00
	b _08129E04
_08129E58:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129EC2
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129E70
	adds r0, #4
	b _08129E7A
_08129E70:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129E7A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129EAA
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129E94
	adds r0, #4
	b _08129EA0
_08129E94:
	ldr r0, _08129EB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129EB4
_08129EAA:
	movs r0, #0
	b _08129EB6
	.align 2, 0
_08129EB0: .4byte 0x030046A4
_08129EB4:
	movs r0, #1
_08129EB6:
	cmp r0, #0
	beq _08129EC2
	cmp r5, r4
	bne _08129EC2
_08129EBE:
	movs r0, #1
	b _08129EC4
_08129EC2:
	movs r0, #0
_08129EC4:
	cmp r0, #0
	bne _08129ECA
	b _0812A080
_08129ECA:
	ldr r0, _08129ED8 @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	subs r0, #1
	mov sb, r0
	b _0812A080
	.align 2, 0
_08129ED8: .4byte 0x00000256
_08129EDC:
	ldr r7, _08129F10 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	mov r3, sb
	subs r4, r3, r2
	ldr r0, _08129F14 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	subs r0, r4, #1
	cmp r0, r1
	bne _08129F6C
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129F18
	adds r0, #4
	b _08129F22
	.align 2, 0
_08129F10: .4byte 0x030046A4
_08129F14: .4byte 0x00000256
_08129F18:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129F22:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129F3C
	adds r0, #4
	b _08129F48
_08129F3C:
	ldr r0, _08129F58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129F48:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129F5C
_08129F52:
	movs r0, #0
	b _08129F5E
	.align 2, 0
_08129F58: .4byte 0x030046A4
_08129F5C:
	movs r0, #1
_08129F5E:
	cmp r0, #0
	bne _08129F64
	b _0812A066
_08129F64:
	cmp r5, r4
	bne _08129F6A
	b _0812A062
_08129F6A:
	b _0812A066
_08129F6C:
	adds r0, r1, r2
	cmp r4, r0
	bne _08129FC4
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129F84
	adds r0, #4
	b _08129F8E
_08129F84:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129F8E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129FA8
_08129FA4:
	adds r0, #4
	b _08129FB4
_08129FA8:
	ldr r0, _08129FC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129FB4:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129F52
	b _08129F5C
	.align 2, 0
_08129FC0: .4byte 0x030046A4
_08129FC4:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129FFE
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08129FDC
	adds r0, #4
	b _08129FE6
_08129FDC:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129FE6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _08129FA4
	b _08129FA8
_08129FFE:
	subs r0, r1, r2
	cmp r4, r0
	bne _0812A066
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812A016
	adds r0, #4
	b _0812A020
_0812A016:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812A020:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _0812A050
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812A03A
	adds r0, #4
	b _0812A046
_0812A03A:
	ldr r0, _0812A054 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812A046:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0812A058
_0812A050:
	movs r0, #0
	b _0812A05A
	.align 2, 0
_0812A054: .4byte 0x030046A4
_0812A058:
	movs r0, #1
_0812A05A:
	cmp r0, #0
	beq _0812A066
	cmp r5, r4
	bne _0812A066
_0812A062:
	movs r0, #1
	b _0812A068
_0812A066:
	movs r0, #0
_0812A068:
	cmp r0, #0
	beq _0812A080
	ldr r0, _0812A090 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _0812A094 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
_0812A07E:
	mov sb, r1
_0812A080:
	mov r0, sb
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812A090: .4byte 0x00000256
_0812A094: .4byte 0x030046A4
