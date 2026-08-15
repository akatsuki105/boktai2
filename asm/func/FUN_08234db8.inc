	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08234DD4 @ =0x0000D4FB
	bl GetFile
	ldr r1, _08234DD8 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x10]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08234DD4: .4byte 0x0000D4FB
_08234DD8: .4byte 0x030046A4
