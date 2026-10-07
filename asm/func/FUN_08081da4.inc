	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08081DCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081DD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08081DD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0x64
	bl Mod
	cmp r0, r4
	blt _08081DD8
	movs r0, #0
	b _08081DDA
	.align 2, 0
_08081DCC: .4byte 0x030046B8
_08081DD0: .4byte 0x000003FF
_08081DD4: .4byte 0x0203B400
_08081DD8:
	movs r0, #1
_08081DDA:
	pop {r4}
	pop {r1}
	bx r1
