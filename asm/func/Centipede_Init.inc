	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b8
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xb3
	lsls r1, r1, #4
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _08138FB0 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #9
	strb r0, [r1]
	adds r0, r7, #0
	bl Centipede_InitAnims
	ldr r3, _08138FB4 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08138FC0
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08138FB8 @ =0x0000D636
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08138FBC @ =0x0000C102
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _08138FB0 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xd4]
	cmp r1, #0x11
	beq _08138F9E
	cmp r1, #0x17
	bne _08138FA2
_08138F9E:
	movs r0, #1
	strb r0, [r5, #7]
_08138FA2:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08139028
	.align 2, 0
_08138FB0: .4byte 0x000001DF
_08138FB4: .4byte 0x0000025D
_08138FB8: .4byte 0x0000D636
_08138FBC: .4byte 0x0000C102
_08138FC0:
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
	ldr r2, _081390A4 @ =0x05000002
	bl CpuSet
	ldr r0, _081390A8 @ =0x0000CB05
	ldr r1, _081390AC @ =0x0000D636
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
	ldr r0, _081390B0 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081390B4 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xd4]
_08139028:
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
	ldr r5, _081390B8 @ =0x0000046F
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
	ldr r1, _081390BC @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081390A4 @ =0x05000002
	bl CpuSet
	ldr r3, _081390C0 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0xa8]
	mov r3, r8
	str r3, [sp, #0xac]
	str r6, [sp, #0x80]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08139094
	b _081391F4
_08139094:
	bl VM_GetPC
	cmp r0, #0
	beq _081390C4
	bl VM_GetValue
	adds r1, r0, #0
	b _081390C6
	.align 2, 0
_081390A4: .4byte 0x05000002
_081390A8: .4byte 0x0000CB05
_081390AC: .4byte 0x0000D636
_081390B0: .4byte 0x000004B7
_081390B4: .4byte 0x000001DF
_081390B8: .4byte 0x0000046F
_081390BC: .4byte 0x00000474
_081390C0: .4byte 0x000004B6
_081390C4:
	movs r1, #0
_081390C6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081390EC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x14c]
	str r4, [sp, #0x150]
	cmp r0, #0
	beq _081390F0
	bl VM_GetValue
	adds r1, r0, #0
	b _081390F2
	.align 2, 0
_081390EC: .4byte 0x00000251
_081390F0:
	movs r1, #0
_081390F2:
	ldr r2, _08139128 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813912C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x14c]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x158]
	cmp r0, #0
	beq _08139130
	bl VM_GetValue
	b _08139134
	.align 2, 0
