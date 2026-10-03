	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r1, #0xd0
	adds r1, r1, r5
	mov r8, r1
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042F98
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r4, [r0]
	adds r4, r5, #0
	adds r4, #0x64
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_082362fc
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r2, r5, r3
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08235f40
	movs r4, #0x89
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_08042F98:
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
	bne _08042FBA
	b _080430F8
_08042FBA:
	adds r2, r5, #0
	adds r2, #0x64
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0xc
	ldrsh r1, [r7, r4]
	movs r4, #8
	ldrsh r3, [r6, r4]
	mov ip, r3
	subs r1, r1, r3
	movs r4, #4
	ldrsh r3, [r0, r4]
	mov sb, r3
	movs r0, #4
	ldrsh r3, [r2, r0]
	mov r4, sb
	subs r0, r4, r3
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r4, r0
	ldr r0, _0804300C @ =0x000009C3
	mov sb, r2
	cmp r1, r0
	bgt _08043010
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	movs r0, #1
	strb r0, [r5, #7]
	b _080430D8
	.align 2, 0
_0804300C: .4byte 0x000009C3
_08043010:
	mov r4, r8
	ldr r0, [r4]
	cmp r0, #2
	bne _080430D8
	adds r0, r5, #0
	adds r0, #0xfc
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080430D8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x1c
	ldrsh r0, [r7, r2]
	mov r4, ip
	subs r0, r0, r4
	movs r2, #4
	ldrsh r1, [r1, r2]
	subs r1, r1, r3
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
	add r2, sp, #4
	ldrb r4, [r6, #5]
	movs r0, #0x30
	mov ip, r0
	ldr r1, _08043090 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _08043094
	asrs r1, r0, #0xc
	b _0804309A
	.align 2, 0
_08043090: .4byte 0x085B0A08
_08043094:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804309A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _080430B8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080430BC
	asrs r0, r0, #0xc
	b _080430C2
	.align 2, 0
_080430B8: .4byte 0x085B0A08
_080430BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080430C2:
	strh r0, [r2, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r0, r0, r3
	strh r0, [r6, #0xc]
_080430D8:
	adds r0, r7, #0
	mov r1, sb
	bl FUN_08236268
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
_080430F8:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
