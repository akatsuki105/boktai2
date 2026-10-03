	push {lr}
	adds r1, r0, #0
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08041086
	adds r2, #0x30
	adds r0, r1, r2
	bl ParticleShadow_Hide
	b _08041094
_08041086:
	cmp r0, #2
	bne _08041094
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r1, r2
	bl AuxShadow_Hide
_08041094:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
