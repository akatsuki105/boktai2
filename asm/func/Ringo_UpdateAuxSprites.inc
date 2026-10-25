	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r5, sp
	mov r2, sl
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08029E30
	asrs r0, r0, #8
	b _08029E36
_08029E30:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E36:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08029E48
	asrs r0, r0, #8
	b _08029E4E
_08029E48:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E4E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08029E62
	asrs r0, r0, #8
	b _08029E68
_08029E62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E68:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08029F18 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	movs r1, #0
	mov sb, r1
	mov r8, sp
	movs r5, #0xb9
	lsls r5, r5, #4
	add r5, sl
	movs r2, #0xb8
	lsls r2, r2, #4
	add r2, sl
	mov ip, r2
	mov r7, sl
_08029E9C:
	mov r4, ip
	ldrb r0, [r4]
	cmp r0, #0
	bne _08029EA6
	b _08029FE6
_08029EA6:
	mov r1, sb
	lsls r0, r1, #3
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r0, r0, r2
	mov r4, sl
	adds r2, r4, r0
	ldr r1, _08029F1C @ =0x00000E5E
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08029ECA
	ldrh r0, [r2, #2]
	subs r0, #1
	strh r0, [r2, #2]
_08029ECA:
	mov r4, r8
	ldrh r0, [r4]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r5, #0x1e]
	mov r1, r8
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	movs r2, #0xe5
	lsls r2, r2, #4
	adds r3, r7, r2
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r3, #4]
	adds r2, r6, #0
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r6
	cmp r2, r0
	beq _08029F20
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08029F28
	.align 2, 0
_08029F18: .4byte 0x030047C8
_08029F1C: .4byte 0x00000E5E
_08029F20:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08029F28:
	str r0, [r5]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r4, #2
	ands r0, r4
	cmp r1, r0
	beq _08029F4C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08029F54
_08029F4C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08029F54:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _08029F8C @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _08029FD2
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08029F96
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _08029F90
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _08029FAC
	.align 2, 0
_08029F8C: .4byte 0x0000FFFF
_08029F90:
	subs r0, #1
	strh r0, [r3, #8]
	b _08029FAA
_08029F96:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08029FAA
	strh r1, [r3, #8]
	movs r2, #1
	b _08029FAC
_08029FAA:
	movs r2, #0
_08029FAC:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029FD4
	movs r0, #1
	strb r0, [r3, #7]
	b _08029FD4
_08029FD2:
	movs r2, #0
_08029FD4:
	cmp r2, #0
	beq _08029FE6
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	mov r4, ip
	strb r0, [r4]
_08029FE6:
	movs r0, #1
	add ip, r0
	adds r7, #0x10
	add sb, r0
	adds r5, #0x2c
	mov r1, sb
	cmp r1, #0xf
	bgt _08029FF8
	b _08029E9C
_08029FF8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
