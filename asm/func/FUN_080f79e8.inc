	adds r0, r6, #0
	bl FUN_080f6c74
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F79F8
	bl FUN_080f83ec
_080F79F8:
	adds r0, r6, #0
	bl FUN_080f6e34
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_080e5098
	adds r0, r6, #0
	bl FUN_080f6af0
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r4, _080F7ACC @ =0x0000048A
	adds r1, r6, r4
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_080f6868
	lsls r0, r0, #0x18
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r7, r6, r5
	cmp r0, #0
	bne _080F7A52
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080F7A52
	movs r0, #0x20
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
_080F7A52:
	ldr r2, _080F7AD0 @ =0x0000048C
	adds r0, r6, r2
	ldrb r1, [r0]
	movs r3, #4
	adds r0, r3, #0
	ands r0, r1
	movs r4, #1
	cmp r0, #0
	beq _080F7A66
	movs r4, #2
_080F7A66:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r2, r6, r5
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r1, r0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	mov sb, r2
	cmp r1, #0
	beq _080F7A84
	b _080F7BF4
_080F7A84:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080F7AA4
	ldrh r0, [r7]
	ands r0, r3
	cmp r0, #0
	bne _080F7AA4
	adds r0, r6, #0
	bl FUN_080e7f30
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0xc
	strh r0, [r1]
_080F7AA4:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r6
	mov r8, r3
	cmp r4, #0
	bne _080F7AB2
	b _080F7BF4
_080F7AB2:
	ldr r5, _080F7AD4 @ =0x0000047C
	adds r0, r6, r5
	ldrh r1, [r0]
	ldr r2, _080F7AD8 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F7ADC
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080F7AE8
	.align 2, 0
