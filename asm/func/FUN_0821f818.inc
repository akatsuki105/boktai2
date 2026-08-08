	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	str r7, [sp, #0x10]
	movs r0, #0
	mov r8, r0
	movs r1, #1
	mov sl, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r0, [r4]
	adds r2, r0, #0
	ands r2, r1
	subs r1, #3
	ands r0, r1
	str r0, [r4]
	cmp r2, #0
	beq _0821F850
	movs r3, #0xfd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x1e
	str r0, [r1]
_0821F850:
	ldr r0, _0821F874 @ =0x03002BE0
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r2, [r0]
	cmp r2, #2
	bne _0821F864
	b _0821FC88
_0821F864:
	cmp r2, #2
	bgt _0821F878
	cmp r2, #0
	beq _0821F886
	cmp r2, #1
	bne _0821F872
	b _0821F9B4
_0821F872:
	b _0821FF22
	.align 2, 0
_0821F874: .4byte 0x03002BE0
_0821F878:
	cmp r2, #3
	bne _0821F87E
	b _0821FE10
_0821F87E:
	cmp r2, #0x63
	bne _0821F884
	b _0821FECA
_0821F884:
	b _0821FF22
_0821F886:
	movs r0, #2
	ldr r1, [r4]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _0821F8B8
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x11
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821F8B8:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	ble _0821F90C
	movs r2, #0x38
	cmp r1, #0x7f
	bgt _0821F8E6
	adds r0, r1, #0
	muls r0, r2, r0
	cmp r0, #0
	blt _0821F8D8
	asrs r1, r0, #6
	b _0821F8DE
_0821F8D8:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821F8DE:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r7, r4
	b _0821F90A
_0821F8E6:
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #8
	lsls r0, r0, #8
	subs r0, #8
	adds r0, r1, r0
	cmp r0, #0
	blt _0821F8FE
	asrs r1, r0, #6
	b _0821F904
_0821F8FE:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821F904:
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r7, r2
_0821F90A:
	strh r1, [r0]
_0821F90C:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r4, r7, r3
	ldr r0, [r4]
	cmp r0, #0x19
	bne _0821F92A
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821F92A:
	ldr r0, [r4]
	cmp r0, #0x2c
	bgt _0821F990
	movs r1, #0x2d
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	asrs r5, r1, #2
	ldr r2, _0821F960 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F964
	asrs r1, r0, #0xc
	b _0821F96A
	.align 2, 0
_0821F960: .4byte 0x085B0A08
_0821F964:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F96A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F986
	asrs r0, r0, #0xc
	b _0821F98C
_0821F986:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F98C:
	strh r0, [r4, #4]
	b _0821FF22
_0821F990:
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0
	strh r2, [r0]
	movs r1, #1
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #2
	subs r3, #0x30
	adds r1, r7, r3
	b _0821FDDA
_0821F9B4:
	movs r0, #2
	ldr r1, [r4]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _0821FA58
	movs r4, #0xed
	lsls r4, r4, #2
	adds r1, r7, r4
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	mov r0, sl
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	adds r0, r7, #0
	movs r1, #9
	movs r2, #1
	movs r3, #0
	bl FUN_0821c400
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #2
	ldrsh r2, [r0, r4]
	movs r4, #4
	ldrsh r3, [r0, r4]
	adds r0, r7, #0
	adds r0, #0xcc
	movs r4, #0
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xce
	strh r2, [r1]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r3, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r4, [r6]
	subs r1, #0x86
	movs r3, #0
	ldrsh r5, [r0, r3]
	movs r4, #8
	ldrsh r0, [r1, r4]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, sl
	strb r3, [r6]
	ldr r0, _0821FA84 @ =0x0000034A
	bl PlaySound_082406e0
_0821FA58:
	adds r4, r7, #0
	adds r4, #0x58
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #0x28
	ldr r2, _0821FA88 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FA8C
	asrs r1, r0, #0xc
	b _0821FA92
	.align 2, 0
_0821FA84: .4byte 0x0000034A
_0821FA88: .4byte 0x085B0A08
_0821FA8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821FA92:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FAAE
	asrs r0, r0, #0xc
	b _0821FAB4
_0821FAAE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821FAB4:
	strh r0, [r4, #4]
	ldr r0, _0821FB28 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x94
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #1
	bls _0821FAD6
	movs r2, #8
	ldr r1, [sp, #0x10]
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #1
	mov r8, r4
_0821FAD6:
	mov r0, r8
	cmp r0, #0
	bne _0821FB2C
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r2, sb
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0821FB2C
	adds r0, r7, #0
	bl FUN_0821e5f0
	cmp r0, #0
	beq _0821FB2C
	adds r0, r7, #0
	bl FUN_0821db8c
	movs r2, #2
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r2, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	mov r1, r8
	str r1, [r0]
	subs r3, #0x14
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _0821FF22
	.align 2, 0
_0821FB28: .4byte 0x030046A0
_0821FB2C:
	movs r5, #0xc8
	lsls r5, r5, #1
	add r4, sp, #8
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	ldr r2, _0821FB58 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FB5C
	asrs r1, r0, #0xc
	b _0821FB62
	.align 2, 0
_0821FB58: .4byte 0x085B0A08
_0821FB5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821FB62:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FB7E
	asrs r0, r0, #0xc
	b _0821FB84
_0821FB7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821FB84:
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	add r2, sp, #8
	adds r1, r2, #0
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #4]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	adds r5, r2, #0
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0821FBCE
	cmp r1, #0
	blt _0821FBCE
	ldr r0, _0821FBD4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0821FBCE
	ldr r0, _0821FBD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0821FBDC
_0821FBCE:
	movs r4, #0
	b _0821FBEA
	.align 2, 0
_0821FBD4: .4byte 0x030046A8
_0821FBD8: .4byte 0x030046AC
_0821FBDC:
	ldr r0, _0821FBFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0821FBEA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0821FC00
	adds r0, #4
	b _0821FC0C
	.align 2, 0
_0821FBFC: .4byte 0x030046A4
_0821FC00:
	ldr r0, _0821FC20 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0821FC0C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0821FC24
	cmp r2, #2
	beq _0821FC28
	b _0821FC2C
	.align 2, 0
_0821FC20: .4byte 0x030046A4
_0821FC24:
	ldrb r0, [r5, #4]
	b _0821FC2A
_0821FC28:
	ldrb r0, [r5]
_0821FC2A:
	subs r1, r1, r0
_0821FC2C:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	subs r0, r1, r0
	ldr r1, _0821FC7C @ =0x000001FF
	adds r0, r0, r1
	adds r1, #0xff
	movs r2, #0
	cmp r0, r1
	bls _0821FC44
	movs r2, #1
_0821FC44:
	cmp r2, #0
	bne _0821FC5C
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, _0821FC80 @ =0x00000804
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	ldr r0, [r0]
	cmp r0, r1
	blt _0821FC84
_0821FC5C:
	movs r1, #3
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r7, r2
	str r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r1, r7, r4
	b _0821FDDA
	.align 2, 0
_0821FC7C: .4byte 0x000001FF
_0821FC80: .4byte 0x00000804
_0821FC84:
	movs r1, #6
	b _0821FEB6
_0821FC88:
	ldr r0, [r4]
	ands r2, r0
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	cmp r2, #0
	beq _0821FCF0
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0xd
	movs r2, #0
	movs r3, #1
	bl FUN_0821c400
	adds r0, r7, #0
	bl FUN_0821dc14
	ldr r1, _0821FCE4 @ =0x00000BBC
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _0821FCE8 @ =0x00000BBD
	adds r0, r7, r3
	strb r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	add r2, sb
	ldrb r1, [r2]
	ldr r4, _0821FCEC @ =0x00000BBE
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r7, r4
	mov r1, r8
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, r2, #0
	b _0821FCFC
	.align 2, 0
_0821FCE4: .4byte 0x00000BBC
_0821FCE8: .4byte 0x00000BBD
_0821FCEC: .4byte 0x00000BBE
_0821FCF0:
	adds r0, r7, #0
	bl FUN_0821dd00
	movs r4, #0x80
	lsls r4, r4, #3
	add r4, sb
_0821FCFC:
	ldrb r2, [r4]
	ldr r0, _0821FD7C @ =0x00000BBF
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, r2
	beq _0821FD14
	strb r2, [r1]
	ldr r2, _0821FD80 @ =0x00000BC1
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0821FD14:
	ldr r3, _0821FD80 @ =0x00000BC1
	adds r5, r7, r3
	ldrb r0, [r5]
	cmp r0, #3
	bls _0821FD42
	mov r0, sb
	bl FUN_0807849c
	lsls r0, r0, #0x1d
	movs r1, #0xa0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	ldr r2, _0821FD84 @ =0x00000BC2
	adds r1, r7, r2
	movs r2, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x10
	strb r0, [r1]
	strb r2, [r5]
_0821FD42:
	movs r2, #4
	ldr r1, [sp, #0x10]
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0821FD88 @ =0x00000BBE
	adds r0, r7, r1
	ldrb r0, [r0]
	ldrb r1, [r4]
	ldr r2, _0821FD8C @ =0xFFFFFF00
	adds r0, r0, r2
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0xf
	ble _0821FD90
	movs r1, #0x63
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0
	str r0, [r1]
	b _0821FDD2
	.align 2, 0
_0821FD7C: .4byte 0x00000BBF
_0821FD80: .4byte 0x00000BC1
_0821FD84: .4byte 0x00000BC2
_0821FD88: .4byte 0x00000BBE
_0821FD8C: .4byte 0xFFFFFF00
_0821FD90:
	ldr r1, _0821FDE4 @ =0x000002D9
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0821FDA0
	b _0821FF22
_0821FDA0:
	ldr r2, _0821FDE8 @ =0x00000BBC
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r3, #0
	strb r2, [r1]
	ldr r0, _0821FDEC @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x28
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _0821FDC0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0821FDF0
_0821FDC0:
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r7, r2
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	str r3, [r0]
_0821FDD2:
	movs r2, #2
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
_0821FDDA:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0821FF22
	.align 2, 0
_0821FDE4: .4byte 0x000002D9
_0821FDE8: .4byte 0x00000BBC
_0821FDEC: .4byte 0x030046A0
_0821FDF0:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r7, r4
	strh r3, [r0]
	ldr r0, _0821FE0C @ =0x000002CA
	adds r1, r7, r0
	movs r0, #7
	strh r0, [r1]
	b _0821FF22
	.align 2, 0
_0821FE0C: .4byte 0x000002CA
_0821FE10:
	movs r0, #2
	ldr r1, [r4]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _0821FE34
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x15
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821FE34:
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0x31
	bgt _0821FEA0
	movs r1, #0x32
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r3, [r0]
	asrs r5, r1, #2
	ldr r2, _0821FE70 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FE74
	asrs r1, r0, #0xc
	b _0821FE7A
	.align 2, 0
_0821FE70: .4byte 0x085B0A08
_0821FE74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821FE7A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821FE96
	asrs r0, r0, #0xc
	b _0821FE9C
_0821FE96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821FE9C:
	strh r0, [r4, #4]
	b _0821FEA8
_0821FEA0:
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0821FEA8:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0x27
	bgt _0821FF22
	movs r1, #0x14
_0821FEB6:
	bl Mod
	cmp r0, #0
	bne _0821FF22
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x14
	bl FUN_0821ddc4
	b _0821FF22
_0821FECA:
	movs r0, #2
	ldr r1, [r4]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _0821FF0E
	adds r0, r7, #0
	bl FUN_0821dca0
	adds r0, r7, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	movs r1, #0xc0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	mov r3, sl
	str r3, [sp]
	mov r0, r8
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
_0821FF0E:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _0821FF22
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0821FF22:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
