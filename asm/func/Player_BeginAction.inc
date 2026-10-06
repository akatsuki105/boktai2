	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	ldr r1, _08060C2C @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _08060C30 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08060BE0
	adds r0, r4, #0
	bl FUN_0809e138
	cmp r0, #0
	beq _08060BE0
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08060BE0:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08060BFC
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08060BFC:
	ldr r1, _08060C34 @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08060C38 @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08060C3C @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060C2C: .4byte 0x0000038E
_08060C30: .4byte 0x030046A0
_08060C34: .4byte 0x00000604
_08060C38: .4byte 0x00000606
_08060C3C: .4byte 0x0000035A
