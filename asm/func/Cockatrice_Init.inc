	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _081606E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081606E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081606E8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r4, _081606EC @ =0x000006BC
	adds r1, r7, r4
	strh r0, [r1]
	movs r5, #0xd8
	lsls r5, r5, #3
	adds r0, r7, r5
	strh r6, [r0]
	ldr r1, _081606F0 @ =0x000006BE
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _081606F4 @ =0x000006E4
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _081606F8 @ =0x000006E2
	adds r0, r7, r3
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	adds r0, r7, #0
	bl Cockatrice_InitAnims
	ldr r4, _081606FC @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816070C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08160700 @ =0x000041CF
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08160704 @ =0x0000DA5E
	bl EnemyAuxSprite_LoadAnim
	ldr r6, _08160708 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _081606D0
	cmp r1, #0x17
	bne _081606D4
_081606D0:
	movs r0, #1
	strb r0, [r5, #7]
_081606D4:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08160772
	.align 2, 0
_081606E0: .4byte 0x030046B8
_081606E4: .4byte 0x000003FF
_081606E8: .4byte 0x0203B400
_081606EC: .4byte 0x000006BC
_081606F0: .4byte 0x000006BE
_081606F4: .4byte 0x000006E4
_081606F8: .4byte 0x000006E2
_081606FC: .4byte 0x0000025D
_08160700: .4byte 0x000041CF
_08160704: .4byte 0x0000DA5E
_08160708: .4byte 0x000001DF
_0816070C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r1, sp, #0x14
	mov r8, r1
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _081607F0 @ =0x05000002
	bl CpuSet
	ldr r0, _081607F4 @ =0x0000CB05
	ldr r1, _081607F8 @ =0x000041CF
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
	ldr r0, _081607FC @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08160800 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x9c]
_08160772:
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
	ldr r5, _08160804 @ =0x0000046F
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
	ldr r1, _08160808 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081607F0 @ =0x05000002
	bl CpuSet
	ldr r3, _0816080C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a8]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x78]
	mov r3, r8
	str r3, [sp, #0x7c]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1a8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081607DE
	b _08160940
_081607DE:
	bl VM_GetPC
	cmp r0, #0
	beq _08160810
	bl VM_GetValue
	adds r1, r0, #0
	b _08160812
	.align 2, 0
_081607F0: .4byte 0x05000002
_081607F4: .4byte 0x0000CB05
_081607F8: .4byte 0x000041CF
_081607FC: .4byte 0x000004B7
_08160800: .4byte 0x000001DF
_08160804: .4byte 0x0000046F
_08160808: .4byte 0x00000474
_0816080C: .4byte 0x000004B6
_08160810:
	movs r1, #0
_08160812:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08160838 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x120]
	str r4, [sp, #0x124]
	cmp r0, #0
	beq _0816083C
	bl VM_GetValue
	adds r1, r0, #0
	b _0816083E
	.align 2, 0
_08160838: .4byte 0x00000251
_0816083C:
	movs r1, #0
_0816083E:
	ldr r2, _08160874 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08160878 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x120]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x12c]
	cmp r0, #0
	beq _0816087C
	bl VM_GetValue
	b _08160880
	.align 2, 0
