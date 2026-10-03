	push {lr}
	adds r2, r0, #0
	adds r2, #0x6c
	movs r3, #0
_081E12AC:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r1
	bne _081E12B8
	adds r0, r2, #0
	b _081E12C2
_081E12B8:
	adds r3, #1
	adds r2, #0x90
	cmp r3, #4
	ble _081E12AC
	movs r0, #0
_081E12C2:
	pop {r1}
	bx r1
	.align 2, 0
