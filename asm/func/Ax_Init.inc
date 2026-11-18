	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081A1A40 @ =0x00000E48
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _081A1A44 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0xd
	strb r0, [r1]
	adds r0, r7, #0
	bl Ax_InitAnims
	ldr r3, _081A1A48 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A1A54
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081A1A4C @ =0x00005291
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081A1A50 @ =0x00003F72
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _081A1A44 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x70]
	cmp r1, #0x11
	beq _081A1A30
	cmp r1, #0x17
	bne _081A1A34
_081A1A30:
	movs r0, #1
	strb r0, [r5, #7]
_081A1A34:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081A1ABC
	.align 2, 0
_081A1A40: .4byte 0x00000E48
_081A1A44: .4byte 0x000001DF
_081A1A48: .4byte 0x0000025D
_081A1A4C: .4byte 0x00005291
_081A1A50: .4byte 0x00003F72
_081A1A54:
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
	ldr r2, _081A1B38 @ =0x05000002
	bl CpuSet
	ldr r0, _081A1B3C @ =0x0000CB05
	ldr r1, _081A1B40 @ =0x00005291
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
	ldr r0, _081A1B44 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081A1B48 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x70]
_081A1ABC:
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
	ldr r5, _081A1B4C @ =0x0000046F
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
	ldr r1, _081A1B50 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081A1B38 @ =0x05000002
	bl CpuSet
	ldr r3, _081A1B54 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a4]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x40]
	mov r3, r8
	str r3, [sp, #0x44]
	str r6, [sp, #0x184]
	ldr r2, [sp, #0x1a4]
	adds r6, r2, #0
	cmp r0, #0
	bne _081A1B28
	b _081A1C88
_081A1B28:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1B58
	bl VM_GetValue
	adds r1, r0, #0
	b _081A1B5A
	.align 2, 0
_081A1B38: .4byte 0x05000002
_081A1B3C: .4byte 0x0000CB05
_081A1B40: .4byte 0x00005291
_081A1B44: .4byte 0x000004B7
_081A1B48: .4byte 0x000001DF
_081A1B4C: .4byte 0x0000046F
_081A1B50: .4byte 0x00000474
_081A1B54: .4byte 0x000004B6
_081A1B58:
	movs r1, #0
_081A1B5A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081A1B80 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xcc]
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _081A1B84
	bl VM_GetValue
	adds r1, r0, #0
	b _081A1B86
	.align 2, 0
_081A1B80: .4byte 0x00000251
_081A1B84:
	movs r1, #0
_081A1B86:
	ldr r2, _081A1BBC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081A1BC0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xcc]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd8]
	cmp r0, #0
	beq _081A1BC4
	bl VM_GetValue
	b _081A1BC8
	.align 2, 0
