	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
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
	beq _08006BD8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006BE0
_08006BD8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006BE0:
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
	beq _08006C04
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006C0C
_08006C04:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006C0C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006C44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08006C8A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006C4E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006C48
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006C64
	.align 2, 0
_08006C44: .4byte 0x0000FFFF
_08006C48:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006C62
_08006C4E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006C62
	strh r1, [r4, #8]
	movs r3, #1
	b _08006C64
_08006C62:
	movs r3, #0
_08006C64:
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
	bne _08006C8C
	movs r0, #1
	strb r0, [r4, #7]
	b _08006C8C
_08006C8A:
	movs r3, #0
_08006C8C:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006C9C
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006C9C:
	cmp r3, #0
	beq _08006CC0
	ldr r0, _08006CBC @ =MapItem_UpdateIdle
	str r0, [r7, #0x44]
	movs r2, #0
	str r2, [r7, #0x18]
	movs r0, #0xff
	strb r0, [r7, #4]
	ldr r0, [r7, #0x28]
	mov r3, ip
	ldr r1, [r3, #0x1c]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	b _08006CC6
	.align 2, 0
_08006CBC: .4byte MapItem_UpdateIdle
_08006CC0:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_08006CC6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
