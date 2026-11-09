	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081110B8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081110BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081110BE
	.align 2, 0
_081110B8: .4byte 0x0000046C
_081110BC:
	movs r0, #0
_081110BE:
	cmp r0, #0
	beq _08111108
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0811118C @ =Skeleton_StateOrbitFlameWindUp
	movs r2, #0x41
	ldr r7, _08111190 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08111194 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r2, _08111198 @ =0x000006FC
	add r2, r8
	ldrh r0, [r2, #0x26]
	orrs r1, r0
	strh r1, [r2, #0x26]
_08111108:
	ldr r3, _0811119C @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08111114
	b _0811124C
_08111114:
	ldr r2, _08111198 @ =0x000006FC
	add r2, r8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	ldr r1, _081111A0 @ =0x00000744
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0x64
	strh r0, [r1]
	ldr r0, _081111A4 @ =0x0000074E
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _081111A8 @ =0x00000746
	add r0, r8
	strh r1, [r0]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r5, r6, r7
	ldr r0, _081111AC @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl Skeleton_PickFarPathNode
	ldr r1, _081111B0 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081111B4
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081111B4
	cmp r0, #2
	beq _08111188
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111188:
	movs r0, #1
	b _081111BE
	.align 2, 0
_0811118C: .4byte Skeleton_StateOrbitFlameWindUp
_08111190: .4byte 0x0000046D
_08111194: .4byte 0x00000553
_08111198: .4byte 0x000006FC
_0811119C: .4byte 0x0000046B
_081111A0: .4byte 0x00000744
_081111A4: .4byte 0x0000074E
_081111A8: .4byte 0x00000746
_081111AC: .4byte 0xFFFFFEFF
_081111B0: .4byte 0x000004A4
_081111B4:
	ldr r0, _081111D0 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_081111BE:
	cmp r0, #0
	bne _081111D8
	ldr r2, _081111D4 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08111256
	.align 2, 0
_081111D0: .4byte 0xFFFFFDFF
_081111D4: .4byte 0x000005C4
_081111D8:
	ldr r3, _08111230 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r5, _08111234 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08111238 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x12
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _0811123C @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08111240 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08111244 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	ldr r1, _08111248 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08111256
	.align 2, 0
_08111230: .4byte Enemy_ClearStateBegun
_08111234: .4byte 0x0000046D
_08111238: .4byte 0x0000046B
_0811123C: .4byte 0x00000469
_08111240: .4byte 0x0000046A
_08111244: .4byte 0x00000484
_08111248: .4byte 0x00000714
_0811124C:
	ldr r7, _08111264 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08111256:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08111264: .4byte 0x00000484
