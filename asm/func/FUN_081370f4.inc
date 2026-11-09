	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #0x1c]
	adds r7, r1, #0
	str r2, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0
	mov sl, r3
	ldr r0, _0813714C @ =0x00000B3A
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp sl, r0
	bge _08137226
	ldr r6, _08137150 @ =0x00000764
	add r6, sb
	movs r0, #0
	str r0, [sp, #0x24]
	ldr r1, _08137154 @ =0x00000755
	add r1, sb
	mov r8, r1
_0813713A:
	movs r1, #2
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08137158
	movs r0, #1
	b _0813715A
	.align 2, 0
_0813714C: .4byte 0x00000B3A
_08137150: .4byte 0x00000764
_08137154: .4byte 0x00000755
_08137158:
	movs r0, #0
_0813715A:
	cmp r0, #0
	beq _08137208
	movs r1, #1
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0813716E
	movs r0, #1
	b _08137170
_0813716E:
	movs r0, #0
_08137170:
	cmp r0, #0
	bne _08137208
	add r5, sp, #4
	ldr r2, [sp, #0x24]
	add r2, sb
	ldr r3, _08137264 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r6]
	ldrh r0, [r2]
	subs r1, r1, r0
	adds r0, r5, #0
	strh r1, [r0]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	adds r0, r5, #0
	movs r4, #0
	ldrsh r2, [r0, r4]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x20]
	cmp r1, r0
	ble _08137208
	cmp r7, #1
	bge _081371C6
	movs r7, #1
_081371C6:
	adds r0, r2, #0
	adds r1, r7, #0
	str r3, [sp, #0x28]
	bl Div
	ldr r4, [sp, #0x24]
	add r4, sb
	ldr r3, [sp, #0x28]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldr r3, _08137268 @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_08137208:
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r6, r3
	ldr r4, [sp, #0x24]
	adds r4, r4, r3
	str r4, [sp, #0x24]
	add r8, r3
	movs r0, #1
	add sl, r0
	ldr r0, _0813726C @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _0813713A
_08137226:
	ldr r0, [sp, #0x1c]
	bl FUN_08136b3c
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0xff
	movs r2, #0
	mov sl, r2
	ldr r0, _0813726C @ =0x00000B3A
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp sl, r0
	blt _0813724C
	b _08137344
_0813724C:
	add r7, sp, #0xc
	ldr r5, _08137264 @ =0x00000674
	add r5, sb
	ldr r6, _08137270 @ =0x00000755
	add r6, sb
_08137256:
	movs r1, #1
	ldrb r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08137274
	movs r0, #1
	b _08137276
	.align 2, 0
_08137264: .4byte 0x00000674
_08137268: .4byte 0x00000676
_0813726C: .4byte 0x00000B3A
_08137270: .4byte 0x00000755
_08137274:
	movs r0, #0
_08137276:
	cmp r0, #0
	bne _0813732C
	movs r1, #2
	ldrb r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08137288
	movs r0, #1
	b _0813728A
_08137288:
	movs r0, #0
_0813728A:
	cmp r0, #0
	beq _08137324
	cmp r3, #0xff
	beq _081372A2
	adds r0, r3, r2
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0xc
	adds r2, r5, #0
	bl FUN_08136f20
	b _08137310
_081372A2:
	add r4, sp, #0x14
	ldrh r0, [r7]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08137320 @ =0x00001A44
	cmp r1, r0
	ble _08137310
	adds r0, r2, #0
	movs r1, #4
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	movs r1, #2
	ldrsh r0, [r4, r1]
	movs r1, #4
	bl Div
	ldrh r1, [r5, #2]
	adds r1, r1, r0
	strh r1, [r5, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #4
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
_08137310:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0xff
	movs r2, #0
	b _0813732C
	.align 2, 0
_08137320: .4byte 0x00001A44
_08137324:
	cmp r3, #0xff
	bne _0813732A
	mov r3, sl
_0813732A:
	adds r2, #1
_0813732C:
	movs r4, #0x90
	lsls r4, r4, #1
	adds r5, r5, r4
	adds r6, r6, r4
	movs r0, #1
	add sl, r0
	ldr r0, _0813735C @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _08137256
_08137344:
	ldr r0, [sp, #0x1c]
	bl FUN_08136a0c
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813735C: .4byte 0x00000B3A
