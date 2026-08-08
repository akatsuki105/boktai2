	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807108E
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08071092
_0807108E:
	movs r5, #0x30
	b _08071094
_08071092:
	movs r5, #0x40
_08071094:
	ldr r1, _080710A8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080710DC
	cmp r0, #1
	bgt _080710AC
	cmp r0, #0
	beq _080710B6
	b _08071210
	.align 2, 0
_080710A8: .4byte 0x0000037D
_080710AC:
	cmp r0, #4
	beq _08071134
	cmp r0, #5
	beq _08071170
	b _08071210
_080710B6:
	adds r0, r4, #0
	bl FUN_0806f780
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _080710DA
	b _08071210
_080710DA:
	b _080711EE
_080710DC:
	adds r0, r4, #0
	bl FUN_0806f780
	adds r0, r4, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071124
	adds r0, r4, #0
	bl FUN_08070adc
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071210
_08071124:
	ldr r0, _08071130 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08071210
	.align 2, 0
_08071130: .4byte 0x0000037E
_08071134:
	ldr r2, _0807116C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_08070db4
	cmp r0, #0
	beq _08071210
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071210
	.align 2, 0
_0807116C: .4byte 0x000003D1
_08071170:
	ldr r2, _080711FC @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071192
	ldr r2, _08071200 @ =0x00000A76
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_08071192:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080711C4
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _080711C4
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080711C4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x2c
	adds r0, r4, #0
	bl FUN_08061a98
_080711C4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08071210
	ldr r2, _08071200 @ =0x00000A76
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08071204
	movs r0, #0
	strb r0, [r1]
_080711EE:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071210
	.align 2, 0
_080711FC: .4byte 0x000003D1
_08071200: .4byte 0x00000A76
_08071204:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071210:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
