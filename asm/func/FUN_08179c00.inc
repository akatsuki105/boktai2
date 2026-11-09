	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x40
	adds r2, r4, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldr r0, _08179C2C @ =0x00000103
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08179C2C: .4byte 0x00000103
