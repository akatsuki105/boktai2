	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _082158DC @ =0x00000DBC
	adds r5, r4, r0
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #7
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _082158E0 @ =0x00000E7C
	adds r4, r4, r0
	ldr r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r5, #0x22]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082158DC: .4byte 0x00000DBC
_082158E0: .4byte 0x00000E7C
