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
	ldr r3, _081A9800 @ =0x000004A4
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
_081A97D8:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _081A97D8
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x24]
	ldr r2, _081A9804 @ =0x00000CB8
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #2
	bne _081A9808
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _081A9836
	.align 2, 0
_081A9800: .4byte 0x000004A4
_081A9804: .4byte 0x00000CB8
_081A9808:
	cmp r3, #3
	bne _081A9834
	ldr r2, _081A9828 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A982C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A9830 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0x2c]
	adds r6, r1, r0
	ands r6, r3
	b _081A9836
	.align 2, 0
_081A9828: .4byte 0x030046B8
_081A982C: .4byte 0x000003FF
_081A9830: .4byte 0x0203B400
_081A9834:
	ldr r6, [sp, #0x2c]
_081A9836:
	ldr r2, [sp, #0x24]
	ldr r4, _081A9898 @ =0x00000CB8
	adds r3, r2, r4
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _081A9860
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
	ldr r2, _081A989C @ =0x00000CB9
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_081A9860:
	movs r3, #3
	str r3, [sp, #0x30]
_081A9864:
	ldr r4, [sp, #0x24]
	ldr r1, _081A989C @ =0x00000CB9
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _081A9874
	rsbs r0, r0, #0
_081A9874:
	cmp r0, #2
	bne _081A987A
	b _081A9C1A
_081A987A:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _081A9884
	rsbs r0, r0, #0
_081A9884:
	cmp r0, #2
	bne _081A988A
	b _081A9C1A
_081A988A:
	cmp r6, #1
	beq _081A98BC
	cmp r6, #1
	bgt _081A98A0
	cmp r6, #0
	beq _081A98AA
	b _081A9910
	.align 2, 0
_081A9898: .4byte 0x00000CB8
_081A989C: .4byte 0x00000CB9
_081A98A0:
	cmp r6, #2
	beq _081A98DC
	cmp r6, #3
	beq _081A98F0
	b _081A9910
_081A98AA:
	ldr r3, [sp, #0x20]
	ldr r4, _081A98B8 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98B8: .4byte 0x00000256
_081A98BC:
	ldr r0, [sp, #0x20]
	ldr r2, _081A98D4 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _081A98D8 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98D4: .4byte 0x00000256
_081A98D8: .4byte 0x030046A4
_081A98DC:
	ldr r3, [sp, #0x20]
	ldr r4, _081A98EC @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98EC: .4byte 0x00000256
_081A98F0:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9908 @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _081A990C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A9908: .4byte 0x00000256
_081A990C: .4byte 0x030046A4
_081A9910:
	ldr r1, [sp, #0x20]
	ldr r2, _081A992C @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_081A991A:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9930
	adds r0, #4
	b _081A993C
	.align 2, 0
_081A992C: .4byte 0x00000256
_081A9930:
	ldr r3, _081A9958 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A993C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A995C
	adds r0, #4
	b _081A9968
	.align 2, 0
_081A9958: .4byte 0x030046A4
_081A995C:
	ldr r1, _081A9980 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9968:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9984
	adds r0, #4
	b _081A9990
	.align 2, 0
_081A9980: .4byte 0x030046A4
_081A9984:
	ldr r2, _081A99D4 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9990:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _081A99D4 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A99D8
	adds r0, #4
	b _081A99E4
	.align 2, 0
_081A99D4: .4byte 0x030046A4
_081A99D8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A99E4:
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9A08
	adds r0, #4
	b _081A9A14
_081A9A08:
	ldr r1, _081A9A28 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9A14:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9A2C
	cmp r2, #2
	beq _081A9A30
	b _081A9A34
	.align 2, 0
_081A9A28: .4byte 0x030046A4
_081A9A2C:
	ldrb r0, [r4, #4]
	b _081A9A32
_081A9A30:
	ldrb r0, [r4]
_081A9A32:
	subs r1, r1, r0
_081A9A34:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _081A9A7C @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _081A9A7C @ =0x030046A4
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
	beq _081A9A80
	adds r0, #4
	b _081A9A8C
	.align 2, 0
_081A9A7C: .4byte 0x030046A4
_081A9A80:
	ldr r3, _081A9AB8 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9A8C:
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9ABC
	adds r0, #4
	b _081A9AC8
	.align 2, 0
_081A9AB8: .4byte 0x030046A4
_081A9ABC:
	ldr r3, _081A9ADC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9AC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9AE0
	cmp r2, #2
	beq _081A9AE4
	b _081A9AE8
	.align 2, 0
_081A9ADC: .4byte 0x030046A4
_081A9AE0:
	ldrb r0, [r5, #4]
	b _081A9AE6
_081A9AE4:
	ldrb r0, [r5]
_081A9AE6:
	subs r1, r1, r0
_081A9AE8:
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
	beq _081A9B08
	b _081A9C1A
_081A9B08:
	cmp r2, #0
	beq _081A9BFE
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081A9B2E
	cmp r6, #1
	bne _081A9B26
	mov r0, sl
	cmp r0, #1
	bne _081A9B48
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081A9B5A
	b _081A9C1A
_081A9B26:
	cmp r6, #3
	bne _081A9C1A
	mov r4, sl
	b _081A9B54
_081A9B2E:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _081A9B5A
	cmp r6, #0
	bne _081A9B4E
	mov r3, sl
	cmp r3, #2
	bne _081A9B48
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081A9B5A
	b _081A9C1A
_081A9B48:
	cmp r1, #0
	beq _081A9B5A
	b _081A9C1A
_081A9B4E:
	cmp r6, #2
	bne _081A9C1A
	mov r0, sl
_081A9B54:
	ldr r0, _081A9B70 @ =0xFFFFFF00
	cmp r1, r0
	bne _081A9C1A
_081A9B5A:
	mov r3, sl
	cmp r3, #1
	bne _081A9B8A
	cmp r6, #1
	bne _081A9B7E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081A9B74
	movs r0, #0x80
	lsls r0, r0, #1
	b _081A9BB6
	.align 2, 0
_081A9B70: .4byte 0xFFFFFF00
_081A9B74:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081A9BC4
	b _081A9C1A
_081A9B7E:
	cmp r6, #3
	bne _081A9C1A
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _081A9BB4
	b _081A9BC0
_081A9B8A:
	mov r0, sl
	cmp r0, #2
	bne _081A9BD0
	cmp r6, #0
	bne _081A9BAA
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _081A9BA4
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081A9BC4
	b _081A9C1A
_081A9BA4:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081A9BB6
_081A9BAA:
	cmp r6, #2
	bne _081A9C1A
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _081A9BC0
_081A9BB4:
	ldr r0, _081A9BBC @ =0xFFFFFF00
_081A9BB6:
	cmp r1, r0
	beq _081A9BC4
	b _081A9C1A
	.align 2, 0
_081A9BBC: .4byte 0xFFFFFF00
_081A9BC0:
	cmp r1, #0
	bne _081A9C1A
_081A9BC4:
	mov r4, sl
	cmp r4, #2
	bne _081A9BD0
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _081A9BDC
_081A9BD0:
	mov r1, sl
	cmp r1, #1
	bne _081A9BEE
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _081A9BEE
_081A9BDC:
	adds r0, r2, #0
	cmp r2, #0
	bge _081A9BE4
	rsbs r0, r2, #0
_081A9BE4:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _081A9BFE
	b _081A9C1A
_081A9BEE:
	adds r0, r2, #0
	cmp r0, #0
	bge _081A9BF6
	rsbs r0, r0, #0
_081A9BF6:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _081A9C00
_081A9BFE:
	adds r5, r7, #0
_081A9C00:
	cmp r5, #0
	blt _081A9C1A
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _081A9C0E
	str r5, [sp, #0x38]
	b _081A9C1A
_081A9C0E:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_081A9C1A:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _081A9C2C
	b _081A9864
_081A9C2C:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _081A9C34
	b _081A9D8C
_081A9C34:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _081A9CE2
	mov r6, sp
_081A9C44:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl Salamander_IsRecentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A9CD4
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _081A9C90 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9C94
	adds r0, #4
	b _081A9C9E
	.align 2, 0
_081A9C90: .4byte 0x030046A4
_081A9C94:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9C9E:
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
	bl Salamander_AddRecentTile
	ldr r3, [sp, #0x24]
	ldr r4, _081A9CCC @ =0x00000CB8
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _081A9CD0 @ =0x00000CB4
	adds r1, r3, r0
	b _081AA218
	.align 2, 0
_081A9CCC: .4byte 0x00000CB8
_081A9CD0: .4byte 0x00000CB4
_081A9CD4:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _081A9C44
_081A9CE2:
	ldr r2, _081A9D40 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A9D44 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A9D48 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _081A9D4C @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9D50
	adds r0, #4
	b _081A9D5A
	.align 2, 0
_081A9D40: .4byte 0x030046B8
_081A9D44: .4byte 0x000003FF
_081A9D48: .4byte 0x0203B400
_081A9D4C: .4byte 0x030046A4
_081A9D50:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9D5A:
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
	bl Salamander_AddRecentTile
	ldr r2, [sp, #0x24]
	ldr r3, _081A9D88 @ =0x00000CB8
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _081AA212
	.align 2, 0
_081A9D88: .4byte 0x00000CB8
_081A9D8C:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _081A9E24
	ldr r0, [sp, #0x20]
	bl Salamander_IsRecentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A9E24
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _081A9DE0 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9DE4
	adds r0, #4
	b _081A9DF0
	.align 2, 0
_081A9DE0: .4byte 0x030046A4
_081A9DE4:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9DF0:
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
	bl Salamander_AddRecentTile
	ldr r3, [sp, #0x24]
	ldr r4, _081A9E1C @ =0x00000CB8
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _081A9E20 @ =0x00000CB4
	adds r1, r3, r0
	b _081AA218
	.align 2, 0
_081A9E1C: .4byte 0x00000CB8
_081A9E20: .4byte 0x00000CB4
_081A9E24:
	ldr r1, [sp, #0x24]
	ldr r2, _081A9E40 @ =0x00000CB9
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _081A9E60
	cmp r6, #1
	bgt _081A9E44
	cmp r6, #0
	beq _081A9E4E
	b _081A9EB4
	.align 2, 0
_081A9E40: .4byte 0x00000CB9
_081A9E44:
	cmp r6, #2
	beq _081A9E80
	cmp r6, #3
	beq _081A9E94
	b _081A9EB4
_081A9E4E:
	ldr r3, [sp, #0x20]
	ldr r4, _081A9E5C @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E5C: .4byte 0x00000256
_081A9E60:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9E78 @ =0x00000256
	adds r1, r0, r2
	ldr r0, _081A9E7C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E78: .4byte 0x00000256
_081A9E7C: .4byte 0x030046A4
_081A9E80:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9E90 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E90: .4byte 0x00000256
_081A9E94:
	ldr r3, [sp, #0x20]
	ldr r4, _081A9EAC @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _081A9EB0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9EAC: .4byte 0x00000256
_081A9EB0: .4byte 0x030046A4
_081A9EB4:
	ldr r4, [sp, #0x20]
	ldr r1, _081A9ED0 @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_081A9EBE:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9ED4
	adds r0, #4
	b _081A9EE0
	.align 2, 0
_081A9ED0: .4byte 0x00000256
_081A9ED4:
	ldr r0, _081A9EFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9EE0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9F00
	adds r0, #4
	b _081A9F0C
	.align 2, 0
_081A9EFC: .4byte 0x030046A4
_081A9F00:
	ldr r0, _081A9F24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9F0C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9F28
	adds r0, #4
	b _081A9F34
	.align 2, 0
_081A9F24: .4byte 0x030046A4
_081A9F28:
	ldr r0, _081A9F78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9F34:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _081A9F78 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9F7C
	adds r0, #4
	b _081A9F88
	.align 2, 0
_081A9F78: .4byte 0x030046A4
_081A9F7C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9F88:
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A9FAC
	adds r0, #4
	b _081A9FB8
_081A9FAC:
	ldr r2, _081A9FCC @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9FB8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9FD0
	cmp r2, #2
	beq _081A9FD4
	b _081A9FD8
	.align 2, 0
_081A9FCC: .4byte 0x030046A4
_081A9FD0:
	ldrb r0, [r4, #4]
	b _081A9FD6
_081A9FD4:
	ldrb r0, [r4]
_081A9FD6:
	subs r1, r1, r0
_081A9FD8:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _081AA020 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _081AA020 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AA024
	adds r0, #4
	b _081AA030
	.align 2, 0
_081AA020: .4byte 0x030046A4
_081AA024:
	ldr r3, _081AA05C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AA030:
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AA060
	adds r0, #4
	b _081AA06C
	.align 2, 0
_081AA05C: .4byte 0x030046A4
_081AA060:
	ldr r0, _081AA080 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AA06C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AA084
	cmp r2, #2
	beq _081AA088
	b _081AA08C
	.align 2, 0
_081AA080: .4byte 0x030046A4
_081AA084:
	ldrb r0, [r5, #4]
	b _081AA08A
_081AA088:
	ldrb r0, [r5]
_081AA08A:
	subs r1, r1, r0
_081AA08C:
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
	beq _081AA0AC
	b _081AA228
_081AA0AC:
	cmp r2, #0
	beq _081AA19A
	mov r0, sl
	cmp r0, #1
	bne _081AA0CE
	cmp r6, #1
	bne _081AA0C6
	mov r3, sb
	cmp r3, #1
	bne _081AA0E4
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA0F4
_081AA0C6:
	cmp r6, #3
	beq _081AA0CC
	b _081AA228
_081AA0CC:
	b _081AA0F0
_081AA0CE:
	mov r0, sl
	cmp r0, #2
	bne _081AA0FA
	cmp r6, #0
	bne _081AA0EA
	mov r3, sb
	cmp r3, #2
	bne _081AA0E4
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA0F4
_081AA0E4:
	cmp r1, #0
	beq _081AA0FA
	b _081AA228
_081AA0EA:
	cmp r6, #2
	beq _081AA0F0
	b _081AA228
_081AA0F0:
	mov r4, sb
	ldr r0, _081AA110 @ =0xFFFFFF00
_081AA0F4:
	cmp r1, r0
	beq _081AA0FA
	b _081AA228
_081AA0FA:
	mov r0, sb
	cmp r0, #1
	bne _081AA128
	cmp r6, #1
	bne _081AA11A
	mov r3, sl
	cmp r3, #1
	bne _081AA114
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
	.align 2, 0
_081AA110: .4byte 0xFFFFFF00
_081AA114:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA11A:
	cmp r6, #3
	beq _081AA120
	b _081AA228
_081AA120:
	mov r4, sl
	cmp r4, #1
	beq _081AA14E
	b _081AA15C
_081AA128:
	mov r0, sb
	cmp r0, #2
	bne _081AA16C
	cmp r6, #0
	bne _081AA144
	mov r3, sl
	cmp r3, #2
	bne _081AA13E
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA13E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA144:
	cmp r6, #2
	bne _081AA228
	mov r4, sl
	cmp r4, #2
	bne _081AA15C
_081AA14E:
	ldr r0, _081AA158 @ =0xFFFFFF00
_081AA150:
	cmp r1, r0
	beq _081AA160
	b _081AA228
	.align 2, 0
_081AA158: .4byte 0xFFFFFF00
_081AA15C:
	cmp r1, #0
	bne _081AA228
_081AA160:
	mov r0, sb
	cmp r0, #2
	bne _081AA16C
	mov r1, sl
	cmp r1, #2
	beq _081AA178
_081AA16C:
	mov r3, sb
	cmp r3, #1
	bne _081AA18A
	mov r4, sl
	cmp r4, #1
	bne _081AA18A
_081AA178:
	adds r1, r2, #0
	cmp r2, #0
	bge _081AA180
	rsbs r1, r2, #0
_081AA180:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _081AA19A
	b _081AA228
_081AA18A:
	adds r0, r2, #0
	cmp r0, #0
	bge _081AA192
	rsbs r0, r0, #0
_081AA192:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _081AA19C
_081AA19A:
	adds r5, r7, #0
_081AA19C:
	cmp r5, #0
	blt _081AA228
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _081AA1E0 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AA1E4
	adds r0, #4
	b _081AA1EE
	.align 2, 0
_081AA1E0: .4byte 0x030046A4
_081AA1E4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AA1EE:
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
	bl Salamander_AddRecentTile
	ldr r2, [sp, #0x24]
	ldr r3, _081AA220 @ =0x00000CB8
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_081AA212:
	strb r0, [r1]
	ldr r4, _081AA224 @ =0x00000CB4
	adds r1, r2, r4
_081AA218:
	movs r0, #0x28
	strh r0, [r1]
	b _081AA238
	.align 2, 0
_081AA220: .4byte 0x00000CB8
_081AA224: .4byte 0x00000CB4
_081AA228:
	ldr r1, [sp, #0x24]
	ldr r2, _081AA248 @ =0x00000CB9
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_081AA238:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA248: .4byte 0x00000CB9
