	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x2c]
	ldr r1, _0816F22C @ =0x000007DC
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _0816F230 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x17
	strb r0, [r1]
	adds r0, r7, #0
	bl Ghost_InitAnims
	ldr r3, _0816F234 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816F244
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0816F238 @ =0x0000D637
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0816F23C @ =0x000029FB
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _0816F230 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x120]
	cmp r1, #0x11
	beq _0816F214
	cmp r1, #0x17
	bne _0816F218
_0816F214:
	movs r0, #1
	strb r0, [r5, #7]
_0816F218:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	ldr r6, _0816F240 @ =0x000004B7
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	b _0816F2AE
	.align 2, 0
_0816F22C: .4byte 0x000007DC
_0816F230: .4byte 0x000001DF
_0816F234: .4byte 0x0000025D
_0816F238: .4byte 0x0000D637
_0816F23C: .4byte 0x000029FB
_0816F240: .4byte 0x000004B7
_0816F244:
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
	ldr r2, _0816F32C @ =0x05000002
	bl CpuSet
	ldr r0, _0816F330 @ =0x0000CB05
	ldr r1, _0816F334 @ =0x0000D637
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
	ldr r0, _0816F338 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _0816F33C @ =0x000001DF
	adds r2, r7, r2
	str r2, [sp, #0x120]
	str r1, [sp, #0x8c]
_0816F2AE:
	str r7, [sp, #0x30]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0
	str r4, [r3]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	str r4, [r5]
	ldr r6, _0816F340 @ =0x0000046F
	adds r0, r7, r6
	strb r4, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	mov sl, r2
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, _0816F344 @ =0x00000474
	adds r6, r7, r3
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0816F32C @ =0x05000002
	bl CpuSet
	ldr r4, _0816F348 @ =0x000004B6
	adds r2, r7, r4
	mov r0, sl
	strb r0, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x90]
	mov r3, r8
	str r3, [sp, #0x98]
	str r6, [sp, #0x5c]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _0816F31A
	b _0816F47C
_0816F31A:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F34C
	bl VM_GetValue
	adds r1, r0, #0
	b _0816F34E
	.align 2, 0
_0816F32C: .4byte 0x05000002
_0816F330: .4byte 0x0000CB05
_0816F334: .4byte 0x0000D637
_0816F338: .4byte 0x000004B7
_0816F33C: .4byte 0x000001DF
_0816F340: .4byte 0x0000046F
_0816F344: .4byte 0x00000474
_0816F348: .4byte 0x000004B6
_0816F34C:
	movs r1, #0
_0816F34E:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0816F374 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x198]
	str r4, [sp, #0x19c]
	cmp r0, #0
	beq _0816F378
	bl VM_GetValue
	adds r1, r0, #0
	b _0816F37A
	.align 2, 0
_0816F374: .4byte 0x00000251
_0816F378:
	movs r1, #0
_0816F37A:
	ldr r2, _0816F3B0 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0816F3B4 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x198]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x1a0]
	cmp r0, #0
	beq _0816F3B8
	bl VM_GetValue
	b _0816F3BC
	.align 2, 0
_0816F3B0: .4byte 0x00000252
_0816F3B4: .4byte 0x000004B4
_0816F3B8:
	ldr r4, [sp, #0x198]
	ldrb r0, [r4]
_0816F3BC:
	strb r0, [r6]
	ldr r5, [sp, #0x198]
	ldrb r1, [r5]
	ldr r6, [sp, #0x1a0]
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
	blt _0816F3F4
	cmp r1, #0
	blt _0816F3F4
	ldr r0, _0816F3F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816F3F4
	ldr r0, _0816F3FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816F400
_0816F3F4:
	movs r1, #0
	b _0816F40E
	.align 2, 0
_0816F3F8: .4byte 0x030046A8
_0816F3FC: .4byte 0x030046AC
_0816F400:
	ldr r0, _0816F428 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0816F40E:
	ldr r2, _0816F42C @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816F430
	adds r0, #4
	b _0816F43C
	.align 2, 0
_0816F428: .4byte 0x030046A4
_0816F42C: .4byte 0x00000256
_0816F430:
	ldr r0, _0816F450 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816F43C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816F454
	cmp r2, #2
	beq _0816F458
	b _0816F45C
	.align 2, 0
_0816F450: .4byte 0x030046A4
_0816F454:
	ldrb r0, [r4, #4]
	b _0816F45A
_0816F458:
	ldrb r0, [r4]
_0816F45A:
	subs r1, r1, r0
_0816F45C:
	ldr r3, _0816F474 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0816F478 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x34]
	b _0816F4BC
	.align 2, 0
_0816F474: .4byte 0x00000472
_0816F478: .4byte 0x0000FFFF
_0816F47C:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0816F4E0 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0816F4E4 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0816F4E8 @ =0x000004B4
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
	str r0, [sp, #0x34]
	str r5, [sp, #0x198]
	str r4, [sp, #0x19c]
	str r3, [sp, #0x1a0]
_0816F4BC:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816F506
	bl VM_GetPC
	cmp r0, #0
	beq _0816F4EC
	bl VM_GetValue
	adds r4, r0, #0
	b _0816F4EE
	.align 2, 0
_0816F4E0: .4byte 0x00000251
_0816F4E4: .4byte 0x00000252
_0816F4E8: .4byte 0x000004B4
_0816F4EC:
	movs r4, #0x30
_0816F4EE:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F500
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0816F502
_0816F500:
	movs r5, #0x40
_0816F502:
	mov r8, r4
	b _0816F50C
_0816F506:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0816F50C:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816F544
	bl VM_GetPC
	cmp r0, #0
	beq _0816F526
	bl VM_GetValue
	adds r6, r0, #0
	b _0816F528
_0816F526:
	movs r6, #0
_0816F528:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F538
	bl VM_GetValue
	adds r1, r0, #0
	b _0816F53A
_0816F538:
	movs r1, #0
_0816F53A:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0816F54E
_0816F544:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0816F54E:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0816F7E0 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x1b0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x1a4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x10c]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x118]
	lsls r6, r6, #0x10
	str r6, [sp, #0x124]
	lsls r5, r5, #0x10
	str r5, [sp, #0x114]
	ldr r4, _0816F7E4 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x1ac]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x100]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x44]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x130]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x58]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x64]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x3c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _0816F7E8 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _0816F7EC @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _0816F7F0 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _0816F7F4 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x60]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r6, _0816F7F8 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x88]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x108]
	ldr r6, _0816F7FC @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x110]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _0816F800 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x140]
	ldr r3, _0816F804 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x148]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	ldr r5, _0816F808 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _0816F80C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _0816F810 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _0816F814 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x180]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x184]
	ldr r5, _0816F818 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _0816F81C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x188]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0816F820 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x160]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x174]
	ldr r4, _0816F824 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _0816F828 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x194]
	ldr r2, _0816F82C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _0816F830 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	ldr r2, _0816F834 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a8]
	ldr r3, _0816F838 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xec]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1b4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0816F83C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0816F840 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	ldr r3, _0816F844 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _0816F848 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x94]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r1, _0816F84C @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _0816F850 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	ldr r4, _0816F854 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x50]
	ldr r5, _0816F858 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x104]
	mov r3, sp
	adds r3, #0x24
	str r3, [sp, #0x38]
	mov r4, sp
	adds r4, #0x28
	str r4, [sp, #0x40]
	ldr r5, _0816F85C @ =0x0000046E
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _0816F860 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	ldr r3, _0816F864 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xa8]
	ldr r5, _0816F868 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xb4]
	ldr r6, _0816F86C @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r1, _0816F870 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	ldr r2, _0816F874 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	ldr r4, _0816F878 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xcc]
	cmp r0, #0
	bne _0816F7B0
	b _0816F8D4
