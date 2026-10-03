	push {r4, lr}
	movs r2, #0
	ldr r4, _08097D38 @ =0x00003FF0
	adds r3, r0, r4
_08097D28:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08097D3C
	adds r0, r2, #0
	b _08097D46
	.align 2, 0
_08097D38: .4byte 0x00003FF0
_08097D3C:
	adds r2, #1
	cmp r2, #0xf
	ble _08097D28
	movs r0, #1
	rsbs r0, r0, #0
_08097D46:
	pop {r4}
	pop {r1}
	bx r1
