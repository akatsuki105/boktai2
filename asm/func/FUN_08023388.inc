	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080233D4 @ =0x0000026A
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r4, [r0]
	ldr r3, _080233D8 @ =0x00000266
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r6, #0x99
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r3, [r0]
	ldr r0, _080233DC @ =0x0000C144
	cmp r1, r0
	bne _0802343E
	cmp r2, #0
	beq _080233E8
	ldr r1, _080233E0 @ =0x085AAAC4
	movs r0, #3
	ands r4, r0
	lsls r4, r4, #1
	adds r1, r4, r1
	movs r6, #0
	ldrsh r0, [r1, r6]
	muls r0, r3, r0
	adds r1, r2, #0
	bl Div
	ldr r1, _080233E4 @ =0x085AAABC
	adds r4, r4, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r4, r1, r0
	b _080233F6
	.align 2, 0
_080233D4: .4byte 0x0000026A
_080233D8: .4byte 0x00000266
_080233DC: .4byte 0x0000C144
_080233E0: .4byte 0x085AAAC4
_080233E4: .4byte 0x085AAABC
_080233E8:
	ldr r1, _08023410 @ =0x085AAABC
	movs r0, #3
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r4, [r0, r3]
_080233F6:
	ldr r1, _08023414 @ =gSineTable
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08023418
	asrs r0, r0, #0xc
	b _0802341E
	.align 2, 0
_08023410: .4byte 0x085AAABC
_08023414: .4byte gSineTable
_08023418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802341E:
	movs r1, #0xad
	lsls r1, r1, #1
	adds r2, r5, r1
	strh r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x23
	bls _08023462
	movs r0, #0
	b _08023460
_0802343E:
	ldr r0, _08023450 @ =gSineTable
	adds r0, #0x80
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08023454
	asrs r0, r0, #0xc
	b _0802345A
	.align 2, 0
_08023450: .4byte gSineTable
_08023454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802345A:
	movs r6, #0xad
	lsls r6, r6, #1
	adds r1, r5, r6
_08023460:
	strh r0, [r1]
_08023462:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
