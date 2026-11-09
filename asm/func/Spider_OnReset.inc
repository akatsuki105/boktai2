	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081301F4 @ =0x0000065C
	adds r0, r1, r2
	movs r2, #0
	strh r2, [r0]
	ldr r3, _081301F8 @ =0x0000065E
	adds r0, r1, r3
	strh r2, [r0]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r1, r1, r0
	strh r2, [r1]
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081301FC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08130204
	.align 2, 0
_081301F4: .4byte 0x0000065C
_081301F8: .4byte 0x0000065E
_081301FC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08130204:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08130228
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08130230
_08130228:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08130230:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08130268 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081302A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0813026C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08130260
	ldrb r0, [r4, #5]
_08130260:
	subs r0, #1
	strh r0, [r4, #8]
	b _0813027C
	.align 2, 0
_08130268: .4byte 0x0000FFFF
_0813026C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0813027C
	strh r1, [r4, #8]
_0813027C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081302A0
	movs r0, #1
	strb r0, [r4, #7]
_081302A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
