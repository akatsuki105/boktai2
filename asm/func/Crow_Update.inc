	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _08145490 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl Enemy_Update
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08145490: .4byte 0x03002BE0
