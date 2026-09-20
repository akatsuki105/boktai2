	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_080cef14
	adds r0, r5, #0
	bl FUN_080cf0b4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cf3c0
	adds r0, r5, #0
	bl FUN_080cf560
	adds r0, r5, #0
	bl FUN_080ceec0
	adds r0, r5, #0
	bl FUN_080cf54c
	adds r0, r5, #0
	bl FUN_080cf610
	adds r0, r5, #0
	bl FUN_080ce378
	ldr r1, _080D8280 @ =0x03002BC0
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x1c]
	str r1, [r0]
	ldr r0, _080D8284 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D8288
	movs r1, #1
	rsbs r1, r1, #0
	b _080D828C
	.align 2, 0
_080D8280: .4byte 0x03002BC0
_080D8284: .4byte 0x03002C68
_080D8288:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D828C:
	ldr r0, [r5, #0x18]
	cmp r0, r1
	bne _080D82BE
	ldr r1, _080D82DC @ =0x030046A0
	ldr r2, [r1]
	ldrh r0, [r5, #0x2c]
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldrh r0, [r5, #0x2e]
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	ldrh r0, [r5, #0x30]
	strh r0, [r2, #0x34]
	ldr r2, [r1]
	ldr r0, _080D82E0 @ =0x00000932
	adds r2, r2, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
_080D82BE:
	ldr r1, _080D82E4 @ =0x03002BE0
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r0]
	ldr r1, _080D82E8 @ =0x03002B98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D82DC: .4byte 0x030046A0
_080D82E0: .4byte 0x00000932
_080D82E4: .4byte 0x03002BE0
_080D82E8: .4byte 0x03002B98
