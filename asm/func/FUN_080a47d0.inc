	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A47E8
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A47E8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A4808
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4842
_080A4808:
	movs r0, #2
	strh r0, [r5, #0x10]
	ldr r1, _080A484C @ =FUN_080a4854
	adds r0, r5, #0
	bl Entity1E98_SetUpdateCallback
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4842
	ldr r1, _080A4850 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A4842:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A484C: .4byte FUN_080a4854
_080A4850: .4byte 0xFFFF0000
