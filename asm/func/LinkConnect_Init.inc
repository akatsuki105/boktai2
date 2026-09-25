	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _081D9CE0 @ =0x03002C64
	str r4, [r0]
	bl SuspendSunlight
	ldr r1, _081D9CE4 @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	bl Sio_Reset
	bl FUN_08238b04
	cmp r5, #0
	bne _081D9CE8
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r4, #0x18]
	b _081D9CEA
	.align 2, 0
_081D9CE0: .4byte 0x03002C64
_081D9CE4: .4byte 0x0300481C
_081D9CE8:
	str r5, [r4, #0x18]
_081D9CEA:
	str r6, [r4, #0x1c]
	movs r1, #0
	str r1, [r4, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	str r1, [r4, #0x34]
	str r1, [r4, #0x38]
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	adds r2, r4, #0
	adds r2, #0x5c
	movs r0, #0xc9
	lsls r0, r0, #1
	strh r0, [r2]
	adds r2, #2
	ldr r0, _081D9D34 @ =0x0000FFFF
	strh r0, [r2]
	adds r2, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	str r1, [r4, #0x70]
	str r1, [r4, #0x68]
	str r1, [r4, #0x6c]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D9D34: .4byte 0x0000FFFF
