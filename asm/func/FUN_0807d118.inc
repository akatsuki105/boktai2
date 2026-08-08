	push {lr}
	adds r2, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #6
	beq _0807D12C
	movs r0, #0
	strb r0, [r1]
_0807D12C:
	ldr r1, _0807D158 @ =0x0000037D
	adds r0, r2, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0807D15C @ =0x0000037E
	adds r0, r2, r3
	movs r3, #0
	strh r1, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0807D14A
	strb r3, [r1]
_0807D14A:
	movs r0, #1
	str r0, [r2, #0x1c]
	ldr r1, _0807D160 @ =0x00000395
	adds r0, r2, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0807D158: .4byte 0x0000037D
_0807D15C: .4byte 0x0000037E
_0807D160: .4byte 0x00000395
