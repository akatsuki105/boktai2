	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080F2AB4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F2A5A
	movs r0, #0
	strb r0, [r1]
_080F2A5A:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2A70
	b _080F2CF2
_080F2A70:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2A7E
	b _080F2CF2
_080F2A7E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _080F2AB8 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _080F2AC0
	ldr r4, _080F2ABC @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080F2AD0
	.align 2, 0
_080F2AB4: .4byte 0x0000046C
_080F2AB8: .4byte 0x0000A02F
_080F2ABC: .4byte 0x00000482
_080F2AC0:
	ldr r1, _080F2AF4 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080F2AD0
	movs r0, #1
	strh r0, [r2]
_080F2AD0:
	ldr r3, _080F2AF8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F2AFC
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _080F2B14
	.align 2, 0
_080F2AF4: .4byte 0x00000482
_080F2AF8: .4byte 0x0000025D
_080F2AFC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_080F2B14:
	ldr r0, _080F2B8C @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	beq _080F2BA8
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F2B3A
	b _080F2CE8
_080F2B3A:
	movs r2, #6
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080F2B90 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _080F2B94 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _080F2B98 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, _080F2B9C @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	ldr r4, _080F2BA0 @ =0x0000046D
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _080F2BA4 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _080F2CE8
	.align 2, 0
_080F2B8C: .4byte 0x000004A4
_080F2B90: .4byte 0x00000469
_080F2B94: .4byte 0x0000046A
_080F2B98: .4byte 0x00000484
_080F2B9C: .4byte 0x000005A4
_080F2BA0: .4byte 0x0000046D
_080F2BA4: .4byte 0x0000046B
_080F2BA8:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F2BBE
	b _080F2CE8
_080F2BBE:
	ldr r4, _080F2C60 @ =0x00000202
	adds r0, r5, r4
	movs r4, #0
	strh r6, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #6
	ldrsh r2, [r0, r1]
	cmp r2, #0
	beq _080F2C7C
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _080F2C64 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r6, [r0]
	ldr r1, _080F2C68 @ =0x0000046C
	adds r0, r5, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	adds r0, r5, #0
	bl FUN_080e6204
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080F2C42
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _080F2C6C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F2C70 @ =0xFFFFFDFF
	mov r2, sb
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080F2C74 @ =0x0000021E
	adds r0, r5, r2
	strh r6, [r0]
	ldr r4, _080F2C60 @ =0x00000202
	adds r0, r5, r4
	strh r6, [r0]
_080F2C42:
	movs r1, #0x91
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _080F2C78 @ =0x00000482
	adds r0, r5, r1
	mov r2, r8
	strh r2, [r0]
	ldr r0, [r7]
	movs r1, #8
	bl ClearMemory
	b _080F2CA0
	.align 2, 0
_080F2C60: .4byte 0x00000202
_080F2C64: .4byte 0x00000469
_080F2C68: .4byte 0x0000046C
_080F2C6C: .4byte 0xFEFFFFFF
_080F2C70: .4byte 0xFFFFFDFF
_080F2C74: .4byte 0x0000021E
_080F2C78: .4byte 0x00000482
_080F2C7C:
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _080F2CD0 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F2CD4 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _080F2CD8 @ =0x0000046C
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080F2CA0:
	ldr r3, _080F2CDC @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _080F2CE0 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F2CE4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _080F2CF2
	.align 2, 0
_080F2CD0: .4byte 0x0000046A
_080F2CD4: .4byte 0x00000484
_080F2CD8: .4byte 0x0000046C
_080F2CDC: .4byte 0x000005A4
_080F2CE0: .4byte 0x0000046D
_080F2CE4: .4byte 0x0000046B
_080F2CE8:
	ldr r4, _080F2D00 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2CF2:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F2D00: .4byte 0x00000484
