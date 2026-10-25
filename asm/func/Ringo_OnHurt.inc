	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08027FDC
	adds r0, r4, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldrh r1, [r6, #0x3e]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _08027FA4
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r3, _08027FA0 @ =0x00000179
	adds r1, r5, r3
	b _08027FC0
	.align 2, 0
_08027FA0: .4byte 0x00000179
_08027FA4:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r2, _08028010 @ =0x00000179
	adds r1, r5, r2
_08027FC0:
	strb r0, [r1]
	ldr r1, [r4, #0x34]
	adds r0, r7, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r4, #0x38]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xde
	ldrh r0, [r4, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3e]
_08027FDC:
	movs r2, #1
	ldr r0, [r4, #0x38]
	ands r0, r2
	cmp r0, #0
	beq _08027FEE
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
_08027FEE:
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0802801C
	ldr r1, _08028014 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _08028018 @ =0x00000177
	adds r0, r5, r3
	strb r2, [r0]
	b _08028022
	.align 2, 0
_08028010: .4byte 0x00000179
_08028014: .4byte 0x00000167
_08028018: .4byte 0x00000177
_0802801C:
	ldr r2, _08028028 @ =0x00000177
	adds r1, r5, r2
	strb r0, [r1]
_08028022:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028028: .4byte 0x00000177
