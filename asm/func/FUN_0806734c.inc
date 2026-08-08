	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080673D2
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08064d6c
	cmp r0, #0
	beq _080673C0
	ldr r0, _080673B0 @ =0x00000392
	bl PlaySound_082406e0
	ldr r0, _080673B4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080673B8 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, #0xe
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _08067392
	movs r0, #0x20
	strb r0, [r1]
_08067392:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrb r1, [r1]
	bl Div
	ldr r3, _080673BC @ =0x000003FD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	b _080673D2
	.align 2, 0
_080673B0: .4byte 0x00000392
_080673B4: .4byte 0x030046A0
_080673B8: .4byte 0x00000942
_080673BC: .4byte 0x000003FD
_080673C0:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_08060b84
_080673D2:
	ldr r1, _080673E4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080673E8
	cmp r0, #1
	beq _0806749C
	b _080674D0
	.align 2, 0
_080673E4: .4byte 0x0000037D
_080673E8:
	ldr r3, _0806740C @ =0x0000037E
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r3, #0x7f
	adds r1, r4, r3
	ldrb r3, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _08067410
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _080674D0
	.align 2, 0
_0806740C: .4byte 0x0000037E
_08067410:
	ldrh r1, [r2]
	adds r0, r3, #0
	subs r0, #8
	cmp r1, r0
	bge _0806742C
	ldr r0, _08067490 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08067494 @ =0x00000125
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_0806742C:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08067458
	ldr r3, _08067498 @ =0x000003CE
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08067458
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_08067458:
	movs r3, #0xff
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08060aa4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080670fc
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08060a24
	b _080674D0
	.align 2, 0
_08067490: .4byte 0x0000095E
_08067494: .4byte 0x00000125
_08067498: .4byte 0x000003CE
_0806749C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r3, _080674D8 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080674D0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080674D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080674D8: .4byte 0x0000037E
