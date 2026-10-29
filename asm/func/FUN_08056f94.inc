	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	bl Hitbox_ApplyDamage
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r6, #6]
	ands r0, r1
	cmp r0, #0
	beq _08056FBA
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08056FD4
_08056FBA:
	movs r1, #0x24
	ldrsh r0, [r7, r1]
	movs r2, #0x24
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r7, r3]
	movs r3, #0x28
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
_08056FD4:
	movs r0, #1
	ldr r1, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08057004
	ldr r0, _08057000 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x10
	ldrsh r1, [r7, r3]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	movs r0, #0x10
	b _08057044
	.align 2, 0
_08057000: .4byte 0x03002BE0
_08057004:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08057012
	movs r1, #0x20
	mov ip, r1
	b _08057046
_08057012:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08057038
	movs r2, #0xc
	ldrsh r0, [r7, r2]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r2, #0x10
	ldrsh r1, [r7, r2]
	movs r3, #0x10
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	movs r0, #0x18
	b _08057044
_08057038:
	movs r0, #8
	ands r1, r0
	movs r2, #0x10
	mov ip, r2
	cmp r1, #0
	beq _08057046
_08057044:
	mov ip, r0
_08057046:
	ldr r2, _08057088 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805708C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08057090 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r2, r3, #4
	movs r1, #7
	ands r0, r1
	adds r3, r2, r0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, _08057094 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08057098
	asrs r1, r0, #0xc
	b _0805709E
	.align 2, 0
_08057088: .4byte 0x030046B8
_0805708C: .4byte 0x000003FF
_08057090: .4byte 0x0203B400
_08057094: .4byte gSineTable
_08057098:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805709E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080570BE
	asrs r0, r0, #0xc
	b _080570C4
_080570BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080570C4:
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r3, _08057134 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08057138 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r7, #0x3e]
	adds r3, r4, #0
	adds r3, #0x68
	add r2, sp, #8
	str r2, [sp]
	movs r5, #1
	str r5, [sp, #4]
	adds r0, r7, #0
	movs r2, #0
	bl CreateDamageNumber
	ldrh r0, [r6, #0x3e]
	adds r0, #2
	strh r0, [r6, #0x3e]
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r4]
	ldrh r1, [r7, #0x3e]
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805713C
	mov r3, r8
	strh r3, [r4]
	movs r0, #7
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r0, r8
	str r0, [r4, #0x14]
	b _08057146
	.align 2, 0
_08057134: .4byte 0xFFFF0000
_08057138: .4byte 0x0000FFFF
_0805713C:
	movs r0, #6
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r1, r8
	str r1, [r4, #0x14]
_08057146:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
