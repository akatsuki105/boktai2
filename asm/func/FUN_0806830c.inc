	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _08068326
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
_08068326:
	ldr r2, _0806833C @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _08068332
	b _0806861A
_08068332:
	lsls r0, r0, #2
	ldr r1, _08068340 @ =_08068344
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806833C: .4byte 0x0000037D
_08068340: .4byte _08068344
_08068344: @ jump table
	.4byte _08068358 @ case 0
	.4byte _0806837C @ case 1
	.4byte _08068454 @ case 2
	.4byte _08068554 @ case 3
	.4byte _080685D4 @ case 4
_08068358:
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
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _0806861A
_0806837C:
	ldr r2, _080683A8 @ =0x0000037E
	adds r0, r4, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080683D2
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080683B4
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080683AC @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080683B0 @ =0x000002E7
	b _080683BE
	.align 2, 0
_080683A8: .4byte 0x0000037E
_080683AC: .4byte 0x000002E6
_080683B0: .4byte 0x000002E7
_080683B4:
	strb r2, [r1]
	ldr r1, _08068438 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080683BE:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldr r2, _0806843C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080683D2:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080683FA
	b _0806861A
_080683FA:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068414
	b _08068590
_08068414:
	adds r0, r4, #0
	bl FUN_080682dc
	adds r1, r0, #0
	cmp r1, #0
	beq _08068448
	movs r0, #0xb9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r0, _08068440 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08068444 @ =0x00000404
	adds r1, r4, r2
	b _080685B8
	.align 2, 0
_08068438: .4byte 0x000002E6
_0806843C: .4byte 0x0000037E
_08068440: .4byte 0x00000409
_08068444: .4byte 0x00000404
_08068448:
	ldr r2, _08068450 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0806853E
	.align 2, 0
_08068450: .4byte 0x00000404
_08068454:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080684C8 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08068478
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _08068478
	ldr r0, _080684CC @ =0x00000239
	bl PlaySound_082406e0
_08068478:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08067f88
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r4, #0
	bl FUN_080620f0
	ldr r2, _080684D0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080684D4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080684D8
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080684E4
	.align 2, 0
_080684C8: .4byte 0x00000404
_080684CC: .4byte 0x00000239
_080684D0: .4byte 0x0000095E
_080684D4: .4byte 0x0000037E
_080684D8:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080684E4:
	ldr r0, _0806851C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080684FC
	movs r0, #0
	strh r0, [r1]
_080684FC:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068528
	ldr r0, _08068520 @ =0x00000239
	bl sound_08240740
	ldr r2, _08068524 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _08068590
	.align 2, 0
_0806851C: .4byte 0x0000037E
_08068520: .4byte 0x00000239
_08068524: .4byte 0x00000409
_08068528:
	adds r0, r4, #0
	bl FUN_080682dc
	cmp r0, #0
	bne _0806861A
	ldr r0, _0806854C @ =0x00000239
	bl sound_08240740
	ldr r1, _08068550 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0806853E:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _0806861A
	.align 2, 0
_0806854C: .4byte 0x00000239
_08068550: .4byte 0x00000409
_08068554:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806859C
_08068590:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _0806861A
_0806859C:
	adds r0, r4, #0
	bl FUN_080682dc
	cmp r0, #0
	beq _0806861A
	ldr r0, _080685C8 @ =0x00000239
	bl PlaySound_082406e0
	ldr r2, _080685CC @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080685D0 @ =0x00000404
	adds r1, r4, r0
_080685B8:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _0806861A
	.align 2, 0
_080685C8: .4byte 0x00000239
_080685CC: .4byte 0x00000409
_080685D0: .4byte 0x00000404
_080685D4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806861A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08068620 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806861A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068620: .4byte 0x000002E7
