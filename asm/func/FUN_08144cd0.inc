	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08144CF0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08144CF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08144CF6
	.align 2, 0
_08144CF0: .4byte 0x0000046C
_08144CF4:
	movs r0, #0
_08144CF6:
	cmp r0, #0
	beq _08144D2C
	ldr r4, _08144D44 @ =FUN_081432ec
	movs r3, #0x25
	ldr r0, _08144D48 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08144D4C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _08144D50 @ =0x000006B2
	adds r1, r6, r0
	movs r0, #0x1e
	strh r0, [r1]
_08144D2C:
	ldr r1, _08144D54 @ =0x00000256
	adds r0, r5, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08144D58
	adds r0, #4
	b _08144D64
	.align 2, 0
_08144D44: .4byte FUN_081432ec
_08144D48: .4byte 0x0000046D
_08144D4C: .4byte 0x0000046B
_08144D50: .4byte 0x000006B2
_08144D54: .4byte 0x00000256
_08144D58:
	ldr r0, _08144DA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144D64:
	ldrh r0, [r0, #2]
	movs r1, #0x42
	ands r0, r1
	cmp r0, #0
	beq _08144DB4
	ldr r2, _08144DA8 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x14
	bgt _08144D7A
	b _08144EB4
_08144D7A:
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08144DAC @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08144DB0 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08144EBE
	.align 2, 0
_08144DA4: .4byte 0x030046A4
_08144DA8: .4byte 0x00000484
_08144DAC: .4byte 0x00000469
_08144DB0: .4byte 0x0000046C
_08144DB4:
	ldr r1, _08144DD0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144DD8
	ldr r3, _08144DD4 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08144DE8
	.align 2, 0
_08144DD0: .4byte 0x0000A02F
_08144DD4: .4byte 0x00000482
_08144DD8:
	ldr r4, _08144E0C @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08144DE8
	movs r0, #1
	strh r0, [r2]
_08144DE8:
	ldr r1, _08144E10 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08144E14
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08144E2C
	.align 2, 0
_08144E0C: .4byte 0x00000482
_08144E10: .4byte 0x0000025D
_08144E14:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08144E2C:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r3, _08144E5C @ =0x000006B2
	adds r4, r6, r3
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08144E60 @ =0x00000484
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _08144E70
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08144E64
	asrs r1, r0, #1
	b _08144E6A
	.align 2, 0
_08144E5C: .4byte 0x000006B2
_08144E60: .4byte 0x00000484
_08144E64:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08144E6A:
	ldr r2, _08144EA4 @ =0x000006B2
	adds r0, r6, r2
	strh r1, [r0]
_08144E70:
	ldr r3, _08144EA4 @ =0x000006B2
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _08144EB4
	movs r2, #2
	movs r3, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08144EA8 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08144EAC @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08144EB0 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08144EBE
	.align 2, 0
_08144EA4: .4byte 0x000006B2
_08144EA8: .4byte 0x00000469
_08144EAC: .4byte 0x0000046A
_08144EB0: .4byte 0x0000046C
_08144EB4:
	ldr r2, _08144EC4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08144EBE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08144EC4: .4byte 0x00000484
