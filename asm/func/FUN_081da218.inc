	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r5, r7, r1
	ldr r1, [r5]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r2, _081DA288 @ =0x00000286
	adds r6, r7, r2
	ldrb r1, [r6]
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r1, [r6]
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, [r5]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r1, _081DA28C @ =0x00000287
	adds r5, r7, r1
	ldrb r1, [r5]
	adds r1, #3
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r1, [r5]
	ldr r2, _081DA290 @ =0x00000299
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r0, [r6]
	cmp r0, #1
	beq _081DA2AE
	cmp r0, #1
	bgt _081DA294
	cmp r0, #0
	beq _081DA29A
	b _081DA2D0
	.align 2, 0
_081DA288: .4byte 0x00000286
_081DA28C: .4byte 0x00000287
_081DA290: .4byte 0x00000299
_081DA294:
	cmp r0, #2
	beq _081DA2B8
	b _081DA2D0
_081DA29A:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r5, [r0]
	b _081DA2D2
_081DA2AE:
	ldr r1, _081DA2B4 @ =0x085AE160
	b _081DA2BA
	.align 2, 0
_081DA2B4: .4byte 0x085AE160
_081DA2B8:
	ldr r1, _081DA2CC @ =0x085AE168
_081DA2BA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA2D2
	.align 2, 0
_081DA2CC: .4byte 0x085AE168
_081DA2D0:
	movs r5, #0
_081DA2D2:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #7
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081DA308 @ =0x0000029A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA308: .4byte 0x0000029A
