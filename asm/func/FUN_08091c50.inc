	push {r4, lr}
	ldr r3, _08091C6C @ =0x00003FB8
	adds r2, r0, r3
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08091C70 @ =0x00003FB9
	adds r2, r0, r4
	strb r1, [r2]
	ldr r1, _08091C74 @ =0x00003AE4
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091C6C: .4byte 0x00003FB8
_08091C70: .4byte 0x00003FB9
_08091C74: .4byte 0x00003AE4
