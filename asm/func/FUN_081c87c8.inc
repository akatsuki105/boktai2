	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081C87E0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C87E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C87E6
	.align 2, 0
_081C87E0: .4byte 0x0000046D
_081C87E4:
	movs r0, #0
_081C87E6:
	cmp r0, #0
	beq _081C87FA
	adds r0, r5, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
	ldr r0, _081C882C @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081C87FA:
	ldr r1, _081C8830 @ =0x00000482
	adds r3, r5, r1
	ldrh r6, [r3]
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8814
	movs r0, #3
	strh r0, [r3]
_081C8814:
	ldr r1, _081C8834 @ =0x0000A02F
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8838
	ldr r0, _081C8830 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081C8848
	.align 2, 0
_081C882C: .4byte 0x0000046E
_081C8830: .4byte 0x00000482
_081C8834: .4byte 0x0000A02F
_081C8838:
	ldr r1, _081C886C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081C8848
	movs r0, #1
	strh r0, [r2]
_081C8848:
	ldr r1, _081C8870 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8874
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081C888C
	.align 2, 0
_081C886C: .4byte 0x00000482
_081C8870: .4byte 0x0000025D
_081C8874:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081C888C:
	ldr r1, _081C88AC @ =0x00000482
	adds r0, r5, r1
	strh r6, [r0]
	subs r1, #0x14
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C88A4
	ldr r0, _081C88B0 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081C88A4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C88AC: .4byte 0x00000482
_081C88B0: .4byte 0x0000046B
