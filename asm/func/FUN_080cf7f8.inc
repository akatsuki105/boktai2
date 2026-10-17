	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080CF880 @ =0x000003CE
	adds r3, r4, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _080CF842
	ldrh r1, [r4, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldrh r0, [r4, #0x2e]
	adds r0, #0x96
	adds r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r1, [r4, #0x30]
	adds r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #6
	adds r0, r4, r5
	strh r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #1
	strh r0, [r3]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF842:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080CF8C8
	adds r0, r1, #0
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080CF884 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF888
	asrs r3, r0, #0xc
	b _080CF88E
	.align 2, 0
_080CF880: .4byte 0x000003CE
_080CF884: .4byte gSineTable
_080CF888:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CF88E:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF8B0
	asrs r2, r0, #0xc
	b _080CF8B6
_080CF8B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CF8B6:
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF8C8:
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080CF8E4
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _080CF94A
_080CF8E4:
	ldr r2, _080CF934 @ =0x000003D1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF94A
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _080CF93C
	movs r0, #8
	subs r0, r0, r2
	subs r5, #0xe6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080CF938 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _080CF948
	.align 2, 0
_080CF934: .4byte 0x000003D1
_080CF938: .4byte 0x000002E7
_080CF93C:
	ldr r2, _080CF950 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080CF954 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080CF948:
	strb r0, [r1]
_080CF94A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF950: .4byte 0x000002E6
_080CF954: .4byte 0x000002E7
