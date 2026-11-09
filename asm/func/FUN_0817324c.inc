	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08173264 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173268
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817326A
	.align 2, 0
_08173264: .4byte 0x0000046C
_08173268:
	movs r0, #0
_0817326A:
	cmp r0, #0
	beq _081732A8
	ldr r4, _081732F0 @ =FUN_08171718
	movs r3, #0x25
	ldr r2, _081732F4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081732F8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081732A8:
	ldr r1, _081732F8 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08173304
	adds r0, r5, #0
	bl FUN_08175898
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081732FC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _08173300 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817330E
	.align 2, 0
_081732F0: .4byte FUN_08171718
_081732F4: .4byte 0x0000046D
_081732F8: .4byte 0x0000046B
_081732FC: .4byte 0x00000484
_08173300: .4byte 0xFFEFFFFF
_08173304:
	ldr r2, _08173314 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817330E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08173314: .4byte 0x00000484
