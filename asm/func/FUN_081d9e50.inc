	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _081D9E68 @ =0x00000286
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081D9E9C
	cmp r0, #1
	bgt _081D9E6C
	cmp r0, #0
	beq _081D9E72
	b _081D9EE4
	.align 2, 0
_081D9E68: .4byte 0x00000286
_081D9E6C:
	cmp r0, #2
	beq _081D9EBC
	b _081D9EE4
_081D9E72:
	movs r2, #0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bge _081D9EEE
	subs r3, #4
	adds r5, r1, r3
	adds r3, #8
	adds r4, r1, r3
	ldrb r1, [r5]
	adds r3, r0, #0
_081D9E8C:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	beq _081D9EDC
	adds r2, #1
	cmp r2, r3
	blt _081D9E8C
	b _081D9EEE
_081D9E9C:
	movs r2, #0
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r1, [r4]
	ldr r3, _081D9EB8 @ =0x085AE160
_081D9EA8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #1
	ble _081D9EA8
	b _081D9EEE
	.align 2, 0
_081D9EB8: .4byte 0x085AE160
_081D9EBC:
	movs r2, #0
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r4, r1, r3
	ldrb r1, [r4]
	ldr r3, _081D9ED8 @ =0x085AE168
_081D9EC8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #0
	ble _081D9EC8
	b _081D9EEE
	.align 2, 0
_081D9ED8: .4byte 0x085AE168
_081D9EDC:
	strb r2, [r5]
	b _081D9EEE
_081D9EE0:
	strb r2, [r4]
	b _081D9EEE
_081D9EE4:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
_081D9EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
