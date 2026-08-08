	push {r4, r5, lr}
	ldr r5, _08237C68 @ =0x04000208
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08237C6C @ =0x04000200
	ldrh r4, [r3]
	strh r0, [r3]
	ldr r1, _08237C70 @ =0x03002CB0
	ldr r0, _08237C74 @ =IntrDummy
	str r0, [r1, #4]
	ldr r2, _08237C78 @ =0x04000128
	ldrh r1, [r2]
	ldr r0, _08237C7C @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08237C80 @ =0x0000FF7F
	ands r0, r4
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	ldr r1, _08237C84 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08237C68: .4byte 0x04000208
_08237C6C: .4byte 0x04000200
_08237C70: .4byte 0x03002CB0
_08237C74: .4byte IntrDummy
_08237C78: .4byte 0x04000128
_08237C7C: .4byte 0x0000BFFF
_08237C80: .4byte 0x0000FF7F
_08237C84: .4byte 0x04000202
