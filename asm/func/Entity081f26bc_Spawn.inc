	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _081F2318 @ =0x030001EC
	ldr r3, [r0]
	cmp r3, #0
	bne _081F22E6
	bl Entity081f26bc_Create
	adds r3, r0, #0
	cmp r3, #0
	beq _081F2312
_081F22E6:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F231C @ =0x030047A4
	ldr r1, _081F2320 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F2312
	ldr r0, _081F2324 @ =0x03002BC0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081F2312
	adds r0, r3, #0
	bl Entity081f26bc_AllocElem
	adds r7, r0, #0
	cmp r7, #0
	bne _081F2328
_081F2312:
	movs r0, #0
	b _081F2582
	.align 2, 0
_081F2318: .4byte 0x030001EC
_081F231C: .4byte 0x030047A4
_081F2320: .4byte 0x030047A0
_081F2324: .4byte 0x03002BC0
_081F2328:
	adds r2, r7, #0
	adds r2, #0x6c
	ldr r0, [sp, #0x34]
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0x76
	movs r3, #1
	mov sb, r3
	mov r1, sb
	strb r1, [r0]
	movs r3, #0x6e
	adds r3, r3, r7
	mov sl, r3
	strb r1, [r3]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	mov r8, r2
	cmn r1, r0
	beq _081F2378
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
_081F2378:
	adds r1, r7, #0
	adds r1, #0x70
	ldr r0, [sp, #0x48]
	strh r0, [r1]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081F238E
	b _081F24C8
_081F238E:
	movs r0, #0x48
	bl Malloc
	str r0, [r7]
	movs r1, #0x48
	bl ClearMemory
	ldr r5, [r7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r0, r7, #0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl Entity081f26bc_LoadAuxSprite
	adds r6, r0, #0
	adds r4, r7, #0
	ldm r4!, {r1}
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [sp, #0x2c]
	lsls r2, r1, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x40]
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	ldr r1, [sp, #0x44]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0xc]
	ldr r1, [sp, #0x38]
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _081F2410
	ldr r0, [r5]
	movs r3, #4
	orrs r0, r3
	b _081F2418
_081F2410:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2418:
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
	beq _081F243C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F2444
_081F243C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2444:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F247C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F24B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2480
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2474
	ldrb r0, [r4, #5]
_081F2474:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2490
	.align 2, 0
_081F247C: .4byte 0x0000FFFF
_081F2480:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2490
	strh r1, [r4, #8]
_081F2490:
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
	bne _081F24B4
	movs r0, #1
	strb r0, [r4, #7]
_081F24B4:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	ldr r3, [sp, #0x30]
	orrs r0, r3
	str r0, [r5]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r5, #7]
	b _081F2560
_081F24C8:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081F2560
	movs r0, #0x2c
	bl Malloc
	str r0, [r7]
	movs r1, #0x2c
	bl ClearMemory
	ldr r5, [r7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r4, [r7]
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl GetParticleGroup
	str r0, [r4, #0x28]
	ldr r0, _081F2594 @ =0x0000922E
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r6, r0, #0
	adds r4, r7, #0
	ldm r4!, {r0}
	ldr r1, [r0, #0x28]
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	ldr r1, [sp, #0x5c]
	rsbs r1, r1, #0
	ldr r2, [sp, #0x60]
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl Particle_SetOffset
	ldr r3, [sp, #0x2c]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x40]
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	ldr r1, [sp, #0x44]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5]
	mov r2, sb
	orrs r0, r2
	ldr r3, [sp, #0x30]
	orrs r0, r3
	str r0, [r5]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r5, #0xf]
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081F2560
	movs r0, #2
	mov r3, sl
	strb r0, [r3]
_081F2560:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	ble _081F2580
	ldr r0, [sp, #0x58]
	str r0, [sp]
	adds r0, r7, #0
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl Entity081f26bc_InitHitbox
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081F2580:
	adds r0, r7, #0
_081F2582:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F2594: .4byte 0x0000922E