_0816F7B0:
	movs r5, #0
	mov sl, r5
	movs r6, #0x8d
	lsls r6, r6, #2
	adds r6, r6, r7
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r7, r2
_0816F7D0:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F87C
	bl VM_GetValue
	b _0816F87E
	.align 2, 0
_0816F7E0: .4byte 0x0000025D
_0816F7E4: .4byte 0x0000025A
_0816F7E8: .4byte 0x0000047A
_0816F7EC: .4byte 0x0000047C
_0816F7F0: .4byte 0x0000047E
_0816F7F4: .4byte 0x00000476
_0816F7F8: .4byte 0x000004A4
_0816F7FC: .4byte 0x000005A4
_0816F800: .4byte 0x000005C4
_0816F804: .4byte 0x000005CC
_0816F808: .4byte 0x000005D4
_0816F80C: .4byte 0x000005DC
_0816F810: .4byte 0x00000584
_0816F814: .4byte 0x00000604
_0816F818: .4byte 0x0000021D
_0816F81C: .4byte 0x0000060C
_0816F820: .4byte 0x000005E4
_0816F824: .4byte 0x000005FC
_0816F828: .4byte 0x00000614
_0816F82C: .4byte 0x000005BC
_0816F830: .4byte 0x000005EC
_0816F834: .4byte 0x00000624
_0816F838: .4byte 0x0000058C
_0816F83C: .4byte 0x00000594
_0816F840: .4byte 0x0000059C
_0816F844: .4byte 0x000005B4
_0816F848: .4byte 0x00000543
_0816F84C: .4byte 0x00000496
_0816F850: .4byte 0x00000469
_0816F854: .4byte 0x0000046A
_0816F858: .4byte 0x00000553
_0816F85C: .4byte 0x0000046E
_0816F860: .4byte 0x00000572
_0816F864: .4byte 0x0000055C
_0816F868: .4byte 0x00000564
_0816F86C: .4byte 0x00000565
_0816F870: .4byte 0x00000566
_0816F874: .4byte 0x00000567
_0816F878: .4byte 0x0000056C
_0816F87C:
	movs r0, #0x18
