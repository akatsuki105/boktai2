	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r0, r2, #0
	movs r3, #0
	adds r4, r0, #0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08003508
	movs r1, #7
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl Video_SetAuxSpritePltt
	b _0800359E
_08003508:
	cmp r2, #1
	bne _08003574
	movs r6, #4
	ldr r0, [r5, #0x38]
	ands r0, r6
	cmp r0, #0
	beq _0800359A
	ldr r0, _08003570 @ =0x00010007
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	bne _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r7, #0xa
	strb r7, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl Video_SetAuxSpritePltt
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800359E
	strb r7, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0xc
	str r1, [sp]
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	b _0800359E
	.align 2, 0
_08003570: .4byte 0x00010007
_08003574:
	cmp r2, #2
	bne _0800359A
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	strb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl Video_SetAuxSpritePltt
	movs r3, #1
_0800359A:
	cmp r3, #0
	beq _080035D6
_0800359E:
	ldrh r0, [r4, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080035B6
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080035C4
	movs r0, #1
	strh r0, [r4, #0x16]
_080035B6:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080035C4
	movs r0, #0
	strh r0, [r4, #0x16]
	b _080035D6
_080035C4:
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _080035D6
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080035D6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
