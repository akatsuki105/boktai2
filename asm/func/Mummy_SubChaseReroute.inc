	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x64
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _08126B60 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08126B64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08126B66
	.align 2, 0
_08126B60: .4byte 0x0000046C
_08126B64:
	movs r0, #0
_08126B66:
	cmp r0, #0
	beq _08126BBA
	ldr r3, _08126D34 @ =0x000005A4
	adds r0, r7, r3
	ldr r2, [r0]
	movs r3, #0
	ldr r4, _08126D38 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08126D3C @ =0x0000046B
	adds r0, r7, r5
	strb r3, [r0]
	ldr r6, _08126D40 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _08126D44 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _08126D48 @ =0x00000202
	adds r0, r7, r6
	strh r3, [r0]
_08126BBA:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _08126BD4
	b _081272C0
_08126BD4:
	ldr r2, _08126D4C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08126BE0
	b _081272BC
_08126BE0:
	ldr r3, _08126D50 @ =0x00000222
	adds r3, r3, r7
	mov r8, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _08126D54 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _08126D38 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0xc]
	movs r4, #1
	ldr r5, [sp, #0xc]
	strb r4, [r5]
	ldr r6, _08126D3C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #0
	strb r2, [r6]
	ldr r3, _08126D40 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x14]
	strb r0, [r3]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sb, r6
	mov r0, ip
	strh r0, [r6]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #0xc
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08126D58 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r7, r1
	str r1, [sp, #0x60]
	strb r0, [r1]
	ldr r2, _08126D5C @ =0x00000469
	adds r5, r7, r2
	strb r4, [r5]
	subs r6, #0xe8
	adds r3, r7, r6
	movs r0, #0
	strb r0, [r3]
	ldr r1, _08126D4C @ =0x00000484
	adds r2, r7, r1
	mov r6, ip
	str r6, [r2]
	ldr r0, _08126D60 @ =0x0000046C
	adds r1, r7, r0
	strb r4, [r1]
	ldr r4, [sp, #8]
	ldr r6, _08126D64 @ =0x000006FE
	adds r0, r4, r6
	ldrh r0, [r0]
	str r1, [sp, #0x4c]
	ldr r1, [sp, #0xc]
	str r1, [sp, #0x50]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x48]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x30]
	mov r1, sl
	str r1, [sp, #0x34]
	mov r4, sb
	str r4, [sp, #0x5c]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r3, [sp, #0x44]
	str r2, [sp, #0x58]
	cmp r0, #0
	beq _08126D7C
	ldr r0, _08126D68 @ =0x00000256
	adds r2, r7, r0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x18]
	ldrh r0, [r2]
	ldrh r1, [r1, #6]
	cmp r0, r1
	bne _08126D7C
	adds r0, r7, #0
	bl Mummy_RouteToFloorEnd
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08126CCE
	b _081272C0
_08126CCE:
	ldr r4, [r7, #0x24]
	ldr r2, _08126D6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08126D70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08126D74 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r4, #2]
	cmp r0, r3
	bne _08126D06
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08126D06:
	strb r0, [r4, #2]
	movs r5, #0
	strb r5, [r4, #3]
	ldr r0, _08126D78 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r0, #4
	mov r6, r8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	b _081272C0
	.align 2, 0
_08126D34: .4byte 0x000005A4
_08126D38: .4byte 0x0000046D
_08126D3C: .4byte 0x0000046B
_08126D40: .4byte 0x00000553
_08126D44: .4byte 0xFFFFFDFF
_08126D48: .4byte 0x00000202
_08126D4C: .4byte 0x00000484
_08126D50: .4byte 0x00000222
_08126D54: .4byte Enemy_WaitPendingState
_08126D58: .4byte 0x00000551
_08126D5C: .4byte 0x00000469
_08126D60: .4byte 0x0000046C
_08126D64: .4byte 0x000006FE
_08126D68: .4byte 0x00000256
_08126D6C: .4byte 0x030046B8
_08126D70: .4byte 0x000003FF
_08126D74: .4byte 0x0203B400
_08126D78: .4byte 0x030046A4
_08126D7C:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov sb, r2
	cmp r4, #0
	blt _08126DB8
	cmp r1, #0
	blt _08126DB8
	ldr r0, _08126DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08126DB8
	ldr r0, _08126DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126DC4
_08126DB8:
	movs r4, #0
	b _08126DD2
	.align 2, 0
_08126DBC: .4byte 0x030046A8
_08126DC0: .4byte 0x030046AC
_08126DC4:
	ldr r0, _08126DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08126DD2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08126DE8
	adds r0, #4
	b _08126DF4
	.align 2, 0
_08126DE4: .4byte 0x030046A4
_08126DE8:
	ldr r0, _08126E08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126DF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08126E0C
	cmp r2, #2
	beq _08126E10
	b _08126E14
	.align 2, 0
_08126E08: .4byte 0x030046A4
_08126E0C:
	ldrb r0, [r5, #4]
	b _08126E12
_08126E10:
	ldrb r0, [r5]
_08126E12:
	subs r1, r1, r0
_08126E14:
	strh r1, [r5, #2]
	ldr r0, _08126E28 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08126E2C
	movs r0, #1
	b _08126E2E
	.align 2, 0
_08126E28: .4byte 0x030047A4
_08126E2C:
	movs r0, #0
_08126E2E:
	cmp r0, #0
	beq _08126E6C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08126E4E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08126E4A
	adds r2, r0, #0
_08126E4A:
	cmp r2, #0
	bge _08126E58
_08126E4E:
	ldr r2, _08126E54 @ =0x000005C4
	adds r0, r7, r2
	b _081272A8
	.align 2, 0
_08126E54: .4byte 0x000005C4
_08126E58:
	ldr r1, _08126E68 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08126EB4
	.align 2, 0
_08126E68: .4byte 0x03002BE0
_08126E6C:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126E98
	cmp r1, #0
	blt _08126E98
	ldr r0, _08126E9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126E98
	ldr r0, _08126EA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126EA4
_08126E98:
	movs r5, #0
	b _08126EB2
	.align 2, 0
_08126E9C: .4byte 0x030046A8
_08126EA0: .4byte 0x030046AC
_08126EA4:
	ldr r0, _08126F44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08126EB2:
	movs r2, #0
_08126EB4:
	ldr r4, _08126F48 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08126ED4
	ldr r1, _08126F4C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08126ED4
	b _081271EC
_08126ED4:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sl, r2
	cmp r3, #0
	beq _08126EEE
	b _081272C0
_08126EEE:
	movs r0, #5
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08126F50
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r5, [sp, #0x50]
	strb r2, [r5]
	ldr r6, [sp, #0x48]
	strb r4, [r6]
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	str r1, [r6]
	ldr r0, [sp, #0x5c]
	strh r3, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	ldr r0, [sp, #0x58]
	str r3, [r0]
	ldr r1, [sp, #0x4c]
	strb r2, [r1]
	b _081270A2
	.align 2, 0
_08126F44: .4byte 0x030046A4
_08126F48: .4byte 0x00000256
_08126F4C: .4byte 0x03002BE0
_08126F50:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r3, [sp, #0x48]
	strb r4, [r3]
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r3, [sp, #0x34]
	str r1, [r3]
	ldr r5, [sp, #0x5c]
	strh r2, [r5]
	movs r1, #5
	ldr r3, [sp, #0x3c]
	strb r4, [r3]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	ldr r4, [sp, #0x58]
	str r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r5, [r6]
	mov r1, sb
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	mov r2, sb
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126FB6
	cmp r1, #0
	blt _08126FB6
	ldr r0, _08126FBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126FB6
	ldr r0, _08126FC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126FC4
_08126FB6:
	movs r4, #0
	b _08126FD2
	.align 2, 0
_08126FBC: .4byte 0x030046A8
_08126FC0: .4byte 0x030046AC
_08126FC4:
	ldr r0, _08126FE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126FD2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08126FE8
	adds r0, #4
	b _08126FF4
	.align 2, 0
_08126FE4: .4byte 0x030046A4
_08126FE8:
	ldr r0, _08127008 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126FF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812700C
	cmp r2, #2
	beq _08127010
	b _08127014
	.align 2, 0
_08127008: .4byte 0x030046A4
_0812700C:
	ldrb r0, [r5, #4]
	b _08127012
_08127010:
	ldrb r0, [r5]
_08127012:
	subs r1, r1, r0
_08127014:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812703C
	cmp r1, #0
	blt _0812703C
	ldr r0, _08127040 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812703C
	ldr r0, _08127044 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127048
_0812703C:
	movs r4, #0
	b _08127056
	.align 2, 0
_08127040: .4byte 0x030046A8
_08127044: .4byte 0x030046AC
_08127048:
	ldr r0, _08127068 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08127056:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812706C
	adds r0, #4
	b _08127078
	.align 2, 0
_08127068: .4byte 0x030046A4
_0812706C:
	ldr r0, _0812708C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127078:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08127090
	cmp r3, #2
	beq _08127094
	b _08127098
	.align 2, 0
_0812708C: .4byte 0x030046A4
_08127090:
	ldrb r0, [r5, #4]
	b _08127096
_08127094:
	ldrb r0, [r5]
_08127096:
	subs r2, r2, r0
_08127098:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081270A2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r5, _081270CC @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x54]
	cmp r0, #0
	bne _081271B0
	movs r1, #4
	mov r6, r8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081270D0
	movs r0, #1
	b _081270D2
	.align 2, 0
_081270CC: .4byte 0x00000482
_081270D0:
	movs r0, #0
_081270D2:
	ldr r1, _081271C0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x54]
	cmp r0, #0
	bne _081271B0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _081271C4 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _081271C8 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x24]
	ldr r0, _081271CC @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _081271D0 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	ldr r2, _081271D4 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _081271D8 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081271DC @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x20]
	ldr r6, _081271E0 @ =0x0203B400
	ldr r1, _081271E4 @ =0x030046B8
	ldr r5, _081271E8 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_08127122:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08127140
	adds r3, #1
	cmp r3, #3
	ble _08127122
	mov r0, sb
_08127140:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x34]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	ldr r4, [sp, #0x28]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0x2c]
	strb r0, [r6]
	mov r0, sp
	ldrb r1, [r0, #0x18]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x38]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, [sp, #0x48]
	strb r3, [r6]
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r5, [sp, #0x34]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x5c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r2, [r6]
	ldr r0, [sp, #0x58]
	str r3, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x20]
	strb r0, [r3]
_081271B0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x54]
	strh r0, [r4]
	b _081272C0
	.align 2, 0
_081271C0: .4byte 0x00000482
_081271C4: .4byte 0x0000054F
_081271C8: .4byte 0x0000054C
_081271CC: .4byte 0x0000054D
_081271D0: .4byte 0x0000054E
_081271D4: .4byte 0x00000541
_081271D8: .4byte 0x000005BC
_081271DC: .4byte 0x00000542
_081271E0: .4byte 0x0203B400
_081271E4: .4byte 0x030046B8
_081271E8: .4byte 0x000003FF
_081271EC:
	mov sb, sp
	ldr r6, _08127228 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812722C
	adds r0, #4
	b _08127236
	.align 2, 0
_08127228: .4byte 0x030046A4
_0812722C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08127236:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0812726C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08127270
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _08127296
	.align 2, 0
_0812726C: .4byte 0x000004A4
_08127270:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08127290
	cmp r0, #2
	beq _0812728C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812728C:
	movs r0, #1
	b _081272A0
_08127290:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_08127296:
	ldr r1, _081272B4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081272A0:
	cmp r0, #0
	bne _081272C0
	ldr r3, _081272B8 @ =0x000005C4
	adds r0, r7, r3
_081272A8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081272C0
	.align 2, 0
_081272B4: .4byte 0xFFFFFDFF
_081272B8: .4byte 0x000005C4
_081272BC:
	adds r0, #1
	str r0, [r1]
_081272C0:
	add sp, #0x64
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
