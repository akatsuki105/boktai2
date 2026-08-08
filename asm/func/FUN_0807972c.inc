	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08079644
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080797C6
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _08079790
	ldr r2, _08079784 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x83
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08079788 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x64
	bl Mod
	subs r0, #0x74
	ldr r2, _0807978C @ =0x00000383
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x10
	b _08079792
	.align 2, 0
_08079784: .4byte 0x030046B8
_08079788: .4byte 0x0203B400
_0807978C: .4byte 0x00000383
_08079790:
	subs r0, #1
_08079792:
	strb r0, [r4]
	ldr r0, _080797AC @ =0x00000382
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _080797B0 @ =0x00000383
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #4
	cmp r2, r0
	bgt _080797B4
	adds r0, r2, #4
	strb r0, [r3]
	b _080797C6
	.align 2, 0
_080797AC: .4byte 0x00000382
_080797B0: .4byte 0x00000383
_080797B4:
	adds r0, r1, #0
	adds r0, #8
	cmp r2, r0
	blt _080797C4
	adds r0, r2, #0
	subs r0, #8
	strb r0, [r3]
	b _080797C6
_080797C4:
	strb r1, [r3]
_080797C6:
	ldr r2, _080797FC @ =0x00000382
	adds r0, r5, r2
	ldrb r2, [r0]
	ldrh r0, [r5, #0x2e]
	ldr r3, _08079800 @ =0x000003F6
	adds r1, r5, r3
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079804
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079822
	.align 2, 0
_080797FC: .4byte 0x00000382
_08079800: .4byte 0x000003F6
_08079804:
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _0807983C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079822:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079840
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _0807984C
	.align 2, 0
_0807983C: .4byte 0x0000FFFB
_08079840:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_0807984C:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079868
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079872
_08079868:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079872:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079890
	ldr r2, _0807988C @ =0x0000060C
	adds r0, r5, r2
	bl FUN_080136b4
	b _08079898
	.align 2, 0
_0807988C: .4byte 0x0000060C
_08079890:
	ldr r3, _080798A0 @ =0x0000060C
	adds r0, r5, r3
	bl FUN_08013698
_08079898:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080798A0: .4byte 0x0000060C
