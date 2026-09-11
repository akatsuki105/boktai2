	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	mov r8, r1
	mov sb, r7
	movs r0, #0x74
	movs r1, #2
	bl VM_GetKeywordValue
	str r0, [sp, #0x34]
	adds r0, r7, #0
	ldr r1, [sp, #0x34]
	bl FUN_08022a0c
	ldr r0, _0803BA48 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0803BA4C
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
	b _0803BA5C
	.align 2, 0
_0803BA48: .4byte 0x03002BE0
_0803BA4C:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r7, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	str r2, [r0]
_0803BA5C:
	ldr r0, _0803BACC @ =0x0000CB05
	ldr r1, _0803BAD0 @ =0x0000D3FA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0803BA6C
	b _0803C158
_0803BA6C:
	movs r6, #0x98
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
	beq _0803BADC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0803BAD4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0803BAD8 @ =0x0000FFFF
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
	adds r4, r0, #0
	b _0803BB04
	.align 2, 0
_0803BACC: .4byte 0x0000CB05
_0803BAD0: .4byte 0x0000D3FA
_0803BAD4: .4byte 0xFFFF0000
_0803BAD8: .4byte 0x0000FFFF
_0803BADC:
	ldr r0, _0803BB20 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _0803BB24 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _0803BB28 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r4, #0x40
_0803BB04:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BB2C
	bl Script_GetValue
	mov sl, r0
	bl Script_GetValue
	movs r6, #0xd7
	lsls r6, r6, #1
	adds r1, r7, r6
	b _0803BB3A
	.align 2, 0
_0803BB20: .4byte 0x030046A0
_0803BB24: .4byte 0xFFFF0000
_0803BB28: .4byte 0x0000FFFF
_0803BB2C:
	movs r0, #0x96
	lsls r0, r0, #2
	mov sl, r0
	movs r2, #0xd7
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x3c
_0803BB3A:
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BBA2
	bl Script_GetValue
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xcb
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xce
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #8
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r7, r2
	b _0803BBE4
_0803BBA2:
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0x3c
	strh r1, [r0]
	movs r5, #0xcb
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0x32
	strh r2, [r0]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0x46
	strh r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	strh r2, [r0]
	adds r5, #8
	adds r2, r7, r5
	movs r0, #0x41
	strh r0, [r2]
	adds r6, #8
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x50
_0803BBE4:
	strh r0, [r1]
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BC5A
	bl Script_GetValue
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xd5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xd9
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #0xa
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #0xa
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	b _0803BCA8
_0803BC5A:
	movs r3, #0xd3
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r2, #0x32
	strh r2, [r0]
	movs r5, #0xd4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0x1e
	strh r1, [r0]
	movs r6, #0xd5
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #3
	strh r0, [r1]
	adds r3, #0xa
	adds r1, r7, r3
	movs r0, #0x2d
	strh r0, [r1]
	adds r5, #0xa
	adds r0, r7, r5
	movs r1, #0x37
	strh r1, [r0]
	adds r6, #0xa
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xdb
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
_0803BCA8:
	str r4, [sp]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #0x34]
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sb
	movs r6, #0
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xab
	add r2, sb
	mov r8, r2
	strb r0, [r2]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r0, #0x98
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x1c
	str r1, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	ldr r4, _0803BDEC @ =0x03003584
	ldr r0, [r4]
	movs r2, #0xbd
	lsls r2, r2, #7
	adds r0, r0, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r7, r3
	ldr r2, _0803BDF0 @ =0x04000040
	bl CpuSet
	ldr r0, [r4]
	movs r4, #0x99
	lsls r4, r4, #6
	adds r6, r0, r4
	mov r5, r8
	str r5, [sp, #0x28]
	movs r0, #0xfc
	add r0, sb
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x30]
	mov r2, sb
	adds r2, #0xde
	str r2, [sp, #0x2c]
	mov r3, sb
	adds r3, #0x48
	str r3, [sp, #0x24]
	movs r4, #0xf8
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r4, #7
_0803BD4C:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _0803BDF4 @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _0803BD4C
	movs r5, #0x9c
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r6, #0x9d
	lsls r6, r6, #3
	adds r0, r7, r6
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r3, _0803BDF8 @ =0x00000201
	movs r2, #2
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r4, sp, #0x1c
	str r4, [sp, #0xc]
	movs r2, #0x40
	bl FUN_0822f3fc
	movs r4, #0
	ldr r3, _0803BDFC @ =0x00007FE8
	adds r6, #0x60
	adds r5, r7, r6
_0803BD98:
	lsls r0, r4, #5
	adds r2, r4, #1
	movs r1, #0xf
	adds r0, r0, r5
	adds r0, #0x1e
_0803BDA2:
	strh r3, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0803BDA2
	adds r4, r2, #0
	cmp r4, #7
	ble _0803BD98
	ldr r0, _0803BE00 @ =0x00000522
	adds r1, r7, r0
	movs r4, #0
	movs r5, #0
	ldr r0, _0803BE04 @ =0x00006583
	strh r0, [r1]
	movs r2, #0xa6
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r0, r7, r3
	str r0, [r1]
	ldr r6, [sp, #0x28]
	ldrb r3, [r6]
	cmp r3, #0
	beq _0803BEA4
	movs r0, #0x44
	movs r1, #1
	bl VM_GetKeywordValue
	adds r3, r0, #0
	cmp r3, #1
	beq _0803BE34
	cmp r3, #1
	bgt _0803BE08
	cmp r3, #0
	beq _0803BE0E
	b _0803BEE6
	.align 2, 0
_0803BDEC: .4byte 0x03003584
_0803BDF0: .4byte 0x04000040
_0803BDF4: .4byte 0x04000008
_0803BDF8: .4byte 0x00000201
_0803BDFC: .4byte 0x00007FE8
_0803BE00: .4byte 0x00000522
_0803BE04: .4byte 0x00006583
_0803BE08:
	cmp r3, #2
	beq _0803BE6C
	b _0803BEE6
_0803BE0E:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BE30 @ =FUN_0803b1a4
	movs r0, #0x11
	b _0803BE88
	.align 2, 0
_0803BE30: .4byte FUN_0803b1a4
_0803BE34:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	strb r3, [r0]
	ldr r1, _0803BE68 @ =FUN_0803b1e0
	movs r0, #0x12
	mov r2, sb
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _0803BEE6
	.align 2, 0
_0803BE68: .4byte FUN_0803b1e0
_0803BE6C:
	mov r0, sb
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BEA0 @ =FUN_0803b278
	movs r0, #0x13
_0803BE88:
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _0803BEE6
	.align 2, 0
_0803BEA0: .4byte FUN_0803b278
_0803BEA4:
	mov r0, sb
	adds r0, #0xa4
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BF38 @ =FUN_0803a128
	subs r0, #5
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_0803BEE6:
	ldr r0, _0803BF3C @ =FUN_0803b830
	mov r4, r8
	str r0, [r4]
	ldr r0, _0803BF40 @ =FUN_0803b7ec
	ldr r5, [sp, #0x30]
	str r0, [r5]
	movs r6, #0xd7
	lsls r6, r6, #1
	adds r4, r7, r6
	movs r0, #0
	ldrsh r3, [r4, r0]
	mov r0, sb
	mov r1, sl
	mov r2, sl
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_08038dc0
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r7, #0
	bl FUN_08038e6c
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BF44
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _0803BF4E
	.align 2, 0
_0803BF38: .4byte FUN_0803a128
_0803BF3C: .4byte FUN_0803b830
_0803BF40: .4byte FUN_0803b7ec
_0803BF44:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_0803BF4E:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BF74
	movs r4, #0
	mov r5, sb
	adds r5, #0xe8
	b _0803BF68
_0803BF60:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_0803BF68:
	cmp r4, #3
	bgt _0803BF74
	bl VM_GetPC
	cmp r0, #0
	bne _0803BF60
_0803BF74:
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x4b
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0xde
	lsls r4, r4, #1
	adds r1, r7, r4
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	adds r0, r7, #0
	bl FUN_08038f00
	movs r0, #0x6a
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803BFC4
	bl Script_GetValue
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r7, r2
	b _0803BFD6
_0803BFC4:
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x96
	strh r0, [r1]
	movs r4, #0xb5
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0x32
_0803BFD6:
	strh r0, [r1]
	movs r5, #0xb3
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	movs r6, #0xb4
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	ldr r1, [sp, #0x28]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803C028
	movs r0, #5
	bl FUN_08234f44
	adds r3, r0, #0
	ldr r2, _0803C01C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803C020 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0803C024 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrb r1, [r3]
	bl Mod
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	b _0803C030
	.align 2, 0
_0803C01C: .4byte 0x030046B8
_0803C020: .4byte 0x000003FF
_0803C024: .4byte 0x0203B400
_0803C028:
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
_0803C030:
	strb r0, [r1]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	movs r5, #0xdf
	lsls r5, r5, #4
	adds r1, r7, r5
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, _0803C088 @ =0x00000DF4
	adds r1, r7, r6
	str r0, [r1]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _0803C08C @ =0x00000DF8
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r1, #0
	movs r0, #0x14
	strh r0, [r2]
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r7, r4
	str r1, [r0]
	adds r5, #0xc
	adds r0, r7, r5
	str r1, [r0]
	movs r0, #0x42
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0803C0B2
	movs r4, #0
	adds r5, r7, r5
	b _0803C0A6
	.align 2, 0
_0803C088: .4byte 0x00000DF4
_0803C08C: .4byte 0x00000DF8
_0803C090:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r6, _0803C13C @ =0x00000E04
	adds r1, r7, r6
	adds r1, r1, r2
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	adds r4, #1
_0803C0A6:
	cmp r4, #7
	bgt _0803C0B2
	bl VM_GetPC
	cmp r0, #0
	bne _0803C090
_0803C0B2:
	ldr r0, _0803C140 @ =0x00000E14
	adds r4, r7, r0
	ldr r2, _0803C144 @ =FUN_08036fd8
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	bl FUN_0807f558
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4, #4]
	ands r0, r1
	str r0, [r4, #4]
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r4, r7, r1
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x48
	str r0, [sp]
	movs r3, #0
	str r3, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r4, #0
	bl FUN_080139a0
	adds r0, r7, #0
	bl FUN_080389b0
	bl FUN_0805d79c
	ldr r3, _0803C148 @ =0x00000DE4
	adds r1, r7, r3
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	ldr r0, _0803C14C @ =0x00006545
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r1, r7, r4
	bl FUN_080601a8
	ldr r5, _0803C150 @ =0x00000DE8
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	bl FUN_0805dcd4
	ldr r6, _0803C154 @ =0x00000DEC
	adds r1, r7, r6
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	movs r0, #0
	b _0803C15C
	.align 2, 0
_0803C13C: .4byte 0x00000E04
_0803C140: .4byte 0x00000E14
_0803C144: .4byte FUN_08036fd8
_0803C148: .4byte 0x00000DE4
_0803C14C: .4byte 0x00006545
_0803C150: .4byte 0x00000DE8
_0803C154: .4byte 0x00000DEC
_0803C158:
	movs r0, #1
	rsbs r0, r0, #0
_0803C15C:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
