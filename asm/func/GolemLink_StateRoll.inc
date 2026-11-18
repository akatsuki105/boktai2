	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov sb, r6
	ldr r1, _081BACD8 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BACDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BACDE
	.align 2, 0
_081BACD8: .4byte 0x0000046D
_081BACDC:
	movs r0, #0
_081BACDE:
	cmp r0, #0
	beq _081BACEA
	ldr r2, _081BAD4C @ =0x0000046E
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
_081BACEA:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	mov r4, sp
	adds r4, #9
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BAD50 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BAD54 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x24]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _081BAD5C
	ldr r2, _081BAD58 @ =0x000004B7
	adds r0, r6, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _081BAD4C @ =0x0000046E
	adds r7, r6, r2
	b _081BADDE
	.align 2, 0
_081BAD4C: .4byte 0x0000046E
_081BAD50: .4byte 0x085ADFA8
_081BAD54: .4byte 0x0000025D
_081BAD58: .4byte 0x000004B7
_081BAD5C:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BADCC @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BADD0 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _081BAD98
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAD98
	cmp r4, #1
	bne _081BAD8A
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BADE2
_081BAD8A:
	cmp r4, #0
	bne _081BAD98
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BADE2
_081BAD98:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BADAC
	movs r3, #6
_081BADAC:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BADD4
	ldr r0, [r5, #8]
	mov r1, r8
	orrs r0, r1
	b _081BADDC
	.align 2, 0
_081BADCC: .4byte 0x000004B7
_081BADD0: .4byte 0x0000046E
_081BADD4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BADDC:
	str r0, [r5, #8]
_081BADDE:
	movs r0, #0
	strb r0, [r7]
_081BADE2:
	ldr r2, [sp, #0x1c]
	ldr r1, _081BAE0C @ =0x000006B6
	adds r0, r2, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BAE10 @ =0x00000482
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _081BAE14 @ =0x0000A02F
	ldr r2, [sp, #0x24]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BAE18
	ldr r0, _081BAE10 @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BAE28
	.align 2, 0
_081BAE0C: .4byte 0x000006B6
_081BAE10: .4byte 0x00000482
_081BAE14: .4byte 0x0000A02F
_081BAE18:
	ldr r1, _081BAE4C @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BAE28
	movs r0, #1
	strh r0, [r2]
_081BAE28:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BAE50
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081BAE68
	.align 2, 0
_081BAE4C: .4byte 0x00000482
_081BAE50:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081BAE68:
	movs r6, #3
	mov r2, sl
	ands r2, r6
	cmp r2, #0
	bne _081BAEBA
	mov r1, sb
	ldrh r0, [r1, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r4, _081BAECC @ =0xFFFF0000
	ldr r5, _081BAED0 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldrh r2, [r1, #0x14]
	rsbs r2, r2, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r3, #0x20
	orrs r0, r3
	ands r0, r5
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	mov r0, sb
	adds r0, #8
	str r6, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl DustManager_Spawn
_081BAEBA:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BAECC: .4byte 0xFFFF0000
_081BAED0: .4byte 0x0000FFFF
