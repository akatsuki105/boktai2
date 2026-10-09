	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_080e37e8
	movs r0, #0x6b
	movs r1, #5
	bl VM_GetNamedArgValue
	ldr r2, _08113F74 @ =0x000001DF
	adds r1, r7, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _08113F12
	movs r0, #0x40
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113F12:
	adds r0, r7, #0
	bl FUN_0810388c
	ldr r4, _08113F78 @ =0x0000025D
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x1a0]
	cmp r1, #0
	bne _08113F80
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08113F7C @ =0x0000AE52
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080e3804
	ldr r6, _08113F74 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0xfc]
	cmp r1, #0x11
	beq _08113F62
	cmp r1, #0x17
	bne _08113F66
_08113F62:
	movs r0, #1
	strb r0, [r5, #7]
_08113F66:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08113FE6
	.align 2, 0
_08113F74: .4byte 0x000001DF
_08113F78: .4byte 0x0000025D
_08113F7C: .4byte 0x0000AE52
_08113F80:
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
	ldr r2, _08114064 @ =0x05000002
	bl CpuSet
	ldr r0, _08114068 @ =0x0000CB05
	ldr r1, _0811406C @ =0x0000AE52
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
	ldr r0, _08114070 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08114074 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xfc]
_08113FE6:
	str r7, [sp, #0x2c]
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
	ldr r5, _08114078 @ =0x0000046F
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
	ldr r1, _0811407C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08114064 @ =0x05000002
	bl CpuSet
	ldr r3, _08114080 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x84]
	mov r3, r8
	str r3, [sp, #0x88]
	str r6, [sp, #0x58]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08114052
	b _081141B4
_08114052:
	bl VM_GetPC
	cmp r0, #0
	beq _08114084
	bl VM_GetValue
	adds r1, r0, #0
	b _08114086
	.align 2, 0
_08114064: .4byte 0x05000002
_08114068: .4byte 0x0000CB05
_0811406C: .4byte 0x0000AE52
_08114070: .4byte 0x000004B7
_08114074: .4byte 0x000001DF
_08114078: .4byte 0x0000046F
_0811407C: .4byte 0x00000474
_08114080: .4byte 0x000004B6
_08114084:
	movs r1, #0
_08114086:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081140AC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x188]
	str r4, [sp, #0x18c]
	cmp r0, #0
	beq _081140B0
	bl VM_GetValue
	adds r1, r0, #0
	b _081140B2
	.align 2, 0
_081140AC: .4byte 0x00000251
_081140B0:
	movs r1, #0
_081140B2:
	ldr r2, _081140E8 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081140EC @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x188]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x190]
	cmp r0, #0
	beq _081140F0
	bl VM_GetValue
	b _081140F4
	.align 2, 0
