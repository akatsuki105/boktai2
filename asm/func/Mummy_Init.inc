	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _0812CB98 @ =0x0000071E
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _0812CB9C @ =0x000001DF
	adds r0, r7, r2
	movs r3, #1
	mov r8, r3
	mov r4, r8
	strb r4, [r0]
	adds r0, r7, #0
	bl Mummy_InitAnims
	ldr r5, _0812CBA0 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812CBAC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0812CBA4 @ =0x000048DE
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0812CBA8 @ =0x0000A4B2
	bl EnemyAuxSprite_LoadAnim
	ldr r6, _0812CB9C @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x44]
	cmp r1, #0x11
	beq _0812CB88
	cmp r1, #0x17
	bne _0812CB8C
_0812CB88:
	mov r0, r8
	strb r0, [r5, #7]
_0812CB8C:
	movs r2, #0xef
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	b _0812CC14
	.align 2, 0
_0812CB98: .4byte 0x0000071E
_0812CB9C: .4byte 0x000001DF
_0812CBA0: .4byte 0x0000025D
_0812CBA4: .4byte 0x000048DE
_0812CBA8: .4byte 0x0000A4B2
_0812CBAC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r3, sp, #0x14
	mov r8, r3
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _0812CC94 @ =0x05000002
	bl CpuSet
	ldr r0, _0812CC98 @ =0x0000CB05
	ldr r1, _0812CC9C @ =0x000048DE
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r5, r6}
	stm r2!, {r5, r6}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r2, _0812CCA0 @ =0x000004B7
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _0812CCA4 @ =0x000001DF
	adds r3, r7, r3
	str r3, [sp, #0x44]
_0812CC14:
	str r7, [sp, #0x28]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	movs r4, #0
	mov r5, sb
	str r4, [r5]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	str r4, [r6]
	ldr r1, _0812CCA8 @ =0x0000046F
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	mov sl, r3
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, _0812CCAC @ =0x00000474
	adds r6, r7, r5
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0812CC94 @ =0x05000002
	bl CpuSet
	ldr r0, _0812CCB0 @ =0x000004B6
	adds r2, r7, r0
	mov r1, sl
	strb r1, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl VM_SeekToNamedArg
	mov r3, sb
	str r3, [sp, #0x180]
	mov r4, r8
	str r4, [sp, #0x188]
	str r6, [sp, #0x164]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _0812CC82
	b _0812CDE4
_0812CC82:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CCB4
	bl VM_GetValue
	adds r1, r0, #0
	b _0812CCB6
	.align 2, 0
_0812CC94: .4byte 0x05000002
_0812CC98: .4byte 0x0000CB05
_0812CC9C: .4byte 0x000048DE
_0812CCA0: .4byte 0x000004B7
_0812CCA4: .4byte 0x000001DF
_0812CCA8: .4byte 0x0000046F
_0812CCAC: .4byte 0x00000474
_0812CCB0: .4byte 0x000004B6
_0812CCB4:
	movs r1, #0
_0812CCB6:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0812CCDC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x80]
	str r4, [sp, #0x88]
	cmp r0, #0
	beq _0812CCE0
	bl VM_GetValue
	adds r1, r0, #0
	b _0812CCE2
	.align 2, 0
_0812CCDC: .4byte 0x00000251
_0812CCE0:
	movs r1, #0
_0812CCE2:
	ldr r2, _0812CD18 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0812CD1C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x80]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x90]
	cmp r0, #0
	beq _0812CD20
	bl VM_GetValue
	b _0812CD24
	.align 2, 0
_0812CD18: .4byte 0x00000252
_0812CD1C: .4byte 0x000004B4
_0812CD20:
	ldr r4, [sp, #0x80]
	ldrb r0, [r4]
_0812CD24:
	strb r0, [r6]
	ldr r5, [sp, #0x80]
	ldrb r1, [r5]
	ldr r6, [sp, #0x90]
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
	blt _0812CD5C
	cmp r1, #0
	blt _0812CD5C
	ldr r0, _0812CD60 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812CD5C
	ldr r0, _0812CD64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812CD68
_0812CD5C:
	movs r1, #0
	b _0812CD76
	.align 2, 0
_0812CD60: .4byte 0x030046A8
_0812CD64: .4byte 0x030046AC
_0812CD68:
	ldr r0, _0812CD90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0812CD76:
	ldr r2, _0812CD94 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812CD98
	adds r0, #4
	b _0812CDA4
	.align 2, 0
_0812CD90: .4byte 0x030046A4
_0812CD94: .4byte 0x00000256
_0812CD98:
	ldr r0, _0812CDB8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812CDA4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812CDBC
	cmp r2, #2
	beq _0812CDC0
	b _0812CDC4
	.align 2, 0
_0812CDB8: .4byte 0x030046A4
_0812CDBC:
	ldrb r0, [r4, #4]
	b _0812CDC2
_0812CDC0:
	ldrb r0, [r4]
_0812CDC2:
	subs r1, r1, r0
_0812CDC4:
	ldr r3, _0812CDDC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0812CDE0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _0812CE24
	.align 2, 0
_0812CDDC: .4byte 0x00000472
_0812CDE0: .4byte 0x0000FFFF
_0812CDE4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0812CE48 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0812CE4C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0812CE50 @ =0x000004B4
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
	str r5, [sp, #0x80]
	str r4, [sp, #0x88]
	str r3, [sp, #0x90]
_0812CE24:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812CE6E
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE54
	bl VM_GetValue
	adds r4, r0, #0
	b _0812CE56
	.align 2, 0
_0812CE48: .4byte 0x00000251
_0812CE4C: .4byte 0x00000252
_0812CE50: .4byte 0x000004B4
_0812CE54:
	movs r4, #0x30
_0812CE56:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE68
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0812CE6A
_0812CE68:
	movs r5, #0x40
_0812CE6A:
	mov r8, r4
	b _0812CE74
_0812CE6E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0812CE74:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812CEAC
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE8E
	bl VM_GetValue
	adds r6, r0, #0
	b _0812CE90
_0812CE8E:
	movs r6, #0
_0812CE90:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CEA0
	bl VM_GetValue
	adds r1, r0, #0
	b _0812CEA2
_0812CEA0:
	movs r1, #0
_0812CEA2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0812CEB6
_0812CEAC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0812CEB6:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0812D144 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x198]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x94]
	lsls r4, r4, #0x10
	str r4, [sp, #0x40]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x4c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x50]
	lsls r5, r5, #0x10
	str r5, [sp, #0x48]
	ldr r4, _0812D148 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x3c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x148]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x54]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x58]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x14c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x150]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x144]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _0812D14C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0812D150 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x174]
	ldr r3, _0812D154 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _0812D158 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x168]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _0812D15C @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x190]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x194]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xc0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd0]
	ldr r6, _0812D160 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	ldr r2, _0812D164 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0xec]
	ldr r3, _0812D168 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _0812D16C @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	ldr r6, _0812D170 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x104]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _0812D174 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r3, _0812D178 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x128]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	ldr r5, _0812D17C @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _0812D180 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x118]
	ldr r2, _0812D184 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	ldr r4, _0812D188 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _0812D18C @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x134]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _0812D190 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x110]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x108]
	ldr r5, _0812D194 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x114]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _0812D198 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _0812D19C @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x140]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _0812D1A0 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _0812D1A4 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _0812D1A8 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	ldr r4, _0812D1AC @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x60]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x154]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1a0]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _0812D1B0 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x18c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x158]
	ldr r4, _0812D1B4 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _0812D1B8 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _0812D1BC @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x64]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x38]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _0812D1C0 @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x30]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	ldr r2, _0812D1C4 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0x68]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _0812D1C8 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _0812D1CC @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0x78]
	ldr r6, _0812D1D0 @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0x7c]
	ldr r1, _0812D1D4 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0x84]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	ldr r3, _0812D1D8 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0x98]
	cmp r0, #0
	bne _0812D114
	b _0812D234
