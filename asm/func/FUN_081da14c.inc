	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DA164 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA17C
	cmp r0, #1
	bgt _081DA168
	cmp r0, #0
	beq _081DA16E
	b _081DA1E0
	.align 2, 0
_081DA164: .4byte 0x0000029D
_081DA168:
	cmp r0, #2
	beq _081DA18C
	b _081DA1E0
_081DA16E:
	ldr r2, _081DA178 @ =0x00000286
	adds r0, r5, r2
	ldrb r1, [r0]
	b _081DA1E2
	.align 2, 0
_081DA178: .4byte 0x00000286
_081DA17C:
	ldr r1, _081DA188 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #3
	b _081DA1E2
	.align 2, 0
_081DA188: .4byte 0x00000287
_081DA18C:
	ldr r2, _081DA1A0 @ =0x00000286
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA1C0
	cmp r0, #1
	bgt _081DA1A4
	cmp r0, #0
	beq _081DA1AA
	b _081DA1E0
	.align 2, 0
_081DA1A0: .4byte 0x00000286
_081DA1A4:
	cmp r0, #2
	beq _081DA1C8
	b _081DA1E0
_081DA1AA:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r0, #7
	b _081DA1E2
_081DA1C0:
	ldr r1, _081DA1C4 @ =0x085AE160
	b _081DA1CA
	.align 2, 0
_081DA1C4: .4byte 0x085AE160
_081DA1C8:
	ldr r1, _081DA1DC @ =0x085AE168
_081DA1CA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #7
	b _081DA1E2
	.align 2, 0
_081DA1DC: .4byte 0x085AE168
_081DA1E0:
	movs r1, #0
_081DA1E2:
	ldr r0, _081DA214 @ =0x0000029B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #0x19
	cmp r0, r4
	beq _081DA20E
	bl Marquee_Clear
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl GetStringByID
	bl Marquee_SetText
	strb r4, [r6]
_081DA20E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA214: .4byte 0x0000029B
