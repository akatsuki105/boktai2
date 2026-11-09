	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _081595B0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081595B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081595B6
	.align 2, 0
_081595B0: .4byte 0x0000046C
_081595B4:
	movs r0, #0
_081595B6:
	cmp r0, #0
	beq _0815962C
	ldr r1, _081596C8 @ =0x000005A4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _081596CC @ =0x0000046D
	adds r0, r4, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081596D0 @ =0x0000046B
	adds r0, r4, r5
	strb r1, [r0]
	ldr r6, _081596D4 @ =0x00000553
	adds r0, r4, r6
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r4, r5
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r1, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	subs r1, #0x81
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _081596D8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r4, r5
	ldr r0, _081596DC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r6, _081596E0 @ =0x00000482
	adds r0, r4, r6
	strh r3, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r2, _081596E4 @ =0xFFF7FFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0815962C:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08159642
	b _08159870
_08159642:
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08159652
	b _08159870
_08159652:
	movs r2, #0x80
	lsls r2, r2, #5
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081596F4
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _081596E8 @ =0x0000FFFE
	cmp r1, r0
	bhi _081596F4
	movs r2, #0xbd
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r3, [r0]
	movs r1, #0x19
	ldr r6, _081596CC @ =0x0000046D
	adds r0, r4, r6
	movs r2, #1
	strb r2, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081596EC @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	ldr r3, _081596F0 @ =0x0000046C
	adds r0, r4, r3
	strb r2, [r0]
	b _08159870
	.align 2, 0
_081596C8: .4byte 0x000005A4
_081596CC: .4byte 0x0000046D
_081596D0: .4byte 0x0000046B
_081596D4: .4byte 0x00000553
_081596D8: .4byte 0xFEFFFFFF
_081596DC: .4byte 0xFFFFFDFF
_081596E0: .4byte 0x00000482
_081596E4: .4byte 0xFFF7FFFF
_081596E8: .4byte 0x0000FFFE
_081596EC: .4byte 0x00000469
_081596F0: .4byte 0x0000046C
_081596F4:
	ldr r5, _0815972C @ =0x00000484
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r0, #0x1e
	bne _08159734
	ldr r6, _08159730 @ =0x000001DF
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08159734
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08159870
	.align 2, 0
_0815972C: .4byte 0x00000484
_08159730: .4byte 0x000001DF
_08159734:
	ldr r5, _081597C0 @ =0x00000484
	adds r1, r4, r5
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08159740
	b _0815986C
_08159740:
	movs r1, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081597C4 @ =0x00000469
	adds r0, r4, r3
	strb r2, [r0]
	subs r5, #0x1a
	adds r0, r4, r5
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r2, [r0]
	ldr r1, _081597C8 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	adds r5, #3
	adds r0, r4, r5
	strb r1, [r0]
	subs r6, #0x19
	adds r0, r4, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r4, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	subs r5, #0xab
	adds r2, r4, r5
	ldr r0, [r2]
	strh r1, [r0, #6]
	subs r6, #0xd4
	adds r0, r4, r6
	ldr r5, [r0]
	adds r6, r4, #0
	adds r6, #8
	ldr r7, [r2]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081597D0
	ldr r0, _081597CC @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081597FA
	.align 2, 0
_081597C0: .4byte 0x00000484
_081597C4: .4byte 0x00000469
_081597C8: .4byte 0x0000046C
_081597CC: .4byte 0xFFFFFDFF
_081597D0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081597F0
	cmp r0, #2
	beq _081597EC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081597EC:
	movs r0, #1
	b _081597FC
_081597F0:
	ldr r0, _08159810 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081597FA:
	movs r0, #0
_081597FC:
	cmp r0, #0
	bne _08159818
	ldr r5, _08159814 @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08159870
	.align 2, 0
_08159810: .4byte 0xFFFFFDFF
_08159814: .4byte 0x000005C4
_08159818:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159870
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _0815985C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08159860 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r0, [r2]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	mov r5, r8
	strh r1, [r5]
	adds r6, #0xa4
	adds r0, r4, r6
	strb r2, [r0]
	ldr r1, _08159864 @ =0x0000021E
	adds r0, r4, r1
	strh r3, [r0]
	ldr r2, _08159868 @ =0x00000202
	adds r0, r4, r2
	strh r3, [r0]
	b _08159870
	.align 2, 0
_0815985C: .4byte 0xFEFFFFFF
_08159860: .4byte 0xFFFFFDFF
_08159864: .4byte 0x0000021E
_08159868: .4byte 0x00000202
_0815986C:
	adds r0, #1
	str r0, [r1]
_08159870:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
