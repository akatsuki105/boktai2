	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r3, [r6]
	cmp r3, #0
	bne _08055C14
	movs r0, #1
	rsbs r0, r0, #0
	b _08055D18
_08055C14:
	cmp r3, #1
	bne _08055D08
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq _08055D16
	adds r7, r6, #0
	adds r7, #0x28
	adds r4, r6, #0
	adds r4, #0x54
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x54]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08055C50
	ldr r0, [r6, #0x28]
	movs r1, #4
	orrs r0, r1
	b _08055C58
_08055C50:
	ldr r0, [r6, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055C58:
	str r0, [r6, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08055C7C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08055C84
_08055C7C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08055C84:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08055CBC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08055D02
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08055CC6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08055CC0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08055CDC
	.align 2, 0
_08055CBC: .4byte 0x0000FFFF
_08055CC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08055CDA
_08055CC6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08055CDA
	strh r1, [r4, #8]
	movs r2, #1
	b _08055CDC
_08055CDA:
	movs r2, #0
_08055CDC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08055D04
	movs r0, #1
	strb r0, [r4, #7]
	b _08055D04
_08055D02:
	movs r2, #0
_08055D04:
	strb r2, [r6, #0xa]
	b _08055D16
_08055D08:
	adds r1, r6, #0
	adds r1, #0xc
	adds r0, r6, #0
	adds r0, #0x2c
	bl MainSprite_AdvanceAnim
	strb r0, [r6, #0xa]
_08055D16:
	ldrb r0, [r6, #0xa]
_08055D18:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
