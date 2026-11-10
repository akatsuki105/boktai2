	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x7c
	str r0, [sp, #8]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #6]
	mov sb, r0
	ldr r4, _0812792C @ =0x0000021E
	adds r0, r2, r4
	ldr r1, _08127930 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081278FA
	bl _081280CC
_081278FA:
	ldr r6, [sp, #8]
	ldr r7, _08127934 @ =0x00000256
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp sb, r0
	bne _08127908
	b _08127A48
_08127908:
	ldr r0, [sp, #8]
	ldr r1, _08127934 @ =0x00000256
	adds r4, r0, r1
	ldrh r7, [r4]
	movs r3, #0xa
	ldrsh r2, [r0, r3]
	mov r8, r2
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x48]
	cmp r0, #0
	beq _0812793C
	adds r0, #4
	ldr r4, _08127938 @ =0x030046A4
	mov sl, r4
	b _0812794A
	.align 2, 0
_0812792C: .4byte 0x0000021E
_08127930: .4byte 0x03002B68
_08127934: .4byte 0x00000256
_08127938: .4byte 0x030046A4
_0812793C:
	ldr r2, _08127974 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_0812794A:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	mov r6, sl
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x10]
	cmp r7, sb
	bge _081279E0
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _08127980
	.align 2, 0
_08127974: .4byte 0x030046A4
_08127978:
	cmp r5, sb
	beq _081279DC
	adds r5, #1
	adds r6, #1
_08127980:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _081279A0
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08127978
_081279A0:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r7, r0
	b _081279BE
_081279AE:
	cmp r5, sb
	beq _081279DC
	ldr r0, _081279D8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
_081279BE:
	ldr r2, [sp, #0x10]
	cmp r2, r5
	ble _08127A42
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081279AE
	b _08127A42
	.align 2, 0
_081279D8: .4byte 0x030046A4
_081279DC:
	movs r0, #1
	b _08127A44
_081279E0:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _081279F4
_081279EC:
	cmp r5, sb
	beq _081279DC
	subs r5, #1
	subs r6, #1
_081279F4:
	cmp r6, #0
	blt _08127A0A
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081279EC
_08127A0A:
	ldr r0, _08127A18 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r7, r0
	b _08127A2C
	.align 2, 0
_08127A18: .4byte 0x030046A4
_08127A1C:
	cmp r5, sb
	beq _081279DC
	ldr r0, _08127A4C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	subs r5, r5, r0
_08127A2C:
	cmp r5, #0
	blt _08127A42
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08127A1C
_08127A42:
	movs r0, #0
_08127A44:
	cmp r0, #0
	beq _08127A50
_08127A48:
	movs r0, #1
	b _081280CE
	.align 2, 0
_08127A4C: .4byte 0x030046A4
_08127A50:
	ldr r7, [sp, #0xc]
	ldr r1, _08127A70 @ =0x000006FE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08127A78
	ldr r2, [sp, #8]
	ldr r3, _08127A74 @ =0x00000256
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, sb
	bne _08127A78
	adds r0, r2, #0
	bl Mummy_RouteToFloorEnd
	b _081280CC
	.align 2, 0
_08127A70: .4byte 0x000006FE
_08127A74: .4byte 0x00000256
_08127A78:
	ldr r4, [sp, #8]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r4, r6
	ldr r0, _08127AC8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r7, #0x95
	lsls r7, r7, #3
	adds r3, r4, r7
	ldr r6, [r3]
	adds r2, r4, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x70]
	str r2, [sp, #0x40]
	cmp r5, #0
	blt _08127AC4
	cmp r1, #0
	blt _08127AC4
	ldr r0, _08127ACC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08127AC4
	ldr r0, _08127AD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127AD4
_08127AC4:
	movs r5, #0
	b _08127AE2
	.align 2, 0
_08127AC8: .4byte 0x03002BE0
_08127ACC: .4byte 0x030046A8
_08127AD0: .4byte 0x030046AC
_08127AD4:
	ldr r0, _08127AF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_08127AE2:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08127AF8
	adds r0, #4
	b _08127B04
	.align 2, 0
_08127AF4: .4byte 0x030046A4
_08127AF8:
	ldr r0, _08127B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127B04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08127B1C
	cmp r2, #2
	beq _08127B20
	b _08127B24
	.align 2, 0
_08127B18: .4byte 0x030046A4
_08127B1C:
	ldrb r0, [r6, #4]
	b _08127B22
_08127B20:
	ldrb r0, [r6]
_08127B22:
	subs r1, r1, r0
_08127B24:
	strh r1, [r6, #2]
	ldr r0, _08127B38 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08127B3C
	movs r0, #1
	b _08127B3E
	.align 2, 0
_08127B38: .4byte 0x030047A4
_08127B3C:
	movs r0, #0
_08127B3E:
	cmp r0, #0
	beq _08127B88
	ldr r1, [sp, #8]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08127B60
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08127B5C
	adds r2, r0, #0
_08127B5C:
	cmp r2, #0
	bge _08127B74
_08127B60:
	ldr r3, [sp, #8]
	ldr r4, _08127B70 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _081280CC
	.align 2, 0
_08127B70: .4byte 0x000005C4
_08127B74:
	ldr r1, _08127B84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08127BD4
	.align 2, 0
_08127B84: .4byte 0x03002BE0
_08127B88:
	ldr r6, [sp, #8]
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08127BB6
	cmp r1, #0
	blt _08127BB6
	ldr r0, _08127BBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08127BB6
	ldr r0, _08127BC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127BC4
_08127BB6:
	movs r5, #0
	b _08127BD2
	.align 2, 0
_08127BBC: .4byte 0x030046A8
_08127BC0: .4byte 0x030046AC
_08127BC4:
	ldr r0, _08127CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08127BD2:
	movs r2, #0
_08127BD4:
	ldr r0, [sp, #0x48]
	ldrh r0, [r0]
	cmp r5, r0
	beq _08127BF2
	ldr r1, _08127CC4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08127BF2
	b _08128004
_08127BF2:
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r1, [sp, #8]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _08127C10
	b _081280CC
_08127C10:
	ldr r4, [sp, #8]
	ldr r6, _08127CC8 @ =0x00000222
	adds r2, r4, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r7, [sp, #0x74]
	ldrh r0, [r7]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	str r2, [sp, #0x38]
	cmp r7, #0
	beq _08127CE4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08127CCC @ =0x0000046D
	adds r4, r4, r2
	mov ip, r4
	movs r3, #1
	mov sb, r3
	mov r6, sb
	strb r6, [r4]
	ldr r7, [sp, #8]
	subs r2, #2
	adds r7, r7, r2
	mov sl, r7
	movs r3, #0
	strb r3, [r7]
	ldr r4, [sp, #8]
	ldr r6, _08127CD0 @ =0x00000553
	adds r4, r4, r6
	mov r8, r4
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	ldr r7, [sp, #8]
	adds r0, r7, r0
	str r0, [sp, #0x78]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x14]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08127CD4 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08127CD8 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08127CDC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x14]
	str r6, [r1]
	ldr r6, _08127CE0 @ =0x0000046C
	adds r0, r7, r6
	mov r7, sb
	strb r7, [r0]
	mov r6, ip
	str r6, [sp, #0x64]
	mov r7, sl
	str r7, [sp, #0x5c]
	mov r6, r8
	str r6, [sp, #0x3c]
	ldr r7, [sp, #0x78]
	str r7, [sp, #0x44]
	str r5, [sp, #0x24]
	str r4, [sp, #0x50]
	str r3, [sp, #0x54]
	str r2, [sp, #0x58]
	str r1, [sp, #0x6c]
	str r0, [sp, #0x60]
	b _08127EB2
	.align 2, 0
_08127CC0: .4byte 0x030046A4
_08127CC4: .4byte 0x03002BE0
_08127CC8: .4byte 0x00000222
_08127CCC: .4byte 0x0000046D
_08127CD0: .4byte 0x00000553
_08127CD4: .4byte 0x00000469
_08127CD8: .4byte 0x0000046A
_08127CDC: .4byte 0x00000484
_08127CE0: .4byte 0x0000046C
_08127CE4:
	ldr r1, [sp, #8]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _08127DA8 @ =0x0000046D
	ldr r3, [sp, #8]
	adds r4, r3, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	ldr r6, _08127DAC @ =0x0000046B
	adds r3, r3, r6
	mov ip, r3
	movs r2, #0
	strb r2, [r3]
	ldr r3, [sp, #8]
	ldr r4, _08127DB0 @ =0x00000553
	adds r3, r3, r4
	mov sl, r3
	strb r0, [r3]
	ldr r6, [sp, #8]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r6, r6, r2
	mov sb, r6
	str r1, [r6]
	ldr r3, [sp, #8]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r3, r3, r4
	mov r8, r3
	strh r7, [r3]
	movs r1, #5
	ldr r2, [sp, #8]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r6, r2, r3
	movs r4, #0
	strb r4, [r6]
	adds r3, #1
	adds r5, r2, r3
	strb r4, [r5]
	adds r3, #1
	adds r4, r2, r3
	strb r1, [r4]
	ldr r1, _08127DB4 @ =0x00000484
	adds r3, r2, r1
	str r7, [r3]
	ldr r7, _08127DB8 @ =0x0000046C
	adds r2, r2, r7
	strb r0, [r2]
	ldr r0, [sp, #0x70]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x40]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r7, [sp, #0x1c]
	strh r1, [r7]
	ldr r7, [sp, #0x40]
	ldr r0, [r7, #8]
	ldrh r0, [r0, #2]
	ldr r7, [sp, #0x1c]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r7, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x64]
	mov r0, ip
	str r0, [sp, #0x5c]
	mov r0, sl
	str r0, [sp, #0x3c]
	mov r0, sb
	str r0, [sp, #0x44]
	mov r0, r8
	str r0, [sp, #0x24]
	str r6, [sp, #0x50]
	str r5, [sp, #0x54]
	str r4, [sp, #0x58]
	str r3, [sp, #0x6c]
	str r2, [sp, #0x60]
	cmp r7, #0
	blt _08127DA4
	cmp r1, #0
	blt _08127DA4
	ldr r0, _08127DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r7, r0
	bhs _08127DA4
	ldr r0, _08127DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127DC4
_08127DA4:
	movs r7, #0
	b _08127DD2
	.align 2, 0
_08127DA8: .4byte 0x0000046D
_08127DAC: .4byte 0x0000046B
_08127DB0: .4byte 0x00000553
_08127DB4: .4byte 0x00000484
_08127DB8: .4byte 0x0000046C
_08127DBC: .4byte 0x030046A8
_08127DC0: .4byte 0x030046AC
_08127DC4:
	ldr r0, _08127DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r7
_08127DD2:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08127DE8
	adds r0, #4
	b _08127DF4
	.align 2, 0
_08127DE4: .4byte 0x030046A4
_08127DE8:
	ldr r0, _08127E08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127DF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08127E0C
	cmp r2, #2
	beq _08127E12
	b _08127E18
	.align 2, 0
_08127E08: .4byte 0x030046A4
_08127E0C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _08127E16
_08127E12:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_08127E16:
	subs r1, r1, r0
_08127E18:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08127E44
	cmp r1, #0
	blt _08127E44
	ldr r0, _08127E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08127E44
	ldr r0, _08127E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127E50
_08127E44:
	movs r7, #0
	b _08127E5E
	.align 2, 0
_08127E48: .4byte 0x030046A8
_08127E4C: .4byte 0x030046AC
_08127E50:
	ldr r0, _08127E74 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_08127E5E:
	ldr r0, [sp, #0x70]
	ldr r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08127E78
	adds r0, #4
	b _08127E84
	.align 2, 0
_08127E74: .4byte 0x030046A4
_08127E78:
	ldr r0, _08127E98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127E84:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08127E9C
	cmp r3, #2
	beq _08127EA0
	b _08127EA4
	.align 2, 0
_08127E98: .4byte 0x030046A4
_08127E9C:
	ldrb r0, [r4, #4]
	b _08127EA2
_08127EA0:
	ldrb r0, [r4]
_08127EA2:
	subs r2, r2, r0
_08127EA4:
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x70]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08127EB2:
	ldr r3, [sp, #8]
	ldrb r3, [r3, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r7, _08127EE4 @ =0x00000482
	ldr r6, [sp, #8]
	adds r7, r6, r7
	str r7, [sp, #0x68]
	cmp r0, #0
	beq _08127ED2
	b _08127FD0
_08127ED2:
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08127EE8
	movs r0, #1
	b _08127EEA
	.align 2, 0
_08127EE4: .4byte 0x00000482
_08127EE8:
	movs r0, #0
_08127EEA:
	ldr r4, _08127FE0 @ =0x00000482
	ldr r3, [sp, #8]
	adds r4, r3, r4
	str r4, [sp, #0x68]
	cmp r0, #0
	bne _08127FD0
	movs r3, #0
	ldr r7, [sp, #8]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	adds r1, r7, #0
	movs r2, #0xa9
	lsls r2, r2, #3
	adds r1, r1, r2
	mov sb, r1
	adds r4, r7, #0
	ldr r7, _08127FE4 @ =0x0000054F
	adds r4, r4, r7
	mov sl, r4
	ldr r0, [sp, #8]
	ldr r1, _08127FE8 @ =0x0000054C
	adds r0, r0, r1
	mov ip, r0
	ldr r4, _08127FEC @ =0x0000054D
	ldr r2, [sp, #8]
	adds r4, r2, r4
	str r4, [sp, #0x30]
	subs r7, #1
	adds r7, r2, r7
	str r7, [sp, #0x34]
	ldr r0, _08127FF0 @ =0x00000541
	adds r0, r2, r0
	str r0, [sp, #0x28]
	adds r1, #0x70
	adds r1, r2, r1
	str r1, [sp, #0x4c]
	ldr r4, _08127FF4 @ =0x00000542
	adds r4, r2, r4
	str r4, [sp, #0x2c]
	ldr r5, _08127FF8 @ =0x0203B400
	ldr r1, _08127FFC @ =0x030046B8
	ldr r4, _08128000 @ =0x000003FF
	movs r2, #3
	mov r7, r8
_08127F44:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r7
	bne _08127F62
	adds r3, #1
	cmp r3, #3
	ble _08127F44
	mov r0, r8
_08127F62:
	movs r3, #0
	strb r0, [r6]
	ldr r6, [sp, #0x44]
	ldr r0, [r6]
	mov r7, sb
	str r0, [r7]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	mov r2, sl
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	mov r6, ip
	strb r0, [r6]
	ldr r7, [sp, #0x54]
	ldrb r0, [r7]
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	ldr r2, [sp, #0x58]
	ldrb r0, [r2]
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	add r6, sp, #0x20
	ldrb r7, [r6]
	ldr r6, [sp, #0x28]
	strb r7, [r6]
	ldr r7, [sp, #0x4c]
	ldr r2, [r7]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x64]
	strb r1, [r4]
	ldr r6, [sp, #0x5c]
	strb r3, [r6]
	ldr r7, [sp, #0x3c]
	strb r0, [r7]
	ldr r0, [sp, #0x44]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x24]
	strh r3, [r4]
	movs r0, #3
	ldr r6, [sp, #0x50]
	strb r0, [r6]
	ldr r7, [sp, #0x54]
	strb r1, [r7]
	ldr r0, [sp, #0x58]
	strb r2, [r0]
	ldr r2, [sp, #0x6c]
	str r3, [r2]
	ldr r3, [sp, #0x60]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
_08127FD0:
	ldr r0, [sp, #8]
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r6, [sp, #0x68]
	strh r0, [r6]
	b _081280CC
	.align 2, 0
_08127FE0: .4byte 0x00000482
_08127FE4: .4byte 0x0000054F
_08127FE8: .4byte 0x0000054C
_08127FEC: .4byte 0x0000054D
_08127FF0: .4byte 0x00000541
_08127FF4: .4byte 0x00000542
_08127FF8: .4byte 0x0203B400
_08127FFC: .4byte 0x030046B8
_08128000: .4byte 0x000003FF
_08128004:
	mov r8, sp
	ldr r6, _08128040 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
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
	beq _08128044
	adds r0, #4
	b _0812804E
	.align 2, 0
_08128040: .4byte 0x030046A4
_08128044:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812804E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, r8
	strh r0, [r3, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r4, [sp, #8]
	ldr r6, _08128084 @ =0x000004A4
	adds r0, r4, r6
	ldr r4, [r0]
	ldr r5, [sp, #8]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08128088
	ldr r7, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081280B0
	.align 2, 0
_08128084: .4byte 0x000004A4
_08128088:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081280A8
	cmp r0, #2
	beq _081280A4
	ldr r0, [sp, #8]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081280A4:
	movs r0, #1
	b _081280BA
_081280A8:
	ldr r2, [sp, #8]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
_081280B0:
	ldr r1, _081280E0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081280BA:
	cmp r0, #0
	bne _081280CC
	ldr r4, [sp, #8]
	ldr r6, _081280E4 @ =0x000005C4
	adds r0, r4, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081280CC:
	movs r0, #0
_081280CE:
	add sp, #0x7c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081280E0: .4byte 0xFFFFFDFF
_081280E4: .4byte 0x000005C4
