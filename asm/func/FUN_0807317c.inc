	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08073198 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bls _0807318C
	b _08073562
_0807318C:
	lsls r0, r0, #2
	ldr r1, _0807319C @ =_080731A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073198: .4byte 0x0000037D
_0807319C: .4byte _080731A0
_080731A0: @ jump table
	.4byte _080731C4 @ case 0
	.4byte _080731F8 @ case 1
	.4byte _08073240 @ case 2
	.4byte _08073280 @ case 3
	.4byte _080732D0 @ case 4
	.4byte _08073364 @ case 5
	.4byte _0807340C @ case 6
	.4byte _08073460 @ case 7
	.4byte _08073500 @ case 8
_080731C4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080731EC
	b _08073562
_080731EC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08073562
_080731F8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807323C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807322E
	b _08073562
_0807322E:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_0807323C: .4byte 0x0000037E
_08073240:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807325C
	ldr r1, _08073278 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807325C
	ldr r0, _0807327C @ =0x00000327
	bl PlaySound_082406e0
_0807325C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r3, _08073278 @ =0x0000037E
	adds r5, r4, r3
	b _080734A4
	.align 2, 0
_08073278: .4byte 0x0000037E
_0807327C: .4byte 0x00000327
_08073280:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _080732C8 @ =0x0000037E
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080732AA
	b _08073562
_080732AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080732CC @ =FUN_080726e0
	str r0, [r1]
	b _08073452
	.align 2, 0
_080732C8: .4byte 0x0000037E
_080732CC: .4byte FUN_080726e0
_080732D0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080732EC
	ldr r2, _08073358 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080732EC
	ldr r0, _0807335C @ =0x00000201
	bl PlaySound_082406e0
_080732EC:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _08073358 @ =0x0000037E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08073360 @ =0x000003F6
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807334C
	b _08073562
_0807334C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_08073358: .4byte 0x0000037E
_0807335C: .4byte 0x00000201
_08073360: .4byte 0x000003F6
_08073364:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r2, _080733C4 @ =0x0000037E
	adds r3, r4, r2
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xbc
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _080733CC
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r4, #0
	adds r2, #0xbd
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r3, _080733C8 @ =0x000003F6
	adds r0, r4, r3
	strh r1, [r0]
	b _080733E4
	.align 2, 0
_080733C4: .4byte 0x0000037E
_080733C8: .4byte 0x000003F6
_080733CC:
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _08073404 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
_080733E4:
	ldr r2, _08073408 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080733F8
	b _08073562
_080733F8:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #6
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_08073404: .4byte 0x000003F6
_08073408: .4byte 0x0000037E
_0807340C:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807345C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _08073446
	b _08073562
_08073446:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
_08073452:
	adds r0, r4, #0
	bl FUN_080726b4
	b _08073562
	.align 2, 0
_0807345C: .4byte 0x0000037E
_08073460:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807347C
	ldr r2, _080734F4 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807347C
	ldr r0, _080734F8 @ =0x00000327
	bl PlaySound_082406e0
_0807347C:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080734F4 @ =0x0000037E
	adds r5, r4, r0
_080734A4:
	ldrb r0, [r5]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	ldrh r0, [r5]
	cmp r0, #8
	bls _080734D8
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0xbd
	strb r0, [r1]
	ldrh r0, [r5]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080734FC @ =0x000003F6
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
_080734D8:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08073562
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_080734F4: .4byte 0x0000037E
_080734F8: .4byte 0x00000327
_080734FC: .4byte 0x000003F6
_08073500:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08073568 @ =0x0000037E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _0807356C @ =0x000003F6
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08073562
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08073570 @ =FUN_080726e0
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
_08073562:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073568: .4byte 0x0000037E
_0807356C: .4byte 0x000003F6
_08073570: .4byte FUN_080726e0
