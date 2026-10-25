	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r7, r2, #0
	adds r5, r3, #0
	cmp r7, #0xc
	ble _0802A022
	b _0802A1F8
_0802A022:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0802A02A
	adds r7, #0x10
_0802A02A:
	movs r1, #0
	str r1, [sp, #8]
	ldr r4, _0802A0A0 @ =0x030046B8
	ldr r2, _0802A0A4 @ =0x000003FF
	mov ip, r2
	movs r0, #7
	mov sl, r0
	movs r1, #0xe5
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	ldr r1, _0802A0A8 @ =0x085AABD8
_0802A042:
	movs r2, #0xb8
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r2, [sp, #8]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A054
	b _0802A1E8
_0802A054:
	movs r0, #0x2c
	muls r0, r2, r0
	movs r2, #0xb9
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r6
	mov sb, r0
	ldr r2, [sp, #8]
	lsls r0, r2, #3
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r3, r6, r0
	subs r0, r5, #2
	cmp r0, #1
	bhi _0802A0B0
	ldr r0, [r4]
	adds r0, #1
	mov r2, ip
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A0AC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r2, r7, #1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	ldr r1, [sp, #0xc]
	subs r0, r0, r1
	subs r0, #0xe
	b _0802A0D8
	.align 2, 0
_0802A0A0: .4byte 0x030046B8
_0802A0A4: .4byte 0x000003FF
_0802A0A8: .4byte 0x085AABD8
_0802A0AC: .4byte 0x0203B400
_0802A0B0:
	ldr r0, [r4]
	adds r0, #1
	mov r2, ip
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A100 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r2, r7, #1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	adds r0, #6
_0802A0D8:
	strh r0, [r3]
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0802A104
	cmp r5, #0
	beq _0802A0E8
	cmp r5, #3
	bne _0802A144
_0802A0E8:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A100 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	subs r0, #0x10
	b _0802A122
	.align 2, 0
_0802A100: .4byte 0x0203B400
_0802A104:
	cmp r5, #0
	beq _0802A10C
	cmp r5, #3
	bne _0802A144
_0802A10C:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A13C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x10
_0802A122:
	lsls r0, r0, #1
	ldr r4, _0802A140 @ =0x085AABD9
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r2, sl
	ands r1, r2
	adds r1, r1, r0
	subs r1, #0x28
	strh r1, [r3, #2]
	b _0802A16A
	.align 2, 0
_0802A13C: .4byte 0x0203B400
_0802A140: .4byte 0x085AABD9
_0802A144:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r4, _0802A194 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r4, _0802A198 @ =0x085AABD9
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r2, sl
	ands r0, r2
	adds r0, r0, r1
	subs r0, #0x28
	strh r0, [r3, #2]
_0802A16A:
	movs r4, #0
	strh r4, [r3, #4]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0802A1A0
	mov r0, sb
	ldr r2, _0802A19C @ =0x00000B48
	adds r1, r6, r2
	bl AuxSprite_SetGfx
	movs r1, #0xfd
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	str r4, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0802A1BE
	.align 2, 0
_0802A194: .4byte 0x0203B400
_0802A198: .4byte 0x085AABD9
_0802A19C: .4byte 0x00000B48
_0802A1A0:
	mov r0, sb
	ldr r2, _0802A1E4 @ =0x00000B64
	adds r1, r6, r2
	bl AuxSprite_SetGfx
	movs r1, #0xfd
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	str r4, [sp]
	mov r0, r8
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
_0802A1BE:
	mov r0, r8
	movs r1, #0x20
	bl AuxAnim_SetAnimSpeed
	mov r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xb8
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r1, [sp, #8]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	b _0802A1F8
	.align 2, 0
_0802A1E4: .4byte 0x00000B64
_0802A1E8:
	movs r2, #0x10
	add r8, r2
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	cmp r0, #0xf
	bgt _0802A1F8
	b _0802A042
_0802A1F8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
