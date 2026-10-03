	push {lr}
	adds r1, r0, #0
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080410B6
	adds r2, #0x30
	adds r0, r1, r2
	bl ParticleShadow_Show
	b _080410C4
_080410B6:
	cmp r0, #2
	bne _080410C4
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r1, r2
	bl AuxShadow_Show
_080410C4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
