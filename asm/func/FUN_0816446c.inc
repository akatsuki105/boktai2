	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r1, _08164500 @ =0x000004A4
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r0, _08164504 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r3, #0xc]
	str r1, [r3, #0x10]
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r0, r2, r6
	ldr r1, _08164508 @ =0x0000065A
	adds r2, r2, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	cmp r0, r2
	blo _081644FA
	ldr r3, _0816450C @ =FUN_08163604
	movs r1, #0x29
	ldr r2, _08164510 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08164514 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08164518 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0816451C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
_081644FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08164500: .4byte 0x000004A4
_08164504: .4byte 0x03002BE0
_08164508: .4byte 0x0000065A
_0816450C: .4byte FUN_08163604
_08164510: .4byte 0x0000046D
_08164514: .4byte 0x0000046B
_08164518: .4byte 0x00000469
_0816451C: .4byte 0x0000046C
