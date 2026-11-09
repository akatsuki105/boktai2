	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081388E8
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _08138840 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _08138844
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _0813884C
	.align 2, 0
_08138840: .4byte 0x00000553
_08138844:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_0813884C:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _081388E8
	mov r5, sp
	adds r3, r4, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r5, r3]
	bl ArcTan2_8
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	ldrb r1, [r4, #5]
	adds r1, #0x10
	ands r1, r3
	asrs r1, r1, #6
	cmp r0, r1
	bne _081388E8
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _081388B0
	rsbs r1, r1, #0
_081388B0:
	ldr r0, _081388DC @ =0x000001FF
	cmp r1, r0
	bgt _081388E8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r1, #0x30
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ands r0, r3
	asrs r0, r0, #6
	ldr r3, _081388E0 @ =0x00000B49
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, _081388E4 @ =0x00000B48
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _081388EA
	.align 2, 0
_081388DC: .4byte 0x000001FF
_081388E0: .4byte 0x00000B49
_081388E4: .4byte 0x00000B48
_081388E8:
	movs r0, #0
_081388EA:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
