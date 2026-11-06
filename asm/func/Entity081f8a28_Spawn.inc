	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r0
	adds r6, r1, #0
	mov sb, r2
	adds r4, r3, #0
	ldr r0, _081F87E4 @ =0x03000208
	ldr r5, [r0]
	cmp r5, #0
	bne _081F86DC
	bl Entity081f8a28_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _081F86DC
	b _081F8910
_081F86DC:
	adds r0, r5, #0
	bl Entity081f8a28_AllocElem
	adds r7, r0, #0
	cmp r7, #0
	bne _081F86EA
	b _081F8910
_081F86EA:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r1, r8
	strb r1, [r0]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x78
	str r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	subs r1, #0x14
	adds r0, r7, r1
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _081F87E8 @ =0x00000109
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	ldr r0, _081F87EC @ =0x0000010B
	adds r1, r7, r0
	ldr r0, [sp, #0x44]
	strb r0, [r1]
	adds r2, #0x19
	adds r1, r7, r2
	ldr r0, [sp, #0x48]
	strb r0, [r1]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x4c]
	strh r0, [r1]
	subs r2, #0x15
	adds r1, r7, r2
	ldr r0, [sp, #0x50]
	strh r0, [r1]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xf8
	movs r0, #0
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldr r2, _081F87F0 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #0xfa
	mov r1, sb
	strh r1, [r0]
	mov sb, r7
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _081F87F4 @ =0x0000922E
	ldr r1, _081F87F8 @ =0x0000121B
	bl GetFile
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r4, r7, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	movs r2, #0
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
	movs r1, #0xd9
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _081F87FC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F8804
	.align 2, 0
_081F87E4: .4byte 0x03000208
_081F87E8: .4byte 0x00000109
_081F87EC: .4byte 0x0000010B
_081F87F0: .4byte 0x05000002
_081F87F4: .4byte 0x0000922E
_081F87F8: .4byte 0x0000121B
_081F87FC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F8804:
	str r0, [r7]
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
	beq _081F8828
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F8830
_081F8828:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F8830:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F8868 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F88A0
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F886C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F8860
	ldrb r0, [r5, #5]
_081F8860:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F887C
	.align 2, 0
_081F8868: .4byte 0x0000FFFF
_081F886C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F887C
	strh r1, [r5, #8]
_081F887C:
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
	bne _081F88A0
	movs r0, #1
	strb r0, [r5, #7]
_081F88A0:
	movs r4, #0
	movs r0, #2
	mov r1, sb
	strb r0, [r1, #7]
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x60]
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x54]
	ldr r2, [sp, #0x58]
	ldr r3, [sp, #0x5c]
	bl Entity081f8a28_InitHitbox
	adds r5, r7, #0
	adds r5, #0x3c
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r2, _081F8920 @ =0x00000111
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081F8924 @ =0x00001C1B
	adds r0, r5, #0
	movs r2, #6
	bl AuxShadow_SetSprite
	adds r0, r5, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r5, #0
	bl AuxShadow_Hide
_081F8910:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F8920: .4byte 0x00000111
_081F8924: .4byte 0x00001C1B
