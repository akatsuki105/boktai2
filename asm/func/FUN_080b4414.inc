	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B444C @ =0x0000C091
	ldr r1, _080B4450 @ =0x000083C0
	bl GetFile
	adds r2, r0, #0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r4, r4, r0
	str r2, [r4]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B444C: .4byte 0x0000C091
_080B4450: .4byte 0x000083C0
