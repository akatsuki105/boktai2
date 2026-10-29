	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r0, _08148E20 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #0xb
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_081482bc
	ldr r1, _08148E24 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08148E30
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08148E28 @ =0x00003876
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08148E2C @ =0x00009AF2
	bl EnemyAuxSprite_LoadAnim
	ldr r2, _08148E20 @ =0x000001DF
	adds r0, r7, r2
	ldrb r1, [r0]
	str r0, [sp, #0x40]
	cmp r1, #0x11
	beq _08148E0E
	cmp r1, #0x17
	bne _08148E12
_08148E0E:
	movs r0, #1
	strb r0, [r5, #7]
_08148E12:
	movs r3, #0xef
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	b _08148E9A
	.align 2, 0
_08148E20: .4byte 0x000001DF
_08148E24: .4byte 0x0000025D
_08148E28: .4byte 0x00003876
_08148E2C: .4byte 0x00009AF2
_08148E30:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _08148F18 @ =0x05000002
	bl CpuSet
	ldr r0, _08148F1C @ =0x0000CB05
	ldr r1, _08148F20 @ =0x00003876
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r2!, {r3, r6}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r5, r8
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r6, _08148F24 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x40]
_08148E9A:
	str r7, [sp, #0x28]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r4, #0
	str r4, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	str r4, [r2]
	ldr r3, _08148F28 @ =0x0000046F
	adds r0, r7, r3
	strb r4, [r0]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r6, #0
	mov sl, r6
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, _08148F2C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08148F18 @ =0x05000002
	bl CpuSet
	ldr r3, _08148F30 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x174]
	mov r3, r8
	str r3, [sp, #0x178]
	str r6, [sp, #0x150]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _08148F06
	b _08149064
_08148F06:
	bl VM_GetPC
	cmp r0, #0
	beq _08148F34
	bl VM_GetValue
	adds r1, r0, #0
	b _08148F36
	.align 2, 0
_08148F18: .4byte 0x05000002
_08148F1C: .4byte 0x0000CB05
_08148F20: .4byte 0x00003876
_08148F24: .4byte 0x000004B7
_08148F28: .4byte 0x0000046F
_08148F2C: .4byte 0x00000474
_08148F30: .4byte 0x000004B6
_08148F34:
	movs r1, #0
_08148F36:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08148F5C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xa0]
	str r4, [sp, #0xa4]
	cmp r0, #0
	beq _08148F60
	bl VM_GetValue
	adds r1, r0, #0
	b _08148F62
	.align 2, 0
_08148F5C: .4byte 0x00000251
_08148F60:
	movs r1, #0
_08148F62:
	ldr r2, _08148F98 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08148F9C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xa0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xac]
	cmp r0, #0
	beq _08148FA0
	bl VM_GetValue
	b _08148FA4
	.align 2, 0
_08148F98: .4byte 0x00000252
_08148F9C: .4byte 0x000004B4
_08148FA0:
	ldr r4, [sp, #0xa0]
	ldrb r0, [r4]
_08148FA4:
	strb r0, [r6]
	ldr r5, [sp, #0xa0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xac]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl Map_GetPathNodePos
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08148FDC
	cmp r1, #0
	blt _08148FDC
	ldr r0, _08148FE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08148FDC
	ldr r0, _08148FE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08148FE8
_08148FDC:
	movs r1, #0
	b _08148FF6
	.align 2, 0
_08148FE0: .4byte 0x030046A8
_08148FE4: .4byte 0x030046AC
_08148FE8:
	ldr r0, _08149010 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08148FF6:
	ldr r2, _08149014 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08149018
	adds r0, #4
	b _08149024
	.align 2, 0
_08149010: .4byte 0x030046A4
_08149014: .4byte 0x00000256
_08149018:
	ldr r0, _08149038 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08149024:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814903C
	cmp r2, #2
	beq _08149040
	b _08149044
	.align 2, 0
_08149038: .4byte 0x030046A4
_0814903C:
	ldrb r0, [r4, #4]
	b _08149042
_08149040:
	ldrb r0, [r4]
_08149042:
	subs r1, r1, r0
_08149044:
	ldr r3, _0814905C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08149060 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081490A4
	.align 2, 0
_0814905C: .4byte 0x00000472
_08149060: .4byte 0x0000FFFF
_08149064:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081490C8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081490CC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081490D0 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xa0]
	str r4, [sp, #0xa4]
	str r3, [sp, #0xac]
_081490A4:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081490EE
	bl VM_GetPC
	cmp r0, #0
	beq _081490D4
	bl VM_GetValue
	adds r4, r0, #0
	b _081490D6
	.align 2, 0
_081490C8: .4byte 0x00000251
_081490CC: .4byte 0x00000252
_081490D0: .4byte 0x000004B4
_081490D4:
	movs r4, #0x30
_081490D6:
	bl VM_GetPC
	cmp r0, #0
	beq _081490E8
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081490EA
_081490E8:
	movs r5, #0x40
_081490EA:
	mov r8, r4
	b _081490F4
_081490EE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081490F4:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0814912C
	bl VM_GetPC
	cmp r0, #0
	beq _0814910E
	bl VM_GetValue
	adds r6, r0, #0
	b _08149110
_0814910E:
	movs r6, #0
_08149110:
	bl VM_GetPC
	cmp r0, #0
	beq _08149120
	bl VM_GetValue
	adds r1, r0, #0
	b _08149122
_08149120:
	movs r1, #0
_08149122:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08149136
_0814912C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08149136:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _081493A8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x98]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x180]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	lsls r4, r4, #0x10
	str r4, [sp, #0x194]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x38]
	lsls r6, r6, #0x10
	str r6, [sp, #0x3c]
	lsls r5, r5, #0x10
	str r5, [sp, #0x34]
	ldr r4, _081493AC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x190]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x138]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x44]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x48]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x13c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x140]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x134]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x160]
	ldr r1, _081493B0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x154]
	ldr r2, _081493B4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x158]
	ldr r3, _081493B8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x15c]
	ldr r4, _081493BC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x16c]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x170]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x94]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _081493C0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	ldr r6, _081493C4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	ldr r1, _081493C8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r3, _081493CC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0xec]
	ldr r4, _081493D0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0xf4]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _081493D4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x88]
	ldr r1, _081493D8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x118]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	ldr r3, _081493DC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	ldr r4, _081493E0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x108]
	ldr r6, _081493E4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	ldr r2, _081493E8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x110]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _081493EC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x124]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x128]
	ldr r6, _081493F0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x100]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	ldr r3, _081493F4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x104]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	ldr r6, _081493F8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x12c]
	ldr r1, _081493FC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x90]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd0]
	ldr r4, _08149400 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	ldr r6, _08149404 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _08149408 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0xcc]
	ldr r2, _0814940C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x188]
	ldr r5, _08149410 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x168]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x144]
	ldr r1, _08149414 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x148]
	ldr r2, _08149418 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _0814941C @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x50]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r1, _08149420 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x18c]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x78]
	ldr r4, _08149424 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x58]
	ldr r6, _08149428 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0x60]
	ldr r1, _0814942C @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _08149430 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r3, _08149434 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08149438 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0x74]
	cmp r0, #0
	bne _08149378
	b _08149492
