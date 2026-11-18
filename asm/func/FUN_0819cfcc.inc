	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0819D028 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CFE8
	movs r0, #0
	strb r0, [r1]
_0819CFE8:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Ax_GetAnimVariant
	ldr r1, _0819D02C @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0819D030 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819D03C
	ldr r1, _0819D034 @ =0x000004B7
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
	ldr r0, _0819D038 @ =0x0000046E
	adds r7, r5, r0
	b _0819D0BE
	.align 2, 0
_0819D028: .4byte 0x0000046D
_0819D02C: .4byte 0x000004EC
_0819D030: .4byte 0x0000025D
_0819D034: .4byte 0x000004B7
_0819D038: .4byte 0x0000046E
_0819D03C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0819D0AC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0819D0B0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0819D076
	ldrb r0, [r7]
	cmp r0, #0
	bne _0819D076
	cmp r4, #1
	bne _0819D068
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0819D0C2
_0819D068:
	cmp r4, #0
	bne _0819D076
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0819D0C2
_0819D076:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0819D088
	movs r3, #6
_0819D088:
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
	beq _0819D0B4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0819D0BC
	.align 2, 0
_0819D0AC: .4byte 0x000004B7
_0819D0B0: .4byte 0x0000046E
_0819D0B4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819D0BC:
	str r0, [r6, #8]
_0819D0BE:
	movs r0, #0
	strb r0, [r7]
_0819D0C2:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0819D0D6
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0819D0D6:
	mov r0, sb
	cmp r0, #0x3b
	ble _0819D0E4
	ldr r0, _0819D0F4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0819D0E4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D0F4: .4byte 0x0000046B
