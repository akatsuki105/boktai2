	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08211838 @ =0x0000086A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _082117DC
	b _082119B8
_082117DC:
	movs r6, #0
	movs r7, #0
	ldr r0, _0821183C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08211808
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x27
	ldrb r1, [r5]
	subs r1, #1
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_08211188
	cmp r0, #0
	bne _08211868
_08211808:
	ldr r0, _0821183C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08211840
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x27
	ldrb r1, [r5]
	adds r1, #1
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_08211188
	cmp r0, #0
	beq _08211840
	ldrb r0, [r5]
	adds r0, #1
	b _0821186C
	.align 2, 0
_08211838: .4byte 0x0000086A
_0821183C: .4byte 0x030044E0
_08211840:
	ldr r0, _08211878 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0821187C
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r0, [r5]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_08211188
	cmp r0, #0
	beq _0821187C
_08211868:
	ldrb r0, [r5]
	subs r0, #1
_0821186C:
	strb r0, [r5]
	movs r6, #1
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _082118B2
	.align 2, 0
_08211878: .4byte 0x030044E0
_0821187C:
	ldr r0, _082118D4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082118B2
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r0, [r5]
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_08211188
	cmp r0, #0
	beq _082118B2
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	movs r6, #1
	movs r0, #0xdc
	bl PlaySound_082406e0
_082118B2:
	ldr r0, _082118D4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _082118F6
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0
	beq _082118D8
	subs r0, #1
	b _082118DA
	.align 2, 0
_082118D4: .4byte 0x030044E0
_082118D8:
	movs r0, #2
_082118DA:
	strb r0, [r1]
	movs r7, #1
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r6, #1
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0821192A
_082118F6:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0821192A
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08211910
	adds r0, #1
	strb r0, [r1]
	b _08211912
_08211910:
	strb r2, [r1]
_08211912:
	movs r7, #1
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r6, #1
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0821192A:
	cmp r6, #0
	bne _08211932
	cmp r7, #0
	beq _08211972
_08211932:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	bl FUN_08211164
	adds r1, r4, #0
	adds r1, #0x26
	ldrb r1, [r1]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x25
	strb r1, [r0]
	cmp r7, #0
	beq _08211972
	adds r0, r4, #0
	bl FUN_08211378
	adds r0, r4, #0
	bl FUN_08211640
	adds r0, r4, #0
	bl FUN_08211730
	adds r0, r4, #0
	bl FUN_0821126c
_08211972:
	cmp r6, #0
	beq _08211982
	adds r0, r4, #0
	bl FUN_08211300
	adds r0, r4, #0
	bl FUN_082111cc
_08211982:
	ldr r0, _082119C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _082119AC
	ldr r1, _082119C4 @ =0x0000087C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0821199E
	movs r1, #0
	bl FUN_082318ac
_0821199E:
	ldr r0, _082119C8 @ =0x00000119
	bl PlaySound_082406e0
	ldr r0, _082119CC @ =0x0000086A
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
_082119AC:
	adds r0, r4, #0
	bl FUN_08211324
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
_082119B8:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082119C0: .4byte 0x030044E0
_082119C4: .4byte 0x0000087C
_082119C8: .4byte 0x00000119
_082119CC: .4byte 0x0000086A
