	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r1, _080736D4 @ =0x0000037D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne _080736CA
	b _080737FC
_080736CA:
	cmp r4, #1
	bgt _080736D8
	cmp r4, #0
	beq _080736E6
	b _080738AC
	.align 2, 0
_080736D4: .4byte 0x0000037D
_080736D8:
	cmp r4, #2
	bne _080736DE
	b _08073840
_080736DE:
	cmp r4, #3
	bne _080736E4
	b _080738A4
_080736E4:
	b _080738AC
_080736E6:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _08073738 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bhi _08073758
	cmp r0, #0
	beq _08073740
	movs r0, #4
	str r0, [sp]
	ldr r0, _0807373C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _08073758
	.align 2, 0
_08073738: .4byte 0x0000FFFF
_0807373C: .4byte 0x00001FFF
_08073740:
	movs r0, #4
	str r0, [sp]
	ldr r0, _08073780 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_08073758:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807378C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073784 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _08073788 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0807379C
	.align 2, 0
_08073780: .4byte 0x00001FFF
_08073784: .4byte 0x000002E6
_08073788: .4byte 0x000002E7
_0807378C:
	lsrs r1, r1, #0x19
	ldr r2, _080737C8 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080737CC @ =0x000002E7
	adds r0, r5, r1
	strb r2, [r0]
_0807379C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080737D0 @ =0x000001AD
	bl PlaySound_082406e0
	ldrb r0, [r4]
	cmp r0, #5
	bne _080737D8
	ldr r0, _080737D4 @ =0x000002ED
	bl PlaySound_082406e0
	b _080737DE
	.align 2, 0
_080737C8: .4byte 0x000002E6
_080737CC: .4byte 0x000002E7
_080737D0: .4byte 0x000001AD
_080737D4: .4byte 0x000002ED
_080737D8:
	ldr r0, _080737F4 @ =0x00000305
	bl PlaySound_082406e0
_080737DE:
	ldr r0, _080737F8 @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_08060b84
	b _080738AC
	.align 2, 0
_080737F4: .4byte 0x00000305
_080737F8: .4byte 0x000003F6
_080737FC:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _08073838 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080738AC
	ldr r1, _0807383C @ =0x000003F6
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0xa2
	strb r4, [r0]
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_08060b84
	b _080738AC
	.align 2, 0
_08073838: .4byte 0x0000037E
_0807383C: .4byte 0x000003F6
_08073840:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807389C @ =0x000003F6
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #0x3c
	strh r0, [r4]
	ldr r2, _080738A0 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080738AC
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	movs r0, #0
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _080738AC
	.align 2, 0
_0807389C: .4byte 0x000003F6
_080738A0: .4byte 0x0000037E
_080738A4:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
_080738AC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
