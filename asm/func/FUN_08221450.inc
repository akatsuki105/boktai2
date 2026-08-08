	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r7
	bl FUN_08022ec0
	adds r0, r7, #0
	bl FUN_0821c5d4
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08221526
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08221488
	adds r0, r7, #0
	movs r1, #7
	bl FUN_0821c238
_08221488:
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _082214E4
	ldr r0, _082214D8 @ =0x0203B400
	mov r8, r0
	ldr r6, _082214DC @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _082214E0 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r3, r7, r0
	ldrh r0, [r3]
	subs r0, #0x18
	movs r5, #0x30
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0x18
	b _08221520
	.align 2, 0
_082214D8: .4byte 0x0203B400
_082214DC: .4byte 0x030046B8
_082214E0: .4byte 0x000003FF
_082214E4:
	ldr r0, _08221568 @ =0x0203B400
	mov r8, r0
	ldr r6, _0822156C @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _08221570 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r3, r7, r0
	ldrh r0, [r3]
	subs r0, #8
	movs r5, #0x10
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #8
_08221520:
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08221526:
	mov r0, sb
	bl FUN_0821dea4
	movs r2, #0xe3
	lsls r2, r2, #2
	add r2, sb
	ldr r1, _08221574 @ =0x00FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _082215C0
	movs r1, #4
	ldr r0, _08221578 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08221580
	ldr r1, _0822157C @ =0x00000BC3
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #2
	beq _082215C0
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x20
	bl FUN_0823b880
	b _082215C0
	.align 2, 0
_08221568: .4byte 0x0203B400
_0822156C: .4byte 0x030046B8
_08221570: .4byte 0x000003FF
_08221574: .4byte 0x00FFFFFF
_08221578: .4byte 0x03002BC0
_0822157C: .4byte 0x00000BC3
_08221580:
	adds r0, r7, #0
	adds r0, #0xa4
	ldrb r0, [r0]
	cmp r0, #2
	beq _082215AC
	movs r1, #0x10
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _082215AC
	ldr r1, _082215A8 @ =0x00000BC3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	mov r0, sb
	bl FUN_08221938
	b _082215C0
	.align 2, 0
_082215A8: .4byte 0x00000BC3
_082215AC:
	ldr r1, _082215E4 @ =0x00000BC3
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #1
	bne _082215C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #8
	bl FUN_0823b880
_082215C0:
	movs r1, #0xe4
	lsls r1, r1, #2
	add r1, sb
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082215E4: .4byte 0x00000BC3
