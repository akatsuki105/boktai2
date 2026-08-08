	push {lr}
	movs r2, #1
	ldr r0, _0823AA38 @ =0x030047A4
	ldr r1, _0823AA3C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0823AA32
	bl FUN_082407e0
	movs r2, #2
	ldr r1, _0823AA40 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0823AA32:
	pop {r0}
	bx r0
	.align 2, 0
_0823AA38: .4byte 0x030047A4
_0823AA3C: .4byte 0x030047A0
_0823AA40: .4byte 0x030044BC
