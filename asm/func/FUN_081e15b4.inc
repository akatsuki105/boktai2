	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E15C8
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E15CA
_081E15C8:
	movs r0, #0
_081E15CA:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	beq _081E15FC
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_082342cc
	strb r0, [r4, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E15F4
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	bl ParticleShadow_Hide
	b _081E15FC
_081E15F4:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
_081E15FC:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E162A
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E161E
	strb r2, [r4, #3]
_081E161E:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E1628
	adds r1, #4
_081E1628:
	strh r1, [r4, #0x34]
_081E162A:
	adds r6, r4, #0
	adds r6, #0x18
	adds r2, r5, #0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E164C
	asrs r0, r0, #8
	b _081E1652
_081E164C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1652:
	strh r0, [r6]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1664
	asrs r0, r0, #8
	b _081E166A
_081E1664:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E166A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E167E
	asrs r1, r0, #8
	b _081E1684
_081E167E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1684:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1344
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
