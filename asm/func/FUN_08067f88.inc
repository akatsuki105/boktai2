	push {lr}
	adds r3, r0, #0
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r3, r0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08067FD0
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08067FC8 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08067FCC @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08067FEE
	.align 2, 0
_08067FC8: .4byte 0x00000932
_08067FCC: .4byte 0x00000934
_08067FD0:
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08067FF4 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08067FF8 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08067FEE:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08067FF4: .4byte 0x00000932
_08067FF8: .4byte 0x00000934
