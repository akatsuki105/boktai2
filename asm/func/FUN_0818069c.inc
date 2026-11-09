	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081806C0 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081806C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081806C6
	.align 2, 0
_081806C0: .4byte 0x0000046D
_081806C4:
	movs r0, #0
_081806C6:
	cmp r0, #0
	beq _081806D4
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _081807C8
_081806D4:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, _08180708 @ =0x000008A4
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081806F2
	movs r0, #0x8a
	lsls r0, r0, #4
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180710
_081806F2:
	ldr r2, _0818070C @ =0x00000898
	add r2, r8
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl cheye_0817c5e0
	b _081807C8
	.align 2, 0
_08180708: .4byte 0x000008A4
_0818070C: .4byte 0x00000898
_08180710:
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, _08180744 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08180748
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
	b _0818076E
	.align 2, 0
_08180744: .4byte 0x000004A4
_08180748:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08180768
	cmp r0, #2
	beq _08180764
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08180764:
	movs r0, #1
	b _08180778
_08180768:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
_0818076E:
	ldr r1, _0818078C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08180778:
	cmp r0, #0
	bne _08180794
	ldr r2, _08180790 @ =0x000005C4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _081807C8
	.align 2, 0
_0818078C: .4byte 0xFFFFFDFF
_08180790: .4byte 0x000005C4
_08180794:
	ldr r2, _081807D4 @ =0x00000898
	add r2, r8
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081807D8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081807C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081807D4: .4byte 0x00000898
_081807D8: .4byte 0x00000484
