	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	ldr r4, _081920E0 @ =0x00000EDC
	adds r2, r0, r4
_081920D4:
	ldrh r0, [r2]
	cmp r0, r1
	bne _081920E4
	movs r0, #1
	b _081920EE
	.align 2, 0
_081920E0: .4byte 0x00000EDC
_081920E4:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _081920D4
	movs r0, #0
_081920EE:
	pop {r4}
	pop {r1}
	bx r1
