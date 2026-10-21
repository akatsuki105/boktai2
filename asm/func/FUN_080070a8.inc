	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl MapItemManager_Ensure
	adds r4, r0, #0
	cmp r4, #0
	beq _08007126
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007126
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r6, [r5]
	strh r7, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	strb r2, [r5, #5]
	strb r2, [r5, #6]
	strb r2, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, _0800712C @ =MapItem_UpdateFall
	str r0, [r5, #0x44]
	strb r2, [r5, #0xc]
	ldr r0, [sp, #0x44]
	strb r0, [r5, #0x14]
	mov r0, r8
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_0800710A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800710A
	movs r0, #0x28
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007130
	adds r0, r5, #0
	bl Free
_08007126:
	movs r0, #1
	rsbs r0, r0, #0
	b _080071FC
	.align 2, 0
_0800712C: .4byte MapItem_UpdateFall
_08007130:
	movs r1, #0x28
	bl ClearMemory
	ldr r0, [r5, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0
	bl Particle_Add
	ldr r0, [r5, #0x1c]
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0xa
	rsbs r2, r2, #0
	bl Particle_SetOffset
	mov r0, sb
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _0800717C
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r1, r0, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #1
	b _08007196
_0800717C:
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	lsls r0, r0, #5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #2
_08007196:
	strb r0, [r1, #0xf]
	ldr r2, [r5, #0x1c]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r1, [r5, #0x1c]
	movs r0, #0x10
	strb r0, [r1, #0x10]
	ldr r0, [r5, #0x1c]
	adds r0, #0x18
	str r0, [r5, #0x2c]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _080071BE
	bl GetZoneAt
	strh r0, [r5, #0x16]
	b _080071C4
_080071BE:
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r5, #0x16]
_080071C4:
	movs r4, #0
	ldr r0, [sp, #0x40]
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r5, #0x1c]
	adds r1, #0x18
	movs r2, #0x28
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x18
	bl AuxShadow_Init
	adds r0, r5, #0
	bl MapItem_Link
	movs r0, #0
_080071FC:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
