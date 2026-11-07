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
	ldr r2, _08145600 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x13
	strb r0, [r1]
	adds r0, r7, #0
	bl Crow_InitAnims
	ldr r3, _08145604 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08145610
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08145608 @ =0x00005A6E
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0814560C @ =0x00007B03
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _08145600 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xa0]
	cmp r1, #0x11
	beq _081455EE
	cmp r1, #0x17
	bne _081455F2
_081455EE:
	movs r0, #1
	strb r0, [r5, #7]
_081455F2:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08145678
	.align 2, 0
_08145600: .4byte 0x000001DF
_08145604: .4byte 0x0000025D
_08145608: .4byte 0x00005A6E
_0814560C: .4byte 0x00007B03
_08145610:
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
	ldr r2, _081456F4 @ =0x05000002
	bl CpuSet
	ldr r0, _081456F8 @ =0x0000CB05
	ldr r1, _081456FC @ =0x00005A6E
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
	ldr r0, _08145700 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08145704 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xa0]
_08145678:
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
	ldr r5, _08145708 @ =0x0000046F
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
	ldr r1, _0814570C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081456F4 @ =0x05000002
	bl CpuSet
	ldr r3, _08145710 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x70]
	mov r3, r8
	str r3, [sp, #0x74]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _081456E4
	b _08145844
_081456E4:
	bl VM_GetPC
	cmp r0, #0
	beq _08145714
	bl VM_GetValue
	adds r1, r0, #0
	b _08145716
	.align 2, 0
_081456F4: .4byte 0x05000002
_081456F8: .4byte 0x0000CB05
_081456FC: .4byte 0x00005A6E
_08145700: .4byte 0x000004B7
_08145704: .4byte 0x000001DF
_08145708: .4byte 0x0000046F
_0814570C: .4byte 0x00000474
_08145710: .4byte 0x000004B6
_08145714:
	movs r1, #0
_08145716:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0814573C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x118]
	str r4, [sp, #0x11c]
	cmp r0, #0
	beq _08145740
	bl VM_GetValue
	adds r1, r0, #0
	b _08145742
	.align 2, 0
_0814573C: .4byte 0x00000251
_08145740:
	movs r1, #0
_08145742:
	ldr r2, _08145778 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0814577C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x118]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x120]
	cmp r0, #0
	beq _08145780
	bl VM_GetValue
	b _08145784
	.align 2, 0
