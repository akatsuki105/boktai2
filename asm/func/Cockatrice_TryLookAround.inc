	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r4, _0815F888 @ =0x030046B8
	ldr r0, [r4]
	adds r2, r0, #1
	ldr r3, _0815F88C @ =0x000003FF
	ands r2, r3
	str r2, [r4]
	lsls r0, r2, #1
	ldr r6, _0815F890 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldrb r0, [r7, #5]
	subs r1, r3, r0
	cmp r1, #0x80
	ble _0815F794
	ldr r0, _0815F894 @ =0xFFFFFF00
	adds r1, r1, r0
_0815F794:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815F7A2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0815F7A2:
	adds r0, r1, #0
	cmp r0, #0
	bge _0815F7AA
	rsbs r0, r0, #0
_0815F7AA:
	cmp r0, #0x20
	bgt _0815F878
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov ip, r6
	ldr r0, [r6]
	str r0, [r1]
	ldr r0, _0815F898 @ =0x00000553
	adds r0, r0, r7
	mov sl, r0
	ldrb r1, [r0]
	ldr r6, _0815F89C @ =0x0000054F
	adds r0, r7, r6
	strb r1, [r0]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	subs r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0815F8A0 @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0815F8A4 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp]
	ldrb r1, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r1, [r0]
	ldrb r1, [r7, #5]
	ldr r6, _0815F8A8 @ =0x000006BE
	adds r0, r5, r6
	strh r1, [r0]
	asrs r1, r3, #5
	ldr r3, _0815F8AC @ =0x000006BA
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r2, #1
	ldr r6, _0815F88C @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0815F890 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r4, #3
	ands r1, r4
	adds r1, #1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r5, r2
	strh r0, [r1]
	movs r2, #0x2c
	ldr r3, _0815F8B0 @ =0x0000046D
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	adds r6, #0x6c
	adds r0, r7, r6
	movs r3, #0
	strb r3, [r0]
	mov r6, sl
	strb r2, [r6]
	ldr r0, _0815F8B4 @ =Cockatrice_StateLookTurn
	mov r2, ip
	str r0, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r6, #0
	strh r6, [r0]
	mov r0, sb
	strb r4, [r0]
	mov r2, r8
	strb r1, [r2]
	ldr r3, [sp]
	strb r6, [r3]
	ldr r2, _0815F8B8 @ =0x00000484
	adds r0, r7, r2
	movs r3, #0
	str r3, [r0]
	ldr r6, _0815F8BC @ =0x0000046C
	adds r0, r7, r6
	strb r1, [r0]
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
_0815F878:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F888: .4byte 0x030046B8
_0815F88C: .4byte 0x000003FF
_0815F890: .4byte 0x0203B400
_0815F894: .4byte 0xFFFFFF00
_0815F898: .4byte 0x00000553
_0815F89C: .4byte 0x0000054F
_0815F8A0: .4byte 0x00000469
_0815F8A4: .4byte 0x0000046A
_0815F8A8: .4byte 0x000006BE
_0815F8AC: .4byte 0x000006BA
_0815F8B0: .4byte 0x0000046D
_0815F8B4: .4byte Cockatrice_StateLookTurn
_0815F8B8: .4byte 0x00000484
_0815F8BC: .4byte 0x0000046C
