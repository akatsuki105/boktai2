	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C58E
	movs r0, #0
	strb r0, [r5]
_0804C58E:
	ldr r0, [r4, #0x44]
	cmp r0, #0x3b
	bls _0804C5B2
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl rfu_LMAN_initializeRFU
	ldr r1, _0804C5BC @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
_0804C5B2:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C5BC: .4byte 0x030000DC
