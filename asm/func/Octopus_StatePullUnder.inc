	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _08185764 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185768
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818576A
	.align 2, 0
_08185764: .4byte 0x0000046D
_08185768:
	movs r0, #0
_0818576A:
	cmp r0, #0
	beq _08185794
	adds r0, r7, #0
	movs r1, #0x13
	bl Enemy_PlayAnimFlipOnly
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081857BC @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081857C0 @ =0x00000474
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08185794:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _081857C4
	ldrh r0, [r4, #0xe]
	adds r0, #1
	ldrb r1, [r4, #7]
	cmp r0, r1
	blt _081857C4
	ldrh r0, [r4, #8]
	adds r6, r0, #1
	ldrb r4, [r4, #5]
	cmp r6, r4
	blt _081857C6
	movs r6, #0
	b _081857C6
	.align 2, 0
_081857BC: .4byte 0x0000FFF7
_081857C0: .4byte 0x00000474
_081857C4:
	ldrh r6, [r4, #8]
_081857C6:
	mov r5, sp
	adds r5, #0x15
	adds r0, r7, #0
	add r1, sp, #0x14
	adds r2, r5, #0
	bl Enemy_SetAnimFacing
	ldr r4, _08185854 @ =0x085ADC4C
	lsls r3, r6, #3
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r6, _08185858 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0x18]
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r7, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0818585C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r0, [r7, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, r8
	ldrb r3, [r1, #4]
	movs r0, #4
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r4, r2, #0
	cmp r1, #0
	beq _08185860
	mov r0, r8
	ldr r1, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r1, #0
	movs r1, #1
	movs r3, #0
	bl FUN_080e6978
	b _08185884
	.align 2, 0
_08185854: .4byte 0x085ADC4C
_08185858: .4byte 0xFFFF0000
_0818585C: .4byte 0x0000FFFF
_08185860:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185884
	mov r0, r8
	ldr r2, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl Player_HoldGrabbed
_08185884:
	ldr r1, _081858B0 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08185946
	subs r1, #3
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	movs r0, #2
	strb r0, [r1, #7]
	ldr r1, _081858B4 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081858B8
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081858C2
	.align 2, 0
_081858B0: .4byte 0x0000046E
_081858B4: .4byte 0x0000025D
_081858B8:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081858C2:
	movs r0, #0xf0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	mov r0, r8
	ldrb r2, [r0, #4]
	movs r0, #4
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818590C
	mov r1, r8
	ldrh r0, [r1]
	bl FindEnemyById
	adds r1, r0, #0
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r1, #0
	movs r1, #2
	adds r2, r4, #0
	movs r3, #0
	bl FUN_080e6978
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl Entity081ea120_Spawn
	b _08185946
_0818590C:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185946
	mov r0, r8
	ldr r2, [r0, #0x38]
	ldrb r0, [r5]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl Player_HoldGrabbed
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl Entity081ea120_Spawn
_08185946:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
