	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _08136CC4 @ =0x00000B38
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _08136CCC
	strh r1, [r0]
	ldr r0, _08136CC8 @ =0x00000B34
	adds r1, r2, r0
	movs r0, #0xff
	b _08136CDA
	.align 2, 0
_08136CC4: .4byte 0x00000B38
_08136CC8: .4byte 0x00000B34
_08136CCC:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _08136CDC
	strh r1, [r0]
	ldr r3, _08136CF8 @ =0x00000B34
	adds r1, r2, r3
	movs r0, #1
_08136CDA:
	strb r0, [r1]
_08136CDC:
	ldr r5, _08136CFC @ =0x00000B38
	adds r1, r2, r5
	ldr r3, _08136CF8 @ =0x00000B34
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08136CF8: .4byte 0x00000B34
_08136CFC: .4byte 0x00000B38
