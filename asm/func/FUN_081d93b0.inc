	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D93CC
	b _081D94F8
_081D93CC:
	movs r0, #0x75
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	movs r6, #0
	mov r2, sl
	strb r0, [r2]
	ldr r4, _081D9480 @ =0x0203B400
	mov sb, r4
	ldr r5, _081D9484 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081D9488 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r4, sl
	strb r0, [r4]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r7, #0
	adds r0, #0x2c
	ldr r2, [sp, #0xc]
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #7
	bl AuxAnim_SetAnim
	adds r0, r7, #0
	adds r0, #0x78
	strb r6, [r0]
	subs r0, #8
	strh r6, [r0]
	add r0, sp, #8
	adds r4, r7, #0
	adds r4, #0x58
	str r6, [sp, #8]
	adds r1, r4, #0
	ldr r2, _081D948C @ =0x05000002
	bl CpuSet
	mov r0, sl
	ldrb r2, [r0]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r3, r1, #2
	ldr r1, _081D9490 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	movs r5, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D9494
	asrs r1, r0, #0xc
	b _081D949A
	.align 2, 0
_081D9480: .4byte 0x0203B400
_081D9484: .4byte 0x030046B8
_081D9488: .4byte 0x000003FF
_081D948C: .4byte 0x05000002
_081D9490: .4byte 0x085B0A08
_081D9494:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D949A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D94B4 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D94B8
	asrs r0, r0, #0xc
	b _081D94BE
	.align 2, 0
_081D94B4: .4byte 0x085B0A08
_081D94B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D94BE:
	movs r3, #0
	strh r0, [r4, #4]
	ldr r2, _081D9558 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D955C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081D9560 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, _081D9564 @ =0x03002BE0
	ldr r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r4, _081D9568 @ =0x000001FF
	adds r1, r4, #0
	ands r2, r1
	adds r0, r0, r2
	adds r1, r7, #0
	adds r1, #0x7a
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	strb r3, [r0]
_081D94F8:
	movs r5, #0x1e
	ldrsh r0, [r7, r5]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	cmp r0, r1
	bge _081D956C
	adds r4, r7, #0
	adds r4, #0x70
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov sb, r4
	adds r1, r7, #0
	adds r1, #0x5a
	cmp r0, #0
	bne _081D9522
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_081D9522:
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1]
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x78
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081D9588
	ldrh r0, [r7, #0x34]
	cmp r0, #5
	bne _081D9588
	b _081D957C
	.align 2, 0
_081D9558: .4byte 0x030046B8
_081D955C: .4byte 0x000003FF
_081D9560: .4byte 0x0203B400
_081D9564: .4byte 0x03002BE0
_081D9568: .4byte 0x000001FF
_081D956C:
	adds r1, r7, #0
	adds r1, #0x68
	movs r0, #4
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D96A8
_081D957C:
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _081D9588
	movs r0, #0xf6
	bl PlaySound_082406e0
_081D9588:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D95BA
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D95C2
_081D95BA:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D95C2:
	str r0, [r7]
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
	beq _081D95E6
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D95EE
_081D95E6:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D95EE:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9628 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081D966E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9632
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D962C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D9648
	.align 2, 0
_081D9628: .4byte 0x0000FFFF
_081D962C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9646
_081D9632:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9646
	strh r1, [r4, #8]
	movs r2, #1
	b _081D9648
_081D9646:
	movs r2, #0
_081D9648:
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
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9670
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9670
_081D966E:
	movs r2, #0
_081D9670:
	cmp r2, #0
	beq _081D96A0
	adds r0, r7, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	ldr r5, [sp, #0xc]
	ldr r1, [r5, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r8
	movs r2, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_081D96A0:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D96A8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
