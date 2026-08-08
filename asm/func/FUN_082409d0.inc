	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, _082409F0 @ =0x030016FC
	movs r5, #0
_082409DA:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r3
	bne _082409F4
	strh r5, [r1]
	movs r0, #1
	b _082409FC
	.align 2, 0
_082409F0: .4byte 0x030016FC
_082409F4:
	adds r2, #1
	cmp r2, #3
	ble _082409DA
	movs r0, #0
_082409FC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
