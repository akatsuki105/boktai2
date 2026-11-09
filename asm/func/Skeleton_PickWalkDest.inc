	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08105B5C @ =0x00000256
	add r1, sb
	str r1, [sp, #0x10]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
	ldr r0, _08105B60 @ =0x030046A4
	mov sl, r0
_08105B46:
	ldr r1, [sp, #0x10]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105B64
	adds r0, #4
	b _08105B70
	.align 2, 0
_08105B5C: .4byte 0x00000256
_08105B60: .4byte 0x030046A4
_08105B64:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105B70:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08105B84
	cmp r3, #2
	beq _08105B8A
	b _08105B90
_08105B84:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _08105B8E
_08105B8A:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_08105B8E:
	subs r2, r2, r0
_08105B90:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105BA2
	adds r0, #4
	b _08105BAE
_08105BA2:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105BAE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _08105BC0
	asrs r0, r0, #6
	b _08105BC6
_08105BC0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08105BC6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08105C04
	cmp r1, #1
	bgt _08105BD8
	cmp r1, #0
	beq _08105BE2
	b _08105CB8
_08105BD8:
	cmp r1, #2
	beq _08105C40
	cmp r1, #3
	beq _08105C62
	b _08105CB8
_08105BE2:
	adds r4, r6, #1
	movs r5, #0
_08105BE6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C00
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _08105BE6
_08105C00:
	subs r5, r4, #1
	b _08105CBC
_08105C04:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_08105C12:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C9C
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _08105C12
	ldr r2, _08105C3C @ =0x030046A4
	b _08105C9E
	.align 2, 0
_08105C3C: .4byte 0x030046A4
_08105C40:
	subs r4, r6, #1
	movs r5, #0
_08105C44:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C5E
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _08105C44
_08105C5E:
	adds r5, r4, #1
	b _08105CBC
_08105C62:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_08105C70:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105CAA
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _08105C70
	ldr r2, _08105C98 @ =0x030046A4
	b _08105CAC
	.align 2, 0
_08105C98: .4byte 0x030046A4
_08105C9C:
	mov r2, sl
_08105C9E:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _08105CBC
_08105CAA:
	mov r2, sl
_08105CAC:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08105CBC
_08105CB8:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_08105CBC:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _08105CD8
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _08105CD8
	b _08105B46
_08105CD8:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sb
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _08105D1C @ =0x030046A4
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
	beq _08105D20
	adds r0, #4
	b _08105D2A
	.align 2, 0
_08105D1C: .4byte 0x030046A4
_08105D20:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105D2A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _08105D70 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _08105D74
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08105D74
	cmp r0, #2
	beq _08105D6C
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08105D6C:
	movs r0, #1
	b _08105D84
	.align 2, 0
_08105D70: .4byte 0x000004A4
_08105D74:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _08105D8C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08105D84:
	cmp r0, #0
	beq _08105D90
	movs r0, #1
	b _08105D9E
	.align 2, 0
_08105D8C: .4byte 0xFFFFFDFF
_08105D90:
	ldr r0, _08105DB0 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_08105D9E:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08105DB0: .4byte 0x000005C4
