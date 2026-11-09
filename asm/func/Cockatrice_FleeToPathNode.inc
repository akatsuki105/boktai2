	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r0, _0815B704 @ =0x000006FC
	add r0, sb
	ldrh r1, [r0]
	mov r0, sp
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	movs r2, #0
	mov r8, r2
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #8
	ldrsh r0, [r2, r4]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _0815B708 @ =gSineTable
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _0815B70C @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r2
	str r1, [sp, #0xc]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #5
	lsrs r1, r1, #0x10
	add r4, sp, #0xc
	ldr r0, [r4, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	bl Map_GetPathNodes
	adds r3, r0, #0
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r0, [r0]
	cmp r8, r0
	bge _0815B6B2
	ldr r0, _0815B710 @ =0x000006FE
	add r0, sb
	mov sl, r0
	mov ip, r7
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x1c]
_0815B632:
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, r6
	beq _0815B6A8
	ldrh r1, [r3]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x14]
	mov r4, ip
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r1, [r3, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #4]
	ldr r7, [sp, #0x1c]
	movs r1, #0
	ldrsh r0, [r7, r1]
	adds r4, r2, #0
	cmp r0, #0
	bge _0815B670
	rsbs r0, r0, #0
_0815B670:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _0815B686
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _0815B682
	rsbs r0, r0, #0
_0815B682:
	cmp r0, r1
	ble _0815B6A8
_0815B686:
	add r0, sp, #0xc
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r2, [sp, #0x1c]
	movs r7, #0
	ldrsh r0, [r2, r7]
	muls r1, r0, r1
	mov r0, sp
	movs r7, #0x10
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	blt _0815B720
	adds r3, #8
_0815B6A8:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _0815B632
_0815B6B2:
	movs r0, #0
	cmp r0, #0
	bne _0815B726
	ldr r2, _0815B714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815B718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0815B71C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _0815B710 @ =0x000006FE
	add r4, sb
	ldrh r2, [r4]
	cmp r8, r2
	bne _0815B6F4
	adds r0, #1
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_0815B6F4:
	movs r1, #0
	mov r3, r8
	strh r3, [r4]
	mov r0, sp
	mov r4, r8
	strb r4, [r0, #2]
	b _0815B736
	.align 2, 0
_0815B704: .4byte 0x000006FC
_0815B708: .4byte gSineTable
_0815B70C: .4byte 0xFFFF0000
_0815B710: .4byte 0x000006FE
_0815B714: .4byte 0x030046B8
_0815B718: .4byte 0x000003FF
_0815B71C: .4byte 0x0203B400
_0815B720:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_0815B726:
	ldr r0, _0815B784 @ =0x000006FE
	add r0, sb
	movs r1, #0
	mov r6, r8
	strh r6, [r0]
	mov r0, sp
	mov r7, r8
	strb r7, [r0, #2]
_0815B736:
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl Map_GetPathNodes
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [sp, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B77E
	cmp r1, #0
	blt _0815B77E
	ldr r0, _0815B788 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B77E
	ldr r0, _0815B78C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B790
_0815B77E:
	movs r4, #0
	b _0815B79E
	.align 2, 0
_0815B784: .4byte 0x000006FE
_0815B788: .4byte 0x030046A8
_0815B78C: .4byte 0x030046AC
_0815B790:
	ldr r0, _0815B7B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815B79E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B7B4
	adds r0, #4
	b _0815B7C0
	.align 2, 0
_0815B7B0: .4byte 0x030046A4
_0815B7B4:
	ldr r0, _0815B7D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815B7C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815B7D8
	cmp r2, #2
	beq _0815B7DC
	b _0815B7E0
	.align 2, 0
_0815B7D4: .4byte 0x030046A4
_0815B7D8:
	ldrb r0, [r6, #4]
	b _0815B7DE
_0815B7DC:
	ldrb r0, [r6]
_0815B7DE:
	subs r1, r1, r0
_0815B7E0:
	strh r1, [r6, #2]
	ldr r2, _0815B80C @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815B810
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	b _0815B836
	.align 2, 0
_0815B80C: .4byte 0x000004A4
_0815B810:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815B830
	cmp r0, #2
	beq _0815B82C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815B82C:
	movs r0, #1
	b _0815B840
_0815B830:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_0815B836:
	ldr r1, _0815B890 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815B840:
	adds r4, r0, #0
	cmp r4, #0
	bne _0815B8B4
	ldr r1, _0815B894 @ =Enemy_ClearStateBegun
	ldr r7, _0815B898 @ =0x0000046D
	adds r0, r5, r7
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0815B89C @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	ldr r6, _0815B8A0 @ =0x00000553
	adds r0, r5, r6
	strb r4, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0815B8A4 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _0815B8A8 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0815B8AC @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0815B8B0 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
	b _0815B8C0
	.align 2, 0
_0815B890: .4byte 0xFFFFFDFF
_0815B894: .4byte Enemy_ClearStateBegun
_0815B898: .4byte 0x0000046D
_0815B89C: .4byte 0x0000046B
_0815B8A0: .4byte 0x00000553
_0815B8A4: .4byte 0x00000469
_0815B8A8: .4byte 0x0000046A
_0815B8AC: .4byte 0x00000484
_0815B8B0: .4byte 0x0000046C
_0815B8B4:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815B8C0:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
