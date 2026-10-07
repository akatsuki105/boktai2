	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08081450 @ =0x00000951
	adds r0, r4, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080813F2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808128c
_080813F2:
	adds r0, r4, #0
	bl FUN_08081240
	adds r2, r0, #0
	ldr r6, _08081454 @ =0x0000094C
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r5
	bne _08081410
	adds r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0808141E
_08081410:
	strh r5, [r1]
	ldr r1, _08081458 @ =0x0000094E
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08081188
_0808141E:
	ldr r2, _0808145C @ =0x00000476
	adds r0, r4, r2
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808148C
	ldr r0, _08081460 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r5, r0, r3
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
_08081442:
	subs r0, r3, #5
	cmp r0, #1
	bls _0808144C
	cmp r3, #0xd
	bne _08081464
_0808144C:
	ldrh r0, [r2]
	b _08081466
	.align 2, 0
_08081450: .4byte 0x00000951
_08081454: .4byte 0x0000094C
_08081458: .4byte 0x0000094E
_0808145C: .4byte 0x00000476
_08081460: .4byte 0x03003584
_08081464:
	ldrh r0, [r5]
_08081466:
	strh r0, [r1]
	adds r5, #2
	adds r1, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08081442
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	ldr r2, _08081488 @ =0x00000476
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0808159C
	.align 2, 0
_08081488: .4byte 0x00000476
_0808148C:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _08081512
	ldr r6, _080814D4 @ =0x00000964
	adds r3, r4, r6
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08081502
	ldr r1, _080814D8 @ =0x03003584
	subs r6, #2
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080814C6
	movs r0, #0x30
	strh r0, [r3]
_080814C6:
	ldrh r0, [r3]
	cmp r0, #0x1f
	bhi _080814DC
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080814F0
	.align 2, 0
_080814D4: .4byte 0x00000964
_080814D8: .4byte 0x03003584
_080814DC:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080814F0
	strh r5, [r3]
_080814F0:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080812d4
	b _0808159C
_08081502:
	strh r5, [r3]
	adds r1, r4, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [r1]
	b _0808159C
_08081512:
	ldr r3, _0808154C @ =0x00000964
	adds r0, r4, r3
	strh r5, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08081572
	ldr r1, _08081550 @ =0x03003584
	ldr r6, _08081554 @ =0x0000095E
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r5, r1, r0
	movs r1, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r4, r0
	subs r0, #0x20
	adds r3, r4, r0
_0808153C:
	subs r0, r1, #5
	cmp r0, #1
	bls _08081546
	cmp r1, #0xd
	bne _08081558
_08081546:
	ldrh r0, [r3]
	b _0808155A
	.align 2, 0
_0808154C: .4byte 0x00000964
_08081550: .4byte 0x03003584
_08081554: .4byte 0x0000095E
_08081558:
	ldrh r0, [r5]
_0808155A:
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0808153C
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	b _08081590
_08081572:
	ldr r1, _080815A4 @ =0x03003584
	ldr r3, _080815A8 @ =0x0000095E
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_080812d4
_08081590:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0808159C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080815A4: .4byte 0x03003584
_080815A8: .4byte 0x0000095E