_0812D114:
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
_0812D134:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D1DC
	bl VM_GetValue
	b _0812D1DE
	.align 2, 0
_0812D144: .4byte 0x0000025D
_0812D148: .4byte 0x0000025A
_0812D14C: .4byte 0x0000047A
_0812D150: .4byte 0x0000047C
_0812D154: .4byte 0x0000047E
_0812D158: .4byte 0x00000476
_0812D15C: .4byte 0x000004A4
_0812D160: .4byte 0x000005A4
_0812D164: .4byte 0x000005C4
_0812D168: .4byte 0x000005CC
_0812D16C: .4byte 0x000005D4
_0812D170: .4byte 0x000005DC
_0812D174: .4byte 0x00000584
_0812D178: .4byte 0x00000604
_0812D17C: .4byte 0x0000021D
_0812D180: .4byte 0x0000060C
_0812D184: .4byte 0x000005E4
_0812D188: .4byte 0x000005FC
_0812D18C: .4byte 0x00000614
_0812D190: .4byte 0x000005BC
_0812D194: .4byte 0x000005EC
_0812D198: .4byte 0x00000624
_0812D19C: .4byte 0x0000058C
_0812D1A0: .4byte 0x00000594
_0812D1A4: .4byte 0x0000059C
_0812D1A8: .4byte 0x000005B4
_0812D1AC: .4byte 0x00000543
_0812D1B0: .4byte 0x00000496
_0812D1B4: .4byte 0x00000469
_0812D1B8: .4byte 0x0000046A
_0812D1BC: .4byte 0x00000553
_0812D1C0: .4byte 0x00000572
_0812D1C4: .4byte 0x0000055C
_0812D1C8: .4byte 0x00000564
_0812D1CC: .4byte 0x00000565
_0812D1D0: .4byte 0x00000566
_0812D1D4: .4byte 0x00000567
_0812D1D8: .4byte 0x0000056C
_0812D1DC:
	movs r0, #0x18
