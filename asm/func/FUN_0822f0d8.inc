	push {r4, lr}
	bl FUN_0822ee74
	adds r4, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	bl ClearMemory
	ldr r1, _0822F0FC @ =0x0400001C
	ldr r0, _0822F100 @ =0x030044A8
	ldr r0, [r0]
	cmp r0, #1
	beq _0822F120
	cmp r0, #1
	bgt _0822F104
	cmp r0, #0
	beq _0822F10E
	b _0822F13E
	.align 2, 0
_0822F0FC: .4byte 0x0400001C
_0822F100: .4byte 0x030044A8
_0822F104:
	cmp r0, #2
	beq _0822F130
	cmp r0, #3
	beq _0822F13C
	b _0822F13E
_0822F10E:
	ldr r0, _0822F11C @ =0x030044A0
	ldr r0, [r0]
	bl FUN_0822ee7c
	adds r1, r0, #0
	b _0822F13E
	.align 2, 0
_0822F11C: .4byte 0x030044A0
_0822F120:
	ldr r0, _0822F12C @ =0x030044A0
	ldr r0, [r0]
	bl FUN_0822eeb8
	adds r1, r0, #0
	b _0822F13E
	.align 2, 0
_0822F12C: .4byte 0x030044A0
_0822F130:
	bl FUN_0822ed10
	ldr r1, _0822F138 @ =0x0400004C
	b _0822F13E
	.align 2, 0
_0822F138: .4byte 0x0400004C
_0822F13C:
	ldr r1, _0822F160 @ =0x04000054
_0822F13E:
	ldr r0, _0822F164 @ =0x03003518
	str r4, [r0]
	ldr r0, _0822F168 @ =0x03002CA0
	str r1, [r0]
	ldr r1, _0822F16C @ =0x03003510
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0822F170 @ =0x03003514
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0822F174 @ =0x030044A4
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822F160: .4byte 0x04000054
_0822F164: .4byte 0x03003518
_0822F168: .4byte 0x03002CA0
_0822F16C: .4byte 0x03003510
_0822F170: .4byte 0x03003514
_0822F174: .4byte 0x030044A4
