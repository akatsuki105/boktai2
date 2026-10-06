	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	adds r5, r1, #0
	str r2, [sp, #0xc]
	adds r7, r5, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x68
	adds r1, r1, r5
	mov r8, r1
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _08046A60
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080469E0 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080469E4 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080469E8
	adds r0, r5, #0
	adds r0, #0x2c
	movs r4, #1
	b _080469EC
	.align 2, 0
_080469E0: .4byte 0x085AB414
_080469E4: .4byte 0x0000192C
_080469E8:
	adds r0, r5, #0
	adds r0, #0x2c
_080469EC:
	strb r4, [r0]
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _080469FE
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046A04
_080469FE:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046A04:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046A2C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046A34
_08046A2C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046A34:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, sl
	adds r1, r4, #0
	bl Map_InitNavAgent
	adds r0, r5, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08235f40
	movs r0, #1
	strb r0, [r5, #0xa]
_08046A60:
	mov r6, sb
	ldr r0, [r6, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bne _08046A9C
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08046A9C
	mov r0, sb
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08046A9C
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046C88
_08046A9C:
	mov r3, sb
	ldr r2, [r3, #0x18]
	ldr r3, [r5, #0x3c]
	movs r4, #0
	ldrsh r1, [r2, r4]
	mov r6, r8
	movs r4, #0
	ldrsh r0, [r6, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AB4
	rsbs r1, r1, #0
_08046AB4:
	cmp r1, r3
	bge _08046AE6
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046ACA
	rsbs r1, r1, #0
_08046ACA:
	cmp r1, #0xff
	bgt _08046AE6
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, r8
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AE0
	rsbs r1, r1, #0
_08046AE0:
	movs r6, #1
	cmp r1, r3
	blt _08046AE8
_08046AE6:
	movs r6, #0
_08046AE8:
	cmp r6, #0
	beq _08046B00
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046C88
_08046B00:
	adds r2, r7, #0
	adds r2, #8
	mov r0, sl
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r4, r1, r0
	mov r0, sl
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
	ldr r0, _08046B50 @ =0x000003FF
	str r2, [sp, #0x10]
	cmp r1, r0
	bgt _08046B54
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r7, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r6, [r5, #0x10]
	movs r0, #0
	b _08046C88
	.align 2, 0
_08046B50: .4byte 0x000003FF
_08046B54:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _08046BE0
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046B72
	movs r6, #0x10
_08046B72:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _08046B9C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BA0
	asrs r1, r0, #0xc
	b _08046BA6
	.align 2, 0
_08046B9C: .4byte 0x085B0A08
_08046BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08046BA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046BC0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BC4
	asrs r0, r0, #0xc
	b _08046BCA
	.align 2, 0
_08046BC0: .4byte 0x085B0A08
_08046BC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08046BCA:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r6, [r7, #8]
	adds r0, r0, r6
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
_08046BE0:
	mov r0, sl
	ldr r1, [sp, #0x10]
	bl Map_StepNavPath
	ldrb r0, [r5, #7]
	ldr r2, _08046C30 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, r8
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _08046C34 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r4, #1
	mov r8, r4
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046C38
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _08046C42
	.align 2, 0
_08046C30: .4byte 0x085AB414
_08046C34: .4byte 0x0000192C
_08046C38:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08046C42:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046C50
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046C56
_08046C50:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046C56:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046C7E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08046C86
_08046C7E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046C86:
	str r1, [r6, #8]
_08046C88:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
