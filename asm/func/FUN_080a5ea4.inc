	push {lr}
	adds r1, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A5EB8
	adds r0, r1, #0
	bl EntityCF58_RunDoneCallback
	b _080A5EBE
_080A5EB8:
	adds r0, r1, #0
	bl EntityCF58_RunScript
_080A5EBE:
	pop {r0}
	bx r0
	.align 2, 0