_0816F87E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0816F890
	bl VM_GetValue
	b _0816F892
_0816F890:
	movs r0, #0x18
_0816F892:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8A4
	bl VM_GetValue
	b _0816F8A6
_0816F8A4:
	movs r0, #0
_0816F8A6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8B8
	bl VM_GetValue
	b _0816F8BA
_0816F8B8:
	movs r0, #0
_0816F8BA:
	strh r0, [r6]
	movs r3, #2
	add sb, r3
	movs r6, #4
	add r8, r6
	adds r5, #2
	adds r4, #2
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _0816F8D4
	b _0816F7D0
_0816F8D4:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816F920
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8EE
	bl VM_GetValue
	adds r4, r0, #0
	b _0816F8F2
_0816F8EE:
	movs r4, #0x96
	lsls r4, r4, #1
_0816F8F2:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F902
	bl VM_GetValue
	adds r6, r0, #0
	b _0816F906
_0816F902:
	movs r6, #0x96
	lsls r6, r6, #1
_0816F906:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F914
	bl VM_GetValue
	b _0816F91A
_0816F914:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0816F91A:
	ldr r3, [sp, #0x190]
	strh r0, [r3]
	b _0816F928
_0816F920:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x190]
	strh r6, [r5]
_0816F928:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0816F940
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0816F940:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0xac]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0xa4]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816FA10
	bl VM_GetPC
	cmp r0, #0
	beq _0816F970
	bl VM_GetValue
	b _0816F972
_0816F970:
	movs r0, #0
_0816F972:
	ldr r1, [sp, #0x1a4]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0816F980
	asrs r1, r0, #1
	b _0816F986
_0816F980:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0816F986:
	ldr r2, _0816F99C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9A0
	bl VM_GetValue
	b _0816F9A2
	.align 2, 0
_0816F99C: .4byte 0x00000546
_0816F9A0:
	movs r0, #0
_0816F9A2:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9B8
	bl VM_GetValue
	b _0816F9BA
_0816F9B8:
	movs r0, #0
_0816F9BA:
	ldr r5, _0816F9D0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9D4
	bl VM_GetValue
	adds r1, r0, #0
	b _0816F9D6
	.align 2, 0
_0816F9D0: .4byte 0x00000187
_0816F9D4:
	movs r1, #0
_0816F9D6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9EC
	bl VM_GetValue
	b _0816F9EE
_0816F9EC:
	movs r0, #0
_0816F9EE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA06
	bl VM_GetValue
	adds r1, r0, #0
	b _0816FA08
_0816FA06:
	movs r1, #0
_0816FA08:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0816FA10:
	ldr r0, [sp, #0x1a4]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0x10c]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x118]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x124]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x114]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816FA72
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA58
	bl VM_GetValue
	b _0816FA5A
_0816FA58:
	movs r0, #0
_0816FA5A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA6A
	bl VM_GetValue
	b _0816FA6C
_0816FA6A:
	movs r0, #0
_0816FA6C:
	ldr r2, _0816FAD4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0816FA72:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x1ac]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0816FA96
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x98]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0816FA96:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0816FAAE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0816FAAE:
	ldr r6, [sp, #0x100]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x30]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816FAD8
	movs r0, #1
	b _0816FADA
	.align 2, 0
_0816FAD4: .4byte 0x00000189
_0816FAD8:
	movs r0, #0
_0816FADA:
	cmp r0, #0
	beq _0816FAEA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0816FB14 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x30]
	bl CWolfTargetManager_Register
