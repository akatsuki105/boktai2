	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08216E88 @ =0x00001FDC
	adds r3, r4, r0
	movs r5, #0
	ldrsh r2, [r3, r5]
	ldr r5, _08216E8C @ =0x00001FC4
	adds r0, r4, r5
	adds r0, r0, r2
	strb r1, [r0]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldrh r2, [r3]
	adds r0, r1, #0
	cmp r0, #0x16
	bgt _08216E90
	adds r0, r2, #1
	strh r0, [r3]
	movs r5, #0
	b _08216E92
	.align 2, 0
_08216E88: .4byte 0x00001FDC
_08216E8C: .4byte 0x00001FC4
_08216E90:
	movs r5, #1
_08216E92:
	adds r0, r4, #0
	bl FUN_08216dd8
	adds r0, r4, #0
	bl FUN_08216bdc
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
