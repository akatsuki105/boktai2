	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, _082409BC @ =0x030016FC
_082409A8:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	bne _082409C0
	strh r3, [r1]
	movs r0, #1
	b _082409C8
	.align 2, 0
_082409BC: .4byte 0x030016FC
_082409C0:
	adds r2, #1
	cmp r2, #3
	ble _082409A8
	movs r0, #0
_082409C8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
