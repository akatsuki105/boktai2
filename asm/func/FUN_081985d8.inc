	push {lr}
	adds r1, r0, #0
	movs r0, #0x80
	strb r0, [r1, #6]
	movs r0, #0x7f
	strb r0, [r1, #8]
	movs r0, #1
	strb r0, [r1, #9]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0xf8
	strb r0, [r2]
	adds r0, #0x8f
	adds r2, r1, r0
	movs r0, #0x10
	strb r0, [r2]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, _08198610 @ =FUN_08198618
	str r0, [r1]
	ldr r0, _08198614 @ =0x0000016D
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_08198610: .4byte FUN_08198618
_08198614: .4byte 0x0000016D
