	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08105E04 @ =0x00000256
	add r1, sl
	str r1, [sp, #0x10]
	mov r2, sl
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
_08105DD6:
	ldr r2, _08105E08 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08105E0C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08105E10 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r7, r0, #1
	ldr r2, [sp, #0x10]
	ldrh r6, [r2]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105E14
	adds r0, #4
	b _08105E20
	.align 2, 0
_08105E04: .4byte 0x00000256
_08105E08: .4byte 0x030046B8
_08105E0C: .4byte 0x000003FF
_08105E10: .4byte 0x0203B400
_08105E14:
	ldr r1, _08105E34 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105E20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08105E38
	cmp r3, #2
	beq _08105E3E
	b _08105E44
	.align 2, 0
_08105E34: .4byte 0x030046A4
_08105E38:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _08105E42
_08105E3E:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_08105E42:
	subs r2, r2, r0
_08105E44:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105E56
	adds r0, #4
	b _08105E62
_08105E56:
	ldr r2, _08105E78 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105E62:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _08105E7C
	asrs r0, r0, #6
	b _08105E82
	.align 2, 0
_08105E78: .4byte 0x030046A4
_08105E7C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08105E82:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08105EC2
	cmp r1, #1
	bgt _08105E94
	cmp r1, #0
	beq _08105E9E
	b _08105F90
_08105E94:
	cmp r1, #2
	beq _08105F00
	cmp r1, #3
	beq _08105F24
	b _08105F90
_08105E9E:
	adds r4, r6, #1
	movs r5, #0
	cmp r5, r7
	bge _08105F60
_08105EA6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F60
	adds r4, #1
	adds r5, #1
	cmp r5, r7
	blt _08105EA6
	b _08105F60
_08105EC2:
	ldr r2, _08105EFC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	cmp r5, r7
	bge _08105F64
_08105ED4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F64
	ldr r2, _08105EFC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _08105ED4
	b _08105F64
	.align 2, 0
_08105EFC: .4byte 0x030046A4
_08105F00:
	subs r4, r6, #1
	movs r5, #0
	cmp r5, r7
	bge _08105F78
_08105F08:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F78
	subs r4, #1
	adds r5, #1
	cmp r5, r7
	blt _08105F08
	b _08105F78
_08105F24:
	ldr r2, _08105F5C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
	cmp r5, r7
	bge _08105F7C
_08105F36:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F7C
	ldr r2, _08105F5C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _08105F36
	b _08105F7C
	.align 2, 0
_08105F5C: .4byte 0x030046A4
_08105F60:
	subs r5, r4, #1
	b _08105F94
_08105F64:
	ldr r2, _08105F74 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _08105F94
	.align 2, 0
_08105F74: .4byte 0x030046A4
_08105F78:
	adds r5, r4, #1
	b _08105F94
_08105F7C:
	ldr r2, _08105F8C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08105F94
	.align 2, 0
_08105F8C: .4byte 0x030046A4
_08105F90:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_08105F94:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _08105FB0
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _08105FB0
	b _08105DD6
_08105FB0:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sl
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _08105FF4 @ =0x030046A4
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
	beq _08105FF8
	adds r0, #4
	b _08106002
	.align 2, 0
_08105FF4: .4byte 0x030046A4
_08105FF8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08106002:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _08106048 @ =0x000004A4
	add r0, sl
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _0810604C
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810604C
	cmp r0, #2
	beq _08106044
	mov r0, sl
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08106044:
	movs r0, #1
	b _0810605C
	.align 2, 0
_08106048: .4byte 0x000004A4
_0810604C:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sl
	ldr r1, _08106064 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810605C:
	cmp r0, #0
	beq _08106068
	movs r0, #1
	b _08106076
	.align 2, 0
_08106064: .4byte 0xFFFFFDFF
_08106068:
	ldr r0, _08106088 @ =0x000005C4
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	movs r0, #0
_08106076:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08106088: .4byte 0x000005C4
