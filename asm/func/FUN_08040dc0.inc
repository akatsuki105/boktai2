	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
	ldr r2, _08040DDC @ =0x085AB2B8
	adds r3, r2, #0
_08040DCC:
	ldrh r0, [r2]
	cmp r0, r5
	bne _08040DE0
	ldrb r0, [r2, #2]
	cmp r0, r4
	bne _08040DE0
	adds r0, r3, #0
	b _08040DEC
	.align 2, 0
_08040DDC: .4byte 0x085AB2B8
_08040DE0:
	adds r2, #8
	adds r3, #8
	adds r1, #1
	cmp r1, #0x14
	ble _08040DCC
	movs r0, #0
_08040DEC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
