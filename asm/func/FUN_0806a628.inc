	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _0806A6DE
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r5, #0xf5
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A684
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A680 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #0xed
	adds r1, r4, r5
	movs r0, #1
	b _0806A692
	.align 2, 0
_0806A680: .4byte 0x000002E6
_0806A684:
	lsrs r1, r1, #0x19
	ldr r2, _0806A6B4 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r5, _0806A6B8 @ =0x000002E7
	adds r1, r4, r5
	movs r0, #0
_0806A692:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806A6C0
	ldr r0, _0806A6BC @ =0x000002EB
	bl PlaySound_082406e0
	b _0806A6C6
	.align 2, 0
_0806A6B4: .4byte 0x000002E6
_0806A6B8: .4byte 0x000002E7
_0806A6BC: .4byte 0x000002EB
_0806A6C0:
	movs r0, #0xe7
	bl PlaySound_082406e0
_0806A6C6:
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, _0806A6F4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0806A6DE
	bl FUN_08050d10
_0806A6DE:
	ldr r2, _0806A6F8 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806A6EA
	b _0806A884
_0806A6EA:
	lsls r0, r0, #2
	ldr r1, _0806A6FC @ =_0806A700
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A6F4: .4byte 0x030047A4
_0806A6F8: .4byte 0x0000037D
_0806A6FC: .4byte _0806A700
_0806A700: @ jump table
	.4byte _0806A718 @ case 0
	.4byte _0806A79C @ case 1
	.4byte _0806A7F0 @ case 2
	.4byte _0806A820 @ case 3
	.4byte _0806A840 @ case 4
	.4byte _0806A87C @ case 5
_0806A718:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A74C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A750
	asrs r0, r0, #0xc
	b _0806A756
	.align 2, 0
_0806A74C: .4byte 0x085B0A08
_0806A750:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A756:
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A772
	asrs r0, r0, #0xc
	b _0806A778
_0806A772:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A778:
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	beq _0806A790
	b _0806A884
_0806A790:
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #1
	bl FUN_08060b84
	b _0806A884
_0806A79C:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _0806A7B6
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806A7B6
	movs r0, #0xd1
	bl PlaySound_082406e0
_0806A7B6:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A884
	ldr r0, _0806A7EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0806A80C
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #2
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A7EC: .4byte 0x030047A4
_0806A7F0:
	ldr r2, _0806A818 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806A884
	ldr r0, _0806A81C @ =0x030047A4
	ldr r1, [r0]
	adds r2, #0x82
	orrs r1, r2
	str r1, [r0]
_0806A80C:
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #3
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A818: .4byte 0x0000037E
_0806A81C: .4byte 0x030047A4
_0806A820:
	ldr r5, _0806A83C @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806A884
	adds r1, r4, #0
	adds r1, #0xa2
	movs r0, #1
	strb r0, [r1]
	b _0806A884
	.align 2, 0
_0806A83C: .4byte 0x0000037E
_0806A840:
	ldr r0, _0806A878 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806A85C
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806A85C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806A884
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #5
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A878: .4byte 0x0000037E
_0806A87C:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806A884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
