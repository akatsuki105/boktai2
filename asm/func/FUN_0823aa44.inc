	push {lr}
	ldr r0, _0823AA64 @ =0x030044BC
	ldr r1, [r0]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	cmp r0, #0
	bne _0823AA6C
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _0823AA68
	bl FUN_0823aa10
	b _0823AA6C
	.align 2, 0
_0823AA64: .4byte 0x030044BC
_0823AA68:
	bl FUN_0823a9f4
_0823AA6C:
	pop {r0}
	bx r0
