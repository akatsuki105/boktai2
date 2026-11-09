	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _08120A88 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _08120A8C @ =0x000001DF
	adds r1, r7, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r7, #0
	bl Golem_InitAnims
	ldr r3, _08120A90 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08120A9C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08120A94 @ =0x00005290
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08120A98 @ =0x00001E38
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _08120A8C @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xac]
	cmp r1, #0x11
	beq _08120A78
	cmp r1, #0x17
	bne _08120A7C
_08120A78:
	movs r0, #1
	strb r0, [r5, #7]
_08120A7C:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08120B04
	.align 2, 0
_08120A88: .4byte 0x0000065C
_08120A8C: .4byte 0x000001DF
_08120A90: .4byte 0x0000025D
_08120A94: .4byte 0x00005290
_08120A98: .4byte 0x00001E38
_08120A9C:
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
	ldr r2, _08120B80 @ =0x05000002
	bl CpuSet
	ldr r0, _08120B84 @ =0x0000CB05
	ldr r1, _08120B88 @ =0x00005290
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
	ldr r0, _08120B8C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08120B90 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xac]
_08120B04:
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
	ldr r5, _08120B94 @ =0x0000046F
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
	ldr r1, _08120B98 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08120B80 @ =0x05000002
	bl CpuSet
	ldr r3, _08120B9C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x5c]
	mov r3, r8
	str r3, [sp, #0x68]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _08120B70
	b _08120CD0
_08120B70:
	bl VM_GetPC
	cmp r0, #0
	beq _08120BA0
	bl VM_GetValue
	adds r1, r0, #0
	b _08120BA2
	.align 2, 0
_08120B80: .4byte 0x05000002
_08120B84: .4byte 0x0000CB05
_08120B88: .4byte 0x00005290
_08120B8C: .4byte 0x000004B7
_08120B90: .4byte 0x000001DF
_08120B94: .4byte 0x0000046F
_08120B98: .4byte 0x00000474
_08120B9C: .4byte 0x000004B6
_08120BA0:
	movs r1, #0
_08120BA2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08120BC8 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc8]
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _08120BCC
	bl VM_GetValue
	adds r1, r0, #0
	b _08120BCE
	.align 2, 0
_08120BC8: .4byte 0x00000251
_08120BCC:
	movs r1, #0
_08120BCE:
	ldr r2, _08120C04 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08120C08 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xc8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd4]
	cmp r0, #0
	beq _08120C0C
	bl VM_GetValue
	b _08120C10
	.align 2, 0
