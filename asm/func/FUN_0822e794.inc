	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0822E7C0 @ =0x03000720
	ldr r2, [r4]
	cmp r2, #0x80
	bhi _0822E7BA
	ldr r0, _0822E7C4 @ =0x030006A0
	adds r0, r2, r0
	strb r3, [r0]
	ldr r0, [r4]
	lsls r0, r0, #5
	ldr r2, _0822E7C8 @ =0x02035C00
	adds r0, r0, r2
	movs r2, #0x20
	bl FUN_08230ab0
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_0822E7BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822E7C0: .4byte 0x03000720
_0822E7C4: .4byte 0x030006A0
_0822E7C8: .4byte 0x02035C00
