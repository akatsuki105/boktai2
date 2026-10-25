	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	movs r0, #0xcc
	adds r0, r0, r4
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026090
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0x8e
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl Boss_PlayAnim
	ldr r6, _08026114 @ =0x0000077A
	adds r0, r4, r6
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Duneyrr_SetHurtboxPower
_08026090:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080260A4
	b _080261A8
_080260A4:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080261A8
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r2, [r0]
	ldr r1, _08026118 @ =0x0003FFFF
	adds r5, r0, #0
	cmp r2, r1
	bhi _080260E8
	subs r0, #0x22
	ldrh r3, [r0]
	cmp r3, #0
	bne _080260E8
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r6, #0x8e
	lsls r6, r6, #2
	adds r2, r4, r6
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #6
	bl Boss_PlayAnim
_080260E8:
	ldr r0, [r5]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, r1
	bhi _080260FA
	movs r2, #1
_080260FA:
	cmp r2, #0
	beq _0802611C
	adds r2, r4, #0
	adds r2, #0xcc
	ldrh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r2, #4]
	adds r0, #4
	strh r1, [r0]
	movs r3, #1
	b _0802617C
	.align 2, 0
_08026114: .4byte 0x0000077A
_08026118: .4byte 0x0003FFFF
_0802611C:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r5, _08026148 @ =0x0000055C
	adds r1, r7, r5
	adds r5, r4, #0
	adds r5, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _0802614C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08026150
	asrs r1, r0, #0xc
	b _08026156
	.align 2, 0
_08026148: .4byte 0x0000055C
_0802614C: .4byte gSineTable
_08026150:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026156:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08026172
	asrs r0, r0, #0xc
	b _08026178
_08026172:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026178:
	strh r0, [r5, #4]
	movs r3, #0
_0802617C:
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r2, [r1]
	mov r6, r8
	movs r5, #2
	ldrsh r0, [r6, r5]
	cmp r2, r0
	ble _08026196
	adds r0, r2, #0
	subs r0, #0x10
	strh r0, [r1]
	b _080261A8
_08026196:
	mov r6, r8
	ldrh r0, [r6, #2]
	strh r0, [r1]
	cmp r3, #0
	beq _080261A8
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080261A8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
