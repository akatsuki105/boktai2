	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	ldr r6, [sp, #0x54]
	str r6, [sp, #8]
	ldr r7, [sp, #0x58]
	str r7, [sp, #0xc]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x10]
	ldr r7, [sp, #0x60]
	str r7, [sp, #0x14]
	ldr r6, [sp, #0x64]
	ldr r7, [sp, #0x68]
	str r7, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #0x18]
	movs r5, #0
	str r5, [sp, #0x20]
	ldr r4, _081EE5C8 @ =0x00004384
	str r4, [sp, #0x24]
	ldr r4, _081EE5CC @ =0x0000F62B
	str r4, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	adds r6, #0x7d
	str r6, [sp, #0x34]
	bl Entity081ee7a8_Spawn
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EE5C8: .4byte 0x00004384
_081EE5CC: .4byte 0x0000F62B