_081A1BBC: .4byte 0x00000252
_081A1BC0: .4byte 0x000004B4
_081A1BC4:
	ldr r4, [sp, #0xcc]
	ldrb r0, [r4]
_081A1BC8:
	strb r0, [r6]
	ldr r5, [sp, #0xcc]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd8]
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
	blt _081A1C00
	cmp r1, #0
	blt _081A1C00
	ldr r0, _081A1C04 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A1C00
	ldr r0, _081A1C08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A1C0C
_081A1C00:
	movs r1, #0
	b _081A1C1A
	.align 2, 0
_081A1C04: .4byte 0x030046A8
_081A1C08: .4byte 0x030046AC
_081A1C0C:
	ldr r0, _081A1C34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081A1C1A:
	ldr r2, _081A1C38 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A1C3C
	adds r0, #4
	b _081A1C48
	.align 2, 0
_081A1C34: .4byte 0x030046A4
_081A1C38: .4byte 0x00000256
_081A1C3C:
	ldr r0, _081A1C5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A1C48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A1C60
	cmp r2, #2
	beq _081A1C64
	b _081A1C68
	.align 2, 0
_081A1C5C: .4byte 0x030046A4
_081A1C60:
	ldrb r0, [r4, #4]
	b _081A1C66
_081A1C64:
	ldrb r0, [r4]
_081A1C66:
	subs r1, r1, r0
_081A1C68:
	ldr r3, _081A1C80 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081A1C84 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081A1CC8
	.align 2, 0
_081A1C80: .4byte 0x00000472
_081A1C84: .4byte 0x0000FFFF
_081A1C88:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081A1CEC @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081A1CF0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081A1CF4 @ =0x000004B4
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
	str r5, [sp, #0xcc]
	str r4, [sp, #0xd0]
	str r3, [sp, #0xd8]
_081A1CC8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A1D12
	bl VM_GetPC
	cmp r0, #0
	beq _081A1CF8
	bl VM_GetValue
	adds r4, r0, #0
	b _081A1CFA
	.align 2, 0
_081A1CEC: .4byte 0x00000251
_081A1CF0: .4byte 0x00000252
_081A1CF4: .4byte 0x000004B4
_081A1CF8:
	movs r4, #0x30
_081A1CFA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D0C
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081A1D0E
_081A1D0C:
	movs r5, #0x40
_081A1D0E:
	mov r8, r4
	b _081A1D18
_081A1D12:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081A1D18:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A1D50
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D32
	bl VM_GetValue
	adds r6, r0, #0
	b _081A1D34
_081A1D32:
	movs r6, #0
_081A1D34:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D44
	bl VM_GetValue
	adds r1, r0, #0
	b _081A1D46
_081A1D44:
	movs r1, #0
_081A1D46:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081A1D5A
_081A1D50:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081A1D5A:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _081A1FD8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x48]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x64]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x6c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x74]
	lsls r5, r5, #0x10
	str r5, [sp, #0x68]
	ldr r4, _081A1FDC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x5c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x16c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x170]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x174]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x168]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x19c]
	ldr r1, _081A1FE0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x190]
	ldr r2, _081A1FE4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x194]
	ldr r3, _081A1FE8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x198]
	ldr r4, _081A1FEC @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _081A1FF0 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x38]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf4]
	ldr r6, _081A1FF4 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	ldr r2, _081A1FF8 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x110]
	ldr r3, _081A1FFC @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	ldr r5, _081A2000 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081A2004 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x114]
	ldr r2, _081A2008 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	ldr r3, _081A200C @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x14c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x150]
	ldr r5, _081A2010 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x88]
	ldr r6, _081A2014 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _081A2018 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _081A201C @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	ldr r6, _081A2020 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x15c]
	ldr r2, _081A2024 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x134]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	ldr r5, _081A2028 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x138]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r2, _081A202C @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x160]
	ldr r3, _081A2030 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x164]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x104]
	ldr r6, _081A2034 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	ldr r2, _081A2038 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _081A203C @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x100]
	ldr r4, _081A2040 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081A2044 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _081A2048 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _081A204C @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _081A2050 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x30]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r3, _081A2054 @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0xb0]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xac]
	ldr r6, _081A2058 @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x90]
	ldr r2, _081A205C @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0x94]
	ldr r3, _081A2060 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0x98]
	ldr r4, _081A2064 @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	ldr r5, _081A2068 @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _081A206C @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	cmp r0, #0
	bne _081A1FAA
	b _081A20C8
_081A1FAA:
	movs r2, #0
	mov sl, r2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_081A1FCA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A2070
	bl VM_GetValue
	b _081A2072
	.align 2, 0
_081A1FD8: .4byte 0x0000025D
_081A1FDC: .4byte 0x0000025A
_081A1FE0: .4byte 0x0000047A
_081A1FE4: .4byte 0x0000047C
_081A1FE8: .4byte 0x0000047E
_081A1FEC: .4byte 0x00000476
_081A1FF0: .4byte 0x000004A4
_081A1FF4: .4byte 0x000005A4
_081A1FF8: .4byte 0x000005C4
_081A1FFC: .4byte 0x000005CC
_081A2000: .4byte 0x000005D4
_081A2004: .4byte 0x000005DC
_081A2008: .4byte 0x00000584
_081A200C: .4byte 0x00000604
_081A2010: .4byte 0x0000021D
_081A2014: .4byte 0x0000060C
_081A2018: .4byte 0x000005E4
_081A201C: .4byte 0x000005FC
_081A2020: .4byte 0x00000614
_081A2024: .4byte 0x000005BC
_081A2028: .4byte 0x000005EC
_081A202C: .4byte 0x00000624
_081A2030: .4byte 0x0000058C
_081A2034: .4byte 0x00000594
_081A2038: .4byte 0x0000059C
_081A203C: .4byte 0x000005B4
_081A2040: .4byte 0x00000543
_081A2044: .4byte 0x00000496
_081A2048: .4byte 0x00000469
_081A204C: .4byte 0x0000046A
_081A2050: .4byte 0x00000553
_081A2054: .4byte 0x00000572
_081A2058: .4byte 0x0000055C
_081A205C: .4byte 0x00000564
_081A2060: .4byte 0x00000565
_081A2064: .4byte 0x00000566
_081A2068: .4byte 0x00000567
_081A206C: .4byte 0x0000056C
_081A2070:
	movs r0, #0x18
