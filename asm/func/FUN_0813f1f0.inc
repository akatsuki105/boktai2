	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F210 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F214
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F216
	.align 2, 0
_0813F210: .4byte 0x0000046D
_0813F214:
	movs r0, #0
_0813F216:
	adds r6, r0, #0
	cmp r6, #0
	beq _0813F234
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r1, [r4, #5]
	ldr r2, _0813F230 @ =0x00000661
	adds r0, r5, r2
	strb r1, [r0]
	b _0813F25E
	.align 2, 0
_0813F230: .4byte 0x00000661
_0813F234:
	adds r0, r4, #0
	bl FUN_08140dd0
	ldr r0, _0813F254 @ =0x00000661
	adds r5, r5, r0
	ldrb r0, [r5]
	ldrb r1, [r4, #5]
	cmp r0, r1
	beq _0813F258
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F25E
	.align 2, 0
_0813F254: .4byte 0x00000661
_0813F258:
	ldr r2, _0813F264 @ =0x0000046E
	adds r0, r4, r2
	strb r6, [r0]
_0813F25E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813F264: .4byte 0x0000046E
