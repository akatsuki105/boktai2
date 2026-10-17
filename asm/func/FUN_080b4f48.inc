	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl MainSprite_AdvanceAnim
	ldr r0, _080B4F7C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B4F84
	ldr r1, _080B4F80 @ =0x00000842
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B4F90
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4c5c
	b _080B4FF4
	.align 2, 0
_080B4F7C: .4byte 0x030044E0
_080B4F80: .4byte 0x00000842
_080B4F84:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080B4F9E
_080B4F90:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4d98
	b _080B4FF4
_080B4F9E:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080B4FE8
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B4FD0 @ =0x00000842
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080B4FD4
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r5, [sp]
	movs r2, #4
	b _080B4FE0
	.align 2, 0
_080B4FD0: .4byte 0x00000842
_080B4FD4:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r3, [sp]
	movs r2, #5
_080B4FE0:
	movs r3, #1
	bl MainSprite_SetAnim
	b _080B4FF4
_080B4FE8:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	bl MainSprite_AdvanceAnim
_080B4FF4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
