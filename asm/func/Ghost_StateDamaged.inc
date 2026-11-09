	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0816BA2C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816BA30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816BA32
	.align 2, 0
_0816BA2C: .4byte 0x0000046D
_0816BA30:
	movs r0, #0
_0816BA32:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r7, r3
	cmp r0, #0
	beq _0816BA7C
	movs r0, #0x20
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816BA68
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0816BA70
_0816BA68:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0816BA70:
	adds r0, r7, #0
	bl Ghost_StopChase
	adds r0, r7, #0
	bl Ghost_ResumeHover
_0816BA7C:
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816BAE8
	adds r0, r4, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _0816BAE8
	ldr r2, _0816BB08 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0816BB0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _0816BB10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816BB14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0816BB18 @ =0x0203B400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl EmitSmoke
_0816BAE8:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r5, #0x85
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0816BB1C
	asrs r0, r0, #2
	b _0816BB22
	.align 2, 0
_0816BB08: .4byte 0xFFFF0000
_0816BB0C: .4byte 0x0000FFFF
_0816BB10: .4byte 0x030046B8
_0816BB14: .4byte 0x000003FF
_0816BB18: .4byte 0x0203B400
_0816BB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0816BB22:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #8
	adds r1, r7, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0816BB40
	asrs r0, r0, #2
	b _0816BB46
_0816BB40:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0816BB46:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0816BB50
	movs r3, #0xc8
	b _0816BB5A
_0816BB50:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0816BB5A
	adds r3, r0, #0
_0816BB5A:
	cmp r2, #0xc8
	ble _0816BB62
	movs r2, #0xc8
	b _0816BB6C
_0816BB62:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0816BB6C
	adds r2, r0, #0
_0816BB6C:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0816BB90
	cmp r2, #0
	bne _0816BB90
	movs r0, #1
	b _0816BB92
_0816BB90:
	movs r0, #0
_0816BB92:
	cmp r0, #0
	beq _0816BC18
	ldr r1, _0816BC28 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	bl Ghost_RestorePlayerSpeed
	movs r0, #0x29
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	movs r4, #0
	strh r0, [r6]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl Ghost_ResumeHover
	movs r2, #0x10
	ldr r1, _0816BC2C @ =0x000007DC
	add r1, sb
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0816BC30 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _0816BC34 @ =0x00000469
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0816BC38 @ =0x00000484
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r5, [r0]
_0816BC18:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816BC28: .4byte 0x0000046B
_0816BC2C: .4byte 0x000007DC
_0816BC30: .4byte 0x0000024E
_0816BC34: .4byte 0x00000469
_0816BC38: .4byte 0x00000484
