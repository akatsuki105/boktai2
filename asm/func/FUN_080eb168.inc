	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080EB17C
	b _080EB294
_080EB17C:
	movs r2, #0x10
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _080EB192
	movs r0, #1
	b _080EB194
_080EB192:
	movs r0, #0
_080EB194:
	cmp r0, #0
	beq _080EB208
	ldr r1, _080EB1AC @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EB1B0
	ldr r0, [r4, #0x44]
	adds r7, r0, #0
	adds r7, #0x1c
	b _080EB1B6
	.align 2, 0
_080EB1AC: .4byte 0x0000025D
_080EB1B0:
	ldr r0, [r4, #0x44]
	adds r7, r0, #0
	adds r7, #0x40
_080EB1B6:
	ldr r6, _080EB1FC @ =0x0203B400
	ldr r4, _080EB200 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080EB204 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r7]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r7]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r7, #4]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r7, #4]
	movs r0, #0x11
	rsbs r0, r0, #0
	b _080EB27C
	.align 2, 0
_080EB1FC: .4byte 0x0203B400
_080EB200: .4byte 0x030046B8
_080EB204: .4byte 0x000003FF
_080EB208:
	movs r1, #0x20
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080EB218
	movs r0, #1
	b _080EB21A
_080EB218:
	movs r0, #0
_080EB21A:
	cmp r0, #0
	beq _080EB294
	ldr r1, _080EB230 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EB234
	ldr r0, [r4, #0x44]
	adds r7, r0, #0
	adds r7, #0x1c
	b _080EB23A
	.align 2, 0
_080EB230: .4byte 0x0000025D
_080EB234:
	ldr r0, [r4, #0x44]
	adds r7, r0, #0
	adds r7, #0x40
_080EB23A:
	ldr r6, _080EB288 @ =0x0203B400
	ldr r4, _080EB28C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080EB290 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	ldrh r1, [r7]
	subs r1, #8
	adds r1, r1, r0
	strh r1, [r7]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	ldrh r1, [r7, #4]
	subs r1, #8
	adds r1, r1, r0
	strh r1, [r7, #4]
	movs r0, #0x21
	rsbs r0, r0, #0
_080EB27C:
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	b _080EB296
	.align 2, 0
_080EB288: .4byte 0x0203B400
_080EB28C: .4byte 0x030046B8
_080EB290: .4byte 0x000003FF
_080EB294:
	movs r0, #0
_080EB296:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
