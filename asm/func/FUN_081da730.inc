	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _081DA74C @ =0x0000029D
	adds r0, r5, r1
	ldrb r7, [r0]
	cmp r7, #1
	beq _081DA7C0
	cmp r7, #1
	bgt _081DA750
	cmp r7, #0
	beq _081DA756
	b _081DA80A
	.align 2, 0
_081DA74C: .4byte 0x0000029D
_081DA750:
	cmp r7, #2
	beq _081DA804
	b _081DA80A
_081DA756:
	ldr r2, _081DA7B8 @ =0x00000286
	adds r6, r5, r2
	ldrb r1, [r6]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x16
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r6]
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, _081DA7BC @ =0x0000029A
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da69c
	adds r0, r5, #0
	bl FUN_081da814
	b _081DA80A
	.align 2, 0
_081DA7B8: .4byte 0x00000286
_081DA7BC: .4byte 0x0000029A
_081DA7C0:
	ldr r2, _081DA7FC @ =0x00000287
	adds r6, r5, r2
	ldrb r1, [r6]
	ldr r0, _081DA800 @ =0x00000299
	adds r7, r5, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x17
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r6]
	adds r1, #3
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r6]
	strb r0, [r7]
	b _081DA80A
	.align 2, 0
_081DA7FC: .4byte 0x00000287
_081DA800: .4byte 0x00000299
_081DA804:
	adds r0, r5, #0
	bl FUN_081da69c
_081DA80A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
