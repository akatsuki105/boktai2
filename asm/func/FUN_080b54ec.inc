	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B5520 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B5518
	ldr r1, _080B5524 @ =0x00000834
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B5518
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
_080B5518:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5520: .4byte 0x00000844
_080B5524: .4byte 0x00000834
