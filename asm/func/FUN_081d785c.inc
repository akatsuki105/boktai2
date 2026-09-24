	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081D78BC @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D786C
	b _081D7A58
_081D786C:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D788C
	adds r0, r5, #0
	bl FUN_081d7814
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
_081D788C:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D78C8
	.align 2, 0
_081D78BC: .4byte 0x0300019C
_081D78C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D78C8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D78F4
_081D78EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D78F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D792C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7972
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7936
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7930
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D794C
	.align 2, 0
_081D792C: .4byte 0x0000FFFF
_081D7930:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D794A
_081D7936:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D794A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D794C
_081D794A:
	movs r2, #0
_081D794C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081D7974
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7974
_081D7972:
	movs r2, #0
_081D7974:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _081D7A4C
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081D79BA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081D7A48 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79BA:
	ldrh r0, [r4]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081D79EA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	adds r0, #0x40
	add r1, sp, #4
	strh r0, [r1]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79EA:
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081D7A18
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r1, sp, #4
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7A18:
	ldrh r0, [r4]
	movs r1, #7
	bl Mod
	cmp r0, #0
	bne _081D7A3C
	adds r4, r7, #0
	adds r4, #0xa4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _081D7A3C
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_081D7A3C:
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	b _081D7A56
	.align 2, 0
_081D7A48: .4byte 0xFFFF0000
_081D7A4C:
	cmp r2, #0
	beq _081D7A58
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
_081D7A56:
	strh r0, [r1]
_081D7A58:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
