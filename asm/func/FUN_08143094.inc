	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _081430B4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081430B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081430BA
	.align 2, 0
_081430B4: .4byte 0x0000046D
_081430B8:
	movs r0, #0
_081430BA:
	cmp r0, #0
	beq _081430CE
	adds r0, r4, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	ldr r0, _081430F8 @ =0x0000065C
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_081430CE:
	ldr r1, _081430F8 @ =0x0000065C
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _081430DE
	adds r0, r4, #0
	bl Crow_PlayWingSound
_081430DE:
	ldr r1, _081430FC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143122
	ldrb r0, [r5]
	cmp r0, #0
	blt _08143118
	cmp r0, #3
	ble _08143100
	cmp r0, #5
	beq _0814310A
	b _08143118
	.align 2, 0
_081430F8: .4byte 0x0000065C
_081430FC: .4byte 0x0000046E
_08143100:
	adds r0, r4, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	b _08143118
_0814310A:
	ldr r0, _08143114 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	b _08143120
	.align 2, 0
_08143114: .4byte 0x0000046B
_08143118:
	ldr r0, _08143128 @ =0x0000065C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
_08143120:
	strb r0, [r1]
_08143122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08143128: .4byte 0x0000065C
