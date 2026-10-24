	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #2
	strb r6, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A46CC
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A46CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A46E0
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4718
_080A46E0:
	strh r6, [r5, #0x10]
	ldr r1, _080A4720 @ =FUN_080a4728
	adds r0, r5, #0
	bl Entity1E98_SetUpdateCallback
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4718
	ldr r1, _080A4724 @ =0xFFFF0000
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
_080A4718:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4720: .4byte FUN_080a4728
_080A4724: .4byte 0xFFFF0000
