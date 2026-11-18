	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r0, _0819D8C0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D8C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D8C6
	.align 2, 0
_0819D8C0: .4byte 0x0000046C
_0819D8C4:
	movs r0, #0
_0819D8C6:
	cmp r0, #0
	beq _0819D8F8
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0819D96C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819D970 @ =0x0000046B
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
_0819D8F8:
	ldr r0, _0819D974 @ =0x00000F0C
	adds r6, r7, r0
	ldrh r0, [r6]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #0x10]
	movs r0, #0xf1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldrh r0, [r4]
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldr r0, _0819D978 @ =0x00000484
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819D936
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r6]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4]
_0819D936:
	ldr r1, _0819D970 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819D988
	subs r1, #3
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0819D97C @ =0x00000469
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0819D980 @ =0x0000046A
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, _0819D978 @ =0x00000484
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _0819D984 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0819D98E
	.align 2, 0
_0819D96C: .4byte 0x0000046D
_0819D970: .4byte 0x0000046B
_0819D974: .4byte 0x00000F0C
_0819D978: .4byte 0x00000484
_0819D97C: .4byte 0x00000469
_0819D980: .4byte 0x0000046A
_0819D984: .4byte 0x0000046C
_0819D988:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
_0819D98E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
