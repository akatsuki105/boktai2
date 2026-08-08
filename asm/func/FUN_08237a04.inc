	push {r4, r5, lr}
	ldr r4, _08237A40 @ =0x04000208
	movs r0, #0
	strh r0, [r4]
	ldr r2, _08237A44 @ =0x04000200
	ldrh r3, [r2]
	strh r0, [r2]
	ldr r1, _08237A48 @ =0x0400010C
	ldr r5, _08237A4C @ =0x0000F5D8
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc1
	strh r0, [r1]
	ldr r1, _08237A50 @ =0x03002CB0
	ldr r0, _08237A54 @ =FUN_08237aac
	str r0, [r1, #8]
	movs r1, #0x40
	adds r0, r1, #0
	orrs r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08237A58 @ =0x04000202
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08237A40: .4byte 0x04000208
_08237A44: .4byte 0x04000200
_08237A48: .4byte 0x0400010C
_08237A4C: .4byte 0x0000F5D8
_08237A50: .4byte 0x03002CB0
_08237A54: .4byte FUN_08237aac
_08237A58: .4byte 0x04000202
