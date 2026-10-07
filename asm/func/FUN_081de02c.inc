	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r1, _081DE068 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r0, r2
	movs r2, #0
	adds r6, r1, #0
_081DE044:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _081DE044
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _081DE070
	ldr r2, _081DE06C @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	b _081DE072
	.align 2, 0
_081DE068: .4byte 0x030046A0
_081DE06C: .4byte 0x030047E0
_081DE070:
	movs r0, #0
_081DE072:
	strh r0, [r3, #0x10]
	movs r0, #0x64
	strh r0, [r3, #0x12]
	ldr r0, [r6]
	ldrh r1, [r0, #0x10]
	strh r1, [r3, #0x14]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r3, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
