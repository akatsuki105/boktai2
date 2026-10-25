	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	mov r1, sl
	adds r0, r1, #0
	str r0, [sp, #0x18]
	ldr r1, _080282E4 @ =0x00000898
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08028304
	ldr r1, _080282E8 @ =0x00000896
	add r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _080282FE
	mov r6, sp
	mov r0, sl
	mov r1, sp
	bl FUN_08028138
	add r7, sp, #8
	movs r1, #0x92
	lsls r1, r1, #2
	add r1, sl
	mov r0, sp
	ldrh r3, [r1]
	ldrh r0, [r0]
	adds r2, r3, r0
	strh r2, [r7]
	ldrh r0, [r6, #2]
	ldrh r4, [r1, #2]
	mov sb, r4
	add r0, sb
	strh r0, [r7, #2]
	ldrh r5, [r1, #4]
	ldrh r1, [r6, #4]
	adds r1, r1, r5
	mov ip, r1
	movs r1, #0x94
	lsls r1, r1, #2
	add r1, sl
	ldrh r4, [r1]
	mov r8, r4
	mov r4, r8
	subs r2, r2, r4
	strh r2, [r7]
	ldrh r2, [r1, #2]
	subs r0, r0, r2
	strh r0, [r7, #2]
	ldrh r1, [r1, #4]
	mov r0, ip
	subs r4, r0, r1
	strh r4, [r7, #4]
	add r4, sp, #0x10
	mov r0, sp
	ldrh r0, [r0]
	adds r3, r3, r0
	strh r3, [r4]
	ldrh r0, [r6, #2]
	add r0, sb
	strh r0, [r4, #2]
	ldrh r6, [r6, #4]
	adds r5, r5, r6
	add r3, r8
	strh r3, [r4]
	adds r0, r0, r2
	strh r0, [r4, #2]
	adds r5, r5, r1
	strh r5, [r4, #4]
	movs r3, #0
	ldr r0, _080282EC @ =0x0000016B
	add r0, sl
	ldrb r0, [r0]
	cmp r3, r0
	bge _08028344
	adds r5, r7, #0
	movs r2, #0
	ldrsh r1, [r5, r2]
	mov r8, r1
	adds r6, r0, #0
_08028296:
	lsls r1, r3, #2
	ldr r7, [sp, #0x18]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	cmp r1, r8
	blt _080282F0
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bgt _080282F0
	ldrh r0, [r5, #2]
	movs r7, #2
	ldrsh r1, [r2, r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _080282F0
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _080282F0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _080282F0
	movs r7, #4
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bgt _080282F0
	movs r0, #1
	b _080282F2
	.align 2, 0
_080282E4: .4byte 0x00000898
_080282E8: .4byte 0x00000896
_080282EC: .4byte 0x0000016B
_080282F0:
	movs r0, #0
_080282F2:
	cmp r0, #0
	bne _0802833C
	adds r3, #1
	cmp r3, r6
	blt _08028296
	b _08028344
_080282FE:
	subs r0, #1
	strh r0, [r1]
	b _08028344
_08028304:
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08028344
	movs r0, #4
	mov r1, sl
	adds r1, #0xa6
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08028334 @ =0x000008D4
	add r0, sl
	ldrh r1, [r0]
	ldr r0, _08028338 @ =0x00000896
	add r0, sl
	strh r1, [r0]
	movs r0, #1
	b _08028346
	.align 2, 0
_08028334: .4byte 0x000008D4
_08028338: .4byte 0x00000896
_0802833C:
	ldr r1, _08028358 @ =0x00000898
	add r1, sl
	movs r0, #0x1e
	strb r0, [r1]
_08028344:
	movs r0, #0
_08028346:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08028358: .4byte 0x00000898
