	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081C4C08 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _081C4C0C @ =0x000001DF
	adds r1, r7, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r7, #0
	bl GolemLink_InitAnims
	ldr r3, _081C4C10 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C4C1C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081C4C14 @ =0x00005290
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081C4C18 @ =0x00001E38
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _081C4C0C @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _081C4BF8
	cmp r1, #0x17
	bne _081C4BFC
_081C4BF8:
	movs r0, #1
	strb r0, [r5, #7]
_081C4BFC:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081C4C84
	.align 2, 0
_081C4C08: .4byte 0x0000065C
_081C4C0C: .4byte 0x000001DF
_081C4C10: .4byte 0x0000025D
_081C4C14: .4byte 0x00005290
_081C4C18: .4byte 0x00001E38
_081C4C1C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081C4D00 @ =0x05000002
	bl CpuSet
	ldr r0, _081C4D04 @ =0x0000CB05
	ldr r1, _081C4D08 @ =0x00005290
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r0, _081C4D0C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081C4D10 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x9c]
_081C4C84:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _081C4D14 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, _081C4D18 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081C4D00 @ =0x05000002
	bl CpuSet
	ldr r3, _081C4D1C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a8]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x58]
	mov r3, r8
	str r3, [sp, #0x5c]
	str r6, [sp, #0x3c]
	ldr r2, [sp, #0x1a8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081C4CF0
	b _081C4E50
_081C4CF0:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4D20
	bl VM_GetValue
	adds r1, r0, #0
	b _081C4D22
	.align 2, 0
_081C4D00: .4byte 0x05000002
_081C4D04: .4byte 0x0000CB05
_081C4D08: .4byte 0x00005290
_081C4D0C: .4byte 0x000004B7
_081C4D10: .4byte 0x000001DF
_081C4D14: .4byte 0x0000046F
_081C4D18: .4byte 0x00000474
_081C4D1C: .4byte 0x000004B6
_081C4D20:
	movs r1, #0
_081C4D22:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081C4D48 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	cmp r0, #0
	beq _081C4D4C
	bl VM_GetValue
	adds r1, r0, #0
	b _081C4D4E
	.align 2, 0
_081C4D48: .4byte 0x00000251
_081C4D4C:
	movs r1, #0
_081C4D4E:
	ldr r2, _081C4D84 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081C4D88 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xbc]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc4]
	cmp r0, #0
	beq _081C4D8C
	bl VM_GetValue
	b _081C4D90
	.align 2, 0
_081C4D84: .4byte 0x00000252
_081C4D88: .4byte 0x000004B4
_081C4D8C:
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
_081C4D90:
	strb r0, [r6]
	ldr r5, [sp, #0xbc]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc4]
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
	blt _081C4DC8
	cmp r1, #0
	blt _081C4DC8
	ldr r0, _081C4DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C4DC8
	ldr r0, _081C4DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4DD4
_081C4DC8:
	movs r1, #0
	b _081C4DE2
	.align 2, 0
_081C4DCC: .4byte 0x030046A8
_081C4DD0: .4byte 0x030046AC
_081C4DD4:
	ldr r0, _081C4DFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081C4DE2:
	ldr r2, _081C4E00 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C4E04
	adds r0, #4
	b _081C4E10
	.align 2, 0
_081C4DFC: .4byte 0x030046A4
_081C4E00: .4byte 0x00000256
_081C4E04:
	ldr r0, _081C4E24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4E10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C4E28
	cmp r2, #2
	beq _081C4E2C
	b _081C4E30
	.align 2, 0
_081C4E24: .4byte 0x030046A4
_081C4E28:
	ldrb r0, [r4, #4]
	b _081C4E2E
_081C4E2C:
	ldrb r0, [r4]
_081C4E2E:
	subs r1, r1, r0
_081C4E30:
	ldr r3, _081C4E48 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081C4E4C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081C4E90
	.align 2, 0
_081C4E48: .4byte 0x00000472
_081C4E4C: .4byte 0x0000FFFF
_081C4E50:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081C4EB4 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081C4EB8 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081C4EBC @ =0x000004B4
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
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
_081C4E90:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C4EDA
	bl VM_GetPC
	cmp r0, #0
	beq _081C4EC0
	bl VM_GetValue
	adds r4, r0, #0
	b _081C4EC2
	.align 2, 0
_081C4EB4: .4byte 0x00000251
_081C4EB8: .4byte 0x00000252
_081C4EBC: .4byte 0x000004B4
_081C4EC0:
	movs r4, #0x30
_081C4EC2:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4ED4
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081C4ED6
_081C4ED4:
	movs r5, #0x40
_081C4ED6:
	mov r8, r4
	b _081C4EE0
_081C4EDA:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081C4EE0:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C4F18
	bl VM_GetPC
	cmp r0, #0
	beq _081C4EFA
	bl VM_GetValue
	adds r6, r0, #0
	b _081C4EFC
_081C4EFA:
	movs r6, #0
_081C4EFC:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4F0C
	bl VM_GetValue
	adds r1, r0, #0
	b _081C4F0E
_081C4F0C:
	movs r1, #0
_081C4F0E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081C4F22
_081C4F18:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081C4F22:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _081C51A8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb8]
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
	str r2, [sp, #0xcc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x90]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x98]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa0]
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	ldr r4, _081C51AC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x88]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x198]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x19c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x1a0]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x18c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081C51B0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _081C51B4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r3, _081C51B8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x50]
	ldr r4, _081C51BC @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _081C51C0 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x78]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x100]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x110]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081C51C4 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _081C51C8 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _081C51CC @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x144]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x148]
	ldr r5, _081C51D0 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	ldr r6, _081C51D4 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C51D8 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x104]
	ldr r3, _081C51DC @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x178]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	ldr r5, _081C51E0 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xac]
	ldr r6, _081C51E4 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x180]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	ldr r2, _081C51E8 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	ldr r4, _081C51EC @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x174]
	ldr r6, _081C51F0 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x184]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x188]
	ldr r2, _081C51F4 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x160]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	ldr r5, _081C51F8 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x164]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _081C51FC @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x190]
	ldr r3, _081C5200 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x194]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081C5204 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x114]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x118]
	ldr r2, _081C5208 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	ldr r3, _081C520C @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _081C5210 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xb0]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x70]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081C5214 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x64]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldr r3, _081C5218 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x34]
	ldr r4, _081C521C @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081C5220 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xb4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x60]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	ldr r4, _081C5224 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _081C5228 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	ldr r3, _081C522C @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xd8]
	ldr r4, _081C5230 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _081C5234 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xe4]
	ldr r6, _081C5238 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _081C523C @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	cmp r0, #0
	bne _081C517A
	b _081C5298