_0812D1DE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0812D1F0
	bl VM_GetValue
	b _0812D1F2
_0812D1F0:
	movs r0, #0x18
_0812D1F2:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0812D204
	bl VM_GetValue
	b _0812D206
_0812D204:
	movs r0, #0
_0812D206:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0812D218
	bl VM_GetValue
	b _0812D21A
_0812D218:
	movs r0, #0
_0812D21A:
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
	bgt _0812D234
	b _0812D134
_0812D234:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812D280
	bl VM_GetPC
	cmp r0, #0
	beq _0812D24E
	bl VM_GetValue
	adds r4, r0, #0
	b _0812D252
_0812D24E:
	movs r4, #0x96
	lsls r4, r4, #1
_0812D252:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D262
	bl VM_GetValue
	adds r6, r0, #0
	b _0812D266
_0812D262:
	movs r6, #0x96
	lsls r6, r6, #1
_0812D266:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D274
	bl VM_GetValue
	b _0812D27A
_0812D274:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_0812D27A:
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	b _0812D288
_0812D280:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x70]
	strh r6, [r3]
_0812D288:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0812D2A0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x188]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0812D2A0:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x198]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812D370
	bl VM_GetPC
	cmp r0, #0
	beq _0812D2D0
	bl VM_GetValue
	b _0812D2D2
_0812D2D0:
	movs r0, #0
