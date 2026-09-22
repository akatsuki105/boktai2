	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r3, _08017C8C @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _08017C90 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r7, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	mov r8, r1
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	bne _08017CA0
	ldr r5, _08017C94 @ =0x0203B400
	ldr r4, _08017C98 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08017C9C @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r2, #0x7f
	ands r1, r2
	adds r1, #0x80
	str r1, [r6, #0x4c]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	subs r0, #1
	str r0, [r6, #0x48]
	b _08017CA4
	.align 2, 0
_08017C8C: .4byte 0x030047C8
_08017C90: .4byte 0x03003540
_08017C94: .4byte 0x0203B400
_08017C98: .4byte 0x030046B8
_08017C9C: .4byte 0x000003FF
_08017CA0:
	subs r0, #1
	str r0, [r6, #0x4c]
_08017CA4:
	ldr r1, [r6, #0x5c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08017CC2
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x48]
	cmp r0, r2
	bge _08017CBA
	adds r0, #1
	b _08017CC0
_08017CBA:
	cmp r0, r2
	ble _08017CC2
	subs r0, #1
_08017CC0:
	str r0, [r6, #0x44]
_08017CC2:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08017CDE
	ldr r0, [r6, #0x34]
	adds r0, #3
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x34]
	ldr r0, [r6, #0x3c]
	subs r0, #8
	subs r0, r0, r1
	str r0, [r6, #0x3c]
	b _08017CF0
_08017CDE:
	ldr r0, [r6, #0x38]
	adds r0, #6
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x40]
	subs r0, #0x10
	subs r0, r0, r1
	str r0, [r6, #0x40]
_08017CF0:
	ldr r1, [r6, #0x50]
	lsls r1, r1, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r5, [r0]
	adds r5, r7, r5
	movs r2, #0xff
	ands r5, r2
	adds r0, r6, #0
	adds r0, #0x3c
	adds r0, r0, r1
	ldr r4, [r0]
	add r4, r8
	ands r4, r2
	adds r0, r7, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	adds r6, r0, #0
	mov r0, r8
	subs r0, #0x80
	movs r1, #8
	bl Div
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r0
	str r4, [sp]
	movs r0, #1
	adds r1, r6, #0
	adds r3, r5, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
