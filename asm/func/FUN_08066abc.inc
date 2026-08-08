	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08066B48 @ =0x000003CE
	adds r3, r4, r0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _08066B0C
	ldr r2, _08066B4C @ =0x03003540
	ldrh r0, [r2]
	ldrh r1, [r4, #0x2c]
	subs r0, r0, r1
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x2e]
	subs r0, r0, r1
	subs r0, #0x96
	adds r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #0x30]
	subs r0, r0, r1
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #1
	movs r0, #1
	strh r0, [r3]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08066a04
_08066B0C:
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08066B9E
	adds r0, r1, #0
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08066B50 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066B54
	asrs r3, r0, #0xc
	b _08066B5A
	.align 2, 0
_08066B48: .4byte 0x000003CE
_08066B4C: .4byte 0x03003540
_08066B50: .4byte 0x085B0A08
_08066B54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08066B5A:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066B7C
	asrs r2, r0, #0xc
	b _08066B82
_08066B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08066B82:
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r2, #0
	strh r0, [r1]
	movs r5, #0xf4
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08066a04
_08066B9E:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _08066BBA
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _08066C58
_08066BBA:
	ldr r2, _08066C20 @ =0x000003D1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08066C58
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	subs r5, #0xe4
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08066C44
	adds r0, r2, #0
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _08066C2C
	subs r0, r0, r1
	ldr r2, _08066C24 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08066C28 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08066C58
	.align 2, 0
_08066C20: .4byte 0x000003D1
_08066C24: .4byte 0x000002E6
_08066C28: .4byte 0x000002E7
_08066C2C:
	ldr r5, _08066C3C @ =0x000002E6
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _08066C40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _08066C58
	.align 2, 0
_08066C3C: .4byte 0x000002E6
_08066C40: .4byte 0x000002E7
_08066C44:
	cmp r0, #4
	bne _08066C52
	ldr r1, _08066C60 @ =0x00000387
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08066C58
_08066C52:
	adds r0, r4, #0
	bl FUN_080609dc
_08066C58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066C60: .4byte 0x00000387