_081C517A:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_081C519A:
	bl VM_GetPC
	cmp r0, #0
	beq _081C5240
	bl VM_GetValue
	b _081C5242
	.align 2, 0
_081C51A8: .4byte 0x0000025D
_081C51AC: .4byte 0x0000025A
_081C51B0: .4byte 0x0000047A
_081C51B4: .4byte 0x0000047C
_081C51B8: .4byte 0x0000047E
_081C51BC: .4byte 0x00000476
_081C51C0: .4byte 0x000004A4
_081C51C4: .4byte 0x000005A4
_081C51C8: .4byte 0x000005C4
_081C51CC: .4byte 0x000005CC
_081C51D0: .4byte 0x000005D4
_081C51D4: .4byte 0x000005DC
_081C51D8: .4byte 0x00000584
_081C51DC: .4byte 0x00000604
_081C51E0: .4byte 0x0000021D
_081C51E4: .4byte 0x0000060C
_081C51E8: .4byte 0x000005E4
_081C51EC: .4byte 0x000005FC
_081C51F0: .4byte 0x00000614
_081C51F4: .4byte 0x000005BC
_081C51F8: .4byte 0x000005EC
_081C51FC: .4byte 0x00000624
_081C5200: .4byte 0x0000058C
_081C5204: .4byte 0x00000594
_081C5208: .4byte 0x0000059C
_081C520C: .4byte 0x000005B4
_081C5210: .4byte 0x00000543
_081C5214: .4byte 0x00000496
_081C5218: .4byte 0x00000469
_081C521C: .4byte 0x0000046A
_081C5220: .4byte 0x00000553
_081C5224: .4byte 0x00000572
_081C5228: .4byte 0x0000055C
_081C522C: .4byte 0x00000564
_081C5230: .4byte 0x00000565
_081C5234: .4byte 0x00000566
_081C5238: .4byte 0x00000567
_081C523C: .4byte 0x0000056C
_081C5240:
	movs r0, #0x18
