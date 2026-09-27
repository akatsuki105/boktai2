	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	mov r6, sp
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _081D38F8 @ =0x03002BE0
	mov sl, r1
_081D38BC:
	mov r2, sl
	ldr r1, [r2]
	cmp r1, #0
	bne _081D38C6
	b _081D3A66
_081D38C6:
	mov r0, sb
	adds r0, #0xb2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	bne _081D38D4
	b _081D3A66
_081D38D4:
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D38E2
	b _081D3A66
_081D38E2:
	movs r2, #8
	mov r1, sb
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #8]
	cmp r0, #0
	beq _081D38FC
	movs r0, #1
	b _081D38FE
	.align 2, 0
_081D38F8: .4byte 0x03002BE0
_081D38FC:
	movs r0, #0
_081D38FE:
	cmp r0, #0
	bne _081D3904
	b _081D3A78
_081D3904:
	mov r0, sb
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081D392E
	cmp r1, #0
	blt _081D392E
	ldr r0, _081D3934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D392E
	ldr r0, _081D3938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D393C
_081D392E:
	movs r0, #0
	b _081D394A
	.align 2, 0
_081D3934: .4byte 0x030046A8
_081D3938: .4byte 0x030046AC
_081D393C:
	ldr r0, _081D39F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D394A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D396A
	mov r4, sl
	ldr r0, [r4]
	mov r2, sb
	adds r2, #0xfe
	movs r5, #0x2e
	ldrsh r1, [r0, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _081D396A
	b _081D3A66
_081D396A:
	mov r3, sp
	mov r4, sl
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	mov r5, r8
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r2, #2]
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r3, #2]
	ldrh r1, [r2, #4]
	mov r2, r8
	ldrh r0, [r2, #4]
	subs r7, r1, r0
	strh r7, [r3, #4]
	ldr r0, _081D39F4 @ =0x085AE0E0
	movs r4, #0
	ldrsh r2, [r6, r4]
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _081D39F8 @ =0x03002BE0
	mov ip, r4
	adds r4, r0, #0
	cmp r2, r1
	bgt _081D39EC
	adds r1, r2, #0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r5, #4
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D3A66
_081D39DE:
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldrh r2, [r4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D39FC
_081D39EC:
	ldrh r0, [r4]
	b _081D3A0A
	.align 2, 0
_081D39F0: .4byte 0x030046A4
_081D39F4: .4byte 0x085AE0E0
_081D39F8: .4byte 0x03002BE0
_081D39FC:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmn r1, r0
	bge _081D3A0C
	rsbs r0, r2, #0
_081D3A0A:
	strh r0, [r6]
_081D3A0C:
	mov r2, sp
	movs r5, #4
	ldrsh r1, [r2, r5]
	ldrh r3, [r4, #4]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D3A20
	strh r3, [r2, #4]
	b _081D3A30
_081D3A20:
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	bge _081D3A30
	rsbs r0, r3, #0
	strh r0, [r2, #4]
_081D3A30:
	ldrh r0, [r6]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
	mov r0, sb
	adds r0, #0xfe
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #0xc]
	add r0, ip
	ldr r0, [r0]
	mov r1, sp
	bl FUN_0807a91c
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	orrs r4, r0
	strh r4, [r3]
_081D3A66:
	ldr r4, [sp, #0xc]
	adds r4, #4
	str r4, [sp, #0xc]
	movs r5, #4
	add sl, r5
	ldr r0, _081D3A88 @ =0x03002BE0
	cmp sl, r0
	bgt _081D3A78
	b _081D38BC
_081D3A78:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D3A88: .4byte 0x03002BE0
