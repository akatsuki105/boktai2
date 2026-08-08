	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08225414
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225410 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08225416
	.align 2, 0
_08225410: .4byte 0x00000F14
_08225414:
	movs r0, #0
_08225416:
	cmp r0, #0
	beq _08225496
	ldr r3, _082254CC @ =0x00000E8C
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0x19
	strh r0, [r1]
	ldr r0, _082254D0 @ =0x00000E8E
	adds r1, r6, r0
	movs r0, #0x66
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #4
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _082254D4 @ =0x00000F15
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	subs r3, #0xa8
	adds r0, r6, r3
	subs r2, #0xe1
	adds r1, r6, r2
	ldr r1, [r1]
	ldr r3, _082254D8 @ =0x00000F29
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _082254DC @ =0x00000D9C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r2]
	ldr r1, _082254E0 @ =0x00000DA5
	adds r0, r6, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _082254E4 @ =0x00000DA4
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _082254E8 @ =0x00000DF4
	adds r0, r6, r3
	bl FUN_080136b4
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_08223984
	ldr r1, _082254EC @ =0x00000DC8
	adds r0, r6, r1
	ldr r1, _082254F0 @ =0x00000117
	bl FUN_0822b20c
_08225496:
	ldr r2, _082254DC @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _082254F4 @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082254F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08225500
	.align 2, 0
_082254CC: .4byte 0x00000E8C
_082254D0: .4byte 0x00000E8E
_082254D4: .4byte 0x00000F15
_082254D8: .4byte 0x00000F29
_082254DC: .4byte 0x00000D9C
_082254E0: .4byte 0x00000DA5
_082254E4: .4byte 0x00000DA4
_082254E8: .4byte 0x00000DF4
_082254EC: .4byte 0x00000DC8
_082254F0: .4byte 0x00000117
_082254F4: .4byte 0x00000DE4
_082254F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08225500:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08225524
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0822552C
_08225524:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0822552C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08225564 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _082255AA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0822556E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08225568
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225584
	.align 2, 0
_08225564: .4byte 0x0000FFFF
_08225568:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225582
_0822556E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225582
	strh r1, [r4, #8]
	movs r2, #1
	b _08225584
_08225582:
	movs r2, #0
_08225584:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _082255AC
	movs r0, #1
	strb r0, [r4, #7]
	b _082255AC
_082255AA:
	movs r2, #0
_082255AC:
	ldr r3, _08225638 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	cmp r2, #0
	beq _0822562E
	ldr r0, _0822563C @ =0x00000F16
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08225640 @ =0x00000F18
	adds r3, r6, r1
	strh r0, [r3]
	movs r2, #3
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _0822560A
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _0822560A
	ldr r2, _08225644 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _08225648 @ =0x00000F42
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _0822564C @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08225650 @ =0x00000F43
	adds r0, r6, r2
	strb r1, [r0]
_0822560A:
	movs r0, #1
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08225654 @ =0x00000F0C
	adds r1, r6, r0
	ldr r2, [r1]
	cmp r2, #0
	beq _0822562E
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
_0822562E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08225638: .4byte 0x00000F14
_0822563C: .4byte 0x00000F16
_08225640: .4byte 0x00000F18
_08225644: .4byte 0x00000DEC
_08225648: .4byte 0x00000F42
_0822564C: .4byte 0x00000DF2
_08225650: .4byte 0x00000F43
_08225654: .4byte 0x00000F0C
