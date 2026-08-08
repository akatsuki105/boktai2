	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	ldr r0, _08217D00 @ =0x0000166C
	adds r6, r4, r0
	ldr r1, _08217D04 @ =0x00001FDE
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, _08217D08 @ =0x00000938
	adds r0, r0, r1
	adds r5, r6, r0
	movs r3, #0xff
	lsls r3, r3, #5
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08217D0C
	movs r3, #0xbd
	lsls r3, r3, #5
	adds r0, r4, r3
	b _08217D10
	.align 2, 0
_08217D00: .4byte 0x0000166C
_08217D04: .4byte 0x00001FDE
_08217D08: .4byte 0x00000938
_08217D0C:
	ldr r1, _08217D3C @ =0x0000179C
	adds r0, r4, r1
_08217D10:
	ldr r0, [r0]
	bl FUN_08231660
	adds r0, r0, r7
	bl FUN_08231978
	ldrb r1, [r0]
	strb r1, [r5]
	ldrb r0, [r0, #1]
	strb r0, [r5, #1]
	ldr r3, _08217D40 @ =0x00000972
	adds r1, r6, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	bgt _08217D44
	adds r0, r2, #1
	strh r0, [r1]
	movs r5, #0
	b _08217D46
	.align 2, 0
_08217D3C: .4byte 0x0000179C
_08217D40: .4byte 0x00000972
_08217D44:
	movs r5, #1
_08217D46:
	adds r0, r4, #0
	bl FUN_08217bfc
	adds r0, r4, #0
	bl FUN_08217b48
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
