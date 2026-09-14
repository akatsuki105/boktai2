	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #0x1a]
	strb r4, [r6, #0x1b]
	movs r0, #0x6c
	movs r1, #0x32
	bl VM_GetKeywordValue
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08013484
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	strh r0, [r6, #0x2a]
	bl Script_GetValue
	b _08013488
_08013484:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_08013488:
	strh r0, [r6, #0x2c]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x24]
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080134AC @ =0x00002567
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _080134B0
	movs r0, #1
	rsbs r0, r0, #0
	b _080135E6
	.align 2, 0
_080134AC: .4byte 0x00002567
_080134B0:
	adds r0, r6, #0
	adds r0, #0xac
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r2, r6, #0
	adds r2, #0xc8
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bne _080134DA
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	b _080134E2
_080134DA:
	ldr r1, _08013578 @ =0x00000287
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
_080134E2:
	adds r4, r6, #0
	adds r4, #0x30
	ldr r2, _0801357C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _08013580 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r6, #0x18]
	ldr r2, _08013584 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r5, r6, #0
	adds r5, #0x28
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _08013588 @ =FUN_08013288
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	ldrh r0, [r6, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08013572
	cmp r1, #0
	blt _08013572
	ldr r0, _0801358C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08013572
	ldr r0, _08013590 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08013594
_08013572:
	movs r4, #0
	b _080135A2
	.align 2, 0
_08013578: .4byte 0x00000287
_0801357C: .4byte 0xFFFF0000
_08013580: .4byte 0x0000FFFF
_08013584: .4byte 0x00004001
_08013588: .4byte FUN_08013288
_0801358C: .4byte 0x030046A8
_08013590: .4byte 0x030046AC
_08013594:
	ldr r0, _080135B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080135A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080135B8
	adds r0, #4
	b _080135C4
	.align 2, 0
_080135B4: .4byte 0x030046A4
_080135B8:
	ldr r0, _080135F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080135C4:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _080135D0
	adds r3, #1
_080135D0:
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0xff
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0
_080135E6:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080135F0: .4byte 0x030046A4
