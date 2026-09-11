	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	str r1, [sp, #0x24]
	mov sb, r7
	movs r0, #0x74
	movs r1, #7
	bl VM_GetKeywordValue
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08022a0c
	ldr r0, _0804057C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _08040580
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r1, r7, r3
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08040590
	.align 2, 0
_0804057C: .4byte 0x03002BE0
_08040580:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r7, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	str r2, [r0]
_08040590:
	ldr r0, _08040600 @ =0x0000CB05
	ldr r1, _08040604 @ =0x00005D36
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _080405A0
	b _08040D30
_080405A0:
	movs r6, #0xcb
	lsls r6, r6, #2
	adds r0, r7, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040610
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08040608 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0804060C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r6, r0, #0
	b _08040638
	.align 2, 0
_08040600: .4byte 0x0000CB05
_08040604: .4byte 0x00005D36
_08040608: .4byte 0xFFFF0000
_0804060C: .4byte 0x0000FFFF
_08040610:
	ldr r0, _08040674 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08040678 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _0804067C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r6, #0x40
_08040638:
	ldr r0, [sp, #0x1c]
	asrs r0, r0, #0x10
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040684
	bl Script_GetValue
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08040680 @ =0x0000028E
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r0, [r1]
	b _080406A4
	.align 2, 0
_08040674: .4byte 0x030046A0
_08040678: .4byte 0xFFFF0000
_0804067C: .4byte 0x0000FFFF
_08040680: .4byte 0x0000028E
_08040684:
	ldr r0, _080406C8 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x32]
	ldr r4, _080406CC @ =0x0000028E
	adds r0, r7, r4
	strh r2, [r0]
	ldrh r1, [r1, #0x34]
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r7, r5
	strh r1, [r0]
_080406A4:
	adds r0, r7, #0
	bl FUN_0803c590
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080406D0
	bl Script_GetValue
	str r0, [sp, #0x28]
	bl Script_GetValue
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r1, r7, r2
	b _080406DE
	.align 2, 0
_080406C8: .4byte 0x030046A0
_080406CC: .4byte 0x0000028E
_080406D0:
	movs r3, #0xfa
	lsls r3, r3, #2
	str r3, [sp, #0x28]
	movs r4, #0xb1
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0x64
_080406DE:
	strh r0, [r1]
	ldr r5, _0804077C @ =0x0000030E
	adds r0, r7, r5
	movs r1, #0x40
	strb r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x4d
	movs r1, #0x80
	bl VM_GetKeywordValue
	ldr r3, _08040780 @ =0x000002C6
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040790
	bl Script_GetValue
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	subs r5, #0x44
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040784 @ =0x000002CE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040788 @ =0x000002D6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0xc
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _0804078C @ =0x000002DA
	adds r1, r7, r2
	b _080407E8
	.align 2, 0
_0804077C: .4byte 0x0000030E
_08040780: .4byte 0x000002C6
_08040784: .4byte 0x000002CE
_08040788: .4byte 0x000002D6
_0804078C: .4byte 0x000002DA
_08040790:
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0x32
	strh r2, [r0]
	ldr r4, _08040880 @ =0x000002CA
	adds r0, r7, r4
	strh r2, [r0]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _08040884 @ =0x000002CE
	adds r1, r7, r0
	movs r0, #0x5a
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r2, [r0]
	ldr r2, _08040888 @ =0x000002D2
	adds r0, r7, r2
	movs r2, #0x3c
	strh r2, [r0]
	adds r3, #0xc
	adds r1, r7, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r4, #0xc
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	adds r5, #0x10
	adds r0, r7, r5
	strh r2, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #4
	strh r0, [r1]
	ldr r2, _0804088C @ =0x000002DA
	adds r1, r7, r2
	movs r0, #0x2d
_080407E8:
	strh r0, [r1]
	movs r0, #0x53
	bl VM_SeekToKeyword
	adds r3, r0, #0
	cmp r3, #0
	beq _080408A4
	bl Script_GetValue
	ldr r3, _08040890 @ =0x000002DE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _08040894 @ =0x000002E2
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040898 @ =0x000002E6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0804089C @ =0x000002EE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080408A0 @ =0x000002F6
	adds r1, r7, r3
	b _08040906
	.align 2, 0
_08040880: .4byte 0x000002CA
_08040884: .4byte 0x000002CE
_08040888: .4byte 0x000002D2
_0804088C: .4byte 0x000002DA
_08040890: .4byte 0x000002DE
_08040894: .4byte 0x000002E2
_08040898: .4byte 0x000002E6
_0804089C: .4byte 0x000002EE
_080408A0: .4byte 0x000002F6
_080408A4:
	ldr r4, _08040974 @ =0x000002DE
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	movs r5, #0xb8
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r2, #0x3c
	strh r2, [r0]
	ldr r1, _08040978 @ =0x000002E2
	adds r0, r7, r1
	strh r2, [r0]
	adds r4, #6
	adds r1, r7, r4
	movs r0, #0x14
	strh r0, [r1]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r4, #6
	adds r0, r7, r4
	strh r1, [r0]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, _0804097C @ =0x000002EE
	adds r0, r7, r1
	strh r2, [r0]
	adds r4, #6
	adds r0, r7, r4
	strh r2, [r0]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x19
	strh r0, [r1]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	ldr r2, _08040980 @ =0x000002F6
	adds r1, r7, r2
	movs r0, #4
_08040906:
	strh r0, [r1]
	movs r0, #0x42
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040990
	bl Script_GetValue
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08040984 @ =0x000002FA
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xbf
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08040988 @ =0x000002FE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0xa
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #0xa
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0804098C @ =0x00000302
	adds r1, r7, r3
	b _080409D8
	.align 2, 0
_08040974: .4byte 0x000002DE
_08040978: .4byte 0x000002E2
_0804097C: .4byte 0x000002EE
_08040980: .4byte 0x000002F6
_08040984: .4byte 0x000002FA
_08040988: .4byte 0x000002FE
_0804098C: .4byte 0x00000302
_08040990:
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0x46
	strh r0, [r1]
	ldr r5, _080409FC @ =0x000002FA
	adds r0, r7, r5
	movs r3, #0x1e
	strh r3, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #8
	strh r2, [r0]
	adds r4, #6
	adds r1, r7, r4
	movs r0, #0x18
	strh r0, [r1]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	ldr r3, _08040A00 @ =0x00000306
	adds r0, r7, r3
	strh r2, [r0]
	adds r4, #0xa
	adds r1, r7, r4
	movs r0, #0x20
	strh r0, [r1]
	adds r5, #2
	adds r1, r7, r5
	movs r0, #0xf
_080409D8:
	strh r0, [r1]
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040A08
	bl Script_GetValue
	movs r2, #0xc4
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08040A04 @ =0x00000311
	adds r1, r7, r3
	strb r0, [r1]
	b _08040A18
	.align 2, 0
_080409FC: .4byte 0x000002FA
_08040A00: .4byte 0x00000306
_08040A04: .4byte 0x00000311
_08040A08:
	movs r4, #0xc4
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #2
	strb r1, [r0]
	ldr r5, _08040AAC @ =0x00000311
	adds r0, r7, r5
	strb r1, [r0]
_08040A18:
	movs r0, #0x6f
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r7, r3
	str r0, [r1]
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #0
	str r1, [r0]
	movs r5, #0xc7
	lsls r5, r5, #2
	adds r0, r7, r5
	str r1, [r0]
	movs r0, #0x4f
	bl VM_SeekToKeyword
	mov r4, sb
	adds r4, #0xab
	movs r1, #0xa4
	adds r1, r1, r7
	mov sl, r1
	adds r2, r7, #0
	adds r2, #0xa5
	str r2, [sp, #0x30]
	adds r3, r7, #0
	adds r3, #0xa6
	str r3, [sp, #0x34]
	adds r5, r7, #0
	adds r5, #0xbc
	str r5, [sp, #0x44]
	adds r1, r7, #0
	adds r1, #0xa8
	str r1, [sp, #0x38]
	ldr r2, _08040AB0 @ =0x0000081C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	mov r3, sb
	adds r3, #0xa3
	str r3, [sp, #0x3c]
	mov r5, sb
	adds r5, #0xf8
	str r5, [sp, #0x48]
	mov r1, sb
	adds r1, #0x8c
	str r1, [sp, #0x2c]
	mov r2, sb
	adds r2, #0xa9
	str r2, [sp, #0x40]
	adds r3, #0x59
	str r3, [sp, #0x4c]
	movs r5, #0x80
	lsls r5, r5, #1
	add r5, sb
	str r5, [sp, #0x50]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	beq _08040ADE
	movs r5, #0
	b _08040AD2
	.align 2, 0
_08040AAC: .4byte 0x00000311
_08040AB0: .4byte 0x0000081C
_08040AB4:
	bl Script_GetValue
	lsls r2, r5, #1
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r1, r7, r3
	adds r1, r1, r2
	strh r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r5, #1
_08040AD2:
	cmp r5, #3
	bgt _08040ADE
	bl VM_GetPC
	cmp r0, #0
	bne _08040AB4
_08040ADE:
	ldr r2, _08040B14 @ =0x0000030A
	adds r1, r7, r2
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	str r6, [sp]
	mov r0, sb
	ldr r1, [sp, #0x24]
	mov r2, r8
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	ldrb r0, [r4]
	cmp r0, #0
	beq _08040B18
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	b _08040B20
	.align 2, 0
_08040B14: .4byte 0x0000030A
_08040B18:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0x40
_08040B20:
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r6, r7, r0
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, sb
	adds r1, r6, #0
	mov r2, r8
	movs r3, #0
	bl FUN_08022d24
	movs r0, #0x78
	mov r3, sl
	strb r5, [r3]
	ldr r6, [sp, #0x30]
	strb r5, [r6]
	ldr r1, [sp, #0x34]
	strb r5, [r1]
	ldr r2, [sp, #0x44]
	str r5, [r2]
	ldr r3, [sp, #0x38]
	strb r4, [r3]
	ldr r6, [sp, #0x54]
	strh r0, [r6]
	ldr r0, _08040BE0 @ =FUN_0803e6b0
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	ldr r2, [sp, #0x48]
	str r0, [r2]
	ldr r3, [sp, #0x2c]
	str r5, [r3]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r0, _08040BE4 @ =FUN_080401ec
	ldr r6, [sp, #0x4c]
	str r0, [r6]
	ldr r0, _08040BE8 @ =FUN_080401a8
	ldr r1, [sp, #0x50]
	str r0, [r1]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r4, r7, r2
	ldrh r3, [r4]
	mov r0, sb
	ldr r1, [sp, #0x28]
	adds r2, r1, #0
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_0803cca4
	ldrh r1, [r4]
	adds r0, r7, #0
	bl FUN_0803cdf8
	adds r0, r7, #0
	bl FUN_0803cd4c
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040BEC
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _08040BF6
	.align 2, 0
_08040BE0: .4byte FUN_0803e6b0
_08040BE4: .4byte FUN_080401ec
_08040BE8: .4byte FUN_080401a8
_08040BEC:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_08040BF6:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040C1C
	movs r5, #0
	mov r4, sb
	adds r4, #0xe8
	b _08040C10
_08040C08:
	bl Script_GetValue
	stm r4!, {r0}
	adds r5, #1
_08040C10:
	cmp r5, #3
	bgt _08040C1C
	bl VM_GetPC
	cmp r0, #0
	bne _08040C08
_08040C1C:
	adds r0, r7, #0
	bl FUN_0803ce8c
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0x40
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r1, _08040CC4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	ldr r0, _08040CC8 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x99
	lsls r1, r1, #6
	adds r6, r0, r1
	movs r2, #0x83
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r5, #0xf
_08040C6E:
	adds r0, r6, #0
	adds r1, r4, #0
	ldr r2, _08040CCC @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08040C6E
	adds r0, r7, #0
	bl FUN_0803c1bc
	ldr r1, _08040CC8 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r5, #0xf
_08040C96:
	adds r0, r6, #0
	adds r1, r4, #0
	ldr r2, _08040CCC @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08040C96
	adds r0, r7, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _08040CD0
	movs r4, #0x83
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [sp, #0x58]
	str r0, [r5]
	b _08040CDC
	.align 2, 0
_08040CC4: .4byte 0x00001C1B
_08040CC8: .4byte 0x03003584
_08040CCC: .4byte 0x04000008
_08040CD0:
	ldr r0, _08040D1C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r6, [sp, #0x58]
	str r0, [r6]
_08040CDC:
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r7, #0
	bl FUN_0803c6f0
	ldr r2, _08040D20 @ =0x00000818
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r3, _08040D24 @ =0x0000081A
	adds r1, r7, r3
	movs r0, #7
	strh r0, [r1]
	bl FUN_0805e67c
	ldr r4, _08040D28 @ =0x00000954
	adds r1, r7, r4
	str r0, [r1]
	cmp r0, #0
	beq _08040D30
	movs r0, #0x78
	bl FUN_0805ee80
	ldr r5, _08040D2C @ =0x00000958
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _08040D30
	movs r0, #0
	b _08040D34
	.align 2, 0
_08040D1C: .4byte 0x03003584
_08040D20: .4byte 0x00000818
_08040D24: .4byte 0x0000081A
_08040D28: .4byte 0x00000954
_08040D2C: .4byte 0x00000958
_08040D30:
	movs r0, #1
	rsbs r0, r0, #0
_08040D34:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
