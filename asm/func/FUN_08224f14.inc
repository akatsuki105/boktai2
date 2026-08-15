	push {r4, lr}
	adds r4, r1, #0
	adds r3, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0xad
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08224F34
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #1
	b _08224F36
_08224F34:
	movs r0, #0
_08224F36:
	cmp r0, #0
	beq _08224F64
	ldr r0, _08224F6C @ =0x00000F0C
	adds r1, r3, r0
	ldr r2, [r1]
	cmp r2, #0
	beq _08224F50
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_08224F50:
	ldr r1, _08224F70 @ =FUN_08224dd0
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0xad
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224F64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08224F6C: .4byte 0x00000F0C
_08224F70: .4byte FUN_08224dd0
