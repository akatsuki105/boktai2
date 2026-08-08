	push {lr}
	cmp r0, #0
	bne _0822CD48
	ldr r1, _0822CD38 @ =0x0300068E
	ldr r0, _0822CD3C @ =0x03003F90
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0822CD40 @ =0x03000692
	ldr r0, _0822CD44 @ =0x03003F9C
	b _0822CD54
	.align 2, 0
_0822CD38: .4byte 0x0300068E
_0822CD3C: .4byte 0x03003F90
_0822CD40: .4byte 0x03000692
_0822CD44: .4byte 0x03003F9C
_0822CD48:
	ldr r1, _0822CD5C @ =0x03000690
	ldr r0, _0822CD60 @ =0x03003FA8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0822CD64 @ =0x03000694
	ldr r0, _0822CD68 @ =0x03003F98
_0822CD54:
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0822CD5C: .4byte 0x03000690
_0822CD60: .4byte 0x03003FA8
_0822CD64: .4byte 0x03000694
_0822CD68: .4byte 0x03003F98
