	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081C1B74 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1B78
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C1B7A
	.align 2, 0
_081C1B74: .4byte 0x0000046D
_081C1B78:
	movs r0, #0
_081C1B7A:
	cmp r0, #0
	beq _081C1BB8
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	ldr r3, _081C1C40 @ =0x000004C4
	adds r2, r5, r3
	ldrb r2, [r2]
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r4]
	str r4, [sp]
	bl AuxAnim_RestartAnim
	movs r7, #0xe1
	lsls r7, r7, #1
	adds r2, r5, r7
	movs r1, #0
	movs r0, #0x20
	strh r0, [r2]
	ldr r2, _081C1C44 @ =0x0000046E
	adds r0, r5, r2
	strb r1, [r0]
_081C1BB8:
	ldr r3, _081C1C48 @ =0x00000482
	adds r1, r5, r3
	movs r4, #0
	movs r6, #0
	movs r0, #4
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl Enemy_PlayAnim
	movs r1, #0x10
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C1C38
	adds r0, r5, #0
	bl Enemy_RouteToNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C1BEE
	adds r0, r5, #0
	bl Enemy_PickPathNodeAwayFromPlayer
_081C1BEE:
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C1C4C @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081C1C50 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081C1C54 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C1C58 @ =FUN_081c1790
	movs r2, #0x13
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081C1C5C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
_081C1C38:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1C40: .4byte 0x000004C4
_081C1C44: .4byte 0x0000046E
_081C1C48: .4byte 0x00000482
_081C1C4C: .4byte 0x00000469
_081C1C50: .4byte 0x0000046A
_081C1C54: .4byte 0x00000484
_081C1C58: .4byte FUN_081c1790
_081C1C5C: .4byte 0x0000046B
