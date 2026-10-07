	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, #0x68
	strh r6, [r0]
	movs r0, #0x6c
	movs r1, #0x64
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x6c
	strh r0, [r1]
	subs r1, #2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0x10
	bl VM_GetNamedArgValue
	str r0, [r5, #0x78]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800E2D0
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E2C8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E2CC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800E2DA
	.align 2, 0
_0800E2C8: .4byte 0xFFFF0000
_0800E2CC: .4byte 0x0000FFFF
_0800E2D0:
	ldr r1, _0800E31C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800E2DA:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800E324
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E31C @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E320 @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x14
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r7, r2, #0
	b _0800E332
	.align 2, 0
_0800E31C: .4byte 0xFFFF0000
_0800E320: .4byte 0x0000FFFF
_0800E324:
	ldr r2, _0800E374 @ =0xFFFF0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r7, r1, #0
_0800E332:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800E37C
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E374 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E378 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r3, r2, #0
	b _0800E38A
	.align 2, 0
_0800E374: .4byte 0xFFFF0000
_0800E378: .4byte 0x0000FFFF
_0800E37C:
	ldr r2, _0800E3EC @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r3, r1, #0
_0800E38A:
	adds r4, r5, #0
	adds r4, #0x18
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800E3F0 @ =0x00004001
	ldr r0, [r5, #0x78]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	add r1, sp, #0xc
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0800E3F4 @ =Entity55C2_OnHit
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r4, #0x56
	strh r0, [r4]
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800E3F8
	bl VM_GetValue
	str r0, [r5, #0x70]
	b _0800E402
	.align 2, 0
_0800E3EC: .4byte 0xFFFF0000
_0800E3F0: .4byte 0x00004001
_0800E3F4: .4byte Entity55C2_OnHit
_0800E3F8:
	str r0, [r5, #0x70]
	ldrh r0, [r4]
	movs r1, #8
	orrs r0, r1
	strh r0, [r4]
_0800E402:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800E414
	bl VM_GetValue
	str r0, [r5, #0x74]
	b _0800E41E
_0800E414:
	str r0, [r5, #0x74]
	ldrh r1, [r4]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4]
_0800E41E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x80
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x82
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	strh r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