_08139128: .4byte 0x00000252
_0813912C: .4byte 0x000004B4
_08139130:
	ldr r4, [sp, #0x14c]
	ldrb r0, [r4]
_08139134:
	strb r0, [r6]
	ldr r5, [sp, #0x14c]
	ldrb r1, [r5]
	ldr r6, [sp, #0x158]
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
	blt _0813916C
	cmp r1, #0
	blt _0813916C
	ldr r0, _08139170 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813916C
	ldr r0, _08139174 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08139178
_0813916C:
	movs r1, #0
	b _08139186
	.align 2, 0
_08139170: .4byte 0x030046A8
_08139174: .4byte 0x030046AC
_08139178:
	ldr r0, _081391A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08139186:
	ldr r2, _081391A4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081391A8
	adds r0, #4
	b _081391B4
	.align 2, 0
_081391A0: .4byte 0x030046A4
_081391A4: .4byte 0x00000256
_081391A8:
	ldr r0, _081391C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081391B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081391CC
	cmp r2, #2
	beq _081391D0
	b _081391D4
	.align 2, 0
_081391C8: .4byte 0x030046A4
_081391CC:
	ldrb r0, [r4, #4]
	b _081391D2
_081391D0:
	ldrb r0, [r4]
_081391D2:
	subs r1, r1, r0
_081391D4:
	ldr r3, _081391EC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081391F0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08139234
	.align 2, 0
_081391EC: .4byte 0x00000472
_081391F0: .4byte 0x0000FFFF
_081391F4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08139258 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813925C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08139260 @ =0x000004B4
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
	str r5, [sp, #0x14c]
	str r4, [sp, #0x150]
	str r3, [sp, #0x158]
_08139234:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0813927E
	bl VM_GetPC
	cmp r0, #0
	beq _08139264
	bl VM_GetValue
	adds r4, r0, #0
	b _08139266
	.align 2, 0
_08139258: .4byte 0x00000251
_0813925C: .4byte 0x00000252
_08139260: .4byte 0x000004B4
_08139264:
	movs r4, #0x30
_08139266:
	bl VM_GetPC
	cmp r0, #0
	beq _08139278
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0813927A
_08139278:
	movs r5, #0x40
_0813927A:
	mov r8, r4
	b _08139284
_0813927E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08139284:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081392BC
	bl VM_GetPC
	cmp r0, #0
	beq _0813929E
	bl VM_GetValue
	adds r6, r0, #0
	b _081392A0
_0813929E:
	movs r6, #0
_081392A0:
	bl VM_GetPC
	cmp r0, #0
	beq _081392B0
	bl VM_GetValue
	adds r1, r0, #0
	b _081392B2
_081392B0:
	movs r1, #0
_081392B2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081392C6
_081392BC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081392C6:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08139558 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x144]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	lsls r4, r4, #0x10
	str r4, [sp, #0xd0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xdc]
	lsls r6, r6, #0x10
	str r6, [sp, #0xe0]
	lsls r5, r5, #0x10
	str r5, [sp, #0xd8]
	ldr r4, _0813955C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x164]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xcc]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x5c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x60]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x64]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x58]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x90]
	ldr r1, _08139560 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _08139564 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x88]
	ldr r3, _08139568 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x8c]
	ldr r4, _0813956C @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _08139570 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x178]
	ldr r6, _08139574 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _08139578 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x184]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x188]
	ldr r3, _0813957C @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x18c]
	ldr r4, _08139580 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x194]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x180]
	ldr r6, _08139584 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x128]
	ldr r1, _08139588 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _0813958C @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _08139590 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a8]
	ldr r6, _08139594 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x19c]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x30]
	ldr r2, _08139598 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x34]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x38]
	ldr r4, _0813959C @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	ldr r6, _081395A0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x174]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x1a0]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _081395A4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x1a4]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x190]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _081395A8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r1, _081395AC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x130]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _081395B0 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x138]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081395B4 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _081395B8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	ldr r2, _081395BC @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xec]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, _081395C0 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r1, _081395C4 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _081395C8 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _081395CC @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x94]
	ldr r4, _081395D0 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r5, _081395D4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	ldr r6, _081395D8 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081395DC @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x120]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xc4]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x98]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	ldr r6, _081395E0 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0x11c]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x118]
	ldr r3, _081395E4 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _081395E8 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	ldr r6, _081395EC @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _081395F0 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _081395F4 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	ldr r4, _081395F8 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0x110]
	cmp r0, #0
	bne _08139528
	b _08139654
_08139528:
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
_08139548:
	bl VM_GetPC
	cmp r0, #0
	beq _081395FC
	bl VM_GetValue
	b _081395FE
	.align 2, 0
