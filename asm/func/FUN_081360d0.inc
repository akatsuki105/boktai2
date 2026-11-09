	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _081360EC @ =0x00000B33
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081360F0
	subs r0, #1
	strb r0, [r1]
	b _08136130
	.align 2, 0
_081360EC: .4byte 0x00000B33
_081360F0:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08136138 @ =0x00000B3A
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #5
	adds r2, r2, r5
	ldr r0, _0813613C @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_0813a250
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _0813613C @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_0813a250
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0813a250
_08136130:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08136138: .4byte 0x00000B3A
_0813613C: .4byte 0x00000674
