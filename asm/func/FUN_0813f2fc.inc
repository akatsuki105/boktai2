	push {lr}
	adds r2, r0, #0
	ldr r0, _0813F31C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F30E
	movs r0, #0
	strb r0, [r1]
_0813F30E:
	adds r0, r2, #0
	movs r1, #0
	bl Enemy_PlayAnim
	pop {r0}
	bx r0
	.align 2, 0
_0813F31C: .4byte 0x0000046D
