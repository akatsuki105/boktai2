	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08157E20 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08157E24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08157E26
	.align 2, 0
_08157E20: .4byte 0x0000046C
_08157E24:
	movs r0, #0
_08157E26:
	cmp r0, #0
	bne _08157E2C
	b _0815814C
_08157E2C:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r3, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r2
	cmp r3, #0
	blt _08157E6E
	cmp r1, #0
	blt _08157E6E
	ldr r0, _08157E74 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08157E6E
	ldr r0, _08157E78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157E7C
_08157E6E:
	movs r4, #0
	b _08157E8A
	.align 2, 0
_08157E74: .4byte 0x030046A8
_08157E78: .4byte 0x030046AC
_08157E7C:
	ldr r0, _08157E9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_08157E8A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08157EA0
	adds r0, #4
	b _08157EAC
	.align 2, 0
_08157E9C: .4byte 0x030046A4
_08157EA0:
	ldr r0, _08157EC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157EAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157EC4
	cmp r2, #2
	beq _08157EC8
	b _08157ECC
	.align 2, 0
_08157EC0: .4byte 0x030046A4
_08157EC4:
	ldrb r0, [r6, #4]
	b _08157ECA
_08157EC8:
	ldrb r0, [r6]
_08157ECA:
	subs r1, r1, r0
_08157ECC:
	strh r1, [r6, #2]
	ldr r6, _08157EFC @ =0x000004A4
	adds r0, r5, r6
	ldr r7, [r0]
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r6, r0, #0
	adds r6, #8
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	mov r8, r4
	cmp r0, #0
	bne _08157F00
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08157F26
	.align 2, 0
_08157EFC: .4byte 0x000004A4
_08157F00:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08157F20
	cmp r0, #2
	beq _08157F1C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157F1C:
	movs r0, #1
	b _08157F30
_08157F20:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08157F26:
	ldr r1, _08157F6C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08157F30:
	cmp r0, #0
	beq _08157F36
	b _0815810C
_08157F36:
	mov r6, sp
	mov r0, sb
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08157F68
	cmp r1, #0
	blt _08157F68
	ldr r0, _08157F70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157F68
	ldr r0, _08157F74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157F78
_08157F68:
	movs r4, #0
	b _08157F86
	.align 2, 0
_08157F6C: .4byte 0xFFFFFDFF
_08157F70: .4byte 0x030046A8
_08157F74: .4byte 0x030046AC
_08157F78:
	ldr r0, _08157F98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08157F86:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08157F9C
	adds r0, #4
	b _08157FA8
	.align 2, 0
_08157F98: .4byte 0x030046A4
_08157F9C:
	ldr r0, _08157FBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157FA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157FC0
	cmp r2, #2
	beq _08157FC4
	b _08157FC8
	.align 2, 0
_08157FBC: .4byte 0x030046A4
_08157FC0:
	ldrb r0, [r6, #4]
	b _08157FC6
_08157FC4:
	ldrb r0, [r6]
_08157FC6:
	subs r1, r1, r0
_08157FC8:
	strh r1, [r6, #2]
	ldr r1, _08157FE8 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08157FEC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08158010
	.align 2, 0
_08157FE8: .4byte 0x000004A4
_08157FEC:
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815800A
	cmp r0, #2
	beq _08158018
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08158018
_0815800A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08158010:
	ldr r1, _0815802C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08158018:
	movs r1, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08158030
	movs r0, #1
	b _08158032
	.align 2, 0
_0815802C: .4byte 0xFFFFFDFF
_08158030:
	movs r0, #0
_08158032:
	adds r4, r0, #0
	cmp r4, #0
	beq _081580A0
	adds r0, r5, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	ldr r3, _08158090 @ =Cockatrice_StateFly
	movs r1, #0x23
	ldr r6, _08158094 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xf
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08158098 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0815809C @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _08158156
	.align 2, 0
_08158090: .4byte Cockatrice_StateFly
_08158094: .4byte 0x0000046D
_08158098: .4byte 0x0000046A
_0815809C: .4byte 0x00000484
_081580A0:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _081580FC @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _08158100 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08158104 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08158108 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	b _08158156
	.align 2, 0
_081580FC: .4byte 0x0000046D
_08158100: .4byte 0x0000046B
_08158104: .4byte 0x0000046A
_08158108: .4byte 0x00000484
_0815810C:
	ldr r1, _08158168 @ =0x000001DF
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
	adds r0, r5, #0
	bl Cockatrice_PauseBeforeMove
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	movs r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	strh r3, [r0, #6]
_0815814C:
	ldr r2, _0815816C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158156:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158168: .4byte 0x000001DF
_0815816C: .4byte 0x00000484
