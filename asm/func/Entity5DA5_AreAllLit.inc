	push {lr}
	ldr r0, _08009164 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _08009168
	movs r0, #1
	rsbs r0, r0, #0
	b _08009188
	.align 2, 0
_08009164: .4byte 0x03000038
_08009168:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_08009170:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _08009178
	adds r3, #1
_08009178:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _08009170
	movs r0, #0
	cmp r3, #4
	bne _08009188
	movs r0, #1
_08009188:
	pop {r1}
	bx r1
