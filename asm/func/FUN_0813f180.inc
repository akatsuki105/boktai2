	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F1A0 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F1A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F1A6
	.align 2, 0
_0813F1A0: .4byte 0x0000046D
_0813F1A4:
	movs r0, #0
_0813F1A6:
	adds r1, r0, #0
	cmp r1, #0
	beq _0813F1C0
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r1, [r4, #5]
	ldr r2, _0813F1BC @ =0x00000661
	adds r0, r5, r2
	b _0813F1E4
	.align 2, 0
_0813F1BC: .4byte 0x00000661
_0813F1C0:
	ldr r0, _0813F1DC @ =0x00000661
	adds r5, r5, r0
	ldrb r0, [r5]
	ldrb r2, [r4, #5]
	cmp r0, r2
	beq _0813F1E0
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F1E6
	.align 2, 0
_0813F1DC: .4byte 0x00000661
_0813F1E0:
	ldr r2, _0813F1EC @ =0x0000046E
	adds r0, r4, r2
_0813F1E4:
	strb r1, [r0]
_0813F1E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813F1EC: .4byte 0x0000046E
