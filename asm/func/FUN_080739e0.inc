	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080739F8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080739FC
	cmp r0, #1
	bne _080739F4
	b _08073B08
_080739F4:
	b _08073B36
	.align 2, 0
_080739F8: .4byte 0x0000037D
_080739FC:
	ldr r2, _08073A30 @ =0x0000037E
	adds r0, r4, r2
	ldrh r3, [r0]
	cmp r3, #0
	bne _08073A6E
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08073A38
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073A34 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _08073A46
	.align 2, 0
_08073A30: .4byte 0x0000037E
_08073A34: .4byte 0x000002E6
_08073A38:
	lsrs r0, r1, #0x19
	ldr r2, _08073AA0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r5, _08073AA4 @ =0x000002E7
	adds r0, r4, r5
	strb r3, [r0]
_08073A46:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r2, _08073AA8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08073A6E:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073AAC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r5, _08073AB0 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073AB4
	asrs r0, r0, #0xc
	b _08073ABA
	.align 2, 0
_08073AA0: .4byte 0x000002E6
_08073AA4: .4byte 0x000002E7
_08073AA8: .4byte 0x0000037E
_08073AAC: .4byte 0x085B0A08
_08073AB0: .4byte 0x000004A4
_08073AB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073ABA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073AD8 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073ADC
	asrs r0, r0, #0xc
	b _08073AE2
	.align 2, 0
_08073AD8: .4byte 0x000004A4
_08073ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073AE2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r0, _08073B04 @ =0x000004A4
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	bne _08073B36
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #1
	bl FUN_08060b84
	b _08073B36
	.align 2, 0
_08073B04: .4byte 0x000004A4
_08073B08:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073B36
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08073B36:
	pop {r4, r5}
	pop {r0}
	bx r0
