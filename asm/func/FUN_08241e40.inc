	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x19]
	cmp r4, #1
	beq _08241E74
	cmp r4, #1
	bgt _08241E54
	cmp r4, #0
	beq _08241E5A
	b _08241EDE
_08241E54:
	cmp r4, #2
	beq _08241E8C
	b _08241EDE
_08241E5A:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08241EDE
	bl FUN_08247774
	movs r0, #1
	strb r0, [r7, #0x19]
	strh r4, [r7, #0x20]
	b _08241EDE
_08241E74:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08241EDE
	movs r0, #2
	strb r0, [r7, #0x19]
	movs r0, #0
	strh r0, [r7, #0x20]
	b _08241EDE
_08241E8C:
	adds r0, r7, #0
	bl FUN_08241da8
	strh r0, [r7, #0x1c]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_08241774
	strh r0, [r7, #0x1e]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_082417ec
	ldr r5, _08241EE4 @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0x94
	lsls r4, r4, #4
	adds r1, r1, r4
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08241774
	ldr r1, [r5]
	ldr r6, _08241EE8 @ =0x00000942
	adds r1, r1, r6
	strh r0, [r1]
	adds r0, r7, #0
	bl solar_08241ac0
	ldr r2, _08241EEC @ =0x03004870
	ldr r1, [r5]
	adds r4, r1, r4
	ldrh r0, [r4]
	strh r0, [r2]
	ldr r2, _08241EF0 @ =0x03004874
	adds r1, r1, r6
	ldrh r0, [r1]
	strh r0, [r2]
_08241EDE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08241EE4: .4byte 0x030046A0
_08241EE8: .4byte 0x00000942
_08241EEC: .4byte 0x03004870
_08241EF0: .4byte 0x03004874
