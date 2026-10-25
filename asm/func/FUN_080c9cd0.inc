	push {lr}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r2, r1, #0
	adds r2, #0xa7
	movs r0, #0
	strb r0, [r2]
	ldr r0, _080C9CFC @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080C9CF2
	adds r0, r1, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080C9CF8
_080C9CF2:
	adds r0, r3, #0
	bl Boss_UpdateState
_080C9CF8:
	pop {r0}
	bx r0
	.align 2, 0
_080C9CFC: .4byte 0x03002BE0
