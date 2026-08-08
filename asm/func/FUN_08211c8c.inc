	push {lr}
	adds r3, r0, #0
	ldr r0, _08211CB4 @ =0x00000322
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	blt _08211CAE
	adds r0, r3, #0
	movs r1, #2
	bl FUN_08211bac
_08211CAE:
	pop {r0}
	bx r0
	.align 2, 0
_08211CB4: .4byte 0x00000322
