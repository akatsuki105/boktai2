	push {lr}
	adds r3, r0, #0
	ldr r1, _08211374 @ =0x00000868
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x1f
	cmp r0, #9
	ble _08211350
	movs r2, #0x1b
	cmp r0, #0x11
	ble _08211350
	movs r2, #0x12
	cmp r0, #0x19
	ble _08211350
	movs r2, #0xa
	cmp r0, #0x21
	ble _08211350
	movs r2, #0x1b
	cmp r0, #0x29
	bgt _08211350
	movs r2, #0x12
_08211350:
	ldr r0, _08211374 @ =0x00000868
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x31
	ble _08211366
	movs r0, #0
	strh r0, [r1]
_08211366:
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08211374: .4byte 0x00000868
