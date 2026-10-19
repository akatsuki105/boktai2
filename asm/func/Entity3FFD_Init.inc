	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	movs r0, #0x1c
	add r0, r8
	mov sb, r0
	mov r7, r8
	adds r7, #0x38
	movs r6, #0xcc
	lsls r6, r6, #1
	add r6, r8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081FA3DC
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _081FA3D4 @ =0xFFFF0000
	adds r4, r5, #0
	ldr r1, [sp, #4]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r1, _081FA3D8 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #8]
	ands r5, r2
	orrs r5, r0
	str r5, [sp, #8]
	b _081FA3EE
	.align 2, 0
_081FA3D4: .4byte 0xFFFF0000
_081FA3D8: .4byte 0x0000FFFF
_081FA3DC:
	ldr r0, _081FA45C @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r0
	str r3, [sp, #4]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, [sp, #8]
	ands r2, r0
	str r2, [sp, #8]
_081FA3EE:
	ldr r0, _081FA460 @ =0x0000922E
	ldr r1, _081FA464 @ =0x0000C102
	bl GetFile
	movs r4, #0xd4
	lsls r4, r4, #1
	add r4, r8
	str r0, [r4]
	ldr r1, _081FA468 @ =0x0000D636
	mov r0, sb
	bl Video_GetAuxSprite
	ldr r1, [r4]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r5, #1
	movs r4, #7
	movs r3, #2
	mov sl, r3
_081FA41E:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r3, r1, r0
	ldrh r0, [r3]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	adds r2, r5, #0
	ands r2, r0
	ldrh r1, [r3]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r5
	cmp r2, r0
	beq _081FA46C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081FA474
	.align 2, 0
_081FA45C: .4byte 0xFFFF0000
_081FA460: .4byte 0x0000922E
_081FA464: .4byte 0x0000C102
_081FA468: .4byte 0x0000D636
_081FA46C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081FA474:
	str r0, [r7]
	ldrb r0, [r6, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r3]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081FA498
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081FA4A0
_081FA498:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081FA4A0:
	str r0, [r7]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r6, #0xe]
	ldr r3, _081FA4D8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r6, #7]
	cmp r0, r3
	blo _081FA50E
	strh r1, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081FA4DC
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081FA4D0
	ldrb r0, [r6, #5]
_081FA4D0:
	subs r0, #1
	strh r0, [r6, #8]
	b _081FA4EC
	.align 2, 0
_081FA4D8: .4byte 0x0000FFFF
_081FA4DC:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081FA4EC
	strh r1, [r6, #8]
_081FA4EC:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r3, r1, r0
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081FA50E
	strb r5, [r6, #7]
_081FA50E:
	adds r7, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _081FA41E
	movs r0, #0
	mov r3, r8
	str r0, [r3, #0x18]
	movs r1, #0xf9
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf7
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf6
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
