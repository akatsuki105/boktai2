	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	bne _0801339C
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	bne _0801330C
	b _0801340C
_0801330C:
	adds r6, r7, #0
	adds r6, #0xc8
	ldr r0, [r7, #0x28]
	ldr r1, [r7, #0x2c]
	str r0, [r6]
	str r1, [r6, #4]
	ldrb r0, [r7, #0x1e]
	subs r0, #1
	strb r0, [r7, #0x1e]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08013346
	ldrb r0, [r7, #0x1a]
	cmp r0, #1
	bne _08013336
	adds r0, r7, #0
	adds r0, #0x90
	movs r1, #0xa2
	lsls r1, r1, #2
	bl Video_SetAuxSpritePltt
_08013336:
	adds r0, r7, #0
	adds r0, #0x30
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	b _0801340C
_08013346:
	ldr r0, _08013390 @ =0x0203B400
	mov sb, r0
	ldr r0, _08013394 @ =0x030046B8
	mov r8, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r3, _08013398 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r6]
	subs r0, #8
	movs r4, #0xf
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r6]
	adds r1, #1
	ands r1, r3
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0xcc
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r2]
	subs r2, #0x9c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _0801340C
	.align 2, 0
_08013390: .4byte 0x0203B400
_08013394: .4byte 0x030046B8
_08013398: .4byte 0x000003FF
_0801339C:
	adds r5, r7, #0
	adds r5, #0x28
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sb, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov sl, r0
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #3
	movs r1, #4
	adds r2, r5, #0
	movs r3, #0x3c
	bl FUN_08014da0
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	mov r0, sl
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #8
	movs r1, #8
	adds r2, r5, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r0, [r7, #0x24]
	cmp r0, #0
	beq _08013406
	movs r1, #0
	bl Script_ExecById
_08013406:
	adds r0, r7, #0
	bl KillEntity
_0801340C:
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
