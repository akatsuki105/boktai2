	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	ldr r4, _081794FC @ =0x00000FB8
	adds r2, r0, r4
_081794F0:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08179500
	movs r0, #1
	b _0817950A
	.align 2, 0
_081794FC: .4byte 0x00000FB8
_08179500:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _081794F0
	movs r0, #0
_0817950A:
	pop {r4}
	pop {r1}
	bx r1