_08160874: .4byte 0x00000252
_08160878: .4byte 0x000004B4
_0816087C:
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
_08160880:
	strb r0, [r6]
	ldr r5, [sp, #0x120]
	ldrb r1, [r5]
	ldr r6, [sp, #0x12c]
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
	blt _081608B8
	cmp r1, #0
	blt _081608B8
	ldr r0, _081608BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081608B8
	ldr r0, _081608C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081608C4
_081608B8:
	movs r1, #0
	b _081608D2
	.align 2, 0
_081608BC: .4byte 0x030046A8
_081608C0: .4byte 0x030046AC
_081608C4:
	ldr r0, _081608EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081608D2:
	ldr r2, _081608F0 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081608F4
	adds r0, #4
	b _08160900
	.align 2, 0
_081608EC: .4byte 0x030046A4
_081608F0: .4byte 0x00000256
_081608F4:
	ldr r0, _08160914 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08160900:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08160918
	cmp r2, #2
	beq _0816091C
	b _08160920
	.align 2, 0
_08160914: .4byte 0x030046A4
_08160918:
	ldrb r0, [r4, #4]
	b _0816091E
_0816091C:
	ldrb r0, [r4]
_0816091E:
	subs r1, r1, r0
_08160920:
	ldr r3, _08160938 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0816093C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08160980
	.align 2, 0
_08160938: .4byte 0x00000472
_0816093C: .4byte 0x0000FFFF
_08160940:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081609A4 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081609A8 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081609AC @ =0x000004B4
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
	str r5, [sp, #0x120]
	str r4, [sp, #0x124]
	str r3, [sp, #0x12c]
_08160980:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081609CA
	bl VM_GetPC
	cmp r0, #0
	beq _081609B0
	bl VM_GetValue
	adds r4, r0, #0
	b _081609B2
	.align 2, 0
_081609A4: .4byte 0x00000251
_081609A8: .4byte 0x00000252
_081609AC: .4byte 0x000004B4
_081609B0:
	movs r4, #0x30
_081609B2:
	bl VM_GetPC
	cmp r0, #0
	beq _081609C4
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081609C6
_081609C4:
	movs r5, #0x40
_081609C6:
	mov r8, r4
	b _081609D0
_081609CA:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081609D0:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08160A08
	bl VM_GetPC
	cmp r0, #0
	beq _081609EA
	bl VM_GetValue
	adds r6, r0, #0
	b _081609EC
_081609EA:
	movs r6, #0
_081609EC:
	bl VM_GetPC
	cmp r0, #0
	beq _081609FC
	bl VM_GetValue
	adds r1, r0, #0
	b _081609FE
_081609FC:
	movs r1, #0
_081609FE:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08160A12
_08160A08:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08160A12:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08160C98 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x118]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x130]
	lsls r4, r4, #0x10
	str r4, [sp, #0xd4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xe4]
	lsls r6, r6, #0x10
	str r6, [sp, #0xec]
	lsls r5, r5, #0x10
	str r5, [sp, #0xe0]
	ldr r4, _08160C9C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x134]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xcc]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
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
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _08160CA0 @ =0x0000047A
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r3, _08160CA4 @ =0x0000047C
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	ldr r4, _08160CA8 @ =0x0000047E
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08160CAC @ =0x00000476
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0x8f
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _08160CB0 @ =0x000004A4
	adds r1, r7, r1
	str r1, [sp, #0x70]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0xb0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x104]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x114]
	ldr r1, _08160CB4 @ =0x000005A4
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x148]
	ldr r3, _08160CB8 @ =0x000005C4
	adds r3, r7, r3
	str r3, [sp, #0x14c]
	ldr r4, _08160CBC @ =0x000005CC
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xba
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _08160CC0 @ =0x000005D4
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	ldr r1, _08160CC4 @ =0x000005DC
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xb9
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _08160CC8 @ =0x00000584
	adds r3, r7, r3
	str r3, [sp, #0xf8]
	ldr r4, _08160CCC @ =0x00000604
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08160CD0 @ =0x0000021D
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _08160CD4 @ =0x0000060C
	adds r1, r7, r1
	str r1, [sp, #0x190]
	movs r2, #0xbe
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _08160CD8 @ =0x000005E4
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	ldr r5, _08160CDC @ =0x000005FC
	adds r5, r7, r5
	str r5, [sp, #0x180]
	movs r6, #0xc0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x184]
	ldr r1, _08160CE0 @ =0x00000614
	adds r1, r7, r1
	str r1, [sp, #0x194]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _08160CE4 @ =0x000005BC
	adds r3, r7, r3
	str r3, [sp, #0x144]
	movs r4, #0xbd
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xbc
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x168]
	ldr r6, _08160CE8 @ =0x000005EC
	adds r6, r7, r6
	str r6, [sp, #0x174]
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x128]
	ldr r3, _08160CEC @ =0x00000624
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	ldr r4, _08160CF0 @ =0x0000058C
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xc5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _08160CF4 @ =0x00000594
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	ldr r3, _08160CF8 @ =0x0000059C
	adds r3, r7, r3
	str r3, [sp, #0x110]
	ldr r4, _08160CFC @ =0x000005B4
	adds r4, r7, r4
	str r4, [sp, #0x13c]
	ldr r5, _08160D00 @ =0x00000543
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _08160D04 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _08160D08 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _08160D0C @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _08160D10 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xac]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x68]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	ldr r4, _08160D14 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08160D18 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r3, _08160D1C @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _08160D20 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, _08160D24 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08160D28 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _08160D2C @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	cmp r0, #0
	bne _08160C6A
	b _08160D88
_08160C6A:
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
_08160C8A:
	bl VM_GetPC
	cmp r0, #0
	beq _08160D30
	bl VM_GetValue
	b _08160D32
	.align 2, 0
_08160C98: .4byte 0x0000025D
_08160C9C: .4byte 0x0000025A
_08160CA0: .4byte 0x0000047A
_08160CA4: .4byte 0x0000047C
_08160CA8: .4byte 0x0000047E
_08160CAC: .4byte 0x00000476
_08160CB0: .4byte 0x000004A4
_08160CB4: .4byte 0x000005A4
_08160CB8: .4byte 0x000005C4
_08160CBC: .4byte 0x000005CC
_08160CC0: .4byte 0x000005D4
_08160CC4: .4byte 0x000005DC
_08160CC8: .4byte 0x00000584
_08160CCC: .4byte 0x00000604
_08160CD0: .4byte 0x0000021D
_08160CD4: .4byte 0x0000060C
_08160CD8: .4byte 0x000005E4
_08160CDC: .4byte 0x000005FC
_08160CE0: .4byte 0x00000614
_08160CE4: .4byte 0x000005BC
_08160CE8: .4byte 0x000005EC
_08160CEC: .4byte 0x00000624
_08160CF0: .4byte 0x0000058C
_08160CF4: .4byte 0x00000594
_08160CF8: .4byte 0x0000059C
_08160CFC: .4byte 0x000005B4
_08160D00: .4byte 0x00000543
_08160D04: .4byte 0x00000496
_08160D08: .4byte 0x00000469
_08160D0C: .4byte 0x0000046A
_08160D10: .4byte 0x00000553
_08160D14: .4byte 0x00000572
_08160D18: .4byte 0x0000055C
_08160D1C: .4byte 0x00000564
_08160D20: .4byte 0x00000565
_08160D24: .4byte 0x00000566
_08160D28: .4byte 0x00000567
_08160D2C: .4byte 0x0000056C
_08160D30:
	movs r0, #0x18
_08160D32:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08160D44
	bl VM_GetValue
	b _08160D46
_08160D44:
	movs r0, #0x18
_08160D46:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08160D58
	bl VM_GetValue
	b _08160D5A
_08160D58:
	movs r0, #0
_08160D5A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08160D6C
	bl VM_GetValue
	b _08160D6E
_08160D6C:
	movs r0, #0
_08160D6E:
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
	bgt _08160D88
	b _08160C8A
_08160D88:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08160DD4
	bl VM_GetPC
	cmp r0, #0
	beq _08160DA2
	bl VM_GetValue
	adds r4, r0, #0
	b _08160DA6
_08160DA2:
	movs r4, #0x96
	lsls r4, r4, #1
_08160DA6:
	bl VM_GetPC
	cmp r0, #0
	beq _08160DB6
	bl VM_GetValue
	adds r6, r0, #0
	b _08160DBA
_08160DB6:
	movs r6, #0x96
	lsls r6, r6, #1
_08160DBA:
	bl VM_GetPC
	cmp r0, #0
	beq _08160DC8
	bl VM_GetValue
	b _08160DCE
_08160DC8:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08160DCE:
	ldr r2, [sp, #0x118]
	strh r0, [r2]
	b _08160DDC
_08160DD4:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x118]
	strh r6, [r3]
_08160DDC:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08160DF4
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x7c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08160DF4:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08160EC4
	bl VM_GetPC
	cmp r0, #0
	beq _08160E24
	bl VM_GetValue
	b _08160E26
_08160E24:
	movs r0, #0
_08160E26:
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08160E34
	asrs r1, r0, #1
	b _08160E3A
_08160E34:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08160E3A:
	ldr r5, _08160E50 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E54
	bl VM_GetValue
	b _08160E56
	.align 2, 0
_08160E50: .4byte 0x00000546
_08160E54:
	movs r0, #0
_08160E56:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E6C
	bl VM_GetValue
	b _08160E6E
_08160E6C:
	movs r0, #0
_08160E6E:
	ldr r3, _08160E84 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E88
	bl VM_GetValue
	adds r1, r0, #0
	b _08160E8A
	.align 2, 0
_08160E84: .4byte 0x00000187
_08160E88:
	movs r1, #0
_08160E8A:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08160EA0
	bl VM_GetValue
	b _08160EA2
_08160EA0:
	movs r0, #0
_08160EA2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160EBA
	bl VM_GetValue
	adds r1, r0, #0
	b _08160EBC
_08160EBA:
	movs r1, #0
_08160EBC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08160EC4:
	ldr r5, [sp, #0x130]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0xd4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xe4]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xec]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xe0]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08160F26
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08160F0C
	bl VM_GetValue
	b _08160F0E
_08160F0C:
	movs r0, #0
_08160F0E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08160F1E
	bl VM_GetValue
	b _08160F20
_08160F1E:
	movs r0, #0
_08160F20:
	ldr r6, _08160F88 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08160F26:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x134]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08160F4A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x7c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08160F4A:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08160F62
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x7c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08160F62:
	ldr r4, [sp, #0xcc]
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
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08160F8C
	movs r0, #1
	b _08160F8E
	.align 2, 0
_08160F88: .4byte 0x00000189
_08160F8C:
	movs r0, #0
_08160F8E:
	cmp r0, #0
	beq _08160F9E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08160FC8 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_08160F9E:
	ldr r6, [sp, #0x138]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08160FAA
	ldr r1, [r7, #0x44]
_08160FAA:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08160FCC
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08160FD8
	.align 2, 0
_08160FC8: .4byte Enemy_OnCWolfMessage
_08160FCC:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08160FD8:
	ldr r2, [sp, #0x9c]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08161026
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08161026
	cmp r0, #0x16
	beq _08161026
	cmp r0, #0x14
	beq _08161026
	cmp r0, #9
	beq _08161026
	cmp r0, #0x19
	beq _08161026
	cmp r0, #0x1a
	beq _08161026
	cmp r0, #0xd
	beq _08161026
	cmp r0, #0x1b
	beq _08161026
	cmp r0, #0x1f
	beq _08161026
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x120]
	ldrb r2, [r3]
	ldr r4, [sp, #0x124]
	ldrb r3, [r4]
	ldr r5, [sp, #0x12c]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_08161026:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08161036
	movs r0, #1
	b _08161038
_08161036:
	movs r0, #0
_08161038:
	cmp r0, #0
	beq _08161046
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	ldr r2, [sp, #0xa0]
	str r0, [r2]
	b _08161058
_08161046:
	ldr r3, [sp, #0xa4]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa0]
	str r0, [r4]
_08161058:
	ldrh r0, [r7]
	ldr r5, [sp, #0x38]
	strh r0, [r5]
	ldr r6, [sp, #0x30]
	ldr r0, [sp, #0x3c]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _08161082
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
_08161082:
	ldr r3, [sp, #0x94]
	ldr r5, [r3]
	movs r0, #0x54
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081610F4
	bl VM_GetPC
	cmp r0, #0
	beq _081610A0
	bl VM_GetValue
	adds r1, r0, #0
	b _081610A6
_081610A0:
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r1, r4, #0
_081610A6:
	ldr r6, _081610BC @ =0x000006EC
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081610C0
	bl VM_GetValue
	b _081610C6
	.align 2, 0
_081610BC: .4byte 0x000006EC
_081610C0:
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
_081610C6:
	ldr r2, _081610DC @ =0x000006EE
	adds r4, r5, r2
	strh r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081610E0
	bl VM_GetValue
	adds r1, r0, #0
	b _081610E6
	.align 2, 0
_081610DC: .4byte 0x000006EE
_081610E0:
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r3, #0
_081610E6:
	ldr r6, _081610F0 @ =0x000006DE
	adds r0, r5, r6
	strh r1, [r0]
	b _08161110
	.align 2, 0
_081610F0: .4byte 0x000006DE
_081610F4:
	ldr r0, _08161174 @ =0x000006EC
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _08161178 @ =0x000006EE
	adds r2, r5, r1
	movs r1, #0x96
	lsls r1, r1, #2
	strh r1, [r2]
	ldr r3, _0816117C @ =0x000006DE
	adds r0, r5, r3
	strh r1, [r0]
	adds r4, r2, #0
_08161110:
	ldr r2, _08161180 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08161184 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _08161188 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl Mod
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r1, r5, r3
	strh r0, [r1]
	movs r4, #0xfd
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x64]
	strh r0, [r6]
	ldr r0, [sp, #0x58]
	strh r4, [r0]
	ldr r1, [sp, #0x5c]
	strh r5, [r1]
	ldrh r0, [r6]
	ldr r2, _0816118C @ =0x000001FB
	adds r0, r0, r2
	ldr r3, [sp, #0x60]
	strh r0, [r3]
	ldr r4, [sp, #0x58]
	ldrh r1, [r4]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r5, [sp, #0x138]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08161190
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0816119C
	.align 2, 0
_08161174: .4byte 0x000006EC
_08161178: .4byte 0x000006EE
_0816117C: .4byte 0x000006DE
_08161180: .4byte 0x030046B8
_08161184: .4byte 0x000003FF
_08161188: .4byte 0x0203B400
_0816118C: .4byte 0x000001FB
_08161190:
	ldr r2, [r7, #0x44]
	ldr r0, _081611D4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0816119C:
	ldr r6, [sp, #0x138]
	ldrb r0, [r6]
	cmp r0, #1
	bne _081611EC
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081611D8
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
	b _081611E2
	.align 2, 0
_081611D4: .4byte 0x03003584
_081611D8:
	ldr r2, [sp, #0x9c]
	ldrb r0, [r2]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081611E2:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081611EC:
	movs r4, #0
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	adds r0, #2
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x54]
	strh r0, [r6]
	adds r0, r7, #0
	bl Cockatrice_InitHitboxes
	ldr r1, [sp, #0x24]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _081613BC @ =0x0000072C
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _081613C0 @ =Cockatrice_UpdateFrame
	mov sb, r5
	ldr r6, _081613C4 @ =Cockatrice_GetMoveSpeed
	mov sl, r6
	ldr r1, _081613C8 @ =Cockatrice_StateTurn
	mov ip, r1
	ldr r5, _081613CC @ =Cockatrice_StateDamaged
	ldr r3, _081613D0 @ =Cockatrice_OnRouteFailed
	ldr r2, _081613D4 @ =FUN_080f62ac
	str r2, [sp, #0x1a4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x78]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x70]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x74]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xf4]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xfc]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x104]
	str r2, [r6]
	ldr r1, _081613D8 @ =Cockatrice_StateMove
	ldr r2, [sp, #0x114]
	str r1, [r2]
	ldr r6, _081613DC @ =Cockatrice_StateWait
	ldr r1, [sp, #0x11c]
	str r6, [r1]
	ldr r2, _081613E0 @ =Cockatrice_StateNap
	ldr r6, [sp, #0x148]
	str r2, [r6]
	ldr r1, [sp, #0x14c]
	str r3, [r1]
	ldr r2, [sp, #0x154]
	str r5, [r2]
	ldr r3, _081613E4 @ =Cockatrice_StateDying
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _081613E8 @ =FUN_080f44f4
	ldr r6, [sp, #0x15c]
	str r1, [r6]
	ldr r1, _081613EC @ =FUN_080f410c
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _081613F0 @ =Cockatrice_StateHeardSound
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r6, _081613F4 @ =Cockatrice_StateRespawnWait
	ldr r1, [sp, #0xf8]
	str r6, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r3, [sp, #0x188]
	str r2, [r3]
	ldr r1, _081613F8 @ =FUN_080f0430
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xe8]
	strb r1, [r6]
	ldr r1, _081613FC @ =0x085AD470
	ldr r2, [sp, #0x190]
	str r1, [r2]
	ldr r1, _08161400 @ =FUN_080e73c8
	ldr r3, [sp, #0x178]
	str r1, [r3]
	ldr r5, [sp, #0x16c]
	str r4, [r5]
	ldr r6, [sp, #0x17c]
	str r4, [r6]
	ldr r1, [sp, #0x180]
	str r4, [r1]
	ldr r2, [sp, #0x184]
	str r4, [r2]
	ldr r3, [sp, #0x194]
	str r4, [r3]
	ldr r1, _08161404 @ =FUN_080f0320
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _08161408 @ =Enemy_080eff14
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r5, _0816140C @ =FUN_080e72b0
	ldr r1, [sp, #0x170]
	str r5, [r1]
	ldr r2, [sp, #0x168]
	str r4, [r2]
	ldr r1, _08161410 @ =Enemy_StateBlownAway
	ldr r3, [sp, #0x174]
	str r1, [r3]
	ldr r1, _08161414 @ =Enemy_StateFallDeath
	ldr r6, [sp, #0x160]
	str r1, [r6]
	ldr r1, [sp, #0x128]
	str r4, [r1]
	ldr r1, _08161418 @ =FUN_080f6e64
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _0816141C @ =Enemy_OnDamaged
	ldr r3, [sp, #0x100]
	str r1, [r3]
	ldr r1, _08161420 @ =FUN_080f84d4
	ldr r6, [sp, #0x1a0]
	str r1, [r6]
	ldr r1, _08161424 @ =FUN_080f624c
	ldr r2, [sp, #0x140]
	str r1, [r2]
	ldr r1, _08161428 @ =FUN_080f56ec
	ldr r3, [sp, #0x108]
	str r1, [r3]
	ldr r1, _0816142C @ =FUN_080f5b34
	ldr r6, [sp, #0x10c]
	str r1, [r6]
	ldr r1, _08161430 @ =FUN_080f5fac
	ldr r2, [sp, #0x110]
	str r1, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	movs r1, #0x28
	ldr r6, [sp, #0xa8]
	strb r1, [r6]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r4, [r1]
	ldr r1, [sp, #0x30]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08161434 @ =Cockatrice_ReleaseTarget
	str r0, [r1]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08161438 @ =Cockatrice_TryDetectPlayer
	str r0, [r1]
	movs r6, #0xbd
	lsls r6, r6, #3
	adds r0, r7, r6
	str r5, [r0]
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0816143C @ =Cockatrice_OnReset
	str r0, [r1]
	ldr r2, _08161440 @ =0x000005BC
	adds r1, r7, r2
	ldr r0, _08161444 @ =Cockatrice_StateLookAround
	str r0, [r1]
	adds r3, #0xc
	adds r1, r7, r3
	ldr r0, _08161448 @ =FUN_0815ec0c
	str r0, [r1]
	adds r4, #0x10
	adds r1, r7, r4
	ldr r0, _0816144C @ =Cockatrice_NoticeHitTarget
	str r0, [r1]
	ldr r5, _08161450 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _08161454 @ =Cockatrice_OnDamaged
	str r0, [r1]
	subs r6, #0x3c
	adds r1, r7, r6
	ldr r0, _08161458 @ =Cockatrice_OnAttackRequest
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0816145C @ =Cockatrice_OnNoticeRequest
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x7c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r4, _08161460 @ =0x000001DF
	adds r1, r7, r4
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x50
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	bne _081613AA
	b _081614D0
_081613AA:
	bl VM_GetPC
	cmp r0, #0
	beq _08161464
	bl VM_GetValue
	adds r1, r0, #0
	b _08161466
	.align 2, 0
_081613BC: .4byte 0x0000072C
_081613C0: .4byte Cockatrice_UpdateFrame
_081613C4: .4byte Cockatrice_GetMoveSpeed
_081613C8: .4byte Cockatrice_StateTurn
_081613CC: .4byte Cockatrice_StateDamaged
_081613D0: .4byte Cockatrice_OnRouteFailed
_081613D4: .4byte FUN_080f62ac
_081613D8: .4byte Cockatrice_StateMove
_081613DC: .4byte Cockatrice_StateWait
_081613E0: .4byte Cockatrice_StateNap
_081613E4: .4byte Cockatrice_StateDying
_081613E8: .4byte FUN_080f44f4
_081613EC: .4byte FUN_080f410c
_081613F0: .4byte Cockatrice_StateHeardSound
_081613F4: .4byte Cockatrice_StateRespawnWait
_081613F8: .4byte FUN_080f0430
_081613FC: .4byte 0x085AD470
_08161400: .4byte FUN_080e73c8
_08161404: .4byte FUN_080f0320
_08161408: .4byte Enemy_080eff14
_0816140C: .4byte FUN_080e72b0
_08161410: .4byte Enemy_StateBlownAway
_08161414: .4byte Enemy_StateFallDeath
_08161418: .4byte FUN_080f6e64
_0816141C: .4byte Enemy_OnDamaged
_08161420: .4byte FUN_080f84d4
_08161424: .4byte FUN_080f624c
_08161428: .4byte FUN_080f56ec
_0816142C: .4byte FUN_080f5b34
_08161430: .4byte FUN_080f5fac
_08161434: .4byte Cockatrice_ReleaseTarget
_08161438: .4byte Cockatrice_TryDetectPlayer
_0816143C: .4byte Cockatrice_OnReset
_08161440: .4byte 0x000005BC
_08161444: .4byte Cockatrice_StateLookAround
_08161448: .4byte FUN_0815ec0c
_0816144C: .4byte Cockatrice_NoticeHitTarget
_08161450: .4byte 0x0000058C
_08161454: .4byte Cockatrice_OnDamaged
_08161458: .4byte Cockatrice_OnAttackRequest
_0816145C: .4byte Cockatrice_OnNoticeRequest
_08161460: .4byte 0x000001DF
_08161464:
	movs r1, #0x14
_08161466:
	ldr r5, [sp, #0x24]
	ldr r6, _0816147C @ =0x000006C5
	adds r0, r5, r6
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08161480
	bl VM_GetValue
	b _08161484
	.align 2, 0
_0816147C: .4byte 0x000006C5
_08161480:
	movs r0, #0x96
	lsls r0, r0, #1
_08161484:
	adds r1, r0, #0
	ldr r2, [sp, #0x24]
	ldr r3, _081614A0 @ =0x000006C6
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081614A4
	bl VM_GetValue
	adds r1, r0, #0
	b _081614A6
	.align 2, 0
_081614A0: .4byte 0x000006C6
_081614A4:
	movs r1, #0
_081614A6:
	ldr r4, [sp, #0x24]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r0, r4, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081614C0
	bl VM_GetValue
	adds r1, r0, #0
	b _081614C2
_081614C0:
	movs r1, #0
_081614C2:
	ldr r6, [sp, #0x24]
	ldr r2, _081614CC @ =0x000006F2
	adds r0, r6, r2
	strh r1, [r0]
	b _081614F2
	.align 2, 0
_081614CC: .4byte 0x000006F2
_081614D0:
	ldr r3, [sp, #0x24]
	ldr r4, _0816153C @ =0x000006C5
	adds r1, r3, r4
	movs r0, #0x14
	strb r0, [r1]
	ldr r5, _08161540 @ =0x000006C6
	adds r1, r3, r5
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #3
	adds r0, r3, r6
	strh r2, [r0]
	ldr r1, _08161544 @ =0x000006F2
	adds r0, r3, r1
	strh r2, [r0]
_081614F2:
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #0x55
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x24]
	ldr r4, _08161548 @ =0x000006FC
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08161556
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0816152C:
	bl VM_GetPC
	cmp r0, #0
	beq _0816154C
	bl VM_GetValue
	b _0816154E
	.align 2, 0
_0816153C: .4byte 0x000006C5
_08161540: .4byte 0x000006C6
_08161544: .4byte 0x000006F2
_08161548: .4byte 0x000006FC
_0816154C:
	movs r0, #0
_0816154E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0816152C
_08161556:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	cmp r2, #0
	beq _0816158E
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x78]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0816158E
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0816158E:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081615A0
	movs r0, #1
	b _081615A2
_081615A0:
	movs r0, #0
_081615A2:
	cmp r0, #0
	beq _081615B4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x7c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081615B4:
	cmp r2, #1
	beq _081615F4
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _08161604 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08161608 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x11c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xac]
	strb r1, [r6]
	ldr r0, [sp, #0xf0]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081615F4:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816160C
	movs r0, #1
	b _0816160E
	.align 2, 0
_08161604: .4byte 0x00000484
_08161608: .4byte 0x0000046C
_0816160C:
	movs r0, #0
_0816160E:
	cmp r0, #0
	beq _08161628
	ldr r0, _08161624 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x68]
	strh r0, [r5]
	b _08161632
	.align 2, 0
_08161624: .4byte 0x030046A0
_08161628:
	ldr r0, [sp, #0x30]
	bl GetZoneAt
	ldr r6, [sp, #0x68]
	strh r0, [r6]
_08161632:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08161642
	movs r0, #1
	b _08161644
_08161642:
	movs r0, #0
_08161644:
	cmp r0, #0
	beq _08161654
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08161678 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08161654:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08161686
	ldr r0, _0816167C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08161680
	movs r0, #1
	b _08161682
	.align 2, 0
_08161678: .4byte 0xFFFFFEFF
_0816167C: .4byte 0x030046A0
_08161680:
	movs r0, #0
_08161682:
	cmp r0, #0
	bne _0816168E
_08161686:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0816168E:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x138]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08161776
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
	beq _081616D0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081616D8
_081616D0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081616D8:
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
	beq _081616FC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08161704
_081616FC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08161704:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0816173C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08161780
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08161740
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08161734
	ldrb r0, [r4, #5]
_08161734:
	subs r0, #1
	strh r0, [r4, #8]
	b _08161750
	.align 2, 0
_0816173C: .4byte 0x0000FFFF
_08161740:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08161750
	strh r1, [r4, #8]
_08161750:
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
	bne _08161780
	movs r0, #1
	strb r0, [r4, #7]
	b _08161780
_08161776:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08161780:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08161798 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0816179C
	movs r0, #1
	b _0816179E
	.align 2, 0
_08161798: .4byte 0x030047A4
_0816179C:
	movs r0, #0
_0816179E:
	cmp r0, #0
	bne _081617DE
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081617C6
	adds r0, r1, #0
	cmp r0, #7
	beq _081617C6
	cmp r0, #6
	beq _081617C6
	cmp r0, #0x15
	beq _081617C6
	cmp r0, #0x14
	beq _081617C6
	cmp r0, #0x17
	bne _081617DE
_081617C6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081617DE:
	ldr r6, [sp, #0x94]
	ldr r4, [r6]
	ldr r0, [sp, #0xa0]
	ldr r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	movs r2, #0xda
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
	ldr r3, _08161894 @ =0x000006D4
	adds r4, r4, r3
	ldr r5, [sp, #0xa0]
	ldr r0, [r5]
	str r0, [r4]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Cockatrice_SetHandlerTable2
	adds r0, r7, #0
	bl Cockatrice_SetHandlerTable4
	adds r0, r7, #0
	bl Cockatrice_SetHandlerTable3
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ldr r1, [sp, #0xdc]
	strh r0, [r1]
	ldr r2, [sp, #0x90]
	ldrh r0, [r2]
	ldr r3, [sp, #0xd8]
	strh r0, [r3]
	ldr r4, [sp, #0x78]
	ldr r0, [r4]
	ldr r5, [sp, #0xb0]
	str r0, [r5]
	ldr r6, [sp, #0x7c]
	ldr r0, [r6]
	ldr r1, [sp, #0xb4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xb8]
	strb r0, [r2]
	ldr r3, [sp, #0x40]
	ldrb r0, [r3]
	ldr r4, [sp, #0xbc]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0xc4]
	strb r0, [r2]
	ldr r3, [sp, #0xf0]
	ldr r0, [r3]
	ldr r4, [sp, #0xc8]
	str r0, [r4]
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
	ldr r6, [sp, #0xd0]
	strb r0, [r6]
	ldr r0, _08161898 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _0816189C @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r2, _081618A0 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081618A4 @ =Cockatrice_Update
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081618A8 @ =Cockatrice_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081618AC
	movs r0, #0
	b _081618B0
	.align 2, 0
_08161894: .4byte 0x000006D4
_08161898: .4byte 0x0000057C
_0816189C: .4byte Enemy_DispatchMsg
_081618A0: .4byte 0x0000061C
_081618A4: .4byte Cockatrice_Update
_081618A8: .4byte Cockatrice_Destroy
_081618AC:
	movs r0, #1
	rsbs r0, r0, #0
_081618B0:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
