	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _08075B7C @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08075BBA
	ldr r2, _08075B80 @ =0x000002E7
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08075B88
	ldr r3, _08075B84 @ =0x000002E6
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #7
	subs r1, r1, r0
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _08075B9A
	.align 2, 0
_08075B7C: .4byte 0x0000037E
_08075B80: .4byte 0x000002E7
_08075B84: .4byte 0x000002E6
_08075B88:
	ldr r3, _08075BE8 @ =0x000002E6
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, #1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_08075B9A:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08075BEC @ =0x0000037F
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_08075BBA:
	ldr r1, _08075BF0 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r3, #7
	adds r1, r3, #0
	ands r1, r0
	lsrs r0, r0, #2
	subs r0, r3, r0
	cmp r1, r0
	bge _08075C10
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #3
	bls _08075BF4
	ldrb r0, [r2]
	subs r0, r3, r0
	asrs r0, r0, #1
	b _08075C34
	.align 2, 0
_08075BE8: .4byte 0x000002E6
_08075BEC: .4byte 0x0000037F
_08075BF0: .4byte 0x0000037E
_08075BF4:
	lsrs r1, r1, #0x19
	ldr r2, _08075C08 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08075C0C @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
	b _08075C5A
	.align 2, 0
_08075C08: .4byte 0x000002E6
_08075C0C: .4byte 0x000002E7
_08075C10:
	adds r0, r5, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	str r1, [r0]
	str r2, [r0, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08075C4C
	movs r0, #8
	subs r0, r0, r2
_08075C34:
	ldr r2, _08075C44 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _08075C48 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08075C5A
	.align 2, 0
_08075C44: .4byte 0x000002E6
_08075C48: .4byte 0x000002E7
_08075C4C:
	ldr r1, _08075CD0 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08075CD4 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
_08075C5A:
	adds r0, r5, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xd0
	ldr r0, _08075CD8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r5, r3
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _08075CD0 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075CDC
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _08075CE4
	.align 2, 0
_08075CD0: .4byte 0x000002E6
_08075CD4: .4byte 0x000002E7
_08075CD8: .4byte 0x03003584
_08075CDC:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075CE4:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075D08
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08075D10
_08075D08:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075D10:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08075D48 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075D80
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075D4C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075D40
	ldrb r0, [r4, #5]
_08075D40:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075D5C
	.align 2, 0
_08075D48: .4byte 0x0000FFFF
_08075D4C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075D5C
	strh r1, [r4, #8]
_08075D5C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075D80
	movs r0, #1
	strb r0, [r4, #7]
_08075D80:
	ldr r3, _08075DE0 @ =0x0000095E
	adds r1, r5, r3
	ldr r0, _08075DE4 @ =0x0000026D
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08075DE8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08075DA4
	movs r0, #0x20
	strh r0, [r1]
_08075DA4:
	ldr r0, _08075DEC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _08075DD6
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _08075DF0 @ =0x00000381
	adds r0, r5, r2
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	bl FUN_08072620
	ldr r3, _08075DF4 @ =0x000004AF
	adds r0, r5, r3
	strb r4, [r0]
_08075DD6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075DE0: .4byte 0x0000095E
_08075DE4: .4byte 0x0000026D
_08075DE8: .4byte 0x0000FFFF
_08075DEC: .4byte 0x0000037E
_08075DF0: .4byte 0x00000381
_08075DF4: .4byte 0x000004AF