_081A2072:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081A2084
	bl VM_GetValue
	b _081A2086
_081A2084:
	movs r0, #0x18
_081A2086:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081A2098
	bl VM_GetValue
	b _081A209A
_081A2098:
	movs r0, #0
_081A209A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081A20AC
	bl VM_GetValue
	b _081A20AE
_081A20AC:
	movs r0, #0
_081A20AE:
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
	bgt _081A20C8
	b _081A1FCA
_081A20C8:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A2114
	bl VM_GetPC
	cmp r0, #0
	beq _081A20E2
	bl VM_GetValue
	adds r4, r0, #0
	b _081A20E6
_081A20E2:
	movs r4, #0x96
	lsls r4, r4, #1
_081A20E6:
	bl VM_GetPC
	cmp r0, #0
	beq _081A20F6
	bl VM_GetValue
	adds r6, r0, #0
	b _081A20FA
_081A20F6:
	movs r6, #0x96
	lsls r6, r6, #1
_081A20FA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A2108
	bl VM_GetValue
	b _081A210E
_081A2108:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081A210E:
	ldr r2, [sp, #0xc4]
	strh r0, [r2]
	b _081A211C
_081A2114:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc4]
	strh r6, [r3]
_081A211C:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081A2134
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x44]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081A2134:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x48]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A2204
	bl VM_GetPC
	cmp r0, #0
	beq _081A2164
	bl VM_GetValue
	b _081A2166
_081A2164:
	movs r0, #0
