	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a8
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	ldr r2, _08151A88 @ =0x000006D6
	adds r0, r7, r2
	strb r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r3, _08151A8C @ =0x000001DF
	adds r1, r7, r3
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	bl Dog_InitAnims
	ldr r4, _08151A90 @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08151A9C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08151A94 @ =0x0000D635
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08151A98 @ =0x0000F6E7
	bl EnemyAuxSprite_LoadAnim
	ldr r6, _08151A8C @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x98]
	cmp r1, #0x11
	beq _08151A78
	cmp r1, #0x17
	bne _08151A7C
_08151A78:
	movs r0, #1
	strb r0, [r5, #7]
_08151A7C:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08151B02
	.align 2, 0
_08151A88: .4byte 0x000006D6
_08151A8C: .4byte 0x000001DF
_08151A90: .4byte 0x0000025D
_08151A94: .4byte 0x0000D635
_08151A98: .4byte 0x0000F6E7
_08151A9C:
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
	ldr r2, _08151B80 @ =0x05000002
	bl CpuSet
	ldr r0, _08151B84 @ =0x0000CB05
	ldr r1, _08151B88 @ =0x0000D635
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
	ldr r0, _08151B8C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08151B90 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x98]
_08151B02:
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
	ldr r5, _08151B94 @ =0x0000046F
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
	ldr r1, _08151B98 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08151B80 @ =0x05000002
	bl CpuSet
	ldr r3, _08151B9C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a0]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x70]
	str r6, [sp, #0x48]
	ldr r2, [sp, #0x1a0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08151B6E
	b _08151CD0
_08151B6E:
	bl VM_GetPC
	cmp r0, #0
	beq _08151BA0
	bl VM_GetValue
	adds r1, r0, #0
	b _08151BA2
	.align 2, 0
_08151B80: .4byte 0x05000002
_08151B84: .4byte 0x0000CB05
_08151B88: .4byte 0x0000D635
_08151B8C: .4byte 0x000004B7
_08151B90: .4byte 0x000001DF
_08151B94: .4byte 0x0000046F
_08151B98: .4byte 0x00000474
_08151B9C: .4byte 0x000004B6
_08151BA0:
	movs r1, #0
_08151BA2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08151BC8 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _08151BCC
	bl VM_GetValue
	adds r1, r0, #0
	b _08151BCE
	.align 2, 0
_08151BC8: .4byte 0x00000251
_08151BCC:
	movs r1, #0
_08151BCE:
	ldr r2, _08151C04 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08151C08 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xfc]
	cmp r0, #0
	beq _08151C0C
	bl VM_GetValue
	b _08151C10
	.align 2, 0
_08151C04: .4byte 0x00000252
_08151C08: .4byte 0x000004B4
_08151C0C:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4]
_08151C10:
	strb r0, [r6]
	ldr r5, [sp, #0xf0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xfc]
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
	blt _08151C48
	cmp r1, #0
	blt _08151C48
	ldr r0, _08151C4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08151C48
	ldr r0, _08151C50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08151C54
_08151C48:
	movs r1, #0
	b _08151C62
	.align 2, 0
_08151C4C: .4byte 0x030046A8
_08151C50: .4byte 0x030046AC
_08151C54:
	ldr r0, _08151C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08151C62:
	ldr r2, _08151C80 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08151C84
	adds r0, #4
	b _08151C90
	.align 2, 0
_08151C7C: .4byte 0x030046A4
_08151C80: .4byte 0x00000256
_08151C84:
	ldr r0, _08151CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08151CA8
	cmp r2, #2
	beq _08151CAC
	b _08151CB0
	.align 2, 0
_08151CA4: .4byte 0x030046A4
_08151CA8:
	ldrb r0, [r4, #4]
	b _08151CAE
_08151CAC:
	ldrb r0, [r4]
_08151CAE:
	subs r1, r1, r0
_08151CB0:
	ldr r3, _08151CC8 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08151CCC @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08151D10
	.align 2, 0
_08151CC8: .4byte 0x00000472
_08151CCC: .4byte 0x0000FFFF
_08151CD0:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08151D34 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08151D38 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08151D3C @ =0x000004B4
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
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r3, [sp, #0xfc]
_08151D10:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08151D5A
	bl VM_GetPC
	cmp r0, #0
	beq _08151D40
	bl VM_GetValue
	adds r4, r0, #0
	b _08151D42
	.align 2, 0
_08151D34: .4byte 0x00000251
_08151D38: .4byte 0x00000252
_08151D3C: .4byte 0x000004B4
_08151D40:
	movs r4, #0x30
_08151D42:
	bl VM_GetPC
	cmp r0, #0
	beq _08151D54
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08151D56
_08151D54:
	movs r5, #0x40
_08151D56:
	mov r8, r4
	b _08151D60
_08151D5A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08151D60:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08151D98
	bl VM_GetPC
	cmp r0, #0
	beq _08151D7A
	bl VM_GetValue
	adds r6, r0, #0
	b _08151D7C
_08151D7A:
	movs r6, #0
_08151D7C:
	bl VM_GetPC
	cmp r0, #0
	beq _08151D8C
	bl VM_GetValue
	adds r1, r0, #0
	b _08151D8E
_08151D8C:
	movs r1, #0
_08151D8E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08151DA2
_08151D98:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08151DA2:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0815201C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x78]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x100]
	lsls r4, r4, #0x10
	str r4, [sp, #0x94]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa4]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _08152020 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x30]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xac]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x34]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x38]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x198]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r1, _08152024 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	ldr r2, _08152028 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x50]
	ldr r3, _0815202C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x54]
	ldr r4, _08152030 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xec]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _08152034 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x128]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08152038 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _0815203C @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x148]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08152040 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _08152044 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08152048 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	ldr r1, _0815204C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x180]
	ldr r3, _08152050 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	ldr r4, _08152054 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08152058 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0815205C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08152060 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08152064 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x138]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	ldr r3, _08152068 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0815206C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x190]
	ldr r1, _08152070 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x134]
	ldr r4, _08152074 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _08152078 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x120]
	ldr r1, _0815207C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x130]
	ldr r2, _08152080 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x80]
	ldr r5, _08152084 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	ldr r1, _08152088 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _0815208C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _08152090 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe4]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x88]
	ldr r2, _08152094 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _08152098 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xc0]
	ldr r1, _0815209C @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0xc4]
	ldr r2, _081520A0 @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _081520A4 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	ldr r4, _081520A8 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	ldr r6, _081520AC @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	cmp r0, #0
	bne _08151FEC
	b _08152106
