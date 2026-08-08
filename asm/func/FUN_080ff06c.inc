	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _080FF090 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FF094
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FF096
	.align 2, 0
_080FF090: .4byte 0x0000046C
_080FF094:
	movs r0, #0
_080FF096:
	cmp r0, #0
	beq _080FF0C4
	ldr r4, _080FF0EC @ =FUN_080fe1bc
	movs r3, #0x23
	ldr r0, _080FF0F0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FF0F4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_080FF0C4:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080FF11C
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF0FC
	ldr r1, _080FF0F8 @ =0x0000065C
	adds r0, r7, r1
	b _080FF10C
	.align 2, 0
_080FF0EC: .4byte FUN_080fe1bc
_080FF0F0: .4byte 0x0000046D
_080FF0F4: .4byte 0x0000046B
_080FF0F8: .4byte 0x0000065C
_080FF0FC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF11C
	ldr r2, _080FF118 @ =0x0000065C
	adds r0, r7, r2
_080FF10C:
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _080FF25E
	.align 2, 0
_080FF118: .4byte 0x0000065C
_080FF11C:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r0, _080FF150 @ =0x00000482
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r1, _080FF154 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FF158
	ldr r3, _080FF150 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080FF168
	.align 2, 0
_080FF150: .4byte 0x00000482
_080FF154: .4byte 0x0000A02F
_080FF158:
	ldr r1, _080FF18C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080FF168
	movs r0, #1
	strh r0, [r2]
_080FF168:
	ldr r3, _080FF190 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FF194
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
	b _080FF1AC
	.align 2, 0
_080FF18C: .4byte 0x00000482
_080FF190: .4byte 0x0000025D
_080FF194:
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
_080FF1AC:
	ldr r0, _080FF204 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _080FF218
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF254
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _080FF208 @ =0x00000469
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080FF20C @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	ldr r0, _080FF210 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	ldr r1, _080FF214 @ =0x0000065C
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080FF25E
	.align 2, 0
_080FF204: .4byte 0x000004A4
_080FF208: .4byte 0x00000469
_080FF20C: .4byte 0x0000046A
_080FF210: .4byte 0x0000046C
_080FF214: .4byte 0x0000065C
_080FF218:
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF254
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _080FF26C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_080FF254:
	ldr r0, _080FF26C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080FF25E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FF26C: .4byte 0x00000484
