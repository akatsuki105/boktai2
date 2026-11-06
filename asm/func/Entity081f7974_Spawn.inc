	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	mov r8, r1
	ldr r0, _081F77E8 @ =0x03000200
	ldr r4, [r0]
	cmp r4, #0
	bne _081F7764
	bl Entity081f7974_Create
	adds r4, r0, #0
	cmp r4, #0
	bne _081F7764
	b _081F789C
_081F7764:
	adds r0, r4, #0
	bl Entity081f7974_AllocElem
	adds r7, r0, #0
	cmp r7, #0
	bne _081F7772
	b _081F789C
_081F7772:
	adds r0, #0x46
	movs r6, #0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strb r2, [r0]
	mov r0, r8
	str r0, [r7, #0x40]
	adds r0, r7, #0
	adds r0, #0x44
	strh r6, [r0]
	adds r5, r7, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, _081F77EC @ =0x0000922E
	ldr r1, _081F77F0 @ =0x0000121B
	bl GetFile
	str r0, [r5, #0x3c]
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x3c]
	str r6, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081F77F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F77FC
	.align 2, 0
_081F77E8: .4byte 0x03000200
_081F77EC: .4byte 0x0000922E
_081F77F0: .4byte 0x0000121B
_081F77F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F77FC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F7820
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F7828
_081F7820:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7828:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F7860 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F7898
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7864
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F7858
	ldrb r0, [r4, #5]
_081F7858:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F7874
	.align 2, 0
_081F7860: .4byte 0x0000FFFF
_081F7864:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F7874
	strh r1, [r4, #8]
_081F7874:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F7898
	movs r0, #1
	strb r0, [r4, #7]
_081F7898:
	movs r0, #3
	strb r0, [r5, #7]
_081F789C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
