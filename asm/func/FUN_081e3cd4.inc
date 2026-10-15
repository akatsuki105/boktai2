	push {lr}
	bl Taiyo_Enable
	ldr r1, _081E3CE4 @ =0x0300481C
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081E3CE4: .4byte 0x0300481C
