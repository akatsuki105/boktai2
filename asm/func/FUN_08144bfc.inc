	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144C28
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r7, _08144C24 @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	b _08144C9E
	.align 2, 0
_08144C24: .4byte 0x0000024E
_08144C28:
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov ip, r0
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r6, r4, r1
	ldr r5, [r6]
	ands r5, r0
	cmp r5, #0
	bne _08144C9E
	ldr r2, _08144CA4 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08144CA8 @ =0x0000046D
	adds r0, r4, r3
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08144CAC @ =0x0000046B
	adds r0, r4, r7
	strb r5, [r0]
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
	movs r1, #0
	strh r5, [r0]
	movs r2, #3
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _08144CB0 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _08144CB4 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r3, [r0]
	ldr r0, [r6]
	mov r1, ip
	orrs r0, r1
	str r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08144C9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144CA4: .4byte Enemy_ClearStateBegun
_08144CA8: .4byte 0x0000046D
_08144CAC: .4byte 0x0000046B
_08144CB0: .4byte 0x0000046A
_08144CB4: .4byte 0x00000484
