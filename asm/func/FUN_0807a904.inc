	push {lr}
	cmp r1, #0
	bne _0807A914
	ldr r2, _0807A918 @ =0x00000402
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0807A914:
	pop {r0}
	bx r0
	.align 2, 0
_0807A918: .4byte 0x00000402