_08149378:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_08149398:
	bl VM_GetPC
	cmp r0, #0
	beq _0814943C
	bl VM_GetValue
	b _0814943E
	.align 2, 0
_081493A8: .4byte 0x0000025D
_081493AC: .4byte 0x0000025A
_081493B0: .4byte 0x0000047A
_081493B4: .4byte 0x0000047C
_081493B8: .4byte 0x0000047E
_081493BC: .4byte 0x000004A4
_081493C0: .4byte 0x000005A4
_081493C4: .4byte 0x000005C4
_081493C8: .4byte 0x000005CC
_081493CC: .4byte 0x000005D4
_081493D0: .4byte 0x000005DC
_081493D4: .4byte 0x00000584
_081493D8: .4byte 0x00000604
_081493DC: .4byte 0x0000021D
_081493E0: .4byte 0x0000060C
_081493E4: .4byte 0x000005E4
_081493E8: .4byte 0x000005FC
_081493EC: .4byte 0x00000614
_081493F0: .4byte 0x000005BC
_081493F4: .4byte 0x000005EC
_081493F8: .4byte 0x00000624
_081493FC: .4byte 0x0000058C
_08149400: .4byte 0x00000594
_08149404: .4byte 0x0000059C
_08149408: .4byte 0x000005B4
_0814940C: .4byte 0x00000543
_08149410: .4byte 0x00000496
_08149414: .4byte 0x00000469
_08149418: .4byte 0x0000046A
_0814941C: .4byte 0x00000553
_08149420: .4byte 0x00000572
_08149424: .4byte 0x0000055C
_08149428: .4byte 0x00000564
_0814942C: .4byte 0x00000565
_08149430: .4byte 0x00000566
_08149434: .4byte 0x00000567
_08149438: .4byte 0x0000056C
_0814943C:
	movs r0, #0x18
