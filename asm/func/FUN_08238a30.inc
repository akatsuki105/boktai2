	push {r4, r5, r6, lr}
	ldr r0, _08238A8C @ =0x030046D4
	movs r6, #0
	str r6, [r0]
	ldr r1, _08238A90 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r3, _08238A94 @ =0x04000208
	strh r6, [r3]
	ldr r2, _08238A98 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08238A9C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _08238AA0 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	ldr r5, _08238AA4 @ =0x04000134
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r5]
	ldr r4, _08238AA8 @ =0x04000128
	strh r6, [r4]
	bl WaitForVBlank
	bl WaitForVBlank
	strh r6, [r5]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #3
	orrs r0, r1
	strh r0, [r4]
	bl WaitForVBlank
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08238A8C: .4byte 0x030046D4
_08238A90: .4byte 0x030046CC
_08238A94: .4byte 0x04000208
_08238A98: .4byte 0x04000200
_08238A9C: .4byte 0x0000FF7F
_08238AA0: .4byte 0x04000202
_08238AA4: .4byte 0x04000134
_08238AA8: .4byte 0x04000128
