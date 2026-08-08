	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _082352EC
	ldrb r0, [r0]
	cmp r0, #0
	bne _082352F6
_082352EC:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _082353F6
_082352F6:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _08235316
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r6, #4]
	b _082353F6
_08235316:
	movs r3, #0
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _08235372
	mov r4, sp
_08235324:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0xc]
	str r3, [sp, #8]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #8]
	cmp r2, r3
	blo _08235368
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_08235368:
	adds r5, #1
	mov r1, r8
	ldrb r1, [r1]
	cmp r5, r1
	blt _08235324
_08235372:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235396
	cmp r1, #0
	blt _08235396
	ldr r0, _0823539C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235396
	ldr r0, _082353A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082353A4
_08235396:
	movs r4, #0
	b _082353B2
	.align 2, 0
_0823539C: .4byte 0x030046A8
_082353A0: .4byte 0x030046AC
_082353A4:
	ldr r0, _082353C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082353B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082353C8
	adds r0, #4
	b _082353D4
	.align 2, 0
_082353C4: .4byte 0x030046A4
_082353C8:
	ldr r0, _082353E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082353D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082353EC
	cmp r2, #2
	beq _082353F0
	b _082353F4
	.align 2, 0
_082353E8: .4byte 0x030046A4
_082353EC:
	ldrb r0, [r6, #4]
	b _082353F2
_082353F0:
	ldrb r0, [r6]
_082353F2:
	subs r1, r1, r0
_082353F4:
	strh r1, [r6, #2]
_082353F6:
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
