	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x20
	str r0, [r6, #0x18]
	adds r7, r6, #0
	adds r7, #0x28
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r2, _0820F508 @ =0x085AF0CE
	mov sl, r2
	movs r3, #0xb4
	adds r3, r3, r6
	mov sb, r3
_0820F4DE:
	mov r4, r8
	cmp r4, #0
	bne _0820F514
	ldr r5, _0820F508 @ =0x085AF0CE
	ldrh r1, [r5]
	ldr r2, _0820F50C @ =0x00000366
	adds r0, r6, r2
	ldrb r2, [r0]
	ldr r3, _0820F510 @ =0x00000367
	adds r0, r6, r3
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	mov r5, r8
	str r5, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	b _0820F56A
	.align 2, 0
_0820F508: .4byte 0x085AF0CE
_0820F50C: .4byte 0x00000366
_0820F510: .4byte 0x00000367
_0820F514:
	mov r1, r8
	cmp r1, #1
	bgt _0820F530
	mov r2, sl
	ldrh r1, [r2]
	movs r3, #1
	str r3, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r4, #5
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r2, #0
	b _0820F548
_0820F530:
	mov r5, r8
	cmp r5, #2
	bgt _0820F550
	mov r0, sl
	ldrh r1, [r0]
	movs r2, #1
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r3, #5
	str r3, [sp, #8]
	adds r0, r7, #0
_0820F548:
	movs r3, #0
	bl FUN_08055b5c
	b _0820F56A
_0820F550:
	mov r4, sl
	ldrh r1, [r4]
	movs r5, #1
	str r5, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08055b5c
_0820F56A:
	adds r0, r7, #0
	bl FUN_08055c04
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r4, [sp, #0xc]
	ldr r5, _0820F5BC @ =0x085AF0C4
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	adds r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, _0820F5C0 @ =0x085AF0C5
	adds r0, r4, r5
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov r5, sb
	ldr r0, [r5]
	add r2, ip
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r4, [r0, #4]
	ldr r0, [r6, #0x18]
	mov r4, sb
	cmp r0, #0
	blt _0820F5C4
	asrs r1, r0, #5
	b _0820F5CA
	.align 2, 0
_0820F5BC: .4byte 0x085AF0C4
_0820F5C0: .4byte 0x085AF0C5
_0820F5C4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F5CA:
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r1, r0
	movs r2, #8
	mov r3, r8
	subs r2, r2, r3
	ldr r3, _0820F5F0 @ =0x085B0A08
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F5F4
	asrs r2, r0, #0xd
	b _0820F5FA
	.align 2, 0
_0820F5F0: .4byte 0x085B0A08
_0820F5F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F5FA:
	ldr r1, [r4]
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	movs r0, #0x94
	add sb, r0
	adds r7, #0x94
	ldr r1, [sp, #0xc]
	adds r1, #2
	str r1, [sp, #0xc]
	movs r2, #2
	add sl, r2
	movs r3, #1
	add r8, r3
	mov r4, r8
	cmp r4, #4
	bgt _0820F61E
	b _0820F4DE
_0820F61E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
