	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _081902A4 @ =0x00000F2C
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _081902A8 @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r2, _081902AC @ =0x00000ED5
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _081902B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081902B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081902B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081902BC @ =0x00000F45
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _081902C0 @ =0x00000ECD
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x3f
	adds r1, r5, r2
	ldr r3, _081902C4 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081902C8
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081902D2
	.align 2, 0
_081902A4: .4byte 0x00000F2C
_081902A8: .4byte 0x0000FFFD
_081902AC: .4byte 0x00000ED5
_081902B0: .4byte 0x030046B8
_081902B4: .4byte 0x000003FF
_081902B8: .4byte 0x0203B400
_081902BC: .4byte 0x00000F45
_081902C0: .4byte 0x00000ECD
_081902C4: .4byte 0x0000025D
_081902C8:
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081902D2:
	ldr r1, _08190358 @ =0x00000F84
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	adds r0, r4, #0
	bl FUN_0819208c
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_0819014c
	adds r0, r4, #0
	bl FUN_0818e6fc
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
	ldr r5, _0819035C @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r1, _08190360 @ =0x0000046C
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
_08190358: .4byte 0x00000F84
_0819035C: .4byte 0x00000469
_08190360: .4byte 0x0000046C
