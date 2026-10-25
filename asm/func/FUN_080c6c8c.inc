	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C6D12
	movs r6, #0
	strb r6, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C6D68 @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	ldr r3, _080C6D6C @ =0x000002F2
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _080C6D70 @ =0x000025FA
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r7, r3
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C6D12:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C6D28
	b _080C716C
_080C6D28:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080C6D74 @ =0x0000191C
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080C6D7C
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r4, #1
	str r4, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r3, _080C6D78 @ =0x000025E8
	adds r0, r7, r3
	b _080C6DA2
	.align 2, 0
_080C6D68: .4byte 0x000002FA
_080C6D6C: .4byte 0x000002F2
_080C6D70: .4byte 0x000025FA
_080C6D74: .4byte 0x0000191C
_080C6D78: .4byte 0x000025E8
_080C6D7C:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080C6DA4
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C6E00 @ =0x000025E8
	adds r0, r7, r2
_080C6DA2:
	strh r4, [r0]
_080C6DA4:
	ldr r3, _080C6E00 @ =0x000025E8
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C6E44
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C6E58
	strh r5, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r4, #1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C6E04 @ =0x0000260C
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C6E10
	ldr r1, _080C6E08 @ =FUN_080c718c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	ldr r3, _080C6E0C @ =0x000025FA
	adds r1, r7, r3
	movs r0, #0
	b _080C6E56
	.align 2, 0
_080C6E00: .4byte 0x000025E8
_080C6E04: .4byte 0x0000260C
_080C6E08: .4byte FUN_080c718c
_080C6E0C: .4byte 0x000025FA
_080C6E10:
	ldr r1, _080C6E38 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C6E3C @ =0x00001908
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _080C6E40 @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080C6E58
	.align 2, 0
_080C6E38: .4byte 0x00001909
_080C6E3C: .4byte 0x00001908
_080C6E40: .4byte FUN_080c73c0
_080C6E44:
	ldr r3, _080C6E80 @ =0x0000260C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C6E58
	ldr r0, _080C6E84 @ =0x000025FA
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
_080C6E56:
	strb r0, [r1]
_080C6E58:
	ldr r1, _080C6E84 @ =0x000025FA
	adds r4, r7, r1
	ldrb r0, [r4]
	cmp r0, #0x95
	bls _080C6E8C
	ldr r2, _080C6E88 @ =FUN_080c718c
	movs r3, #1
	adds r0, r7, #0
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	strb r1, [r4]
	b _080C716C
	.align 2, 0
_080C6E80: .4byte 0x0000260C
_080C6E84: .4byte 0x000025FA
_080C6E88: .4byte FUN_080c718c
_080C6E8C:
	mov r2, r8
	cmp r2, #0x59
	ble _080C6EE4
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080C6ED4 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C6EAC
	rsbs r1, r1, #0
_080C6EAC:
	cmp r1, #0x3f
	bgt _080C6EE4
	ldr r1, _080C6ED8 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C6EDC @ =0x00001908
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080C6EE0 @ =FUN_080c73c0
	movs r0, #3
	adds r3, r7, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	b _080C6F04
	.align 2, 0
_080C6ED4: .4byte 0x03002BE0
_080C6ED8: .4byte 0x00001909
_080C6EDC: .4byte 0x00001908
_080C6EE0: .4byte FUN_080c73c0
_080C6EE4:
	ldr r3, _080C6F10 @ =0x000008F9
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C6F18
	ldr r2, _080C6F14 @ =FUN_080c72f4
	movs r0, #2
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
_080C6F04:
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080C716C
	.align 2, 0
_080C6F10: .4byte 0x000008F9
_080C6F14: .4byte FUN_080c72f4
_080C6F18:
	ldr r0, _080C6F48 @ =0x000025D6
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C6FE8
	adds r3, r0, #0
	ldr r2, _080C6F4C @ =gSineTable
	ldr r1, _080C6F50 @ =0x000025D5
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080C6F54
	asrs r3, r0, #0xc
	b _080C6F5A
	.align 2, 0
