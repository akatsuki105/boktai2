	push {r4, lr}
	ldr r2, _0802239C @ =0x03002B4C
	str r0, [r2]
	adds r2, r0, #0
	adds r2, #0x23
	movs r3, #0
	strb r3, [r2]
	ldr r2, _080223A0 @ =0x0000FFFF
	strh r2, [r0, #0x18]
	movs r2, #1
	rsbs r2, r2, #0
	strh r2, [r0, #0x1a]
	movs r2, #0
	strh r3, [r0, #0x1c]
	strb r2, [r0, #0x1e]
	strb r2, [r0, #0x1f]
	strh r3, [r0, #0x20]
	movs r4, #0x22
	strb r2, [r4, r0]
	str r3, [r0, #0x6c]
	str r3, [r0, #0x74]
	adds r0, #0x78
	movs r2, #1
	bl FUN_080223f4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802239C: .4byte 0x03002B4C
_080223A0: .4byte 0x0000FFFF
