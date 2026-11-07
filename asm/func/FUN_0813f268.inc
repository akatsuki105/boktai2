	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0813F280 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F284
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F286
	.align 2, 0
_0813F280: .4byte 0x0000046D
_0813F284:
	movs r0, #0
_0813F286:
	cmp r0, #0
	beq _0813F294
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl Enemy_PlayAnimWithVariant
_0813F294:
	ldr r0, _0813F2A4 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813F2A4: .4byte 0x0000046E
