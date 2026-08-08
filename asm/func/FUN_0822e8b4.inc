	push {lr}
	ldr r0, _0822E8C4 @ =0x02035400
	movs r1, #0x80
	lsls r1, r1, #4
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_0822E8C4: .4byte 0x02035400
