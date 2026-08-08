	push {lr}
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0823A8DC @ =0x030047A4
	ldr r1, _0823A8E0 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0823A8EC
	ldr r0, _0823A8E4 @ =0x030047B0
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A8EC
	ldr r0, _0823A8E8 @ =0x03004790
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A8EC
	movs r0, #0
	b _0823A8EE
	.align 2, 0
_0823A8DC: .4byte 0x030047A4
_0823A8E0: .4byte 0x030047A0
_0823A8E4: .4byte 0x030047B0
_0823A8E8: .4byte 0x03004790
_0823A8EC:
	movs r0, #1
_0823A8EE:
	pop {r1}
	bx r1
	.align 2, 0
