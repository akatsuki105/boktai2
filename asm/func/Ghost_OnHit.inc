	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816AA8E
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0816AA8E
	ldrh r5, [r5, #0xa]
	cmp r5, #1
	bne _0816AA8E
	movs r7, #0xe6
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r6, [r0]
	ldr r2, _0816AA94 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _0816AA98 @ =0x0000046D
	adds r0, r4, r7
	strb r5, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strh r3, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r4, r7
	strb r2, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0816AA9C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0816AAA0 @ =0x00000484
	adds r0, r4, r2
	str r3, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r4, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r0, _0816AAA4 @ =0xFFFFFE7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r2, _0816AAA8 @ =0x000007DC
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	ldr r0, _0816AAAC @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #3
	ldr r7, _0816AAB0 @ =0x00000402
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
	movs r2, #0x80
	ldr r0, _0816AAA8 @ =0x000007DC
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0816AAB4 @ =0x0000083F
	adds r0, r6, r1
	strb r3, [r0]
	ldr r0, _0816AAB8 @ =0x000003CB
	bl PlaySound_082406e0
_0816AA8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816AA94: .4byte Enemy_ClearStateBegun
_0816AA98: .4byte 0x0000046D
_0816AA9C: .4byte 0x0000046A
_0816AAA0: .4byte 0x00000484
_0816AAA4: .4byte 0xFFFFFE7F
_0816AAA8: .4byte 0x000007DC
_0816AAAC: .4byte 0x03002BE0
_0816AAB0: .4byte 0x00000402
_0816AAB4: .4byte 0x0000083F
_0816AAB8: .4byte 0x000003CB
