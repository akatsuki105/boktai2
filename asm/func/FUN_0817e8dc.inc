	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _0817E8FC @ =0x000008AC
	adds r3, r0, r4
_0817E8EC:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _0817E900
	movs r0, #1
	b _0817E908
	.align 2, 0
_0817E8FC: .4byte 0x000008AC
_0817E900:
	adds r2, #1
	cmp r2, #2
	ble _0817E8EC
	movs r0, #0
_0817E908:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
