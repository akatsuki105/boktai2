	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r1
	mov r7, sl
	adds r7, #0x20
	ldrb r0, [r1, #9]
	cmp r0, #0
	beq _08044B40
	movs r4, #0
	strb r4, [r1, #9]
	strb r4, [r1, #7]
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r1, #8
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	mov r2, sl
	strh r4, [r2, #0x20]
	strh r4, [r7, #2]
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08044B3C
	ldr r0, _08044AEC @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08044AF0 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08044AF4 @ =0x0203B400
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x54
	bgt _08044AFC
	ldr r0, _08044AF8 @ =0x000002DE
	bl PlaySound_082406e0
	b _08044B14
	.align 2, 0
_08044AEC: .4byte 0x030046B8
_08044AF0: .4byte 0x000003FF
_08044AF4: .4byte 0x0203B400
_08044AF8: .4byte 0x000002DE
_08044AFC:
	cmp r0, #0xa9
	bgt _08044B0C
	ldr r0, _08044B08 @ =0x000002DF
	bl PlaySound_082406e0
	b _08044B14
	.align 2, 0
_08044B08: .4byte 0x000002DF
_08044B0C:
	movs r0, #0xb8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08044B14:
	ldr r2, _08044B30 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08044B34 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08044B38 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #1
	b _08044B3E
	.align 2, 0
_08044B30: .4byte 0x030046B8
_08044B34: .4byte 0x000003FF
_08044B38: .4byte 0x0203B400
_08044B3C:
	subs r0, #1
_08044B3E:
	strb r0, [r7, #4]
_08044B40:
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08044B58
	b _08044D8A
_08044B58:
	ldr r1, [r7]
	movs r0, #0xc0
	lsls r0, r0, #0xa
	cmp r1, r0
	beq _08044B64
	b _08044D3A
_08044B64:
	mov r2, sl
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	adds r0, #0xc8
	add r1, sp, #0x1c
	strh r0, [r1]
	ldr r5, _08044D5C @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #4]
	movs r0, #0xa
	mov r8, r0
	str r0, [sp, #8]
	movs r6, #5
	str r6, [sp, #0xc]
	movs r4, #8
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r6, #0xe
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl Entity080146e0_SpawnAtAngle
	bl FUN_0801dfe4
	adds r4, r0, #0
	bl FUN_0801e00c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0801c0d8
	ldr r0, _08044D68 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #2
	bl FUN_0807c7c8
_08044D3A:
	ldrh r0, [r7, #2]
	adds r0, #1
	movs r4, #0
	strh r0, [r7, #2]
	mov r0, sl
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044D8A
	ldrh r0, [r7]
	cmp r0, #0
	beq _08044D6C
	cmp r0, #1
	beq _08044D7E
	b _08044D8A
	.align 2, 0
_08044D5C: .4byte 0x030046B8
_08044D60: .4byte 0x000003FF
_08044D64: .4byte 0x0203B400
_08044D68: .4byte 0x03002BE0
_08044D6C:
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044D82
_08044D7E:
	mov r1, sl
	strb r0, [r1, #7]
_08044D82:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	strh r4, [r7, #2]
_08044D8A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
