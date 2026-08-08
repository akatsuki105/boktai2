	push {lr}
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0807A968
	movs r0, #0
	b _0807A96A
_0807A968:
	movs r0, #1
_0807A96A:
	pop {r1}
	bx r1
	.align 2, 0
