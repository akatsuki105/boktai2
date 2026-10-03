	push {lr}
	movs r1, #8
	ldr r3, _08098924 @ =0x00003FF0
	adds r2, r0, r3
_08098914:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08098928
	movs r0, #1
	b _08098930
	.align 2, 0
_08098924: .4byte 0x00003FF0
_08098928:
	adds r1, #1
	cmp r1, #0xb
	ble _08098914
	movs r0, #0
_08098930:
	pop {r1}
	bx r1
