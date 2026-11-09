	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _08171FC0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171FC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171FC6
	.align 2, 0
_08171FC0: .4byte 0x0000046D
_08171FC4:
	movs r0, #0
_08171FC6:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _08172018
	adds r0, r6, #0
	bl FUN_0817b848
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0817205C @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08172060 @ =0x00001008
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08172018:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Sandworm_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08172064 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172070
	ldr r1, _08172068 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0817206C @ =0x0000046E
	adds r7, r6, r2
	b _081720F2
	.align 2, 0
_0817205C: .4byte 0xFFEFFFFF
_08172060: .4byte 0x00001008
_08172064: .4byte 0x0000025D
_08172068: .4byte 0x000004B7
_0817206C: .4byte 0x0000046E
_08172070:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _081720E0 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081720E4 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _081720AA
	ldrb r0, [r7]
	cmp r0, #0
	bne _081720AA
	cmp r4, #1
	bne _0817209C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081720F6
_0817209C:
	cmp r4, #0
	bne _081720AA
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081720F6
_081720AA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081720BC
	movs r3, #6
_081720BC:
	ldr r1, [r6, #0x44]
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
	beq _081720E8
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _081720F0
	.align 2, 0
_081720E0: .4byte 0x000004B7
_081720E4: .4byte 0x0000046E
_081720E8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081720F0:
	str r0, [r5, #8]
_081720F2:
	movs r0, #0
	strb r0, [r7]
_081720F6:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_08177a4c
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08172168
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08172158 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _0817215C @ =FUN_08172188
	movs r2, #0x24
	ldr r0, _08172160 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08172164 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _08172178
	.align 2, 0
_08172158: .4byte 0xFFFFFEFF
_0817215C: .4byte FUN_08172188
_08172160: .4byte 0x0000046D
_08172164: .4byte 0x0000046B
_08172168:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08172178:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
