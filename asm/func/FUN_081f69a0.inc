	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r5, #2
	ldr r3, _081F69E0 @ =0xFFFF0000
	mov r6, sp
	movs r0, #0xd1
	lsls r0, r0, #2
	adds r4, r7, r0
_081F69B2:
	lsls r2, r5, #3
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #0x10
	ldrb r1, [r4]
	adds r0, r0, r1
	strb r0, [r4]
	ldr r1, _081F69E4 @ =gSineTable
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081F69E8
	asrs r0, r0, #0xc
	b _081F69EE
	.align 2, 0
_081F69E0: .4byte 0xFFFF0000
_081F69E4: .4byte gSineTable
_081F69E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F69EE:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	ldr r0, [r6, #4]
	ands r0, r3
	str r0, [r6, #4]
	ldr r1, _081F6A80 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	adds r2, r5, #0
	str r3, [sp, #0x10]
	bl Entity081f73ec_SetSegVel
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
	ldr r3, [sp, #0x10]
	cmp r5, #5
	ble _081F69B2
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081F6AE6
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r6, r1, #0
	cmp r3, #0
	blt _081F6A7A
	cmp r2, #0
	blt _081F6A7A
	ldr r0, _081F6A84 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F6A7A
	ldr r0, _081F6A88 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081F6A8C
_081F6A7A:
	movs r4, #0
	b _081F6A9A
	.align 2, 0
_081F6A80: .4byte 0x0000FFFF
_081F6A84: .4byte 0x030046A8
_081F6A88: .4byte 0x030046AC
_081F6A8C:
	ldr r0, _081F6AAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F6A9A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6AB0
	adds r0, #4
	b _081F6ABC
	.align 2, 0
_081F6AAC: .4byte 0x030046A4
_081F6AB0:
	ldr r0, _081F6AD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6ABC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6AD4
	cmp r2, #2
	beq _081F6AD8
	b _081F6ADC
	.align 2, 0
_081F6AD0: .4byte 0x030046A4
_081F6AD4:
	ldrb r0, [r5, #4]
	b _081F6ADA
_081F6AD8:
	ldrb r0, [r5]
_081F6ADA:
	subs r1, r1, r0
_081F6ADC:
	strh r1, [r6, #2]
	adds r0, r6, #0
	movs r1, #1
	bl Entity081f73ec_SpawnDust
_081F6AE6:
	adds r0, r7, #0
	bl Entity081f73ec_UpdateHitbox
	adds r0, r7, #0
	bl Entity081f73ec_ApplySegVel
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
