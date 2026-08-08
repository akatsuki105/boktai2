	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r7, r1, #0
	mov sl, r2
	ldr r6, [sp, #0x20]
	cmp r6, #0
	bne _080E08A0
_080E089A:
	movs r0, #0xff
	rsbs r0, r0, #0
	b _080E09AA
_080E08A0:
	cmp r6, #0
	bge _080E08F8
	movs r2, #1
	rsbs r5, r6, #0
	adds r0, r4, #1
	mov r8, r0
	movs r1, #8
	adds r1, r1, r7
	mov sb, r1
	cmp r2, r5
	bgt _080E08EC
	subs r1, r4, #1
	cmp r1, #0
	blt _080E08EC
	ldr r0, _080E08F4 @ =0x085AD374
	mov ip, r0
	lsls r0, r7, #3
	adds r1, r1, r0
	add r1, ip
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, r3
	bne _080E08EC
	adds r0, r4, r0
	add r0, ip
	subs r1, r0, #1
_080E08D6:
	subs r1, #1
	adds r2, #1
	cmp r2, r5
	bgt _080E08EC
	subs r0, r4, r2
	cmp r0, #0
	blt _080E08EC
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r3
	beq _080E08D6
_080E08EC:
	mov r1, r8
	subs r4, r1, r2
	b _080E0940
	.align 2, 0
_080E08F4: .4byte 0x085AD374
_080E08F8:
	movs r2, #1
	subs r0, r4, #1
	mov ip, r0
	movs r1, #8
	adds r1, r1, r7
	mov sb, r1
	cmp r2, r6
	bgt _080E093C
	adds r1, r4, #1
	cmp r1, #7
	bgt _080E093C
	ldr r5, _080E097C @ =0x085AD374
	lsls r0, r7, #3
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, r3
	bne _080E093C
	adds r0, r4, r0
	adds r0, r0, r5
	adds r1, r0, #1
_080E0926:
	adds r1, #1
	adds r2, #1
	cmp r2, r6
	bgt _080E093C
	adds r0, r4, r2
	cmp r0, #7
	bgt _080E093C
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r3
	beq _080E0926
_080E093C:
	mov r0, ip
	adds r4, r0, r2
_080E0940:
	ldr r1, _080E0980 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #5
	adds r2, r4, r0
	cmp r2, sl
	bne _080E09A8
	cmp r6, #0
	bge _080E0984
	subs r0, r4, #2
	cmp r0, #0
	blt _080E089A
	ldr r0, _080E097C @ =0x085AD374
	lsls r1, r7, #3
	subs r1, #2
	adds r1, r4, r1
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r3
	bne _080E089A
	movs r0, #2
	subs r0, r0, r2
	b _080E09AA
	.align 2, 0
_080E097C: .4byte 0x085AD374
_080E0980: .4byte 0x030046A4
_080E0984:
	adds r0, r4, #2
	cmp r0, #7
	bgt _080E089A
	ldr r0, _080E09A4 @ =0x085AD374
	lsls r1, r7, #3
	adds r1, #2
	adds r1, r4, r1
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r3
	beq _080E099E
	b _080E089A
_080E099E:
	adds r0, r2, #2
	rsbs r0, r0, #0
	b _080E09AA
	.align 2, 0
_080E09A4: .4byte 0x085AD374
_080E09A8:
	adds r0, r2, #0
_080E09AA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
