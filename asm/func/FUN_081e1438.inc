	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r4, r2, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081E144E
	movs r0, #0
	strb r0, [r5, #4]
	movs r0, #1
	b _081E1450
_081E144E:
	movs r0, #0
_081E1450:
	cmp r0, #0
	beq _081E147C
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	adds r0, #0x50
	bl ParticleShadow_Show
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e10b8
	ldr r0, _081E14E4 @ =0x00000276
	bl PlaySound_082406e0
_081E147C:
	ldrb r0, [r5, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r5, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E14AA
	strb r2, [r5, #2]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E149E
	strb r2, [r5, #3]
_081E149E:
	ldrb r1, [r5, #3]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _081E14A8
	adds r1, #4
_081E14A8:
	strh r1, [r5, #0x34]
_081E14AA:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r5, #0
	adds r1, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r3, [r5, #6]
	movs r4, #6
	str r4, [sp]
	bl LerpVec3
	ldr r2, _081E14E8 @ =0x085B0A08
	ldrh r0, [r5, #6]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _081E14EC
	asrs r2, r0, #0xc
	b _081E14F2
	.align 2, 0
_081E14E4: .4byte 0x00000276
_081E14E8: .4byte 0x085B0A08
_081E14EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081E14F2:
	adds r1, r5, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _081E1516
	ldr r0, _081E1520 @ =FUN_081e1524
	str r0, [r5, #0x20]
	movs r0, #0
	strh r0, [r5, #6]
	movs r0, #1
	strb r0, [r5, #4]
_081E1516:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E1520: .4byte FUN_081e1524
