	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _08074DE8 @ =0x000002E6
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	adds r4, #0xe8
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08074DEC
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _08074DF4
	.align 2, 0
_08074DE8: .4byte 0x000002E6
_08074DEC:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08074DF4:
	str r0, [r4]
	ldrb r0, [r5, #4]
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
	beq _08074E18
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08074E20
_08074E18:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08074E20:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _08074E58 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08074E90
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08074E5C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08074E50
	ldrb r0, [r5, #5]
_08074E50:
	subs r0, #1
	strh r0, [r5, #8]
	b _08074E6C
	.align 2, 0
_08074E58: .4byte 0x0000FFFF
_08074E5C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08074E6C
	strh r1, [r5, #8]
_08074E6C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08074E90
	movs r0, #1
	strb r0, [r5, #7]
_08074E90:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
