	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x34
	adds r5, r0, #0
	add r0, sp, #4
	ldr r1, _08212C90 @ =0x08252750
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
	adds r7, r5, #0
	adds r7, #0x94
	movs r0, #0x88
	adds r0, r0, r5
	mov sb, r0
	movs r1, #1
	mov r8, r1
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08212BAC
	movs r0, #1
_08212BAC:
	movs r6, #2
	rsbs r6, r6, #0
	ands r1, r6
	str r1, [r5, #0x44]
	cmp r0, #0
	beq _08212CAC
	adds r0, r5, #0
	bl FUN_08212510
	adds r0, r5, #0
	bl FUN_08212570
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, [r5, #0x38]
	movs r0, #2
	movs r2, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r5, #0x6c]
	ldr r3, _08212C94 @ =0x00000414
	adds r0, r5, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_082127e4
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	ands r0, r6
	str r0, [r7, #0x68]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0xa4
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #0x15
	ldr r1, [r5, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08212C74
	movs r0, #5
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
	movs r0, #2
	orrs r1, r0
	str r1, [r5, #0x44]
	adds r0, r5, #0
	bl FUN_082128b0
	adds r0, r5, #0
	bl FUN_082128d8
	ldr r0, _08212C98 @ =0x03004040
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _08212C9C @ =0x0300445C
	str r1, [r0]
_08212C74:
	ldr r0, [r5, #0x40]
	cmp r0, #2
	bne _08212CA4
	ldr r2, _08212CA0 @ =0x00000424
	adds r1, r5, r2
	movs r0, #5
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_082128b0
	adds r0, r5, #0
	bl FUN_082128d8
	b _08212CAC
	.align 2, 0
_08212C90: .4byte 0x08252750
_08212C94: .4byte 0x00000414
_08212C98: .4byte 0x03004040
_08212C9C: .4byte 0x0300445C
_08212CA0: .4byte 0x00000424
_08212CA4:
	ldr r3, _08212D54 @ =0x00000424
	adds r0, r5, r3
	mov r4, r8
	str r4, [r0]
_08212CAC:
	ldr r0, [r5, #0x64]
	cmp r0, #7
	bgt _08212CC8
	ldr r0, _08212D58 @ =0x00000381
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08212CC8
	adds r0, r5, #0
	bl FUN_082127e4
_08212CC8:
	ldr r0, [r5, #0x64]
	subs r0, #5
	cmp r0, #2
	bhi _08212D40
	ldr r1, _08212D5C @ =0x0000038E
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r4, r0, #0
	cmp r4, #0
	bne _08212D40
	add r2, sp, #0x2c
	mov r8, r2
	ldr r1, _08212D60 @ =0x08252778
	mov r0, r8
	movs r2, #8
	bl memcpy
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r6, r7, r3
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08212D0C
	strh r4, [r6]
_08212D0C:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrb r2, [r1]
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r2, [r6]
	lsls r2, r2, #1
	mov r1, sp
	adds r1, #0x2d
	adds r1, r1, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
_08212D40:
	ldr r0, [r5, #0x64]
	cmp r0, #0x63
	bls _08212D4A
	bl _082135A0
_08212D4A:
	lsls r0, r0, #2
	ldr r1, _08212D64 @ =_08212D68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08212D54: .4byte 0x00000424
_08212D58: .4byte 0x00000381
_08212D5C: .4byte 0x0000038E
_08212D60: .4byte 0x08252778
_08212D64: .4byte _08212D68
_08212D68: @ jump table
	.4byte _08212EF8 @ case 0
	.4byte _08212F3C @ case 1
	.4byte _08212FC0 @ case 2
	.4byte _0821303C @ case 3
	.4byte _08213112 @ case 4
	.4byte _08213170 @ case 5
	.4byte _08213206 @ case 6
	.4byte _082132CC @ case 7
	.4byte _082133CC @ case 8
	.4byte _08213418 @ case 9
	.4byte _08213474 @ case 10
	.4byte _082134C0 @ case 11
	.4byte _0821350C @ case 12
	.4byte _082135A0 @ case 13
	.4byte _082135A0 @ case 14
	.4byte _082135A0 @ case 15
	.4byte _082135A0 @ case 16
	.4byte _082135A0 @ case 17
	.4byte _082135A0 @ case 18
	.4byte _082135A0 @ case 19
	.4byte _082135A0 @ case 20
	.4byte _082135A0 @ case 21
	.4byte _082135A0 @ case 22
	.4byte _082135A0 @ case 23
	.4byte _082135A0 @ case 24
	.4byte _082135A0 @ case 25
	.4byte _082135A0 @ case 26
	.4byte _082135A0 @ case 27
	.4byte _082135A0 @ case 28
	.4byte _082135A0 @ case 29
	.4byte _082135A0 @ case 30
	.4byte _082135A0 @ case 31
	.4byte _082135A0 @ case 32
	.4byte _082135A0 @ case 33
	.4byte _082135A0 @ case 34
	.4byte _082135A0 @ case 35
	.4byte _082135A0 @ case 36
	.4byte _082135A0 @ case 37
	.4byte _082135A0 @ case 38
	.4byte _082135A0 @ case 39
	.4byte _082135A0 @ case 40
	.4byte _082135A0 @ case 41
	.4byte _082135A0 @ case 42
	.4byte _082135A0 @ case 43
	.4byte _082135A0 @ case 44
	.4byte _082135A0 @ case 45
	.4byte _082135A0 @ case 46
	.4byte _082135A0 @ case 47
	.4byte _082135A0 @ case 48
	.4byte _082135A0 @ case 49
	.4byte _082135A0 @ case 50
	.4byte _082135A0 @ case 51
	.4byte _082135A0 @ case 52
	.4byte _082135A0 @ case 53
	.4byte _082135A0 @ case 54
	.4byte _082135A0 @ case 55
	.4byte _082135A0 @ case 56
	.4byte _082135A0 @ case 57
	.4byte _082135A0 @ case 58
	.4byte _082135A0 @ case 59
	.4byte _082135A0 @ case 60
	.4byte _082135A0 @ case 61
	.4byte _082135A0 @ case 62
	.4byte _082135A0 @ case 63
	.4byte _082135A0 @ case 64
	.4byte _082135A0 @ case 65
	.4byte _082135A0 @ case 66
	.4byte _082135A0 @ case 67
	.4byte _082135A0 @ case 68
	.4byte _082135A0 @ case 69
	.4byte _082135A0 @ case 70
	.4byte _082135A0 @ case 71
	.4byte _082135A0 @ case 72
	.4byte _082135A0 @ case 73
	.4byte _082135A0 @ case 74
	.4byte _082135A0 @ case 75
	.4byte _082135A0 @ case 76
	.4byte _082135A0 @ case 77
	.4byte _082135A0 @ case 78
	.4byte _082135A0 @ case 79
	.4byte _082135A0 @ case 80
	.4byte _082135A0 @ case 81
	.4byte _082135A0 @ case 82
	.4byte _082135A0 @ case 83
	.4byte _082135A0 @ case 84
	.4byte _082135A0 @ case 85
	.4byte _082135A0 @ case 86
	.4byte _082135A0 @ case 87
	.4byte _082135A0 @ case 88
	.4byte _082135A0 @ case 89
	.4byte _082135A0 @ case 90
	.4byte _082135A0 @ case 91
	.4byte _082135A0 @ case 92
	.4byte _082135A0 @ case 93
	.4byte _082135A0 @ case 94
	.4byte _082135A0 @ case 95
	.4byte _082135A0 @ case 96
	.4byte _082135A0 @ case 97
	.4byte _082135A0 @ case 98
	.4byte _0821356C @ case 99
_08212EF8:
	movs r4, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, [r5, #0x64]
	ldr r2, [r5, #0x5c]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r5, #0
	adds r2, #0x70
	adds r2, r2, r1
	ldrh r2, [r2]
	ldr r3, _08212F38 @ =0x000001FF
	movs r1, #0
	bl FUN_0821b21c
	cmp r0, #0
	bne _08212F2E
	b _082135A0
_08212F2E:
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	b _08213550
	.align 2, 0
_08212F38: .4byte 0x000001FF
_08212F3C:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08212F4A
	movs r1, #1
_08212F4A:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _08212F66
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08212FB8 @ =0x00000386
	adds r0, r7, r2
	strh r1, [r0]
_08212F66:
	adds r0, r5, #0
	bl FUN_082129b8
	ldr r0, _08212FBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08212F7A
	b _082135A0
_08212F7A:
	movs r0, #3
	str r0, [r5, #0x64]
	movs r2, #0
	str r2, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r4
	str r0, [r5, #0x44]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #5
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xa8
	movs r4, #0xd0
	lsls r4, r4, #2
	adds r0, r7, r4
	str r0, [r1]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	bl FUN_082124ac
	lsls r0, r0, #2
	add r0, sp
	adds r0, #4
	ldr r0, [r0]
	bl PlaySound_082406e0
	b _082135A0
	.align 2, 0
_08212FB8: .4byte 0x00000386
_08212FBC: .4byte 0x030044E0
_08212FC0:
	movs r6, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r6
	cmp r1, #0
	beq _08212FCE
	movs r1, #1
_08212FCE:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	adds r4, r5, #0
	adds r4, #0x70
	cmp r1, #0
	beq _08212FFE
	ldr r2, [r5, #0x64]
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08213038 @ =0x03004040
	ldr r0, [r0]
	muls r0, r1, r0
	movs r1, #0x40
	bl Div
	mov r2, sb
	str r0, [r2, #4]
_08212FFE:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, [r5, #0x64]
	ldr r2, [r5, #0x5c]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, #1
	movs r3, #7
	bl FUN_0821b21c
	cmp r0, #0
	bne _08213020
	b _082135A0
_08213020:
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r6
	str r0, [r5, #0x44]
	b _082135A0
	.align 2, 0
_08213038: .4byte 0x03004040
_0821303C:
	movs r4, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	ldr r0, [r5, #0x68]
	cmp r0, #0x7c
	ble _082130F8
	ldr r0, [r7, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x68]
	adds r0, r5, #0
	bl FUN_082128b0
	adds r0, r5, #0
	bl FUN_082128d8
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r4
	str r0, [r5, #0x44]
	bl FUN_082124ec
	subs r0, #1
	cmp r0, #0xb
	bls _08213088
	b _082135A0
_08213088:
	lsls r0, r0, #2
	ldr r1, _08213094 @ =_08213098
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08213094: .4byte _08213098
_08213098: @ jump table
	.4byte _082130E6 @ case 0
	.4byte _082130E6 @ case 1
	.4byte _082130C8 @ case 2
	.4byte _082130C8 @ case 3
	.4byte _082130C8 @ case 4
	.4byte _082130D2 @ case 5
	.4byte _082130D2 @ case 6
	.4byte _082130D2 @ case 7
	.4byte _082130DC @ case 8
	.4byte _082130DC @ case 9
	.4byte _082130DC @ case 10
	.4byte _082130E6 @ case 11
_082130C8:
	bl FUN_082124ac
	lsls r0, r0, #2
	add r1, sp, #0xc
	b _082130EE
_082130D2:
	bl FUN_082124ac
	lsls r0, r0, #2
	add r1, sp, #0x14
	b _082130EE
_082130DC:
	bl FUN_082124ac
	lsls r0, r0, #2
	add r1, sp, #0x1c
	b _082130EE
_082130E6:
	bl FUN_082124ac
	lsls r0, r0, #2
	add r1, sp, #0x24
_082130EE:
	adds r1, r1, r0
	ldr r0, [r1]
	bl PlaySound_082406e0
	b _082135A0
_082130F8:
	movs r1, #4
	bl Mod
	cmp r0, #0
	beq _08213104
	b _082135A0
_08213104:
	ldr r1, [r7, #0x68]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08213160
	b _0821316A
_08213112:
	movs r2, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r2
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	ldr r0, [r5, #0x68]
	cmp r0, #0x23
	ble _08213148
	ldr r0, [r7, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x68]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r2
	str r0, [r5, #0x44]
	b _082135A0
_08213148:
	movs r1, #4
	bl Mod
	cmp r0, #0
	beq _08213154
	b _082135A0
_08213154:
	ldr r1, [r7, #0x68]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0821316A
_08213160:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x68]
	b _082135A0
_0821316A:
	orrs r1, r2
	str r1, [r7, #0x68]
	b _082135A0
_08213170:
	movs r6, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r6
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r1
	str r2, [r5, #0x44]
	ldr r0, _0821319C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _082131A0
	movs r0, #6
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	b _082131B2
	.align 2, 0
_0821319C: .4byte 0x030044E0
_082131A0:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _082131B8
	movs r0, #7
	str r0, [r5, #0x64]
	str r3, [r5, #0x68]
_082131B2:
	orrs r2, r6
	str r2, [r5, #0x44]
	b _082135A0
_082131B8:
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _082131C2
	b _082135A0
_082131C2:
	movs r0, #4
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
	orrs r2, r6
	str r2, [r5, #0x44]
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r0, #8
	str r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _082131EC
	movs r0, #0xe0
	b _082131EE
_082131EC:
	movs r0, #0xdd
_082131EE:
	bl PlaySound_082406e0
	movs r0, #0xa4
	bl sound_08240960
	cmp r0, #0
	bne _082131FE
	b _082135A0
_082131FE:
	movs r0, #2
	bl sound_fadeout_08240440
	b _082135A0
_08213206:
	movs r2, #2
	ldr r1, [r5, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08213212
	movs r2, #1
_08213212:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	adds r4, r7, #0
	adds r4, #0xe0
	cmp r2, #0
	beq _0821327E
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r2, r7, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _082132C0 @ =0x00000389
	adds r1, r7, r3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08213244
	movs r0, #0
	strb r0, [r2]
_08213244:
	adds r0, r7, #0
	adds r0, #0xc0
	adds r1, r5, #0
	adds r1, #0x18
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	adds r2, r7, #0
	adds r2, #0xc8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x90
	strh r0, [r4]
	ldr r2, _082132C4 @ =0x0000038A
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, _082132C8 @ =0x0000012B
	bl PlaySound_082406e0
_0821327E:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	bgt _08213296
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r7, r3
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #5
	movs r3, #1
	bl Sprite_SetSprite
_08213296:
	ldr r0, _082132C4 @ =0x0000038A
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #2
	movs r6, #0
	strb r0, [r1]
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r2, r2, r0
	strh r2, [r4]
	adds r0, r2, #0
	subs r0, #0x90
	adds r4, r7, #0
	adds r4, #0x80
	strh r0, [r4]
	cmp r2, #0
	ble _082132BE
	b _082135A0
_082132BE:
	b _0821337E
	.align 2, 0
_082132C0: .4byte 0x00000389
_082132C4: .4byte 0x0000038A
_082132C8: .4byte 0x0000012B
_082132CC:
	movs r2, #2
	ldr r1, [r5, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _082132D8
	movs r2, #1
_082132D8:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	adds r4, r7, #0
	adds r4, #0xe0
	cmp r2, #0
	beq _0821333E
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08213304
	ldr r1, _082133BC @ =0x00000389
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r2]
_08213304:
	adds r0, r7, #0
	adds r0, #0xc0
	adds r1, r5, #0
	adds r1, #0x18
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	adds r2, r7, #0
	adds r2, #0xc8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	ldr r0, _082133C0 @ =0x0000FF70
	strh r0, [r4]
	ldr r2, _082133C4 @ =0x0000038A
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, _082133C8 @ =0x0000012B
	bl PlaySound_082406e0
_0821333E:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	bgt _08213356
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #9
	movs r3, #1
	bl Sprite_SetSprite
_08213356:
	ldr r0, _082133C4 @ =0x0000038A
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #2
	movs r6, #0
	strb r0, [r1]
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r2, r2, r0
	strh r2, [r4]
	adds r0, r2, #0
	adds r0, #0x90
	adds r4, r7, #0
	adds r4, #0x80
	strh r0, [r4]
	cmp r2, #0
	bge _0821337E
	b _082135A0
_0821337E:
	adds r0, r7, #0
	adds r0, #0x60
	adds r1, r5, #0
	adds r1, #0x18
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	strh r6, [r4]
	adds r2, r7, #0
	adds r2, #0xc8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #5
	str r0, [r5, #0x64]
	str r6, [r5, #0x68]
	movs r1, #2
	ldr r0, [r5, #0x44]
	orrs r0, r1
	str r0, [r5, #0x44]
	b _082135A0
	.align 2, 0
_082133BC: .4byte 0x00000389
_082133C0: .4byte 0x0000FF70
_082133C4: .4byte 0x0000038A
_082133C8: .4byte 0x0000012B
_082133CC:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082133DA
	movs r1, #1
_082133DA:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _082133EC
	adds r0, r5, #0
	bl FUN_08212910
_082133EC:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	bgt _082133F4
	b _082135A0
_082133F4:
	ldr r0, _0821340C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08213410 @ =0x0000093C
	adds r0, r0, r1
	ldr r2, _08213414 @ =0x0000041C
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
	ldr r0, [r5, #0x48]
	b _08213548
	.align 2, 0
_0821340C: .4byte 0x030046A0
_08213410: .4byte 0x0000093C
_08213414: .4byte 0x0000041C
_08213418:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08213426
	movs r1, #1
_08213426:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _08213444
	adds r0, r5, #0
	bl FUN_08212910
	ldr r0, _08213464 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08213468 @ =0x0000093E
	adds r0, r0, r3
	movs r1, #0
	strh r1, [r0]
_08213444:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	bgt _0821344C
	b _082135A0
_0821344C:
	ldr r0, _08213464 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0821346C @ =0x0000093C
	adds r0, r0, r1
	ldr r2, _08213470 @ =0x0000041C
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
	ldr r0, [r5, #0x4c]
	b _08213548
	.align 2, 0
_08213464: .4byte 0x030046A0
_08213468: .4byte 0x0000093E
_0821346C: .4byte 0x0000093C
_08213470: .4byte 0x0000041C
_08213474:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08213482
	movs r1, #1
_08213482:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _08213494
	adds r0, r5, #0
	bl FUN_08212910
_08213494:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	bgt _0821349C
	b _082135A0
_0821349C:
	ldr r0, _082134B4 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _082134B8 @ =0x0000093C
	adds r0, r0, r3
	ldr r2, _082134BC @ =0x0000041C
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
	ldr r0, [r5, #0x50]
	b _08213548
	.align 2, 0
_082134B4: .4byte 0x030046A0
_082134B8: .4byte 0x0000093C
_082134BC: .4byte 0x0000041C
_082134C0:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082134CE
	movs r1, #1
_082134CE:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _082134E0
	adds r0, r5, #0
	bl FUN_08212910
_082134E0:
	ldr r0, [r5, #0x68]
	cmp r0, #4
	ble _082135A0
	ldr r0, _08213500 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08213504 @ =0x0000093C
	adds r0, r0, r3
	ldr r2, _08213508 @ =0x0000041C
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
	ldr r0, [r5, #0x54]
	b _08213548
	.align 2, 0
_08213500: .4byte 0x030046A0
_08213504: .4byte 0x0000093C
_08213508: .4byte 0x0000041C
_0821350C:
	movs r4, #2
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _0821351A
	movs r1, #1
_0821351A:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _0821352C
	adds r0, r5, #0
	bl FUN_08212910
_0821352C:
	ldr r0, [r5, #0x68]
	cmp r0, #0x3c
	ble _082135A0
	ldr r0, _08213560 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08213564 @ =0x0000093C
	adds r0, r0, r3
	ldr r2, _08213568 @ =0x0000041C
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
	ldr r0, [r5, #0x58]
_08213548:
	movs r1, #0
	bl Script_ExecById
	movs r0, #0x63
_08213550:
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r4
	str r0, [r5, #0x44]
	b _082135A0
	.align 2, 0
_08213560: .4byte 0x030046A0
_08213564: .4byte 0x0000093C
_08213568: .4byte 0x0000041C
_0821356C:
	movs r2, #2
	ldr r1, [r5, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08213578
	movs r2, #1
_08213578:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	cmp r2, #0
	beq _0821358E
	ldr r0, _08213598 @ =0x03004040
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _0821359C @ =0x0300445C
	str r1, [r0]
_0821358E:
	adds r0, r5, #0
	bl KillEntity
	b _082135E4
	.align 2, 0
_08213598: .4byte 0x03004040
_0821359C: .4byte 0x0300445C
_082135A0:
	ldr r0, [r5, #0x64]
	cmp r0, #1
	beq _082135AA
	cmp r0, #5
	bne _082135E0
_082135AA:
	adds r1, r5, #0
	adds r1, #0x84
	ldr r0, [r5, #0x60]
	ldrh r1, [r1]
	cmp r0, r1
	blt _082135E4
	movs r1, #2
	str r1, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r1
	str r0, [r5, #0x44]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xc
	str r0, [r1]
	movs r0, #0xa4
	bl sound_08240960
	cmp r0, #0
	beq _082135E4
	movs r0, #3
	bl sound_fadeout_08240440
	b _082135E4
_082135E0:
	movs r0, #0
	str r0, [r5, #0x60]
_082135E4:
	add sp, #0x34
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
