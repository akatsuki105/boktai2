	push {r4, lr}
	ldr r0, _0823A6E4 @ =0x03000838
	ldr r1, _0823A6E8 @ =0x00000E64
	ldr r4, _0823A6EC @ =0x03002CB4
	adds r2, r4, #0
	movs r3, #1
	bl rfu_initializeAPI
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823A6F0
	adds r1, r4, #4
	movs r0, #3
	bl rfu_setTimerInterrupt
	movs r0, #0
	b _0823A6F4
	.align 2, 0
_0823A6E4: .4byte 0x03000838
_0823A6E8: .4byte 0x00000E64
_0823A6EC: .4byte 0x03002CB4
_0823A6F0:
	movs r0, #1
	rsbs r0, r0, #0
_0823A6F4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