_081C5242:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081C5254
	bl VM_GetValue
	b _081C5256
_081C5254:
	movs r0, #0x18
_081C5256:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081C5268
	bl VM_GetValue
	b _081C526A
_081C5268:
	movs r0, #0
_081C526A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081C527C
	bl VM_GetValue
	b _081C527E
_081C527C:
	movs r0, #0
_081C527E:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _081C5298
	b _081C519A
_081C5298:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C52E4
	bl VM_GetPC
	cmp r0, #0
	beq _081C52B2
	bl VM_GetValue
	adds r4, r0, #0
	b _081C52B6
_081C52B2:
	movs r4, #0x96
	lsls r4, r4, #1
_081C52B6:
	bl VM_GetPC
	cmp r0, #0
	beq _081C52C6
	bl VM_GetValue
	adds r6, r0, #0
	b _081C52CA
_081C52C6:
	movs r6, #0x96
	lsls r6, r6, #1
_081C52CA:
	bl VM_GetPC
	cmp r0, #0
	beq _081C52D8
	bl VM_GetValue
	b _081C52DE
_081C52D8:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081C52DE:
	ldr r2, [sp, #0xb8]
	strh r0, [r2]
	b _081C52EC
_081C52E4:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xb8]
	strh r6, [r3]
_081C52EC:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081C5304
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081C5304:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x6c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x68]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C53D4
	bl VM_GetPC
	cmp r0, #0
	beq _081C5334
	bl VM_GetValue
	b _081C5336
_081C5334:
	movs r0, #0
