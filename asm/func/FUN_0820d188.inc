	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0820d0ec
	cmp r0, #0
	beq _0820D1B4
	ldr r0, _0820D1AC @ =0x00000F14
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820D1B0 @ =0x00000F74
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	b _0820D1C8
	.align 2, 0
_0820D1AC: .4byte 0x00000F14
_0820D1B0: .4byte 0x00000F74
_0820D1B4:
	ldr r0, _0820D1F8 @ =0x00000F14
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820D1FC @ =0x00000F74
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
_0820D1C8:
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0820D210
	cmp r0, #0
	bne _0820D204
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	bl FUN_0820d084
	cmp r0, #0
	beq _0820D204
	ldr r1, _0820D200 @ =0x00000FD4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0820D20E
	.align 2, 0
_0820D1F8: .4byte 0x00000F14
_0820D1FC: .4byte 0x00000F74
_0820D200: .4byte 0x00000FD4
_0820D204:
	ldr r1, _0820D218 @ =0x00000FD4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0820D20E:
	str r1, [r0]
_0820D210:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820D218: .4byte 0x00000FD4
