	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _0813D5CC @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x11
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0813c738
	ldr r3, _0813D5D0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813D5DC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0813D5D4 @ =0x0000D28E
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0813D5D8 @ =0x00009607
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _0813D5CC @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x90]
	cmp r1, #0x11
	beq _0813D5BA
	cmp r1, #0x17
	bne _0813D5BE
_0813D5BA:
	movs r0, #1
	strb r0, [r5, #7]
_0813D5BE:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _0813D644
	.align 2, 0
_0813D5CC: .4byte 0x000001DF
_0813D5D0: .4byte 0x0000025D
_0813D5D4: .4byte 0x0000D28E
_0813D5D8: .4byte 0x00009607
_0813D5DC:
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
	ldr r2, _0813D6C0 @ =0x05000002
	bl CpuSet
	ldr r0, _0813D6C4 @ =0x0000CB05
	ldr r1, _0813D6C8 @ =0x0000D28E
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
	ldr r0, _0813D6CC @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _0813D6D0 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x90]
_0813D644:
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
	ldr r5, _0813D6D4 @ =0x0000046F
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
	ldr r1, _0813D6D8 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0813D6C0 @ =0x05000002
	bl CpuSet
	ldr r3, _0813D6DC @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x64]
	str r6, [sp, #0x3c]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _0813D6B0
	b _0813D810
_0813D6B0:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D6E0
	bl VM_GetValue
	adds r1, r0, #0
	b _0813D6E2
	.align 2, 0
_0813D6C0: .4byte 0x05000002
_0813D6C4: .4byte 0x0000CB05
_0813D6C8: .4byte 0x0000D28E
_0813D6CC: .4byte 0x000004B7
_0813D6D0: .4byte 0x000001DF
_0813D6D4: .4byte 0x0000046F
_0813D6D8: .4byte 0x00000474
_0813D6DC: .4byte 0x000004B6
_0813D6E0:
	movs r1, #0
_0813D6E2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0813D708 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xe8]
	str r4, [sp, #0xec]
	cmp r0, #0
	beq _0813D70C
	bl VM_GetValue
	adds r1, r0, #0
	b _0813D70E
	.align 2, 0
_0813D708: .4byte 0x00000251
_0813D70C:
	movs r1, #0
_0813D70E:
	ldr r2, _0813D744 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813D748 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xe8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _0813D74C
	bl VM_GetValue
	b _0813D750
	.align 2, 0
_0813D744: .4byte 0x00000252
_0813D748: .4byte 0x000004B4
_0813D74C:
	ldr r4, [sp, #0xe8]
	ldrb r0, [r4]
_0813D750:
	strb r0, [r6]
	ldr r5, [sp, #0xe8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xf4]
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
	blt _0813D788
	cmp r1, #0
	blt _0813D788
	ldr r0, _0813D78C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813D788
	ldr r0, _0813D790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813D794
_0813D788:
	movs r1, #0
	b _0813D7A2
	.align 2, 0
_0813D78C: .4byte 0x030046A8
_0813D790: .4byte 0x030046AC
_0813D794:
	ldr r0, _0813D7BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0813D7A2:
	ldr r2, _0813D7C0 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0813D7C4
	adds r0, #4
	b _0813D7D0
	.align 2, 0
_0813D7BC: .4byte 0x030046A4
_0813D7C0: .4byte 0x00000256
_0813D7C4:
	ldr r0, _0813D7E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813D7D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813D7E8
	cmp r2, #2
	beq _0813D7EC
	b _0813D7F0
	.align 2, 0
_0813D7E4: .4byte 0x030046A4
_0813D7E8:
	ldrb r0, [r4, #4]
	b _0813D7EE
_0813D7EC:
	ldrb r0, [r4]
_0813D7EE:
	subs r1, r1, r0
_0813D7F0:
	ldr r3, _0813D808 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0813D80C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _0813D850
	.align 2, 0
_0813D808: .4byte 0x00000472
_0813D80C: .4byte 0x0000FFFF
_0813D810:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0813D874 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813D878 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0813D87C @ =0x000004B4
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
	str r5, [sp, #0xe8]
	str r4, [sp, #0xec]
	str r3, [sp, #0xf4]
_0813D850:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813D89A
	bl VM_GetPC
	cmp r0, #0
	beq _0813D880
	bl VM_GetValue
	adds r4, r0, #0
	b _0813D882
	.align 2, 0
_0813D874: .4byte 0x00000251
_0813D878: .4byte 0x00000252
_0813D87C: .4byte 0x000004B4
_0813D880:
	movs r4, #0x30
_0813D882:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D894
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0813D896
_0813D894:
	movs r5, #0x40
_0813D896:
	mov r8, r4
	b _0813D8A0
_0813D89A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0813D8A0:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813D8D8
	bl VM_GetPC
	cmp r0, #0
	beq _0813D8BA
	bl VM_GetValue
	adds r6, r0, #0
	b _0813D8BC
_0813D8BA:
	movs r6, #0
_0813D8BC:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D8CC
	bl VM_GetValue
	adds r1, r0, #0
	b _0813D8CE
_0813D8CC:
	movs r1, #0
_0813D8CE:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0813D8E2
_0813D8D8:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0813D8E2:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0813DB54 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe0]
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
	str r2, [sp, #0xf8]
	lsls r4, r4, #0x10
	str r4, [sp, #0x84]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x8c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x94]
	lsls r5, r5, #0x10
	str r5, [sp, #0x88]
	ldr r4, _0813DB58 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x104]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x7c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x18c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x98]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x9c]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x190]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x194]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x188]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r1, _0813DB5C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _0813DB60 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _0813DB64 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _0813DB68 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _0813DB6C @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0813DB70 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x130]
	ldr r1, _0813DB74 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _0813DB78 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _0813DB7C @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0813DB80 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	ldr r1, _0813DB84 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _0813DB88 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	ldr r4, _0813DB8C @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _0813DB90 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	ldr r2, _0813DB94 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x164]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	ldr r4, _0813DB98 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _0813DB9C @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _0813DBA0 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _0813DBA4 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x180]
	ldr r1, _0813DBA8 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _0813DBAC @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x10c]
	ldr r6, _0813DBB0 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x110]
	ldr r1, _0813DBB4 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x120]
	ldr r2, _0813DBB8 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _0813DBBC @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x54]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r1, _0813DBC0 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _0813DBC4 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _0813DBC8 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	ldr r1, _0813DBCC @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	ldr r4, _0813DBD0 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xac]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _0813DBD4 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _0813DBD8 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0813DBDC @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	ldr r3, _0813DBE0 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	ldr r5, _0813DBE4 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	cmp r0, #0
	bne _0813DB24
	b _0813DC3E