_081140E8: .4byte 0x00000252
_081140EC: .4byte 0x000004B4
_081140F0:
	ldr r4, [sp, #0x188]
	ldrb r0, [r4]
_081140F4:
	strb r0, [r6]
	ldr r5, [sp, #0x188]
	ldrb r1, [r5]
	ldr r6, [sp, #0x190]
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
	blt _0811412C
	cmp r1, #0
	blt _0811412C
	ldr r0, _08114130 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811412C
	ldr r0, _08114134 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08114138
_0811412C:
	movs r1, #0
	b _08114146
	.align 2, 0
_08114130: .4byte 0x030046A8
_08114134: .4byte 0x030046AC
_08114138:
	ldr r0, _08114160 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08114146:
	ldr r2, _08114164 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08114168
	adds r0, #4
	b _08114174
	.align 2, 0
_08114160: .4byte 0x030046A4
_08114164: .4byte 0x00000256
_08114168:
	ldr r0, _08114188 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08114174:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811418C
	cmp r2, #2
	beq _08114190
	b _08114194
	.align 2, 0
_08114188: .4byte 0x030046A4
_0811418C:
	ldrb r0, [r4, #4]
	b _08114192
_08114190:
	ldrb r0, [r4]
_08114192:
	subs r1, r1, r0
_08114194:
	ldr r3, _081141AC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081141B0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _081141F4
	.align 2, 0
_081141AC: .4byte 0x00000472
_081141B0: .4byte 0x0000FFFF
_081141B4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08114218 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0811421C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08114220 @ =0x000004B4
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
	str r5, [sp, #0x188]
	str r4, [sp, #0x18c]
	str r3, [sp, #0x190]
_081141F4:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0811423E
	bl VM_GetPC
	cmp r0, #0
	beq _08114224
	bl VM_GetValue
	adds r4, r0, #0
	b _08114226
	.align 2, 0
_08114218: .4byte 0x00000251
_0811421C: .4byte 0x00000252
_08114220: .4byte 0x000004B4
_08114224:
	movs r4, #0x30
_08114226:
	bl VM_GetPC
	cmp r0, #0
	beq _08114238
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0811423A
_08114238:
	movs r5, #0x40
_0811423A:
	mov r8, r4
	b _08114244
_0811423E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08114244:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0811427C
	bl VM_GetPC
	cmp r0, #0
	beq _0811425E
	bl VM_GetValue
	adds r6, r0, #0
	b _08114260
_0811425E:
	movs r6, #0
_08114260:
	bl VM_GetPC
	cmp r0, #0
	beq _08114270
	bl VM_GetValue
	adds r1, r0, #0
	b _08114272
_08114270:
	movs r1, #0
_08114272:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08114286
_0811427C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08114286:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	movs r1, #0x93
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x98]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x198]
	lsls r4, r4, #0x10
	str r4, [sp, #0x118]
	mov r2, r8
	lsls r2, r2, #0x10
	str r2, [sp, #0x128]
	lsls r6, r6, #0x10
	str r6, [sp, #0x12c]
	lsls r5, r5, #0x10
	str r5, [sp, #0x120]
	ldr r3, _08114510 @ =0x0000025A
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	mov r4, sb
	lsls r4, r4, #0x10
	str r4, [sp, #0x110]
	adds r5, r7, #0
	adds r5, #0x8c
	str r5, [sp, #0x40]
	movs r6, #0xf4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x108]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	adds r2, r7, #0
	adds r2, #0xa8
	str r2, [sp, #0x50]
	adds r3, r7, #0
	adds r3, #0xac
	str r3, [sp, #0x54]
	adds r4, r7, #0
	adds r4, #8
	str r4, [sp, #0x38]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x70]
	ldr r6, _08114514 @ =0x0000047A
	adds r6, r7, r6
	str r6, [sp, #0x64]
	ldr r1, _08114518 @ =0x0000047C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _0811451C @ =0x0000047E
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r3, _08114520 @ =0x00000476
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08114524 @ =0x000004A4
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xb0
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _08114528 @ =0x000005A4
	adds r5, r7, r5
	str r5, [sp, #0x100]
	movs r6, #0xb8
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x130]
	ldr r1, _0811452C @ =0x000005C4
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _08114530 @ =0x000005CC
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08114534 @ =0x000005D4
	adds r4, r7, r4
	str r4, [sp, #0x144]
	ldr r5, _08114538 @ =0x000005DC
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	movs r6, #0xb9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x138]
	ldr r1, _0811453C @ =0x00000584
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _08114540 @ =0x00000604
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08114544 @ =0x0000021D
	adds r4, r7, r4
	str r4, [sp, #0x154]
	ldr r5, _08114548 @ =0x0000060C
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	movs r6, #0xbe
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x164]
	ldr r1, _0811454C @ =0x000005E4
	adds r1, r7, r1
	str r1, [sp, #0x158]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x168]
	ldr r3, _08114550 @ =0x000005FC
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xc0
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	ldr r5, _08114554 @ =0x00000614
	adds r5, r7, r5
	str r5, [sp, #0x184]
	movs r6, #0xc3
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x194]
	ldr r1, _08114558 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x124]
	movs r2, #0xbd
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _0811455C @ =0x000005EC
	adds r4, r7, r4
	str r4, [sp, #0x160]
	movs r5, #0xbb
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _08114560 @ =0x00000624
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _08114564 @ =0x0000058C
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xc5
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1a8]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	ldr r5, _08114568 @ =0x00000594
	adds r5, r7, r5
	str r5, [sp, #0xe8]
	movs r6, #0xb3
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xec]
	ldr r1, _0811456C @ =0x0000059C
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	ldr r2, _08114570 @ =0x000005B4
	adds r2, r7, r2
	str r2, [sp, #0x114]
	ldr r3, _08114574 @ =0x00000543
	adds r3, r7, r3
	str r3, [sp, #0x8c]
	ldr r4, [sp, #0x28]
	adds r4, #8
	str r4, [sp, #0x3c]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _08114578 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _0811457C @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08114580 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _08114584 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _08114588 @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc4]
	ldr r6, _0811458C @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	ldr r2, _08114590 @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0xac]
	ldr r3, _08114594 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0xb0]
	ldr r4, _08114598 @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0xb4]
	ldr r5, _0811459C @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0xb8]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r1, _081145A0 @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r3, #0xe6
	lsls r3, r3, #3
	ldr r2, [sp, #0x24]
	adds r3, r2, r3
	str r3, [sp, #0x34]
	cmp r0, #0
	bne _081144E0
	b _081145FA
_081144E0:
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
_08114500:
	bl VM_GetPC
	cmp r0, #0
	beq _081145A4
	bl VM_GetValue
	b _081145A6
	.align 2, 0
_08114510: .4byte 0x0000025A
_08114514: .4byte 0x0000047A
_08114518: .4byte 0x0000047C
_0811451C: .4byte 0x0000047E
_08114520: .4byte 0x00000476
_08114524: .4byte 0x000004A4
_08114528: .4byte 0x000005A4
_0811452C: .4byte 0x000005C4
_08114530: .4byte 0x000005CC
_08114534: .4byte 0x000005D4
_08114538: .4byte 0x000005DC
_0811453C: .4byte 0x00000584
_08114540: .4byte 0x00000604
_08114544: .4byte 0x0000021D
_08114548: .4byte 0x0000060C
_0811454C: .4byte 0x000005E4
_08114550: .4byte 0x000005FC
_08114554: .4byte 0x00000614
_08114558: .4byte 0x000005BC
_0811455C: .4byte 0x000005EC
_08114560: .4byte 0x00000624
_08114564: .4byte 0x0000058C
_08114568: .4byte 0x00000594
_0811456C: .4byte 0x0000059C
_08114570: .4byte 0x000005B4
_08114574: .4byte 0x00000543
_08114578: .4byte 0x00000496
_0811457C: .4byte 0x00000469
_08114580: .4byte 0x0000046A
_08114584: .4byte 0x00000553
_08114588: .4byte 0x00000572
_0811458C: .4byte 0x0000055C
_08114590: .4byte 0x00000564
_08114594: .4byte 0x00000565
_08114598: .4byte 0x00000566
_0811459C: .4byte 0x00000567
_081145A0: .4byte 0x0000056C
_081145A4:
	movs r0, #0x18
_081145A6:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081145B8
	bl VM_GetValue
	b _081145BA
_081145B8:
	movs r0, #0x18
_081145BA:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081145CC
	bl VM_GetValue
	b _081145CE
_081145CC:
	movs r0, #0
_081145CE:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081145E0
	bl VM_GetValue
	b _081145E2
_081145E0:
	movs r0, #0
_081145E2:
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
	ble _08114500
_081145FA:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08114646
	bl VM_GetPC
	cmp r0, #0
	beq _08114614
	bl VM_GetValue
	adds r4, r0, #0
	b _08114618
_08114614:
	movs r4, #0x96
	lsls r4, r4, #1
_08114618:
	bl VM_GetPC
	cmp r0, #0
	beq _08114628
	bl VM_GetValue
	adds r6, r0, #0
	b _0811462C
_08114628:
	movs r6, #0x96
	lsls r6, r6, #1
_0811462C:
	bl VM_GetPC
	cmp r0, #0
	beq _0811463A
	bl VM_GetValue
	b _08114640
_0811463A:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08114640:
	ldr r2, [sp, #0x180]
	strh r0, [r2]
	b _0811464E
_08114646:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x180]
	strh r6, [r3]
_0811464E:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08114666
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08114666:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x98]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x94]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08114734
	bl VM_GetPC
	cmp r0, #0
	beq _08114696
	bl VM_GetValue
	b _08114698
_08114696:
	movs r0, #0
_08114698:
	ldr r3, [sp, #0x198]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081146A6
	asrs r1, r0, #1
	b _081146AC
_081146A6:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081146AC:
	ldr r5, _081146C0 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081146C4
	bl VM_GetValue
	b _081146C6
	.align 2, 0
_081146C0: .4byte 0x00000546
_081146C4:
	movs r0, #0
_081146C6:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081146DC
	bl VM_GetValue
	b _081146DE
_081146DC:
	movs r0, #0
_081146DE:
	ldr r3, _081146F4 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081146F8
	bl VM_GetValue
	adds r1, r0, #0
	b _081146FA
	.align 2, 0
_081146F4: .4byte 0x00000187
_081146F8:
	movs r1, #0
_081146FA:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08114710
	bl VM_GetValue
	b _08114712
_08114710:
	movs r0, #0
_08114712:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0811472A
	bl VM_GetValue
	adds r1, r0, #0
	b _0811472C
_0811472A:
	movs r1, #0
_0811472C:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08114734:
	ldr r5, [sp, #0x198]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x118]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x128]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x12c]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x120]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08114796
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0811477C
	bl VM_GetValue
	b _0811477E
_0811477C:
	movs r0, #0
_0811477E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0811478E
	bl VM_GetValue
	b _08114790
_0811478E:
	movs r0, #0
_08114790:
	ldr r6, _081147F8 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08114796:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081147BA
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081147BA:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081147D2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x88]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081147D2:
	ldr r4, [sp, #0x110]
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
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081147FC
	movs r0, #1
	b _081147FE
	.align 2, 0
_081147F8: .4byte 0x00000189
_081147FC:
	movs r0, #0
_081147FE:
	cmp r0, #0
	beq _0811480E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08114838 @ =FUN_080f48ac
	ldr r1, [sp, #0x2c]
	bl Entity5941_Register
_0811480E:
	ldr r6, [sp, #0x1a0]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _0811481A
	ldr r1, [r7, #0x44]
_0811481A:
	ldr r0, [sp, #0x2c]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0xfc]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _0811483C
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x40]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08114848
	.align 2, 0
_08114838: .4byte FUN_080f48ac
_0811483C:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x40]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08114848:
	ldr r2, [sp, #0xfc]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08114896
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08114896
	cmp r0, #0x16
	beq _08114896
	cmp r0, #0x14
	beq _08114896
	cmp r0, #9
	beq _08114896
	cmp r0, #0x19
	beq _08114896
	cmp r0, #0x1a
	beq _08114896
	cmp r0, #0xd
	beq _08114896
	cmp r0, #0x1b
	beq _08114896
	cmp r0, #0x1f
	beq _08114896
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x188]
	ldrb r2, [r3]
	ldr r4, [sp, #0x18c]
	ldrb r3, [r4]
	ldr r5, [sp, #0x190]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl Mover_SetPath
_08114896:
	movs r1, #8
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081148A6
	movs r0, #1
	b _081148A8
_081148A6:
	movs r0, #0
_081148A8:
	cmp r0, #0
	beq _081148B6
	ldr r1, [sp, #0x10c]
	ldr r0, [r1]
	ldr r2, [sp, #0x108]
	str r0, [r2]
	b _081148C8
_081148B6:
	ldr r3, [sp, #0x10c]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x108]
	str r0, [r4]
_081148C8:
	ldrh r0, [r7]
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	ldr r6, [sp, #0x38]
	ldr r0, [sp, #0x54]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _081148F2
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
_081148F2:
	adds r0, r7, #0
	bl FUN_081055ac
	adds r0, r7, #0
	bl FUN_081065ec
	adds r0, r7, #0
	bl FUN_08108634
	movs r4, #0xf7
	ldr r5, _0811493C @ =0x00000101
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x70]
	strh r0, [r3]
	ldr r6, [sp, #0x64]
	strh r4, [r6]
	ldr r0, [sp, #0x68]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0xf7
	ldr r1, [sp, #0x6c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x1a0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08114940
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0811494C
	.align 2, 0
_0811493C: .4byte 0x00000101
_08114940:
	ldr r2, [r7, #0x44]
	ldr r0, _08114984 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0811494C:
	ldr r3, [sp, #0x1a0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0811499C
	ldr r4, [sp, #0xfc]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08114988
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
	b _08114992
	.align 2, 0
_08114984: .4byte 0x03003584
_08114988:
	ldr r5, [sp, #0xfc]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08114992:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0811499C:
	movs r4, #0
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	adds r0, #6
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r2, [sp, #0x60]
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_08106234
	adds r0, r7, #0
	bl FUN_08103504
	ldr r3, [sp, #0x24]
	ldr r5, _08114B44 @ =0x0000076C
	adds r0, r3, r5
	movs r6, #0xf2
	lsls r6, r6, #3
	adds r3, r3, r6
	mov r8, r3
	ldr r1, _08114B48 @ =FUN_08113c2c
	mov sb, r1
	ldr r2, _08114B4C @ =FUN_08105170
	mov sl, r2
	ldr r3, _08114B50 @ =FUN_0810bad8
	mov ip, r3
	ldr r5, _08114B54 @ =FUN_0810caa4
	ldr r3, _08114B58 @ =FUN_080f62b0
	ldr r6, _08114B5C @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x84]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x7c]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x80]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xd0]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xdc]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0xe4]
	str r2, [r6]
	ldr r1, _08114B60 @ =FUN_081091cc
	ldr r2, [sp, #0xf8]
	str r1, [r2]
	ldr r6, _08114B64 @ =FUN_081091fc
	ldr r1, [sp, #0x100]
	str r6, [r1]
	ldr r2, _08114B68 @ =FUN_0810c1b0
	ldr r6, [sp, #0x130]
	str r2, [r6]
	ldr r1, [sp, #0x134]
	str r3, [r1]
	ldr r2, [sp, #0x13c]
	str r5, [r2]
	ldr r3, _08114B6C @ =FUN_0810e2a0
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r1, _08114B70 @ =FUN_080f44f4
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _08114B74 @ =FUN_080f410c
	ldr r2, [sp, #0x14c]
	str r1, [r2]
	ldr r3, _08114B78 @ =FUN_0810c8dc
	ldr r5, [sp, #0x138]
	str r3, [r5]
	ldr r6, _08114B7C @ =FUN_0810c520
	ldr r1, [sp, #0xd8]
	str r6, [r1]
	ldr r2, [sp, #0x1ac]
	ldr r3, [sp, #0x174]
	str r2, [r3]
	ldr r1, _08114B80 @ =FUN_080f0430
	ldr r5, [sp, #0x178]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0x154]
	strb r1, [r6]
	ldr r1, _08114B84 @ =0x085AD470
	ldr r2, [sp, #0x17c]
	str r1, [r2]
	ldr r1, _08114B88 @ =FUN_080e73c8
	ldr r3, [sp, #0x164]
	str r1, [r3]
	ldr r5, [sp, #0x158]
	str r4, [r5]
	ldr r6, [sp, #0x168]
	str r4, [r6]
	ldr r1, [sp, #0x16c]
	str r4, [r1]
	ldr r2, [sp, #0x170]
	str r4, [r2]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r1, _08114B8C @ =FUN_080f0320
	ldr r5, [sp, #0x194]
	str r1, [r5]
	ldr r1, _08114B90 @ =Enemy_080eff14
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r1, _08114B94 @ =FUN_080e72b0
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, [sp, #0x150]
	str r4, [r3]
	ldr r1, _08114B98 @ =FUN_080f47c8
	ldr r5, [sp, #0x160]
	str r1, [r5]
	ldr r1, _08114B9C @ =FUN_080f54e4
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r1, [sp, #0x104]
	str r4, [r1]
	ldr r1, _08114BA0 @ =FUN_080f6e64
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _08114BA4 @ =FUN_080f64f0
	ldr r3, [sp, #0xe0]
	str r1, [r3]
	ldr r1, _08114BA8 @ =FUN_080f84d4
	ldr r5, [sp, #0x1a8]
	str r1, [r5]
	ldr r1, _08114BAC @ =FUN_080f624c
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _08114BB0 @ =FUN_080f56ec
	ldr r2, [sp, #0xe8]
	str r1, [r2]
	ldr r1, _08114BB4 @ =FUN_080f5b34
	ldr r3, [sp, #0xec]
	str r1, [r3]
	ldr r1, _08114BB8 @ =FUN_080f5fac
	ldr r5, [sp, #0xf4]
	str r1, [r5]
	ldr r6, [sp, #0x114]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0x8c]
	strb r1, [r2]
	ldr r1, [sp, #0x3c]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114BBC @ =FUN_0810342c
	str r0, [r1]
	ldr r5, _08114BC0 @ =0x000005FC
	adds r0, r7, r5
	str r4, [r0]
	movs r6, #0xc3
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08114BC4 @ =FUN_0810608c
	str r0, [r1]
	ldr r1, _08114BC8 @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08114AFA
	b _08114C54
_08114AFA:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08114BEC
	subs r3, #0x4c
	adds r1, r7, r3
	ldr r0, _08114BCC @ =FUN_081061fc
	str r0, [r1]
	movs r4, #0xb6
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08114BD0 @ =FUN_08106230
	str r0, [r1]
	subs r5, #0x70
	adds r1, r7, r5
	ldr r0, _08114BD4 @ =FUN_08112c68
	str r0, [r1]
	subs r6, #0x10
	adds r1, r7, r6
	ldr r0, _08114BD8 @ =FUN_081061b0
	str r0, [r1]
	ldr r0, _08114BDC @ =0x0000060C
	adds r1, r7, r0
	ldr r0, _08114BE0 @ =0x085AD5D8
	str r0, [r1]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08114BE4 @ =FUN_0810e000
	str r0, [r1]
	adds r3, #0x40
	adds r1, r7, r3
	ldr r0, _08114BE8 @ =FUN_081086f8
	b _08114C7E
	.align 2, 0
_08114B44: .4byte 0x0000076C
_08114B48: .4byte FUN_08113c2c
_08114B4C: .4byte FUN_08105170
_08114B50: .4byte FUN_0810bad8
_08114B54: .4byte FUN_0810caa4
_08114B58: .4byte FUN_080f62b0
_08114B5C: .4byte FUN_080f62ac
_08114B60: .4byte FUN_081091cc
_08114B64: .4byte FUN_081091fc
_08114B68: .4byte FUN_0810c1b0
_08114B6C: .4byte FUN_0810e2a0
_08114B70: .4byte FUN_080f44f4
_08114B74: .4byte FUN_080f410c
_08114B78: .4byte FUN_0810c8dc
_08114B7C: .4byte FUN_0810c520
_08114B80: .4byte FUN_080f0430
_08114B84: .4byte 0x085AD470
_08114B88: .4byte FUN_080e73c8
_08114B8C: .4byte FUN_080f0320
_08114B90: .4byte Enemy_080eff14
_08114B94: .4byte FUN_080e72b0
_08114B98: .4byte FUN_080f47c8
_08114B9C: .4byte FUN_080f54e4
_08114BA0: .4byte FUN_080f6e64
_08114BA4: .4byte FUN_080f64f0
_08114BA8: .4byte FUN_080f84d4
_08114BAC: .4byte FUN_080f624c
_08114BB0: .4byte FUN_080f56ec
_08114BB4: .4byte FUN_080f5b34
_08114BB8: .4byte FUN_080f5fac
_08114BBC: .4byte FUN_0810342c
_08114BC0: .4byte 0x000005FC
_08114BC4: .4byte FUN_0810608c
_08114BC8: .4byte 0x000001DF
_08114BCC: .4byte FUN_081061fc
_08114BD0: .4byte FUN_08106230
_08114BD4: .4byte FUN_08112c68
_08114BD8: .4byte FUN_081061b0
_08114BDC: .4byte 0x0000060C
_08114BE0: .4byte 0x085AD5D8
_08114BE4: .4byte FUN_0810e000
_08114BE8: .4byte FUN_081086f8
_08114BEC:
	ldr r4, _08114C2C @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _08114C30 @ =FUN_081061fc
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08114C34 @ =FUN_08106230
	str r0, [r1]
	ldr r6, _08114C38 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _08114C3C @ =FUN_08112d40
	str r0, [r1]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _08114C40 @ =FUN_081061b0
	str r0, [r1]
	ldr r2, _08114C44 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08114C48 @ =0x085AD5D8
	str r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114C4C @ =FUN_0810e000
	str r0, [r1]
	adds r4, #0x40
	adds r1, r7, r4
	ldr r0, _08114C50 @ =FUN_08108788
	b _08114C7E
	.align 2, 0
_08114C2C: .4byte 0x000005AC
_08114C30: .4byte FUN_081061fc
_08114C34: .4byte FUN_08106230
_08114C38: .4byte 0x0000058C
_08114C3C: .4byte FUN_08112d40
_08114C40: .4byte FUN_081061b0
_08114C44: .4byte 0x0000060C
_08114C48: .4byte 0x085AD5D8
_08114C4C: .4byte FUN_0810e000
_08114C50: .4byte FUN_08108788
_08114C54:
	ldr r5, _08114CBC @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _08114CC0 @ =FUN_08104d70
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08114CC4 @ =FUN_08104ebc
	str r0, [r1]
	ldr r0, _08114CC8 @ =0x0000058C
	adds r1, r7, r0
	ldr r0, _08114CCC @ =FUN_08111438
	str r0, [r1]
	ldr r2, _08114CD0 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08114CD4 @ =0x085AD5B8
	str r0, [r1]
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114CD8 @ =FUN_0810de10
_08114C7E:
	str r0, [r1]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	movs r0, #0
	strh r0, [r1]
	ldr r5, _08114CDC @ =0x000001DF
	adds r0, r7, r5
	ldrb r2, [r0]
	cmp r2, #8
	bne _08114CE0
	movs r1, #0xa0
	lsls r1, r1, #0xf
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r1, [sp, #0x88]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08114D0E
	.align 2, 0
_08114CBC: .4byte 0x000005AC
_08114CC0: .4byte FUN_08104d70
_08114CC4: .4byte FUN_08104ebc
_08114CC8: .4byte 0x0000058C
_08114CCC: .4byte FUN_08111438
_08114CD0: .4byte 0x0000060C
_08114CD4: .4byte 0x085AD5B8
_08114CD8: .4byte FUN_0810de10
_08114CDC: .4byte 0x000001DF
_08114CE0:
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r4, [sp, #0x84]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _08114D40 @ =0x08000008
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #0x80
	ldr r6, [sp, #0x58]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	adds r2, r7, #0
	adds r2, #0xd8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08114D0E:
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xa0]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08114D4E
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_08114D32:
	bl VM_GetPC
	cmp r0, #0
	beq _08114D44
	bl VM_GetValue
	b _08114D46
	.align 2, 0
_08114D40: .4byte 0x08000008
_08114D44:
	movs r0, #0
_08114D46:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08114D32
_08114D4E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0xa4]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	cmp r2, #0
	beq _08114D86
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x84]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _08114D86
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_08114D86:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08114D98
	movs r0, #1
	b _08114D9A
_08114D98:
	movs r0, #0
_08114D9A:
	cmp r0, #0
	beq _08114DAC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_08114DAC:
	cmp r2, #1
	beq _08114DEC
	movs r1, #0
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, _08114DFC @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _08114E00 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x100]
	ldr r3, [r4]
	ldr r5, _08114E04 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0x90]
	strb r1, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08114DEC:
	movs r1, #2
	ldr r4, [sp, #0x58]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08114E08
	movs r0, #1
	b _08114E0A
	.align 2, 0
_08114DFC: .4byte 0x00000484
_08114E00: .4byte 0x0000046C
_08114E04: .4byte 0x0000046D
_08114E08:
	movs r0, #0
_08114E0A:
	cmp r0, #0
	beq _08114E24
	ldr r0, _08114E20 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x74]
	strh r0, [r6]
	b _08114E2E
	.align 2, 0
_08114E20: .4byte 0x030046A0
_08114E24:
	ldr r0, [sp, #0x38]
	bl GetMapAreaAt
	ldr r1, [sp, #0x74]
	strh r0, [r1]
_08114E2E:
	movs r1, #0x40
	ldr r2, [sp, #0x58]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08114E3E
	movs r0, #1
	b _08114E40
_08114E3E:
	movs r0, #0
_08114E40:
	cmp r0, #0
	beq _08114E50
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08114E74 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08114E50:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08114E82
	ldr r0, _08114E78 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x74]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08114E7C
	movs r0, #1
	b _08114E7E
	.align 2, 0
_08114E74: .4byte 0xFFFFFEFF
_08114E78: .4byte 0x030046A0
_08114E7C:
	movs r0, #0
_08114E7E:
	cmp r0, #0
	bne _08114E8A
_08114E82:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08114E8A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x1a0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08114F72
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
	beq _08114ECC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08114ED4
_08114ECC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08114ED4:
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
	beq _08114EF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08114F00
_08114EF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08114F00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08114F38 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08114F7C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08114F3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08114F30
	ldrb r0, [r4, #5]
_08114F30:
	subs r0, #1
	strh r0, [r4, #8]
	b _08114F4C
	.align 2, 0
_08114F38: .4byte 0x0000FFFF
_08114F3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08114F4C
	strh r1, [r4, #8]
_08114F4C:
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
	bne _08114F7C
	movs r0, #1
	strb r0, [r4, #7]
	b _08114F7C
_08114F72:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08114F7C:
	movs r0, #0
	ldr r3, [sp, #0xf0]
	str r0, [r3]
	ldr r0, _08114F94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08114F98
	movs r0, #1
	b _08114F9A
	.align 2, 0
_08114F94: .4byte 0x030047A4
_08114F98:
	movs r0, #0
_08114F9A:
	cmp r0, #0
	bne _08114FDA
	ldr r4, [sp, #0xfc]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08114FC2
	adds r0, r1, #0
	cmp r0, #7
	beq _08114FC2
	cmp r0, #6
	beq _08114FC2
	cmp r0, #0x15
	beq _08114FC2
	cmp r0, #0x14
	beq _08114FC2
	cmp r0, #0x17
	bne _08114FDA
_08114FC2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x58]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08114FDA:
	adds r0, r7, #0
	bl FUN_08105690
	ldr r6, _08115088 @ =0x000001DF
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #8
	bne _08115000
	movs r0, #2
	ldr r2, [sp, #0x58]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_0810770c
	adds r0, r7, #0
	bl FUN_081075dc
_08115000:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08113c18
	adds r0, r7, #0
	bl FUN_0810ff48
	adds r0, r7, #0
	bl FUN_08111424
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldr r4, [sp, #0xc8]
	strh r0, [r4]
	ldr r5, [sp, #0xd4]
	ldrh r0, [r5]
	ldr r6, [sp, #0xc4]
	strh r0, [r6]
	ldr r1, [sp, #0x84]
	ldr r0, [r1]
	ldr r2, [sp, #0x9c]
	str r0, [r2]
	ldr r3, [sp, #0x88]
	ldr r0, [r3]
	ldr r4, [sp, #0xa8]
	str r0, [r4]
	ldrb r0, [r7, #5]
	ldr r5, [sp, #0xac]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xb0]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xb4]
	strb r0, [r3]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb8]
	strb r0, [r5]
	ldr r6, [sp, #0xcc]
	ldr r0, [r6]
	ldr r1, [sp, #0xbc]
	str r0, [r1]
	ldr r2, [sp, #0x90]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, _0811508C @ =0x00000574
	adds r1, r7, r4
	ldr r5, [sp, #0x24]
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrh r0, [r0]
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x34]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08115090
	movs r0, #1
	b _08115092
	.align 2, 0
_08115088: .4byte 0x000001DF
_0811508C: .4byte 0x00000574
_08115090:
	movs r0, #0
_08115092:
	cmp r0, #0
	bne _08115098
	b _0811521C
_08115098:
	ldr r3, _08115108 @ =FUN_0810c2dc
	movs r1, #0x3c
	ldr r4, _0811510C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08115110 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, [sp, #0x90]
	strb r1, [r6]
	ldr r0, [sp, #0xcc]
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r0, #3
	ldr r3, [sp, #0x44]
	strb r0, [r3]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r6, [sp, #0x4c]
	strb r1, [r6]
	ldr r1, _08115114 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08115118 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r0, #0x10
	ldr r3, [sp, #0x34]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r4, [sp, #0x58]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _081150FA
	b _08115288
_081150FA:
	bl VM_GetPC
	cmp r0, #0
	beq _0811511C
	bl VM_GetValue
	b _0811511E
	.align 2, 0
_08115108: .4byte FUN_0810c2dc
_0811510C: .4byte 0x0000046D
_08115110: .4byte 0x0000046B
_08115114: .4byte 0x00000484
_08115118: .4byte 0x0000046C
_0811511C:
	movs r0, #0
_0811511E:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0811512E
	bl VM_GetValue
	b _08115130
_0811512E:
	movs r0, #0
_08115130:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08115140
	bl VM_GetValue
	b _08115142
_08115140:
	movs r0, #0
_08115142:
	strh r0, [r7, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _08115152
	bl VM_GetValue
	b _08115154
_08115152:
	movs r0, #0
_08115154:
	strb r0, [r7, #5]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	bl VM_GetPC
	cmp r0, #0
	beq _0811516C
	bl VM_GetValue
	adds r0, #0xdd
	b _0811516E
_0811516C:
	movs r0, #0xdd
_0811516E:
	strh r0, [r4, #0x3a]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r5, [sp, #0x38]
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08115196
	cmp r1, #0
	blt _08115196
	ldr r0, _0811519C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115196
	ldr r0, _081151A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081151A4
_08115196:
	movs r1, #0
	b _081151B2
	.align 2, 0
_0811519C: .4byte 0x030046A8
_081151A0: .4byte 0x030046AC
_081151A4:
	ldr r0, _081151CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081151B2:
	ldr r6, _081151D0 @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x38]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081151D4
	adds r0, #4
	b _081151E0
	.align 2, 0
_081151CC: .4byte 0x030046A4
_081151D0: .4byte 0x00000256
_081151D4:
	ldr r0, _081151F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081151E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081151F8
	cmp r3, #2
	beq _081151FC
	b _08115200
	.align 2, 0
_081151F4: .4byte 0x030046A4
_081151F8:
	ldrb r0, [r5, #4]
	b _081151FE
_081151FC:
	ldrb r0, [r5]
_081151FE:
	subs r2, r2, r0
_08115200:
	ldr r1, _08115218 @ =0x00000472
	adds r0, r7, r1
	strh r2, [r0]
	ldrh r1, [r7, #0xa]
	subs r1, r1, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r0]
	strh r0, [r7, #0xa]
	b _08115288
	.align 2, 0
_08115218: .4byte 0x00000472
_0811521C:
	movs r1, #8
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811522C
	movs r0, #1
	b _0811522E
_0811522C:
	movs r0, #0
_0811522E:
	cmp r0, #0
	beq _08115288
	ldr r3, _081152B4 @ =FUN_0810c464
	movs r1, #0x38
	ldr r5, _081152B8 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081152BC @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	ldr r0, [sp, #0x90]
	strb r1, [r0]
	ldr r1, [sp, #0xcc]
	str r3, [r1]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #3
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	strb r1, [r6]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, _081152C0 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _081152C4 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r3, [sp, #0x58]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x10
	ldr r4, [sp, #0x34]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_08115288:
	ldr r5, _081152C8 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081152CC @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _081152D0 @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081152D4 @ =FUN_08113ca0
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081152D8 @ =EnemySkeleton_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081152DC
	movs r0, #0
	b _081152E0
	.align 2, 0
_081152B4: .4byte FUN_0810c464
_081152B8: .4byte 0x0000046D
_081152BC: .4byte 0x0000046B
_081152C0: .4byte 0x00000484
_081152C4: .4byte 0x0000046C
_081152C8: .4byte 0x0000057C
_081152CC: .4byte FUN_080f09e0
_081152D0: .4byte 0x0000061C
_081152D4: .4byte FUN_08113ca0
_081152D8: .4byte EnemySkeleton_Destroy
_081152DC:
	movs r0, #1
	rsbs r0, r0, #0
_081152E0:
	add sp, #0x1b4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
