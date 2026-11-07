	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _0814CBA4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CBA8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CBAA
	.align 2, 0
_0814CBA4: .4byte 0x0000046D
_0814CBA8:
	movs r0, #0
_0814CBAA:
	cmp r0, #0
	beq _0814CBBE
	adds r0, r4, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
	ldr r2, _0814CC68 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0814CBBE:
	ldr r3, _0814CC68 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CBCA
	b _0814CCE2
_0814CBCA:
	ldr r6, _0814CC6C @ =0x0000046B
	adds r0, r4, r6
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0814CC84
	adds r3, #0x36
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl Enemy_SetAngleToward
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _0814CC70 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0814CC74 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0814CC78 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _0814CC7C @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0814CC80 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _0814CCE2
	.align 2, 0
_0814CC68: .4byte 0x0000046E
_0814CC6C: .4byte 0x0000046B
_0814CC70: .4byte 0x0000046D
_0814CC74: .4byte 0x0000046A
_0814CC78: .4byte 0x00000484
_0814CC7C: .4byte 0x00000222
_0814CC80: .4byte 0x00000482
_0814CC84:
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, _0814CCE8 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r2, _0814CCEC @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r6, _0814CCF0 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0814CCF4 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0814CCF8 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_0814CCE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814CCE8: .4byte Enemy_ClearStateBegun
_0814CCEC: .4byte 0x0000046D
_0814CCF0: .4byte 0x0000046B
_0814CCF4: .4byte 0x0000046A
_0814CCF8: .4byte 0x00000484
