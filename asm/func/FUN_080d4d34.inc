	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _080D4D96
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0x29
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4]
	cmp r0, #5
	bne _080D4D7C
	ldr r0, [r5, #0x18]
	ldr r1, _080D4D78 @ =0x000002EB
	bl Sound_PlayForPlayer
	b _080D4D84
	.align 2, 0
_080D4D78: .4byte 0x000002EB
_080D4D7C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl Sound_PlayForPlayer
_080D4D84:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #0
	bl PlayerLink_SetAction
_080D4D96:
	ldr r1, _080D4DAC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D4DA2
	b _080D4EF8
_080D4DA2:
	cmp r0, #1
	bgt _080D4DB0
	cmp r0, #0
	beq _080D4DBE
	b _080D4F98
	.align 2, 0
_080D4DAC: .4byte 0x0000037D
_080D4DB0:
	cmp r0, #2
	bne _080D4DB6
	b _080D4F46
_080D4DB6:
	cmp r0, #3
	bne _080D4DBC
	b _080D4F68
_080D4DBC:
	b _080D4F98
_080D4DBE:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4DF4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4DF8
	asrs r0, r0, #0xc
	b _080D4DFE
	.align 2, 0
_080D4DF4: .4byte gSineTable
_080D4DF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4DFE:
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4E1A
	asrs r0, r0, #0xc
	b _080D4E20
_080D4E1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4E20:
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4E90 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D4E8A
	cmp r1, #0
	blt _080D4E8A
	ldr r0, _080D4E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D4E8A
	ldr r0, _080D4E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D4E9C
_080D4E8A:
	movs r4, #0
	b _080D4EAA
	.align 2, 0
_080D4E90: .4byte 0xFFFF0000
_080D4E94: .4byte 0x030046A8
_080D4E98: .4byte 0x030046AC
_080D4E9C:
	ldr r0, _080D4EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D4EAA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D4EC0
	adds r0, #4
	b _080D4ECC
	.align 2, 0
_080D4EBC: .4byte 0x030046A4
_080D4EC0:
	ldr r0, _080D4EF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D4ECC:
	ldrh r0, [r0, #2]
	bl PlayerLink_IsFrozenLava
	cmp r0, #0
	beq _080D4EDC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D4EDC:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D4F98
	.align 2, 0
_080D4EF4: .4byte 0x030046A4
_080D4EF8:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D4F1E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F1E
	ldr r0, [r5, #0x18]
	movs r1, #0xd1
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
_080D4F1E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x2e
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D4F98
_080D4F46:
	ldr r4, _080D4F64 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D4F98
	.align 2, 0
_080D4F64: .4byte 0x0000037E
_080D4F68:
	ldr r0, _080D4FA0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D4F84
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D4F84:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D4F98
	adds r0, r5, #0
	bl FUN_080d05e8
_080D4F98:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4FA0: .4byte 0x0000037E
