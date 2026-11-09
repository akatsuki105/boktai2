	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182E08 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182E0E
	.align 2, 0
_08182E08: .4byte 0x0000046C
_08182E0C:
	movs r0, #0
_08182E0E:
	cmp r0, #0
	beq _08182E3A
	ldr r4, _08182E74 @ =FUN_08180494
	movs r3, #0x2c
	ldr r0, _08182E78 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182E7C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08182E3A:
	ldr r2, _08182E80 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _08182E8C
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1b
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08182E84 @ =0x0000046C
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _08182E88 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	b _08182E8E
	.align 2, 0
_08182E74: .4byte FUN_08180494
_08182E78: .4byte 0x0000046D
_08182E7C: .4byte 0x0000046B
_08182E80: .4byte 0x00000484
_08182E84: .4byte 0x0000046C
_08182E88: .4byte 0x00000898
_08182E8C:
	adds r0, #1
_08182E8E:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