_08139558: .4byte 0x0000025D
_0813955C: .4byte 0x0000025A
_08139560: .4byte 0x0000047A
_08139564: .4byte 0x0000047C
_08139568: .4byte 0x0000047E
_0813956C: .4byte 0x000004A4
_08139570: .4byte 0x000005A4
_08139574: .4byte 0x000005C4
_08139578: .4byte 0x000005CC
_0813957C: .4byte 0x000005D4
_08139580: .4byte 0x000005DC
_08139584: .4byte 0x00000584
_08139588: .4byte 0x00000604
_0813958C: .4byte 0x0000021D
_08139590: .4byte 0x0000060C
_08139594: .4byte 0x000005E4
_08139598: .4byte 0x000005FC
_0813959C: .4byte 0x00000614
_081395A0: .4byte 0x000005BC
_081395A4: .4byte 0x000005EC
_081395A8: .4byte 0x00000624
_081395AC: .4byte 0x0000058C
_081395B0: .4byte 0x00000594
_081395B4: .4byte 0x0000059C
_081395B8: .4byte 0x000005B4
_081395BC: .4byte 0x00000543
_081395C0: .4byte 0x00000496
_081395C4: .4byte 0x00000469
_081395C8: .4byte 0x0000046A
_081395CC: .4byte 0x00000484
_081395D0: .4byte 0x0000046C
_081395D4: .4byte 0x0000046D
_081395D8: .4byte 0x0000046B
_081395DC: .4byte 0x00000553
_081395E0: .4byte 0x00000572
_081395E4: .4byte 0x0000055C
_081395E8: .4byte 0x00000564
_081395EC: .4byte 0x00000565
_081395F0: .4byte 0x00000566
_081395F4: .4byte 0x00000567
_081395F8: .4byte 0x0000056C
_081395FC:
	movs r0, #0x18
_081395FE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08139610
	bl VM_GetValue
	b _08139612
_08139610:
	movs r0, #0x18
_08139612:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08139624
	bl VM_GetValue
	b _08139626
_08139624:
	movs r0, #0
_08139626:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08139638
	bl VM_GetValue
	b _0813963A
_08139638:
	movs r0, #0
_0813963A:
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
	bgt _08139654
	b _08139548
_08139654:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081396A0
	bl VM_GetPC
	cmp r0, #0
	beq _0813966E
	bl VM_GetValue
	adds r4, r0, #0
	b _08139672
_0813966E:
	movs r4, #0x96
	lsls r4, r4, #1
_08139672:
	bl VM_GetPC
	cmp r0, #0
	beq _08139682
	bl VM_GetValue
	adds r6, r0, #0
	b _08139686
_08139682:
	movs r6, #0x96
	lsls r6, r6, #1
_08139686:
	bl VM_GetPC
	cmp r0, #0
	beq _08139694
	bl VM_GetValue
	b _0813969A
_08139694:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0813969A:
	ldr r3, [sp, #0x144]
	strh r0, [r3]
	b _081396A8
_081396A0:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x144]
	strh r6, [r5]
_081396A8:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081396C0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0xac]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081396C0:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0xb4]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0xb0]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08139790
	bl VM_GetPC
	cmp r0, #0
	beq _081396F0
	bl VM_GetValue
	b _081396F2
_081396F0:
	movs r0, #0
