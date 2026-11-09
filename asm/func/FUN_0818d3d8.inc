	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818D400 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D404
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D406
	.align 2, 0
_0818D400: .4byte 0x0000046C
_0818D404:
	movs r0, #0
_0818D406:
	cmp r0, #0
	beq _0818D4EA
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _0818D530 @ =0x0000046D
	adds r0, r7, r4
	movs r5, #0
	strb r1, [r0]
	ldr r3, _0818D534 @ =0x0000046B
	adds r0, r7, r3
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	adds r6, r7, #0
	adds r6, #8
	ldr r0, _0818D538 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08193648
	subs r4, #0xdf
	adds r2, r7, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r4, _0818D53C @ =0x00000F2C
	add r4, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x2a
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0818D540 @ =0x00000472
	adds r5, r7, r2
	ldr r3, _0818D544 @ =0xFFFFF818
	adds r1, r3, #0
	ldrh r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0818D548 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl FUN_0819014c
	ldrh r1, [r5]
	adds r0, r6, #0
	bl FUN_08191a14
	movs r0, #0xcf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _0818D54C @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D550 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_0818D4EA:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0818D55C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #2
	movs r3, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r7, r4
	strb r2, [r0]
	ldr r2, _0818D554 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	str r1, [r0]
	ldr r1, _0818D558 @ =0x0000046C
	adds r0, r7, r1
	strb r3, [r0]
	b _0818D5A0
	.align 2, 0
_0818D530: .4byte 0x0000046D
_0818D534: .4byte 0x0000046B
_0818D538: .4byte 0x03002BE0
_0818D53C: .4byte 0x00000F2C
_0818D540: .4byte 0x00000472
_0818D544: .4byte 0xFFFFF818
_0818D548: .4byte 0x0000FFFF
_0818D54C: .4byte 0x000003E5
_0818D550: .4byte 0xFFFF7FFF
_0818D554: .4byte 0x0000046A
_0818D558: .4byte 0x0000046C
_0818D55C:
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0818D572
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _0818D57A
_0818D572:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_0818D57A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #8
	bl FUN_0818fdd8
	mov r0, r8
	bl FUN_0818f008
	mov r0, r8
	movs r1, #4
	bl FUN_0818f17c
	ldr r3, _0818D5AC @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818D5A0:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818D5AC: .4byte 0x00000484
