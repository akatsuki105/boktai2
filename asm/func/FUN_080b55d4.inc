	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B560C @ =0x0000C091
	ldr r1, _080B5610 @ =0x000083C0
	bl GetFile
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #4
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
	bl Video_SetupBGLayout
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B560C: .4byte 0x0000C091
_080B5610: .4byte 0x000083C0
