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
	ldr r1, _08177AA0 @ =0x00001012
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08177A78
	b _08177B74
_08177A78:
	ldr r0, _08177AA4 @ =gSineTable
	mov sb, r0
	adds r4, r5, #0
	movs r6, #0
	ldr r1, _08177AA8 @ =0x0000075A
	adds r3, r5, r1
	movs r0, #0x92
	lsls r0, r0, #1
	mov r8, r0
_08177A8A:
	adds r0, r6, r5
	ldr r1, _08177AAC @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08177AB0
	movs r0, #1
	b _08177AB2
	.align 2, 0
_08177AA0: .4byte 0x00001012
_08177AA4: .4byte gSineTable
_08177AA8: .4byte 0x0000075A
_08177AAC: .4byte 0x00000755
_08177AB0:
	movs r0, #0
_08177AB2:
	cmp r0, #0
	beq _08177B5E
	adds r0, r6, r5
	ldr r1, _08177ACC @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08177AD0
	movs r0, #1
	b _08177AD2
	.align 2, 0
_08177ACC: .4byte 0x00000755
_08177AD0:
	movs r0, #0
_08177AD2:
	cmp r0, #0
	bne _08177B5E
	mov r0, sl
	cmp r0, #0
	bne _08177B00
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08177AF0
	asrs r2, r0, #0xc
	b _08177AF6
_08177AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177AF6:
	ldr r0, _08177AFC @ =0x0000076E
	b _08177B4E
	.align 2, 0
_08177AFC: .4byte 0x0000076E
_08177B00:
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
	blt _08177B1A
	asrs r2, r0, #0xc
	b _08177B20
_08177B1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177B20:
	ldr r0, _08177B40 @ =0x0000076C
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
	blt _08177B44
	asrs r2, r0, #0xc
	b _08177B4A
	.align 2, 0
_08177B40: .4byte 0x0000076C
_08177B44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08177B4A:
	movs r0, #0xee
	lsls r0, r0, #3
_08177B4E:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_08177B5E:
	add r4, r8
	add r6, r8
	add r3, r8
	movs r0, #1
	add ip, r0
	ldr r1, _08177B84 @ =0x00001012
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _08177A8A
_08177B74:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177B84: .4byte 0x00001012
