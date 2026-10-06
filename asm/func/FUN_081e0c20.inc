	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r7, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0C4E
	cmp r1, #0
	blt _081E0C4E
	ldr r0, _081E0C54 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0C4E
	ldr r0, _081E0C58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0C5C
_081E0C4E:
	movs r6, #0
	b _081E0C6A
	.align 2, 0
_081E0C54: .4byte 0x030046A8
_081E0C58: .4byte 0x030046AC
_081E0C5C:
	ldr r0, _081E0C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0C6A:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0C80
	adds r0, #4
	b _081E0C8C
	.align 2, 0
_081E0C7C: .4byte 0x030046A4
_081E0C80:
	ldr r0, _081E0CA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0C8C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0CE4
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0CCC
	adds r0, #4
	b _081E0CD8
	.align 2, 0
_081E0CA8: .4byte 0x030046A4
_081E0CAC:
	ldr r4, _081E0CC8 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	ldr r0, [r4]
	b _081E0E2A
	.align 2, 0
_081E0CC8: .4byte 0x030046A4
_081E0CCC:
	ldr r0, _081E0CFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0CD8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0CE4
	b _081E0EB2
_081E0CE4:
	movs r0, #0
	mov sb, r0
	ldr r1, _081E0CFC @ =0x030046A4
	mov r8, r1
_081E0CEC:
	mov r2, sb
	cmp r2, #1
	beq _081E0D46
	cmp r2, #1
	bgt _081E0D00
	cmp r2, #0
	beq _081E0D0E
	b _081E0EA6
	.align 2, 0
_081E0CFC: .4byte 0x030046A4
_081E0D00:
	mov r0, sb
	cmp r0, #2
	beq _081E0DC2
	cmp r0, #3
	bne _081E0D0C
	b _081E0E3C
_081E0D0C:
	b _081E0EA6
_081E0D0E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0D20
	adds r0, #4
	b _081E0D2C
_081E0D20:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D2C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D38
	b _081E0EA6
_081E0D38:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _081E0DF6
	b _081E0DFA
_081E0D46:
	ldr r5, _081E0D64 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0D68
	adds r0, #4
	b _081E0D72
	.align 2, 0
_081E0D64: .4byte 0x030046A4
_081E0D68:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D72:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D7E
	b _081E0EA6
_081E0D7E:
	ldr r5, _081E0D9C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0DA0
	adds r0, #4
	b _081E0DAA
	.align 2, 0
_081E0D9C: .4byte 0x030046A4
_081E0DA0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E0E1C
_081E0DC2:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0DD4
	adds r0, #4
	b _081E0DE0
_081E0DD4:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DE0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0DFA
_081E0DF6:
	adds r0, #4
	b _081E0E06
_081E0DFA:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E06:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	adds r6, r4, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E0E1C:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	mov r1, r8
	ldr r0, [r1]
_081E0E2A:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	strh r0, [r7, #0x14]
	b _081E0EB2
_081E0E3C:
	ldr r5, _081E0E58 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0E5C
	adds r0, #4
	b _081E0E66
	.align 2, 0
_081E0E58: .4byte 0x030046A4
_081E0E5C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E66:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	ldr r5, _081E0E8C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E0E90
	adds r0, #4
	b _081E0E9A
	.align 2, 0
_081E0E8C: .4byte 0x030046A4
_081E0E90:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E9A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	b _081E0CAC
_081E0EA6:
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	bgt _081E0EB2
	b _081E0CEC
_081E0EB2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
