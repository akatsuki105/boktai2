	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08148C18 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08148C1C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08148C1E
	.align 2, 0
_08148C18: .4byte 0x0000046C
_08148C1C:
	movs r0, #0
_08148C1E:
	cmp r0, #0
	beq _08148C58
	adds r0, r4, #0
	bl FUN_081486d8
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08148C50 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08148C54 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08148C62
	.align 2, 0
_08148C50: .4byte 0x00000469
_08148C54: .4byte 0x00000484
_08148C58:
	ldr r0, _08148C68 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08148C62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08148C68: .4byte 0x00000484
