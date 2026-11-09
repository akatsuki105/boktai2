	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _081780E0 @ =0x00001008
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _081780E4 @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r2, _081780E8 @ =0x00000FB5
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _081780EC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081780F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081780F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081780F8 @ =0x00001021
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _081780FC @ =0x00000FAD
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x3f
	adds r1, r5, r2
	ldr r3, _08178100 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08178104
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0817810E
	.align 2, 0
_081780E0: .4byte 0x00001008
_081780E4: .4byte 0x0000FFFD
_081780E8: .4byte 0x00000FB5
_081780EC: .4byte 0x030046B8
_081780F0: .4byte 0x000003FF
_081780F4: .4byte 0x0203B400
_081780F8: .4byte 0x00001021
_081780FC: .4byte 0x00000FAD
_08178100: .4byte 0x0000025D
_08178104:
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0817810E:
	movs r1, #0x83
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	adds r0, r4, #0
	bl FUN_081794a8
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_08177f7c
	adds r0, r4, #0
	bl FUN_08175898
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r5, _08178198 @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r1, _0817819C @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	subs r5, #0x17
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08178198: .4byte 0x00000469
_0817819C: .4byte 0x0000046C
