	push {lr}
	cmp r0, #0
	bne _0822CD9C
	ldr r1, _0822CD88 @ =0x03003F90
	ldr r0, _0822CD8C @ =0x0300068E
	ldrh r3, [r0]
	strh r3, [r1]
	ldr r1, _0822CD90 @ =0x03003F9C
	ldr r0, _0822CD94 @ =0x03000692
	ldrh r2, [r0]
	strh r2, [r1]
	ldr r0, _0822CD98 @ =0x04000040
	b _0822CDAE
	.align 2, 0
_0822CD88: .4byte 0x03003F90
_0822CD8C: .4byte 0x0300068E
_0822CD90: .4byte 0x03003F9C
_0822CD94: .4byte 0x03000692
_0822CD98: .4byte 0x04000040
_0822CD9C:
	ldr r1, _0822CDB8 @ =0x03003FA8
	ldr r0, _0822CDBC @ =0x03000690
	ldrh r3, [r0]
	strh r3, [r1]
	ldr r1, _0822CDC0 @ =0x03003F98
	ldr r0, _0822CDC4 @ =0x03000694
	ldrh r2, [r0]
	strh r2, [r1]
	ldr r0, _0822CDC8 @ =0x04000042
_0822CDAE:
	strh r3, [r0]
	adds r0, #4
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0822CDB8: .4byte 0x03003FA8
_0822CDBC: .4byte 0x03000690
_0822CDC0: .4byte 0x03003F98
_0822CDC4: .4byte 0x03000694
_0822CDC8: .4byte 0x04000042
