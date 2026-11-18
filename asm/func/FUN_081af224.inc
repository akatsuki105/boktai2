	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	adds r3, r5, #0
	adds r3, #0x9c
	ldr r0, _081AF248 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AF24C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AF24E
	.align 2, 0
_081AF248: .4byte 0x0000046D
_081AF24C:
	movs r0, #0
_081AF24E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081AF25C
	b _081AF68E
_081AF25C:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r4, _081AF2AC @ =0x0000046A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #6
	beq _081AF2B0
	cmp r0, #0x11
	beq _081AF2B0
	movs r1, #0x89
	lsls r1, r1, #7
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081AF2B0
	ldr r0, [r3, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081AF2B8
	.align 2, 0
_081AF2AC: .4byte 0x0000046A
_081AF2B0:
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r1, [r0]
_081AF2B8:
	asrs r0, r1, #1
	cmp r2, r0
	bne _081AF2FE
	ldr r1, _081AF2EC @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	subs r1, #0x6b
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF2F4
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081AF2F0 @ =0x00000469
	b _081AF7DC
	.align 2, 0
_081AF2EC: .4byte 0x0000046B
_081AF2F0: .4byte 0x00000469
_081AF2F4:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _081AF860
_081AF2FE:
	cmp r2, #1
	beq _081AF3D4
	cmp r2, #1
	bgt _081AF30C
	cmp r2, #0
	beq _081AF31A
	b _081AF686
_081AF30C:
	cmp r2, #2
	bne _081AF312
	b _081AF478
_081AF312:
	cmp r2, #3
	bne _081AF318
	b _081AF564
_081AF318:
	b _081AF686
_081AF31A:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081AF36C
	movs r2, #9
	ldr r3, _081AF340 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF348
	ldr r4, _081AF344 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081AF586
	.align 2, 0
_081AF340: .4byte 0x0000025D
_081AF344: .4byte 0x000004B7
_081AF348:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xa
	ldr r1, _081AF364 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF368 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xa
	beq _081AF362
	b _081AF5C2
_081AF362:
	b _081AF5B2
	.align 2, 0
_081AF364: .4byte 0x000004B7
_081AF368: .4byte 0x0000046E
_081AF36C:
	movs r1, #9
	ldr r4, _081AF394 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF39C
	ldr r2, _081AF398 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #0
	bl AuxAnim_SetAnim
	b _081AF3C2
	.align 2, 0
_081AF394: .4byte 0x0000025D
_081AF398: .4byte 0x000004B7
_081AF39C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r3, _081AF3CC @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #9
_081AF3B2:
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF3C2:
	ldr r4, _081AF3D0 @ =0x0000046E
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	b _081AF678
	.align 2, 0
_081AF3CC: .4byte 0x000004B7
_081AF3D0: .4byte 0x0000046E
_081AF3D4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081AF428
	movs r2, #9
	ldr r1, _081AF3FC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF404
	ldr r4, _081AF400 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081AF586
	.align 2, 0
_081AF3FC: .4byte 0x0000025D
_081AF400: .4byte 0x000004B7
_081AF404:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xb
	ldr r1, _081AF420 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF424 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xb
	beq _081AF41E
	b _081AF5C2
_081AF41E:
	b _081AF5B2
	.align 2, 0
_081AF420: .4byte 0x000004B7
_081AF424: .4byte 0x0000046E
_081AF428:
	movs r1, #9
	ldr r4, _081AF450 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF458
	ldr r2, _081AF454 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081AF3C2
	.align 2, 0
_081AF450: .4byte 0x0000025D
_081AF454: .4byte 0x000004B7
_081AF458:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r3, _081AF474 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	b _081AF3B2
	.align 2, 0
_081AF474: .4byte 0x000004B7
_081AF478:
	subs r0, r1, #1
	cmp r0, #4
	bls _081AF4F4
	movs r1, #9
	ldr r2, _081AF4A8 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF4B0
	ldr r3, _081AF4AC @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081AF4D6
	.align 2, 0
_081AF4A8: .4byte 0x0000025D
_081AF4AC: .4byte 0x000004B7
_081AF4B0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r2, _081AF4EC @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_081AF4D6:
	ldr r3, _081AF4F0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	b _081AF5EC
	.align 2, 0
_081AF4EC: .4byte 0x000004B7
_081AF4F0: .4byte 0x0000046E
_081AF4F4:
	movs r1, #9
	ldr r2, _081AF51C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF524
	ldr r3, _081AF520 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #2
	bl AuxAnim_SetAnim
	b _081AF54C
	.align 2, 0
_081AF51C: .4byte 0x0000025D
_081AF520: .4byte 0x000004B7
_081AF524:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xb
	ldr r2, _081AF55C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xb
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF54C:
	ldr r3, _081AF560 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r5, r4
	b _081AF67E
	.align 2, 0
_081AF55C: .4byte 0x000004B7
_081AF560: .4byte 0x0000046E
_081AF564:
	cmp r1, #3
	bhi _081AF5FC
	movs r2, #9
	ldr r1, _081AF590 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081AF59C
	ldr r4, _081AF594 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081AF586:
	bl AuxAnim_SetAnim
	ldr r0, _081AF598 @ =0x0000046E
	adds r6, r5, r0
	b _081AF5DE
	.align 2, 0
_081AF590: .4byte 0x0000025D
_081AF594: .4byte 0x000004B7
_081AF598: .4byte 0x0000046E
_081AF59C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _081AF5F4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081AF5F8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #9
	bne _081AF5C2
_081AF5B2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081AF5C2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081AF5E2
_081AF5C2:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081AF5DE:
	movs r0, #0
	strb r0, [r6]
_081AF5E2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_081AF5EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081AF686
	.align 2, 0
_081AF5F4: .4byte 0x000004B7
_081AF5F8: .4byte 0x0000046E
_081AF5FC:
	movs r2, #9
	ldr r4, _081AF628 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF634
	ldr r1, _081AF62C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r2, _081AF630 @ =0x0000046E
	adds r6, r5, r2
	b _081AF674
	.align 2, 0
_081AF628: .4byte 0x0000025D
_081AF62C: .4byte 0x000004B7
_081AF630: .4byte 0x0000046E
_081AF634:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xa
	ldr r3, _081AF6CC @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r4, _081AF6D0 @ =0x0000046E
	adds r6, r5, r4
	cmp r1, #0xa
	bne _081AF65C
	ldrb r0, [r6]
	cmp r0, #0
	bne _081AF65C
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081AF678
_081AF65C:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081AF674:
	movs r0, #0
	strb r0, [r6]
_081AF678:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
_081AF67E:
	ldr r1, _081AF6D4 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081AF686:
	ldr r2, _081AF6D0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081AF68E:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _081AF6FC
	ldrh r0, [r1, #8]
	cmp r0, #1
	beq _081AF6A4
	cmp r0, #3
	bne _081AF6FC
_081AF6A4:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r4, r8
	ldrb r2, [r4, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _081AF6C2
	rsbs r0, r0, #0
_081AF6C2:
	cmp r0, #0x20
	bgt _081AF6D8
	mov r0, r8
	strb r1, [r0, #5]
	b _081AF6FC
	.align 2, 0
_081AF6CC: .4byte 0x000004B7
_081AF6D0: .4byte 0x0000046E
_081AF6D4: .4byte 0xFFFEFFFF
_081AF6D8:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AF6F4
	adds r0, r2, #0
	adds r0, #0x20
	mov r4, r8
	strb r0, [r4, #5]
	b _081AF6FC
_081AF6F4:
	adds r0, r2, #0
	subs r0, #0x20
	mov r1, r8
	strb r0, [r1, #5]
_081AF6FC:
	ldr r1, _081AF714 @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF71C
	ldr r3, _081AF718 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081AF72C
	.align 2, 0
_081AF714: .4byte 0x0000A02F
_081AF718: .4byte 0x00000482
_081AF71C:
	ldr r4, _081AF750 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081AF72C
	movs r0, #1
	strh r0, [r2]
_081AF72C:
	ldr r1, _081AF754 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AF758
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081AF770
	.align 2, 0
_081AF750: .4byte 0x00000482
_081AF754: .4byte 0x0000025D
_081AF758:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081AF770:
	ldr r2, _081AF820 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081AF860
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081AF79A
	rsbs r1, r1, #0
_081AF79A:
	cmp r1, #0
	bgt _081AF830
	ldr r4, _081AF824 @ =0x0000046B
	adds r0, r5, r4
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AF860
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
_081AF7DC:
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081AF828 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081AF82C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _081AF824 @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
	b _081AF860
	.align 2, 0
_081AF820: .4byte 0x0000046E
_081AF824: .4byte 0x0000046B
_081AF828: .4byte 0x0000046A
_081AF82C: .4byte 0x000005BC
_081AF830:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081AF870 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081AF874 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081AF860:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AF870: .4byte 0x0000046D
_081AF874: .4byte 0x0000046B
