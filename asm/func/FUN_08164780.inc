	push {lr}
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _08164792
	movs r0, #0
	b _081647B0
_08164792:
	ldr r2, _081647B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081647B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081647BC @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _081647C0 @ =0x00200004
	cmp r0, #0xb3
	bgt _081647AE
	ldr r1, _081647C4 @ =0x00400008
_081647AE:
	adds r0, r1, #0
_081647B0:
	pop {r1}
	bx r1
	.align 2, 0
_081647B4: .4byte 0x030046B8
_081647B8: .4byte 0x000003FF
_081647BC: .4byte 0x0203B400
_081647C0: .4byte 0x00200004
_081647C4: .4byte 0x00400008
