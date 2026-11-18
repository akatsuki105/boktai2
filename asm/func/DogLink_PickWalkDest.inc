	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _081C6DFC @ =0x00000256
	add r1, sb
	str r1, [sp, #0x14]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x1c]
	str r2, [sp, #0x18]
	ldr r0, _081C6E00 @ =0x030046A4
	mov sl, r0
_081C6DE8:
	ldr r1, [sp, #0x14]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C6E04
	adds r0, #4
	b _081C6E10
	.align 2, 0
_081C6DFC: .4byte 0x00000256
_081C6E00: .4byte 0x030046A4
_081C6E04:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C6E10:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C6E24
	cmp r3, #2
	beq _081C6E2A
	b _081C6E30
_081C6E24:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _081C6E2E
_081C6E2A:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_081C6E2E:
	subs r2, r2, r0
_081C6E30:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C6E42
	adds r0, #4
	b _081C6E4E
_081C6E42:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C6E4E:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081C6E60
	asrs r0, r0, #6
	b _081C6E66
_081C6E60:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081C6E66:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081C6EA4
	cmp r1, #1
	bgt _081C6E78
	cmp r1, #0
	beq _081C6E82
	b _081C6F58
_081C6E78:
	cmp r1, #2
	beq _081C6EE0
	cmp r1, #3
	beq _081C6F02
	b _081C6F58
_081C6E82:
	adds r4, r6, #1
	movs r5, #0
_081C6E86:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6EA0
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081C6E86
_081C6EA0:
	subs r5, r4, #1
	b _081C6F5C
_081C6EA4:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_081C6EB2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6F3C
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081C6EB2
	ldr r2, _081C6EDC @ =0x030046A4
	b _081C6F3E
	.align 2, 0
_081C6EDC: .4byte 0x030046A4
_081C6EE0:
	subs r4, r6, #1
	movs r5, #0
_081C6EE4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6EFE
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081C6EE4
_081C6EFE:
	adds r5, r4, #1
	b _081C6F5C
_081C6F02:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_081C6F10:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6F4A
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081C6F10
	ldr r2, _081C6F38 @ =0x030046A4
	b _081C6F4C
	.align 2, 0
_081C6F38: .4byte 0x030046A4
_081C6F3C:
	mov r2, sl
_081C6F3E:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _081C6F5C
_081C6F4A:
	mov r2, sl
_081C6F4C:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _081C6F5C
_081C6F58:
	ldr r2, [sp, #0x14]
	ldrh r5, [r2]
_081C6F5C:
	ldr r0, [sp, #0x14]
	ldrh r0, [r0]
	cmp r5, r0
	bne _081C6F98
	ldr r1, [sp, #0xc]
	ldr r2, _081C6F80 @ =0x000006D6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _081C6F84
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	b _081C6F8C
	.align 2, 0
_081C6F80: .4byte 0x000006D6
_081C6F84:
	mov r2, sb
	ldrb r0, [r2, #5]
	subs r0, #0x40
	strb r0, [r2, #5]
_081C6F8C:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _081C6F98
	b _081C6DE8
_081C6F98:
	ldr r2, _081C6FBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081C6FC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081C6FC4 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081C6FCC
	ldr r2, [sp, #0xc]
	ldr r0, _081C6FC8 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #1
	b _081C6FD4
	.align 2, 0
_081C6FBC: .4byte 0x030046B8
_081C6FC0: .4byte 0x000003FF
_081C6FC4: .4byte 0x0203B400
_081C6FC8: .4byte 0x000006D6
_081C6FCC:
	ldr r2, [sp, #0xc]
	ldr r0, _081C701C @ =0x000006D6
	adds r1, r2, r0
	movs r0, #0
_081C6FD4:
	strb r0, [r1]
	mov r1, sp
	ldrb r2, [r1, #8]
	mov r1, sb
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _081C7020 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C7024
	adds r0, #4
	b _081C702E
	.align 2, 0
_081C701C: .4byte 0x000006D6
_081C7020: .4byte 0x030046A4
_081C7024:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C702E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _081C7074 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081C7078
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C7078
	cmp r0, #2
	beq _081C7070
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C7070:
	movs r0, #1
	b _081C7088
	.align 2, 0
_081C7074: .4byte 0x000004A4
_081C7078:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _081C709C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C7088:
	cmp r0, #0
	beq _081C70A4
	ldr r2, [sp, #0xc]
	ldr r0, _081C70A0 @ =0x000006D7
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b _081C70B2
	.align 2, 0
_081C709C: .4byte 0xFFFFFDFF
_081C70A0: .4byte 0x000006D7
_081C70A4:
	ldr r0, _081C70C4 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_081C70B2:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C70C4: .4byte 0x000005C4
