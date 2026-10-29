	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EF760 @ =0x030001DC
	ldr r3, [r0]
	cmp r3, #0
	bne _081EF72E
	bl Entity081efa9c_Create
	adds r3, r0, #0
	cmp r3, #0
	beq _081EF75A
_081EF72E:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EF764 @ =0x030047A4
	ldr r1, _081EF768 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EF75A
	movs r1, #4
	ldr r0, _081EF76C @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081EF75A
	adds r0, r3, #0
	bl Entity081efa9c_AllocElem
	adds r6, r0, #0
	cmp r6, #0
	bne _081EF770
_081EF75A:
	movs r0, #0
	b _081EF98A
	.align 2, 0
_081EF760: .4byte 0x030001DC
_081EF764: .4byte 0x030047A4
_081EF768: .4byte 0x030047A0
_081EF76C: .4byte 0x03002BC0
_081EF770:
	adds r0, r6, #0
	adds r0, #0xba
	movs r3, #0
	strh r4, [r0]
	adds r0, #0xa
	movs r4, #1
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r6, #0
	adds r1, #0xc6
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
	subs r1, #0xf
	ldr r0, [sp, #0x34]
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc0
	mov r2, r8
	str r2, [r0]
	adds r0, #5
	strb r3, [r0]
	ldrb r0, [r1]
	str r1, [sp, #4]
	cmp r0, #0
	bne _081EF7B4
	adds r0, r6, #0
	adds r0, #0xbc
	strb r4, [r0]
	b _081EF7BC
_081EF7B4:
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #2
	strb r0, [r1]
_081EF7BC:
	adds r7, r6, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x3c
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	ldr r0, _081EF844 @ =0x0000922E
	mov r2, sl
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r4, r6, #0
	adds r4, #0xa8
	str r0, [r4]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	subs r5, #0x10
	ldr r1, [r4]
	ldr r2, [sp, #0x28]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x3c]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #0x40]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl AuxAnim_SetAnim
	ldr r0, [r6, #0xc]
	ldr r1, [sp, #0x38]
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EF848
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081EF850
	.align 2, 0
_081EF844: .4byte 0x0000922E
_081EF848:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EF850:
	str r0, [r6]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EF874
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081EF87C
_081EF874:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EF87C:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081EF8B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081EF8EC
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EF8B8
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081EF8AC
	ldrb r0, [r5, #5]
_081EF8AC:
	subs r0, #1
	strh r0, [r5, #8]
	b _081EF8C8
	.align 2, 0
_081EF8B4: .4byte 0x0000FFFF
_081EF8B8:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081EF8C8
	strh r1, [r5, #8]
_081EF8C8:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081EF8EC
	movs r0, #1
	strb r0, [r5, #7]
_081EF8EC:
	ldr r0, [r7]
	movs r4, #1
	orrs r0, r4
	strb r4, [r7, #7]
	ldr r1, [sp, #0x30]
	orrs r0, r1
	str r0, [r7]
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _081EF968
	ldr r3, _081EF938 @ =0x0203B400
	ldr r1, _081EF93C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081EF940 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r7, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x7f
	bgt _081EF944
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	b _081EF94A
	.align 2, 0
_081EF938: .4byte 0x0203B400
_081EF93C: .4byte 0x030046B8
_081EF940: .4byte 0x000003FF
_081EF944:
	adds r0, r6, #0
	adds r0, #0xb5
	strb r4, [r0]
_081EF94A:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EF99C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081EF9A0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	adds r1, r6, #0
	adds r1, #0xb6
	strb r0, [r1]
_081EF968:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	ble _081EF988
	ldr r0, [sp, #0x50]
	str r0, [sp]
	adds r0, r6, #0
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x48]
	ldr r3, [sp, #0x4c]
	bl Entity081efa9c_InitHitbox
	ldr r2, [sp, #4]
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_081EF988:
	adds r0, r6, #0
_081EF98A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EF99C: .4byte 0x000003FF
_081EF9A0: .4byte 0x0203B400
