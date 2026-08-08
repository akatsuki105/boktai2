	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08074F00 @ =0x0000049C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0x94
	lsls r3, r3, #3
	adds r7, r6, r3
	movs r0, #0
	ldrsh r4, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	cmp r0, #0x51
	bgt _08074F8C
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r6, #0x2c]
	ldrh r0, [r7]
	strh r0, [r6, #0x30]
	ldr r4, _08074F04 @ =0x000004A9
	adds r1, r6, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08074F08
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xff
	b _08074F22
	.align 2, 0
_08074F00: .4byte 0x0000049C
_08074F04: .4byte 0x000004A9
_08074F08:
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r4, #0xba
	lsls r4, r4, #2
	adds r1, r6, r4
_08074F22:
	strb r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08074F54
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08074F4C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08074F50 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08074F64
	.align 2, 0
_08074F4C: .4byte 0x000002E6
_08074F50: .4byte 0x000002E7
_08074F54:
	lsrs r1, r1, #0x19
	ldr r4, _08074F80 @ =0x000002E6
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08074F84 @ =0x000002E7
	adds r0, r6, r1
	strb r2, [r0]
_08074F64:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, _08074F88 @ =FUN_08074d90
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08075028
	.align 2, 0
_08074F80: .4byte 0x000002E6
_08074F84: .4byte 0x000002E7
_08074F88: .4byte FUN_08074d90
_08074F8C:
	ldr r2, _08074FAC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	blt _08074FB0
	asrs r0, r0, #0xc
	b _08074FB6
	.align 2, 0
_08074FAC: .4byte 0x085B0A08
_08074FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08074FB6:
	strh r0, [r6, #0x34]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	blt _08074FD0
	asrs r0, r0, #0xc
	b _08074FD6
_08074FD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08074FD6:
	strh r0, [r6, #0x38]
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r6, r3
	strb r0, [r2]
	lsls r1, r0, #0x18
	cmp r0, #4
	bls _08075018
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r4, _08075010 @ =0x000002E6
	adds r1, r6, r4
	strb r0, [r1]
	ldr r0, _08075014 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _08075026
	.align 2, 0
_08075010: .4byte 0x000002E6
_08075014: .4byte 0x000002E7
_08075018:
	lsrs r1, r1, #0x19
	ldr r2, _0807507C @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08075080 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #0
_08075026:
	strb r0, [r1]
_08075028:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807507C @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075084
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807508C
	.align 2, 0
_0807507C: .4byte 0x000002E6
_08075080: .4byte 0x000002E7
_08075084:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807508C:
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
	beq _080750B0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080750B8
_080750B0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080750B8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080750F0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075128
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080750F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080750E8
	ldrb r0, [r4, #5]
_080750E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075104
	.align 2, 0
_080750F0: .4byte 0x0000FFFF
_080750F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075104
	strh r1, [r4, #8]
_08075104:
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
	bne _08075128
	movs r0, #1
	strb r0, [r4, #7]
_08075128:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
