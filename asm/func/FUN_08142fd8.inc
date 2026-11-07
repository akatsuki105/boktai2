	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08143000 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08142FEA
	movs r0, #0
	strb r0, [r1]
_08142FEA:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	adds r0, r4, #0
	bl FUN_08144b70
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08143000: .4byte 0x0000046D
