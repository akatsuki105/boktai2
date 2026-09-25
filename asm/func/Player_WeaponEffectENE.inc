	push {lr}
	adds r2, r0, #0
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08063DD0 @ =0x0000036A
	adds r2, r2, r1
	ldrh r1, [r2]
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_08063DD0: .4byte 0x0000036A
