	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r3, _08113A64 @ =0x0000046C
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08113A68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08113A6A
	.align 2, 0
_08113A64: .4byte 0x0000046C
_08113A68:
	movs r0, #0
_08113A6A:
	cmp r0, #0
	beq _08113AAE
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08113ADC @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113AE0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113AAE:
	ldr r3, _08113AE0 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08113ABA
	b _08113C04
_08113ABA:
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r2, r7, r4
	ldr r0, _08113AE4 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08113AE8 @ =0x000006FC
	adds r0, r7, r1
	movs r1, #8
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08113AEC
	movs r0, #1
	b _08113AEE
	.align 2, 0
_08113ADC: .4byte 0x0000046D
_08113AE0: .4byte 0x0000046B
_08113AE4: .4byte 0xFFFFFBFF
_08113AE8: .4byte 0x000006FC
_08113AEC:
	movs r0, #0
_08113AEE:
	cmp r0, #0
	beq _08113B68
	ldr r2, _08113B50 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08113B54 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08113B58 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r0, #9
	mov ip, r0
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08113B5C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	mov r1, ip
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r6, r4
	str r3, [r0]
	ldr r1, _08113B60 @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r3, _08113B64 @ =0x000006FC
	adds r2, r7, r3
	movs r0, #9
	rsbs r0, r0, #0
	b _08113BE2
	.align 2, 0
_08113B50: .4byte Enemy_ClearStateBegun
_08113B54: .4byte 0x0000046D
_08113B58: .4byte 0x0000046B
_08113B5C: .4byte 0x00000469
_08113B60: .4byte 0x0000046C
_08113B64: .4byte 0x000006FC
_08113B68:
	ldr r4, _08113B7C @ =0x000006FC
	adds r0, r7, r4
	movs r1, #4
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08113B80
	movs r0, #1
	b _08113B82
	.align 2, 0
_08113B7C: .4byte 0x000006FC
_08113B80:
	movs r0, #0
_08113B82:
	cmp r0, #0
	beq _08113C0E
	ldr r2, _08113BEC @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08113BF0 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08113BF4 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r0, #8
	mov ip, r0
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08113BF8 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	mov r1, ip
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r6, r4
	str r3, [r0]
	ldr r1, _08113BFC @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r3, _08113C00 @ =0x000006FC
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
_08113BE2:
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	b _08113C0E
	.align 2, 0
_08113BEC: .4byte Enemy_ClearStateBegun
_08113BF0: .4byte 0x0000046D
_08113BF4: .4byte 0x0000046B
_08113BF8: .4byte 0x00000469
_08113BFC: .4byte 0x0000046C
_08113C00: .4byte 0x000006FC
_08113C04:
	ldr r4, _08113C14 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08113C0E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08113C14: .4byte 0x00000484
