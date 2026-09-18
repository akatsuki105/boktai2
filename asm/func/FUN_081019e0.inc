	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08101A06
	b _08101B9C
_08101A06:
	movs r2, #1
	ldr r1, _08101A1C @ =0x0000065C
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08101A20
	movs r0, #1
	b _08101A22
	.align 2, 0
_08101A1C: .4byte 0x0000065C
_08101A20:
	movs r0, #0
_08101A22:
	cmp r0, #0
	bne _08101A28
	b _08101B9C
_08101A28:
	ldr r1, _08101A50 @ =0x0000A107
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r2, r6
	mov r8, r2
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08101A3C
	b _08101B9C
_08101A3C:
	ldr r1, _08101A54 @ =0x0000067C
	add r1, sb
	ldrh r0, [r1]
	adds r7, r0, #0
	cmp r7, #0
	beq _08101A58
	subs r0, #1
	strh r0, [r1]
	b _08101B9C
	.align 2, 0
_08101A50: .4byte 0x0000A107
_08101A54: .4byte 0x0000067C
_08101A58:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r4, _08101B44 @ =0x000004A4
	adds r5, r6, r4
	ldr r0, [r5]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r6, #0
	bl FUN_080e6304
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r0, #0xc
	mov ip, r0
	movs r1, #0x1e
	subs r4, #0x60
	adds r2, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _08101B48 @ =0x00000551
	adds r0, r6, r2
	strb r7, [r0]
	ldr r3, _08101B4C @ =0x00000552
	adds r0, r6, r3
	mov r4, ip
	strb r4, [r0]
	ldr r3, _08101B50 @ =FUN_080e6794
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _08101B54 @ =0x0000046B
	adds r0, r6, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	strh r7, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08101B58 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r7, [r0]
	ldr r3, _08101B5C @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x9c
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r2, [r0]
	ldr r3, _08101B60 @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_0823b490
	ldr r5, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r7, #0xcc
	lsls r7, r7, #3
	add r7, sb
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08101B68
	ldr r0, _08101B64 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08101B90
	.align 2, 0
_08101B44: .4byte 0x000004A4
_08101B48: .4byte 0x00000551
_08101B4C: .4byte 0x00000552
_08101B50: .4byte FUN_080e6794
_08101B54: .4byte 0x0000046B
_08101B58: .4byte 0x00000469
_08101B5C: .4byte 0x0000046C
_08101B60: .4byte 0x00000251
_08101B64: .4byte 0xFFFFFDFF
_08101B68:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08101B86
	cmp r0, #2
	beq _08101B90
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08101B90
_08101B86:
	ldr r0, _08101BB0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08101B90:
	movs r0, #2
	rsbs r0, r0, #0
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08101B9C:
	movs r0, #1
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08101BB0: .4byte 0xFFFFFDFF
