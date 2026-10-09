	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _08082520
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080824E4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080824DC @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _080824E0 @ =0x000002E7
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _080824F4
	.align 2, 0
_080824DC: .4byte 0x000002E6
_080824E0: .4byte 0x000002E7
_080824E4:
	lsrs r1, r1, #0x19
	ldr r2, _08082510 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08082514 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080824F4:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082518 @ =0x00000366
	bl sound_08240740
	ldr r0, _0808251C @ =0x0000036A
	bl PlaySound_082406e0
	b _08082666
	.align 2, 0
_08082510: .4byte 0x000002E6
_08082514: .4byte 0x000002E7
_08082518: .4byte 0x00000366
_0808251C: .4byte 0x0000036A
_08082520:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r5, r4, r6
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808260C
	ldr r1, _0808255C @ =0x00000395
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082598
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r3, r1, r0
	movs r6, #0x30
	ldrsh r1, [r4, r6]
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	rsbs r0, r3, #0
	cmp r0, #0
	blt _08082560
	asrs r0, r0, #3
	b _08082564
	.align 2, 0
_0808255C: .4byte 0x00000395
_08082560:
	asrs r0, r3, #3
	rsbs r0, r0, #0
_08082564:
	strh r0, [r4, #0x34]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08082570
	asrs r0, r0, #3
	b _08082574
_08082570:
	asrs r0, r1, #3
	rsbs r0, r0, #0
_08082574:
	strh r0, [r4, #0x38]
	movs r6, #0xf5
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	cmp r1, #0x55
	bls _080825FA
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080825FA
	ldr r0, _08082594 @ =0x00000191
	bl PlaySound_082406e0
	b _080825FA
	.align 2, 0
_08082594: .4byte 0x00000191
_08082598:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080825C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825CC
	asrs r0, r0, #0xc
	b _080825D2
	.align 2, 0
_080825C8: .4byte 0x085B0A08
_080825CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825D2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825F0
	asrs r0, r0, #0xc
	b _080825F6
_080825F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825F6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080825FA:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08082666
_0808260C:
	ldr r6, _0808262C @ =0x000004C5
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _08082634
	ldr r1, _08082630 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082634
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
	b _08082666
	.align 2, 0
_0808262C: .4byte 0x000004C5
_08082630: .4byte 0x000004C7
_08082634:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082666
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _0808266C @ =0x00000395
	adds r0, r4, r3
	strb r2, [r0]
	adds r0, r4, #0
	bl LinkPlayer_SetAnimFacing
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808266C: .4byte 0x00000395
