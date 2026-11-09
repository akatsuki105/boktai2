	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817C550
	bl VM_GetPC
	cmp r0, #0
	beq _0817C478
	bl VM_GetValue
	b _0817C47A
_0817C478:
	movs r0, #0
_0817C47A:
	strh r0, [r6, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0817C48A
	bl VM_GetValue
	b _0817C48C
_0817C48A:
	movs r0, #0
_0817C48C:
	strh r0, [r6, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0817C49C
	bl VM_GetValue
	b _0817C49E
_0817C49C:
	movs r0, #0
_0817C49E:
	strh r0, [r6, #0xc]
	adds r0, r6, #0
	adds r0, #8
	ldrh r1, [r6, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r2, #0
	blt _0817C4CA
	cmp r1, #0
	blt _0817C4CA
	ldr r0, _0817C4D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C4CA
	ldr r0, _0817C4D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C4D8
_0817C4CA:
	movs r1, #0
	b _0817C4E6
	.align 2, 0
_0817C4D0: .4byte 0x030046A8
_0817C4D4: .4byte 0x030046AC
_0817C4D8:
	ldr r0, _0817C500 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817C4E6:
	ldr r2, _0817C504 @ =0x00000256
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r4, [r0]
	adds r5, r3, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817C508
	adds r0, #4
	b _0817C514
	.align 2, 0
_0817C500: .4byte 0x030046A4
_0817C504: .4byte 0x00000256
_0817C508:
	ldr r0, _0817C528 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817C514:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817C52C
	cmp r3, #2
	beq _0817C530
	b _0817C534
	.align 2, 0
_0817C528: .4byte 0x030046A4
_0817C52C:
	ldrb r0, [r5, #4]
	b _0817C532
_0817C530:
	ldrb r0, [r5]
_0817C532:
	subs r2, r2, r0
_0817C534:
	ldr r3, _0817C54C @ =0x00000472
	adds r0, r6, r3
	strh r2, [r0]
	ldrh r1, [r6, #0xa]
	subs r1, r1, r2
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r2, r6, r4
	strh r1, [r2]
	ldrh r0, [r0]
	strh r0, [r6, #0xa]
	b _0817C586
	.align 2, 0
_0817C54C: .4byte 0x00000472
_0817C550:
	adds r1, r6, #0
	adds r1, #0x9c
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r2, [r0]
	ldr r3, _0817C5AC @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	ldr r4, _0817C5B0 @ =0x00000252
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl Mover_SetPath
	adds r0, r6, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	strb r0, [r6, #5]
_0817C586:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	ldr r7, _0817C5B4 @ =0x00000898
	add r7, r8
	cmp r0, #0
	beq _0817C5C6
	movs r4, #0
_0817C596:
	lsls r0, r4, #1
	ldr r1, _0817C5B8 @ =0x00000888
	add r1, r8
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817C5BC
	bl VM_GetValue
	b _0817C5BE
	.align 2, 0
_0817C5AC: .4byte 0x00000251
_0817C5B0: .4byte 0x00000252
_0817C5B4: .4byte 0x00000898
_0817C5B8: .4byte 0x00000888
_0817C5BC:
	movs r0, #0
_0817C5BE:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #5
	ble _0817C596
_0817C5C6:
	movs r1, #1
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_0817e870
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