_0816FAEA:
	ldr r3, [sp, #0x1b0]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0816FAF6
	ldr r1, [r7, #0x44]
_0816FAF6:
	ldr r0, [sp, #0x30]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0816FB18
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x44]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _0816FB24
	.align 2, 0
_0816FB14: .4byte Enemy_OnCWolfMessage
_0816FB18:
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x44]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_0816FB24:
	ldr r5, [sp, #0x120]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816FB72
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0816FB72
	cmp r0, #0x16
	beq _0816FB72
	cmp r0, #0x14
	beq _0816FB72
	cmp r0, #9
	beq _0816FB72
	cmp r0, #0x19
	beq _0816FB72
	cmp r0, #0x1a
	beq _0816FB72
	cmp r0, #0xd
	beq _0816FB72
	cmp r0, #0x1b
	beq _0816FB72
	cmp r0, #0x1f
	beq _0816FB72
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x198]
	ldrb r2, [r6]
	ldr r0, [sp, #0x19c]
	ldrb r3, [r0]
	ldr r4, [sp, #0x1a0]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x30]
	bl Mover_SetPath
_0816FB72:
	movs r1, #8
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816FB82
	movs r0, #1
	b _0816FB84
_0816FB82:
	movs r0, #0
_0816FB84:
	cmp r0, #0
	beq _0816FB92
	ldr r6, [sp, #0x130]
	ldr r0, [r6]
	ldr r1, [sp, #0x128]
	str r0, [r1]
	b _0816FBA4
_0816FB92:
	ldr r2, [sp, #0x130]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x128]
	str r0, [r3]
_0816FBA4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	ldr r5, [sp, #0x3c]
	ldr r6, [sp, #0x64]
	str r5, [r6]
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq _0816FBCE
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
	ldr r1, [sp, #0x30]
	strb r0, [r1, #5]
_0816FBCE:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816FCB0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FBE6
	bl VM_GetValue
	b _0816FBE8
_0816FBE6:
	movs r0, #0
_0816FBE8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FBF8
	bl VM_GetValue
	b _0816FBFA
_0816FBF8:
	movs r0, #0
_0816FBFA:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FC0A
	bl VM_GetValue
	b _0816FC0C
_0816FC0A:
	movs r0, #0
_0816FC0C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0816FC34
	cmp r1, #0
	blt _0816FC34
	ldr r0, _0816FC38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816FC34
	ldr r0, _0816FC3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816FC40
_0816FC34:
	movs r1, #0
	b _0816FC4E
	.align 2, 0
_0816FC38: .4byte 0x030046A8
_0816FC3C: .4byte 0x030046AC
_0816FC40:
	ldr r0, _0816FC68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0816FC4E:
	ldr r4, _0816FC6C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816FC70
	adds r0, #4
	b _0816FC7C
	.align 2, 0
_0816FC68: .4byte 0x030046A4
_0816FC6C: .4byte 0x00000256
_0816FC70:
	ldr r0, _0816FC90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816FC7C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816FC94
	cmp r2, #2
	beq _0816FC98
	b _0816FC9C
	.align 2, 0
_0816FC90: .4byte 0x030046A4
_0816FC94:
	ldrb r0, [r5, #4]
	b _0816FC9A
_0816FC98:
	ldrb r0, [r5]
_0816FC9A:
	subs r1, r1, r0
_0816FC9C:
	ldr r5, _0816FCAC @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x2c]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	b _0816FCBE
	.align 2, 0
_0816FCAC: .4byte 0x00000472
_0816FCB0:
	ldr r3, _0816FCF0 @ =0x00000472
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x2c]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r0, r4, r5
_0816FCBE:
	strh r1, [r0]
	ldr r6, [sp, #0x2c]
	movs r0, #0x89
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, _0816FCF4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816FD44
	bl VM_GetPC
	cmp r0, #0
	beq _0816FCF8
	bl VM_GetValue
	adds r1, r0, #0
	b _0816FCFA
	.align 2, 0
_0816FCF0: .4byte 0x00000472
_0816FCF4: .4byte 0x03002BE0
_0816FCF8:
	movs r1, #0
_0816FCFA:
	ldr r2, [sp, #0x2c]
	ldr r3, _0816FD14 @ =0x000007E4
	adds r0, r2, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD18
	bl VM_GetValue
	adds r1, r0, #0
	b _0816FD1A
	.align 2, 0
_0816FD14: .4byte 0x000007E4
_0816FD18:
	movs r1, #0
_0816FD1A:
	ldr r4, [sp, #0x2c]
	ldr r5, _0816FD34 @ =0x000007E5
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD38
	bl VM_GetValue
	adds r1, r0, #0
	b _0816FD3A
	.align 2, 0
_0816FD34: .4byte 0x000007E5
_0816FD38:
	movs r1, #0
_0816FD3A:
	ldr r6, [sp, #0x2c]
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r6, r2
	strb r1, [r0]
_0816FD44:
	movs r0, #0x67
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0816FD60
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, [sp, #0x2c]
	ldr r4, _0816FD7C @ =0x000007DC
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816FD60:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0816FDBC
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD80
	bl VM_GetValue
	adds r1, r0, #0
	b _0816FD82
	.align 2, 0
_0816FD7C: .4byte 0x000007DC
_0816FD80:
	movs r1, #0
_0816FD82:
	ldr r5, [sp, #0x2c]
	ldr r6, _0816FD9C @ =0x00000844
	adds r0, r5, r6
	strh r1, [r0]
	ldr r0, _0816FDA0 @ =0x00000848
	adds r4, r5, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FDA4
	bl VM_GetValue
	b _0816FDA6
	.align 2, 0
_0816FD9C: .4byte 0x00000844
_0816FDA0: .4byte 0x00000848
_0816FDA4:
	movs r0, #0
_0816FDA6:
	str r0, [r4]
	ldr r1, [sp, #0x2c]
	ldr r2, _0816FDB8 @ =0x00000848
	adds r0, r1, r2
	ldr r1, [r0]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	b _0816FDC8
	.align 2, 0
_0816FDB8: .4byte 0x00000848
_0816FDBC:
	ldr r4, [sp, #0x2c]
	ldr r5, _0816FE24 @ =0x00000844
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _0816FE28 @ =0x00000848
	adds r0, r4, r6
_0816FDC8:
	str r1, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0816FDE6
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r0, [sp, #0x2c]
	ldr r3, _0816FE2C @ =0x000007DC
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816FDE6:
	ldr r4, _0816FE30 @ =0x0000017D
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x78]
	strh r0, [r6]
	ldr r0, [sp, #0x6c]
	strh r4, [r0]
	ldr r1, [sp, #0x70]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x74]
	strh r0, [r2]
	ldr r3, [sp, #0x6c]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x1b0]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0816FE34
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0816FE40
	.align 2, 0
_0816FE24: .4byte 0x00000844
_0816FE28: .4byte 0x00000848
_0816FE2C: .4byte 0x000007DC
_0816FE30: .4byte 0x0000017D
_0816FE34:
	ldr r2, [r7, #0x44]
	ldr r0, _0816FE78 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0816FE40:
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #1
	bne _0816FE90
	ldr r6, [sp, #0x120]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0816FE7C
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
	b _0816FE86
	.align 2, 0
_0816FE78: .4byte 0x03003584
_0816FE7C:
	ldr r1, [sp, #0x120]
	ldrb r0, [r1]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0816FE86:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0816FE90:
	ldr r2, [sp, #0x6c]
	ldrh r0, [r2]
	ldr r3, [sp, #0x60]
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #2
	ldr r4, [sp, #0x68]
	strh r0, [r4]
	ldr r5, _0816FED4 @ =0x0000047E
	adds r1, r7, r5
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x55
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0816FF60
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, _0816FED8 @ =0x000007DC
	adds r0, r3, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816FEDC
	movs r0, #1
	b _0816FEDE
	.align 2, 0
_0816FED4: .4byte 0x0000047E
_0816FED8: .4byte 0x000007DC
_0816FEDC:
	movs r0, #0
_0816FEDE:
	cmp r0, #0
	beq _0816FF04
	movs r1, #0x20
	ldr r0, _0816FEF8 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0816FEFC @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816FF00
	movs r0, #1
	b _0816FF10
	.align 2, 0
_0816FEF8: .4byte 0x030046A0
_0816FEFC: .4byte 0x00000934
_0816FF00:
	movs r0, #0
	b _0816FF10
_0816FF04:
	ldr r0, _0816FF30 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0816FF34 @ =0x00000942
	adds r0, r0, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
_0816FF10:
	cmp r0, #0
	ble _0816FF40
	movs r2, #0x40
	ldr r0, _0816FF38 @ =0x000007DC
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0816FF3C @ =0x00000836
	adds r1, r3, r2
	b _0816FF5C
	.align 2, 0
_0816FF30: .4byte 0x030046A0
_0816FF34: .4byte 0x00000942
_0816FF38: .4byte 0x000007DC
_0816FF3C: .4byte 0x00000836
_0816FF40:
	movs r2, #0x20
	ldr r4, _081700F8 @ =0x000007DC
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r5, _081700FC @ =0x00000836
	adds r1, r3, r5
_0816FF5C:
	movs r0, #0
	strh r0, [r1]
_0816FF60:
	adds r0, r7, #0
	bl Ghost_InitHitboxes
	ldr r6, [sp, #0x2c]
	ldr r0, _08170100 @ =0x0000084C
	adds r4, r6, r0
	movs r1, #0x87
	lsls r1, r1, #4
	adds r5, r6, r1
	ldr r2, _08170104 @ =Ghost_UpdateFrame
	str r2, [sp, #0x1c0]
	ldr r3, _08170108 @ =Ghost_GetMoveSpeed
	mov r8, r3
	ldr r6, _0817010C @ =Ghost_StateTurn
	mov sb, r6
	ldr r0, _08170110 @ =Ghost_StateFly
	mov sl, r0
	ldr r1, _08170114 @ =Ghost_StateWait
	mov ip, r1
	movs r2, #0
	ldr r3, _08170118 @ =FUN_080f62b0
	ldr r6, _0817011C @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x90]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x84]
	str r4, [r0]
	ldr r1, [sp, #0x88]
	str r5, [r1]
	ldr r4, [sp, #0x1c0]
	ldr r5, [sp, #0xdc]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xf0]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x108]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r4, [sp, #0x13c]
	str r2, [r4]
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _08170120 @ =Ghost_StateDamaged
	ldr r0, [sp, #0x148]
	str r6, [r0]
	ldr r1, _08170124 @ =Ghost_StateDying
	ldr r3, [sp, #0x14c]
	str r1, [r3]
	ldr r0, _08170128 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r0, [r4]
	ldr r0, _0817012C @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r0, [r5]
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r0, [sp, #0xe0]
	str r2, [r0]
	ldr r1, [sp, #0x1b8]
	ldr r3, [sp, #0x180]
	str r1, [r3]
	ldr r0, _08170130 @ =FUN_080f0430
	ldr r4, [sp, #0x184]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0x164]
	strb r6, [r5]
	ldr r0, _08170134 @ =0x085AD470
	ldr r1, [sp, #0x188]
	str r0, [r1]
	ldr r0, _08170138 @ =FUN_080e73c8
	ldr r3, [sp, #0x170]
	str r0, [r3]
	ldr r4, [sp, #0x160]
	str r2, [r4]
	ldr r5, [sp, #0x174]
	str r2, [r5]
	ldr r6, [sp, #0x178]
	str r2, [r6]
	ldr r0, [sp, #0x17c]
	str r2, [r0]
	ldr r1, [sp, #0x18c]
	str r2, [r1]
	ldr r0, _0817013C @ =FUN_080f0320
	ldr r3, [sp, #0x194]
	str r0, [r3]
	ldr r0, _08170140 @ =Enemy_080eff14
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r0, _08170144 @ =FUN_080e72b0
	ldr r5, [sp, #0x168]
	str r0, [r5]
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r0, _08170148 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x16c]
	str r0, [r1]
	ldr r0, _0817014C @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x154]
	str r0, [r3]
	ldr r4, [sp, #0x11c]
	str r2, [r4]
	ldr r0, _08170150 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a8]
	str r0, [r5]
	ldr r0, _08170154 @ =Enemy_OnDamaged
	ldr r6, [sp, #0xec]
	str r0, [r6]
	ldr r0, _08170158 @ =FUN_080f84d4
	ldr r1, [sp, #0x1b4]
	str r0, [r1]
	ldr r0, _0817015C @ =FUN_080f624c
	ldr r3, [sp, #0x134]
	str r0, [r3]
	ldr r0, _08170160 @ =FUN_080f56ec
	ldr r4, [sp, #0xf4]
	str r0, [r4]
	ldr r0, _08170164 @ =FUN_080f5b34
	ldr r5, [sp, #0xf8]
	str r0, [r5]
	ldr r0, _08170168 @ =FUN_080f5fac
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r0, [sp, #0x12c]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x94]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0817016C @ =Ghost_OnReset
	str r0, [r1]
	ldr r4, _08170170 @ =0x000005FC
	adds r0, r7, r4
	str r2, [r0]
	ldr r5, _08170174 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _08170178 @ =Ghost_OnAttackRequest
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0817017C @ =Ghost_TryDetectPlayer
	str r0, [r1]
	ldr r2, _08170180 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08170184 @ =0x085ADAC4
	str r0, [r1]
	movs r0, #0x20
	ldr r3, [sp, #0x5c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x90]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _08170188 @ =0x02100400
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0xb0]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08170196
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_081700EA:
	bl VM_GetPC
	cmp r0, #0
	beq _0817018C
	bl VM_GetValue
	b _0817018E
	.align 2, 0
_081700F8: .4byte 0x000007DC
_081700FC: .4byte 0x00000836
_08170100: .4byte 0x0000084C
_08170104: .4byte Ghost_UpdateFrame
_08170108: .4byte Ghost_GetMoveSpeed
_0817010C: .4byte Ghost_StateTurn
_08170110: .4byte Ghost_StateFly
_08170114: .4byte Ghost_StateWait
_08170118: .4byte FUN_080f62b0
_0817011C: .4byte FUN_080f62ac
_08170120: .4byte Ghost_StateDamaged
_08170124: .4byte Ghost_StateDying
_08170128: .4byte FUN_080f44f4
_0817012C: .4byte FUN_080f410c
_08170130: .4byte FUN_080f0430
_08170134: .4byte 0x085AD470
_08170138: .4byte FUN_080e73c8
_0817013C: .4byte FUN_080f0320
_08170140: .4byte Enemy_080eff14
_08170144: .4byte FUN_080e72b0
_08170148: .4byte Enemy_StateBlownAway
_0817014C: .4byte Enemy_StateFallDeath
_08170150: .4byte FUN_080f6e64
_08170154: .4byte Enemy_OnDamaged
_08170158: .4byte FUN_080f84d4
_0817015C: .4byte FUN_080f624c
_08170160: .4byte FUN_080f56ec
_08170164: .4byte FUN_080f5b34
_08170168: .4byte FUN_080f5fac
_0817016C: .4byte Ghost_OnReset
_08170170: .4byte 0x000005FC
_08170174: .4byte 0x000005AC
_08170178: .4byte Ghost_OnAttackRequest
_0817017C: .4byte Ghost_TryDetectPlayer
_08170180: .4byte 0x0000060C
_08170184: .4byte 0x085ADAC4
_08170188: .4byte 0x02100400
_0817018C:
	movs r0, #0
_0817018E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081700EA
_08170196:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xb8]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x80]
	strh r0, [r3]
	cmp r2, #0
	beq _081701CE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x90]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081701CE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081701CE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081701E0
	movs r0, #1
	b _081701E2
_081701E0:
	movs r0, #0
_081701E2:
	cmp r0, #0
	beq _081701F4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x98]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081701F4:
	cmp r2, #1
	beq _08170234
	movs r1, #0
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	ldr r4, _08170244 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08170248 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x110]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x9c]
	strb r1, [r6]
	ldr r0, [sp, #0xd8]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08170234:
	movs r1, #2
	ldr r3, [sp, #0x5c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0817024C
	movs r0, #1
	b _0817024E
	.align 2, 0
_08170244: .4byte 0x00000484
_08170248: .4byte 0x0000046C
_0817024C:
	movs r0, #0
_0817024E:
	cmp r0, #0
	beq _08170268
	ldr r0, _08170264 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	b _08170272
	.align 2, 0
_08170264: .4byte 0x030046A0
_08170268:
	ldr r0, [sp, #0x3c]
	bl GetZoneAt
	ldr r6, [sp, #0x7c]
	strh r0, [r6]
_08170272:
	movs r1, #0x40
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08170282
	movs r0, #1
	b _08170284
_08170282:
	movs r0, #0
_08170284:
	cmp r0, #0
	beq _08170294
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081702B8 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08170294:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081702C6
	ldr r0, _081702BC @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x7c]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081702C0
	movs r0, #1
	b _081702C2
	.align 2, 0
_081702B8: .4byte 0xFFFFFEFF
_081702BC: .4byte 0x030046A0
_081702C0:
	movs r0, #0
_081702C2:
	cmp r0, #0
	bne _081702CE
_081702C6:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_081702CE:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081703B6
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
	beq _08170310
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08170318
_08170310:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170318:
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
	beq _0817033C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08170344
_0817033C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08170344:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0817037C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081703C0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08170380
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08170374
	ldrb r0, [r4, #5]
_08170374:
	subs r0, #1
	strh r0, [r4, #8]
	b _08170390
	.align 2, 0
_0817037C: .4byte 0x0000FFFF
_08170380:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08170390
	strh r1, [r4, #8]
_08170390:
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
	bne _081703C0
	movs r0, #1
	strb r0, [r4, #7]
	b _081703C0
_081703B6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081703C0:
	movs r0, #0
	ldr r3, [sp, #0x104]
	str r0, [r3]
	ldr r0, _081703D8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081703DC
	movs r0, #1
	b _081703DE
	.align 2, 0
_081703D8: .4byte 0x030047A4
_081703DC:
	movs r0, #0
_081703DE:
	cmp r0, #0
	bne _0817041E
	ldr r4, [sp, #0x120]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08170406
	adds r0, r1, #0
	cmp r0, #7
	beq _08170406
	cmp r0, #6
	beq _08170406
	cmp r0, #0x15
	beq _08170406
	cmp r0, #0x14
	beq _08170406
	cmp r0, #0x17
	bne _0817041E
_08170406:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x5c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0817041E:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Ghost_SetHandlerTable2
	adds r0, r7, #0
	bl Ghost_SetHandlerTable4
	adds r0, r7, #0
	bl Ghost_SetHandlerTable3
	ldr r6, [sp, #0x2c]
	ldr r1, _08170488 @ =0x00000844
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08170448
	adds r0, r7, #0
	bl Ghost_SetHandlerTable8
_08170448:
	adds r0, r7, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r0, [r7, #5]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x40]
	bl Ghost_GetAnimVariant
	ldr r2, _0817048C @ =0x000004C4
	adds r0, r7, r2
	ldrb r2, [r0]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x28]
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08170490
	ldr r6, [sp, #0x8c]
	strb r2, [r6]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	b _08170500
	.align 2, 0
_08170488: .4byte 0x00000844
_0817048C: .4byte 0x000004C4
_08170490:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, [sp, #0x8c]
	ldrb r0, [r1]
	cmp r0, r2
	bne _081704C4
	ldr r3, [sp, #0x54]
	ldrb r0, [r3]
	cmp r0, #0
	bne _081704C4
	cmp r4, #1
	bne _081704B6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170506
_081704B6:
	cmp r4, #0
	bne _081704C4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170506
_081704C4:
	ldr r6, [sp, #0x8c]
	strb r2, [r6]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _081704D6
	movs r3, #6
_081704D6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081704F6
	ldr r0, [r5, #8]
	orrs r0, r6
	b _081704FE
_081704F6:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081704FE:
	str r0, [r5, #8]
_08170500:
	movs r0, #0
	ldr r1, [sp, #0x54]
	strb r0, [r1]
_08170506:
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	adds r0, r7, #0
	bl Ghost_InitAfterimages
	ldr r3, [sp, #0x5c]
	ldrh r0, [r3]
	ldr r4, [sp, #0xd4]
	strh r0, [r4]
	ldr r5, [sp, #0xe8]
	ldrh r0, [r5]
	ldr r6, [sp, #0xd0]
	strh r0, [r6]
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	ldr r2, [sp, #0xa0]
	str r0, [r2]
	ldr r3, [sp, #0x98]
	ldr r0, [r3]
	ldr r4, [sp, #0xa8]
	str r0, [r4]
	ldrb r0, [r7, #5]
	ldr r5, [sp, #0xb4]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	ldrb r0, [r6]
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc4]
	strb r0, [r5]
	ldr r6, [sp, #0xd8]
	ldr r0, [r6]
	ldr r1, [sp, #0xc8]
	str r0, [r1]
	ldr r2, [sp, #0x9c]
	ldrb r0, [r2]
	ldr r3, [sp, #0xcc]
	strb r0, [r3]
	ldr r4, _0817059C @ =0x00000574
	adds r1, r7, r4
	ldr r5, [sp, #0x2c]
	ldr r6, _081705A0 @ =0x000007DC
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _081705A4 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _081705A8 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r2, _081705AC @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081705B0 @ =Ghost_Update
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081705B4 @ =Ghost_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081705B8
	movs r0, #0
	b _081705BC
	.align 2, 0
_0817059C: .4byte 0x00000574
_081705A0: .4byte 0x000007DC
_081705A4: .4byte 0x0000057C
_081705A8: .4byte Enemy_DispatchMsg
_081705AC: .4byte 0x0000061C
_081705B0: .4byte Ghost_Update
_081705B4: .4byte Ghost_Destroy
_081705B8:
	movs r0, #1
	rsbs r0, r0, #0
_081705BC:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