_0813DB24:
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
_0813DB44:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DBE8
	bl VM_GetValue
	b _0813DBEA
	.align 2, 0
_0813DB54: .4byte 0x0000025D
_0813DB58: .4byte 0x0000025A
_0813DB5C: .4byte 0x0000047A
_0813DB60: .4byte 0x0000047C
_0813DB64: .4byte 0x0000047E
_0813DB68: .4byte 0x000004A4
_0813DB6C: .4byte 0x000005A4
_0813DB70: .4byte 0x000005C4
_0813DB74: .4byte 0x000005CC
_0813DB78: .4byte 0x000005D4
_0813DB7C: .4byte 0x000005DC
_0813DB80: .4byte 0x00000584
_0813DB84: .4byte 0x00000604
_0813DB88: .4byte 0x0000021D
_0813DB8C: .4byte 0x0000060C
_0813DB90: .4byte 0x000005E4
_0813DB94: .4byte 0x000005FC
_0813DB98: .4byte 0x00000614
_0813DB9C: .4byte 0x000005BC
_0813DBA0: .4byte 0x000005EC
_0813DBA4: .4byte 0x00000624
_0813DBA8: .4byte 0x0000058C
_0813DBAC: .4byte 0x00000594
_0813DBB0: .4byte 0x0000059C
_0813DBB4: .4byte 0x000005B4
_0813DBB8: .4byte 0x00000543
_0813DBBC: .4byte 0x00000496
_0813DBC0: .4byte 0x00000469
_0813DBC4: .4byte 0x0000046A
_0813DBC8: .4byte 0x00000553
_0813DBCC: .4byte 0x00000572
_0813DBD0: .4byte 0x0000055C
_0813DBD4: .4byte 0x00000564
_0813DBD8: .4byte 0x00000565
_0813DBDC: .4byte 0x00000566
_0813DBE0: .4byte 0x00000567
_0813DBE4: .4byte 0x0000056C
_0813DBE8:
	movs r0, #0x18
