	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08189120 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189124
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189126
	.align 2, 0
_08189120: .4byte 0x0000046D
_08189124:
	movs r0, #0
_08189126:
	cmp r0, #0
	beq _0818920E
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818916C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189178
	ldr r1, _08189170 @ =0x000004B7
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
	ldr r0, _08189174 @ =0x0000046E
	adds r7, r5, r0
	b _081891FA
	.align 2, 0
_0818916C: .4byte 0x0000025D
_08189170: .4byte 0x000004B7
_08189174: .4byte 0x0000046E
_08189178:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081891E8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081891EC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081891B2
	ldrb r0, [r7]
	cmp r0, #0
	bne _081891B2
	cmp r4, #1
	bne _081891A4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081891FE
_081891A4:
	cmp r4, #0
	bne _081891B2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081891FE
_081891B2:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081891C4
	movs r3, #6
_081891C4:
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
	beq _081891F0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081891F8
	.align 2, 0
_081891E8: .4byte 0x000004B7
_081891EC: .4byte 0x0000046E
_081891F0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081891F8:
	str r0, [r6, #8]
_081891FA:
	movs r0, #0
	strb r0, [r7]
_081891FE:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	b _081892F0
_0818920E:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189250 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818925C
	ldr r1, _08189254 @ =0x000004B7
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
	ldr r0, _08189258 @ =0x0000046E
	adds r7, r5, r0
	b _081892DE
	.align 2, 0
_08189250: .4byte 0x0000025D
_08189254: .4byte 0x000004B7
_08189258: .4byte 0x0000046E
_0818925C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081892CC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081892D0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08189296
	ldrb r0, [r7]
	cmp r0, #0
	bne _08189296
	cmp r4, #1
	bne _08189288
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081892E2
_08189288:
	cmp r4, #0
	bne _08189296
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081892E2
_08189296:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081892A8
	movs r3, #6
_081892A8:
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
	beq _081892D4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081892DC
	.align 2, 0
_081892CC: .4byte 0x000004B7
_081892D0: .4byte 0x0000046E
_081892D4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081892DC:
	str r0, [r6, #8]
_081892DE:
	movs r0, #0
	strb r0, [r7]
_081892E2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
_081892F0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
