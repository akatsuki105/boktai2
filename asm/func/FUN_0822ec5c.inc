	push {lr}
	sub sp, #4
	ldr r0, _0822EC74 @ =0x44444444
	str r0, [sp]
	ldr r1, _0822EC78 @ =0x0600A000
	ldr r2, _0822EC7C @ =0x01000800
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0822EC74: .4byte 0x44444444
_0822EC78: .4byte 0x0600A000
_0822EC7C: .4byte 0x01000800
