	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _080D8800
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D87B0
	movs r0, #1
	b _080D87B2
_080D87B0:
	movs r0, #0
_080D87B2:
	cmp r0, #0
	beq _080D884A
	adds r0, r5, #0
	bl FUN_080d8644
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x24]
	str r0, [r5, #0x48]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r4, [r0]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r2, _080D87FC @ =0x000009FC
	add r2, r8
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	movs r0, #1
	b _080D884C
	.align 2, 0
_080D87FC: .4byte 0x000009FC
_080D8800:
	cmp r0, #0xa
	ble _080D883E
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D8816
	movs r0, #1
	b _080D8818
_080D8816:
	movs r0, #0
_080D8818:
	cmp r0, #0
	beq _080D883E
	ldr r2, _080D8858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D885C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D8860 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
_080D883E:
	adds r0, r5, #0
	bl FUN_080d866c
	ldrh r0, [r5, #0x3c]
	subs r0, #1
	strh r0, [r5, #0x3c]
_080D884A:
	movs r0, #0
_080D884C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D8858: .4byte 0x030046B8
_080D885C: .4byte 0x000003FF
_080D8860: .4byte 0x0203B400
