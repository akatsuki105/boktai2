	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080A31D0 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A316A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A316A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A316A:
	ldr r0, _080A31D0 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A31C6
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A31AA
	ldr r1, _080A31D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A31AA:
	ldr r1, _080A31D8 @ =0x000001C3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r1, #0
	bl VM_ExecByID
_080A31C6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A31D0: .4byte 0x00000382
_080A31D4: .4byte 0xFFFF0000
_080A31D8: .4byte 0x000001C3