_08151FEC:
	movs r0, #0
	mov sl, r0
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r4, r7, r6
_0815200C:
	bl VM_GetPC
	cmp r0, #0
	beq _081520B0
	bl VM_GetValue
	b _081520B2
	.align 2, 0
_0815201C: .4byte 0x0000025D
_08152020: .4byte 0x0000025A
_08152024: .4byte 0x0000047A
_08152028: .4byte 0x0000047C
_0815202C: .4byte 0x0000047E
_08152030: .4byte 0x000004A4
_08152034: .4byte 0x000005A4
_08152038: .4byte 0x000005C4
_0815203C: .4byte 0x000005CC
_08152040: .4byte 0x000005D4
_08152044: .4byte 0x000005DC
_08152048: .4byte 0x00000584
_0815204C: .4byte 0x00000604
_08152050: .4byte 0x0000021D
_08152054: .4byte 0x0000060C
_08152058: .4byte 0x000005E4
_0815205C: .4byte 0x000005FC
_08152060: .4byte 0x00000614
_08152064: .4byte 0x000005BC
_08152068: .4byte 0x000005EC
_0815206C: .4byte 0x00000624
_08152070: .4byte 0x0000058C
_08152074: .4byte 0x00000594
_08152078: .4byte 0x0000059C
_0815207C: .4byte 0x000005B4
_08152080: .4byte 0x00000543
_08152084: .4byte 0x00000496
_08152088: .4byte 0x00000469
_0815208C: .4byte 0x0000046A
_08152090: .4byte 0x00000553
_08152094: .4byte 0x00000572
_08152098: .4byte 0x0000055C
_0815209C: .4byte 0x00000564
_081520A0: .4byte 0x00000565
_081520A4: .4byte 0x00000566
_081520A8: .4byte 0x00000567
_081520AC: .4byte 0x0000056C
_081520B0:
	movs r0, #0x18
_081520B2:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081520C4
	bl VM_GetValue
	b _081520C6
_081520C4:
	movs r0, #0x18
_081520C6:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081520D8
	bl VM_GetValue
	b _081520DA
_081520D8:
	movs r0, #0
_081520DA:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081520EC
	bl VM_GetValue
	b _081520EE
