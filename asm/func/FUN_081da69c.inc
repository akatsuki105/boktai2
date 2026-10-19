	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	adds r1, #0x12
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	beq _081DA724
	subs r1, #0x14
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA6DC
	cmp r0, #1
	bgt _081DA6CA
	cmp r0, #0
	beq _081DA6D0
	b _081DA6F4
_081DA6CA:
	cmp r0, #2
	beq _081DA6E4
	b _081DA6F4
_081DA6D0:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r6, r1
	adds r0, r0, r2
	ldrb r5, [r0]
	b _081DA6F6
_081DA6DC:
	ldr r1, _081DA6E0 @ =0x085AE160
	b _081DA6E6
	.align 2, 0
_081DA6E0: .4byte 0x085AE160
_081DA6E4:
	ldr r1, _081DA6F0 @ =0x085AE168
_081DA6E6:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA6F6
	.align 2, 0
_081DA6F0: .4byte 0x085AE168
_081DA6F4:
	movs r5, #0
_081DA6F6:
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r4, r6, r2
	ldr r0, [r4]
	subs r2, #0x10
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #7
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _081DA72C @ =0x0000029A
	adds r0, r6, r2
	strb r1, [r0]
_081DA724:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA72C: .4byte 0x0000029A
