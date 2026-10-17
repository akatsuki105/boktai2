	push {r4, r5, lr}
	ldr r0, _08086DC8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DCC @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08086DDA
	b _08086DF2
	.align 2, 0
_08086DC8: .4byte 0x030046A0
_08086DCC: .4byte 0x00000252
_08086DD0:
	adds r0, r5, #0
	bl RemoveValuable
	adds r0, r4, #0
	b _08086DF2
_08086DDA:
	movs r5, #0
_08086DDC:
	adds r0, r5, #0
	bl GetValuableItemID
	adds r4, r0, #0
	subs r4, #0x38
	cmp r4, #7
	bls _08086DD0
	adds r5, #1
	cmp r5, #0xf
	ble _08086DDC
	movs r0, #0
_08086DF2:
	pop {r4, r5}
	pop {r1}
	bx r1
