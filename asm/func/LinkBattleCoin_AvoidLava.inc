	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldrh r0, [r0, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0EF2
	cmp r1, #0
	blt _081E0EF2
	ldr r0, _081E0EF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0EF2
	ldr r0, _081E0EFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0F00
_081E0EF2:
	movs r6, #0
	b _081E0F0E
	.align 2, 0
_081E0EF8: .4byte 0x030046A8
_081E0EFC: .4byte 0x030046AC
_081E0F00:
	ldr r0, _081E0F34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0F0E:
	ldr r0, _081E0F38 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081E0F3C @ =0x00000934
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081E0F22
	b _081E10AA
_081E0F22:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0F60
	adds r0, #4
	b _081E0F6C
	.align 2, 0
_081E0F34: .4byte 0x030046A4
_081E0F38: .4byte 0x030046A0
_081E0F3C: .4byte 0x00000934
_081E0F40:
	ldr r4, _081E0F5C @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	ldr r0, [r4]
	b _081E1056
	.align 2, 0
_081E0F5C: .4byte 0x030046A4
_081E0F60:
	ldr r0, _081E0F90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0F6C:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081E0F78
	b _081E10AA
_081E0F78:
	movs r7, #0
	ldr r2, _081E0F90 @ =0x030046A4
	mov sb, r2
	mov sl, r1
_081E0F80:
	cmp r7, #1
	beq _081E0FCE
	cmp r7, #1
	bgt _081E0F94
	cmp r7, #0
	beq _081E0F9E
	b _081E10A2
	.align 2, 0
_081E0F90: .4byte 0x030046A4
_081E0F94:
	cmp r7, #2
	beq _081E1012
	cmp r7, #3
	beq _081E106A
	b _081E10A2
_081E0F9E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0FB0
	adds r0, #4
	b _081E0FBC
_081E0FB0:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FBC:
	ldrh r0, [r0, #2]
	mov r2, sl
	ands r0, r2
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r1, sb
	ldr r0, [r1]
	b _081E1040
_081E0FCE:
	ldr r5, _081E0FEC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0FF0
	adds r0, #4
	b _081E0FFA
	.align 2, 0
_081E0FEC: .4byte 0x030046A4
_081E0FF0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FFA:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E1046
_081E1012:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E1024
	adds r0, #4
	b _081E1030
_081E1024:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1030:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r2, sb
	ldr r0, [r2]
_081E1040:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E1046:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	mov r2, sb
	ldr r0, [r2]
_081E1056:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x14]
	b _081E10AA
_081E106A:
	ldr r5, _081E1088 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E108C
	adds r0, #4
	b _081E1096
	.align 2, 0
_081E1088: .4byte 0x030046A4
_081E108C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1096:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	b _081E0F40
_081E10A2:
	adds r7, #1
	cmp r7, #3
	bgt _081E10AA
	b _081E0F80
_081E10AA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
