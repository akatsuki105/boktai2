	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, #0x9e
	ldrb r5, [r0]
	movs r6, #0
	ldr r7, _080E72A4 @ =0x030046B8
	movs r0, #0xa0
	adds r0, r0, r4
	mov r8, r0
_080E721A:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080E72A8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080E72AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r1, [r1]
	ldrb r1, [r1]
	bl Mod
	adds r2, r0, #0
	cmp r2, r5
	beq _080E724A
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _080E7250
_080E724A:
	adds r6, #1
	cmp r6, #3
	ble _080E721A
_080E7250:
	cmp r2, r5
	beq _080E7260
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _080E726E
_080E7260:
	adds r2, r5, #1
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	blt _080E726E
	movs r2, #0
_080E726E:
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	adds r5, r4, #0
	adds r5, #0x9e
	strb r2, [r5]
	adds r0, r4, #0
	adds r0, #0x9f
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	bl FUN_08234f6c
	adds r2, r4, #0
	adds r2, #0xa4
	str r0, [r2]
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E72A4: .4byte 0x030046B8
_080E72A8: .4byte 0x000003FF
_080E72AC: .4byte 0x0203B400
