	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _08092632
	ldr r1, _08092624 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08092628
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	b _080926BA
	.align 2, 0
_08092624: .4byte 0x00003AEB
_08092628:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	b _080926BA
_08092632:
	movs r5, #0
	ldr r2, _0809265C @ =0x00003F9C
	adds r6, r4, r2
	ldrb r0, [r6]
	ldr r1, _08092660 @ =0x00003AEE
	adds r7, r4, r1
	ldrb r1, [r7]
	bl GetItemID
	cmp r0, #0
	bge _08092668
	ldrb r0, [r6]
	ldr r2, _08092664 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0
	blt _08092696
	b _08092694
	.align 2, 0
_0809265C: .4byte 0x00003F9C
_08092660: .4byte 0x00003AEE
_08092664: .4byte 0x00003AEB
_08092668:
	ldr r1, _08092678 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0x10
	bne _0809267C
	movs r5, #1
	b _08092696
	.align 2, 0
_08092678: .4byte 0x00003AEB
_0809267C:
	ldrb r0, [r7]
	cmp r0, r1
	bne _08092694
	ldr r2, _08092690 @ =0x00003AE8
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r5, #1
	ands r5, r0
	b _08092696
	.align 2, 0
_08092690: .4byte 0x00003AE8
_08092694:
	movs r5, #3
_08092696:
	cmp r5, #1
	beq _080926A8
	cmp r5, #3
	beq _080926B2
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	b _080926BA
_080926A8:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #1
	b _080926BA
_080926B2:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #3
_080926BA:
	bl FUN_0808c658
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