_081A2166:
	ldr r3, [sp, #0xdc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081A2174
	asrs r1, r0, #1
	b _081A217A
_081A2174:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081A217A:
	ldr r5, _081A2190 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A2194
	bl VM_GetValue
	b _081A2196
	.align 2, 0
_081A2190: .4byte 0x00000546
_081A2194:
	movs r0, #0
_081A2196:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21AC
	bl VM_GetValue
	b _081A21AE
_081A21AC:
	movs r0, #0
_081A21AE:
	ldr r3, _081A21C4 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21C8
	bl VM_GetValue
	adds r1, r0, #0
	b _081A21CA
	.align 2, 0
_081A21C4: .4byte 0x00000187
_081A21C8:
	movs r1, #0
_081A21CA:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21E0
	bl VM_GetValue
	b _081A21E2
_081A21E0:
	movs r0, #0
_081A21E2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21FA
	bl VM_GetValue
	adds r1, r0, #0
	b _081A21FC
_081A21FA:
	movs r1, #0
_081A21FC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081A2204:
	ldr r5, [sp, #0xdc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0x64]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x6c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x74]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x68]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A2266
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081A224C
	bl VM_GetValue
	b _081A224E
_081A224C:
	movs r0, #0
_081A224E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081A225E
	bl VM_GetValue
	b _081A2260
_081A225E:
	movs r0, #0
_081A2260:
	ldr r6, _081A22C8 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081A2266:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081A228A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x44]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081A228A:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081A22A2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x44]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081A22A2:
	ldr r4, [sp, #0x5c]
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
	ldr r5, [sp, #0x184]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A22CC
	movs r0, #1
	b _081A22CE
	.align 2, 0
_081A22C8: .4byte 0x00000189
_081A22CC:
	movs r0, #0
_081A22CE:
	cmp r0, #0
	beq _081A22DE
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081A2308 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_081A22DE:
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081A22EA
	ldr r1, [r7, #0x44]
_081A22EA:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0x70]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081A230C
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x16c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081A2318
	.align 2, 0
_081A2308: .4byte Enemy_OnCWolfMessage
_081A230C:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x16c]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081A2318:
	ldr r2, [sp, #0x70]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A2366
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081A2366
	cmp r0, #0x16
	beq _081A2366
	cmp r0, #0x14
	beq _081A2366
	cmp r0, #9
	beq _081A2366
	cmp r0, #0x19
	beq _081A2366
	cmp r0, #0x1a
	beq _081A2366
	cmp r0, #0xd
	beq _081A2366
	cmp r0, #0x1b
	beq _081A2366
	cmp r0, #0x1f
	beq _081A2366
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xcc]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_081A2366:
	movs r1, #8
	ldr r6, [sp, #0x184]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081A2376
	movs r0, #1
	b _081A2378
_081A2376:
	movs r0, #0
_081A2378:
	cmp r0, #0
	beq _081A2386
	ldr r1, [sp, #0x7c]
	ldr r0, [r1]
	ldr r2, [sp, #0x78]
	str r0, [r2]
	b _081A2398
_081A2386:
	ldr r3, [sp, #0x7c]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x78]
	str r0, [r4]
_081A2398:
	ldrh r0, [r7]
	ldr r5, [sp, #0x170]
	strh r0, [r5]
	ldr r6, [sp, #0x168]
	ldr r0, [sp, #0x174]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _081A23C2
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
_081A23C2:
	adds r0, r7, #0
	bl FUN_0819e56c
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A24B0
	bl VM_GetPC
	cmp r0, #0
	beq _081A23E0
	bl VM_GetValue
	b _081A23E2
_081A23E0:
	movs r0, #0
_081A23E2:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081A23F2
	bl VM_GetValue
	b _081A23F4
_081A23F2:
	movs r0, #0
_081A23F4:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081A2404
	bl VM_GetValue
	b _081A2406
_081A2404:
	movs r0, #0
_081A2406:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x168]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081A242E
	cmp r1, #0
	blt _081A242E
	ldr r0, _081A2434 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A242E
	ldr r0, _081A2438 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A243C
_081A242E:
	movs r1, #0
	b _081A244A
	.align 2, 0
_081A2434: .4byte 0x030046A8
_081A2438: .4byte 0x030046AC
_081A243C:
	ldr r0, _081A2464 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081A244A:
	ldr r4, _081A2468 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x168]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A246C
	adds r0, #4
	b _081A2478
	.align 2, 0
_081A2464: .4byte 0x030046A4
_081A2468: .4byte 0x00000256
_081A246C:
	ldr r0, _081A248C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A2478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A2490
	cmp r2, #2
	beq _081A2494
	b _081A2498
	.align 2, 0
_081A248C: .4byte 0x030046A4
_081A2490:
	ldrb r0, [r5, #4]
	b _081A2496
_081A2494:
	ldrb r0, [r5]
_081A2496:
	subs r1, r1, r0
_081A2498:
	ldr r5, _081A24A8 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	ldr r2, _081A24AC @ =0x00000E54
	adds r0, r6, r2
	b _081A24BC
	.align 2, 0
_081A24A8: .4byte 0x00000472
_081A24AC: .4byte 0x00000E54
_081A24B0:
	ldr r3, _081A2514 @ =0x00000472
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x24]
	ldr r5, _081A2518 @ =0x00000E54
	adds r0, r4, r5
_081A24BC:
	strh r1, [r0]
	adds r0, r7, #0
	bl FUN_081a0470
	ldr r6, [sp, #0x24]
	ldr r0, _081A251C @ =0x00000F14
	adds r2, r6, r0
	ldr r0, _081A2520 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r4, _081A2524 @ =0x0000012D
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	ldr r2, [sp, #0x190]
	strh r4, [r2]
	ldr r3, [sp, #0x194]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x198]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x19c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081A2528
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081A2534
	.align 2, 0
_081A2514: .4byte 0x00000472
_081A2518: .4byte 0x00000E54
_081A251C: .4byte 0x00000F14
_081A2520: .4byte 0x03002BE0
_081A2524: .4byte 0x0000012D
_081A2528:
	ldr r2, [r7, #0x44]
	ldr r0, _081A256C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081A2534:
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081A2584
	ldr r2, [sp, #0x70]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081A2570
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
	b _081A257A
	.align 2, 0
_081A256C: .4byte 0x03003584
_081A2570:
	ldr r3, [sp, #0x70]
	ldrb r0, [r3]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081A257A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081A2584:
	movs r4, #0
	ldr r5, [sp, #0x190]
	ldrh r0, [r5]
	ldr r6, [sp, #0x188]
	strh r0, [r6]
	ldrh r0, [r5]
	adds r0, #2
	ldr r1, [sp, #0x18c]
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0819edcc
	ldr r2, _081A273C @ =0x0000047E
	adds r1, r7, r2
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl Ax_InitHitboxes
	ldr r5, [sp, #0x24]
	movs r6, #0xed
	lsls r6, r6, #4
	adds r3, r5, r6
	ldr r0, _081A2740 @ =0x00000EF4
	adds r5, r5, r0
	ldr r1, _081A2744 @ =Ax_UpdateFrame
	str r1, [sp, #0x1a8]
	ldr r2, _081A2748 @ =Ax_GetMoveSpeed
	mov r8, r2
	ldr r6, _081A274C @ =Ax_StateTurn
	mov sb, r6
	ldr r0, _081A2750 @ =Ax_StateMove
	mov sl, r0
	ldr r1, _081A2754 @ =Ax_StateWait
	mov ip, r1
	ldr r2, _081A2758 @ =FUN_080f62b0
	ldr r6, _081A275C @ =FUN_080f62ac
	str r6, [sp, #0x1a0]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x40]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x38]
	str r3, [r0]
	ldr r1, [sp, #0x3c]
	str r5, [r1]
	ldr r3, [sp, #0x1a8]
	ldr r5, [sp, #0xb8]
	str r3, [r5]
	mov r6, r8
	ldr r0, [sp, #0xc0]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xd4]
	str r1, [r3]
	mov r5, sl
	ldr r6, [sp, #0xf4]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0xf8]
	str r0, [r1]
	ldr r3, [sp, #0x10c]
	str r4, [r3]
	ldr r5, [sp, #0x110]
	str r2, [r5]
	ldr r6, _081A2760 @ =Ax_StateDamaged
	ldr r0, [sp, #0x118]
	str r6, [r0]
	ldr r1, _081A2764 @ =Ax_StateDying
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r0, _081A2768 @ =FUN_080f44f4
	ldr r3, [sp, #0x120]
	str r0, [r3]
	ldr r0, _081A276C @ =FUN_080f410c
	ldr r5, [sp, #0x128]
	str r0, [r5]
	ldr r6, [sp, #0x114]
	str r4, [r6]
	ldr r0, [sp, #0xbc]
	str r4, [r0]
	ldr r1, [sp, #0x1a0]
	ldr r2, [sp, #0x14c]
	str r1, [r2]
	ldr r0, _081A2770 @ =FUN_080f0430
	ldr r3, [sp, #0x150]
	str r0, [r3]
	movs r6, #1
	ldr r5, [sp, #0x88]
	strb r6, [r5]
	ldr r0, _081A2774 @ =0x085AD470
	ldr r1, [sp, #0x154]
	str r0, [r1]
	ldr r0, _081A2778 @ =FUN_080e73c8
	ldr r2, [sp, #0x13c]
	str r0, [r2]
	ldr r3, [sp, #0x130]
	str r4, [r3]
	ldr r5, [sp, #0x140]
	str r4, [r5]
	ldr r6, [sp, #0x144]
	str r4, [r6]
	ldr r0, [sp, #0x148]
	str r4, [r0]
	ldr r1, [sp, #0x158]
	str r4, [r1]
	ldr r0, _081A277C @ =FUN_080f0320
	ldr r2, [sp, #0x15c]
	str r0, [r2]
	ldr r0, _081A2780 @ =Enemy_080eff14
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r0, _081A2784 @ =FUN_080e72b0
	ldr r5, [sp, #0x134]
	str r0, [r5]
	ldr r6, [sp, #0x12c]
	str r4, [r6]
	ldr r0, _081A2788 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x138]
	str r0, [r1]
	ldr r0, _081A278C @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x124]
	str r0, [r2]
	ldr r3, [sp, #0xfc]
	str r4, [r3]
	ldr r0, _081A2790 @ =FUN_080f6e64
	ldr r5, [sp, #0x160]
	str r0, [r5]
	ldr r0, _081A2794 @ =Enemy_OnDamaged
	ldr r6, [sp, #0xc8]
	str r0, [r6]
	ldr r0, _081A2798 @ =FUN_080f84d4
	ldr r1, [sp, #0x164]
	str r0, [r1]
	ldr r0, _081A279C @ =FUN_080f624c
	ldr r2, [sp, #0x104]
	str r0, [r2]
	ldr r0, _081A27A0 @ =FUN_080f56ec
	ldr r3, [sp, #0xe0]
	str r0, [r3]
	ldr r0, _081A27A4 @ =FUN_080f5b34
	ldr r5, [sp, #0xe4]
	str r0, [r5]
	ldr r0, _081A27A8 @ =FUN_080f5fac
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, [sp, #0x100]
	str r4, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081A27AC @ =Ax_OnReset
	str r0, [r1]
	ldr r3, _081A27B0 @ =0x000005FC
	adds r0, r7, r3
	str r4, [r0]
	ldr r5, _081A27B4 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _081A27B8 @ =Ax_OnAttackRequest
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r4, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081A27BC @ =Ax_TryDetectPlayer
	str r0, [r1]
	subs r2, #0x6c
	adds r1, r7, r2
	ldr r0, _081A27C0 @ =Ax_OnDamaged
	str r0, [r1]
	movs r0, #0x60
	ldr r3, [sp, #0x184]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x40]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _081A27C4 @ =0x02100408
	ldr r5, [sp, #0x44]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A27D2
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_081A272E:
	bl VM_GetPC
	cmp r0, #0
	beq _081A27C8
	bl VM_GetValue
	b _081A27CA
	.align 2, 0
_081A273C: .4byte 0x0000047E
_081A2740: .4byte 0x00000EF4
_081A2744: .4byte Ax_UpdateFrame
_081A2748: .4byte Ax_GetMoveSpeed
_081A274C: .4byte Ax_StateTurn
_081A2750: .4byte Ax_StateMove
_081A2754: .4byte Ax_StateWait
_081A2758: .4byte FUN_080f62b0
_081A275C: .4byte FUN_080f62ac
_081A2760: .4byte Ax_StateDamaged
_081A2764: .4byte Ax_StateDying
_081A2768: .4byte FUN_080f44f4
_081A276C: .4byte FUN_080f410c
_081A2770: .4byte FUN_080f0430
_081A2774: .4byte 0x085AD470
_081A2778: .4byte FUN_080e73c8
_081A277C: .4byte FUN_080f0320
_081A2780: .4byte Enemy_080eff14
_081A2784: .4byte FUN_080e72b0
_081A2788: .4byte Enemy_StateBlownAway
_081A278C: .4byte Enemy_StateFallDeath
_081A2790: .4byte FUN_080f6e64
_081A2794: .4byte Enemy_OnDamaged
_081A2798: .4byte FUN_080f84d4
_081A279C: .4byte FUN_080f624c
_081A27A0: .4byte FUN_080f56ec
_081A27A4: .4byte FUN_080f5b34
_081A27A8: .4byte FUN_080f5fac
_081A27AC: .4byte Ax_OnReset
_081A27B0: .4byte 0x000005FC
_081A27B4: .4byte 0x000005AC
_081A27B8: .4byte Ax_OnAttackRequest
_081A27BC: .4byte Ax_TryDetectPlayer
_081A27C0: .4byte Ax_OnDamaged
_081A27C4: .4byte 0x02100408
_081A27C8:
	movs r0, #0
_081A27CA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081A272E
_081A27D2:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x54]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x34]
	strh r0, [r3]
	cmp r2, #0
	beq _081A280A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x40]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081A280A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081A280A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x184]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A281C
	movs r0, #1
	b _081A281E
_081A281C:
	movs r0, #0
_081A281E:
	cmp r0, #0
	beq _081A2830
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x44]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081A2830:
	cmp r2, #1
	beq _081A2870
	movs r1, #0
	ldr r0, [sp, #0x178]
	strb r1, [r0]
	ldr r2, [sp, #0x17c]
	strb r1, [r2]
	ldr r3, [sp, #0x180]
	strb r1, [r3]
	ldr r4, _081A2880 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081A2884 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xf8]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x84]
	strb r1, [r6]
	ldr r0, [sp, #0xb4]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081A2870:
	movs r1, #2
	ldr r3, [sp, #0x184]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081A2888
	movs r0, #1
	b _081A288A
	.align 2, 0
_081A2880: .4byte 0x00000484
_081A2884: .4byte 0x0000046C
_081A2888:
	movs r0, #0
_081A288A:
	cmp r0, #0
	beq _081A28A4
	ldr r0, _081A28A0 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x30]
	strh r0, [r5]
	b _081A28AE
	.align 2, 0
_081A28A0: .4byte 0x030046A0
_081A28A4:
	ldr r0, [sp, #0x168]
	bl GetZoneAt
	ldr r6, [sp, #0x30]
	strh r0, [r6]
_081A28AE:
	movs r1, #0x40
	ldr r2, [sp, #0x184]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A28BE
	movs r0, #1
	b _081A28C0
_081A28BE:
	movs r0, #0
_081A28C0:
	cmp r0, #0
	beq _081A28D0
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081A28F4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081A28D0:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081A2902
	ldr r0, _081A28F8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x30]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081A28FC
	movs r0, #1
	b _081A28FE
	.align 2, 0
_081A28F4: .4byte 0xFFFFFEFF
_081A28F8: .4byte 0x030046A0
_081A28FC:
	movs r0, #0
_081A28FE:
	cmp r0, #0
	bne _081A290A
_081A2902:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_081A290A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xec]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A29F2
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
	beq _081A294C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081A2954
_081A294C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A2954:
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
	beq _081A2978
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081A2980
_081A2978:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081A2980:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081A29B8 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081A29FC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081A29BC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081A29B0
	ldrb r0, [r4, #5]
_081A29B0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081A29CC
	.align 2, 0
_081A29B8: .4byte 0x0000FFFF
_081A29BC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081A29CC
	strh r1, [r4, #8]
_081A29CC:
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
	bne _081A29FC
	movs r0, #1
	strb r0, [r4, #7]
	b _081A29FC
_081A29F2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081A29FC:
	movs r0, #0
	ldr r3, [sp, #0x60]
	str r0, [r3]
	ldr r0, _081A2A14 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A2A18
	movs r0, #1
	b _081A2A1A
	.align 2, 0
_081A2A14: .4byte 0x030047A4
_081A2A18:
	movs r0, #0
_081A2A1A:
	cmp r0, #0
	bne _081A2A5A
	ldr r4, [sp, #0x70]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A2A42
	adds r0, r1, #0
	cmp r0, #7
	beq _081A2A42
	cmp r0, #6
	beq _081A2A42
	cmp r0, #0x15
	beq _081A2A42
	cmp r0, #0x14
	beq _081A2A42
	cmp r0, #0x17
	bne _081A2A5A
_081A2A42:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x184]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081A2A5A:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Ax_SetHandlerTable2
	adds r0, r7, #0
	bl Ax_SetHandlerTable4
	adds r0, r7, #0
	bl Ax_SetHandlerTable3
	ldr r1, [r7, #0x44]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #7]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r2, [r0]
	adds r0, r7, #0
	bl Ax_InitAfterimages
	adds r0, r7, #0
	bl Ax_ClearRecentNodes
	adds r0, r7, #0
	bl FUN_0819fd30
	ldr r1, [sp, #0x184]
	ldrh r0, [r1]
	ldr r2, [sp, #0xb0]
	strh r0, [r2]
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldr r4, [sp, #0xac]
	strh r0, [r4]
	ldr r5, [sp, #0x40]
	ldr r0, [r5]
	ldr r6, [sp, #0x8c]
	str r0, [r6]
	ldr r1, [sp, #0x44]
	ldr r0, [r1]
	ldr r2, [sp, #0x90]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x94]
	strb r0, [r3]
	ldr r4, [sp, #0x178]
	ldrb r0, [r4]
	ldr r5, [sp, #0x98]
	strb r0, [r5]
	ldr r6, [sp, #0x17c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x9c]
	strb r0, [r1]
	ldr r2, [sp, #0x180]
	ldrb r0, [r2]
	ldr r3, [sp, #0xa0]
	strb r0, [r3]
	ldr r4, [sp, #0xb4]
	ldr r0, [r4]
	ldr r5, [sp, #0xa4]
	str r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	ldr r1, [sp, #0xa8]
	strb r0, [r1]
	ldr r2, _081A2B1C @ =0x00000574
	adds r1, r7, r2
	ldr r3, [sp, #0x24]
	ldr r4, _081A2B20 @ =0x00000E48
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, _081A2B24 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081A2B28 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r6, _081A2B2C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081A2B30 @ =Ax_Update
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081A2B34 @ =Ax_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A2B38
	movs r0, #0
	b _081A2B3C
	.align 2, 0
_081A2B1C: .4byte 0x00000574
_081A2B20: .4byte 0x00000E48
_081A2B24: .4byte 0x0000057C
_081A2B28: .4byte Enemy_DispatchMsg
_081A2B2C: .4byte 0x0000061C
_081A2B30: .4byte Ax_Update
_081A2B34: .4byte Ax_Destroy
_081A2B38:
	movs r0, #1
	rsbs r0, r0, #0
_081A2B3C:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
