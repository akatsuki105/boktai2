	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _08097F24 @ =0x00001E6C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	ldr r3, _08097F28 @ =0x00001CEC
	adds r1, r6, r3
	movs r7, #3
_08097E5A:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r7, #1
	cmp r7, #0
	bge _08097E5A
	movs r7, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08097F16
	movs r2, #2
	rsbs r2, r2, #0
	mov sb, r2
	ldr r3, _08097F2C @ =0x00001E84
	adds r3, r3, r6
	mov sl, r3
_08097E82:
	movs r0, #0x64
	adds r2, r7, #0
	muls r2, r0, r2
	adds r2, r6, r2
	ldr r1, _08097F30 @ =0x00000C08
	adds r0, r2, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, r5, #0
	adds r1, #0x24
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r8, r0
	ldr r3, _08097F34 @ =0x00000F6C
	adds r1, r6, r3
	add r1, r8
	ldr r0, [r1]
	mov r3, sb
	ands r0, r3
	str r0, [r1]
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08097F38 @ =0x00001CE4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r1, _08097F3C @ =0x00000C09
	adds r2, r2, r1
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	movs r1, #1
	bl MainSprite_SetPltt
	ldr r2, _08097F40 @ =0x00000C04
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bne _08097F08
	ldr r0, _08097F24 @ =0x00001E6C
	adds r1, r6, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	mov r3, r8
	adds r0, r6, r3
	ldr r1, _08097F44 @ =0x00000F84
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sl
	str r0, [r2]
	str r1, [r2, #4]
_08097F08:
	adds r7, #1
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r7, r0
	blt _08097E82
_08097F16:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097F24: .4byte 0x00001E6C
_08097F28: .4byte 0x00001CEC
_08097F2C: .4byte 0x00001E84
_08097F30: .4byte 0x00000C08
_08097F34: .4byte 0x00000F6C
_08097F38: .4byte 0x00001CE4
_08097F3C: .4byte 0x00000C09
_08097F40: .4byte 0x00000C04
_08097F44: .4byte 0x00000F84
