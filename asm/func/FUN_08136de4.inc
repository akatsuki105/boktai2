	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r1, #0
	str r2, [sp]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0
	mov ip, r0
	ldr r1, _08136E38 @ =0x00000B3A
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08136E10
	b _08136F0C
_08136E10:
	ldr r0, _08136E3C @ =gSineTable
	mov sb, r0
	movs r6, #0
	ldr r1, _08136E40 @ =0x0000075A
	adds r3, r5, r1
	adds r4, r5, #0
	movs r0, #0x90
	lsls r0, r0, #1
	mov r8, r0
_08136E22:
	adds r0, r6, r5
	ldr r1, _08136E44 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08136E48
	movs r0, #1
	b _08136E4A
	.align 2, 0
_08136E38: .4byte 0x00000B3A
_08136E3C: .4byte gSineTable
_08136E40: .4byte 0x0000075A
_08136E44: .4byte 0x00000755
_08136E48:
	movs r0, #0
_08136E4A:
	cmp r0, #0
	beq _08136EF6
	adds r0, r6, r5
	ldr r1, _08136E64 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136E68
	movs r0, #1
	b _08136E6A
	.align 2, 0
_08136E64: .4byte 0x00000755
_08136E68:
	movs r0, #0
_08136E6A:
	cmp r0, #0
	bne _08136EF6
	mov r0, sl
	cmp r0, #0
	bne _08136E98
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08136E88
	asrs r2, r0, #0xc
	b _08136E8E
_08136E88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136E8E:
	ldr r0, _08136E94 @ =0x0000076E
	b _08136EE6
	.align 2, 0
_08136E94: .4byte 0x0000076E
_08136E98:
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08136EB2
	asrs r2, r0, #0xc
	b _08136EB8
_08136EB2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136EB8:
	ldr r0, _08136ED8 @ =0x0000076C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08136EDC
	asrs r2, r0, #0xc
	b _08136EE2
	.align 2, 0
_08136ED8: .4byte 0x0000076C
_08136EDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08136EE2:
	movs r0, #0xee
	lsls r0, r0, #3
_08136EE6:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_08136EF6:
	add r6, r8
	add r3, r8
	add r4, r8
	movs r0, #1
	add ip, r0
	ldr r1, _08136F1C @ =0x00000B3A
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08136E22
_08136F0C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136F1C: .4byte 0x00000B3A
