	push {lr}
	ldr r0, [r0, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #5
	bne _08144B8A
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _08144B8A
	movs r0, #0xf6
	bl PlaySound_082406e0
_08144B8A:
	pop {r0}
	bx r0
	.align 2, 0