_08145778: .4byte 0x00000252
_0814577C: .4byte 0x000004B4
_08145780:
	ldr r4, [sp, #0x118]
	ldrb r0, [r4]
_08145784:
	strb r0, [r6]
	ldr r5, [sp, #0x118]
	ldrb r1, [r5]
	ldr r6, [sp, #0x120]
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
	blt _081457BC
	cmp r1, #0
	blt _081457BC
	ldr r0, _081457C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081457BC
	ldr r0, _081457C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081457C8
_081457BC:
	movs r1, #0
	b _081457D6
	.align 2, 0
_081457C0: .4byte 0x030046A8
_081457C4: .4byte 0x030046AC
_081457C8:
	ldr r0, _081457F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081457D6:
	ldr r2, _081457F4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081457F8
	adds r0, #4
	b _08145804
	.align 2, 0
_081457F0: .4byte 0x030046A4
_081457F4: .4byte 0x00000256
_081457F8:
	ldr r0, _08145818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08145804:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814581C
	cmp r2, #2
	beq _08145820
	b _08145824
	.align 2, 0
_08145818: .4byte 0x030046A4
_0814581C:
	ldrb r0, [r4, #4]
	b _08145822
_08145820:
	ldrb r0, [r4]
_08145822:
	subs r1, r1, r0
_08145824:
	ldr r3, _0814583C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08145840 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08145884
	.align 2, 0
_0814583C: .4byte 0x00000472
_08145840: .4byte 0x0000FFFF
_08145844:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081458A8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081458AC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081458B0 @ =0x000004B4
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
	str r5, [sp, #0x118]
	str r4, [sp, #0x11c]
	str r3, [sp, #0x120]
_08145884:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081458CE
	bl VM_GetPC
	cmp r0, #0
	beq _081458B4
	bl VM_GetValue
	adds r4, r0, #0
	b _081458B6
	.align 2, 0
_081458A8: .4byte 0x00000251
_081458AC: .4byte 0x00000252
_081458B0: .4byte 0x000004B4
_081458B4:
	movs r4, #0x30
_081458B6:
	bl VM_GetPC
	cmp r0, #0
	beq _081458C8
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081458CA
_081458C8:
	movs r5, #0x40
_081458CA:
	mov r8, r4
	b _081458D4
_081458CE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081458D4:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0814590C
	bl VM_GetPC
	cmp r0, #0
	beq _081458EE
	bl VM_GetValue
	adds r6, r0, #0
	b _081458F0
_081458EE:
	movs r6, #0
_081458F0:
	bl VM_GetPC
	cmp r0, #0
	beq _08145900
	bl VM_GetValue
	adds r1, r0, #0
	b _08145902
_08145900:
	movs r1, #0
_08145902:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08145916
_0814590C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08145916:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08145B88 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x134]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x114]
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
	str r2, [sp, #0x124]
	lsls r4, r4, #0x10
	str r4, [sp, #0x94]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x9c]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa4]
	lsls r5, r5, #0x10
	str r5, [sp, #0x98]
	ldr r4, _08145B8C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _08145B90 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _08145B94 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _08145B98 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _08145B9C @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	ldr r4, _08145BA0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08145BA4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _08145BA8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x148]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08145BAC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _08145BB0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08145BB4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xec]
	ldr r1, _08145BB8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x180]
	ldr r3, _08145BBC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	ldr r4, _08145BC0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08145BC4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _08145BC8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08145BCC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08145BD0 @ =0x000005BC
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
	ldr r3, _08145BD4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x110]
	ldr r6, _08145BD8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x190]
	ldr r1, _08145BDC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x130]
	ldr r4, _08145BE0 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x100]
	ldr r6, _08145BE4 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _08145BE8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08145BEC @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x80]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x84]
	ldr r5, _08145BF0 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _08145BF4 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _08145BF8 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _08145BFC @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x90]
	ldr r1, _08145C00 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd8]
	ldr r4, _08145C04 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xb8]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	ldr r6, _08145C08 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xc0]
	ldr r1, _08145C0C @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xc4]
	ldr r2, _08145C10 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _08145C14 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	ldr r5, _08145C18 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	cmp r0, #0
	bne _08145B58
	b _08145C72
_08145B58:
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
_08145B78:
	bl VM_GetPC
	cmp r0, #0
	beq _08145C1C
	bl VM_GetValue
	b _08145C1E
	.align 2, 0
_08145B88: .4byte 0x0000025D
_08145B8C: .4byte 0x0000025A
_08145B90: .4byte 0x0000047A
_08145B94: .4byte 0x0000047C
_08145B98: .4byte 0x0000047E
_08145B9C: .4byte 0x000004A4
_08145BA0: .4byte 0x000005A4
_08145BA4: .4byte 0x000005C4
_08145BA8: .4byte 0x000005CC
_08145BAC: .4byte 0x000005D4
_08145BB0: .4byte 0x000005DC
_08145BB4: .4byte 0x00000584
_08145BB8: .4byte 0x00000604
_08145BBC: .4byte 0x0000021D
_08145BC0: .4byte 0x0000060C
_08145BC4: .4byte 0x000005E4
_08145BC8: .4byte 0x000005FC
_08145BCC: .4byte 0x00000614
_08145BD0: .4byte 0x000005BC
_08145BD4: .4byte 0x000005EC
_08145BD8: .4byte 0x00000624
_08145BDC: .4byte 0x0000058C
_08145BE0: .4byte 0x00000594
_08145BE4: .4byte 0x0000059C
_08145BE8: .4byte 0x000005B4
_08145BEC: .4byte 0x00000543
_08145BF0: .4byte 0x00000496
_08145BF4: .4byte 0x00000469
_08145BF8: .4byte 0x0000046A
_08145BFC: .4byte 0x00000553
_08145C00: .4byte 0x00000572
_08145C04: .4byte 0x0000055C
_08145C08: .4byte 0x00000564
_08145C0C: .4byte 0x00000565
_08145C10: .4byte 0x00000566
_08145C14: .4byte 0x00000567
_08145C18: .4byte 0x0000056C
_08145C1C:
	movs r0, #0x18