_081396F2:
	ldr r1, [sp, #0x15c]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08139700
	asrs r1, r0, #1
	b _08139706
_08139700:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08139706:
	ldr r2, _0813971C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08139720
	bl VM_GetValue
	b _08139722
	.align 2, 0
_0813971C: .4byte 0x00000546
_08139720:
	movs r0, #0
_08139722:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139738
	bl VM_GetValue
	b _0813973A
_08139738:
	movs r0, #0
_0813973A:
	ldr r5, _08139750 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139754
	bl VM_GetValue
	adds r1, r0, #0
	b _08139756
	.align 2, 0
_08139750: .4byte 0x00000187
_08139754:
	movs r1, #0
_08139756:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813976C
	bl VM_GetValue
	b _0813976E
_0813976C:
	movs r0, #0
_0813976E:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08139786
	bl VM_GetValue
	adds r1, r0, #0
	b _08139788
_08139786:
	movs r1, #0
_08139788:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08139790:
	ldr r0, [sp, #0x15c]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0xd0]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xdc]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xe0]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xd8]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081397F2
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081397D8
	bl VM_GetValue
	b _081397DA
_081397D8:
	movs r0, #0
_081397DA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081397EA
	bl VM_GetValue
	b _081397EC
_081397EA:
	movs r0, #0
_081397EC:
	ldr r2, _08139854 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_081397F2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x164]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08139816
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0xac]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08139816:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0813982E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0xac]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0813982E:
	ldr r6, [sp, #0xcc]
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
	ldr r2, [sp, #0x80]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08139858
	movs r0, #1
	b _0813985A
	.align 2, 0
_08139854: .4byte 0x00000189
_08139858:
	movs r0, #0
_0813985A:
	cmp r0, #0
	beq _0813986A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08139894 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_0813986A:
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08139876
	ldr r1, [r7, #0x44]
_08139876:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08139898
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081398A4
	.align 2, 0
_08139894: .4byte Enemy_OnCWolfMessage
_08139898:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081398A4:
	ldr r5, [sp, #0xd4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081398F2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081398F2
	cmp r0, #0x16
	beq _081398F2
	cmp r0, #0x14
	beq _081398F2
	cmp r0, #9
	beq _081398F2
	cmp r0, #0x19
	beq _081398F2
	cmp r0, #0x1a
	beq _081398F2
	cmp r0, #0xd
	beq _081398F2
	cmp r0, #0x1b
	beq _081398F2
	cmp r0, #0x1f
	beq _081398F2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x14c]
	ldrb r2, [r6]
	ldr r0, [sp, #0x150]
	ldrb r3, [r0]
	ldr r4, [sp, #0x158]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_081398F2:
	movs r1, #8
	ldr r5, [sp, #0x80]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08139902
	movs r0, #1
	b _08139904
_08139902:
	movs r0, #0
_08139904:
	cmp r0, #0
	beq _08139912
	ldr r6, [sp, #0xe8]
	ldr r0, [r6]
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	b _08139924
_08139912:
	ldr r2, [sp, #0xe8]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xe4]
	str r0, [r3]
_08139924:
	ldrh r0, [r7]
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	ldr r5, [sp, #0x58]
	ldr r6, [sp, #0x64]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0813994E
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
_0813994E:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _0813995A
	b _08139A68
_0813995A:
	bl VM_GetPC
	cmp r0, #0
	beq _08139968
	bl VM_GetValue
	b _0813996A
_08139968:
	movs r0, #0
_0813996A:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0813997A
	bl VM_GetValue
	b _0813997C
_0813997A:
	movs r0, #0
_0813997C:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0813998C
	bl VM_GetValue
	b _0813998E
_0813998C:
	movs r0, #0
_0813998E:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x58]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081399B6
	cmp r1, #0
	blt _081399B6
	ldr r0, _081399BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081399B6
	ldr r0, _081399C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081399C4
_081399B6:
	movs r1, #0
	b _081399D2
	.align 2, 0
_081399BC: .4byte 0x030046A8
_081399C0: .4byte 0x030046AC
_081399C4:
	ldr r0, _081399EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081399D2:
	ldr r4, _081399F0 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x58]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081399F4
	adds r0, #4
	b _08139A00
	.align 2, 0
_081399EC: .4byte 0x030046A4
_081399F0: .4byte 0x00000256
_081399F4:
	ldr r0, _08139A14 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08139A00:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08139A18
	cmp r3, #2
	beq _08139A1C
	b _08139A20
	.align 2, 0
_08139A14: .4byte 0x030046A4
_08139A18:
	ldrb r0, [r5, #4]
	b _08139A1E
_08139A1C:
	ldrb r0, [r5]
_08139A1E:
	subs r2, r2, r0
_08139A20:
	ldr r5, _08139A4C @ =0x00000472
	adds r1, r7, r5
	strh r2, [r1]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r2
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
	ldr r1, [sp, #0x168]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08139A50
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08139A5A
	.align 2, 0
_08139A4C: .4byte 0x00000472
_08139A50:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08139A5A:
	ldr r3, [sp, #0x24]
	ldr r4, _08139A84 @ =0x00000B8C
	adds r2, r3, r4
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08139A68:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08139A96
	bl VM_GetPC
	cmp r0, #0
	beq _08139A88
	bl VM_GetValue
	adds r1, r0, #0
	b _08139A8E
	.align 2, 0
_08139A84: .4byte 0x00000B8C
_08139A88:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r1, r5, #0
_08139A8E:
	ldr r6, [sp, #0x24]
	ldr r2, _08139AD8 @ =0x00000B46
	adds r0, r6, r2
	strh r1, [r0]
_08139A96:
	adds r0, r7, #0
	bl FUN_08138710
	ldr r4, _08139ADC @ =0x000001A1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x90]
	strh r0, [r3]
	ldr r6, [sp, #0x84]
	strh r4, [r6]
	ldr r0, [sp, #0x88]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x168]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08139AE0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08139AEC
	.align 2, 0
_08139AD8: .4byte 0x00000B46
_08139ADC: .4byte 0x000001A1
_08139AE0:
	ldr r2, [r7, #0x44]
	ldr r0, _08139B24 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08139AEC:
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08139B3C
	ldr r4, [sp, #0xd4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08139B28
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
	b _08139B32
	.align 2, 0
_08139B24: .4byte 0x03003584
_08139B28:
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08139B32:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08139B3C:
	adds r0, r7, #0
	bl Centipede_InitHitboxes
	adds r0, r7, #0
	bl FUN_08136d00
	ldr r0, _08139CE8 @ =0x00000B58
	ldr r6, [sp, #0x24]
	adds r0, r6, r0
	str r0, [sp, #0x1b4]
	ldr r1, _08139CEC @ =0x00000B7C
	adds r6, r6, r1
	mov r8, r6
	ldr r2, _08139CF0 @ =FUN_08138de0
	mov sb, r2
	ldr r3, _08139CF4 @ =Centipede_GetMoveSpeed
	mov sl, r3
	ldr r4, _08139CF8 @ =FUN_08132d30
	mov ip, r4
	movs r2, #0
	ldr r4, _08139CFC @ =Centipede_StateDamaged
	ldr r5, _08139D00 @ =Centipede_StateDying
	ldr r3, _08139D04 @ =FUN_080f62b0
	ldr r6, _08139D08 @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0xa8]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1b4]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0xa4]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0x124]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0x134]
	str r6, [r0]
	ldr r1, _08139D0C @ =FUN_08132a24
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r0, _08139D10 @ =FUN_08132c24
	ldr r1, [sp, #0x154]
	str r0, [r1]
	ldr r6, _08139D14 @ =FUN_08132d34
	ldr r0, [sp, #0x178]
	str r6, [r0]
	ldr r1, [sp, #0x17c]
	str r3, [r1]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r4, [sp, #0x188]
	str r5, [r4]
	ldr r0, _08139D18 @ =FUN_080f44f4
	ldr r5, [sp, #0x18c]
	str r0, [r5]
	ldr r0, _08139D1C @ =FUN_080f410c
	ldr r6, [sp, #0x194]
	str r0, [r6]
	ldr r0, [sp, #0x180]
	str r2, [r0]
	ldr r1, _08139D20 @ =FUN_08132e60
	ldr r3, [sp, #0x128]
	str r1, [r3]
	ldr r4, [sp, #0x1ac]
	ldr r5, [sp, #0x3c]
	str r4, [r5]
	ldr r0, _08139D24 @ =FUN_080f0430
	ldr r6, [sp, #0x40]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0x114]
	strb r1, [r0]
	ldr r0, _08139D28 @ =0x085AD470
	ldr r3, [sp, #0x44]
	str r0, [r3]
	ldr r0, _08139D2C @ =FUN_080e73c8
	ldr r4, [sp, #0x1a8]
	str r0, [r4]
	ldr r5, [sp, #0x19c]
	str r2, [r5]
	ldr r6, [sp, #0x30]
	str r2, [r6]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	ldr r1, [sp, #0x38]
	str r2, [r1]
	ldr r3, [sp, #0x48]
	str r2, [r3]
	ldr r0, _08139D30 @ =FUN_080f0320
	ldr r4, [sp, #0x4c]
	str r0, [r4]
	ldr r0, _08139D34 @ =Enemy_080eff14
	ldr r5, [sp, #0x174]
	str r0, [r5]
	ldr r0, _08139D38 @ =FUN_080e72b0
	ldr r6, [sp, #0x1a0]
	str r0, [r6]
	ldr r0, _08139D3C @ =FUN_08133ed4
	ldr r1, [sp, #0x198]
	str r0, [r1]
	ldr r0, _08139D40 @ =Enemy_StateBlownAway
	ldr r3, [sp, #0x1a4]
	str r0, [r3]
	ldr r0, _08139D44 @ =Enemy_StateFallDeath
	ldr r4, [sp, #0x190]
	str r0, [r4]
	ldr r5, [sp, #0x160]
	str r2, [r5]
	ldr r0, _08139D48 @ =FUN_080f6e64
	ldr r6, [sp, #0x50]
	str r0, [r6]
	ldr r0, _08139D4C @ =Enemy_OnDamaged
	ldr r1, [sp, #0x130]
	str r0, [r1]
	ldr r0, _08139D50 @ =FUN_080f84d4
	ldr r3, [sp, #0x54]
	str r0, [r3]
	ldr r0, _08139D54 @ =FUN_080f624c
	ldr r4, [sp, #0x170]
	str r0, [r4]
	ldr r0, _08139D58 @ =FUN_080f56ec
	ldr r5, [sp, #0x138]
	str r0, [r5]
	ldr r0, _08139D5C @ =FUN_080f5b34
	ldr r6, [sp, #0x13c]
	str r0, [r6]
	ldr r0, _08139D60 @ =FUN_080f5fac
	ldr r1, [sp, #0x140]
	str r0, [r1]
	ldr r3, [sp, #0x16c]
	str r2, [r3]
	movs r0, #0x28
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08139D64 @ =Centipede_OnReset
	str r0, [r1]
	ldr r6, _08139D68 @ =0x000005FC
	adds r0, r7, r6
	str r2, [r0]
	ldr r0, _08139D6C @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _08139D70 @ =FUN_081387a0
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08139D74 @ =FUN_08138808
	str r0, [r1]
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08139D78 @ =FUN_0813880c
	str r0, [r1]
	ldr r4, _08139D7C @ =0x0000058C
	adds r1, r7, r4
	ldr r0, _08139D80 @ =FUN_08138cb0
	str r0, [r1]
	subs r5, #0x44
	adds r1, r7, r5
	ldr r0, _08139D84 @ =FUN_08137a50
	str r0, [r1]
	ldr r1, _08139D88 @ =0x00100200
	ldr r6, [sp, #0xa8]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #8
	ldr r2, [sp, #0xac]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x40
	ldr r3, [sp, #0x80]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0xb8]
	strh r0, [r4]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08139D96
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08139CD8:
	bl VM_GetPC
	cmp r0, #0
	beq _08139D8C
	bl VM_GetValue
	b _08139D8E
	.align 2, 0
_08139CE8: .4byte 0x00000B58
_08139CEC: .4byte 0x00000B7C
_08139CF0: .4byte FUN_08138de0
_08139CF4: .4byte Centipede_GetMoveSpeed
_08139CF8: .4byte FUN_08132d30
_08139CFC: .4byte Centipede_StateDamaged
_08139D00: .4byte Centipede_StateDying
_08139D04: .4byte FUN_080f62b0
_08139D08: .4byte FUN_080f62ac
_08139D0C: .4byte FUN_08132a24
_08139D10: .4byte FUN_08132c24
_08139D14: .4byte FUN_08132d34
_08139D18: .4byte FUN_080f44f4
_08139D1C: .4byte FUN_080f410c
_08139D20: .4byte FUN_08132e60
_08139D24: .4byte FUN_080f0430
_08139D28: .4byte 0x085AD470
_08139D2C: .4byte FUN_080e73c8
_08139D30: .4byte FUN_080f0320
_08139D34: .4byte Enemy_080eff14
_08139D38: .4byte FUN_080e72b0
_08139D3C: .4byte FUN_08133ed4
_08139D40: .4byte Enemy_StateBlownAway
_08139D44: .4byte Enemy_StateFallDeath
_08139D48: .4byte FUN_080f6e64
_08139D4C: .4byte Enemy_OnDamaged
_08139D50: .4byte FUN_080f84d4
_08139D54: .4byte FUN_080f624c
_08139D58: .4byte FUN_080f56ec
_08139D5C: .4byte FUN_080f5b34
_08139D60: .4byte FUN_080f5fac
_08139D64: .4byte Centipede_OnReset
_08139D68: .4byte 0x000005FC
_08139D6C: .4byte 0x000005AC
_08139D70: .4byte FUN_081387a0
_08139D74: .4byte FUN_08138808
_08139D78: .4byte FUN_0813880c
_08139D7C: .4byte 0x0000058C
_08139D80: .4byte FUN_08138cb0
_08139D84: .4byte FUN_08137a50
_08139D88: .4byte 0x00100200
_08139D8C:
	movs r0, #0
_08139D8E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08139CD8
_08139D96:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xbc]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x9c]
	strh r0, [r3]
	cmp r2, #0
	beq _08139DCE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0xa8]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08139DCE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08139DCE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x80]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08139DE0
	movs r0, #1
	b _08139DE2
_08139DE0:
	movs r0, #0
_08139DE2:
	cmp r0, #0
	beq _08139DF4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0xac]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08139DF4:
	cmp r2, #1
	beq _08139E28
	movs r0, #0
	ldr r1, [sp, #0x68]
	strb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, [sp, #0x70]
	strb r0, [r3]
	ldr r4, [sp, #0x94]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x78]
	strb r1, [r5]
	ldr r6, [sp, #0x154]
	ldr r2, [r6]
	ldr r3, [sp, #0x7c]
	strb r1, [r3]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0xf0]
	strb r0, [r5]
	ldr r6, [sp, #0x120]
	str r2, [r6]
	ldr r1, [sp, #0xc4]
	strh r0, [r1]
_08139E28:
	movs r1, #2
	ldr r2, [sp, #0x80]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08139E38
	movs r0, #1
	b _08139E3A
_08139E38:
	movs r0, #0
_08139E3A:
	cmp r0, #0
	beq _08139E54
	ldr r0, _08139E50 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x98]
	strh r0, [r4]
	b _08139E5E
	.align 2, 0
_08139E50: .4byte 0x030046A0
_08139E54:
	ldr r0, [sp, #0x58]
	bl GetZoneAt
	ldr r5, [sp, #0x98]
	strh r0, [r5]
_08139E5E:
	movs r1, #0x40
	ldr r6, [sp, #0x80]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08139E6E
	movs r0, #1
	b _08139E70
_08139E6E:
	movs r0, #0
_08139E70:
	cmp r0, #0
	beq _08139E80
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08139EA4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08139E80:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08139EB2
	ldr r0, _08139EA8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x98]
	ldrh r2, [r2]
	cmp r0, r2
	bne _08139EAC
	movs r0, #1
	b _08139EAE
	.align 2, 0
_08139EA4: .4byte 0xFFFFFEFF
_08139EA8: .4byte 0x030046A0
_08139EAC:
	movs r0, #0
_08139EAE:
	cmp r0, #0
	bne _08139EBA
_08139EB2:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_08139EBA:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, [sp, #0x168]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08139FA2
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
	beq _08139EFC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08139F04
_08139EFC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08139F04:
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
	beq _08139F28
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08139F30
_08139F28:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08139F30:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08139F68 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _08139FAC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08139F6C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08139F60
	ldrb r0, [r4, #5]
_08139F60:
	subs r0, #1
	strh r0, [r4, #8]
	b _08139F7C
	.align 2, 0
_08139F68: .4byte 0x0000FFFF
_08139F6C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08139F7C
	strh r1, [r4, #8]
_08139F7C:
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
	bne _08139FAC
	movs r0, #1
	strb r0, [r4, #7]
	b _08139FAC
_08139FA2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08139FAC:
	movs r0, #0
	ldr r3, [sp, #0xc8]
	str r0, [r3]
	ldr r0, _08139FC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08139FC8
	movs r0, #1
	b _08139FCA
	.align 2, 0
_08139FC4: .4byte 0x030047A4
_08139FC8:
	movs r0, #0
_08139FCA:
	cmp r0, #0
	bne _0813A00A
	ldr r4, [sp, #0xd4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08139FF2
	adds r0, r1, #0
	cmp r0, #7
	beq _08139FF2
	cmp r0, #6
	beq _08139FF2
	cmp r0, #0x15
	beq _08139FF2
	cmp r0, #0x14
	beq _08139FF2
	cmp r0, #0x17
	bne _0813A00A
_08139FF2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x80]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0813A00A:
	adds r0, r7, #0
	bl FUN_081355f0
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x68]
	strb r2, [r6]
	ldr r1, [sp, #0x6c]
	strb r2, [r1]
	ldr r3, [sp, #0x70]
	strb r0, [r3]
	ldr r4, [sp, #0x94]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x78]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x7c]
	strb r1, [r3]
	ldr r4, [sp, #0x74]
	strb r2, [r4]
	ldr r5, [sp, #0xf0]
	strb r1, [r5]
	ldr r6, [sp, #0x120]
	str r0, [r6]
	ldr r0, [sp, #0xc4]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_081355ac
	adds r0, r7, #0
	bl FUN_08138c54
	ldr r1, _0813A0F8 @ =0x0000D636
	ldr r2, _0813A0FC @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_08136140
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x58]
	bl FUN_08137360
	adds r0, r7, #0
	bl FUN_081380d8
	adds r0, r7, #0
	bl FUN_081355f0
	adds r0, r7, #0
	bl FUN_08136be4
	ldr r1, [sp, #0x80]
	ldrh r0, [r1]
	ldr r2, [sp, #0x11c]
	strh r0, [r2]
	ldr r3, [sp, #0xc0]
	ldrh r0, [r3]
	ldr r4, [sp, #0x118]
	strh r0, [r4]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xf8]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
	ldr r4, [sp, #0x68]
	ldrb r0, [r4]
	ldr r5, [sp, #0x100]
	strb r0, [r5]
	ldr r6, [sp, #0x6c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x104]
	strb r0, [r1]
	ldr r2, [sp, #0x70]
	ldrb r0, [r2]
	ldr r3, [sp, #0x108]
	strb r0, [r3]
	ldr r4, [sp, #0x120]
	ldr r0, [r4]
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r6, [sp, #0xf0]
	ldrb r0, [r6]
	ldr r1, [sp, #0x110]
	strb r0, [r1]
	ldr r2, _0813A100 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0813A104 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0813A108 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0813A10C @ =Centipede_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0813A110 @ =Centipede_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813A114
	movs r0, #0
	b _0813A118
	.align 2, 0
_0813A0F8: .4byte 0x0000D636
_0813A0FC: .4byte 0x0000C102
_0813A100: .4byte 0x0000057C
_0813A104: .4byte Enemy_DispatchMsg
_0813A108: .4byte 0x0000061C
_0813A10C: .4byte Centipede_Update
_0813A110: .4byte Centipede_Destroy
_0813A114:
	movs r0, #1
	rsbs r0, r0, #0
_0813A118:
	add sp, #0x1b8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