_08120C04: .4byte 0x00000252
_08120C08: .4byte 0x000004B4
_08120C0C:
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
_08120C10:
	strb r0, [r6]
	ldr r5, [sp, #0xc8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd4]
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
	blt _08120C48
	cmp r1, #0
	blt _08120C48
	ldr r0, _08120C4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120C48
	ldr r0, _08120C50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120C54
_08120C48:
	movs r1, #0
	b _08120C62
	.align 2, 0
_08120C4C: .4byte 0x030046A8
_08120C50: .4byte 0x030046AC
_08120C54:
	ldr r0, _08120C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08120C62:
	ldr r2, _08120C80 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08120C84
	adds r0, #4
	b _08120C90
	.align 2, 0
_08120C7C: .4byte 0x030046A4
_08120C80: .4byte 0x00000256
_08120C84:
	ldr r0, _08120CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08120C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08120CA8
	cmp r2, #2
	beq _08120CAC
	b _08120CB0
	.align 2, 0
_08120CA4: .4byte 0x030046A4
_08120CA8:
	ldrb r0, [r4, #4]
	b _08120CAE
_08120CAC:
	ldrb r0, [r4]
_08120CAE:
	subs r1, r1, r0
_08120CB0:
	ldr r3, _08120CC8 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08120CCC @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08120D10
	.align 2, 0
_08120CC8: .4byte 0x00000472
_08120CCC: .4byte 0x0000FFFF
_08120CD0:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08120D34 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08120D38 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08120D3C @ =0x000004B4
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
	str r5, [sp, #0xc8]
	str r4, [sp, #0xd0]
	str r3, [sp, #0xd4]
_08120D10:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08120D5A
	bl VM_GetPC
	cmp r0, #0
	beq _08120D40
	bl VM_GetValue
	adds r4, r0, #0
	b _08120D42
	.align 2, 0
_08120D34: .4byte 0x00000251
_08120D38: .4byte 0x00000252
_08120D3C: .4byte 0x000004B4
_08120D40:
	movs r4, #0x30
_08120D42:
	bl VM_GetPC
	cmp r0, #0
	beq _08120D54
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08120D56
_08120D54:
	movs r5, #0x40
_08120D56:
	mov r8, r4
	b _08120D60
_08120D5A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08120D60:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08120D98
	bl VM_GetPC
	cmp r0, #0
	beq _08120D7A
	bl VM_GetValue
	adds r6, r0, #0
	b _08120D7C
_08120D7A:
	movs r6, #0
_08120D7C:
	bl VM_GetPC
	cmp r0, #0
	beq _08120D8C
	bl VM_GetValue
	adds r1, r0, #0
	b _08120D8E
_08120D8C:
	movs r1, #0
_08120D8E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08120DA2
_08120D98:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08120DA2:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08121030 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	lsls r4, r4, #0x10
	str r4, [sp, #0xa0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa8]
	lsls r6, r6, #0x10
	str r6, [sp, #0xb0]
	lsls r5, r5, #0x10
	str r5, [sp, #0xa4]
	ldr r4, _08121034 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x98]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x30]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x34]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x38]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x194]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	ldr r1, _08121038 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _0812103C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r3, _08121040 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _08121044 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x50]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _08121048 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x110]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _0812104C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x134]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x148]
	ldr r2, _08121050 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08121054 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x154]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	ldr r5, _08121058 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _0812105C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x150]
	ldr r2, _08121060 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x114]
	ldr r3, _08121064 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x188]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x18c]
	ldr r5, _08121068 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	ldr r6, _0812106C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x190]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x178]
	ldr r2, _08121070 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _08121074 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x180]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x184]
	ldr r6, _08121078 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _0812107C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x144]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x168]
	ldr r5, _08121080 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x174]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _08121084 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _08121088 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x140]
	ldr r6, _0812108C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08121090 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x12c]
	ldr r3, _08121094 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	ldr r4, _08121098 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xc0]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x3c]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _0812109C @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081210A0 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081210A4 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081210A8 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x94]
	ldr r5, _081210AC @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0x108]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _081210B0 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe8]
	ldr r4, _081210B4 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _081210B8 @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081210BC @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _081210C0 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	ldr r3, _081210C4 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0x100]
	cmp r0, #0
	bne _08121000
	b _08121120
_08121000:
	movs r4, #0
	mov sl, r4
	movs r5, #0x8d
	lsls r5, r5, #2
	adds r5, r5, r7
	mov sb, r5
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r4, r7, r1
_08121020:
	bl VM_GetPC
	cmp r0, #0
	beq _081210C8
	bl VM_GetValue
	b _081210CA
	.align 2, 0
_08121030: .4byte 0x0000025D
_08121034: .4byte 0x0000025A
_08121038: .4byte 0x0000047A
_0812103C: .4byte 0x0000047C
_08121040: .4byte 0x0000047E
_08121044: .4byte 0x00000476
_08121048: .4byte 0x000004A4
_0812104C: .4byte 0x000005A4
_08121050: .4byte 0x000005C4
_08121054: .4byte 0x000005CC
_08121058: .4byte 0x000005D4
_0812105C: .4byte 0x000005DC
_08121060: .4byte 0x00000584
_08121064: .4byte 0x00000604
_08121068: .4byte 0x0000021D
_0812106C: .4byte 0x0000060C
_08121070: .4byte 0x000005E4
_08121074: .4byte 0x000005FC
_08121078: .4byte 0x00000614
_0812107C: .4byte 0x000005BC
_08121080: .4byte 0x000005EC
_08121084: .4byte 0x00000624
_08121088: .4byte 0x0000058C
_0812108C: .4byte 0x00000594
_08121090: .4byte 0x0000059C
_08121094: .4byte 0x000005B4
_08121098: .4byte 0x00000543
_0812109C: .4byte 0x00000496
_081210A0: .4byte 0x00000469
_081210A4: .4byte 0x0000046A
_081210A8: .4byte 0x00000553
_081210AC: .4byte 0x00000572
_081210B0: .4byte 0x0000055C
_081210B4: .4byte 0x00000564
_081210B8: .4byte 0x00000565
_081210BC: .4byte 0x00000566
_081210C0: .4byte 0x00000567
_081210C4: .4byte 0x0000056C
_081210C8:
	movs r0, #0x18
