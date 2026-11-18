	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	ldr r1, _081B73B8 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	adds r0, r7, #0
	bl BokuLink_InitAnims
	adds r0, r7, #0
	bl BokuLink_InitDelayedScript
	ldr r2, _081B73BC @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B73CC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081B73C0 @ =0x00009247
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081B73C4 @ =0x00001DF8
	bl EnemyAuxSprite_LoadAnim
	ldr r3, _081B73C8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0xac]
	cmp r1, #0x11
	beq _081B73A8
	cmp r1, #0x17
	bne _081B73AC
_081B73A8:
	movs r0, #1
	strb r0, [r5, #7]
_081B73AC:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081B7434
	.align 2, 0
_081B73B8: .4byte 0x0000065C
_081B73BC: .4byte 0x0000025D
_081B73C0: .4byte 0x00009247
_081B73C4: .4byte 0x00001DF8
_081B73C8: .4byte 0x000001DF
_081B73CC:
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
	ldr r2, _081B74B0 @ =0x05000002
	bl CpuSet
	ldr r0, _081B74B4 @ =0x0000CB05
	ldr r1, _081B74B8 @ =0x00009247
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
	ldr r6, _081B74BC @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0xac]
_081B7434:
	str r7, [sp, #0x2c]
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
	ldr r3, _081B74C0 @ =0x0000046F
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
	ldr r1, _081B74C4 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081B74B0 @ =0x05000002
	bl CpuSet
	ldr r3, _081B74C8 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x6c]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _081B74A0
	b _081B75FC
_081B74A0:
	bl VM_GetPC
	cmp r0, #0
	beq _081B74CC
	bl VM_GetValue
	adds r1, r0, #0
	b _081B74CE
	.align 2, 0
_081B74B0: .4byte 0x05000002
_081B74B4: .4byte 0x0000CB05
_081B74B8: .4byte 0x00009247
_081B74BC: .4byte 0x000004B7
_081B74C0: .4byte 0x0000046F
_081B74C4: .4byte 0x00000474
_081B74C8: .4byte 0x000004B6
_081B74CC:
	movs r1, #0
