	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204952
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #1
	strb r0, [r4]
_08204952:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _08204982
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0820498A
_08204982:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0820498A:
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
	beq _082049AE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082049B6
_082049AE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082049B6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082049F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08204A36
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082049FA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082049F4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204A10
	.align 2, 0
_082049F0: .4byte 0x0000FFFF
_082049F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204A0E
_082049FA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204A0E
	strh r1, [r4, #8]
	movs r2, #1
	b _08204A10
_08204A0E:
	movs r2, #0
_08204A10:
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
	bne _08204A38
	movs r0, #1
	strb r0, [r4, #7]
	b _08204A38
_08204A36:
	movs r2, #0
_08204A38:
	ldrh r1, [r5, #0x3c]
	movs r3, #0x3c
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _08204A46
	subs r0, r1, #1
	strh r0, [r5, #0x3c]
_08204A46:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _08204A5A
	cmp r2, #0
	beq _08204A5A
	adds r0, r5, #0
	movs r1, #1
	bl Entity08204cb8_SetElemState
_08204A5A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
