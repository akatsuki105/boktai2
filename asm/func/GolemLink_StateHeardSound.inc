	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r2, _081BC11C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BC120
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BC122
	.align 2, 0
_081BC11C: .4byte 0x0000046D
_081BC120:
	movs r0, #0
_081BC122:
	cmp r0, #0
	beq _081BC136
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _081BC1E8 @ =0x0000046E
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
_081BC136:
	cmp r6, #0x3c
	bgt _081BC13C
	b _081BC2A4
_081BC13C:
	ldr r6, _081BC1E8 @ =0x0000046E
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BC148
	b _081BC2C0
_081BC148:
	ldr r1, _081BC1EC @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081BC208
	ldr r3, _081BC1F0 @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl Enemy_SetAngleToward
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _081BC1F4 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081BC1F8 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081BC1FC @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _081BC200 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081BC204 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _081BC2C0
	.align 2, 0
_081BC1E8: .4byte 0x0000046E
_081BC1EC: .4byte 0x0000046B
_081BC1F0: .4byte 0x000004A4
_081BC1F4: .4byte 0x0000046D
_081BC1F8: .4byte 0x0000046A
_081BC1FC: .4byte 0x00000484
_081BC200: .4byte 0x00000222
_081BC204: .4byte 0x00000482
_081BC208:
	movs r0, #0xd1
	lsls r0, r0, #3
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _081BC28C @ =0x0000068C
	add r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl Enemy_SetAngleToward
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, _081BC290 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r6, _081BC294 @ =0x0000046D
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _081BC298 @ =0x0000046B
	adds r0, r4, r2
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r2, #0
	strh r5, [r0]
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081BC29C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081BC2A0 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r4, #0
	bl GolemLink_SetTargetTile
	b _081BC2C0
	.align 2, 0
_081BC28C: .4byte 0x0000068C
_081BC290: .4byte Enemy_ClearStateBegun
_081BC294: .4byte 0x0000046D
_081BC298: .4byte 0x0000046B
_081BC29C: .4byte 0x0000046A
_081BC2A0: .4byte 0x00000484
_081BC2A4:
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne _081BC2C0
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081BC2C0
	cmp r2, #1
	beq _081BC2C0
	movs r0, #0
	strh r0, [r5, #0xe]
_081BC2C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
