	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3AA2
	b _081D3C18
_081D3AA2:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D3AB6
	movs r0, #1
	b _081D3AB8
_081D3AB6:
	movs r0, #0
_081D3AB8:
	cmp r0, #0
	bne _081D3ABE
	b _081D3C18
_081D3ABE:
	mov r0, sp
	bl FUN_08086a28
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D3AEE
	cmp r1, #0
	blt _081D3AEE
	ldr r0, _081D3AF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3AEE
	ldr r0, _081D3AF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3AFC
_081D3AEE:
	movs r0, #0
	b _081D3B0A
	.align 2, 0
_081D3AF4: .4byte 0x030046A8
_081D3AF8: .4byte 0x030046AC
_081D3AFC:
	ldr r0, _081D3BA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D3B0A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3B28
	mov r0, sp
	adds r1, r7, #0
	adds r1, #0xfe
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	beq _081D3C18
_081D3B28:
	add r3, sp, #8
	mov r4, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r6]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r5, ip
	strh r5, [r3, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r6, #4]
	subs r4, r2, r0
	strh r4, [r3, #4]
	ldr r2, _081D3BAC @ =0x085AE0E0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D3BA4
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r2, r5]
	cmp r0, r1
	bgt _081D3B96
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3B96
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r2, r4]
	cmn r1, r0
	bge _081D3C18
_081D3B96:
	movs r5, #0
	ldrsh r1, [r3, r5]
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BB0
_081D3BA4:
	ldrh r0, [r2]
	b _081D3BBE
	.align 2, 0
_081D3BA8: .4byte 0x030046A4
_081D3BAC: .4byte 0x085AE0E0
_081D3BB0:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BC0
	rsbs r0, r4, #0
_081D3BBE:
	strh r0, [r3]
_081D3BC0:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r4, [r2, #4]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BD2
	strh r4, [r3, #4]
	b _081D3BE2
_081D3BD2:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BE2
	rsbs r0, r4, #0
	strh r0, [r3, #4]
_081D3BE2:
	ldrh r0, [r3]
	ldrh r6, [r6]
	adds r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3C18:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
