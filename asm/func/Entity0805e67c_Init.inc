	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	ldr r0, _0805E674 @ =0x0000922E
	ldr r1, _0805E678 @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805E654:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805e67c_InitElem
	adds r4, #1
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805E654
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805E674: .4byte 0x0000922E
_0805E678: .4byte 0x00005BB7