_081210CA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081210DC
	bl VM_GetValue
	b _081210DE
_081210DC:
	movs r0, #0x18
_081210DE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081210F0
	bl VM_GetValue
	b _081210F2
_081210F0:
	movs r0, #0
_081210F2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08121104
	bl VM_GetValue
	b _08121106
_08121104:
	movs r0, #0
_08121106:
	strh r0, [r6]
	movs r2, #2
	add sb, r2
	movs r3, #4
	add r8, r3
	adds r5, #2
	adds r4, #2
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #3
	bgt _08121120
	b _08121020
_08121120:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812116C
	bl VM_GetPC
	cmp r0, #0
	beq _0812113A
	bl VM_GetValue
	adds r4, r0, #0
	b _0812113E
_0812113A:
	movs r4, #0x96
	lsls r4, r4, #1
_0812113E:
	bl VM_GetPC
	cmp r0, #0
	beq _0812114E
	bl VM_GetValue
	adds r6, r0, #0
	b _08121152
_0812114E:
	movs r6, #0x96
	lsls r6, r6, #1
_08121152:
	bl VM_GetPC
	cmp r0, #0
	beq _08121160
	bl VM_GetValue
	b _08121166
_08121160:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08121166:
	ldr r2, [sp, #0xc4]
	strh r0, [r2]
	b _08121174
_0812116C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc4]
	strh r6, [r3]
_08121174:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0812118C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x68]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0812118C:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x7c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x78]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812125C
	bl VM_GetPC
	cmp r0, #0
	beq _081211BC
	bl VM_GetValue
	b _081211BE
_081211BC:
	movs r0, #0
