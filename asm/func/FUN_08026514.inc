	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	adds r5, r1, #0
	mov r7, r8
	movs r0, #0x48
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802657C
	movs r4, #0
	strb r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0
	bl Boss_PlayAnim
	bl FUN_080591f4
	movs r1, #6
	cmp r0, #6
	ble _0802656C
	movs r1, #3
_0802656C:
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0802657C:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08026590
	b _08026728
_08026590:
	movs r2, #0x80
	lsls r2, r2, #1
	mov sl, r2
	mov r0, r8
	add r0, sl
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080265AA
	b _08026728
_080265AA:
	movs r6, #7
	ands r6, r5
	cmp r6, #0
	bne _08026632
	ldr r4, _08026670 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08026674 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	ldr r5, _08026678 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802667C @ =0x000001FF
	mov ip, r2
	mov r5, ip
	ands r0, r5
	mov r2, sb
	ldrh r2, [r2, #8]
	adds r0, r0, r2
	ldr r5, _08026680 @ =0xFFFFFF00
	adds r0, r0, r5
	lsls r0, r0, #0x10
	ldr r2, _08026684 @ =0xFFFF0000
	mov ip, r2
	mov r5, sb
	ldrh r5, [r5, #0xa]
	lsls r2, r5, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r2
	str r0, [sp, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	ldr r0, _08026678 @ =0x0203B400
	adds r1, r1, r0
	ldrb r1, [r1]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	adds r0, r0, r1
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	mov r5, ip
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08026688 @ =0x00003001
	str r6, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #0xe
	str r0, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	add r1, sp, #0x1c
	str r1, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08026632:
	mov r0, r8
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _08026648
	movs r2, #1
_08026648:
	cmp r2, #0
	beq _0802668C
	ldr r5, [sp, #0x24]
	ldrh r1, [r5]
	mov r0, r8
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r5, #4]
	adds r0, #4
	strh r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _080266F2
	movs r0, #1
	strh r0, [r1]
	b _080266E6
	.align 2, 0
_08026670: .4byte 0x030046B8
_08026674: .4byte 0x000003FF
_08026678: .4byte 0x0203B400
_0802667C: .4byte 0x000001FF
_08026680: .4byte 0xFFFFFF00
_08026684: .4byte 0xFFFF0000
_08026688: .4byte 0x00003001
_0802668C:
	mov r0, r8
	adds r0, #0xc8
	ldr r2, _080266B8 @ =0x0000055C
	adds r1, r7, r2
	mov r3, r8
	adds r3, #0x58
	ldrb r4, [r0]
	ldrh r5, [r1]
	ldr r2, _080266BC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080266C0
	asrs r1, r0, #0xc
	b _080266C6
	.align 2, 0
_080266B8: .4byte 0x0000055C
_080266BC: .4byte gSineTable
_080266C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080266C6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080266DE
	asrs r0, r0, #0xc
	b _080266E4
_080266DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080266E4:
	strh r0, [r3, #4]
_080266E6:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08026712
_080266F2:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	bhi _08026706
	adds r0, #0x20
	b _08026726
_08026706:
	strh r2, [r1]
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08026728
_08026712:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r3, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	cmp r3, r0
	bls _08026728
	adds r0, r3, #0
	subs r0, #0x10
_08026726:
	strh r0, [r1]
_08026728:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