_080F7ACC: .4byte 0x0000048A
_080F7AD0: .4byte 0x0000048C
_080F7AD4: .4byte 0x0000047C
_080F7AD8: .4byte 0x0000025D
_080F7ADC:
	ldr r2, [r6, #0x44]
	ldr r0, _080F7B14 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080F7AE8:
	ldr r3, _080F7B18 @ =0x00000492
	adds r1, r6, r3
	movs r0, #8
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r6, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080F7B1C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _080F7B20
	movs r0, #1
	b _080F7B22
	.align 2, 0
_080F7B14: .4byte 0x03003584
_080F7B18: .4byte 0x00000492
_080F7B1C: .4byte 0x030047A4
_080F7B20:
	movs r0, #0
_080F7B22:
	cmp r0, #0
	beq _080F7B90
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080F7B90
	cmp r2, #0
	beq _080F7B90
	ldr r0, _080F7B48 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080F7B4C
	movs r0, #1
	rsbs r0, r0, #0
	b _080F7B50
	.align 2, 0
_080F7B48: .4byte 0x03002C68
_080F7B4C:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080F7B50:
	cmp r0, #1
	beq _080F7B72
	cmp r0, #1
	bgt _080F7B5E
	cmp r0, #0
	beq _080F7B68
	b _080F7B90
_080F7B5E:
	cmp r0, #2
	beq _080F7B7C
	cmp r0, #3
	beq _080F7B86
	b _080F7B90
_080F7B68:
	ldr r0, [r1]
	cmp r0, #1
	beq _080F7B90
	movs r0, #0
	b _080F7B92
_080F7B72:
	ldr r0, [r1]
	cmp r0, #2
	beq _080F7B90
	movs r0, #0
	b _080F7B92
_080F7B7C:
	ldr r0, [r1]
	cmp r0, #4
	beq _080F7B90
	movs r0, #0
	b _080F7B92
_080F7B86:
	ldr r0, [r1]
	cmp r0, #8
	beq _080F7B90
	movs r0, #0
	b _080F7B92
_080F7B90:
	movs r0, #1
_080F7B92:
	cmp r0, #0
	beq _080F7BF4
	ldrh r0, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	adds r3, #0xd0
	adds r2, r6, r3
	ldrh r2, [r2]
	ldr r5, _080F7C24 @ =0x0000025A
	adds r3, r6, r5
	ldrh r3, [r3]
	movs r5, #1
	lsrs r4, r4, #1
	str r4, [sp]
	bl FUN_0809c344
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _080F7C28 @ =0x05000002
	bl CpuSet
	ldr r0, _080F7C2C @ =0x0000048A
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _080F7BE0
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080F7BF4
_080F7BE0:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r6, #0
	adds r3, #8
	str r4, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080F7BF4:
	movs r0, #0x10
	ldrh r2, [r7]
	ands r0, r2
	cmp r0, #0
	bne _080F7C0C
	movs r1, #0x80
	lsls r1, r1, #2
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080F7C34
_080F7C0C:
	ldr r4, _080F7C30 @ =0x000001DF
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080F7C88
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r0, #0
	strh r0, [r1]
	b _080F7C88
	.align 2, 0
_080F7C24: .4byte 0x0000025A
_080F7C28: .4byte 0x05000002
_080F7C2C: .4byte 0x0000048A
_080F7C30: .4byte 0x000001DF
_080F7C34:
	movs r0, #6
	ands r2, r0
	cmp r2, #0
	beq _080F7C5A
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldrh r3, [r0]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _080F7C88
	strh r3, [r2]
	b _080F7C88
_080F7C5A:
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r2, r6, r5
	movs r1, #0xc7
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _080F7C88
	subs r5, #2
	adds r0, r6, r5
	ldrh r0, [r0]
	strh r0, [r2]
	movs r0, #2
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080F7C88:
	movs r1, #0x80
	mov r2, r8
	ldr r0, [r2]
	ands r1, r0
	ldr r3, _080F7CD8 @ =0xFFFEBE3F
	ands r0, r3
	str r0, [r2]
	ldr r4, _080F7CDC @ =0x0000021E
	adds r5, r6, r4
	movs r0, #0
	mov sb, r0
	mov r2, sb
	strh r2, [r5]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r3, r3, r6
	mov sl, r3
	strh r2, [r3]
	ldr r0, _080F7CE0 @ =0x00000202
	adds r4, r6, r0
	strh r2, [r4]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_080f6604
	ldrh r0, [r7]
	str r5, [sp, #0x40]
	str r4, [sp, #0x3c]
	cmp r0, #0
	bne _080F7CE8
	ldr r1, _080F7CE4 @ =0xFFFFDFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _080F8364
	.align 2, 0
_080F7CD8: .4byte 0xFFFEBE3F
_080F7CDC: .4byte 0x0000021E
_080F7CE0: .4byte 0x00000202
_080F7CE4: .4byte 0xFFFFDFFF
_080F7CE8:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080F7D78
	movs r5, #0x80
	lsls r5, r5, #5
	ldrh r0, [r7]
	ands r0, r5
	cmp r0, #0
	beq _080F7D18
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	bics r0, r5
	strh r0, [r7]
	mov r1, sb
	str r1, [r4]
_080F7D18:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F7D50
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F7D6C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7D70 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r5, #0
	strb r5, [r0]
	mov r1, sb
	ldr r0, [sp, #0x40]
	strh r1, [r0]
	ldr r2, [sp, #0x3c]
	strh r1, [r2]
_080F7D50:
	movs r0, #0x40
	strh r0, [r7]
	movs r4, #0
	ldr r3, [sp, #0x48]
	strb r4, [r3]
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r6, r5
	ldr r0, _080F7D74 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080F8364
	.align 2, 0
_080F7D6C: .4byte 0xFEFFFFFF
_080F7D70: .4byte 0xFFFFFDFF
_080F7D74: .4byte 0xFFFFF67F
_080F7D78:
	movs r0, #0x80
	lsls r0, r0, #6
	mov sb, r0
	ldrh r2, [r7]
	adds r1, r2, #0
	adds r0, r1, #0
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080F7E54
	ldr r0, _080F7E28 @ =0x00000482
	adds r5, r6, r0
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strh r2, [r5]
	ldr r3, _080F7E2C @ =0x00000222
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080F7E30 @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r0, _080F7E34 @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7E38 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F7DEA
	subs r3, #0xa6
	adds r2, r6, r3
	ldr r1, _080F7E3C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7E40 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, [sp, #0x40]
	strh r4, [r3]
	ldr r0, [sp, #0x3c]
	strh r4, [r0]
_080F7DEA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r3, _080F7E44 @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F7E48 @ =0xFBFFFFFF
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _080F7E4C @ =0xFFFFFAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	mov r1, sb
	strh r1, [r5]
	ldr r0, _080F7E50 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080F8148
	.align 2, 0
_080F7E28: .4byte 0x00000482
_080F7E2C: .4byte 0x00000222
_080F7E30: .4byte 0x0000024E
_080F7E34: .4byte 0xFFFFFC7F
_080F7E38: .4byte 0xF3FFFFFF
_080F7E3C: .4byte 0xFEFFFFFF
_080F7E40: .4byte 0xFFFFFDFF
_080F7E44: .4byte 0x00000542
_080F7E48: .4byte 0xFBFFFFFF
_080F7E4C: .4byte 0xFFFFFAFF
_080F7E50: .4byte 0xFFFFF67F
_080F7E54:
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080F7F2C
	ldr r2, _080F7F00 @ =0x00000482
	adds r4, r6, r2
	movs r5, #1
	strh r5, [r4]
	ldr r1, _080F7F04 @ =0x00000222
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _080F7F08 @ =0x0000024E
	adds r0, r6, r2
	strh r3, [r0]
	ldr r0, _080F7F0C @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7F10 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F7EB8
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F7F14 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7F18 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, [sp, #0x40]
	strh r3, [r0]
	ldr r1, [sp, #0x3c]
	strh r3, [r1]
_080F7EB8:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r3, _080F7F1C @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F7F20 @ =0xFBFFFFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080F7F24 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	strh r5, [r4]
	ldr r0, _080F7F28 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	b _080F8148
	.align 2, 0
_080F7F00: .4byte 0x00000482
_080F7F04: .4byte 0x00000222
_080F7F08: .4byte 0x0000024E
_080F7F0C: .4byte 0xFFFFFC7F
_080F7F10: .4byte 0xF3FFFFFF
_080F7F14: .4byte 0xFEFFFFFF
_080F7F18: .4byte 0xFFFFFDFF
_080F7F1C: .4byte 0x00000542
_080F7F20: .4byte 0xFBFFFFFF
_080F7F24: .4byte 0xFFFFDAFF
_080F7F28: .4byte 0xFFFFF67F
_080F7F2C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F7FF0
	ldr r3, _080F7FC4 @ =0x00000482
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	ldr r5, _080F7FC8 @ =0x00000222
	adds r0, r6, r5
	strh r4, [r0]
	ldr r1, _080F7FCC @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r0, _080F7FD0 @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7FD4 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F7F8A
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F7FD8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7FDC @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	subs r5, #6
	adds r0, r6, r5
	movs r1, #0
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strh r4, [r2]
	ldr r3, [sp, #0x3c]
	strh r4, [r3]
_080F7F8A:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r4, _080F7FE0 @ =0x00000542
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F7FE4 @ =0xFBFFFFFF
	mov r5, r8
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r0, _080F7FE8 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	orrs r2, r0
	movs r3, #0
	orrs r2, r3
	ldr r0, _080F7FEC @ =0xFFFFF67F
	ands r2, r0
	strh r2, [r1]
	b _080F8148
	.align 2, 0
_080F7FC4: .4byte 0x00000482
_080F7FC8: .4byte 0x00000222
_080F7FCC: .4byte 0x0000024E
_080F7FD0: .4byte 0xFFFFFC7F
_080F7FD4: .4byte 0xF3FFFFFF
_080F7FD8: .4byte 0xFEFFFFFF
_080F7FDC: .4byte 0xFFFFFDFF
_080F7FE0: .4byte 0x00000542
_080F7FE4: .4byte 0xFBFFFFFF
_080F7FE8: .4byte 0xFFFFDAFF
_080F7FEC: .4byte 0xFFFFF67F
_080F7FF0:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080F801C
	ldr r0, _080F8018 @ =0xFFFFDAFF
	ands r0, r2
	strh r0, [r7]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	movs r5, #0
	orrs r0, r5
	b _080F8142
	.align 2, 0
_080F8018: .4byte 0xFFFFDAFF
_080F801C:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _080F8026
	b _080F8148
_080F8026:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080F8220 @ =0xFFFEBE3F
	ands r0, r2
	str r0, [r1]
	ldr r3, [sp, #0x40]
	strh r5, [r3]
	mov r4, sl
	strh r5, [r4]
	ldr r0, [sp, #0x3c]
	strh r5, [r0]
	ldr r1, _080F8224 @ =0x00000482
	adds r3, r6, r1
	movs r0, #1
	strh r0, [r3]
	ldr r2, _080F8228 @ =0x00000222
	adds r0, r6, r2
	strh r5, [r0]
	ldr r4, _080F822C @ =0x0000024E
	adds r0, r6, r4
	strh r5, [r0]
	ldr r0, _080F8230 @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F8234 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #0xe
	ands r0, r4
	cmp r0, #0
	beq _080F8094
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F8238 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F823C @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r4, [sp, #0x40]
	strh r5, [r4]
	ldr r0, [sp, #0x3c]
	strh r5, [r0]
_080F8094:
	ldrh r1, [r7]
	ldr r0, _080F8240 @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F8244 @ =0x00000542
	adds r1, r1, r6
	mov sb, r1
	movs r2, #1
	rsbs r2, r2, #0
	add r4, sp, #0x2c
	strb r2, [r4]
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _080F8248 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #6
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #5
	mov sl, r2
	ldrh r0, [r7]
	ands r0, r2
	cmp r0, #0
	beq _080F80E6
	movs r3, #0x97
	lsls r3, r3, #3
	adds r4, r6, r3
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r1, sl
	bics r0, r1
	strh r0, [r7]
	str r5, [r4]
_080F80E6:
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #0xe
	ands r0, r3
	cmp r0, #0
	beq _080F811C
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _080F8238 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F823C @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, [sp, #0x40]
	strh r5, [r3]
	ldr r4, [sp, #0x3c]
	strh r5, [r4]
_080F811C:
	ldrh r1, [r7]
	ldr r0, _080F8240 @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r7]
	mov r5, sb
	ldrb r0, [r5]
	add r1, sp, #0x2c
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r5]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r0, r1
	movs r4, #0
	orrs r0, r4
_080F8142:
	ldr r1, _080F824C @ =0xFFFFF67F
	ands r0, r1
	strh r0, [r2]
_080F8148:
	ldr r0, _080F8250 @ =0x0000803E
	ldrh r1, [r7]
	ands r0, r1
	cmp r0, #0
	bne _080F8154
	b _080F8272
_080F8154:
	ldr r0, _080F8254 @ =0xFFFFFDFE
	ands r0, r1
	movs r5, #0
	mov sl, r5
	strh r0, [r7]
	ldr r0, _080F8258 @ =0xF7FFBFFF
	mov r1, r8
	ldr r2, [r1]
	ands r2, r0
	str r2, [r1]
	movs r1, #0x20
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	bne _080F817C
	movs r0, #0x81
	rsbs r0, r0, #0
	ands r2, r0
	mov r3, r8
	str r2, [r3]
_080F817C:
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r5, r6, r4
	ldr r0, _080F825C @ =0xFFEFFFFB
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #5
	mov sb, r0
	ldrh r0, [r7]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _080F81B2
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r3, sb
	bics r0, r3
	strh r0, [r7]
	mov r0, sl
	str r0, [r4]
_080F81B2:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F81E4
	ldr r1, _080F8238 @ =0xFEFFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r0, _080F823C @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r4, #0
	strb r4, [r0]
	mov r0, sl
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldr r1, [sp, #0x3c]
	strh r0, [r1]
_080F81E4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r7]
	bics r0, r1
	strh r0, [r7]
	ldr r3, _080F8244 @ =0x00000542
	adds r2, r6, r3
	movs r0, #0xff
	strb r0, [r2]
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080F8264
	ldr r1, _080F8260 @ =0xFFFFDFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F827C
	.align 2, 0
_080F8220: .4byte 0xFFFEBE3F
_080F8224: .4byte 0x00000482
_080F8228: .4byte 0x00000222
_080F822C: .4byte 0x0000024E
_080F8230: .4byte 0xFFFFFC7F
_080F8234: .4byte 0xF3FFFFFF
_080F8238: .4byte 0xFEFFFFFF
_080F823C: .4byte 0xFFFFFDFF
_080F8240: .4byte 0xFFFFFBFF
_080F8244: .4byte 0x00000542
_080F8248: .4byte 0xFFFFDAFF
_080F824C: .4byte 0xFFFFF67F
_080F8250: .4byte 0x0000803E
_080F8254: .4byte 0xFFFFFDFE
_080F8258: .4byte 0xF7FFBFFF
_080F825C: .4byte 0xFFEFFFFB
_080F8260: .4byte 0xFFFFDFFF
_080F8264:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, r8
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	b _080F827C
_080F8272:
	ldr r1, _080F82D4 @ =0xFFFFDFFF
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080F827C:
	movs r3, #0x80
	lsls r3, r3, #3
	ldrh r0, [r7]
	ands r0, r3
	cmp r0, #0
	beq _080F82AE
	ldr r5, _080F82D8 @ =0x00000542
	adds r1, r6, r5
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080F82A4
	ldr r4, _080F82DC @ =0x00000553
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080F82AE
	cmp r0, #2
	beq _080F82AE
_080F82A4:
	movs r0, #0xff
	strb r0, [r1]
	ldrh r0, [r7]
	bics r0, r3
	strh r0, [r7]
_080F82AE:
	movs r0, #0x80
	ldrh r3, [r7]
	adds r2, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080F82F4
	ldr r5, _080F82E0 @ =0x000001DF
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _080F8322
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080F82E8
	ldr r2, _080F82E4 @ =0x00000482
	adds r1, r6, r2
	b _080F8326
	.align 2, 0
_080F82D4: .4byte 0xFFFFDFFF
_080F82D8: .4byte 0x00000542
_080F82DC: .4byte 0x00000553
_080F82E0: .4byte 0x000001DF
_080F82E4: .4byte 0x00000482
_080F82E8:
	ldr r3, _080F82F0 @ =0x00000482
	adds r1, r6, r3
	b _080F8334
	.align 2, 0
_080F82F0: .4byte 0x00000482
_080F82F4:
	movs r1, #0x90
	lsls r1, r1, #5
	ands r1, r2
	cmp r1, #0
	beq _080F8340
	ldr r4, _080F8310 @ =0x000001DF
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080F8318
	ldr r5, _080F8314 @ =0x00000482
	adds r1, r6, r5
	b _080F8326
	.align 2, 0
_080F8310: .4byte 0x000001DF
_080F8314: .4byte 0x00000482
_080F8318:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080F8330
_080F8322:
	ldr r0, _080F832C @ =0x00000482
	adds r1, r6, r0
_080F8326:
	movs r0, #2
	strh r0, [r1]
	b _080F8364
	.align 2, 0
_080F832C: .4byte 0x00000482
_080F8330:
	ldr r2, _080F833C @ =0x00000482
	adds r1, r6, r2
_080F8334:
	movs r0, #3
	strh r0, [r1]
	b _080F8364
	.align 2, 0
_080F833C: .4byte 0x00000482
_080F8340:
	ldr r0, _080F837C @ =0xFFFFFBFF
	ands r0, r3
	movs r2, #0
	strh r0, [r7]
	ldr r3, _080F8380 @ =0x00000222
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _080F8384 @ =0x00000542
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	movs r5, #0xa8
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _080F8388 @ =0x00000541
	adds r0, r6, r1
	strb r2, [r0]
_080F8364:
	adds r0, r6, #0
	bl FUN_080e499c
	movs r1, #0x40
	ldr r2, _080F838C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F8390
	movs r0, #1
	b _080F8392
	.align 2, 0
_080F837C: .4byte 0xFFFFFBFF
_080F8380: .4byte 0x00000222
_080F8384: .4byte 0x00000542
_080F8388: .4byte 0x00000541
_080F838C: .4byte 0x00000474
_080F8390:
	movs r0, #0
_080F8392:
	cmp r0, #0
	beq _080F83A8
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F83A4 @ =0x0000FEFF
	ands r0, r1
	b _080F83EA
	.align 2, 0
_080F83A4: .4byte 0x0000FEFF
_080F83A8:
	ldr r3, _080F83D0 @ =0x0000049C
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #0x84
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	bne _080F83C2
	ldr r1, _080F83D4 @ =0x00002016
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080F83DC
_080F83C2:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F83D8 @ =0x0000FEFF
	ands r0, r1
	b _080F83EA
	.align 2, 0
_080F83D0: .4byte 0x0000049C
_080F83D4: .4byte 0x00002016
_080F83D8: .4byte 0x0000FEFF
_080F83DC:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r4, #0
	orrs r0, r1
_080F83EA:
	strh r0, [r2]
FUN_080f83ec:
	movs r0, #1

	non_word_aligned_thumb_func_start FUN_080f83ee
FUN_080f83ee: @ 0x080F83EE
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
