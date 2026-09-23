	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08020254 @ =0x000085E6
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _0802024A
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0802024A
	bl Script_GetValue
	adds r7, r0, #0
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0802024A
	ldr r1, _08020258 @ =0x0000042C
	adds r6, r4, r1
	movs r5, #0
	movs r0, #2
	mov r8, r0
	ldr r1, _0802025C @ =FUN_08020734
	mov ip, r1
_08020200:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _08020242
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r2, #0x34]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
	adds r0, r2, #0
	adds r0, #0x37
	mov r1, r8
	strb r1, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_08020242:
	adds r3, #1
	ldrh r1, [r4, #0x1a]
	cmp r3, r1
	blt _08020200
_0802024A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020254: .4byte 0x000085E6
_08020258: .4byte 0x0000042C
_0802025C: .4byte FUN_08020734
