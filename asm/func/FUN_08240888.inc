	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _082408B0 @ =gMPlayTable
_0824088E:
	lsls r4, r5, #1
	ldr r0, [r6]
	bl m4aMPlayStop
	ldr r0, _082408B4 @ =0x03004820
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	adds r6, #0xc
	adds r5, #1
	cmp r5, #0x1f
	ble _0824088E
	bl m4aSoundInit
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082408B0: .4byte gMPlayTable
_082408B4: .4byte 0x03004820
