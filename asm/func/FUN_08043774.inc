	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043798
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
_08043798:
	ldr r0, [r4, #0x14]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08043890
	ldr r1, _080437F8 @ =0x000001ED
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov sb, r0
	cmp r1, #0
	beq _08043830
	bl FUN_080865c0
	adds r3, r0, #0
	movs r6, #0
	cmp r3, #0
	beq _080437E8
	adds r1, r4, #0
	adds r1, #0x64
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0
	ldrsh r0, [r3, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080437FC @ =0x000270FF
	cmp r1, r0
	bgt _080437E8
	movs r6, #1
_080437E8:
	cmp r6, #0
	beq _08043804
	ldr r6, _08043800 @ =0x00000236
	adds r1, r4, r6
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08043820
	.align 2, 0
_080437F8: .4byte 0x000001ED
_080437FC: .4byte 0x000270FF
_08043800: .4byte 0x00000236
_08043804:
	mov r7, sb
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _08043830
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043830
	ldr r0, _0804382C @ =0x00000236
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
_08043820:
	strh r0, [r1]
	movs r0, #0xc
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	b _08043902
	.align 2, 0
_0804382C: .4byte 0x00000236
_08043830:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043890
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043890
	adds r2, r5, #0
	adds r2, #0x22
	ldr r6, _0804388C @ =0x00000233
	adds r3, r4, r6
	ldrb r0, [r2]
	ldrb r7, [r3]
	cmp r0, r7
	bne _08043866
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043882
_08043866:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08043890
	adds r0, r5, #0
	adds r0, #0x23
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08043890
_08043882:
	movs r0, #0xd
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	b _08043902
	.align 2, 0
_0804388C: .4byte 0x00000233
_08043890:
	ldr r1, _08043908 @ =0x00000434
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080438EC
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080438B6
	rsbs r1, r1, #0
_080438B6:
	cmp r1, r5
	bge _080438E4
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080438CA
	rsbs r1, r1, #0
_080438CA:
	cmp r1, #0xff
	bgt _080438E4
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080438DE
	rsbs r0, r0, #0
_080438DE:
	movs r1, #1
	cmp r0, r5
	blt _080438E6
_080438E4:
	movs r1, #0
_080438E6:
	movs r0, #1
	cmp r1, #0
	bne _080438EE
_080438EC:
	movs r0, #0
_080438EE:
	cmp r0, #0
	beq _08043910
	ldrb r1, [r4, #4]
	ldr r6, _0804390C @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
_08043902:
	movs r0, #1
	strb r0, [r4, #8]
	b _08043952
	.align 2, 0
_08043908: .4byte 0x00000434
_0804390C: .4byte 0x00000227
_08043910:
	ldr r7, _08043940 @ =0x000001EF
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0804394C
	ldr r0, _08043944 @ =0x0000020E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	bne _08043948
	mov r0, r8
	bl Map_AdvancePathWalker
	adds r0, r4, #0
	bl FUN_08043510
	strb r0, [r4, #4]
	str r5, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0804394C
	.align 2, 0
_08043940: .4byte 0x000001EF
_08043944: .4byte 0x0000020E
_08043948:
	subs r0, #1
	strh r0, [r1]
_0804394C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043952:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
