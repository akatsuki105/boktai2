	push {lr}
	adds r1, r0, #0
	ldr r0, _080BFD44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFD48 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _080BFD4C
	movs r0, #0xb1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080BFD54
	.align 2, 0
_080BFD44: .4byte 0x03002BE0
_080BFD48: .4byte 0x0000042E
_080BFD4C:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #0
_080BFD54:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
