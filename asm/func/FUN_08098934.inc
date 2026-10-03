	push {lr}
	movs r1, #0xc
	ldr r3, _0809894C @ =0x00003FF0
	adds r2, r0, r3
_0809893C:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08098950
	movs r0, #1
	b _08098958
	.align 2, 0
_0809894C: .4byte 0x00003FF0
_08098950:
	adds r1, #1
	cmp r1, #0xf
	ble _0809893C
	movs r0, #0
_08098958:
	pop {r1}
	bx r1
