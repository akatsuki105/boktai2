	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	ldr r0, _081939F0 @ =0x00000E44
	adds r3, r4, r0
	movs r5, #0xff
_081939D2:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _081939D2
	ldr r0, _081939F4 @ =0x00000E43
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081939F0: .4byte 0x00000E44
_081939F4: .4byte 0x00000E43
