	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #5]
	cmp r0, #0
	beq _0804642C
	movs r4, #0
	strb r4, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _080463AC @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080463B0 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	movs r0, #1
	mov sl, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080463B4
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, sl
	strb r1, [r0]
	b _080463BA
	.align 2, 0
_080463AC: .4byte 0x085AB424
_080463B0: .4byte 0x0000192C
_080463B4:
	adds r0, r6, #0
	adds r0, #0x2c
	strb r4, [r0]
_080463BA:
	adds r2, r0, #0
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _080463CA
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _080463D0
_080463CA:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_080463D0:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _080463F8
	ldr r0, [r5, #8]
	movs r1, #4
	orrs r0, r1
	b _08046400
_080463F8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046400:
	str r0, [r5, #8]
	movs r5, #0
	movs r0, #1
	strb r0, [r6, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, r8
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r6, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08235f40
	strb r5, [r6, #0xa]
_0804642C:
	adds r2, r7, #0
	adds r2, #8
	mov r3, r8
	movs r0, #0x1c
	ldrsh r1, [r3, r0]
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r4, r1, r0
	mov r0, r8
	movs r3, #0x20
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046480 @ =0x000003FF
	adds r5, r2, #0
	cmp r1, r0
	bgt _08046484
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r7, #8]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	str r1, [r6, #0x10]
	movs r0, #0
	b _080465A0
	.align 2, 0
_08046480: .4byte 0x000003FF
_08046484:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _080464B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080464B4
	asrs r1, r0, #0xc
	b _080464BA
	.align 2, 0
_080464B0: .4byte 0x085B0A08
_080464B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080464BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080464D8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _080464DC
	asrs r0, r0, #0xc
	b _080464E2
	.align 2, 0
_080464D8: .4byte 0x085B0A08
_080464DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080464E2:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	mov r0, r8
	adds r1, r5, #0
	bl Map_StepNavPath
	ldrb r0, [r6, #7]
	ldr r2, _08046548 @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _0804654C @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046550
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804655A
	.align 2, 0
_08046548: .4byte 0x085AB424
_0804654C: .4byte 0x0000192C
_08046550:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804655A:
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _08046568
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804656E
_08046568:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_0804656E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046596
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _0804659E
_08046596:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804659E:
	str r1, [r5, #8]
_080465A0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
