	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0817FDAC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FDB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FDB2
	.align 2, 0
_0817FDAC: .4byte 0x0000046D
_0817FDB0:
	movs r0, #0
_0817FDB2:
	cmp r0, #0
	bne _0817FDB8
	b _0817FECA
_0817FDB8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Shaian_GetAnimVariant
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r2, _0817FE18 @ =0x000004F9
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r4, [sp, #8]
	ldrb r2, [r1]
	ldr r3, [sp, #4]
	orrs r4, r0
	ldr r1, _0817FE1C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817FE28
	ldr r1, _0817FE20 @ =0x000004B7
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
	ldr r2, _0817FE24 @ =0x0000046E
	adds r7, r5, r2
	b _0817FEAA
	.align 2, 0
_0817FE18: .4byte 0x000004F9
_0817FE1C: .4byte 0x0000025D
_0817FE20: .4byte 0x000004B7
_0817FE24: .4byte 0x0000046E
_0817FE28:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0817FE98 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817FE9C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817FE62
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817FE62
	cmp r4, #1
	bne _0817FE54
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817FEAE
_0817FE54:
	cmp r4, #0
	bne _0817FE62
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817FEAE
_0817FE62:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817FE74
	movs r3, #6
_0817FE74:
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
	beq _0817FEA0
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0817FEA8
	.align 2, 0
_0817FE98: .4byte 0x000004B7
_0817FE9C: .4byte 0x0000046E
_0817FEA0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817FEA8:
	str r0, [r6, #8]
_0817FEAA:
	movs r0, #0
	strb r0, [r7]
_0817FEAE:
	ldr r4, _0817FED8 @ =0x000008B7
	add r4, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _0817FEC2
	ldr r0, _0817FEDC @ =0x000003CE
	bl PlaySound_082406e0
	movs r0, #0xa
	strb r0, [r4]
_0817FEC2:
	ldr r1, _0817FEE0 @ =0x000008B6
	add r1, sb
	movs r0, #0x1e
	strb r0, [r1]
_0817FECA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817FED8: .4byte 0x000008B7
_0817FEDC: .4byte 0x000003CE
_0817FEE0: .4byte 0x000008B6
