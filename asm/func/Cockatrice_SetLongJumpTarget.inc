	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08161928 @ =0x00000256
	add r0, sb
	ldrh r6, [r0]
	mov r4, sb
	adds r4, #8
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816192C
	adds r0, #4
	b _08161938
	.align 2, 0
_08161928: .4byte 0x00000256
_0816192C:
	ldr r0, _0816194C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161938:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08161950
	cmp r3, #2
	beq _08161954
	b _08161958
	.align 2, 0
_0816194C: .4byte 0x030046A4
_08161950:
	ldrb r0, [r4, #4]
	b _08161956
_08161954:
	ldrb r0, [r4]
_08161956:
	subs r2, r2, r0
_08161958:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816196A
	adds r0, #4
	b _08161976
_0816196A:
	ldr r0, _08161988 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161976:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0816198C
	asrs r0, r0, #6
	b _08161992
	.align 2, 0
_08161988: .4byte 0x030046A4
_0816198C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08161992:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081619D0
	cmp r1, #1
	bgt _081619A4
	cmp r1, #0
	beq _081619AE
	b _08161A90
_081619A4:
	cmp r1, #2
	beq _08161A0C
	cmp r1, #3
	beq _08161A2E
	b _08161A90
_081619AE:
	adds r4, r6, #1
	movs r5, #0
_081619B2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081619CC
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _081619B2
_081619CC:
	subs r5, r4, #1
	b _08161A96
_081619D0:
	ldr r1, _08161A08 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_081619DE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A68
	ldr r0, _08161A08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _081619DE
	subs r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A08: .4byte 0x030046A4
_08161A0C:
	subs r4, r6, #1
	movs r5, #0
_08161A10:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A2A
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08161A10
_08161A2A:
	adds r5, r4, #1
	b _08161A96
_08161A2E:
	ldr r1, _08161A64 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
_08161A3C:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A7C
	ldr r0, _08161A64 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08161A3C
	adds r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A64: .4byte 0x030046A4
_08161A68:
	ldr r1, _08161A78 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A78: .4byte 0x030046A4
_08161A7C:
	ldr r1, _08161A8C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A8C: .4byte 0x030046A4
_08161A90:
	ldr r0, _08161AE0 @ =0x00000256
	add r0, sb
	ldrh r5, [r0]
_08161A96:
	ldr r0, _08161AE0 @ =0x00000256
	add r0, sb
	ldrh r0, [r0]
	cmp r5, r0
	bne _08161B1C
	movs r6, #0xd6
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _08161AE4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08161AE4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08161AE8
	adds r0, #4
	b _08161AF4
	.align 2, 0
_08161AE0: .4byte 0x00000256
_08161AE4: .4byte 0x030046A4
_08161AE8:
	ldr r1, _08161B14 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08161AF4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r0, _08161B18 @ =0x000006E2
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08161B7C
	movs r0, #0
	b _08161B7E
	.align 2, 0
_08161B14: .4byte 0x030046A4
_08161B18: .4byte 0x000006E2
_08161B1C:
	movs r6, #0xd6
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _08161B5C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08161B5C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08161B60
	adds r0, #4
	b _08161B6C
	.align 2, 0
_08161B5C: .4byte 0x030046A4
_08161B60:
	ldr r1, _08161B8C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08161B6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
_08161B7C:
	movs r0, #1
_08161B7E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08161B8C: .4byte 0x030046A4
