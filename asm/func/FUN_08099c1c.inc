	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08099C50 @ =0x0000400D
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r5, _08099C54 @ =0x030046A0
	ldr r0, [r5]
	ldrh r1, [r0, #0x10]
	ldr r2, _08099C58 @ =0x0000400E
	adds r0, r4, r2
	strb r1, [r0]
	bl FUN_08099b5c
	ldr r2, _08099C5C @ =0x0000400F
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldrh r0, [r0, #0x14]
	ldr r1, _08099C60 @ =0x00004010
	adds r4, r4, r1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099C50: .4byte 0x0000400D
_08099C54: .4byte 0x030046A0
_08099C58: .4byte 0x0000400E
_08099C5C: .4byte 0x0000400F
_08099C60: .4byte 0x00004010
