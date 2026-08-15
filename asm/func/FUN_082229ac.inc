	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _082229E0 @ =0x0000C091
	ldr r1, _082229E4 @ =0x000033B2
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x38]
	movs r0, #0xb
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082229E0: .4byte 0x0000C091
_082229E4: .4byte 0x000033B2
