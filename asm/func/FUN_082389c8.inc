	push {r4, lr}
	ldr r0, _08238A10 @ =0x030046D4
	movs r4, #0
	str r4, [r0]
	ldr r1, _08238A14 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r3, _08238A18 @ =0x04000208
	strh r4, [r3]
	ldr r2, _08238A1C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08238A20 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _08238A24 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	bl WaitForVBlank
	ldr r0, _08238A28 @ =0x04000134
	strh r4, [r0]
	ldr r2, _08238A2C @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08238A10: .4byte 0x030046D4
_08238A14: .4byte 0x030046CC
_08238A18: .4byte 0x04000208
_08238A1C: .4byte 0x04000200
_08238A20: .4byte 0x0000FF7F
_08238A24: .4byte 0x04000202
_08238A28: .4byte 0x04000134
_08238A2C: .4byte 0x04000128
