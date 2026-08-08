	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807F12A
	movs r0, #6
	bl IsMagicUnlocked
	cmp r0, #0
	beq _0807F10A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807F0F0
	ldr r0, _0807F0EC @ =0x030046A0
	ldr r0, [r0]
	subs r1, #0x80
	b _0807F0FC
	.align 2, 0
_0807F0EC: .4byte 0x030046A0
_0807F0F0:
	cmp r0, #5
	beq _0807F10A
	ldr r0, _0807F130 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xb7
	lsls r1, r1, #2
_0807F0FC:
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0807F134 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0807F10A
	adds r0, r1, #1
	str r0, [r2]
_0807F10A:
	ldr r1, _0807F138 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _0807F130 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0807F134 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0807F12A
	adds r0, r1, #1
	str r0, [r2]
_0807F12A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807F130: .4byte 0x030046A0
_0807F134: .4byte 0x7FFFFFFE
_0807F138: .4byte 0x00000A75