_080C6F48: .4byte 0x000025D6
_080C6F4C: .4byte gSineTable
_080C6F50: .4byte 0x000025D5
_080C6F54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C6F5A:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r3, _080C6F84 @ =0x000002EA
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r7, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C6F88
	asrs r1, r0, #3
	b _080C6F8E
	.align 2, 0
_080C6F84: .4byte 0x000002EA
_080C6F88:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C6F8E:
	ldr r2, _080C6FB4 @ =0x000002EA
	adds r0, r7, r2
	strh r1, [r0]
	ldr r3, _080C6FB8 @ =0x000025D6
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _080C6FBC @ =0x000025D5
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C6FC0
	asrs r2, r0, #0xc
	b _080C6FC6
	.align 2, 0
_080C6FB4: .4byte 0x000002EA
_080C6FB8: .4byte 0x000025D6
_080C6FBC: .4byte 0x000025D5
_080C6FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C6FC6:
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r1, _080C6FE4 @ =0x000025D6
	adds r2, r7, r1
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080C716C
	.align 2, 0
_080C6FE4: .4byte 0x000025D6
_080C6FE8:
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r2, #8
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r1, r0
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080C701A
	cmp r1, #0
	beq _080C7052
_080C701A:
	adds r0, r2, #0
	bl ArcTan2_8
	ldr r1, _080C7040 @ =0x000008F2
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080C7048
	ldr r1, _080C7044 @ =0x0000260D
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, r2, r0
	b _080C7050
	.align 2, 0
_080C7040: .4byte 0x000008F2
_080C7044: .4byte 0x0000260D
_080C7048:
	ldr r1, _080C707C @ =0x0000260D
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, r2, r0
_080C7050:
	strb r0, [r3]
_080C7052:
	ldr r2, _080C7080 @ =0x0000260E
	adds r0, r7, r2
	ldrh r3, [r0]
	ldr r2, _080C7084 @ =gSineTable
	ldr r1, _080C7088 @ =0x000008F2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080C708C
	asrs r3, r0, #0xc
	b _080C7092
	.align 2, 0
_080C707C: .4byte 0x0000260D
_080C7080: .4byte 0x0000260E
_080C7084: .4byte gSineTable
_080C7088: .4byte 0x000008F2
_080C708C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C7092:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r3, _080C70BC @ =0x000002EA
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r7, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C70C0
	asrs r1, r0, #3
	b _080C70C6
	.align 2, 0
_080C70BC: .4byte 0x000002EA
_080C70C0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C70C6:
	ldr r2, _080C70EC @ =0x000002EA
	adds r0, r7, r2
	strh r1, [r0]
	ldr r3, _080C70F0 @ =0x0000260E
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _080C70F4 @ =0x000008F2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C70F8
	asrs r2, r0, #0xc
	b _080C70FE
	.align 2, 0
_080C70EC: .4byte 0x000002EA
_080C70F0: .4byte 0x0000260E
_080C70F4: .4byte 0x000008F2
_080C70F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C70FE:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r0, #0x3f
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	bne _080C716C
	ldr r6, _080C7178 @ =0x0203B400
	ldr r4, _080C717C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _080C7180 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldr r2, _080C7184 @ =0x03002BE0
	ldr r2, [r2]
	ldrb r3, [r0]
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r3
	subs r0, #0x7f
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r7, r3
	strh r0, [r2]
	ldr r2, _080C7188 @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	adds r3, #2
	adds r2, r7, r3
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r2, r7, r1
	subs r3, #0xf3
	adds r1, r3, #0
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
_080C716C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7178: .4byte 0x0203B400
_080C717C: .4byte 0x030046B8
_080C7180: .4byte 0x000003FF
_080C7184: .4byte 0x03002BE0
_080C7188: .4byte 0x000002FA
