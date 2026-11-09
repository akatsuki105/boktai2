	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x19c
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	adds r0, r7, #0
	bl Octopus_InitAnims
	ldr r2, _08187758 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08187768
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0818775C @ =0x0000D291
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08187760 @ =0x0000DCEB
	bl EnemyAuxSprite_LoadAnim
	ldr r3, _08187764 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _08187746
	cmp r1, #0x17
	bne _0818774A
_08187746:
	movs r0, #1
	strb r0, [r5, #7]
_0818774A:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081877D0
	.align 2, 0
_08187758: .4byte 0x0000025D
_0818775C: .4byte 0x0000D291
_08187760: .4byte 0x0000DCEB
_08187764: .4byte 0x000001DF
_08187768:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _0818784C @ =0x05000002
	bl CpuSet
	ldr r0, _08187850 @ =0x0000CB05
	ldr r1, _08187854 @ =0x0000D291
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
	ldr r6, _08187858 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x9c]
_081877D0:
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
	ldr r3, _0818785C @ =0x0000046F
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
	ldr r1, _08187860 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0818784C @ =0x05000002
	bl CpuSet
	ldr r3, _08187864 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x198]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x54]
	mov r3, r8
	str r3, [sp, #0x5c]
	str r6, [sp, #0x44]
	ldr r2, [sp, #0x198]
	adds r6, r2, #0
	cmp r0, #0
	bne _0818783C
	b _08187998
_0818783C:
	bl VM_GetPC
	cmp r0, #0
	beq _08187868
	bl VM_GetValue
	adds r1, r0, #0
	b _0818786A
	.align 2, 0
_0818784C: .4byte 0x05000002
_08187850: .4byte 0x0000CB05
_08187854: .4byte 0x0000D291
_08187858: .4byte 0x000004B7
_0818785C: .4byte 0x0000046F
_08187860: .4byte 0x00000474
_08187864: .4byte 0x000004B6
_08187868:
	movs r1, #0
_0818786A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08187890 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	cmp r0, #0
	beq _08187894
	bl VM_GetValue
	adds r1, r0, #0
	b _08187896
	.align 2, 0
_08187890: .4byte 0x00000251
_08187894:
	movs r1, #0
_08187896:
	ldr r2, _081878CC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081878D0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xb8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc0]
	cmp r0, #0
	beq _081878D4
	bl VM_GetValue
	b _081878D8
	.align 2, 0
_081878CC: .4byte 0x00000252
_081878D0: .4byte 0x000004B4
_081878D4:
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
_081878D8:
	strb r0, [r6]
	ldr r5, [sp, #0xb8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc0]
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
	blt _08187910
	cmp r1, #0
	blt _08187910
	ldr r0, _08187914 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08187910
	ldr r0, _08187918 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818791C
_08187910:
	movs r1, #0
	b _0818792A
	.align 2, 0
_08187914: .4byte 0x030046A8
_08187918: .4byte 0x030046AC
_0818791C:
	ldr r0, _08187944 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0818792A:
	ldr r2, _08187948 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818794C
	adds r0, #4
	b _08187958
	.align 2, 0
_08187944: .4byte 0x030046A4
_08187948: .4byte 0x00000256
_0818794C:
	ldr r0, _0818796C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08187958:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08187970
	cmp r2, #2
	beq _08187974
	b _08187978
	.align 2, 0
_0818796C: .4byte 0x030046A4
_08187970:
	ldrb r0, [r4, #4]
	b _08187976
_08187974:
	ldrb r0, [r4]
_08187976:
	subs r1, r1, r0
_08187978:
	ldr r3, _08187990 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08187994 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081879D8
	.align 2, 0
_08187990: .4byte 0x00000472
_08187994: .4byte 0x0000FFFF
_08187998:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081879FC @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08187A00 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08187A04 @ =0x000004B4
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
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
_081879D8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08187A22
	bl VM_GetPC
	cmp r0, #0
	beq _08187A08
	bl VM_GetValue
	adds r4, r0, #0
	b _08187A0A
	.align 2, 0
_081879FC: .4byte 0x00000251
_08187A00: .4byte 0x00000252
_08187A04: .4byte 0x000004B4
_08187A08:
	movs r4, #0x30
_08187A0A:
	bl VM_GetPC
	cmp r0, #0
	beq _08187A1C
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08187A1E
_08187A1C:
	movs r5, #0x40
_08187A1E:
	mov r8, r4
	b _08187A28
_08187A22:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08187A28:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08187A60
	bl VM_GetPC
	cmp r0, #0
	beq _08187A42
	bl VM_GetValue
	adds r6, r0, #0
	b _08187A44
_08187A42:
	movs r6, #0
_08187A44:
	bl VM_GetPC
	cmp r0, #0
	beq _08187A54
	bl VM_GetValue
	adds r1, r0, #0
	b _08187A56
_08187A54:
	movs r1, #0
_08187A56:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08187A6A
_08187A60:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08187A6A:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08187CDC @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xd4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x88]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x90]
	lsls r6, r6, #0x10
	str r6, [sp, #0x94]
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	ldr r4, _08187CE0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x84]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x194]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x30]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x34]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x184]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r1, _08187CE4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _08187CE8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r3, _08187CEC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x50]
	ldr r4, _08187CF0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x78]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	ldr r4, _08187CF4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _08187CF8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x138]
	ldr r1, _08187CFC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x140]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x144]
	ldr r3, _08187D00 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _08187D04 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x150]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08187D08 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _08187D0C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x174]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _08187D10 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	ldr r4, _08187D14 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _08187D18 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	ldr r2, _08187D1C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _08187D20 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x180]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _08187D24 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x15c]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x154]
	ldr r3, _08187D28 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x160]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _08187D2C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	ldr r1, _08187D30 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _08187D34 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x110]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x114]
	ldr r6, _08187D38 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x118]
	ldr r1, _08187D3C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08187D40 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xac]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _08187D44 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r1, _08187D48 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r2, _08187D4C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _08187D50 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x98]
	ldr r1, _08187D54 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x80]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf0]
	ldr r4, _08187D58 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xc8]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xcc]
	ldr r6, _08187D5C @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08187D60 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	ldr r2, _08187D64 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _08187D68 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	ldr r5, _08187D6C @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xec]
	cmp r0, #0
	bne _08187CAC
	b _08187DC6
