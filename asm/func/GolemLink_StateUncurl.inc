	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081BAEF0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BAEF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BAEF6
	.align 2, 0
_081BAEF0: .4byte 0x0000046D
_081BAEF4:
	movs r0, #0
_081BAEF6:
	cmp r0, #0
	beq _081BAFD2
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r1, [r4]
	movs r0, #4
	movs r2, #7
	adds r4, r1, #0
	orrs r4, r0
	ldr r1, _081BAF3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BAF48
	ldr r1, _081BAF40 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r0, _081BAF44 @ =0x0000046E
	adds r7, r5, r0
	b _081BAFC6
	.align 2, 0
_081BAF3C: .4byte 0x0000025D
_081BAF40: .4byte 0x000004B7
_081BAF44: .4byte 0x0000046E
_081BAF48:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r3, #7
	ldr r1, _081BAFB4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BAFB8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081BAF82
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAF82
	cmp r4, #1
	bne _081BAF74
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BAFCA
_081BAF74:
	cmp r4, #0
	bne _081BAF82
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BAFCA
_081BAF82:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BAF94
	movs r3, #6
_081BAF94:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BAFBC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081BAFC4
	.align 2, 0
_081BAFB4: .4byte 0x000004B7
_081BAFB8: .4byte 0x0000046E
_081BAFBC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BAFC4:
	str r0, [r6, #8]
_081BAFC6:
	movs r0, #0
	strb r0, [r7]
_081BAFCA:
	ldr r0, _081BB000 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081BAFD2:
	ldr r1, _081BB000 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BAFF2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _081BB004 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081BB008 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081BAFF2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BB000: .4byte 0x0000046E
_081BB004: .4byte 0xFFFFFEFF
_081BB008: .4byte 0x0000046B
