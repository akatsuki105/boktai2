	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08092B24 @ =0x00003AEE
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08092B28 @ =0x00000F6C
	adds r2, r4, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r5]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r6, sp, #0x18
	ldr r1, _08092B2C @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _08092B30 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08092B34 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r1, _08092B38 @ =FUN_08092b3c
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092B24: .4byte 0x00003AEE
_08092B28: .4byte 0x00000F6C
_08092B2C: .4byte 0x00003AEB
_08092B30: .4byte 0x00003F9C
_08092B34: .4byte 0x00000F9E
_08092B38: .4byte FUN_08092b3c
