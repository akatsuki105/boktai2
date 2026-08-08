	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807E3DC
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0807E3EC @ =0x00000381
	adds r0, r5, r4
	strb r1, [r0]
_0807E3DC:
	ldrh r0, [r6, #0x3c]
	cmp r0, #0
	ble _0807E3F0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08236524
	b _0807E3F4
	.align 2, 0
_0807E3EC: .4byte 0x00000381
_0807E3F0:
	movs r0, #0
	strh r0, [r7, #0x3e]
_0807E3F4:
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xe
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	movs r2, #0
	mov r8, r2
	mov sb, r1
	cmp r0, #0
	beq _0807E41E
	movs r4, #1
	rsbs r4, r4, #0
	mov r8, r4
_0807E41E:
	adds r0, r6, #0
	adds r0, #0x40
	ldrh r1, [r0]
	cmp r1, #0
	bne _0807E43C
	ldr r2, _0807E434 @ =0x000003D6
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _0807E438 @ =0x00000446
	adds r4, r5, r0
	b _0807E51A
	.align 2, 0
_0807E434: .4byte 0x000003D6
_0807E438: .4byte 0x00000446
_0807E43C:
	ldr r1, _0807E550 @ =0x000003D6
	adds r0, r5, r1
	movs r1, #0xe6
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	cmp r1, #2
	bne _0807E45C
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0807E46C
_0807E45C:
	cmp r1, #3
	bne _0807E47C
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _0807E47C
_0807E46C:
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0807E554 @ =0x00000381
	adds r0, r5, r4
	strb r1, [r0]
_0807E47C:
	ldr r0, _0807E558 @ =0x000003FF
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0807E48C
	bl FUN_080dab9c
_0807E48C:
	ldr r1, _0807E55C @ =0x00000446
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r4, r0, #0
	cmp r1, #0
	beq _0807E4A6
	ldr r1, _0807E560 @ =0x00000442
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _0807E4A6
	movs r2, #1
_0807E4A6:
	cmp r2, #0
	beq _0807E4C4
	ldr r2, _0807E560 @ =0x00000442
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xe8
	ldr r0, [r2]
	ldr r1, _0807E564 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
_0807E4C4:
	ldr r1, _0807E568 @ =0x000003EA
	adds r0, r5, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0807E4DC
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807E4DC
	strh r2, [r1]
_0807E4DC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _0807E4FE
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0807E4FE
	adds r0, r5, #0
	bl FUN_08063220
	movs r2, #1
	add r8, r2
_0807E4FE:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08060cf8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #1
	bne _0807E51A
	ldr r2, _0807E56C @ =0x00000449
	adds r0, r5, r2
	strb r1, [r0]
_0807E51A:
	ldrh r0, [r4]
	movs r1, #0
	cmp r0, #0
	beq _0807E52E
	ldr r2, _0807E560 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _0807E52E
	movs r1, #1
_0807E52E:
	cmp r1, #0
	beq _0807E570
	movs r0, #0
	strh r0, [r7, #0x3e]
	movs r4, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0807E546
	b _0807E76E
_0807E546:
	adds r0, r5, #0
	bl FUN_08063220
	b _0807E76E
	.align 2, 0
_0807E550: .4byte 0x000003D6
_0807E554: .4byte 0x00000381
_0807E558: .4byte 0x000003FF
_0807E55C: .4byte 0x00000446
_0807E560: .4byte 0x00000442
_0807E564: .4byte 0xFFFFFBFF
_0807E568: .4byte 0x000003EA
_0807E56C: .4byte 0x00000449
_0807E570:
	ldrh r0, [r4]
	movs r1, #0
	cmp r0, #0
	beq _0807E584
	ldr r4, _0807E5E0 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _0807E584
	movs r1, #1
_0807E584:
	cmp r1, #0
	bne _0807E5A4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807E5A4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807E5A4
	cmp r0, #3
	bne _0807E5A8
_0807E5A4:
	movs r4, #1
	add r8, r4
_0807E5A8:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E5F0
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E670
	ldr r1, _0807E5E4 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E5D4
	ldr r2, _0807E5E8 @ =0x000003D6
	adds r1, r5, r2
	ldr r0, _0807E5EC @ =0x00000191
	strh r0, [r1]
_0807E5D4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08063288
	b _0807E670
	.align 2, 0
_0807E5E0: .4byte 0x00000442
_0807E5E4: .4byte 0x000003D2
_0807E5E8: .4byte 0x000003D6
_0807E5EC: .4byte 0x00000191
_0807E5F0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0807E630
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E670
	ldr r4, _0807E624 @ =0x000003D2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E61A
	ldr r0, _0807E628 @ =0x000003D6
	adds r1, r5, r0
	ldr r0, _0807E62C @ =0x00000133
	strh r0, [r1]
_0807E61A:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08063288
	b _0807E670
	.align 2, 0
_0807E624: .4byte 0x000003D2
_0807E628: .4byte 0x000003D6
_0807E62C: .4byte 0x00000133
_0807E630:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0807E660
	ldr r2, _0807E654 @ =0x000003D6
	adds r1, r5, r2
	movs r4, #0
	ldr r0, _0807E658 @ =0x00000133
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08063288
	ldr r1, _0807E65C @ =0x000003D2
	adds r0, r5, r1
	strb r4, [r0]
	b _0807E670
	.align 2, 0
_0807E654: .4byte 0x000003D6
_0807E658: .4byte 0x00000133
_0807E65C: .4byte 0x000003D2
_0807E660:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _0807E670
	adds r0, r5, #0
	bl FUN_08063220
_0807E670:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E694
	movs r1, #0x20
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0807E694
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08063574
_0807E694:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E6AC
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08063574
_0807E6AC:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E73A
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0807E6E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0807E6EC
	asrs r0, r0, #0xc
	b _0807E6F2
	.align 2, 0
_0807E6E8: .4byte 0x085B0A08
_0807E6EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807E6F2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0807E714
	asrs r0, r0, #0xc
	b _0807E71A
_0807E714:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807E71A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807E748 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
_0807E73A:
	mov r4, r8
	cmp r4, #0
	blt _0807E74C
	ldrh r4, [r7, #0x3e]
	mov r0, r8
	lsls r4, r0
	b _0807E760
	.align 2, 0
_0807E748: .4byte 0xFFFF0000
_0807E74C:
	ldrh r1, [r7, #0x3e]
	mov r2, r8
	rsbs r0, r2, #0
	adds r4, r1, #0
	asrs r4, r0
	cmp r1, #0
	beq _0807E760
	cmp r4, #0
	bne _0807E760
	movs r4, #1
_0807E760:
	movs r0, #0
	strh r0, [r7, #0x3e]
	ldr r0, _0807E780 @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_0807E76E:
	adds r0, r4, #0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807E780: .4byte 0x00000376