_0813DBEA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0813DBFC
	bl VM_GetValue
	b _0813DBFE
_0813DBFC:
	movs r0, #0x18
_0813DBFE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC10
	bl VM_GetValue
	b _0813DC12
_0813DC10:
	movs r0, #0
_0813DC12:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC24
	bl VM_GetValue
	b _0813DC26
_0813DC24:
	movs r0, #0
_0813DC26:
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
	ble _0813DB44
_0813DC3E:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813DC8A
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC58
	bl VM_GetValue
	adds r4, r0, #0
	b _0813DC5C
_0813DC58:
	movs r4, #0x96
	lsls r4, r4, #1
_0813DC5C:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC6C
	bl VM_GetValue
	adds r6, r0, #0
	b _0813DC70
_0813DC6C:
	movs r6, #0x96
	lsls r6, r6, #1
_0813DC70:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC7E
	bl VM_GetValue
	b _0813DC84
_0813DC7E:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_0813DC84:
	ldr r5, [sp, #0xe0]
	strh r0, [r5]
	b _0813DC92
_0813DC8A:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0xe0]
	strh r6, [r0]
_0813DC92:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0813DCAA
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0813DCAA:
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
	beq _0813DD78
	bl VM_GetPC
	cmp r0, #0
	beq _0813DCDA
	bl VM_GetValue
	b _0813DCDC
_0813DCDA:
	movs r0, #0