_08187CAC:
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
_08187CCC:
	bl VM_GetPC
	cmp r0, #0
	beq _08187D70
	bl VM_GetValue
	b _08187D72
	.align 2, 0
_08187CDC: .4byte 0x0000025D
_08187CE0: .4byte 0x0000025A
_08187CE4: .4byte 0x0000047A
_08187CE8: .4byte 0x0000047C
_08187CEC: .4byte 0x0000047E
_08187CF0: .4byte 0x000004A4
_08187CF4: .4byte 0x000005A4
_08187CF8: .4byte 0x000005C4
_08187CFC: .4byte 0x000005CC
_08187D00: .4byte 0x000005D4
_08187D04: .4byte 0x000005DC
_08187D08: .4byte 0x00000584
_08187D0C: .4byte 0x00000604
_08187D10: .4byte 0x0000021D
_08187D14: .4byte 0x0000060C
_08187D18: .4byte 0x000005E4
_08187D1C: .4byte 0x000005FC
_08187D20: .4byte 0x00000614
_08187D24: .4byte 0x000005BC
_08187D28: .4byte 0x000005EC
_08187D2C: .4byte 0x00000624
_08187D30: .4byte 0x0000058C
_08187D34: .4byte 0x00000594
_08187D38: .4byte 0x0000059C
_08187D3C: .4byte 0x000005B4
_08187D40: .4byte 0x00000543
_08187D44: .4byte 0x00000496
_08187D48: .4byte 0x00000469
_08187D4C: .4byte 0x0000046A
_08187D50: .4byte 0x00000553
_08187D54: .4byte 0x00000572
_08187D58: .4byte 0x0000055C
_08187D5C: .4byte 0x00000564
_08187D60: .4byte 0x00000565
_08187D64: .4byte 0x00000566
_08187D68: .4byte 0x00000567
_08187D6C: .4byte 0x0000056C
_08187D70:
	movs r0, #0x18
_08187D72:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08187D84
	bl VM_GetValue
	b _08187D86
_08187D84:
	movs r0, #0x18
_08187D86:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08187D98
	bl VM_GetValue
	b _08187D9A
_08187D98:
	movs r0, #0
_08187D9A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08187DAC
	bl VM_GetValue
	b _08187DAE
_08187DAC:
	movs r0, #0
_08187DAE:
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
	ble _08187CCC
