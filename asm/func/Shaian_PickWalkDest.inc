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
	ldr r1, _0817C0D0 @ =0x00000256
	add r1, sb
	str r1, [sp, #0x10]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
	ldr r0, _0817C0D4 @ =0x030046A4
	mov sl, r0
_0817C0BA:
	ldr r1, [sp, #0x10]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817C0D8
	adds r0, #4
	b _0817C0E4
	.align 2, 0
_0817C0D0: .4byte 0x00000256
_0817C0D4: .4byte 0x030046A4
_0817C0D8:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C0E4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817C0F8
	cmp r3, #2
	beq _0817C0FE
	b _0817C104
_0817C0F8:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _0817C102
_0817C0FE:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_0817C102:
	subs r2, r2, r0
_0817C104:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817C116
	adds r0, #4
	b _0817C122
_0817C116:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C122:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817C134
	asrs r0, r0, #6
	b _0817C13A
_0817C134:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817C13A:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817C178
	cmp r1, #1
	bgt _0817C14C
	cmp r1, #0
	beq _0817C156
	b _0817C22C
_0817C14C:
	cmp r1, #2
	beq _0817C1B4
	cmp r1, #3
	beq _0817C1D6
	b _0817C22C
_0817C156:
	adds r4, r6, #1
	movs r5, #0
_0817C15A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C174
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0817C15A
_0817C174:
	subs r5, r4, #1
	b _0817C230
_0817C178:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_0817C186:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C210
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0817C186
	ldr r2, _0817C1B0 @ =0x030046A4
	b _0817C212
	.align 2, 0
_0817C1B0: .4byte 0x030046A4
_0817C1B4:
	subs r4, r6, #1
	movs r5, #0
_0817C1B8:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C1D2
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0817C1B8
_0817C1D2:
	adds r5, r4, #1
	b _0817C230
_0817C1D6:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_0817C1E4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C21E
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0817C1E4
	ldr r2, _0817C20C @ =0x030046A4
	b _0817C220
	.align 2, 0
_0817C20C: .4byte 0x030046A4
_0817C210:
	mov r2, sl
_0817C212:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0817C230
_0817C21E:
	mov r2, sl
_0817C220:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _0817C230
_0817C22C:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_0817C230:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0817C24C
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _0817C24C
	b _0817C0BA
_0817C24C:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sb
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _0817C290 @ =0x030046A4
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
	beq _0817C294
	adds r0, #4
	b _0817C29E
	.align 2, 0
_0817C290: .4byte 0x030046A4
_0817C294:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C29E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _0817C2E4 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _0817C2E8
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0817C2E8
	cmp r0, #2
	beq _0817C2E0
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0817C2E0:
	movs r0, #1
	b _0817C2F8
	.align 2, 0
_0817C2E4: .4byte 0x000004A4
_0817C2E8:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _0817C300 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0817C2F8:
	cmp r0, #0
	beq _0817C304
	movs r0, #1
	b _0817C312
	.align 2, 0
_0817C300: .4byte 0xFFFFFDFF
_0817C304:
	ldr r0, _0817C324 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_0817C312:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0817C324: .4byte 0x000005C4
