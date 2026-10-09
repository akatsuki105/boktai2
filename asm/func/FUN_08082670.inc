	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080826D8
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080826BC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080826B4 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080826B8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080826CC
	.align 2, 0
_080826B4: .4byte 0x000002E6
_080826B8: .4byte 0x000002E7
_080826BC:
	lsrs r1, r1, #0x19
	ldr r2, _080826F0 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080826F4 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080826CC:
	ldr r0, _080826F8 @ =0x00000366
	bl sound_08240740
	ldr r0, _080826FC @ =0x0000036B
	bl PlaySound_082406e0
_080826D8:
	ldr r5, _08082700 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080826E4
	b _0808295A
_080826E4:
	lsls r0, r0, #2
	ldr r1, _08082704 @ =_08082708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080826F0: .4byte 0x000002E6
_080826F4: .4byte 0x000002E7
_080826F8: .4byte 0x00000366
_080826FC: .4byte 0x0000036B
_08082700: .4byte 0x0000037D
_08082704: .4byte _08082708
_08082708: @ jump table
	.4byte _0808271C @ case 0
	.4byte _0808274C @ case 1
	.4byte _0808285C @ case 2
	.4byte _080828E8 @ case 3
	.4byte _0808290C @ case 4
_0808271C:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082748 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0808273C
	b _0808295A
_0808273C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082748: .4byte 0x0000037E
_0808274C:
	ldr r1, _080827A0 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08082760
	ldr r2, _080827A4 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08082760:
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080827A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827AC
	asrs r0, r0, #0xc
	b _080827B2
	.align 2, 0
_080827A0: .4byte 0x0000037E
_080827A4: .4byte 0x000003F6
_080827A8: .4byte 0x085B0A08
_080827AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827B2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080827D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827D8
	asrs r0, r0, #0xc
	b _080827DE
	.align 2, 0
_080827D4: .4byte 0x085B0A08
_080827D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827DE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _0808280C @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08082818
	ldr r2, _08082810 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08082814
	subs r0, r2, r0
	b _08082816
	.align 2, 0
_0808280C: .4byte 0x0000037E
_08082810: .4byte 0x000003F6
_08082814:
	movs r0, #0
_08082816:
	strh r0, [r1]
_08082818:
	ldr r3, _08082850 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08082830
	b _0808295A
_08082830:
	ldr r0, _08082854 @ =0x000003F6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808283C
	b _0808295A
_0808283C:
	strh r0, [r1]
	ldr r0, _08082858 @ =0x0000033A
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082850: .4byte 0x0000037E
_08082854: .4byte 0x000003F6
_08082858: .4byte 0x0000033A
_0808285C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08082890 @ =0x085B0A08
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
	blt _08082894
	asrs r0, r0, #0xc
	b _0808289A
	.align 2, 0
_08082890: .4byte 0x085B0A08
_08082894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808289A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080828B8
	asrs r0, r0, #0xc
	b _080828BE
_080828B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080828BE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08080e0c
	b _0808295A
_080828E8:
	ldr r0, _08082908 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0808295A
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082908: .4byte 0x0000037E
_0808290C:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	ldr r1, _08082960 @ =0x000003D2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r4, #0
	bl LinkPlayer_SetAnimFacing
	ldr r3, _08082964 @ =0x0000046D
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	subs r3, #1
	adds r1, r4, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08082950
	strb r5, [r2]
	ldr r5, _08082968 @ =0x00000472
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r2, _0808296C @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08082950:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_0808295A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082960: .4byte 0x000003D2
_08082964: .4byte 0x0000046D
_08082968: .4byte 0x00000472
_0808296C: .4byte 0x00000474
