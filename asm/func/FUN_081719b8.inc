	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r3, [r0]
	ldr r1, _08171A20 @ =0x0000046D
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081719DC
	movs r0, #0
	strb r0, [r1]
_081719DC:
	movs r6, #0
	ldr r1, _08171A24 @ =0x00001012
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r4, sp, #8
	mov sl, r4
	ldr r1, _08171A28 @ =0x0000025D
	add r1, r8
	str r1, [sp, #0x10]
	ldr r2, _08171A2C @ =0x000004B7
	add r2, r8
	mov sb, r2
	ldr r4, _08171A30 @ =0x0000046E
	add r4, r8
	str r4, [sp, #0xc]
	cmp r6, r0
	bge _08171AB6
_08171A00:
	lsls r2, r6, #3
	adds r0, r2, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #2
	ldr r4, _08171A34 @ =0x00000755
	adds r0, r0, r4
	ldrb r0, [r0]
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _08171A38
	movs r0, #1
	b _08171A3A
	.align 2, 0
_08171A20: .4byte 0x0000046D
_08171A24: .4byte 0x00001012
_08171A28: .4byte 0x0000025D
_08171A2C: .4byte 0x000004B7
_08171A30: .4byte 0x0000046E
_08171A34: .4byte 0x00000755
_08171A38:
	movs r0, #0
_08171A3A:
	adds r5, r6, #1
	cmp r0, #0
	beq _08171AA8
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #5
	ldr r2, _08171A5C @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08171A60
	movs r0, #1
	b _08171A62
	.align 2, 0
_08171A5C: .4byte 0x00000755
_08171A60:
	movs r0, #0
_08171A62:
	adds r7, r0, #0
	adds r5, r6, #1
	cmp r7, #0
	bne _08171AA8
	mov r1, r8
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	adds r4, r4, r6
	lsls r4, r4, #3
	adds r4, r4, r6
	lsls r4, r4, #2
	ldr r3, [sp, #0x14]
	adds r4, r3, r4
	ldr r2, _08171B04 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _08171B08 @ =0x0000076E
	adds r0, r4, r1
	strh r7, [r0]
	mov r2, r8
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r4, r4, r2
	strh r0, [r4]
	ldr r3, [sp, #0x14]
_08171AA8:
	adds r6, r5, #0
	ldr r4, _08171B0C @ =0x00001012
	adds r0, r3, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _08171A00
_08171AB6:
	movs r3, #0x80
	lsls r3, r3, #0xb
	mov r0, r8
	movs r1, #0x18
	movs r2, #0xc
	bl FUN_08177d34
	mov r2, r8
	ldrb r0, [r2, #5]
	add r1, sp, #4
	mov r2, sl
	bl Sandworm_GetAnimVariant
	movs r0, #0x9f
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08171B10
	mov r0, sb
	strb r2, [r0]
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	b _08171B84
	.align 2, 0
_08171B04: .4byte 0x0000076C
_08171B08: .4byte 0x0000076E
_08171B0C: .4byte 0x00001012
_08171B10:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, r2
	bne _08171B46
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08171B46
	cmp r4, #1
	bne _08171B38
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08171B8A
_08171B38:
	cmp r4, #0
	bne _08171B46
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08171B8A
_08171B46:
	mov r0, sb
	strb r2, [r0]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _08171B58
	movs r3, #6
_08171B58:
	mov r0, r8
	ldr r1, [r0, #0x44]
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
	beq _08171B7A
	ldr r0, [r5, #8]
	orrs r0, r6
	b _08171B82
_08171B7A:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171B82:
	str r0, [r5, #8]
_08171B84:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
_08171B8A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
