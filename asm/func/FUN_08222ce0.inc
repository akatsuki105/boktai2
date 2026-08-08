	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08222D28 @ =0x00000F08
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08222D2C @ =0x00000F0A
	adds r1, r4, r2
	movs r0, #0x32
	strh r0, [r1]
	ldr r1, _08222D30 @ =0x00000DC8
	adds r0, r4, r1
	movs r1, #0x8c
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _08222D34 @ =0x00000F04
	adds r2, r4, r0
	ldr r0, _08222D38 @ =0x00000DD4
	adds r1, r4, r0
	ldr r0, [r1]
	str r0, [r2]
	ldr r2, _08222D3C @ =0x00000EE4
	adds r0, r4, r2
	str r0, [r1]
	ldr r1, _08222D40 @ =0x00000F16
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #2
	bne _08222D48
	adds r2, #0x64
	adds r1, r4, r2
	ldr r0, _08222D44 @ =FUN_08222f0c
	b _08222D4E
	.align 2, 0
_08222D28: .4byte 0x00000F08
_08222D2C: .4byte 0x00000F0A
_08222D30: .4byte 0x00000DC8
_08222D34: .4byte 0x00000F04
_08222D38: .4byte 0x00000DD4
_08222D3C: .4byte 0x00000EE4
_08222D40: .4byte 0x00000F16
_08222D44: .4byte FUN_08222f0c
_08222D48:
	ldr r0, _08222D58 @ =0x00000F48
	adds r1, r4, r0
	ldr r0, _08222D5C @ =FUN_08222d60
_08222D4E:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08222D58: .4byte 0x00000F48
_08222D5C: .4byte FUN_08222d60