_08145C1E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08145C30
	bl VM_GetValue
	b _08145C32
_08145C30:
	movs r0, #0x18
_08145C32:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08145C44
	bl VM_GetValue
	b _08145C46
_08145C44:
	movs r0, #0
_08145C46:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08145C58
	bl VM_GetValue
	b _08145C5A
_08145C58:
	movs r0, #0
_08145C5A:
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
	ble _08145B78
_08145C72:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08145CBE
	bl VM_GetPC
	cmp r0, #0
	beq _08145C8C
	bl VM_GetValue
	adds r4, r0, #0
	b _08145C90
_08145C8C:
	movs r4, #0x96
	lsls r4, r4, #1
_08145C90:
	bl VM_GetPC
	cmp r0, #0
	beq _08145CA0
	bl VM_GetValue
	adds r6, r0, #0
	b _08145CA4
_08145CA0:
	movs r6, #0x96
	lsls r6, r6, #1
_08145CA4:
	bl VM_GetPC
	cmp r0, #0
	beq _08145CB2
	bl VM_GetValue
	b _08145CB8
_08145CB2:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_08145CB8:
	ldr r5, [sp, #0x114]
	strh r0, [r5]
	b _08145CC6
_08145CBE:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0x114]
	strh r6, [r0]
_08145CC6:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08145CDE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08145CDE:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08145DAC
	bl VM_GetPC
	cmp r0, #0
	beq _08145D0E
	bl VM_GetValue
	b _08145D10
_08145D0E:
	movs r0, #0