_08187DC6:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08187E12
	bl VM_GetPC
	cmp r0, #0
	beq _08187DE0
	bl VM_GetValue
	adds r4, r0, #0
	b _08187DE4
_08187DE0:
	movs r4, #0x96
	lsls r4, r4, #1
_08187DE4:
	bl VM_GetPC
	cmp r0, #0
	beq _08187DF4
	bl VM_GetValue
	adds r6, r0, #0
	b _08187DF8
_08187DF4:
	movs r6, #0x96
	lsls r6, r6, #1
_08187DF8:
	bl VM_GetPC
	cmp r0, #0
	beq _08187E06
	bl VM_GetValue
	b _08187E0C
_08187E06:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_08187E0C:
	ldr r5, [sp, #0xb0]
	strh r0, [r5]
	b _08187E1A
_08187E12:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0xb0]
	strh r6, [r0]
_08187E1A:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08187E32
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08187E32:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x68]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08187F00
	bl VM_GetPC
	cmp r0, #0
	beq _08187E62
	bl VM_GetValue
	b _08187E64
_08187E62:
	movs r0, #0
_08187E64:
	ldr r1, [sp, #0xc4]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08187E72
	asrs r1, r0, #1
	b _08187E78
_08187E72:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08187E78:
	ldr r2, _08187E8C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08187E90
	bl VM_GetValue
	b _08187E92
	.align 2, 0
_08187E8C: .4byte 0x00000546
_08187E90:
	movs r0, #0
_08187E92:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EA8
	bl VM_GetValue
	b _08187EAA
_08187EA8:
	movs r0, #0
_08187EAA:
	ldr r5, _08187EC0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EC4
	bl VM_GetValue
	adds r1, r0, #0
	b _08187EC6
	.align 2, 0
_08187EC0: .4byte 0x00000187
_08187EC4:
	movs r1, #0
_08187EC6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EDC
	bl VM_GetValue
	b _08187EDE
_08187EDC:
	movs r0, #0
_08187EDE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08187EF6
	bl VM_GetValue
	adds r1, r0, #0
	b _08187EF8
_08187EF6:
	movs r1, #0
_08187EF8:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08187F00:
	ldr r0, [sp, #0xc4]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0x88]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x90]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x94]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x8c]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08187F62
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08187F48
	bl VM_GetValue
	b _08187F4A
_08187F48:
	movs r0, #0
_08187F4A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08187F5A
	bl VM_GetValue
	b _08187F5C
_08187F5A:
	movs r0, #0
_08187F5C:
	ldr r2, _08187FC4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08187F62:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0xd0]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08187F86
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x5c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08187F86:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08187F9E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08187F9E:
	ldr r6, [sp, #0x84]
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
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08187FC8
	movs r0, #1
	b _08187FCA
	.align 2, 0
_08187FC4: .4byte 0x00000189
_08187FC8:
	movs r0, #0
_08187FCA:
	cmp r0, #0
	beq _08187FDA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08188004 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_08187FDA:
	ldr r3, [sp, #0xd4]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08187FE6
	ldr r1, [r7, #0x44]
_08187FE6:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x9c]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08188008
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x194]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08188014
	.align 2, 0
_08188004: .4byte Enemy_OnCWolfMessage
_08188008:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x194]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08188014:
	ldr r5, [sp, #0x9c]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08188062
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08188062
	cmp r0, #0x16
	beq _08188062
	cmp r0, #0x14
	beq _08188062
	cmp r0, #9
	beq _08188062
	cmp r0, #0x19
	beq _08188062
	cmp r0, #0x1a
	beq _08188062
	cmp r0, #0xd
	beq _08188062
	cmp r0, #0x1b
	beq _08188062
	cmp r0, #0x1f
	beq _08188062
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xb8]
	ldrb r2, [r6]
	ldr r0, [sp, #0xbc]
	ldrb r3, [r0]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_08188062:
	movs r1, #8
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08188072
	movs r0, #1
	b _08188074
_08188072:
	movs r0, #0
_08188074:
	cmp r0, #0
	beq _08188082
	ldr r6, [sp, #0xa4]
	ldr r0, [r6]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	b _08188094
_08188082:
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa0]
	str r0, [r3]
_08188094:
	ldrh r0, [r7]
	ldr r4, [sp, #0x30]
	strh r0, [r4]
	ldr r5, [sp, #0x184]
	ldr r6, [sp, #0x34]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081880BE
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
_081880BE:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08188122
	bl VM_GetPC
	cmp r0, #0
	beq _081880D8
	bl VM_GetValue
	adds r1, r0, #0
	b _081880DA
_081880D8:
	movs r1, #0
_081880DA:
	ldr r2, [sp, #0x24]
	ldr r3, _081880F4 @ =0x0000066A
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081880F8
	bl VM_GetValue
	adds r1, r0, #0
	b _081880FA
	.align 2, 0
_081880F4: .4byte 0x0000066A
_081880F8:
	movs r1, #0
_081880FA:
	ldr r4, [sp, #0x24]
	ldr r5, _08188114 @ =0x0000066E
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08188118
	bl VM_GetValue
	adds r1, r0, #0
	b _0818811A
	.align 2, 0
_08188114: .4byte 0x0000066E
_08188118:
	movs r1, #0
_0818811A:
	ldr r6, [sp, #0x24]
	ldr r2, _08188144 @ =0x0000066D
	adds r0, r6, r2
	strb r1, [r0]
_08188122:
	ldrh r0, [r7, #8]
	adds r0, #0x20
	strh r0, [r7, #8]
	ldrh r0, [r7, #0xc]
	adds r0, #0x20
	strh r0, [r7, #0xc]
	ldr r3, [sp, #0xd4]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08188148
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08188152
	.align 2, 0
_08188144: .4byte 0x0000066D
_08188148:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08188152:
	ldr r4, _08188190 @ =0x000001BF
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	ldr r0, [sp, #0x48]
	strh r4, [r0]
	ldr r1, [sp, #0x4c]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x50]
	strh r0, [r2]
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	cmp r0, #0
	bne _08188194
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081881A0
	.align 2, 0
_08188190: .4byte 0x000001BF
_08188194:
	ldr r2, [r7, #0x44]
	ldr r0, _081881D8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081881A0:
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	cmp r0, #1
	bne _081881F0
	ldr r6, [sp, #0x9c]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081881DC
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
	b _081881E6
	.align 2, 0
_081881D8: .4byte 0x03003584
_081881DC:
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081881E6:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081881F0:
	adds r0, r7, #0
	bl Octopus_InitHitboxes
	ldr r2, [sp, #0x24]
	movs r4, #0xce
	lsls r4, r4, #3
	adds r3, r2, r4
	ldr r5, _0818838C @ =0x00000694
	adds r4, r2, r5
	ldr r5, _08188390 @ =Octopus_UpdateFrame
	movs r1, #0
	ldr r6, _08188394 @ =FUN_08184dd8
	mov sb, r6
	ldr r0, _08188398 @ =Octopus_StateDying
	mov ip, r0
	ldr r2, _0818839C @ =FUN_080f62ac
	mov r8, r2
	movs r6, #1
	mov sl, r6
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x54]
	ldr r0, [r6]
	orrs r0, r2
	str r0, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x7c]
	str r4, [r2]
	ldr r3, [sp, #0xfc]
	str r5, [r3]
	ldr r4, [sp, #0x104]
	str r1, [r4]
	ldr r5, [sp, #0x10c]
	str r1, [r5]
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r0, [sp, #0x120]
	str r1, [r0]
	ldr r2, [sp, #0x134]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r1, [r3]
	ldr r4, [sp, #0x140]
	str r1, [r4]
	mov r5, ip
	ldr r6, [sp, #0x144]
	str r5, [r6]
	ldr r0, _081883A0 @ =FUN_080f44f4
	ldr r2, [sp, #0x148]
	str r0, [r2]
	ldr r0, _081883A4 @ =FUN_080f410c
	ldr r3, [sp, #0x150]
	str r0, [r3]
	ldr r4, [sp, #0x13c]
	str r1, [r4]
	mov r5, sb
	ldr r6, [sp, #0x100]
	str r5, [r6]
	mov r0, r8
	ldr r2, [sp, #0x174]
	str r0, [r2]
	ldr r0, _081883A8 @ =FUN_080f0430
	ldr r3, [sp, #0x178]
	str r0, [r3]
	mov r5, sl
	ldr r4, [sp, #0xa8]
	strb r5, [r4]
	ldr r0, _081883AC @ =0x085AD470
	ldr r6, [sp, #0x17c]
	str r0, [r6]
	ldr r0, _081883B0 @ =FUN_080e73c8
	ldr r2, [sp, #0x164]
	str r0, [r2]
	ldr r3, [sp, #0x158]
	str r1, [r3]
	ldr r4, [sp, #0x168]
	str r1, [r4]
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r0, [sp, #0x180]
	str r1, [r0]
	ldr r0, _081883B4 @ =FUN_080f0320
	ldr r2, [sp, #0x188]
	str r0, [r2]
	ldr r0, _081883B8 @ =Enemy_080eff14
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _081883BC @ =FUN_080e72b0
	ldr r4, [sp, #0x15c]
	str r0, [r4]
	ldr r5, [sp, #0x154]
	str r1, [r5]
	ldr r0, _081883C0 @ =Enemy_StateBlownAway
	ldr r6, [sp, #0x160]
	str r0, [r6]
	ldr r0, _081883C4 @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x14c]
	str r0, [r2]
	ldr r3, [sp, #0x124]
	str r1, [r3]
	ldr r0, _081883C8 @ =FUN_080f6e64
	ldr r4, [sp, #0x18c]
	str r0, [r4]
	ldr r0, _081883CC @ =Enemy_OnDamaged
	ldr r5, [sp, #0x108]
	str r0, [r5]
	ldr r0, _081883D0 @ =FUN_080f84d4
	ldr r6, [sp, #0x190]
	str r0, [r6]
	ldr r0, _081883D4 @ =FUN_080f624c
	ldr r2, [sp, #0x12c]
	str r0, [r2]
	ldr r0, _081883D8 @ =FUN_080f56ec
	ldr r3, [sp, #0x110]
	str r0, [r3]
	ldr r0, _081883DC @ =FUN_080f5b34
	ldr r4, [sp, #0x114]
	str r0, [r4]
	ldr r0, _081883E0 @ =FUN_080f5fac
	ldr r5, [sp, #0x118]
	str r0, [r5]
	ldr r6, [sp, #0x128]
	str r1, [r6]
	movs r0, #0x28
	ldr r2, [sp, #0xac]
	strb r0, [r2]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _081883E4 @ =Octopus_OnReset
	str r0, [r2]
	ldr r4, _081883E8 @ =0x000005AC
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	ldr r6, _081883EC @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081883F0 @ =Octopus_OnDamaged
	str r0, [r1]
	ldr r0, _081883F4 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x54]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x81
	lsls r1, r1, #3
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x44]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Octopus_CreateGroup
	movs r0, #0x45
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08188360
	movs r1, #0x80
	lsls r1, r1, #0x12
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08188360:
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08188402
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0818837E:
	bl VM_GetPC
	cmp r0, #0
	beq _081883F8
	bl VM_GetValue
	b _081883FA
	.align 2, 0
_0818838C: .4byte 0x00000694
_08188390: .4byte Octopus_UpdateFrame
_08188394: .4byte FUN_08184dd8
_08188398: .4byte Octopus_StateDying
_0818839C: .4byte FUN_080f62ac
_081883A0: .4byte FUN_080f44f4
_081883A4: .4byte FUN_080f410c
_081883A8: .4byte FUN_080f0430
_081883AC: .4byte 0x085AD470
_081883B0: .4byte FUN_080e73c8
_081883B4: .4byte FUN_080f0320
_081883B8: .4byte Enemy_080eff14
_081883BC: .4byte FUN_080e72b0
_081883C0: .4byte Enemy_StateBlownAway
_081883C4: .4byte Enemy_StateFallDeath
_081883C8: .4byte FUN_080f6e64
_081883CC: .4byte Enemy_OnDamaged
_081883D0: .4byte FUN_080f84d4
_081883D4: .4byte FUN_080f624c
_081883D8: .4byte FUN_080f56ec
_081883DC: .4byte FUN_080f5b34
_081883E0: .4byte FUN_080f5fac
_081883E4: .4byte Octopus_OnReset
_081883E8: .4byte 0x000005AC
_081883EC: .4byte 0x0000058C
_081883F0: .4byte Octopus_OnDamaged
_081883F4: .4byte 0x000001DF
_081883F8:
	movs r0, #0
_081883FA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0818837E
_08188402:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _0818843A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x54]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0818843A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0818843A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818844C
	movs r0, #1
	b _0818844E
_0818844C:
	movs r0, #0
_0818844E:
	cmp r0, #0
	beq _08188460
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08188460:
	cmp r2, #1
	beq _081884A0
	movs r1, #0
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	ldr r3, [sp, #0x40]
	strb r1, [r3]
	ldr r4, _081884B0 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081884B4 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x120]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xf8]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081884A0:
	movs r1, #2
	ldr r3, [sp, #0x44]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081884B8
	movs r0, #1
	b _081884BA
	.align 2, 0
_081884B0: .4byte 0x00000484
_081884B4: .4byte 0x0000046C
_081884B8:
	movs r0, #0
_081884BA:
	cmp r0, #0
	beq _081884D4
	ldr r0, _081884D0 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081884DE
	.align 2, 0
_081884D0: .4byte 0x030046A0
_081884D4:
	ldr r0, [sp, #0x184]
	bl GetZoneAt
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081884DE:
	movs r1, #0x40
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081884EE
	movs r0, #1
	b _081884F0
_081884EE:
	movs r0, #0
_081884F0:
	cmp r0, #0
	beq _08188500
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08188524 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08188500:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08188532
	ldr r0, _08188528 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0818852C
	movs r0, #1
	b _0818852E
	.align 2, 0
_08188524: .4byte 0xFFFFFEFF
_08188528: .4byte 0x030046A0
_0818852C:
	movs r0, #0
_0818852E:
	cmp r0, #0
	bne _0818853A
_08188532:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0818853A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08188622
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
	beq _0818857C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08188584
_0818857C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08188584:
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
	beq _081885A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081885B0
_081885A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081885B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081885E8 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0818862C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081885EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081885E0
	ldrb r0, [r4, #5]
_081885E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081885FC
	.align 2, 0
_081885E8: .4byte 0x0000FFFF
_081885EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081885FC
	strh r1, [r4, #8]
_081885FC:
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
	bne _0818862C
	movs r0, #1
	strb r0, [r4, #7]
	b _0818862C
_08188622:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_0818862C:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08188644 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08188648
	movs r0, #1
	b _0818864A
	.align 2, 0
_08188644: .4byte 0x030047A4
_08188648:
	movs r0, #0
_0818864A:
	cmp r0, #0
	bne _0818868A
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08188672
	adds r0, r1, #0
	cmp r0, #7
	beq _08188672
	cmp r0, #6
	beq _08188672
	cmp r0, #0x15
	beq _08188672
	cmp r0, #0x14
	beq _08188672
	cmp r0, #0x17
	bne _0818868A
_08188672:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x44]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0818868A:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Octopus_InitHandlerTables
	ldr r6, _0818871C @ =0x0000060C
	adds r1, r7, r6
	ldr r0, _08188720 @ =0x085ADCA8
	str r0, [r1]
	adds r0, r7, #0
	bl Octopus_EnterHidden
	ldr r1, [sp, #0x44]
	ldrh r0, [r1]
	ldr r2, [sp, #0xf4]
	strh r0, [r2]
	ldr r3, [sp, #0x80]
	ldrh r0, [r3]
	ldr r4, [sp, #0xf0]
	strh r0, [r4]
	ldr r5, [sp, #0x54]
	ldr r0, [r5]
	ldr r6, [sp, #0xc8]
	str r0, [r6]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xd8]
	strb r0, [r3]
	ldr r4, [sp, #0x38]
	ldrb r0, [r4]
	ldr r5, [sp, #0xdc]
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xe0]
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	ldr r3, [sp, #0xe4]
	strb r0, [r3]
	ldr r4, [sp, #0xf8]
	ldr r0, [r4]
	ldr r5, [sp, #0xe8]
	str r0, [r5]
	ldr r6, [sp, #0xb4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xec]
	strb r0, [r1]
	ldr r2, _08188724 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08188728 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0818872C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08188730 @ =Octopus_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08188734 @ =Octopus_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08188738
	movs r0, #0
	b _0818873C
	.align 2, 0
_0818871C: .4byte 0x0000060C
_08188720: .4byte 0x085ADCA8
_08188724: .4byte 0x0000057C
_08188728: .4byte Enemy_DispatchMsg
_0818872C: .4byte 0x0000061C
_08188730: .4byte Octopus_Update
_08188734: .4byte Octopus_Destroy
_08188738:
	movs r0, #1
	rsbs r0, r0, #0
_0818873C:
	add sp, #0x19c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
