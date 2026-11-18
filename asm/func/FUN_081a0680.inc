	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081A06E8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A069A
	movs r0, #0
	strb r0, [r1]
_081A069A:
	ldr r1, _081A06EC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0700
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A06F0 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	ldr r1, _081A06F4 @ =0x00000E48
	adds r2, r6, r1
	ldr r1, _081A06F8 @ =0xFFFFFBFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A06FC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A070A
	.align 2, 0
_081A06E8: .4byte 0x0000046C
_081A06EC: .4byte 0x0000046B
_081A06F0: .4byte 0xFFFFFEFF
_081A06F4: .4byte 0x00000E48
_081A06F8: .4byte 0xFFFFFBFF
_081A06FC: .4byte 0x00000484
_081A0700:
	ldr r0, _081A0710 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A070A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A0710: .4byte 0x00000484
