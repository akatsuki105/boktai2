	push {lr}
	ldr r0, _0800919C @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _080091A0
	movs r0, #1
	rsbs r0, r0, #0
	b _080091C0
	.align 2, 0
_0800919C: .4byte 0x03000038
_080091A0:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_080091A8:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _080091B0
	adds r3, #1
_080091B0:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _080091A8
	movs r0, #0
	cmp r3, #0
	bne _080091C0
	movs r0, #1
_080091C0:
	pop {r1}
	bx r1
