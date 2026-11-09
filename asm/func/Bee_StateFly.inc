	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08167048 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816704C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816704E
	.align 2, 0
_08167048: .4byte 0x0000046D
_0816704C:
	movs r0, #0
_0816704E:
	adds r1, r0, #0
	cmp r1, #0
	beq _08167140
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Bee_GetAnimVariant
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strb r1, [r0, #5]
	ldr r1, _0816709C @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081670A0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081670AC
	ldr r1, _081670A4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _081670A8 @ =0x0000046E
	adds r7, r5, r2
	b _0816712E
	.align 2, 0
_0816709C: .4byte 0x000004C4
_081670A0: .4byte 0x0000025D
_081670A4: .4byte 0x000004B7
_081670A8: .4byte 0x0000046E
_081670AC:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816711C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167120 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081670E6
	ldrb r0, [r7]
	cmp r0, #0
	bne _081670E6
	cmp r4, #1
	bne _081670D8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08167132
_081670D8:
	cmp r4, #0
	bne _081670E6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08167132
_081670E6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081670F8
	movs r3, #6
_081670F8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08167124
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0816712C
	.align 2, 0
_0816711C: .4byte 0x000004B7
_08167120: .4byte 0x0000046E
_08167124:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816712C:
	str r0, [r6, #8]
_0816712E:
	movs r0, #0
	strb r0, [r7]
_08167132:
	ldrb r1, [r5, #5]
	ldr r0, _0816713C @ =0x00000663
	add r0, sl
	b _08167258
	.align 2, 0
_0816713C: .4byte 0x00000663
_08167140:
	ldr r0, _081671A0 @ =0x00000663
	add r0, sl
	ldrb r0, [r0]
	ldrb r2, [r5, #5]
	cmp r0, r2
	bne _0816714E
	b _08167254
_0816714E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrh r0, [r0, #8]
	str r0, [sp, #0xc]
	mov r1, r8
	ldrh r1, [r1, #0xe]
	str r1, [sp, #0x10]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Bee_GetAnimVariant
	ldr r2, _081671A4 @ =0x000004C4
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081671A8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081671B4
	ldr r1, _081671AC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _081671B0 @ =0x0000046E
	adds r7, r5, r2
	b _08167236
	.align 2, 0
_081671A0: .4byte 0x00000663
_081671A4: .4byte 0x000004C4
_081671A8: .4byte 0x0000025D
_081671AC: .4byte 0x000004B7
_081671B0: .4byte 0x0000046E
_081671B4:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08167224 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167228 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081671EE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081671EE
	cmp r4, #1
	bne _081671E0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816723A
_081671E0:
	cmp r4, #0
	bne _081671EE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816723A
_081671EE:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08167200
	movs r3, #6
_08167200:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816722C
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _08167234
	.align 2, 0
_08167224: .4byte 0x000004B7
_08167228: .4byte 0x0000046E
_0816722C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08167234:
	str r0, [r6, #8]
_08167236:
	movs r0, #0
	strb r0, [r7]
_0816723A:
	mov r0, sp
	ldrh r1, [r0, #0xc]
	mov r0, r8
	strh r1, [r0, #8]
	mov r2, sp
	ldrh r2, [r2, #0x10]
	strh r2, [r0, #0xe]
	ldrb r1, [r5, #5]
	ldr r0, _08167250 @ =0x00000663
	add r0, sl
	b _08167258
	.align 2, 0
_08167250: .4byte 0x00000663
_08167254:
	ldr r2, _0816726C @ =0x0000046E
	adds r0, r5, r2
_08167258:
	strb r1, [r0]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816726C: .4byte 0x0000046E
