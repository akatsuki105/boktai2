	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0xff
	mov sl, r1
	movs r2, #0x18
	str r2, [sp, #8]
_080B05CC:
	movs r0, #0x68
	ldr r3, [sp, #4]
	muls r0, r3, r0
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r0, r4
	add r0, r8
	mov ip, r0
	mov sb, ip
	adds r2, r3, #0
	adds r2, #2
	movs r0, #8
	subs r3, r0, r2
	ldr r0, _080B0608 @ =0x0000061A
	add r0, r8
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _080B060C @ =0x00000672
	add r0, r8
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	muls r1, r3, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080B0610
	asrs r0, r0, #5
	b _080B0616
	.align 2, 0
_080B0608: .4byte 0x0000061A
_080B060C: .4byte 0x00000672
_080B0610:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080B0616:
	adds r4, r0, #0
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B063C
	asrs r0, r0, #3
	b _080B0642
_080B063C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0642:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0670 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B0674 @ =0x0000061A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B0678 @ =0x00000672
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B067C
	asrs r0, r0, #3
	b _080B0682
	.align 2, 0
_080B0670: .4byte 0xFFFF0000
_080B0674: .4byte 0x0000061A
_080B0678: .4byte 0x00000672
_080B067C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0682:
	lsls r1, r0, #0x10
	ldr r0, _080B06AC @ =0x0000FFFF
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B06B0 @ =0x0000061C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B06B4 @ =0x00000674
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B06B8
	asrs r0, r0, #3
	b _080B06BE
	.align 2, 0
_080B06AC: .4byte 0x0000FFFF
_080B06B0: .4byte 0x0000061C
_080B06B4: .4byte 0x00000674
_080B06B8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B06BE:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B06F4 @ =0xFFFF0000
	ands r0, r7
	adds r7, r0, #0
	orrs r7, r1
	ldr r2, _080B06F8 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x64
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	adds r0, #0x40
	mov r4, sl
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r1, [sp, #8]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B06FC
	asrs r0, r0, #0xc
	b _080B0702
	.align 2, 0
_080B06F4: .4byte 0xFFFF0000
_080B06F8: .4byte 0x085B0A08
_080B06FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0702:
	adds r5, r0, #0
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	mov r4, sl
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r5, r1
	adds r4, r0, #0
	cmp r1, #0
	blt _080B0724
	asrs r0, r1, #0xc
	b _080B072A
_080B0724:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B072A:
	adds r0, r6, r0
	mov r1, sb
	strh r0, [r1, #0x1c]
	asrs r0, r6, #0x10
	strh r0, [r1, #0x1e]
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080B074C
	asrs r0, r0, #0xc
	b _080B0752
_080B074C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0752:
	adds r0, r7, r0
	mov r5, sb
	strh r0, [r5, #0x20]
	ldrh r0, [r4]
	adds r0, #3
	mov r1, sl
	ands r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	adds r0, #5
	strh r0, [r3]
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _080B07A0
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B07AC
_080B07A0:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B07AC:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B07D2
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B07E0
_080B07D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B07E0:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0814 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B084E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B080E
	ldrb r0, [r4, #5]
_080B080E:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0828
	.align 2, 0
_080B0814: .4byte 0x0000FFFF
_080B0818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0828
	strh r1, [r4, #8]
_080B0828:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	mov r3, sl
	ands r0, r3
	cmp r0, #0
	bne _080B084E
	movs r5, #1
	strb r5, [r4, #7]
_080B084E:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #8]
	adds r0, #4
	str r0, [sp, #8]
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #5
	bgt _080B086A
	b _080B05CC
_080B086A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
