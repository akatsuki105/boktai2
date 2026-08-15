	push {lr}
	adds r2, r0, #0
	ldr r0, _0823CB44 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CB3A
	adds r0, r2, #0
	adds r0, #0x20
	bl FUN_08022428
_0823CB3A:
	ldr r1, _0823CB48 @ =gCamera
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0823CB44: .4byte 0x030047A4
_0823CB48: .4byte gCamera
