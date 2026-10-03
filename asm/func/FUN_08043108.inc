	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r7, r5, r1
	movs r2, #0xd0
	adds r2, r2, r5
	mov r8, r2
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080431E0
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x64
	mov r0, sb
	adds r1, r4, #0
	bl Map_InitNavAgent
	ldr r1, _08043254 @ =0x000001EF
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x84
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r7, #0
	bl Map_InitPathWalker
	movs r7, #0xd0
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r1, [r0]
	add r0, sp, #4
	movs r2, #0
	bl Map_ReadPathNodePos
	mov r0, sb
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	mov r1, sb
	movs r3, #0x1c
	ldrsh r0, [r1, r3]
	movs r7, #8
	ldrsh r1, [r6, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r4, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080431E0:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08043202
	b _08043350
_08043202:
	adds r2, r5, #0
	adds r2, #0x64
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r4, sb
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	movs r3, #8
	ldrsh r4, [r6, r3]
	subs r1, r1, r4
	movs r7, #4
	ldrsh r0, [r0, r7]
	movs r7, #4
	ldrsh r3, [r2, r7]
	subs r0, r0, r3
	adds r7, r1, #0
	muls r7, r1, r7
	adds r1, r7, #0
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	ldr r0, _08043258 @ =0x000009C3
	mov sl, r2
	cmp r1, r0
	bgt _0804325C
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	movs r0, #1
	strb r0, [r5, #7]
	b _08043330
	.align 2, 0
_08043254: .4byte 0x000001EF
_08043258: .4byte 0x000009C3
_0804325C:
	mov r7, r8
	ldr r0, [r7]
	cmp r0, #2
	bne _08043330
	movs r0, #0xfc
	adds r0, r0, r5
	mov r8, r0
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08043330
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	mov r7, sb
	movs r2, #0x1c
	ldrsh r0, [r7, r2]
	subs r0, r0, r4
	movs r4, #4
	ldrsh r1, [r1, r4]
	subs r1, r1, r3
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r7, #0xff
	ands r1, r7
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r7
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	mov r0, r8
	ldrh r1, [r0, #0x14]
	movs r0, #1
	ands r0, r1
	movs r1, #0x30
	mov ip, r1
	cmp r0, #0
	beq _080432CA
	movs r2, #0x18
	mov ip, r2
_080432CA:
	add r3, sp, #0xc
	ldrb r4, [r6, #5]
	ldr r0, _080432F0 @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x40
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r7, #0
	ldrsh r1, [r1, r7]
	mov r2, ip
	muls r2, r1, r2
	adds r7, r3, #0
	adds r1, r0, #0
	cmp r2, #0
	blt _080432F4
	asrs r2, r2, #0xc
	b _080432FA
	.align 2, 0
_080432F0: .4byte 0x085B0A08
_080432F4:
	rsbs r0, r2, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080432FA:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08043316
	asrs r0, r0, #0xc
	b _0804331C
_08043316:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0804331C:
	strh r0, [r3, #4]
	ldrh r0, [r7]
	ldrh r3, [r6, #8]
	adds r0, r0, r3
	strh r0, [r6, #8]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r4, [r6, #0xc]
	adds r0, r0, r4
	strh r0, [r6, #0xc]
_08043330:
	mov r0, sb
	mov r1, sl
	bl Map_StepNavPath
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043350:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
