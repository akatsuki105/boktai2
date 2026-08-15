	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080E3830 @ =0x0000922E
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x58]
	adds r4, #0x48
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E3830: .4byte 0x0000922E
