	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080C0218 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	str r4, [r0]
	bl FUN_080bfa74
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sound_SetBGMTempo
	movs r0, #8
	bl FUN_0823bca8
	adds r0, r7, #0
	bl FUN_080bffcc
	ldr r2, _080C021C @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #2
	str r1, [r0, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r2]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	cmp r6, #0
	bne _080C0224
	ldr r2, _080C0220 @ =FUN_080c0014
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
	b _080C0230
	.align 2, 0
_080C0218: .4byte 0x030046A0
_080C021C: .4byte 0x03002BE0
_080C0220: .4byte FUN_080c0014
_080C0224:
	ldr r2, _080C0240 @ =FUN_080c0058
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
_080C0230:
	ldr r1, _080C0244 @ =FUN_080c01a8
	adds r0, r7, #0
	bl EntityB3D1_SetState
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0240: .4byte FUN_080c0058
_080C0244: .4byte FUN_080c01a8
