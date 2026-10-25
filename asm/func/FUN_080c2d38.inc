	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _080C2DA8 @ =0x00000DB9
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C2D50
	b _080C2E72
_080C2D50:
	movs r7, #0
	ldr r0, _080C2DAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r6, r0, #0x1f
	movs r5, #0
_080C2D66:
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	adds r0, r2, r1
	ldr r3, _080C2DB0 @ =0x00000E14
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E64
	ldr r4, _080C2DB4 @ =0x00000DC4
	adds r0, r1, r4
	adds r4, r2, r0
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080C2DB8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x50
	strb r2, [r0]
	b _080C2E64
	.align 2, 0
_080C2DA8: .4byte 0x00000DB9
_080C2DAC: .4byte 0x03002BE0
_080C2DB0: .4byte 0x00000E14
_080C2DB4: .4byte 0x00000DC4
_080C2DB8:
	movs r7, #1
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r3, [r4, #0x20]
	adds r0, r0, r3
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E32
	cmp r6, #0
	bne _080C2E32
	ldr r0, _080C2E44 @ =0x03002BE0
	ldr r2, [r0]
	movs r0, #0x2c
	ldrsh r1, [r2, r0]
	movs r3, #0x1c
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E00
	rsbs r1, r1, #0
_080C2E00:
	cmp r1, #0x3f
	bgt _080C2E32
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r3, #0x20
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E14
	rsbs r1, r1, #0
_080C2E14:
	cmp r1, #0x3f
	bgt _080C2E32
	ldr r0, _080C2E48 @ =0x00000DBE
	add r0, r8
	ldrh r1, [r0]
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	movs r6, #1
_080C2E32:
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #0x2c
	bhi _080C2E4C
	movs r1, #4
	bl Div
	b _080C2E62
	.align 2, 0
_080C2E44: .4byte 0x03002BE0
_080C2E48: .4byte 0x00000DBE
_080C2E4C:
	cmp r0, #0x47
	bne _080C2E54
	movs r0, #0xe
	b _080C2E62
_080C2E54:
	cmp r0, #0x4a
	bne _080C2E5C
	movs r0, #5
	b _080C2E62
_080C2E5C:
	cmp r0, #0x4d
	bne _080C2E64
	movs r0, #2
_080C2E62:
	strh r0, [r4, #0x10]
_080C2E64:
	adds r5, #1
	cmp r5, #0x1f
	bgt _080C2E6C
	b _080C2D66
_080C2E6C:
	ldr r0, _080C2F1C @ =0x00000DB9
	add r0, r8
	strb r7, [r0]
_080C2E72:
	ldr r2, _080C2F20 @ =0x00000DBC
	add r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080C2E7E
	b _080C30FE
_080C2E7E:
	ldr r1, _080C2F24 @ =0x00000DBB
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080C2E92
	b _080C30F6
_080C2E92:
	ldr r0, _080C2F28 @ =0x00000DBA
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x54
	muls r0, r1, r0
	ldr r4, _080C2F2C @ =0x00000DC4
	adds r0, r0, r4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strh r0, [r7, #0x10]
	ldrb r0, [r2]
	cmp r0, #1
	bne _080C2F90
	ldr r2, _080C2F30 @ =0x0203B400
	mov sb, r2
	ldr r4, _080C2F34 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C2F38 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x30
	bl Mod
	adds r6, r0, #0
	adds r6, #0x28
	ldr r1, [r4]
	adds r1, #1
	ands r1, r5
	lsls r2, r1, #1
	add r2, sb
	ldrh r2, [r2]
	movs r3, #0x7f
	ands r2, r3
	adds r3, #0xc1
	adds r3, r3, r2
	mov ip, r3
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r5, r1, #3
	ldr r2, _080C2F3C @ =gSineTable
	adds r0, #0x68
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _080C2F40
	asrs r0, r0, #0xc
	b _080C2F46
	.align 2, 0
_080C2F1C: .4byte 0x00000DB9
_080C2F20: .4byte 0x00000DBC
_080C2F24: .4byte 0x00000DBB
_080C2F28: .4byte 0x00000DBA
_080C2F2C: .4byte 0x00000DC4
_080C2F30: .4byte 0x0203B400
_080C2F34: .4byte 0x030046B8
_080C2F38: .4byte 0x000003FF
_080C2F3C: .4byte gSineTable
_080C2F40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C2F46:
	adds r2, r7, #0
	adds r2, #0x48
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x4a
	movs r0, #3
	strh r0, [r1]
	ldr r1, _080C2F70 @ =gSineTable
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080C2F74
	asrs r2, r0, #0xc
	b _080C2F7A
	.align 2, 0
_080C2F70: .4byte gSineTable
_080C2F74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C2F7A:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	strh r2, [r1]
	adds r3, r7, #0
	adds r3, #0x53
	strb r0, [r3]
	ldr r3, _080C2F8C @ =0x030046B8
	b _080C3030
	.align 2, 0
_080C2F8C: .4byte 0x030046B8
_080C2F90:
	ldr r5, _080C2FE0 @ =0x0203B400
	ldr r3, _080C2FE4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _080C2FE8 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0x1f
	ands r2, r0
	adds r6, r2, #0
	adds r6, #0x30
	movs r0, #0xc0
	lsls r0, r0, #1
	mov ip, r0
	adds r1, #1
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r5, r0, #0
	adds r5, #0xa
	ldr r1, _080C2FEC @ =gSineTable
	adds r2, #0x70
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _080C2FF0
	asrs r4, r0, #0xc
	b _080C2FF6
	.align 2, 0
_080C2FE0: .4byte 0x0203B400
_080C2FE4: .4byte 0x030046B8
_080C2FE8: .4byte 0x000003FF
_080C2FEC: .4byte gSineTable
_080C2FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080C2FF6:
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	strh r4, [r1]
	adds r4, r7, #0
	adds r4, #0x4a
	strh r0, [r4]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _080C301C
	asrs r0, r0, #0xc
	b _080C3022
_080C301C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C3022:
	adds r1, r7, #0
	adds r1, #0x4c
	strh r0, [r1]
	adds r4, r7, #0
	adds r4, #0x53
	movs r0, #1
	strb r0, [r4]
_080C3030:
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r1, [r5]
	ldrh r0, [r7, #0x20]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldrh r0, [r4]
	add r0, ip
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C3074 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080C3078 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C307C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080C3084
	.align 2, 0
_080C3074: .4byte 0x000003FF
_080C3078: .4byte 0x0203B400
_080C307C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080C3084:
	str r0, [r7]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C30AC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080C30B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C30B4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080C30BC
	.align 2, 0
_080C30AC: .4byte 0x000003FF
_080C30B0: .4byte 0x0203B400
_080C30B4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080C30BC:
	str r0, [r7]
	adds r0, r7, #0
	adds r0, #0x51
	movs r2, #0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x52
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080C310C @ =0x00000DB9
	add r0, r8
	strb r1, [r0]
	ldr r1, _080C3110 @ =0x00000DBA
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080C30F0
	strb r2, [r1]
_080C30F0:
	ldr r0, _080C3114 @ =0x00000DBB
	add r0, r8
	strb r2, [r0]
_080C30F6:
	ldr r1, _080C3118 @ =0x00000DBC
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_080C30FE:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C310C: .4byte 0x00000DB9
_080C3110: .4byte 0x00000DBA
_080C3114: .4byte 0x00000DBB
_080C3118: .4byte 0x00000DBC
