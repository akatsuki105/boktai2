	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #6
	lsls r0, r0, #6
	str r0, [sp, #0x14]
	add r4, sp, #4
	adds r3, r7, #0
	adds r3, #8
	ldr r2, _0817CEF4 @ =0x000004A4
	adds r0, r7, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r0, #0x20
	ands r0, r5
	asrs r0, r0, #6
	lsls r1, r0, #6
	strb r1, [r7, #5]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r0, #3
	ldr r3, [sp, #0x18]
	ands r3, r0
	str r3, [sp, #0x18]
	movs r1, #0
	mov r0, sp
	adds r0, #3
_0817CEBE:
	strb r1, [r0]
	subs r0, #1
	cmp r0, sp
	bge _0817CEBE
	movs r5, #0
	str r5, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #8
	str r0, [sp, #0x1c]
	ldr r1, _0817CEF8 @ =0x00000256
	adds r1, r7, r1
	str r1, [sp, #0x20]
_0817CED6:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r3, _0817CEFC @ =0x00000898
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817CF00
	movs r0, #1
	b _0817CF02
	.align 2, 0
_0817CEF4: .4byte 0x000004A4
_0817CEF8: .4byte 0x00000256
_0817CEFC: .4byte 0x00000898
_0817CF00:
	movs r0, #0
_0817CF02:
	cmp r0, #0
	beq _0817CF28
	adds r0, r7, #0
	ldr r5, [sp, #0xc]
	ldr r2, _0817CF24 @ =0x00000854
	adds r1, r5, r2
	bl FUN_0817eb28
	lsls r0, r0, #0x18
	movs r3, #2
	mov sl, r3
	cmp r0, #0
	beq _0817CF2C
	movs r5, #1
	mov sl, r5
	b _0817CF2C
	.align 2, 0
_0817CF24: .4byte 0x00000854
_0817CF28:
	movs r0, #2
	mov sl, r0
_0817CF2C:
	ldr r1, [sp, #0x20]
	ldrh r6, [r1]
	ldr r4, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817CF42
	adds r0, #4
	b _0817CF4E
_0817CF42:
	ldr r2, _0817CF64 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CF4E:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817CF68
	cmp r3, #2
	beq _0817CF6C
	b _0817CF70
	.align 2, 0
_0817CF64: .4byte 0x030046A4
_0817CF68:
	ldrb r0, [r4, #4]
	b _0817CF6E
_0817CF6C:
	ldrb r0, [r4]
_0817CF6E:
	subs r2, r2, r0
_0817CF70:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817CF82
	adds r0, #4
	b _0817CF8E
_0817CF82:
	ldr r3, _0817CFA0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CF8E:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	ldrb r0, [r7, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817CFA4
	asrs r0, r0, #6
	b _0817CFAA
	.align 2, 0
_0817CFA0: .4byte 0x030046A4
_0817CFA4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817CFAA:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817CFEA
	cmp r1, #1
	bgt _0817CFBC
	cmp r1, #0
	beq _0817CFC6
	b _0817D0C4
_0817CFBC:
	cmp r1, #2
	beq _0817D034
	cmp r1, #3
	beq _0817D058
	b _0817D0C4
_0817CFC6:
	adds r4, r6, #1
	movs r5, #0
	cmp r5, sl
	bge _0817D094
_0817CFCE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D094
	adds r4, #1
	adds r5, #1
	cmp r5, sl
	blt _0817CFCE
	b _0817D094
_0817CFEA:
	ldr r5, _0817D030 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	cmp r5, sl
	bge _0817D020
_0817CFFC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D098
	ldr r2, _0817D030 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, sl
	blt _0817CFFC
_0817D020:
	ldr r5, _0817D030 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D030: .4byte 0x030046A4
_0817D034:
	subs r4, r6, #1
	movs r5, #0
	cmp r5, sl
	bge _0817D0AC
_0817D03C:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D0AC
	subs r4, #1
	adds r5, #1
	cmp r5, sl
	blt _0817D03C
	b _0817D0AC
_0817D058:
	ldr r2, _0817D090 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r6, r0
	movs r5, #0
	cmp r5, sl
	bge _0817D0B0
_0817D06A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D0B0
	ldr r1, _0817D090 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, sl
	blt _0817D06A
	b _0817D0B0
	.align 2, 0
_0817D090: .4byte 0x030046A4
_0817D094:
	subs r5, r4, #1
	b _0817D0C8
_0817D098:
	ldr r1, _0817D0A8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D0A8: .4byte 0x030046A4
_0817D0AC:
	adds r5, r4, #1
	b _0817D0C8
_0817D0B0:
	ldr r3, _0817D0C0 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D0C0: .4byte 0x030046A4
_0817D0C4:
	ldr r0, [sp, #0x20]
	ldrh r5, [r0]
_0817D0C8:
	ldr r1, _0817D110 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0817D19C
	add r2, sp, #4
	mov sb, r2
	ldr r6, _0817D114 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #4
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817D118
	adds r0, #4
	b _0817D122
	.align 2, 0
_0817D110: .4byte 0x00000256
_0817D114: .4byte 0x030046A4
_0817D118:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817D122:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r1, _0817D154 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	add r2, sp, #4
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0817D158
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	b _0817D17C
	.align 2, 0
_0817D154: .4byte 0x000004A4
_0817D158:
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	add r2, sp, #4
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0817D176
	cmp r0, #2
	beq _0817D184
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0817D184
_0817D176:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
_0817D17C:
	ldrh r1, [r2]
	ldr r0, _0817D194 @ =0xFFFFFDFF
	ands r0, r1
	strh r0, [r2]
_0817D184:
	ldr r1, _0817D198 @ =0x000004A4
	adds r0, r7, r1
	ldr r2, [r0]
	ldr r0, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0817D1F4
	.align 2, 0
_0817D194: .4byte 0xFFFFFDFF
_0817D198: .4byte 0x000004A4
_0817D19C:
	ldrb r0, [r7, #5]
	lsrs r0, r0, #6
	mov r2, sp
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0817D1C6
	ldr r5, [sp, #0x14]
	cmp r0, r5
	beq _0817D1C6
	strb r5, [r7, #5]
	b _0817D1E8
_0817D1BA:
	movs r1, #0x40
	lsls r1, r2
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r7, #5]
	b _0817D1E2
_0817D1C6:
	adds r4, r0, #0
	movs r1, #0
	movs r3, #3
_0817D1CC:
	ldr r0, [sp, #0x18]
	adds r2, r0, r1
	ands r2, r3
	mov r5, sp
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0817D1BA
	adds r1, #1
	cmp r1, #3
	ble _0817D1CC
_0817D1E2:
	ldrb r0, [r7, #5]
	cmp r4, r0
	beq _0817D1F4
_0817D1E8:
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	cmp r1, #3
	bgt _0817D1F4
	b _0817CED6
_0817D1F4:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
