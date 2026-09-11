	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009CA6
	movs r5, #0
	strb r5, [r6, #7]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08009D20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
_08009CA6:
	ldr r0, [r6, #0x64]
	movs r2, #1
	mov ip, r2
	ands r0, r2
	cmp r0, #0
	beq _08009D24
	ldrh r0, [r6, #0xa]
	adds r1, r0, #1
	strh r1, [r6, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0xc]
	cmp r0, r1
	bhi _08009CC4
	b _08009E20
_08009CC4:
	movs r5, #0
	strh r5, [r6, #0xa]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08009D20 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08009E1E
	.align 2, 0
_08009D18: .4byte 0x030046B8
_08009D1C: .4byte 0x000003FF
_08009D20: .4byte 0x0203B400
_08009D24:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x20]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	mov r1, ip
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, ip
	ands r0, r2
	cmp r1, r0
	beq _08009D6A
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009D72
_08009D6A:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009D72:
	str r0, [r6, #0x64]
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
	beq _08009D96
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009D9E
_08009D96:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009D9E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009DD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08009E10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08009DE2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08009DDC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08009DF8
	.align 2, 0
_08009DD8: .4byte 0x0000FFFF
_08009DDC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08009DF6
_08009DE2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08009DF6
	strh r1, [r4, #8]
	movs r2, #1
	b _08009DF8
_08009DF6:
	movs r2, #0
_08009DF8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _08009E12
_08009E10:
	movs r2, #0
_08009E12:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _08009E20
	ldr r0, [r6, #0x64]
	movs r1, #1
	orrs r0, r1
_08009E1E:
	str r0, [r6, #0x64]
_08009E20:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
