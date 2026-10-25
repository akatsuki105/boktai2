	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov sb, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802EDD6
	movs r0, #0
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x50
	ldr r1, _0802ED98 @ =0x0000085C
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sb
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r5, _0802ED9C @ =0x00000854
	adds r2, r4, r5
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _0802EDA0 @ =0x00000899
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	mov r6, sb
	movs r5, #8
	ldrsh r1, [r6, r5]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r2, r4, #0
	adds r2, #0xa1
	strb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0802EDA8
	ldr r6, _0802EDA4 @ =0x00000824
	adds r0, r4, r6
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EDB8
	movs r3, #0
	b _0802EDB8
	.align 2, 0
_0802ED98: .4byte 0x0000085C
_0802ED9C: .4byte 0x00000854
_0802EDA0: .4byte 0x00000899
_0802EDA4: .4byte 0x00000824
_0802EDA8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EDB8
	movs r3, #5
_0802EDB8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r6, #0xb5
	lsls r6, r6, #2
	adds r2, r7, r6
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
	b _0802EE62
_0802EDD6:
	ldr r0, _0802EE30 @ =0x00000899
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r2, r4, #0
	adds r2, #0xa1
	strb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0802EE38
	ldr r1, _0802EE34 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EE48
	movs r3, #0
	b _0802EE48
	.align 2, 0
_0802EE30: .4byte 0x00000899
_0802EE34: .4byte 0x00000824
_0802EE38:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EE48
	movs r3, #5
_0802EE48:
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
_0802EE62:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _0802EEEC @ =0x00000167
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _0802EEF0 @ =0x0001000C
	adds r2, r4, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	mov r6, r8
	cmp r6, #1
	bgt _0802EE94
	movs r0, #0x10
	orrs r1, r0
	str r1, [r2]
_0802EE94:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802EF56
	mov r2, r8
	cmp r2, #8
	bgt _0802EF48
	ldrb r0, [r5]
	adds r0, #5
	lsls r0, r0, #0x1d
	lsrs r2, r0, #0x18
	movs r0, #1
	mov r5, r8
	ands r0, r5
	adds r3, r2, #0
	adds r3, #0x60
	cmp r0, #0
	beq _0802EEC6
	subs r3, #0xc0
_0802EEC6:
	movs r0, #8
	mov r6, r8
	subs r0, r0, r6
	add r5, sp, #0xc
	lsls r6, r0, #4
	ldr r2, _0802EEF4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802EEF8
	asrs r1, r0, #0xc
	b _0802EEFE
	.align 2, 0
_0802EEEC: .4byte 0x00000167
_0802EEF0: .4byte 0x0001000C
_0802EEF4: .4byte gSineTable
_0802EEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EEFE:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802EF1A
	asrs r0, r0, #0xc
	b _0802EF20
_0802EF1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802EF20:
	strh r0, [r5, #4]
	mov r3, sb
	adds r3, #8
	ldr r5, _0802EF64 @ =0x00000854
	adds r1, r7, r5
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r6, [r1]
	adds r0, r0, r6
	mov r5, sb
	strh r0, [r5, #8]
	ldrh r0, [r2, #2]
	ldrh r6, [r1, #2]
	adds r0, r0, r6
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_0802EF48:
	mov r0, r8
	cmp r0, #0xf
	ble _0802EF56
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802EF56:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EF64: .4byte 0x00000854
