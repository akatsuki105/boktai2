	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldr r0, _0800C5B8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	mov sb, r1
	cmp r0, #0
	beq _0800C52A
	adds r0, #0x2c
	mov sb, r0
_0800C52A:
	movs r4, #0
	ldr r6, [r7, #0x20]
	mov r8, r4
	ldrb r2, [r7, #0x18]
	cmp r8, r2
	blt _0800C538
	b _0800C66E
_0800C538:
	movs r0, #4
	mov sl, r0
	adds r5, r6, #0
_0800C53E:
	movs r1, #1
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0800C54E
	b _0800C65E
_0800C54E:
	movs r1, #2
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800C5C0
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq _0800C5A6
	ldrh r0, [r5]
	str r0, [sp]
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	str r0, [sp, #4]
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r2, #0x18
	ldrsh r0, [r5, r2]
	str r0, [sp, #0xc]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x10]
	movs r2, #0xe
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x14]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x18]
	movs r2, #0x12
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x1c]
	ldr r1, _0800C5BC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #8]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #8]
_0800C5A6:
	adds r0, r6, #0
	bl Hazard_EmitBreakEffect
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, r8
	bl Hazard_Remove
	b _0800C65E
	.align 2, 0
_0800C5B8: .4byte 0x03002BE0
_0800C5BC: .4byte 0xFFFF0000
_0800C5C0:
	ldrb r1, [r5, #0xa]
	cmp r1, #0
	beq _0800C5E8
	ldrh r0, [r5, #0x32]
	mov r2, sl
	orrs r0, r2
	strh r0, [r5, #0x32]
	subs r0, r1, #1
	strb r0, [r5, #0xa]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800C5F2
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, _0800C5E4 @ =0x0000011B
	bl Video_SetAuxSpritePltt
	b _0800C5F2
	.align 2, 0
_0800C5E4: .4byte 0x0000011B
_0800C5E8:
	ldrh r1, [r5, #0x32]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5, #0x32]
_0800C5F2:
	mov r0, sb
	cmp r0, #0
	beq _0800C65E
	cmp r4, #0
	bne _0800C65E
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x1c
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x26
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #0x20
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	movs r0, #1
	b _0800C642
_0800C640:
	movs r0, #0
_0800C642:
	cmp r0, #0
	beq _0800C65E
	adds r4, r7, #0
	adds r4, #0x24
	adds r1, r6, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r4, #1
_0800C65E:
	movs r0, #1
	add r8, r0
	adds r5, #0xd4
	adds r6, #0xd4
	ldrb r1, [r7, #0x18]
	cmp r8, r1
	bge _0800C66E
	b _0800C53E
_0800C66E:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
