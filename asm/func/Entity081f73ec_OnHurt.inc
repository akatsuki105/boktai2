	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x44
	ldrh r5, [r4]
	cmp r5, #0
	beq _081F5E78
	b _081F6006
_081F5E78:
	adds r0, r7, #0
	bl Hitbox_ApplyDamage
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r4]
	mov r0, r8
	bl Entity081f73ec_StartFlash
	add r0, sp, #0x14
	add r4, sp, #0x18
	str r5, [sp, #0x14]
	adds r1, r4, #0
	ldr r2, _081F5EF8 @ =0x05000002
	bl CpuSet
	ldrh r1, [r6, #0x3e]
	mov r3, r8
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl CreateDamageNumber
	add r1, sp, #0x10
	movs r0, #6
	strh r0, [r1]
	ldrh r0, [r6, #0x3e]
	strh r0, [r1, #2]
	movs r0, #0x19
	bl FUN_080ec79c
	ldr r2, _081F5EFC @ =0x000006E4
	add r2, sb
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _081F5EE2
	b _081F6006
_081F5EE2:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F5F00
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _081F5F62
	.align 2, 0
_081F5EF8: .4byte 0x05000002
_081F5EFC: .4byte 0x000006E4
_081F5F00:
	add r3, sp, #0x20
	adds r5, r6, #0
	adds r5, #0xc
	adds r4, r7, #0
	adds r4, #0xc
	ldrh r2, [r7, #0xc]
	ldrh r0, [r6, #0xc]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r0, r1, r0
	strh r0, [r3, #4]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne _081F5F50
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081F5F50
	ldr r0, _081F5F44 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _081F5F48 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _081F5F4C @ =0x0203B400
	adds r1, r1, r0
	ldrb r3, [r1]
	b _081F5F62
	.align 2, 0
_081F5F44: .4byte 0x030046B8
_081F5F48: .4byte 0x000003FF
_081F5F4C: .4byte 0x0203B400
_081F5F50:
	movs r1, #0
	ldrsh r0, [r3, r1]
	add r1, sp, #0x20
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_081F5F62:
	mov r2, r8
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldr r0, _081F6018 @ =0x0203B400
	mov r8, r0
	ldr r1, _081F601C @ =0x030046B8
	mov sl, r1
	ldr r4, [r1]
	adds r4, #1
	ldr r6, _081F6020 @ =0x000003FF
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldr r2, [sp, #0x30]
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081F6024 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _081F6028 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r5
	movs r1, #0x3c
	orrs r0, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r5
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r5, [r0]
	movs r0, #7
	ands r5, r0
	adds r5, #4
	adds r4, #1
	ands r4, r6
	mov r1, sl
	str r4, [r1]
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r4]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x30
	str r5, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	bl EmitSmoke
_081F6006:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F6018: .4byte 0x0203B400
_081F601C: .4byte 0x030046B8
_081F6020: .4byte 0x000003FF
_081F6024: .4byte 0x0000FFFF
_081F6028: .4byte 0xFFFF0000