_081B74CE:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081B74F4 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc8]
	str r4, [sp, #0xcc]
	cmp r0, #0
	beq _081B74F8
	bl VM_GetValue
	adds r1, r0, #0
	b _081B74FA
	.align 2, 0
_081B74F4: .4byte 0x00000251
_081B74F8:
	movs r1, #0
_081B74FA:
	ldr r2, _081B7530 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081B7534 @ =0x000004B4
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
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _081B7538
	bl VM_GetValue
	b _081B753C
	.align 2, 0
_081B7530: .4byte 0x00000252
_081B7534: .4byte 0x000004B4
_081B7538:
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
_081B753C:
	strb r0, [r6]
	ldr r5, [sp, #0xc8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd0]
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
	blt _081B7574
	cmp r1, #0
	blt _081B7574
	ldr r0, _081B7578 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B7574
	ldr r0, _081B757C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B7580
_081B7574:
	movs r1, #0
	b _081B758E
	.align 2, 0
_081B7578: .4byte 0x030046A8
_081B757C: .4byte 0x030046AC
_081B7580:
	ldr r0, _081B75A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081B758E:
	ldr r2, _081B75AC @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B75B0
	adds r0, #4
	b _081B75BC
	.align 2, 0
_081B75A8: .4byte 0x030046A4
_081B75AC: .4byte 0x00000256
_081B75B0:
	ldr r0, _081B75D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B75BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B75D4
	cmp r2, #2
	beq _081B75D8
	b _081B75DC
	.align 2, 0
_081B75D0: .4byte 0x030046A4
_081B75D4:
	ldrb r0, [r4, #4]
	b _081B75DA
_081B75D8:
	ldrb r0, [r4]
_081B75DA:
	subs r1, r1, r0
_081B75DC:
	ldr r3, _081B75F4 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081B75F8 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _081B763C
	.align 2, 0
_081B75F4: .4byte 0x00000472
_081B75F8: .4byte 0x0000FFFF
_081B75FC:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081B7660 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081B7664 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081B7668 @ =0x000004B4
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
	str r0, [sp, #0x30]
	str r5, [sp, #0xc8]
	str r4, [sp, #0xcc]
	str r3, [sp, #0xd0]
_081B763C:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B7686
	bl VM_GetPC
	cmp r0, #0
	beq _081B766C
	bl VM_GetValue
	adds r4, r0, #0
	b _081B766E
	.align 2, 0
_081B7660: .4byte 0x00000251
_081B7664: .4byte 0x00000252
_081B7668: .4byte 0x000004B4
_081B766C:
	movs r4, #0x30
_081B766E:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7680
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081B7682
_081B7680:
	movs r5, #0x40
_081B7682:
	mov r8, r4
	b _081B768C
_081B7686:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081B768C:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B76C4
	bl VM_GetPC
	cmp r0, #0
	beq _081B76A6
	bl VM_GetValue
	adds r6, r0, #0
	b _081B76A8
_081B76A6:
	movs r6, #0
_081B76A8:
	bl VM_GetPC
	cmp r0, #0
	beq _081B76B8
	bl VM_GetValue
	adds r1, r0, #0
	b _081B76BA
_081B76B8:
	movs r1, #0
_081B76BA:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081B76CE
_081B76C4:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081B76CE:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _081B7954 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc0]
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
	str r2, [sp, #0xd4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x98]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa4]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa8]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _081B7958 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x190]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r1, _081B795C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081B7960 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r3, _081B7964 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _081B7968 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x50]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _081B796C @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _081B7970 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _081B7974 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x148]
	ldr r3, _081B7978 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x150]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	ldr r5, _081B797C @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _081B7980 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	ldr r2, _081B7984 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x110]
	ldr r3, _081B7988 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x188]
	ldr r5, _081B798C @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xb8]
	ldr r6, _081B7990 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081B7994 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x168]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _081B7998 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x180]
	ldr r6, _081B799C @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _081B79A0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x140]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x164]
	ldr r5, _081B79A4 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x170]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081B79A8 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _081B79AC @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081B79B0 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x120]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x124]
	ldr r2, _081B79B4 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x128]
	ldr r3, _081B79B8 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x138]
	ldr r4, _081B79BC @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, [sp, #0x28]
	adds r5, #8
	str r5, [sp, #0x194]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _081B79C0 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081B79C4 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081B79C8 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081B79CC @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	ldr r4, _081B79D0 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x104]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _081B79D4 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _081B79D8 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xe8]
	ldr r4, _081B79DC @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _081B79E0 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081B79E4 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _081B79E8 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	cmp r0, #0
	bne _081B7924
	b _081B7A44
_081B7924:
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
_081B7944:
	bl VM_GetPC
	cmp r0, #0
	beq _081B79EC
	bl VM_GetValue
	b _081B79EE
	.align 2, 0
_081B7954: .4byte 0x0000025D
_081B7958: .4byte 0x0000025A
_081B795C: .4byte 0x0000047A
_081B7960: .4byte 0x0000047C
_081B7964: .4byte 0x0000047E
_081B7968: .4byte 0x00000476
_081B796C: .4byte 0x000004A4
_081B7970: .4byte 0x000005A4
_081B7974: .4byte 0x000005C4
_081B7978: .4byte 0x000005CC
_081B797C: .4byte 0x000005D4
_081B7980: .4byte 0x000005DC
_081B7984: .4byte 0x00000584
_081B7988: .4byte 0x00000604
_081B798C: .4byte 0x0000021D
_081B7990: .4byte 0x0000060C
_081B7994: .4byte 0x000005E4
_081B7998: .4byte 0x000005FC
_081B799C: .4byte 0x00000614
_081B79A0: .4byte 0x000005BC
_081B79A4: .4byte 0x000005EC
_081B79A8: .4byte 0x00000624
_081B79AC: .4byte 0x0000058C
_081B79B0: .4byte 0x00000594
_081B79B4: .4byte 0x0000059C
_081B79B8: .4byte 0x000005B4
_081B79BC: .4byte 0x00000543
_081B79C0: .4byte 0x00000496
_081B79C4: .4byte 0x00000469
_081B79C8: .4byte 0x0000046A
_081B79CC: .4byte 0x00000553
_081B79D0: .4byte 0x00000572
_081B79D4: .4byte 0x0000055C
_081B79D8: .4byte 0x00000564
_081B79DC: .4byte 0x00000565
_081B79E0: .4byte 0x00000566
_081B79E4: .4byte 0x00000567
_081B79E8: .4byte 0x0000056C
_081B79EC:
	movs r0, #0x18
_081B79EE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A00
	bl VM_GetValue
	b _081B7A02
_081B7A00:
	movs r0, #0x18
_081B7A02:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A14
	bl VM_GetValue
	b _081B7A16
_081B7A14:
	movs r0, #0
_081B7A16:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A28
	bl VM_GetValue
	b _081B7A2A
_081B7A28:
	movs r0, #0
_081B7A2A:
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
	bgt _081B7A44
	b _081B7944
_081B7A44:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B7A90
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A5E
	bl VM_GetValue
	adds r4, r0, #0
	b _081B7A62
_081B7A5E:
	movs r4, #0x96
	lsls r4, r4, #1
_081B7A62:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A72
	bl VM_GetValue
	adds r6, r0, #0
	b _081B7A76
_081B7A72:
	movs r6, #0x96
	lsls r6, r6, #1
_081B7A76:
	bl VM_GetPC
	cmp r0, #0
	beq _081B7A84
	bl VM_GetValue
	b _081B7A8A
_081B7A84:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081B7A8A:
	ldr r2, [sp, #0xc0]
	strh r0, [r2]
	b _081B7A98
_081B7A90:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc0]
	strh r6, [r3]
_081B7A98:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081B7AB0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081B7AB0:
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
	beq _081B7B80
	bl VM_GetPC
	cmp r0, #0
	beq _081B7AE0
	bl VM_GetValue
	b _081B7AE2
_081B7AE0:
	movs r0, #0
_081B7AE2:
	ldr r3, [sp, #0xd4]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081B7AF0
	asrs r1, r0, #1
	b _081B7AF6
_081B7AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081B7AF6:
	ldr r5, _081B7B0C @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B10
	bl VM_GetValue
	b _081B7B12
	.align 2, 0
_081B7B0C: .4byte 0x00000546
_081B7B10:
	movs r0, #0
_081B7B12:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B28
	bl VM_GetValue
	b _081B7B2A
_081B7B28:
	movs r0, #0
_081B7B2A:
	ldr r3, _081B7B40 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B44
	bl VM_GetValue
	adds r1, r0, #0
	b _081B7B46
	.align 2, 0
_081B7B40: .4byte 0x00000187
_081B7B44:
	movs r1, #0
_081B7B46:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B5C
	bl VM_GetValue
	b _081B7B5E
_081B7B5C:
	movs r0, #0
_081B7B5E:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7B76
	bl VM_GetValue
	adds r1, r0, #0
	b _081B7B78
_081B7B76:
	movs r1, #0
_081B7B78:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081B7B80:
	ldr r5, [sp, #0xd4]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0x98]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xa4]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa8]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x9c]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B7BE2
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081B7BC8
	bl VM_GetValue
	b _081B7BCA
_081B7BC8:
	movs r0, #0
_081B7BCA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7BDA
	bl VM_GetValue
	b _081B7BDC
_081B7BDA:
	movs r0, #0
_081B7BDC:
	ldr r6, _081B7C44 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081B7BE2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xdc]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081B7C06
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081B7C06:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081B7C1E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x6c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081B7C1E:
	ldr r4, [sp, #0x94]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081B7C48
	movs r0, #1
	b _081B7C4A
	.align 2, 0
_081B7C44: .4byte 0x00000189
_081B7C48:
	movs r0, #0
_081B7C4A:
	cmp r0, #0
	beq _081B7C5A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081B7C84 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x2c]
	bl CWolfTargetManager_Register
_081B7C5A:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081B7C66
	ldr r1, [r7, #0x44]
_081B7C66:
	ldr r0, [sp, #0x2c]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0xac]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081B7C88
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081B7C94
	.align 2, 0
_081B7C84: .4byte Enemy_OnCWolfMessage
_081B7C88:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081B7C94:
	ldr r2, [sp, #0xac]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081B7CE2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081B7CE2
	cmp r0, #0x16
	beq _081B7CE2
	cmp r0, #0x14
	beq _081B7CE2
	cmp r0, #9
	beq _081B7CE2
	cmp r0, #0x19
	beq _081B7CE2
	cmp r0, #0x1a
	beq _081B7CE2
	cmp r0, #0xd
	beq _081B7CE2
	cmp r0, #0x1b
	beq _081B7CE2
	cmp r0, #0x1f
	beq _081B7CE2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xcc]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd0]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl Mover_SetPath
_081B7CE2:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081B7CF2
	movs r0, #1
	b _081B7CF4
_081B7CF2:
	movs r0, #0
_081B7CF4:
	cmp r0, #0
	beq _081B7D02
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb0]
	str r0, [r2]
	b _081B7D14
_081B7D02:
	ldr r3, [sp, #0xb4]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb0]
	str r0, [r4]
_081B7D14:
	ldrh r0, [r7]
	ldr r5, [sp, #0x38]
	strh r0, [r5]
	ldr r6, [sp, #0x190]
	ldr r0, [sp, #0x3c]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _081B7D3E
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
	ldr r2, [sp, #0x2c]
	strb r0, [r2, #5]
_081B7D3E:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B7DA8
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D58
	bl VM_GetValue
	adds r1, r0, #0
	b _081B7D5A
_081B7D58:
	movs r1, #0x78
_081B7D5A:
	ldr r3, [sp, #0x24]
	ldr r4, _081B7D74 @ =0x00000674
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D78
	bl VM_GetValue
	adds r1, r0, #0
	b _081B7D7A
	.align 2, 0
_081B7D74: .4byte 0x00000674
_081B7D78:
	movs r1, #0x78
_081B7D7A:
	ldr r5, [sp, #0x24]
	ldr r6, _081B7D94 @ =0x0000067E
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B7D98
	bl VM_GetValue
	adds r1, r0, #0
	b _081B7D9A
	.align 2, 0
_081B7D94: .4byte 0x0000067E
_081B7D98:
	movs r1, #0x78
_081B7D9A:
	ldr r2, [sp, #0x24]
	ldr r3, _081B7DA4 @ =0x00000672
	adds r0, r2, r3
	b _081B7DB6
	.align 2, 0
_081B7DA4: .4byte 0x00000672
_081B7DA8:
	ldr r4, [sp, #0x24]
	ldr r5, _081B7DF4 @ =0x00000674
	adds r0, r4, r5
	movs r1, #0x78
	strb r1, [r0]
	ldr r6, _081B7DF8 @ =0x0000067E
	adds r0, r4, r6
_081B7DB6:
	strh r1, [r0]
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x68]
	strh r0, [r1]
	ldr r2, [sp, #0x58]
	strh r4, [r2]
	ldr r3, [sp, #0x5c]
	strh r4, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x64]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x68]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081B7DFC
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081B7E08
	.align 2, 0
_081B7DF4: .4byte 0x00000674
_081B7DF8: .4byte 0x0000067E
_081B7DFC:
	ldr r2, [r7, #0x44]
	ldr r0, _081B7E40 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081B7E08:
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081B7E58
	ldr r2, [sp, #0xac]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081B7E44
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
	b _081B7E4E
	.align 2, 0
_081B7E40: .4byte 0x03003584
_081B7E44:
	ldr r3, [sp, #0xac]
	ldrb r0, [r3]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081B7E4E:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081B7E58:
	movs r4, #0
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	adds r0, #4
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	ldrh r0, [r5]
	ldr r1, [sp, #0x54]
	strh r0, [r1]
	adds r0, r7, #0
	bl BokuLink_InitHitboxes
	ldr r2, [sp, #0x24]
	movs r3, #0xd0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r5, _081B8008 @ =0x000006A4
	adds r2, r2, r5
	mov r8, r2
	ldr r6, _081B800C @ =FUN_081b71e8
	mov sb, r6
	ldr r1, _081B8010 @ =BokuLink_GetMoveSpeed
	mov sl, r1
	ldr r2, _081B8014 @ =FUN_081af224
	mov ip, r2
	ldr r5, _081B8018 @ =BokuLink_StateDamaged
	ldr r3, _081B801C @ =FUN_080f62b0
	ldr r6, _081B8020 @ =FUN_080f62ac
	str r6, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x8c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x10c]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x114]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x11c]
	str r2, [r6]
	ldr r1, _081B8024 @ =FUN_081af1e8
	ldr r2, [sp, #0x12c]
	str r1, [r2]
	ldr r6, _081B8028 @ =FUN_081af200
	ldr r1, [sp, #0x130]
	str r6, [r1]
	ldr r2, _081B802C @ =BokuLink_StateNap
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r1, [sp, #0x148]
	str r3, [r1]
	ldr r2, [sp, #0x150]
	str r5, [r2]
	ldr r3, _081B8030 @ =BokuLink_StateDying
	ldr r5, [sp, #0x154]
	str r3, [r5]
	ldr r1, _081B8034 @ =FUN_080f44f4
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, _081B8038 @ =FUN_080f410c
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, _081B803C @ =FUN_081afd08
	ldr r5, [sp, #0x14c]
	str r3, [r5]
	ldr r6, _081B8040 @ =FUN_081af9a4
	ldr r1, [sp, #0x110]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x184]
	str r2, [r3]
	ldr r1, _081B8044 @ =FUN_080f0430
	ldr r5, [sp, #0x188]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r1, _081B8048 @ =0x085AD470
	ldr r2, [sp, #0x18c]
	str r1, [r2]
	ldr r1, _081B804C @ =FUN_080e73c8
	ldr r3, [sp, #0x174]
	str r1, [r3]
	ldr r5, [sp, #0x168]
	str r4, [r5]
	ldr r6, [sp, #0x178]
	str r4, [r6]
	ldr r1, [sp, #0x17c]
	str r4, [r1]
	ldr r2, [sp, #0x180]
	str r4, [r2]
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081B8050 @ =FUN_080f0320
	ldr r5, [sp, #0x19c]
	str r1, [r5]
	ldr r1, _081B8054 @ =Enemy_080eff14
	ldr r6, [sp, #0x140]
	str r1, [r6]
	ldr r1, _081B8058 @ =FUN_080e72b0
	ldr r2, [sp, #0x16c]
	str r1, [r2]
	ldr r3, _081B805C @ =FUN_081afcac
	ldr r5, [sp, #0x164]
	str r3, [r5]
	ldr r1, _081B8060 @ =Enemy_StateBlownAway
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r1, _081B8064 @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, [sp, #0x134]
	str r4, [r3]
	ldr r1, _081B8068 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a0]
	str r1, [r5]
	ldr r1, _081B806C @ =Enemy_OnDamaged
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081B8070 @ =FUN_080f84d4
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _081B8074 @ =FUN_080f624c
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r1, _081B8078 @ =FUN_080f56ec
	ldr r5, [sp, #0x120]
	str r1, [r5]
	ldr r1, _081B807C @ =FUN_080f5b34
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r1, _081B8080 @ =FUN_080f5fac
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0xbc]
	strb r1, [r4]
	ldr r1, [sp, #0x194]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081B8084 @ =BokuLink_OnReset
	str r0, [r1]
	ldr r6, _081B8088 @ =0x000005FC
	adds r1, r7, r6
	ldr r0, _081B808C @ =FUN_081b33e8
	str r0, [r1]
	ldr r0, _081B8090 @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _081B8094 @ =FUN_081b2ea8
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081B8098 @ =FUN_081b2f80
	str r0, [r1]
	ldr r3, _081B809C @ =0x0000058C
	adds r1, r7, r3
	ldr r0, _081B80A0 @ =BokuLink_OnDamaged
	str r0, [r1]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _081B80A4 @ =Enemy_TryHeadToSound
	str r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	ldr r6, _081B80A8 @ =0x000001DF
	adds r0, r7, r6
	movs r1, #4
	strb r1, [r0]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081B80B6
	movs r3, #0xce
	lsls r3, r3, #1
	adds r5, r7, r3
	movs r4, #4
_081B7FFA:
	bl VM_GetPC
	cmp r0, #0
	beq _081B80AC
	bl VM_GetValue
	b _081B80AE
	.align 2, 0
_081B8008: .4byte 0x000006A4
_081B800C: .4byte FUN_081b71e8
_081B8010: .4byte BokuLink_GetMoveSpeed
_081B8014: .4byte FUN_081af224
_081B8018: .4byte BokuLink_StateDamaged
_081B801C: .4byte FUN_080f62b0
_081B8020: .4byte FUN_080f62ac
_081B8024: .4byte FUN_081af1e8
_081B8028: .4byte FUN_081af200
_081B802C: .4byte BokuLink_StateNap
_081B8030: .4byte BokuLink_StateDying
_081B8034: .4byte FUN_080f44f4
_081B8038: .4byte FUN_080f410c
_081B803C: .4byte FUN_081afd08
_081B8040: .4byte FUN_081af9a4
_081B8044: .4byte FUN_080f0430
_081B8048: .4byte 0x085AD470
_081B804C: .4byte FUN_080e73c8
_081B8050: .4byte FUN_080f0320
_081B8054: .4byte Enemy_080eff14
_081B8058: .4byte FUN_080e72b0
_081B805C: .4byte FUN_081afcac
_081B8060: .4byte Enemy_StateBlownAway
_081B8064: .4byte Enemy_StateFallDeath
_081B8068: .4byte FUN_080f6e64
_081B806C: .4byte Enemy_OnDamaged
_081B8070: .4byte FUN_080f84d4
_081B8074: .4byte FUN_080f624c
_081B8078: .4byte FUN_080f56ec
_081B807C: .4byte FUN_080f5b34
_081B8080: .4byte FUN_080f5fac
_081B8084: .4byte BokuLink_OnReset
_081B8088: .4byte 0x000005FC
_081B808C: .4byte FUN_081b33e8
_081B8090: .4byte 0x000005AC
_081B8094: .4byte FUN_081b2ea8
_081B8098: .4byte FUN_081b2f80
_081B809C: .4byte 0x0000058C
_081B80A0: .4byte BokuLink_OnDamaged
_081B80A4: .4byte Enemy_TryHeadToSound
_081B80A8: .4byte 0x000001DF
_081B80AC:
	movs r0, #0
_081B80AE:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081B7FFA
_081B80B6:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0x84]
	strh r0, [r4]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r5, [sp, #0x74]
	strh r0, [r5]
	cmp r2, #0
	beq _081B80EE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	cmp r2, #2
	bne _081B80EE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r6]
_081B80EE:
	movs r2, #0
	movs r1, #4
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081B8100
	movs r0, #1
	b _081B8102
_081B8100:
	movs r0, #0
_081B8102:
	cmp r0, #0
	beq _081B8114
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #1
_081B8114:
	cmp r2, #1
	beq _081B8154
	movs r1, #0
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, _081B8164 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	ldr r3, _081B8168 @ =0x0000046C
	adds r0, r7, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x130]
	ldr r3, [r4]
	ldr r5, _081B816C @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081B8170 @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xc4]
	strb r1, [r0]
	ldr r2, [sp, #0x108]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081B8154:
	movs r1, #2
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B8174
	movs r0, #1
	b _081B8176
	.align 2, 0
_081B8164: .4byte 0x00000484
_081B8168: .4byte 0x0000046C
_081B816C: .4byte 0x0000046D
_081B8170: .4byte 0x0000046B
_081B8174:
	movs r0, #0
_081B8176:
	cmp r0, #0
	beq _081B8190
	ldr r0, _081B818C @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	b _081B819A
	.align 2, 0
_081B818C: .4byte 0x030046A0
_081B8190:
	ldr r0, [sp, #0x190]
	bl GetZoneAt
	ldr r1, [sp, #0x70]
	strh r0, [r1]
_081B819A:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B81AA
	movs r0, #1
	b _081B81AC
_081B81AA:
	movs r0, #0
_081B81AC:
	cmp r0, #0
	beq _081B81BC
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081B81E0 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081B81BC:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081B81EE
	ldr r0, _081B81E4 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x70]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081B81E8
	movs r0, #1
	b _081B81EA
	.align 2, 0
_081B81E0: .4byte 0xFFFFFEFF
_081B81E4: .4byte 0x030046A0
_081B81E8:
	movs r0, #0
_081B81EA:
	cmp r0, #0
	bne _081B81F6
_081B81EE:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_081B81F6:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xe4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081B82DE
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
	beq _081B8238
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081B8240
_081B8238:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081B8240:
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
	beq _081B8264
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081B826C
_081B8264:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081B826C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081B82A4 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081B82E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081B82A8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081B829C
	ldrb r0, [r4, #5]
_081B829C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081B82B8
	.align 2, 0
_081B82A4: .4byte 0x0000FFFF
_081B82A8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081B82B8
	strh r1, [r4, #8]
_081B82B8:
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
	bne _081B82E8
	movs r0, #1
	strb r0, [r4, #7]
	b _081B82E8
_081B82DE:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081B82E8:
	movs r0, #0
	ldr r3, [sp, #0xa0]
	str r0, [r3]
	ldr r0, _081B8300 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B8304
	movs r0, #1
	b _081B8306
	.align 2, 0
_081B8300: .4byte 0x030047A4
_081B8304:
	movs r0, #0
_081B8306:
	cmp r0, #0
	bne _081B8346
	ldr r4, [sp, #0xac]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081B832E
	adds r0, r1, #0
	cmp r0, #7
	beq _081B832E
	cmp r0, #6
	beq _081B832E
	cmp r0, #0x15
	beq _081B832E
	cmp r0, #0x14
	beq _081B832E
	cmp r0, #0x17
	bne _081B8346
_081B832E:
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
_081B8346:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_081b3fa0
	adds r0, r7, #0
	bl FUN_081b281c
	adds r0, r7, #0
	bl FUN_081b2e28
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ldr r1, [sp, #0x104]
	strh r0, [r1]
	ldr r2, [sp, #0x90]
	ldrh r0, [r2]
	ldr r3, [sp, #0x100]
	strh r0, [r3]
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	ldr r5, [sp, #0xd8]
	str r0, [r5]
	ldr r6, [sp, #0x6c]
	ldr r0, [r6]
	ldr r1, [sp, #0xe0]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xe8]
	strb r0, [r2]
	ldr r3, [sp, #0x40]
	ldrb r0, [r3]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0xf4]
	strb r0, [r2]
	ldr r3, [sp, #0x108]
	ldr r0, [r3]
	ldr r4, [sp, #0xf8]
	str r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xfc]
	strb r0, [r6]
	ldr r0, _081B83D8 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _081B83DC @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r2, _081B83E0 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081B83E4 @ =BokuLink_Update
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081B83E8 @ =BokuLink_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B83EC
	movs r0, #0
	b _081B83F0
	.align 2, 0
_081B83D8: .4byte 0x0000057C
_081B83DC: .4byte Enemy_DispatchMsg
_081B83E0: .4byte 0x0000061C
_081B83E4: .4byte BokuLink_Update
_081B83E8: .4byte BokuLink_Destroy
_081B83EC:
	movs r0, #1
	rsbs r0, r0, #0
_081B83F0:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
