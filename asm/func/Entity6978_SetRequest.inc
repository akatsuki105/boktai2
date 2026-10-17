	push {lr}
	adds r3, r0, #0
	ldr r0, _08002828 @ =0x03002B30
	ldr r0, [r0]
	cmp r0, #0
	beq _08002822
	strh r3, [r0, #0x24]
	cmp r1, #0
	ble _08002822
	adds r3, r0, #0
	adds r3, #0x26
_08002816:
	ldm r2!, {r0}
	strh r0, [r3]
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _08002816
_08002822:
	pop {r0}
	bx r0
	.align 2, 0
_08002828: .4byte 0x03002B30
