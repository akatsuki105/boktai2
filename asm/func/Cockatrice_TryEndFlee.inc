	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161BD2
	b _08161E94
_08161BD2:
	movs r2, #0x20
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _08161BE8
	movs r0, #1
	b _08161BEA
_08161BE8:
	movs r0, #0
_08161BEA:
	cmp r0, #0
	bne _08161BF0
	b _08161E94
_08161BF0:
	ldr r2, _08161CF8 @ =0x0000B007
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08161C04
	b _08161E94
_08161C04:
	ldr r1, _08161CFC @ =0x000006DC
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08161C12
	b _08161E94
_08161C12:
	ldr r3, _08161D00 @ =0x000001DF
	adds r0, r5, r3
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	adds r0, r5, #0
	bl Cockatrice_ResetChaseState
	movs r2, #0x10
	subs r6, #8
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #2
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08161D04 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	ldr r4, _08161D08 @ =Enemy_WaitPendingState
	movs r1, #0xe
	subs r3, #0xe4
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	subs r6, #0xe7
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r4, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08161D0C @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08161D10 @ =0x0000046C
	adds r0, r5, r2
	strb r3, [r0]
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
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
	blt _08161CF4
	cmp r1, #0
	blt _08161CF4
	ldr r0, _08161D14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08161CF4
	ldr r0, _08161D18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08161D1C
_08161CF4:
	movs r4, #0
	b _08161D2A
	.align 2, 0
_08161CF8: .4byte 0x0000B007
_08161CFC: .4byte 0x000006DC
_08161D00: .4byte 0x000001DF
_08161D04: .4byte 0x00000551
_08161D08: .4byte Enemy_WaitPendingState
_08161D0C: .4byte 0x00000469
_08161D10: .4byte 0x0000046C
_08161D14: .4byte 0x030046A8
_08161D18: .4byte 0x030046AC
_08161D1C:
	ldr r0, _08161D3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08161D2A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08161D40
	adds r0, #4
	b _08161D4C
	.align 2, 0
_08161D3C: .4byte 0x030046A4
_08161D40:
	ldr r0, _08161D60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161D4C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08161D64
	cmp r2, #2
	beq _08161D68
	b _08161D6C
	.align 2, 0
_08161D60: .4byte 0x030046A4
_08161D64:
	ldrb r0, [r6, #4]
	b _08161D6A
_08161D68:
	ldrb r0, [r6]
_08161D6A:
	subs r1, r1, r0
_08161D6C:
	strh r1, [r6, #2]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08161D96
	cmp r1, #0
	blt _08161D96
	ldr r0, _08161D9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08161D96
	ldr r0, _08161DA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08161DA4
_08161D96:
	movs r4, #0
	b _08161DB2
	.align 2, 0
_08161D9C: .4byte 0x030046A8
_08161DA0: .4byte 0x030046AC
_08161DA4:
	ldr r0, _08161DC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08161DB2:
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r7, r6, #0
	cmp r0, #0
	beq _08161DCC
	adds r0, #4
	b _08161DD8
	.align 2, 0
_08161DC8: .4byte 0x030046A4
_08161DCC:
	ldr r0, _08161DEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161DD8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08161DF0
	cmp r2, #2
	beq _08161DF4
	b _08161DF8
	.align 2, 0
_08161DEC: .4byte 0x030046A4
_08161DF0:
	ldrb r0, [r6, #4]
	b _08161DF6
_08161DF4:
	ldrb r0, [r6]
_08161DF6:
	subs r1, r1, r0
_08161DF8:
	mov r0, sp
	strh r1, [r0, #2]
	ldr r3, _08161E1C @ =0x000004A4
	adds r0, r5, r3
	ldr r4, [r0]
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08161E24
	ldr r0, _08161E20 @ =0xFFFFFDFF
	mov r6, r8
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08161E4C
	.align 2, 0
_08161E1C: .4byte 0x000004A4
_08161E20: .4byte 0xFFFFFDFF
_08161E24:
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08161E42
	cmp r0, #2
	beq _08161E4C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08161E4C
_08161E42:
	ldr r0, _08161E68 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08161E4C:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	movs r1, #0x20
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08161E6C
	movs r0, #1
	b _08161E6E
	.align 2, 0
_08161E68: .4byte 0xFFFFFDFF
_08161E6C:
	movs r0, #0
_08161E6E:
	cmp r0, #0
	beq _08161E94
	movs r1, #0x21
	rsbs r1, r1, #0
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	adds r1, #0x1c
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _08161EA4 @ =0x00000482
	adds r1, r5, r6
	movs r0, #1
	strh r0, [r1]
_08161E94:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08161EA4: .4byte 0x00000482
