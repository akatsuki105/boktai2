	push {lr}
	bl FUN_08238bf4
	ldr r1, _081DFC48 @ =FUN_0822db5c
	ldr r2, _081DFC4C @ =FUN_0822aaac
	ldr r3, _081DFC50 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r0, _081DFC54 @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	ldr r2, _081DFC58 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _081DFC5C @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DFC60 @ =0x03002C68
	str r3, [r0]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081DFC48: .4byte FUN_0822db5c
_081DFC4C: .4byte FUN_0822aaac
_081DFC50: .4byte FUN_0822f204
_081DFC54: .4byte 0x030044D0
_081DFC58: .4byte 0x030047A4
_081DFC5C: .4byte 0xFFFFF7FF
_081DFC60: .4byte 0x03002C68
