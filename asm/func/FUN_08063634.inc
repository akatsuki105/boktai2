	push {r4, lr}
	adds r3, r0, #0
	lsls r2, r1, #1
	ldr r4, _0806365C @ =0x0000043C
	adds r0, r3, r4
	adds r0, r0, r2
	movs r2, #0
	strh r2, [r0]
	cmp r1, #2
	bne _08063654
	ldr r0, _08063660 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x10]
	ldr r2, _08063664 @ =0x00000456
	adds r0, r3, r2
	strb r1, [r0]
_08063654:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806365C: .4byte 0x0000043C
_08063660: .4byte 0x030046A0
_08063664: .4byte 0x00000456
