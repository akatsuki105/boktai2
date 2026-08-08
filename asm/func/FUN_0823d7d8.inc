	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #5
	movs r1, #0x54
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823D852
	cmp r5, #0
	bne _0823D804
	strh r5, [r4, #0x1c]
	ldr r0, _0823D7FC @ =FUN_0823d764
	mov ip, r0
	ldr r5, _0823D800 @ =FUN_0823d7d4
	b _0823D82C
	.align 2, 0
_0823D7FC: .4byte FUN_0823d764
_0823D800: .4byte FUN_0823d7d4
_0823D804:
	ldr r2, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x30
	str r0, [r4, #0x20]
	adds r3, r0, #0
	ldrh r0, [r5]
	strh r0, [r4, #0x1c]
	ldrh r1, [r5]
	ldr r0, _0823D838 @ =FUN_0823d764
	mov ip, r0
	ldr r5, _0823D83C @ =FUN_0823d7d4
	cmp r1, #0
	beq _0823D82C
_0823D81E:
	ldm r2!, {r0}
	stm r3!, {r0}
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0823D81E
_0823D82C:
	cmp r6, #0
	bge _0823D840
	movs r0, #1
	strh r0, [r4, #0x2c]
	rsbs r6, r6, #0
	b _0823D844
	.align 2, 0
_0823D838: .4byte FUN_0823d764
_0823D83C: .4byte FUN_0823d7d4
_0823D840:
	movs r0, #0
	strh r0, [r4, #0x2c]
_0823D844:
	str r6, [r4, #0x28]
	str r7, [r4, #0x24]
	adds r0, r4, #0
	mov r1, ip
	adds r2, r5, #0
	bl SetEntityRoutine
_0823D852:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
