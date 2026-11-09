	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	ldr r0, _0817E8A0 @ =0x000008AC
	adds r3, r4, r0
	movs r5, #0xff
_0817E882:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _0817E882
	ldr r0, _0817E8A4 @ =0x000008AF
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817E8A0: .4byte 0x000008AC
_0817E8A4: .4byte 0x000008AF
