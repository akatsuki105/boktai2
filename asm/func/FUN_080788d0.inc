	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _08078910
	ldr r2, _080789C0 @ =0x000003FF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08078910
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #0x22
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_08078910:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08078932
	ldr r2, _080789C4 @ =0x000003F3
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08078932
	ldr r3, _080789C8 @ =0x000003BD
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_0807a44c
_08078932:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _080789CC @ =0x00000446
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0
	adds r6, r0, #0
	cmp r1, #0
	beq _08078954
	ldr r3, _080789D0 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078954
	movs r2, #1
_08078954:
	cmp r2, #0
	bne _08078974
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08078974
	adds r0, r5, #0
	bl FUN_08064db0
	adds r4, r0, #0
_08078974:
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080789E0
	ldr r3, _080789D4 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x18
	cmp r0, #0
	beq _0807898E
	movs r4, #0x19
_0807898E:
	ldr r7, _080789D8 @ =0x03002BA8
	ldr r2, [r7]
	cmp r2, #0
	beq _080789B8
	ldr r6, _080789DC @ =0x03002BF4
	ldrh r0, [r6]
	cmp r0, #0
	beq _080789B8
	ldr r0, [r2, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080789B2
	ldr r0, [r2]
	ldr r3, [r2, #8]
	movs r2, #0x3c
	bl _call_via_r3
_080789B2:
	movs r0, #0
	str r0, [r7]
	strh r0, [r6]
_080789B8:
	adds r0, r5, #0
	bl FUN_08078548
	b _08078BB6
	.align 2, 0
_080789C0: .4byte 0x000003FF
_080789C4: .4byte 0x000003F3
_080789C8: .4byte 0x000003BD
_080789CC: .4byte 0x00000446
_080789D0: .4byte 0x00000442
_080789D4: .4byte 0x000003D2
_080789D8: .4byte 0x03002BA8
_080789DC: .4byte 0x03002BF4
_080789E0:
	adds r0, r4, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08078A0A
	cmp r4, #0x16
	beq _08078A0A
	cmp r4, #0x17
	beq _08078A0A
	cmp r4, #0x15
	beq _08078A0A
	cmp r4, #0x14
	beq _08078A0A
	cmp r4, #0x13
	beq _08078A0A
	movs r1, #0xfb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08078A0A
	movs r4, #0x12
_08078A0A:
	subs r0, r4, #2
	cmp r0, #0x1e
	bhi _08078AC0
	lsls r0, r0, #2
	ldr r1, _08078A1C @ =_08078A20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078A1C: .4byte _08078A20
_08078A20: @ jump table
	.4byte _08078BB6 @ case 0
	.4byte _08078BB6 @ case 1
	.4byte _08078A9C @ case 2
	.4byte _08078BB6 @ case 3
	.4byte _08078AAC @ case 4
	.4byte _08078BB6 @ case 5
	.4byte _08078BB6 @ case 6
	.4byte _08078BB6 @ case 7
	.4byte _08078BB6 @ case 8
	.4byte _08078BB6 @ case 9
	.4byte _08078BB6 @ case 10
	.4byte _08078BB6 @ case 11
	.4byte _08078BB6 @ case 12
	.4byte _08078BB6 @ case 13
	.4byte _08078BB6 @ case 14
	.4byte _08078BB6 @ case 15
	.4byte _08078BB6 @ case 16
	.4byte _08078BB6 @ case 17
	.4byte _08078BB6 @ case 18
	.4byte _08078BB6 @ case 19
	.4byte _08078BB6 @ case 20
	.4byte _08078BB6 @ case 21
	.4byte _08078BB6 @ case 22
	.4byte _08078BB6 @ case 23
	.4byte _08078AC0 @ case 24
	.4byte _08078AC0 @ case 25
	.4byte _08078AC0 @ case 26
	.4byte _08078AC0 @ case 27
	.4byte _08078AC0 @ case 28
	.4byte _08078AC0 @ case 29
	.4byte _08078BB6 @ case 30
_08078A9C:
	adds r0, r5, #0
	bl FUN_0807868c
	cmp r0, #0
	beq _08078AA8
	b _08078BB6
_08078AA8:
	movs r4, #0
	b _08078BB6
_08078AAC:
	adds r0, r5, #0
	bl FUN_08078844
	cmp r0, #0
	beq _08078AB8
	b _08078BB6
_08078AB8:
	movs r0, #0xda
	bl PlaySound_082406e0
	b _08078AA8
_08078AC0:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _08078AD4
	ldr r2, _08078B18 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078AD4
	movs r1, #1
_08078AD4:
	cmp r1, #0
	beq _08078B1C
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078AF8
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08078AA8
_08078AF8:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08078AA8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	b _08078BA8
	.align 2, 0
_08078B18: .4byte 0x00000442
_08078B1C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08078B64
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r5, #0
	bl FUN_08060ed8
	cmp r0, #0
	bne _08078B52
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060ed8
	cmp r0, #0
	beq _08078B60
	ldr r2, _08078B5C @ =0x00000A75
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _08078B60
_08078B52:
	movs r4, #0
	adds r0, r5, #0
	bl FUN_08060ee8
	b _08078BB6
	.align 2, 0
_08078B5C: .4byte 0x00000A75
_08078B60:
	movs r4, #3
	b _08078BB6
_08078B64:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078B92
	adds r0, r5, #0
	bl FUN_080788b0
	cmp r0, #0
	beq _08078B80
	movs r0, #0xda
	bl PlaySound_082406e0
	movs r4, #6
	b _08078BB6
_08078B80:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r4, #7
	cmp r0, #0
	beq _08078BB6
	b _08078AA8
_08078B92:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08078BA6
	b _08078AA8
_08078BA6:
	ldrh r1, [r2]
_08078BA8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078BB4
	b _08078AA8
_08078BB4:
	movs r4, #1
_08078BB6:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
