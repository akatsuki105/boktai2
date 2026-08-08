	push {r4, r5, r6, lr}
	ldr r5, _08237C1C @ =0x04000208
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08237C20 @ =0x04000200
	ldrh r4, [r3]
	strh r0, [r3]
	ldr r1, _08237C24 @ =0x03002CB0
	ldr r0, _08237C28 @ =FUN_08237c88
	str r0, [r1, #4]
	ldr r2, _08237C2C @ =0x04000128
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #7
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	adds r0, r1, #0
	orrs r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	ldr r0, _08237C30 @ =0x04000202
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237C1C: .4byte 0x04000208
_08237C20: .4byte 0x04000200
_08237C24: .4byte 0x03002CB0
_08237C28: .4byte FUN_08237c88
_08237C2C: .4byte 0x04000128
_08237C30: .4byte 0x04000202
