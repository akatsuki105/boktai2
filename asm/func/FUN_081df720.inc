	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DF730 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF734
	movs r0, #0
	b _081DF754
	.align 2, 0
_081DF730: .4byte 0x03002C68
_081DF734:
	movs r2, #0
	movs r1, #0
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r3, r0, r5
_081DF73E:
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	bne _081DF74C
	adds r2, #1
_081DF74C:
	adds r1, #1
	cmp r1, #4
	ble _081DF73E
	adds r0, r2, #0
_081DF754:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
