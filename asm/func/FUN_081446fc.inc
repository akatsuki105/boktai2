	push {lr}
	ldr r1, _08144724 @ =0x00000484
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	cmp r0, #0x1d
	ble _08144718
	movs r1, #1
	cmp r0, #0x31
	ble _08144718
	movs r1, #3
	cmp r0, #0x45
	bgt _08144718
	movs r1, #2
_08144718:
	ldr r0, _08144728 @ =0x085AD83C
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08144724: .4byte 0x00000484
_08144728: .4byte 0x085AD83C
