	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081ACDA8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081ACDAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081ACDAE
	.align 2, 0
_081ACDA8: .4byte 0x0000046C
_081ACDAC:
	movs r0, #0
_081ACDAE:
	cmp r0, #0
	beq _081ACDE6
	ldr r4, _081ACE88 @ =Salamander_StateHover
	movs r3, #0x22
	ldr r2, _081ACE8C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081ACE90 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081ACE94 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
_081ACDE6:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _081ACDF8
	rsbs r3, r1, #0
_081ACDF8:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _081ACE0A
	rsbs r2, r0, #0
_081ACE0A:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl Salamander_PullSegments
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl Salamander_UpdateWave
	ldr r6, _081ACE90 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081ACEA0
	adds r0, r5, #0
	bl Salamander_PickNextTile
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _081ACE8C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _081ACE94 @ =0x00000553
	adds r0, r5, r4
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081ACE98 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _081ACE9C @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081ACEAA
	.align 2, 0
_081ACE88: .4byte Salamander_StateHover
_081ACE8C: .4byte 0x0000046D
_081ACE90: .4byte 0x0000046B
_081ACE94: .4byte 0x00000553
_081ACE98: .4byte 0x0000046A
_081ACE9C: .4byte 0x00000484
_081ACEA0:
	ldr r0, _081ACEB0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081ACEAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081ACEB0: .4byte 0x00000484
