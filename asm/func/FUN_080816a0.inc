	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08081748 @ =0x000005FC
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r2, _0808174C @ =0x00000604
	adds r0, r4, r2
	movs r5, #0
	movs r6, #0
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #4
	adds r0, r4, r2
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl FUN_080815ac
	ldr r1, _08081750 @ =0x0000097C
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08081754 @ =0x0000097D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x18
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _08081758 @ =0x000003FF
	adds r4, r4, r2
	movs r0, #0xff
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081748: .4byte 0x000005FC
_0808174C: .4byte 0x00000604
_08081750: .4byte 0x0000097C
_08081754: .4byte 0x0000097D
_08081758: .4byte 0x000003FF