_0812D2D2:
	ldr r3, [sp, #0x94]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _0812D2E0
	asrs r1, r0, #1
	b _0812D2E6
_0812D2E0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0812D2E6:
	ldr r5, _0812D2FC @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D300
	bl VM_GetValue
	b _0812D302
	.align 2, 0
_0812D2FC: .4byte 0x00000546
_0812D300:
	movs r0, #0
_0812D302:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D318
	bl VM_GetValue
	b _0812D31A
_0812D318:
	movs r0, #0
_0812D31A:
	ldr r3, _0812D330 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D334
	bl VM_GetValue
	adds r1, r0, #0
	b _0812D336
	.align 2, 0
_0812D330: .4byte 0x00000187
_0812D334:
	movs r1, #0
_0812D336:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D34C
	bl VM_GetValue
	b _0812D34E
_0812D34C:
	movs r0, #0
_0812D34E:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D366
	bl VM_GetValue
	adds r1, r0, #0
	b _0812D368
_0812D366:
	movs r1, #0
_0812D368:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0812D370:
	ldr r5, [sp, #0x94]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0x40]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x4c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x50]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x48]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812D3D2
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0812D3B8
	bl VM_GetValue
	b _0812D3BA
_0812D3B8:
	movs r0, #0
_0812D3BA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D3CA
	bl VM_GetValue
	b _0812D3CC
_0812D3CA:
	movs r0, #0
_0812D3CC:
	ldr r6, _0812D434 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_0812D3D2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xa0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0812D3F6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x188]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0812D3F6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0812D40E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_0812D40E:
	ldr r4, [sp, #0x3c]
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
	ldr r5, [sp, #0x164]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812D438
	movs r0, #1
	b _0812D43A
	.align 2, 0
_0812D434: .4byte 0x00000189
_0812D438:
	movs r0, #0
_0812D43A:
	cmp r0, #0
	beq _0812D44A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0812D474 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_0812D44A:
	ldr r6, [sp, #0xa8]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _0812D456
	ldr r1, [r7, #0x44]
_0812D456:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _0812D478
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _0812D484
	.align 2, 0
_0812D474: .4byte Enemy_OnCWolfMessage
_0812D478:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_0812D484:
	ldr r2, [sp, #0x44]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812D4D2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0812D4D2
	cmp r0, #0x16
	beq _0812D4D2
	cmp r0, #0x14
	beq _0812D4D2
	cmp r0, #9
	beq _0812D4D2
	cmp r0, #0x19
	beq _0812D4D2
	cmp r0, #0x1a
	beq _0812D4D2
	cmp r0, #0xd
	beq _0812D4D2
	cmp r0, #0x1b
	beq _0812D4D2
	cmp r0, #0x1f
	beq _0812D4D2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x80]
	ldrb r2, [r3]
	ldr r4, [sp, #0x88]
	ldrb r3, [r4]
	ldr r5, [sp, #0x90]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_0812D4D2:
	movs r1, #8
	ldr r6, [sp, #0x164]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0812D4E2
	movs r0, #1
	b _0812D4E4
_0812D4E2:
	movs r0, #0
_0812D4E4:
	cmp r0, #0
	beq _0812D4F2
	ldr r1, [sp, #0x58]
	ldr r0, [r1]
	ldr r2, [sp, #0x54]
	str r0, [r2]
	b _0812D504
_0812D4F2:
	ldr r3, [sp, #0x58]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x54]
	str r0, [r4]
_0812D504:
	ldrh r0, [r7]
	ldr r5, [sp, #0x14c]
	strh r0, [r5]
	ldr r6, [sp, #0x144]
	ldr r0, [sp, #0x150]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0812D52E
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
_0812D52E:
	movs r4, #0x17
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x17c]
	strh r0, [r3]
	ldr r6, [sp, #0x170]
	strh r4, [r6]
	ldr r0, [sp, #0x174]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0x17
	ldr r1, [sp, #0x178]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xa8]
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812D568
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0812D574
_0812D568:
	ldr r2, [r7, #0x44]
	ldr r0, _0812D5AC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0812D574:
	ldr r3, [sp, #0xa8]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0812D5C4
	ldr r4, [sp, #0x44]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0812D5B0
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
	b _0812D5BA
	.align 2, 0
_0812D5AC: .4byte 0x03003584
_0812D5B0:
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0812D5BA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0812D5C4:
	ldr r6, _0812D7B0 @ =0x0000047A
	adds r0, r7, r6
	ldrh r0, [r0]
	adds r0, #3
	ldr r2, _0812D7B4 @ =0x0000047E
	adds r1, r7, r2
	movs r4, #0
	strh r0, [r1]
	ldr r3, [sp, #0x170]
	ldrh r0, [r3]
	adds r0, #4
	ldr r5, [sp, #0x168]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x16c]
	strh r0, [r6]
	adds r0, r7, #0
	bl Mummy_InitHitboxes
	ldr r1, [sp, #0x24]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _0812D7B8 @ =0x00000744
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _0812D7BC @ =Mummy_UpdateFrame
	mov sb, r5
	ldr r6, _0812D7C0 @ =Mummy_GetMoveSpeed
	mov sl, r6
	ldr r1, _0812D7C4 @ =Mummy_StateTurn
	mov ip, r1
	ldr r5, _0812D7C8 @ =Mummy_StateDamaged
	ldr r3, _0812D7CC @ =FUN_080f62b0
	ldr r2, _0812D7D0 @ =FUN_080f62ac
	str r2, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x180]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x190]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x194]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xb0]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xb8]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0xc0]
	str r2, [r6]
	ldr r1, _0812D7D4 @ =Mummy_StateMove
	ldr r2, [sp, #0xd0]
	str r1, [r2]
	ldr r6, _0812D7D8 @ =Mummy_StateWait
	ldr r1, [sp, #0xd4]
	str r6, [r1]
	ldr r2, _0812D7DC @ =Mummy_StateNap
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	ldr r1, [sp, #0xec]
	str r3, [r1]
	ldr r2, [sp, #0xf4]
	str r5, [r2]
	ldr r3, _0812D7E0 @ =Mummy_StateDying
	ldr r5, [sp, #0xf8]
	str r3, [r5]
	ldr r1, _0812D7E4 @ =FUN_080f44f4
	ldr r6, [sp, #0xfc]
	str r1, [r6]
	ldr r1, _0812D7E8 @ =FUN_080f410c
	ldr r2, [sp, #0x104]
	str r1, [r2]
	ldr r3, _0812D7EC @ =Mummy_StateHeardSound
	ldr r5, [sp, #0xf0]
	str r3, [r5]
	ldr r6, _0812D7F0 @ =Mummy_StateRespawnWait
	ldr r1, [sp, #0xb4]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x128]
	str r2, [r3]
	ldr r1, _0812D7F4 @ =FUN_080f0430
	ldr r5, [sp, #0x12c]
	str r1, [r5]
	movs r1, #3
	ldr r6, [sp, #0x5c]
	strb r1, [r6]
	ldr r1, _0812D7F8 @ =0x085AD470
	ldr r2, [sp, #0x130]
	str r1, [r2]
	ldr r1, _0812D7FC @ =FUN_080e73c8
	ldr r3, [sp, #0x118]
	str r1, [r3]
	ldr r5, [sp, #0x10c]
	str r4, [r5]
	ldr r6, [sp, #0x11c]
	str r4, [r6]
	ldr r1, [sp, #0x120]
	str r4, [r1]
	ldr r2, [sp, #0x124]
	str r4, [r2]
	ldr r3, [sp, #0x134]
	str r4, [r3]
	ldr r1, _0812D800 @ =FUN_080f0320
	ldr r5, [sp, #0x138]
	str r1, [r5]
	ldr r1, _0812D804 @ =Enemy_080eff14
	ldr r6, [sp, #0xe4]
	str r1, [r6]
	ldr r1, _0812D808 @ =FUN_080e72b0
	ldr r2, [sp, #0x110]
	str r1, [r2]
	ldr r3, _0812D80C @ =FUN_08122388
	ldr r5, [sp, #0x108]
	str r3, [r5]
	ldr r1, _0812D810 @ =Enemy_StateBlownAway
	ldr r6, [sp, #0x114]
	str r1, [r6]
	ldr r1, _0812D814 @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x100]
	str r1, [r2]
	ldr r3, [sp, #0xd8]
	str r4, [r3]
	ldr r1, _0812D818 @ =FUN_080f6e64
	ldr r5, [sp, #0x13c]
	str r1, [r5]
	ldr r1, _0812D81C @ =Enemy_OnDamaged
	ldr r6, [sp, #0xbc]
	str r1, [r6]
	ldr r1, _0812D820 @ =FUN_080f84d4
	ldr r2, [sp, #0x140]
	str r1, [r2]
	ldr r1, _0812D824 @ =FUN_080f624c
	ldr r3, [sp, #0xe0]
	str r1, [r3]
	ldr r1, _0812D828 @ =FUN_080f56ec
	ldr r5, [sp, #0xc4]
	str r1, [r5]
	ldr r1, _0812D82C @ =FUN_080f5b34
	ldr r6, [sp, #0xc8]
	str r1, [r6]
	ldr r1, _0812D830 @ =FUN_080f5fac
	ldr r2, [sp, #0xcc]
	str r1, [r2]
	ldr r3, [sp, #0xdc]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0x60]
	strb r1, [r4]
	ldr r1, [sp, #0x144]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _0812D834 @ =Mummy_TryDetectPlayer
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _0812D838 @ =Mummy_OnReset
	str r0, [r1]
	ldr r0, _0812D83C @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _0812D840 @ =FUN_0812a63c
	str r0, [r1]
	ldr r2, _0812D844 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _0812D848 @ =Mummy_OnAttackRequest
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0812D84C @ =FUN_08128824
	str r0, [r1]
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0812D850 @ =Mummy_StateBurning
	str r0, [r1]
	subs r5, #0x7c
	adds r1, r7, r5
	ldr r0, _0812D854 @ =Mummy_OnDamaged
	str r0, [r1]
	adds r6, #0x30
	adds r1, r7, r6
	ldr r0, _0812D858 @ =Mummy_HearSound
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x180]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r4, [sp, #0x154]
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x1a0]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812D866
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0812D7A0:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D85C
	bl VM_GetValue
	b _0812D85E
	.align 2, 0
_0812D7B0: .4byte 0x0000047A
_0812D7B4: .4byte 0x0000047E
_0812D7B8: .4byte 0x00000744
_0812D7BC: .4byte Mummy_UpdateFrame
_0812D7C0: .4byte Mummy_GetMoveSpeed
_0812D7C4: .4byte Mummy_StateTurn
_0812D7C8: .4byte Mummy_StateDamaged
_0812D7CC: .4byte FUN_080f62b0
_0812D7D0: .4byte FUN_080f62ac
_0812D7D4: .4byte Mummy_StateMove
_0812D7D8: .4byte Mummy_StateWait
_0812D7DC: .4byte Mummy_StateNap
_0812D7E0: .4byte Mummy_StateDying
_0812D7E4: .4byte FUN_080f44f4
_0812D7E8: .4byte FUN_080f410c
_0812D7EC: .4byte Mummy_StateHeardSound
_0812D7F0: .4byte Mummy_StateRespawnWait
_0812D7F4: .4byte FUN_080f0430
_0812D7F8: .4byte 0x085AD470
_0812D7FC: .4byte FUN_080e73c8
_0812D800: .4byte FUN_080f0320
_0812D804: .4byte Enemy_080eff14
_0812D808: .4byte FUN_080e72b0
_0812D80C: .4byte FUN_08122388
_0812D810: .4byte Enemy_StateBlownAway
_0812D814: .4byte Enemy_StateFallDeath
_0812D818: .4byte FUN_080f6e64
_0812D81C: .4byte Enemy_OnDamaged
_0812D820: .4byte FUN_080f84d4
_0812D824: .4byte FUN_080f624c
_0812D828: .4byte FUN_080f56ec
_0812D82C: .4byte FUN_080f5b34
_0812D830: .4byte FUN_080f5fac
_0812D834: .4byte Mummy_TryDetectPlayer
_0812D838: .4byte Mummy_OnReset
_0812D83C: .4byte 0x000005FC
_0812D840: .4byte FUN_0812a63c
_0812D844: .4byte 0x000005AC
_0812D848: .4byte Mummy_OnAttackRequest
_0812D84C: .4byte FUN_08128824
_0812D850: .4byte Mummy_StateBurning
_0812D854: .4byte Mummy_OnDamaged
_0812D858: .4byte Mummy_HearSound
_0812D85C:
	movs r0, #0
_0812D85E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0812D7A0
_0812D866:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x1a4]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x18c]
	strh r0, [r3]
	cmp r2, #0
	beq _0812D89E
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x180]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0812D89E
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0812D89E:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x164]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812D8B0
	movs r0, #1
	b _0812D8B2
_0812D8B0:
	movs r0, #0
_0812D8B2:
	cmp r0, #0
	beq _0812D8C4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x188]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_0812D8C4:
	cmp r2, #1
	beq _0812D904
	movs r1, #0
	ldr r0, [sp, #0x158]
	strb r1, [r0]
	ldr r2, [sp, #0x15c]
	strb r1, [r2]
	ldr r3, [sp, #0x160]
	strb r1, [r3]
	ldr r4, _0812D914 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _0812D918 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xd4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x64]
	strb r1, [r6]
	ldr r0, [sp, #0xac]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_0812D904:
	movs r1, #2
	ldr r3, [sp, #0x164]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0812D91C
	movs r0, #1
	b _0812D91E
	.align 2, 0
_0812D914: .4byte 0x00000484
_0812D918: .4byte 0x0000046C
_0812D91C:
	movs r0, #0
_0812D91E:
	cmp r0, #0
	beq _0812D938
	ldr r0, _0812D934 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x184]
	strh r0, [r5]
	b _0812D942
	.align 2, 0
_0812D934: .4byte 0x030046A0
_0812D938:
	ldr r0, [sp, #0x144]
	bl GetZoneAt
	ldr r6, [sp, #0x184]
	strh r0, [r6]
_0812D942:
	movs r1, #0x40
	ldr r2, [sp, #0x164]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812D952
	movs r0, #1
	b _0812D954
_0812D952:
	movs r0, #0
_0812D954:
	cmp r0, #0
	beq _0812D962
	ldr r0, _0812D988 @ =0xFFFFFEFF
	ldr r3, [sp, #0x154]
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
_0812D962:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0812D996
	ldr r0, _0812D98C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x184]
	ldrh r5, [r5]
	cmp r0, r5
	bne _0812D990
	movs r0, #1
	b _0812D992
	.align 2, 0
_0812D988: .4byte 0xFFFFFEFF
_0812D98C: .4byte 0x030046A0
_0812D990:
	movs r0, #0
_0812D992:
	cmp r0, #0
	bne _0812D99E
_0812D996:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0812D99E:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r6, [sp, #0xa8]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0812DA86
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
	beq _0812D9E0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0812D9E8
_0812D9E0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0812D9E8:
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
	beq _0812DA0C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0812DA14
_0812DA0C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0812DA14:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0812DA4C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0812DA90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0812DA50
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0812DA44
	ldrb r0, [r4, #5]
_0812DA44:
	subs r0, #1
	strh r0, [r4, #8]
	b _0812DA60
	.align 2, 0
_0812DA4C: .4byte 0x0000FFFF
_0812DA50:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0812DA60
	strh r1, [r4, #8]
_0812DA60:
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
	bne _0812DA90
	movs r0, #1
	strb r0, [r4, #7]
	b _0812DA90
_0812DA86:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_0812DA90:
	movs r0, #0
	ldr r6, [sp, #0x38]
	str r0, [r6]
	ldr r0, _0812DAA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812DAAC
	movs r0, #1
	b _0812DAAE
	.align 2, 0
_0812DAA8: .4byte 0x030047A4
_0812DAAC:
	movs r0, #0
_0812DAAE:
	cmp r0, #0
	bne _0812DAEE
	ldr r0, [sp, #0x44]
	ldrb r1, [r0]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812DAD6
	adds r0, r1, #0
	cmp r0, #7
	beq _0812DAD6
	cmp r0, #6
	beq _0812DAD6
	cmp r0, #0x15
	beq _0812DAD6
	cmp r0, #0x14
	beq _0812DAD6
	cmp r0, #0x17
	bne _0812DAEE
_0812DAD6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x164]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812DAEE:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Mummy_SetHandlerTable2
	adds r0, r7, #0
	bl Mummy_SetHandlerTable3
	adds r0, r7, #0
	bl Mummy_SetHandlerTable4
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x24]
	ldr r5, _0812DB34 @ =0x00000714
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, [sp, #0x34]
	ldr r4, [r6]
	movs r0, #0x42
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0812DB60
	bl VM_GetPC
	cmp r0, #0
	beq _0812DB38
	bl VM_GetValue
	adds r1, r0, #0
	b _0812DB3A
	.align 2, 0
_0812DB34: .4byte 0x00000714
_0812DB38:
	movs r1, #0x14
_0812DB3A:
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812DB52
	bl VM_GetValue
	adds r1, r0, #0
	b _0812DB54
_0812DB52:
	movs r1, #0xb4
_0812DB54:
	ldr r3, _0812DB5C @ =0x000006FA
	adds r0, r4, r3
	strh r1, [r0]
	b _0812DB72
	.align 2, 0
_0812DB5C: .4byte 0x000006FA
_0812DB60:
	movs r5, #0xdf
	lsls r5, r5, #3
	adds r1, r4, r5
	movs r0, #0x14
	strh r0, [r1]
	ldr r6, _0812DC10 @ =0x000006FA
	adds r1, r4, r6
	movs r0, #0xb4
	strh r0, [r1]
_0812DB72:
	ldr r0, [sp, #0x34]
	ldr r4, [r0]
	ldr r2, [sp, #0x54]
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, _0812DC14 @ =0x00000704
	adds r1, r4, r3
	str r0, [r1]
	movs r5, #0xe1
	lsls r5, r5, #3
	adds r4, r4, r5
	ldr r6, [sp, #0x54]
	ldr r0, [r6]
	str r0, [r4]
	ldr r1, [sp, #0x164]
	ldrh r0, [r1]
	ldr r2, [sp, #0xa4]
	strh r0, [r2]
	ldr r3, [sp, #0x30]
	ldrh r0, [r3]
	ldr r4, [sp, #0x9c]
	strh r0, [r4]
	ldr r5, [sp, #0x180]
	ldr r0, [r5]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	ldr r1, [sp, #0x188]
	ldr r0, [r1]
	ldr r2, [sp, #0x6c]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r4, [sp, #0x158]
	ldrb r0, [r4]
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x15c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x7c]
	strb r0, [r1]
	ldr r2, [sp, #0x160]
	ldrb r0, [r2]
	ldr r3, [sp, #0x84]
	strb r0, [r3]
	ldr r4, [sp, #0xac]
	ldr r0, [r4]
	ldr r5, [sp, #0x8c]
	str r0, [r5]
	ldr r6, [sp, #0x64]
	ldrb r0, [r6]
	ldr r1, [sp, #0x98]
	strb r0, [r1]
	ldr r2, _0812DC18 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0812DC1C @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0812DC20 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0812DC24 @ =Mummy_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0812DC28 @ =Mummy_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812DC2C
	movs r0, #0
	b _0812DC30
	.align 2, 0
_0812DC10: .4byte 0x000006FA
_0812DC14: .4byte 0x00000704
_0812DC18: .4byte 0x0000057C
_0812DC1C: .4byte Enemy_DispatchMsg
_0812DC20: .4byte 0x0000061C
_0812DC24: .4byte Mummy_Update
_0812DC28: .4byte Mummy_Destroy
_0812DC2C:
	movs r0, #1
	rsbs r0, r0, #0
_0812DC30:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
