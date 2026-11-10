	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	str r0, [sp, #0x18]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r2, [sp, #0x18]
	ldr r3, _0811DDAC @ =0x0000046C
	adds r1, r2, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811DDB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811DDB2
	.align 2, 0
_0811DDAC: .4byte 0x0000046C
_0811DDB0:
	movs r0, #0
_0811DDB2:
	cmp r0, #0
	beq _0811DDBE
	ldr r4, _0811DE08 @ =0x00000659
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
_0811DDBE:
	ldr r0, [sp, #0x18]
	bl Golem_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811DDCE
	bl _0811EDDA
_0811DDCE:
	ldr r6, _0811DE08 @ =0x00000659
	adds r5, r7, r6
	ldrb r0, [r5]
	cmp r0, #1
	bne _0811DDEE
	ldr r1, _0811DE0C @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r4, #0
	bne _0811DDEE
	ldr r0, [sp, #0x18]
	movs r1, #4
	bl PlayGolemSound
	strb r4, [r5]
_0811DDEE:
	ldr r0, [sp, #0x18]
	bl Golem_Accelerate
	ldr r0, _0811DE10 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811DE14
	movs r0, #1
	b _0811DE16
	.align 2, 0
_0811DE08: .4byte 0x00000659
_0811DE0C: .4byte 0x000006B6
_0811DE10: .4byte 0x030047A4
_0811DE14:
	movs r0, #0
_0811DE16:
	cmp r0, #0
	beq _0811DE80
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0811DED0
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811DE34
	adds r2, r0, #0
_0811DE34:
	cmp r2, #0
	blt _0811DED0
	ldr r1, _0811DE60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811DED0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r5, _0811DE64 @ =0x0000065C
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811DE68
	movs r0, #1
	b _0811DE6A
	.align 2, 0
_0811DE60: .4byte 0x03002BE0
_0811DE64: .4byte 0x0000065C
_0811DE68:
	movs r0, #0
_0811DE6A:
	adds r5, r0, #0
	cmp r5, #0
	bne _0811DED0
	ldr r6, _0811DE7C @ =0x000006B4
	adds r1, r7, r6
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	b _0811E25E
	.align 2, 0
_0811DE7C: .4byte 0x000006B4
_0811DE80:
	ldr r0, _0811DEA4 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811DED0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _0811DEA8 @ =0x0000065C
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811DEAC
	movs r0, #1
	b _0811DEAE
	.align 2, 0
_0811DEA4: .4byte 0x03002BE0
_0811DEA8: .4byte 0x0000065C
_0811DEAC:
	movs r0, #0
_0811DEAE:
	adds r5, r0, #0
	cmp r5, #0
	bne _0811DED0
	ldr r3, _0811DEC8 @ =0x000006B4
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	strh r0, [r1]
	ldr r6, _0811DECC @ =0x000006C4
	adds r0, r7, r6
	b _0811E264
	.align 2, 0
_0811DEC8: .4byte 0x000006B4
_0811DECC: .4byte 0x000006C4
_0811DED0:
	ldr r2, [sp, #0x18]
	ldr r3, _0811DF7C @ =0x000004A4
	adds r0, r2, r3
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0811DEE8
	b _0811E404
_0811DEE8:
	ldr r4, _0811DF80 @ =0x000006B6
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl Golem_MoveAlongNavAxis
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811DF0A
	b _0811E2E8
_0811DF0A:
	movs r6, #0xda
	lsls r6, r6, #3
	adds r2, r7, r6
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	add r3, sp, #8
	ldr r4, [sp, #0x18]
	adds r4, #8
	ldrh r0, [r2]
	ldr r5, [sp, #0x18]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r5, _0811DF84 @ =0x000006C2
	adds r2, r7, r5
	ldr r6, _0811DF88 @ =0x00000659
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r1, r1, r0
	adds r6, r4, #0
	cmp r1, #0x80
	ble _0811DF90
	ldr r0, _0811DF8C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811DF9E
	.align 2, 0
_0811DF7C: .4byte 0x000004A4
_0811DF80: .4byte 0x000006B6
_0811DF84: .4byte 0x000006C2
_0811DF88: .4byte 0x00000659
_0811DF8C: .4byte 0xFFFFFF00
_0811DF90:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811DF9E
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811DF9E:
	cmp r1, #0
	bge _0811DFA4
	rsbs r1, r1, #0
_0811DFA4:
	cmp r1, #0xf
	bgt _0811DFE0
	ldr r0, _0811DFD0 @ =0x0000FFFE
	cmp r3, r0
	bgt _0811DFE0
	ldr r3, _0811DFD4 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc7
	ble _0811DFE0
	ldr r5, _0811DFD8 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	ldr r6, _0811DFDC @ =0x000006C4
	adds r0, r7, r6
	b _0811E264
	.align 2, 0
_0811DFD0: .4byte 0x0000FFFE
_0811DFD4: .4byte 0x000006B6
_0811DFD8: .4byte 0x000006B4
_0811DFDC: .4byte 0x000006C4
_0811DFE0:
	ldr r2, _0811E004 @ =0x000006C2
	adds r0, r7, r2
	ldrb r4, [r0]
	add r1, sp, #8
	adds r0, r1, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl ArcTan2_8
	subs r1, r0, r4
	cmp r1, #0x80
	ble _0811E00C
	ldr r0, _0811E008 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811E01A
	.align 2, 0
_0811E004: .4byte 0x000006C2
_0811E008: .4byte 0xFFFFFF00
_0811E00C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E01A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811E01A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0811E022
	rsbs r0, r0, #0
_0811E022:
	cmp r0, #0xf
	bgt _0811E0C8
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E050
	cmp r1, #0
	blt _0811E050
	ldr r0, _0811E054 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E050
	ldr r0, _0811E058 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E05C
_0811E050:
	movs r5, #0
	b _0811E06A
	.align 2, 0
_0811E054: .4byte 0x030046A8
_0811E058: .4byte 0x030046AC
_0811E05C:
	ldr r0, _0811E07C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811E06A:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811E080
	adds r0, #4
	b _0811E08C
	.align 2, 0
_0811E07C: .4byte 0x030046A4
_0811E080:
	ldr r0, _0811E0C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E08C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	ldr r4, _0811E0C4 @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r4, r0, #6
	adds r0, r5, #0
	adds r2, r4, #0
	bl Golem_ClassifyNextTile
	cmp r0, #0
	bne _0811E0B8
	movs r5, #0xda
	lsls r5, r5, #3
	adds r0, r7, r5
	adds r1, r4, #0
	bl Golem_SnapToNextTile
_0811E0B8:
	adds r0, r7, #0
	bl Golem_RouteTo
	b _0811E0D4
	.align 2, 0
_0811E0C0: .4byte 0x030046A4
_0811E0C4: .4byte 0x000006C2
_0811E0C8:
	subs r0, #0x34
	cmp r0, #0x18
	bhi _0811E0D4
	adds r0, r7, #0
	bl Golem_RouteTo
_0811E0D4:
	ldr r1, _0811E0EC @ =0x000006C4
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _0811E0F0 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E0F8
	ldr r3, _0811E0F4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0811E106
	.align 2, 0
_0811E0EC: .4byte 0x000006C4
_0811E0F0: .4byte 0x000006C2
_0811E0F4: .4byte 0xFFFFFF00
_0811E0F8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E106
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0811E106:
	cmp r1, #0
	bge _0811E10C
	rsbs r1, r1, #0
_0811E10C:
	cmp r1, #0x1f
	ble _0811E180
	ldr r5, _0811E164 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _0811E168 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _0811E16C @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811E136
	b _0811E558
_0811E136:
	ldr r2, _0811E170 @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811E174 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E178 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E17C @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E164: .4byte 0x000006C4
_0811E168: .4byte 0x000006C5
_0811E16C: .4byte 0x000006B4
_0811E170: .4byte Golem_StateUncurl
_0811E174: .4byte 0x0000046D
_0811E178: .4byte 0x0000046B
_0811E17C: .4byte 0x00000553
_0811E180:
	add r2, sp, #8
	ldr r1, [sp, #0x18]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r1, #8]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r5, #4
	ldrsh r0, [r2, r5]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r3, r1, r0
	ldr r0, _0811E1E4 @ =0x0000FFFE
	cmp r3, r0
	bgt _0811E252
	ldr r1, _0811E1E8 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xc7
	ble _0811E252
	ldr r0, _0811E1EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811E1F0
	movs r0, #1
	b _0811E1F2
	.align 2, 0
_0811E1E4: .4byte 0x0000FFFE
_0811E1E8: .4byte 0x000006B6
_0811E1EC: .4byte 0x030047A4
_0811E1F0:
	movs r0, #0
_0811E1F2:
	cmp r0, #0
	beq _0811E238
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0811E252
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811E210
	adds r2, r0, #0
_0811E210:
	cmp r2, #0
	blt _0811E252
	ldr r1, _0811E230 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E252
	ldr r5, _0811E234 @ =0x000006BC
	adds r1, r7, r5
	b _0811E24C
	.align 2, 0
_0811E230: .4byte 0x03002BE0
_0811E234: .4byte 0x000006BC
_0811E238:
	ldr r0, _0811E2BC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E252
	ldr r6, _0811E2C0 @ =0x000006BC
	adds r1, r7, r6
_0811E24C:
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
_0811E252:
	ldr r0, _0811E2C4 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
_0811E25E:
	strh r0, [r1]
	ldr r1, _0811E2C8 @ =0x000006C4
	adds r0, r7, r1
_0811E264:
	ldrb r1, [r0]
	ldr r2, _0811E2CC @ =0x000006C5
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #2
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _0811E2D0 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811E2D4 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0811E2D8 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0811E2DC @ =Golem_StateBrake
	movs r2, #0x2a
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811E2E0 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811E2E4 @ =0x00000553
	adds r0, r7, r4
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	bl _0811EDDA
	.align 2, 0
_0811E2BC: .4byte 0x03002BE0
_0811E2C0: .4byte 0x000006BC
_0811E2C4: .4byte 0x000006B4
_0811E2C8: .4byte 0x000006C4
_0811E2CC: .4byte 0x000006C5
_0811E2D0: .4byte 0x00000469
_0811E2D4: .4byte 0x0000046A
_0811E2D8: .4byte 0x00000484
_0811E2DC: .4byte Golem_StateBrake
_0811E2E0: .4byte 0x0000046B
_0811E2E4: .4byte 0x00000553
_0811E2E8:
	ldr r2, [sp, #0x18]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, _0811E304 @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E30C
	ldr r5, _0811E308 @ =0xFFFFFF00
	adds r1, r1, r5
	b _0811E31A
	.align 2, 0
_0811E304: .4byte 0x000006C2
_0811E308: .4byte 0xFFFFFF00
_0811E30C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E31A
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0811E31A:
	cmp r1, #0
	bge _0811E320
	rsbs r1, r1, #0
_0811E320:
	cmp r1, #0xf
	bgt _0811E352
	ldr r1, [sp, #0x18]
	ldr r2, _0811E36C @ =0x00000256
	adds r0, r1, r2
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0811E352
	movs r4, #0xda
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r5, #0xd9
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl Golem_RouteTo
_0811E352:
	ldr r6, _0811E370 @ =0x000006C4
	adds r0, r7, r6
	ldrb r1, [r0]
	ldr r2, _0811E374 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E37C
	ldr r3, _0811E378 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0811E38A
	.align 2, 0
_0811E36C: .4byte 0x00000256
_0811E370: .4byte 0x000006C4
_0811E374: .4byte 0x000006C2
_0811E378: .4byte 0xFFFFFF00
_0811E37C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E38A
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0811E38A:
	cmp r1, #0
	bge _0811E390
	rsbs r1, r1, #0
_0811E390:
	cmp r1, #0x1f
	bgt _0811E396
	b _0811E5C8
_0811E396:
	ldr r5, _0811E3E8 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _0811E3EC @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _0811E3F0 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811E3BC
	b _0811E558
_0811E3BC:
	ldr r2, _0811E3F4 @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811E3F8 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E3FC @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E400 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E3E8: .4byte 0x000006C4
_0811E3EC: .4byte 0x000006C5
_0811E3F0: .4byte 0x000006B4
_0811E3F4: .4byte Golem_StateUncurl
_0811E3F8: .4byte 0x0000046D
_0811E3FC: .4byte 0x0000046B
_0811E400: .4byte 0x00000553
_0811E404:
	ldr r3, _0811E440 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl Golem_MoveAlongNavAxis
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811E444
	movs r5, #0xda
	lsls r5, r5, #3
	adds r2, r7, r5
	movs r6, #0xd9
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl Golem_RouteTo
	b _0811E4AE
	.align 2, 0
_0811E440: .4byte 0x000006B6
_0811E444:
	ldr r1, [sp, #0x18]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r1, [r0]
	ldr r3, _0811E460 @ =0x000006C2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E468
	ldr r4, _0811E464 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0811E476
	.align 2, 0
_0811E460: .4byte 0x000006C2
_0811E464: .4byte 0xFFFFFF00
_0811E468:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E476
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0811E476:
	cmp r1, #0
	bge _0811E47C
	rsbs r1, r1, #0
_0811E47C:
	cmp r1, #0xf
	bgt _0811E4AE
	ldr r6, [sp, #0x18]
	ldr r1, _0811E4C8 @ =0x00000256
	adds r0, r6, r1
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0811E4AE
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r4, #0xd9
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl Golem_RouteTo
_0811E4AE:
	ldr r5, _0811E4CC @ =0x000006C4
	adds r0, r7, r5
	ldrb r1, [r0]
	ldr r6, _0811E4D0 @ =0x000006C2
	adds r0, r7, r6
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E4D8
	ldr r0, _0811E4D4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811E4E6
	.align 2, 0
_0811E4C8: .4byte 0x00000256
_0811E4CC: .4byte 0x000006C4
_0811E4D0: .4byte 0x000006C2
_0811E4D4: .4byte 0xFFFFFF00
_0811E4D8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E4E6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811E4E6:
	cmp r1, #0
	bge _0811E4EC
	rsbs r1, r1, #0
_0811E4EC:
	cmp r1, #0x1f
	ble _0811E5C8
	ldr r3, _0811E540 @ =0x000006C4
	adds r2, r7, r3
	ldrb r1, [r2]
	ldr r4, _0811E544 @ =0x000006C5
	adds r0, r7, r4
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r5, _0811E548 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0811E558
	ldr r2, _0811E54C @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r6, _0811E550 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E554 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E540: .4byte 0x000006C4
_0811E544: .4byte 0x000006C5
_0811E548: .4byte 0x000006B4
_0811E54C: .4byte Golem_StateUncurl
_0811E550: .4byte 0x0000046D
_0811E554: .4byte 0x00000553
_0811E558:
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r1, _0811E5AC @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0811E5B0 @ =Golem_StateStopAndTurn
	movs r1, #0x25
	ldr r3, _0811E5B4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E5B8 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E5BC @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #2
_0811E596:
	ldr r2, _0811E5C0 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	subs r5, #0xcf
	adds r0, r7, r5
	str r4, [r0]
	ldr r6, _0811E5C4 @ =0x0000046C
	adds r0, r7, r6
	strb r3, [r0]
	bl _0811EDDA
	.align 2, 0
_0811E5AC: .4byte 0x000004A4
_0811E5B0: .4byte Golem_StateStopAndTurn
_0811E5B4: .4byte 0x0000046D
_0811E5B8: .4byte 0x0000046B
_0811E5BC: .4byte 0x00000553
_0811E5C0: .4byte 0x0000046A
_0811E5C4: .4byte 0x0000046C
_0811E5C8:
	ldr r1, _0811E6F8 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0811E5D8
	bl _0811EDC4
_0811E5D8:
	ldr r0, [sp, #0x18]
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x1c]
	movs r1, #0
	strb r0, [r4]
	ldr r5, _0811E6FC @ =0x00000469
	adds r5, r3, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r0, _0811E700 @ =0x0000046A
	adds r3, r3, r0
	mov ip, r3
	strb r1, [r3]
	ldr r2, [sp, #0x18]
	ldr r3, _0811E704 @ =0x00000484
	adds r2, r2, r3
	mov sl, r2
	str r1, [r2]
	ldr r4, [sp, #0x18]
	ldr r5, _0811E708 @ =0x0000046C
	adds r6, r4, r5
	movs r0, #1
	strb r0, [r6]
	ldr r2, _0811E70C @ =Enemy_WaitPendingState
	movs r0, #0xe
	subs r3, #0x17
	adds r4, r4, r3
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r3, [sp, #0x18]
	ldr r4, _0811E710 @ =0x0000046B
	adds r3, r3, r4
	mov r8, r3
	strb r1, [r3]
	ldr r3, [sp, #0x18]
	adds r4, #0xe8
	adds r5, r3, r4
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r3, r0
	str r2, [r4]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r3, r3, r2
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r0, _0811E714 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ands r1, r0
	str r6, [sp, #0x40]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x30]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x34]
	mov r6, ip
	str r6, [sp, #0x38]
	mov r0, sl
	str r0, [sp, #0x4c]
	mov r6, sb
	str r6, [sp, #0x44]
	mov r0, r8
	str r0, [sp, #0x3c]
	str r5, [sp, #0x68]
	str r4, [sp, #0x28]
	str r3, [sp, #0x58]
	mov sl, r2
	cmp r1, #0
	bne _0811E682
	b _0811EC58
_0811E682:
	ldr r1, [sp, #0x18]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	ldr r5, [sp, #0x18]
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
	ldr r3, _0811E718 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r5, [r3]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811E6F2
	cmp r1, #0
	blt _0811E6F2
	ldr r0, _0811E71C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811E6F2
	ldr r0, _0811E720 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E724
_0811E6F2:
	movs r4, #0
	b _0811E732
	.align 2, 0
_0811E6F8: .4byte 0x000006B4
_0811E6FC: .4byte 0x00000469
_0811E700: .4byte 0x0000046A
_0811E704: .4byte 0x00000484
_0811E708: .4byte 0x0000046C
_0811E70C: .4byte Enemy_WaitPendingState
_0811E710: .4byte 0x0000046B
_0811E714: .4byte 0xFFFFFEFF
_0811E718: .4byte 0x00000551
_0811E71C: .4byte 0x030046A8
_0811E720: .4byte 0x030046AC
_0811E724:
	ldr r0, _0811E744 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811E732:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811E748
	adds r0, #4
	b _0811E754
	.align 2, 0
_0811E744: .4byte 0x030046A4
_0811E748:
	ldr r0, _0811E768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E754:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811E76C
	cmp r2, #2
	beq _0811E770
	b _0811E774
	.align 2, 0
_0811E768: .4byte 0x030046A4
_0811E76C:
	ldrb r0, [r5, #4]
	b _0811E772
_0811E770:
	ldrb r0, [r5]
_0811E772:
	subs r1, r1, r0
_0811E774:
	strh r1, [r5, #2]
	ldr r0, _0811E788 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811E78C
	movs r0, #1
	b _0811E78E
	.align 2, 0
_0811E788: .4byte 0x030047A4
_0811E78C:
	movs r0, #0
_0811E78E:
	cmp r0, #0
	beq _0811E7D4
	ldr r1, [sp, #0x18]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0811E7B0
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811E7AC
	adds r2, r0, #0
_0811E7AC:
	cmp r2, #0
	bge _0811E7C0
_0811E7B0:
	ldr r3, [sp, #0x18]
	ldr r4, _0811E7BC @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	b _0811EC2E
	.align 2, 0
_0811E7BC: .4byte 0x000005C4
_0811E7C0:
	ldr r1, _0811E7D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811E820
	.align 2, 0
_0811E7D0: .4byte 0x03002BE0
_0811E7D4:
	ldr r5, [sp, #0x18]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E802
	cmp r1, #0
	blt _0811E802
	ldr r0, _0811E808 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E802
	ldr r0, _0811E80C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E810
_0811E802:
	movs r5, #0
	b _0811E81E
	.align 2, 0
_0811E808: .4byte 0x030046A8
_0811E80C: .4byte 0x030046AC
_0811E810:
	ldr r0, _0811E858 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811E81E:
	movs r2, #0
_0811E820:
	ldr r3, [sp, #0x18]
	ldr r4, _0811E85C @ =0x00000256
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811E842
	ldr r1, _0811E860 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E842
	b _0811EB64
_0811E842:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811E864
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811E858: .4byte 0x030046A4
_0811E85C: .4byte 0x00000256
_0811E860: .4byte 0x03002BE0
_0811E864:
	ldr r0, [sp, #0x18]
	ldr r1, _0811E8C4 @ =0x00000222
	adds r2, r0, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0811E8C8
	ldr r6, [sp, #0x18]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x44]
	strb r2, [r3]
	ldr r6, [sp, #0x3c]
	strb r5, [r6]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r6, [sp, #0x28]
	str r1, [r6]
	ldr r0, [sp, #0x58]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x30]
	strb r5, [r1]
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r4, [r6]
	ldr r0, [sp, #0x40]
	strb r2, [r0]
	b _0811EA1A
	.align 2, 0
_0811E8C4: .4byte 0x00000222
_0811E8C8:
	ldr r1, [sp, #0x18]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x44]
	strb r0, [r4]
	ldr r2, [sp, #0x3c]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r2, [sp, #0x28]
	str r1, [r2]
	ldr r4, [sp, #0x58]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x30]
	strb r5, [r2]
	ldr r4, [sp, #0x34]
	strb r5, [r4]
	ldr r5, [sp, #0x38]
	strb r1, [r5]
	ldr r1, [sp, #0x4c]
	str r3, [r1]
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E92E
	cmp r1, #0
	blt _0811E92E
	ldr r0, _0811E934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E92E
	ldr r0, _0811E938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E93C
_0811E92E:
	movs r4, #0
	b _0811E94A
	.align 2, 0
_0811E934: .4byte 0x030046A8
_0811E938: .4byte 0x030046AC
_0811E93C:
	ldr r0, _0811E95C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811E94A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811E960
	adds r0, #4
	b _0811E96C
	.align 2, 0
_0811E95C: .4byte 0x030046A4
_0811E960:
	ldr r0, _0811E980 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E96C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811E984
	cmp r2, #2
	beq _0811E988
	b _0811E98C
	.align 2, 0
_0811E980: .4byte 0x030046A4
_0811E984:
	ldrb r0, [r5, #4]
	b _0811E98A
_0811E988:
	ldrb r0, [r5]
_0811E98A:
	subs r1, r1, r0
_0811E98C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E9B4
	cmp r1, #0
	blt _0811E9B4
	ldr r0, _0811E9B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E9B4
	ldr r0, _0811E9BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E9C0
_0811E9B4:
	movs r4, #0
	b _0811E9CE
	.align 2, 0
_0811E9B8: .4byte 0x030046A8
_0811E9BC: .4byte 0x030046AC
_0811E9C0:
	ldr r0, _0811E9E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811E9CE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811E9E4
	adds r0, #4
	b _0811E9F0
	.align 2, 0
_0811E9E0: .4byte 0x030046A4
_0811E9E4:
	ldr r0, _0811EA04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E9F0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811EA08
	cmp r3, #2
	beq _0811EA0C
	b _0811EA10
	.align 2, 0
_0811EA04: .4byte 0x030046A4
_0811EA08:
	ldrb r0, [r5, #4]
	b _0811EA0E
_0811EA0C:
	ldrb r0, [r5]
_0811EA0E:
	subs r2, r2, r0
_0811EA10:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811EA1A:
	ldr r4, [sp, #0x18]
	ldrb r4, [r4, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	ldr r6, [sp, #0x18]
	adds r1, r6, r1
	str r1, [sp, #0x48]
	cmp r0, #0
	bne _0811EB32
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811EA48
	movs r0, #1
	b _0811EA4A
_0811EA48:
	movs r0, #0
_0811EA4A:
	ldr r4, _0811EB44 @ =0x00000482
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x48]
	cmp r0, #0
	bne _0811EB32
	movs r3, #0
	ldr r5, [sp, #0x18]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r5, r5, r6
	mov sb, r5
	ldr r0, [sp, #0x18]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov sl, r0
	ldr r2, [sp, #0x18]
	ldr r4, _0811EB48 @ =0x0000054F
	adds r2, r2, r4
	mov ip, r2
	adds r6, #0xc
	ldr r5, [sp, #0x18]
	adds r6, r5, r6
	str r6, [sp, #0x5c]
	ldr r0, _0811EB4C @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x60]
	adds r1, #6
	adds r1, r5, r1
	str r1, [sp, #0x64]
	ldr r2, _0811EB50 @ =0x00000541
	adds r2, r5, r2
	str r2, [sp, #0x50]
	adds r4, #0x6d
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	ldr r6, _0811EB54 @ =0x00000542
	adds r6, r5, r6
	str r6, [sp, #0x54]
	ldr r6, _0811EB58 @ =0x0203B400
	ldr r1, _0811EB5C @ =0x030046B8
	ldr r5, _0811EB60 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811EAA4:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _0811EAC2
	adds r3, #1
	cmp r3, #3
	ble _0811EAA4
	mov r0, r8
_0811EAC2:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x38]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x50]
	strb r4, [r2]
	ldr r4, [sp, #0x2c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x28]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x58]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r2, [r6]
	ldr r0, [sp, #0x4c]
	str r3, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x54]
	strb r0, [r3]
_0811EB32:
	ldr r0, [sp, #0x18]
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811EB44: .4byte 0x00000482
_0811EB48: .4byte 0x0000054F
_0811EB4C: .4byte 0x0000054D
_0811EB50: .4byte 0x00000541
_0811EB54: .4byte 0x00000542
_0811EB58: .4byte 0x0203B400
_0811EB5C: .4byte 0x030046B8
_0811EB60: .4byte 0x000003FF
_0811EB64:
	add r6, sp, #0x10
	ldr r0, _0811EBA4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811EBA8
	adds r0, #4
	b _0811EBB4
	.align 2, 0
_0811EBA4: .4byte 0x030046A4
_0811EBA8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811EBB4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, [sp, #0x18]
	ldr r6, _0811EBEC @ =0x000004A4
	adds r0, r5, r6
	ldr r4, [r0]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811EBF4
	ldr r0, _0811EBF0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811EC1E
	.align 2, 0
_0811EBEC: .4byte 0x000004A4
_0811EBF0: .4byte 0xFFFFFDFF
_0811EBF4:
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811EC14
	cmp r0, #2
	beq _0811EC10
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811EC10:
	movs r0, #1
	b _0811EC20
_0811EC14:
	ldr r0, _0811EC38 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811EC1E:
	movs r0, #0
_0811EC20:
	cmp r0, #0
	bne _0811EC40
	ldr r4, [sp, #0x18]
	ldr r5, _0811EC3C @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
_0811EC2E:
	bl _call_via_r1
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811EC38: .4byte 0xFFFFFDFF
_0811EC3C: .4byte 0x000005C4
_0811EC40:
	movs r0, #1
_0811EC42:
	cmp r0, #0
	bne _0811EC48
	b _0811EDDA
_0811EC48:
	ldr r6, [sp, #0x18]
	ldr r0, _0811EC54 @ =0x00000482
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _0811EDC4
	.align 2, 0
_0811EC54: .4byte 0x00000482
_0811EC58:
	movs r2, #0x10
	ldr r3, [sp, #0x18]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _0811ECDC @ =0x00000482
	adds r0, r3, r5
	movs r6, #1
	strh r6, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	ldr r5, [sp, #0x18]
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
	ldr r3, _0811ECE0 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r5, r1
	ldr r5, [r0]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811ECD8
	cmp r1, #0
	blt _0811ECD8
	ldr r0, _0811ECE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811ECD8
	ldr r0, _0811ECE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811ECEC
_0811ECD8:
	movs r4, #0
	b _0811ECFA
	.align 2, 0
_0811ECDC: .4byte 0x00000482
_0811ECE0: .4byte 0x00000551
_0811ECE4: .4byte 0x030046A8
_0811ECE8: .4byte 0x030046AC
_0811ECEC:
	ldr r0, _0811ED0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811ECFA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811ED10
	adds r0, #4
	b _0811ED1C
	.align 2, 0
_0811ED0C: .4byte 0x030046A4
_0811ED10:
	ldr r0, _0811ED30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811ED1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811ED34
	cmp r2, #2
	beq _0811ED38
	b _0811ED3C
	.align 2, 0
_0811ED30: .4byte 0x030046A4
_0811ED34:
	ldrb r0, [r5, #4]
	b _0811ED3A
_0811ED38:
	ldrb r0, [r5]
_0811ED3A:
	subs r1, r1, r0
_0811ED3C:
	strh r1, [r5, #2]
	ldr r3, [sp, #0x18]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r3, r4
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _0811ED74 @ =0x000004A4
	adds r0, r3, r5
	ldr r4, [r0]
	adds r5, r3, #0
	adds r5, #8
	ldr r6, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811ED7C
	ldr r0, _0811ED78 @ =0xFFFFFDFF
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811EDA6
	.align 2, 0
_0811ED74: .4byte 0x000004A4
_0811ED78: .4byte 0xFFFFFDFF
_0811ED7C:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811ED9C
	cmp r0, #2
	beq _0811ED98
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811ED98:
	movs r0, #1
	b _0811EDA8
_0811ED9C:
	ldr r0, _0811EDBC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811EDA6:
	movs r0, #0
_0811EDA8:
	cmp r0, #0
	bne _0811EDC4
	ldr r3, [sp, #0x18]
	ldr r4, _0811EDC0 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _0811EDDA
	.align 2, 0
_0811EDBC: .4byte 0xFFFFFDFF
_0811EDC0: .4byte 0x000005C4
_0811EDC4:
	ldr r5, _0811EDEC @ =0x000006BA
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x18]
	ldr r0, _0811EDF0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811EDDA:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811EDEC: .4byte 0x000006BA
_0811EDF0: .4byte 0x00000484