_0813DCDC:
	ldr r1, [sp, #0xf8]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813DCEA
	asrs r1, r0, #1
	b _0813DCF0
_0813DCEA:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0813DCF0:
	ldr r2, _0813DD04 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD08
	bl VM_GetValue
	b _0813DD0A
	.align 2, 0
_0813DD04: .4byte 0x00000546
_0813DD08:
	movs r0, #0
_0813DD0A:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD20
	bl VM_GetValue
	b _0813DD22
_0813DD20:
	movs r0, #0
_0813DD22:
	ldr r5, _0813DD38 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD3C
	bl VM_GetValue
	adds r1, r0, #0
	b _0813DD3E
	.align 2, 0
_0813DD38: .4byte 0x00000187
_0813DD3C:
	movs r1, #0
_0813DD3E:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD54
	bl VM_GetValue
	b _0813DD56
_0813DD54:
	movs r0, #0
_0813DD56:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD6E
	bl VM_GetValue
	adds r1, r0, #0
	b _0813DD70
_0813DD6E:
	movs r1, #0
_0813DD70:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0813DD78:
	ldr r0, [sp, #0xf8]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0x84]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x8c]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x94]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x88]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813DDDA
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0813DDC0
	bl VM_GetValue
	b _0813DDC2
_0813DDC0:
	movs r0, #0
_0813DDC2:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DDD2
	bl VM_GetValue
	b _0813DDD4
_0813DDD2:
	movs r0, #0
_0813DDD4:
	ldr r2, _0813DE3C @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0813DDDA:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x104]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0813DDFE
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x64]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0813DDFE:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0813DE16
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0813DE16:
	ldr r6, [sp, #0x7c]
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
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813DE40
	movs r0, #1
	b _0813DE42
	.align 2, 0
_0813DE3C: .4byte 0x00000189
_0813DE40:
	movs r0, #0
_0813DE42:
	cmp r0, #0
	beq _0813DE52
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0813DE7C @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_0813DE52:
	ldr r3, [sp, #0x108]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0813DE5E
	ldr r1, [r7, #0x44]
_0813DE5E:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x90]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0813DE80
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x18c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _0813DE8C
	.align 2, 0
_0813DE7C: .4byte Enemy_OnCWolfMessage
_0813DE80:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x18c]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_0813DE8C:
	ldr r5, [sp, #0x90]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0813DEDA
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0813DEDA
	cmp r0, #0x16
	beq _0813DEDA
	cmp r0, #0x14
	beq _0813DEDA
	cmp r0, #9
	beq _0813DEDA
	cmp r0, #0x19
	beq _0813DEDA
	cmp r0, #0x1a
	beq _0813DEDA
	cmp r0, #0xd
	beq _0813DEDA
	cmp r0, #0x1b
	beq _0813DEDA
	cmp r0, #0x1f
	beq _0813DEDA
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xe8]
	ldrb r2, [r6]
	ldr r0, [sp, #0xec]
	ldrb r3, [r0]
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_0813DEDA:
	movs r1, #8
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0813DEEA
	movs r0, #1
	b _0813DEEC
_0813DEEA:
	movs r0, #0
_0813DEEC:
	cmp r0, #0
	beq _0813DEFA
	ldr r6, [sp, #0x9c]
	ldr r0, [r6]
	ldr r1, [sp, #0x98]
	str r0, [r1]
	b _0813DF0C
_0813DEFA:
	ldr r2, [sp, #0x9c]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x98]
	str r0, [r3]
_0813DF0C:
	ldrh r0, [r7]
	ldr r4, [sp, #0x190]
	strh r0, [r4]
	ldr r5, [sp, #0x188]
	ldr r6, [sp, #0x194]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0813DF36
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
_0813DF36:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813E014
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF4E
	bl VM_GetValue
	b _0813DF50
_0813DF4E:
	movs r0, #0
_0813DF50:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF60
	bl VM_GetValue
	b _0813DF62
_0813DF60:
	movs r0, #0
_0813DF62:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF72
	bl VM_GetValue
	b _0813DF74
_0813DF72:
	movs r0, #0
_0813DF74:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x188]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0813DF9C
	cmp r1, #0
	blt _0813DF9C
	ldr r0, _0813DFA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813DF9C
	ldr r0, _0813DFA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813DFA8
_0813DF9C:
	movs r1, #0
	b _0813DFB6
	.align 2, 0
_0813DFA0: .4byte 0x030046A8
_0813DFA4: .4byte 0x030046AC
_0813DFA8:
	ldr r0, _0813DFD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0813DFB6:
	ldr r4, _0813DFD4 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x188]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0813DFD8
	adds r0, #4
	b _0813DFE4
	.align 2, 0
_0813DFD0: .4byte 0x030046A4
_0813DFD4: .4byte 0x00000256
_0813DFD8:
	ldr r0, _0813DFF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813DFE4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813DFFC
	cmp r2, #2
	beq _0813E000
	b _0813E004
	.align 2, 0
_0813DFF8: .4byte 0x030046A4
_0813DFFC:
	ldrb r0, [r5, #4]
	b _0813E002
_0813E000:
	ldrb r0, [r5]
_0813E002:
	subs r1, r1, r0
_0813E004:
	ldr r5, _0813E030 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
_0813E014:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813E05E
	bl VM_GetPC
	cmp r0, #0
	beq _0813E034
	bl VM_GetValue
	adds r1, r0, #0
	b _0813E036
	.align 2, 0
_0813E030: .4byte 0x00000472
_0813E034:
	movs r1, #0
_0813E036:
	ldr r3, [sp, #0x24]
	ldr r4, _0813E050 @ =0x0000065C
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813E054
	bl VM_GetValue
	adds r1, r0, #0
	b _0813E056
	.align 2, 0
_0813E050: .4byte 0x0000065C
_0813E054:
	movs r1, #0
_0813E056:
	ldr r5, [sp, #0x24]
	ldr r6, _0813E09C @ =0x0000065D
	adds r0, r5, r6
	strb r1, [r0]
_0813E05E:
	movs r4, #0x5c
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	ldr r2, [sp, #0x40]
	strh r4, [r2]
	ldr r3, [sp, #0x44]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, #0x61
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0x108]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0813E0A0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0813E0AC
	.align 2, 0
_0813E09C: .4byte 0x0000065D
_0813E0A0:
	ldr r2, [r7, #0x44]
	ldr r0, _0813E0E4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0813E0AC:
	ldr r1, [sp, #0x108]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0813E0FC
	ldr r2, [sp, #0x90]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0813E0E8
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
	b _0813E0F2
	.align 2, 0
_0813E0E4: .4byte 0x03003584
_0813E0E8:
	ldr r3, [sp, #0x90]
	ldrb r0, [r3]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0813E0F2:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0813E0FC:
	adds r0, r7, #0
	bl Curoro_InitHitboxes
	ldr r5, [sp, #0x24]
	ldr r6, _0813E2A8 @ =0x0000066C
	adds r4, r5, r6
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r1, _0813E2AC @ =FUN_0813d404
	str r1, [sp, #0x1a0]
	ldr r2, _0813E2B0 @ =Curoro_GetMoveSpeed
	mov r8, r2
	ldr r3, _0813E2B4 @ =FUN_0813ae6c
	mov sb, r3
	ldr r6, _0813E2B8 @ =FUN_0813ac34
	mov sl, r6
	ldr r0, _0813E2BC @ =FUN_0813ad64
	mov ip, r0
	movs r2, #0
	ldr r3, _0813E2C0 @ =FUN_080f62b0
	ldr r1, _0813E2C4 @ =FUN_080f62ac
	str r1, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x58]
	str r4, [r0]
	ldr r1, [sp, #0x5c]
	str r5, [r1]
	ldr r4, [sp, #0x1a0]
	ldr r5, [sp, #0xd8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xfc]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x114]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x118]
	str r0, [r1]
	ldr r4, [sp, #0x12c]
	str r2, [r4]
	ldr r5, [sp, #0x130]
	str r3, [r5]
	ldr r6, _0813E2C8 @ =FUN_0813b358
	ldr r0, [sp, #0x138]
	str r6, [r0]
	ldr r1, _0813E2CC @ =FUN_0813b640
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r0, _0813E2D0 @ =FUN_080f44f4
	ldr r4, [sp, #0x140]
	str r0, [r4]
	ldr r0, _0813E2D4 @ =FUN_080f410c
	ldr r5, [sp, #0x148]
	str r0, [r5]
	ldr r6, [sp, #0x134]
	str r2, [r6]
	ldr r0, [sp, #0xdc]
	str r2, [r0]
	ldr r1, [sp, #0x198]
	ldr r3, [sp, #0x16c]
	str r1, [r3]
	ldr r0, _0813E2D8 @ =FUN_080f0430
	ldr r4, [sp, #0x170]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0xa8]
	strb r6, [r5]
	ldr r0, _0813E2DC @ =0x085AD470
	ldr r1, [sp, #0x174]
	str r0, [r1]
	ldr r0, _0813E2E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x15c]
	str r0, [r3]
	ldr r4, [sp, #0x150]
	str r2, [r4]
	ldr r5, [sp, #0x160]
	str r2, [r5]
	ldr r6, [sp, #0x164]
	str r2, [r6]
	ldr r0, [sp, #0x168]
	str r2, [r0]
	ldr r1, [sp, #0x178]
	str r2, [r1]
	ldr r0, _0813E2E4 @ =FUN_080f0320
	ldr r3, [sp, #0x17c]
	str r0, [r3]
	ldr r0, _0813E2E8 @ =Enemy_080eff14
	ldr r4, [sp, #0x128]
	str r0, [r4]
	ldr r0, _0813E2EC @ =FUN_080e72b0
	ldr r5, [sp, #0x154]
	str r0, [r5]
	ldr r6, [sp, #0x14c]
	str r2, [r6]
	ldr r0, _0813E2F0 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x158]
	str r0, [r1]
	ldr r0, _0813E2F4 @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x144]
	str r0, [r3]
	ldr r4, [sp, #0x11c]
	str r2, [r4]
	ldr r0, _0813E2F8 @ =FUN_080f6e64
	ldr r5, [sp, #0x180]
	str r0, [r5]
	ldr r0, _0813E2FC @ =Enemy_OnDamaged
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, _0813E300 @ =FUN_080f84d4
	ldr r1, [sp, #0x184]
	str r0, [r1]
	ldr r0, _0813E304 @ =FUN_080f624c
	ldr r3, [sp, #0x124]
	str r0, [r3]
	ldr r0, _0813E308 @ =FUN_080f56ec
	ldr r4, [sp, #0x100]
	str r0, [r4]
	ldr r0, _0813E30C @ =FUN_080f5b34
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r0, _0813E310 @ =FUN_080f5fac
	ldr r6, [sp, #0x110]
	str r0, [r6]
	ldr r0, [sp, #0x120]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0xa0]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0813E314 @ =Curoro_OnReset
	str r0, [r1]
	ldr r4, _0813E318 @ =0x000005FC
	adds r0, r7, r4
	str r2, [r0]
	ldr r5, _0813E31C @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _0813E320 @ =FUN_0813ccf0
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0813E324 @ =FUN_0813cc7c
	str r0, [r1]
	ldr r2, _0813E328 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _0813E32C @ =0x085AD7B4
	str r0, [r1]
	movs r0, #0x60
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, _0813E330 @ =0x02100400
	ldr r5, [sp, #0x64]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813E274
	movs r0, #8
	orrs r1, r0
	str r1, [r5]
_0813E274:
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x70]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813E33E
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_0813E298:
	bl VM_GetPC
	cmp r0, #0
	beq _0813E334
	bl VM_GetValue
	b _0813E336
	.align 2, 0
_0813E2A8: .4byte 0x0000066C
_0813E2AC: .4byte FUN_0813d404
_0813E2B0: .4byte Curoro_GetMoveSpeed
_0813E2B4: .4byte FUN_0813ae6c
_0813E2B8: .4byte FUN_0813ac34
_0813E2BC: .4byte FUN_0813ad64
_0813E2C0: .4byte FUN_080f62b0
_0813E2C4: .4byte FUN_080f62ac
_0813E2C8: .4byte FUN_0813b358
_0813E2CC: .4byte FUN_0813b640
_0813E2D0: .4byte FUN_080f44f4
_0813E2D4: .4byte FUN_080f410c
_0813E2D8: .4byte FUN_080f0430
_0813E2DC: .4byte 0x085AD470
_0813E2E0: .4byte FUN_080e73c8
_0813E2E4: .4byte FUN_080f0320
_0813E2E8: .4byte Enemy_080eff14
_0813E2EC: .4byte FUN_080e72b0
_0813E2F0: .4byte Enemy_StateBlownAway
_0813E2F4: .4byte Enemy_StateFallDeath
_0813E2F8: .4byte FUN_080f6e64
_0813E2FC: .4byte Enemy_OnDamaged
_0813E300: .4byte FUN_080f84d4
_0813E304: .4byte FUN_080f624c
_0813E308: .4byte FUN_080f56ec
_0813E30C: .4byte FUN_080f5b34
_0813E310: .4byte FUN_080f5fac
_0813E314: .4byte Curoro_OnReset
_0813E318: .4byte 0x000005FC
_0813E31C: .4byte 0x000005AC
_0813E320: .4byte FUN_0813ccf0
_0813E324: .4byte FUN_0813cc7c
_0813E328: .4byte 0x0000060C
_0813E32C: .4byte 0x085AD7B4
_0813E330: .4byte 0x02100400
_0813E334:
	movs r0, #0
_0813E336:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0813E298
_0813E33E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x74]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x54]
	strh r0, [r4]
	cmp r2, #0
	beq _0813E376
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x60]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _0813E376
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_0813E376:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x3c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0813E388
	movs r0, #1
	b _0813E38A
_0813E388:
	movs r0, #0
_0813E38A:
	cmp r0, #0
	beq _0813E39C
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_0813E39C:
	cmp r2, #1
	beq _0813E3DC
	movs r1, #0
	ldr r3, [sp, #0x30]
	strb r1, [r3]
	ldr r4, [sp, #0x34]
	strb r1, [r4]
	ldr r5, [sp, #0x38]
	strb r1, [r5]
	ldr r6, _0813E3EC @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _0813E3F0 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x118]
	ldr r3, [r4]
	ldr r5, _0813E3F4 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xa4]
	strb r1, [r0]
	ldr r2, [sp, #0xd4]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0813E3DC:
	movs r1, #2
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813E3F8
	movs r0, #1
	b _0813E3FA
	.align 2, 0
_0813E3EC: .4byte 0x00000484
_0813E3F0: .4byte 0x0000046C
_0813E3F4: .4byte 0x0000046D
_0813E3F8:
	movs r0, #0
_0813E3FA:
	cmp r0, #0
	beq _0813E414
	ldr r0, _0813E410 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	b _0813E41E
	.align 2, 0
_0813E410: .4byte 0x030046A0
_0813E414:
	ldr r0, [sp, #0x188]
	bl GetZoneAt
	ldr r1, [sp, #0x50]
	strh r0, [r1]
_0813E41E:
	movs r1, #0x40
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813E42E
	movs r0, #1
	b _0813E430
_0813E42E:
	movs r0, #0
_0813E430:
	cmp r0, #0
	beq _0813E440
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0813E464 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0813E440:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0813E472
	ldr r0, _0813E468 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x50]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0813E46C
	movs r0, #1
	b _0813E46E
	.align 2, 0
_0813E464: .4byte 0xFFFFFEFF
_0813E468: .4byte 0x030046A0
_0813E46C:
	movs r0, #0
_0813E46E:
	cmp r0, #0
	bne _0813E47A
_0813E472:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0813E47A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x108]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0813E562
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
	beq _0813E4BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0813E4C4
_0813E4BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813E4C4:
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
	beq _0813E4E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0813E4F0
_0813E4E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813E4F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0813E528 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0813E56C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0813E52C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0813E520
	ldrb r0, [r4, #5]
_0813E520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0813E53C
	.align 2, 0
_0813E528: .4byte 0x0000FFFF
_0813E52C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0813E53C
	strh r1, [r4, #8]
_0813E53C:
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
	bne _0813E56C
	movs r0, #1
	strb r0, [r4, #7]
	b _0813E56C
_0813E562:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_0813E56C:
	movs r0, #0
	ldr r3, [sp, #0x80]
	str r0, [r3]
	ldr r0, _0813E584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813E588
	movs r0, #1
	b _0813E58A
	.align 2, 0
_0813E584: .4byte 0x030047A4
_0813E588:
	movs r0, #0
_0813E58A:
	cmp r0, #0
	bne _0813E5CA
	ldr r4, [sp, #0x90]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0813E5B2
	adds r0, r1, #0
	cmp r0, #7
	beq _0813E5B2
	cmp r0, #6
	beq _0813E5B2
	cmp r0, #0x15
	beq _0813E5B2
	cmp r0, #0x14
	beq _0813E5B2
	cmp r0, #0x17
	bne _0813E5CA
_0813E5B2:
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
_0813E5CA:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_0813c138
	adds r0, r7, #0
	bl FUN_0813d1bc
	adds r0, r7, #0
	bl FUN_0813d3f4
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xd0]
	strh r0, [r2]
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ldr r4, [sp, #0xcc]
	strh r0, [r4]
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	ldr r6, [sp, #0xac]
	str r0, [r6]
	ldr r1, [sp, #0x64]
	ldr r0, [r1]
	ldr r2, [sp, #0xb0]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xb4]
	strb r0, [r3]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb8]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0xd4]
	ldr r0, [r4]
	ldr r5, [sp, #0xc4]
	str r0, [r5]
	ldr r6, [sp, #0xa4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc8]
	strb r0, [r1]
	ldr r2, _0813E664 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0813E668 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0813E66C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0813E670 @ =Curoro_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0813E674 @ =Curoro_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813E678
	movs r0, #0
	b _0813E67C
	.align 2, 0
_0813E664: .4byte 0x0000057C
_0813E668: .4byte Enemy_DispatchMsg
_0813E66C: .4byte 0x0000061C
_0813E670: .4byte Curoro_Update
_0813E674: .4byte Curoro_Destroy
_0813E678:
	movs r0, #1
	rsbs r0, r0, #0
_0813E67C:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
