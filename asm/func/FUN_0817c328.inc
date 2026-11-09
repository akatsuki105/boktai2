	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _0817C428
	adds r0, r5, #0
	bl Enemy_Alert
	ldr r1, _0817C3A4 @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl EnemyTargetManager_FindOwnerByID
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817C39E
	cmp r1, #0
	blt _0817C39E
	ldr r0, _0817C3A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C39E
	ldr r0, _0817C3AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C3B0
_0817C39E:
	movs r1, #0
	b _0817C3BE
	.align 2, 0
_0817C3A4: .4byte 0x00000222
_0817C3A8: .4byte 0x030046A8
_0817C3AC: .4byte 0x030046AC
_0817C3B0:
	ldr r0, _0817C41C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817C3BE:
	ldr r3, _0817C420 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	strb r0, [r5, #5]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0817C424 @ =0x00000898
	adds r1, r1, r2
	movs r2, #0x31
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #1
	b _0817C440
	.align 2, 0
_0817C41C: .4byte 0x030046A4
_0817C420: .4byte 0x0000025E
_0817C424: .4byte 0x00000898
_0817C428:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0817C43E
	ldr r0, _0817C448 @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_0817C43E:
	movs r0, #0
_0817C440:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0817C448: .4byte 0xF7FFFFFF
