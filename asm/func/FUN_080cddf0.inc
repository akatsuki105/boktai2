	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r5
	ldr r0, _080CDE44 @ =0x000004C7
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	adds r0, r4, #0
	bl PlayerLink_GetMashCount
	ldr r2, _080CDE48 @ =0x085AD148
	ldr r1, _080CDE4C @ =0x000004C5
	adds r6, r4, r1
	ldrb r1, [r6]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	blt _080CDE32
	adds r0, r4, #0
	bl FUN_080cdc6c
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_080CDE32:
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	ldrb r0, [r6]
	cmp r0, #1
	bne _080CDE50
	movs r5, #3
	b _080CDE5E
	.align 2, 0
_080CDE44: .4byte 0x000004C7
_080CDE48: .4byte 0x085AD148
_080CDE4C: .4byte 0x000004C5
_080CDE50:
	cmp r0, #2
	bne _080CDE58
	movs r5, #4
	b _080CDE5E
_080CDE58:
	cmp r0, #3
	bne _080CDE5E
	movs r5, #5
_080CDE5E:
	cmp r5, r8
	bne _080CDE8C
	ldr r0, _080CDE84 @ =0x00000954
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDE9A
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDE7E
	ldr r1, _080CDE88 @ =0x00000952
	adds r0, r4, r1
	ldrh r5, [r0]
_080CDE7E:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDE9A
	.align 2, 0
_080CDE84: .4byte 0x00000954
_080CDE88: .4byte 0x00000952
_080CDE8C:
	ldr r2, _080CDEA8 @ =0x00000952
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, _080CDEAC @ =0x00000954
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_080CDE9A:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDEA8: .4byte 0x00000952
_080CDEAC: .4byte 0x00000954
