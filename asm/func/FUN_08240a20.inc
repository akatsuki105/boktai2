	push {r4, lr}
	ldr r1, _08240A30 @ =0x030016FC
	ldr r0, [r1]
	cmp r0, #0
	bne _08240A34
	movs r0, #1
	rsbs r0, r0, #0
	b _08240A4C
	.align 2, 0
_08240A30: .4byte 0x030016FC
_08240A34:
	movs r2, #0
	adds r4, r1, #0
	movs r3, #0
_08240A3A:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r0, r0, r1
	strh r3, [r0]
	adds r2, #1
	cmp r2, #3
	ble _08240A3A
	movs r0, #0
_08240A4C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
