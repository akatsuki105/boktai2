	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081D9DC4 @ =0x03002C68
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _081D9DBC
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, ip
	cmp r4, #0
	bne _081D9DC8
_081D9DBC:
	movs r0, #1
	rsbs r0, r0, #0
	b _081D9E48
	.align 2, 0
_081D9DC4: .4byte 0x03002C68
_081D9DC8:
	ldr r1, _081D9DF0 @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r1, #0xea
	add r1, ip
	strb r0, [r1]
	ldr r2, _081D9DF4 @ =0x00000287
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r2, #0xea
	add r2, ip
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	beq _081D9E14
	cmp r0, #1
	bgt _081D9DF8
	cmp r0, #0
	beq _081D9DFE
	b _081D9E38
	.align 2, 0
_081D9DF0: .4byte 0x00000286
_081D9DF4: .4byte 0x00000287
_081D9DF8:
	cmp r0, #2
	beq _081D9E1C
	b _081D9E38
_081D9DFE:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r2, #0xf2
	b _081D9E2E
_081D9E14:
	ldr r1, _081D9E18 @ =0x085AE160
	b _081D9E1E
	.align 2, 0
_081D9E18: .4byte 0x085AE160
_081D9E1C:
	ldr r1, _081D9E34 @ =0x085AE168
_081D9E1E:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r2, #0xea
_081D9E2E:
	add r2, ip
	strb r0, [r2]
	b _081D9E46
	.align 2, 0
_081D9E34: .4byte 0x085AE168
_081D9E38:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081D9E46:
	movs r0, #0
_081D9E48:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
