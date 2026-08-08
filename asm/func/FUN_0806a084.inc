	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806A110
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A0D0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _0806A0C8 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _0806A0CC @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0806A0E0
	.align 2, 0
_0806A0C8: .4byte 0x000002E6
_0806A0CC: .4byte 0x000002E7
_0806A0D0:
	lsrs r1, r1, #0x19
	ldr r2, _0806A14C @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0806A150 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_0806A0E0:
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0806A154 @ =0x000003F6
	adds r0, r5, r1
	movs r6, #0
	strh r6, [r0]
	ldr r2, _0806A158 @ =0x000003D6
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806A110
	bl PlaySound_082406e0
	strh r6, [r4]
_0806A110:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r3, r5, r6
	ldrh r0, [r3]
	cmp r0, #0
	bne _0806A11E
	b _0806A2B6
_0806A11E:
	ldr r1, _0806A15C @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A1AC
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806A160
	asrs r0, r3, #3
	b _0806A166
	.align 2, 0
_0806A14C: .4byte 0x000002E6
_0806A150: .4byte 0x000002E7
_0806A154: .4byte 0x000003F6
_0806A158: .4byte 0x000003D6
_0806A15C: .4byte 0x00000395
_0806A160:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A166:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806A170
	asrs r0, r1, #3
	b _0806A176
_0806A170:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A176:
	strh r0, [r5, #0x38]
	ldr r3, _0806A1A4 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bls _0806A184
	b _0806A29E
_0806A184:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806A19A
	ldr r0, _0806A1A8 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_0806A19A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0806A29E
	.align 2, 0
_0806A1A4: .4byte 0x0000037E
_0806A1A8: .4byte 0x00000191
_0806A1AC:
	ldr r6, _0806A1DC @ =0x00000397
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A23C
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806A1E0
	asrs r0, r3, #3
	b _0806A1E6
	.align 2, 0
_0806A1DC: .4byte 0x00000397
_0806A1E0:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A1E6:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806A1F0
	asrs r0, r1, #3
	b _0806A1F6
_0806A1F0:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A1F6:
	strh r0, [r5, #0x38]
	ldr r3, _0806A234 @ =0x0000037E
	adds r6, r5, r3
	ldrh r0, [r6]
	cmp r0, #5
	bhi _0806A29E
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _0806A22A
	ldr r0, _0806A238 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
_0806A22A:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b _0806A29E
	.align 2, 0
_0806A234: .4byte 0x0000037E
_0806A238: .4byte 0x00000191
_0806A23C:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806A26C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A270
	asrs r0, r0, #0xc
	b _0806A276
	.align 2, 0
_0806A26C: .4byte 0x085B0A08
_0806A270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A276:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A294
	asrs r0, r0, #0xc
	b _0806A29A
_0806A294:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A29A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_0806A29E:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _0806A324
_0806A2B6:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _0806A2E8 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806A2EC @ =0x00000397
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0806A2F0 @ =0x000004C5
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806A2F8
	ldr r1, _0806A2F4 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A2F8
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806A324
	.align 2, 0
_0806A2E8: .4byte 0x00000395
_0806A2EC: .4byte 0x00000397
_0806A2F0: .4byte 0x000004C5
_0806A2F4: .4byte 0x000004C7
_0806A2F8:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A324
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A324:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
