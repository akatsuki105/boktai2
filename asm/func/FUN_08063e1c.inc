	push {lr}
	ldr r2, _08063E3C @ =0x00000366
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	bl Div
	rsbs r0, r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08063E3C: .4byte 0x00000366
