	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _0808D7E4 @ =0x00000C02
	adds r7, r6, r0
	movs r0, #0xff
	strb r0, [r7]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D7F4
	ldr r0, _0808D7E8 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D7EC @ =0x030046A0
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0x5a
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	mov ip, r2
	adds r3, #0x68
	movs r2, #0
_0808D7B2:
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0808D7D8
	ldr r0, _0808D7F0 @ =0x00000C08
	adds r1, r2, r0
	adds r1, r6, r1
	strb r4, [r1]
	ldrh r0, [r3]
	strb r0, [r1, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bne _0808D7D4
	strb r5, [r7]
_0808D7D4:
	adds r2, #0x64
	adds r5, #1
_0808D7D8:
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _0808D7B2
	b _0808D83E
	.align 2, 0
_0808D7E4: .4byte 0x00000C02
_0808D7E8: .4byte 0x00000C04
_0808D7EC: .4byte 0x030046A0
_0808D7F0: .4byte 0x00000C08
_0808D7F4:
	ldr r0, _0808D818 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D81C @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x5e
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	adds r3, r7, #0
	movs r1, #8
	mov ip, r1
	ldr r7, _0808D820 @ =0x00000C08
	adds r1, r6, r7
_0808D80E:
	strb r4, [r1]
	cmp r4, #0
	bne _0808D824
	mov r0, ip
	b _0808D826
	.align 2, 0
_0808D818: .4byte 0x00000C04
_0808D81C: .4byte 0x030046A0
_0808D820: .4byte 0x00000C08
_0808D824:
	movs r0, #9
_0808D826:
	strb r0, [r1, #1]
	ldr r0, [r2]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r4, r0
	bne _0808D834
	strb r5, [r3]
_0808D834:
	adds r1, #0x64
	adds r5, #1
	adds r4, #1
	cmp r4, #1
	ble _0808D80E
_0808D83E:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	strb r5, [r0]
	cmp r5, #3
	bgt _0808D86A
	movs r2, #0xff
	movs r0, #0x64
	muls r0, r5, r0
	ldr r7, _0808D8E0 @ =0x00000C08
	adds r0, r0, r7
	adds r1, r0, r6
_0808D856:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	adds r1, #0x64
	adds r5, #1
	cmp r5, #3
	ble _0808D856
_0808D86A:
	movs r4, #3
_0808D86C:
	subs r4, #1
	cmp r4, #0
	bge _0808D86C
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D8F2
	ldr r7, _0808D8E4 @ =0x00000C02
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D8F2
	movs r4, #1
	ldr r0, _0808D8E8 @ =0x00000C04
	adds r5, r6, r0
	movs r3, #3
_0808D894:
	ldr r2, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r4
	ands r0, r3
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0808D8EC
	ldrh r0, [r2]
	adds r0, r0, r4
	ands r0, r3
	strh r0, [r2]
	movs r3, #0
	ldr r7, _0808D8E8 @ =0x00000C04
	adds r5, r6, r7
	ldr r0, _0808D8E4 @ =0x00000C02
	adds r4, r6, r0
	ldr r1, _0808D8E0 @ =0x00000C08
	adds r2, r6, r1
_0808D8C6:
	ldr r0, [r5]
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bne _0808D8D6
	strb r3, [r4]
_0808D8D6:
	adds r2, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D8C6
	b _0808D8F2
	.align 2, 0
_0808D8E0: .4byte 0x00000C08
_0808D8E4: .4byte 0x00000C02
_0808D8E8: .4byte 0x00000C04
_0808D8EC:
	adds r4, #1
	cmp r4, #3
	ble _0808D894
_0808D8F2:
	ldr r0, _0808D904 @ =0x00000C03
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D904: .4byte 0x00000C03
