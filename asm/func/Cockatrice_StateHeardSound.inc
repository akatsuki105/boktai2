	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0815391C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153920
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153922
	.align 2, 0
_0815391C: .4byte 0x0000046D
_08153920:
	movs r0, #0
_08153922:
	cmp r0, #0
	beq _0815392E
	ldr r3, _081539DC @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
_0815392E:
	adds r0, r5, #0
	bl Cockatrice_PlayIdleAnim
	cmp r4, #0x3c
	bgt _0815393A
	b _08153ADA
_0815393A:
	ldr r0, _081539E0 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081539E4 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r5, #0
	bl Enemy_SetAngleToward
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081539F8
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r2, _081539E8 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081539E0 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081539EC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081539F0 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #4
	ldr r1, _081539F4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08153AD2
	.align 2, 0
_081539DC: .4byte 0x0000046E
_081539E0: .4byte 0x0000046B
_081539E4: .4byte 0x000004A4
_081539E8: .4byte 0x0000046D
_081539EC: .4byte 0x0000046A
_081539F0: .4byte 0x00000484
_081539F4: .4byte 0x00000222
_081539F8:
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08153A0C
	movs r0, #1
	b _08153A0E
_08153A0C:
	movs r0, #0
_08153A0E:
	adds r4, r0, #0
	cmp r4, #0
	beq _08153A74
	ldr r3, _08153A64 @ =Cockatrice_StateFly
	movs r1, #0x23
	ldr r6, _08153A68 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x11
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08153A6C @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08153A70 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _08153AC4
	.align 2, 0
_08153A64: .4byte Cockatrice_StateFly
_08153A68: .4byte 0x0000046D
_08153A6C: .4byte 0x0000046A
_08153A70: .4byte 0x00000484
_08153A74:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _08153AE0 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _08153AE4 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08153AE8 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08153AEC @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
_08153AC4:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08153AD2:
	ldr r2, _08153AF0 @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
_08153ADA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08153AE0: .4byte 0x0000046D
_08153AE4: .4byte 0x0000046B
_08153AE8: .4byte 0x0000046A
_08153AEC: .4byte 0x00000484
_08153AF0: .4byte 0x00000482
