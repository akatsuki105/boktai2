	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	movs r0, #0
	str r0, [sp, #8]
	ldr r7, _081D3578 @ =0x03002BE0
	movs r1, #0xfc
	add r1, sl
	mov r8, r1
_081D354E:
	ldr r0, [r7]
	cmp r0, #0
	bne _081D3556
	b _081D3694
_081D3556:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D3562
	b _081D3694
_081D3562:
	movs r2, #8
	mov r1, sl
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D357C
	movs r0, #1
	b _081D357E
	.align 2, 0
_081D3578: .4byte 0x03002BE0
_081D357C:
	movs r0, #0
_081D357E:
	cmp r0, #0
	bne _081D3584
	b _081D3694
_081D3584:
	ldr r0, [r7]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D35AA
	cmp r1, #0
	blt _081D35AA
	ldr r0, _081D35B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D35AA
	ldr r0, _081D35B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D35B8
_081D35AA:
	movs r4, #0
	b _081D35C6
	.align 2, 0
_081D35B0: .4byte 0x030046A8
_081D35B4: .4byte 0x030046AC
_081D35B8:
	ldr r0, _081D35E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D35C6:
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3694
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081D35E8
	adds r0, #4
	b _081D35F4
	.align 2, 0
_081D35E4: .4byte 0x030046A4
_081D35E8:
	ldr r0, _081D36B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D35F4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3694
	mov r3, sp
	ldr r0, [r7]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	mov r4, r8
	ldrh r0, [r4]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	ldrh r0, [r4, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r2, #4]
	mov r6, r8
	ldrh r0, [r6, #4]
	subs r5, r1, r0
	strh r5, [r3, #4]
	ldr r2, _081D36B8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldr r6, _081D36BC @ =0x03002BE0
	mov ip, r6
	mov r6, sl
	adds r6, #0xfc
	str r6, [sp, #0xc]
	cmp r1, r0
	bgt _081D367C
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmn r1, r0
	blt _081D367C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D367C
	movs r6, #2
	ldrsh r1, [r3, r6]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D367C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r2, r6]
	cmp r0, r1
	bgt _081D367C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D3694
_081D367C:
	ldr r0, [sp, #8]
	add r0, ip
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	bl FUN_0807a9b8
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_081D3694:
	ldr r6, [sp, #8]
	adds r6, #4
	str r6, [sp, #8]
	adds r7, #4
	ldr r0, _081D36BC @ =0x03002BE0
	cmp r7, r0
	bgt _081D36A4
	b _081D354E
_081D36A4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D36B4: .4byte 0x030046A4
_081D36B8: .4byte 0x085AE0D0
_081D36BC: .4byte 0x03002BE0
