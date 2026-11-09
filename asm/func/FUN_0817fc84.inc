	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0817FCE8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FC9C
	movs r0, #0
	strb r0, [r1]
_0817FC9C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Shaian_GetAnimVariant
	movs r2, #0x98
	lsls r2, r2, #3
	adds r1, r5, r2
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r4, [sp, #8]
	ldrb r2, [r1]
	ldr r3, [sp, #4]
	orrs r4, r0
	ldr r1, _0817FCEC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817FCF8
	ldr r1, _0817FCF0 @ =0x000004B7
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
	ldr r2, _0817FCF4 @ =0x0000046E
	adds r7, r5, r2
	b _0817FD7A
	.align 2, 0
_0817FCE8: .4byte 0x0000046D
_0817FCEC: .4byte 0x0000025D
_0817FCF0: .4byte 0x000004B7
_0817FCF4: .4byte 0x0000046E
_0817FCF8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0817FD68 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817FD6C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817FD32
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817FD32
	cmp r4, #1
	bne _0817FD24
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817FD7E
_0817FD24:
	cmp r4, #0
	bne _0817FD32
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817FD7E
_0817FD32:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817FD44
	movs r3, #6
_0817FD44:
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
	beq _0817FD70
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0817FD78
	.align 2, 0
_0817FD68: .4byte 0x000004B7
_0817FD6C: .4byte 0x0000046E
_0817FD70:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817FD78:
	str r0, [r6, #8]
_0817FD7A:
	movs r0, #0
	strb r0, [r7]
_0817FD7E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
