	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r1
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	ldr r2, _0812F1EC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F1F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F1F2
	.align 2, 0
_0812F1EC: .4byte 0x0000046D
_0812F1F0:
	movs r0, #0
_0812F1F2:
	cmp r0, #0
	beq _0812F22C
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #5
	bl Enemy_PlayAnim
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0812F32C @ =0xFFFFBFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [r1]
_0812F22C:
	ldrh r0, [r4, #8]
	cmp r0, #3
	bne _0812F270
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne _0812F270
	movs r0, #0x8a
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r2, [r0]
	cmp r2, #0
	beq _0812F270
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r3, _0812F330 @ =0x00000226
	adds r1, r5, r3
	ldrh r3, [r1]
	ldr r4, _0812F334 @ =0x0000022E
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp]
	adds r4, #8
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	bl SpiderVenom_Spawn
_0812F270:
	ldr r1, _0812F338 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812F31E
	mov r2, r8
	cmp r2, #0x3c
	ble _0812F31E
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r5, r3
	ldr r1, _0812F33C @ =0xFFFFFEFF
	ldrh r0, [r6]
	ands r1, r0
	movs r7, #0
	movs r4, #0
	strh r1, [r6]
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0812F340 @ =0x00000469
	adds r0, r5, r3
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	ldr r1, _0812F344 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0x1a
	subs r3, #0x17
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0812F348 @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	ldr r4, _0812F34C @ =0x000001DF
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0812F308
	movs r0, #4
	ldr r1, _0812F350 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812F308:
	movs r0, #0x80
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _0812F354 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
_0812F31E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F32C: .4byte 0xFFFFBFFF
_0812F330: .4byte 0x00000226
_0812F334: .4byte 0x0000022E
_0812F338: .4byte 0x0000046E
_0812F33C: .4byte 0xFFFFFEFF
_0812F340: .4byte 0x00000469
_0812F344: .4byte 0x0000046C
_0812F348: .4byte 0x0000046B
_0812F34C: .4byte 0x000001DF
_0812F350: .4byte 0x00000222
_0812F354: .4byte 0x0000024E
