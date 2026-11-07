	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0813F2C0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F2C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F2C6
	.align 2, 0
_0813F2C0: .4byte 0x0000046D
_0813F2C4:
	movs r0, #0
_0813F2C6:
	cmp r0, #0
	beq _0813F2D4
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl Enemy_PlayAnimWithVariant
_0813F2D4:
	ldr r1, _0813F2F8 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813F2F0
	subs r1, #3
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Show
_0813F2F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813F2F8: .4byte 0x0000046E
