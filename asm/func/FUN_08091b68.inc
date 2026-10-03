	push {lr}
	ldr r1, _08091B8C @ =0x00003F9D
	adds r0, r0, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08091B98
	ldr r2, _08091B90 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08091B94 @ =0x000002B2
	adds r0, r0, r1
	strh r3, [r0]
	b _08091BB0
	.align 2, 0
_08091B8C: .4byte 0x00003F9D
_08091B90: .4byte 0x030046A0
_08091B94: .4byte 0x000002B2
_08091B98:
	ldr r2, _08091BB4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08091BB8 @ =0x000002B2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
_08091BB0:
	pop {r0}
	bx r0
	.align 2, 0
_08091BB4: .4byte 0x030046A0
_08091BB8: .4byte 0x000002B2
