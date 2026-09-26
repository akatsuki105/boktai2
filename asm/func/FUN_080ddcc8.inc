	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r2, #0
	str r3, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #8]
	ldr r0, _080DDCF8 @ =0x03000174
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	bl Entity080de11c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	movs r0, #0
	b _080DDF74
	.align 2, 0
_080DDCF8: .4byte 0x03000174
_080DDCFC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, _080DDD34 @ =0x030046B8
	mov sb, r1
	ldr r2, [sp, #0x10]
	adds r2, #0x50
	mov sl, r2
	ldr r0, [sp, #0x10]
	adds r0, #0x28
	mov r8, r0
	mov r4, r8
	ldr r1, [sp, #0x10]
	adds r1, #0x18
	str r1, [sp, #0x18]
_080DDD18:
	mov r2, sl
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _080DDD22
	b _080DDF58
_080DDD22:
	cmp r6, #0
	beq _080DDE0E
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _080DDD38
	ldrh r0, [r7]
	b _080DDD78
	.align 2, 0
_080DDD34: .4byte 0x030046B8
_080DDD38:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDD64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDD68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDD6C
	asrs r0, r0, #1
	b _080DDD72
	.align 2, 0
_080DDD64: .4byte 0x000003FF
_080DDD68: .4byte 0x0203B400
_080DDD6C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDD72:
	subs r0, r1, r0
	ldrh r1, [r7]
	adds r0, r0, r1
_080DDD78:
	strh r0, [r4, #0x18]
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _080DDD86
	ldrh r0, [r7, #2]
	b _080DDDC4
_080DDD86:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDB0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDB4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDDB8
	asrs r0, r0, #1
	b _080DDDBE
	.align 2, 0
_080DDDB0: .4byte 0x000003FF
_080DDDB4: .4byte 0x0203B400
_080DDDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDDBE:
	subs r0, r1, r0
	ldrh r1, [r7, #2]
	adds r0, r0, r1
_080DDDC4:
	strh r0, [r4, #0x1a]
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq _080DDE16
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDF8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDFC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDE00
	asrs r0, r0, #1
	b _080DDE06
	.align 2, 0
_080DDDF8: .4byte 0x000003FF
_080DDDFC: .4byte 0x0203B400
_080DDE00:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDE06:
	subs r0, r1, r0
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	b _080DDE18
_080DDE0E:
	ldrh r0, [r7]
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	strh r0, [r4, #0x1a]
_080DDE16:
	ldrh r0, [r7, #4]
_080DDE18:
	strh r0, [r4, #0x1c]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r2, sp, #0x48
	ldrb r2, [r2]
	strb r2, [r4, #0xf]
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #8]
	movs r2, #0
	str r2, [sp, #4]
	add r0, sp, #4
	ldr r2, _080DDE64 @ =0x05000002
	bl CpuSet
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _080DDE9A
	mov r3, sl
	ldr r2, _080DDE68 @ =0x085B0A08
	ldr r0, [sp, #0xc]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE6C
	asrs r0, r0, #0xc
	b _080DDE72
	.align 2, 0
_080DDE64: .4byte 0x05000002
_080DDE68: .4byte 0x085B0A08
_080DDE6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE72:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	movs r0, #0xff
	ldr r1, [sp, #0xc]
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE92
	asrs r0, r0, #0xc
	b _080DDE98
_080DDE92:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE98:
	strh r0, [r3, #4]
_080DDE9A:
	ldr r2, [sp, #0x40]
	cmp r2, #0
	bne _080DDEC0
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDEB8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDEBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x20
	b _080DDED6
	.align 2, 0
_080DDEB8: .4byte 0x000003FF
_080DDEBC: .4byte 0x0203B400
_080DDEC0:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDEEC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDEF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x40]
_080DDED6:
	bl Mod
	strh r0, [r4, #0x2a]
	ldr r0, [sp, #0x44]
	cmp r0, #1
	beq _080DDF00
	cmp r0, #1
	bgt _080DDEF4
	cmp r0, #0
	beq _080DDF00
	b _080DDF1C
	.align 2, 0
_080DDEEC: .4byte 0x000003FF
_080DDEF0: .4byte 0x0203B400
_080DDEF4:
	ldr r1, [sp, #0x44]
	cmp r1, #2
	beq _080DDF0C
	cmp r1, #3
	beq _080DDF10
	b _080DDF1C
_080DDF00:
	movs r5, #0xf
	mov r0, r8
	movs r1, #1
	bl FUN_0822dadc
	b _080DDF26
_080DDF0C:
	movs r5, #0x10
	b _080DDF12
_080DDF10:
	movs r5, #0x11
_080DDF12:
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
	b _080DDF26
_080DDF1C:
	movs r5, #0xf
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
_080DDF26:
	ldr r2, [sp, #0x10]
	ldr r1, _080DDF84 @ =0x00000CD8
	adds r0, r2, r1
	ldr r1, [r0]
	adds r2, r5, #0
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x18]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [sp, #8]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #0
	beq _080DDF72
_080DDF58:
	movs r1, #0x44
	add sl, r1
	adds r4, #0x44
	add r8, r1
	ldr r2, [sp, #0x18]
	adds r2, #0x44
	str r2, [sp, #0x18]
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0x2f
	bgt _080DDF72
	b _080DDD18
_080DDF72:
	movs r0, #1
_080DDF74:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DDF84: .4byte 0x00000CD8
