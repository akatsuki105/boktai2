	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _080567A4 @ =0x03000128
	ldr r1, [r1]
	mov r8, r1
	cmp r1, #0
	bne _080567A8
	bl DustManager_Create
	mov r8, r0
	cmp r0, #0
	bne _080567A8
	movs r0, #1
	rsbs r0, r0, #0
	b _080569E2
	.align 2, 0
_080567A4: .4byte 0x03000128
_080567A8:
	ldr r1, [sp, #0x58]
	cmp r1, #1
	beq _080567D2
	cmp r1, #1
	bgt _080567B8
	cmp r1, #0
	beq _080567C2
	b _080567F4
_080567B8:
	ldr r2, [sp, #0x58]
	cmp r2, #2
	beq _080567E2
	cmp r2, #3
	bne _080567F4
_080567C2:
	movs r3, #3
	str r3, [sp, #0x20]
	movs r5, #0x89
	lsls r5, r5, #2
	str r5, [sp, #0x24]
	movs r1, #2
	str r1, [sp, #0x28]
	b _08056802
_080567D2:
	movs r2, #6
	str r2, [sp, #0x20]
	movs r3, #0x8b
	lsls r3, r3, #2
	str r3, [sp, #0x24]
	movs r5, #1
	str r5, [sp, #0x28]
	b _08056802
_080567E2:
	movs r1, #8
	str r1, [sp, #0x20]
	ldr r2, _080567F0 @ =0x0000023A
	str r2, [sp, #0x24]
	movs r3, #2
	str r3, [sp, #0x28]
	b _08056802
	.align 2, 0
_080567F0: .4byte 0x0000023A
_080567F4:
	movs r5, #3
	str r5, [sp, #0x20]
	movs r1, #0x89
	lsls r1, r1, #2
	str r1, [sp, #0x24]
	movs r2, #2
	str r2, [sp, #0x28]
_08056802:
	ldr r3, [sp, #0xc]
	asrs r3, r3, #1
	str r3, [sp, #0x18]
	ldr r5, [sp, #0x4c]
	asrs r5, r5, #1
	str r5, [sp, #0x1c]
	movs r1, #0
	str r1, [sp, #0x14]
	mov r4, r8
	adds r4, #0x2c
	mov sl, r1
	movs r2, #0x40
	add r2, r8
	mov sb, r2
_0805681E:
	movs r2, #1
	mov r3, sl
	lsls r2, r3
	mov r5, r8
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _08056830
	b _080569D0
_08056830:
	adds r7, r4, #0
	adds r7, #0x30
	add r0, sp, #0x58
	ldrb r0, [r0]
	strb r0, [r4, #8]
	movs r1, #0
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r4]
	ldr r3, [sp, #0x58]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08056850
	cmp r0, #3
	bne _08056854
_08056850:
	strb r1, [r4, #2]
	b _08056858
_08056854:
	movs r5, #1
	strb r5, [r4, #2]
_08056858:
	movs r0, #0
	strh r0, [r4, #6]
	add r1, sp, #0x54
	ldrb r1, [r1]
	strb r1, [r4, #5]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08056870
	mov r3, sp
	ldrb r3, [r3, #8]
	strb r3, [r4, #3]
	b _08056894
_08056870:
	ldr r5, _080568A0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080568A4 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080568A8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #8]
	adds r0, r2, r0
	ldr r3, [sp, #0x18]
	subs r0, r0, r3
	strb r0, [r4, #3]
_08056894:
	ldr r5, [sp, #0x4c]
	cmp r5, #0
	bne _080568AC
	mov r0, sp
	ldrb r0, [r0, #0x10]
	b _080568D0
	.align 2, 0
_080568A0: .4byte 0x030046B8
_080568A4: .4byte 0x000003FF
_080568A8: .4byte 0x0203B400
_080568AC:
	ldr r1, _080568F8 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080568FC @ =0x000003FF
	ands r0, r1
	ldr r2, _080568F8 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08056900 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r5, [sp, #0x10]
	adds r0, r5, r0
	ldr r1, [sp, #0x1c]
	subs r0, r0, r1
_080568D0:
	strb r0, [r4, #4]
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4, #3]
	ldrb r6, [r4, #4]
	ldr r2, _08056904 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056908
	asrs r0, r0, #0xc
	b _0805690E
	.align 2, 0
_080568F8: .4byte 0x030046B8
_080568FC: .4byte 0x000003FF
_08056900: .4byte 0x0203B400
_08056904: .4byte gSineTable
_08056908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805690E:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056926
	asrs r0, r0, #0xc
	b _0805692C
_08056926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805692C:
	strh r0, [r3, #4]
	movs r2, #0
	strh r2, [r4, #0xe]
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r4, #0
	adds r0, #0x5c
	mov r5, r8
	ldr r1, [r5, #0x18]
	ldr r3, [sp, #0x20]
	lsls r2, r3, #0x10
	movs r5, #0
	str r5, [sp]
	lsrs r2, r2, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #0x12
	strh r0, [r7, #0x10]
	add r0, sp, #0x28
	ldrb r0, [r0]
	strb r0, [r7, #7]
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	mov r0, sb
	ldr r1, [sp, #0x24]
	bl Video_SetAuxSpritePltt
	ldrb r1, [r4, #8]
	cmp r1, #0
	bne _080569B6
	adds r3, r4, #0
	adds r3, #0x4c
	mov r1, sb
	movs r5, #0x38
	ldrsh r2, [r1, r5]
	ldr r1, _0805698C @ =0x0000011F
	cmp r2, r1
	bgt _08056990
	adds r1, #1
	mov r2, sb
	strh r1, [r2, #0x38]
	b _0805699A
	.align 2, 0
_0805698C: .4byte 0x0000011F
_08056990:
	movs r1, #0xbe
	lsls r1, r1, #4
	cmp r2, r1
	ble _0805699A
	strh r1, [r3]
_0805699A:
	movs r5, #4
	ldrsh r2, [r3, r5]
	ldr r1, _080569A8 @ =0x0000021F
	cmp r2, r1
	bgt _080569AC
	adds r1, #1
	b _080569B4
	.align 2, 0
_080569A8: .4byte 0x0000021F
_080569AC:
	movs r1, #0xc8
	lsls r1, r1, #4
	cmp r2, r1
	ble _080569B6
_080569B4:
	strh r1, [r3, #4]
_080569B6:
	movs r2, #1
	mov r1, sl
	lsls r2, r1
	mov r3, r8
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
	ldr r5, [sp, #0x14]
	adds r5, #1
	str r5, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r5, r1
	bge _080569E2
_080569D0:
	movs r2, #1
	add sl, r2
	movs r3, #0x6c
	add sb, r3
	adds r4, #0x6c
	mov r5, sl
	cmp r5, #0x1f
	bgt _080569E2
	b _0805681E
_080569E2:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
