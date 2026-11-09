	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, [sp]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081909A2
	b _08190ACA
_081909A2:
	movs r0, #0
	mov sl, r0
	ldr r0, _081909D4 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081909B4
	b _08190ACA
_081909B4:
	ldr r7, _081909D8 @ =0x00000676
	add r7, sb
	ldr r6, _081909DC @ =0x00000674
	add r6, sb
	ldr r2, _081909E0 @ =0x0000077A
	add r2, sb
	mov r8, r2
_081909C2:
	movs r1, #2
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081909E4
	movs r0, #1
	b _081909E6
	.align 2, 0
_081909D4: .4byte 0x00000F36
_081909D8: .4byte 0x00000676
_081909DC: .4byte 0x00000674
_081909E0: .4byte 0x0000077A
_081909E4:
	movs r0, #0
_081909E6:
	cmp r0, #0
	beq _08190AAE
	movs r1, #1
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081909FA
	movs r0, #1
	b _081909FC
_081909FA:
	movs r0, #0
_081909FC:
	cmp r0, #0
	bne _08190AAE
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08190A24
	cmp r1, #0
	blt _08190A24
	ldr r0, _08190A28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08190A24
	ldr r0, _08190A2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08190A30
_08190A24:
	movs r4, #0
	b _08190A3E
	.align 2, 0
_08190A28: .4byte 0x030046A8
_08190A2C: .4byte 0x030046AC
_08190A30:
	ldr r0, _08190A50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08190A3E:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08190A54
	adds r0, #4
	b _08190A60
	.align 2, 0
_08190A50: .4byte 0x030046A4
_08190A54:
	ldr r0, _08190A74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08190A60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08190A78
	cmp r2, #2
	beq _08190A7C
	b _08190A80
	.align 2, 0
_08190A74: .4byte 0x030046A4
_08190A78:
	ldrb r0, [r5, #4]
	b _08190A7E
_08190A7C:
	ldrb r0, [r5]
_08190A7E:
	subs r1, r1, r0
_08190A80:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r0, r1
	beq _08190AAE
	cmp r0, r1
	bge _08190AA0
	subs r0, r1, r0
	cmp r0, #0
	bge _08190A94
	rsbs r0, r0, #0
_08190A94:
	cmp r0, #0xff
	ble _08190AAC
	ldr r1, [sp]
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _08190AAE
_08190AA0:
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
_08190AAC:
	strh r1, [r7]
_08190AAE:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r7, r7, r2
	adds r6, r6, r2
	add r8, r2
	movs r3, #1
	add sl, r3
	ldr r0, _08190ADC @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08190ACA
	b _081909C2
_08190ACA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190ADC: .4byte 0x00000F36
