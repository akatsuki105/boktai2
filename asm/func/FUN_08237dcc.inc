	push {r4, lr}
	ldr r0, _08237E0C @ =0x030046D4
	movs r3, #0
	str r3, [r0]
	ldr r1, _08237E10 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r4, _08237E14 @ =0x04000208
	strh r3, [r4]
	ldr r2, _08237E18 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08237E1C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08237E20 @ =0x04000134
	strh r3, [r0]
	subs r2, #0xd8
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
_08237E0C: .4byte 0x030046D4
_08237E10: .4byte 0x030046CC
_08237E14: .4byte 0x04000208
_08237E18: .4byte 0x04000200
_08237E1C: .4byte 0x0000FF7F
_08237E20: .4byte 0x04000134