_0814943E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08149450
	bl VM_GetValue
	b _08149452
_08149450:
	movs r0, #0x18
_08149452:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08149464
	bl VM_GetValue
	b _08149466
_08149464:
	movs r0, #0
_08149466:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08149478
	bl VM_GetValue
	b _0814947A
_08149478:
	movs r0, #0
_0814947A:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _08149398
_08149492:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081494DE
	bl VM_GetPC
	cmp r0, #0
	beq _081494AC
	bl VM_GetValue
	adds r4, r0, #0
	b _081494B0
_081494AC:
	movs r4, #0x96
	lsls r4, r4, #1
_081494B0:
	bl VM_GetPC
	cmp r0, #0
	beq _081494C0
	bl VM_GetValue
	adds r6, r0, #0
	b _081494C4
_081494C0:
	movs r6, #0x96
	lsls r6, r6, #1
_081494C4:
	bl VM_GetPC
	cmp r0, #0
	beq _081494D2
	bl VM_GetValue
	b _081494D8
_081494D2:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_081494D8:
	ldr r5, [sp, #0x98]
	strh r0, [r5]
	b _081494E6
_081494DE:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0x98]
	strh r6, [r0]
_081494E6:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081494FE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x178]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081494FE:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x180]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x17c]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081495CC
	bl VM_GetPC
	cmp r0, #0
	beq _0814952E
	bl VM_GetValue
	b _08149530
_0814952E:
	movs r0, #0