_081520EC:
	movs r0, #0
_081520EE:
	strh r0, [r6]
	movs r0, #2
	add sb, r0
	movs r1, #4
	add r8, r1
	adds r5, #2
	adds r4, #2
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _0815200C
_08152106:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08152152
	bl VM_GetPC
	cmp r0, #0
	beq _08152120
	bl VM_GetValue
	adds r4, r0, #0
	b _08152124
_08152120:
	movs r4, #0x96
	lsls r4, r4, #1
_08152124:
	bl VM_GetPC
	cmp r0, #0
	beq _08152134
	bl VM_GetValue
	adds r6, r0, #0
	b _08152138
_08152134:
	movs r6, #0x96
	lsls r6, r6, #1
_08152138:
	bl VM_GetPC
	cmp r0, #0
	beq _08152146
	bl VM_GetValue
	b _0815214C
_08152146:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_0815214C:
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	b _0815215A
_08152152:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xe8]
	strh r6, [r2]
_0815215A:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08152172
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x70]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08152172:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08152240
	bl VM_GetPC
	cmp r0, #0
	beq _081521A2
	bl VM_GetValue
	b _081521A4
_081521A2:
	movs r0, #0
_081521A4:
	ldr r2, [sp, #0x100]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081521B2
	asrs r1, r0, #1
	b _081521B8
_081521B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081521B8:
	ldr r3, _081521CC @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081521D0
	bl VM_GetValue
	b _081521D2
	.align 2, 0
_081521CC: .4byte 0x00000546
_081521D0:
	movs r0, #0
_081521D2:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081521E8
	bl VM_GetValue
	b _081521EA
_081521E8:
	movs r0, #0
_081521EA:
	ldr r2, _08152200 @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152204
	bl VM_GetValue
	adds r1, r0, #0
	b _08152206
	.align 2, 0
_08152200: .4byte 0x00000187
_08152204:
	movs r1, #0
_08152206:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0815221C
	bl VM_GetValue
	b _0815221E
_0815221C:
	movs r0, #0
_0815221E:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152236
	bl VM_GetValue
	adds r1, r0, #0
	b _08152238
_08152236:
	movs r1, #0
_08152238:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08152240:
	ldr r3, [sp, #0x100]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r4, [sp, #0x94]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0xa0]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0xa4]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x9c]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081522A2
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl VM_GetPC
	cmp r0, #0
	beq _08152288
	bl VM_GetValue
	b _0815228A
_08152288:
	movs r0, #0
_0815228A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0815229A
	bl VM_GetValue
	b _0815229C
_0815229A:
	movs r0, #0
_0815229C:
	ldr r3, _08152304 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081522A2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0x10c]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081522C6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081522C6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081522DE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081522DE:
	ldr r0, [sp, #0x90]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08152308
	movs r0, #1
	b _0815230A
	.align 2, 0
_08152304: .4byte 0x00000189
_08152308:
	movs r0, #0
_0815230A:
	cmp r0, #0
	beq _0815231A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08152344 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_0815231A:
	ldr r3, [sp, #0x110]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08152326
	ldr r1, [r7, #0x44]
_08152326:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x98]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08152348
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08152354
	.align 2, 0
_08152344: .4byte Enemy_OnCWolfMessage
_08152348:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08152354:
	ldr r5, [sp, #0x98]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081523A2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081523A2
	cmp r0, #0x16
	beq _081523A2
	cmp r0, #0x14
	beq _081523A2
	cmp r0, #9
	beq _081523A2
	cmp r0, #0x19
	beq _081523A2
	cmp r0, #0x1a
	beq _081523A2
	cmp r0, #0xd
	beq _081523A2
	cmp r0, #0x1b
	beq _081523A2
	cmp r0, #0x1f
	beq _081523A2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xfc]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_081523A2:
	movs r1, #8
	ldr r5, [sp, #0x48]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081523B2
	movs r0, #1
	b _081523B4
_081523B2:
	movs r0, #0
_081523B4:
	cmp r0, #0
	beq _081523C2
	ldr r6, [sp, #0xac]
	ldr r0, [r6]
	ldr r1, [sp, #0xa8]
	str r0, [r1]
	b _081523D4
_081523C2:
	ldr r2, [sp, #0xac]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa8]
	str r0, [r3]
_081523D4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	ldr r5, [sp, #0x198]
	ldr r6, [sp, #0x38]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081523FE
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
_081523FE:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08152446
	bl VM_GetPC
	cmp r0, #0
	beq _08152418
	bl VM_GetValue
	adds r1, r0, #0
	b _0815241A
_08152418:
	movs r1, #0xc8
_0815241A:
	ldr r2, [sp, #0x24]
	ldr r3, _08152434 @ =0x000006CC
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08152438
	bl VM_GetValue
	adds r1, r0, #0
	b _0815243E
	.align 2, 0
_08152434: .4byte 0x000006CC
_08152438:
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r4, #0
_0815243E:
	ldr r5, [sp, #0x24]
	ldr r6, _08152464 @ =0x000006CE
	adds r0, r5, r6
	strh r1, [r0]
_08152446:
	movs r0, #0x59
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081524C6
	ldr r0, [sp, #0x24]
	ldr r1, _08152468 @ =0x000006B4
	adds r4, r0, r1
	bl VM_GetPC
	cmp r0, #0
	beq _0815246C
	bl VM_GetValue
	b _0815246E
	.align 2, 0
_08152464: .4byte 0x000006CE
_08152468: .4byte 0x000006B4
_0815246C:
	movs r0, #0
_0815246E:
	str r0, [r4]
	ldr r2, [sp, #0x24]
	ldr r3, _08152490 @ =0x000006B4
	adds r1, r2, r3
	ldr r0, [r1]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	str r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152494
	bl VM_GetValue
	adds r1, r0, #0
	b _0815249A
	.align 2, 0
_08152490: .4byte 0x000006B4
_08152494:
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r1, r5, #0
_0815249A:
	ldr r6, [sp, #0x24]
	ldr r2, _081524B4 @ =0x000006C2
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081524B8
	bl VM_GetValue
	adds r1, r0, #0
	b _081524BE
	.align 2, 0
_081524B4: .4byte 0x000006C2
_081524B8:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r3, #0
_081524BE:
	ldr r4, [sp, #0x24]
	ldr r5, _08152530 @ =0x000006C4
	adds r0, r4, r5
	strh r1, [r0]
_081524C6:
	movs r0, #0x64
	movs r1, #0x32
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x24]
	ldr r2, _08152534 @ =0x000006D9
	adds r1, r6, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081524E0
	movs r0, #0x32
	strb r0, [r1]
_081524E0:
	ldr r3, [sp, #0x24]
	movs r4, #0xda
	lsls r4, r4, #3
	adds r1, r3, r4
	ldr r0, _08152538 @ =0x0000FFFF
	strh r0, [r1]
	ldr r5, _0815253C @ =0x000006D4
	adds r1, r3, r5
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08152540 @ =0x000001F5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	ldr r0, [sp, #0x4c]
	strh r4, [r0]
	ldr r1, [sp, #0x50]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	ldr r3, [sp, #0x4c]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x110]
	ldrb r0, [r4]
	cmp r0, #0
	bne _08152544
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08152550
	.align 2, 0
_08152530: .4byte 0x000006C4
_08152534: .4byte 0x000006D9
_08152538: .4byte 0x0000FFFF
_0815253C: .4byte 0x000006D4
_08152540: .4byte 0x000001F5
_08152544:
	ldr r2, [r7, #0x44]
	ldr r0, _08152588 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08152550:
	ldr r5, [sp, #0x110]
	ldrb r0, [r5]
	cmp r0, #1
	bne _081525A0
	ldr r6, [sp, #0x98]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0815258C
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
	b _08152596
	.align 2, 0
_08152588: .4byte 0x03003584
_0815258C:
	ldr r1, [sp, #0x98]
	ldrb r0, [r1]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08152596:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081525A0:
	adds r0, r7, #0
	bl Dog_InitHitboxes
	ldr r2, [sp, #0x24]
	ldr r3, _0815275C @ =0x000006DC
	adds r0, r2, r3
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r4, r2, r4
	str r4, [sp, #0x1a4]
	ldr r5, _08152760 @ =FUN_081518c0
	mov r8, r5
	ldr r6, _08152764 @ =FUN_0814a8dc
	mov sb, r6
	ldr r1, _08152768 @ =Dog_StateTurn
	mov sl, r1
	ldr r2, _0815276C @ =FUN_0814c28c
	mov ip, r2
	ldr r4, _08152770 @ =Dog_StateDamaged
	ldr r5, _08152774 @ =Dog_StateDying
	ldr r3, _08152778 @ =FUN_080f62b0
	ldr r6, _0815277C @ =FUN_080f62ac
	str r6, [sp, #0x19c]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x6c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x64]
	str r0, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	mov r1, r8
	ldr r2, [sp, #0xec]
	str r1, [r2]
	mov r6, sb
	ldr r1, [sp, #0x104]
	str r6, [r1]
	mov r2, sl
	ldr r6, [sp, #0x114]
	str r2, [r6]
	mov r1, ip
	ldr r2, [sp, #0x124]
	str r1, [r2]
	ldr r6, _08152780 @ =FUN_0814c2b0
	ldr r1, [sp, #0x128]
	str r6, [r1]
	ldr r2, _08152784 @ =FUN_0814c974
	ldr r6, [sp, #0x13c]
	str r2, [r6]
	ldr r1, [sp, #0x140]
	str r3, [r1]
	ldr r2, [sp, #0x148]
	str r4, [r2]
	ldr r3, [sp, #0x14c]
	str r5, [r3]
	ldr r1, _08152788 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r1, [r4]
	ldr r1, _0815278C @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r1, [r5]
	ldr r6, _08152790 @ =FUN_0814cb8c
	ldr r1, [sp, #0x144]
	str r6, [r1]
	ldr r2, _08152794 @ =FUN_0814c970
	ldr r3, [sp, #0xf8]
	str r2, [r3]
	ldr r4, [sp, #0x19c]
	ldr r5, [sp, #0x17c]
	str r4, [r5]
	ldr r1, _08152798 @ =FUN_080f0430
	ldr r6, [sp, #0x180]
	str r1, [r6]
	movs r4, #0
	movs r2, #1
	ldr r1, [sp, #0xb4]
	strb r2, [r1]
	ldr r1, _0815279C @ =0x085AD470
	ldr r3, [sp, #0x184]
	str r1, [r3]
	ldr r1, _081527A0 @ =FUN_080e73c8
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r6, [sp, #0x160]
	str r4, [r6]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r2, [sp, #0x174]
	str r4, [r2]
	ldr r3, [sp, #0x178]
	str r4, [r3]
	ldr r5, [sp, #0x188]
	str r4, [r5]
	ldr r1, _081527A4 @ =FUN_080f0320
	ldr r6, [sp, #0x18c]
	str r1, [r6]
	ldr r1, _081527A8 @ =Enemy_080eff14
	ldr r2, [sp, #0x138]
	str r1, [r2]
	ldr r1, _081527AC @ =FUN_080e72b0
	ldr r3, [sp, #0x164]
	str r1, [r3]
	ldr r5, _081527B0 @ =FUN_0814e420
	ldr r6, [sp, #0x15c]
	str r5, [r6]
	ldr r1, _081527B4 @ =Enemy_StateBlownAway
	ldr r2, [sp, #0x168]
	str r1, [r2]
	ldr r1, _081527B8 @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x154]
	str r1, [r3]
	ldr r5, [sp, #0x12c]
	str r4, [r5]
	ldr r1, _081527BC @ =FUN_080f6e64
	ldr r6, [sp, #0x190]
	str r1, [r6]
	ldr r1, _081527C0 @ =Enemy_OnDamaged
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r1, _081527C4 @ =FUN_080f84d4
	ldr r3, [sp, #0x194]
	str r1, [r3]
	ldr r1, _081527C8 @ =FUN_080f624c
	ldr r5, [sp, #0x134]
	str r1, [r5]
	ldr r1, _081527CC @ =FUN_080f56ec
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081527D0 @ =FUN_080f5b34
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r1, _081527D4 @ =FUN_080f5fac
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r5, [sp, #0x130]
	str r4, [r5]
	movs r1, #0x28
	ldr r6, [sp, #0xb0]
	strb r1, [r6]
	ldr r1, [sp, #0x198]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081527D8 @ =Dog_OnReset
	str r0, [r1]
	ldr r2, _081527DC @ =0x000005FC
	adds r1, r7, r2
	ldr r0, _081527E0 @ =FUN_0814a8c8
	str r0, [r1]
	ldr r3, _081527E4 @ =0x000005AC
	adds r1, r7, r3
	ldr r0, _081527E8 @ =enemy_dog_08149f6c
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081527EC @ =FUN_0814a098
	str r0, [r1]
	ldr r6, _081527F0 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081527F4 @ =FUN_0814eacc
	str r0, [r1]
	ldr r0, _081527F8 @ =0x000005BC
	adds r1, r7, r0
	ldr r0, _081527FC @ =FUN_0814e248
	str r0, [r1]
	adds r2, #0x1c
	adds r1, r7, r2
	ldr r0, _08152800 @ =FUN_0814b3e0
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	ldr r4, _08152804 @ =0x00000543
	adds r1, r7, r4
	movs r0, #0x14
	strb r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x7c]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08152812
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_0815274E:
	bl VM_GetPC
	cmp r0, #0
	beq _08152808
	bl VM_GetValue
	b _0815280A
	.align 2, 0
_0815275C: .4byte 0x000006DC
_08152760: .4byte FUN_081518c0
_08152764: .4byte FUN_0814a8dc
_08152768: .4byte Dog_StateTurn
_0815276C: .4byte FUN_0814c28c
_08152770: .4byte Dog_StateDamaged
_08152774: .4byte Dog_StateDying
_08152778: .4byte FUN_080f62b0
_0815277C: .4byte FUN_080f62ac
_08152780: .4byte FUN_0814c2b0
_08152784: .4byte FUN_0814c974
_08152788: .4byte FUN_080f44f4
_0815278C: .4byte FUN_080f410c
_08152790: .4byte FUN_0814cb8c
_08152794: .4byte FUN_0814c970
_08152798: .4byte FUN_080f0430
_0815279C: .4byte 0x085AD470
_081527A0: .4byte FUN_080e73c8
_081527A4: .4byte FUN_080f0320
_081527A8: .4byte Enemy_080eff14
_081527AC: .4byte FUN_080e72b0
_081527B0: .4byte FUN_0814e420
_081527B4: .4byte Enemy_StateBlownAway
_081527B8: .4byte Enemy_StateFallDeath
_081527BC: .4byte FUN_080f6e64
_081527C0: .4byte Enemy_OnDamaged
_081527C4: .4byte FUN_080f84d4
_081527C8: .4byte FUN_080f624c
_081527CC: .4byte FUN_080f56ec
_081527D0: .4byte FUN_080f5b34
_081527D4: .4byte FUN_080f5fac
_081527D8: .4byte Dog_OnReset
_081527DC: .4byte 0x000005FC
_081527E0: .4byte FUN_0814a8c8
_081527E4: .4byte 0x000005AC
_081527E8: .4byte enemy_dog_08149f6c
_081527EC: .4byte FUN_0814a098
_081527F0: .4byte 0x0000058C
_081527F4: .4byte FUN_0814eacc
_081527F8: .4byte 0x000005BC
_081527FC: .4byte FUN_0814e248
_08152800: .4byte FUN_0814b3e0
_08152804: .4byte 0x00000543
_08152808:
	movs r0, #0
_0815280A:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0815274E
_08152812:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x80]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	cmp r2, #0
	beq _0815284A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x6c]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _0815284A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_0815284A:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x48]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815285C
	movs r0, #1
	b _0815285E
_0815285C:
	movs r0, #0
_0815285E:
	cmp r0, #0
	beq _08152870
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x70]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_08152870:
	cmp r2, #1
	beq _081528B0
	movs r1, #0
	ldr r3, [sp, #0x3c]
	strb r1, [r3]
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, _081528C0 @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _081528C4 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x128]
	ldr r3, [r4]
	ldr r5, _081528C8 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xb8]
	strb r1, [r0]
	ldr r2, [sp, #0xe4]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081528B0:
	movs r1, #2
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081528CC
	movs r0, #1
	b _081528CE
	.align 2, 0
_081528C0: .4byte 0x00000484
_081528C4: .4byte 0x0000046C
_081528C8: .4byte 0x0000046D
_081528CC:
	movs r0, #0
_081528CE:
	cmp r0, #0
	beq _081528E8
	ldr r0, _081528E4 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x5c]
	strh r0, [r6]
	b _081528F2
	.align 2, 0
_081528E4: .4byte 0x030046A0
_081528E8:
	ldr r0, [sp, #0x198]
	bl GetZoneAt
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
_081528F2:
	movs r1, #0x40
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08152902
	movs r0, #1
	b _08152904
_08152902:
	movs r0, #0
_08152904:
	cmp r0, #0
	beq _08152914
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08152938 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08152914:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08152946
	ldr r0, _0815293C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x5c]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08152940
	movs r0, #1
	b _08152942
	.align 2, 0
_08152938: .4byte 0xFFFFFEFF
_0815293C: .4byte 0x030046A0
_08152940:
	movs r0, #0
_08152942:
	cmp r0, #0
	bne _0815294E
_08152946:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0815294E:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x110]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08152A36
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
	beq _08152990
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08152998
_08152990:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08152998:
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
	beq _081529BC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081529C4
_081529BC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081529C4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081529FC @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08152A40
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08152A00
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081529F4
	ldrb r0, [r4, #5]
_081529F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08152A10
	.align 2, 0
_081529FC: .4byte 0x0000FFFF
_08152A00:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08152A10
	strh r1, [r4, #8]
_08152A10:
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
	bne _08152A40
	movs r0, #1
	strb r0, [r4, #7]
	b _08152A40
_08152A36:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08152A40:
	movs r0, #0
	ldr r3, [sp, #0x8c]
	str r0, [r3]
	ldr r0, _08152A58 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08152A5C
	movs r0, #1
	b _08152A5E
	.align 2, 0
_08152A58: .4byte 0x030047A4
_08152A5C:
	movs r0, #0
_08152A5E:
	cmp r0, #0
	bne _08152A9E
	ldr r4, [sp, #0x98]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08152A86
	adds r0, r1, #0
	cmp r0, #7
	beq _08152A86
	cmp r0, #6
	beq _08152A86
	cmp r0, #0x15
	beq _08152A86
	cmp r0, #0x14
	beq _08152A86
	cmp r0, #0x17
	bne _08152A9E
_08152A86:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x48]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08152A9E:
	ldr r6, [sp, #0x88]
	ldr r3, [r6]
	ldr r1, [sp, #0x58]
	ldrh r0, [r1]
	cmp r0, #1
	bls _08152AAE
	cmp r0, #4
	bne _08152AC0
_08152AAE:
	ldr r4, _08152ABC @ =0x000006AC
	adds r2, r3, r4
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	b _08152AD6
	.align 2, 0
_08152ABC: .4byte 0x000006AC
_08152AC0:
	ldr r0, _08152B78 @ =0x000006AC
	adds r2, r3, r0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r1, r3, r4
	movs r0, #0xe1
	lsls r0, r0, #0xa
	str r0, [r1]
_08152AD6:
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, _08152B7C @ =0x0000FFFF
	str r0, [r1]
	ldr r6, _08152B80 @ =0x000006BC
	adds r1, r3, r6
	ldr r0, [r2]
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_081518ac
	adds r0, r7, #0
	bl FUN_081504e8
	adds r0, r7, #0
	bl FUN_0815077c
	ldr r1, [sp, #0x48]
	ldrh r0, [r1]
	ldr r2, [sp, #0xe0]
	strh r0, [r2]
	ldr r3, [sp, #0x84]
	ldrh r0, [r3]
	ldr r4, [sp, #0xdc]
	strh r0, [r4]
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	ldr r6, [sp, #0xbc]
	str r0, [r6]
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	ldr r2, [sp, #0xc0]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc4]
	strb r0, [r3]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc8]
	strb r0, [r5]
	ldr r6, [sp, #0x40]
	ldrb r0, [r6]
	ldr r1, [sp, #0xcc]
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldrb r0, [r2]
	ldr r3, [sp, #0xd0]
	strb r0, [r3]
	ldr r4, [sp, #0xe4]
	ldr r0, [r4]
	ldr r5, [sp, #0xd4]
	str r0, [r5]
	ldr r6, [sp, #0xb8]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd8]
	strb r0, [r1]
	ldr r2, _08152B84 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08152B88 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _08152B8C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08152B90 @ =Dog_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08152B94 @ =Dog_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08152B98
	movs r0, #0
	b _08152B9C
	.align 2, 0
_08152B78: .4byte 0x000006AC
_08152B7C: .4byte 0x0000FFFF
_08152B80: .4byte 0x000006BC
_08152B84: .4byte 0x0000057C
_08152B88: .4byte Enemy_DispatchMsg
_08152B8C: .4byte 0x0000061C
_08152B90: .4byte Dog_Update
_08152B94: .4byte Dog_Destroy
_08152B98:
	movs r0, #1
	rsbs r0, r0, #0
_08152B9C:
	add sp, #0x1a8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
