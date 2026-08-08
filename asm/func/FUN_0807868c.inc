	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08078700 @ =0x000003F3
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _0807869E
	b _080787EE
_0807869E:
	ldr r2, _08078704 @ =0x000003BD
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, r3, #7
	movs r0, #7
	ands r2, r0
	adds r1, r3, #0
	adds r1, #9
	ands r1, r0
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r3
	beq _080786C8
	cmp r0, r2
	beq _080786C8
	cmp r0, r1
	beq _080786C8
	b _0807881C
_080786C8:
	ldr r1, _08078704 @ =0x000003BD
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _08078708 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0807870C
	asrs r2, r0, #0xc
	b _08078712
	.align 2, 0
_08078700: .4byte 0x000003F3
_08078704: .4byte 0x000003BD
_08078708: .4byte 0x085B0A08
_0807870C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078712:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807873C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08078740
	asrs r2, r0, #0xc
	b _08078746
	.align 2, 0
_0807873C: .4byte 0xFFFF0000
_08078740:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078746:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078788 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08078782
	cmp r1, #0
	blt _08078782
	ldr r0, _0807878C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08078782
	ldr r0, _08078790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08078794
_08078782:
	movs r4, #0
	b _080787A2
	.align 2, 0
_08078788: .4byte 0xFFFF0000
_0807878C: .4byte 0x030046A8
_08078790: .4byte 0x030046AC
_08078794:
	ldr r0, _080787B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080787A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080787B8
	adds r0, #4
	b _080787C4
	.align 2, 0
_080787B4: .4byte 0x030046A4
_080787B8:
	ldr r0, _080787D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080787C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080787DC
	cmp r2, #2
	beq _080787E0
	b _080787E4
	.align 2, 0
_080787D8: .4byte 0x030046A4
_080787DC:
	ldrb r0, [r6, #4]
	b _080787E2
_080787E0:
	ldrb r0, [r6]
_080787E2:
	subs r1, r1, r0
_080787E4:
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #0xc8
	cmp r1, r0
	blo _080787F2
_080787EE:
	movs r0, #1
	b _0807883A
_080787F2:
	ldr r4, _08078818 @ =0x000003BD
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	b _08078836
	.align 2, 0
_08078818: .4byte 0x000003BD
_0807881C:
	adds r0, r3, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r6, #0xdf
	lsls r6, r6, #2
	adds r0, r5, r6
_08078836:
	strb r4, [r0]
	movs r0, #0
_0807883A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
