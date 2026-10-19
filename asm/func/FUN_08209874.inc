	push {lr}
	ldr r3, _08209888 @ =0x085AEC24
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08209888: .4byte 0x085AEC24
