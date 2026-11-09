	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08180514 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180518
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818051A
	.align 2, 0
_08180514: .4byte 0x0000046D
_08180518:
	movs r0, #0
_0818051A:
	cmp r0, #0
	beq _08180526
	adds r0, r4, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
_08180526:
	ldr r1, _08180540 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180538
	ldr r0, _08180544 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08180538:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08180540: .4byte 0x0000046E
_08180544: .4byte 0x0000046B
