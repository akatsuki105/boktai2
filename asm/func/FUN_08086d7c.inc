	push {r4, lr}
	ldr r0, _08086DAC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DB0 @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08086DA4
	movs r4, #0
_08086D90:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08086DA4
	adds r4, #1
	cmp r4, #0xf
	ble _08086D90
	movs r0, #0
_08086DA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086DAC: .4byte 0x030046A0
_08086DB0: .4byte 0x00000252
