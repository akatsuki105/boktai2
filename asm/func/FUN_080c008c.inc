	push {r4, lr}
	ldr r0, _080C00C8 @ =0x03000158
	ldr r3, [r0]
	cmp r3, #0
	beq _080C00C2
	ldr r2, _080C00CC @ =FUN_080bffe8
	movs r0, #0
	movs r1, #0
	bl FUN_080a6180
	ldr r4, _080C00D0 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0807b910
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
_080C00C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C00C8: .4byte 0x03000158
_080C00CC: .4byte FUN_080bffe8
_080C00D0: .4byte 0x03002BE0
