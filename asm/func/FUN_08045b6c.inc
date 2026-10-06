	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #0xc]
	movs r0, #0x60
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r4, r1
	str r1, [sp, #0x10]
	movs r2, #0x68
	adds r2, r2, r4
	mov sb, r2
	adds r3, r4, #0
	adds r3, #0xa4
	str r3, [sp, #0x14]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08045C64
	movs r5, #0
	strb r5, [r4, #5]
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	mov r6, sb
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	ldrh r1, [r2, #2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	mov r6, sl
	strb r0, [r6, #5]
	ldrb r0, [r4, #7]
	ldr r2, _08045C04 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	ldr r6, [sp, #0x14]
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045C08 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045C0C
	adds r0, r4, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _08045C12
	.align 2, 0
_08045C04: .4byte 0x085AB414
_08045C08: .4byte 0x0000192C
_08045C0C:
	adds r0, r4, #0
	adds r0, #0x2c
	strb r5, [r0]
_08045C12:
	adds r2, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045C22
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045C28
_08045C22:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045C28:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r5]
	cmp r0, #0
	beq _08045C50
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08045C58
_08045C50:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08045C58:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x36
	strb r0, [r1]
_08045C64:
	mov r2, r8
	ldr r0, [r2, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp, #0xc]
	cmp r0, r3
	bne _08045CF8
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08045CA0
	mov r0, r8
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045CA0
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045E58
_08045CA0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08045CF8
	mov r5, r8
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08045CF8
	mov r2, r8
	adds r2, #0x20
	adds r3, r4, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r6, [r3]
	cmp r0, r6
	bne _08045CCE
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08045CE8
_08045CCE:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08045CF8
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08045CF8
_08045CE8:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045E58
_08045CF8:
	mov r0, r8
	ldr r2, [r0, #0x18]
	ldr r3, [r4, #0x3c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov r6, sb
	movs r5, #0
	ldrsh r0, [r6, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D10
	rsbs r1, r1, #0
_08045D10:
	cmp r1, r3
	bge _08045D42
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r5, sb
	movs r6, #2
	ldrsh r0, [r5, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D26
	rsbs r1, r1, #0
_08045D26:
	cmp r1, #0xff
	bgt _08045D42
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, sb
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D3C
	rsbs r1, r1, #0
_08045D3C:
	movs r0, #1
	cmp r1, r3
	blt _08045D44
_08045D42:
	movs r0, #0
_08045D44:
	cmp r0, #0
	beq _08045D54
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	b _08045DAE
_08045D54:
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08045D9E
	ldr r0, [sp, #0x14]
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08045D98
	ldr r2, [sp, #0x14]
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r5, #0x20
	cmp r0, #0
	beq _08045D7C
	movs r5, #0x10
_08045D7C:
	mov r1, sl
	adds r1, #8
	mov r2, sl
	adds r2, #0x10
	mov r3, sl
	adds r3, #5
	movs r0, #0x28
	str r0, [sp]
	str r0, [sp, #4]
	str r5, [sp, #8]
	ldr r0, [sp, #0x10]
	bl Map_GetStepToPathNode
	strb r0, [r6]
_08045D98:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08045DB8
_08045D9E:
	ldr r3, [sp, #0x14]
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08045DB8
	movs r1, #0
	strb r1, [r4, #4]
_08045DAE:
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08045E58
_08045DB8:
	ldrb r0, [r4, #7]
	ldr r2, _08045E00 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r5, r8
	adds r7, r0, r5
	ldr r0, _08045E04 @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r1, #1
	mov r8, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045E08
	adds r0, r4, #0
	adds r0, #0x2c
	mov r2, r8
	strb r2, [r0]
	adds r2, r0, #0
	b _08045E12
	.align 2, 0
_08045E00: .4byte 0x085AB414
_08045E04: .4byte 0x0000192C
_08045E08:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08045E12:
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045E20
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045E26
_08045E20:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045E26:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045E4E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045E56
_08045E4E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045E56:
	str r1, [r6, #8]
_08045E58:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