_081C5336:
	ldr r3, [sp, #0xcc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081C5344
	asrs r1, r0, #1
	b _081C534A
_081C5344:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C534A:
	ldr r5, _081C5360 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081C5364
	bl VM_GetValue
	b _081C5366
	.align 2, 0
_081C5360: .4byte 0x00000546
_081C5364:
	movs r0, #0
_081C5366:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C537C
	bl VM_GetValue
	b _081C537E
_081C537C:
	movs r0, #0
_081C537E:
	ldr r3, _081C5394 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C5398
	bl VM_GetValue
	adds r1, r0, #0
	b _081C539A
	.align 2, 0
_081C5394: .4byte 0x00000187
_081C5398:
	movs r1, #0
_081C539A:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081C53B0
	bl VM_GetValue
	b _081C53B2
_081C53B0:
	movs r0, #0
_081C53B2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C53CA
	bl VM_GetValue
	adds r1, r0, #0
	b _081C53CC
_081C53CA:
	movs r1, #0
_081C53CC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081C53D4:
	ldr r5, [sp, #0xcc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0x90]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x98]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x94]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C5436
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081C541C
	bl VM_GetValue
	b _081C541E
_081C541C:
	movs r0, #0
_081C541E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081C542E
	bl VM_GetValue
	b _081C5430
_081C542E:
	movs r0, #0
_081C5430:
	ldr r6, _081C5498 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081C5436:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xd4]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081C545A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081C545A:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081C5472
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081C5472:
	ldr r4, [sp, #0x88]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C549C
	movs r0, #1
	b _081C549E
	.align 2, 0
_081C5498: .4byte 0x00000189
_081C549C:
	movs r0, #0
_081C549E:
	cmp r0, #0
	beq _081C54AE
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081C54D8 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_081C54AE:
	ldr r6, [sp, #0xe0]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081C54BA
	ldr r1, [r7, #0x44]
_081C54BA:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081C54DC
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x198]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081C54E8
	.align 2, 0
_081C54D8: .4byte Enemy_OnCWolfMessage
_081C54DC:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x198]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081C54E8:
	ldr r2, [sp, #0x9c]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081C5536
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081C5536
	cmp r0, #0x16
	beq _081C5536
	cmp r0, #0x14
	beq _081C5536
	cmp r0, #9
	beq _081C5536
	cmp r0, #0x19
	beq _081C5536
	cmp r0, #0x1a
	beq _081C5536
	cmp r0, #0xd
	beq _081C5536
	cmp r0, #0x1b
	beq _081C5536
	cmp r0, #0x1f
	beq _081C5536
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xbc]
	ldrb r2, [r3]
	ldr r4, [sp, #0xc0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_081C5536:
	movs r1, #8
	ldr r6, [sp, #0x3c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C5546
	movs r0, #1
	b _081C5548
_081C5546:
	movs r0, #0
_081C5548:
	cmp r0, #0
	beq _081C5556
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	ldr r2, [sp, #0xa4]
	str r0, [r2]
	b _081C5568
_081C5556:
	ldr r3, [sp, #0xa8]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa4]
	str r0, [r4]
_081C5568:
	ldrh r0, [r7]
	ldr r5, [sp, #0x19c]
	strh r0, [r5]
	ldr r6, [sp, #0x18c]
	ldr r0, [sp, #0x1a0]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _081C5592
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
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_081C5592:
	ldr r4, _081C55CC @ =0x00000201
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x54]
	strh r0, [r3]
	ldr r6, [sp, #0x48]
	strh r4, [r6]
	ldr r0, [sp, #0x4c]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xe0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C55D0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081C55DC
	.align 2, 0
_081C55CC: .4byte 0x00000201
_081C55D0:
	ldr r2, [r7, #0x44]
	ldr r0, _081C5614 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C55DC:
	ldr r3, [sp, #0xe0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081C562C
	ldr r4, [sp, #0x9c]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081C5618
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
	b _081C5622
	.align 2, 0
_081C5614: .4byte 0x03003584
_081C5618:
	ldr r5, [sp, #0x9c]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081C5622:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081C562C:
	ldr r6, _081C57FC @ =0x0000047A
	adds r0, r7, r6
	ldrh r0, [r0]
	adds r0, #3
	ldr r2, _081C5800 @ =0x0000047E
	adds r1, r7, r2
	movs r4, #0
	strh r0, [r1]
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	adds r0, #2
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x44]
	strh r0, [r6]
	adds r0, r7, #0
	bl GolemLink_InitHitboxes
	ldr r1, [sp, #0x24]
	ldr r2, _081C5804 @ =0x0000066C
	adds r0, r1, r2
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _081C5808 @ =GolemLink_UpdateFrame
	mov sb, r5
	ldr r6, _081C580C @ =GolemLink_GetMoveSpeed
	mov sl, r6
	ldr r1, _081C5810 @ =GolemLink_StateTurn
	mov ip, r1
	ldr r5, _081C5814 @ =GolemLink_StateDamaged
	ldr r3, _081C5818 @ =FUN_080f62b0
	ldr r2, _081C581C @ =FUN_080f62ac
	str r2, [sp, #0x1a4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x58]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x78]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x7c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x100]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x108]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x110]
	str r2, [r6]
	ldr r1, _081C5820 @ =GolemLink_StateMove
	ldr r2, [sp, #0x120]
	str r1, [r2]
	ldr r6, _081C5824 @ =GolemLink_StateWait
	ldr r1, [sp, #0x124]
	str r6, [r1]
	ldr r2, _081C5828 @ =GolemLink_StateNap
	ldr r6, [sp, #0x138]
	str r2, [r6]
	ldr r1, [sp, #0x13c]
	str r3, [r1]
	ldr r2, [sp, #0x144]
	str r5, [r2]
	ldr r3, _081C582C @ =GolemLink_StateDying
	ldr r5, [sp, #0x148]
	str r3, [r5]
	ldr r1, _081C5830 @ =FUN_080f44f4
	ldr r6, [sp, #0x14c]
	str r1, [r6]
	ldr r1, _081C5834 @ =FUN_080f410c
	ldr r2, [sp, #0x154]
	str r1, [r2]
	ldr r3, _081C5838 @ =GolemLink_StateHeardSound
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _081C583C @ =GolemLink_StateRespawnWait
	ldr r1, [sp, #0x104]
	str r6, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r3, [sp, #0x178]
	str r2, [r3]
	ldr r1, _081C5840 @ =FUN_080f0430
	ldr r5, [sp, #0x17c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xac]
	strb r1, [r6]
	ldr r1, _081C5844 @ =0x085AD470
	ldr r2, [sp, #0x180]
	str r1, [r2]
	ldr r1, _081C5848 @ =FUN_080e73c8
	ldr r3, [sp, #0x168]
	str r1, [r3]
	ldr r5, [sp, #0x15c]
	str r4, [r5]
	ldr r6, [sp, #0x16c]
	str r4, [r6]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r2, [sp, #0x174]
	str r4, [r2]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r1, _081C584C @ =FUN_080f0320
	ldr r5, [sp, #0x188]
	str r1, [r5]
	ldr r1, _081C5850 @ =Enemy_080eff14
	ldr r6, [sp, #0x134]
	str r1, [r6]
	ldr r1, _081C5854 @ =FUN_080e72b0
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, _081C5858 @ =FUN_081bdb78
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _081C585C @ =Enemy_StateBlownAway
	ldr r6, [sp, #0x164]
	str r1, [r6]
	ldr r1, _081C5860 @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x150]
	str r1, [r2]
	ldr r3, [sp, #0x128]
	str r4, [r3]
	ldr r1, _081C5864 @ =FUN_080f6e64
	ldr r5, [sp, #0x190]
	str r1, [r5]
	ldr r1, _081C5868 @ =Enemy_OnDamaged
	ldr r6, [sp, #0x10c]
	str r1, [r6]
	ldr r1, _081C586C @ =FUN_080f84d4
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081C5870 @ =FUN_080f624c
	ldr r3, [sp, #0x130]
	str r1, [r3]
	ldr r1, _081C5874 @ =FUN_080f56ec
	ldr r5, [sp, #0x114]
	str r1, [r5]
	ldr r1, _081C5878 @ =FUN_080f5b34
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081C587C @ =FUN_080f5fac
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r3, [sp, #0x12c]
	str r4, [r3]
	movs r1, #0x28
	ldr r5, [sp, #0xb0]
	strb r1, [r5]
	ldr r1, [sp, #0x18c]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081C5880 @ =GolemLink_OnReset
	str r0, [r1]
	ldr r0, _081C5884 @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _081C5888 @ =FUN_081b908c
	str r0, [r1]
	ldr r2, _081C588C @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081C5890 @ =GolemLink_OnAttackRequest
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081C5894 @ =FUN_081b8988
	str r0, [r1]
	ldr r5, _081C5898 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _081C589C @ =GolemLink_OnDamaged
	str r0, [r1]
	adds r6, #0x30
	adds r1, r7, r6
	ldr r0, _081C58A0 @ =Enemy_TryHeadToSound
	str r0, [r1]
	movs r0, #0xb5
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081C58A4 @ =GolemLink_StateBurning
	str r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0x70]
	strh r0, [r4]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081C58B2
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081C57EE:
	bl VM_GetPC
	cmp r0, #0
	beq _081C58A8
	bl VM_GetValue
	b _081C58AA
	.align 2, 0
_081C57FC: .4byte 0x0000047A
_081C5800: .4byte 0x0000047E
_081C5804: .4byte 0x0000066C
_081C5808: .4byte GolemLink_UpdateFrame
_081C580C: .4byte GolemLink_GetMoveSpeed
_081C5810: .4byte GolemLink_StateTurn
_081C5814: .4byte GolemLink_StateDamaged
_081C5818: .4byte FUN_080f62b0
_081C581C: .4byte FUN_080f62ac
_081C5820: .4byte GolemLink_StateMove
_081C5824: .4byte GolemLink_StateWait
_081C5828: .4byte GolemLink_StateNap
_081C582C: .4byte GolemLink_StateDying
_081C5830: .4byte FUN_080f44f4
_081C5834: .4byte FUN_080f410c
_081C5838: .4byte GolemLink_StateHeardSound
_081C583C: .4byte GolemLink_StateRespawnWait
_081C5840: .4byte FUN_080f0430
_081C5844: .4byte 0x085AD470
_081C5848: .4byte FUN_080e73c8
_081C584C: .4byte FUN_080f0320
_081C5850: .4byte Enemy_080eff14
_081C5854: .4byte FUN_080e72b0
_081C5858: .4byte FUN_081bdb78
_081C585C: .4byte Enemy_StateBlownAway
_081C5860: .4byte Enemy_StateFallDeath
_081C5864: .4byte FUN_080f6e64
_081C5868: .4byte Enemy_OnDamaged
_081C586C: .4byte FUN_080f84d4
_081C5870: .4byte FUN_080f624c
_081C5874: .4byte FUN_080f56ec
_081C5878: .4byte FUN_080f5b34
_081C587C: .4byte FUN_080f5fac
_081C5880: .4byte GolemLink_OnReset
_081C5884: .4byte 0x000005FC
_081C5888: .4byte FUN_081b908c
_081C588C: .4byte 0x000005AC
_081C5890: .4byte GolemLink_OnAttackRequest
_081C5894: .4byte FUN_081b8988
_081C5898: .4byte 0x0000058C
_081C589C: .4byte GolemLink_OnDamaged
_081C58A0: .4byte Enemy_TryHeadToSound
_081C58A4: .4byte GolemLink_StateBurning
_081C58A8:
	movs r0, #0
_081C58AA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081C57EE
_081C58B2:
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
	beq _081C58EA
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x58]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081C58EA
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081C58EA:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C58FC
	movs r0, #1
	b _081C58FE
_081C58FC:
	movs r0, #0
_081C58FE:
	cmp r0, #0
	beq _081C5910
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081C5910:
	cmp r2, #1
	beq _081C5950
	movs r1, #0
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r3, [sp, #0x38]
	strb r1, [r3]
	ldr r4, _081C5960 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081C5964 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x124]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xfc]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081C5950:
	movs r1, #2
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C5968
	movs r0, #1
	b _081C596A
	.align 2, 0
_081C5960: .4byte 0x00000484
_081C5964: .4byte 0x0000046C
_081C5968:
	movs r0, #0
_081C596A:
	cmp r0, #0
	beq _081C5984
	ldr r0, _081C5980 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081C598E
	.align 2, 0
_081C5980: .4byte 0x030046A0
_081C5984:
	ldr r0, [sp, #0x18c]
	bl GetZoneAt
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081C598E:
	movs r1, #0x40
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C599E
	movs r0, #1
	b _081C59A0
_081C599E:
	movs r0, #0
_081C59A0:
	cmp r0, #0
	beq _081C59B0
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081C59D4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081C59B0:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081C59E2
	ldr r0, _081C59D8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081C59DC
	movs r0, #1
	b _081C59DE
	.align 2, 0
_081C59D4: .4byte 0xFFFFFEFF
_081C59D8: .4byte 0x030046A0
_081C59DC:
	movs r0, #0
_081C59DE:
	cmp r0, #0
	bne _081C59EA
_081C59E2:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_081C59EA:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xe0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081C5AD2
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
	beq _081C5A2C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081C5A34
_081C5A2C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081C5A34:
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
	beq _081C5A58
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081C5A60
_081C5A58:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081C5A60:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081C5A98 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081C5ADC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081C5A9C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081C5A90
	ldrb r0, [r4, #5]
_081C5A90:
	subs r0, #1
	strh r0, [r4, #8]
	b _081C5AAC
	.align 2, 0
_081C5A98: .4byte 0x0000FFFF
_081C5A9C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081C5AAC
	strh r1, [r4, #8]
_081C5AAC:
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
	bne _081C5ADC
	movs r0, #1
	strb r0, [r4, #7]
	b _081C5ADC
_081C5AD2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081C5ADC:
	movs r0, #0
	ldr r3, [sp, #0x8c]
	str r0, [r3]
	ldr r0, _081C5AF4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C5AF8
	movs r0, #1
	b _081C5AFA
	.align 2, 0
_081C5AF4: .4byte 0x030047A4
_081C5AF8:
	movs r0, #0
_081C5AFA:
	cmp r0, #0
	bne _081C5B3A
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081C5B22
	adds r0, r1, #0
	cmp r0, #7
	beq _081C5B22
	cmp r0, #6
	beq _081C5B22
	cmp r0, #0x15
	beq _081C5B22
	cmp r0, #0x14
	beq _081C5B22
	cmp r0, #0x17
	bne _081C5B3A
_081C5B22:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x3c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081C5B3A:
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	str r1, [r0]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	ldr r3, _081C5C20 @ =0x00000634
	adds r1, r7, r3
	ldr r0, _081C5C24 @ =0x085ADFDC
	str r0, [r1]
	adds r0, r7, #0
	bl GolemLink_SetHandlerTable3
	adds r0, r7, #0
	bl GolemLink_SetHandlerTable4
	ldr r4, [sp, #0x24]
	ldr r5, _081C5C28 @ =0x000006C1
	adds r0, r4, r5
	movs r2, #0
	strb r2, [r0]
	ldr r6, _081C5C2C @ =0x000006B4
	adds r3, r4, r6
	movs r4, #0
	movs r0, #0x78
	strh r0, [r3]
	ldr r1, [sp, #0x24]
	subs r5, #7
	adds r0, r1, r5
	strh r2, [r0]
	adds r6, #4
	adds r1, r1, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x24]
	subs r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	movs r0, #0xa0
	strh r0, [r3]
	adds r6, #6
	adds r0, r1, r6
	strh r2, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r1, r2
	strb r4, [r0]
	ldr r3, _081C5C30 @ =0x000006C7
	adds r0, r1, r3
	strb r4, [r0]
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ldr r5, [sp, #0xf8]
	strh r0, [r5]
	ldr r6, [sp, #0x80]
	ldrh r0, [r6]
	ldr r1, [sp, #0xf4]
	strh r0, [r1]
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	ldr r3, [sp, #0xc8]
	str r0, [r3]
	ldr r4, [sp, #0x5c]
	ldr r0, [r4]
	ldr r5, [sp, #0xd0]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0xd8]
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0xdc]
	strb r0, [r2]
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	ldr r1, [sp, #0xfc]
	ldr r0, [r1]
	ldr r2, [sp, #0xec]
	str r0, [r2]
	ldr r3, [sp, #0xb4]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf0]
	strb r0, [r4]
	ldr r5, _081C5C34 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081C5C38 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r6, _081C5C3C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081C5C40 @ =GolemLink_Update
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081C5C44 @ =GolemLink_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C5C48
	movs r0, #0
	b _081C5C4C
	.align 2, 0
_081C5C20: .4byte 0x00000634
_081C5C24: .4byte 0x085ADFDC
_081C5C28: .4byte 0x000006C1
_081C5C2C: .4byte 0x000006B4
_081C5C30: .4byte 0x000006C7
_081C5C34: .4byte 0x0000057C
_081C5C38: .4byte Enemy_DispatchMsg
_081C5C3C: .4byte 0x0000061C
_081C5C40: .4byte GolemLink_Update
_081C5C44: .4byte GolemLink_Destroy
_081C5C48:
	movs r0, #1
	rsbs r0, r0, #0
_081C5C4C:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

@ 通信対戦専用のエネミー
