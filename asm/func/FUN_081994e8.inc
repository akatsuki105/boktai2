	push {lr}
	adds r2, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _0819955C @ =0x00000CEC
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0819951E
	ldr r0, _08199560 @ =0x00000185
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08199516
	rsbs r0, r0, #0
_08199516:
	cmp r0, #0xf
	ble _0819951E
	movs r0, #0xf1
	strb r0, [r1]
_0819951E:
	ldr r1, _08199560 @ =0x00000185
	adds r3, r2, r1
	ldrb r0, [r3]
	ldrb r1, [r2, #6]
	adds r0, r0, r1
	strb r0, [r2, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _08199556
	movs r0, #0
	str r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08199548
	rsbs r0, r0, #0
_08199548:
	cmp r0, #0xf
	bne _08199556
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199564 @ =FUN_08199568
	str r0, [r1]
_08199556:
	pop {r0}
	bx r0
	.align 2, 0
_0819955C: .4byte 0x00000CEC
_08199560: .4byte 0x00000185
_08199564: .4byte FUN_08199568
