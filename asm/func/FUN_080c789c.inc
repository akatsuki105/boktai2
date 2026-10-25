	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C78DC
	movs r4, #0
	strb r4, [r7]
	ldr r1, _080C7964 @ =0x00001908
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, _080C7968 @ =0x00000225
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C78DC:
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r3, _080C796C @ =0xFFFF0000
	ldr r1, _080C7970 @ =0x000002EA
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x18]
	ldr r0, _080C7974 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #1
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	mov r0, r8
	cmp r0, #3
	ble _080C7956
	ldr r1, _080C7978 @ =FUN_080c797c
	movs r0, #8
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	strb r5, [r7]
_080C7956:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7964: .4byte 0x00001908
_080C7968: .4byte 0x00000225
_080C796C: .4byte 0xFFFF0000
_080C7970: .4byte 0x000002EA
_080C7974: .4byte 0x03002BE0
_080C7978: .4byte FUN_080c797c
