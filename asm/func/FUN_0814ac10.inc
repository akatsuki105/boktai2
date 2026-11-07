	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814AC2C
	b _0814AE78
_0814AC2C:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0814AC46
	asrs r0, r1, #6
	b _0814AC4C
_0814AC46:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814AC4C:
	lsls r4, r0, #6
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _0814AC64
	movs r0, #1
	b _0814AC66
_0814AC64:
	movs r0, #0
_0814AC66:
	cmp r0, #0
	beq _0814ACC0
	ldr r2, _0814AC88 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r3, r2, #0
	cmp r0, #0
	blt _0814AC8C
	asrs r2, r0, #0xc
	b _0814AC92
	.align 2, 0
_0814AC88: .4byte gSineTable
_0814AC8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814AC92:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814ACBC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	bge _0814AD10
	b _0814AD18
	.align 2, 0
_0814ACBC: .4byte 0xFFFF0000
_0814ACC0:
	ldr r2, _0814ACE0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r3, r2, #0
	cmp r0, #0
	blt _0814ACE4
	asrs r2, r0, #0xc
	b _0814ACEA
	.align 2, 0
_0814ACE0: .4byte gSineTable
_0814ACE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814ACEA:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814AD14 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0814AD18
_0814AD10:
	asrs r2, r0, #0xc
	b _0814AD1E
	.align 2, 0
_0814AD14: .4byte 0xFFFF0000
_0814AD18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814AD1E:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814AD58 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0814AD5C @ =0x0000069A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r4, #0
	blt _0814AD60
	asrs r0, r4, #6
	b _0814AD66
	.align 2, 0
_0814AD58: .4byte 0xFFFF0000
_0814AD5C: .4byte 0x0000069A
_0814AD60:
	rsbs r0, r4, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814AD66:
	cmp r0, #1
	beq _0814ADC4
	cmp r0, #1
	bgt _0814AD74
	cmp r0, #0
	beq _0814AD7E
	b _0814AE08
_0814AD74:
	cmp r0, #2
	beq _0814AD7E
	cmp r0, #3
	beq _0814ADC4
	b _0814AE08
_0814AD7E:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814AD8C
	movs r0, #1
	b _0814AD8E
_0814AD8C:
	movs r0, #0
_0814AD8E:
	cmp r0, #0
	beq _0814ADAA
	ldr r3, _0814ADC0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #4]
_0814ADAA:
	ldr r3, _0814ADC0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x78
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0814AE04
	.align 2, 0
_0814ADC0: .4byte 0xFFFF0000
_0814ADC4:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814ADD2
	movs r0, #1
	b _0814ADD4
_0814ADD2:
	movs r0, #0
_0814ADD4:
	cmp r0, #0
	beq _0814ADF0
	ldr r3, _0814AE50 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [r2, #4]
_0814ADF0:
	ldr r3, _0814AE50 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x78
_0814AE04:
	orrs r0, r1
	str r0, [r2, #4]
_0814AE08:
	ldr r1, _0814AE54 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	adds r0, #0xd8
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814AE58
	movs r0, #1
	b _0814AE5A
	.align 2, 0
_0814AE50: .4byte 0xFFFF0000
_0814AE54: .4byte 0x0000FFFF
_0814AE58:
	movs r0, #0
_0814AE5A:
	cmp r0, #0
	beq _0814AE6A
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	b _0814AE74
_0814AE6A:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
_0814AE74:
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_0814AE78:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
