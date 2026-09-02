	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _08069812
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _080697FC
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069768 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x96
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0806976C
	asrs r2, r0, #0xc
	b _08069772
	.align 2, 0
_08069768: .4byte 0x085B0A08
_0806976C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08069772:
	add r0, sp, #4
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806979C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080697A0
	asrs r2, r0, #0xc
	b _080697A6
	.align 2, 0
_0806979C: .4byte 0xFFFF0000
_080697A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080697A6:
	add r0, sp, #4
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080697EC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, _080697F0 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080697F4 @ =0x00000942
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, #0x78
	adds r0, r5, #0
	adds r0, #0x28
	movs r4, #1
	adds r1, r4, #0
	ldrb r0, [r0]
	lsls r1, r0
	movs r0, #0x5a
	str r0, [sp]
	add r0, sp, #4
	bl FreezeEffect_Create
	ldr r2, _080697F8 @ =0x000003FA
	adds r0, r5, r2
	strb r4, [r0]
	b _08069802
	.align 2, 0
_080697EC: .4byte 0xFFFF0000
_080697F0: .4byte 0x030046A0
_080697F4: .4byte 0x00000942
_080697F8: .4byte 0x000003FA
_080697FC:
	ldr r4, _08069828 @ =0x000003FA
	adds r0, r5, r4
	strb r1, [r0]
_08069802:
	ldr r0, _0806982C @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #0
	bl FUN_08060b84
_08069812:
	ldr r1, _08069830 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069890
	cmp r0, #1
	bgt _08069834
	cmp r0, #0
	beq _0806983E
	b _08069920
	.align 2, 0
_08069828: .4byte 0x000003FA
_0806982C: .4byte 0x00000306
_08069830: .4byte 0x0000037D
_08069834:
	cmp r0, #2
	beq _080698CC
	cmp r0, #3
	beq _08069908
	b _08069920
_0806983E:
	ldr r2, _0806987C @ =0x000003FA
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0806985C
	ldr r0, _08069880 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
_0806985C:
	adds r0, r5, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069920
	ldrb r0, [r4]
	cmp r0, #0
	beq _08069884
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #1
	bl FUN_08060b84
	b _08069920
	.align 2, 0
_0806987C: .4byte 0x000003FA
_08069880: .4byte 0x0000095E
_08069884:
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #2
	bl FUN_08060b84
	b _08069920
_08069890:
	ldr r4, _080698C4 @ =0x0000095E
	adds r1, r5, r4
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0xae
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080698C8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08069920
	b _080698F6
	.align 2, 0
_080698C4: .4byte 0x0000095E
_080698C8: .4byte 0x0000037E
_080698CC:
	ldr r0, _08069904 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080698DE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080698DE:
	adds r0, r5, #0
	movs r1, #0xa9
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08069920
_080698F6:
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #3
	bl FUN_08060b84
	b _08069920
	.align 2, 0
_08069904: .4byte 0x0000037E
_08069908:
	adds r0, r5, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069920
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069920:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
