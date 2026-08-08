	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	mov sb, r2
	adds r5, r3, #0
	ldr r7, [sp, #0x20]
	cmp r7, #0
	bne _080E0766
_080E0760:
	movs r0, #0xff
	rsbs r0, r0, #0
	b _080E0876
_080E0766:
	cmp r7, #0
	bge _080E07C4
	movs r2, #1
	rsbs r1, r7, #0
	adds r0, r4, #1
	mov r8, r0
	ldr r3, _080E07BC @ =0x030046A4
	mov sl, r3
	cmp r2, r1
	bgt _080E07B6
	subs r0, r4, #1
	cmp r0, #0
	blt _080E07B6
	ldr r3, _080E07C0 @ =0x085AD374
	mov ip, r3
	lsls r0, r0, #3
	adds r0, r6, r0
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r5
	bne _080E07B6
	adds r3, r1, #0
	lsls r0, r4, #3
	adds r0, r0, r6
	add r0, ip
	adds r1, r0, #0
	subs r1, #8
_080E07A0:
	subs r1, #8
	adds r2, #1
	cmp r2, r3
	bgt _080E07B6
	subs r0, r4, r2
	cmp r0, #0
	blt _080E07B6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080E07A0
_080E07B6:
	mov r0, r8
	subs r4, r0, r2
	b _080E080A
	.align 2, 0
_080E07BC: .4byte 0x030046A4
_080E07C0: .4byte 0x085AD374
_080E07C4:
	movs r2, #1
	subs r3, r4, #1
	ldr r0, _080E0844 @ =0x030046A4
	mov sl, r0
	cmp r2, r7
	bgt _080E0808
	adds r0, r4, #1
	cmp r0, #9
	bgt _080E0808
	ldr r1, _080E0848 @ =0x085AD374
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r5
	bne _080E0808
	lsls r0, r4, #3
	adds r0, r0, r6
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #8
_080E07F2:
	adds r1, #8
	adds r2, #1
	cmp r2, r7
	bgt _080E0808
	adds r0, r4, r2
	cmp r0, #9
	bgt _080E0808
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080E07F2
_080E0808:
	adds r4, r3, r2
_080E080A:
	adds r1, r4, #0
	adds r1, #8
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r3, [r0, r2]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, #5
	adds r2, r6, r0
	cmp r2, sb
	bne _080E0874
	cmp r7, #0
	bge _080E084C
	subs r1, r4, #2
	cmp r1, #0
	blt _080E0760
	ldr r0, _080E0848 @ =0x085AD374
	lsls r1, r1, #3
	adds r1, r6, r1
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	bne _080E0760
	lsls r0, r3, #1
	subs r0, r0, r2
	b _080E0876
	.align 2, 0
_080E0844: .4byte 0x030046A4
_080E0848: .4byte 0x085AD374
_080E084C:
	adds r1, r4, #2
	cmp r1, #9
	ble _080E0854
	b _080E0760
_080E0854:
	ldr r0, _080E0870 @ =0x085AD374
	lsls r1, r1, #3
	adds r1, r6, r1
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080E0866
	b _080E0760
_080E0866:
	lsls r0, r3, #1
	adds r0, r2, r0
	rsbs r0, r0, #0
	b _080E0876
	.align 2, 0
_080E0870: .4byte 0x085AD374
_080E0874:
	adds r0, r2, #0
_080E0876:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
