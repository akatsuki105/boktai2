	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _081CB42C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB430
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB432
	.align 2, 0
_081CB42C: .4byte 0x0000046C
_081CB430:
	movs r0, #0
_081CB432:
	cmp r0, #0
	beq _081CB460
	ldr r4, _081CB5B4 @ =FUN_081c9f24
	movs r3, #0x27
	ldr r6, _081CB5B8 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB5BC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_081CB460:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB476
	b _081CB7D2
_081CB476:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	cmp r1, #6
	beq _081CB48E
	cmp r1, #0xc
	beq _081CB48E
	cmp r1, #0x13
	beq _081CB48E
	cmp r1, #0x19
	beq _081CB48E
	b _081CB5E8
_081CB48E:
	ldrh r1, [r0, #0xe]
	ldrb r0, [r0, #7]
	subs r0, #1
	cmp r1, r0
	beq _081CB49A
	b _081CB5E8
_081CB49A:
	ldr r0, _081CB5C0 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	mov r8, r1
	cmp r0, #0
	beq _081CB4AC
	ldrh r0, [r0, #0x1a]
	mov r8, r0
_081CB4AC:
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	ldr r3, _081CB5C4 @ =0x7FFFFFFF
	mov ip, r3
	movs r4, #0
	cmp r4, r8
	bge _081CB52A
	mov r3, sp
	adds r6, r5, #0
	adds r6, #8
	ldr r0, [sp, #8]
	ldr r1, _081CB5C8 @ =0x000006B4
	adds r0, r0, r1
	mov sb, r0
	ldr r7, _081CB5CC @ =0x03002BE0
_081CB4CC:
	lsls r0, r4, #2
	ldr r1, [r7]
	cmp r1, #0
	beq _081CB522
	ldr r2, _081CB5D0 @ =0x03002BC0
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #8
	ands r0, r2
	cmp r0, #0
	bne _081CB522
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	cmp r1, r0
	bhs _081CB522
	cmp r1, ip
	bhs _081CB522
	mov ip, r1
	mov sl, r4
_081CB522:
	adds r7, #4
	adds r4, #1
	cmp r4, r8
	blt _081CB4CC
_081CB52A:
	mov r3, sl
	cmp r3, #0
	blt _081CB5E8
	ldr r6, _081CB5D4 @ =0x000001DF
	adds r0, r5, r6
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CB5D8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081CB5DC @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB5E0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r6, [sp, #8]
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r1, _081CB5CC @ =0x03002BE0
	mov r3, sl
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CB592
	b _081CB7D2
_081CB592:
	ldr r0, _081CB5E4 @ =0x0000024E
	adds r3, r5, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	adds r6, #0xcc
	adds r1, r5, r6
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _081CB5B0
	b _081CB7D2
_081CB5B0:
	strh r1, [r3]
	b _081CB7D2
	.align 2, 0
_081CB5B4: .4byte FUN_081c9f24
_081CB5B8: .4byte 0x0000046D
_081CB5BC: .4byte 0x0000046B
_081CB5C0: .4byte 0x03002C68
_081CB5C4: .4byte 0x7FFFFFFF
_081CB5C8: .4byte 0x000006B4
_081CB5CC: .4byte 0x03002BE0
_081CB5D0: .4byte 0x03002BC0
_081CB5D4: .4byte 0x000001DF
_081CB5D8: .4byte 0x00000469
_081CB5DC: .4byte 0x0000046A
_081CB5E0: .4byte 0x00000484
_081CB5E4: .4byte 0x0000024E
_081CB5E8:
	ldr r1, _081CB668 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CB5F4
	b _081CB7C8
_081CB5F4:
	movs r2, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081CB67C
	movs r2, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CB66C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB670 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0x1a
	ldr r6, _081CB674 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB668 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #4
	ldr r6, _081CB678 @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081CB7D2
	.align 2, 0
_081CB668: .4byte 0x0000046B
_081CB66C: .4byte 0x00000469
_081CB670: .4byte 0x00000484
_081CB674: .4byte 0x0000046D
_081CB678: .4byte 0x00000222
_081CB67C:
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081CB6B0
	cmp r1, #0
	blt _081CB6B0
	ldr r0, _081CB6B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CB6B0
	ldr r0, _081CB6B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CB6BC
_081CB6B0:
	movs r4, #0
	b _081CB6CA
	.align 2, 0
_081CB6B4: .4byte 0x030046A8
_081CB6B8: .4byte 0x030046AC
_081CB6BC:
	ldr r0, _081CB6DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CB6CA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CB6E0
	adds r0, #4
	b _081CB6EC
	.align 2, 0
_081CB6DC: .4byte 0x030046A4
_081CB6E0:
	ldr r0, _081CB700 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB6EC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CB704
	cmp r3, #2
	beq _081CB708
	b _081CB70C
	.align 2, 0
_081CB700: .4byte 0x030046A4
_081CB704:
	ldrb r0, [r6, #4]
	b _081CB70A
_081CB708:
	ldrb r0, [r6]
_081CB70A:
	subs r2, r2, r0
_081CB70C:
	movs r1, #0
	movs r4, #0
	strh r2, [r6, #2]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #1
	ldr r6, _081CB798 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081CB79C @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081CB7A0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x3a
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081CB7A4
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CB7A4
	cmp r0, #2
	beq _081CB792
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB792:
	movs r0, #1
	b _081CB7AE
	.align 2, 0
_081CB798: .4byte 0x0000046D
_081CB79C: .4byte 0x0000046A
_081CB7A0: .4byte 0x00000484
_081CB7A4:
	ldr r0, _081CB7C0 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_081CB7AE:
	cmp r0, #0
	bne _081CB7D2
	ldr r2, _081CB7C4 @ =0x000005C4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081CB7D2
	.align 2, 0
_081CB7C0: .4byte 0xFFFFFDFF
_081CB7C4: .4byte 0x000005C4
_081CB7C8:
	ldr r3, _081CB7E4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB7D2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB7E4: .4byte 0x00000484
