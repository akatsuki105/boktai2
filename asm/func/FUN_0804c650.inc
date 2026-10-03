	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C668
	movs r0, #0
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	strb r0, [r1]
_0804C668:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C694 @ =0x08251D40
	movs r0, #0
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C698
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	subs r0, #2
	b _0804C6A4
	.align 2, 0
_0804C694: .4byte 0x08251D40
_0804C698:
	movs r1, #8
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C6A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
