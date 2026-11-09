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
	ldr r3, _08167330 @ =0x0000046D
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08167334
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08167336
	.align 2, 0
_08167330: .4byte 0x0000046D
_08167334:
	movs r0, #0
_08167336:
	adds r2, r0, #0
	cmp r2, #0
	beq _08167424
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	add r2, sp, #8
	add r1, sp, #4
	bl Bee_GetAnimVariant
	ldr r3, _08167384 @ =0x000004C4
	adds r0, r5, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08167388 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08167394
	ldr r1, _0816738C @ =0x000004B7
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
	ldr r3, _08167390 @ =0x0000046E
	adds r7, r5, r3
	b _08167416
	.align 2, 0
_08167384: .4byte 0x000004C4
_08167388: .4byte 0x0000025D
_0816738C: .4byte 0x000004B7
_08167390: .4byte 0x0000046E
_08167394:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08167404 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167408 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081673CE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081673CE
	cmp r4, #1
	bne _081673C0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816741A
_081673C0:
	cmp r4, #0
	bne _081673CE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816741A
_081673CE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081673E0
	movs r3, #6
_081673E0:
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
	beq _0816740C
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _08167414
	.align 2, 0
_08167404: .4byte 0x000004B7
_08167408: .4byte 0x0000046E
_0816740C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08167414:
	str r0, [r6, #8]
_08167416:
	movs r0, #0
	strb r0, [r7]
_0816741A:
	adds r0, r5, #0
	movs r1, #1
	bl Enemy_PlayAnim
	b _08167530
_08167424:
	ldr r0, _08167488 @ =0x00000663
	add r0, sl
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	bne _08167438
	b _08167544
_08167438:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrh r0, [r0, #8]
	str r0, [sp, #0xc]
	mov r3, r8
	ldrh r3, [r3, #0xe]
	str r3, [sp, #0x10]
	ldrb r0, [r1]
	add r2, sp, #8
	add r1, sp, #4
	bl Bee_GetAnimVariant
	ldr r1, _0816748C @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08167490 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816749C
	ldr r1, _08167494 @ =0x000004B7
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
	ldr r3, _08167498 @ =0x0000046E
	adds r7, r5, r3
	b _0816751E
	.align 2, 0
_08167488: .4byte 0x00000663
_0816748C: .4byte 0x000004C4
_08167490: .4byte 0x0000025D
_08167494: .4byte 0x000004B7
_08167498: .4byte 0x0000046E
_0816749C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816750C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167510 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081674D6
	ldrb r0, [r7]
	cmp r0, #0
	bne _081674D6
	cmp r4, #1
	bne _081674C8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08167522
_081674C8:
	cmp r4, #0
	bne _081674D6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08167522
_081674D6:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081674E8
	movs r3, #6
_081674E8:
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
	beq _08167514
	ldr r0, [r6, #8]
	mov r3, sb
	orrs r0, r3
	b _0816751C
	.align 2, 0
_0816750C: .4byte 0x000004B7
_08167510: .4byte 0x0000046E
_08167514:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816751C:
	str r0, [r6, #8]
_0816751E:
	movs r0, #0
	strb r0, [r7]
_08167522:
	mov r0, sp
	ldrh r1, [r0, #0xc]
	mov r0, r8
	strh r1, [r0, #8]
	mov r3, sp
	ldrh r3, [r3, #0x10]
	strh r3, [r0, #0xe]
_08167530:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r0, _08167540 @ =0x00000663
	add r0, sl
	strb r1, [r0]
	b _0816754A
	.align 2, 0
_08167540: .4byte 0x00000663
_08167544:
	ldr r3, _0816755C @ =0x0000046E
	adds r0, r5, r3
	strb r2, [r0]
_0816754A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816755C: .4byte 0x0000046E
