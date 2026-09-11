	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14c
	str r0, [sp, #0x100]
	adds r6, r1, #0
	adds r7, r2, #0
	str r3, [sp, #0x104]
	cmp r3, #0
	blt _0822A590
	asrs r3, r3, #1
	b _0822A598
_0822A590:
	ldr r1, [sp, #0x104]
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r3, r0, #0
_0822A598:
	str r3, [sp, #0x104]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0822A5A6
	str r0, [sp, #0x104]
	b _0822A5B0
_0822A5A6:
	ldr r2, [sp, #0x104]
	cmp r2, #0x7f
	ble _0822A5B0
	movs r3, #0x7f
	str r3, [sp, #0x104]
_0822A5B0:
	movs r4, #0
	str r4, [sp, #0x114]
	ldr r0, _0822A664 @ =0x030044B0
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	ldr r5, [sp, #0x100]
	ldr r5, [r5]
	mov sb, r5
	cmp r0, #0
	beq _0822A5D8
	ldr r1, [sp, #0x100]
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0822A5D8
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r5
	cmp r0, #0
	beq _0822A5E4
_0822A5D8:
	movs r0, #0x80
	lsls r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0822A5EE
_0822A5E4:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r3, [sp, #0x114]
	orrs r3, r0
	str r3, [sp, #0x114]
_0822A5EE:
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ands r0, r4
	cmp r0, #0
	beq _0822A604
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r5, [sp, #0x114]
	orrs r5, r0
	str r5, [sp, #0x114]
_0822A604:
	ldr r0, _0822A668 @ =0x030044AC
	ldr r0, [r0]
	cmp r0, #0
	beq _0822A622
	movs r0, #0x80
	lsls r0, r0, #7
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0822A622
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r2, [sp, #0x114]
	orrs r2, r0
	str r2, [sp, #0x114]
_0822A622:
	ldr r3, [sp, #0x100]
	ldr r0, [r3, #0x18]
	ldr r4, [sp, #0x114]
	orrs r4, r0
	str r4, [sp, #0x114]
	movs r0, #2
	mov r5, sb
	ands r0, r5
	cmp r0, #0
	bne _0822A66C
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq _0822A646
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	str r4, [sp, #0x114]
_0822A646:
	movs r0, #8
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0822A65A
	movs r0, #0x80
	lsls r0, r0, #0x16
	ldr r2, [sp, #0x114]
	orrs r2, r0
	str r2, [sp, #0x114]
_0822A65A:
	movs r3, #0
	str r3, [sp, #0x10c]
	movs r4, #0
	str r4, [sp, #0x110]
	b _0822A734
	.align 2, 0
_0822A664: .4byte 0x030044B0
_0822A668: .4byte 0x030044AC
_0822A66C:
	ldr r5, [sp, #0x100]
	movs r1, #8
	ldrsb r1, [r5, r1]
	movs r2, #9
	ldrsb r2, [r5, r2]
	movs r0, #4
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	beq _0822A682
	rsbs r1, r1, #0
_0822A682:
	movs r0, #8
	mov r4, sb
	ands r4, r0
	cmp r4, #0
	beq _0822A68E
	rsbs r2, r2, #0
_0822A68E:
	adds r0, r1, #0
	cmp r1, #0
	bge _0822A696
	rsbs r0, r1, #0
_0822A696:
	cmp r0, #0x3c
	bgt _0822A6AE
	adds r0, r2, #0
	cmp r2, #0
	bge _0822A6A2
	rsbs r0, r2, #0
_0822A6A2:
	cmp r0, #0x3c
	bgt _0822A6AE
	ldr r5, [sp, #0x100]
	ldrb r0, [r5, #6]
	cmp r0, #0
	beq _0822A6BA
_0822A6AE:
	movs r0, #0xc0
	lsls r0, r0, #2
	ldr r3, [sp, #0x114]
	orrs r3, r0
	str r3, [sp, #0x114]
	b _0822A6C4
_0822A6BA:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r4, [sp, #0x114]
	orrs r4, r0
	str r4, [sp, #0x114]
_0822A6C4:
	ldr r5, [sp, #0x100]
	ldrb r3, [r5, #6]
	lsls r0, r1, #0x18
	asrs r4, r0, #0x18
	lsls r0, r2, #0x18
	asrs r5, r0, #0x18
	ldr r2, _0822A6DC @ =0x03003E40
	ldr r0, [r2]
	cmp r0, #0x1f
	ble _0822A6E0
	movs r1, #0
	b _0822A700
	.align 2, 0
_0822A6DC: .4byte 0x03003E40
_0822A6E0:
	ldr r1, _0822A774 @ =0x030035B0
	lsls r0, r0, #2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	strb r4, [r0, #1]
	ldr r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	strb r5, [r0, #2]
	ldr r0, [r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r2]
_0822A700:
	lsls r0, r1, #0x19
	ldr r1, [sp, #0x114]
	orrs r1, r0
	str r1, [sp, #0x114]
	ldr r3, _0822A778 @ =0x085B0A08
	ldr r2, [sp, #0x100]
	ldrb r1, [r2, #6]
	rsbs r1, r1, #0
	movs r2, #0xff
	adds r0, r1, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r4, [r0, r5]
	str r4, [sp, #0x10c]
	adds r1, #0x40
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x110]
	ldr r3, [sp, #0x100]
	ldr r3, [r3]
	mov sb, r3
_0822A734:
	ldr r4, [sp, #0x100]
	ldr r4, [r4, #0xc]
	str r4, [sp, #0x11c]
	ldr r5, [sp, #0x100]
	adds r5, #0x10
	str r5, [sp, #0x134]
	ldr r0, [r4, #0x14]
	str r0, [sp, #0x138]
	ldr r2, [sp, #0x100]
	movs r3, #0x10
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, [sp, #0x138]
	adds r4, r4, r0
	str r4, [sp, #0x138]
	ldr r0, _0822A77C @ =0x0300359C
	ldr r1, [r0]
	ldr r0, [r4, #8]
	adds r1, r1, r0
	movs r0, #4
	mov r5, sb
	ands r0, r5
	cmp r0, #0
	beq _0822A780
	ldr r2, [sp, #0x134]
	movs r0, #6
	ldrsb r0, [r2, r0]
	subs r6, r6, r0
	b _0822A788
	.align 2, 0
_0822A774: .4byte 0x030035B0
_0822A778: .4byte 0x085B0A08
_0822A77C: .4byte 0x0300359C
_0822A780:
	ldr r3, [sp, #0x134]
	movs r0, #6
	ldrsb r0, [r3, r0]
	adds r6, r6, r0
_0822A788:
	str r6, [sp, #0x128]
	movs r0, #8
	mov r4, sb
	ands r0, r4
	cmp r0, #0
	beq _0822A79E
	ldr r5, [sp, #0x134]
	movs r0, #7
	ldrsb r0, [r5, r0]
	subs r0, r7, r0
	b _0822A7A6
_0822A79E:
	ldr r2, [sp, #0x134]
	movs r0, #7
	ldrsb r0, [r2, r0]
	adds r0, r7, r0
_0822A7A6:
	str r0, [sp, #0x12c]
	ldr r3, [sp, #0x100]
	ldrb r3, [r3, #7]
	str r3, [sp, #0x130]
	movs r4, #0
	str r4, [sp, #0x118]
	movs r5, #0
	str r5, [sp, #0x120]
	movs r0, #0
	str r0, [sp, #0x124]
	adds r6, r1, #0
	movs r1, #0
	str r1, [sp, #0x108]
	ldr r2, [sp, #0x138]
	ldrb r2, [r2]
	cmp r4, r2
	blt _0822A7CA
	b _0822A982
_0822A7CA:
	mov r3, sb
	str r3, [sp, #0x13c]
	mov r4, sb
	movs r5, #4
	ands r4, r5
	str r4, [sp, #0x140]
	mov r0, sp
	str r0, [sp, #0x148]
	mov r1, sb
	movs r2, #8
	ands r1, r2
	str r1, [sp, #0x144]
_0822A7E2:
	ldrb r3, [r6]
	mov sl, r3
	ldr r4, [sp, #0x120]
	ldr r5, [sp, #0x124]
	adds r4, r4, r5
	str r4, [sp, #0x120]
	ldr r0, _0822A81C @ =0x03004030
	add r0, sl
	ldrb r5, [r0]
	ldr r0, _0822A820 @ =0x03003FC0
	add r0, sl
	ldrb r7, [r0]
	ldr r0, _0822A824 @ =0x03003FD0
	add r0, sl
	ldrb r0, [r0]
	str r0, [sp, #0x124]
	movs r0, #2
	ldr r1, [sp, #0x13c]
	ands r0, r1
	cmp r0, #0
	bne _0822A86C
	ldr r2, [sp, #0x140]
	cmp r2, #0
	beq _0822A828
	movs r0, #2
	ldrsb r0, [r6, r0]
	rsbs r2, r0, #0
	subs r4, r2, r5
	b _0822A82E
	.align 2, 0
_0822A81C: .4byte 0x03004030
_0822A820: .4byte 0x03003FC0
_0822A824: .4byte 0x03003FD0
_0822A828:
	movs r4, #2
	ldrsb r4, [r6, r4]
	adds r2, r4, r5
_0822A82E:
	ldr r3, [sp, #0x144]
	cmp r3, #0
	beq _0822A83E
	movs r0, #3
	ldrsb r0, [r6, r0]
	rsbs r1, r0, #0
	subs r3, r1, r7
	b _0822A844
_0822A83E:
	movs r3, #3
	ldrsb r3, [r6, r3]
	adds r1, r3, r7
_0822A844:
	ldr r5, [sp, #0x128]
	adds r4, r4, r5
	ldr r0, [sp, #0x12c]
	adds r3, r3, r0
	cmp r4, #0xf0
	ble _0822A852
	b _0822A970
_0822A852:
	cmp r3, #0xb4
	ble _0822A858
	b _0822A970
_0822A858:
	adds r0, r2, r5
	cmp r0, #0
	bge _0822A860
	b _0822A970
_0822A860:
	ldr r2, [sp, #0x12c]
	adds r0, r1, r2
	cmp r0, #0
	bge _0822A86A
	b _0822A970
_0822A86A:
	b _0822A93C
_0822A86C:
	asrs r3, r5, #1
	mov ip, r3
	asrs r4, r7, #1
	mov r8, r4
	movs r0, #2
	ldrsb r0, [r6, r0]
	add r0, ip
	ldr r2, [sp, #0x100]
	movs r1, #8
	ldrsb r1, [r2, r1]
	muls r0, r1, r0
	cmp r0, #0
	blt _0822A88A
	asrs r0, r0, #6
	b _0822A890
_0822A88A:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0822A890:
	adds r3, r0, #0
	movs r0, #3
	ldrsb r0, [r6, r0]
	add r0, r8
	ldr r4, [sp, #0x100]
	movs r1, #9
	ldrsb r1, [r4, r1]
	muls r0, r1, r0
	cmp r0, #0
	blt _0822A8A8
	asrs r0, r0, #6
	b _0822A8AE
_0822A8A8:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0822A8AE:
	adds r2, r0, #0
	mov r0, sb
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0822A8BC
	rsbs r3, r3, #0
_0822A8BC:
	mov r0, sb
	movs r4, #8
	ands r0, r4
	cmp r0, #0
	beq _0822A8C8
	rsbs r2, r2, #0
_0822A8C8:
	ldr r0, [sp, #0x110]
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r4, [sp, #0x10c]
	adds r0, r2, #0
	muls r0, r4, r0
	subs r0, r1, r0
	cmp r0, #0
	blt _0822A8DE
	asrs r0, r0, #0xc
	b _0822A8E4
_0822A8DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0822A8E4:
	mov r1, ip
	subs r4, r0, r1
	ldr r0, [sp, #0x10c]
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r3, [sp, #0x110]
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _0822A8FE
	asrs r0, r0, #0xc
	b _0822A904
_0822A8FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0822A904:
	mov r1, r8
	subs r3, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r0, [sp, #0x114]
	ands r0, r1
	cmp r0, r1
	bne _0822A920
	mov r2, ip
	subs r4, r4, r2
	mov r0, r8
	subs r3, r3, r0
	lsls r5, r5, #1
	lsls r7, r7, #1
_0822A920:
	ldr r1, [sp, #0x128]
	adds r4, r4, r1
	ldr r2, [sp, #0x12c]
	adds r3, r3, r2
	adds r0, r4, r5
	cmp r0, #0
	blt _0822A970
	cmp r4, #0xf0
	bgt _0822A970
	adds r0, r3, r7
	cmp r0, #0
	blt _0822A970
	cmp r3, #0xb4
	bgt _0822A970
_0822A93C:
	ldr r5, [sp, #0x118]
	lsls r2, r5, #2
	ldr r0, _0822AA14 @ =0x000001FF
	ands r4, r0
	lsls r1, r4, #0x10
	movs r0, #0xff
	ands r3, r0
	orrs r1, r3
	ldr r0, [sp, #0x114]
	orrs r1, r0
	mov r3, sl
	lsls r0, r3, #2
	ldr r4, _0822AA18 @ =0x03003FF0
	adds r0, r0, r4
	ldr r0, [r0]
	orrs r1, r0
	ldr r5, [sp, #0x148]
	stm r5!, {r1}
	str r5, [sp, #0x148]
	add r0, sp, #0x80
	adds r0, r0, r2
	ldr r1, [sp, #0x120]
	str r1, [r0]
	ldr r2, [sp, #0x118]
	adds r2, #1
	str r2, [sp, #0x118]
_0822A970:
	ldr r3, [sp, #0x108]
	adds r3, #1
	str r3, [sp, #0x108]
	adds r6, #4
	ldr r4, [sp, #0x138]
	ldrb r4, [r4]
	cmp r3, r4
	bge _0822A982
	b _0822A7E2
_0822A982:
	ldr r5, [sp, #0x118]
	cmp r5, #0
	bgt _0822A98A
	b _0822AA90
_0822A98A:
	ldr r0, _0822AA1C @ =0x03003598
	ldr r0, [r0]
	ldr r2, [sp, #0x138]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	ldrb r1, [r2, #1]
	bl FUN_0822b270
	mov sb, r0
	ldr r3, [sp, #0x11c]
	ldrh r0, [r3, #6]
	ldr r4, [sp, #0x134]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	ldr r1, [r3, #0xc]
	bl FUN_0822d190
	ldr r5, [sp, #0x130]
	lsls r7, r5, #0xa
	lsls r0, r0, #0xc
	orrs r7, r0
	ldr r1, [sp, #0x100]
	ldr r0, [r1]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0822AA2C
	movs r2, #0
	str r2, [sp, #0x108]
	ldr r3, [sp, #0x118]
	cmp r2, r3
	bge _0822AA90
	ldr r4, _0822AA20 @ =0x03003A38
	mov r8, r4
	ldr r5, _0822AA24 @ =0x03003630
	mov sl, r5
	ldr r6, _0822AA28 @ =0x03002CA4
	mov r5, sp
	add r4, sp, #0x80
_0822A9D8:
	ldr r0, [r4]
	mov r1, sb
	adds r2, r1, r0
	orrs r2, r7
	ldr r3, [r5]
	mov r0, r8
	ldr r1, [r0]
	cmp r1, #0x7f
	bgt _0822AA00
	lsls r0, r1, #3
	add r0, sl
	str r3, [r0]
	strh r2, [r0, #4]
	adds r0, r1, #1
	mov r1, r8
	str r0, [r1]
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_0822AA00:
	adds r5, #4
	adds r4, #4
	ldr r2, [sp, #0x108]
	adds r2, #1
	str r2, [sp, #0x108]
	ldr r3, [sp, #0x118]
	cmp r2, r3
	blt _0822A9D8
	b _0822AA90
	.align 2, 0
_0822AA14: .4byte 0x000001FF
_0822AA18: .4byte 0x03003FF0
_0822AA1C: .4byte 0x03003598
_0822AA20: .4byte 0x03003A38
_0822AA24: .4byte 0x03003630
_0822AA28: .4byte 0x03002CA4
_0822AA2C:
	movs r4, #0
	str r4, [sp, #0x108]
	ldr r5, [sp, #0x118]
	cmp r4, r5
	bge _0822AA90
	ldr r0, _0822AAA0 @ =0x03003A3C
	mov r8, r0
	ldr r0, [sp, #0x104]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #8
	mov sl, r0
	ldr r1, _0822AAA4 @ =0x03003A30
	ldr r2, [sp, #0x130]
	lsls r0, r2, #1
	adds r6, r0, r1
	ldr r3, _0822AAA8 @ =0x03003A40
	mov ip, r3
	mov r5, sp
	add r3, sp, #0x80
_0822AA56:
	ldr r0, [r3]
	mov r4, sb
	adds r2, r4, r0
	orrs r2, r7
	ldr r4, [r5]
	mov r0, r8
	ldr r1, [r0]
	cmp r1, #0x7f
	bgt _0822AA80
	lsls r0, r1, #3
	add r0, ip
	str r4, [r0]
	strh r2, [r0, #4]
	mov r2, sl
	strh r2, [r0, #6]
	adds r0, r1, #1
	mov r4, r8
	str r0, [r4]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_0822AA80:
	adds r5, #4
	adds r3, #4
	ldr r0, [sp, #0x108]
	adds r0, #1
	str r0, [sp, #0x108]
	ldr r1, [sp, #0x118]
	cmp r0, r1
	blt _0822AA56
_0822AA90:
	add sp, #0x14c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822AAA0: .4byte 0x03003A3C
_0822AAA4: .4byte 0x03003A30
_0822AAA8: .4byte 0x03003A40
