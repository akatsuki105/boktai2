	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _080F9BD8 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	bne _080F9BE6
	movs r0, #8
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080F9BE4
	ldr r1, _080F9BDC @ =FUN_080f9b5c
	ldr r2, _080F9BE0 @ =0x080F9B75
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080f9b80
	cmp r0, #0
	bge _080F9BE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080F9BE6
	.align 2, 0
_080F9BD8: .4byte 0x03000184
_080F9BDC: .4byte FUN_080f9b5c
_080F9BE0: .4byte 0x080F9B75
_080F9BE4:
	adds r0, r4, #0
_080F9BE6:
	pop {r4, r5}
	pop {r1}
	bx r1
