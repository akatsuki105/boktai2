	push {lr}
	bl FUN_080ee218
	ldr r0, _080EEA7C @ =0x03002C60
	ldr r0, [r0]
	bl Free
	ldr r1, _080EEA80 @ =0x03002C5C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080EEA7C: .4byte 0x03002C60
_080EEA80: .4byte 0x03002C5C
