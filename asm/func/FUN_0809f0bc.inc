	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F138
	ldr r1, _0809F0EC @ =0x0000025F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _0809F0FA
	cmp r1, #1
	bgt _0809F0F0
	cmp r1, #0
	beq _0809F10C
	b _0809F124
	.align 2, 0
_0809F0EC: .4byte 0x0000025F
_0809F0F0:
	cmp r1, #2
	beq _0809F10C
	cmp r1, #3
	beq _0809F11A
	b _0809F124
_0809F0FA:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F108 @ =0x0000013F
	bl Video_SetAuxSpritePltt
	b _0809F124
	.align 2, 0
_0809F108: .4byte 0x0000013F
_0809F10C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _0809F124
_0809F11A:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F130 @ =0x0000013D
	bl Video_SetAuxSpritePltt
_0809F124:
	ldr r0, _0809F134 @ =0x0000025F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0809F170
	.align 2, 0
_0809F130: .4byte 0x0000013D
_0809F134: .4byte 0x0000025F
_0809F138:
	ldr r1, _0809F160 @ =0x0000025F
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #4
	bls _0809F146
	movs r0, #4
	strb r0, [r4]
_0809F146:
	ldrb r6, [r4]
	cmp r6, #0
	beq _0809F164
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0809F170
	.align 2, 0
_0809F160: .4byte 0x0000025F
_0809F164:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F178 @ =0x0000013D
	bl Video_SetAuxSpritePltt
	strb r6, [r4]
_0809F170:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F178: .4byte 0x0000013D