_081211BE:
	ldr r3, [sp, #0xd8]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081211CC
	asrs r1, r0, #1
	b _081211D2
_081211CC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081211D2:
	ldr r5, _081211E8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081211EC
	bl VM_GetValue
	b _081211EE
	.align 2, 0
_081211E8: .4byte 0x00000546
_081211EC:
	movs r0, #0
_081211EE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121204
	bl VM_GetValue
	b _08121206
_08121204:
	movs r0, #0
_08121206:
	ldr r3, _0812121C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121220
	bl VM_GetValue
	adds r1, r0, #0
	b _08121222
	.align 2, 0
_0812121C: .4byte 0x00000187
_08121220:
	movs r1, #0
_08121222:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08121238
	bl VM_GetValue
	b _0812123A
_08121238:
	movs r0, #0
_0812123A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121252
	bl VM_GetValue
	adds r1, r0, #0
	b _08121254
_08121252:
	movs r1, #0
_08121254:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0812125C:
	ldr r5, [sp, #0xd8]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0xa0]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xa8]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xb0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xa4]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081212BE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081212A4
	bl VM_GetValue
	b _081212A6
_081212A4:
	movs r0, #0
_081212A6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081212B6
	bl VM_GetValue
	b _081212B8
_081212B6:
	movs r0, #0
_081212B8:
	ldr r6, _08121320 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081212BE:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xe0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081212E2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x68]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081212E2:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081212FA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081212FA:
	ldr r4, [sp, #0x98]
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
	beq _08121324
	movs r0, #1
	b _08121326
	.align 2, 0
_08121320: .4byte 0x00000189
_08121324:
	movs r0, #0
_08121326:
	cmp r0, #0
	beq _08121336
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08121360 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_08121336:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08121342
	ldr r1, [r7, #0x44]
_08121342:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0xac]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08121364
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08121370
	.align 2, 0
_08121360: .4byte Enemy_OnCWolfMessage
_08121364:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08121370:
	ldr r2, [sp, #0xac]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081213BE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081213BE
	cmp r0, #0x16
	beq _081213BE
	cmp r0, #0x14
	beq _081213BE
	cmp r0, #9
	beq _081213BE
	cmp r0, #0x19
	beq _081213BE
	cmp r0, #0x1a
	beq _081213BE
	cmp r0, #0xd
	beq _081213BE
	cmp r0, #0x1b
	beq _081213BE
	cmp r0, #0x1f
	beq _081213BE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_081213BE:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081213CE
	movs r0, #1
	b _081213D0
_081213CE:
	movs r0, #0
_081213D0:
	cmp r0, #0
	beq _081213DE
	ldr r1, [sp, #0xb8]
	ldr r0, [r1]
	ldr r2, [sp, #0xb4]
	str r0, [r2]
	b _081213F0
_081213DE:
	ldr r3, [sp, #0xb8]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb4]
	str r0, [r4]
_081213F0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x34]
	strh r0, [r5]
	ldr r6, [sp, #0x194]
	ldr r0, [sp, #0x38]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0812141A
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
_0812141A:
	ldr r4, _08121454 @ =0x00000201
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	ldr r6, [sp, #0x58]
	strh r4, [r6]
	ldr r0, [sp, #0x60]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xe4]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08121458
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08121464
	.align 2, 0
_08121454: .4byte 0x00000201
_08121458:
	ldr r2, [r7, #0x44]
	ldr r0, _0812149C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08121464:
	ldr r3, [sp, #0xe4]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081214B4
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081214A0
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
	b _081214AA
	.align 2, 0
_0812149C: .4byte 0x03003584
_081214A0:
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081214AA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081214B4:
	movs r4, #0
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	adds r0, #2
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	adds r0, r7, #0
	bl Golem_InitHitboxes
	ldr r3, [sp, #0x24]
	ldr r5, _08121670 @ =0x0000066C
	adds r0, r3, r5
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r3, r3, r6
	mov r8, r3
	ldr r1, _08121674 @ =Golem_UpdateFrame
	mov sb, r1
	ldr r2, _08121678 @ =Golem_GetMoveSpeed
	mov sl, r2
	ldr r3, _0812167C @ =Golem_StateTurn
	mov ip, r3
	ldr r5, _08121680 @ =Golem_StateDamaged
	ldr r3, _08121684 @ =FUN_080f62b0
	ldr r6, _08121688 @ =FUN_080f62ac
	str r6, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x5c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x8c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x110]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x118]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x120]
	str r2, [r6]
	ldr r1, _0812168C @ =Golem_StateMove
	ldr r2, [sp, #0x130]
	str r1, [r2]
	ldr r6, _08121690 @ =Golem_StateWait
	ldr r1, [sp, #0x134]
	str r6, [r1]
	ldr r2, _08121694 @ =Golem_StateNap
	ldr r6, [sp, #0x148]
	str r2, [r6]
	ldr r1, [sp, #0x14c]
	str r3, [r1]
	ldr r2, [sp, #0x154]
	str r5, [r2]
	ldr r3, _08121698 @ =Golem_StateDying
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _0812169C @ =FUN_080f44f4
	ldr r6, [sp, #0x15c]
	str r1, [r6]
	ldr r1, _081216A0 @ =FUN_080f410c
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _081216A4 @ =Golem_StateHeardSound
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r6, _081216A8 @ =Golem_StateRespawnWait
	ldr r1, [sp, #0x114]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x188]
	str r2, [r3]
	ldr r1, _081216AC @ =FUN_080f0430
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r1, _081216B0 @ =0x085AD470
	ldr r2, [sp, #0x190]
	str r1, [r2]
	ldr r1, _081216B4 @ =FUN_080e73c8
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
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081216B8 @ =FUN_080f0320
	ldr r5, [sp, #0x19c]
	str r1, [r5]
	ldr r1, _081216BC @ =Enemy_080eff14
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _081216C0 @ =FUN_080e72b0
	ldr r2, [sp, #0x170]
	str r1, [r2]
	ldr r3, _081216C4 @ =FUN_0811aa64
	ldr r5, [sp, #0x168]
	str r3, [r5]
	ldr r1, _081216C8 @ =Enemy_StateBlownAway
	ldr r6, [sp, #0x174]
	str r1, [r6]
	ldr r1, _081216CC @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r4, [r3]
	ldr r1, _081216D0 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a0]
	str r1, [r5]
	ldr r1, _081216D4 @ =Enemy_OnDamaged
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _081216D8 @ =FUN_080f84d4
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _081216DC @ =FUN_080f624c
	ldr r3, [sp, #0x140]
	str r1, [r3]
	ldr r1, _081216E0 @ =FUN_080f56ec
	ldr r5, [sp, #0x124]
	str r1, [r5]
	ldr r1, _081216E4 @ =FUN_080f5b34
	ldr r6, [sp, #0x128]
	str r1, [r6]
	ldr r1, _081216E8 @ =FUN_080f5fac
	ldr r2, [sp, #0x12c]
	str r1, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	movs r1, #0x28
	ldr r5, [sp, #0xc0]
	strb r1, [r5]
	ldr r1, [sp, #0x194]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081216EC @ =Golem_OnReset
	str r0, [r1]
	ldr r0, _081216F0 @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _081216F4 @ =FUN_08115f78
	str r0, [r1]
	ldr r2, _081216F8 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081216FC @ =Golem_OnAttackRequest
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08121700 @ =FUN_08115874
	str r0, [r1]
	ldr r5, _08121704 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _08121708 @ =Golem_OnDamaged
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0812170C @ =0x08000008
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r4, [sp, #0x3c]
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x80]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812171A
	subs r6, #0x20
	adds r5, r7, r6
	movs r4, #4
_08121660:
	bl VM_GetPC
	cmp r0, #0
	beq _08121710
	bl VM_GetValue
	b _08121712
	.align 2, 0
_08121670: .4byte 0x0000066C
_08121674: .4byte Golem_UpdateFrame
_08121678: .4byte Golem_GetMoveSpeed
_0812167C: .4byte Golem_StateTurn
_08121680: .4byte Golem_StateDamaged
_08121684: .4byte FUN_080f62b0
_08121688: .4byte FUN_080f62ac
_0812168C: .4byte Golem_StateMove
_08121690: .4byte Golem_StateWait
_08121694: .4byte Golem_StateNap
_08121698: .4byte Golem_StateDying
_0812169C: .4byte FUN_080f44f4
_081216A0: .4byte FUN_080f410c
_081216A4: .4byte Golem_StateHeardSound
_081216A8: .4byte Golem_StateRespawnWait
_081216AC: .4byte FUN_080f0430
_081216B0: .4byte 0x085AD470
_081216B4: .4byte FUN_080e73c8
_081216B8: .4byte FUN_080f0320
_081216BC: .4byte Enemy_080eff14
_081216C0: .4byte FUN_080e72b0
_081216C4: .4byte FUN_0811aa64
_081216C8: .4byte Enemy_StateBlownAway
_081216CC: .4byte Enemy_StateFallDeath
_081216D0: .4byte FUN_080f6e64
_081216D4: .4byte Enemy_OnDamaged
_081216D8: .4byte FUN_080f84d4
_081216DC: .4byte FUN_080f624c
_081216E0: .4byte FUN_080f56ec
_081216E4: .4byte FUN_080f5b34
_081216E8: .4byte FUN_080f5fac
_081216EC: .4byte Golem_OnReset
_081216F0: .4byte 0x000005FC
_081216F4: .4byte FUN_08115f78
_081216F8: .4byte 0x000005AC
_081216FC: .4byte Golem_OnAttackRequest
_08121700: .4byte FUN_08115874
_08121704: .4byte 0x0000058C
_08121708: .4byte Golem_OnDamaged
_0812170C: .4byte 0x08000008
_08121710:
	movs r0, #0
_08121712:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08121660
_0812171A:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x74]
	strh r0, [r3]
	cmp r2, #0
	beq _08121752
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x5c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08121752
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08121752:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08121764
	movs r0, #1
	b _08121766
_08121764:
	movs r0, #0
_08121766:
	cmp r0, #0
	beq _08121778
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x68]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08121778:
	cmp r2, #1
	beq _081217B8
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081217C8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081217CC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x134]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xcc]
	strb r1, [r6]
	ldr r0, [sp, #0x10c]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081217B8:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081217D0
	movs r0, #1
	b _081217D2
	.align 2, 0
_081217C8: .4byte 0x00000484
_081217CC: .4byte 0x0000046C
_081217D0:
	movs r0, #0
_081217D2:
	cmp r0, #0
	beq _081217EC
	ldr r0, _081217E8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x70]
	strh r0, [r5]
	b _081217F6
	.align 2, 0
_081217E8: .4byte 0x030046A0
_081217EC:
	ldr r0, [sp, #0x194]
	bl GetZoneAt
	ldr r6, [sp, #0x70]
	strh r0, [r6]
_081217F6:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08121806
	movs r0, #1
	b _08121808
_08121806:
	movs r0, #0
_08121808:
	cmp r0, #0
	beq _08121816
	ldr r0, _0812183C @ =0xFFFFFEFF
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
_08121816:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0812184A
	ldr r0, _08121840 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x70]
	ldrh r5, [r5]
	cmp r0, r5
	bne _08121844
	movs r0, #1
	b _08121846
	.align 2, 0
_0812183C: .4byte 0xFFFFFEFF
_08121840: .4byte 0x030046A0
_08121844:
	movs r0, #0
_08121846:
	cmp r0, #0
	bne _08121852
_0812184A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_08121852:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0812193A
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
	beq _08121894
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0812189C
_08121894:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0812189C:
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
	beq _081218C0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081218C8
_081218C0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081218C8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08121900 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08121944
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08121904
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081218F8
	ldrb r0, [r4, #5]
_081218F8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08121914
	.align 2, 0
_08121900: .4byte 0x0000FFFF
_08121904:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _08121914
	strh r1, [r4, #8]
_08121914:
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
	bne _08121944
	movs r0, #1
	strb r0, [r4, #7]
	b _08121944
_0812193A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08121944:
	movs r0, #0
	ldr r6, [sp, #0x9c]
	str r0, [r6]
	ldr r0, _0812195C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08121960
	movs r0, #1
	b _08121962
	.align 2, 0
_0812195C: .4byte 0x030047A4
_08121960:
	movs r0, #0
_08121962:
	cmp r0, #0
	bne _081219A2
	ldr r0, [sp, #0xac]
	ldrb r1, [r0]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812198A
	adds r0, r1, #0
	cmp r0, #7
	beq _0812198A
	cmp r0, #6
	beq _0812198A
	cmp r0, #0x15
	beq _0812198A
	cmp r0, #0x14
	beq _0812198A
	cmp r0, #0x17
	bne _081219A2
_0812198A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x4c]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081219A2:
	ldr r3, [sp, #0x94]
	ldr r0, [r3]
	movs r4, #0xcc
	lsls r4, r4, #3
	adds r0, r0, r4
	ldr r5, [sp, #0xb4]
	ldr r1, [r5]
	str r1, [r0]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Golem_SetHandlerTable3
	adds r0, r7, #0
	bl Golem_SetHandlerTable4
	ldr r6, [sp, #0x24]
	ldr r1, _08121A7C @ =0x000006C1
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	adds r4, #0x54
	adds r3, r6, r4
	movs r4, #0
	movs r0, #0x78
	strh r0, [r3]
	ldr r5, _08121A80 @ =0x000006BA
	adds r0, r6, r5
	strh r2, [r0]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _08121A84 @ =0x000006B6
	adds r0, r6, r1
	strh r2, [r0]
	movs r0, #0xa0
	strh r0, [r3]
	ldr r3, _08121A88 @ =0x000006BE
	adds r0, r6, r3
	strh r2, [r0]
	subs r5, #0x62
	adds r0, r6, r5
	strb r4, [r0]
	adds r1, #0x11
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ldr r3, [sp, #0x108]
	strh r0, [r3]
	ldr r4, [sp, #0x90]
	ldrh r0, [r4]
	ldr r5, [sp, #0x104]
	strh r0, [r5]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	ldr r1, [sp, #0xdc]
	str r0, [r1]
	ldr r2, [sp, #0x68]
	ldr r0, [r2]
	ldr r3, [sp, #0xe8]
	str r0, [r3]
	ldrb r0, [r7, #5]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0xf4]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf8]
	strb r0, [r4]
	ldr r5, [sp, #0x10c]
	ldr r0, [r5]
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r1, [sp, #0xcc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x100]
	strb r0, [r2]
	ldr r3, _08121A8C @ =0x0000057C
	adds r1, r7, r3
	ldr r0, _08121A90 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r4, _08121A94 @ =0x0000061C
	adds r1, r7, r4
	ldr r0, _08121A98 @ =Golem_Update
	str r0, [r1]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08121A9C @ =Golem_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08121AA0
	movs r0, #0
	b _08121AA4
	.align 2, 0
_08121A7C: .4byte 0x000006C1
_08121A80: .4byte 0x000006BA
_08121A84: .4byte 0x000006B6
_08121A88: .4byte 0x000006BE
_08121A8C: .4byte 0x0000057C
_08121A90: .4byte Enemy_DispatchMsg
_08121A94: .4byte 0x0000061C
_08121A98: .4byte Golem_Update
_08121A9C: .4byte Golem_Destroy
_08121AA0:
	movs r0, #1
	rsbs r0, r0, #0
_08121AA4:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
