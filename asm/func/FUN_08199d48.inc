	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ldr r1, _08199D70 @ =0x00000111
	adds r3, r2, r1
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08199D74
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #1
	b _08199D76
	.align 2, 0
_08199D70: .4byte 0x00000111
_08199D74:
	movs r0, #0
_08199D76:
	cmp r0, #0
	beq _08199D84
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199D9C @ =FUN_0819936c
	str r0, [r1]
_08199D84:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199D96
	adds r0, r2, #0
	bl _call_via_r1
_08199D96:
	pop {r0}
	bx r0
	.align 2, 0
_08199D9C: .4byte FUN_0819936c
