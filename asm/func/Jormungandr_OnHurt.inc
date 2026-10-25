	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C42A6
	b _080C4512
_080C42A6:
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080C42BA
	b _080C4512
_080C42BA:
	movs r0, #0xf
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080C42D8
	ldr r0, _080C42D4 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	b _080C42EE
	.align 2, 0
_080C42D4: .4byte 0x03002BE0
_080C42D8:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080C42E6
	movs r0, #0x24
	ldrsh r1, [r7, r0]
	b _080C42EA
_080C42E6:
	movs r3, #0x24
	ldrsh r1, [r7, r3]
_080C42EA:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
_080C42EE:
	movs r2, #2
	cmp r1, r0
	ble _080C42F6
	movs r2, #1
_080C42F6:
	cmp r2, #1
	bne _080C43EC
	ldr r3, _080C43C0 @ =0x0000191A
	adds r6, r4, r3
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C4306
	b _080C4512
_080C4306:
	ldr r1, _080C43C4 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C43AA
	adds r0, r5, #0
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
	ldr r2, _080C43C8 @ =0x00001910
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C43CC @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C43D0 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C43D4 @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _080C43D8 @ =0x000025DC
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x64
	ble _080C4364
	movs r0, #0x64
	strh r0, [r1]
_080C4364:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C43DC @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C43E0 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C438E
	strh r1, [r2]
_080C438E:
	ldr r2, _080C43E4 @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C43E8 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C43AA:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080C44B8
	b _080C44F8
	.align 2, 0
_080C43C0: .4byte 0x0000191A
_080C43C4: .4byte 0x000025C8
_080C43C8: .4byte 0x00001910
_080C43CC: .4byte 0x0000191C
_080C43D0: .4byte 0x000025C2
_080C43D4: .4byte 0x000025D8
_080C43D8: .4byte 0x000025DC
_080C43DC: .4byte 0x000025DE
_080C43E0: .4byte 0x000025E0
_080C43E4: .4byte 0x000025E4
_080C43E8: .4byte 0x000025CC
_080C43EC:
	cmp r2, #2
	beq _080C43F2
	b _080C4512
_080C43F2:
	ldr r0, _080C44C8 @ =0x00001918
	adds r6, r4, r0
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C43FE
	b _080C4512
_080C43FE:
	ldr r1, _080C44CC @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C44A4
	adds r0, r5, #0
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
	ldr r2, _080C44D0 @ =0x0000190E
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C44D4 @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C44D8 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C44DC @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r1, _080C44E0 @ =0x000025DC
	adds r3, r4, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x64
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080C445E
	strh r1, [r3]
_080C445E:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C44E4 @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C44E8 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C4488
	strh r1, [r2]
_080C4488:
	ldr r2, _080C44EC @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C44F0 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C44A4:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080C44F8
_080C44B8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r3, _080C44F4 @ =0x000025D6
	adds r0, r4, r3
	strh r1, [r0]
	b _080C4506
	.align 2, 0
_080C44C8: .4byte 0x00001918
_080C44CC: .4byte 0x000025C8
_080C44D0: .4byte 0x0000190E
_080C44D4: .4byte 0x0000191C
_080C44D8: .4byte 0x000025C2
_080C44DC: .4byte 0x000025D8
_080C44E0: .4byte 0x000025DC
_080C44E4: .4byte 0x000025DE
_080C44E8: .4byte 0x000025E0
_080C44EC: .4byte 0x000025E4
_080C44F0: .4byte 0x000025CC
_080C44F4: .4byte 0x000025D6
_080C44F8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	asrs r0, r0, #1
	ldr r2, _080C4518 @ =0x000025D6
	adds r1, r4, r2
	strh r0, [r1]
_080C4506:
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r3, _080C451C @ =0x000025D5
	adds r0, r4, r3
	strb r1, [r0]
_080C4512:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4518: .4byte 0x000025D6
_080C451C: .4byte 0x000025D5
