	push {lr}
	ldr r0, _08231D48 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08231D4C @ =0x0300469C
	ldr r1, [r1]
	ldr r2, _08231D50 @ =0x00000958
	bl FUN_08230ab0
	ldr r0, _08231D54 @ =0x03004698
	ldr r0, [r0]
	ldr r1, _08231D58 @ =0x03004694
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_08230ab0
	pop {r0}
	bx r0
	.align 2, 0
_08231D48: .4byte 0x030046A0
_08231D4C: .4byte 0x0300469C
_08231D50: .4byte 0x00000958
_08231D54: .4byte 0x03004698
_08231D58: .4byte 0x03004694