_08145D10:
	ldr r1, [sp, #0x124]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08145D1E
	asrs r1, r0, #1
	b _08145D24
_08145D1E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08145D24:
	ldr r2, _08145D38 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D3C
	bl VM_GetValue
	b _08145D3E
	.align 2, 0
_08145D38: .4byte 0x00000546
_08145D3C:
	movs r0, #0
_08145D3E:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D54
	bl VM_GetValue
	b _08145D56
_08145D54:
	movs r0, #0
_08145D56:
	ldr r5, _08145D6C @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D70
	bl VM_GetValue
	adds r1, r0, #0
	b _08145D72
	.align 2, 0
_08145D6C: .4byte 0x00000187
_08145D70:
	movs r1, #0
_08145D72:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D88
	bl VM_GetValue
	b _08145D8A
_08145D88:
	movs r0, #0
_08145D8A:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145DA2
	bl VM_GetValue
	adds r1, r0, #0
	b _08145DA4
_08145DA2:
	movs r1, #0
_08145DA4:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08145DAC:
	ldr r0, [sp, #0x124]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0x94]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x9c]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xa4]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x98]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08145E0E
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08145DF4
	bl VM_GetValue
	b _08145DF6
_08145DF4:
	movs r0, #0
_08145DF6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08145E06
	bl VM_GetValue
	b _08145E08
_08145E06:
	movs r0, #0
_08145E08:
	ldr r2, _08145E70 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08145E0E:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x12c]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08145E32
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x74]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08145E32:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08145E4A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08145E4A:
	ldr r6, [sp, #0x8c]
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
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08145E74
	movs r0, #1
	b _08145E76
	.align 2, 0
_08145E70: .4byte 0x00000189
_08145E74:
	movs r0, #0
_08145E76:
	cmp r0, #0
	beq _08145E86
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08145EB0 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_08145E86:
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08145E92
	ldr r1, [r7, #0x44]
_08145E92:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0xa0]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08145EB4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08145EC0
	.align 2, 0
_08145EB0: .4byte Enemy_OnCWolfMessage
_08145EB4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08145EC0:
	ldr r5, [sp, #0xa0]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08145F0E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08145F0E
	cmp r0, #0x16
	beq _08145F0E
	cmp r0, #0x14
	beq _08145F0E
	cmp r0, #9
	beq _08145F0E
	cmp r0, #0x19
	beq _08145F0E
	cmp r0, #0x1a
	beq _08145F0E
	cmp r0, #0xd
	beq _08145F0E
	cmp r0, #0x1b
	beq _08145F0E
	cmp r0, #0x1f
	beq _08145F0E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x118]
	ldrb r2, [r6]
	ldr r0, [sp, #0x11c]
	ldrb r3, [r0]
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_08145F0E:
	movs r1, #8
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08145F1E
	movs r0, #1
	b _08145F20
_08145F1E:
	movs r0, #0
_08145F20:
	cmp r0, #0
	beq _08145F2E
	ldr r6, [sp, #0xb0]
	ldr r0, [r6]
	ldr r1, [sp, #0xac]
	str r0, [r1]
	b _08145F40
_08145F2E:
	ldr r2, [sp, #0xb0]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xac]
	str r0, [r3]
_08145F40:
	ldrh r0, [r7]
	ldr r4, [sp, #0x38]
	strh r0, [r4]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x3c]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _08145F6A
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
_08145F6A:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08146038
	ldr r2, [sp, #0x24]
	ldr r3, _08145F88 @ =0x00000664
	adds r4, r2, r3
	bl VM_GetPC
	cmp r0, #0
	beq _08145F8C
	bl VM_GetValue
	b _08145F8E
	.align 2, 0
_08145F88: .4byte 0x00000664
_08145F8C:
	movs r0, #0
_08145F8E:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _08145FA0
	bl VM_GetValue
	adds r1, r0, #0
	b _08145FA2
_08145FA0:
	movs r1, #0
_08145FA2:
	ldr r4, [sp, #0x24]
	movs r5, #0xcc
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145FBC
	bl VM_GetValue
	adds r1, r0, #0
	b _08145FBE
_08145FBC:
	movs r1, #0
_08145FBE:
	ldr r6, [sp, #0x24]
	ldr r2, _08145FF0 @ =0x0000065D
	adds r0, r6, r2
	strb r1, [r0]
	ldr r2, _08145FF4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08145FF8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08145FFC @ =0x0203B400
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08146000
	bl VM_GetValue
	adds r1, r0, r4
	b _08146002
	.align 2, 0
_08145FF0: .4byte 0x0000065D
_08145FF4: .4byte 0x030046B8
_08145FF8: .4byte 0x000003FF
_08145FFC: .4byte 0x0203B400
_08146000:
	adds r1, r4, #0
_08146002:
	ldr r4, [sp, #0x24]
	ldr r5, _0814605C @ =0x0000065E
	adds r0, r4, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08146028
	bl VM_GetValue
	cmp r0, #0
	beq _08146028
	movs r2, #4
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08146028:
	ldr r1, [sp, #0x24]
	ldr r2, _08146060 @ =0x00000664
	adds r0, r1, r2
	ldr r1, [r0]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	str r1, [r0]
_08146038:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r7, #5]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _0814604E
	b _08146160
_0814604E:
	bl VM_GetPC
	cmp r0, #0
	beq _08146064
	bl VM_GetValue
	b _08146066
	.align 2, 0
_0814605C: .4byte 0x0000065E
_08146060: .4byte 0x00000664
_08146064:
	movs r0, #0
_08146066:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08146076
	bl VM_GetValue
	b _08146078
_08146076:
	movs r0, #0
_08146078:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08146088
	bl VM_GetValue
	b _0814608A
_08146088:
	movs r0, #0
_0814608A:
	strh r0, [r7, #0xc]
	ldr r4, [sp, #0x24]
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r2, r4, r5
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081460C0
	cmp r1, #0
	blt _081460C0
	ldr r0, _081460C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081460C0
	ldr r0, _081460C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081460CC
_081460C0:
	movs r1, #0
	b _081460DA
	.align 2, 0
_081460C4: .4byte 0x030046A8
_081460C8: .4byte 0x030046AC
_081460CC:
	ldr r0, _081460FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_081460DA:
	ldr r6, _08146100 @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r0, [sp, #0x24]
	movs r1, #0xd7
	lsls r1, r1, #3
	adds r5, r0, r1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08146104
	adds r0, #4
	b _08146110
	.align 2, 0
_081460FC: .4byte 0x030046A4
_08146100: .4byte 0x00000256
_08146104:
	ldr r0, _08146124 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08146110:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08146128
	cmp r2, #2
	beq _0814612C
	b _08146130
	.align 2, 0
_08146124: .4byte 0x030046A4
_08146128:
	ldrb r0, [r5, #4]
	b _0814612E
_0814612C:
	ldrb r0, [r5]
_0814612E:
	subs r1, r1, r0
_08146130:
	ldr r3, _081461A0 @ =0x00000472
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r1, [r7, #0xa]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, [sp, #0x24]
	ldr r6, _081461A4 @ =0x0000066E
	adds r0, r5, r6
	strh r1, [r0]
	ldrh r0, [r2]
	strh r0, [r7, #0xa]
	ldr r1, _081461A8 @ =0x00000256
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r3, _081461AC @ =0x0000066C
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r4, _081461B0 @ =0x00000662
	adds r0, r5, r4
	strh r1, [r0]
_08146160:
	movs r4, #0xa6
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x5c]
	strh r0, [r6]
	ldr r0, [sp, #0x50]
	strh r4, [r0]
	ldr r1, [sp, #0x54]
	strh r5, [r1]
	ldrh r0, [r6]
	ldr r2, _081461B4 @ =0x0000014F
	adds r0, r0, r2
	ldr r3, [sp, #0x58]
	strh r0, [r3]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r5, [sp, #0x134]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081461B8
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081461C4
	.align 2, 0
_081461A0: .4byte 0x00000472
_081461A4: .4byte 0x0000066E
_081461A8: .4byte 0x00000256
_081461AC: .4byte 0x0000066C
_081461B0: .4byte 0x00000662
_081461B4: .4byte 0x0000014F
_081461B8:
	ldr r2, [r7, #0x44]
	ldr r0, _081461FC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081461C4:
	ldr r6, [sp, #0x134]
	ldrb r0, [r6]
	cmp r0, #1
	bne _08146214
	ldr r1, [sp, #0xa0]
	ldrb r0, [r1]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08146200
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
	b _0814620A
	.align 2, 0
_081461FC: .4byte 0x03003584
_08146200:
	ldr r2, [sp, #0xa0]
	ldrb r0, [r2]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0814620A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08146214:
	adds r0, r7, #0
	bl Crow_InitHitboxes
	ldr r3, [sp, #0x24]
	ldr r5, _081463A8 @ =0x00000674
	adds r4, r3, r5
	movs r6, #0xd3
	lsls r6, r6, #3
	adds r5, r3, r6
	ldr r0, _081463AC @ =FUN_08145438
	str r0, [sp, #0x1a0]
	ldr r1, _081463B0 @ =Crow_GetMoveSpeed
	mov r8, r1
	ldr r2, _081463B4 @ =FUN_0814312c
	mov sb, r2
	ldr r3, _081463B8 @ =FUN_08142fd8
	mov sl, r3
	ldr r6, _081463BC @ =FUN_08143004
	mov ip, r6
	movs r2, #0
	ldr r3, _081463C0 @ =FUN_080f62b0
	ldr r0, _081463C4 @ =FUN_080f62ac
	str r0, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x68]
	str r4, [r0]
	ldr r1, [sp, #0x6c]
	str r5, [r1]
	ldr r4, [sp, #0x1a0]
	ldr r5, [sp, #0xe8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xf0]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xf8]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x108]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x10c]
	str r0, [r1]
	ldr r4, [sp, #0x13c]
	str r2, [r4]
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _081463C8 @ =FUN_08143310
	ldr r0, [sp, #0x148]
	str r6, [r0]
	ldr r1, _081463CC @ =Crow_StateDying
	ldr r3, [sp, #0x14c]
	str r1, [r3]
	ldr r0, _081463D0 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r0, [r4]
	ldr r0, _081463D4 @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r0, [r5]
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r0, [sp, #0xec]
	str r2, [r0]
	ldr r1, [sp, #0x198]
	ldr r3, [sp, #0x17c]
	str r1, [r3]
	ldr r0, _081463D8 @ =FUN_080f0430
	ldr r4, [sp, #0x180]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0xe4]
	strb r6, [r5]
	ldr r0, _081463DC @ =0x085AD470
	ldr r1, [sp, #0x184]
	str r0, [r1]
	ldr r0, _081463E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x16c]
	str r0, [r3]
	ldr r4, [sp, #0x160]
	str r2, [r4]
	ldr r5, [sp, #0x170]
	str r2, [r5]
	ldr r6, [sp, #0x174]
	str r2, [r6]
	ldr r0, [sp, #0x178]
	str r2, [r0]
	ldr r1, [sp, #0x188]
	str r2, [r1]
	ldr r0, _081463E4 @ =FUN_080f0320
	ldr r3, [sp, #0x18c]
	str r0, [r3]
	ldr r0, _081463E8 @ =Enemy_080eff14
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r0, _081463EC @ =FUN_080e72b0
	ldr r5, [sp, #0x164]
	str r0, [r5]
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r0, _081463F0 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x168]
	str r0, [r1]
	ldr r0, _081463F4 @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x154]
	str r0, [r3]
	ldr r4, [sp, #0x110]
	str r2, [r4]
	ldr r0, _081463F8 @ =FUN_080f6e64
	ldr r5, [sp, #0x190]
	str r0, [r5]
	ldr r0, _081463FC @ =Enemy_OnDamaged
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r0, _08146400 @ =FUN_080f84d4
	ldr r1, [sp, #0x194]
	str r0, [r1]
	ldr r0, _08146404 @ =FUN_080f624c
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _08146408 @ =FUN_080f56ec
	ldr r4, [sp, #0xfc]
	str r0, [r4]
	ldr r0, _0814640C @ =FUN_080f5b34
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r0, _08146410 @ =FUN_080f5fac
	ldr r6, [sp, #0x104]
	str r0, [r6]
	ldr r0, [sp, #0x128]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0xa8]
	strb r0, [r1]
	ldr r3, _08146414 @ =0x0000060C
	adds r1, r7, r3
	ldr r0, _08146418 @ =0x085AD858
	str r0, [r1]
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0814641C @ =Crow_OnReset
	str r0, [r1]
	ldr r5, _08146420 @ =0x000005FC
	adds r0, r7, r5
	str r2, [r0]
	ldr r6, _08146424 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _08146428 @ =FUN_08144bfc
	str r0, [r1]
	movs r1, #0xb6
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _0814642C @ =FUN_08144b90
	str r0, [r1]
	subs r3, #0x80
	adds r1, r7, r3
	ldr r0, _08146430 @ =FUN_080f8400
	str r0, [r1]
	ldr r1, _08146434 @ =0x02100408
	ldr r4, [sp, #0x74]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x80]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08146442
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0814639A:
	bl VM_GetPC
	cmp r0, #0
	beq _08146438
	bl VM_GetValue
	b _0814643A
	.align 2, 0
_081463A8: .4byte 0x00000674
_081463AC: .4byte FUN_08145438
_081463B0: .4byte Crow_GetMoveSpeed
_081463B4: .4byte FUN_0814312c
_081463B8: .4byte FUN_08142fd8
_081463BC: .4byte FUN_08143004
_081463C0: .4byte FUN_080f62b0
_081463C4: .4byte FUN_080f62ac
_081463C8: .4byte FUN_08143310
_081463CC: .4byte Crow_StateDying
_081463D0: .4byte FUN_080f44f4
_081463D4: .4byte FUN_080f410c
_081463D8: .4byte FUN_080f0430
_081463DC: .4byte 0x085AD470
_081463E0: .4byte FUN_080e73c8
_081463E4: .4byte FUN_080f0320
_081463E8: .4byte Enemy_080eff14
_081463EC: .4byte FUN_080e72b0
_081463F0: .4byte Enemy_StateBlownAway
_081463F4: .4byte Enemy_StateFallDeath
_081463F8: .4byte FUN_080f6e64
_081463FC: .4byte Enemy_OnDamaged
_08146400: .4byte FUN_080f84d4
_08146404: .4byte FUN_080f624c
_08146408: .4byte FUN_080f56ec
_0814640C: .4byte FUN_080f5b34
_08146410: .4byte FUN_080f5fac
_08146414: .4byte 0x0000060C
_08146418: .4byte 0x085AD858
_0814641C: .4byte Crow_OnReset
_08146420: .4byte 0x000005FC
_08146424: .4byte 0x000005AC
_08146428: .4byte FUN_08144bfc
_0814642C: .4byte FUN_08144b90
_08146430: .4byte FUN_080f8400
_08146434: .4byte 0x02100408
_08146438:
	movs r0, #0
_0814643A:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0814639A
_08146442:
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
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _0814647A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x70]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0814647A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0814647A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814648C
	movs r0, #1
	b _0814648E
_0814648C:
	movs r0, #0
_0814648E:
	cmp r0, #0
	beq _081464A0
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081464A0:
	cmp r2, #1
	beq _081464E0
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081464F0 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081464F4 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x10c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xe0]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081464E0:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081464F8
	movs r0, #1
	b _081464FA
	.align 2, 0
_081464F0: .4byte 0x00000484
_081464F4: .4byte 0x0000046C
_081464F8:
	movs r0, #0
_081464FA:
	cmp r0, #0
	beq _08146514
	ldr r0, _08146510 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _0814651E
	.align 2, 0
_08146510: .4byte 0x030046A0
_08146514:
	ldr r0, [sp, #0x30]
	bl GetZoneAt
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_0814651E:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814652E
	movs r0, #1
	b _08146530
_0814652E:
	movs r0, #0
_08146530:
	cmp r0, #0
	beq _08146540
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08146564 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08146540:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08146572
	ldr r0, _08146568 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0814656C
	movs r0, #1
	b _0814656E
	.align 2, 0
_08146564: .4byte 0xFFFFFEFF
_08146568: .4byte 0x030046A0
_0814656C:
	movs r0, #0
_0814656E:
	cmp r0, #0
	bne _0814657A
_08146572:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0814657A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x134]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08146662
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
	beq _081465BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081465C4
_081465BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081465C4:
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
	beq _081465E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081465F0
_081465E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081465F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08146628 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0814666C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0814662C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08146620
	ldrb r0, [r4, #5]
_08146620:
	subs r0, #1
	strh r0, [r4, #8]
	b _0814663C
	.align 2, 0
_08146628: .4byte 0x0000FFFF
_0814662C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0814663C
	strh r1, [r4, #8]
_0814663C:
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
	bne _0814666C
	movs r0, #1
	strb r0, [r4, #7]
	b _0814666C
_08146662:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_0814666C:
	movs r0, #0
	ldr r3, [sp, #0x90]
	str r0, [r3]
	ldr r0, _08146684 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08146688
	movs r0, #1
	b _0814668A
	.align 2, 0
_08146684: .4byte 0x030047A4
_08146688:
	movs r0, #0
_0814668A:
	cmp r0, #0
	bne _081466CA
	ldr r4, [sp, #0xa0]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081466B2
	adds r0, r1, #0
	cmp r0, #7
	beq _081466B2
	cmp r0, #6
	beq _081466B2
	cmp r0, #0x15
	beq _081466B2
	cmp r0, #0x14
	beq _081466B2
	cmp r0, #0x17
	bne _081466CA
_081466B2:
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
_081466CA:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_0814414c
	adds r0, r7, #0
	bl FUN_08145424
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xdc]
	strh r0, [r2]
	ldr r3, [sp, #0x88]
	ldrh r0, [r3]
	ldr r4, [sp, #0xd8]
	strh r0, [r4]
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	ldr r6, [sp, #0xb8]
	str r0, [r6]
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc4]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc8]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xcc]
	strb r0, [r3]
	ldr r4, [sp, #0xe0]
	ldr r0, [r4]
	ldr r5, [sp, #0xd0]
	str r0, [r5]
	ldr r6, [sp, #0xb4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd4]
	strb r0, [r1]
	ldr r2, _08146760 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08146764 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _08146768 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0814676C @ =Crow_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08146770 @ =Crow_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08146774
	movs r0, #0
	b _08146778
	.align 2, 0
_08146760: .4byte 0x0000057C
_08146764: .4byte Enemy_DispatchMsg
_08146768: .4byte 0x0000061C
_0814676C: .4byte Crow_Update
_08146770: .4byte Crow_Destroy
_08146774:
	movs r0, #1
	rsbs r0, r0, #0
_08146778:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
