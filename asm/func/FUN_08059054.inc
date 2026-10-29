	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _08059088 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _0805908C
	ldr r0, [sp, #0x48]
	movs r1, #1
	movs r2, #0
	bl Entity08058ffc_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _0805908C
	movs r0, #1
	rsbs r0, r0, #0
	b _080591DA
	.align 2, 0
_08059088: .4byte 0x0300012C
_0805908C:
	movs r1, #0
	str r1, [sp, #0x14]
	mov sl, r1
	adds r2, r5, #0
	adds r2, #0xd4
	str r2, [sp, #0x18]
	adds r3, r5, #0
	adds r3, #0x8c
	str r3, [sp, #0x1c]
	movs r6, #0x7c
	adds r6, r6, r5
	mov r8, r6
	adds r4, r5, #0
	adds r4, #0x5c
	adds r1, r5, #0
	adds r1, #0xa8
	str r1, [sp, #0x20]
	str r4, [sp, #0x24]
_080590B0:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r2, [r5, #0x1c]
	ands r2, r1
	cmp r2, #0
	bne _080591AE
	ldr r7, [sp, #0x20]
	mov r3, sp
	ldrh r3, [r3, #0xc]
	strh r3, [r4]
	mov r6, sp
	ldrh r6, [r6, #0x10]
	strh r6, [r4, #2]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r4, #5]
	movs r3, #8
	strb r3, [r4, #6]
	ldrb r1, [r4, #5]
	movs r0, #8
	strh r2, [r4, #0x22]
	cmp r1, #1
	beq _080590FE
	cmp r1, #1
	bgt _080590EA
	cmp r1, #0
	beq _080590F4
	b _08059116
_080590EA:
	cmp r1, #2
	beq _08059106
	cmp r1, #3
	beq _0805910E
	b _08059116
_080590F4:
	strh r2, [r4, #0x20]
	rsbs r0, r0, #0
	mov r1, r8
	strh r0, [r1, #4]
	b _08059116
_080590FE:
	strh r0, [r4, #0x20]
	mov r3, r8
	strh r2, [r3, #4]
	b _08059116
_08059106:
	strh r2, [r4, #0x20]
	mov r6, r8
	strh r0, [r6, #4]
	b _08059116
_0805910E:
	rsbs r0, r3, #0
	strh r0, [r4, #0x20]
	mov r0, r8
	strh r2, [r0, #4]
_08059116:
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r6, #0
	strb r6, [r4, #9]
	strb r6, [r4, #0xa]
	movs r0, #0xff
	strb r0, [r4, #0xb]
	strb r6, [r4, #0x10]
	movs r3, #1
	mov sb, r3
	movs r1, #1
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805913A
	movs r1, #8
_0805913A:
	strb r1, [r4, #4]
	mov r0, sb
	strb r0, [r4, #8]
	str r6, [r4, #0x14]
	ldr r0, [sp, #0x1c]
	ldr r1, _080591EC @ =0x0000022A
	bl Video_SetAuxSpritePltt
	ldr r1, [r5, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x18]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_080572b8
	ldr r2, _080591F0 @ =0x00000EBC
	adds r1, r5, r2
	ldr r2, [r1]
	movs r6, #0x2c
	ldrsh r3, [r2, r6]
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	subs r3, r3, r1
	movs r1, #0x30
	ldrsh r2, [r2, r1]
	movs r6, #0x20
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	adds r1, r3, #0
	muls r1, r3, r1
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	adds r1, r1, r2
	str r1, [r4, #0x18]
	mov r2, sb
	mov r6, sl
	lsls r2, r6
	ldr r1, [r5, #0x1c]
	orrs r1, r2
	str r1, [r5, #0x1c]
	ldr r1, [r5, #0x28]
	adds r1, #1
	str r1, [r5, #0x28]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #4]
	cmp r1, r2
	bge _080591DA
_080591AE:
	ldr r3, [sp, #0x18]
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r3, r3, r6
	str r3, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r1, r1, r6
	str r1, [sp, #0x1c]
	add r8, r6
	adds r4, r4, r6
	ldr r2, [sp, #0x20]
	adds r2, r2, r6
	str r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	adds r3, r3, r6
	str r3, [sp, #0x24]
	movs r6, #1
	add sl, r6
	mov r1, sl
	cmp r1, #0xb
	bgt _080591DA
	b _080590B0
_080591DA:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080591EC: .4byte 0x0000022A
_080591F0: .4byte 0x00000EBC
