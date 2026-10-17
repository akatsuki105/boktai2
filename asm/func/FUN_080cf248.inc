	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _080CF2F8 @ =0x0000D495
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r0, _080CF2FC @ =0x0000922E
	ldr r1, _080CF300 @ =0x0000AF44
	bl GetFile
	mov r8, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r6, r7, #0
	adds r6, #0xe8
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [r0]
	movs r5, #0
	ldr r2, _080CF304 @ =0x00001001
	adds r0, r6, #0
	adds r1, r4, #0
	bl AuxSprite_Add
	ldrh r1, [r7, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r0, [r7, #0x2e]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r7, #0x30]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080CF308 @ =0x000003F6
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r1, _080CF30C @ =0x000002E6
	adds r0, r7, r1
	ldrb r3, [r0]
	subs r2, #0x55
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080CF310
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080CF318
	.align 2, 0
_080CF2F8: .4byte 0x0000D495
_080CF2FC: .4byte 0x0000922E
_080CF300: .4byte 0x0000AF44
_080CF304: .4byte 0x00001001
_080CF308: .4byte 0x000003F6
_080CF30C: .4byte 0x000002E6
_080CF310:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CF318:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080CF33C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080CF344
_080CF33C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CF344:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CF37C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CF3B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CF380
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CF374
	ldrb r0, [r4, #5]
_080CF374:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CF390
	.align 2, 0
_080CF37C: .4byte 0x0000FFFF
_080CF380:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CF390
	strh r1, [r4, #8]
_080CF390:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080CF3B4
	movs r0, #1
	strb r0, [r4, #7]
_080CF3B4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
