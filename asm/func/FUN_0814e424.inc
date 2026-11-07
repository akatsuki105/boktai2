	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0814E448 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E44C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E44E
	.align 2, 0
_0814E448: .4byte 0x0000046D
_0814E44C:
	movs r0, #0
_0814E44E:
	cmp r0, #0
	bne _0814E522
	adds r0, r4, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
	adds r0, r4, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814E522
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _0814E49C @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0814E4A0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _0814E4C6
	.align 2, 0
_0814E49C: .4byte 0x000004A4
_0814E4A0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814E4C0
	cmp r0, #2
	beq _0814E4BC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814E4BC:
	movs r0, #1
	b _0814E4D0
_0814E4C0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_0814E4C6:
	ldr r1, _0814E4E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814E4D0:
	cmp r0, #0
	bne _0814E4EC
	ldr r1, _0814E4E8 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0814E522
	.align 2, 0
_0814E4E4: .4byte 0xFFFFFDFF
_0814E4E8: .4byte 0x000005C4
_0814E4EC:
	movs r2, #0xd5
	lsls r2, r2, #3
	add r2, r8
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E52C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0814E522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814E52C: .4byte 0x00000484
