	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C8CE
	movs r1, #0
	strb r1, [r5]
_0804C8CE:
	ldr r2, [r4, #0x44]
	ldr r1, _0804C8F0 @ =0x00000257
	cmp r2, r1
	bls _0804C8EA
	movs r0, #0
	bl rfu_LMAN_stopManager
	movs r2, #4
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C8EA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C8F0: .4byte 0x00000257
