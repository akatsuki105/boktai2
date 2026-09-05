	push {lr}
	adds r3, r0, #0
	ldr r0, _08001B40 @ =0x00000642
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #1
	bls _08001B44
	subs r0, #2
	strb r0, [r2]
	b _08001B4E
	.align 2, 0
_08001B40: .4byte 0x00000642
_08001B44:
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08001B54 @ =0x00000644
	adds r0, r3, r2
	strb r1, [r0]
_08001B4E:
	pop {r0}
	bx r0
	.align 2, 0
_08001B54: .4byte 0x00000644
