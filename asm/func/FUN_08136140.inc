	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0813621C @ =0x00000B3A
	adds r4, r5, r2
	movs r0, #4
	strh r0, [r4]
	movs r1, #4
	adds r2, #0x10
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _08136220 @ =0x00000B4C
	adds r1, r5, r0
	ldr r0, _08136224 @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _08136228 @ =0x00000B4B
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r7, #0
	movs r1, #0
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp sb, r0
	bge _0813629A
	mov sl, r1
	movs r0, #0xe8
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r1, _0813622C @ =0x00000684
	adds r6, r5, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r5
	mov r8, r2
_081361B4:
	adds r0, r6, #0
	ldr r1, [sp, #0xc]
	bl Video_GetAuxSprite
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _08136230 @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r4, #0x10]
	ldr r1, _0813621C @ =0x00000B3A
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _08136234
	ldrb r0, [r4, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	movs r0, #4
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _08136260
	.align 2, 0
_0813621C: .4byte 0x00000B3A
_08136220: .4byte 0x00000B4C
_08136224: .4byte 0x7FFFFFFF
_08136228: .4byte 0x00000B4B
_0813622C: .4byte 0x00000684
_08136230: .4byte 0x0000922E
_08136234:
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	strh r7, [r4, #8]
	adds r7, #1
	cmp r7, #3
	ble _08136260
	movs r7, #0
_08136260:
	str r5, [r4, #0x34]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _08136276
	mov r1, sl
	strb r1, [r4, #0x1a]
	movs r0, #2
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _0813627C
_08136276:
	ldr r2, [sp, #0x18]
	adds r2, #1
	str r2, [sp, #0x18]
_0813627C:
	movs r0, #0x18
	add sl, r0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r6, r6, r1
	add r8, r1
	movs r2, #1
	add sb, r2
	ldr r1, _081362AC @ =0x00000B3A
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _081361B4
_0813629A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081362AC: .4byte 0x00000B3A
