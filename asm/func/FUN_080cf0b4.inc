	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cef30
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #1
	str r0, [r4, #0x1c]
	ldr r1, _080CF144 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	str r5, [r0]
	ldr r2, [r1]
	adds r3, #4
	adds r0, r2, r3
	str r5, [r0]
	subs r3, #0x1c
	adds r0, r2, r3
	strh r5, [r0]
	ldr r0, [r1]
	ldr r1, _080CF148 @ =0x000002B2
	adds r0, r0, r1
	strh r5, [r0]
	adds r0, r4, #0
	bl FUN_080cef5c
	adds r0, r4, #0
	bl FUN_080cefcc
	adds r0, r4, #0
	bl FUN_080cf01c
	adds r0, r4, #0
	bl FUN_080cf040
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
	adds r0, r4, #0
	bl FUN_080cf064
	ldr r2, _080CF14C @ =0x00000442
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080CF150 @ =0x00000444
	adds r0, r4, r3
	strh r5, [r0]
	ldr r1, _080CF154 @ =0x00000446
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, [r4, #0x18]
	adds r2, #0x13
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x16
	adds r0, r4, r3
	strh r5, [r0]
	ldr r0, _080CF158 @ =0x0000045C
	adds r4, r4, r0
	str r5, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CF144: .4byte 0x030046A0
_080CF148: .4byte 0x000002B2
_080CF14C: .4byte 0x00000442
_080CF150: .4byte 0x00000444
_080CF154: .4byte 0x00000446
_080CF158: .4byte 0x0000045C
