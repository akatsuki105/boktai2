	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08181FEC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181F96
	movs r0, #0
	strb r0, [r1]
_08181F96:
	ldr r0, _08181FF0 @ =0x000008AA
	add r0, sl
	ldrh r0, [r0]
	ldr r3, _08181FF4 @ =0x00000484
	adds r2, r5, r3
	ldr r1, [r2]
	cmp r0, r1
	blt _08181FA8
	b _0818222C
_08181FA8:
	ldr r4, _08181FF8 @ =0x00000256
	adds r0, r5, r4
	ldrh r6, [r0]
	mov sb, sp
	ldr r7, _08181FFC @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08182000
	adds r0, #4
	b _0818200A
	.align 2, 0
_08181FEC: .4byte 0x0000046C
_08181FF0: .4byte 0x000008AA
_08181FF4: .4byte 0x00000484
_08181FF8: .4byte 0x00000256
_08181FFC: .4byte 0x030046A4
_08182000:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818200A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r6, #0
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	add r2, sp, #8
	adds r3, r5, #0
	adds r3, #8
	mov r4, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r2, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08182084 @ =0x000003FF
	mov r8, r2
	adds r7, r3, #0
	cmp r1, r0
	bgt _08182098
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08182088 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0818208C @ =0x0000046A
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _08182090 @ =0x00000484
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	ldr r0, _08182094 @ =0x0000046C
	adds r1, r5, r0
	b _0818221A
	.align 2, 0
_08182084: .4byte 0x000003FF
_08182088: .4byte 0x00000469
_0818208C: .4byte 0x0000046A
_08182090: .4byte 0x00000484
_08182094: .4byte 0x0000046C
_08182098:
	movs r2, #1
	ldr r1, _081820AC @ =0x00000898
	add r1, sl
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081820B0
	movs r0, #1
	b _081820B2
	.align 2, 0
_081820AC: .4byte 0x00000898
_081820B0:
	movs r0, #0
_081820B2:
	cmp r0, #0
	beq _081820F0
	ldr r1, _081820E8 @ =0x03002BE0
	ldr r2, _081820EC @ =0x000004A4
	adds r0, r5, r2
	ldr r4, [r0]
	ldr r0, [r1]
	adds r6, r0, #0
	adds r6, #0x2c
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _0818214E
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	bne _0818213E
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	b _08182154
	.align 2, 0
_081820E8: .4byte 0x03002BE0
_081820EC: .4byte 0x000004A4
_081820F0:
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182100
	movs r0, #1
	b _08182102
_08182100:
	movs r0, #0
_08182102:
	cmp r0, #0
	beq _0818215C
	ldr r1, _08182128 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r6, _0818212C @ =0x00000854
	add r6, sl
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08182130
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08182154
	.align 2, 0
_08182128: .4byte 0x000004A4
_0818212C: .4byte 0x00000854
_08182130:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0818214E
_0818213E:
	cmp r0, #2
	beq _0818215C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0818215C
_0818214E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08182154:
	ldr r1, _081821A0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0818215C:
	ldr r4, _081821A4 @ =0x000004A4
	adds r0, r5, r4
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	add r3, sp, #8
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r3, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081821AC
	ldr r4, _081821A8 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081821BA
	.align 2, 0
_081821A0: .4byte 0xFFFFFDFF
_081821A4: .4byte 0x000004A4
_081821A8: .4byte 0xFFFFFF00
_081821AC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081821BA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081821BA:
	adds r0, r1, #0
	cmp r0, #0
	bge _081821C2
	rsbs r0, r0, #0
_081821C2:
	cmp r0, #0x1f
	bgt _081821F8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081821E8 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081821EC @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _081821F0 @ =0x00000484
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _081821F4 @ =0x0000046C
	adds r1, r5, r0
	b _0818221A
	.align 2, 0
_081821E8: .4byte 0x00000469
_081821EC: .4byte 0x0000046A
_081821F0: .4byte 0x00000484
_081821F4: .4byte 0x0000046C
_081821F8:
	movs r2, #0x15
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08182220 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08182224 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08182228 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
_0818221A:
	movs r0, #1
	strb r0, [r1]
	b _08182230
	.align 2, 0
_08182220: .4byte 0x00000469
_08182224: .4byte 0x0000046A
_08182228: .4byte 0x00000484
_0818222C:
	adds r0, r1, #1
	str r0, [r2]
_08182230:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
