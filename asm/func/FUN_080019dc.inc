	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _08001A10 @ =0x000092B3
	bl GetFile
	adds r1, r0, #0
	adds r1, #0x14
	ldr r0, _08001A14 @ =0x00000434
	adds r4, r4, r0
	movs r0, #0xd0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x32
	movs r3, #0
	bl FUN_08001944
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A10: .4byte 0x000092B3
_08001A14: .4byte 0x00000434
