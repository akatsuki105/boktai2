	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08216190 @ =0x00000E8C
	adds r5, r4, r0
	ldr r1, _08216194 @ =0x000012B0
	adds r2, r4, r1
	ldr r0, [r2]
	lsls r0, r0, #5
	movs r6, #0
	strh r0, [r5, #0x22]
	ldr r1, _08216198 @ =0x00000EEC
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r2, [r2]
	adds r2, #0x4b
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [r5, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x68]
	str r6, [r4, #0x68]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08216190: .4byte 0x00000E8C
_08216194: .4byte 0x000012B0
_08216198: .4byte 0x00000EEC
