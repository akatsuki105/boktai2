	push {r4, r5, lr}
	ldr r2, _08241A3C @ =0x030046A0
	ldr r3, [r2]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _08241A40 @ =0x0000752F
	adds r4, r2, #0
	cmp r1, r0
	ble _08241AB8
	ldr r2, _08241A44 @ =0x00000942
	adds r0, r3, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	ble _08241A88
	movs r1, #0x84
	lsls r1, r1, #7
	subs r2, #0xe
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08241A48
	movs r0, #1
	b _08241A4A
	.align 2, 0
_08241A3C: .4byte 0x030046A0
_08241A40: .4byte 0x0000752F
_08241A44: .4byte 0x00000942
_08241A48:
	movs r0, #0
_08241A4A:
	cmp r0, #0
	bne _08241A88
	bl SetOverheatTime
	ldr r2, _08241A7C @ =0x030046A0
	ldr r0, [r2]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r3, _08241A80 @ =0x00000942
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08241A84 @ =0x00001388
	cmp r0, r1
	ble _08241AB8
	ldr r0, [r2]
	movs r2, #0xdd
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08241AB6
	.align 2, 0
_08241A7C: .4byte 0x030046A0
_08241A80: .4byte 0x00000942
_08241A84: .4byte 0x00001388
_08241A88:
	ldr r0, [r4]
	movs r5, #0xdd
	lsls r5, r5, #1
	adds r1, r0, r5
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08241A9E
	subs r0, r2, #1
	strh r0, [r1]
_08241A9E:
	bl IsGunCooled
	cmp r0, #0
	beq _08241AB8
	ldr r0, [r4]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r0, [r4]
	adds r0, r0, r5
_08241AB6:
	strh r1, [r0]
_08241AB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
