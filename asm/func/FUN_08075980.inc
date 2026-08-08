	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _080759F0 @ =0x0000037E
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807599C
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0807599C:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	ldr r5, _080759F4 @ =0x000002E6
	adds r0, r7, r5
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080759F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08075A00
	.align 2, 0
_080759F0: .4byte 0x0000037E
_080759F4: .4byte 0x000002E6
_080759F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075A00:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075A24
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08075A2C
_08075A24:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075A2C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08075A64 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075A9C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075A68
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075A5C
	ldrb r0, [r4, #5]
_08075A5C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075A78
	.align 2, 0
_08075A64: .4byte 0x0000FFFF
_08075A68:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075A78
	strh r1, [r4, #8]
_08075A78:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08075A9C
	movs r0, #1
	strb r0, [r4, #7]
_08075A9C:
	ldr r5, _08075AD4 @ =0x000004A4
	adds r3, r7, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _08075B24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08075AD8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08075ADC
	asrs r0, r0, #0xc
	b _08075AE2
	.align 2, 0
_08075AD4: .4byte 0x000004A4
_08075AD8: .4byte 0x085B0A08
_08075ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08075AE2:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08075B00 @ =0x000004A4
	adds r0, r7, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08075B04
	asrs r0, r0, #0xc
	b _08075B0A
	.align 2, 0
_08075B00: .4byte 0x000004A4
_08075B04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08075B0A:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
	ldr r0, _08075B20 @ =0x000004A4
	adds r2, r7, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08075B40
	.align 2, 0
_08075B20: .4byte 0x000004A4
_08075B24:
	strh r0, [r3]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08075B48 @ =FUN_08074d90
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080726b4
_08075B40:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075B48: .4byte FUN_08074d90
