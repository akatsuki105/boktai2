	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08146B08 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146B0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146B0E
	.align 2, 0
_08146B08: .4byte 0x0000046C
_08146B0C:
	movs r0, #0
_08146B0E:
	cmp r0, #0
	beq _08146B3C
	ldr r4, _08146B88 @ =FUN_081473ac
	movs r3, #0x23
	ldr r6, _08146B8C @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08146B90 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08146B3C:
	ldr r6, _08146B94 @ =0x000004A4
	adds r0, r5, r6
	ldr r1, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08146B66
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_08146B66:
	ldr r3, _08146B90 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08146B72
	b _08146CC8
_08146B72:
	movs r2, #1
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08146B98
	movs r0, #1
	b _08146B9A
	.align 2, 0
_08146B88: .4byte FUN_081473ac
_08146B8C: .4byte 0x0000046D
_08146B90: .4byte 0x0000046B
_08146B94: .4byte 0x000004A4
_08146B98:
	movs r0, #0
_08146B9A:
	adds r4, r0, #0
	cmp r4, #0
	beq _08146C1C
	ldr r1, _08146BE0 @ =0x0000068C
	adds r0, r7, r1
	ldr r2, _08146BE4 @ =0x00000256
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08146BF0
	movs r4, #1
	mvns r1, r4
	ldrh r0, [r6]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r6]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08146BE8 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r2, _08146BEC @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _08146CD6
	.align 2, 0
_08146BE0: .4byte 0x0000068C
_08146BE4: .4byte 0x00000256
_08146BE8: .4byte 0x00000469
_08146BEC: .4byte 0x0000046C
_08146BF0:
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08146C14 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _08146C18 @ =0x0000046C
	adds r1, r5, r0
	b _08146CB4
	.align 2, 0
_08146C14: .4byte 0x00000469
_08146C18: .4byte 0x0000046C
_08146C1C:
	adds r0, r5, #0
	bl FUN_081489a0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08146C94
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08146C7C @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _08146C80 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _08146C84 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08146C88 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08146C8C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _08146C90 @ =0x0000024E
	adds r0, r5, r3
	strh r4, [r0]
	b _08146CD6
	.align 2, 0
_08146C7C: .4byte 0x00000469
_08146C80: .4byte 0x0000046A
_08146C84: .4byte 0x00000484
_08146C88: .4byte Enemy_ClearStateBegun
_08146C8C: .4byte 0x0000046B
_08146C90: .4byte 0x0000024E
_08146C94:
	movs r1, #0xf
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r3, _08146CBC @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08146CC0 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08146CC4 @ =0x0000046C
	adds r1, r5, r2
_08146CB4:
	movs r0, #1
	strb r0, [r1]
	b _08146CD6
	.align 2, 0
_08146CBC: .4byte 0x00000469
_08146CC0: .4byte 0x00000484
_08146CC4: .4byte 0x0000046C
_08146CC8:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08146CD6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
