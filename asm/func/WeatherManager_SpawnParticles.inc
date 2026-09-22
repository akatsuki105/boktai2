	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08017E98 @ =0x03002BE0
	ldr r0, [r0]
	mov r8, r0
	ldr r1, [sp]
	adds r1, #0x60
	ldrh r0, [r1]
	cmp r0, #0
	beq _08017E9C
	subs r0, #1
	strh r0, [r1]
	b _080180FA
	.align 2, 0
_08017E98: .4byte 0x03002BE0
_08017E9C:
	movs r0, #0
	str r1, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r0, r1
	blt _08017EA8
	b _080180CA
_08017EA8:
	ldr r3, _08017F34 @ =0x030046B8
	ldr r2, _08017F38 @ =0x00000FFF
	mov sl, r2
	ldr r4, _08017F3C @ =0xFFFFF800
	mov sb, r4
_08017EB2:
	ldr r1, [sp]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r7, r1, r2
	movs r1, #0
	adds r0, #1
	str r0, [sp, #0x10]
	adds r6, r7, #0
_08017EC2:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08017ECA
	b _080180B4
_08017ECA:
	strb r0, [r6, #2]
	strb r0, [r6, #1]
	strb r0, [r6, #3]
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08017F44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #4]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08017F44 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #8]
	adds r5, r7, #4
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08017F30
	cmp r1, #0
	blt _08017F30
	ldr r0, _08017F48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08017F30
	ldr r0, _08017F4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08017F50
_08017F30:
	movs r4, #0
	b _08017F5E
	.align 2, 0
_08017F34: .4byte 0x030046B8
_08017F38: .4byte 0x00000FFF
_08017F3C: .4byte 0xFFFFF800
_08017F40: .4byte 0x000003FF
_08017F44: .4byte 0x0203B400
_08017F48: .4byte 0x030046A8
_08017F4C: .4byte 0x030046AC
_08017F50:
	ldr r0, _08017F74 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08017F5E:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08017F78
	adds r0, #4
	b _08017F84
	.align 2, 0
_08017F74: .4byte 0x030046A4
_08017F78:
	ldr r0, _08017F98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08017F84:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08017F9C
	cmp r2, #2
	beq _08017FA0
	b _08017FA4
	.align 2, 0
_08017F98: .4byte 0x030046A4
_08017F9C:
	ldrb r0, [r5, #4]
	b _08017FA2
_08017FA0:
	ldrb r0, [r5]
_08017FA2:
	subs r1, r1, r0
_08017FA4:
	strh r1, [r6, #6]
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _0801800C @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08018010 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #0xc]
	adds r1, #1
	ldr r4, _0801800C @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08018010 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #0x10]
	adds r5, r7, #0
	adds r5, #0xc
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08018008
	cmp r1, #0
	blt _08018008
	ldr r0, _08018014 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08018008
	ldr r0, _08018018 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801801C
_08018008:
	movs r4, #0
	b _0801802A
	.align 2, 0
_0801800C: .4byte 0x000003FF
_08018010: .4byte 0x0203B400
_08018014: .4byte 0x030046A8
_08018018: .4byte 0x030046AC
_0801801C:
	ldr r0, _08018040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0801802A:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08018044
	adds r0, #4
	b _08018050
	.align 2, 0
_08018040: .4byte 0x030046A4
_08018044:
	ldr r0, _08018064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08018050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08018068
	cmp r2, #2
	beq _0801806C
	b _08018070
	.align 2, 0
_08018064: .4byte 0x030046A4
_08018068:
	ldrb r0, [r5, #4]
	b _0801806E
_0801806C:
	ldrb r0, [r5]
_0801806E:
	subs r1, r1, r0
_08018070:
	strh r1, [r6, #0xe]
	adds r5, r7, #0
	adds r5, #0x14
	ldrb r0, [r6, #3]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r1, [r0, #8]
	ldr r0, [r0, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	ldr r1, [sp]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x1e
	str r3, [sp, #0x18]
	bl FUN_0822dafc
	movs r4, #1
	strb r4, [r5, #0xf]
	ldr r0, [r6, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x14]
	adds r0, r5, #0
	movs r1, #0
	bl Video_AddParticleIntoDrawList
	strb r4, [r6]
	ldr r3, [sp, #0x18]
	b _080180C0
_080180B4:
	adds r1, #1
	adds r6, #0x3c
	adds r7, #0x3c
	cmp r1, #0x1f
	bgt _080180C0
	b _08017EC2
_080180C0:
	ldr r0, [sp, #0x10]
	ldr r4, [sp, #4]
	cmp r0, r4
	bge _080180CA
	b _08017EB2
_080180CA:
	mov r0, sp
	ldrh r1, [r0, #8]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _080180FA
	ldr r2, _0801810C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08018110 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08018114 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080180FA:
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801810C: .4byte 0x030046B8
_08018110: .4byte 0x000003FF
_08018114: .4byte 0x0203B400
