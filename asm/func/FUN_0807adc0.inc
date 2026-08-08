	push {lr}
	adds r2, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #0x1a
	bne _0807ADE4
	ldr r1, _0807ADE0 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1a
	b _0807AE22
	.align 2, 0
_0807ADE0: .4byte 0x0000037D
_0807ADE4:
	cmp r1, #0x1b
	bne _0807AE04
	ldr r1, _0807AE00 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1b
	movs r2, #5
	bl FUN_08060b84
	b _0807AE62
	.align 2, 0
_0807AE00: .4byte 0x0000037D
_0807AE04:
	cmp r1, #0x1f
	bne _0807AE44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807AE2A
	adds r1, #0x25
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1f
_0807AE22:
	movs r2, #4
	bl FUN_08060b84
	b _0807AE62
_0807AE2A:
	ldr r1, _0807AE40 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1f
	movs r2, #2
	bl FUN_08060b84
	b _0807AE62
	.align 2, 0
_0807AE40: .4byte 0x0000037D
_0807AE44:
	ldr r0, [r2, #0x1c]
	cmp r0, #2
	bne _0807AE62
	cmp r1, #0x12
	bne _0807AE62
	ldr r1, _0807AE68 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x12
	movs r2, #4
	bl FUN_08060b84
_0807AE62:
	pop {r0}
	bx r0
	.align 2, 0
_0807AE68: .4byte 0x0000037D
