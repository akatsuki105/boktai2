	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _080F1ABC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F19E0
	movs r0, #0
	strb r0, [r1]
_080F19E0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F19F6
	b _080F1C38
_080F19F6:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _080F1A06
	b _080F1C38
_080F1A06:
	ldr r2, _080F1AC0 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x3c
	bgt _080F1A12
	b _080F1C2E
_080F1A12:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r4, r5, r3
	ldr r1, _080F1AC4 @ =0xFFFFFEFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r7, _080F1AC8 @ =0x000001DF
	adds r0, r5, r7
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _080F1ACC @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _080F1AD0 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _080F1AD4 @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _080F1AD8 @ =0x0000046B
	adds r0, r5, r2
	strb r6, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r4, #0
	cmp r2, #0
	blt _080F1AB8
	cmp r1, #0
	blt _080F1AB8
	ldr r0, _080F1ADC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F1AB8
	ldr r0, _080F1AE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F1AE4
_080F1AB8:
	movs r4, #0
	b _080F1AF2
	.align 2, 0
_080F1ABC: .4byte 0x0000046C
_080F1AC0: .4byte 0x00000484
_080F1AC4: .4byte 0xFFFFFEFF
_080F1AC8: .4byte 0x000001DF
_080F1ACC: .4byte 0x00000469
_080F1AD0: .4byte 0x0000046A
_080F1AD4: .4byte FUN_080e6794
_080F1AD8: .4byte 0x0000046B
_080F1ADC: .4byte 0x030046A8
_080F1AE0: .4byte 0x030046AC
_080F1AE4:
	ldr r0, _080F1B04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F1AF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F1B08
	adds r0, #4
	b _080F1B14
	.align 2, 0
_080F1B04: .4byte 0x030046A4
_080F1B08:
	ldr r0, _080F1B28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F1B14:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F1B2C
	cmp r2, #2
	beq _080F1B30
	b _080F1B34
	.align 2, 0
_080F1B28: .4byte 0x030046A4
_080F1B2C:
	ldrb r0, [r6, #4]
	b _080F1B32
_080F1B30:
	ldrb r0, [r6]
_080F1B32:
	subs r1, r1, r0
_080F1B34:
	strh r1, [r6, #2]
	ldrh r1, [r5, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r3, _080F1B5C @ =0x000004A4
	adds r0, r5, r3
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080F1B60
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	b _080F1B84
	.align 2, 0
_080F1B5C: .4byte 0x000004A4
_080F1B60:
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080F1B7E
	cmp r0, #2
	beq _080F1B8C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080F1B8C
_080F1B7E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_080F1B84:
	ldr r1, _080F1BE8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080F1B8C:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r6, #0
	movs r0, #1
	strh r0, [r1, #6]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0x20
	movs r3, #0x20
	bl 0x080e5e94 @ TODO: FUN_080e5e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F1BF4
	movs r1, #0xc1
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r7, #0xab
	lsls r7, r7, #3
	adds r2, r5, r7
	subs r7, #4
	adds r0, r5, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080F1BEC @ =0x00000551
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _080F1BF0 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
	b _080F1C26
	.align 2, 0
_080F1BE8: .4byte 0xFFFFFDFF
_080F1BEC: .4byte 0x00000551
_080F1BF0: .4byte 0x00000552
_080F1BF4:
	movs r1, #0xd1
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r4, _080F1C40 @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #0x1e
	movs r7, #0xab
	lsls r7, r7, #3
	adds r2, r5, r7
	subs r4, #0x50
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	subs r7, #8
	adds r0, r5, r7
	strb r6, [r0]
	ldr r1, _080F1C44 @ =0x00000551
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080F1C48 @ =0x00000552
	adds r0, r5, r2
	strb r6, [r0]
_080F1C26:
	ldr r3, _080F1C4C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
_080F1C2E:
	ldr r4, _080F1C50 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F1C38:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F1C40: .4byte 0x000005A4
_080F1C44: .4byte 0x00000551
_080F1C48: .4byte 0x00000552
_080F1C4C: .4byte 0x00000482
_080F1C50: .4byte 0x00000484
