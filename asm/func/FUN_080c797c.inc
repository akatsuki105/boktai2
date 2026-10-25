	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	mov r8, r1
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C79CC
	movs r2, #0
	strb r2, [r1]
	ldr r0, _080C7A14 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r3, _080C7A18 @ =0x0000192C
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _080C7A1C @ =0x0000192E
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C79CC:
	ldr r2, _080C7A1C @ =0x0000192E
	adds r4, r5, r2
	ldrb r6, [r4]
	cmp r6, #0
	beq _080C7A28
	cmp r6, #1
	bne _080C79E0
	ldr r0, _080C7A20 @ =0x00000226
	bl PlaySound_082406e0
_080C79E0:
	ldrb r0, [r4]
	adds r0, #1
	movs r6, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _080C7A48
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #1
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	strb r6, [r4]
	ldr r1, _080C7A24 @ =0x0000192F
	adds r0, r5, r1
	strb r6, [r0]
	b _080C7A48
	.align 2, 0
_080C7A14: .4byte 0x03002BE0
_080C7A18: .4byte 0x0000192C
_080C7A1C: .4byte 0x0000192E
_080C7A20: .4byte 0x00000226
_080C7A24: .4byte 0x0000192F
_080C7A28:
	ldr r2, _080C7A8C @ =0x0000192F
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C7A38
	ldr r0, _080C7A90 @ =0x00000226
	bl PlaySound_082406e0
_080C7A38:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bls _080C7A48
	strb r6, [r4]
_080C7A48:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r3, _080C7A94 @ =0xFFFF0000
	ldr r1, _080C7A98 @ =0x000002EA
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
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
	movs r0, #0xf
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _080C7A9C
	movs r1, #0
	b _080C7AA2
	.align 2, 0
_080C7A8C: .4byte 0x0000192F
_080C7A90: .4byte 0x00000226
_080C7A94: .4byte 0xFFFF0000
_080C7A98: .4byte 0x000002EA
_080C7A9C:
	ldr r1, _080C7B34 @ =0x0000192A
	adds r0, r5, r1
	ldrh r1, [r0]
_080C7AA2:
	ldr r4, _080C7B38 @ =0x03002BE0
	ldr r0, [r4]
	movs r6, #1
	str r6, [sp]
	movs r7, #0
	str r7, [sp, #4]
	str r6, [sp, #8]
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	ldr r2, _080C7B3C @ =0x0000192C
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _080C7B40 @ =0xFFFFFF00
	adds r1, r1, r2
	subs r4, r0, r1
	movs r0, #0xff
	ands r4, r0
	ldr r3, _080C7B44 @ =0x0000192D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r4, r0
	beq _080C7B0E
	cmp r4, #8
	beq _080C7AEA
	cmp r4, #0x10
	bne _080C7B08
_080C7AEA:
	ldr r1, _080C7B48 @ =0x0000192E
	adds r0, r5, r1
	strb r6, [r0]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C7B08:
	ldr r3, _080C7B44 @ =0x0000192D
	adds r0, r5, r3
	strb r4, [r0]
_080C7B0E:
	ldr r2, _080C7B38 @ =0x03002BE0
	ldr r1, _080C7B3C @ =0x0000192C
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, _080C7B40 @ =0xFFFFFF00
	adds r1, r1, r3
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x13
	ble _080C7B50
	ldr r2, _080C7B4C @ =FUN_080c7b84
	movs r0, #9
	b _080C7B5A
	.align 2, 0
_080C7B34: .4byte 0x0000192A
_080C7B38: .4byte 0x03002BE0
_080C7B3C: .4byte 0x0000192C
_080C7B40: .4byte 0xFFFFFF00
_080C7B44: .4byte 0x0000192D
_080C7B48: .4byte 0x0000192E
_080C7B4C: .4byte FUN_080c7b84
_080C7B50:
	mov r0, r8
	cmp r0, #0xb3
	ble _080C7B74
	ldr r2, _080C7B80 @ =FUN_080c7c20
	movs r0, #0xa
_080C7B5A:
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C7B74:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7B80: .4byte FUN_080c7c20
