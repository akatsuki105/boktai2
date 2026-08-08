	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08073E68 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08073E28
	b _08073F3C
_08073E28:
	cmp r0, #1
	ble _08073E2E
	b _08073F82
_08073E2E:
	cmp r0, #0
	beq _08073E34
	b _08073F82
_08073E34:
	ldr r2, _08073E6C @ =0x0000037E
	adds r0, r5, r2
	ldrh r3, [r0]
	cmp r3, #0
	bne _08073EA6
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08073E74
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073E70 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r4, #1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _08073E82
	.align 2, 0
_08073E68: .4byte 0x0000037D
_08073E6C: .4byte 0x0000037E
_08073E70: .4byte 0x000002E6
_08073E74:
	lsrs r0, r1, #0x19
	ldr r2, _08073ED8 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r4, _08073EDC @ =0x000002E7
	adds r0, r5, r4
	strb r3, [r0]
_08073E82:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #5
	beq _08073EA6
	movs r0, #0xe7
	bl PlaySound_082406e0
_08073EA6:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073EE0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _08073EE4 @ =0x000004A4
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073EE8
	asrs r0, r0, #0xc
	b _08073EEE
	.align 2, 0
_08073ED8: .4byte 0x000002E6
_08073EDC: .4byte 0x000002E7
_08073EE0: .4byte 0x085B0A08
_08073EE4: .4byte 0x000004A4
_08073EE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073EEE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, _08073F0C @ =0x000004A4
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073F10
	asrs r0, r0, #0xc
	b _08073F16
	.align 2, 0
_08073F0C: .4byte 0x000004A4
_08073F10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073F16:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08073F38 @ =0x000004A4
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	bne _08073F82
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #1
	bl FUN_08060b84
	b _08073F82
	.align 2, 0
_08073F38: .4byte 0x000004A4
_08073F3C:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _08073F56
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073F56
	movs r0, #0xd1
	bl PlaySound_082406e0
_08073F56:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073F82
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #2
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
_08073F82:
	pop {r4, r5}
	pop {r0}
	bx r0
