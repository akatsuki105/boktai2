	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0812FDE0 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FDE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FDE6
	.align 2, 0
_0812FDE0: .4byte 0x0000046C
_0812FDE4:
	movs r0, #0
_0812FDE6:
	cmp r0, #0
	beq _0812FE1A
	ldr r3, _0812FE44 @ =0x000005A4
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #0
	ldr r4, _0812FE48 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r7, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	subs r4, #0xf6
	adds r0, r7, r4
	strh r2, [r0]
_0812FE1A:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FE30
	b _0813005C
_0812FE30:
	movs r1, #4
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FE4C
	movs r0, #1
	b _0812FE4E
	.align 2, 0
_0812FE44: .4byte 0x000005A4
_0812FE48: .4byte 0x0000046D
_0812FE4C:
	movs r0, #0
_0812FE4E:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812FEF0
	adds r0, r7, #0
	movs r1, #0x40
	movs r2, #0x40
	bl Spider_IsCoffinInRange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FEE8
	ldr r2, _0812FED0 @ =0x00000482
	adds r1, r7, r2
	movs r4, #0
	movs r5, #0
	movs r6, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl Spider_PickRandomPathNode
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	ldr r0, _0812FED4 @ =0x0000065E
	add r0, r8
	strh r5, [r0]
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _0812FED8 @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0812FEDC @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r6, [r0]
	ldr r2, _0812FEE0 @ =FUN_0812ef50
	movs r1, #0x21
	adds r3, #3
	adds r0, r7, r3
	strb r6, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	ldr r4, _0812FEE4 @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	b _0813005C
	.align 2, 0
_0812FED0: .4byte 0x00000482
_0812FED4: .4byte 0x0000065E
_0812FED8: .4byte 0x00000469
_0812FEDC: .4byte 0x00000484
_0812FEE0: .4byte FUN_0812ef50
_0812FEE4: .4byte 0x00000553
_0812FEE8:
	adds r0, r7, #0
	bl FUN_08130508
	b _0813005C
_0812FEF0:
	ldr r3, _0812FF40 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0812FEFC
	b _08130058
_0812FEFC:
	adds r0, r7, #0
	bl Spider_PickRandomPathNode
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0812FF58
	ldr r6, _0812FF44 @ =0x030046B8
	ldr r0, [r6]
	adds r5, r0, #1
	ldr r2, _0812FF48 @ =0x000003FF
	mov ip, r2
	ands r5, r2
	str r5, [r6]
	lsls r0, r5, #1
	ldr r3, _0812FF4C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0812FF54
	movs r1, #0xf
	adds r2, #0x69
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812FF50 @ =0x00000469
	b _0812FF82
	.align 2, 0
_0812FF40: .4byte 0x00000484
_0812FF44: .4byte 0x030046B8
_0812FF48: .4byte 0x000003FF
_0812FF4C: .4byte 0x0203B400
_0812FF50: .4byte 0x00000469
_0812FF54:
	movs r1, #7
	b _08130000
_0812FF58:
	ldr r6, _0812FFE4 @ =0x030046B8
	ldr r0, [r6]
	adds r5, r0, #1
	ldr r3, _0812FFE8 @ =0x000003FF
	mov ip, r3
	ands r5, r3
	str r5, [r6]
	lsls r0, r5, #1
	ldr r1, _0812FFEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08130000
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x6a
_0812FF82:
	adds r0, r7, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r4, [r0]
	ldr r1, _0812FFF0 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0812FFF4 @ =FUN_0812ef50
	mov sb, r2
	movs r2, #0x21
	subs r3, #0x17
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0812FFF8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r5, #1
	mov r4, ip
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _0812FFEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x3c
	ldr r1, _0812FFFC @ =0x0000065E
	add r1, r8
	strh r0, [r1]
	b _0813005C
	.align 2, 0
_0812FFE4: .4byte 0x030046B8
_0812FFE8: .4byte 0x000003FF
_0812FFEC: .4byte 0x0203B400
_0812FFF0: .4byte 0x0000046C
_0812FFF4: .4byte FUN_0812ef50
_0812FFF8: .4byte 0x0000046B
_0812FFFC: .4byte 0x0000065E
_08130000:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08130050 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r4, [r0]
	ldr r1, _08130054 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	subs r3, #0x17
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _0813005C
	.align 2, 0
_08130050: .4byte 0x00000469
_08130054: .4byte 0x0000046C
_08130058:
	adds r0, #1
	str r0, [r1]
_0813005C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
