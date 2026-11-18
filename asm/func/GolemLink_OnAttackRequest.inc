	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _081B8918
	ldr r3, _081B890C @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081B88DC
	movs r0, #4
	ldr r6, _081B8910 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081B88DC:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r6, _081B8914 @ =0x0000024E
	adds r0, r4, r6
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081B8970
	adds r0, r4, #0
	bl GolemLink_ResumeMove
	b _081B8960
	.align 2, 0
_081B890C: .4byte 0x000001DF
_081B8910: .4byte 0x00000222
_081B8914: .4byte 0x0000024E
_081B8918:
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _081B8978 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r6, _081B897C @ =0x0000046A
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r3, _081B8980 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081B8984 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081B8960:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081B8970:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8978: .4byte 0x00000469
_081B897C: .4byte 0x0000046A
_081B8980: .4byte Enemy_ClearStateBegun
_081B8984: .4byte 0x0000046B
