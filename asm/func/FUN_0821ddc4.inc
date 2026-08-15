	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r5
	movs r4, #0
	ldr r7, _0821DE30 @ =0x03003584
	movs r0, #0
	mov sb, r0
_0821DDDA:
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _0821DE34 @ =0x00000814
	adds r0, r0, r1
	adds r1, r5, r0
	adds r3, r1, #0
	adds r3, #0x60
	ldrb r0, [r3]
	cmp r0, #1
	beq _0821DE90
	movs r0, #1
	strb r0, [r3]
	adds r0, r1, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r4, r1, #0
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r2, [r0]
	adds r0, r4, #0
	subs r3, #0x40
	adds r1, r5, r3
	movs r3, #1
	bl Sprite_SetSprite
	mov r0, r8
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #1
	bne _0821DE38
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _0821DE40
	.align 2, 0
_0821DE30: .4byte 0x03003584
_0821DE34: .4byte 0x00000814
_0821DE38:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0821DE40:
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	cmp r6, #0
	beq _0821DE56
	cmp r6, #1
	beq _0821DE7C
	b _0821DE96
_0821DE56:
	movs r0, #0x82
	lsls r0, r0, #7
	strh r0, [r4, #0x3a]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DE70
	ldr r0, [r7]
	adds r0, #0xe0
	str r0, [r4, #0x48]
	b _0821DE96
_0821DE70:
	ldr r0, [r7]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r4, #0x48]
	b _0821DE96
_0821DE7C:
	ldr r0, _0821DE8C @ =0x00004110
	strh r0, [r4, #0x3a]
	ldr r0, [r7]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x48]
	b _0821DE96
	.align 2, 0
_0821DE8C: .4byte 0x00004110
_0821DE90:
	adds r4, #1
	cmp r4, #7
	ble _0821DDDA
_0821DE96:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
