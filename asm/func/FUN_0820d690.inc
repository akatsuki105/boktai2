	push {lr}
	adds r3, r0, #0
	ldr r1, _0820D6DC @ =0x0000110C
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x1f
	cmp r0, #9
	ble _0820D6BC
	movs r2, #0x1b
	cmp r0, #0x11
	ble _0820D6BC
	movs r2, #0x12
	cmp r0, #0x19
	ble _0820D6BC
	movs r2, #0xa
	cmp r0, #0x21
	ble _0820D6BC
	movs r2, #0x1b
	cmp r0, #0x29
	bgt _0820D6BC
	movs r2, #0x12
_0820D6BC:
	ldr r0, _0820D6DC @ =0x0000110C
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x31
	ble _0820D6D2
	movs r0, #0
	strh r0, [r1]
_0820D6D2:
	ldr r1, _0820D6E0 @ =0x00001104
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0820D6DC: .4byte 0x0000110C
_0820D6E0: .4byte 0x00001104
