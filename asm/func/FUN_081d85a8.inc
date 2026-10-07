	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D8640 @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	bne _081D85B8
	b _081D8706
_081D85B8:
	adds r1, r5, #0
	adds r1, #0xd4
	ldrb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	beq _081D85E6
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r2, #0x34]
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #1
	bl AuxAnim_SetAnim
	adds r0, r6, #0
	movs r1, #0x20
	bl AuxAnim_SetAnimSpeed
_081D85E6:
	adds r4, r5, #0
	adds r4, #0xd6
	ldrh r0, [r4]
	lsls r0, r0, #3
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	subs r4, #0x9a
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _081D8644
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D864C
	.align 2, 0
_081D8640: .4byte 0x030001A0
_081D8644:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D864C:
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
	beq _081D8670
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D8678
_081D8670:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8678:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D86B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D86E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D86B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D86A8
	ldrb r0, [r4, #5]
_081D86A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D86C4
	.align 2, 0
_081D86B0: .4byte 0x0000FFFF
_081D86B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D86C4
	strh r1, [r4, #8]
_081D86C4:
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
	bne _081D86E8
	movs r0, #1
	strb r0, [r4, #7]
_081D86E8:
	ldrh r0, [r5, #0x34]
	cmp r0, #3
	bne _081D8706
	adds r0, r5, #0
	bl FUN_081d8298
	adds r0, r5, #0
	bl FUN_081d8560
	adds r0, r5, #0
	bl FUN_081d822c
	ldr r0, _081D8710 @ =0x000001E1
	bl PlaySound_082406e0
_081D8706:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D8710: .4byte 0x000001E1
