	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823A78C @ =0x05000081
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823A78C: .4byte 0x05000081