_08149530:
	ldr r1, [sp, #0xb0]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814953E
	asrs r1, r0, #1
	b _08149544
_0814953E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08149544:
	ldr r2, _08149558 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0814955C
	bl VM_GetValue
	b _0814955E
	.align 2, 0
_08149558: .4byte 0x00000546
_0814955C:
	movs r0, #0
_0814955E:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08149574
	bl VM_GetValue
	b _08149576
_08149574:
	movs r0, #0
_08149576:
	ldr r5, _0814958C @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08149590
	bl VM_GetValue
	adds r1, r0, #0
	b _08149592
	.align 2, 0
_0814958C: .4byte 0x00000187
_08149590:
	movs r1, #0
_08149592:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081495A8
	bl VM_GetValue
	b _081495AA
_081495A8:
	movs r0, #0
_081495AA:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081495C2
	bl VM_GetValue
	adds r1, r0, #0
	b _081495C4
_081495C2:
	movs r1, #0
_081495C4:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_081495CC:
	ldr r0, [sp, #0xb0]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x194]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x38]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x3c]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x34]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0814962E
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08149614
	bl VM_GetValue
	b _08149616
_08149614:
	movs r0, #0
_08149616:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08149626
	bl VM_GetValue
	b _08149628
_08149626:
	movs r0, #0
_08149628:
	ldr r2, _08149690 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0814962E:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0xbc]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08149652
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x178]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08149652:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0814966A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x178]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0814966A:
	ldr r6, [sp, #0x190]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x150]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08149694
	movs r0, #1
	b _08149696
	.align 2, 0
_08149690: .4byte 0x00000189
_08149694:
	movs r0, #0
_08149696:
	cmp r0, #0
	beq _081496A6
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081496D0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl Entity5941_Register
_081496A6:
	ldr r3, [sp, #0xc0]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081496B2
	ldr r1, [r7, #0x44]
_081496B2:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081496D4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x138]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081496E0
	.align 2, 0
_081496D0: .4byte FUN_080f48ac
_081496D4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x138]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081496E0:
	ldr r5, [sp, #0x40]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0814972E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0814972E
	cmp r0, #0x16
	beq _0814972E
	cmp r0, #0x14
	beq _0814972E
	cmp r0, #9
	beq _0814972E
	cmp r0, #0x19
	beq _0814972E
	cmp r0, #0x1a
	beq _0814972E
	cmp r0, #0xd
	beq _0814972E
	cmp r0, #0x1b
	beq _0814972E
	cmp r0, #0x1f
	beq _0814972E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xa0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xa4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_0814972E:
	movs r1, #8
	ldr r5, [sp, #0x150]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814973E
	movs r0, #1
	b _08149740
_0814973E:
	movs r0, #0
_08149740:
	cmp r0, #0
	beq _0814974E
	ldr r6, [sp, #0x48]
	ldr r0, [r6]
	ldr r1, [sp, #0x44]
	str r0, [r1]
	b _08149760
_0814974E:
	ldr r2, [sp, #0x48]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x44]
	str r0, [r3]
_08149760:
	ldrh r0, [r7]
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	ldr r5, [sp, #0x134]
	ldr r6, [sp, #0x140]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0814978A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_0814978A:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r7, #5]
	movs r0, #0x73
	movs r1, #0xa
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x24]
	ldr r3, _081497BC @ =0x00000692
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08149894
	bl VM_GetPC
	cmp r0, #0
	beq _081497C0
	bl VM_GetValue
	b _081497C2
	.align 2, 0
_081497BC: .4byte 0x00000692
_081497C0:
	movs r0, #0
_081497C2:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081497D2
	bl VM_GetValue
	b _081497D4
_081497D2:
	movs r0, #0
_081497D4:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081497E4
	bl VM_GetValue
	b _081497E6
_081497E4:
	movs r0, #0
_081497E6:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r4, [sp, #0x134]
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814980E
	cmp r1, #0
	blt _0814980E
	ldr r0, _08149814 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814980E
	ldr r0, _08149818 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814981C
_0814980E:
	movs r2, #0
	b _0814982A
	.align 2, 0
_08149814: .4byte 0x030046A8
_08149818: .4byte 0x030046AC
_0814981C:
	ldr r0, _0814984C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0814982A:
	ldr r5, _08149850 @ =0x00000256
	adds r1, r7, r5
	strh r2, [r1]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r7, r6
	strh r2, [r0]
	ldrh r4, [r1]
	ldr r5, [sp, #0x134]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08149854
	adds r0, #4
	b _08149860
	.align 2, 0
_0814984C: .4byte 0x030046A4
_08149850: .4byte 0x00000256
_08149854:
	ldr r0, _08149874 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08149860:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08149878
	cmp r3, #2
	beq _0814987C
	b _08149880
	.align 2, 0
_08149874: .4byte 0x030046A4
_08149878:
	ldrb r0, [r5, #4]
	b _0814987E
_0814987C:
	ldrb r0, [r5]
_0814987E:
	subs r2, r2, r0
_08149880:
	ldr r0, _081498E8 @ =0x00000472
	adds r1, r7, r0
	movs r0, #0
	strh r2, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
_08149894:
	ldr r4, [sp, #0x24]
	ldr r5, _081498EC @ =0x00000684
	adds r2, r4, r5
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _081498F0 @ =0x00000256
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _081498F4 @ =0x0000068C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r4, _081498F8 @ =0x0000028A
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x160]
	strh r0, [r3]
	ldr r6, [sp, #0x154]
	strh r4, [r6]
	ldr r0, [sp, #0x158]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x15c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081498FC
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08149908
	.align 2, 0
_081498E8: .4byte 0x00000472
_081498EC: .4byte 0x00000684
_081498F0: .4byte 0x00000256
_081498F4: .4byte 0x0000068C
_081498F8: .4byte 0x0000028A
_081498FC:
	ldr r2, [r7, #0x44]
	ldr r0, _08149940 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08149908:
	ldr r3, [sp, #0xc0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08149958
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08149944
	movs r0, #5
	bl Enemy_CountByKind
	adds r4, r0, #1
	movs r0, #6
	bl Enemy_CountByKind
	adds r4, r4, r0
	movs r0, #7
	bl Enemy_CountByKind
	adds r4, r4, r0
	movs r0, #8
	bl Enemy_CountByKind
	adds r4, r4, r0
	b _0814994E
	.align 2, 0
_08149940: .4byte 0x03003584
_08149944:
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0814994E:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08149958:
	adds r0, r7, #0
	bl FUN_0814842c
	ldr r6, [sp, #0x24]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r6, r0
	ldr r1, _08149AE4 @ =0x0000067C
	adds r4, r6, r1
	ldr r5, _08149AE8 @ =FUN_08148c7c
	movs r2, #0
	ldr r6, _08149AEC @ =FUN_08146fcc
	mov r8, r6
	ldr r0, _08149AF0 @ =FUN_081474e8
	mov sb, r0
	ldr r1, _08149AF4 @ =FUN_081477dc
	mov sl, r1
	ldr r6, _08149AF8 @ =FUN_081475b8
	mov ip, r6
	ldr r0, _08149AFC @ =FUN_081489ec
	str r0, [sp, #0x1a0]
	ldr r1, _08149B00 @ =FUN_080f62ac
	str r1, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x174]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x16c]
	str r3, [r0]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r3, [sp, #0x84]
	str r5, [r3]
	ldr r4, [sp, #0x8c]
	str r2, [r4]
	ldr r5, [sp, #0x94]
	str r2, [r5]
	mov r6, r8
	ldr r0, [sp, #0xb8]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xc4]
	str r1, [r3]
	ldr r4, [sp, #0xd8]
	str r2, [r4]
	ldr r5, [sp, #0x1a0]
	ldr r6, [sp, #0xdc]
	str r5, [r6]
	mov r0, sl
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	mov r3, ip
	ldr r4, [sp, #0xe8]
	str r3, [r4]
	ldr r0, _08149B04 @ =FUN_080f44f4
	ldr r5, [sp, #0xec]
	str r0, [r5]
	ldr r0, _08149B08 @ =FUN_080f410c
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r0, [sp, #0xe0]
	str r2, [r0]
	ldr r1, [sp, #0x88]
	str r2, [r1]
	ldr r3, [sp, #0x198]
	ldr r4, [sp, #0x118]
	str r3, [r4]
	ldr r0, _08149B0C @ =FUN_080f0430
	ldr r5, [sp, #0x11c]
	str r0, [r5]
	movs r0, #1
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	ldr r0, _08149B10 @ =0x085AD470
	ldr r1, [sp, #0x120]
	str r0, [r1]
	ldr r0, _08149B14 @ =FUN_080e73c8
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r4, [sp, #0xfc]
	str r2, [r4]
	ldr r5, [sp, #0x10c]
	str r2, [r5]
	ldr r6, [sp, #0x110]
	str r2, [r6]
	ldr r0, [sp, #0x114]
	str r2, [r0]
	ldr r1, [sp, #0x124]
	str r2, [r1]
	ldr r0, _08149B18 @ =FUN_080f0320
	ldr r3, [sp, #0x128]
	str r0, [r3]
	ldr r0, _08149B1C @ =Enemy_080eff14
	ldr r4, [sp, #0xd4]
	str r0, [r4]
	ldr r0, _08149B20 @ =FUN_080e72b0
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r6, [sp, #0xf8]
	str r2, [r6]
	ldr r0, _08149B24 @ =FUN_080f47c8
	ldr r1, [sp, #0x104]
	str r0, [r1]
	ldr r0, _08149B28 @ =FUN_080f54e4
	ldr r3, [sp, #0xf0]
	str r0, [r3]
	ldr r4, [sp, #0xc8]
	str r2, [r4]
	ldr r0, _08149B2C @ =FUN_080f6e64
	ldr r5, [sp, #0x12c]
	str r0, [r5]
	ldr r0, _08149B30 @ =FUN_080f64f0
	ldr r6, [sp, #0x90]
	str r0, [r6]
	ldr r0, _08149B34 @ =FUN_080f84d4
	ldr r1, [sp, #0x130]
	str r0, [r1]
	ldr r0, _08149B38 @ =FUN_080f624c
	ldr r3, [sp, #0xd0]
	str r0, [r3]
	ldr r0, _08149B3C @ =FUN_080f56ec
	ldr r4, [sp, #0x9c]
	str r0, [r4]
	ldr r0, _08149B40 @ =FUN_080f5b34
	ldr r5, [sp, #0xa8]
	str r0, [r5]
	ldr r0, _08149B44 @ =FUN_080f5fac
	ldr r6, [sp, #0xb4]
	str r0, [r6]
	ldr r0, [sp, #0xcc]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x4c]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08149B48 @ =FUN_08147a38
	str r0, [r1]
	ldr r4, _08149B4C @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _08149B50 @ =FUN_081488bc
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08149B54 @ =FUN_08148784
	str r0, [r1]
	ldr r0, _08149B58 @ =0x0000058C
	adds r1, r7, r0
	ldr r0, _08149B5C @ =FUN_08148af4
	str r0, [r1]
	ldr r1, _08149B60 @ =0x00400200
	ldr r2, [sp, #0x174]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x178]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x150]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x184]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08149B6E
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08149AD6:
	bl VM_GetPC
	cmp r0, #0
	beq _08149B64
	bl VM_GetValue
	b _08149B66
	.align 2, 0
_08149AE4: .4byte 0x0000067C
_08149AE8: .4byte FUN_08148c7c
_08149AEC: .4byte FUN_08146fcc
_08149AF0: .4byte FUN_081474e8
_08149AF4: .4byte FUN_081477dc
_08149AF8: .4byte FUN_081475b8
_08149AFC: .4byte FUN_081489ec
_08149B00: .4byte FUN_080f62ac
_08149B04: .4byte FUN_080f44f4
_08149B08: .4byte FUN_080f410c
_08149B0C: .4byte FUN_080f0430
_08149B10: .4byte 0x085AD470
_08149B14: .4byte FUN_080e73c8
_08149B18: .4byte FUN_080f0320
_08149B1C: .4byte Enemy_080eff14
_08149B20: .4byte FUN_080e72b0
_08149B24: .4byte FUN_080f47c8
_08149B28: .4byte FUN_080f54e4
_08149B2C: .4byte FUN_080f6e64
_08149B30: .4byte FUN_080f64f0
_08149B34: .4byte FUN_080f84d4
_08149B38: .4byte FUN_080f624c
_08149B3C: .4byte FUN_080f56ec
_08149B40: .4byte FUN_080f5b34
_08149B44: .4byte FUN_080f5fac
_08149B48: .4byte FUN_08147a38
_08149B4C: .4byte 0x000005AC
_08149B50: .4byte FUN_081488bc
_08149B54: .4byte FUN_08148784
_08149B58: .4byte 0x0000058C
_08149B5C: .4byte FUN_08148af4
_08149B60: .4byte 0x00400200
_08149B64:
	movs r0, #0
_08149B66:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08149AD6
_08149B6E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x188]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x168]
	strh r0, [r3]
	cmp r2, #0
	beq _08149BA6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x174]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08149BA6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08149BA6:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x150]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08149BB8
	movs r0, #1
	b _08149BBA
_08149BB8:
	movs r0, #0
_08149BBA:
	cmp r0, #0
	beq _08149BCC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x178]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08149BCC:
	cmp r2, #1
	beq _08149C0C
	movs r1, #0
	ldr r0, [sp, #0x144]
	strb r1, [r0]
	ldr r2, [sp, #0x148]
	strb r1, [r2]
	ldr r3, [sp, #0x14c]
	strb r1, [r3]
	ldr r4, _08149C1C @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08149C20 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xc4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x50]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08149C0C:
	movs r1, #2
	ldr r3, [sp, #0x150]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08149C24
	movs r0, #1
	b _08149C26
	.align 2, 0
_08149C1C: .4byte 0x00000484
_08149C20: .4byte 0x0000046C
_08149C24:
	movs r0, #0
_08149C26:
	cmp r0, #0
	beq _08149C40
	ldr r0, _08149C3C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x164]
	strh r0, [r5]
	b _08149C4A
	.align 2, 0
_08149C3C: .4byte 0x030046A0
_08149C40:
	ldr r0, [sp, #0x134]
	bl GetZoneAt
	ldr r6, [sp, #0x164]
	strh r0, [r6]
_08149C4A:
	movs r1, #0x40
	ldr r2, [sp, #0x150]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08149C5A
	movs r0, #1
	b _08149C5C
_08149C5A:
	movs r0, #0
_08149C5C:
	cmp r0, #0
	beq _08149C6C
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08149C90 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08149C6C:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08149C9E
	ldr r0, _08149C94 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x164]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08149C98
	movs r0, #1
	b _08149C9A
	.align 2, 0
_08149C90: .4byte 0xFFFFFEFF
_08149C94: .4byte 0x030046A0
_08149C98:
	movs r0, #0
_08149C9A:
	cmp r0, #0
	bne _08149CA6
_08149C9E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08149CA6:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xc0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08149D8E
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08149CE8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08149CF0
_08149CE8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08149CF0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08149D14
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08149D1C
_08149D14:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08149D1C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08149D54 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08149D98
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08149D58
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08149D4C
	ldrb r0, [r4, #5]
_08149D4C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08149D68
	.align 2, 0
_08149D54: .4byte 0x0000FFFF
_08149D58:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08149D68
	strh r1, [r4, #8]
_08149D68:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08149D98
	movs r0, #1
	strb r0, [r4, #7]
	b _08149D98
_08149D8E:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08149D98:
	movs r0, #0
	ldr r3, [sp, #0x30]
	str r0, [r3]
	ldr r0, _08149DB0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08149DB4
	movs r0, #1
	b _08149DB6
	.align 2, 0
_08149DB0: .4byte 0x030047A4
_08149DB4:
	movs r0, #0
_08149DB6:
	cmp r0, #0
	bne _08149DF6
	ldr r4, [sp, #0x40]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08149DDE
	adds r0, r1, #0
	cmp r0, #7
	beq _08149DDE
	cmp r0, #6
	beq _08149DDE
	cmp r0, #0x15
	beq _08149DDE
	cmp r0, #0x14
	beq _08149DDE
	cmp r0, #0x17
	bne _08149DF6
_08149DDE:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x150]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08149DF6:
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08149E4A
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r1, #0
	movs r5, #0
	strh r0, [r2]
	ldr r3, _08149EF4 @ =FUN_08147428
	movs r2, #0x25
	ldr r4, _08149EF8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08149EFC @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	ldr r2, [sp, #0x80]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r0, #3
	ldr r6, [sp, #0x144]
	strb r0, [r6]
	ldr r0, [sp, #0x148]
	strb r1, [r0]
	ldr r2, [sp, #0x14c]
	strb r1, [r2]
	ldr r3, _08149F00 @ =0x00000484
	adds r0, r7, r3
	str r5, [r0]
	ldr r5, _08149F04 @ =0x0000046C
	adds r0, r7, r5
	strb r4, [r0]
_08149E4A:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_08146fac
	adds r0, r7, #0
	bl FUN_08148c6c
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	strh r0, [r1]
	ldr r1, [sp, #0x150]
	ldrh r0, [r1]
	ldr r2, [sp, #0x7c]
	strh r0, [r2]
	ldr r3, [sp, #0x18c]
	ldrh r0, [r3]
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	ldr r5, [sp, #0x174]
	ldr r0, [r5]
	ldr r6, [sp, #0x54]
	str r0, [r6]
	ldr r1, [sp, #0x178]
	ldr r0, [r1]
	ldr r2, [sp, #0x58]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, [sp, #0x144]
	ldrb r0, [r4]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x148]
	ldrb r0, [r6]
	ldr r1, [sp, #0x68]
	strb r0, [r1]
	ldr r2, [sp, #0x14c]
	ldrb r0, [r2]
	ldr r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	ldr r5, [sp, #0x70]
	str r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x74]
	strb r0, [r1]
	ldr r2, _08149F08 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0xb
	strb r0, [r1]
	ldr r3, _08149F0C @ =0x0000057C
	adds r1, r7, r3
	ldr r0, _08149F10 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r4, _08149F14 @ =0x0000061C
	adds r1, r7, r4
	ldr r0, _08149F18 @ =FUN_08148cb4
	str r0, [r1]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08149F1C @ =EnemyMimic_Destroy
	str r0, [r1]
	movs r6, #0x8f
	lsls r6, r6, #3
	adds r1, r7, r6
	movs r0, #0xa3
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08149F20
	movs r0, #0
	b _08149F24
	.align 2, 0
_08149EF4: .4byte FUN_08147428
_08149EF8: .4byte 0x0000046D
_08149EFC: .4byte 0x0000046B
_08149F00: .4byte 0x00000484
_08149F04: .4byte 0x0000046C
_08149F08: .4byte 0x000001DF
_08149F0C: .4byte 0x0000057C
_08149F10: .4byte Enemy_DispatchMsg
_08149F14: .4byte 0x0000061C
_08149F18: .4byte FUN_08148cb4
_08149F1C: .4byte EnemyMimic_Destroy
_08149F20:
	movs r0, #1
	rsbs r0, r0, #0
_08149F24:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
